// FUN_004e1b2a @ 004e1b2a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004e1b2a(void)

{
  int iVar1;
  
  iVar1 = 0xc;
  DAT_008c8850 = 0;
  do {
    (&DAT_01cade58)[DAT_008c8850] = (&DAT_01aad694)[DAT_01b12c90 * 0xc + DAT_008c8850];
    (&DAT_01cade64)[DAT_008c8850] = (&DAT_01aad748)[DAT_01b12c90 * 0xc + DAT_008c8850];
    DAT_008c8850 = DAT_008c8850 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


