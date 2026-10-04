// FUN_005734d7 @ 005734d7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005734d7(void)

{
  int iVar1;
  
  DAT_020b8ea2 = DAT_020b90a2;
  if ((DAT_020b90a2 != 'I') && (DAT_020b90a2 != 'C')) {
    if (DAT_020b90a2 == 'X') {
      ITEM_WORDS = ITEM_WORDS + -7;
      thunk_FUN_0054c590(&ITEM_P8,&ITEM_P1,&ITEM_WORDS);
      DAT_01e6794c = 2;
      iVar1 = ITEM_I + -2;
      ITEM_I = ITEM_I + -1;
      for (; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_PTR0)[DAT_01e6794c] = (&DAT_02091d20)[DAT_01e6794c] + -7;
        DAT_01e6794c = DAT_01e6794c + 1;
      }
    }
    else {
      if (ITEM_P2 != f_13) {
        DAT_01e6794c = ITEM_WORDS;
        for (iVar1 = -ITEM_WORDS / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
          *(undefined4 *)(&ITEM_P7 + DAT_01e6794c * 4) = (&ITEM_LEN)[DAT_01e6794c];
          DAT_01e6794c = DAT_01e6794c + -1;
        }
        ITEM_WORDS = ITEM_WORDS + 7;
        DAT_01e6794c = ITEM_I + 1;
        ITEM_I = DAT_01e6794c;
        for (iVar1 = -DAT_01e6794c / -1; ITEM_P2 = f_13, 0 < iVar1; iVar1 = iVar1 + -1) {
          (&DAT_02091d20)[DAT_01e6794c] = (&ITEM_PTR0)[DAT_01e6794c] + 7;
          DAT_01e6794c = DAT_01e6794c + -1;
        }
      }
      if (P2 == f_0) {
        P2 = f_1;
      }
      IP2 = (int)ROUND(P2);
      ITEM_P3 = P2;
      ITEM_P4 = f_0;
      _ITEM_P7 = f_25 / (float)(&STAFF_STEP0)[IP2];
      DAT_009a8894 = f_1 / _ITEM_P7;
      ITEM_P5 = f_11 - f_11 / DAT_009a8894;
      ITEM_P6 = f_1300;
      ITEM_P1 = f_6;
    }
    draw_items();
  }
  return;
}


