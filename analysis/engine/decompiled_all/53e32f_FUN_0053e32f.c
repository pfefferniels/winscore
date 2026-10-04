// FUN_0053e32f @ 0053e32f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0053e32f(int *param_1)

{
  int iVar1;
  float10 fVar2;
  float10 extraout_ST1;
  
  DAT_0078cd30 = f_2_5;
  if (*param_1 == 0x14) {
    DAT_0078cd30 = -f_2_5;
  }
LAB_0053e35e:
  fVar2 = (float10)P5 - (float10)P4;
  DAT_0078cd34 = (float)(fVar2 / ((float10)P6 - (float10)P3));
  DAT_0078cd38 = P4 - DAT_0078cd30;
  DAT_0078cd3c = DAT_01f95c94 + 1;
  iVar1 = DAT_01f95c98 - DAT_0078cd3c;
  do {
    if (iVar1 < 1) {
      ffree(fVar2);
      return;
    }
    if ((float)(&DAT_01f95d44)[DAT_0078cd3c * 0xf] == f_1) {
      fVar2 = (float10)P7 + (float10)DAT_0078cd38;
      DAT_0078cd40 = (float)(((float10)(float)(&DAT_01f95d4c)[DAT_0078cd3c * 0xf] - (float10)P3) *
                             (float10)DAT_0078cd34 + fVar2);
      DAT_0078cd44 = (((int)ROUND((float)(&DAT_01f95d54)[DAT_0078cd3c * 0xf]) % 100) / 10) * 10;
      if (DAT_0078cd44 != *param_1) {
        DAT_0078cd48 = f_0;
        if (f_0 < *(float *)(&DAT_01f95d6c + DAT_0078cd3c * 0x3c)) {
          ffree(fVar2);
          fVar2 = (float10)amod(&DAT_01f95d6c + DAT_0078cd3c * 0x3c,&f_1);
          DAT_0078cd48 = (float)(fVar2 * (float10)f_10);
          if (DAT_0078cd44 == 10) {
            fVar2 = (float10)DAT_0078cd48;
            DAT_0078cd48 = (float)(-fVar2 - (float10)f_2);
          }
          else {
            DAT_0078cd48 = DAT_0078cd48 + f_2;
            fVar2 = extraout_ST1;
          }
        }
        DAT_0078cd4c = (float)(&DAT_01f95d50)[DAT_0078cd3c * 0xf];
        if (f_100 <= DAT_0078cd4c) {
          DAT_0078cd4c = DAT_0078cd4c - f_100;
        }
        else if (DAT_0078cd4c <= f_m100) {
          DAT_0078cd4c = DAT_0078cd4c + f_100;
        }
        DAT_0078cd48 = DAT_0078cd48 + DAT_0078cd4c;
        if (*param_1 == 0x14) {
          if (DAT_0078cd48 < DAT_0078cd40) {
LAB_0053e5e5:
            DAT_0078cd48 = DAT_0078cd48 - DAT_0078cd40;
            if (P9 != f_0) break;
            P7 = DAT_0078cd48 + P7;
          }
        }
        else if (DAT_0078cd40 < DAT_0078cd48) goto LAB_0053e5e5;
      }
    }
    DAT_0078cd3c = DAT_0078cd3c + 1;
    iVar1 = iVar1 + -1;
  } while( true );
  DAT_0078cd48 = DAT_0078cd48 + f_0_5;
  if (*param_1 == 0x14) {
    DAT_0078cd48 = DAT_0078cd48 - f_1;
  }
  P4 = DAT_0078cd48 + P4;
  P5 = DAT_0078cd48 + P5;
  DAT_01f95c94 = DAT_0078cd3c;
  goto LAB_0053e35e;
}


