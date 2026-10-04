// FUN_00505e84 @ 00505e84 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00505e84(void)

{
  int iVar1;
  int iVar2;
  
  DAT_00935e64 = 0;
  DAT_00935e60 = 1;
  DAT_00935e5c = 0;
  do {
    DAT_00935e58 = DAT_00935e64;
    _DAT_00935e54 = f_1;
    DAT_00935e50 = f_0;
    LOAD_I = DAT_00935e60;
    for (iVar1 = (ITEM_I - DAT_00935e60) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      load_item_header();
      if (DAT_00935e58 < LOAD_STAFF) goto LAB_00506017;
      if (LOAD_CODE == 0xe) {
        if (DAT_00935e64 == 0) {
          DAT_00935e64 = LOAD_STAFF;
        }
        DAT_00935e50 = f_1;
        if ((3 < LOAD_LEN) && (f_0 < (float)(&ITEM_P4)[LOAD_W])) {
          DAT_00935e50 = (float)(&ITEM_P4)[LOAD_W];
        }
        if (_DAT_00935e54 < DAT_00935e50) {
          _DAT_00935e54 = DAT_00935e50;
        }
        DAT_00935e58 = (int)ROUND(((float)DAT_00935e64 + _DAT_00935e54) - f_1);
      }
      LOAD_I = LOAD_I + 1;
    }
    if (DAT_00935e50 != f_0) {
LAB_00506017:
      DAT_00935e5c = DAT_00935e5c + 1;
      *(int *)(DAT_00935e5c * 8 + 0x1b58f78) = DAT_00935e64;
      *(int *)(DAT_00935e5c * 8 + 0x1b58f74) =
           (int)ROUND(((float)DAT_00935e64 + _DAT_00935e54) - f_1);
    }
    if (ITEM_I <= LOAD_I) {
      DAT_00935e48 = 1;
      DAT_00935e4c = DAT_00935e5c;
      for (iVar1 = DAT_00935e5c; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&DAT_01b408d8)[DAT_00935e4c * 2] = *(undefined4 *)(DAT_00935e48 * 8 + 0x1b58f78);
        (&DAT_01b408d4)[DAT_00935e4c * 2] = *(undefined4 *)(DAT_00935e48 * 8 + 0x1b58f74);
        DAT_00935e4c = DAT_00935e4c + -1;
        DAT_00935e48 = DAT_00935e48 + 1;
      }
      DAT_00935e48 = 1;
      for (iVar1 = DAT_00935e5c; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_00935e4c = (&DAT_01b408d4)[DAT_00935e48 * 2];
        DAT_00935e44 = 1;
        for (iVar2 = ((&DAT_01b408d4)[DAT_00935e48 * 2] - (&DAT_01b408d8)[DAT_00935e48 * 2]) + 1;
            0 < iVar2; iVar2 = iVar2 + -1) {
          if (299 < DAT_00935e4c) {
            DAT_00935e4c = DAT_00935e4c + -300;
          }
          *(int *)(DAT_00935e48 * 4 + DAT_00935e44 * 0x40 + 0x1f9393c) = DAT_00935e4c;
          DAT_00935e4c = DAT_00935e4c + -1;
          DAT_00935e44 = DAT_00935e44 + 1;
        }
        DAT_00935e48 = DAT_00935e48 + 1;
      }
      return;
    }
    DAT_00935e60 = LOAD_I;
    DAT_00935e64 = LOAD_STAFF;
  } while( true );
}


