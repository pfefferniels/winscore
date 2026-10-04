// FUN_004d31bb @ 004d31bb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d31bb(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6,int *param_7)

{
  float fVar1;
  
  _DAT_008a0230 = *param_3;
  _DAT_008a022c = *param_5;
  _DAT_008a0228 = *param_4;
  _DAT_008a0224 = *param_6;
  if (f_0_01 < ABS(*param_1 - _DAT_01aae2b4)) {
    _DAT_01aae2b4 = *param_1 - _DAT_01aae2b4;
    _DAT_008a0230 = _DAT_01aae2b4 + _DAT_008a0230;
    _DAT_008a022c = _DAT_01aae2b4 + _DAT_008a022c;
  }
  if (f_0_01 < ABS(*param_2 - _DAT_01aae2b8)) {
    _DAT_01aae2b8 = *param_2 - _DAT_01aae2b8;
    _DAT_008a0228 = _DAT_01aae2b8 + _DAT_008a0228;
    _DAT_008a0224 = _DAT_01aae2b8 + _DAT_008a0224;
  }
  DAT_01aae2a0 = _DAT_01aae2b0 * _DAT_008a0230;
  DAT_01aae2a4 = _DAT_01aae2b0 * _DAT_008a0228;
  DAT_01aae2a8 = _DAT_01aae2b0 * _DAT_008a022c;
  DAT_01aae2ac = _DAT_01aae2b0 * _DAT_008a0224;
  if (DAT_020b8e8c != f_1) {
    _DAT_008a0220 = *param_1 * f_72;
    _DAT_008a021c = *param_2 * f_72;
    DAT_01aae2a8 = (DAT_01aae2a8 - _DAT_008a0220) * DAT_020b8e8c + _DAT_008a0220;
    DAT_01aae2ac = (DAT_01aae2ac - _DAT_008a021c) * DAT_020b8e8c + _DAT_008a021c;
    DAT_01aae2a0 = (DAT_01aae2a0 - _DAT_008a0220) * DAT_020b8e8c + _DAT_008a0220;
    DAT_01aae2a4 = (DAT_01aae2a4 - _DAT_008a021c) * DAT_020b8e8c + _DAT_008a021c;
  }
  if (*param_7 != 0) {
    _DAT_008a0218 = DAT_01aae2ac;
    fVar1 = DAT_01aae2a8 - f_8;
    DAT_01aae2a8 = ram0x00765488 - DAT_01aae2a4;
    DAT_01aae2a4 = DAT_01aae2a0 - f_8;
    DAT_01aae2a0 = ram0x00765488 - DAT_01aae2ac;
    DAT_01aae2ac = fVar1;
  }
  return;
}


