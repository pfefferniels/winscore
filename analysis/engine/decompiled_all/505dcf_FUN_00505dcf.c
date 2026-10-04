// FUN_00505dcf @ 00505dcf (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00505dcf(int param_1,int *param_2)

{
  DAT_00935e38 = *(undefined4 *)(param_1 + -4 + *param_2 * 4);
  *(undefined4 *)(param_1 + -4 + *param_2 * 4) = *(undefined4 *)(param_1 + *param_2 * 4);
  *(undefined4 *)(param_1 + *param_2 * 4) = DAT_00935e38;
  return;
}


