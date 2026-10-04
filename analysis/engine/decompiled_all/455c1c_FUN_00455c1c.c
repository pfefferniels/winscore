// FUN_00455c1c @ 00455c1c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00455c1c(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  DAT_007febc0 = *param_1;
  DAT_007febc4 = *param_2;
  for (iVar1 = (*param_3 - DAT_007febc4) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    *param_1 = *param_1 + 1;
    (&PT_X0)[*param_1] = (&PT_X0)[DAT_007febc4] + 500;
    (&PT_Y0)[*param_1] = (&PT_Y0)[DAT_007febc4] + 500;
    *(undefined2 *)((int)&DAT_01fbb8dc + *param_1 * 2 + 2) =
         *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007febc4 * 2 + 2);
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
         (&PT_X0)[*param_1] + DAT_0078df10;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
         (&PT_Y0)[*param_1] - DAT_0078df14;
    DAT_007febbc = thunk_FUN_00450b9c(&DAT_007febc4);
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
         *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007febbc + 2) * VEC_STRIDE);
    if ((*(short *)((int)&DAT_01fbb8dc + DAT_007febc4 * 2 + 2) == 0) && (DAT_007febc4 == *param_2))
    {
      *(undefined2 *)((int)&DAT_01fbb8dc + *param_1 * 2 + 2) = 1;
      *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
           &DAT_0100962c;
    }
    VEC_N = VEC_N + 3;
    DAT_007febc4 = DAT_007febc4 + 1;
  }
  *DAT_01fbb7c0 = VEC_N + -1;
  *param_2 = DAT_007febc0 + 1;
  *param_3 = *param_1;
  _DAT_01c25e58 = *param_1;
  thunk_FUN_0044ec7c(&PT_X0 + *param_2,&PT_Y0 + *param_2);
  thunk_FUN_0044efa3(&PT_X0 + *param_3,&PT_Y0 + *param_3);
  return;
}


