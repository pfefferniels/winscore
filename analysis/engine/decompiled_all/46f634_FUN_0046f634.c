// FUN_0046f634 @ 0046f634 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046f634(int *param_1)

{
  _DAT_00824e58 = *(float *)(&DAT_020b9438 + *param_1 * 4);
  if (_DAT_00824e58 == f_0) {
    _DAT_00824e58 = f_1;
  }
  (&P1)[DAT_020527d4] =
       (*(float *)(&DAT_020b9358 + DAT_020527d4 * 4) * *(float *)(&DAT_020b943c + *param_1 * 4)) /
       _DAT_00824e58;
  *(float *)(&P0 + DAT_020527d4 * 4) = (float)*param_1;
  DAT_020527d4 = DAT_020527d4 + 2;
  return;
}


