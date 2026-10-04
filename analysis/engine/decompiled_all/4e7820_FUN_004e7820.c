// FUN_004e7820 @ 004e7820 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e7820(void)

{
  int iVar1;
  
  thunk_FUN_005725fa();
  DAT_008d12d0 = 999;
  LOAD_I = 1;
  _DAT_008d12cc = f_0;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if (((LOAD_CODE == 8) && (LOAD_STAFF <= DAT_008d12d0)) &&
       (DAT_008d12d0 = LOAD_STAFF, 3 < LOAD_LEN)) {
      _DAT_008d12cc = (float)(&ITEM_P4)[LOAD_W];
    }
    LOAD_I = LOAD_I + 1;
  }
  _DAT_008d12c8 = (float)(&STAFF_STEP0)[DAT_008d12d0];
  DAT_008d12d0 = DAT_008d12d0 + -1;
  LOAD_I = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    (&ITEM_P2)[LOAD_W] = (float)(LOAD_STAFF - DAT_008d12d0);
    if ((LOAD_CODE == 8) && (3 < LOAD_LEN)) {
      _DAT_008d12c4 = (_DAT_008d12c8 / (float)(&STAFF_STEP0)[LOAD_STAFF]) * _DAT_008d12cc;
      (&ITEM_P4)[LOAD_W] = (float)(&ITEM_P4)[LOAD_W] - _DAT_008d12c4;
    }
    LOAD_I = LOAD_I + 1;
  }
  draw_items();
  return;
}


