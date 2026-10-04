// draw_box_other @ 00432e80 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_box_other(void)

{
  undefined1 *puVar1;
  unkbyte10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  undefined1 *puVar4;
  float local_4c [11];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  puVar4 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  ffree(in_ST0);
  fVar2 = (float10)push_words(&DAT_00760144,&P1);
  _DAT_007f74ec = NPT;
  _DAT_007f74e8 = STEP * f_6_9996;
  if (P6 == f_0) {
    P6 = f_1;
  }
  if (P7 == f_0) {
    P7 = P6;
  }
  P47 = P6;
  P48 = P7;
  P46 = P13;
  if (P12 == f_0) {
    P12 = f_1;
  }
  if (P13 == f_0) {
    P46 = P12;
  }
  if (IP10 == 1) {
    if ((0 < IP8) && (OUTPUT_MODE == -1)) {
      ffree(fVar2);
      fVar2 = (float10)thunk_FUN_004d4ed2(&IP8);
    }
    _DAT_007f74e4 = X_POS;
    _DAT_007f74e0 = Y_POS;
    _DAT_007f74e8 = STEP * f_6;
    ffree(fVar2);
    Var3 = add_point(&X_POS,&Y_POS,&DAT_00760110);
    P6 = STEP * f_35 * P6 + X_POS;
    ffree(Var3);
    fVar2 = (float10)add_point(&P6,&Y_POS,&DAT_00760108);
    if (-1 < IP12) {
      P13 = _DAT_007f74e8 * P46;
      P12 = P12 * f_0_555 * _DAT_007f74e8;
      if (P47 < f_0) {
        fVar2 = (float10)P13;
        P13 = (float)-fVar2;
      }
      local_4c[0] = P13 + P6;
      ffree(fVar2);
      Var3 = add_point(local_4c,&Y_POS,&DAT_00760100);
      local_4c[0] = P12 + Y_POS;
      ffree(Var3);
      Var3 = add_point(&P6,local_4c,&DAT_00760108);
      local_4c[0] = Y_POS - P12;
      ffree(Var3);
      Var3 = add_point(&P6,local_4c,&DAT_00760108);
      local_4c[0] = P13 + P6;
      ffree(Var3);
      fVar2 = (float10)add_point(local_4c,&Y_POS,&DAT_00760108);
      if (P9 != f_0) {
        ffree(fVar2);
        fVar2 = (float10)thunk_FUN_0042a5f4(&DAT_007f74ec,&DAT_007f74e4,&DAT_007f74e0,&P9);
      }
      if ((0 < IP8) && (OUTPUT_MODE == -1)) {
        ffree(fVar2);
        fVar2 = (float10)thunk_FUN_004d4f3f();
      }
      local_18 = 0;
      goto LAB_00433514;
    }
    local_1c = 0;
  }
  else {
    local_20 = 0;
    if (IP11 < 0x169) {
      local_14 = 0;
    }
    else {
      IP11 = 0x168;
      P11 = f_360;
    }
    IP11 = 0xb4 - IP11;
    IP10 = 0x5a;
    DAT_007f74dc = IP11 % 0x168 + 1;
    DAT_007f74d8 = (P6 * *(float *)(&DAT_01c58a18 + DAT_007f74dc * 8)) / f_20;
    DAT_007f74d4 = (P7 * *(float *)(&DAT_01c58a1c + DAT_007f74dc * 8)) / f_20;
    if (IP9 == 0) {
      local_10 = 0;
      _DAT_007f74cc = DAT_007f74d4;
      _DAT_007f74d0 = DAT_007f74d8;
      P6 = P6 * f_10;
      P7 = P7 * f_10;
    }
    else {
      _DAT_007f74e4 = P9 / f_57_295776;
      ffree(fVar2);
      P6 = P6 * f_10;
      P7 = P7 * f_10;
      fVar2 = (float10)FUN_005ff110(&stack0xfffffffc,0x433087);
      _DAT_007f74d0 = (float)fVar2;
      ffree(extraout_ST1);
      puVar1 = puVar4;
      fVar2 = (float10)FUN_005ff0f5(puVar4,0x4330a9);
      _DAT_007f74cc = (float)fVar2;
      P1 = DAT_007f74d4 * _DAT_007f74d0 + DAT_007f74d8 * _DAT_007f74cc;
      fVar2 = (float10)DAT_007f74d4 * (float10)_DAT_007f74cc;
      P2 = (float)(fVar2 - (float10)DAT_007f74d8 * (float10)_DAT_007f74d0);
      _DAT_007f74cc = P2;
      _DAT_007f74d0 = P1;
      *(undefined4 *)(puVar1 + -8) = 0;
    }
    X_POS = X_POS - _DAT_007f74e8 * _DAT_007f74d0;
    P4 = P4 - _DAT_007f74cc;
    ffree(fVar2);
    fVar2 = (float10)staff_level_y(&P4);
    Y_POS = (float)fVar2;
    IP12 = 0;
    IP5 = 1;
    P13 = f_0;
    if (OUTPUT_MODE != -1) {
      IP9 = 0;
    }
    ffree(extraout_ST1_00);
    fVar2 = (float10)draw_box();
    _DAT_007f74e4 = X_POS;
    _DAT_007f74e0 = Y_POS;
    if (f_0 <= P12) {
      if (P48 < f_0) {
        fVar2 = (float10)P46;
        P46 = (float)-fVar2;
      }
      P6 = P12 * f_1_2;
      P7 = P46 * f_1_2;
      P46 = P46 * f_0_28;
      *(float *)(puVar1 + -0x48) = P46 + P4;
      ffree(fVar2);
      fVar2 = (float10)staff_level_y(puVar1 + -0x48);
      Y_POS = (float)fVar2;
      X_POS = _DAT_007f74e8 * f_5 * P47 + X_POS;
      IP10 = 0;
      IP11 = 0;
      IP12 = 0x78;
      P13 = f_1;
      P8 = f_m1;
      ffree(extraout_ST1_01);
      fVar2 = (float10)draw_box();
    }
    else {
      *(undefined4 *)(puVar1 + -4) = 0;
    }
  }
  if ((OUTPUT_MODE != -1) && (P9 != f_0)) {
    ffree(fVar2);
    fVar2 = (float10)thunk_FUN_0042a5f4(&DAT_007f74ec,&DAT_007f74e4,&DAT_007f74e0,&P9);
  }
LAB_00433514:
  ffree(fVar2);
  Var3 = pop_words(&DAT_00760144,&P1);
  ffree(Var3);
  return;
}


