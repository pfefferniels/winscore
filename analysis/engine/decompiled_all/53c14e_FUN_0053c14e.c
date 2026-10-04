// FUN_0053c14e @ 0053c14e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053c14e(float *param_1,float *param_2,float *param_3,undefined4 param_4)

{
  _DAT_0099ca10 = (*param_1 - X_POS) * *param_2 + *param_3;
  add_point(param_1,&DAT_0099ca10,param_4);
  return;
}


