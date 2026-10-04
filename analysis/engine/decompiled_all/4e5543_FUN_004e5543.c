// FUN_004e5543 @ 004e5543 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e5543(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  
  puVar2 = &stack0xfffffffc;
  _DAT_008d09ec = *param_3;
  for (iVar4 = 1; iVar4 < 0x33; iVar4 = iVar4 + 1) {
    *(undefined4 *)(&IP0 + iVar4 * 4) = 0;
  }
  iVar4 = *param_3;
  *param_4 = 1;
  do {
    if (iVar4 < 1) {
LAB_004e56b5:
      iVar4 = **(int **)(puVar2 + 0x14);
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      *(undefined4 *)(puVar2 + -0x30) = 0;
      *(int *)(puVar2 + -0x40) = iVar4;
      *(undefined4 *)(puVar2 + -0x3c) = *(undefined4 *)(puVar2 + 8);
      *(undefined4 *)(puVar2 + -0x38) = 200;
      *(int **)(puVar2 + -0x34) = &IP1;
      uVar1 = FUN_006050d0(puVar2 + -0x30,0x784ff02,&DAT_00765f2c,puVar2 + -0x40);
      *(undefined4 *)(puVar2 + -8) = uVar1;
      return;
    }
    FUN_005f46bc(puVar2,0x4e55cf);
    FUN_005f34d1(puVar2,0x4e55e5);
    if ((DAT_008d09e8 == 0x3b) || (bVar6 = DAT_008d09e8 < 0x2f, DAT_008d09e8 == 0x2f)) {
      *(undefined4 *)(puVar2 + -0xc) = 0;
      goto LAB_004e56b5;
    }
    iVar4 = 1;
    bVar7 = false;
    pbVar3 = &DAT_008d09e8;
    pbVar5 = &DAT_00765f20;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar6 = *pbVar3 < *pbVar5;
      bVar7 = *pbVar3 == *pbVar5;
      pbVar3 = pbVar3 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar7);
    if (bVar6) {
LAB_004e5653:
      FUN_005f46bc(puVar2,0x4e5672);
      FUN_005f34d1(puVar2,0x4e5688);
    }
    else {
      iVar4 = 1;
      bVar6 = false;
      pbVar3 = &DAT_008d09e8;
      pbVar5 = &DAT_00765f1c;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar6 = *pbVar3 < *pbVar5;
        bVar7 = *pbVar3 == *pbVar5;
        pbVar3 = pbVar3 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (!bVar6 && !bVar7) goto LAB_004e5653;
    }
    **(int **)(puVar2 + 0x14) = **(int **)(puVar2 + 0x14) + 1;
    *(int *)(puVar2 + -0x10) = *(int *)(puVar2 + -0x10) + -1;
    iVar4 = *(int *)(puVar2 + -0x10);
  } while( true );
}


