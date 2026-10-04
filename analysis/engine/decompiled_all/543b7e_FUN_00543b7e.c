// FUN_00543b7e @ 00543b7e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00543b7e(void)

{
  int iVar1;
  int iVar2;
  
  DAT_0099f138 = 0;
  DAT_0099f134 = 999;
  thunk_FUN_0054e546(&DAT_0099f130,&DAT_0099f12c);
  DAT_0099f138 = (int)ROUND(_DAT_0099f130);
  DAT_0099f134 = (int)ROUND(_DAT_0099f12c);
  DAT_0099f128 = DAT_0099f138 - DAT_0099f134;
  DAT_0099f120 = DAT_0099f138;
  DAT_0099f124 = DAT_0099f138;
  for (iVar1 = (DAT_0099f134 - DAT_0099f138) / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
    LOAD_I = 1;
    for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
      load_item_header();
      if (DAT_0099f138 == LOAD_STAFF) {
        (&ITEM_P2)[LOAD_W] = (float)(DAT_0099f128 + DAT_0099f138);
      }
      LOAD_I = LOAD_I + 1;
    }
    DAT_0099f138 = DAT_0099f138 + -1;
    DAT_0099f128 = DAT_0099f128 + -1;
    DAT_0099f120 = DAT_0099f120 + -1;
  }
  draw_items();
  return;
}


