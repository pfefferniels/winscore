// FUN_004eae57 @ 004eae57 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


float10 FUN_004eae57(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x4eae81);
  iVar1 = FUN_005ff950(puVar2 + -0x58,0x30);
  DAT_008d15f0 = iVar1 + 1;
  FUN_005f46bc(puVar2,0x4eaedc);
  FUN_005f34d1(puVar2,0x4eaef2);
  FUN_005f33c9(puVar2,0x4eaf1a);
  FUN_005f34d1(puVar2,0x4eaf35);
  return (float10)*(float *)(puVar2 + -4);
}


