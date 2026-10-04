// Decompiles every non-thunk routine with its entry in [start, end] into <outdir>/<address>_<name>.c
// and writes <outdir>/index.tsv: DecompileRange.java <outdir> <start> <end>
import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.Function;
import java.io.PrintWriter;
import java.nio.file.*;

public class DecompileRange extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path dir = Paths.get(args[0]);
        Files.createDirectories(dir);
        AddressSet range = new AddressSet(toAddr(args[1]), toAddr(args[2]));
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        int done = 0;
        try (PrintWriter index = new PrintWriter(dir.resolve("index.tsv").toFile())) {
            index.println("address\tname\tbytes\tfile");
            for (Function f : currentProgram.getFunctionManager().getFunctions(range, true)) {
                if (f.isThunk() || monitor.isCancelled()) continue;
                DecompileResults r = ifc.decompileFunction(f, 600, monitor);
                String file = String.format("%s_%s.c", f.getEntryPoint().toString().replaceFirst("^0+", ""), f.getName());
                try (PrintWriter out = new PrintWriter(dir.resolve(file).toFile())) {
                    out.printf("// %s @ %s (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)%n%n", f.getName(), f.getEntryPoint());
                    out.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// failed: " + r.getErrorMessage());
                }
                index.printf("%s\t%s\t%d\t%s%n", f.getEntryPoint(), f.getName(), f.getBody().getNumAddresses(), file);
                if (++done % 50 == 0) println("decompiled " + done);
            }
        } finally {
            ifc.dispose();
        }
        println("decompiled " + done + " routines");
    }
}
