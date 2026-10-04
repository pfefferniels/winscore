// FUN_00488258 @ 00488258 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00488258(void)

{
  int iVar1;
  
  if (P2 == f_1) {
    DAT_0078df24 = 1;
  }
  if (P2 == f_2) {
    DAT_0078df24 = 0;
  }
  DAT_01a149ac = DAT_00791630;
  DAT_01a149b0 = DAT_00791634;
  DAT_00828f98 = thunk_FUN_00595d40();
  if (DAT_00828f98 < 0) {
    PAPER = 0;
    thunk_FUN_00495d4f(&DAT_0078b510,0x80);
    draw_items();
  }
  else {
    PAPER = DAT_00828f98;
    _DAT_009c66d0 = DAT_00828f98;
    thunk_FUN_00495d4f(&DAT_0078b510,0x80);
    DAT_00791630 = DAT_01a149ac;
    DAT_00791634 = DAT_01a149b0;
    if (_DAT_01a149b4 == f_0) {
      DAT_00791630 = DAT_01a149ac / f_2_54;
      DAT_00791634 = DAT_01a149b0 / f_2_54;
    }
    _DAT_00828f94 = (uint)(_DAT_01a149b4 == f_0);
    _DAT_00828f90 = f_11;
    DAT_01fbb8b8 = f_200;
    RIGHT_LIMIT = 30000;
    if (DAT_0078df24 != 0) {
      if (PAPER == 2) {
        _DAT_00828f90 = f_14;
      }
      if (PAPER == 3) {
        _DAT_00828f90 = f_17;
        DAT_01fbb8b8 = f_266;
        RIGHT_LIMIT = 0x9bdc;
      }
      else if (PAPER == 5) {
        _DAT_00828f90 = f_16_5;
        DAT_01fbb8b8 = f_285;
        RIGHT_LIMIT = 0xa6fe;
      }
      else if (PAPER == 6) {
        _DAT_00828f90 = f_11_75;
        DAT_01fbb8b8 = f_194;
        RIGHT_LIMIT = 0x71ac;
      }
      else if (PAPER == 7) {
        _DAT_00828f90 = f_13_875;
        DAT_01fbb8b8 = f_234;
        RIGHT_LIMIT = 0x891c;
      }
      else if (PAPER == 8) {
        _DAT_00828f90 = DAT_00791634;
        _DAT_00828f8c = (DAT_00791630 - f_1) * f_4000;
        RIGHT_LIMIT = (int)ROUND(_DAT_00828f8c + f_0_5);
        DAT_01fbb8b8 = _DAT_00828f8c / f_150;
      }
      DAT_0078df20 = DAT_01fbb8b8;
      for (iVar1 = 1; iVar1 < 0x41; iVar1 = iVar1 + 1) {
        *(float *)(&DAT_01a149a8 + iVar1 * 4) = f_0;
      }
      DAT_0078df28 = DAT_01fbb8b8 / f_2;
      thunk_FUN_00579770(&DAT_00762b78,1,&IP1);
    }
    draw_items();
  }
  return;
}


