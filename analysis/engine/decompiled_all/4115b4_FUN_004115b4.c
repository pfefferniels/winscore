// FUN_004115b4 @ 004115b4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004115b4(int *param_1,int *param_2)

{
  if (*param_1 < *param_2) {
    DAT_01fb8cc0 = DAT_01fb8cc0 + 1;
    (&DAT_01fb8cc0)[DAT_01fb8cc0] = (int)(float)*param_1;
    DAT_01fb8cc0 = DAT_01fb8cc0 + 1;
    (&DAT_01fb8cc0)[DAT_01fb8cc0] = (int)(float)*param_2;
  }
  *param_1 = 0;
  return;
}


