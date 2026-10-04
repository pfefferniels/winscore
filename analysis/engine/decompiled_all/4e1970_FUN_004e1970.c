// FUN_004e1970 @ 004e1970 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e1970(void)

{
  (&DAT_01aad694)[DAT_01b12c90 * 0xc + _DAT_01aad7ac] = DAT_01ade7c7;
  (&DAT_01aad748)[DAT_01b12c90 * 0xc + _DAT_01aad7ac] = (undefined1)DAT_01aad7b0;
  DAT_0078d934 = DAT_01ade7c7 + -0x42;
  if (DAT_0078d934 < 1) {
    DAT_0078d934 = DAT_01ade7c7 + -0x3b;
  }
  *(undefined4 *)(&DAT_01cadd20 + DAT_0078d934 * 4 + DAT_01ade7dc * 0x1c) = DAT_01aad7b0;
  FUN_004e1b2a();
  return;
}


