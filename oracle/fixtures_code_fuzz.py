"""Minimal mismatches found by fuzz.py (fuzz_cases.json), kept as fixtures fuzz-codeNN-*."""
from __future__ import annotations

from fixtures import Case
from fuzz import load_saved, FuzzCase


def cases() -> list[Case]:
    return [replace_description(FuzzCase.from_json(entry).case(), entry) for entry in load_saved()]


def replace_description(case: Case, entry: dict) -> Case:
    description = f"fuzz, {entry['owner']}: {', '.join(entry['symptoms'])}; {str(entry['detail'])[:100]}"
    return Case(case.name, description, case.mus)
