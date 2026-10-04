// FUN_00505e0d @ 00505e0d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00505e0d(int param_1,int *param_2)

{
  _DAT_00935e3c = (int)*(char *)(param_1 + -1 + *param_2);
  *(undefined1 *)(param_1 + -1 + *param_2) = *(undefined1 *)(param_1 + *param_2);
  *(undefined1 *)(param_1 + *param_2) = DAT_00935e3c;
  return;
}


