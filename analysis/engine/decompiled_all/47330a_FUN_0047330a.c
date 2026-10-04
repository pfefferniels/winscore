// FUN_0047330a @ 0047330a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047330a(void)

{
  if (DAT_01be1324 == f_0) {
    thunk_FUN_0054d831("*** Nothing to RESTORE.",0x18);
  }
  else {
    DAT_00824fd8 = (int)ROUND(DAT_01be1324);
    thunk_FUN_0054c590(&DAT_01be1324,&ITEM_LEN + ITEM_WORDS,&DAT_00824fd8);
    ITEM_WORDS = DAT_00824fd8 + ITEM_WORDS;
    ITEM_I = ITEM_I + 1;
    (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
    index_items();
    P3 = (float)_DAT_01be1320;
    P2 = (float)ITEM_I;
    thunk_FUN_0058adc1(&DAT_00762188);
    DAT_0078b4e0 = 0x49;
    DAT_0078b4e4 = 0x20;
    DAT_020b8ea0 = DAT_00762184;
    DAT_020b8ea2 = DAT_00762186;
    P2 = (float)_DAT_01be1320;
    _DAT_01be1320 = 0;
    DAT_01be1324 = f_0;
  }
  return;
}


