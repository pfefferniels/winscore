// FUN_005857c8 @ 005857c8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_005857c8(int *param_1)

{
  DAT_009a9190 = (&DAT_02091d20)[*param_1];
  DAT_009a918c = (&ITEM_PTR0)[*param_1];
  if (ITEM_WORDS == DAT_009a9190) {
    ITEM_I = ITEM_I + -1;
    ITEM_WORDS = DAT_009a918c;
  }
  else {
    DAT_009a9188 = ITEM_WORDS - DAT_009a9190;
    thunk_FUN_0054c590(&ITEM_LEN + DAT_009a9190,&ITEM_LEN + DAT_009a918c,&DAT_009a9188);
    DAT_009a9188 = DAT_009a918c + DAT_009a9188;
    thunk_FUN_0049836a(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I,&DAT_009a9188);
    (&DAT_02091d20)[ITEM_I] = DAT_009a9188;
  }
  return;
}


