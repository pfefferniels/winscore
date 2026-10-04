// FUN_00526451 @ 00526451 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00526451(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  
  puVar4 = &stack0xfffffffc;
  if ((((char)DAT_020b8ea0 == 'L') || ((char)DAT_020b8ea0 == 'X')) ||
     (puVar1 = &stack0xfffffffc, (char)DAT_020b8ea0 == ';')) {
    pcVar6 = "input.tmp               File exists - write over file? (Y/N) >";
    puVar5 = &DAT_0094ea98;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      puVar5 = puVar5 + 1;
    }
  }
  else {
    while( true ) {
      puVar4 = puVar1;
      thunk_FUN_0054ebeb();
      puVar5 = (undefined4 *)&DAT_020b8ea0;
      puVar7 = &DAT_0094ea98;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      iVar3 = FUN_00601a30(0x20);
      if (iVar3 != 0) {
        *(undefined4 *)(puVar4 + -0x54) = 0;
        return;
      }
      if (((char)DAT_020b8ea0 == '!') || ((char)DAT_020b8ea0 == '^')) {
        *(undefined4 *)(puVar4 + -0x50) = 0;
        return;
      }
      *(undefined4 *)(puVar4 + -0x7c) = 0;
      *(undefined4 *)(puVar4 + -0x90) = 0x18;
      *(undefined4 **)(puVar4 + -0x8c) = &DAT_0094ea98;
      *(uint **)(puVar4 + -0x88) = &DAT_0094ea94;
      FUN_005f47c0(puVar4 + -0x7c,0xffffffff,0x784ff00,&DAT_00767ebc,puVar4 + -0x90);
      if ((DAT_0094ea94 & 1) == 0) {
        *(undefined4 *)(puVar4 + -0x48) = 0;
        goto LAB_00526613;
      }
      FUN_005f33c9(puVar4,0x526583);
      FUN_005f34d1(puVar4,0x52659e);
      DAT_0094ea88 = thunk_FUN_00595cd0(&DAT_020b8ea0);
      if (DAT_0094ea88 != 0) break;
      *(undefined4 *)(puVar4 + -0x40) = 0;
      puVar1 = puVar4;
    }
    *(undefined4 *)(puVar4 + -0x44) = 0;
  }
