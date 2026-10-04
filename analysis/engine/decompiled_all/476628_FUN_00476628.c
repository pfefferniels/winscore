// FUN_00476628 @ 00476628 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476628(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  uint local_64;
  int local_60;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  DAT_0082707c = (&DAT_02091d20)[ITEM_I];
  iVar1 = 0x32;
  DAT_01f95c80 = 0x32;
  do {
    if (*(float *)(&DAT_020b943c + DAT_01f95c80 * 4) != f_0) {
      local_3c = 0;
      break;
    }
    DAT_01f95c80 = DAT_01f95c80 + -1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  if (DAT_01f95c80 < 3) {
    DAT_01f95c80 = 3;
  }
  (&DAT_02091d24)[ITEM_I] = DAT_01f95c80 + DAT_0082707c + 1;
  (&ITEM_LEN)[DAT_0082707c] = (float)DAT_01f95c80;
  P2 = f_0;
  thunk_FUN_0054c590(&DAT_020b9440,&ITEM_P1 + DAT_0082707c,&DAT_01f95c80);
  if (DAT_020b8e50 == 0x10) {
    local_64 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_00827078 = (int)ROUND((DAT_020b946c + f_3) / f_4);
    DAT_00827074 = 0xe;
    if (DAT_020b9474 == f_m1) {
      DAT_00827074 = 0x11;
    }
    local_60 = DAT_00827078;
    thunk_FUN_0054c590(&DAT_01fb8cf8,&ITEM_LEN + DAT_00827074 + DAT_0082707c,&DAT_00827078);
    (&ITEM_LEN)[DAT_0082707c] = (float)(DAT_00827078 + DAT_01f95c80);
    local_34 = 0;
  }
  else {
    local_38 = 0;
  }
  local_64 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_00827070 = (int)ROUND(DAT_020b9440);
  if (DAT_00827070 == 0x10) {
    local_30 = 0;
    DAT_01f95c9c = (int)ROUND((DAT_020b946c + f_3) / f_4);
    DAT_00827074 = 0xd;
    if (DAT_020b9474 == f_m1) {
      DAT_00827074 = 0x10;
    }
    DAT_0082706c = DAT_00827074 + DAT_01f95c9c;
    local_64 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_020527c4 = (int)ROUND((float)(&ITEM_LEN)[DAT_020527c0]);
    local_60 = DAT_020527c4;
  }
  else {
    DAT_0082706c = DAT_020527c8;
    if (DAT_020527c8 < 3) {
      DAT_0082706c = 3;
    }
    local_60 = DAT_00827070;
    if (DAT_01fbb720 < 0) {
      if (DAT_0082706c < 0xf) {
        DAT_0082706c = 0xf;
      }
      if (DAT_01fbb720 == -1) {
        DAT_01fbb720 = 0;
      }
      local_28 = 0;
      goto LAB_00476b62;
    }
    local_2c = 0;
  }
  if (DAT_0078b4e0 == 0x43) {
    local_24 = 0;
    NPT = DAT_01f95c84;
    if (DAT_00827070 == 0x10) {
      local_18 = 0;
      DAT_00827074 = 0xd;
      if (DAT_020b9474 == f_m1) {
        DAT_00827074 = 0x10;
      }
      thunk_FUN_0054c590(&DAT_020b9440,&DAT_01fb8cc4,&DAT_00827074);
      local_64 = DAT_00827074 + DAT_01f95c9c;
      thunk_FUN_00547799(&local_64,&DAT_01fb8cc4);
    }
    else {
      if ((char)DAT_020b8ea0 != 'C') {
        thunk_FUN_00547799(&DAT_0082706c,&DAT_020b9440);
      }
      local_14 = 0;
    }
    EDIT_ITEM = DAT_020527e8;
    local_10 = 0;
    if (DAT_00827070 == 8) {
      local_c = 0;
    }
    else {
      DAT_00827060 = *(int *)(&DAT_020359fc + ITEM_I * 4) - *(int *)(&DAT_020359f8 + ITEM_I * 4);
      DAT_0082705c = (&DAT_02035a00)[DAT_020527e8] - *(int *)(&DAT_020359fc + DAT_020527e8 * 4);
      if (DAT_0082705c == DAT_00827060) {
        DAT_0082705c = *(int *)(&DAT_020359fc + DAT_020527e8 * 4);
        DAT_00827058 = *(int *)(&DAT_020359f8 + ITEM_I * 4);
        thunk_FUN_0054c4c6(DAT_00827058 * VEC_STRIDE + (VEC_BASE - VEC_STRIDE * VEC_LBOUND),
                           (VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_0082705c * VEC_STRIDE,
                           &DAT_00827060);
        ITEM_I = ITEM_I + -1;
        DAT_0205274c = 0;
        thunk_FUN_00549422();
        return;
      }
    }
    DAT_0082706c = DAT_020527e8;
    DAT_00827054 = P2;
    DAT_0078b4e4 = 0;
    _DAT_00827050 = 1;
    _DAT_0082704c = ITEM_WORDS;
    EDIT_ITEM = 0;
    draw_items();
    DAT_0205274c = 0;
    EDIT_ITEM = DAT_0082706c;
    P2 = DAT_00827054;
    return;
  }
LAB_00476b62:
  local_20 = 0;
  _DAT_00827068 = ITEM_I + 1;
  DAT_01f95c98 = EDIT_ITEM + 1;
  DAT_00827064 = P2;
  FUN_00476da3();
  P2 = DAT_00827064;
  return;
}


