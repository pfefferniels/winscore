// staff_p4_error @ 00546910 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void staff_p4_error(void)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x546937);
  FUN_005f34d1(puVar1,0x546952);
  *(undefined4 *)(puVar1 + -0x28) = 0;
  *(undefined4 *)(puVar1 + -0x38) = 4;
  *(undefined4 *)(puVar1 + -0x34) = 0x20b90b9;
  *(undefined4 *)(puVar1 + -0x30) = *(undefined4 *)(puVar1 + 8);
  FUN_005f34f0(puVar1 + -0x28,0x784ff00,&DAT_00768f64,puVar1 + -0x38,&DAT_00797518);
  *(undefined4 *)(puVar1 + -0x28) = 0;
  *(undefined4 *)(puVar1 + -0x38) = 0x16;
  *(undefined **)(puVar1 + -0x34) = &DAT_020b90cc;
  *(undefined4 *)(puVar1 + -0x30) = *(undefined4 *)(puVar1 + 0xc);
  FUN_005f34f0(puVar1 + -0x28,0x784ff00,&DAT_00768f5c,puVar1 + -0x38,&DAT_0079752c);
  *(undefined4 *)(puVar1 + -0x30) = *(undefined4 *)(puVar1 + 0x10);
  FUN_005f3960(puVar1 + -0x28,&DAT_00768f58,puVar1 + -0x30);
  DAT_020b90df._3_1_ = 0;
  thunk_FUN_0054d831(&DAT_020b90a0,1);
  return;
}


