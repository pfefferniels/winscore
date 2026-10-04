// FUN_00468130 @ 00468130 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00468130(int *param_1,int *param_2,int *param_3,float *param_4,float *param_5)

{
  float10 fVar1;
  
  *param_3 = (int)ROUND(*param_5);
  *param_1 = *param_3 / 100;
  *param_2 = (*param_3 % 100) / 10;
  *param_3 = *param_3 % 10;
  fVar1 = (float10)amod(param_5,&f_1);
  *param_4 = (float)fVar1;
  return;
}


