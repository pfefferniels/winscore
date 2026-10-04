// FUN_00448179 @ 00448179 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00448179(void)

{
  DAT_02091d20 = 1;
  DAT_007fcf6c = 1;
  DAT_007fcf68 = 1;
  do {
    DAT_007fcf64 = (int)ROUND((float)(&ITEM_LEN)[DAT_007fcf6c]);
    DAT_007fcf68 = DAT_007fcf68 + 1;
    DAT_007fcf6c = DAT_007fcf64 + DAT_007fcf6c + 1;
    (&ITEM_PTR0)[DAT_007fcf68] = DAT_007fcf6c;
  } while (DAT_007fcf6c < ITEM_WORDS);
  ITEM_I = DAT_007fcf68 + -1;
  return;
}


