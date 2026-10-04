// FUN_00502525 @ 00502525 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00502525(byte *param_1)

{
  DAT_009029d0 = (uint)*param_1;
  if ((0x60 < DAT_009029d0) && (DAT_009029d0 < 0x7b)) {
    *param_1 = *param_1 - 0x20;
  }
  return;
}


