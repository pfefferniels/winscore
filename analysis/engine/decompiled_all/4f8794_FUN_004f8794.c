// FUN_004f8794 @ 004f8794 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004f8794(void)

{
  DAT_008f9184 = 1;
  ITEM_I = 1;
  do {
    DAT_008f9180 = (int)ROUND((float)(&ITEM_LEN)[DAT_008f9184]);
    if (DAT_008f9180 == 0) break;
    DAT_008f9184 = DAT_008f9180 + DAT_008f9184 + 1;
    ITEM_I = ITEM_I + 1;
    (&ITEM_PTR0)[ITEM_I] = DAT_008f9184;
  } while (DAT_008f9184 < ITEM_WORDS + -1);
  ITEM_WORDS = (&ITEM_PTR0)[ITEM_I];
  ITEM_I = ITEM_I + -1;
  DAT_02091d20 = 1;
  thunk_FUN_0054c590(&ITEM_P1,&DAT_01e99980,&ITEM_WORDS);
  return;
}


