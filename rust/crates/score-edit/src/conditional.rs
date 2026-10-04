//! Conditional editing (WinScore help, conditional_editing.txt): a statement
//! `IF condition THEN changes` applied to every item of the score, e.g.
//! `IF P3 > 100 AND (P1=9 OR P1=18) THEN P3=P3-20, P11=5` or `… THEN DEL`.

use crate::params::{Draft, MAX_PARAM};

const COLOUR: usize = 26;

#[derive(Debug, Clone, PartialEq)]
pub enum Expr {
    Number(f32),
    Param(usize),
    /// MOD(Pn, x): the remainder of Pn divided by x.
    Modulo(Box<Expr>, Box<Expr>),
    Binary(Box<Expr>, Arithmetic, Box<Expr>),
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Arithmetic {
    Add,
    Subtract,
    Multiply,
    Divide,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    NotEqual,
    Less,
    Greater,
    LessOrEqual,
    GreaterOrEqual,
}

#[derive(Debug, Clone, PartialEq)]
pub enum Condition {
    Compare(Expr, Comparison, Expr),
    And(Box<Condition>, Box<Condition>),
    Or(Box<Condition>, Box<Condition>),
}

#[derive(Debug, Clone, PartialEq)]
pub enum Action {
    Set(usize, Expr),
    Delete,
    Cut,
    /// RGB n, GRA n, BLA: the colour or grey of P26.
    Colour(f32),
}

#[derive(Debug, Clone, PartialEq)]
pub struct Statement {
    pub condition: Condition,
    pub actions: Vec<Action>,
}

impl Expr {
    pub fn value(&self, draft: &Draft) -> f32 {
        match self {
            Expr::Number(n) => *n,
            Expr::Param(n) => draft.get(*n),
            Expr::Modulo(a, b) => a.value(draft) % b.value(draft),
            Expr::Binary(a, op, b) => {
                let (a, b) = (a.value(draft), b.value(draft));
                match op {
                    Arithmetic::Add => a + b,
                    Arithmetic::Subtract => a - b,
                    Arithmetic::Multiply => a * b,
                    Arithmetic::Divide => a / b,
                }
            }
        }
    }
}

impl Condition {
    pub fn holds(&self, draft: &Draft) -> bool {
        match self {
            Condition::Compare(a, op, b) => {
                let (a, b) = (a.value(draft), b.value(draft));
                match op {
                    Comparison::Equal => a == b,
                    Comparison::NotEqual => a != b,
                    Comparison::Less => a < b,
                    Comparison::Greater => a > b,
                    Comparison::LessOrEqual => a <= b,
                    Comparison::GreaterOrEqual => a >= b,
                }
            }
            Condition::And(a, b) => a.holds(draft) && b.holds(draft),
            Condition::Or(a, b) => a.holds(draft) || b.holds(draft),
        }
    }
}

impl Statement {
    pub fn deletes(&self) -> bool {
        self.actions.contains(&Action::Delete)
    }

    pub fn cuts(&self) -> bool {
        self.actions.contains(&Action::Cut)
    }

