// FUN_004cb2ea @ 004cb2ea (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cb2ea(void)

{
  int iVar1;
  float10 in_ST0;
  
  if (LOAD_CODE != 8) {
    iVar1 = 5000;
    DAT_01add2e0 = 1;
    do {
      if (LOAD_STAFF < (int)(&DAT_01abaffc)[DAT_01add2e0]) break;
      if (LOAD_STAFF == (&DAT_01abaffc)[DAT_01add2e0]) {
        _DAT_01add2f0 = (float)(&DAT_01ab61dc)[DAT_01add2e0];
        _DAT_01add2f4 = (float)(&DAT_01ab61e0)[DAT_01add2e0];
        if (LOAD_P3 < _DAT_01add2f0) break;
        if (LOAD_P3 <= _DAT_01add2f4) {
          P5 = LOAD_P3 - (float)(&DAT_01ab61dc)[DAT_01add2e0];
          in_ST0 = (float10)P5;
          if (ABS(in_ST0) < (float10)f_0_01) {
            P5 = f_0;
          }
          P4 = (float)(&DAT_01ab61e0)[DAT_01add2e0] - (float)(&DAT_01ab61dc)[DAT_01add2e0];
          if (f_0_01 <= P4) {
            P4 = P5 / P4;
            if (ABS(P4 - f_1) < f_0_01) {
              P4 = f_1;
            }
            _DAT_01add2f0 = (float)(&ITEM_LEN)[(&DAT_01abfe1c)[DAT_01add2e0]];
            _DAT_01add2f4 = (float)(&ITEM_LEN)[(&DAT_01abfe20)[DAT_01add2e0]];
            if ((int)(&DAT_01ac4c40)[DAT_01add2e0] < 0) {
              _DAT_01add2f4 = DAT_01fbb8b8;
            }
            (&ITEM_LEN)[DAT_01add2e8] = (_DAT_01add2f4 - _DAT_01add2f0) * P4 + _DAT_01add2f0;
          }
        }
      }
      DAT_01add2e0 = DAT_01add2e0 + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
  }
  ffree(in_ST0);
  return;
}


