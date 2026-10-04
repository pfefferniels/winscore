// FUN_0041a4f9 @ 0041a4f9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041a4f9(int *param_1,int *param_2,int *param_3,float *param_4,int *param_5,float *param_6,
                 undefined4 *param_7)

{
  float10 fVar1;
  unkbyte10 Var2;
  
  DAT_007d1530 = (int)ROUND(*param_4);
  DAT_007d152c = 0;
  if ((DAT_01fbb700 == 5) ||
     (DAT_007d152c = *(int *)(&DAT_01f9929c + *param_2 * 4), DAT_007d152c == 0)) {
    if (DAT_007d1530 < 0) {
      DAT_007d152c = 0x14;
    }
    if (9999 < DAT_007d1530) {
      DAT_007d152c = 10;
    }
  }
  else if (DAT_007d152c < 0) {
    DAT_007d152c = -DAT_007d152c;
  }
  *param_1 = DAT_007d152c;
  *param_3 = (int)ROUND(ABS(*param_4));
  *param_3 = (*param_3 + (*param_3 / 10000) * -10000) / 100;
  *param_5 = *(int *)(&DAT_01f995bc + *param_2 * 4);
  DAT_007d1528 = *param_5;
  if (DAT_01fbb700 != 5) {
    for (; ((float)(&DAT_01f95d80)[DAT_007d1528 * 0xf] == f_1 &&
           ((float)(&DAT_020492a0)[DAT_007d1528] == f_0)); DAT_007d1528 = DAT_007d1528 + 1) {
    }
  }
  DAT_007d1524 = (float)(&DAT_01f95d50)[DAT_007d1528 * 0xf];
  *param_6 = DAT_007d1524;
  *param_7 = 0;
  fVar1 = (float10)DAT_007d1524;
  if ((float10)f_100 <= ABS(fVar1)) {
    if (f_64 <= *(float *)(&DAT_01f95d5c + DAT_007d1528 * 0x3c)) {
      *param_7 = 1;
    }
    _DAT_007d1520 = f_100;
    if (DAT_007d1524 < f_0) {
      fVar1 = (float10)f_100;
      _DAT_007d1520 = (float)-fVar1;
    }
    *param_6 = DAT_007d1524 - _DAT_007d1520;
  }
  ffree(fVar1);
  Var2 = FUN_0041a776(param_6,&DAT_007d1528);
  ffree(Var2);
  return;
}


