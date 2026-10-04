// FUN_00521219 @ 00521219 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00521219(void)

{
  int iVar1;
  
  DAT_01fbb860 = DAT_01aad7c8;
  for (iVar1 = (DAT_01aad7d4 - DAT_01aad7c8) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_01fbb864 = DAT_01fbb860;
    thunk_FUN_0049b1d8();
    FUN_00521109();
    thunk_FUN_004e7eea();
    DAT_01fbb860 = DAT_01fbb860 + 1;
  }
  return;
}


