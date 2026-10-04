// FUN_004a6258 @ 004a6258 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004a6258(void)

{
  int iVar1;
  
  if (DAT_01e62c80 != 0) {
    DAT_008391b8 = DAT_0078b388;
    for (iVar1 = ((DAT_008391b4 - DAT_0078b388) + -1) / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&DAT_020b909f)[DAT_008391b8] = (&DAT_020b909e)[DAT_008391b8];
      DAT_008391b8 = DAT_008391b8 + -1;
    }
  }
  return;
}


