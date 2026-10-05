"""Run the FORTRAN engine of WScore.exe under Unicorn, without Windows or MFC.

The engine is driven exactly as the MFC shell drives it: a command word is
copied to the engine's command buffer and the interpreter routine is called.
Its vector and text output buffers are then read back.
"""
from __future__ import annotations

import struct
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable

import pefile
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UC_HOOK_MEM_INVALID, UC_PROT_ALL
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW, UC_X86_REG_FS, UC_X86_REG_GDTR, UC_X86_REG_SS, UC_X86_REG_DS, UC_X86_REG_ES

from callbacks import HANDLERS, NATIVE, Shell, WaitingForInput
from winapi import WinApi

EXE = Path(__file__).resolve().parents[1] / "WINSCORE 5.01" / "winscore" / "WScore.exe"

INTERPRETER = 0x47EC50
ENGINE_INIT = 0x4A6730
TEXT_BUF_DIRECT = 0x15E9C34
VECTOR_BUF, VECTOR_LEN = 0x9C73D8, 0x1576468
TEXT_OUT, TEXT_LEN = 0x157E574, 0x1576464
COMMAND, LINE_BUF, MESSAGE_BUF = 0x7A0B7C, 0x9AE2BC, 0x9C66D4
ZOOM, ENGINE_ZOOM, FLAG_9A9498 = 0x7A0A80, 0x9C66CC, 0x9A9498
CPP_CODE = range(0x58C900, 0x5ED300)

STACK_BASE, STACK_SIZE = 0x7F000000, 0x100000
AFTER_C_INITIALIZERS = 0x5EEB96   # in _cinit, before the C++ constructor table
WINDOWS_FPU_CONTROL = 0x27F       # 53-bit precision, all exceptions masked
STUB_BASE = 0x7E000000
TIB_BASE = 0x7EFD0000
GDT_BASE = 0x7EFC0000
RETURN_SENTINEL = 0x7E0FFFF0


class EmulationStop(Exception):
    """Raised by a handler to stop emulation with an explanation."""


@dataclass
class Import:
    dll: str
    name: str


@dataclass
class EngineResult:
    status: int
    vector: list[tuple[int, int, int]]
    text: bytes
    message: str


