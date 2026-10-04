"""Replacements for the C++ functions that the FORTRAN engine calls back.

In WScore.exe these show dialogs, write to the command bar, or query the
MFC view. Here they record what the engine asked for and answer from a queue.
"""
from __future__ import annotations

import struct
from dataclasses import dataclass, field
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from emu import Engine

COMMAND = 0x7A0B7C
ZOOM = 0x7A0A80

# Callbacks executed natively because they touch no MFC state.
NATIVE = {0x595680, 0x597B30, 0x597B60, 0x595820}

DIALOGS = {
    0x5956B0, 0x595720, 0x595D40, 0x595E00, 0x595E70, 0x595F30, 0x596010, 0x5998C0, 0x599A70,
    0x599BD0, 0x599D30, 0x599E90, 0x599FD0, 0x59A110, 0x59A200, 0x59A340, 0x59A430, 0x59A520,
    0x59A610, 0x59A750, 0x59A8E0, 0x59AA20, 0x59AB50, 0x59AC20, 0x59AD60, 0x59AE50, 0x59AF40,
    0x59AFC0, 0x59B090, 0x59B160, 0x59B2A0, 0x59B370, 0x59B4E0, 0x59B5A0, 0x59B710, 0x59B810,
    0x59B8B0, 0x59B960, 0x59BAE0, 0x59BEB0, 0x59BF80, 0x59C000, 0x59C140, 0x59C2E0, 0x59C430,
    0x59C5D0, 0x59C6A0, 0x59C770, 0x59C7F0, 0x59C9D0, 0x59CAA0, 0x59CB70, 0x59CCB0, 0x59CDF0,
    0x59D0A0, 0x59D170, 0x59D310, 0x59D400, 0x595CD0,
}


@dataclass
class Event:
    kind: str
    detail: str


@dataclass
class Shell:
    """State of the emulated MFC shell as seen by the engine."""
    answers: list[str] = field(default_factory=list)
    events: list[Event] = field(default_factory=list)
    window_text: str = ""

    def record(self, kind: str, detail: str = ""):
        self.events.append(Event(kind, detail))


class WaitingForInput(Exception):
    pass


def _feed_answer(e: "Engine", prompt: str):
    if not e.shell.answers:
        e.shell.record("prompt-unanswered", prompt)
        raise WaitingForInput(prompt)
    answer = e.shell.answers.pop(0)
    e.shell.record("answer", f"{prompt!r} -> {answer!r}")
    e.uc.mem_write(COMMAND, answer.encode("latin-1") + b"\0")
    return answer


def message_box(e: "Engine") -> int:
    e.shell.record("message", e.cstr(e.arg(0)))
    return 0


def append_command_text(e: "Engine") -> int:
    text = e.cstr(e.arg(0))
    e.shell.window_text += text
    e.shell.record("text", text)
    return 0


def prompt_line(e: "Engine") -> int:
    prompt, label = e.cstr(e.arg(0)), e.cstr(e.arg(1))
    _feed_answer(e, f"{label} {prompt}".strip())
    return 0


def wait_key(e: "Engine") -> int:
    """0x597120, typed-string path: copies the answer to arg0, blanks COMMAND, returns arg2 (input-lang)."""
    buf = e.arg(0)
    answer = _feed_answer(e, "key")
    e.put32(0x9A9488, 0)
    e.uc.mem_write(buf, answer.encode("latin-1") + b"\0")
    e.uc.mem_write(COMMAND, b" \0")
    e.uc.mem_write(0x9C6C5D, b"\0")
    e.put32(0x9C48F4, 0)
    return e.arg(2)


def request_redraw(e: "Engine") -> int:
    e.shell.record("redraw")
    return 0


def dialog(e: "Engine") -> int:
    e.shell.record("dialog", f"{e.current_callback:#x} args={[hex(e.arg(i)) for i in range(3)]}")
    return 0


def service(e: "Engine") -> int:
    """0x597D30: opcode-dispatched window services (see analysis/decompiled/services.c)."""
    op, params = e.arg(0), e.arg(1)
    code = bytes(e.uc.mem_read(op, 4))
    letter = chr(code[1])
    if letter == "k":
        requested = e.u32(params + 4)
        current = e.u32(ZOOM)
        e.put32(ZOOM, 0x40 if requested == 0 and current != 0x40 else (requested or 0x80))
    elif letter in "bz":
        e.uc.mem_write(params, struct.pack("<ii", 0, 0))
    elif letter in "di":
        e.put32(params, 0)
    elif letter == "o":
        e.put32(params, 0xFFFFFFFF)
    elif letter in "hn":
        e.shell.record("document", f"{letter}: {e.cstr(params)}")
    e.shell.record("service", f"{code!r}")
    e.uc.mem_write(op, b"\0")
    return 0


HANDLERS = {
    0x5960F0: message_box,
    0x5963E0: append_command_text,
    0x596140: request_redraw,
    0x596260: request_redraw,
    0x5962F0: append_command_text,
    0x596580: append_command_text,
    0x5966D0: prompt_line,
    0x596A30: prompt_line,
    0x596CC0: prompt_line,
    0x597120: wait_key,
    0x597340: wait_key,
    0x597550: wait_key,
    0x5977C0: request_redraw,
    0x5979A0: request_redraw,
    0x597AD0: request_redraw,
    0x597D30: service,
    0x59CFA0: request_redraw,
    0x59D020: request_redraw,
    0x59D240: request_redraw,
    0x5C69A0: request_redraw,
    **{a: dialog for a in DIALOGS},
}
