"""Create the directory tree the emulated engine sees as its disks.

<root>/winscore  copy of the WINSCORE 5.01 install (C:\\winscore\\...)
<root>/cwd       working directory (C:\\WORK, relative paths)
<root>/c         every other absolute C:\\ path, e.g. C:\\!tmp
The engine writes temporary and history files, so it never runs on the originals.
"""
import shutil
from pathlib import Path

INSTALL = Path(__file__).resolve().parents[1] / "WINSCORE 5.01" / "winscore"


def make_sandbox(root: Path, scores: tuple[Path, ...] = ()) -> Path:
    if not (root / "winscore").exists():
        shutil.copytree(INSTALL, root / "winscore")
    (root / "cwd").mkdir(parents=True, exist_ok=True)
    (root / "c" / "!tmp").mkdir(parents=True, exist_ok=True)
    for score in scores:
        shutil.copy2(score, root / "cwd" / score.name)
    return root
