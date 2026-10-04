// FUN_00448fcc @ 00448fcc (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00448fcc(int *param_1,int param_2,int param_3)

{
  int iVar1;
  unkbyte10 in_ST0;
  float10 fVar2;
  
  ffree(in_ST0);
  fVar2 = (float10)FUN_00448ab8(&DAT_007fd45c,&DAT_01c4c824);
  DAT_01c4c850 = (float)_DAT_007fd45c;
  iVar1 = *param_1;
  DAT_01c4c828 = 1;
  _DAT_01c4c858 = f_0;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_01c4c824 = *(int *)(DAT_01c4c828 * 4 + param_2 + -4);
    if ((*(float *)(param_3 + 4 + DAT_01c4c824 * 4) == f_1) &&
       (*(float *)(param_3 + DAT_01c4c824 * 4) == f_14)) {
      DAT_01c4c854 = f_1;
      fVar2 = (float10)*(float *)(param_3 + 0xc + DAT_01c4c824 * 4);
      DAT_007fd458 = (float)ABS(fVar2);
      if ((f_0 < DAT_007fd458) && (f_3 < *(float *)(param_3 + -4 + DAT_01c4c824 * 4))) {
        DAT_01c4c854 = DAT_007fd458;
      }
      if ((float)_DAT_007fd45c <= DAT_01c4c854) goto LAB_0044913a;
      if (_DAT_01c4c858 < DAT_01c4c854) {
        _DAT_01c4c858 = DAT_01c4c854;
      }
    }
    DAT_01c4c828 = DAT_01c4c828 + 1;
  }
  DAT_01c4c828 = 0;
LAB_0044913a:
  ffree(fVar2);
  return;
}


