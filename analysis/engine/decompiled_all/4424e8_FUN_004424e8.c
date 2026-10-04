// FUN_004424e8 @ 004424e8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004424e8(void)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  
  DAT_01f95c88 = 1;
  for (iVar2 = DAT_020492a4; 0 < iVar2; iVar2 = iVar2 + -1) {
    DAT_01f95c8c = (&DAT_020492a4)[DAT_01f95c88];
    if ((((-1 < DAT_01f95c8c) &&
         (DAT_01f95c90 = (int)ROUND(*(float *)(&DAT_02053434 + DAT_01f95c8c * 4)),
         DAT_01f95c90 < 0x11)) && (DAT_01f95c90 != 0xe)) &&
       ((DAT_01f95c90 != 8 && (DAT_01f95c90 != 3)))) {
      DAT_01f95c94 = (int)ROUND(*(float *)(&DAT_02053430 + DAT_01f95c8c * 4));
      if ((DAT_01f95c90 == 4) && ((8 < DAT_01f95c94 && ((float)(&ITEM_P4)[DAT_01f95c8c] == f_100))))
      {
        DAT_01f95c84 = (float)(DAT_01f95c8c + 6);
        for (iVar1 = (((DAT_01f95c94 + DAT_01f95c8c) - (int)DAT_01f95c84) + -1) / 2; 0 < iVar1;
            iVar1 = iVar1 + -1) {
          (&ITEM_LEN)[(int)DAT_01f95c84] = _DAT_01fbb888 + (float)(&ITEM_LEN)[(int)DAT_01f95c84];
          DAT_01f95c84 = (float)((int)DAT_01f95c84 + 2);
        }
      }
      if (3 < DAT_01f95c94) {
        _DAT_007f7e18 = (float)(&ITEM_P1)[DAT_01f95c8c];
        DAT_01f95c84 = _DAT_01fbb888 + _DAT_007f7e18;
        in_ST0 = (float10)_DAT_007f7e18;
        if (((float10)f_100 <= ABS(in_ST0)) &&
           (in_ST0 = (float10)DAT_01f95c84, ABS(in_ST0) < (float10)f_100)) {
          DAT_01f95c84 = f_m200;
          if (_DAT_007f7e18 < f_0) {
            in_ST0 = (float10)f_m200;
            DAT_01f95c84 = (float)-in_ST0;
          }
          DAT_01f95c84 = _DAT_01fbb888 + DAT_01f95c84 + _DAT_007f7e18;
        }
        (&ITEM_P1)[DAT_01f95c8c] = DAT_01f95c84;
        if ((((3 < DAT_01f95c90) && (DAT_01f95c90 < 7)) && (4 < DAT_01f95c94)) &&
           (_DAT_007f7e14 = (float)(&ITEM_P2)[DAT_01f95c8c], _DAT_007f7e14 != f_999)) {
          (&ITEM_P2)[DAT_01f95c8c] = _DAT_01fbb888 + _DAT_007f7e14;
        }
      }
    }
    DAT_01f95c88 = DAT_01f95c88 + 1;
  }
  ffree(in_ST0);
  return;
}


