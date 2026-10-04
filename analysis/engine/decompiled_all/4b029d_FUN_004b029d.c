// FUN_004b029d @ 004b029d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b029d(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  *param_3 = *param_4;
  (&DAT_020b8e9f)[*param_3] = 0x5c;
  FUN_004b023b(param_1,0x18,param_4);
  *param_3 = *param_3 + 1;
  *param_4 = *param_4 + *param_3;
  FUN_005f46bc(&stack0xfffffffc,0x4b031a);
  FUN_005f34d1(puVar1,0x4b0330);
  return;
}


