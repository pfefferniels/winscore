// FUN_004cb5f5 @ 004cb5f5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cb5f5(void)

{
  if ((DAT_01aae490 != f_0) &&
     (((f_0 < DAT_01aae490 || (_DAT_01aae488 <= f_0)) || (DAT_01aae490 == f_m14)))) {
    DAT_01aae494 = DAT_01aae494 + 1;
    *(float *)(&DAT_01ea1434 + DAT_01aae494 * 4) = DAT_01aae490;
    _DAT_01aae488 = DAT_01aae490;
  }
  return;
}


