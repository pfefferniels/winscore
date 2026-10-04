// FUN_004b6657 @ 004b6657 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b6657(int *param_1,int *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6,float *param_7,float *param_8)

{
  float10 fVar1;
  float local_44 [16];
  
  *param_4 = f_4_5;
  if ((float10)f_100 <= ABS((float10)*param_6)) {
    local_44[0] = *param_6;
    ffree((float10)*param_6);
    fVar1 = (float10)FUN_005ff874(local_44,&f_100);
    *param_6 = (float)fVar1;
    *param_4 = f_5;
  }
  if (f_0 <= *param_6) {
    if (f_1 < *param_6) {
      *param_4 = (*param_6 - f_1) * f_0_5 + *param_4;
    }
  }
  else {
    *param_4 = f_6;
    if (*param_6 == f_m4) {
      *param_4 = f_9_5;
    }
    if ((8 < *param_1) && (*(float *)(&ITEM_P9 + *param_2 * 4) != f_0)) {
      *param_4 = f_1;
    }
  }
  if (*param_7 != f_0) {
    *param_4 = *param_7 * f_1_75 + *param_4;
  }
  fVar1 = (float10)*param_5;
  if ((float10)f_100 <= ABS(fVar1)) {
    *param_8 = f_0_6;
  }
  if (9 < *param_1) {
    DAT_01c585d0 = *(float *)(&ITEM_P10 + *param_2 * 4);
    if (DAT_01c585d0 != f_0) {
      fVar1 = (float10)DAT_01c585d0;
      *param_3 = (float)-fVar1;
      *param_4 = DAT_01c585d0 + *param_4;
    }
    if ((0xe < *param_1) && (*(float *)(&ITEM_P15 + *param_2 * 4) != f_0)) {
      *param_8 = *param_8 * *(float *)(&ITEM_P15 + *param_2 * 4);
    }
  }
  ffree(fVar1);
  return;
}


