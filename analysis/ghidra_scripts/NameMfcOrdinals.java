// Renames MFC ordinal imports using the ordinal map extracted from the import libraries.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.*;
import java.nio.file.*;
import java.util.*;

public class NameMfcOrdinals extends GhidraScript {
    @Override
    public void run() throws Exception {
        Map<String, String> names = new HashMap<>();
        for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
            String[] f = line.split("\t");
            names.put(f[0] + "#" + f[1], f[2]);
        }
        ExternalManager ext = currentProgram.getExternalManager();
        int renamed = 0;
        for (String lib : ext.getExternalLibraryNames()) {
            ExternalLocationIterator it = ext.getExternalLocations(lib);
            while (it.hasNext()) {
                ExternalLocation loc = it.next();
                String label = loc.getLabel();
                if (!label.startsWith("Ordinal_")) continue;
                String symbol = names.get(lib.toUpperCase() + "#" + label.substring(8));
                if (symbol == null) continue;
                loc.setName(loc.getParentNameSpace(), symbol, SourceType.IMPORTED);
                renamed++;
            }
        }
        println("renamed " + renamed + " ordinal imports");
    }
}
