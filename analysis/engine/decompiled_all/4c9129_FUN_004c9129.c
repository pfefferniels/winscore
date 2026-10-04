// FUN_004c9129 @ 004c9129 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004c9129(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  *param_3 = *param_3 + 1;
  *param_2 = (&DAT_01e9bfc4)[*param_3];
  *param_1 = *(undefined4 *)(&DAT_01e9cf5c + *param_3 * 4);
  return;
}


