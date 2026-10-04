"""Minimal Win32 API surface needed by the WScore.exe engine and its runtimes."""
from __future__ import annotations

import datetime
import os
import struct
from dataclasses import dataclass, field
from pathlib import Path, PureWindowsPath
from typing import TYPE_CHECKING, BinaryIO, Callable

from unicorn import UC_PROT_ALL

if TYPE_CHECKING:
    from emu import Engine

HEAP_BASE, HEAP_SIZE = 0x60000000, 0x08000000
INVALID_HANDLE = 0xFFFFFFFF
ERROR_FILE_NOT_FOUND, ERROR_INVALID_HANDLE, ERROR_NO_MORE_FILES = 2, 6, 18
CWD = "C:\\WORK"
FIXED_TIME = datetime.datetime(2013, 11, 1, 12, 0, 0)


def filetime(dt: datetime.datetime) -> int:
    return int((dt - datetime.datetime(1601, 1, 1)).total_seconds() * 10_000_000)


def systemtime(dt: datetime.datetime) -> bytes:
    return struct.pack("<8H", dt.year, dt.month, dt.isoweekday() % 7, dt.day, dt.hour, dt.minute, dt.second, 0)

GENERIC_WRITE = 0x40000000
CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING, OPEN_ALWAYS, TRUNCATE_EXISTING = 1, 2, 3, 4, 5


@dataclass
class BumpHeap:
    """Never-freeing allocator; adequate for single command runs."""
    next: int = HEAP_BASE
    sizes: dict[int, int] = field(default_factory=dict)

    def alloc(self, size: int) -> int:
        addr = self.next
        self.next = (addr + max(size, 1) + 15) & ~15
        if self.next > HEAP_BASE + HEAP_SIZE:
            raise MemoryError("emulated heap exhausted")
        self.sizes[addr] = size
        return addr


@dataclass
class OpenFile:
    path: Path
    stream: BinaryIO


