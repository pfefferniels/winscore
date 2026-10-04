// FUN_0044efa3 @ 0044efa3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044efa3(int *param_1,int *param_2)

{
  _DAT_007fe354 = (float)DAT_009c66cc;
  if (_DAT_007fe354 == f_0) {
    _DAT_007fe354 = f_64;
  }
  _DAT_007fe350 = (f_64 / _DAT_007fe354) * f_600;
  _DAT_007fe354 = (f_64 / _DAT_007fe354) * f_200;
  DAT_007fe34c = *param_1 + DAT_0078df10;
  DAT_007fe348 = *param_2 - DAT_0078df14;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
       (int)ROUND((float)DAT_007fe34c - _DAT_007fe354);
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
       (int)ROUND((float)DAT_007fe348 - _DAT_007fe350);
  *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) = &DAT_0200962c;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 3) * VEC_STRIDE) = DAT_007fe34c;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 4) * VEC_STRIDE) = DAT_007fe348;
  *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 5) * VEC_STRIDE) = 0;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 6) * VEC_STRIDE) =
       (int)ROUND((float)DAT_007fe34c + _DAT_007fe354);
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 7) * VEC_STRIDE) =
       (int)ROUND((float)DAT_007fe348 - _DAT_007fe350);
  *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 8) * VEC_STRIDE) = 0;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 9) * VEC_STRIDE) =
       (int)ROUND((float)DAT_007fe34c - _DAT_007fe354);
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 10) * VEC_STRIDE) =
       (int)ROUND((float)DAT_007fe348 - _DAT_007fe350);
  *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 0xb) * VEC_STRIDE) = 0;
  *DAT_01fbb7c0 = VEC_N + 0xb;
  return;
}


