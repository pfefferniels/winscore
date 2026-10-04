// push_words @ 0054daf6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void push_words(int *param_1,int param_2)

{
  int iVar1;
  
  DAT_009a2aac = 0;
  DAT_009a2aa8 = DAT_01a1b3a0 + 1;
  for (iVar1 = ((*param_1 + DAT_01a1b3a0) - DAT_009a2aa8) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_009a2aac = DAT_009a2aac + 1;
    (&DAT_01a1b3a0)[DAT_009a2aa8] = *(undefined4 *)(param_2 + -4 + DAT_009a2aac * 4);
    DAT_009a2aa8 = DAT_009a2aa8 + 1;
  }
  DAT_01a1b3a0 = *param_1 + DAT_01a1b3a0;
  return;
}


