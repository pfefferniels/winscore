// FUN_004e8adf @ 004e8adf (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004e8ce8) */
/* WARNING: Removing unreachable block (ram,0x004e8ca9) */
/* WARNING: Removing unreachable block (ram,0x004e8d72) */
/* WARNING: Removing unreachable block (ram,0x004e8d8f) */
/* WARNING: Removing unreachable block (ram,0x004e8de7) */

void FUN_004e8adf(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar3 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x4e8b05);
  FUN_005f46bc(puVar3,0x4e8b36);
  FUN_005f34d1(puVar3,0x4e8b4c);
  FUN_005f46bc(puVar3,0x4e8b86);
  FUN_005f34d1(puVar3,0x4e8b9c);
  *(undefined4 *)(puVar3 + -0x54) = 0;
  *(undefined4 *)(puVar3 + -0x70) = 0x80;
  *(undefined2 **)(puVar3 + -0x6c) = &DAT_020b8ea0;
  *(undefined4 *)(puVar3 + -0x68) = 3;
  *(undefined **)(puVar3 + -100) = &DAT_00766220;
  *(undefined4 *)(puVar3 + -0x60) = 2;
  uVar1 = FUN_005f6540(puVar3 + -0x54,9,0x784ff01,&DAT_00766210,puVar3 + -0x70);
  *(undefined4 *)(puVar3 + -0x34) = uVar1;
  if (*(int *)(puVar3 + -0x34) == 0) {
    DAT_008d1324 = 1;
    FUN_005f34d1(puVar3,0x4e8c2d);
    while( true ) {
      *(undefined4 *)(puVar3 + -0x54) = 0;
      *(undefined4 *)(puVar3 + -0x60) = 0x18;
      *(undefined4 **)(puVar3 + -0x5c) = &DAT_008d1328;
      uVar1 = FUN_005fdbd0(puVar3 + -0x54,9,0x784ff01,&DAT_0076620c,puVar3 + -0x60,&DAT_00794bb0);
      *(undefined4 *)(puVar3 + -0x30) = uVar1;
      if (*(int *)(puVar3 + -0x30) != 0) break;
      *(undefined4 *)(puVar3 + -0x2c) = 0x14;
      DAT_008d1320 = 2;
      do {
        iVar2 = FUN_005f4660(0x20);
        if (iVar2 != 0) {
          *(undefined4 *)(puVar3 + -0x28) = 0;
          goto LAB_004e8e56;
        }
        iVar2 = FUN_005f4660(0x20);
        if (iVar2 != 0) {
          *(undefined4 *)(puVar3 + -0x24) = 0;
          break;
        }
        DAT_008d1320 = DAT_008d1320 + 1;
        *(int *)(puVar3 + -0x2c) = *(int *)(puVar3 + -0x2c) + -1;
      } while (0 < *(int *)(puVar3 + -0x2c));
      *(undefined4 *)(puVar3 + -0x20) = 0x10;
      DAT_008d131c = 9;
      do {
        *(undefined4 *)(puVar3 + -0x58) = 1;
        *(undefined4 *)(puVar3 + -0x5c) = 1;
        FUN_005f46bc(puVar3,0x4e8db7);
        FUN_005f34d1(puVar3,0x4e8dcd);
        FUN_005f46bc(puVar3,0x4e8e0b);
        FUN_005f34d1(puVar3,0x4e8e21);
        DAT_008d1320 = DAT_008d1320 + 1;
        DAT_008d131c = DAT_008d131c + 1;
        *(int *)(puVar3 + -0x20) = *(int *)(puVar3 + -0x20) + -1;
      } while (0 < *(int *)(puVar3 + -0x20));
LAB_004e8e56:
      puVar4 = &DAT_008d1328;
      puVar5 = (undefined4 *)(&DAT_009bead8 + DAT_008d1324 * 0x18);
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      DAT_008d1324 = DAT_008d1324 + 1;
      if (1000 < DAT_008d1324) break;
      *(undefined4 *)(puVar3 + -0x1c) = 0;
    }
    *(undefined4 *)(puVar3 + -0x54) = 0;
    FUN_005f7950(puVar3 + -0x54,9,0x784ff00,&DAT_007661a8,0);
    if (**(int **)(puVar3 + 8) == 0) {
      *(undefined4 *)(puVar3 + -0x14) = 0;
    }
    else if (**(int **)(puVar3 + 8) == -1) {
      DAT_008d1318 = thunk_FUN_0059d170(**(undefined4 **)(puVar3 + 8));
      if (DAT_008d1318 == 2) {
        *(undefined4 *)(puVar3 + -0x10) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0xc) = 0;
      }
    }
    else {
      if (**(int **)(puVar3 + 8) == -99) {
        **(int **)(puVar3 + 8) = DAT_008d1314 + -1;
      }
      if (**(int **)(puVar3 + 8) == -0x62) {
        **(int **)(puVar3 + 8) = DAT_008d1314 + 1;
      }
      if (DAT_008d1324 <= **(int **)(puVar3 + 8)) {
        **(undefined4 **)(puVar3 + 8) = 1;
      }
      if (**(int **)(puVar3 + 8) < 1) {
        **(int **)(puVar3 + 8) = DAT_008d1324 + -1;
      }
      FUN_005f34d1(puVar3,0x4e8f8e);
      DAT_020b90a0 = DAT_00766204;
      puVar4 = (undefined4 *)(&DAT_009bead8 + **(int **)(puVar3 + 8) * 0x18);
      puVar5 = (undefined4 *)&DAT_020b90a2;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      DAT_008d1314 = **(int **)(puVar3 + 8);
      cmd_get();
      *(undefined4 *)(puVar3 + -8) = 0;
    }
  }
  else {
    thunk_FUN_0054d831("#MUSDIR#.TMP not found.",0x18);
    *(undefined4 *)(puVar3 + -0x54) = 0;
    FUN_005f7950(puVar3 + -0x54,9,0x784ff00,&DAT_007661a8,0);
  }
  return;
}


