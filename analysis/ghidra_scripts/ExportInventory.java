// Writes function, call-graph, string and data-reference tables for offline analysis.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.*;
import java.io.PrintWriter;
import java.nio.file.*;

public class ExportInventory extends GhidraScript {
    private static String clean(String s) {
        return s.replace("\t", "\\t").replace("\n", "\\n").replace("\r", "\\r");
    }

    @Override
    public void run() throws Exception {
        Path out = Paths.get(getScriptArgs()[0]);
        Files.createDirectories(out);
        Listing listing = currentProgram.getListing();
        ReferenceManager refs = currentProgram.getReferenceManager();
        MemoryBlock data = currentProgram.getMemory().getBlock(".data");
        try (PrintWriter fn = new PrintWriter(out.resolve("functions.tsv").toFile());
             PrintWriter calls = new PrintWriter(out.resolve("calls.tsv").toFile());
             PrintWriter strs = new PrintWriter(out.resolve("strings.tsv").toFile());
             PrintWriter drefs = new PrintWriter(out.resolve("datarefs.tsv").toFile())) {
            fn.println("entry\tname\tsize\tcallers\tcallees\tconvention\tparams");
            for (Function f : listing.getFunctions(true)) {
                if (monitor.isCancelled()) break;
                String entry = f.getEntryPoint().toString();
                fn.printf("%s\t%s\t%d\t%d\t%d\t%s\t%d%n", entry, clean(f.getName(true)),
                    f.getBody().getNumAddresses(), f.getCallingFunctions(monitor).size(),
                    f.getCalledFunctions(monitor).size(), f.getCallingConventionName(), f.getParameterCount());
                for (Function callee : f.getCalledFunctions(monitor))
                    calls.printf("%s\t%s%n", entry, callee.getEntryPoint());
                for (Address a : f.getBody().getAddresses(true)) {
                    for (Reference r : refs.getReferencesFrom(a)) {
                        Address to = r.getToAddress();
                        if (!to.isMemoryAddress()) continue;
                        Data d = listing.getDataAt(to);
                        if (d != null && d.hasStringValue())
                            strs.printf("%s\t%s\t%s%n", entry, to, clean(String.valueOf(d.getValue())));
                        else if (data != null && data.contains(to))
                            drefs.printf("%s\t%s\t%s%n", entry, a, to);
                    }
                }
            }
        }
        println("inventory written to " + out);
    }
}
