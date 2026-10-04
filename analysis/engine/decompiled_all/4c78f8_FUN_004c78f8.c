// FUN_004c78f8 @ 004c78f8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004c78f8(undefined4 *param_1,int *param_2)

{
  *param_2 = *param_2 + 1;
  (&DAT_01e9bfc4)[*param_2] = LOAD_P3;
  *(int *)(&DAT_01ea0164 + *param_2 * 4) = LOAD_W + 3;
  *(int *)(&DAT_01e9e224 + *param_2 * 4) = LOAD_STAFF;
  (&DAT_01ea20a4)[*param_2] = LOAD_I;
  (&DAT_01e9997c)[*param_2] = *param_1;
  return;
}


