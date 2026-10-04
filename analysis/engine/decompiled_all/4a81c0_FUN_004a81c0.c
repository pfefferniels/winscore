// FUN_004a81c0 @ 004a81c0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_004a81c0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  DAT_0088d024 = *param_3;
  DAT_0088d020 = *param_3;
  FUN_005f46bc(&stack0xfffffffc,0x4a820f);
  FUN_005f34d1(puVar2,0x4a8225);
  iVar1 = DAT_0088d020;
  *(int *)(puVar2 + -0x18) = DAT_0088d020;
  DAT_0088d01c = 1;
  while (0 < iVar1) {
    if (*(char *)((int)&DAT_0088d024 + DAT_0088d01c + 3) == '\0') {
      DAT_0088d020 = DAT_0088d01c;
      *(undefined4 *)(puVar2 + -0x10) = 0;
      break;
    }
    *(undefined4 *)(puVar2 + -0x14) = 0;
    *(undefined4 *)(puVar2 + -0xc) = 0;
    DAT_0088d01c = DAT_0088d01c + 1;
    *(int *)(puVar2 + -0x18) = *(int *)(puVar2 + -0x18) + -1;
    iVar1 = *(int *)(puVar2 + -0x18);
  }
  iVar1 = -DAT_0088d020 / -1;
  DAT_0088d018 = DAT_0088d020;
  do {
    if (iVar1 < 1) {
      DAT_0088d018 = 0;
LAB_004a82f6:
      *(int *)(puVar2 + -0x1c) = DAT_0088d018;
      return *(undefined4 *)(puVar2 + -0x1c);
    }
    if (' ' < *(char *)((int)&DAT_0088d024 + DAT_0088d018 + 3)) {
      *(undefined4 *)(puVar2 + -8) = 0;
      goto LAB_004a82f6;
    }
    DAT_0088d018 = DAT_0088d018 + -1;
    iVar1 = iVar1 + -1;
  } while( true );
}


