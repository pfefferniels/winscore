# Tools

## oracle/trace.py: who emitted what

Runs commands through the emulated engine (in a fresh temporary sandbox) and records

- every call between routines (a shadow call stack from a basic-block hook: a block entered right after a block ending in CALL, with the fall-through address on top of the stack, is a call; incremental-linking thunks are resolved to their targets),
- for every word written to the vector buffer and every byte of the text buffer, the call chain, the writing instruction and the item last loaded by `load_item_header`,
- optionally, every write into address ranges you name (`--watch`),
- basic-block execution counts (`--blocks`), useful for diffing two runs that differ in one parameter.

```sh
PY=/Users/nielspfeffer/Projects/winscore/oracle/.venv/bin/python
$PY oracle/trace.py --mus my.mus                       # calls and emissions for "G my.mus"
$PY oracle/trace.py --mus my.mus --emissions           # vector runs and text strings with chains
$PY oracle/trace.py --mus my.mus --calls --top 30      # call counts, top callers
$PY oracle/trace.py --mus my.mus --watch 20527f4       # who writes VIEW_DY, with values
$PY oracle/trace.py --mus my.mus --blocks a.tsv        # block counts
$PY oracle/trace.py --mus a.mus --cmd "G a.mus" --cmd "SA b.mus"   # several commands; the report covers the last
```

Routine names come from `analysis/engine/names.tsv` (falling back to Ghidra's `FUN_...`). A chain prints as `outer@return_address > ... > inner@return_address`; the return address locates the call site in the caller.

Python API (from the `oracle/` directory):

```python
from trace import Tracer
with Tracer(engine, watches=[range(0x20527F4, 0x20527F8)]) as t:
    result = engine.command("G my.mus")
for run in t.vector_runs(result):          # consecutive triples written by one instruction under one chain
    print(run.first, run.count, run.write.item, t.chain_text(run.write.chain))
for s in t.text_strings(result):
    print(s.text, s.x, s.y, t.chain_text(s.write.chain))
t.calls, t.edges, t.blocks, t.hits         # Counters and watch hits
```

Cost: about 1 s for a small score (block hook in Python). The module name shadows the standard library's `trace` inside `oracle/`; nothing there imports the standard one.

## experiments/lab.py

`Lab()` boots one engine in a private temporary sandbox; `lab.load(items)` writes the items as a .mus, sends `G`, returns the EngineResult; `lab.render(items)` returns decoded shapes and text runs. Experiment scripts in `experiments/` use it, e.g. `staves.py` and `barlines.py` compare a Python model against the engine on random items.

## Ghidra

`ghidra/ghidra.sh` runs our GhidraScripts against `tools/ghidra-project` (single writer: only `disasm-expert` runs it):

- `ghidra.sh names`: apply `names.tsv` and `globals.tsv`;
- `ghidra.sh constants`: type the engine's read-only constants and label them by value (done once; `f_150`, `i_3`, `d_...`);
- `ghidra.sh decompile 0xADDR ...`: write `decompiled/<addr>_<name>.c`;
- `ghidra.sh all`: decompile all 878 engine routines into `/Users/nielspfeffer/Projects/winscore/tools/decompiled/<addr>_<name>.c` plus `index.tsv` (6 MB, a few minutes; not in git, regenerated after renames).

**Everyone can read the full engine decompilation** at `/Users/nielspfeffer/Projects/winscore/tools/decompiled/` without running Ghidra. File names carry our routine names where we have them (`545140_draw_staff.c`), else `FUN_`. Globals and constants are named as in `globals.tsv` and by value (`f_150`).

A copy of the project before our changes is at `tools/ghidra-project.orig-2026-10-04`.
