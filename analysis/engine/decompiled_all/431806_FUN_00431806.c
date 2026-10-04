// FUN_00431806 @ 00431806 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00431806(int *param_1,int *param_2)

{
  while ((&DAT_020b8e9f)[*param_1] == ' ') {
    *param_1 = *param_1 + 1;
  }
  *param_2 = *param_1;
  while ((&DAT_020b8e9f)[*param_2] != ' ') {
    *param_2 = *param_2 + 1;
  }
  *param_2 = *param_2 + -1;
  return;
}


