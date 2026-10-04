"""Run commands through the emulated engine: python run_one.py "G carmen.mus" ["SA out.mus" ...]

Uses ./sandbox (created on first run) with the WINSCORE sample scores in its C:\\WORK.
"""
import sys
from pathlib import Path

from emu import Engine
from sandbox import INSTALL, make_sandbox

SANDBOX = Path(__file__).resolve().parent / "sandbox"


def main(*commands):
    make_sandbox(SANDBOX, tuple(INSTALL.glob("*.mus")))
    e = Engine(SANDBOX)
    e.initialize()
    for cmd in commands:
        try:
            r = e.command(cmd)
        except RuntimeError as err:
            print(f"[{cmd}] ERROR {err}")
            break
        print(f"[{cmd}] status={r.status} vector words={3 * len(r.vector)} text bytes={len(r.text)}")
    for ev in e.shell.events:
        if ev.kind in ("message", "document", "prompt-unanswered", "dialog"):
            print("  ", ev.kind, ev.detail[:120])
    return e


if __name__ == "__main__":
    main(*sys.argv[1:])
