// FUN_004e8642 @ 004e8642 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004e8642(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  bool bVar9;
  
  puVar4 = &stack0xfffffffc;
  DAT_008d130c = ITEM_I;
  FUN_005f33c9(&stack0xfffffffc,0x4e8675);
  FUN_005f34d1(puVar4,0x4e8690);
  DAT_008d1308 = thunk_FUN_0059c6a0();
  puVar5 = &DAT_009ae2bc;
  puVar7 = (undefined4 *)&DAT_020b8ea0;
  for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  if (((((char)DAT_020b8ea0 == '\0') || (DAT_007a0b7c == '\0')) ||
      (iVar3 = FUN_005f4660(0x20), iVar3 != 0)) || (DAT_008d1308 == 2)) {
    *(undefined4 *)(puVar4 + -0x34) = 0;
  }
  else {
    puVar5 = (undefined4 *)&DAT_007a0b7c;
    puVar7 = &DAT_0078b610;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    *(undefined4 *)(puVar4 + -0x54) = 0;
    *(undefined4 *)(puVar4 + -0x68) = 0x80;
    *(undefined4 **)(puVar4 + -100) = &DAT_0078b610;
    *(int **)(puVar4 + -0x60) = &DAT_008d1310;
    FUN_005f47c0(puVar4 + -0x54,0xffffffff,0x784ff00,&DAT_007661d0,puVar4 + -0x68);
    if (DAT_008d1310 == 0) {
      *(undefined4 *)(puVar4 + -0x2c) = 0;
    }
    else {
      FUN_005f33c9(puVar4,0x4e8797);
      FUN_005f34d1(puVar4,0x4e87b2);
      ITEM_I = 1;
      iVar3 = thunk_FUN_00579410(&DAT_007661cc);
      if (iVar3 == 1) {
        *(undefined4 *)(puVar4 + -0x28) = 0;
        goto LAB_004e8a8a;
      }
      puVar5 = &DAT_009ae2bc;
      puVar7 = (undefined4 *)&DAT_020b8ea0;
      for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    DAT_008d1304 = 0x15;
    *(undefined4 *)(puVar4 + -0x54) = 0;
    *(undefined4 *)(puVar4 + -0x68) = 0x80;
    *(undefined4 **)(puVar4 + -100) = &DAT_0078b610;
    *(undefined4 *)(puVar4 + -0x60) = 2;
    *(undefined4 *)(puVar4 + -0x5c) = 4;
    FUN_005f6540(puVar4 + -0x54,0x15,0x784ff00,&DAT_007661bc,puVar4 + -0x68);
    if (DAT_008d1304 != 0x15) {
      *(undefined4 *)(puVar4 + -0x20) = 0;
      return;
    }
    DAT_008d1300 = 0;
    DAT_008d1304 = 1;
LAB_004e8877:
    bVar9 = 0xfffffffe < DAT_008d1300;
    iVar3 = 1;
    pbVar6 = (byte *)((int)&DAT_020b8ea0 + DAT_008d1300);
    pbVar8 = &DAT_007661b8;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar2 = *pbVar8;
      bVar1 = *pbVar6;
      bVar9 = bVar1 < bVar2;
      pbVar6 = pbVar6 + 1;
      pbVar8 = pbVar8 + 1;
    } while (bVar1 == bVar2);
    if (!bVar9) {
      *(undefined4 *)(puVar4 + -0x18) = 0;
      DAT_008d1300 = DAT_008d1300 + 1;
      goto LAB_004e8877;
    }
    *(undefined4 *)(puVar4 + -0x1c) = 0;
    *(undefined4 *)(puVar4 + -0x54) = 0;
    DAT_008d1300 = DAT_008d1300 + 1;
    FUN_005fc330(puVar4 + -0x54,0x15,0x784ff00,&DAT_007661b4,0,&DAT_00794b88);
    DAT_008d1308 = DAT_008d1304;
    for (iVar3 = DAT_008d1300 - DAT_008d1304; 0 < iVar3; iVar3 = iVar3 + -1) {
      *(undefined4 *)(puVar4 + -0x68) = 1;
      *(undefined1 **)(puVar4 + -100) = &DAT_020b8e9f + DAT_008d1308;
      *(undefined4 *)(puVar4 + -0x60) = 1;
      FUN_005fc980(puVar4 + -0x54,&DAT_007661b0,puVar4 + -0x68);
      DAT_008d1308 = DAT_008d1308 + 1;
    }
    FUN_005fc980(puVar4 + -0x54,&DAT_007661ac,0);
    if ((&DAT_020b8e9f)[DAT_008d1300] != '\0') {
      DAT_008d1304 = DAT_008d1300 + 2;
      *(undefined4 *)(puVar4 + -0xc) = 0;
      DAT_008d1300 = DAT_008d1300 + 1;
      goto LAB_004e8877;
    }
    *(undefined4 *)(puVar4 + -0x10) = 0;
    *(undefined4 *)(puVar4 + -0x54) = 0;
    FUN_005f7950(puVar4 + -0x54,0x15,0x784ff00,&DAT_007661a8,0);
    FUN_005f33c9(puVar4,0x4e8a04);
    FUN_005f34d1(puVar4,0x4e8a1f);
    *(undefined4 *)(puVar4 + -0x54) = 0;
    *(undefined4 *)(puVar4 + -0x68) = 0x19;
    *(undefined4 *)(puVar4 + -100) = 0x20b8ead;
    *(undefined4 *)(puVar4 + -0x60) = 0x18;
    *(undefined4 **)(puVar4 + -0x5c) = &DAT_0078b610;
    FUN_005f34f0(puVar4 + -0x54,0x784ff00,&DAT_00766178,puVar4 + -0x68,&DAT_00794b9c);
    thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
  }
LAB_004e8a8a:
  FUN_005f34d1(puVar4,0x4e8aa7);
  FUN_005f34d1(puVar4,0x4e8ac8);
  ITEM_I = DAT_008d130c;
  return;
}


