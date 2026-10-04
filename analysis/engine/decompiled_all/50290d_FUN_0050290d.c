// FUN_0050290d @ 0050290d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0050290d(void)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x502934);
  FUN_005f34d1(puVar1,0x50294f);
  *(undefined4 *)(puVar1 + -0x24) = 0;
  *(undefined4 *)(puVar1 + -0x38) = 3;
  *(undefined4 **)(puVar1 + -0x34) = &DAT_01caea48;
  *(undefined4 *)(puVar1 + -0x30) = *(undefined4 *)(puVar1 + 8);
  FUN_005f34f0(puVar1 + -0x24,0x784ff00,&DAT_00766d88,puVar1 + -0x38,&DAT_00795610);
  FUN_005f33c9(puVar1,0x5029b3);
  FUN_005f34d1(puVar1,0x5029ce);
  DAT_0078b4e4 = 0;
  P2 = f_1;
  P3 = **(float **)(puVar1 + 0x10);
  P4 = **(float **)(puVar1 + 0xc) + f_8;
  P5 = f_0;
  P6 = f_0_9;
  P7 = f_0;
  DAT_009029e4 = NPT;
  NPT = 1;
  DAT_00795448 = 1;
  thunk_FUN_005644b8();
  DAT_00795448 = 0;
  NPT = DAT_009029e4;
  P12 = f_0;
  P13 = f_0;
  return;
}


