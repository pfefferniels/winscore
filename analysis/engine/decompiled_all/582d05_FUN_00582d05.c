// FUN_00582d05 @ 00582d05 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00582d05(void)

{
  int iVar1;
  
  iVar1 = 6;
  DAT_009a908c = 2;
  do {
    *(float *)(&P0 + DAT_009a908c * 4) = (&P1)[DAT_009a908c];
    DAT_009a908c = DAT_009a908c + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


