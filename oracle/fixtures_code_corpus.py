"""Minimal cases for differences found in real SCORE files (corpus/REPORT.md, sources in corpus/SOURCES.md).

The corpus files themselves are not committed. Each case here is synthetic: a staff and the
few items that show the difference, with the parameter values of the corpus item it stands
for. Names: codeNN-corpus-<what>. Owned by corpus.
"""
from __future__ import annotations

from fixtures import Case
from fixtures_code01 import single


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
    return mark_29()
