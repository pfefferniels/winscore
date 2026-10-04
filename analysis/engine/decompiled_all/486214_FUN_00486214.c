// FUN_00486214 @ 00486214 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00486214(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar3 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x48623b);
  FUN_005f34d1(puVar3,0x486256);
  iVar1 = FUN_005f4660(0x20);
  if (iVar1 == 0) {
    *(undefined4 *)(puVar3 + -0x18) = 0;
  }
  else {
    thunk_FUN_00572158();
    puVar4 = (undefined4 *)&DAT_020b8ea0;
    puVar5 = (undefined4 *)&DAT_020b90a1;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      *(undefined4 *)(puVar3 + -0x14) = 0;
      return;
    }
  }
  *(undefined4 *)(puVar3 + -0x38) = 0;
  *(undefined4 *)(puVar3 + -0x50) = 0x80;
  *(undefined **)(puVar3 + -0x4c) = &DAT_020b90a1;
  *(undefined4 *)(puVar3 + -0x48) = 3;
  *(undefined **)(puVar3 + -0x44) = &DAT_007629d8;
  *(undefined4 *)(puVar3 + -0x40) = 2;
  uVar2 = FUN_005f6540(puVar3 + -0x38,5,0x784ff01,&DAT_007629c8,puVar3 + -0x50);
  *(undefined4 *)(puVar3 + -0x10) = uVar2;
  if (*(int *)(puVar3 + -0x10) == 0) {
    FUN_005f33c9(puVar3,0x486358);
    FUN_005f34d1(puVar3,0x486373);
    FUN_005f33c9(puVar3,0x486395);
    *(undefined4 *)(puVar3 + -0x38) = 0;
    *(undefined4 *)(puVar3 + -0x40) = 0x200;
    *(undefined2 **)(puVar3 + -0x3c) = &DAT_020b8ea0;
    uVar2 = FUN_005fdbd0(puVar3 + -0x38,5,0x784ff01,&DAT_007629bc,puVar3 + -0x40,&DAT_00791160);
    *(undefined4 *)(puVar3 + -0xc) = uVar2;
    if (*(int *)(puVar3 + -0xc) == 0) {
      _DAT_00828dcc = 2;
      thunk_FUN_00470ea5(&DAT_00828dcc);
      *(undefined4 *)(puVar3 + -8) = 0;
    }
  }
  else {
    thunk_FUN_0042ac4e(&DAT_020b90a1,0x80);
  }
  *(undefined4 *)(puVar3 + -0x38) = 0;
  FUN_005f7950(puVar3 + -0x38,5,0x784ff00,&DAT_007629b8,0);
  _DAT_00828dc8 = 0;
  return;
}


