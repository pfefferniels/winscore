// draw_meter @ 004bfa59 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_meter(void)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  DAT_01f95d44 = P4;
  thunk_FUN_0054c590(&P5,&DAT_01ade840,&DAT_00764c40);
  if (P7 == f_0) {
    P7 = f_1;
  }
  P8 = f_0;
  P9 = f_0;
  P14 = f_0;
  DAT_01f95d20 = IP5;
  if (IP5 < 0x5b) {
    DAT_01f95d24 = IP6;
    DAT_01f95d28 = IP8;
    DAT_01f95d2c = IP9;
    _DAT_0089fa04 = IP10;
    if ((OUTPUT_MODE == -1) || (IP13 != 0)) {
      P4 = P4 + f_0_1;
      fVar1 = f_1_2;
    }
    else {
      P4 = P4 - f_0_23;
      fVar1 = f_1_35;
    }
    DAT_01f95d4c = P7 * fVar1;
    DAT_01f95d60 = X_POS;
    if (IP8 != 0) {
      _DAT_0089fa00 = X_POS;
      DAT_0089f9fc = IP5;
      if (IP9 == 0) {
        DAT_01f95d2c = -1;
      }
      IP9 = 0;
      fVar1 = STEP * f_6 * P7;
      DAT_01f95d58 = (P11 + f_4_2) * fVar1;
      DAT_01f95d30 = IP12;
      _DAT_01f95d64 = X_POS;
      if (IP12 == 0) {
        DAT_01f95d54 = f_3_5;
        if ((9 < IP5) || (9 < IP6 && 0 < DAT_01f95d2c)) {
          DAT_01f95d54 = f_6_6;
        }
        _DAT_01f95d64 = (P10 + DAT_01f95d54) * fVar1 + X_POS;
      }
    }
    if ((OUTPUT_MODE == -1) || (IP13 != 0)) {
      _DAT_01f95d5c = f_5_82;
    }
    else {
      _DAT_01f95d5c = f_5_46;
    }
    if (IP5 == 0) {
      _DAT_01f95d5c = f_4_08;
      DAT_01f95d20 = IP6;
      DAT_01f95d24 = 0;
    }
    DAT_0089f9f8 = _DAT_01f95d5c * DAT_01f95d4c + P4;
    while( true ) {
      DAT_01f95d44 = DAT_0089f9f8;
      P6 = DAT_01f95d4c;
      P7 = DAT_01f95d4c;
      DAT_01f95d38 = DAT_01f95d60;
      DAT_01f95d3c = DAT_01f95d60;
      if ((-1 < DAT_01f95d2c) && (9 < DAT_01f95d24 || 9 < DAT_01f95d20)) {
        DAT_01f95d40 = STEP * f_7_6 * DAT_01f95d4c + DAT_01f95d60;
        if (DAT_01f95d20 < 10) {
          DAT_01f95d38 = DAT_01f95d40;
        }
        if (DAT_01f95d24 < 10) {
          DAT_01f95d3c = DAT_01f95d40;
        }
      }
      X_POS = DAT_01f95d38;
      while( true ) {
        fVar3 = (float10)staff_level_y(&DAT_01f95d44);
        Y_POS = (float)fVar3;
        IP8 = 0;
        if (P13 == f_0) {
          IP7 = 6;
          IP9 = -1;
        }
        else {
          IP7 = (int)ROUND(P13);
        }
        P5 = (float)DAT_01f95d20;
        DAT_0089f9f4 = DAT_020b945c;
        draw_number(&DAT_01f95d20);
        iVar2 = DAT_01f95d24;
        IP9 = 0;
        DAT_020b945c = DAT_0089f9f4;
        if (DAT_01f95d24 < 1) break;
        DAT_01f95d20 = DAT_01f95d24;
        DAT_01f95d24 = 0;
        DAT_01f95d44 = DAT_01f95d4c * f_2_48 + P4;
        if (DAT_01f95d2c < 0) {
          DAT_01f95d60 = f_3_8;
          if (9 < iVar2) {
            DAT_01f95d60 = f_2_4;
          }
          if (9 < DAT_0089f9fc) {
            DAT_01f95d60 = DAT_01f95d60 + f_3_4;
          }
          X_POS = (P10 + DAT_01f95d60) * f_4_8 * STEP * DAT_01f95d4c + _DAT_0089fa00;
        }
        else {
          X_POS = DAT_01f95d3c;
        }
      }
      if (DAT_01f95d28 == 0) break;
      if (DAT_01f95d30 == 0) {
        IP1 = 3;
        DAT_01f95d44 = f_4_72;
        if (DAT_01f95d2c < 1) {
          DAT_01f95d44 = f_6_6;
        }
        DAT_01f95d44 = DAT_01f95d4c * DAT_01f95d44 + P4;
        fVar3 = (float10)staff_level_y(&DAT_01f95d44);
        DAT_01f95d44 = (float)fVar3;
        draw_clef(&DAT_01f95d64,&DAT_01f95d44,&DAT_00764be8,&DAT_01f95d4c,&DAT_01f95d4c);
      }
      DAT_01f95d20 = DAT_01f95d28;
      DAT_01f95d60 = DAT_01f95d58 + _DAT_01f95d64;
      DAT_01f95d28 = 0;
      DAT_01f95d24 = DAT_01f95d2c;
    }
  }
  else {
    IP1 = 3;
    DAT_01f95d4c = P7 * f_0_75;
    DAT_01f95d20 = 0x75 - IP5;
    draw_symbol(&X_POS,&Y_POS,&DAT_01f95d20,&DAT_01f95d4c,&DAT_01f95d4c,&DAT_00764c38,&f_0,&f_0);
  }
  thunk_FUN_0054c590(&DAT_01ade840,&P5,&DAT_00764c40);
  return;
}


