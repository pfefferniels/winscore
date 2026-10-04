// FUN_0045623f @ 0045623f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045623f(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (DAT_01d953e0 < 1) {
    DAT_01d953e0 = 1;
  }
  DAT_007fec18 = thunk_FUN_00450b9c(&DAT_01d953e0);
  DAT_007fec14 = *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fec18 * VEC_STRIDE);
  _DAT_007fec10 = *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fec18 + 1) * VEC_STRIDE);
  if (*param_3 == 0) {
    DAT_007fec0c = DAT_01a14950;
    DAT_007fec08 = DAT_01a1494c;
    DAT_007fec14 = DAT_01a14950 - DAT_007fec14;
    _DAT_007fec10 = DAT_01a1494c - _DAT_007fec10;
    thunk_FUN_0044efa3(&DAT_007612f4,&DAT_007612f4);
    DAT_007fec18 = *param_1 * 3 + 0x16;
    DAT_007fec04 = *param_1;
    for (iVar1 = (*param_2 - DAT_007fec04) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fec18 * VEC_STRIDE) =
           DAT_007fec14 + *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fec18 * VEC_STRIDE)
      ;
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fec18 + 1) * VEC_STRIDE) =
           *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fec18 + 1) * VEC_STRIDE) +
           _DAT_007fec10;
      (&PT_X0)[DAT_007fec04] =
           DAT_0078df10 + *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fec18 * VEC_STRIDE)
      ;
      (&PT_Y0)[DAT_007fec04] =
           *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fec18 + 1) * VEC_STRIDE) -
           DAT_0078df14;
      thunk_FUN_0044ec7c(&PT_X0 + DAT_007fec04,&PT_Y0 + DAT_007fec04);
      DAT_007fec18 = DAT_007fec18 + 3;
      DAT_007fec04 = DAT_007fec04 + 1;
    }
    thunk_FUN_0044ec7c(&PT_X0 + DAT_01d953e0,&PT_Y0 + DAT_01d953e0);
  }
  else {
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fec18 * VEC_STRIDE) = DAT_01a14950;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fec18 + 1) * VEC_STRIDE) = DAT_01a1494c;
    (&PT_X0)[DAT_01d953e0] = DAT_0078df10 + _DAT_0078df18;
    (&PT_Y0)[DAT_01d953e0] = DAT_0078df1c - DAT_0078df14;
    thunk_FUN_0044ec7c(&PT_X0 + DAT_01d953e0,&PT_Y0 + DAT_01d953e0);
    thunk_FUN_0044ea5b(&DAT_01d953e0,&PT_X0 + DAT_01d953e0,&PT_Y0 + DAT_01d953e0,
                       DAT_01d953e0 * 2 + 0x1fbb8de);
  }
  return;
}


