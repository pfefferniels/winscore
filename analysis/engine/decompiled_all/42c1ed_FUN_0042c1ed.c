// FUN_0042c1ed @ 0042c1ed (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0042c1ed(void)

{
  int iVar1;
  
  thunk_FUN_005725fa();
  DAT_007f1350 = 0;
  DAT_007f134c = (int)ROUND(P2);
  LOAD_I = 1;
  DAT_020b9440 = f_4;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if (((((LOAD_CODE == 4) && (LOAD_STAFF == DAT_007f134c || MAX_STAFF < DAT_007f134c)) &&
         (5 < LOAD_LEN)) && ((float)(&ITEM_P4)[LOAD_W] == (float)(&ITEM_P5)[LOAD_W])) &&
       ((LOAD_LEN < 0xb || (LOAD_LEN == 0xe)))) {
      DAT_020b9458 = f_0;
      if (6 < LOAD_LEN) {
        DAT_020b9458 = *(float *)(&ITEM_P7 + LOAD_W * 4);
      }
      DAT_020b944c = (&ITEM_P4)[LOAD_W];
      DAT_020b9444 = (float)LOAD_STAFF;
      DAT_020b9448 = LOAD_P3;
      if (0xd < LOAD_LEN) {
        DAT_020b9474 = *(float *)(&ITEM_P14 + LOAD_W * 4);
      }
      if ((DAT_0078b4a0 != 0) && (EDIT_ITEM == 0)) {
        DAT_020b9474 = f_0;
      }
      if ((DAT_020b9458 != f_0) && (DAT_0078b4a0 != 0)) {
        if (LOAD_LEN < 0xe) {
          thunk_FUN_005239c9(&LOAD_I,&DAT_0075fd5c);
        }
        *(float *)(&ITEM_P14 + LOAD_W * 4) = DAT_020b9474;
      }
      FUN_0042bab0();
      if (DAT_01cafaac + DAT_01cafab0 != 0) {
        DAT_007f1350 = 1;
        (&ITEM_P3)[LOAD_W] = P2;
        (&ITEM_P4)[LOAD_W] = P4;
        (&ITEM_P5)[LOAD_W] = P4;
        (&ITEM_P6)[LOAD_W] = P8;
        if ((DAT_020b9458 != f_0) && (6 < LOAD_LEN)) {
          *(float *)(&ITEM_P8 + LOAD_W * 4) = P10;
          if (LOAD_LEN < 9) {
            thunk_FUN_005239c9(&LOAD_I,&f_9);
          }
          *(float *)(&ITEM_P9 + LOAD_W * 4) = P12;
          DAT_007f1350 = 1;
        }
      }
    }
    LOAD_I = LOAD_I + 1;
  }
  if (DAT_007f1350 != 0) {
    draw_items();
  }
  return;
}


