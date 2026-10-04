// FUN_00508c9f @ 00508c9f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00508dc5) */
/* WARNING: Removing unreachable block (ram,0x00508cf9) */
/* WARNING: Removing unreachable block (ram,0x00508e6d) */
/* WARNING: Removing unreachable block (ram,0x00508f03) */
/* WARNING: Removing unreachable block (ram,0x00508f4d) */

void FUN_00508c9f(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  undefined4 uStack_78;
  
  puVar5 = &stack0xfffffffc;
  *param_4 = 0;
  if (*param_1 != ' ') {
    DAT_009403f4 = 1;
    do {
      uStack_78 = 0x508d18;
      FUN_005f46bc();
      uStack_78 = 0x508d2e;
      FUN_005f34d1();
      bVar8 = (undefined1 *)0xfffffffb < &uStack_78;
      bVar9 = &stack0x00000000 == (undefined1 *)0x74;
      iVar4 = 1;
      pbVar6 = &DAT_009403f8;
      pbVar7 = &DAT_00766fc4;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pbVar6 < *pbVar7;
        bVar9 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar8) {
        iVar4 = 1;
        pbVar6 = &DAT_009403f8;
        pbVar7 = &DAT_00766fc0;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar8 = *pbVar6 < *pbVar7;
          bVar9 = *pbVar6 == *pbVar7;
          pbVar6 = pbVar6 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar9);
        if (bVar8 || bVar9) {
          *(undefined4 *)(puVar5 + -0x24) = 0;
          goto LAB_00508d8a;
        }
      }
      DAT_009403f4 = DAT_009403f4 + 1;
      *(int *)(puVar5 + -0x28) = *(int *)(puVar5 + -0x28) + -1;
    } while (0 < *(int *)(puVar5 + -0x28));
    *(undefined4 *)(puVar5 + -0x20) = 0;
  }
  return;
LAB_00508d8a:
  iVar4 = 0x51 - DAT_009403f4;
  *(int *)(puVar5 + -0x1c) = iVar4;
  DAT_009403f0 = DAT_009403f4;
  while (0 < iVar4) {
    uStack_78 = 0x508de6;
    FUN_005f46bc();
    uStack_78 = 0x508dfc;
    FUN_005f34d1();
    bVar8 = DAT_009403f8 < 0x2d;
    if (DAT_009403f8 != 0x2d) {
      iVar4 = 1;
      pbVar6 = &DAT_009403f8;
      pbVar7 = &DAT_00766fc4;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar2 = *pbVar7;
        bVar1 = *pbVar6;
        bVar8 = bVar1 < bVar2;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar1 == bVar2);
      bVar9 = bVar8 != 0;
      iVar4 = -(uint)bVar8;
      bVar8 = iVar4 == 0;
      *(int *)(puVar5 + -0x50) = iVar4;
      iVar4 = 1;
      pbVar6 = &DAT_009403f8;
      pbVar7 = &DAT_00766fc0;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pbVar6 < *pbVar7;
        bVar8 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar8);
      if (((-(uint)(!bVar9 && !bVar8) | *(uint *)(puVar5 + -0x50)) & 1) != 0) {
        uStack_78 = 0x508e8e;
        FUN_005f46bc();
        uStack_78 = 0x508ea4;
        FUN_005f34d1();
      }
    }
    DAT_009403f0 = DAT_009403f0 + 1;
    *(int *)(puVar5 + -0x1c) = *(int *)(puVar5 + -0x1c) + -1;
    iVar4 = *(int *)(puVar5 + -0x1c);
  }
  *(int *)(puVar5 + -0x18) = 0x51 - DAT_009403f4;
  DAT_009403f0 = DAT_009403f4;
  if (0x51 - DAT_009403f4 < 1) {
    return;
  }
  do {
    uStack_78 = 0x20;
    iVar4 = FUN_00601a30();
    if (iVar4 == 0) {
      *(undefined4 *)(puVar5 + -0x14) = 0;
    }
    else {
      uStack_78 = 0x20;
      iVar4 = FUN_00601a30();
      if (iVar4 == 0) break;
      *(undefined4 *)(puVar5 + -0x10) = 0;
    }
    *(undefined4 *)(puVar5 + -4) = 0;
    DAT_009403f0 = DAT_009403f0 + 1;
    *(int *)(puVar5 + -0x18) = *(int *)(puVar5 + -0x18) + -1;
    if (*(int *)(puVar5 + -0x18) < 1) {
      return;
    }
  } while( true );
  **(int **)(puVar5 + 0x14) = **(int **)(puVar5 + 0x14) + 1;
  iVar4 = (DAT_009403f0 - (DAT_009403f4 + -1)) + -1;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  iVar3 = **(int **)(puVar5 + 0x14);
  *(undefined4 *)(puVar5 + -0x4c) = 0;
  *(int *)(puVar5 + -0x60) = iVar4;
  *(int *)(puVar5 + -0x5c) = DAT_009403f4 + -1 + *(int *)(puVar5 + 8);
  *(undefined4 *)(puVar5 + -0x58) = 4;
  *(int *)(puVar5 + -0x54) = iVar3 * 4 + *(int *)(puVar5 + 0x10) + -4;
  FUN_005f9240(puVar5 + -0x4c,0x784ff00,&DAT_00766fb4,puVar5 + -0x60,&DAT_00795704);
  DAT_009403f4 = DAT_009403f0 + 1;
  *(undefined4 *)(puVar5 + -8) = 0;
  goto LAB_00508d8a;
}


