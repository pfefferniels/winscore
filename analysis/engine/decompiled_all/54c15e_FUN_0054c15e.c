// FUN_0054c15e @ 0054c15e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c15e(void)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  if (DAT_020b8ea0._1_1_ == 'W') {
    FUN_00548f74();
  }
  else if (DAT_020b8ea0._1_1_ == 'S') {
    thunk_FUN_0046966c();
  }
  else {
    _DAT_009a2354 = 0;
    FUN_005f33c9(&stack0xfffffffc,0x54c1dc);
    FUN_005f34d1(puVar1,0x54c1f7);
    FUN_0054991a(&DAT_0076928c,2);
    *(undefined4 *)(puVar1 + -0x58) = 0;
  }
  return;
}


