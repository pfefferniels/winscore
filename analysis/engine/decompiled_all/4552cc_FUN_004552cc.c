// FUN_004552cc @ 004552cc (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004552cc(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  _DAT_007feba0 = f_100;
  if (((char)DAT_020b8ea0 == 'R') || ((char)DAT_020b8ea0 == 'L')) {
    thunk_FUN_00518448();
    DAT_007feb9c = (int)ROUND(P2);
    if (DAT_020b8ea0._1_1_ != '*') {
      DAT_007feb9c = DAT_007feb98;
    }
    DAT_007feb98 = DAT_007feb9c;
    DAT_007feb9c = (int)ROUND((float)DAT_007feb9c * _DAT_007feba0);
    if ((char)DAT_020b8ea0 == 'L') {
      DAT_007feb9c = -DAT_007feb9c;
    }
    if ((*param_3 == 0) && (*param_2 != 0)) {
      DAT_007feb94 = (&PT_X0)[*param_1] + DAT_007feb9c;
      (&PT_X0)[*param_1] = DAT_007feb94;
      DAT_007feb90 = thunk_FUN_00450b9c(param_1);
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007feb90 * VEC_STRIDE) = DAT_007feb94;
      return;
    }
    iVar1 = *param_1;
    DAT_007feb90 = 1;
    for (; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (*param_3 == 0) {
LAB_00455773:
        (&PT_X0)[DAT_007feb90] = (&PT_X0)[DAT_007feb90] + DAT_007feb9c;
        DAT_007feb8c = thunk_FUN_00450b9c(&DAT_007feb90);
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007feb8c * VEC_STRIDE) =
             *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007feb8c * VEC_STRIDE) +
             DAT_007feb9c;
      }
      else if (*param_3 <= DAT_007feb90) {
        if (DAT_007feb90 <= *param_4) goto LAB_00455773;
        break;
      }
      DAT_007feb90 = DAT_007feb90 + 1;
    }
  }
  else if (((char)DAT_020b8ea0 == 'U') || ((char)DAT_020b8ea0 == 'D')) {
    thunk_FUN_00518448();
    DAT_007feb9c = (int)ROUND(P2);
    if (DAT_020b8ea0._1_1_ != '*') {
      DAT_007feb9c = DAT_007feb88;
    }
    DAT_007feb88 = DAT_007feb9c;
    DAT_007feb9c = (int)ROUND((float)DAT_007feb9c * _DAT_007feba0);
    if ((char)DAT_020b8ea0 == 'D') {
      DAT_007feb9c = -DAT_007feb9c;
    }
    if ((*param_3 == 0) && (*param_2 != 0)) {
      (&PT_Y0)[*param_1] = (&PT_Y0)[*param_1] + DAT_007feb9c;
      DAT_007feb8c = thunk_FUN_00450b9c(param_1);
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007feb8c + 1) * VEC_STRIDE) =
           DAT_007feb9c +
           *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007feb8c + 1) * VEC_STRIDE);
      return;
    }
    iVar1 = *param_1;
    DAT_007feb90 = 1;
    for (; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (*param_3 == 0) {
LAB_00455520:
        (&PT_Y0)[DAT_007feb90] = (&PT_Y0)[DAT_007feb90] + DAT_007feb9c;
        DAT_007feb8c = thunk_FUN_00450b9c(&DAT_007feb90);
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007feb8c + 1) * VEC_STRIDE) =
             *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007feb8c + 1) * VEC_STRIDE) +
             DAT_007feb9c;
      }
      else if (*param_3 <= DAT_007feb90) {
        if (DAT_007feb90 <= *param_4) goto LAB_00455520;
        break;
      }
      DAT_007feb90 = DAT_007feb90 + 1;
    }
  }
  if (*param_3 != 0) {
    thunk_FUN_0044ec7c(&PT_X0 + *param_3,&PT_Y0 + *param_3);
    thunk_FUN_0044efa3(&PT_X0 + *param_4,&PT_Y0 + *param_4);
  }
  return;
}


