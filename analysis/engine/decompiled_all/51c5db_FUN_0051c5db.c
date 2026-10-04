// FUN_0051c5db @ 0051c5db (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


float10 FUN_0051c5db(float *param_1)

{
  DAT_01be6c60 = 3 - (int)ROUND(*param_1);
  if (DAT_01be6c60 == 0) {
    DAT_01be6c60 = 1;
  }
  if (*param_1 == f_0_0625) {
    DAT_01be6c60 = -1;
  }
  return (float10)DAT_01be6c60;
}


