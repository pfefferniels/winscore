// FUN_0045d278 @ 0045d278 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045d278(void)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char *pcVar5;
  bool bVar6;
  undefined2 in_FPUControlWord;
  float10 fVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 local_cc;
  undefined4 *local_c8;
  undefined4 *local_c4;
  uint local_c0;
  int local_bc;
  undefined4 local_b8 [9];
  undefined4 local_94;
  undefined4 local_8c;
  int local_80;
  undefined4 local_7c;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  puVar8 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  if (_DAT_020b8ea0 == 0x45544144) {
    FUN_0045e1ee();
    return;
  }
  if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x59) {
    thunk_FUN_00552d80();
    return;
  }
  local_94 = 0;
  if ((DAT_0078b4e4 == 0x58) || (DAT_0078b4e4 == 0x42)) {
    if (DAT_01beabe0 == 0) {
      return;
    }
    if (DAT_01beabe0 == 0) {
      return;
    }
    _DAT_008242d8 = DAT_0078b510;
    DAT_008242dc = DAT_0078b514;
    DAT_008242e0 = DAT_0078b518;
    DAT_008242e4 = 0x20;
    puVar2 = &DAT_0078b510;
    puVar4 = &DAT_01beabc0;
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_0045da56();
    _DAT_008242d8 = DAT_01beabc0;
    DAT_008242dc = DAT_01beabc4;
    DAT_008242e0 = DAT_01beabc8;
    DAT_008242e4 = DAT_01beabcc;
    DAT_008242c8 = 1;
    local_80 = DAT_01beac00;
    do {
      if (local_80 < 1) {
        return;
      }
      bVar6 = local_80 == 0;
      iVar1 = 0xd;
      pcVar3 = (char *)(DAT_008242c8 * 0xd + 0x1be78d7);
      pcVar5 = &DAT_008242d8;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        local_7c = 0;
        if (DAT_0078b4e4 == 0x42) {
          DAT_01beabe4 = DAT_008242c8 + -1;
          if (DAT_01beabe4 == 0) {
            DAT_01beabe4 = DAT_01beac00;
          }
        }
        else {
          DAT_01beabe4 = DAT_008242c8 + 1;
          if (DAT_01beac00 < DAT_01beabe4) {
            DAT_01beabe4 = 1;
          }
        }
        FUN_005f33c9(&stack0xfffffffc,0x45d96d);
        FUN_005f34d1(puVar9,0x45d988);
        FUN_005f33c9(puVar9,0x45d9aa);
        FUN_005f34d1(puVar9,0x45d9c5);
        DAT_0078b4e4 = 0x20;
        cmd_get();
        iVar1 = FUN_005f4660(0x20);
        if (iVar1 != 0) {
          *(undefined4 *)(puVar9 + -0x70) = 0;
          return;
        }
        _DAT_020b8ea4 = _DAT_020b90a3;
        DAT_020b8ea8 = ram0x020b90a7;
        _DAT_020b8eac = _DAT_020b90ab;
        DAT_020b8eb0._0_1_ = DAT_020b90af;
        *(undefined4 *)(puVar9 + -0x6c) = 0;
        return;
      }
      DAT_008242c8 = DAT_008242c8 + 1;
      local_80 = local_80 + -1;
    } while( true );
  }
  local_8c = 0;
  if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x47) {
    local_6c = 0;
  }
  else {
    if (DAT_0078b4e4 != 0x45) {
      local_68 = 0;
      if ((DAT_0078b4e4 == 0x49) && ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x52)) {
        _DAT_008242ac = 2;
        local_1c = 0;
        thunk_FUN_0054c5f8(&DAT_020b90a0,1,&DAT_020b8ea0,1,&DAT_00761630);
        return;
      }
      local_20 = 0;
      if (DAT_0078b4e4 != 0x41) {
        return;
      }
      DAT_0078b4e4 = 0x45;
      thunk_FUN_00575e58();
      return;
    }
    if ((_DAT_020b8ea0 & 0xff) == 0x53) {
      local_64 = 0;
      goto LAB_0045d7da;
    }
    local_60 = 0;
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x43) {
      thunk_FUN_004479a8();
      return;
    }
    local_58 = 0;
  }
  if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x50) {
    local_50 = 0;
    DAT_008242bc = 0xc9;
    DAT_008242b8 = 0x100;
    if (_DAT_020b8ea0 >> 0x18 == 0x52) {
      DAT_008242bc = 1;
      DAT_008242b8 = 200;
    }
    thunk_FUN_005725fa();
    ITEM_WORDS = 1;
    DAT_008242c8 = 1;
    for (local_34 = ITEM_I; 0 < local_34; local_34 = local_34 + -1) {
      DAT_008242b4 = (&ITEM_PTR0)[DAT_008242c8];
      DAT_008242d0 = (int)ROUND((float)(&ITEM_P2)[DAT_008242b4]);
      if ((DAT_008242d0 < DAT_008242bc) || (DAT_008242b8 < DAT_008242d0)) {
        local_30 = 0;
        local_bc = DAT_008242d0;
      }
      else {
        local_bc = (int)ROUND((float)DAT_008242b4 + (float)(&ITEM_LEN)[DAT_008242b4]);
        DAT_008242b0 = DAT_008242b4;
        for (local_2c = (local_bc - DAT_008242b4) + 1; 0 < local_2c; local_2c = local_2c + -1) {
          (&DAT_01e9997c)[ITEM_WORDS] = (&ITEM_LEN)[DAT_008242b0];
          ITEM_WORDS = ITEM_WORDS + 1;
          DAT_008242b0 = DAT_008242b0 + 1;
        }
      }
      local_c0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      local_28 = 0;
      DAT_008242c8 = DAT_008242c8 + 1;
    }
    thunk_FUN_0054c590(&DAT_01e99980,&ITEM_P1,&ITEM_WORDS);
    draw_items();
    return;
  }
  if (((EDIT_ITEM == 0) && ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4c)) &&
     (_DAT_020b8ea0 >> 0x18 == 0x2a)) {
    local_b8[0] = 0;
    local_cc = 0x2e;
    local_c8 = &DAT_020b90a4;
    local_c4 = &DAT_008242cc;
    FUN_005f47c0(local_b8,0xffffffff,0x784ff00,&DAT_00761624,&local_cc);
    if ((DAT_008242cc & 1) == 0) {
      return;
    }
    FUN_005f33c9(&stack0xfffffffc,0x45d6f2);
    FUN_005f33c9(puVar8,0x45d70e);
    FUN_005f34d1(puVar8,0x45d729);
    DAT_008242c4 = thunk_FUN_00595f30(&DAT_020b8ea0,1);
    if (DAT_008242c4 == 0) {
      *(undefined4 *)(puVar8 + -0x3c) = 0;
      return;
    }
    fVar7 = (float10)FUN_005f7ed0(&DAT_020b90a4,0x2e);
    *(undefined2 *)(puVar8 + -0xbc) = in_FPUControlWord;
    *(ushort *)(puVar8 + -0xba) = (ushort)*(undefined4 *)(puVar8 + -0xbc) | 0xc00;
    *(int *)(puVar8 + -0xb8) = (int)ROUND(fVar7);
    _DAT_008242c0 = *(undefined4 *)(puVar8 + -0xb8);
    FUN_005f34d1(puVar8,0x45d7c3);
    *(undefined4 *)(puVar8 + -0x38) = 0;
    return;
  }
  local_4c = 0;
LAB_0045d7da:
  thunk_FUN_004a217d();
  return;
}


