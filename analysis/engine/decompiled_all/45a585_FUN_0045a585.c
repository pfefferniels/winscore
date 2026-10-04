// FUN_0045a585 @ 0045a585 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0045a585(int *param_1)

{
  int iVar1;
  
  VEC_N = 0x19;
  iVar1 = *param_1;
  DAT_007fee64 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    (&PT_X0)[DAT_007fee64] = (&PT_X0)[DAT_007fee64] * 100 + 8000;
    (&PT_Y0)[DAT_007fee64] = (&PT_Y0)[DAT_007fee64] * 100 + -19000;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
         (&PT_X0)[DAT_007fee64] + DAT_0078df10;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
         (&PT_Y0)[DAT_007fee64] - DAT_0078df14;
    DAT_007fee60 = (undefined *)0x0;
    DAT_007fee5c = (int)*(short *)((int)&DAT_01fbb8dc + DAT_007fee64 * 2 + 2);
    if (DAT_007fee5c == 1) {
      DAT_007fee60 = &DAT_0100962c;
    }
    if (1 < DAT_007fee5c) {
      DAT_007fee60 = &DAT_010000ff;
    }
    *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) = DAT_007fee60;
    *(int *)(&DAT_020359fc + DAT_007fee64 * 4) = VEC_N;
    VEC_N = VEC_N + 3;
    DAT_007fee64 = DAT_007fee64 + 1;
  }
  *DAT_01fbb7c0 = VEC_N + -1;
  return;
}


