"""Summarise data/commands.tsv as Markdown tables for commands.md.

    python command_summary.py > ../data/commands_summary.md

Sections: items created with nothing selected, changes to the selected note, commands with no
visible effect on the items, and the handler routines grouped by command family.
"""
from __future__ import annotations

import csv
from collections import defaultdict
from pathlib import Path

DATA = Path(__file__).resolve().parents[1] / "data" / "commands.tsv"
RENAMED = {"cmd_input": "cmd_I", "FUN_0046d088": "edit_params", "FUN_0045ef21": "edit_letters", "FUN_00580b70": "create_by_mnemonic"}
EVERY_COMMAND = {"FUN_0054943a", "FUN_00549449", "FUN_0054e2a1", "FUN_0059d020", "FUN_005f33c9", "FUN_005f34d1",
                 "FUN_005f4660", "FUN_0048ecfb", "FUN_00518448"}


def rows():
    with DATA.open() as f:
        return list(csv.DictReader(f, delimiter="\t"))


def handlers(row) -> str:
    return " ".join(RENAMED.get(h, h) for h in row["handlers"].split() if h not in EVERY_COMMAND)


def table(header: list[str], body: list[list[str]]) -> str:
    lines = ["| " + " | ".join(header) + " |", "|" + "---|" * len(header)]
    lines += ["| " + " | ".join(cell.replace("|", "/") for cell in r) + " |" for r in body]
    return "\n".join(lines)


def main():
    data = rows()
    new = [r for r in data if r["context"] == "new"]
    note = [r for r in data if r["context"] == "note"]
    created = [[f"`{r['command'].strip()}`", r["added"], handlers(r)] for r in new if r["added"]]
    changed = [[f"`{r['command'].strip()}`", r["item4"].split(" -> ")[1] if r["item4"] else "", r["added"] if not r["item4"] else "",
                handlers(r)] for r in note if r["item4"] or (r["added"] and r["added"] not in r["item4"])]
    silent = sorted({r["command"].strip() for r in data
                     if not r["added"] and not r["item4"] and r["deleted"] in ("0", "")})
    print("### Items created with nothing selected\n")
    print(table(["command", "item(s) added", "handlers"], created))
    print("\n### Effect on the selected note `1 1 30 5 10 0 1`\n")
    print(table(["command", "note after", "added", "handlers"], changed))
    print(f"\n### No change to the items in either context ({len(silent)} commands)\n")
    print(", ".join(f"`{c}`" for c in silent))
    families = defaultdict(set)
    for r in data:
        families[handlers(r)].add(r["command"].strip())
    print("\n### Handler sets\n")
    print(table(["handlers", "commands"], [[h or "(none)", ", ".join(sorted(c)[:12]) + (" ..." if len(c) > 12 else "")]
                                          for h, c in sorted(families.items(), key=lambda kv: -len(kv[1]))]))


if __name__ == "__main__":
    main()
