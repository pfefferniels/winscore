// FUN_0044236f @ 0044236f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0044236f(void)

{
  int iVar1;
  
  if (DAT_020527a0 == 0) {
    DAT_020527a0 = ITEM_WORDS;
  }
  DAT_007f7e10 = 1;
  DAT_020492a0 = ITEM_I;
  for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_007f7e0c = (&DAT_020492a4)[DAT_007f7e10];
    if (DAT_007f7e0c < 0) {
      (&DAT_020492a4)[DAT_007f7e10] = (DAT_007f7e00 + DAT_007f7e0c) - DAT_007f7e08;
    }
    else {
      DAT_007f7e08 = DAT_007f7e0c + -3;
      DAT_007f7e04 = (int)ROUND((float)(&ITEM_LEN)[DAT_007f7e08] + f_1);
      thunk_FUN_0054c590(&ITEM_LEN + DAT_007f7e08,&ITEM_LEN + ITEM_WORDS,&DAT_007f7e04);
      DAT_007f7e08 = ITEM_WORDS + 3;
      (&DAT_020492a4)[DAT_007f7e10] = DAT_007f7e08;
      ITEM_WORDS = DAT_007f7e04 + ITEM_WORDS;
      DAT_007f7e00 = DAT_007f7e0c;
    }
    DAT_007f7e10 = DAT_007f7e10 + 1;
  }
  return;
}


