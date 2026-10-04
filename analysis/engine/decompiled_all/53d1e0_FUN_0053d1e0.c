// FUN_0053d1e0 @ 0053d1e0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0053d1e0(void)

{
  bool bVar1;
  int iVar2;
  unkbyte10 in_ST0;
  float10 fVar3;
  unkbyte10 Var4;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  float10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  int local_20;
  
  P1 = f_5;
  P2 = DAT_01fb8c60;
  ffree(in_ST0);
  fVar3 = (float10)thunk_FUN_00547ae0(&DAT_0099d0c4,&DAT_0099d0c0,&DAT_0099d0bc);
  DAT_01f95c84 = 0;
LAB_0053d22e:
  ffree(fVar3);
  Var4 = thunk_FUN_0041a14c(&DAT_01f95c84,&DAT_0099d0b8,&DAT_01f95c8c,&DAT_01f95c90,&IP9,
                            &DAT_01f95c94,&DAT_01f95c98,&DAT_0099d0b4,&DAT_0099d0b0,&DAT_0099d0ac,
                            &DAT_0099d0a8);
  DAT_0078cd64 = DAT_0099d0b8;
  DAT_0099d0a4 = DAT_0078b4a4;
  if ((-1 < DAT_0078b4a4) &&
     ((float)(&DAT_01f95d4c)[DAT_01f95c94 * 0xf] == (float)(&DAT_01f95d88)[DAT_01f95c94 * 0xf])) {
    DAT_0099d0a4 = -1;
  }
  P9 = (float)IP9;
  DAT_01f95c88 = DAT_01f95c94;
  if (DAT_01f95c8c == 99) {
    DAT_0099d0b4 = DAT_0099d0b0;
    DAT_01f95c88 = DAT_01f95c98;
  }
  ffree(Var4);
  DAT_0099d0a0 = FUN_0053dfd6(&DAT_01f95c88);
  DAT_01f95c88 = DAT_01f95c98;
  if (DAT_01f95c90 == 99) {
    DAT_0099d0b0 = DAT_0099d0b4;
    DAT_01f95c88 = DAT_01f95c94;
  }
  ffree(extraout_ST0);
  DAT_0099d09c = FUN_0053dfd6(&DAT_01f95c88);
  Var4 = extraout_ST0_00;
  if (DAT_0099d0ac == 0) {
    if (DAT_0099d0b8 == 0) {
      DAT_0099d0b8 = 0x14;
      DAT_01f95c80 = DAT_01f95c94;
      for (iVar2 = (DAT_01f95c98 - DAT_01f95c94) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
        if ((float)(&DAT_01f95d44)[DAT_01f95c80 * 0xf] == f_1) {
          DAT_01f95c88 = (int)ROUND((float)(&DAT_01f95d54)[DAT_01f95c80 * 0xf]) % 100;
          bVar1 = DAT_01f95c88 < 10;
          ffree(Var4);
          fVar3 = (float10)amod(&DAT_01f95d50 + DAT_01f95c80 * 0xf,&f_100);
          Var4 = extraout_ST1;
          if ((float10)f_6 < fVar3 && bVar1) break;
          if (0x13 < DAT_01f95c88) {
            DAT_0099d0b8 = 10;
            break;
          }
        }
        DAT_01f95c80 = DAT_01f95c80 + 1;
      }
    }
  }
  else if (DAT_0099d0b8 == 0) {
    DAT_0099d0b8 = 0x1e - DAT_0099d0a0;
  }
  DAT_0099d098 = 0;
  if (DAT_01fb8c78 <= DAT_01f95c90) {
    P6 = DAT_0099d0c0;
  }
  if (DAT_01f95c8c == 0) {
    P3 = (float)(&DAT_01f95d4c)[DAT_01f95c94 * 0xf] - f_8;
LAB_0053d633:
    DAT_0099d098 = 1;
    if (0 < DAT_0099d0a4) {
      P8 = f_0_4;
      goto LAB_0053d78a;
    }
    if ((((DAT_0099d0a4 == 0) && (DAT_01f95c8c != 0)) && (P6 - P3 < f_10)) ||
       (DAT_01f95c88 = (int)ROUND((float)(&DAT_01f95d54)[DAT_01f95c98 * 0xf]) % 10,
       DAT_01f95c88 != 0)) goto LAB_0053d77e;
    ffree(Var4);
    FUN_0053df2a(&DAT_0099d0b4,&DAT_0099d0b8);
    P8 = f_m2;
    if (f_10 <= *(float *)(&DAT_01f95d64 + DAT_01f95c94 * 0x3c)) {
      P8 = f_m3;
    }
  }
  else {
    if (DAT_01f95c8c == 99) {
      P3 = (float)(&DAT_01f95d4c)[DAT_01f95c94 * 0xf] - f_5;
    }
    else if ((DAT_01f95c90 != 99) &&
            ((DAT_01fb8c78 <= DAT_01f95c90 ||
             (((IP9 == 0 && (DAT_0099d0b0 == DAT_0099d0b4)) && (DAT_01f95c90 - DAT_01f95c8c == 1))))
            )) goto LAB_0053d633;
LAB_0053d77e:
    P8 = f_m1;
LAB_0053d78a:
    if (DAT_01fb8c78 <= DAT_01f95c90) {
      P6 = P6 - f_1_5;
    }
    if (DAT_0099d09c == DAT_0099d0a0) {
      ffree(Var4);
      fVar3 = (float10)FUN_0053de20(&DAT_01f95c94,&DAT_0099d0b8,&DAT_0099d0b4,&DAT_0099d0a0);
      P4 = (float)fVar3;
      ffree(extraout_ST1_02);
      fVar3 = (float10)FUN_0053de20(&DAT_01f95c98,&DAT_0099d0b8,&DAT_0099d0b0,&DAT_0099d09c);
      P5 = (float)fVar3;
      fVar3 = extraout_ST1_03;
      if ((DAT_0099d0b8 == DAT_0099d0a0) && (P8 = f_0, DAT_0099d0b8 == 10)) {
        P8 = f_m4;
      }
    }
    else {
      DAT_0099d094 = DAT_0099d0b4 - DAT_0099d0b0;
      if (DAT_0099d0a0 == DAT_0099d0b8) {
        ffree(Var4);
        fVar3 = (float10)FUN_0053de20(&DAT_01f95c98,&DAT_0099d0b8,&DAT_0099d0b0,&DAT_0099d09c);
        P5 = (float)fVar3;
        P4 = P5;
        if ((f_0 < DAT_0099d094) && (DAT_0099d0b8 == 10)) {
          P4 = DAT_0099d0b4 + f_2;
        }
        fVar3 = extraout_ST1_01;
        if ((DAT_0099d094 < f_0) && (DAT_0099d0b8 == 0x14)) {
          P4 = DAT_0099d0b4 - f_2;
        }
      }
      else {
        ffree(Var4);
        fVar3 = (float10)FUN_0053de20(&DAT_01f95c94,&DAT_0099d0b8,&DAT_0099d0b4,&DAT_0099d0a0);
        P4 = (float)fVar3;
        P5 = P4;
        if ((f_0 < DAT_0099d094) && (DAT_0099d0b8 == 0x14)) {
          P5 = DAT_0099d0b0 - f_2;
        }
        fVar3 = extraout_ST1_00;
        if ((DAT_0099d094 < f_0) && (DAT_0099d0b8 == 10)) {
          P5 = DAT_0099d0b0 + f_2;
        }
      }
    }
    if (DAT_0099d098 != 1) {
      ffree(fVar3);
      Var4 = thunk_FUN_0042c60e(&P4,&DAT_0099d0b8);
      ffree(Var4);
      fVar3 = (float10)thunk_FUN_0042c60e(&P5,&DAT_0099d0b8);
    }
    if (IP9 != 0) {
      P8 = f_3;
      P7 = f_2;
      goto LAB_0053dac3;
    }
  }
  DAT_0099d094 = P6 - P3;
  if ((P8 < f_m1) && (f_m4 < P8)) {
    DAT_0099d094 = P8 * f_2 + DAT_0099d094;
  }
  fVar3 = (float10)DAT_0099d094 / (float10)f_20 + (float10)f_0_9;
  DAT_0099d094 = (float)(ABS((float10)P5 - (float10)P4) * (float10)f_0_1 + fVar3);
  P7 = DAT_0099d094;
LAB_0053dac3:
  if (DAT_0099d0b8 == 0x14) {
    fVar3 = (float10)P7;
    P7 = (float)-fVar3;
  }
  if (DAT_0099d098 == 0) {
    ffree(fVar3);
    Var4 = FUN_0053e094(&P4,&DAT_01f95c94,&DAT_0099d0a0,&DAT_0099d0b8,&IP9);
    ffree(Var4);
    fVar3 = (float10)FUN_0053e094(&P5,&DAT_01f95c98,&DAT_0099d09c,&DAT_0099d0b8,&IP9);
    if (1 < DAT_01f95c90 - DAT_01f95c8c) {
      ffree(fVar3);
      fVar3 = (float10)FUN_0053e32f(&DAT_0099d0b8);
    }
  }
  do {
    DAT_01fb8c80 = DAT_01fb8c80 + 1;
    if (200 < DAT_01fb8c80) goto LAB_0053de17;
    local_20 = 9;
    DAT_01f95c80 = 1;
    do {
      (&DAT_01f95d40)[DAT_01f95c80 + DAT_01fb8c80 * 0xf] = *(undefined4 *)(&P0 + DAT_01f95c80 * 4);
      DAT_01f95c80 = DAT_01f95c80 + 1;
      local_20 = local_20 + -1;
    } while (0 < local_20);
    iVar2 = 6;
    DAT_01f95c80 = 10;
    do {
      (&DAT_01f95d40)[DAT_01f95c80 + DAT_01fb8c80 * 0xf] = f_0;
      DAT_01f95c80 = DAT_01f95c80 + 1;
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
    if (-1 < DAT_0099d098) {
      if (DAT_0099d098 == 0) break;
      DAT_01f95c9c = 1;
      DAT_01f95c88 = DAT_01f95c94 + 1;
      DAT_0099d094 = (float)(&DAT_01f95d4c)[DAT_01f95c94 * 0xf];
      do {
        if (((float)(&DAT_01f95d44)[DAT_01f95c88 * 0xf] != f_1) ||
           (DAT_0099d094 != (float)(&DAT_01f95d4c)[DAT_01f95c88 * 0xf])) break;
        DAT_01f95c9c = DAT_01f95c9c + 1;
        DAT_01f95c88 = DAT_01f95c88 + 1;
      } while (DAT_01f95c88 <= DAT_01fb8c80);
      if (DAT_01f95c9c == 1) break;
      DAT_0078cd30 = DAT_01f95c9c / 2 + 1;
      DAT_0099d098 = -1;
      DAT_01f95c88 = DAT_01f95c94;
    }
    if ((DAT_0078cd64 < 10) && (DAT_0078cd30 == DAT_01f95c9c)) {
      fVar3 = (float10)P7;
      P7 = (float)-fVar3;
      DAT_0099d0b8 = 0x1e - DAT_0099d0b8;
    }
    DAT_01f95c9c = DAT_01f95c9c + -1;
    DAT_01f95c88 = DAT_01f95c88 + 1;
    if (DAT_01f95c9c == 1) {
      DAT_0099d098 = 0;
    }
    ffree(fVar3);
    fVar3 = (float10)amod(&DAT_01f95d50 + DAT_01f95c88 * 0xf,&f_100);
    DAT_0099d094 = (float)fVar3;
    ffree(extraout_ST1_04);
    fVar3 = (float10)FUN_0053df2a(&DAT_0099d094,&DAT_0099d0b8);
  } while( true );
  DAT_01f95c84 = DAT_01f95c84 + 1;
  if (DAT_01fb8cc0 <= DAT_01f95c84) {
LAB_0053de17:
    ffree(fVar3);
    return;
  }
  goto LAB_0053d22e;
}


