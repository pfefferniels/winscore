// FUN_004c54f6 @ 004c54f6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


int FUN_004c54f6(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  int local_c;
  
  bVar5 = &stack0xfffffffc < (undefined1 *)0x2c;
  bVar6 = &stack0x00000000 == (undefined1 *)0x30;
  local_c = 0;
  iVar1 = 1;
  pbVar2 = param_1;
  pbVar4 = &DAT_00764de4;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pbVar2 < *pbVar4;
    bVar6 = *pbVar2 == *pbVar4;
    pbVar2 = pbVar2 + 1;
    pbVar4 = pbVar4 + 1;
  } while (bVar6);
  if (!bVar5 && !bVar6) {
    iVar1 = 1;
    pbVar2 = param_1;
    pbVar4 = &DAT_00764de0;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pbVar2 < *pbVar4;
      bVar6 = *pbVar2 == *pbVar4;
      pbVar2 = pbVar2 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar6);
    if (bVar5 || bVar6) {
      bVar5 = *param_1 < 0x30;
      local_c = *param_1 - 0x30;
      bVar6 = local_c == 0;
    }
  }
  iVar1 = 1;
  pbVar4 = &DAT_00764de4;
  pbVar2 = param_1;
  do {
    pbVar2 = pbVar2 + 1;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pbVar2 < *pbVar4;
    bVar6 = *pbVar2 == *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar6);
  if (!bVar5) {
    iVar1 = 1;
    pbVar4 = &DAT_00764de0;
    pbVar2 = param_1;
    do {
      pbVar2 = pbVar2 + 1;
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pbVar2 < *pbVar4;
      bVar6 = *pbVar2 == *pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (bVar6);
    if (bVar5 || bVar6) {
      uVar3 = local_c * 10 + (uint)param_1[1];
      bVar5 = uVar3 < 0x30;
      local_c = uVar3 - 0x30;
      bVar6 = local_c == 0;
      iVar1 = 1;
      pbVar2 = param_1 + 2;
      pbVar4 = &DAT_00764de4;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pbVar2 < *pbVar4;
        bVar6 = *pbVar2 == *pbVar4;
        pbVar2 = pbVar2 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar6);
      if (!bVar5) {
        iVar1 = 1;
        pbVar2 = param_1 + 2;
        pbVar4 = &DAT_00764de0;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pbVar2 < *pbVar4;
          bVar6 = *pbVar2 == *pbVar4;
          pbVar2 = pbVar2 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar6);
        if (bVar5 || bVar6) {
          local_c = local_c * 10 + (uint)param_1[2] + -0x30;
        }
      }
    }
  }
  return local_c;
}


