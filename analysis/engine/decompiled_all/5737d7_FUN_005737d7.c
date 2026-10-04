// FUN_005737d7 @ 005737d7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005737d7(void)

{
  if (DAT_0078b374 != 2) {
    if (((DAT_0205274c == 0) && (EDIT_ITEM != 0)) &&
       (((int)P3 <= DAT_009a889c ||
        (((DAT_009a889c <= (int)P2 || (DAT_009a88a0 < 1)) || (DAT_0078b4e4 <= DAT_009a88a0)))))) {
      DAT_0078b4e4 = 0x5a;
      P2 = DAT_01be6c54;
      thunk_FUN_0058c344();
    }
    _DAT_009a8898 = 1;
  }
  return;
}


