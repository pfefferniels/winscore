// FUN_004a7da8 @ 004a7da8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a7da8(void)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  
  puVar8 = &stack0xfffffffc;
  FUN_004a6baa();
  DAT_00791448 = 1;
  _DAT_01fbb828 = 0;
  DAT_01fbb700 = 0;
  FUN_005f33c9(&stack0xfffffffc,0x4a7def);
  FUN_005f34d1(puVar8,0x4a7e0a);
  puVar4 = &DAT_0078b510;
  puVar7 = &DAT_0078b590;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  _DAT_01b9d620 = 0;
  DAT_0205274c = 0;
  DAT_02052760 = 0;
  DAT_01b9d624 = 1;
  DAT_01b9d628 = 0xffffffff;
  uVar2 = (uint)DAT_0088cc04 >> 8;
  _DAT_0088cbfc = 1;
  _DAT_0088cc08 = 1;
  DAT_0088cc10 = 1;
  DAT_0088cc14 = 1;
  DAT_0088cc0c = 4;
  DAT_0088cbf8 = &DAT_0088cbd0;
  _DAT_0088cc00 = 0xffffffff;
  DAT_0088cc04 = CONCAT31(((uint3)uVar2 | 0xff0000) ^ 0xfe0000,1);
  uVar2 = (uint)DAT_0088cbe4 >> 8;
  _DAT_0088cbdc = 4;
  _DAT_0088cbe8 = 1;
  DAT_0088cbf0 = 4;
  DAT_0088cbf4 = 1;
  DAT_0088cbec = 0x100;
  DAT_0088cbd8 = &DAT_0088cc18;
  _DAT_0088cbe0 = 0xfffffffc;
  DAT_0088cbe4 = CONCAT31(((uint3)uVar2 | 0xff0000) ^ 0xfc0000,1);
  DAT_0088cbd0 = 0x7e;
  DAT_0088cbd1 = 0x7a;
  DAT_0088cbd2 = 0x61;
  *(undefined1 **)(puVar8 + -0x28) = &stack0xffffff94;
  puVar1 = DAT_0088cbf8;
  *(int *)(puVar8 + -0x44) = DAT_0088cc10;
  *(int *)(puVar8 + -0x48) = DAT_0088cc14;
  iVar3 = (DAT_0088cc0c + DAT_0088cc14) - *(int *)(puVar8 + -0x48);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  *(int *)(puVar8 + -0x4c) = iVar3;
  iVar3 = DAT_0088cc10 * DAT_0088cc14;
  puVar5 = puVar8 + -0x68;
  for (uVar2 = *(int *)(puVar8 + -0x4c) + 7U & 0xfffffff8; 0x1000 < (int)uVar2;
      uVar2 = uVar2 - 0x1000) {
    puVar5 = puVar5 + -0x1000;
  }
  iVar6 = (int)puVar5 - uVar2;
  *(int *)(puVar8 + -0x30) = iVar6;
  *(int *)(puVar8 + -0x28) = iVar6;
  *(undefined4 *)(puVar8 + -0x3c) = *(undefined4 *)(puVar8 + -0x48);
  *(undefined4 *)(puVar8 + -0x40) = 1;
  while (puVar4 = DAT_0088cbd8, *(int *)(puVar8 + -0x40) <= *(int *)(puVar8 + -0x4c)) {
    *(undefined1 *)(*(int *)(puVar8 + -0x40) + *(int *)(puVar8 + -0x30) + -1) =
         puVar1[*(int *)(puVar8 + -0x3c) * *(int *)(puVar8 + -0x44) - iVar3];
    *(int *)(puVar8 + -0x3c) = *(int *)(puVar8 + -0x3c) + 1;
    *(int *)(puVar8 + -0x40) = *(int *)(puVar8 + -0x40) + 1;
  }
  *(int *)(puVar8 + -0x50) = DAT_0088cbf0;
  *(int *)(puVar8 + -0x54) = DAT_0088cbf4;
  iVar3 = (DAT_0088cbec + DAT_0088cbf4) - *(int *)(puVar8 + -0x54);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  *(int *)(puVar8 + -0x58) = iVar3;
  iVar3 = DAT_0088cbf0 * DAT_0088cbf4;
  for (uVar2 = *(int *)(puVar8 + -0x58) * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar2;
      uVar2 = uVar2 - 0x1000) {
    iVar6 = iVar6 + -0x1000;
  }
  iVar6 = iVar6 - uVar2;
  *(int *)(puVar8 + -0x2c) = iVar6;
  *(int *)(puVar8 + -0x28) = iVar6;
  *(undefined4 *)(puVar8 + -0x34) = *(undefined4 *)(puVar8 + -0x54);
  *(undefined4 *)(puVar8 + -0x38) = 1;
  while (*(int *)(puVar8 + -0x38) <= *(int *)(puVar8 + -0x58)) {
    *(undefined4 *)(*(int *)(puVar8 + -0x38) * 4 + *(int *)(puVar8 + -0x2c) + -4) =
         *(undefined4 *)
          ((int)puVar4 + (*(int *)(puVar8 + -0x34) * *(int *)(puVar8 + -0x50) - iVar3));
    *(int *)(puVar8 + -0x34) = *(int *)(puVar8 + -0x34) + 1;
    *(int *)(puVar8 + -0x38) = *(int *)(puVar8 + -0x38) + 1;
  }
  *(undefined4 *)(iVar6 + -4) = *(undefined4 *)(puVar8 + -0x2c);
  *(undefined4 *)(iVar6 + -8) = *(undefined4 *)(puVar8 + -0x30);
  *(undefined4 *)(iVar6 + -0xc) = 0x4a80c5;
  thunk_FUN_00597d30();
  puVar1 = DAT_0088cbf8;
  iVar3 = DAT_0088cc10 * DAT_0088cc14;
  *(undefined4 *)(puVar8 + -0x3c) = *(undefined4 *)(puVar8 + -0x48);
  *(undefined4 *)(puVar8 + -0x40) = 1;
  while (puVar4 = DAT_0088cbd8, *(int *)(puVar8 + -0x40) <= *(int *)(puVar8 + -0x4c)) {
    puVar1[*(int *)(puVar8 + -0x3c) * *(int *)(puVar8 + -0x44) - iVar3] =
         *(undefined1 *)(*(int *)(puVar8 + -0x40) + *(int *)(puVar8 + -0x30) + -1);
    *(int *)(puVar8 + -0x3c) = *(int *)(puVar8 + -0x3c) + 1;
    *(int *)(puVar8 + -0x40) = *(int *)(puVar8 + -0x40) + 1;
  }
  iVar3 = DAT_0088cbf0 * DAT_0088cbf4;
  *(undefined4 *)(puVar8 + -0x34) = *(undefined4 *)(puVar8 + -0x54);
  *(undefined4 *)(puVar8 + -0x38) = 1;
  while (*(int *)(puVar8 + -0x38) <= *(int *)(puVar8 + -0x58)) {
    *(undefined4 *)((int)puVar4 + (*(int *)(puVar8 + -0x34) * *(int *)(puVar8 + -0x50) - iVar3)) =
         *(undefined4 *)(*(int *)(puVar8 + -0x38) * 4 + *(int *)(puVar8 + -0x2c) + -4);
    *(int *)(puVar8 + -0x34) = *(int *)(puVar8 + -0x34) + 1;
    *(int *)(puVar8 + -0x38) = *(int *)(puVar8 + -0x38) + 1;
  }
  _DAT_0088cbc4 = DAT_0088cc18;
  _DAT_0088cbc0 = DAT_0088cc1c;
  *(undefined **)(puVar8 + -0x70) = &DAT_00763d50;
  *(undefined4 *)(puVar8 + -0x74) = 0x4a819b;
  thunk_FUN_00473cdd();
  *(undefined4 *)(puVar8 + -0x6c) = 9;
  *(char **)(puVar8 + -0x70) = "SCORE.MUS";
  *(undefined4 *)(puVar8 + -0x74) = 0x4a81af;
  thunk_FUN_00495d4f();
  *(undefined4 *)(puVar8 + -4) = 0;
  return;
}


