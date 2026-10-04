// FUN_004a72c7 @ 004a72c7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a72c7(void)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  FUN_005f46bc(&stack0xfffffffc,0x4a7301);
  FUN_005f46bc(puVar1,0x4a731a);
  FUN_005f34d1(puVar1,0x4a7330);
  DAT_0088c9e4 = 8;
  thunk_FUN_00498826(&DAT_0088c9f4,0x80,&DAT_0088c9e4,&DAT_00763c94,&DAT_00763c94);
  if (DAT_0088c9e4 < 0) {
    *(undefined4 *)(puVar1 + -0x14) = 0;
    _DAT_0088c9e0 = 0;
  }
  else {
    *(undefined4 *)(puVar1 + -0x34) = 0;
    *(undefined4 *)(puVar1 + -0x40) = 0x16;
    *(undefined **)(puVar1 + -0x3c) = &DAT_01c2cd10;
    FUN_005f8240(puVar1 + -0x34,DAT_0088c9e4,0x784ff00,&DAT_00763c90,puVar1 + -0x40);
    *(undefined4 *)(puVar1 + -0x34) = 0;
    *(undefined4 *)(puVar1 + -0x48) = 0xf0;
    *(undefined4 **)(puVar1 + -0x44) = &DAT_01c2cc20;
    *(undefined4 *)(puVar1 + -0x40) = 0x18;
    FUN_005f8240(puVar1 + -0x34,DAT_0088c9e4,0x784ff00,&DAT_00763c8c,puVar1 + -0x48);
    *(undefined4 *)(puVar1 + -8) = 0;
  }
  *(undefined4 *)(puVar1 + -0x34) = 0;
  FUN_005f7950(puVar1 + -0x34,8,0x784ff00,&DAT_00763c88,0);
  return;
}


