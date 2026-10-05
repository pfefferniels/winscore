"""Engine references for the corpus of real SCORE files (sources: corpus/SOURCES.md).

    python corpus/corpus.py [--out DIR] [--jobs N] [--list] [PATTERN ...]

Every binary .mus or .pag file under corpus/files/<source>/, and every SCORE PMX text
file there (converted to binary), becomes a case corpus-<source>-<file>. The engine
fixtures go to corpus/fixtures/ (gitignored, like the files) in the format of
rust/fixtures/README.md, so score-compare and score-triage read them with --fixtures.
"""
from __future__ import annotations

import argparse
import os
import re
import shutil
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

CORPUS = Path(__file__).resolve().parent
sys.path.insert(0, str(CORPUS.parent / "oracle"))

from fixtures import SANDBOXES, Case, selected, write_fixture  # noqa: E402
from pmx import pmx_to_mus  # noqa: E402

FILES = CORPUS / "files"
FIXTURES = CORPUS / "fixtures"
BINARY_SUFFIXES = {".mus", ".pag"}
TEXT_SUFFIXES = {".pmx", ".txt"}
MAX_JOBS = 4   # the machine is shared with the other agents' builds and runs


def slug(text: str) -> str:
    return re.sub(r"[^a-z0-9]+", "-", text.lower()).strip("-")


def source_name(path: Path) -> str:
    """The source directory without the hosting prefixes, which only lengthen case names."""
    name = slug(path.relative_to(FILES).parts[0])
    return name.removeprefix("github-").removeprefix("craigsapp-")


def case_name(path: Path) -> str:
    suffix = "" if path.suffix.lower() == ".mus" else f"-{path.suffix.lower()[1:]}"
    return f"corpus-{source_name(path)}-{slug(path.stem)}{suffix}"


def has_binary_twin(path: Path) -> bool:
    """A PMX listing next to the binary file it was printed from."""
    return any(path.with_suffix(s).exists() for s in BINARY_SUFFIXES)


def case_of(path: Path) -> Case | None:
    """None for a text file that is not SCORE PMX."""
    description = f"corpus file {path.relative_to(FILES)}"
    if path.suffix.lower() in BINARY_SUFFIXES:
        return Case(case_name(path), description, path.read_bytes())
    mus = pmx_to_mus(path.read_text(encoding="latin-1"))
    return Case(case_name(path), f"{description} (PMX converted)", mus) if mus else None


def is_case_file(path: Path) -> bool:
    suffix = path.suffix.lower()
    return path.is_file() and (suffix in BINARY_SUFFIXES or (suffix in TEXT_SUFFIXES and not has_binary_twin(path)))


def corpus_files() -> list[Path]:
    """Multi-page .ppmx files are left out: `python corpus/pmx.py` splits them into pages first."""
    return sorted(filter(is_case_file, FILES.rglob("*")))


def corpus_cases() -> list[Case]:
    cases = [c for c in map(case_of, corpus_files()) if c is not None]
    names = [c.name for c in cases]
    duplicates = sorted({n for n in names if names.count(n) > 1})
    if duplicates:
        raise ValueError(f"duplicate case names: {duplicates}")
    return cases


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("patterns", nargs="*")
    parser.add_argument("--out", type=Path, default=FIXTURES)
    parser.add_argument("--jobs", type=int, default=min(MAX_JOBS, max(1, (os.cpu_count() or 2) // 2)))
    parser.add_argument("--list", action="store_true")
    args = parser.parse_args(argv)

    cases = selected(corpus_cases(), args.patterns)
    if args.list:
        print("\n".join(f"{c.name}\t{c.description}" for c in cases))
        return 0
    try:
        with ProcessPoolExecutor(max_workers=min(args.jobs, MAX_JOBS)) as pool:
            written = list(pool.map(write_fixture, cases, [args.out] * len(cases), [True] * len(cases)))
    finally:
        shutil.rmtree(SANDBOXES, ignore_errors=True)
    for w in written:
        state = "ok" if w.valid else "INVALID " + "; ".join(w.reasons)
        print(f"{w.name:48} shapes={w.shapes:5} strings={w.texts:4} {state}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
