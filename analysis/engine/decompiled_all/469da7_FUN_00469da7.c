// FUN_00469da7 @ 00469da7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00469da7(int *param_1,int *param_2)

{
  if (*param_1 == -1) {
    DAT_00824b68 = (&DAT_02091d20)[DAT_00824b64];
    *param_1 = 1;
    if (*(float *)(&ITEM_P14 + DAT_00824b68 * 4) == f_m1) {
      DAT_00824b60 = 0x11;
    }
    else {
      DAT_00824b60 = 0xe;
    }
    DAT_00824b68 = DAT_00824b60 + DAT_00824b68;
    P48 = DAT_020b9454;
    if (P5 == f_0) {
      P5 = f_1;
    }
    thunk_FUN_0042fa58(&ITEM_LEN + DAT_00824b68,4,&IP12);
    *param_2 = (&DAT_01caea3c)[DAT_00824b5c];
    DAT_00824b58 = DAT_01caea44;
    _DAT_00824b54 = f_0;
    if ((((*param_2 == 0x4e) || (*param_2 == 0x4c)) || (*param_2 == 0x24)) ||
       ((*param_2 == 0x25 || (*param_2 < 0x46 && 0x41 < *param_2)))) {
      _DAT_00824b54 = *(float *)(&DAT_01cadd3c + DAT_00824b5c * 4) / f_2;
    }
    if (((DAT_01caea44 == 0x4e) || (DAT_01caea44 == 0x80)) || (DAT_01caea44 == 0x68)) {
      _DAT_00824b54 = _DAT_00824b54 - DAT_01cadd44 / f_2;
    }
  }
  _DAT_00824b50 = _DAT_00824b4c * f_0_064 - P6;
  if (*param_1 == 1) {
    _DAT_00824b50 = _DAT_00824b54 + _DAT_00824b50;
    *param_1 = 0;
  }
  _DAT_00824b48 = P2;
  return;
}


