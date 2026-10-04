// FUN_004b6a52 @ 004b6a52 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b6a52(int *param_1,float *param_2,float *param_3,int param_4,int *param_5,float *param_6
                 )

{
  *param_2 = f_0;
  *param_3 = f_7_5;
  if (*param_5 == 0xe) {
    *param_6 = *param_6 - f_1_5;
    *param_2 = f_0_5;
  }
  if (*param_5 == 1) {
    *param_2 = f_2;
  }
  if (*param_5 == 0x11) {
    *param_2 = f_m1_5;
  }
  DAT_01c585d4 = *(float *)(param_4 + 0x10);
  if (((f_10 <= DAT_01c585d4) || (f_10 <= *(float *)(param_4 + 0x14))) && (DAT_01c585d4 <= f_90)) {
    *param_3 = *param_3 + f_2_5;
  }
  for (DAT_0089f49c = *param_1; *(float *)(param_4 + -4 + DAT_0089f49c * 4) == f_0;
      DAT_0089f49c = DAT_0089f49c + -1) {
  }
  if (7 < DAT_0089f49c) {
    DAT_01c585d4 = f_0;
    if (((DAT_0089f49c < 0xc) || (*(float *)(param_4 + 0x2c) == f_0)) &&
       ((DAT_01c585d4 = f_4_5, 9 < DAT_0089f49c && (*(float *)(param_4 + 0x24) != f_0)))) {
      DAT_01c585d4 = f_4_5 + *(float *)(param_4 + 0x24);
    }
    if ((10 < DAT_0089f49c) && (*(float *)(param_4 + 0x28) != f_0)) {
      DAT_01c585d4 = DAT_01c585d4 + *(float *)(param_4 + 0x28);
    }
    DAT_01c585d8 = f_3_5;
    if ((f_10 < *(float *)(param_4 + 0x1c)) || (f_10 < *(float *)(param_4 + 0x20))) {
      DAT_01c585d8 = f_6;
    }
    *param_3 = DAT_01c585d4 + *param_3 + DAT_01c585d8;
  }
  return;
}


