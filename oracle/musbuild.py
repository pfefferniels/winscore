"""Build small .mus files for oracle experiments (format: see rust/crates/score-format)."""
import struct


def text_item(params: list[float], text: bytes) -> bytes:
    """A code-16 item: P12 must be len(text); the characters follow, blank-padded to whole words."""
    return b"".join(struct.pack("<f", float(p)) for p in params) + text + b" " * (-len(text) % 4)


def item_words(item) -> bytes:
    """Parameters as f32 words, or an item already packed as words (text, copied items)."""
    if isinstance(item, (bytes, bytearray)):
        return bytes(item)
    return b"".join(struct.pack("<f", float(p)) for p in item)


def mus_bytes(items: list, serial: int = 1111, version: float = 6.0) -> bytes:
    words: list[bytes] = []
    for packed in map(item_words, items):
        words.append(struct.pack("<f", float(len(packed) // 4)))
        words.append(packed)
    trailer = [struct.pack("<f", 0.0), struct.pack("<I", serial), struct.pack("<f", version),
               struct.pack("<f", 0.0), struct.pack("<f", 5.0), struct.pack("<f", -9999.0)]
    body = b"".join(words + trailer)
    return struct.pack("<H", len(body) // 4) + body
