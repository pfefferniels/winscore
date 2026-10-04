// FUN_00474742 @ 00474742 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004747e7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00474742(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar2;
  float10 fVar3;
  unkbyte10 Var4;
  unkbyte10 in_ST1;
  unkbyte10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined4 *local_54;
  int local_50;
  undefined4 local_4c [8];
  int local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_0078b4e8 == 1) {
    P2 = P2 / f_2_54;
  }
  local_2c = 0x7c;
  DAT_00826a4c = 5;
  while (((&DAT_020b909f)[DAT_00826a4c] != ':' && ((&DAT_020b909f)[DAT_00826a4c] != '\''))) {
    local_28 = 0;
    local_1c = 0;
    DAT_00826a4c = DAT_00826a4c + 1;
    local_2c = local_2c + -1;
    if (local_2c < 1) goto LAB_004748c8;
  }
  local_5c = 3;
  local_58 = &DAT_020b90a0 + DAT_00826a4c;
  local_4c[0] = 0;
  local_54 = &DAT_00826a48;
  ffree(in_ST1);
  ffree(in_ST0);
  FUN_005f9240(local_4c,0x784ff00,&DAT_00762230,&local_5c,&DAT_00790d50);
  in_ST0 = (float10)P3 + (float10)f_1;
  local_50 = (int)ROUND(in_ST0);
  local_58 = (undefined1 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
  local_54 = (undefined4 *)(int)ROUND(in_ST0);
  DAT_00826a44 = local_50;
  for (iVar1 = (DAT_00826a48 - (int)local_54) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(float *)(&P0 + DAT_00826a44 * 4) = (float)DAT_00826a44;
    DAT_00826a44 = DAT_00826a44 + 1;
  }
  local_20 = 0;
  in_ST1 = extraout_ST1;
LAB_004748c8:
  ffree(in_ST1);
  ffree(in_ST0);
  fVar2 = (float10)thunk_FUN_005725fa();
  local_18 = 0x26;
  DAT_00826a4c = 3;
  fVar3 = extraout_ST1_00;
  do {
    if (*(float *)(&P0 + DAT_00826a4c * 4) == f_0) {
      local_14 = 0;
    }
    else {
      local_54 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
      DAT_00826a40 = (int)ROUND(*(float *)(&P0 + DAT_00826a4c * 4));
      DAT_00826a3c = 0;
      LOAD_I = 1;
      local_50 = DAT_00826a40;
      for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
        ffree(fVar3);
        ffree(fVar2);
        fVar2 = (float10)load_item_header();
        if (LOAD_CODE == 8) {
          if ((DAT_00826a3c < LOAD_STAFF) && (LOAD_STAFF < DAT_00826a40)) {
            DAT_00826a3c = LOAD_STAFF;
            DAT_00826a38 = LOAD_W;
          }
          if (DAT_00826a40 == LOAD_STAFF) {
            DAT_00826a34 = LOAD_W;
          }
        }
        else {
          local_10 = 0;
        }
        local_c = 0;
        LOAD_I = LOAD_I + 1;
        fVar3 = extraout_ST1_01;
      }
      _DAT_00826a30 = f_175;
      if ((f_4 < (float)(&ITEM_LEN)[DAT_00826a34]) && ((float)(&ITEM_P5)[DAT_00826a34] != f_0)) {
        _DAT_00826a30 = (float)(&ITEM_P5)[DAT_00826a34] * f_175;
      }
      _DAT_00826a2c = f_175;
      if ((f_4 < (float)(&ITEM_LEN)[DAT_00826a38]) && ((float)(&ITEM_P5)[DAT_00826a38] != f_0)) {
        _DAT_00826a2c = (float)(&ITEM_P5)[DAT_00826a38] * f_175;
      }
      _DAT_00826a28 = (int)ROUND(_DAT_00826a2c * f_11 + (float)(int)(&STAFF_Y0)[DAT_00826a3c]);
      fVar2 = (float10)_DAT_00826a28;
      fVar3 = (float10)P2 * (float10)f_4000;
      local_54 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
      DAT_00826a24 = (int)ROUND((fVar3 - (float10)_DAT_00826a30 * (float10)f_3) + fVar2);
      local_50 = DAT_00826a24 - (&STAFF_Y0)[DAT_00826a40];
      _DAT_00826a20 = (float)local_50;
      (&STAFF_Y0)[DAT_00826a40] = DAT_00826a24;
      _DAT_00826a1c = _DAT_00826a20 / _DAT_00826a30;
      (&ITEM_P4)[DAT_00826a34] = _DAT_00826a1c + (float)(&ITEM_P4)[DAT_00826a34];
    }
    local_8 = 0;
    DAT_00826a4c = DAT_00826a4c + 1;
    local_18 = local_18 + -1;
  } while (0 < local_18);
  ffree(fVar3);
  ffree(fVar2);
  Var4 = draw_items();
  ffree(extraout_ST1_02);
  ffree(Var4);
  return;
}


