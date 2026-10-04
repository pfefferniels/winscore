// FUN_0042c60e @ 0042c60e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0042c60e(float *param_1,int *param_2)

{
  float10 fVar1;
  
  DAT_007f1358 = (int)ROUND(*param_1);
  fVar1 = (float10)amod(param_1,&f_2);
  if (fVar1 == (float10)f_1) {
    if (*param_2 == 10) {
      if (DAT_007f1358 < 0xc) {
        *param_1 = *param_1 + f_1;
      }
    }
    else if (2 < DAT_007f1358) {
      *param_1 = *param_1 - f_1;
    }
  }
  return;
}


