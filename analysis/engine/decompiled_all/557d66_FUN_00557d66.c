// FUN_00557d66 @ 00557d66 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00557d66(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x557d8c);
  FUN_005f34d1(puVar2,0x557da7);
  puVar1 = &DAT_01e9dc94 + DAT_009a3c50;
  *(undefined4 *)(puVar2 + -0x24) = 0;
  *(undefined4 *)(puVar2 + -0x38) = 6;
  *(undefined4 *)(puVar2 + -0x34) = 0x9ae2da;
  *(undefined4 *)(puVar2 + -0x30) = 4;
  *(undefined4 **)(puVar2 + -0x2c) = puVar1;
  FUN_005f34f0(puVar2 + -0x24,0x784ff00,&DAT_00769a4c,puVar2 + -0x38,&DAT_0079ecac);
  return;
}


