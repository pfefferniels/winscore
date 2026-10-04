// Decompiles the functions at the given addresses into one C file: Decompile.java <out.c> <addr>...
import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import java.io.PrintWriter;

public class Decompile extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        try (PrintWriter out = new PrintWriter(args[0])) {
            for (int i = 1; i < args.length; i++) {
                Function f = getFunctionContaining(toAddr(args[i]));
                if (f == null) { out.printf("// no function at %s%n%n", args[i]); continue; }
                DecompileResults r = ifc.decompileFunction(f, 120, monitor);
                out.printf("// ===== %s @ %s =====%n", f.getName(true), f.getEntryPoint());
                out.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// failed: " + r.getErrorMessage());
            }
        } finally {
            ifc.dispose();
        }
    }
}
