// FUN_004ec885 @ 004ec885 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004ec885(int *param_1,int *param_2)

{
  int iVar1;
  
  DAT_008d16d4 = (int)ROUND(DAT_01fb8c60);
  LOAD_I = 1;
  DAT_008d16d0 = f_999;
  iVar1 = ITEM_I;
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 < 1) {
      DAT_008d16d0 = DAT_008d16d0 + f_1;
LAB_004ec9cb:
      DAT_008d16cc = ITEM_WORDS;
      (&ITEM_LEN)[ITEM_WORDS] = f_6;
      (&ITEM_P1)[DAT_008d16cc] = f_17;
      (&ITEM_P2)[DAT_008d16cc] = DAT_01fb8c60;
      (&ITEM_P3)[DAT_008d16cc] = DAT_008d16d0;
      (&ITEM_P4)[DAT_008d16cc] = f_0;
      (&ITEM_P5)[DAT_008d16cc] = (float)*param_1;
      (&ITEM_P6)[DAT_008d16cc] = (float)*param_2;
      ITEM_WORDS = ITEM_WORDS + 7;
      ITEM_I = ITEM_I + 1;
      (&ITEM_PTR0)[ITEM_I] = DAT_008d16cc;
      return;
    }
    load_item_header();
    if (DAT_008d16d4 == LOAD_STAFF) {
      if (LOAD_P3 < DAT_008d16d0) {
        DAT_008d16d0 = LOAD_P3;
      }
      if (LOAD_CODE == 3) {
        DAT_008d16d0 = LOAD_P3;
        if (f_3 <= (float)(&ITEM_LEN)[(&DAT_02091d20)[LOAD_I]]) {
          DAT_008d16d0 = ((float)(&ITEM_P3)[(&DAT_02091d20)[LOAD_I]] - LOAD_P3) / f_2 + LOAD_P3;
        }
        goto LAB_004ec9cb;
      }
    }
    LOAD_I = LOAD_I + 1;
  } while( true );
}


