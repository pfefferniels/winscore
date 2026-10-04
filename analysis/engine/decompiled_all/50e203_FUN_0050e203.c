// FUN_0050e203 @ 0050e203 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050e203(void)

{
  if (IP9 != 0) {
    DAT_01a27704 = (int)ROUND(X_POS);
    if (f_199 < P2) {
      DAT_01a27704 = DAT_01a27704 + 0x8502;
    }
    DAT_01a27708 = (int)ROUND(Y_POS);
    thunk_FUN_0056f14d(&P9);
    DAT_0078d850 = 1;
    IP9 = 0;
  }
  if (P8 != f_0) {
    _DAT_00940e24 = (int)ROUND(P8 * f_2);
    if (IP5 == 0) {
      thunk_FUN_004d4ed2(&DAT_00940e24);
    }
    else {
      DAT_01aae32c = (float)_DAT_00940e24;
      thunk_FUN_004cf0d3();
    }
    IP8 = 0;
  }
  return;
}


