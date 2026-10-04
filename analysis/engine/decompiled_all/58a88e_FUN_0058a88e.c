// FUN_0058a88e @ 0058a88e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058a88e(int *param_1,float *param_2,int *param_3,int param_4)

{
  int iVar1;
  float10 in_ST0;
  int local_2c;
  
  DAT_009a9310._0_1_ = DAT_0076adfc;
  DAT_009a9308 = *param_2;
  if (*param_1 < 0) goto LAB_0058abdc;
  if (0 < *param_1) goto LAB_0058abcd;
  do {
    if ((int)DAT_009a9308 < 0) {
      in_ST0 = (float10)DAT_009a9308;
      DAT_009a9308 = (float)-in_ST0;
      DAT_009a9310._0_1_ = DAT_0076adc0;
    }
    else {
      if (DAT_009a9308 < f_10000) break;
      DAT_009a9308 = DAT_009a9308 - f_10000;
      DAT_009a9310._0_1_ = DAT_0076adc4;
    }
LAB_0058abcd:
    *param_3 = *param_3 + 1;
LAB_0058abdc:
    *(undefined1 *)(*param_3 + param_4 + -1) = (undefined1)DAT_009a9310;
  } while( true );
  DAT_009a9310 = (int)ROUND(DAT_009a9308 * f_100 + f_0_02);
  if (DAT_009a9310 == 0) {
    *param_3 = *param_3 + 1;
    *(undefined1 *)(*param_3 + param_4 + -1) = 0x30;
  }
  else {
    DAT_009a9308 = 1.4013e-40;
    DAT_009a9328 = *param_3 + 1;
    DAT_009a9324 = 0;
    local_2c = 6;
    DAT_009a9320 = 1;
    do {
      if (DAT_009a9320 == 5) {
        DAT_009a9324 = 1;
        *param_3 = *param_3 + 1;
        *(undefined1 *)(*param_3 + param_4 + -1) = 0x2e;
      }
      DAT_009a931c = DAT_009a9310 / (int)DAT_009a9308;
      DAT_009a9310 = DAT_009a9310 % (int)DAT_009a9308;
      DAT_009a9308 = (float)((int)DAT_009a9308 / 10);
      if ((DAT_009a931c != 0) || (DAT_009a9324 != 0)) {
        *param_3 = *param_3 + 1;
        *(char *)(*param_3 + param_4 + -1) = (char)DAT_009a931c + '0';
        DAT_009a9324 = 1;
      }
      DAT_009a9320 = DAT_009a9320 + 1;
      local_2c = local_2c + -1;
    } while (0 < local_2c);
    DAT_009a9320 = *param_3;
    DAT_009a9318 = DAT_009a9320;
    for (iVar1 = ((DAT_009a9328 - DAT_009a9320) + -1) / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
      if ((*(char *)(DAT_009a9320 + param_4 + -1) == '.') && (DAT_009a9320 == *param_3))
      goto LAB_0058ab85;
      if (*(char *)(DAT_009a9320 + param_4 + -1) != '0') break;
      *param_3 = *param_3 + -1;
      DAT_009a9320 = DAT_009a9320 + -1;
    }
  }
  *param_3 = *param_3 + 1;
LAB_0058ab85:
  *(undefined1 *)(*param_3 + param_4 + -1) = 0x2f;
  ffree(in_ST0);
  return;
}


