// input_min_gap @ 0052fc56 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void input_min_gap(int *param_1)

{
  int iVar1;
  
  _DAT_0099a128 = 1;
  _DAT_01f9a6f0 = f_0;
  iVar1 = *param_1;
  DAT_0099a11c = 2;
  _DAT_0099a124 = f_0;
  _DAT_0099a120 = f_0;
  while (iVar1 = iVar1 + -1, 0 < iVar1) {
    _DAT_0099a118 =
         (float)(&DAT_01f95d4c)[DAT_0099a11c * 0xf] - (float)(&DAT_01f95d10)[DAT_0099a11c * 0xf];
    if ((f_3 <= _DAT_0099a118) || (_DAT_0099a118 == f_0)) {
      _DAT_0099a120 = _DAT_0099a118 + _DAT_0099a120;
    }
    else {
      _DAT_0099a124 = (_DAT_0099a124 + f_3) - _DAT_0099a118;
    }
    DAT_0099a11c = DAT_0099a11c + 1;
  }
  if ((_DAT_0099a124 != f_0) &&
     (_DAT_0099a114 = (_DAT_0099a120 - _DAT_0099a124) / _DAT_0099a120, f_0 < _DAT_0099a114)) {
    iVar1 = *param_1;
    DAT_0099a11c = 2;
    DAT_01f98f80 = DAT_00796fd0;
    _DAT_0099a124 = f_0;
    while (iVar1 = iVar1 + -1, 0 < iVar1) {
      _DAT_0099a118 =
           (float)(&DAT_01f95d4c)[DAT_0099a11c * 0xf] - (float)(&DAT_01f95d10)[DAT_0099a11c * 0xf];
      if (((f_3_6 <= _DAT_0099a118) || (_DAT_0099a124 = f_3, _DAT_0099a118 == f_0)) &&
         (_DAT_0099a124 = f_0, f_0 < _DAT_0099a118)) {
        _DAT_0099a124 = _DAT_0099a114 * _DAT_0099a118;
      }
      (&DAT_01f98f7c)[DAT_0099a11c] = _DAT_0099a124 + (float)(&DAT_01f98f78)[DAT_0099a11c];
      DAT_0099a11c = DAT_0099a11c + 1;
    }
    DAT_0099a11c = 2;
    for (iVar1 = *param_1 + -2; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&DAT_01f95d4c)[DAT_0099a11c * 0xf] = (&DAT_01f98f7c)[DAT_0099a11c];
      DAT_0099a11c = DAT_0099a11c + 1;
    }
  }
  return;
}


