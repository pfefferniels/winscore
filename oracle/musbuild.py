"""Build small .mus files for oracle experiments (format: see rust/crates/score-format)."""
import struct


def mus_bytes(items: list[list[float]], serial: int = 1111, version: float = 6.0) -> bytes:
    words: list[bytes] = []
    for params in items:
        words.append(struct.pack("<f", float(len(params))))
        words.extend(struct.pack("<f", float(p)) for p in params)
    trailer = [struct.pack("<f", 0.0), struct.pack("<I", serial), struct.pack("<f", version),
               struct.pack("<f", 0.0), struct.pack("<f", 5.0), struct.pack("<f", -9999.0)]
    body = b"".join(words + trailer)
    return struct.pack("<H", len(body) // 4) + body
