// FUN_0052b325 @ 0052b325 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052b325(void)

{
  int iVar1;
  
  iVar1 = *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_STRIDE);
  DAT_0098d674 = 1;
  DAT_0098d630 = iVar1;
  _DAT_0098d66c = NPT;
  DAT_0078de00 = DAT_0098d670;
  for (; DAT_0098d670 = DAT_0078de00, NPT = _DAT_0098d66c, 0 < iVar1; iVar1 = iVar1 + -1) {
    (&ITEM_LEN)[DAT_0098d674] =
         *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_0098d674 + 1) * VEC_STRIDE);
    DAT_0098d674 = DAT_0098d674 + 1;
    _DAT_0098d66c = NPT;
    DAT_0078de00 = DAT_0098d670;
  }
  DAT_0098d630 = DAT_0098d630 + -5;
  ITEM_I = 1;
  _DAT_020b8e40 = 0;
  ITEM_WORDS = DAT_0098d630;
  thunk_FUN_00545752(&DAT_0098d630);
  if (DAT_0078b4e4 != 0x1a0a) {
    DAT_0098d668 = DAT_02052740;
    index_items();
    draw_items();
    thunk_FUN_00549422();
    _DAT_0098d664 = 0;
    fit_view(&DAT_00768078,&DAT_0098d660,&DAT_0098d65c,&DAT_0098d658,&DAT_0098d654);
    thunk_FUN_00579770(&DAT_00768074,1,&DAT_0098d650);
    _DAT_0098d64c = (float)DAT_0098d648 / f_64;
    _DAT_0098d644 = (f_17000 - (float)DAT_0098d660) / f_40000;
    if (DAT_0098d660 + 27000 < DAT_0098d648) {
      _DAT_0098d644 = f_2;
    }
    _DAT_0098d644 = _DAT_0098d64c * _DAT_0098d644;
    DAT_0098d648 = (int)ROUND(_DAT_0098d644);
    if (_DAT_0098d640 == f_0) {
      thunk_FUN_00535d00(&DAT_00767fe8);
    }
    DAT_020527e8 = ITEM_I;
    DAT_02052740 = DAT_0098d668;
    if ((DAT_0098d63c == 0) && (DAT_0098d668 == 0)) {
      DAT_0078b4e4 = 0x48;
    }
    DAT_0098d638 = 0;
    DAT_0098d63c = 0;
    do {
      DAT_0098d638 = DAT_0098d638 + 1;
      if ((float)(&ITEM_LEN)[(&ITEM_PTR0)[DAT_0098d638]] < f_3) {
        thunk_FUN_005239c9(&DAT_0098d638,&f_3);
      }
    } while (DAT_0098d638 < ITEM_I);
    thunk_FUN_0054e9f2();
    DAT_0078b4ec = 0;
  }
  return;
}


