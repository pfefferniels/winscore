// FUN_004d5fe1 @ 004d5fe1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d5fe1(int *param_1,int *param_2)

{
  float10 fVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  _DAT_008a0404 = (float)(*param_1 + *param_2) * DAT_01aae2f0;
  fVar1 = (float10)FUN_005ff381(&stack0xfffffffc,0x4d6016);
  *(int *)(puVar2 + -0x28) = (int)ROUND(fVar1);
  *(int *)(puVar2 + -4) = DAT_0078b4e4 + *(int *)(puVar2 + -0x28);
  return *(undefined4 *)(puVar2 + -4);
}


