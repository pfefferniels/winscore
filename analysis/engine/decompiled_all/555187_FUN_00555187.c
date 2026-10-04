// FUN_00555187 @ 00555187 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


float10 FUN_00555187(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 local_ac [42];
  
  puVar4 = &stack0xfffffffc;
  puVar2 = (undefined4 *)(&DAT_0078b650 + *param_1 * 0x80);
  puVar3 = local_ac;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = FUN_005ff950(local_ac,0x80);
  DAT_009a3ba8 = iVar1 + 1;
  FUN_005f46bc(&stack0xfffffffc,0x55520c);
  FUN_005f34d1(puVar4,0x555222);
  FUN_005f33c9(puVar4,0x55524d);
  FUN_005f34d1(puVar4,0x555268);
  return (float10)*(float *)(puVar4 + -4);
}


