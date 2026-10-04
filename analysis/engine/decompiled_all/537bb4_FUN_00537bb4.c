// FUN_00537bb4 @ 00537bb4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00537bb4(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if ((char)DAT_020b8ea0 == ' ') {
    FUN_005f33c9(&stack0xfffffffc,0x537bee);
    puVar3 = puVar4;
    FUN_005f34d1(puVar4,0x537c09);
  }
  *(undefined4 *)(puVar3 + -0x3c) = 0;
  *(undefined4 *)(puVar3 + -0x58) = 0x80;
  *(undefined2 **)(puVar3 + -0x54) = &DAT_020b8ea0;
  *(undefined4 *)(puVar3 + -0x50) = 3;
  *(undefined **)(puVar3 + -0x4c) = &DAT_00768a18;
  *(undefined4 *)(puVar3 + -0x48) = 2;
  uVar1 = FUN_005f6540(puVar3 + -0x3c,3,0x784ff01,&DAT_00768a08,puVar3 + -0x58);
  *(undefined4 *)(puVar3 + -0x1c) = uVar1;
  if (*(int *)(puVar3 + -0x1c) == 0) {
    while (**(int **)(puVar3 + 0x10) = **(int **)(puVar3 + 0x10) + 1,
          **(int **)(puVar3 + 0x10) < 0x12d) {
      while( true ) {
        iVar2 = **(int **)(puVar3 + 0x10);
        *(undefined4 *)(puVar3 + -0x3c) = 0;
        *(undefined4 *)(puVar3 + -0x50) = 0x80;
        *(int *)(puVar3 + -0x4c) = iVar2 * 0x80 + *(int *)(puVar3 + 8) + -0x80;
        *(undefined4 *)(puVar3 + -0x48) = 0x80;
        uVar1 = FUN_005fdbd0(puVar3 + -0x3c,3,0x784ff01,&DAT_00768a04,puVar3 + -0x50,&DAT_00797368);
        *(undefined4 *)(puVar3 + -0x14) = uVar1;
        if (*(int *)(puVar3 + -0x14) != 0) goto LAB_00537d61;
        iVar2 = FUN_005f4660(0x20);
        if (iVar2 == 0) break;
        *(undefined4 *)(puVar3 + -0x10) = 0;
      }
      thunk_FUN_0054c83c(**(int **)(puVar3 + 0x10) * 0x80 + *(int *)(puVar3 + 8) + -0x80,0x80,
                         &DAT_007689fc);
      *(undefined4 *)(puVar3 + -0xc) = 0;
    }
    *(undefined4 *)(puVar3 + -0x18) = 0;
LAB_00537d61:
    **(int **)(puVar3 + 0x10) = **(int **)(puVar3 + 0x10) + -1;
    *(undefined4 *)(puVar3 + -8) = 0;
  }
  else {
    **(undefined4 **)(puVar3 + 0x10) = 0xfffffc19;
  }
  *(undefined4 *)(puVar3 + -0x3c) = 0;
  FUN_005f7950(puVar3 + -0x3c,3,0x784ff00,&DAT_007689f8,0);
  return;
}


