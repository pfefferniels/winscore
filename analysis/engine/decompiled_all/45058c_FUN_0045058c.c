// FUN_0045058c @ 0045058c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045058c(int *param_1,int *param_2)

{
  int iVar1;
  
  if (2 < *param_1) {
    if (0 < *param_2) {
      DAT_007fe8c8 = *param_2 + 1;
      iVar1 = (*param_1 - DAT_007fe8c8) + 1;
      while ((0 < iVar1 && (*(short *)((int)&DAT_01fbb8dc + DAT_007fe8c8 * 2 + 2) < 1))) {
        DAT_007fe8c8 = DAT_007fe8c8 + 1;
        iVar1 = iVar1 + -1;
      }
      if (*param_1 < DAT_007fe8c8) {
        DAT_007fe8c8 = *param_1;
      }
      if (DAT_007fe8c8 != *param_1) {
        DAT_007fe8c8 = DAT_007fe8c8 + -1;
        DAT_007fe8b8 = *param_2;
        iVar1 = -DAT_007fe8b8 / -1;
        while ((0 < iVar1 && (*(short *)((int)&DAT_01fbb8dc + DAT_007fe8b8 * 2 + 2) < 2))) {
          DAT_007fe8b8 = DAT_007fe8b8 + -1;
          iVar1 = iVar1 + -1;
        }
        if (DAT_007fe8b8 < 1) {
          DAT_007fe8b8 = 1;
        }
        FUN_004509c3(&DAT_007fe8c8,param_1);
        DAT_007fe8c8 = DAT_007fe8c8 + 1;
        (&PT_X0)[DAT_007fe8c8] = (&PT_X0)[DAT_007fe8b8];
        (&PT_Y0)[DAT_007fe8c8] = (&PT_Y0)[DAT_007fe8b8];
        *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fe8c8 * 2 + 2) = 0;
        DAT_007fe8c0 = FUN_00450b9c(&DAT_007fe8c8);
        DAT_007fe8c4 = FUN_00450b9c(&DAT_007fe8b8);
        *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fe8c0 * VEC_STRIDE) =
             *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fe8c4 * VEC_STRIDE);
        *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fe8c0 + 1) * VEC_STRIDE) =
             *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fe8c4 + 1) * VEC_STRIDE)
        ;
        *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fe8c0 + 2) * VEC_STRIDE) = 0;
        *param_1 = *param_1 + 1;
        _DAT_007fe8bc = *param_1;
        return;
      }
    }
    DAT_007fe8c8 = *param_1;
    iVar1 = -DAT_007fe8c8 / -1;
    while ((0 < iVar1 && (*(short *)((int)&DAT_01fbb8dc + DAT_007fe8c8 * 2 + 2) < 1))) {
      DAT_007fe8c8 = DAT_007fe8c8 + -1;
      iVar1 = iVar1 + -1;
    }
    DAT_007fe8c4 = (&PT_X0)[DAT_007fe8c8];
    DAT_007fe8c0 = (&PT_Y0)[DAT_007fe8c8];
    *param_1 = *param_1 + 1;
    _DAT_007fe8bc = *param_1;
    (&PT_X0)[*param_1] = DAT_007fe8c4;
    (&PT_Y0)[*param_1] = DAT_007fe8c0;
    *(undefined2 *)((int)&DAT_01fbb8dc + *param_1 * 2 + 2) = 0;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
         DAT_0078df10 + DAT_007fe8c4;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
         DAT_007fe8c0 - DAT_0078df14;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) = 0;
    iVar1 = VEC_N + 2;
    VEC_N = VEC_N + 3;
    *DAT_01fbb7c0 = iVar1;
  }
  return;
}


