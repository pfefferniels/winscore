// FUN_0054a967 @ 0054a967 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054a967(void)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x54a98e);
  FUN_005f34d1(puVar1,0x54a9a9);
  if (f_0 < P3) {
    FUN_005f33c9(puVar1,0x54a9de);
    FUN_005f34d1(puVar1,0x54a9f9);
  }
  *(undefined4 *)(puVar1 + -0x28) = 0;
  *(undefined4 *)(puVar1 + -0x38) = 3;
  *(undefined4 *)(puVar1 + -0x34) = 0x7a0b82;
  *(int **)(puVar1 + -0x30) = &IP2;
  FUN_005f34f0(puVar1 + -0x28,0x784ff00,&DAT_0076915c,puVar1 + -0x38,&DAT_00797628);
  *(undefined4 *)(puVar1 + -0x28) = 0;
  *(undefined4 *)(puVar1 + -0x38) = 2;
  *(undefined **)(puVar1 + -0x34) = &DAT_007a0b8d;
  *(int **)(puVar1 + -0x30) = &IP1;
  FUN_005f34f0(puVar1 + -0x28,0x784ff00,&DAT_0076915c,puVar1 + -0x38,&DAT_0079763c);
  DAT_01f9a6f4 = thunk_FUN_0059afc0();
  FUN_005f34d1(puVar1,0x54aaaf);
  return;
}


