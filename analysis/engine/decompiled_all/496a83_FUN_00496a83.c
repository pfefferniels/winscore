// FUN_00496a83 @ 00496a83 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00496a83(void)

{
  (&ITEM_LEN)[DAT_01b12c84] = (float)(DAT_0078de00 + -1) + (float)(&ITEM_LEN)[DAT_01b12c84];
  if (DAT_0078d894 < (float)(&ITEM_LEN)[DAT_01b12c84]) {
    (&ITEM_LEN)[DAT_01b12c84] = DAT_0078d894;
    DAT_01b12c88 = 0xffffffff;
  }
  return;
}


