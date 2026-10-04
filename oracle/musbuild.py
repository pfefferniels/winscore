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


TRAILER_WORDS = 6


def read_items(data: bytes) -> list[bytes]:
    """The items of a .mus file as packed words (parameters and characters), in file order."""
    short = int.from_bytes(data[:2], "little")
    words = data[2:] if 2 + 4 * short == len(data) else data[4:]
    items, pos = [], 0
    while pos < len(words) - 4 * TRAILER_WORDS:
        length = int(struct.unpack_from("<f", words, pos)[0])   # the engine truncates stray mantissa bits
        if length <= 0:
            break
        items.append(words[pos + 4:pos + 4 + 4 * length])
        pos += 4 + 4 * length
    return items


def param(packed: bytes, n: int) -> float:
    """Pn (1-based) of a packed item, 0 where not stored."""
    return struct.unpack_from("<f", packed, 4 * (n - 1))[0] if len(packed) >= 4 * n else 0.0


def mus_bytes(items: list, serial: int = 1111, version: float = 6.0) -> bytes:
    words: list[bytes] = []
    for packed in map(item_words, items):
        words.append(struct.pack("<f", float(len(packed) // 4)))
        words.append(packed)
    trailer = [struct.pack("<f", 0.0), struct.pack("<I", serial), struct.pack("<f", version),
               struct.pack("<f", 0.0), struct.pack("<f", 5.0), struct.pack("<f", -9999.0)]
    body = b"".join(words + trailer)
    return struct.pack("<H", len(body) // 4) + body
