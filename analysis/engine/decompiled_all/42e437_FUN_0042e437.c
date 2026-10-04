// FUN_0042e437 @ 0042e437 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042e437(int *param_1,float *param_2)

{
  float10 in_ST0;
  float10 fVar1;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  
  DAT_01caf6fc = (int)ROUND((float)(&ITEM_LEN)[*param_1]);
  *param_2 = f_0;
  if (3 < DAT_01caf6fc) {
    ffree(in_ST0);
    fVar1 = (float10)amod(&ITEM_P4 + *param_1,&f_100);
    *param_2 = (float)fVar1;
    in_ST0 = extraout_ST1;
  }
  DAT_01caf6f4 = 0;
  if (4 < DAT_01caf6fc) {
    DAT_01caf6f4 = (int)ROUND((float)(&ITEM_P5)[*param_1]);
  }
  DAT_01caf6f4 = DAT_01caf6f4 % 100;
  _DAT_01caf704 = f_0;
  if (7 < DAT_01caf6fc) {
    ffree(in_ST0);
    fVar1 = (float10)amod(&ITEM_P8 + *param_1 * 4,&f_100);
    _DAT_01caf704 = (float)fVar1;
    in_ST0 = extraout_ST1_00;
  }
  if (DAT_01caf6f4 < 10) {
    _DAT_01caf704 = f_m6;
  }
  if (8 < DAT_01caf6fc) {
    ffree(in_ST0);
    fVar1 = (float10)amod(&ITEM_P9 + *param_1 * 4,&f_10);
    DAT_01caf708 = (int)ROUND(fVar1) + -1;
    in_ST0 = extraout_ST1_01;
    if (0 < DAT_01caf708) {
      _DAT_01caf704 = (float)(DAT_01caf708 * 2) + _DAT_01caf704;
    }
  }
  if (DAT_01caf6e0 < 0) {
    if (DAT_01caf6f4 < 0x14) {
      _DAT_01caf70c = f_m2;
      goto LAB_0042e664;
    }
    _DAT_01caf70c = f_m8_4 - _DAT_01caf704;
  }
  else {
    if (0x13 < DAT_01caf6f4) {
      _DAT_01caf70c = f_2;
      goto LAB_0042e664;
    }
    _DAT_01caf70c = _DAT_01caf704 + f_8_4;
  }
  in_ST0 = (float10)(float)(&ITEM_P4)[*param_1];
  if ((float10)f_100 <= ABS(in_ST0)) {
    _DAT_01caf70c = _DAT_01caf70c * f_0_6;
  }
LAB_0042e664:
  *param_2 = _DAT_01caf70c + *param_2;
  ffree(in_ST0);
  return;
}


