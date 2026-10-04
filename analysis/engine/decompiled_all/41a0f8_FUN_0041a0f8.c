// FUN_0041a0f8 @ 0041a0f8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


int FUN_0041a0f8(float *param_1)

{
  int iVar1;
  
  DAT_007d14fc = (int)ROUND(*param_1);
  iVar1 = (int)ROUND(*param_1) % 100;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  return iVar1;
}


