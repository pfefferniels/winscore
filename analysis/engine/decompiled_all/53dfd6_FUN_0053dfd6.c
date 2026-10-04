// FUN_0053dfd6 @ 0053dfd6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


int FUN_0053dfd6(int *param_1)

{
  int iVar1;
  
  DAT_0078cd30 = (int)ROUND((float)(&DAT_01f95d54)[*param_1 * 0xf]) % 100;
  iVar1 = (DAT_0078cd30 / 10) * 10;
  if (iVar1 == 0) {
    DAT_0078cd30 = (int)ROUND((float)(&DAT_01f95d50)[*param_1 * 0xf]);
    iVar1 = 10;
    if (6 < DAT_0078cd30) {
      iVar1 = 0x14;
    }
  }
  return iVar1;
}


