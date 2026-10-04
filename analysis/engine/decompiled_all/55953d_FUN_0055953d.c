// FUN_0055953d @ 0055953d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055953d(void)

{
  int iVar1;
  
  DAT_0078cd44 = *(int *)(&DAT_0079ede4 + DAT_0078cd44 * 4);
  DAT_009a3c70 = DAT_0078cd44;
  DAT_0078cd58 = *(int *)(&DAT_0079ee14 + DAT_0078cd4c * 4) + DAT_0078cd54;
  iVar1 = (DAT_0078cd58 + 6) % 7;
  DAT_009a3c6c = iVar1 + 1;
  if (DAT_009a3c6c < 1) {
    DAT_009a3c6c = iVar1 + 8;
  }
  _DAT_009a3c68 = DAT_0078cd58 + 100;
  DAT_0078cd54 = DAT_0078cd44 +
                 ((DAT_0078cd58 + 0x22) / 7) * 0xc + *(int *)(&DAT_0079edc4 + DAT_009a3c6c * 4);
  return;
}


