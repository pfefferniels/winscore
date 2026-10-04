// FUN_0053e094 @ 0053e094 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0053e094(float *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  float10 in_ST0;
  float10 fVar3;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  
  DAT_0078cd30 = *(float *)(&DAT_01f95d6c + *param_2 * 0x3c);
  DAT_0078cd34 = (int)ROUND(DAT_0078cd30);
  if ((DAT_0078cd34 != 0) &&
     (DAT_0078cd3c = (float)DAT_0078cd34, ABS(DAT_0078cd30 - DAT_0078cd3c) <= f_0_1)) {
    DAT_0078cd38 = DAT_0078cd34;
    if (DAT_0078cd34 < 0) {
      DAT_0078cd38 = -DAT_0078cd34;
    }
    iVar2 = 0xe;
    DAT_0078cd40 = 1;
    do {
      if (DAT_0078cd38 == *(int *)(DAT_0078cd40 * 4 + 0x797450)) {
        ffree(in_ST0);
        fVar3 = (float10)amod(&DAT_01f95d50 + *param_2 * 0xf,&f_100);
        DAT_0078cd40 = (uint)ROUND(fVar3);
        DAT_0078cd3c = f_1_5;
        in_ST0 = extraout_ST1;
        if (DAT_0078cd34 < 1) {
          if (*param_3 != *param_4) break;
        }
        else {
          if (*param_3 == *param_4) break;
          if (*param_5 == 0) {
            if ((DAT_0078cd38 != 6) && (DAT_0078cd38 != 7)) {
              ffree(extraout_ST1);
              fVar3 = (float10)amod(&DAT_0078cd30,&f_1);
              DAT_0078cd44 = (float)fVar3;
              in_ST0 = extraout_ST1_00;
              if (DAT_0078cd44 <= f_0_2) {
                *(float *)(&DAT_01f95d6c + *param_2 * 0x3c) = DAT_0078cd30 + f_0_18;
              }
              break;
            }
            uVar1 = DAT_0078cd40 & 1;
            if ((uVar1 != 0) && ((int)DAT_0078cd40 < 0)) {
              uVar1 = uVar1 - 2;
            }
            if ((uVar1 == 1) &&
               ((((int)DAT_0078cd40 < 9 && (*param_3 == 0x14)) ||
                ((5 < (int)DAT_0078cd40 && (*param_3 == 10)))))) {
              DAT_0078cd3c = f_2_5;
            }
          }
        }
        if (*param_4 == 0x14) {
          in_ST0 = (float10)DAT_0078cd3c;
          DAT_0078cd3c = (float)-in_ST0;
        }
        *param_1 = DAT_0078cd3c + *param_1;
        break;
      }
      DAT_0078cd40 = DAT_0078cd40 + 1;
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
  }
  ffree(in_ST0);
  return;
}


