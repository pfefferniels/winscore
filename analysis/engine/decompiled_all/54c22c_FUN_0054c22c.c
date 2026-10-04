// FUN_0054c22c @ 0054c22c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c22c(void)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  DAT_00791470 = 0;
  _DAT_009a235c = f_322;
  _DAT_009a2358 = 0x1e240;
  FUN_005f33c9(&stack0xfffffffc,0x54c272);
  FUN_005f34d1(puVar1,0x54c28d);
  *(undefined4 *)(puVar1 + -0x24) = 0;
  *(undefined4 *)(puVar1 + -0x38) = 0x15;
  *(undefined **)(puVar1 + -0x34) = &DAT_020b90bd;
  *(undefined **)(puVar1 + -0x30) = &DAT_009a235c;
  FUN_005f34f0(puVar1 + -0x24,0x784ff00,&DAT_00769474,puVar1 + -0x38,&DAT_007978a8);
  *(undefined **)(puVar1 + -0x30) = &DAT_009a2358;
  FUN_005f3960(puVar1 + -0x24,&DAT_007693cc,puVar1 + -0x30);
  DAT_020b90cb = 0;
  FUN_0054946a(&DAT_020b90a0,0x200);
  return;
}


