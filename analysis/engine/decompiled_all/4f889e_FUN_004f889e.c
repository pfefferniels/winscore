// FUN_004f889e @ 004f889e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004f889e(int *param_1,int *param_2)

{
  DAT_008f9188 = (&DAT_02091d20)[*param_1] - (&ITEM_PTR0)[*param_1];
  thunk_FUN_0054c590(&DAT_01e9997c + (&ITEM_PTR0)[*param_1],&ITEM_LEN + *param_2,&DAT_008f9188);
  *param_2 = DAT_008f9188 + *param_2;
  return;
}


