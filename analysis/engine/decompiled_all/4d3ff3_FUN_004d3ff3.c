// FUN_004d3ff3 @ 004d3ff3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d3ff3(void)

{
  bool bVar1;
  undefined *local_fc;
  undefined *local_f8;
  undefined2 *local_f4;
  undefined1 local_f0;
  undefined4 local_ec [2];
  undefined **local_e4;
  undefined4 *local_dc [2];
  undefined4 local_d4;
  undefined *local_d0;
  undefined *local_cc;
  undefined2 *local_c8;
  undefined1 local_c4 [4];
  undefined4 local_c0 [9];
  undefined4 local_9c;
  undefined4 local_94;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_5c;
  int local_58;
  int local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_14;
  
  DAT_01aae344 = DAT_0078b6bc;
  DAT_008a0300 = 0x78;
  DAT_01aae34c = NPT;
  DAT_01aae348 = 1;
  if (1 < NPT) {
    DAT_01aae340 = 0;
    DAT_008a02fc = 0;
    while( true ) {
      while( true ) {
        DAT_01aae33c = (int)*(short *)((int)&DAT_01fbb8dc + DAT_01aae348 * 2 + 2);
        while( true ) {
          DAT_01aae334 = (&PT_X0)[DAT_01aae348];
          _DAT_01aae338 = (&PT_Y0)[DAT_01aae348];
          if (-0x2f059 < DAT_01aae334) break;
          DAT_01aae33c = DAT_01aae334 + 0x2f0bc;
          DAT_01aae348 = DAT_01aae348 + 1;
          local_9c = 0;
        }
        if (DAT_01aae33c == 99) break;
        if (DAT_01aae33c != -99) {
          if (DAT_01aae33c != 0) {
            DAT_01aae340 = DAT_01aae33c;
          }
          local_88 = 0;
          goto LAB_004d4190;
        }
        thunk_FUN_004cf166();
        if (DAT_0078b4e0 == 0x42) {
          return;
        }
        DAT_01aae348 = DAT_01aae348 + 1;
        local_8c = 0;
      }
      DAT_01aae32c = (float)_DAT_01aae338;
      thunk_FUN_004cf0d3();
      if (DAT_0078b4e0 == 0x42) break;
      DAT_01aae348 = DAT_01aae348 + 1;
      local_94 = 0;
    }
  }
  return;
LAB_004d4190:
  while( true ) {
    while( true ) {
      while( true ) {
        DAT_008a0304 = DAT_00765510;
        local_28 = 0;
        while( true ) {
          if (200 < IP2) {
            DAT_01aae334 = DAT_01aae334 + 0x8502;
          }
          thunk_FUN_004cf014(local_c4,1,&DAT_01aae334);
          DAT_00793c88 = (undefined *)CONCAT13(local_c4[0],DAT_00793c88._0_3_);
          thunk_FUN_004cf014(local_c4,1,&DAT_01aae338);
          DAT_00793c8c = (undefined *)CONCAT13(local_c4[0],DAT_00793c8c._0_3_);
          local_c0[0] = 0;
          local_d0 = DAT_00793c88;
          local_cc = DAT_00793c8c;
          local_c8 = DAT_00793c90;
          local_c4[0] = DAT_00793c94;
          local_dc[0] = &DAT_01aae334;
          local_fc = DAT_00793c88;
          local_f8 = DAT_00793c8c;
          local_f4 = DAT_00793c90;
          local_f0 = DAT_00793c94;
          local_e4 = &local_fc;
          local_ec[0] = 0xd;
          local_24 = FUN_005fc330(local_c0,0x18,0x784ff09,&DAT_0076550c,local_dc,local_ec);
          if (local_24 == 0) {
            local_cc = &DAT_01aae338;
            local_24 = FUN_005fc980(local_c0,&DAT_0076550c,&local_cc);
            if (local_24 == 0) {
              local_cc = (undefined *)0x2;
              local_c8 = &DAT_008a0304;
              local_24 = FUN_005fc980(local_c0,&DAT_00765508,&local_cc);
            }
          }
          if (local_24 != 0) goto LAB_004d4924;
          local_20 = 0;
          while( true ) {
            while( true ) {
              DAT_01aae348 = DAT_01aae348 + 1;
              DAT_008a0300 = DAT_008a0300 + -1;
              if (DAT_01aae34c <= DAT_01aae348) {
                local_84 = 0;
                if (DAT_01aae340 != 2) {
                  local_d0 = &DAT_00793c7f + DAT_01aae340;
                  local_c0[0] = 0;
                  local_d4 = 1;
                  local_cc = (undefined *)0x1;
                  local_1c = FUN_005fc330(local_c0,0x18,0x784ff01,&DAT_00765504,&local_d4,
                                          &DAT_00793bc8);
                  if (local_1c != 0) goto LAB_004d4924;
                }
                if (DAT_01aae340 != 2) {
                  return;
                }
                local_c0[0] = 0;
                local_cc = (undefined *)0x7;
                local_c8 = (undefined2 *)&DAT_00793c78;
                local_14 = FUN_005fc330(local_c0,0x18,0x784ff01,&DAT_00765508,&local_cc,
                                        &DAT_00793ba8);
                if (local_14 == 0) {
                  if (DAT_008a02f8 == 0) {
                    return;
                  }
                  local_c0[0] = 0;
                  FUN_005fc330(local_c0,0x18,0x784ff00,&DAT_007654f8,0,&DAT_00793c10);
                  DAT_008a02f8 = 0;
                  return;
                }
                goto LAB_004d4924;
              }
              if (DAT_01aae344 < 0) {
                if ((DAT_008a0300 < 1) && (OUTPUT_MODE == -99)) {
                  DAT_008a0300 = 0x78;
                  local_c0[0] = 0;
                  local_78 = FUN_005fc330(local_c0,0x18,0x784ff01,&DAT_007654f8,0,&DAT_00793be8);
                  if (local_78 != 0) goto LAB_004d4924;
                }
                else {
                  local_7c = 0;
                }
              }
              else {
                local_80 = 0;
              }
              while ((DAT_01aae33c = (int)*(short *)((int)&DAT_01fbb8dc + DAT_01aae348 * 2 + 2),
                     DAT_008a02fc != 0 && (DAT_01aae33c == -1))) {
                local_c0[0] = 0;
                FUN_005fc330(local_c0,0x18,0x784ff00,&DAT_007654f8,0,&DAT_00793c00);
                DAT_008a02fc = 0;
                DAT_01aae348 = DAT_01aae348 + 1;
                if (DAT_01aae34c <= DAT_01aae348) {
                  DAT_008a02fc = 0;
                  return;
                }
                local_68 = 0;
              }
              local_74 = 0;
              while( true ) {
                DAT_01aae334 = (&PT_X0)[DAT_01aae348];
                _DAT_01aae338 = (&PT_Y0)[DAT_01aae348];
                if (-0x2f059 < DAT_01aae334) break;
                DAT_01aae33c = DAT_01aae334 + 0x2f0bc;
                DAT_01aae348 = DAT_01aae348 + 1;
                local_64 = 0;
              }
              DAT_008a02f8 = 0;
              if (DAT_01aae33c != 99) break;
              DAT_01aae32c = (float)_DAT_01aae338;
              thunk_FUN_004cf0d3();
              if (DAT_0078b4e0 == 0x42) {
                return;
              }
              local_5c = 0;
            }
            if (DAT_01aae33c != -99) break;
            if (DAT_01aae340 != 2) {
              local_d0 = &DAT_00793c7f + DAT_01aae340;
              local_c0[0] = 0;
              local_d4 = 1;
              local_cc = (undefined *)0x1;
              local_58 = FUN_005fc330(local_c0,0x18,0x784ff01,&DAT_00765504,&local_d4,&DAT_00793bc8)
              ;
              if (local_58 != 0) goto LAB_004d4924;
            }
            if (DAT_01aae340 == 2) {
              local_c0[0] = 0;
              local_cc = (undefined *)0x7;
              local_c8 = (undefined2 *)&DAT_00793c78;
              local_54 = FUN_005fc330(local_c0,0x18,0x784ff01,&DAT_00765508,&local_cc,&DAT_00793ba8)
              ;
              if (local_54 != 0) goto LAB_004d4924;
            }
            thunk_FUN_004cf166();
            if (DAT_0078b4e0 == 0x42) {
              return;
            }
            local_4c = 0;
          }
          bVar1 = DAT_01aae33c == 0x62;
          if (bVar1) {
            DAT_01aae33c = 0;
          }
          DAT_008a02f8 = (uint)bVar1;
          if (0 < DAT_01aae33c) break;
          local_48 = 0;
          DAT_008a0304 = DAT_00765500;
        }
        if (DAT_01aae340 != 0) break;
        DAT_01aae340 = DAT_01aae33c;
        local_44 = 0;
      }
      if (DAT_01aae33c != 3) break;
      local_40 = 0;
    }
    if ((DAT_01aae33c != 1) || (DAT_01aae340 != 1)) break;
    local_3c = 0;
  }
  if (DAT_01aae340 == 2) {
    local_c0[0] = 0;
    local_cc = (undefined *)0x7;
    local_c8 = (undefined2 *)&DAT_00793c78;
    local_34 = FUN_005fc330(local_c0,0x18,0x784ff01,&DAT_00765508,&local_cc,&DAT_00793ba8);
    if (local_34 != 0) {
LAB_004d4924:
      thunk_FUN_004cf1c2();
      return;
    }
    local_30 = 0;
  }
  else {
    local_38 = 0;
    local_d0 = &DAT_00793c7f + DAT_01aae340;
    local_c0[0] = 0;
    local_d4 = 1;
    local_cc = (undefined *)0x1;
    local_2c = FUN_005fc330(local_c0,0x18,0x784ff01,&DAT_00765504,&local_d4,&DAT_00793bc8);
    if (local_2c != 0) goto LAB_004d4924;
  }
  DAT_01aae340 = DAT_01aae33c;
  goto LAB_004d4190;
}


