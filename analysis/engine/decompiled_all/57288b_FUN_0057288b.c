// FUN_0057288b @ 0057288b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057288b(void)

{
  if (DAT_0078b4e4 == 0x4e) {
    if (DAT_020b8ea3 == 'O') {
      if (((NPT == _DAT_01c4ef50) && (ITEM_I == DAT_01c4ef48)) && (ITEM_WORDS == _DAT_01c4ef54)) {
        DAT_01c4ef48 = 0;
        ITEM_I = DAT_01c4ef44;
        ITEM_WORDS = (&DAT_02091d20)[DAT_01c4ef44];
        NPT = (&DAT_02035a00)[DAT_01c4ef44];
      }
      else {
        thunk_FUN_0054d831("**** Nothing to UNDO or changes made ****",0x29);
      }
    }
    else {
      if (DAT_01c26194 != 0) {
        DAT_009a87dc = DAT_01c26194;
        if (DAT_01c26194 < 0) {
          DAT_009a87dc = -DAT_01c26194;
        }
        thunk_FUN_0054c590(&DAT_01c25fa0,&ITEM_LEN + ITEM_WORDS,&DAT_009a87dc);
        ITEM_WORDS = DAT_009a87dc + ITEM_WORDS;
        ITEM_I = ITEM_I + 1;
        (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
        P2 = (float)ITEM_I;
        if (0 < DAT_01c26194) {
          P3 = (float)_DAT_01c26198;
          thunk_FUN_0058adc1(&DAT_0076a584);
          P2 = (float)_DAT_01c26198;
        }
        if (DAT_01c26194 < 0) {
          draw_items();
          P2 = (float)ITEM_I;
        }
        DAT_0078b4e0 = 0x49;
        DAT_0078b4e4 = 0x20;
        DAT_01c26194 = 0;
        DAT_020b8ea0 = DAT_0076a580;
        DAT_020b8ea2 = DAT_0076a582;
        return;
      }
      thunk_FUN_0054d831("*** Nothing to UNDELETE.",0x19);
    }
  }
  DAT_0078b4e4 = 0xffffffff;
  return;
}


