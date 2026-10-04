// FUN_004c7374 @ 004c7374 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c7374(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  bool bVar2;
  float10 in_ST0;
  float10 fVar3;
  unkbyte10 Var4;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  float10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  float10 extraout_ST1_03;
  
  DAT_0089fc2c = *param_1;
  if (DAT_0089fc2c < 0) {
    DAT_0089fc2c = -DAT_0089fc2c;
  }
  *param_2 = f_1_2;
  if (DAT_0089fc2c == 1) {
    DAT_0089fc28 = f_1;
    *param_3 = f_4_1;
    if ((5 < LOAD_LEN) && ((float)(&ITEM_P6)[LOAD_W] == f_2)) {
      *param_3 = f_4_6;
    }
    if ((9 < LOAD_LEN) && (*(float *)(&ITEM_P10 + LOAD_W * 4) != f_0)) {
      _DAT_0089fc24 = *(float *)(&ITEM_P10 + LOAD_W * 4);
      in_ST0 = (float10)_DAT_0089fc24;
      if (ABS(in_ST0) < (float10)f_10) {
        *param_3 = _DAT_0089fc24 + *param_3;
      }
      if (_DAT_0089fc24 == f_10) {
        *param_3 = *param_3 + *param_3;
      }
      if (_DAT_0089fc24 == f_20) {
        DAT_0089fc28 = DAT_0089fc28 + *param_3;
      }
    }
    ffree(in_ST0);
    fVar3 = (float10)amod(&ITEM_P4 + LOAD_W,&f_100);
    _DAT_0089fc24 = (float)fVar3;
    DAT_0089fc20 = f_0;
    if ((f_13 <= _DAT_0089fc24) || (_DAT_0089fc24 <= f_0)) {
      *param_3 = *param_3 + f_0_5;
      DAT_0089fc20 = f_1;
    }
    DAT_0089fc1c = 1;
    *param_2 = f_0;
    Var4 = extraout_ST1;
    if (4 < LOAD_LEN) {
      ffree(extraout_ST1);
      fVar3 = (float10)amod(&ITEM_P5 + LOAD_W,&f_10);
      *param_2 = (float)fVar3;
      Var4 = extraout_ST1_00;
    }
    DAT_0089fc1c = (int)ROUND(*param_2 + f_1);
    fVar1 = *(float *)(&DAT_00792638 + DAT_0089fc1c * 4);
    ffree(Var4);
    fVar3 = (float10)amod(param_2,&f_1);
    *param_2 = (float)(fVar3 * (float10)f_10 + (float10)fVar1);
    if (*param_2 <= f_1) {
      DAT_0089fc28 = DAT_0089fc20 + DAT_0089fc28;
    }
    if (*param_2 < DAT_0089fc28) {
      *param_2 = DAT_0089fc28;
    }
    in_ST0 = extraout_ST1_01;
    if (8 < LOAD_LEN) {
      DAT_0089fc20 = f_0;
      DAT_0089fc1c = (int)ROUND(*(float *)(&ITEM_P9 + LOAD_W * 4) / f_10);
      _DAT_0089fc24 = (float)DAT_0089fc1c;
      ffree(extraout_ST1_01);
      fVar3 = (float10)amod(&ITEM_P9 + LOAD_W * 4,&f_1);
      _DAT_0089fc24 = (float)(fVar3 * (float10)f_10 + (float10)_DAT_0089fc24);
      bVar2 = (float)(&ITEM_P5)[LOAD_W] < f_20;
      ffree(extraout_ST1_02);
      fVar3 = (float10)amod(&ITEM_P9 + LOAD_W * 4,&f_10);
      if (bVar2 && (float10)f_1 <= fVar3) {
        DAT_0089fc20 = f_1_6;
      }
      if (_DAT_0089fc24 < DAT_0089fc20) {
        _DAT_0089fc24 = DAT_0089fc20;
      }
      *param_3 = _DAT_0089fc24 + *param_3;
      in_ST0 = extraout_ST1_03;
    }
  }
  else if (DAT_0089fc2c == 2) {
    *param_3 = f_3_1;
  }
  else if (DAT_0089fc2c == 3) {
    *param_3 = f_7;
    if ((3 < LOAD_LEN) && (f_100 <= (float)(&ITEM_P4)[LOAD_W])) {
      *param_3 = f_5_6;
    }
  }
  else if (DAT_0089fc2c == 0xe) {
    *param_3 = f_1_5;
    *param_2 = f_2_4;
    if (4 < LOAD_LEN) {
      DAT_0089fc20 = (float)(&ITEM_P5)[LOAD_W];
      if (DAT_0089fc20 == f_1) {
        *param_2 = f_2_7;
      }
      if (DAT_0089fc20 == f_2) {
        *param_2 = f_3_7;
      }
      if (DAT_0089fc20 == f_3) {
        *param_2 = f_6;
      }
      if (f_4 <= DAT_0089fc20) {
        *param_3 = f_4_9;
      }
      if (f_5 < DAT_0089fc20) {
        *param_2 = f_5;
      }
    }
  }
  else if ((DAT_0089fc2c != 0x11) &&
          ((*param_3 = f_5_6, f_9 < (float)(&ITEM_P5)[LOAD_W] ||
           ((f_9 < (float)(&ITEM_P6)[LOAD_W] && ((float)(&ITEM_P5)[LOAD_W] < f_90)))))) {
    *param_3 = f_8_1;
  }
  ffree(in_ST0);
  return;
}


