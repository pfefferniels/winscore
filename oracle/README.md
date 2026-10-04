# Engine oracle

Runs the FORTRAN engine inside `WScore.exe` (WINSCORE 5.01) under the Unicorn CPU emulator, without Windows, MFC or Wine, and returns exactly what the engine would have handed to the Windows view. It is meant as a reference for testing the Rust port.

```sh
python3 -m venv .venv && .venv/bin/pip install -r requirements.txt
.venv/bin/python run_one.py "G carmen.mus" "SA copy.mus"
```

```python
from pathlib import Path
from emu import Engine
from displaylist import shapes, text_runs
from render_svg import to_svg

e = Engine(Path("sandbox")); e.initialize()
r = e.command("G carmen.mus")
Path("carmen.svg").write_text(to_svg(shapes(r.vector), text_runs(r.text)))
```

How it works:

- `emu.py` maps the PE image, sets up a thread block and GDT, runs the CRT start-up through the C initialisers (the MFC constructors are skipped), calls the engine's init routine `0x4A6730`, then the interpreter `0x47EC50` per command.
- `winapi.py` implements the KERNEL32 calls the CRT, the Fortran runtime and the engine use. File paths are mapped into `sandbox/` (see `sandbox.py`). Time is fixed at 2013-11-01 12:00.
- `callbacks.py` replaces the C++ functions the engine calls back: dialogs are logged and return defaults, prompts take answers from `engine.shell.answers`.
- `displaylist.py` decodes the output buffers as the C++ shell does. `render_svg.py` draws them. Text placement in the SVG is approximate (generic font metrics).
- `musbuild.py` writes small `.mus` files for experiments.

Known limits: dialogs do not run, so commands that need one do nothing or use defaults. The FPU control word is set to the Windows default `0x27F`. Bit-exact agreement of floating-point results with a real Windows run has not been verified.
