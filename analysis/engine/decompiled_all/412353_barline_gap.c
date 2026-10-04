// barline_gap @ 00412353 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void barline_gap(void)

{
  int iVar1;
  
  _DAT_007d130c = NPT;
  _DAT_007d1308 = (float)DAT_02004cc0;
  _DAT_007d1304 = (float)DAT_02004cc4;
  _DAT_007d1300 = _DAT_007d1304 - _DAT_007d1308;
  _DAT_007d12fc = P18;
  if (f_1 < P18) {
    _DAT_007d12fc = P18 / f_100;
  }
  _DAT_007d12f8 = _DAT_007d12fc * _DAT_007d1300 + _DAT_007d1308;
  _DAT_007d12f4 = STEP * P19 * f_7;
  _DAT_007d12f0 = _DAT_007d12f8 - _DAT_007d12f4 / f_2;
  _DAT_007d12ec = _DAT_007d12f4 + _DAT_007d12f0;
  DAT_007d12e8 = 1;
  if (P5 == f_1) {
    DAT_007d12e8 = 2;
  }
  if (OUTPUT_MODE < 0) {
    DAT_007d12e8 = DAT_007d12e8 * 2;
  }
  DAT_007d12e4 = 1;
  DAT_007d1310 = DAT_01fd3f80;
  DAT_007d1314 = DAT_01fd3f88;
  _DAT_007d1318 = DAT_01fd3f90;
  _DAT_007d131c = DAT_01fd3f98;
  DAT_007d12e0 = 1;
  iVar1 = DAT_007d12e8;
  if (DAT_007d12e8 != 0) {
    do {
      (&PT_X0)[DAT_007d12e4] = *(undefined4 *)(&DAT_007d130c + DAT_007d12e0 * 4);
      *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007d12e4 * 2 + 2) = 1;
      (&PT_Y0)[DAT_007d12e4] = (int)ROUND(_DAT_007d1308);
      DAT_007d12e4 = DAT_007d12e4 + 1;
      (&PT_X0)[DAT_007d12e4] = *(undefined4 *)(&DAT_007d130c + DAT_007d12e0 * 4);
      *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007d12e4 * 2 + 2) = 0;
      (&PT_Y0)[DAT_007d12e4] = (int)ROUND(_DAT_007d12f0);
      DAT_007d12e4 = DAT_007d12e4 + 1;
      (&PT_X0)[DAT_007d12e4] = *(undefined4 *)(&DAT_007d130c + DAT_007d12e0 * 4);
      *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007d12e4 * 2 + 2) = 1;
      (&PT_Y0)[DAT_007d12e4] = (int)ROUND(_DAT_007d12ec);
      DAT_007d12e4 = DAT_007d12e4 + 1;
      (&PT_X0)[DAT_007d12e4] = *(undefined4 *)(&DAT_007d130c + DAT_007d12e0 * 4);
      *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007d12e4 * 2 + 2) = 0;
      (&PT_Y0)[DAT_007d12e4] = (int)ROUND(_DAT_007d1304);
      DAT_007d12e4 = DAT_007d12e4 + 1;
      DAT_007d12e0 = DAT_007d12e0 + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
  }
  NPT = DAT_007d12e4;
  return;
}


