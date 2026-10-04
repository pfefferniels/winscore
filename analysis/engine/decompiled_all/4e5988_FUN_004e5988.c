// FUN_004e5988 @ 004e5988 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e5988(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  undefined *puStack_88;
  undefined4 local_74;
  undefined *local_70;
  undefined4 local_6c;
  char *local_68;
  undefined4 local_64;
  undefined4 local_5c [10];
  undefined4 local_34;
  
  puVar5 = &stack0xfffffffc;
  local_5c[0] = 0;
  local_74 = 0x10;
  local_70 = &DAT_00765fa4;
  local_6c = 7;
  local_68 = "unknown";
  local_64 = 2;
  FUN_005f6540(local_5c,0xe,0x784ff00,&DAT_00765f8c,&local_74);
  local_5c[0] = 0;
  puStack_88 = &DAT_00794a6c;
  FUN_005fc330(local_5c,0xe,0x784ff00,&DAT_00765f88,0);
  local_34 = 5;
  DAT_008d0a48 = 1;
  do {
    DAT_008d0a30 = DAT_00765f84;
    _DAT_008d0a44 = 1;
    DAT_008d0a40 = 0;
LAB_004e5a47:
    puStack_88 = (undefined *)0x4e5a6c;
    FUN_005f33c9();
    puStack_88 = (undefined *)0x4e5a88;
    FUN_005f33c9();
    puStack_88 = (undefined *)0x4e5aa4;
    FUN_005f33c9();
    puStack_88 = (undefined *)0x4e5ac5;
    FUN_005f34d1();
    *(undefined4 *)(puVar5 + -0x58) = 0;
    *(undefined4 *)(puVar5 + -0x70) = 0xd;
    *(undefined **)(puVar5 + -0x6c) = &DAT_008d0a4c;
    *(undefined4 *)(puVar5 + -0x68) = 3;
    *(undefined **)(puVar5 + -100) = &DAT_00765f74;
    *(undefined4 *)(puVar5 + -0x60) = 2;
    uVar3 = FUN_005f6540(puVar5 + -0x58,0xd,0x784ff01,&DAT_00765f8c,puVar5 + -0x70);
    *(undefined4 *)(puVar5 + -0x2c) = uVar3;
    if (*(int *)(puVar5 + -0x2c) != 0) {
LAB_004e5da4:
      bVar8 = 0xfffffffe < (uint)(int)DAT_008d0a30;
      iVar4 = (int)DAT_008d0a30 + 1;
      bVar9 = iVar4 == 0;
      DAT_008d0a30 = (char)iVar4;
      iVar4 = 1;
      pbVar6 = (byte *)&DAT_008d0a30;
      pbVar7 = &DAT_00765f54;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pbVar6 < *pbVar7;
        bVar9 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar8 && !bVar9) goto LAB_004e5de0;
      *(undefined4 *)(puVar5 + -0x10) = 0;
      goto LAB_004e5a47;
    }
    *(undefined4 *)(puVar5 + -0x58) = 0;
    *(undefined4 *)(puVar5 + -0x60) = 0x100;
    *(undefined **)(puVar5 + -0x5c) = &DAT_008d0a60;
    puStack_88 = &DAT_00794a88;
    uVar3 = FUN_005fdbd0(puVar5 + -0x58,0xd,0x784ff01,&DAT_00765f70,puVar5 + -0x60);
    *(undefined4 *)(puVar5 + -0x28) = uVar3;
    if (*(int *)(puVar5 + -0x28) != 0) goto LAB_004e5da4;
    thunk_FUN_0054c83c(&DAT_008d0a60,0x100,&DAT_00765f6c);
    bVar8 = (undefined1 *)0xfffffffb < &puStack_88;
    *(undefined4 *)(puVar5 + -0x24) = 0x100;
    DAT_008d0a3c = 0x100;
    puVar2 = &stack0xffffff7c;
    do {
      bVar9 = puVar2 == (undefined1 *)0x0;
      iVar4 = 1;
      pbVar6 = (byte *)(DAT_008d0a3c + 0x8d0a5f);
      pbVar7 = &DAT_00765f68;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pbVar6 < *pbVar7;
        bVar9 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar8 && !bVar9) {
        *(undefined4 *)(puVar5 + -0x20) = 0;
        break;
      }
      DAT_008d0a3c = DAT_008d0a3c + -1;
      *(int *)(puVar5 + -0x24) = *(int *)(puVar5 + -0x24) + -1;
      puVar2 = *(undefined1 **)(puVar5 + -0x24);
      bVar8 = false;
    } while (0 < (int)puVar2);
    puVar1 = &DAT_008d0a60 + DAT_008d0a3c;
    DAT_008d0a3c = DAT_008d0a3c + 1;
    *puVar1 = 0x20;
    if ((DAT_01fbb700 < 3) || (DAT_008d0a48 == DAT_01fbb700)) {
      if (DAT_008d0a40 == 0) {
        *(undefined4 *)(puVar5 + -0x58) = 0;
        *(undefined4 *)(puVar5 + -0x68) = 6;
        *(int *)(puVar5 + -100) = DAT_008d0a48 * 6 + 0x794aea;
        *(undefined4 *)(puVar5 + -0x60) = 6;
        puStack_88 = &DAT_00794a58;
        FUN_005fc330(puVar5 + -0x58,0xe,0x784ff00,&DAT_00765f64,puVar5 + -0x68);
      }
      DAT_008d0a40 = 1;
      *(undefined4 *)(puVar5 + -0x58) = 0;
      *(undefined4 *)(puVar5 + -0x60) = 1;
      *(char **)(puVar5 + -0x5c) = &DAT_008d0a30;
      puStack_88 = &DAT_00794a18;
      FUN_005fc330(puVar5 + -0x58,0xe,0x784ff00,&DAT_00765f60,puVar5 + -0x60);
      *(undefined4 *)(puVar5 + -0x68) = 4;
      *(char **)(puVar5 + -100) = s_NOTES_RHYTHMMARKS_BEAMS_SLURS_00794af0 + DAT_008d0a48 * 4 + 0x1c
      ;
      *(undefined4 *)(puVar5 + -0x60) = 4;
      FUN_005fc980(puVar5 + -0x58,&DAT_00765f5c,puVar5 + -0x68);
      FUN_005fc980(puVar5 + -0x58,&DAT_00765f58,0);
      DAT_008d0a38 = 1;
      for (iVar4 = DAT_008d0a3c; 0 < iVar4; iVar4 = iVar4 + -1) {
        *(undefined4 *)(puVar5 + -0x68) = 1;
        *(int *)(puVar5 + -100) = DAT_008d0a38 + 0x8d0a5f;
        *(undefined4 *)(puVar5 + -0x60) = 1;
        FUN_005fc980(puVar5 + -0x58,&DAT_00765f5c,puVar5 + -0x68);
        DAT_008d0a38 = DAT_008d0a38 + 1;
      }
      FUN_005fc980(puVar5 + -0x58,&DAT_00765f88,0);
      goto LAB_004e5da4;
    }
    *(undefined4 *)(puVar5 + -0x1c) = 0;
LAB_004e5de0:
    *(undefined4 *)(puVar5 + -0xc) = 0;
    DAT_008d0a48 = DAT_008d0a48 + 1;
    *(int *)(puVar5 + -0x30) = *(int *)(puVar5 + -0x30) + -1;
    if (*(int *)(puVar5 + -0x30) < 1) {
      *(undefined4 *)(puVar5 + -0x58) = 0;
      FUN_005f7950(puVar5 + -0x58,0xd,0x784ff00,&DAT_00765f50,0);
      *(undefined4 *)(puVar5 + -0x58) = 0;
      FUN_005f7950(puVar5 + -0x58,0xe,0x784ff00,&DAT_00765f50,0);
      puStack_88 = (undefined *)0x4e5e7b;
      FUN_005f33c9(puVar5);
      puStack_88 = (undefined *)0x4e5e96;
      FUN_005f34d1(puVar5);
      puStack_88 = (undefined *)0x4e5e9f;
      thunk_FUN_00567e5b();
      return;
    }
  } while( true );
}


