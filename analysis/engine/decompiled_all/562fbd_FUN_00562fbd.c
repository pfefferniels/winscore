// FUN_00562fbd @ 00562fbd (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_00562fbd(float *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*param_1 < (float)IP1) || ((float)IP2 < *param_1)) {
    uVar1 = 1;
  }
  return uVar1;
}


