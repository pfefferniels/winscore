// FUN_0054d90a @ 0054d90a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054d90a(void)

{
  DAT_009a2aa0 = 1;
  VEC_N = 1;
  DAT_02035a00 = 1;
  do {
    DAT_009a2a9c = (&ITEM_PTR0)[DAT_009a2aa0];
    _DAT_009a2a98 = (int)ROUND((float)(&ITEM_LEN)[DAT_009a2a9c]);
    NPT = 1;
    if (((float)(&ITEM_P1)[DAT_009a2a9c] == f_16) &&
       (f_1 < *(float *)(&ITEM_P12 + DAT_009a2a9c * 4))) {
      _DAT_009a2a98 = 0xc;
    }
    FUN_0054c419(&P1,&DAT_007692b8);
    FUN_0054c590(&ITEM_P1 + DAT_009a2a9c,&P1,&DAT_009a2a98);
    draw_item();
    flush_points();
    DAT_009a2aa0 = DAT_009a2aa0 + 1;
    *(int *)(&DAT_020359fc + DAT_009a2aa0 * 4) = VEC_N;
  } while (DAT_009a2aa0 <= ITEM_I);
  NPT = 1;
  return;
}


