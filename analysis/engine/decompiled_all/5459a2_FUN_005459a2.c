// FUN_005459a2 @ 005459a2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005459a2(void)

{
  int iVar1;
  unkbyte10 in_ST0;
  float10 fVar2;
  
  CUR_STAFF = IP2;
  _DAT_0099f7f8 = P5;
  if (P5 == f_0) {
    _DAT_0099f7f8 = f_1;
  }
  DAT_0099f7f4 = _DAT_0099f7f8 * f_25;
  STEP = DAT_0099f7f4;
  (&STAFF_STEP0)[IP2] = DAT_0099f7f4;
  DAT_0099f7f0 = IP11;
  if ((IP11 == 0) && (_DAT_0099f7f8 < f_0_65)) {
    DAT_0099f7f0 = -1;
  }
  *(int *)(&STAFF_THICK0 + CUR_STAFF * 4) = DAT_0099f7f0;
  P50 = (IP2 + -199) * 0xc4e + -0x765c;
  _DAT_0099f7ec = P4;
  if (f_1000 <= P4) {
    ffree(in_ST0);
    fVar2 = (float10)staff_p4_error(&IP2,&P4,&P50);
  }
  else {
    if (P10 == f_0) {
      _DAT_0099f7e8 = (float)P50 + P4 * f_7 * DAT_0099f7f4;
      (&STAFF_Y0)[CUR_STAFF] = (int)ROUND(_DAT_0099f7e8 - DAT_0099f7f4 * f_21);
      fVar2 = (float10)(int)(&STAFF_Y0)[CUR_STAFF];
      (&STAFF_MID0)[CUR_STAFF] = (int)ROUND((float10)_DAT_0099f7f8 * (float10)f_1225 + fVar2);
    }
    else {
      ffree(in_ST0);
      fVar2 = (float10)amod(&P10,&DAT_00768ec8);
      _DAT_0099f7e8 = (float)(fVar2 * (float10)f_4000);
      if (DAT_0078b4e8 != 0) {
        _DAT_0099f7e8 = _DAT_0099f7e8 / f_2_54;
      }
      DAT_0099f7e4 = IP10 / 100;
      if (DAT_0099f7e4 == 0) {
        DAT_0099f7e4 = 1;
      }
      fVar2 = (float10)(int)(&STAFF_Y0)[DAT_0099f7e4];
      _DAT_0099f7e8 =
           (float)((float10)(float)(&STAFF_STEP0)[DAT_0099f7e4] * (float10)f_21 + fVar2 +
                  (float10)_DAT_0099f7e8);
      (&STAFF_Y0)[CUR_STAFF] = (int)ROUND(_DAT_0099f7e8 - DAT_0099f7f4 * f_21);
    }
    _DAT_0099f7e0 = f_30000;
    if ((DAT_0099f7f0 == 99) || (OUTPUT_MODE != -1)) {
      DAT_0099f7f0 = 0;
    }
    if ((DAT_0099f7f0 != 0) && (-1 < IP7)) {
      ffree(fVar2);
      fVar2 = (float10)thunk_FUN_004d4ed2(&DAT_0099f7f0);
    }
    if (-1 < IP7) {
      if (P6 != f_0) {
        _DAT_0099f7e0 = P6 * f_150;
      }
      DAT_0099f7f4 = DAT_0099f7f4 * f_14;
      P50 = 5;
      if (0 < IP7) {
        P50 = IP7;
      }
      DAT_0099f7dc = 1;
      for (iVar1 = P50; 0 < iVar1; iVar1 = iVar1 + -1) {
        ffree(fVar2);
        fVar2 = (float10)add_segment(&X_POS,&DAT_0099f7e8,&DAT_0099f7e0,&DAT_0099f7e8);
        _DAT_0099f7e8 = DAT_0099f7f4 + _DAT_0099f7e8;
        DAT_0099f7dc = DAT_0099f7dc + 1;
      }
      if (DAT_0099f7f0 != 0) {
        ffree(fVar2);
        fVar2 = (float10)thunk_FUN_004d4f3f();
      }
    }
    if ((IP12 == 0) && (-1 < OUTPUT_MODE)) {
      ffree(fVar2);
      fVar2 = (float10)draw_staff_number(&DAT_0099f7f8,&CUR_STAFF);
    }
  }
  ffree(fVar2);
  return;
}


