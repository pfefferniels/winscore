// FUN_00471190 @ 00471190 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00471190(void)

{
  int iVar1;
  float10 in_ST0;
  unkbyte10 Var2;
  
  if ((DAT_01cadd28 == 0) && (DAT_01cb1060 != f_m9999)) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0054d831(&DAT_007620c0,0x24);
  }
  else {
    DAT_0078d864 = (STEP * P48) / f_25;
    _DAT_00824f68 = P13;
    DAT_00824f64 = DAT_01cb1068;
    DAT_00824f60 = 1;
    for (iVar1 = DAT_01cb1068; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (9999 < (int)(&DAT_01caea3c)[DAT_00824f60]) goto LAB_0047126c;
      DAT_00824f60 = DAT_00824f60 + 1;
    }
    DAT_00824f60 = 0;
LAB_0047126c:
    if (DAT_01cb1060 == f_m9999) {
      if (DAT_00824f60 != 0) {
        if (P5 != f_1) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0054d831(&DAT_0076208c,0x30);
          goto LAB_004716cf;
        }
        DAT_01cadd04 = 1;
        _DAT_00824f68 = f_0;
        iVar1 = DAT_00824f60;
        while (iVar1 = iVar1 + -1, 0 < iVar1) {
          _DAT_00824f68 = _DAT_00824f68 + *(float *)(&DAT_01cadd3c + DAT_01cadd04 * 4);
          DAT_01cadd04 = DAT_01cadd04 + 1;
        }
        DAT_00824f64 = DAT_00824f60;
      }
    }
    else if (DAT_00824f60 != 0) {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_0054d831(&DAT_00762054,0x25);
      goto LAB_004716cf;
    }
    iVar1 = -DAT_00824f64 / -1;
    for (DAT_0078d85c = DAT_00824f64; (0 < iVar1 && (999 < (int)(&DAT_01caea3c)[DAT_0078d85c]));
        DAT_0078d85c = DAT_0078d85c + -1) {
      iVar1 = iVar1 + -1;
    }
    DAT_01cadce0 = DAT_0078d85c;
    for (iVar1 = -DAT_0078d85c / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (999 < (int)(&DAT_01caea3c)[DAT_01cadce0]) {
        DAT_00824f5c = DAT_0078b6a0;
        DAT_0078b6a0 = ((&DAT_01caea3c)[DAT_01cadce0] + -1000) % 100;
        break;
      }
      DAT_01cadce0 = DAT_01cadce0 + -1;
    }
    DAT_01cadd04 = (&DAT_01caea3c)[DAT_0078d85c] + 1;
    if (DAT_0078b6a0 < 0x5a) {
      if (DAT_0078b6a0 == 99) goto LAB_004716cf;
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00430a61();
      DAT_0078d858 = *(float *)(&DAT_01cac100 + DAT_01cadd04 * 4 + DAT_00791440 * 0x288) -
                     (float)(int)*(short *)(&DAT_01be5dfa + DAT_00791440 * 0x144 + DAT_01cadd04 * 2)
                     / f_638;
    }
    else {
      if ((DAT_01cadd04 == 0x88) || (DAT_01cadd04 == 0x96)) {
        DAT_01cadd04 = (&DAT_01caea3c)[DAT_0078d85c] + -0x37;
      }
      DAT_0078d858 = *(float *)(&DAT_01c6da5c + DAT_01cadd04 * 4) * f_0_1;
    }
    DAT_0078d858 = DAT_0078d858 * f_3_2833 * DAT_0078d864;
    if (DAT_01cb1060 == f_m9999) {
      if (DAT_01cb1064 == f_0) {
        DAT_01cb1064 = DAT_0078df20;
      }
      DAT_0078df20 = DAT_01cb1064;
      P3 = (DAT_01cb1064 - _DAT_00824f68) + DAT_0078d858;
    }
    else {
      if ((DAT_0078b4e0 != 0) && (DAT_01cb1060 == f_0)) {
        DAT_01cb1060 = DAT_00790cac;
      }
      DAT_00790cac = DAT_01cb1060;
      if (DAT_01cb1064 == f_0) {
        DAT_01cb1064 = DAT_00790ca8;
      }
      DAT_00790ca8 = DAT_01cb1064;
      in_ST0 = (((float10)DAT_01cb1064 + (float10)DAT_0078d858) - (float10)DAT_01cb1060) -
               (float10)P13;
      DAT_0078d858 = (float)(in_ST0 / (float10)DAT_01cadd28);
      P10 = DAT_0078d858 / (P5 * DAT_0078d864) + P10;
      P3 = DAT_01cb1060;
      DAT_020b9464 = P10;
    }
    ffree(in_ST0);
    Var2 = thunk_FUN_0054c590(&P3,&DAT_020b9448,&DAT_0076207c);
    ffree(Var2);
    in_ST0 = (float10)item_position();
    DAT_01cb1064 = f_0;
    DAT_01cb1060 = f_0;
    DAT_0078b6a0 = DAT_00824f5c;
  }
LAB_004716cf:
  ffree(in_ST0);
  return;
}


