// Applies our names to WScore.exe: analysis/engine/names.tsv (routines) and globals.tsv (data).
// names.tsv: address, name, ...   globals.tsv: address, name, type (int|float|double|short|byte|char[N]|T[N]), ...
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.nio.file.*;
import java.util.*;

public class ApplyNames extends GhidraScript {
    private static DataType scalar(String t) {
        switch (t) {
            case "int": return IntegerDataType.dataType;
            case "float": return FloatDataType.dataType;
            case "double": return DoubleDataType.dataType;
            case "short": return ShortDataType.dataType;
            case "byte": return ByteDataType.dataType;
            case "char": return CharDataType.dataType;
            default: return null;
        }
    }

    private static DataType parse(String t) {
        int bracket = t.indexOf('[');
        if (bracket < 0) return scalar(t);
        DataType element = scalar(t.substring(0, bracket));
        int n = Integer.parseInt(t.substring(bracket + 1, t.length() - 1));
        return element == null ? null : new ArrayDataType(element, n, element.getLength());
    }

    private static List<String[]> rows(Path p) throws Exception {
        List<String[]> out = new ArrayList<>();
        if (!Files.exists(p)) return out;
        List<String> lines = Files.readAllLines(p);
        for (String line : lines.subList(1, lines.size()))
            if (!line.isBlank() && !line.startsWith("#")) out.add(line.split("\t"));
        return out;
    }

    @Override
    public void run() throws Exception {
        Path dir = Paths.get(getScriptArgs()[0]);
        SymbolTable symbols = currentProgram.getSymbolTable();
        Listing listing = currentProgram.getListing();
        int routines = 0, globals = 0;
        for (String[] r : rows(dir.resolve("names.tsv"))) {
            Address a = toAddr(Long.parseLong(r[0], 16));
            Function f = getFunctionAt(a);
            if (f == null) f = createFunction(a, r[1]);
            else f.setName(r[1], SourceType.USER_DEFINED);
            routines++;
        }
        for (String[] r : rows(dir.resolve("globals.tsv"))) {
            Address a = toAddr(Long.parseLong(r[0], 16));
            Symbol primary = symbols.getPrimarySymbol(a);
            if (primary != null && primary.getSource() != SourceType.DEFAULT) primary.setName(r[1], SourceType.USER_DEFINED);
            else symbols.createLabel(a, r[1], SourceType.USER_DEFINED).setPrimary();
            DataType t = r.length > 2 ? parse(r[2].trim()) : null;
            if (t != null) {
                listing.clearCodeUnits(a, a.add(t.getLength() - 1), false);
                listing.createData(a, t);
            }
            globals++;
        }
        println("named " + routines + " routines, " + globals + " globals");
    }
}
