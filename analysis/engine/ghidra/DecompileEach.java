// Decompiles each given routine into <outdir>/<address>_<name>.c: DecompileEach.java <outdir> <addr>...
import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import java.io.PrintWriter;
import java.nio.file.*;

public class DecompileEach extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path dir = Paths.get(args[0]);
        Files.createDirectories(dir);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        try {
            for (int i = 1; i < args.length; i++) {
                Function f = getFunctionContaining(toAddr(args[i]));
                if (f == null) { println("no function at " + args[i]); continue; }
                DecompileResults r = ifc.decompileFunction(f, 300, monitor);
                String file = String.format("%s_%s.c", f.getEntryPoint().toString().replaceFirst("^0+", ""), f.getName());
                try (PrintWriter out = new PrintWriter(dir.resolve(file).toFile())) {
                    out.printf("// %s @ %s (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)%n%n", f.getName(), f.getEntryPoint());
                    out.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// failed: " + r.getErrorMessage());
                }
                println("wrote " + file);
            }
        } finally {
            ifc.dispose();
        }
    }
}
