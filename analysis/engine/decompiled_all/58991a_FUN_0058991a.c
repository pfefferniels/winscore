// FUN_0058991a @ 0058991a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058991a(void)

{
  undefined2 in_FPUControlWord;
  float10 fVar1;
  undefined1 local_64 [4];
  uint local_60;
  undefined4 local_5c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  _DAT_009a92e4 = f_0;
  _DAT_009a92e0 = f_1;
  DAT_01a9f31c = 0;
  if (6 < LOAD_LEN) {
    _DAT_009a92e0 = *(float *)(&ITEM_P7 + LOAD_W * 4);
  }
  if (f_32 <= _DAT_009a92e0) {
    DAT_009a92dc = 8;
    local_34 = 0;
LAB_00589d3a:
    FUN_00589da2(s_RWRFRIRDRURPTRBAALTEPR_007a05b0 + DAT_009a92dc + 0x17,1);
    goto LAB_00589d51;
  }
  local_38 = 0;
  local_60 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_009a92d8 = (int)ROUND(_DAT_009a92e0 * f_1000);
  local_5c = DAT_009a92d8;
  if (LOAD_CODE == 2) {
    if (5 < LOAD_LEN) {
      DAT_01a9f31c = (int)ROUND((float)(&ITEM_P6)[LOAD_W]);
      local_28 = 0;
      local_5c = DAT_01a9f31c;
      goto LAB_00589a6d;
    }
    local_2c = 0;
  }
  else {
    local_30 = 0;
    if (LOAD_LEN < 9) {
      local_24 = 0;
    }
    else {
      local_5c = (int)ROUND(*(float *)(&ITEM_P9 + LOAD_W * 4));
      DAT_01a9f31c = (local_5c % 100) / 10;
LAB_00589a6d:
      local_60 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      if (DAT_01a9f31c == 1) {
        DAT_009a92d8 = (DAT_009a92d8 * 2) / 3;
      }
      if (DAT_01a9f31c == 2) {
        DAT_009a92d8 = (DAT_009a92d8 * 4) / 7;
      }
    }
  }
  local_20 = 7;
  DAT_009a92dc = 1;
  do {
    if (DAT_009a92d8 == *(int *)(DAT_009a92dc * 4 + 0x7a05cc)) {
      local_1c = 0;
      goto LAB_00589d3a;
    }
    DAT_009a92dc = DAT_009a92dc + 1;
    local_20 = local_20 + -1;
  } while (0 < local_20);
  _DAT_009a92e4 = f_4 / _DAT_009a92e0;
  local_60 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_009a92dc = (int)ROUND(_DAT_009a92e4 + f_0_01);
  _DAT_009a92e0 = (float)DAT_009a92dc;
  if (_DAT_009a92e4 - _DAT_009a92e0 < f_0_01) {
    _DAT_009a92e4 = f_0;
  }
  local_5c = DAT_009a92dc;
  if (9 < DAT_009a92dc) goto LAB_00589b83;
  local_18 = 0;
  while( true ) {
    DAT_009a92dc = DAT_009a92dc + 0x30;
    local_5c = CONCAT13((undefined1)DAT_009a92dc,(undefined3)local_5c);
    local_64[0] = (undefined1)DAT_009a92dc;
    FUN_00589da2(local_64,1);
    if (_DAT_009a92e4 == f_0) break;
    FUN_00589da2(&DAT_0076ae58,1);
    fVar1 = (float10)amod(&DAT_009a92e4,&f_1);
    local_60 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_009a92d4 = (int)ROUND(fVar1 * (float10)f_10000);
    DAT_009a92d8 = DAT_009a92d4 / 1000 + 0x30;
    local_5c._0_3_ = (undefined3)DAT_009a92d4;
    local_5c = CONCAT13((undefined1)DAT_009a92d8,(undefined3)local_5c);
    local_64[0] = (undefined1)DAT_009a92d8;
    FUN_00589da2(local_64,1);
    DAT_009a92dc = DAT_009a92d4 % 1000;
    DAT_009a92d8 = DAT_009a92dc / 100 + 0x30;
    local_5c = CONCAT13((undefined1)DAT_009a92d8,(undefined3)local_5c);
    local_64[0] = (undefined1)DAT_009a92d8;
    FUN_00589da2(local_64,1);
    DAT_009a92dc = DAT_009a92dc % 100;
    _DAT_009a92e4 = f_0;
    local_10 = 0;
LAB_00589b83:
    DAT_009a92d8 = DAT_009a92dc / 10 + 0x30;
    local_5c = CONCAT13((undefined1)DAT_009a92d8,(undefined3)local_5c);
    local_64[0] = (undefined1)DAT_009a92d8;
    FUN_00589da2(local_64,1);
    DAT_009a92dc = DAT_009a92dc % 10;
  }
  local_14 = 0;
LAB_00589d51:
  for (; 0 < DAT_01a9f31c; DAT_01a9f31c = DAT_01a9f31c + -1) {
    FUN_00589da2(&DAT_0076ae58,1);
    local_8 = 0;
  }
  local_c = 0;
  FUN_00589da2(&DAT_0076adf8,1);
  return;
}


