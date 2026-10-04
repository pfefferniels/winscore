// index_items @ 00548981 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void index_items(void)

{
  DAT_0099f958 = 1;
  _DAT_0099f954 = 0;
  ITEM_I = 1;
  do {
    DAT_0099f950 = (int)ROUND((float)(&ITEM_LEN)[DAT_0099f958]);
    if (DAT_0099f950 == 0) break;
    DAT_0099f958 = DAT_0099f950 + DAT_0099f958 + 1;
    ITEM_I = ITEM_I + 1;
    (&ITEM_PTR0)[ITEM_I] = DAT_0099f958;
  } while (DAT_0099f958 < ITEM_WORDS + -1);
  ITEM_WORDS = (&ITEM_PTR0)[ITEM_I];
  ITEM_I = ITEM_I + -1;
  return;
}


