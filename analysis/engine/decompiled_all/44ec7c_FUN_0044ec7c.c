// FUN_0044ec7c @ 0044ec7c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044ec7c(int *param_1,int *param_2)

{
  _DAT_007fe344 = (float)DAT_009c66cc;
  if (_DAT_007fe344 == f_0) {
    _DAT_007fe344 = f_64;
  }
  _DAT_007fe340 = (f_64 / _DAT_007fe344) * f_600;
  _DAT_007fe344 = (f_64 / _DAT_007fe344) * f_200;
  DAT_007fe33c = *param_1 + DAT_0078df10;
  DAT_007fe338 = *param_2 - DAT_0078df14;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0xd) =
       (int)ROUND((float)DAT_007fe33c - _DAT_007fe344);
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0xe) =
       (int)ROUND((float)DAT_007fe338 - _DAT_007fe340);
  *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0xf) = &DAT_020000ff;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0x10) = DAT_007fe33c;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0x11) = DAT_007fe338;
  *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0x12) = 0;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0x13) =
       (int)ROUND((float)DAT_007fe33c + _DAT_007fe344);
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0x14) =
       (int)ROUND((float)DAT_007fe338 - _DAT_007fe340);
  *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0x15) = 0;
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0x16) =
       (int)ROUND((float)DAT_007fe33c - _DAT_007fe344);
  *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0x17) =
       (int)ROUND((float)DAT_007fe338 - _DAT_007fe340);
  *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE * 0x18) = 0;
  return;
}


