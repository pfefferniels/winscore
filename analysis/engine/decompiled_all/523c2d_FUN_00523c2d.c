// FUN_00523c2d @ 00523c2d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00523c2d(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  DAT_01e6078c = 1;
  DAT_0094e648 = 0xb;
  if (DAT_00796fd4 == f_0) {
    DAT_00796fd4 = DAT_01fbb8b8;
  }
  iVar2 = (ITEM_I - DAT_01a1fe18) + 1;
  DAT_01e60790 = f_0;
  LOAD_I = DAT_01a1fe18;
  do {
    if (iVar2 < 1) {
      if (DAT_01e6078c == 1) {
        DAT_0078d890 = 0;
      }
      else {
        (&DAT_01e60790)[DAT_01e6078c] = DAT_01fbb8b8;
        thunk_FUN_0054cd13(&P1,&DAT_00767ce8);
        P2 = (float)CUR_STAFF;
        DAT_0094e630 = (float)(DAT_0094e648 + 2);
        P6 = f_25 / (float)(&STAFF_STEP0)[IP2];
        DAT_0094e628 = 1;
        P1 = f_13;
        _DAT_0094e62c = f_0;
        iVar2 = DAT_01e6078c;
        while (iVar2 = iVar2 + -1, 0 < iVar2) {
          P3 = (&DAT_01e60790)[DAT_0094e628];
          P5 = (float)(DAT_0094e628 + 4000);
          fVar1 = P3 - _DAT_0094e62c;
          _DAT_0094e62c = P3;
          P4 = DAT_0094e630;
          if (fVar1 <= f_4) {
            P4 = DAT_0094e630 + f_2;
            _DAT_0094e62c = f_0;
          }
          draw_item();
          flush_points();
          DAT_0094e628 = DAT_0094e628 + 1;
        }
      }
      return;
    }
    load_item_header();
    if ((((LOAD_CODE == 1) && (CUR_STAFF == LOAD_STAFF)) && (DAT_00796fd0 <= LOAD_P3)) &&
       (LOAD_P3 <= DAT_00796fd4)) {
      DAT_0094e644 = (int)ROUND((float)(&ITEM_P4)[LOAD_W]) % 100;
      DAT_0094e640 = (int)ROUND((float)(&ITEM_P5)[LOAD_W]) % 100;
      if ((DAT_0094e640 < 0x14) && (9 < DAT_0094e640)) {
        DAT_0094e644 = DAT_0094e644 + 8;
      }
      if (DAT_0094e648 < DAT_0094e644) {
        DAT_0094e648 = DAT_0094e644;
      }
      DAT_0094e63c = LOAD_P3;
      if ((DAT_01e6078c == 0) || ((float)(&DAT_01e6078c)[DAT_01e6078c] + f_1 < LOAD_P3)) {
        DAT_01e6078c = DAT_01e6078c + 1;
        (&DAT_01e6078c)[DAT_01e6078c] = (int)LOAD_P3;
      }
      else {
        iVar3 = -DAT_01e6078c / -1;
        for (DAT_0094e640 = DAT_01e6078c;
            (0 < iVar3 &&
            (_DAT_0094e638 = LOAD_P3 - (float)(&DAT_01e6078c)[DAT_0094e640],
            _DAT_0094e638 <= f_0_005)); DAT_0094e640 = DAT_0094e640 + -1) {
          if (f_m0_005 <= _DAT_0094e638) goto LAB_00523f78;
          iVar3 = iVar3 + -1;
        }
        DAT_0094e640 = DAT_0094e640 + 1;
        DAT_0094e634 = DAT_01e6078c;
        for (iVar3 = ((DAT_0094e640 - DAT_01e6078c) + -1) / -1; 0 < iVar3; iVar3 = iVar3 + -1) {
          (&DAT_01e60790)[DAT_0094e634] = (float)(&DAT_01e6078c)[DAT_0094e634];
          DAT_0094e634 = DAT_0094e634 + -1;
        }
        (&DAT_01e6078c)[DAT_0094e640] = (int)DAT_0094e63c;
        DAT_01e6078c = DAT_01e6078c + 1;
      }
    }
LAB_00523f78:
    LOAD_I = LOAD_I + 1;
    iVar2 = iVar2 + -1;
  } while( true );
}


