// FUN_0055e50b @ 0055e50b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0055e50b(void)

{
  int iVar1;
  
  DAT_009a6f80 = 1;
  do {
    while( true ) {
      DAT_009a6f7c = (int)ROUND((float)(&ITEM_LEN)[DAT_009a6f80] + f_1);
      if ((float)(&ITEM_P1)[DAT_009a6f80] != f_13) break;
      DAT_009a6f78 = DAT_009a6f80;
      for (iVar1 = (ITEM_WORDS - DAT_009a6f80) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_LEN)[DAT_009a6f78] = (&ITEM_LEN)[DAT_009a6f7c + DAT_009a6f78];
        DAT_009a6f78 = DAT_009a6f78 + 1;
      }
      ITEM_I = ITEM_I + -1;
      ITEM_WORDS = ITEM_WORDS - DAT_009a6f7c;
    }
    DAT_009a6f80 = DAT_009a6f7c + DAT_009a6f80;
  } while (DAT_009a6f80 < ITEM_WORDS);
  return;
}


