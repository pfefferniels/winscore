// FUN_00502f69 @ 00502f69 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00502f69(void)

{
  int iVar1;
  float local_54 [2];
  int local_4c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_009a9498 = 0xffffffc0;
  ITEM_I = 0;
  ITEM_WORDS = 1;
  DAT_00795464 = 0;
  DAT_00902a50 = -1;
  DAT_01c58600 = 0;
  DAT_00902a4c = 1;
  _DAT_00902a54 = f_m50;
  for (local_28 = DAT_01b11800; 0 < local_28; local_28 = local_28 + -1) {
    DAT_00902a50 = DAT_00902a50 + 1;
    if ((&DAT_01b11800)[DAT_00902a4c] == 0) {
      DAT_01c58600 = DAT_01c58600 + 1;
      if (*(int *)(DAT_00902a4c * 4 + 0x1b117fc) == 0) {
        local_20 = 0;
      }
      else {
        *(int *)(DAT_01c58600 * 4 + 0x902ba8) = DAT_00902a50;
        if (DAT_00795464 < DAT_00902a50) {
          DAT_00795464 = DAT_00902a50;
        }
        DAT_00902a50 = -1;
      }
    }
    else {
      local_24 = 0;
    }
    local_1c = 0;
    DAT_00902a4c = DAT_00902a4c + 1;
  }
  DAT_00902a50 = (DAT_01c58600 + 1) / 2;
  DAT_00902a48 = DAT_01b11800 - DAT_01c58600;
  DAT_00902a44 = (DAT_00795468 - DAT_01c58600) + 1;
  DAT_00902a34 = -1;
  DAT_00902a38 = f_m5;
  if (DAT_00795460 != (DAT_00795460 / 2) * 2) {
    DAT_00902a34 = 1;
    DAT_00902a38 = f_107;
  }
  if (0 < DAT_00902a34) {
    DAT_00902a48 = DAT_00795464 + DAT_00902a48;
  }
  DAT_00902a30 = DAT_00795464 * 2;
  DAT_00902a2c = DAT_00902a48 % DAT_00902a30;
  if (DAT_00795464 < DAT_00902a2c) {
    DAT_00902a2c = DAT_00795464;
  }
  DAT_00902a28 = DAT_00902a2c + (DAT_00902a48 / DAT_00902a30) * DAT_00795464;
  local_4c = DAT_00902a50 * 5 + DAT_00902a28 * 10;
  DAT_00902a24 = (float)local_4c;
  DAT_00902a3c = f_107;
  DAT_00902a40 = f_m5;
  FUN_00502d0b(&DAT_01ba0d6c,&DAT_00902a24);
  _DAT_00902a1c = (float)DAT_00795440;
  if (_DAT_00902a1c < f_0) {
    _DAT_00902a1c = f_1;
  }
  _DAT_00902a18 = ((float)DAT_01ba0d84 + _DAT_00902a1c) - f_1;
  DAT_00902a50 = 1;
  DAT_00902a14 = 0;
  DAT_00902a10 = 0;
  DAT_00902a28 = 0;
  DAT_00902a0c = 0;
  DAT_00902a08 = f_99999;
  do {
    DAT_00902a38 = DAT_00902a40;
    DAT_00902a10 = DAT_00902a10 + 1;
    if (0 < DAT_00902a34) {
      DAT_00902a38 = DAT_00902a3c;
    }
    local_54[0] = DAT_00902a38 + f_35;
    DAT_00902a20 = DAT_00902a24;
    FUN_0050290d(&DAT_00902a44,&DAT_00902a24,local_54);
    local_18 = *(int *)(DAT_00902a10 * 4 + 0x902ba8);
    DAT_00902a04 = 1;
    for (; 0 < local_18; local_18 = local_18 + -1) {
      FUN_00502a82(&DAT_00902a38,&DAT_00902a24,&DAT_00766e2c);
      local_54[0] = DAT_00902a38 + f_90;
      FUN_00502a82(local_54,&DAT_00902a24,&DAT_00766e2c);
      FUN_00502b10(&DAT_00902a38,&DAT_00902a24);
      _DAT_00902a00 = 0;
      local_14 = (&DAT_01b11800)[DAT_00902a50];
      DAT_009029fc = 1;
      for (; 0 < local_14; local_14 = local_14 + -1) {
        DAT_00902a14 = DAT_00902a14 + 1;
        _DAT_00902a00 = (&DAT_01e9b0ec)[DAT_00902a14] + _DAT_00902a00;
        DAT_009029fc = DAT_009029fc + 1;
      }
      DAT_00902ae4 = DAT_00902a38;
      _DAT_009029f8 = f_90 / (float)_DAT_00902a00;
      P3 = DAT_00902a38 - f_7;
      P4 = DAT_00902a24 - f_1;
      P6 = f_1;
      local_4c = (*(int *)(DAT_00902a10 * 4 + 0x902ba8) - DAT_00902a04) + 1;
      P5 = (float)local_4c;
      P7 = f_1005;
      FUN_00502cae();
      DAT_009029f4 = DAT_00902a38;
      FUN_00502c1d(&DAT_00902a1c,&DAT_00902a24,&DAT_009029f4);
      iVar1 = (&DAT_01b11800)[DAT_00902a50];
      DAT_00902a4c = 2;
      for (; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_00902a28 = DAT_00902a28 + 1;
        DAT_009029f4 = (float)(int)(&DAT_01e9b0ec)[DAT_00902a28] * _DAT_009029f8 + DAT_009029f4;
        FUN_00502a82(&DAT_009029f4,&DAT_00902a24,DAT_00902a28 * 4 + 0x1e9c08c);
        _DAT_00902a1c = _DAT_00902a1c + f_1;
        if (DAT_00902a4c <= (&DAT_01b11800)[DAT_00902a50]) {
          FUN_00502c1d(&DAT_00902a1c,&DAT_00902a24,&DAT_009029f4);
        }
        *(float *)(DAT_00902a4c * 4 + 0x902ae0) = DAT_009029f4;
        DAT_00902a4c = DAT_00902a4c + 1;
      }
      iVar1 = (&DAT_01b11800)[DAT_00902a50];
      DAT_00902a4c = 1;
      for (; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_00902a0c = DAT_00902a0c + 1;
        DAT_009029f4 = ((&DAT_00902ae4)[DAT_00902a4c] - *(float *)(DAT_00902a4c * 4 + 0x902ae0)) /
                       f_2 + *(float *)(DAT_00902a4c * 4 + 0x902ae0);
        local_54[0] = DAT_009029f4 - f_2_5;
        FUN_00502bcd(&DAT_01e9b0ec + DAT_00902a0c,&DAT_00902a24,local_54);
        DAT_00902a4c = DAT_00902a4c + 1;
      }
      DAT_00902a50 = DAT_00902a50 + 1;
      _DAT_009029f0 = (float)_DAT_00902a00;
      FUN_00502b77(&DAT_009029f0,&DAT_00902a24,&DAT_00902a38);
      if ((&DAT_01b11800)[DAT_00902a50] == 0) {
        DAT_00902a50 = DAT_00902a50 + 1;
      }
      else {
        local_10 = 0;
      }
      DAT_00902a24 = DAT_00902a24 - f_10;
      if (DAT_00902a24 < DAT_00902a08) {
        DAT_00902a08 = DAT_00902a24;
      }
      if (_DAT_00902a18 <= _DAT_00902a1c) {
        local_c = 0;
        flush_points();
        *DAT_01fbb7c0 = VEC_N + -1;
        ITEM_P1 = f_0;
        ITEM_P2 = f_0;
        ITEM_I = -1;
        return;
      }
      DAT_00902a04 = DAT_00902a04 + 1;
    }
    DAT_00902a34 = -DAT_00902a34;
    DAT_00902a44 = DAT_00902a44 + 1;
    if (DAT_00902a34 < 1) {
      if (DAT_00902a08 < DAT_00902a24) {
        DAT_00902a24 = DAT_00902a08;
      }
      DAT_00902a20 = DAT_00902a24 - f_12;
      DAT_00902a08 = f_99999;
    }
    local_8 = 0;
    DAT_00902a24 = DAT_00902a20;
  } while( true );
}


