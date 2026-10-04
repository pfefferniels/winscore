// FUN_0054e79e @ 0054e79e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054e79e(void)

{
  int iVar1;
  int iVar2;
  
  DAT_009a2b24 = P3;
  if (P3 == f_0) {
    FUN_0054e546(&DAT_009a2b24,&DAT_009a2b20);
  }
  FUN_0054e634(&DAT_009a2b28,&DAT_009a2b1c);
  if (DAT_009a2b1c != 0) {
    if (P2 != f_0) {
      DAT_009a2b18 = P2;
    }
    DAT_009a2b04 = 1;
    DAT_009a2b14 = f_16;
    DAT_009a2b10 = f_201;
    DAT_009a2b0c = f_1002;
    DAT_009a2b08 = f_1_3;
    iVar2 = DAT_009a2b00;
    DAT_009a2b00 = ITEM_WORDS;
    iVar1 = DAT_009a2b1c;
    while (iVar1 = iVar1 + -1, ITEM_WORDS = DAT_009a2b00, 0 < iVar1) {
      FUN_0054c419(&ITEM_LEN + DAT_009a2b00,&DAT_0076960c);
      (&ITEM_LEN)[DAT_009a2b00] = f_15;
      (&ITEM_P1)[DAT_009a2b00] = f_10;
      (&ITEM_P2)[DAT_009a2b00] = DAT_009a2b24;
      (&ITEM_P3)[DAT_009a2b00] = (&DAT_009a2b24)[DAT_009a2b04];
      *(float *)(&ITEM_P7 + DAT_009a2b00 * 4) = DAT_009a2b0c;
      (&ITEM_P4)[DAT_009a2b00] = DAT_009a2b14;
      (&ITEM_P5)[DAT_009a2b00] = DAT_009a2b18;
      (&ITEM_P6)[DAT_009a2b00] = DAT_009a2b10;
      DAT_009a2b18 = DAT_009a2b18 + f_1;
      if (DAT_009a2b04 == 1) {
        (&ITEM_P3)[DAT_009a2b00] = DAT_009a2b28 + f_5;
        (&ITEM_LEN)[DAT_009a2b00] = f_7;
        ITEM_WORDS = ITEM_WORDS + 8;
      }
      else {
        *(float *)(&ITEM_P15 + DAT_009a2b00 * 4) = DAT_009a2b08;
        ITEM_WORDS = ITEM_WORDS + 0x10;
      }
      DAT_009a2b04 = DAT_009a2b04 + 1;
      iVar2 = DAT_009a2b00;
      DAT_009a2b00 = ITEM_WORDS;
    }
    DAT_009a2b00 = iVar2;
    draw_items();
  }
  return;
}


