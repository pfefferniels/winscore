// note_ledger_lines @ 004f0871 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void note_ledger_lines(void)

{
  int iVar1;
  unkbyte10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  undefined4 local_58 [9];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  DAT_01a9f300 = (uint)ROUND(P30);
  if ((int)DAT_01a9f300 < 0) goto LAB_004f0d28;
  DAT_01a9f314 = DAT_01f95ce0 * f_5;
  DAT_01a9f31c = X_POS - DAT_01a9f314;
  DAT_01a9f318 = DAT_01f95cf0 + X_POS + DAT_01a9f314;
  fVar2 = (float10)DAT_01a9f360;
  _DAT_01a9f334 = (float)(-fVar2 - (float10)DAT_01a9f360);
  DAT_01a9f30c = IP4;
  if (IP4 < 2) {
    local_34 = 0;
    DAT_01a9f308 = 1;
    DAT_01a9f304 = -2;
    fVar2 = (float10)_DAT_01a9f334;
    _DAT_01a9f334 = (float)-fVar2;
  }
  else {
    DAT_01a9f304 = 2;
    DAT_01a9f308 = 0xd;
    if (IP16 != 0) {
      DAT_01a9f308 = IP16 * 2 + 3;
    }
    IP16 = 0;
    local_30 = 0;
  }
  _DAT_01a9f32c = Y_POS;
  if (DAT_01a9f300 == 0) {
    local_2c = 0;
    DAT_01a9f330 = f_0;
    DAT_01a9f300 = IP4 & 1;
    if ((DAT_01a9f300 != 0) && (IP4 < 0)) {
      DAT_01a9f300 = DAT_01a9f300 - 2;
    }
    if (DAT_01a9f300 == 0) {
      DAT_01a9f330 = _DAT_01a9f334 / f_2;
    }
    _DAT_01a9f32c = DAT_01a9f330 + Y_POS;
  }
  else {
    _DAT_008d1974 = STEP * f_7;
    DAT_01a9f308 = IP4;
    if (DAT_01a9f300 != 1) {
      if (DAT_01a9f300 == 2) {
LAB_004f0aff:
        _DAT_01a9f32c = _DAT_008d1974 + Y_POS;
        local_20 = 0;
      }
      else if (DAT_01a9f300 == 3) {
LAB_004f0ae4:
        _DAT_01a9f32c = Y_POS - _DAT_008d1974;
        local_24 = 0;
      }
      else {
        DAT_01a9f308 = 1;
        DAT_01a9f304 = 1;
        fVar2 = (float10)_DAT_01a9f334;
        _DAT_01a9f334 = (float)ABS(fVar2);
        DAT_01a9f30c = (int)DAT_01a9f300 % 10;
        if ((int)DAT_01a9f300 / 10 != 1) {
          if ((int)DAT_01a9f300 / 10 == 2) goto LAB_004f0aff;
          fVar2 = (float10)_DAT_01a9f334;
          _DAT_01a9f334 = (float)-fVar2;
          if ((int)DAT_01a9f300 < 0x28) goto LAB_004f0ae4;
          local_28 = 0;
        }
      }
    }
  }
  if (OUTPUT_MODE == -1) {
    ffree(fVar2);
    fVar2 = (float10)thunk_FUN_0050ddf0();
    if (DAT_01a9f310 == 99) goto LAB_004f0b43;
    local_18 = 0;
  }
  else {
    local_1c = 0;
LAB_004f0b43:
    DAT_01a9f310 = 0;
  }
  DAT_01a9f300 = DAT_01a9f308;
  local_14 = DAT_01a9f304;
  for (iVar1 = (int)((DAT_01a9f30c - DAT_01a9f308) + DAT_01a9f304) / DAT_01a9f304; 0 < iVar1;
      iVar1 = iVar1 + -1) {
    ffree(fVar2);
    Var3 = add_point(&DAT_01a9f31c,&DAT_01a9f32c,&DAT_007664a8);
    ffree(Var3);
    fVar2 = (float10)add_point(&DAT_01a9f318,&DAT_01a9f32c,&DAT_007664a4);
    _DAT_01a9f32c = _DAT_01a9f334 + _DAT_01a9f32c;
    DAT_01a9f300 = local_14 + DAT_01a9f300;
  }
  if (DAT_01a9f310 != 0) {
    ffree(fVar2);
    fVar2 = (float10)thunk_FUN_004d4f3f();
  }
  if (OUTPUT_MODE == -1) {
    if ((P27 == f_0) && (P26 != (float)(&MAX_STAFF)[IP2])) {
      ffree(fVar2);
      Var3 = FUN_004f0d31(&MAX_STAFF + IP2);
      ffree(Var3);
      Var3 = thunk_FUN_004d3e78();
      local_58[0] = 0;
      ffree(Var3);
      in_ST0 = FUN_005fc330(local_58,0x18,0x784ff00,&DAT_007664a0,0,&DAT_00794e00);
    }
    else {
      local_10 = 0;
      ffree(fVar2);
      in_ST0 = thunk_FUN_004d3e78();
    }
  }
  else if (P26 == (float)(&MAX_STAFF)[IP2]) {
    ffree(fVar2);
    in_ST0 = emit_points();
  }
  else {
    DAT_008d1970 = P26;
    if (IP27 == 0) {
      P26 = (float)(&MAX_STAFF)[IP2];
    }
    DAT_01a9f300 = COLOR;
    DAT_01b11790 = 0;
    ffree(fVar2);
    in_ST0 = flush_points();
    P26 = DAT_008d1970;
    DAT_01b11790 = 0;
    COLOR = DAT_01a9f300;
  }
LAB_004f0d28:
  ffree(in_ST0);
  return;
}


