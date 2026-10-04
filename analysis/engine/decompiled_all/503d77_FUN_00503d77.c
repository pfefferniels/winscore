// FUN_00503d77 @ 00503d77 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00503d77(int *param_1,int *param_2,int *param_3,float *param_4,float *param_5,int param_6)

{
  _DAT_00903c90 = *(float *)(param_6 + -4 + (*param_2 + *param_3) * 4);
  if ((*param_4 <= _DAT_00903c90) && (_DAT_00903c90 <= *param_5)) {
    DAT_020492a4 = DAT_020492a4 + 1;
    *(int *)(&DAT_02049a74 + DAT_020492a4 * 4) = -*param_3 - *param_2;
    if (DAT_020492a0 == 0) {
      DAT_020492a0 = *param_1;
    }
  }
  return;
}


