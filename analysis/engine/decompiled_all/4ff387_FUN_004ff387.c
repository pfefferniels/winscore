// FUN_004ff387 @ 004ff387 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004ff387(void)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x4ff3ae);
  FUN_005f34d1(puVar1,0x4ff3c9);
  *(undefined4 *)(puVar1 + -0x28) = 0;
  *(undefined4 *)(puVar1 + -0x38) = 3;
  *(undefined4 *)(puVar1 + -0x34) = 0x20b90b6;
  *(undefined4 *)(puVar1 + -0x30) = *(undefined4 *)(puVar1 + 8);
  FUN_005f34f0(puVar1 + -0x28,0x784ff00,&DAT_00766a80,puVar1 + -0x38,&DAT_007953bc);
  *(undefined4 *)(puVar1 + -0x28) = 0;
  *(undefined4 *)(puVar1 + -0x38) = 3;
  *(undefined4 *)(puVar1 + -0x34) = 0x20b90ba;
  *(undefined4 *)(puVar1 + -0x30) = *(undefined4 *)(puVar1 + 0xc);
  FUN_005f34f0(puVar1 + -0x28,0x784ff00,&DAT_00766a80,puVar1 + -0x38,&DAT_007953d0);
  thunk_FUN_0054d831(&DAT_020b90a0,0x200);
  return;
}