@dataclass
class Engine:
    root: Path
    uc: Uc = field(init=False)
    imports: dict[int, Import] = field(default_factory=dict)
    trace: list[str] = field(default_factory=list)
    shell: Shell = field(default_factory=Shell)
    current_callback: int = 0
    timeout_ms: int = 0              # wall-clock limit per call; 0 = none

    def __post_init__(self):
        self.pe = pefile.PE(str(EXE))
        self.uc = Uc(UC_ARCH_X86, UC_MODE_32)
        self._map_image()
        self.uc.mem_map(STACK_BASE, STACK_SIZE, UC_PROT_ALL)
        self._map_thread_block()
        self.api = WinApi(self)
        self._bind_imports()
        self.uc.hook_add(UC_HOOK_CODE, self._on_stub, begin=STUB_BASE, end=STUB_BASE + 0xFFFFF)
        self.uc.hook_add(UC_HOOK_CODE, self._on_cpp, begin=CPP_CODE.start, end=CPP_CODE.stop - 1)
        self.uc.hook_add(UC_HOOK_MEM_INVALID, self._on_bad_memory)
        self._boot()

    def _boot(self):
        """Run the CRT startup through the C initialisers, skipping MFC's C++ constructors."""
        self.uc.reg_write(UC_X86_REG_FPCW, WINDOWS_FPU_CONTROL)
        self.uc.reg_write(UC_X86_REG_ESP, STACK_BASE + STACK_SIZE - 0x100)
        entry = self.pe.OPTIONAL_HEADER.ImageBase + self.pe.OPTIONAL_HEADER.AddressOfEntryPoint
        try:
            self.uc.emu_start(entry, AFTER_C_INITIALIZERS)
        except UcError as err:
            self.trace.append(f"{err} at eip {self.reg(UC_X86_REG_EIP):#x}")
        if self.reg(UC_X86_REG_EIP) != AFTER_C_INITIALIZERS:
            raise RuntimeError("CRT startup failed: " + "; ".join(self.trace[-5:]))

    # -- loading -----------------------------------------------------------
    def _map_image(self):
        base = self.pe.OPTIONAL_HEADER.ImageBase
        size = (self.pe.OPTIONAL_HEADER.SizeOfImage + 0xFFF) & ~0xFFF
        self.uc.mem_map(base, size, UC_PROT_ALL)
        self.uc.mem_write(base, self.pe.header)
        for s in self.pe.sections:
            self.uc.mem_write(base + s.VirtualAddress, s.get_data())

    def _map_thread_block(self):
        """Thread information block: empty SEH chain, stack limits, self pointer."""
        self.uc.mem_map(TIB_BASE, 0x2000, UC_PROT_ALL)
        tib = struct.pack("<7I", 0xFFFFFFFF, STACK_BASE + STACK_SIZE, STACK_BASE, 0, 0, 0, TIB_BASE)
        self.uc.mem_write(TIB_BASE, tib)
        self.uc.mem_write(TIB_BASE + 0x30, struct.pack("<I", TIB_BASE + 0x1000))
        self._load_fs_segment(TIB_BASE)

    @staticmethod
    def _descriptor(base, limit, access, flags):
        return (limit & 0xFFFF) | (base & 0xFFFFFF) << 16 | access << 40 \
            | ((limit >> 16) & 0xF) << 48 | flags << 52 | ((base >> 24) & 0xFF) << 56

    def _load_fs_segment(self, base):
        """32-bit mode needs GDT descriptors: flat ring-0 data for SS/DS/ES, FS at the TIB."""
        present, data, writable, ring3 = 0x80, 0x10, 0x02, 0x60
        big_pages, big = 0xC, 0x4
        flat = self._descriptor(0, 0xFFFFF, present | data | writable, big_pages)
        fs = self._descriptor(base, 0x1FFF, present | data | writable | ring3, big)
        self.uc.mem_map(GDT_BASE, 0x1000, UC_PROT_ALL)
        self.uc.mem_write(GDT_BASE, struct.pack("<QQQ", 0, flat, fs))
        self.uc.reg_write(UC_X86_REG_GDTR, (0, GDT_BASE, 0x17, 0))
        for reg in (UC_X86_REG_SS, UC_X86_REG_DS, UC_X86_REG_ES):
            self.uc.reg_write(reg, 1 << 3)
        self.uc.reg_write(UC_X86_REG_FS, (2 << 3) | 3)

    def _bind_imports(self):
        self.uc.mem_map(STUB_BASE, 0x100000, UC_PROT_ALL)
        index = 0
        for entry in self.pe.DIRECTORY_ENTRY_IMPORT:
            dll = entry.dll.decode().upper()
            for imp in entry.imports:
                stub = STUB_BASE + 4 * index
                name = imp.name.decode() if imp.name else f"#{imp.ordinal}"
                self.imports[stub] = Import(dll, name)
                self.uc.mem_write(imp.address, struct.pack("<I", stub))
                index += 1
        self.uc.mem_write(STUB_BASE, b"\xC3" * (4 * index))

    # -- register and memory helpers --------------------------------------
    def reg(self, r):
        return self.uc.reg_read(r)

    def u32(self, addr):
        return struct.unpack("<I", self.uc.mem_read(addr, 4))[0]

    def i32(self, addr):
        return struct.unpack("<i", self.uc.mem_read(addr, 4))[0]

    def put32(self, addr, value):
        self.uc.mem_write(addr, struct.pack("<I", value & 0xFFFFFFFF))

    def arg(self, n):
        """n-th stack argument (0-based) at a function entry."""
        return self.u32(self.reg(UC_X86_REG_ESP) + 4 + 4 * n)

    def cstr(self, addr, limit=4096):
        """NUL-terminated string, read in chunks that never cross a page boundary."""
        out = bytearray()
        while len(out) < limit:
            chunk = bytes(self.uc.mem_read(addr + len(out), 0x1000 - ((addr + len(out)) & 0xFFF)))
            end = chunk.find(b"\0")
            if end >= 0:
                out += chunk[:end]
                break
            out += chunk
        return out[:limit].decode("latin-1")

    def return_from_call(self, eax, pop_bytes):
        esp = self.reg(UC_X86_REG_ESP)
        ret = self.u32(esp)
        self.uc.reg_write(UC_X86_REG_EAX, eax & 0xFFFFFFFF)
        self.uc.reg_write(UC_X86_REG_ESP, esp + 4 + pop_bytes)
        self.uc.reg_write(UC_X86_REG_EIP, ret)

    # -- hooks -------------------------------------------------------------
    def _on_stub(self, uc, address, size, _user):
        imp = self.imports.get(address)
        if imp is None:
            return
        handler = self.api.handler(imp.dll, imp.name)
        if handler is None:
            self._stop(f"unhandled import {imp.dll}!{imp.name} called from {self.u32(self.reg(UC_X86_REG_ESP)):#x}")
            return
        try:
            eax, pop = handler()
        except EmulationStop as stop:
            self._stop(str(stop))
            return
        except Exception as err:
            self._stop(f"{imp.dll}!{imp.name} handler failed: {err!r}")
            return
        self.return_from_call(eax, pop)

    def _on_cpp(self, uc, address, size, _user):
        handler = HANDLERS.get(address)
        if handler is None:
            return
        self.current_callback = address
        try:
            result = handler(self)
        except WaitingForInput as wait:
            self._stop(f"engine waits for input: {wait}")
            return
        self.return_from_call(result, 0)

    def _on_bad_memory(self, uc, access, address, size, value, _user):
        self.trace.append(f"invalid memory access {access} at {address:#x} (eip {self.reg(UC_X86_REG_EIP):#x})")
        return False

    def _stop(self, reason):
        self.trace.append(reason)
        self.uc.emu_stop()

    # -- running -----------------------------------------------------------
    def call(self, func, *args, limit=0):
        """Call a stdcall/cdecl function and run until it returns."""
        esp = STACK_BASE + STACK_SIZE - 0x100
        for a in reversed((RETURN_SENTINEL, *args)):
            esp -= 4
            self.put32(esp, a)
        self.uc.reg_write(UC_X86_REG_ESP, esp)
        self.trace.clear()
        try:
            self.uc.emu_start(func, RETURN_SENTINEL, timeout=1000 * self.timeout_ms, count=limit)
        except UcError as err:
            self.trace.append(f"{err} at eip {self.reg(UC_X86_REG_EIP):#x}")
        finished = self.reg(UC_X86_REG_EIP) == RETURN_SENTINEL
        if not finished and not self.trace and self.timeout_ms:
            self.trace.append(f"no return within {self.timeout_ms} ms (eip {self.reg(UC_X86_REG_EIP):#x}); the engine loops")
        return finished, self.reg(UC_X86_REG_EAX)

    def initialize(self) -> int:
        """Engine start-up, as CMainFrame::OnCreate calls it: stdcall 0x4A6730(0)."""
        finished, eax = self.call(ENGINE_INIT, 0)
        if not finished:
            raise RuntimeError("engine initialisation did not return: " + "; ".join(self.trace[-5:]))
        return eax

    def command(self, text: str) -> EngineResult:
        """Send one command line, as SendCommand/0x5925B0 do for menu and typed commands."""
        self.uc.mem_write(COMMAND, text.encode("latin-1") + b"\0")
        self.uc.mem_write(LINE_BUF, text.encode("latin-1").ljust(0x200, b" "))
        self.uc.mem_write(MESSAGE_BUF, b" " * 0x200)
        self.put32(FLAG_9A9498, 0)
        self.put32(ENGINE_ZOOM, self.u32(ZOOM))
        return self._interpret(TEXT_OUT)

    def open_document(self, windows_path: str) -> EngineResult:
        """Open a file the way CWScoreView does (0x5E5360): line buffer "~~R" (read; "~~W" writes)."""
        self.uc.mem_write(LINE_BUF, b"~~R\0")
        self.uc.mem_write(COMMAND, windows_path.encode("latin-1") + b"\0")
        return self._interpret(TEXT_BUF_DIRECT)

    def _interpret(self, text_out: int) -> EngineResult:
        status_addr = STACK_BASE + 0x100
        self.put32(status_addr, 0)
        finished, _ = self.call(INTERPRETER, VECTOR_BUF, VECTOR_LEN, text_out, TEXT_LEN, status_addr)
        if not finished:
            raise RuntimeError("engine did not return: " + "; ".join(self.trace[-5:]))
        n = max(self.i32(VECTOR_LEN), 0)
        words = struct.unpack(f"<{n}i", self.uc.mem_read(VECTOR_BUF, 4 * n))
        vector = [tuple(words[i:i + 3]) for i in range(0, n - 2, 3)]
        text = bytes(self.uc.mem_read(text_out, max(self.i32(TEXT_LEN), 0)))
        message = bytes(self.uc.mem_read(LINE_BUF, 0x200)).decode("latin-1").rstrip(" \0")
        return EngineResult(self.i32(status_addr), vector, text, message)
