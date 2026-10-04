// FUN_004509c3 @ 004509c3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004509c3(int *param_1,int *param_2)

{
  int iVar1;
  
  DAT_007fe8d0 = *param_2;
  for (iVar1 = (*param_1 - DAT_007fe8d0) / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
    (&DAT_01fd3f80)[DAT_007fe8d0] = (&PT_X0)[DAT_007fe8d0];
    (&DAT_02004cc0)[DAT_007fe8d0] = (&PT_Y0)[DAT_007fe8d0];
    (&DAT_01fbb8e0)[DAT_007fe8d0] = *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fe8d0 * 2 + 2);
    DAT_007fe8cc = FUN_00450b9c(&DAT_007fe8d0);
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fe8cc + 3) * VEC_STRIDE) =
         *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fe8cc * VEC_STRIDE);
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fe8cc + 4) * VEC_STRIDE) =
         *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fe8cc + 1) * VEC_STRIDE);
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fe8cc + 5) * VEC_STRIDE) =
         *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fe8cc + 2) * VEC_STRIDE);
    DAT_007fe8d0 = DAT_007fe8d0 + -1;
  }
  VEC_N = VEC_N + 3;
  *DAT_01fbb7c0 = *DAT_01fbb7c0 + 3;
  return;
}


