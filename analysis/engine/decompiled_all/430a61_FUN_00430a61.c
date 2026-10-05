// FUN_00430a61 @ 00430a61 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00430a61(void)

{
  if (DAT_0078b6a0 != DAT_00791444) {
    DAT_020b8e6c = OUTPUT_MODE;
    OUTPUT_MODE = 0;
    load_font_metrics();
    OUTPUT_MODE = DAT_020b8e6c;
  }
  return;
}