    /// The parameter changes, one after the other (P3=P3-20 sees the old P3).
    pub fn apply(&self, draft: &mut Draft) {
        self.actions.iter().for_each(|action| match action {
            Action::Set(n, expr) => {
                let value = expr.value(draft);
                draft.set(*n, value);
            }
            Action::Colour(value) => draft.set(COLOUR, *value),
            Action::Delete | Action::Cut => {}
        });
    }
}

#[derive(Debug, Clone, PartialEq)]
enum Token {
    Number(f32),
    Param(usize),
    Word(String),
    Symbol(&'static str),
}

const SYMBOLS: [&str; 15] = ["<>", "<=", ">=", "=", "<", ">", "~", "{", "}", "+", "-", "*", "/", "(", ")"];

fn tokens(text: &str) -> Option<Vec<Token>> {
    let mut out = Vec::new();
    let mut rest = text.trim_start();
    while !rest.is_empty() {
        let token;
        if let Some(sym) = SYMBOLS.iter().find(|s| rest.starts_with(**s)) {
            token = Token::Symbol(sym);
            rest = &rest[sym.len()..];
        } else if rest.starts_with([',', ';']) {
            token = Token::Symbol(if rest.starts_with(',') { "," } else { ";" });
            rest = &rest[1..];
        } else {
            let end = rest.find(|c: char| !(c.is_ascii_alphanumeric() || c == '.')).unwrap_or(rest.len());
            if end == 0 {
                return None;
            }
            let word = &rest[..end];
            rest = &rest[end..];
            let upper = word.to_ascii_uppercase();
            token = match (upper.strip_prefix('P').map(str::parse::<usize>), word.parse::<f32>()) {
                (_, Ok(n)) => Token::Number(n),
                (Some(Ok(n)), _) if (1..=MAX_PARAM).contains(&n) => Token::Param(n),
                _ => Token::Word(upper),
            };
        }
        out.push(token);
        rest = rest.trim_start();
    }
    Some(out)
}

/// A recursive-descent reader over the tokens of one statement.
struct Reader {
    tokens: Vec<Token>,
    at: usize,
}

impl Reader {
    fn peek(&self) -> Option<&Token> {
        self.tokens.get(self.at)
    }

    fn next(&mut self) -> Option<Token> {
        let token = self.tokens.get(self.at).cloned();
        self.at += 1;
        token
    }

    fn eat_symbol(&mut self, symbol: &str) -> bool {
        let found = matches!(self.peek(), Some(Token::Symbol(s)) if *s == symbol);
        self.at += usize::from(found);
        found
    }

    fn eat_word(&mut self, word: &str) -> bool {
        let found = matches!(self.peek(), Some(Token::Word(w)) if w == word);
        self.at += usize::from(found);
        found
    }

    /// AND and OR from left to right, as the engine reads them:
    /// `A OR B AND C` is `(A OR B) AND C`.
    fn condition(&mut self) -> Option<Condition> {
        let mut left = self.comparison()?;
        loop {
            left = if self.eat_word("AND") {
                Condition::And(Box::new(left), Box::new(self.comparison()?))
            } else if self.eat_word("OR") {
                Condition::Or(Box::new(left), Box::new(self.comparison()?))
            } else {
                return Some(left);
            };
        }
    }

    fn comparison(&mut self) -> Option<Condition> {
        let start = self.at;
        if self.eat_symbol("(") {
            if let Some(inner) = self.condition().filter(|_| self.eat_symbol(")")) {
                return Some(inner);
            }
            self.at = start;
        }
        let left = self.expr()?;
        let op = match self.next()? {
            Token::Symbol("=") => Comparison::Equal,
            Token::Symbol("<>" | "~") => Comparison::NotEqual,
            Token::Symbol("<") => Comparison::Less,
            Token::Symbol(">") => Comparison::Greater,
            Token::Symbol("<=" | "{") => Comparison::LessOrEqual,
            Token::Symbol(">=" | "}") => Comparison::GreaterOrEqual,
            _ => return None,
        };
        Some(Condition::Compare(left, op, self.expr()?))
    }

    /// Arithmetic from left to right, as the engine evaluates it:
    /// P3+P4*2 is (P3+P4)*2.
    fn expr(&mut self) -> Option<Expr> {
        let mut left = self.operand()?;
        loop {
            let op = [("+", Arithmetic::Add), ("-", Arithmetic::Subtract), ("*", Arithmetic::Multiply), ("/", Arithmetic::Divide)]
                .into_iter()
                .find(|(symbol, _)| self.eat_symbol(symbol))
                .map(|(_, op)| op);
            let Some(op) = op else { return Some(left) };
            left = Expr::Binary(Box::new(left), op, Box::new(self.operand()?));
        }
    }

