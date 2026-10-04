// FUN_0053df2a @ 0053df2a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0053df2a(float *param_1,int *param_2)

{
  uint uVar1;
  float10 in_ST0;
  
  DAT_0078cd34 = f_0_5;
  DAT_0078cd38 = (uint)ROUND(*param_1);
  uVar1 = DAT_0078cd38 & 1;
  if ((uVar1 != 0) && ((int)DAT_0078cd38 < 0)) {
    uVar1 = uVar1 - 2;
  }
  if (uVar1 != 0) {
    DAT_0078cd34 = f_1_2;
  }
  if (*param_2 == 0x14) {
    in_ST0 = (float10)DAT_0078cd34;
    DAT_0078cd34 = (float)-in_ST0;
  }
  *param_1 = DAT_0078cd34 + *param_1;
  P4 = *param_1;
  P5 = *param_1;
  ffree(in_ST0);
  return;
}