LAB_00526613:
  *(undefined4 *)(puVar4 + -0x7c) = 0;
  *(undefined4 *)(puVar4 + -0x90) = 0x18;
  *(undefined4 **)(puVar4 + -0x8c) = &DAT_0094ea98;
  *(undefined4 *)(puVar4 + -0x88) = 2;
  *(undefined4 *)(puVar4 + -0x84) = 4;
  uVar2 = FUN_005f6540(puVar4 + -0x7c,0x16,0x784ff01,&DAT_00767e6c,puVar4 + -0x90);
  *(undefined4 *)(puVar4 + -0x3c) = uVar2;
  if (*(int *)(puVar4 + -0x3c) == 0) {
    DAT_01a1f484._0_2_ = DAT_00767e68;
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x88) = 0x40;
    *(undefined4 **)(puVar4 + -0x84) = &DAT_01a1f484;
    FUN_005fc330(puVar4 + -0x7c,0x16,0x784ff00,&DAT_00767e64,puVar4 + -0x88,&DAT_00796c78);
    iVar3 = FUN_005f4660(0x20);
    if (iVar3 != 0) {
      _DAT_01a1f4c4 = i_808591410;
      DAT_01a1f4c8 = i_538976304;
      DAT_01a1f4cc = i_538976288;
      DAT_01a1f4d0 = i_538976288;
    }
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x88) = 0x10;
    *(undefined1 **)(puVar4 + -0x84) = &DAT_01a1f4c4;
    FUN_005fc330(puVar4 + -0x7c,0x16,0x784ff00,&DAT_00767e64,puVar4 + -0x88,&DAT_00796c8c);
    thunk_FUN_0054cb15(&DAT_01a1f4d4,1,&DAT_0094ea88,&DAT_00767e50);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x90) = 3;
    *(undefined4 *)(puVar4 + -0x8c) = 0x796d31;
    *(int **)(puVar4 + -0x88) = &DAT_0094ea88;
    FUN_005f34f0(puVar4 + -0x7c,0x784ff00,&DAT_00767e1c,puVar4 + -0x90,&DAT_00796ca0);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x98) = DAT_00796d30;
    *(undefined2 *)(puVar4 + -0x94) = DAT_00796d34;
    puVar4[-0x92] = DAT_00796d36;
    *(undefined1 **)(puVar4 + -0x88) = puVar4 + -0x98;
    *(undefined4 *)(puVar4 + -0x90) = 7;
    FUN_005fc330(puVar4 + -0x7c,0x16,0x784ff08,&DAT_00767e4c,0,puVar4 + -0x90);
    *(int *)(puVar4 + -0x80) = DAT_0094ea88;
    DAT_0094ea84 = 1;
    iVar3 = DAT_0094ea88;
    while (0 < iVar3) {
      *(undefined4 *)(puVar4 + -0x90) = 1;
      *(int *)(puVar4 + -0x8c) = DAT_0094ea84 + 0x1a1f4d3;
      *(undefined4 *)(puVar4 + -0x88) = 1;
      FUN_005fc980(puVar4 + -0x7c,&DAT_00767e48,puVar4 + -0x90);
      DAT_0094ea84 = DAT_0094ea84 + 1;
      *(int *)(puVar4 + -0x80) = *(int *)(puVar4 + -0x80) + -1;
      iVar3 = *(int *)(puVar4 + -0x80);
    }
    FUN_005fc980(puVar4 + -0x7c,&DAT_00767e44,0);
    thunk_FUN_0054cb15(&DAT_01a1f654,1,&DAT_0094ea88,&DAT_00767e50);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x90) = 3;
    *(undefined4 *)(puVar4 + -0x8c) = 0x796d31;
    *(int **)(puVar4 + -0x88) = &DAT_0094ea88;
    FUN_005f34f0(puVar4 + -0x7c,0x784ff00,&DAT_00767e1c,puVar4 + -0x90,&DAT_00796cb4);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x98) = DAT_00796d30;
    *(undefined2 *)(puVar4 + -0x94) = DAT_00796d34;
    puVar4[-0x92] = DAT_00796d36;
    *(undefined1 **)(puVar4 + -0x88) = puVar4 + -0x98;
    *(undefined4 *)(puVar4 + -0x90) = 7;
    FUN_005fc330(puVar4 + -0x7c,0x16,0x784ff08,&DAT_00767e4c,0,puVar4 + -0x90);
    *(int *)(puVar4 + -0x80) = DAT_0094ea88;
    DAT_0094ea84 = 1;
    iVar3 = DAT_0094ea88;
    while (0 < iVar3) {
      *(undefined4 *)(puVar4 + -0x90) = 1;
      *(undefined **)(puVar4 + -0x8c) = &DAT_01a1f653 + DAT_0094ea84;
      *(undefined4 *)(puVar4 + -0x88) = 1;
      FUN_005fc980(puVar4 + -0x7c,&DAT_00767e48,puVar4 + -0x90);
      DAT_0094ea84 = DAT_0094ea84 + 1;
      *(int *)(puVar4 + -0x80) = *(int *)(puVar4 + -0x80) + -1;
      iVar3 = *(int *)(puVar4 + -0x80);
    }
    FUN_005fc980(puVar4 + -0x7c,&DAT_00767e44,0);
    thunk_FUN_0054cb15(&DAT_01a1f7d4,1,&DAT_0094ea88,&DAT_00767e50);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x90) = 3;
    *(undefined4 *)(puVar4 + -0x8c) = 0x796d31;
    *(int **)(puVar4 + -0x88) = &DAT_0094ea88;
    FUN_005f34f0(puVar4 + -0x7c,0x784ff00,&DAT_00767e1c,puVar4 + -0x90,&DAT_00796cc8);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x98) = DAT_00796d30;
    *(undefined2 *)(puVar4 + -0x94) = DAT_00796d34;
    puVar4[-0x92] = DAT_00796d36;
    *(undefined1 **)(puVar4 + -0x88) = puVar4 + -0x98;
    *(undefined4 *)(puVar4 + -0x90) = 7;
    FUN_005fc330(puVar4 + -0x7c,0x16,0x784ff08,&DAT_00767e4c,0,puVar4 + -0x90);
    *(int *)(puVar4 + -0x80) = DAT_0094ea88;
    DAT_0094ea84 = 1;
    iVar3 = DAT_0094ea88;
    while (0 < iVar3) {
      *(undefined4 *)(puVar4 + -0x90) = 1;
      *(undefined **)(puVar4 + -0x8c) = &DAT_01a1f7d3 + DAT_0094ea84;
      *(undefined4 *)(puVar4 + -0x88) = 1;
      FUN_005fc980(puVar4 + -0x7c,&DAT_00767e48,puVar4 + -0x90);
      DAT_0094ea84 = DAT_0094ea84 + 1;
      *(int *)(puVar4 + -0x80) = *(int *)(puVar4 + -0x80) + -1;
      iVar3 = *(int *)(puVar4 + -0x80);
    }
    FUN_005fc980(puVar4 + -0x7c,&DAT_00767e44,0);
    thunk_FUN_0054cb15(&DAT_01a1f954,1,&DAT_0094ea88,&DAT_00767e50);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x90) = 3;
    *(undefined4 *)(puVar4 + -0x8c) = 0x796d31;
    *(int **)(puVar4 + -0x88) = &DAT_0094ea88;
    FUN_005f34f0(puVar4 + -0x7c,0x784ff00,&DAT_00767e1c,puVar4 + -0x90,&DAT_00796cdc);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x98) = DAT_00796d30;
    *(undefined2 *)(puVar4 + -0x94) = DAT_00796d34;
    puVar4[-0x92] = DAT_00796d36;
    *(undefined1 **)(puVar4 + -0x88) = puVar4 + -0x98;
    *(undefined4 *)(puVar4 + -0x90) = 7;
    FUN_005fc330(puVar4 + -0x7c,0x16,0x784ff08,&DAT_00767e4c,0,puVar4 + -0x90);
    *(int *)(puVar4 + -0x80) = DAT_0094ea88;
    DAT_0094ea84 = 1;
    iVar3 = DAT_0094ea88;
    while (0 < iVar3) {
      *(undefined4 *)(puVar4 + -0x90) = 1;
      *(int *)(puVar4 + -0x8c) = DAT_0094ea84 + 0x1a1f953;
      *(undefined4 *)(puVar4 + -0x88) = 1;
      FUN_005fc980(puVar4 + -0x7c,&DAT_00767e48,puVar4 + -0x90);
      DAT_0094ea84 = DAT_0094ea84 + 1;
      *(int *)(puVar4 + -0x80) = *(int *)(puVar4 + -0x80) + -1;
      iVar3 = *(int *)(puVar4 + -0x80);
    }
    FUN_005fc980(puVar4 + -0x7c,&DAT_00767e44,0);
    thunk_FUN_0054cb15(&DAT_01a1fad4,1,&DAT_0094ea88,&DAT_00767e50);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x90) = 3;
    *(undefined4 *)(puVar4 + -0x8c) = 0x796d31;
    *(int **)(puVar4 + -0x88) = &DAT_0094ea88;
    FUN_005f34f0(puVar4 + -0x7c,0x784ff00,&DAT_00767e1c,puVar4 + -0x90,&DAT_00796cf0);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    *(undefined4 *)(puVar4 + -0x98) = DAT_00796d30;
    *(undefined2 *)(puVar4 + -0x94) = DAT_00796d34;
    puVar4[-0x92] = DAT_00796d36;
    *(undefined1 **)(puVar4 + -0x88) = puVar4 + -0x98;
    *(undefined4 *)(puVar4 + -0x90) = 7;
    FUN_005fc330(puVar4 + -0x7c,0x16,0x784ff08,&DAT_00767e4c,0,puVar4 + -0x90);
    *(int *)(puVar4 + -0x80) = DAT_0094ea88;
    DAT_0094ea84 = 1;
    iVar3 = DAT_0094ea88;
    while (0 < iVar3) {
      *(undefined4 *)(puVar4 + -0x90) = 1;
      *(int *)(puVar4 + -0x8c) = DAT_0094ea84 + 0x1a1fad3;
      *(undefined4 *)(puVar4 + -0x88) = 1;
      FUN_005fc980(puVar4 + -0x7c,&DAT_00767e48,puVar4 + -0x90);
      DAT_0094ea84 = DAT_0094ea84 + 1;
      *(int *)(puVar4 + -0x80) = *(int *)(puVar4 + -0x80) + -1;
      iVar3 = *(int *)(puVar4 + -0x80);
    }
    FUN_005fc980(puVar4 + -0x7c,&DAT_00767e44,0);
    *(undefined4 *)(puVar4 + -0x7c) = 0;
    FUN_005f7950(puVar4 + -0x7c,0x16,0x784ff00,&DAT_00767e40,0);
    *(undefined4 *)(puVar4 + -4) = 0;
  }
  else {
    thunk_FUN_0054d831("Error writing file",0x12);
  }
  return;
}


