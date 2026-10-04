// FUN_004e79d2 @ 004e79d2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e79d2(void)

{
  int iVar1;
  
  thunk_FUN_005725fa();
  DAT_008d12e4 = (int)ROUND(P2);
  _DAT_008d12e0 = P3 - f_2;
  _DAT_008d12dc = P3 + f_2;
  DAT_008d12d8 = 0;
  if (P4 == f_0) {
    P4 = f_m1;
  }
  LOAD_I = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if ((((DAT_008d12e4 == LOAD_STAFF) && (LOAD_CODE == 0x10 || LOAD_CODE == 4)) &&
        (_DAT_008d12d4 = (float)(&ITEM_P4)[LOAD_W], _DAT_008d12e0 <= _DAT_008d12d4)) &&
       (_DAT_008d12d4 <= _DAT_008d12dc)) {
      (&ITEM_P4)[LOAD_W] = P4 + _DAT_008d12d4;
      if (LOAD_CODE == 4) {
        (&ITEM_P5)[LOAD_W] = P4 + (float)(&ITEM_P5)[LOAD_W];
      }
      DAT_008d12d8 = 1;
    }
    LOAD_I = LOAD_I + 1;
  }
  if (DAT_008d12d8 == 0) {
    thunk_FUN_0054d831("Text not found.",0xf);
  }
  else {
    draw_items();
  }
  return;
}


