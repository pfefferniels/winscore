// FUN_0041a14c @ 0041a14c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041a14c(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                 int *param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,
                 undefined4 param_11)

{
  float10 fVar1;
  
  *param_1 = *param_1 + 1;
  _DAT_007d151c = (float)(&DAT_01fb8cc0)[*param_1];
  _DAT_007d1518 = (float)(&DAT_01fb8cc4)[*param_1];
  DAT_007d1514 = FUN_0041a0f8(&DAT_007d151c);
  DAT_007d1510 = FUN_0041a0f8(&DAT_007d1518);
  *param_3 = DAT_007d1514;
  *param_4 = DAT_007d1510;
  DAT_007d150c = DAT_007d1510;
  if (DAT_007d1510 == 0) {
    DAT_007d1510 = 1;
  }
  if ((DAT_007d1514 == 0) || (DAT_007d1514 == 99)) {
    DAT_007d1514 = 1;
  }
  else if (DAT_007d1510 <= DAT_007d1514) {
    DAT_007d1510 = DAT_007d1514 + 1;
    *param_4 = DAT_007d1510;
  }
  if (DAT_01fb8c78 <= DAT_007d1510) {
    DAT_007d1510 = DAT_01fb8c78 + -1;
  }
  FUN_0041a4f9(param_2,&DAT_007d1514,param_5,&DAT_007d151c,param_6,param_8,param_10);
  FUN_0041a4f9(&DAT_007d1508,&DAT_007d1510,&DAT_007d1504,&DAT_007d1518,param_7,param_9,param_11);
  if (DAT_007d1504 != 0) {
    *param_5 = DAT_007d1504;
  }
  if ((DAT_007d1508 != 0) && (*param_2 == 0)) {
    *param_2 = DAT_007d1508;
  }
  P3 = (float)(&DAT_01f95d4c)[*param_6 * 0xf];
  P6 = (float)(&DAT_01f95d4c)[*param_7 * 0xf];
  if (DAT_01fbb700 == 5) {
    fVar1 = (float10)amod(&DAT_007d151c,&f_1);
    _DAT_007d151c = (float)fVar1;
    fVar1 = (float10)amod(&DAT_007d1518,&f_1);
    _DAT_007d1518 = (float)ABS(fVar1);
    DAT_007d1510 = DAT_007d150c + 1;
    if (_DAT_007d151c != f_0) {
      DAT_007d1514 = *param_3;
      if (DAT_01fb8c78 <= DAT_007d1514) {
        return;
      }
      if (DAT_007d1514 == 0) {
        _DAT_007d1500 = P3;
        P3 = DAT_01e67918;
      }
      else {
        _DAT_007d1500 = (float)(&DAT_01f95d4c)[(&DAT_01f995c0)[DAT_007d1514] * 0xf];
      }
      P3 = (_DAT_007d1500 - P3) * _DAT_007d151c + P3;
      *param_3 = 1;
      *param_4 = 1;
    }
    if (_DAT_007d1518 != f_0) {
      if (DAT_007d1510 <= DAT_007d1514) {
        DAT_007d1510 = DAT_007d1514 + 1;
      }
      if (DAT_007d1510 < DAT_01fb8c78) {
        if (DAT_007d150c <= DAT_007d1514) {
          P6 = (float)(&DAT_01f95d4c)[*param_6 * 0xf];
        }
        _DAT_007d1500 = (float)(&DAT_01f95d4c)[*(int *)(&DAT_01f995bc + DAT_007d1510 * 4) * 0xf];
      }
      else {
        _DAT_007d1500 = DAT_01e67914;
      }
      P6 = (_DAT_007d1500 - P6) * _DAT_007d1518 + P6;
      *param_3 = 1;
      *param_4 = 1;
    }
  }
  return;
}


