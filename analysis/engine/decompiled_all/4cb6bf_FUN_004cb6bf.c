// FUN_004cb6bf @ 004cb6bf (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cb6bf(int *param_1)

{
  do {
    DAT_01add2e8 = DAT_01add2e8 + 1;
    DAT_01be1818 = *(float *)(&DAT_01e9cf5c + DAT_01add2e8 * 4);
    if (f_0 < DAT_01be1818) {
      _DAT_01add2f0 = DAT_01be1818 + _DAT_01add2f0;
      return;
    }
    FUN_004cb692(&DAT_01be1818);
  } while (*param_1 == 0);
  return;
}


