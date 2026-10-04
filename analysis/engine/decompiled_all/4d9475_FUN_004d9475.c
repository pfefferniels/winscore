// FUN_004d9475 @ 004d9475 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004d9475(int *param_1,int *param_2,float *param_3,int *param_4)

{
  int iVar1;
  float10 fVar2;
  
  DAT_008a05ac = (int)ROUND((float)(&DAT_01f95d50)[*param_1 * 0xf]) % 100;
  if ((*param_2 == 0x42) || (*param_2 == 0x43)) {
    *param_4 = -*param_4;
  }
  fVar2 = (float10)amod(&DAT_01f95d54 + *param_1 * 0xf,&DAT_00765850);
  if (fVar2 < (float10)f_20) {
    if (0x31 < *param_2) {
      if (2 < DAT_008a05ac) {
        return;
      }
      if (*param_4 < 0) {
        return;
      }
      *param_3 = (float)(DAT_008a05ac + -3);
      return;
    }
    if (DAT_008a05ac < 4) {
      iVar1 = *param_2;
      goto joined_r0x004d9612;
    }
    *param_3 = f_0_4;
    if (*param_2 == 5) {
      *param_3 = f_0_35;
    }
    *param_3 = (float)DAT_008a05ac / f_10 - *param_3;
  }
  else {
    if (0x31 < *param_2) {
      if (DAT_008a05ac < 0xc) {
        return;
      }
      if (-1 < *param_4) {
        return;
      }
      *param_3 = (float)(DAT_008a05ac + -0xb);
      return;
    }
    if (10 < DAT_008a05ac) {
      iVar1 = *param_2;
joined_r0x004d9612:
      if (iVar1 != 5) {
        return;
      }
      *param_3 = f_0_05;
      return;
    }
    *param_3 = f_1;
    if (*param_2 == 5) {
      *param_3 = f_1_05;
    }
    *param_3 = *param_3 - (float)DAT_008a05ac / f_10;
  }
  if (f_0_9 < *param_3) {
    *param_3 = f_0_9;
  }
  return;
}


