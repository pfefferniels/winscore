// FUN_00419498 @ 00419498 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00419498(void)

{
  int iVar1;
  
  DAT_007d14c8 = (int)ROUND(DAT_020b9444);
  IP7 = (int)ROUND(DAT_020b9458);
  DAT_007d14c4 = IP7 / 10;
  if (DAT_007d14c4 < 0) {
    DAT_007d14c4 = -DAT_007d14c4;
  }
  IP9 = 0;
  if (P1 == f_9) {
    IP9 = (int)ROUND(P2);
  }
  _DAT_007d14c0 = DAT_020b9468;
  _DAT_007d14bc = DAT_020b946c;
  _DAT_007d14b8 = DAT_020b9474;
  _DAT_007d14b4 = DAT_020b9478;
  if (DAT_020b9468 == f_m1) {
    _DAT_007d14c0 = DAT_020b9448;
  }
  if (DAT_020b946c == f_m1) {
    _DAT_007d14bc = DAT_020b9454;
  }
  if (DAT_020b9474 == f_m1) {
    _DAT_007d14b8 = DAT_020b9448;
  }
  if (DAT_020b9478 == f_m1) {
    _DAT_007d14b4 = DAT_020b9454;
  }
  DAT_007d14b0 = 0;
  _DAT_007d14ac = 0;
  DAT_007d14a8 = 0;
  LOAD_I = 1;
  _DAT_007d14a4 = f_m9999;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if (((((DAT_007d14c8 == LOAD_STAFF) && (LOAD_CODE == 1)) && (LOAD_P3 <= DAT_020b9454)) &&
        ((_DAT_007d14a4 != LOAD_P3 && (DAT_020b9448 <= LOAD_P3)))) &&
       ((4 < LOAD_LEN &&
        ((DAT_007d14a0 = ((int)ROUND((float)(&ITEM_P5)[LOAD_W]) % 100) / 10, DAT_007d14a0 != 0 &&
         (DAT_007d14c4 != DAT_007d14a0)))))) {
      if (DAT_020b9448 == LOAD_P3) {
        thunk_FUN_0042e679(&DAT_007d14a8,&DAT_0075f5b0);
      }
      if (_DAT_007d14c0 == LOAD_P3) {
        thunk_FUN_0042e679(&DAT_007d14b0,&DAT_0075f5b0);
      }
      if (_DAT_007d14b8 == LOAD_P3) {
        thunk_FUN_0042e679(&DAT_007d14ac,&DAT_0075f5b0);
      }
      if (DAT_020b9454 == LOAD_P3) {
        thunk_FUN_0042e679(&DAT_007d14a8,&DAT_0075f628);
      }
      if (_DAT_007d14bc == LOAD_P3) {
        thunk_FUN_0042e679(&DAT_007d14b0,&DAT_0075f628);
      }
      if (_DAT_007d14b4 == LOAD_P3) {
        thunk_FUN_0042e679(&DAT_007d14ac,&DAT_0075f628);
      }
      _DAT_007d14a4 = LOAD_P3;
    }
    LOAD_I = LOAD_I + 1;
  }
  P1 = f_9;
  P2 = (float)(DAT_007d14a8 * 100 + DAT_007d14b0 * 10 + _DAT_007d14ac);
  return;
}


