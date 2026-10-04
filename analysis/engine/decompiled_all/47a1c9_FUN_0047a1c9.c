// FUN_0047a1c9 @ 0047a1c9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0047a1c9(int *param_1)

{
  int iVar1;
  
  DAT_01ba0d60 = *param_1;
  DAT_008283fc = 1;
  DAT_01ba0d64 = DAT_01ba0d60;
  for (iVar1 = DAT_01ba0d68; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_008283f8 = param_1[DAT_008283fc + -1];
    if (DAT_008283f8 < DAT_01ba0d60) {
      DAT_01ba0d60 = DAT_008283f8;
    }
    if (DAT_01ba0d64 < DAT_008283f8) {
      DAT_01ba0d64 = DAT_008283f8;
    }
    DAT_008283fc = DAT_008283fc + 1;
  }
  return;
}


