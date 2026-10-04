// FUN_0054cb15 @ 0054cb15 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */

void FUN_0054cb15(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int *in_stack_00000010;
  
  DAT_009a23ac = *in_stack_00000010;
  iVar3 = DAT_009a23ac;
  if (DAT_009a23ac < 0) {
    iVar3 = 0;
  }
  puVar4 = &stack0xffffffb4;
  for (uVar1 = iVar3 + 7U & 0xfffffff8; 0x1000 < (int)uVar1; uVar1 = uVar1 - 0x1000) {
    puVar4 = puVar4 + -0x1000;
  }
  iVar5 = (int)puVar4 - uVar1;
  *(undefined4 *)(iVar5 + -4) = 0x54cb89;
  *(undefined1 **)(iVar5 + -8) = &stack0xfffffffc;
  *(undefined4 *)(iVar5 + -0xc) = 0x54cb89;
  FUN_005f33c9();
  iVar3 = *(int *)(iVar5 + -8);
  *(undefined4 *)(iVar3 + -0x34) = *(undefined4 *)(iVar3 + -0x34);
  for (uVar1 = *(int *)(iVar3 + -0x34) + 7U & 0xfffffff8; 0x1000 < (int)uVar1;
      uVar1 = uVar1 - 0x1000) {
    iVar5 = iVar5 + -0x1000;
  }
  iVar5 = iVar5 - uVar1;
  *(int *)(iVar3 + -0x3c) = iVar5;
  *(undefined4 *)(iVar5 + -4) = 0x54cbe0;
  *(int *)(iVar5 + -8) = iVar3;
  *(undefined4 *)(iVar5 + -0xc) = 0x54cbe0;
  FUN_005f46bc();
  *(undefined4 *)(iVar5 + -4) = 0x54cbf6;
  *(undefined4 *)(iVar5 + -8) = *(undefined4 *)(iVar5 + -8);
  *(undefined4 *)(iVar5 + -0xc) = 0x54cbf6;
  FUN_005f34d1();
  iVar3 = *(int *)(iVar5 + -8);
  *(undefined4 *)(iVar5 + -4) = *(undefined4 *)(iVar3 + -0x34);
  *(undefined4 *)(iVar5 + -8) = *(undefined4 *)(iVar3 + -0x3c);
  *(undefined4 *)(iVar5 + -0xc) = 0x54cc07;
  uVar2 = FUN_005ff950();
  **(undefined4 **)(iVar3 + 0x10) = uVar2;
  if (**(int **)(iVar3 + 0x10) == 0) {
    *(undefined4 *)(iVar3 + -0x10) = 0;
  }
  else {
    while( true ) {
      *(undefined4 *)(iVar3 + -0x4c) = 0x20;
      *(undefined4 *)(iVar3 + -0x50) = 0x54cc50;
      iVar5 = FUN_00608e50();
      if (iVar5 == 0) break;
      **(int **)(iVar3 + 0x10) = **(int **)(iVar3 + 0x10) + -1;
      *(undefined4 *)(iVar3 + -8) = 0;
    }
    *(undefined4 *)(iVar3 + -0xc) = 0;
  }
  return;
}


