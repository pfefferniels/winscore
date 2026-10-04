// FUN_00567bc7 @ 00567bc7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00567bc7(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_64;
  undefined4 *local_60;
  undefined4 local_58 [8];
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_01a1fe80._0_2_ = DAT_020b8ea0;
  DAT_01a1fe80._2_1_ = DAT_020b8ea2;
  push_words(&DAT_0076a070,&DAT_0078b610);
  push_words(&DAT_0076a070,&DAT_0078b510);
  if (DAT_020b8ea0._1_1_ == 'Y') {
    local_34 = 0x1fe;
    DAT_0078b4e0 = 3;
    do {
      if (s_______09___InchesMetricParallel_P_0078da40[0] == (&DAT_020b8e9f)[DAT_0078b4e0]) {
        local_30 = 0;
        break;
      }
      DAT_0078b4e0 = DAT_0078b4e0 + 1;
      local_34 = local_34 + -1;
    } while (0 < local_34);
    DAT_0078b4e4 = DAT_0078b4e0 + 1;
    for (local_2c = 0x201 - DAT_0078b4e4; 0 < local_2c; local_2c = local_2c + -1) {
      if (s_______09___InchesMetricParallel_P_0078da40[0] != (&DAT_020b8e9f)[DAT_0078b4e4]) {
        local_28 = 0;
        thunk_FUN_0054c5f8(&DAT_020b8e9f + DAT_0078b4e4,1,&DAT_0078b610,0x80,&DAT_0076a06c);
        local_20 = 0;
        goto LAB_00567dde;
      }
      DAT_0078b4e4 = DAT_0078b4e4 + 1;
    }
    local_24 = 0;
  }
  else {
    local_38 = 0;
  }
  if (DAT_02052740 == 0) {
    thunk_FUN_00572158();
    puVar2 = (undefined4 *)&DAT_020b8ea0;
    puVar3 = &DAT_0078b610;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    local_14 = 0;
  }
  else {
    local_18 = 0;
    while( true ) {
      local_58[0] = 0;
      local_64 = 0x80;
      local_60 = &DAT_0078b610;
      local_10 = FUN_005fdbd0(local_58,DAT_02052740,0x784ff01,&DAT_0076a04c,&local_64,&DAT_0079f6bc)
      ;
      if (local_10 == 0) break;
      DAT_02052740 = 0;
      local_1c = 0;
    }
  }
  iVar1 = FUN_005f4660(0x20);
  if (iVar1 == 0) {
    local_c = 0;
LAB_00567dde:
    DAT_0078b4e0 = 0x52;
    DAT_0078b4e4 = 0x45;
    FUN_005f34d1(&stack0xfffffffc,0x567e11);
    thunk_FUN_00522bd8();
  }
  else {
    DAT_0078b4e0 = 0xffffffff;
    local_8 = 0;
  }
  pop_words(&DAT_0076a070,&DAT_0078b510);
  pop_words(&DAT_0076a070,&DAT_0078b610);
  return;
}


