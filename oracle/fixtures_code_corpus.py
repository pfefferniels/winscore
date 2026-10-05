"""Real SCORE files and minimal cases for differences found in them (corpus/REPORT.md).

Most corpus files may not be redistributed and stay out of the repository (corpus/SOURCES.md).
The few that may are in corpus/free/ and become whole-page cases corpus-<file>. The minimal
cases are synthetic: a staff and the few items that show a difference, with the parameter
values of the corpus item they stand for; names codeNN-corpus-<what>. Owned by corpus.
"""
from __future__ import annotations

import sys
from pathlib import Path

from fixtures import Case
from fixtures_code01 import single

FREE = Path(__file__).resolve().parents[1] / "corpus" / "free"
sys.path.insert(0, str(FREE.parent))

from pmx import pmx_to_mus  # noqa: E402


def free_page(path: Path) -> Case:
    name = path.name.split(".")[0]
    if path.suffix == ".mus":
        return Case(f"corpus-{name}", f"corpus/free/{path.name}", path.read_bytes())
    return Case(f"corpus-{name}", f"corpus/free/{path.name} (PMX converted)", pmx_to_mus(path.read_text(encoding="latin-1")))


def free_pages() -> list[Case]:
    """Chopin op. 28/4 and 28/6 (Sapp, CC BY 4.0) and mus2pmx's ex1 (licence "Whatever")."""
    return [free_page(p) for p in sorted(FREE.iterdir()) if p.suffix in {".mus", ".txt"}]


def mark_29() -> list[Case]:
    """P11 = 29 has no entry in the help's list of marks; Sapp's SCORE 3.11 code-1 sheet uses it
    (sapp-ccrma-code-input/code1.mus item 122: 1 5 171 3 10 0 1 0 0 0 29 0 0 -2)."""
    source = "as in Sapp's code-1 parameter sheet"
    return [
        single("corpus-mark29", f"mark P11 = 29 ({source})", p11=29),
        single("corpus-mark29-p14", f"mark P11 = 29 moved by P14 = -2 ({source})", p11=29, p14=-2),
        single("corpus-mark29-down", "mark P11 = 29, stem down", p11=29, p5=20),
        single("corpus-mark-m29", "mark P11 = -29 on the stem side", p11=-29),
    ]


def cases() -> list[Case]:
    return free_pages() + mark_29()
