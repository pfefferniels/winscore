// FUN_004b362c @ 004b362c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004b37b7) */
/* WARNING: Removing unreachable block (ram,0x004b3778) */
/* WARNING: Removing unreachable block (ram,0x004b382c) */

void FUN_004b362c(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  puVar5 = &stack0xfffffffc;
  if ((&DAT_020b8e9f)[*param_1] == 'P') {
    *param_1 = *param_1 + 1;
  }
  DAT_0089f36c = *param_1;
  do {
    DAT_0089f370 = *(byte *)((int)&DAT_020b8ea0 + *param_1);
    if (DAT_0089f370 == 0x44) {
      return;
    }
    bVar8 = DAT_0089f370 < 0x2e;
    if (DAT_0089f370 != 0x2e) {
      iVar4 = 1;
      pbVar6 = &DAT_0089f370;
      pbVar7 = &DAT_007645dc;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar2 = *pbVar7;
        bVar1 = *pbVar6;
        bVar8 = bVar1 < bVar2;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar1 == bVar2);
      bVar8 = !bVar8;
      bVar10 = !bVar8;
      iVar4 = 1;
      pbVar6 = &DAT_0089f370;
      pbVar7 = &DAT_007645d8;
      bVar9 = bVar8;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pbVar6 < *pbVar7;
        bVar10 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar10);
      if (!bVar9 && !bVar10 || !bVar8) {
        FUN_005f46bc(&stack0xfffffffc,0x4b3736);
        FUN_005f34d1(puVar5,0x4b374c);
        *(undefined4 *)(puVar5 + -0x14) = 9;
        DAT_0089f368 = 1;
        break;
      }
    }
    *param_1 = *param_1 + 1;
  } while( true );
LAB_004b3762:
  iVar4 = FUN_005f4660(0x20);
  if (iVar4 != 0) {
    *(undefined4 *)(puVar5 + -0x10) = 0;
    goto LAB_004b386a;
  }
  iVar4 = FUN_005f4660(0x20);
  if (iVar4 != 0) {
    *(undefined4 *)(puVar5 + -0xc) = 0;
    goto LAB_004b3814;
  }
  DAT_0089f368 = DAT_0089f368 + 1;
  *(int *)(puVar5 + -0x14) = *(int *)(puVar5 + -0x14) + -1;
  if (*(int *)(puVar5 + -0x14) < 1) {
LAB_004b3814:
    FUN_005f46bc(puVar5,0x4b3850);
    FUN_005f34d1(puVar5,0x4b3866);
LAB_004b386a:
    *(undefined4 *)(puVar5 + -0x3c) = 0;
    *(undefined4 *)(puVar5 + -0x50) = 9;
    *(undefined **)(puVar5 + -0x4c) = &DAT_0089f374;
    *(undefined4 *)(puVar5 + -0x48) = *(undefined4 *)(puVar5 + 0xc);
    uVar3 = FUN_005f9240(puVar5 + -0x3c,0x784ff01,&DAT_007645cc,puVar5 + -0x50,&DAT_00792490);
    *(undefined4 *)(puVar5 + -8) = uVar3;
    if (*(int *)(puVar5 + -8) == 0) {
      if ((&DAT_020b8e9e)[DAT_0089f36c] == 'P') {
        **(float **)(puVar5 + 0xc) = **(float **)(puVar5 + 0xc) + f_1000000;
      }
      **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + 1;
      *(undefined4 *)(puVar5 + -4) = 0;
    }
    else {
      **(undefined4 **)(puVar5 + 8) = 0xffffffff;
    }
    return;
  }
  goto LAB_004b3762;
}


