// FUN_0054d7d4 @ 0054d7d4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054d7d4(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x54d7fa);
  puVar1 = *(undefined4 **)(puVar2 + 8);
  DAT_009a247f = *puVar1;
  DAT_009a2483 = puVar1[1];
  DAT_009a2487 = *(undefined1 *)(puVar1 + 2);
  thunk_FUN_005960f0(&DAT_009a2458);
  return;
}


