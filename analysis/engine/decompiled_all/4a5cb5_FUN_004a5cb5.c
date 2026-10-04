// FUN_004a5cb5 @ 004a5cb5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a5cb5(void)

{
  float10 fVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  fVar1 = (float10)FUN_005ff381(&stack0xfffffffc,0x4a5ce7);
  *(int *)(puVar2 + -0x24) = (int)ROUND(fVar1);
  _DAT_00839160 = *(undefined4 *)(puVar2 + -0x24);
  _DAT_0083915c = 1;
  return;
}


