// draw_keysig @ 004bf4f8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_keysig(void)

{
  float fVar1;
  int iVar2;
  float10 in_ST0;
  
  DAT_01f95d20 = IP5;
  DAT_01f95d24 = IP5;
  if (IP5 < 0) {
    DAT_01f95d24 = -IP5;
  }
  IP1 = 3;
  _DAT_01f95d68 = STEP;
  X_POS = STEP * f_15 + X_POS;
  DAT_01f95d4c = STEP * f_16_8;
  if (P7 != f_0) {
    DAT_01f95d4c = P7 * DAT_01f95d4c;
  }
  DAT_01f95d28 = 6;
  DAT_01f95d48 = f_1;
  if (-1 < IP5) {
    DAT_01f95d28 = 7;
  }
  if (99 < DAT_01f95d24) {
    DAT_01f95d28 = 8;
    DAT_01f95d24 = DAT_01f95d24 % 100;
  }
  DAT_01f95d34 = IP6;
  if (99 < IP6) {
    DAT_01f95d48 = f_0_8;
    DAT_01f95d4c = f_0_8 * DAT_01f95d4c;
    DAT_01f95d34 = IP6 + -100;
  }
  if (IP8 != 0) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0054c590(&P6,&DAT_01ade840,&DAT_00764bb8);
    iVar2 = 6;
    DAT_01f95d54 = 8;
    do {
      *(undefined4 *)(&IP0 + DAT_01f95d54 * 4) = 0;
      *(float *)(&P0 + DAT_01f95d54 * 4) = f_0;
      DAT_01f95d54 = DAT_01f95d54 + 1;
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
    DAT_01f95d24 = 3;
    goto LAB_004bf7ea;
  }
  DAT_01f95d54 = 0;
  if ((DAT_01f95d34 < 0) || (3 < DAT_01f95d34)) {
    DAT_01f95d34 = 0;
  }
  DAT_01f95d50 = f_84_5;
  if (DAT_01f95d34 == 1) {
    DAT_01f95d50 = f_70_5;
  }
  if (1 < DAT_01f95d34) {
    DAT_01f95d50 = f_77_5;
  }
  DAT_01f95d50 = STEP * DAT_01f95d50 + Y_POS;
  DAT_01f95d2c = -1;
  if (IP5 < 0) {
    DAT_01f95d40 = (float)(&DAT_007925bc)[DAT_01f95d34];
    in_ST0 = (float10)STEP;
    _DAT_01f95d68 = (float)-in_ST0;
  }
  else {
    DAT_01f95d40 = (float)(&DAT_007925ac)[DAT_01f95d34];
    if (DAT_01f95d34 == 3) {
      DAT_01f95d2c = 1;
    }
  }
  _DAT_01f95d64 = STEP * f_49;
  DAT_01f95d3c = _DAT_01f95d68 * f_28;
  DAT_01f95d38 = -(_DAT_01f95d68 * f_21);
  DAT_01f95d30 = 1;
  while( true ) {
    DAT_01f95d44 = STEP * DAT_01f95d40 + Y_POS;
    P10 = f_0;
    iVar2 = DAT_01f95d2c;
    while( true ) {
      DAT_01f95d2c = iVar2;
      ffree(in_ST0);
      in_ST0 = (float10)draw_clef(&X_POS,&DAT_01f95d44,&DAT_01f95d28,&DAT_01f95d48,&DAT_01f95d48);
      if (DAT_01f95d54 != 0) break;
      if (DAT_01f95d24 <= DAT_01f95d30) goto LAB_004bfa50;
      DAT_01f95d30 = DAT_01f95d30 + 1;
      X_POS = DAT_01f95d4c + X_POS;
      fVar1 = DAT_01f95d38;
      if (-DAT_01f95d2c < 0) {
        fVar1 = DAT_01f95d3c;
      }
      DAT_01f95d44 = fVar1 + DAT_01f95d44;
      iVar2 = -DAT_01f95d2c;
      if (DAT_01f95d50 < DAT_01f95d44) {
        DAT_01f95d44 = DAT_01f95d44 - _DAT_01f95d64;
        iVar2 = DAT_01f95d2c;
      }
    }
    if (8 < DAT_01f95d24) goto LAB_004bfa50;
    X_POS = DAT_01f95d4c + X_POS;
    DAT_01f95d24 = DAT_01f95d24 + 1;
    fVar1 = P16;
    if (DAT_01f95d24 < 9) {
LAB_004bf7ea:
      fVar1 = *(float *)(&DAT_01ade83c + DAT_01f95d24 * 4);
    }
    DAT_01f95d54 = (int)ROUND(fVar1);
    if (DAT_01f95d54 == 0) break;
    DAT_01f95d28 = DAT_01f95d54 / 100 + 5;
    DAT_01f95d40 = (float)((DAT_01f95d54 % 100) * 7);
  }
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_0054c590(&DAT_01ade840,&P6,&DAT_00764bb8);
LAB_004bfa50:
  ffree(in_ST0);
  return;
}


