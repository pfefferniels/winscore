// FUN_004e7eea @ 004e7eea (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004e7eea(void)

{
  int iVar1;
  
  DAT_01f95c88 = 1;
  for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_01f95c8c = (&DAT_020492a4)[DAT_01f95c88];
    if (0 < DAT_01f95c8c) {
      *(float *)(&DAT_02053438 + DAT_01f95c8c * 4) =
           P1 + *(float *)(&DAT_02053438 + DAT_01f95c8c * 4);
    }
    DAT_01f95c88 = DAT_01f95c88 + 1;
  }
  return;
}


