// load_item_header @ 00547c32 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void load_item_header(void)

{
  LOAD_W = (&ITEM_PTR0)[LOAD_I];
  LOAD_LEN = (int)ROUND((float)(&ITEM_LEN)[LOAD_W]);
  LOAD_CODE = (int)ROUND((float)(&ITEM_P1)[LOAD_W]);
  LOAD_STAFF = (int)ROUND((float)(&ITEM_P2)[LOAD_W]);
  LOAD_P3 = f_0;
  if (2 < (int)ROUND((float)(&ITEM_LEN)[LOAD_W])) {
    LOAD_P3 = (float)(&ITEM_P3)[LOAD_W];
  }
  return;
}


