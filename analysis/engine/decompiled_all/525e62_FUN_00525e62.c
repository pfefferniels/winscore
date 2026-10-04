// FUN_00525e62 @ 00525e62 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00525e62(void)

{
  int iVar1;
  float10 in_ST0;
  
  LOAD_I = 1;
  _DAT_0094ea78 = f_0;
  P1 = f_2;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    if ((((_DAT_0094ea78 <= LOAD_P3) && ((float)LOAD_STAFF == DAT_01fb8c60)) &&
        ((LOAD_CODE < 4 || (0xd < LOAD_CODE)))) && ((LOAD_CODE != 0xf && (LOAD_CODE != 0x10)))) {
      DAT_0094ea74 = LOAD_CODE;
      _DAT_0094ea78 = LOAD_P3;
      DAT_0094ea70 = LOAD_W;
      if ((LOAD_CODE == 0xe) && (LOAD_P3 == f_0)) {
        _DAT_0094ea78 = f_m1;
      }
    }
    LOAD_I = LOAD_I + 1;
  }
  if (_DAT_0094ea78 != f_0) {
    DAT_0094ea6c = f_7;
    if (DAT_0094ea74 == 3) {
      DAT_0094ea6c = f_9;
    }
    if (DAT_0094ea74 == 0x11) {
      in_ST0 = (float10)(float)(&ITEM_P5)[DAT_0094ea70];
      DAT_0094ea6c = (float)(ABS(in_ST0) * (float10)f_2_5 + (float10)f_4);
    }
    if (DAT_0094ea74 == 0x12) {
      DAT_0094ea6c = f_8;
    }
    DAT_0094ea6c = DAT_0094ea6c + _DAT_0094ea78;
    if (P1 < DAT_0094ea6c) {
      P1 = DAT_0094ea6c;
    }
  }
  ffree(in_ST0);
  return;
}


