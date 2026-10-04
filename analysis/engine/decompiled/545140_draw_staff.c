// draw_staff @ 00545140 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_staff(void)

{
  int iVar1;
  float10 in_ST0;
  float10 fVar2;
  
  if (IP2 < 1) goto LAB_0054574a;
  if (VIEW_DY == 0) {
    VIEW_DY = -15000;
  }
  (&MAX_STAFF)[IP2] = (int)P26;
  CUR_STAFF = IP2;
  if (P14 != f_0) {
    P5 = P14 / f_0_889;
    DAT_020b9450 = P5;
  }
  _DAT_0099f7d8 = P5;
  if (P5 == f_0) {
    _DAT_0099f7d8 = f_1;
  }
  DAT_0099f7d4 = _DAT_0099f7d8 * f_25;
  STEP = DAT_0099f7d4;
  (&STAFF_STEP0)[IP2] = DAT_0099f7d4;
  DAT_0099f7d0 = IP11;
  if ((IP11 == 0) && (_DAT_0099f7d8 < f_0_65)) {
    DAT_0099f7d0 = -1;
  }
  *(int *)(&STAFF_THICK0 + CUR_STAFF * 4) = DAT_0099f7d0;
  P50 = IP2 + 1;
  if (199 < IP2) {
    P50 = IP2 + -199;
  }
  P50 = P50 * 0xc4e + -0x765c;
  _DAT_0099f7cc = P4;
  if (f_1000 <= P4) {
    ffree(in_ST0);
    in_ST0 = (float10)staff_y_absolute(&IP2,&P4,&P50);
  }
  else {
    if (P10 == f_0) {
      _DAT_0099f7c8 = (float)P50 + P4 * f_7 * DAT_0099f7d4;
      (&STAFF_Y0)[CUR_STAFF] = (int)ROUND(_DAT_0099f7c8 - DAT_0099f7d4 * f_21);
      in_ST0 = (float10)(int)(&STAFF_Y0)[CUR_STAFF];
      (&STAFF_MID0)[CUR_STAFF] = (int)ROUND((float10)_DAT_0099f7d8 * (float10)f_1225 + in_ST0);
    }
    else {
      ffree(in_ST0);
      fVar2 = (float10)amod(&P10,&DAT_00768ec8);
      _DAT_0099f7c8 = (float)(fVar2 * (float10)f_4000);
      if (DAT_0078b4e8 != 0) {
        _DAT_0099f7c8 = _DAT_0099f7c8 / f_2_54;
      }
      DAT_0099f7c4 = IP10 / 100;
      if (DAT_0099f7c4 == 0) {
        DAT_0099f7c4 = 1;
      }
      in_ST0 = (float10)(int)(&STAFF_Y0)[DAT_0099f7c4];
      _DAT_0099f7c8 =
           (float)((float10)(float)(&STAFF_STEP0)[DAT_0099f7c4] * (float10)f_21 + in_ST0 +
                  (float10)_DAT_0099f7c8);
      (&STAFF_Y0)[CUR_STAFF] = (int)ROUND(_DAT_0099f7c8 - DAT_0099f7d4 * f_21);
    }
    _DAT_0099f7c0 = f_30000;
    if ((P8 == f_0) || (OUTPUT_MODE < 0)) {
      if ((DAT_0099f7d0 == 99) || (OUTPUT_MODE != -1)) {
        DAT_0099f7d0 = 0;
      }
      if ((DAT_0099f7d0 != 0) && (-1 < IP7)) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_004d4ed2(&DAT_0099f7d0);
      }
    }
    else {
      DAT_0099f7d0 = 0;
      _DAT_0099f7cc = f_4000;
      if (DAT_0078b4e8 != 0) {
        _DAT_0099f7cc = f_1574_8;
      }
      _DAT_0099f7cc = _DAT_0099f7cc * P8 + _DAT_0099f7c8;
      ffree(in_ST0);
      in_ST0 = (float10)add_segment(&X_POS,&DAT_0099f7cc,&DAT_0099f7c0,&DAT_0099f7cc);
    }
    if (IP7 < 0) {
      if ((OUTPUT_MODE != -1) && (-1 < DAT_007924c0)) {
        IP7 = 0;
        P26 = f_0_8;
        goto LAB_0054558d;
      }
    }
    else {
LAB_0054558d:
      if (P6 != f_0) {
        _DAT_0099f7c0 = P6 * f_150;
      }
      DAT_0099f7d4 = DAT_0099f7d4 * f_14;
      P50 = 5;
      if (0 < IP7) {
        P50 = IP7;
      }
      if (99 < P50) {
        if (1 < P50 / 100) {
          _DAT_0099f7c8 = (float)(P50 / 100 + -1) * DAT_0099f7d4 + _DAT_0099f7c8;
        }
        P50 = P50 % 100;
      }
      DAT_0099f7bc = 1;
      for (iVar1 = P50; 0 < iVar1; iVar1 = iVar1 + -1) {
        ffree(in_ST0);
        in_ST0 = (float10)add_segment(&X_POS,&DAT_0099f7c8,&DAT_0099f7c0,&DAT_0099f7c8);
        _DAT_0099f7c8 = DAT_0099f7d4 + _DAT_0099f7c8;
        DAT_0099f7bc = DAT_0099f7bc + 1;
      }
      if (DAT_0099f7d0 != 0) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_004d4f3f();
      }
    }
    if ((IP12 == 0) && (-1 < OUTPUT_MODE)) {
      ffree(in_ST0);
      in_ST0 = (float10)draw_staff_number(&DAT_0099f7d8,&CUR_STAFF);
    }
  }
  P50 = 0;
LAB_0054574a:
  ffree(in_ST0);
  return;
}