    fn operand(&mut self) -> Option<Expr> {
        match self.next()? {
            Token::Number(n) => Some(Expr::Number(n)),
            Token::Param(n) => Some(Expr::Param(n)),
            Token::Symbol("-") => match self.next()? {
                Token::Number(n) => Some(Expr::Number(-n)),
                _ => None,
            },
            Token::Word(w) if w == "MOD" => {
                if !self.eat_symbol("(") {
                    return None;
                }
                let value = self.expr()?;
                if !self.eat_symbol(",") {
                    return None;
                }
                let divisor = self.expr()?;
                self.eat_symbol(")").then(|| Expr::Modulo(Box::new(value), Box::new(divisor)))
            }
            Token::Symbol("(") => {
                let inner = self.expr()?;
                self.eat_symbol(")").then_some(inner)
            }
            _ => None,
        }
    }

    fn action(&mut self) -> Option<Action> {
        match self.next()? {
            Token::Param(n) => self.eat_symbol("=").then(|| self.expr().map(|e| Action::Set(n, e))).flatten(),
            Token::Word(w) => match w.as_str() {
                "DEL" => Some(Action::Delete),
                "CUT" => Some(Action::Cut),
                "BLA" => Some(Action::Colour(0.0)),
                "RGB" | "GRA" => match self.next()? {
                    Token::Number(n) => Some(Action::Colour(n)),
                    _ => None,
                },
                _ => None,
            },
            _ => None,
        }
    }
}

/// Reads `IF … THEN …` (`;` may stand for THEN); `None` if it is not one.
pub fn parse(line: &str) -> Option<Statement> {
    let tokens = tokens(line)?;
    let mut reader = Reader { tokens, at: 0 };
    if !reader.eat_word("IF") {
        return None;
    }
    let condition = reader.condition()?;
    if !(reader.eat_word("THEN") || reader.eat_symbol(";")) {
        return None;
    }
    let mut actions = vec![reader.action()?];
    while reader.eat_symbol(",") {
        actions.push(reader.action()?);
    }
    (reader.at == reader.tokens.len()).then_some(Statement { condition, actions })
}

#[cfg(test)]
mod tests {
    use super::*;

    fn note() -> Draft {
        Draft::new(&[1.0, 2.0, 120.0, 6.0, 10.0, 0.0, 0.5, 0.0, 1.0])
    }

    #[test]
    fn the_help_examples_parse() {
        assert!(parse("IF P3 > 100 THEN P3=P3-20").is_some());
        assert!(parse("IF P3 > 100 ; P3=p3-20").is_some());
        assert!(parse("IF P3 > 100 AND (P1=9 OR P1=18) THEN CUT").is_some());
        assert!(parse("IF (P1=1 AND P2<4) OR (P1=2 AND P2>=6) THEN DEL").is_some());
        let s = parse("IF(P1=1 AND P2>3 AND MOD(P9,10) <> 0) OR (P1=1 AND P2=1 AND P3>100) THEN P11=5, P6=6").unwrap();
        assert_eq!(s.actions.len(), 2);
        assert!(parse("IF P3 > 100").is_none());
        assert!(parse("NOTE 1").is_none());
    }

    #[test]
    fn conditions_and_changes_apply_per_item() {
        let mut d = note();
        let s = parse("IF P1=1 AND P2<4 AND MOD(P9,10) ~ 0 THEN P3=P3-20, P11=5, RGB 990000").unwrap();
        assert!(s.condition.holds(&d));
        s.apply(&mut d);
        assert_eq!((d.get(3), d.get(11), d.get(26)), (100.0, 5.0, 990000.0));
        assert!(!parse("IF P3 { 50 THEN DEL").unwrap().condition.holds(&d) || d.get(3) <= 50.0);
    }

    #[test]
    fn and_and_or_read_left_to_right() {
        let s = parse("IF P3=120 OR P1=2 AND P2=5 THEN DEL").unwrap();
        assert!(!s.condition.holds(&note()));
        let t = parse("IF P3=120 OR (P1=2 AND P2=5) THEN DEL").unwrap();
        assert!(t.condition.holds(&note()));
    }
}
