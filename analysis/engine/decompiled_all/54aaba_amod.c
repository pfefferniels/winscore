// amod @ 0054aaba (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


float10 amod(float *param_1,float *param_2)

{
  return (float10)(*param_1 - (float)(int)ROUND(*param_1 / *param_2) * *param_2);
}


