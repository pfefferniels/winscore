// FUN_005191dc @ 005191dc (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


float10 FUN_005191dc(void)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  
  puVar3 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x519202);
  FUN_005f46bc(puVar3,0x519242);
  FUN_005f34d1(puVar3,0x519258);
  *(undefined4 *)(puVar3 + -0x28) = 0xc;
  DAT_0094e1ec = 1;
  do {
    if (*(char *)((int)&DAT_0094e1ec + DAT_0094e1ec + 3) == '.') {
      DAT_0094e1e8 = DAT_0094e1ec + 1;
      iVar2 = 0xd - DAT_0094e1e8;
      *(int *)(puVar3 + -0x24) = iVar2;
      goto joined_r0x00519344;
    }
    if ((*(char *)((int)&DAT_0094e1ec + DAT_0094e1ec + 3) != '+') &&
       (bVar1 = *(byte *)((int)&DAT_0094e1ec + DAT_0094e1ec + 3), bVar6 = bVar1 < 0x2d,
       bVar1 != 0x2d)) {
      iVar2 = 1;
      bVar7 = false;
      pbVar4 = (byte *)((int)&DAT_0094e1ec + DAT_0094e1ec + 3);
      pbVar5 = &DAT_00767804;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pbVar4 < *pbVar5;
        bVar7 = *pbVar4 == *pbVar5;
        pbVar4 = pbVar4 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (!bVar6) {
        iVar2 = 1;
        bVar6 = false;
        pbVar4 = (byte *)((int)&DAT_0094e1ec + DAT_0094e1ec + 3);
        pbVar5 = &DAT_00767800;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pbVar4 < *pbVar5;
          bVar7 = *pbVar4 == *pbVar5;
          pbVar4 = pbVar4 + 1;
          pbVar5 = pbVar5 + 1;
        } while (bVar7);
        if (bVar6 || bVar7) {
          *(undefined4 *)(puVar3 + -0x10) = 0;
          goto LAB_005192f8;
        }
      }
      *(undefined1 *)((int)&DAT_0094e1ec + DAT_0094e1ec + 3) = 0x2e;
      FUN_005f46bc(puVar3,0x519459);
      FUN_005f34d1(puVar3,0x51946f);
      *(undefined4 *)(puVar3 + -0xc) = 0;
      break;
    }
    *(undefined4 *)(puVar3 + -0x14) = 0;
LAB_005192f8:
    *(undefined4 *)(puVar3 + -8) = 0;
    DAT_0094e1ec = DAT_0094e1ec + 1;
    *(int *)(puVar3 + -0x28) = *(int *)(puVar3 + -0x28) + -1;
  } while (0 < *(int *)(puVar3 + -0x28));
LAB_0051947a:
  *(undefined4 *)(puVar3 + -0x4c) = 0;
  *(undefined4 *)(puVar3 + -0x60) = 0xc;
  *(undefined1 **)(puVar3 + -0x5c) = &DAT_0094e1f0;
  *(undefined1 **)(puVar3 + -0x58) = puVar3 + -0x2c;
  FUN_005f9240(puVar3 + -0x4c,0x784ff00,&DAT_0076780c,puVar3 + -0x60,&DAT_0079692c);
  **(int **)(puVar3 + 8) = **(int **)(puVar3 + 0xc) + 1;
  return (float10)*(float *)(puVar3 + -0x2c);
joined_r0x00519344:
  if (iVar2 < 1) goto LAB_00519405;
  bVar7 = iVar2 == 0;
  bVar6 = false;
  iVar2 = 1;
  pbVar4 = (byte *)((int)&DAT_0094e1ec + DAT_0094e1e8 + 3);
  pbVar5 = &DAT_00767804;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pbVar4 < *pbVar5;
    bVar7 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar7);
  if (bVar6) {
LAB_005193a0:
    *(undefined4 *)(puVar3 + -0x20) = 0;
    FUN_005f46bc(puVar3,0x5193e2);
    FUN_005f34d1(puVar3,0x5193f8);
    *(undefined4 *)(puVar3 + -0x18) = 0;
    goto LAB_0051947a;
  }
  iVar2 = 1;
  bVar6 = false;
  pbVar4 = (byte *)((int)&DAT_0094e1ec + DAT_0094e1e8 + 3);
  pbVar5 = &DAT_00767800;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pbVar4 < *pbVar5;
    bVar7 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar7);
  if (!bVar6 && !bVar7) goto LAB_005193a0;
  DAT_0094e1e8 = DAT_0094e1e8 + 1;
  *(int *)(puVar3 + -0x24) = *(int *)(puVar3 + -0x24) + -1;
  iVar2 = *(int *)(puVar3 + -0x24);
  goto joined_r0x00519344;
LAB_00519405:
  *(undefined4 *)(puVar3 + -0x1c) = 0;
  goto LAB_0051947a;
}


