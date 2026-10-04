// FUN_00493e65 @ 00493e65 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493e65(void)

{
  VIEW_DX = 0x960;
  fit_view(&DAT_00762e40,&DAT_0082a00c,&DAT_0082a008,&DAT_0082a004,&DAT_0082a000);
  _DAT_00829ffc = (float)_DAT_01be6ca0;
  _DAT_00829ff8 = (float)(DAT_0082a00c - _DAT_0082a008);
  _DAT_00829ff4 = _DAT_00829ffc / _DAT_00829ff8;
  _DAT_0082a010 = (_DAT_00829ff4 - f_0_05) * (float)DAT_009c66cc;
  DAT_009a9498 = (int)ROUND(_DAT_0082a010);
  DAT_00829ff0 = (int)ROUND((_DAT_0082a010 / f_64) * f_100 + f_0_5);
  if (300 < DAT_00829ff0) {
    DAT_00829ff0 = 100;
  }
  DAT_009c66cc = DAT_009a9498;
  _DAT_00829fec = thunk_FUN_0059d240(DAT_00829ff0);
  draw_items();
  IP2 = 99999;
  thunk_FUN_00579770(&DAT_00762e2c,1,&IP1);
  IP2 = 0;
  IP1 = -0x960;
  thunk_FUN_00579770(&DAT_00762e28,1,&IP1);
  FUN_005f34d1(&stack0xfffffffc,0x49401c);
  return;
}


