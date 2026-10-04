// FUN_00537f49 @ 00537f49 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00538194) */

void FUN_00537f49(void)

{
  undefined1 *puVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  bool bVar7;
  bool bVar8;
  undefined1 *puVar9;
  
  puVar9 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x537f6d);
  FUN_005f34d1(puVar9,0x537f88);
  *(undefined4 *)(puVar9 + -0x24) = 0x7e;
  DAT_0099a9a4 = 2;
  while ((&DAT_020b8e9f)[DAT_0099a9a4] != ' ') {
    *(undefined4 *)(puVar9 + -0x20) = 0;
    *(undefined4 *)(puVar9 + -4) = 0;
    DAT_0099a9a4 = DAT_0099a9a4 + 1;
    *(int *)(puVar9 + -0x24) = *(int *)(puVar9 + -0x24) + -1;
    if (*(int *)(puVar9 + -0x24) < 1) {
      return;
    }
  }
  DAT_0099a9a0 = DAT_0099a9a4 + 1;
  iVar2 = 0x80 - DAT_0099a9a0;
  *(int *)(puVar9 + -0x1c) = iVar2;
  do {
    if (iVar2 < 1) {
      **(int **)(puVar9 + 0x10) = **(int **)(puVar9 + 0x10) + 1;
      puVar4 = *(undefined4 **)(puVar9 + 8);
      puVar6 = (undefined4 *)(&DAT_01c4eec4 + **(int **)(puVar9 + 0x10) * 0x80);
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      thunk_FUN_00571b78(&DAT_01c4eec4 + **(int **)(puVar9 + 0x10) * 0x80,0x80,&DAT_00768a2c,3);
      *(undefined4 *)(puVar9 + -0x14) = 0;
      return;
    }
    bVar8 = iVar2 == 0;
    bVar7 = false;
    iVar2 = 1;
    pbVar3 = &DAT_020b8e9f + DAT_0099a9a0;
    pbVar5 = &DAT_00768a34;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *pbVar3 < *pbVar5;
      bVar8 = *pbVar3 == *pbVar5;
      pbVar3 = pbVar3 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar8);
    if (!bVar7) {
      iVar2 = 1;
      pbVar3 = &DAT_020b8e9f + DAT_0099a9a0;
      pbVar5 = &DAT_00768a30;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar7 = *pbVar3 < *pbVar5;
        bVar8 = *pbVar3 == *pbVar5;
        pbVar3 = pbVar3 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar8);
      if (bVar7 || bVar8) {
        *(undefined4 *)(puVar9 + -0x18) = 0;
        **(int **)(puVar9 + 0x10) = **(int **)(puVar9 + 0x10) + 1;
        FUN_005f46bc(puVar9,0x5380ae);
        FUN_005f34d1(puVar9,0x5380c4);
        thunk_FUN_00571b78(&DAT_01c4eec4 + **(int **)(puVar9 + 0x10) * 0x80,0x80,&DAT_00768a2c,3);
        bVar7 = false;
        bVar8 = true;
        DAT_0099a99c = 0;
        iVar2 = 1;
        pbVar3 = (byte *)((int)&DAT_020b8ea0 + DAT_0099a9a0);
        pbVar5 = &DAT_00768a34;
        break;
      }
    }
    DAT_0099a9a0 = DAT_0099a9a0 + 1;
    *(int *)(puVar9 + -0x1c) = *(int *)(puVar9 + -0x1c) + -1;
    iVar2 = *(int *)(puVar9 + -0x1c);
  } while( true );
  while( true ) {
    iVar2 = iVar2 + -1;
    bVar7 = *pbVar3 < *pbVar5;
    bVar8 = *pbVar3 == *pbVar5;
    pbVar3 = pbVar3 + 1;
    pbVar5 = pbVar5 + 1;
    if (!bVar8) break;
    if (iVar2 == 0) break;
  }
  if (!bVar7) {
    iVar2 = 1;
    pbVar3 = (byte *)((int)&DAT_020b8ea0 + DAT_0099a9a0);
    pbVar5 = &DAT_00768a30;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *pbVar3 < *pbVar5;
      bVar8 = *pbVar3 == *pbVar5;
      pbVar3 = pbVar3 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar8);
    if (bVar7 || bVar8) {
      DAT_0099a99c = 1;
    }
  }
  iVar2 = 1;
  pbVar3 = (byte *)((int)&DAT_020b8ea0 + DAT_0099a9a0 + 1);
  pbVar5 = &DAT_00768a34;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar7 = *pbVar3 < *pbVar5;
    bVar8 = *pbVar3 == *pbVar5;
    pbVar3 = pbVar3 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar8);
  if (!bVar7) {
    iVar2 = 1;
    pbVar3 = (byte *)((int)&DAT_020b8ea0 + DAT_0099a9a0 + 1);
    pbVar5 = &DAT_00768a30;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *pbVar3 < *pbVar5;
      bVar8 = *pbVar3 == *pbVar5;
      pbVar3 = pbVar3 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar8);
    if (bVar7 || bVar8) {
      DAT_0099a99c = 2;
    }
  }
  iVar2 = DAT_0099a99c + 1;
  puVar1 = &DAT_020b8e9f + DAT_0099a9a0;
  *(undefined4 *)(puVar9 + -0x44) = 0;
  *(int *)(puVar9 + -0x58) = iVar2;
  *(undefined1 **)(puVar9 + -0x54) = puVar1;
  *(int **)(puVar9 + -0x50) = &DAT_0099a998;
  FUN_005f9240(puVar9 + -0x44,0x784ff00,&DAT_00768a24,puVar9 + -0x58,&DAT_0079737c);
  iVar2 = DAT_0099a998 + -1;
  *(int *)(puVar9 + -0xc) = iVar2;
  DAT_0099a99c = 2;
  while (0 < iVar2) {
    **(int **)(puVar9 + 0x10) = **(int **)(puVar9 + 0x10) + 1;
    FUN_005f33c9(puVar9,0x538235);
    thunk_FUN_004cfb85(&DAT_01c4eec4 + **(int **)(puVar9 + 0x10) * 0x80,0x80);
    DAT_0099a99c = DAT_0099a99c + 1;
    *(int *)(puVar9 + -0xc) = *(int *)(puVar9 + -0xc) + -1;
    iVar2 = *(int *)(puVar9 + -0xc);
  }
  DAT_0099a998 = **(undefined4 **)(puVar9 + 0x10);
  *(undefined4 *)(puVar9 + -8) = 0;
  return;
}


