"""Minimal cases cut out of the sample scores where a whole page differs but the code's own sweeps pass.

Each case keeps the chosen items verbatim plus the staff items they hang on (see
rust/fixtures/TRIAGE.md for how they were found). Names: codeNN-sample-<what>.
"""
from __future__ import annotations

from pathlib import Path

from fixtures import Case
from fixtures_cases import WINSCORE, excerpt
from musbuild import mus_bytes


def cut(name: str, description: str, sample: Path, indices: list[int], staves: tuple[int, ...] = ()) -> Case:
    source = f"{sample.name} items {', '.join(map(str, indices))}"
    return Case(name, f"{description} ({source})", mus_bytes(excerpt(sample, indices, staves)))


def cases() -> list[Case]:
    sonlcs = WINSCORE / "sonlcs.mus"
    return [
        cut("code01-sample-chord-flats",
            "stemless note with displaced flat (P5 1.155) and stem-down note with flat at the same P3, "
            "staff size 0.85", sonlcs, [315, 316]),
    ]
