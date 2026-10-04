// FUN_00546a1b @ 00546a1b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00546a1b(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_009ae2bc;
  puVar3 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = 0x7d;
  DAT_0099f85c = 4;
  do {
    if ((&DAT_020b909f)[DAT_0099f85c] == '-') {
      DAT_0099f858 = (byte)(&DAT_020b90a0)[DAT_0099f85c] - 0x30;
      iVar1 = (byte)(&DAT_020b90a1)[DAT_0099f85c] - 0x30;
      if ((-1 < iVar1) && (iVar1 < 10)) {
        DAT_0099f858 = DAT_0099f858 * 10 + iVar1;
      }
      DAT_0099f854 = (int)ROUND(P3 + f_1);
      iVar1 = 0x29;
      DAT_0099f850 = 4;
      do {
        *(float *)(&P0 + DAT_0099f850 * 4) = (float)DAT_0099f854;
        if (DAT_0099f858 <= DAT_0099f854) {
          return;
        }
        DAT_0099f854 = DAT_0099f854 + 1;
        DAT_0099f850 = DAT_0099f850 + 1;
        iVar1 = iVar1 + -1;
      } while (0 < iVar1);
      return;
    }
    DAT_0099f85c = DAT_0099f85c + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


