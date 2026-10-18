// Arithmetic for edit scripts: the values a step gives each item, such as
// "1 + (to - 1) * t ^ curve" for sizes that grow from left to right. Numbers,
// names (the item's parameters p1 … p45, its place among the targets, the
// knobs), + − × / % ^, comparisons, && || !, ?: and a few functions. An
// expression is compiled once and run for every item on every slider move.

export type Vars = Record<string, number>;
export type Compiled = (vars: Vars) => number;

const FUNCTIONS: Record<string, (...args: number[]) => number> = {
  min: Math.min,
  max: Math.max,
  abs: Math.abs,
  round: Math.round,
  floor: Math.floor,
  ceil: Math.ceil,
  sqrt: Math.sqrt,
  pow: Math.pow,
  exp: Math.exp,
  log: Math.log,
  sin: Math.sin,
  cos: Math.cos,
  sign: Math.sign,
  trunc: Math.trunc,
  /** a at t = 0, b at t = 1. */
  lerp: (a, b, t) => a + (b - a) * t,
  clamp: (x, lo, hi) => Math.min(hi, Math.max(lo, x)),
  /** x rounded to the nearest multiple of step. */
  snap: (x, step) => (step ? Math.round(x / step) * step : x),
};

type Token = { kind: 'num'; value: number } | { kind: 'name'; name: string } | { kind: 'op'; op: string };

const OPERATORS = ['&&', '||', '==', '!=', '<=', '>=', '**', '+', '-', '*', '/', '%', '^', '<', '>', '!', '?', ':', '(', ')', ','];

function tokens(text: string): Token[] {
  const out: Token[] = [];
  let i = 0;
  while (i < text.length) {
    const c = text[i]!;
    if (/\s/.test(c)) {
      i++;
      continue;
    }
    const number = /^(\d+\.?\d*|\.\d+)(e[+-]?\d+)?/i.exec(text.slice(i));
    if (number) {
      out.push({ kind: 'num', value: Number(number[0]) });
      i += number[0].length;
      continue;
    }
    const name = /^[a-z_][a-z0-9_]*/i.exec(text.slice(i));
    if (name) {
      out.push({ kind: 'name', name: name[0] });
      i += name[0].length;
      continue;
    }
    const op = OPERATORS.find((o) => text.startsWith(o, i));
    if (!op) throw new Error(`Cannot read “${c}” in “${text}”`);
    out.push({ kind: 'op', op: op === '**' ? '^' : op });
    i += op.length;
  }
  return out;
}

/** Binding strength of binary operators; ^ binds right. */
const BINARY: Record<string, number> = { '||': 1, '&&': 2, '==': 3, '!=': 3, '<': 4, '<=': 4, '>': 4, '>=': 4, '+': 5, '-': 5, '*': 6, '/': 6, '%': 6, '^': 8 };
/** What a sign before an operand takes along: only ^. */
const UNARY = 7;

function binary(op: string, a: Compiled, b: Compiled): Compiled {
  switch (op) {
    case '||': return (v) => (a(v) || b(v) ? 1 : 0);
    case '&&': return (v) => (a(v) && b(v) ? 1 : 0);
    case '==': return (v) => (Math.abs(a(v) - b(v)) < 1e-4 ? 1 : 0);
    case '!=': return (v) => (Math.abs(a(v) - b(v)) < 1e-4 ? 0 : 1);
    case '<': return (v) => (a(v) < b(v) ? 1 : 0);
    case '<=': return (v) => (a(v) <= b(v) ? 1 : 0);
    case '>': return (v) => (a(v) > b(v) ? 1 : 0);
    case '>=': return (v) => (a(v) >= b(v) ? 1 : 0);
    case '+': return (v) => a(v) + b(v);
    case '-': return (v) => a(v) - b(v);
    case '*': return (v) => a(v) * b(v);
    case '/': return (v) => a(v) / b(v);
    case '%': return (v) => a(v) % b(v);
    default: return (v) => Math.pow(a(v), b(v));
  }
}

/** Compiles `text`; unknown names are an error when the expression runs, so knobs can be added later. */
export function compile(text: string): Compiled {
  const list = tokens(text);
  let at = 0;
  const peek = () => list[at];
  const isOp = (op: string) => {
    const t = peek();
    return t?.kind === 'op' && t.op === op;
  };
  const expect = (op: string) => {
    if (!isOp(op)) throw new Error(`“${op}” expected in “${text}”`);
    at++;
  };

  function primary(): Compiled {
    const t = list[at++];
    if (!t) throw new Error(`“${text}” ends too early`);
    if (t.kind === 'num') {
      const value = t.value;
      return () => value;
    }
    if (t.kind === 'name') {
      if (isOp('(')) {
        at++;
        const fn = FUNCTIONS[t.name.toLowerCase()];
        if (!fn) throw new Error(`No function ${t.name}`);
        const args: Compiled[] = [];
        while (!isOp(')')) {
          args.push(ternary());
          if (isOp(',')) at++;
          else break;
        }
        expect(')');
        return (v) => fn(...args.map((a) => a(v)));
      }
      const name = t.name;
      return (v) => {
        const value = v[name];
        if (value === undefined) throw new Error(`Unknown name ${name}`);
        return value;
      };
    }
    if (t.op === '(') {
      const inner = ternary();
      expect(')');
      return inner;
    }
    // A sign binds less tightly than ^: -x^2 is -(x^2).
    if (t.op === '-') {
      const operand = operation(UNARY);
      return (v) => -operand(v);
    }
    if (t.op === '+') return operation(UNARY);
    if (t.op === '!') {
      const operand = operation(UNARY);
      return (v) => (operand(v) ? 0 : 1);
    }
    throw new Error(`Unexpected “${t.op}” in “${text}”`);
  }

  function operation(minimum: number): Compiled {
    let left = primary();
    for (;;) {
      const t = peek();
      const strength = t?.kind === 'op' ? BINARY[t.op] : undefined;
      if (t?.kind !== 'op' || strength === undefined || strength < minimum) return left;
      at++;
      const right = operation(t.op === '^' ? strength : strength + 1);
      left = binary(t.op, left, right);
    }
  }

  function ternary(): Compiled {
    const condition = operation(1);
    if (!isOp('?')) return condition;
    at++;
    const yes = ternary();
    expect(':');
    const no = ternary();
    return (v) => (condition(v) ? yes(v) : no(v));
  }

  const result = ternary();
  if (at < list.length) throw new Error(`Unexpected text after “${text.slice(0, 40)}”`);
  return result;
}

/** A number as it is, or text compiled as an expression. */
export function valueOf(value: number | string): Compiled {
  if (typeof value === 'number') return () => value;
  const trimmed = value.trim();
  const plain = Number(trimmed);
  return trimmed !== '' && Number.isFinite(plain) ? () => plain : compile(trimmed);
}