class WinApi:
    def __init__(self, engine: "Engine"):
        self.e = engine
        engine.uc.mem_map(HEAP_BASE, HEAP_SIZE, UC_PROT_ALL)
        self.heap = BumpHeap()
        self.files: dict[int, OpenFile] = {}
        self.next_handle = 0x1000
        self.last_error = 0
        self.log: list[str] = []
        self.table: dict[tuple[str, str], Callable[[], tuple[int, int]]] = {
            (dll, name[2:]): getattr(self, name)
            for name in dir(self) if name.startswith("k_")
            for dll in ("KERNEL32.DLL",)
        }

    def handler(self, dll: str, name: str):
        return self.table.get((dll, name))

    # -- path sandboxing ---------------------------------------------------
    def host_path(self, win_path: str) -> Path:
        """Map a Windows path into the sandbox root.

        C:\\winscore\\... and the Program Files variants map to the WINSCORE
        install; every other absolute path maps below root/c/.
        """
        p = PureWindowsPath(win_path)
        parts = [x for x in p.parts if x not in ("\\", "/")]
        if p.drive:
            parts = parts[1:]
        lowered = [x.lower() for x in parts]
        for prefix in (["winscore"], ["program files", "winscore"], ["program files (x86)", "winscore"]):
            if lowered[:len(prefix)] == prefix:
                return self.e.root / "winscore" / Path(*parts[len(prefix):]) if parts[len(prefix):] else self.e.root / "winscore"
        if lowered[:1] == ["work"]:
            return self.e.root / "cwd" / Path(*parts[1:])
        if p.is_absolute() or p.drive:
            return self.e.root / "c" / Path(*parts)
        return self.e.root / "cwd" / Path(*parts)

    @staticmethod
    def resolve_case(path: Path) -> Path:
        """Follow existing directory entries case-insensitively, as Windows does."""
        resolved = Path(path.anchor)
        for part in path.parts[1:]:
            candidate = resolved / part
            if not candidate.exists() and resolved.is_dir():
                match = next((c for c in resolved.iterdir() if c.name.lower() == part.lower()), None)
                candidate = match or candidate
            resolved = candidate
        return resolved

    def new_handle(self) -> int:
        self.next_handle += 4
        return self.next_handle

    # -- memory ------------------------------------------------------------
    def k_HeapCreate(self):
        return 0x00500000, 12

    def k_HeapDestroy(self):
        return 1, 4

    def k_HeapAlloc(self):
        size = self.e.arg(2)
        addr = self.heap.alloc(size)
        if self.e.arg(1) & 0x8:
            self.e.uc.mem_write(addr, b"\0" * size)
        return addr, 12

    def k_HeapReAlloc(self):
        old, size = self.e.arg(2), self.e.arg(3)
        if old not in self.heap.sizes:
            raise ValueError(f"HeapReAlloc of unknown block {old:#x} to {size} bytes")
        new = self.heap.alloc(size)
        keep = min(size, self.heap.sizes[old])
        self.e.uc.mem_write(new, bytes(self.e.uc.mem_read(old, keep)))
        return new, 16

    def k_HeapFree(self):
        return 1, 12

    def k_HeapSize(self):
        return self.heap.sizes.get(self.e.arg(2), 0), 12

    def k_VirtualAlloc(self):
        """Reserve 64 KB-aligned regions; commits inside a reservation return the address."""
        wanted, size = self.e.arg(0), self.e.arg(1)
        if wanted:
            return wanted & ~0xFFF, 16
        addr = (self.heap.alloc(size + 0xFFFF) + 0xFFFF) & ~0xFFFF
        self.heap.sizes[addr] = size
        return addr, 16

    def k_VirtualFree(self):
        return 1, 12

    def k_GlobalAlloc(self):
        size = self.e.arg(1)
        addr = self.heap.alloc(size)
        self.e.uc.mem_write(addr, b"\0" * size)
        return addr, 8

    def k_GlobalLock(self):
        return self.e.arg(0), 4

    def k_GlobalUnlock(self):
        return 1, 4

    def k_GlobalFree(self):
        return 0, 4

    # -- process and environment ------------------------------------------
    def k_GetLastError(self):
        return self.last_error, 0

    def k_GetVersion(self):
        return 0x0A280105, 0  # Windows XP-like: major 5, minor 1

    def k_GetModuleHandleA(self):
        return 0x400000, 4

    def k_GetModuleFileNameA(self):
        buf, size = self.e.arg(1), self.e.arg(2)
        name = b"C:\\winscore\\WScore.exe\0"
        self.e.uc.mem_write(buf, name[:size])
        return len(name) - 1, 12

    def k_GetCurrentProcess(self):
        return 0xFFFFFFFF, 0

    def k_GetLocalTime(self):
        self.e.uc.mem_write(self.e.arg(0), systemtime(FIXED_TIME))
        return 0, 4

    def k_SetErrorMode(self):
        return 0, 4

    def k_Sleep(self):
        return 0, 4

    def k_GetACP(self):
        return 1252, 0

    def k_GetOEMCP(self):
        return 437, 0

    def k_GetCPInfo(self):
        info = struct.pack("<I2s12s", 1, b"?\0", b"\0" * 12)
        self.e.uc.mem_write(self.e.arg(1), info)
        return 1, 8

    def k_lstrlenA(self):
        return len(self.e.cstr(self.e.arg(0))), 4

    def k_lstrcpyA(self):
        dst, src = self.e.arg(0), self.e.arg(1)
        self.e.uc.mem_write(dst, self.e.cstr(src).encode("latin-1") + b"\0")
        return dst, 8

    def k_GetStdHandle(self):
        return 0, 4

    def k_GetStartupInfoA(self):
        self.e.uc.mem_write(self.e.arg(0), struct.pack("<I", 68) + b"\0" * 64)
        return 0, 4

    def _static_string(self, attr: str, data: bytes) -> int:
        if not hasattr(self, attr):
            addr = self.heap.alloc(len(data))
            self.e.uc.mem_write(addr, data)
            setattr(self, attr, addr)
        return getattr(self, attr)

    def k_GetCommandLineA(self):
        return self._static_string("_cmdline", b"C:\\winscore\\WScore.exe\0"), 0

    def k_GetEnvironmentStrings(self):
        return self._static_string("_env_a", b"PATH=C:\\WINDOWS\0\0"), 0

    def k_GetEnvironmentStringsW(self):
        return self._static_string("_env_w", "PATH=C:\\WINDOWS\0\0".encode("utf-16le")), 0

    def k_FreeEnvironmentStringsA(self):
        return 1, 4

    def k_FreeEnvironmentStringsW(self):
        return 1, 4

    def k_LoadLibraryA(self):
        self.log.append(f"LoadLibraryA {self.e.cstr(self.e.arg(0))!r} -> refused")
        return 0, 4

    def k_GetProcAddress(self):
        name = self.e.arg(1)
        label = self.e.cstr(name) if name > 0xFFFF else f"#{name}"
        self.log.append(f"GetProcAddress {label!r} -> not found")
        return 0, 8

    def k_SetHandleCount(self):
        return self.e.arg(0), 4

    def k_MultiByteToWideChar(self):
        _cp, _flags, src, n, dst, dst_len = (self.e.arg(i) for i in range(6))
        raw = bytes(self.e.uc.mem_read(src, n)) if n != 0xFFFFFFFF else (self.e.cstr(src) + "\0").encode("latin-1")
        wide = raw.decode("cp1252", errors="replace").encode("utf-16le")
        count = len(wide) // 2
        if dst_len == 0:
            return count, 24
        self.e.uc.mem_write(dst, wide[:2 * dst_len])
        return min(count, dst_len), 24

    def k_WideCharToMultiByte(self):
        _cp, _flags, src, n, dst, dst_len = (self.e.arg(i) for i in range(6))
        if n == 0xFFFFFFFF:
            raw = b""
            while not raw.endswith(b"\0\0") or len(raw) % 2:
                raw += bytes(self.e.uc.mem_read(src + len(raw), 2))
        else:
            raw = bytes(self.e.uc.mem_read(src, 2 * n))
        narrow = raw.decode("utf-16le").encode("cp1252", errors="replace")
        if dst_len == 0:
            return len(narrow), 32
        self.e.uc.mem_write(dst, narrow[:dst_len])
        return min(len(narrow), dst_len), 32

    def k_GetStringTypeW(self):
        _type, src, n, out = (self.e.arg(i) for i in range(4))
        self.e.uc.mem_write(out, b"\0\0" * (n if n != 0xFFFFFFFF else 1))
        return 1, 16

    def k_GetStringTypeA(self):
        return 0, 20

    def k_LCMapStringW(self):
        return 0, 24

    def k_LCMapStringA(self):
        return 0, 24

    # -- files -------------------------------------------------------------
    def k_CreateFileA(self):
        name = self.e.cstr(self.e.arg(0))
        access, disposition = self.e.arg(1), self.e.arg(4)
        path = self.resolve_case(self.host_path(name))
        writing = bool(access & GENERIC_WRITE)
        exists = path.exists()
        self.log.append(f"CreateFileA {name!r} -> {path} disp={disposition} write={writing}")
        if disposition in (OPEN_EXISTING, TRUNCATE_EXISTING) and not exists:
            self.last_error = ERROR_FILE_NOT_FOUND
            return INVALID_HANDLE, 28
        if disposition == CREATE_NEW and exists:
            self.last_error = 80
            return INVALID_HANDLE, 28
        path.parent.mkdir(parents=True, exist_ok=True)
        if disposition in (CREATE_ALWAYS, TRUNCATE_EXISTING, CREATE_NEW):
            mode = "w+b"
        elif exists:
            mode = "r+b" if writing else "rb"
        else:
            mode = "w+b"
        handle = self.new_handle()
        self.files[handle] = OpenFile(path, open(path, mode))
        self.last_error = 0
        return handle, 28

    def k_ReadFile(self):
        handle, buf, n, read_ptr = (self.e.arg(i) for i in range(4))
        if handle not in self.files:
            # A GUI process has no console: GetStdHandle gives 0 and reading it fails, as on Windows.
            self.e.shell.record("console-read", f"{n} bytes from handle {handle:#x}, failed as invalid")
            if read_ptr:
                self.e.put32(read_ptr, 0)
            self.last_error = ERROR_INVALID_HANDLE
            return 0, 20
        data = self.files[handle].stream.read(n)
        self.e.uc.mem_write(buf, data)
        if read_ptr:
            self.e.put32(read_ptr, len(data))
        return 1, 20

    def k_WriteFile(self):
        handle, buf, n, written_ptr = (self.e.arg(i) for i in range(4))
        data = bytes(self.e.uc.mem_read(buf, n))
        if handle in self.files:
            self.files[handle].stream.write(data)
        else:
            self.log.append(f"WriteFile to handle {handle:#x}: {data[:200]!r}")
        if written_ptr:
            self.e.put32(written_ptr, n)
        return 1, 20

    def k_SetFilePointer(self):
        handle, dist, high_ptr, method = (self.e.arg(i) for i in range(4))
        stream = self.files[handle].stream
        offset = struct.unpack("<i", struct.pack("<I", dist))[0]
        stream.seek(offset, (os.SEEK_SET, os.SEEK_CUR, os.SEEK_END)[method])
        return stream.tell(), 16

    def k_SetEndOfFile(self):
        self.files[self.e.arg(0)].stream.truncate()
        return 1, 4

    def k_CloseHandle(self):
        f = self.files.pop(self.e.arg(0), None)
        if f:
            f.stream.close()
        return 1, 4

    def k_GetFileType(self):
        return (1 if self.e.arg(0) in self.files else 2), 4

    def k_GetFileAttributesA(self):
        path = self.host_path(self.e.cstr(self.e.arg(0)))
        if not path.exists():
            self.last_error = ERROR_FILE_NOT_FOUND
            return INVALID_HANDLE, 4
        return (0x10 if path.is_dir() else 0x80), 4

    def k_FlushFileBuffers(self):
        return 1, 4

    # -- second batch: time, directories, misc ----------------------------
    def k_GetSystemTimeAsFileTime(self):
        self.e.uc.mem_write(self.e.arg(0), struct.pack("<Q", filetime(FIXED_TIME)))
        return 0, 4

    def k_GetSystemTime(self):
        self.e.uc.mem_write(self.e.arg(0), systemtime(FIXED_TIME))
        return 0, 4

    def k_GetTimeZoneInformation(self):
        self.e.uc.mem_write(self.e.arg(0), b"\0" * 172)
        return 0, 4

    def k_FileTimeToSystemTime(self):
        ft = struct.unpack("<Q", self.e.uc.mem_read(self.e.arg(0), 8))[0]
        dt = datetime.datetime(1601, 1, 1) + datetime.timedelta(microseconds=ft // 10)
        self.e.uc.mem_write(self.e.arg(1), systemtime(dt))
        return 1, 8

    def k_FileTimeToLocalFileTime(self):
        self.e.uc.mem_write(self.e.arg(1), bytes(self.e.uc.mem_read(self.e.arg(0), 8)))
        return 1, 8

    k_LocalFileTimeToFileTime = k_FileTimeToLocalFileTime

    def k_SystemTimeToFileTime(self):
        y, mo, _dow, d, h, mi, sec, _ms = struct.unpack("<8H", self.e.uc.mem_read(self.e.arg(0), 16))
        self.e.uc.mem_write(self.e.arg(1), struct.pack("<Q", filetime(datetime.datetime(y, mo, d, h, mi, sec))))
        return 1, 8

    def k_GetProcessTimes(self):
        for i in range(1, 5):
            self.e.uc.mem_write(self.e.arg(i), b"\0" * 8)
        return 1, 20

    def k_GetVersionExA(self):
        info = self.e.arg(0)
        self.e.uc.mem_write(info + 4, struct.pack("<4I", 5, 1, 2600, 2))
        return 1, 4

    def k_SetLastError(self):
        self.last_error = self.e.arg(0)
        return 0, 4

    def k_SetUnhandledExceptionFilter(self):
        return 0, 4

    def k_SetConsoleCtrlHandler(self):
        return 1, 8

    def k_IsBadReadPtr(self):
        return 0, 8

    k_IsBadWritePtr = k_IsBadReadPtr

    def k_IsBadCodePtr(self):
        return 0, 4

    def k_InitializeCriticalSection(self):
        return 0, 4

    k_EnterCriticalSection = k_InitializeCriticalSection
    k_LeaveCriticalSection = k_InitializeCriticalSection

    def k_TlsSetValue(self):
        return 1, 8

    def k_GetCurrentThread(self):
        return 0xFFFFFFFE, 0

    def k_SetThreadPriority(self):
        return 1, 8

    def k_MulDiv(self):
        a, b, c = (struct.unpack("<i", struct.pack("<I", self.e.arg(i)))[0] for i in range(3))
        return (round(a * b / c) if c else -1), 12

    def k_Beep(self):
        return 1, 8

    def k_LocalAlloc(self):
        size = self.e.arg(1)
        addr = self.heap.alloc(size)
        self.e.uc.mem_write(addr, b"\0" * size)
        return addr, 8

    def k_LocalFree(self):
        return 0, 4

    def k_LocalLock(self):
        return self.e.arg(0), 4

    def k_LocalUnlock(self):
        return 1, 4

    def k_LocalReAlloc(self):
        old, size = self.e.arg(0), self.e.arg(1)
        new = self.heap.alloc(size)
        keep = min(size, self.heap.sizes.get(old, 0))
        self.e.uc.mem_write(new, b"\0" * size)
        if keep:
            self.e.uc.mem_write(new, bytes(self.e.uc.mem_read(old, keep)))
        return new, 12

    k_GlobalReAlloc = k_LocalReAlloc

    def k_GlobalHandle(self):
        return self.e.arg(0), 4

    def k_GetCurrentDirectoryA(self):
        size, buf = self.e.arg(0), self.e.arg(1)
        data = CWD.encode() + b"\0"
        if size >= len(data):
            self.e.uc.mem_write(buf, data)
            return len(data) - 1, 8
        return len(data), 8

    def k_SetCurrentDirectoryA(self):
        self.log.append(f"SetCurrentDirectoryA {self.e.cstr(self.e.arg(0))!r} ignored")
        return 1, 4

    def k_GetFullPathNameA(self):
        name, size, buf, file_part = (self.e.arg(i) for i in range(4))
        path = self.e.cstr(name)
        if PureWindowsPath(path).drive:
            full = path
        elif path.startswith("\\"):           # root-relative: on the current drive
            full = CWD[:2] + path
        else:
            full = CWD + "\\" + path
        data = full.encode("latin-1") + b"\0"
        if size < len(data):
            return len(data), 16
        self.e.uc.mem_write(buf, data)
        if file_part:
            self.e.put32(file_part, buf + full.rfind("\\") + 1)
        return len(data) - 1, 16

    def k_GetSystemDirectoryA(self):
        data = b"C:\\WINDOWS\\SYSTEM32\0"
        self.e.uc.mem_write(self.e.arg(0), data[: self.e.arg(1)])
        return len(data) - 1, 8

    def k_GetTempPathA(self):
        data = b"C:\\TEMP\\\0"
        self.e.uc.mem_write(self.e.arg(1), data[: self.e.arg(0)])
        return len(data) - 1, 8

    def k_GetDriveTypeA(self):
        return 3, 4

    def k_GetLogicalDrives(self):
        return 0b100, 0

    def k_GetDiskFreeSpaceA(self):
        for i, v in enumerate((8, 512, 1_000_000, 2_000_000)):
            if self.e.arg(1 + i):
                self.e.put32(self.e.arg(1 + i), v)
        return 1, 20

    def k_CreateDirectoryA(self):
        self.host_path(self.e.cstr(self.e.arg(0))).mkdir(parents=True, exist_ok=True)
        return 1, 8

    def k_RemoveDirectoryA(self):
        return 0, 4

    def k_DeleteFileA(self):
        path = self.host_path(self.e.cstr(self.e.arg(0)))
        if path.is_file():
            path.unlink()
            return 1, 4
        self.last_error = ERROR_FILE_NOT_FOUND
        return 0, 4

    def k_MoveFileA(self):
        src, dst = (self.host_path(self.e.cstr(self.e.arg(i))) for i in range(2))
        if not src.exists():
            self.last_error = ERROR_FILE_NOT_FOUND
            return 0, 8
        src.rename(dst)
        return 1, 8

    def k_SetFileAttributesA(self):
        return 1, 8

    def k_SetFileTime(self):
        return 1, 16

    def k_GetFileInformationByHandle(self):
        f = self.files.get(self.e.arg(0))
        if f is None:
            return 0, 8
        size = f.path.stat().st_size
        ft = struct.pack("<Q", filetime(FIXED_TIME))
        info = struct.pack("<I", 0x80) + ft * 3 + struct.pack("<6I", 0, 0, size, 1, 0, 0)
        self.e.uc.mem_write(self.e.arg(1), info)
        return 1, 8

    def k_FindFirstFileA(self):
        pattern = self.host_path(self.e.cstr(self.e.arg(0)))
        matches = sorted(pattern.parent.glob(pattern.name)) if pattern.parent.is_dir() else []
        matches = [m for m in matches if m.name.lower() == pattern.name.lower() or any(c in pattern.name for c in "*?")] or \
            ([m for m in pattern.parent.iterdir() if m.name.lower() == pattern.name.lower()] if pattern.parent.is_dir() else [])
        if not matches:
            self.last_error = ERROR_FILE_NOT_FOUND
            return INVALID_HANDLE, 8
        handle = self.new_handle()
        self.searches = getattr(self, "searches", {})
        self.searches[handle] = matches
        self._write_find_data(self.e.arg(1), matches.pop(0))
        return handle, 8

    def k_FindNextFileA(self):
        remaining = getattr(self, "searches", {}).get(self.e.arg(0), [])
        if not remaining:
            self.last_error = ERROR_NO_MORE_FILES
            return 0, 8
        self._write_find_data(self.e.arg(1), remaining.pop(0))
        return 1, 8

    def k_FindClose(self):
        getattr(self, "searches", {}).pop(self.e.arg(0), None)
        return 1, 4

    def _write_find_data(self, addr, path: Path):
        ft = struct.pack("<Q", filetime(FIXED_TIME))
        size = path.stat().st_size if path.is_file() else 0
        name = path.name.encode("latin-1")[:259].ljust(260, b"\0")
        attrs = 0x10 if path.is_dir() else 0x80
        self.e.uc.mem_write(addr, struct.pack("<I", attrs) + ft * 3 + struct.pack("<4I", 0, size, 0, 0) + name + b"\0" * 14)

    def k__lopen(self):
        path = self.host_path(self.e.cstr(self.e.arg(0)))
        if not path.exists():
            return INVALID_HANDLE, 8
        handle = self.new_handle()
        self.files[handle] = OpenFile(path, open(path, "rb"))
        return handle, 8

    def k__lread(self):
        data = self.files[self.e.arg(0)].stream.read(self.e.arg(2))
        self.e.uc.mem_write(self.e.arg(1), data)
        return len(data), 12

    def k__lclose(self):
        return self.k_CloseHandle()[0], 4

    def k_FormatMessageA(self):
        return 0, 28

    def k_RtlUnwind(self):
        raise RuntimeError("RtlUnwind: structured exception unwinding is not emulated")

    def k_RaiseException(self):
        raise RuntimeError(f"RaiseException code {self.e.arg(0):#x}")

    def k_ExitProcess(self):
        raise RuntimeError(f"ExitProcess({self.e.arg(0)})")

    def k_TerminateProcess(self):
        raise RuntimeError(f"TerminateProcess({self.e.arg(1)})")

    def k_DebugBreak(self):
        raise RuntimeError("DebugBreak")

    def k_SetEnvironmentVariableA(self):
        return 1, 8

    k_SetEnvironmentVariableW = k_SetEnvironmentVariableA
