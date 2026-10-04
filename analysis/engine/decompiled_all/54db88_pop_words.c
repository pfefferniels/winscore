// pop_words @ 0054db88 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void pop_words(int *param_1,int param_2)

{
  int iVar1;
  
  DAT_009a2ab4 = *param_1;
  DAT_009a2ab0 = DAT_01a1b3a0;
  for (iVar1 = -*param_1 / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(int *)(param_2 + -4 + DAT_009a2ab4 * 4) = (&DAT_01a1b3a0)[DAT_009a2ab0];
    DAT_009a2ab4 = DAT_009a2ab4 + -1;
    DAT_009a2ab0 = DAT_009a2ab0 + -1;
  }
  DAT_01a1b3a0 = DAT_01a1b3a0 - *param_1;
  return;
}


