// FUN_00469059 @ 00469059 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00469059(float *param_1,int *param_2,float *param_3,int *param_4)

{
  int iVar1;
  
  DAT_00824670 = (int)ROUND(*param_1);
  DAT_0082466c = FUN_005ff9b0(10,*param_2);
  DAT_00824668 = DAT_00824670 % DAT_0082466c;
  iVar1 = FUN_005ff9b0(10,*param_2 + -1);
  *param_4 = iVar1;
  DAT_00824664 = DAT_00824668 / *param_4;
  *param_3 = (float)DAT_00824664;
  DAT_00824670 = DAT_00824670 - DAT_00824664 * *param_4;
  *param_1 = (float)DAT_00824670;
  return;
}


