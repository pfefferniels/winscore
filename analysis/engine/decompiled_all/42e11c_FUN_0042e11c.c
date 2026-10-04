// FUN_0042e11c @ 0042e11c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042e11c(int *param_1,int *param_2)

{
  int iVar1;
  
  DAT_01caf6e0 = 0;
  if (DAT_020b9458 < f_0) {
    DAT_01caf6e0 = -1;
  }
  DAT_007f13b4 = *param_1;
  DAT_01caf6e4 = f_4;
  while( true ) {
    if ((float)(&ITEM_P1)[DAT_007f13b4] == f_1) {
      FUN_0042e437(&DAT_007f13b4,&DAT_01caf6e8);
      DAT_01caf6f0 = f_0;
      if (f_3 <= (float)(&ITEM_LEN)[DAT_007f13b4]) {
        DAT_01caf6f0 = (float)(&ITEM_P3)[DAT_007f13b4];
      }
      DAT_01caf6a4 = (int)ROUND(DAT_020b9444);
      DAT_01caf6d0 = 1;
      for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_01caf6d4 = (&ITEM_PTR0)[DAT_01caf6d0];
        _DAT_007f13b0 = f_0;
        if (f_3 <= (float)(&ITEM_LEN)[DAT_01caf6d4]) {
          _DAT_007f13b0 = (float)(&ITEM_P3)[DAT_01caf6d4];
        }
        if ((((DAT_01caf6f0 == _DAT_007f13b0) && ((float)(&ITEM_P1)[DAT_01caf6d4] == f_1)) &&
            (DAT_01caf6a4 == (int)ROUND((float)(&ITEM_P2)[DAT_01caf6d4]))) &&
           (DAT_01caf6d4 != DAT_007f13b4)) {
          FUN_0042e437(&DAT_01caf6d4,&DAT_01caf6ec);
          if (DAT_01caf6e0 < 0) {
            if (DAT_01caf6ec < DAT_01caf6e8) {
              DAT_01caf6e8 = DAT_01caf6ec;
            }
          }
          else if (DAT_01caf6e8 < DAT_01caf6ec) {
            DAT_01caf6e8 = DAT_01caf6ec;
          }
        }
        DAT_01caf6d0 = DAT_01caf6d0 + 1;
      }
      DAT_01caf6d0 = 10;
      if (DAT_01caf6e0 < 0) {
        DAT_01caf6d0 = 0x14;
      }
      thunk_FUN_0042c60e(&DAT_01caf6e8,&DAT_01caf6d0);
      *(float *)(&P0 + DAT_01caf6b0 * 4) = DAT_01caf6e4;
      (&P1)[DAT_01caf6b0] = DAT_01caf6e8;
      DAT_01caf6b0 = DAT_01caf6b0 + 2;
    }
    if (DAT_007f13b4 == *param_2) break;
    DAT_01caf6e4 = f_5;
    DAT_007f13b4 = *param_2;
  }
  return;
}


