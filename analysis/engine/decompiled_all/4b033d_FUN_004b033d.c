// FUN_004b033d @ 004b033d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b033d(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  *param_3 = *param_4;
  FUN_005f46bc(&stack0xfffffffc,0x4b0387);
  FUN_005f34d1(puVar1,0x4b039d);
  FUN_004b023b(*(undefined4 *)(puVar1 + 8),0x18,*(undefined4 *)(puVar1 + 0x14));
  *param_3 = *param_3 + 4;
  **(int **)(puVar1 + 0x14) = **(int **)(puVar1 + 0x14) + *param_3;
  FUN_005f46bc(puVar1,0x4b03fa);
  FUN_005f34d1(puVar1,0x4b0410);
  return;
}


