// Types the read-only constants the FORTRAN engine reads, so the decompiler prints their values.
// An address read by an x87 instruction becomes float/double (floats are also copied with MOV),
// one read only by integer instructions becomes int. Each gets a label spelling its value
// (f_16, f_m1, f_0_92, d_..., i_3), since the decompiler prints labels rather than folding the values.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

public class TypeConstants extends GhidraScript {
    private static final long ENGINE_START = 0x40BC18L, ENGINE_END = 0x58C7E2L;

    private DataType typeFor(Instruction ins, int operand) {
        String m = ins.getMnemonicString().toUpperCase();
        String rep = ins.getDefaultOperandRepresentation(operand).toLowerCase();
        boolean x87 = m.startsWith("F") && !m.startsWith("FI") && !m.contains("CW") && !m.contains("SW")
            && !m.contains("ENV") && !m.contains("SAVE") && !m.contains("RSTOR");
        if (x87 && (rep.startsWith("float") || rep.startsWith("dword"))) return FloatDataType.dataType;
        if (x87 && (rep.startsWith("double") || rep.startsWith("qword"))) return DoubleDataType.dataType;
        if (m.startsWith("FI") && rep.startsWith("dword")) return IntegerDataType.dataType;
        if (!m.startsWith("F") && rep.startsWith("dword")) return IntegerDataType.dataType;
        return null;
    }

    private static String spell(String number) {
        String n = number.endsWith(".0") ? number.substring(0, number.length() - 2) : number;
        return n.replace("-", "m").replace(".", "_").replace("+", "");
    }

    private String label(Address a, DataType t) throws Exception {
        if (t instanceof FloatDataType) return "f_" + spell(Float.toString(Float.intBitsToFloat(getInt(a))));
        if (t instanceof DoubleDataType) return "d_" + spell(Double.toString(Double.longBitsToDouble(getLong(a))));
        return "i_" + spell(Integer.toString(getInt(a)));
    }

    /** Floats copied with MOV and never read by the FPU look like large integers with a short float spelling. */
    private boolean looksLikeFloat(Address a) throws Exception {
        int bits = getInt(a);
        float f = Float.intBitsToFloat(bits);
        return Math.abs(bits) > 0x100000 && Float.isFinite(f) && Float.toString(f).length() <= 9;
    }

    @Override
    public void run() throws Exception {
        MemoryBlock rdata = currentProgram.getMemory().getBlock(".rdata");
        println(".rdata writable: " + rdata.isWrite());
        AddressSet engine = new AddressSet(toAddr(ENGINE_START), toAddr(ENGINE_END));
        Map<Address, DataType> chosen = new HashMap<>();
        Set<Address> conflicting = new HashSet<>();
        for (Instruction ins : currentProgram.getListing().getInstructions(engine, true)) {
            for (int op = 0; op < ins.getNumOperands(); op++) {
                for (Reference ref : ins.getOperandReferences(op)) {
                    Address to = ref.getToAddress();
                    if (!rdata.contains(to)) continue;
                    DataType t = typeFor(ins, op);
                    if (t == null) continue;
                    DataType prior = chosen.get(to);
                    boolean priorIsInt = prior == null || prior instanceof IntegerDataType;
                    if (priorIsInt) chosen.put(to, t);
                    else if (!(t instanceof IntegerDataType) && !prior.isEquivalent(t)) conflicting.add(to);
                }
            }
        }
        int typed = 0, skipped = 0;
        Listing listing = currentProgram.getListing();
        for (Map.Entry<Address, DataType> e : chosen.entrySet()) {
            Address a = e.getKey();
            if (conflicting.contains(a)) { skipped++; continue; }
            if (e.getValue() instanceof IntegerDataType && looksLikeFloat(a)) e.setValue(FloatDataType.dataType);
            Data existing = listing.getDataContaining(a);
            boolean ours = existing != null && (existing.getDataType() instanceof IntegerDataType || existing.getDataType() instanceof FloatDataType);
            if (existing != null && existing.isDefined() && !Undefined.isUndefined(existing.getDataType()) && !ours
                && !(existing.getAddress().equals(a) && existing.getDataType().isEquivalent(e.getValue()))) { skipped++; continue; }
            try {
                listing.clearCodeUnits(a, a.add(e.getValue().getLength() - 1), false);
                listing.createData(a, e.getValue());
                currentProgram.getSymbolTable().createLabel(a, label(a, e.getValue()), SourceType.USER_DEFINED).setPrimary();
                typed++;
            } catch (Exception ex) {
                skipped++;
            }
        }
        println("typed " + typed + " constants, skipped " + skipped + " (" + conflicting.size() + " with conflicting uses)");
    }
}
