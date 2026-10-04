// FUN_004cb518 @ 004cb518 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004cb518(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  
  DAT_01aae498 = 0;
  DAT_01be180c = *param_1;
  DAT_01be1818 = f_0;
  for (iVar1 = (*param_2 - DAT_01be180c) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_01aae48c = *(float *)(param_3 + -4 + DAT_01be180c * 4);
    if ((DAT_01aae48c != f_m14) || (DAT_01aae48c != DAT_01be1818)) {
      DAT_01aae498 = DAT_01aae498 + 1;
      *(float *)(&DAT_01e9cf5c + DAT_01aae498 * 4) = DAT_01aae48c;
      DAT_01be1818 = DAT_01aae48c;
    }
    DAT_01be180c = DAT_01be180c + 1;
  }
  return;
}


