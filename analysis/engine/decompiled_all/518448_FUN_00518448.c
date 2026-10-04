// FUN_00518448 @ 00518448 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00518781) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00518448(void)

{
  int iVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  bool bVar6;
  bool bVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 local_bc;
  undefined2 *local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac [8];
  int local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10;
  
  puVar8 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  DAT_020b8e60 = 0;
  _DAT_0078b500 = 0;
  FUN_00519746();
  if (DAT_02052740 != 0) {
LAB_00518476:
    do {
      local_ac[0] = 0;
      local_bc = 0x200;
      local_b8 = &DAT_020b8ea0;
      local_b4 = 1;
      local_8c = FUN_005fdbd0(local_ac,DAT_02052740,0x784ff03,&DAT_007677f8,&local_bc,&DAT_00796918)
      ;
      if ((local_8c == -1) || (bVar6 = false, local_8c != 0)) goto LAB_00518668;
      iVar1 = 1;
      bVar7 = true;
      pbVar2 = (byte *)&DAT_020b8ea0;
      pbVar4 = &DAT_007677f4;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar6 = *pbVar2 < *pbVar4;
        bVar7 = *pbVar2 == *pbVar4;
        pbVar2 = pbVar2 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar7);
      if (bVar6) {
        local_88 = 0;
        goto LAB_00518476;
      }
      iVar1 = 1;
      bVar6 = false;
      pbVar2 = (byte *)&DAT_020b8ea0;
      pbVar4 = &DAT_007677f4;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar6 = *pbVar2 < *pbVar4;
        bVar7 = *pbVar2 == *pbVar4;
        pbVar2 = pbVar2 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar7);
      if ((bVar6 || bVar7) && (iVar1 = FUN_005f4660(0x20), iVar1 != 0)) {
        local_84 = 0;
      }
      else {
        if ((_DAT_020b8ea0 & 0xff) != 0x25) {
          local_80 = 0;
          if ((_DAT_020b8ea0 & 0xff) != 0x2a) break;
LAB_00518668:
          _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_007677d0);
          local_ac[0] = 0;
          FUN_005f7950(local_ac,DAT_02052740,0x784ff00,&DAT_007677cc,0);
          DAT_02052740 = 0;
          draw_items();
          DAT_0078b4e0 = 0;
          FUN_005f34d1(&stack0xfffffffc,0x5186db);
          FUN_005f34d1(puVar8,0x5186fc);
          *(undefined4 *)(puVar8 + -100) = 0;
          return;
        }
        if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x24) {
          thunk_FUN_00549422();
          thunk_FUN_0054d831("*** Hit enter to continue.",0x1a);
        }
        if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x25) {
          while( true ) {
            local_ac[0] = 0;
            local_bc = 0x200;
            local_b8 = &DAT_020b8ea0;
            local_b4 = 1;
            local_78 = FUN_005fdbd0(local_ac,DAT_02052740,0x784ff03,&DAT_007677f8,&local_bc,
                                    &DAT_00796918);
            if ((local_78 == -1) || (local_78 != 0)) goto LAB_00518668;
            if ((_DAT_020b8ea0 & 0xffff) == 0x2525) break;
            local_74 = 0;
            local_78 = 0;
          }
          local_70 = 0;
        }
        else {
          local_7c = 0;
        }
      }
    } while( true );
  }
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  puVar5 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  thunk_FUN_0054c78b(&DAT_0094e1c0);
  if (DAT_02052740 == 0) {
    local_64 = 0;
  }
  else {
    DAT_0094e1bc = 2;
    local_60 = DAT_0094e1c0;
    while (local_60 = local_60 + -1, 0 < local_60) {
      local_b0 = 2;
      iVar1 = FUN_005f4660(0x20);
      if (iVar1 != 0) {
        DAT_0094e1c0 = DAT_0094e1bc + -1;
        local_58 = 0;
        break;
      }
      local_5c = 0;
      local_54 = 0;
      DAT_0094e1bc = DAT_0094e1bc + 1;
    }
  }
  while ((_DAT_020b8ea0 & 0xff) == 0x20) {
    local_4c = 0x1ff;
    DAT_0078b4e0 = 2;
    while ((&DAT_020b8e9f)[DAT_0078b4e0] == ' ') {
      DAT_0078b4e0 = DAT_0078b4e0 + 1;
      local_4c = local_4c + -1;
      if (local_4c < 1) {
        DAT_0078b4e0 = 0x20;
        FUN_005f34d1(&stack0xfffffffc,0x518b2d);
        *(undefined4 *)(puVar9 + -0x40) = 0;
        return;
      }
    }
    local_48 = 0;
    local_40 = 0x9f;
    DAT_0078b4e4 = 1;
    do {
      (&DAT_020b8e9f)[DAT_0078b4e4] = *(undefined1 *)((int)&DAT_020b8ea0 + DAT_0078b4e4);
      DAT_0078b4e4 = DAT_0078b4e4 + 1;
      local_40 = local_40 + -1;
    } while (0 < local_40);
    local_3c = 0;
  }
  local_50 = 0;
  iVar1 = FUN_005f4660(0x20);
  if (iVar1 == 0) {
    local_38 = 0;
    if ((_DAT_020b8ea0 & 0xff) != 0x22) {
      local_30 = 0;
LAB_005189d0:
      do {
        DAT_020b8e60 = _DAT_020b8ea0;
        _DAT_020b8e64 = _DAT_020b8ea4;
        DAT_020b8e68 = DAT_020b8ea8;
        DAT_020b8e6c = _DAT_020b8eac;
        if ((DAT_0078b4e0 == 0x3a) || (DAT_0078b4e0 == 0x27)) {
          local_20 = 0;
          if (DAT_0078b4e4 == 0x3b) {
            return;
          }
        }
        else {
          if ((DAT_0078b4e0 != 0x3b) && ((_DAT_020b8ea0 & 0xff) != 0x60)) {
            local_1c = 0;
            if (((_DAT_020b8ea0 >> 8 & 0xff) != 0x52) &&
               ((((_DAT_020b8ea0 >> 8 & 0xff) != 0x55 && ((_DAT_020b8ea0 & 0xff) == 0x47)) &&
                ((_DAT_020b8ea0 >> 8 & 0xff) != 0x4c)))) {
              return;
            }
            FUN_00518b3f(&DAT_0094e1c0);
            return;
          }
          local_18 = 0;
        }
        thunk_FUN_00572c60(&DAT_0094e1c0);
        DAT_0078b4e0 = (int)(char)DAT_020b8ea0;
        DAT_0078b4e4 = (int)DAT_020b8ea0._1_1_;
        local_10 = 0;
      } while( true );
    }
    local_2c = 0x1ff;
    DAT_0078b4e0 = 2;
    do {
      DAT_01caeb7c._3_1_ = (&DAT_020b909f)[DAT_0078b4e0];
      (&DAT_020b8e9f)[DAT_0078b4e0] = 0x20;
      if (DAT_01caeb7c._3_1_ == '\"') {
        local_28 = 0;
        *(undefined1 *)((int)&DAT_01caea3c + DAT_0078b4e0 + 3) = 0x7e;
        *(undefined1 *)((int)&DAT_01caea40 + DAT_0078b4e0) = 0x7e;
        _DAT_020b8ea0 = CONCAT22(_DAT_020b8ea2,DAT_007677c0);
        goto LAB_005189d0;
      }
      *(char *)((int)&DAT_01caea3c + DAT_0078b4e0 + 3) = DAT_01caeb7c._3_1_;
      DAT_0078b4e0 = DAT_0078b4e0 + 1;
      local_2c = local_2c + -1;
    } while (0 < local_2c);
  }
  else {
    thunk_FUN_0054e546(&P4,&P1);
  }
  return;
}


