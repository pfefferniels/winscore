// FUN_00567e5b @ 00567e5b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00567e5b(void)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  int local_84;
  char *local_80;
  undefined4 local_7c;
  char *local_78;
  int local_74;
  int local_70;
  char *local_6c;
  undefined4 local_68 [8];
  undefined4 local_48;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_005f33c9();
  FUN_005f34d1();
  iVar1 = FUN_005f4660();
  if (iVar1 == 0) {
    local_48 = 0;
  }
  else {
    thunk_FUN_00572158();
    puVar4 = (undefined4 *)&DAT_020b8ea0;
    puVar8 = (undefined4 *)&DAT_020b90a1;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar8 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar8 = puVar8 + 1;
    }
    iVar1 = FUN_005f4660();
    if (iVar1 != 0) {
      return;
    }
  }
LAB_00567f1f:
  thunk_FUN_0054cb15(&DAT_020b90a1,0x80);
  DAT_009a7e70 = DAT_009a7e74 + 1;
  FUN_005f46bc();
  FUN_005f34d1();
  local_68[0] = 0;
  local_84 = 6;
  local_80 = "binary";
  local_7c = 3;
  local_78 = "old";
  local_74 = 2;
  local_40 = FUN_005f6540(local_68,5,0x784ff01,&DAT_0076a098);
  if (local_40 != 0) goto LAB_00568417;
  puVar4 = (undefined4 *)&DAT_020b90a1;
  puVar8 = &DAT_0078b610;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar8 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar8 = puVar8 + 1;
  }
  for (iVar1 = 1; iVar1 < 0x4e21; iVar1 = iVar1 + 1) {
    *(undefined1 *)((int)&DAT_009a9498 + iVar1 + 3) = 0x20;
  }
  local_68[0] = 0;
  local_7c = 20000;
  local_78 = &DAT_009a949c;
  local_74 = 1;
  local_3c = FUN_005f8240(local_68,5,0x784ff03,&DAT_0076a094);
  if (local_3c != -1) {
    if (local_3c != 0) goto LAB_00568417;
    local_38 = 0;
  }
  local_30 = 0;
  local_68[0] = 0;
  FUN_005f7950(local_68,5,0x784ff00,&DAT_00769ee0);
  puVar4 = (undefined4 *)&DAT_020b90a1;
  puVar8 = (undefined4 *)&DAT_007a0b7c;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar8 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar8 = puVar8 + 1;
  }
  FUN_005f33c9();
  FUN_005f34d1();
  bVar11 = &stack0x00000000 == (undefined1 *)0x9c;
  iVar1 = 0x11;
  pcVar3 = &DAT_020b90a1;
  pcVar7 = " C:\\!tmp\\msee.tmp";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar11 = *pcVar3 == *pcVar7;
    pcVar3 = pcVar3 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar11);
  if (bVar11) {
    FUN_005f33c9();
    FUN_005f34d1();
  }
  DAT_009a7e6c = thunk_FUN_0059bf80();
  if (DAT_009a7e6c == 2) {
    iVar1 = FUN_005f4660();
    if (iVar1 != 0) {
      local_28 = 0;
      goto LAB_00568409;
    }
    puVar4 = (undefined4 *)&DAT_007a0b7c;
    puVar8 = (undefined4 *)&DAT_020b90a1;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar8 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar8 = puVar8 + 1;
    }
    local_24 = 0;
    goto LAB_00567f1f;
  }
  if (DAT_009a7e6c != 3) {
    local_20 = 0;
    goto LAB_00568409;
  }
  DAT_02091d04 = 0xfffffb2e;
  thunk_FUN_00572158();
  puVar4 = (undefined4 *)&DAT_020b8ea0;
  puVar8 = (undefined4 *)&DAT_020b90a1;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar8 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar1 = FUN_005f4660();
  if (iVar1 == 0) {
    local_68[0] = 0;
    local_84 = 6;
    local_80 = "binary";
    local_7c = 7;
    local_78 = "unknown";
    local_74 = 2;
    local_18 = FUN_005f6540(local_68,5,0x784ff01,&DAT_0076a098);
    if (local_18 != 0) {
LAB_00568417:
      thunk_FUN_0042ac4e();
      local_34 = 0;
      goto LAB_0056842f;
    }
    local_14 = 20000;
    DAT_009a7e70 = 20000;
    bVar11 = true;
    do {
      bVar10 = false;
      iVar1 = 1;
      pbVar5 = (byte *)((int)&DAT_009a9498 + DAT_009a7e70 + 3);
      pbVar9 = &DAT_00769fa0;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar10 = *pbVar5 < *pbVar9;
        bVar11 = *pbVar5 == *pbVar9;
        pbVar5 = pbVar5 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar10 && !bVar11) {
        local_10 = 0;
        break;
      }
      DAT_009a7e70 = DAT_009a7e70 + -1;
      local_14 = local_14 + -1;
      bVar11 = local_14 == 0;
    } while (0 < local_14);
    local_84 = DAT_009a7e70;
    if (DAT_009a7e70 < 0) {
      local_84 = 0;
    }
    puVar6 = &stack0xffffff64;
    for (uVar2 = local_84 + 7U & 0xfffffff8; 0x1000 < (int)uVar2; uVar2 = uVar2 - 0x1000) {
      puVar6 = puVar6 + -0x1000;
    }
    local_80 = puVar6 + -uVar2;
    local_70 = 1;
    for (local_74 = 1; local_74 <= local_84; local_74 = local_74 + 1) {
      local_80[local_74 + -1] = *(char *)((int)&DAT_009a9498 + local_70 + 3);
      local_70 = local_70 + 1;
    }
    local_68[0] = 0;
    local_7c = 1;
    *(int **)(local_80 + -8) = &local_84;
    *(undefined **)(local_80 + -0xc) = &DAT_0076a094;
    local_80[-0xffffffff00000010] = '\x01';
    local_80[-0xffffffff0000000f] = -1;
    local_80[-0xffffffff0000000e] = -0x7c;
    local_80[-0xffffffff0000000d] = '\a';
    local_80[-0xffffffff00000014] = '\x05';
    local_80[-0xffffffff00000013] = '\0';
    local_80[-0xffffffff00000012] = '\0';
    local_80[-0xffffffff00000011] = '\0';
    *(undefined4 **)(local_80 + -0x18) = local_68;
    local_80[-0xffffffff0000001c] = -0xc;
    local_80[-0xffffffff0000001b] = -0x7d;
    local_80[-0xffffffff0000001a] = 'V';
    local_80[-0xffffffff00000019] = '\0';
    local_6c = local_80;
    local_c = FUN_005fa4d0();
  }
  else {
    local_1c = 0;
  }
LAB_00568409:
  _DAT_009a7e68 = DAT_009a7e64;
LAB_0056842f:
  local_68[0] = 0;
  FUN_005f7950(local_68,5,0x784ff00,&DAT_00769ee0);
  FUN_005f34d1();
  FUN_005f34d1();
  return;
}


