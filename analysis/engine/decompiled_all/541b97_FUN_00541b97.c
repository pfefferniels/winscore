// FUN_00541b97 @ 00541b97 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00541b97(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00541c6b(param_1,param_2,param_3,param_4);
  LOAD_I = 1;
  do {
    load_item_header();
    if (*param_2 < LOAD_STAFF) {
      return;
    }
    if (LOAD_CODE == 99) {
      _DAT_0099ea04 = ITEM_WORDS;
      _DAT_0099ea00 = (&ITEM_LEN)[LOAD_W];
      FUN_0054037e(&LOAD_I);
      LOAD_I = LOAD_I + -1;
      _DAT_0099e9fc = 1;
    }
    LOAD_I = LOAD_I + 1;
  } while (LOAD_I <= ITEM_I);
  return;
}


