// FUN_0041a776 @ 0041a776 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0041a776(float *param_1,int *param_2)

{
  float10 in_ST0;
  
  DAT_007d153c = (int)ROUND(*(float *)(&DAT_01f95d70 + *param_2 * 0x3c));
  if (DAT_007d153c != 0) {
    DAT_007d1538 = (int)ROUND(DAT_01fb8c60);
    if (((DAT_007d1538 < 2) && (DAT_007d153c == 2)) ||
       ((DAT_007d153c == 1 && (MAX_STAFF <= DAT_007d1538)))) {
      *(float *)(&DAT_01f95d70 + *param_2 * 0x3c) = f_0;
    }
    else {
      DAT_007d1534 = DAT_007d153c * -2 + 3;
      in_ST0 = (float10)(int)((&STAFF_Y0)[DAT_007d1534 + DAT_007d1538] - (&STAFF_Y0)[DAT_007d1538]);
      *param_1 = (float)(in_ST0 / ((float10)STEP * (float10)f_7) + (float10)*param_1);
    }
  }
  ffree(in_ST0);
  return;
}


