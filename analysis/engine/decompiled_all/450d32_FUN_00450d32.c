// FUN_00450d32 @ 00450d32 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00450d32(int *param_1)

{
  int iVar1;
  
  DAT_007fe8f0 = 99999;
  DAT_007fe8ec = 99999;
  iVar1 = *param_1;
  DAT_007fe8e8 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    if ((int)(&PT_X0)[DAT_007fe8e8] < DAT_007fe8f0) {
      DAT_007fe8f0 = (&PT_X0)[DAT_007fe8e8];
    }
    if ((int)(&PT_Y0)[DAT_007fe8e8] < DAT_007fe8ec) {
      DAT_007fe8ec = (&PT_Y0)[DAT_007fe8e8];
    }
    DAT_007fe8e8 = DAT_007fe8e8 + 1;
  }
  DAT_007fe8f0 = 8000 - DAT_007fe8f0;
  DAT_007fe8ec = -32000 - DAT_007fe8ec;
  VEC_N = 0x19;
  iVar1 = *param_1;
  DAT_007fe8e8 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_007fe8e4 = (&PT_X0)[DAT_007fe8e8] + DAT_007fe8f0;
    (&PT_X0)[DAT_007fe8e8] = DAT_007fe8e4;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
         DAT_0078df10 + DAT_007fe8e4;
    DAT_007fe8e0 = (&PT_Y0)[DAT_007fe8e8] + DAT_007fe8ec;
    (&PT_Y0)[DAT_007fe8e8] = DAT_007fe8e0;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
         DAT_007fe8e0 - DAT_0078df14;
    VEC_N = VEC_N + 3;
    DAT_007fe8e8 = DAT_007fe8e8 + 1;
  }
  return;
}


