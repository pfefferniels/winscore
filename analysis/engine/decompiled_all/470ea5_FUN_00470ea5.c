// FUN_00470ea5 @ 00470ea5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00470ea5(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffffc;
  iVar1 = 0x200;
  DAT_00824f50 = 1;
  do {
    if ((char)(&DAT_020b8e9f)[DAT_00824f50] < ' ') {
      (&DAT_020b8e9f)[DAT_00824f50] = 0;
    }
    DAT_00824f50 = DAT_00824f50 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  puVar2 = (undefined4 *)&DAT_020b8ea0;
  puVar3 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)&DAT_020b8ea0;
  puVar3 = &DAT_009ae2bc;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_005f33c9(&stack0xfffffffc,0x470f39);
  FUN_005f34d1(puVar4,0x470f54);
  DAT_00824f50 = thunk_FUN_0059beb0(DAT_00824f54);
  if (DAT_00824f50 == 2) {
    if (**(int **)(puVar4 + 8) == 2) {
      **(undefined4 **)(puVar4 + 8) = 0;
      *(undefined4 *)(puVar4 + -4) = 0;
      return;
    }
    puVar2 = (undefined4 *)&DAT_020b90a0;
    puVar3 = &DAT_009ae2bc;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    *(undefined4 *)(puVar4 + -8) = 0;
  }
  puVar2 = &DAT_009ae2bc;
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


