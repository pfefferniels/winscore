// FUN_00441fb8 @ 00441fb8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00441fb8(void)

{
  int iVar1;
  
  DAT_01fbb874 = 0;
  LOAD_I = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if ((((LOAD_CODE == 5) && (DAT_01fbb860 <= LOAD_STAFF)) && (LOAD_STAFF <= DAT_01fbb864)) &&
       (((DAT_01fbb868 <= LOAD_P3 && (LOAD_P3 <= DAT_01fbb86c)) &&
        ((6 < LOAD_LEN && (*(float *)(&ITEM_P9 + LOAD_W * 4) != f_99 || LOAD_LEN < 9)))))) {
      thunk_FUN_0054c590(&ITEM_P1 + LOAD_W,&DAT_020b9440,&LOAD_LEN);
      if (LOAD_LEN < 8) {
        DAT_020b945c = f_0;
      }
      thunk_FUN_0042c51c();
      *(float *)(&ITEM_P7 + LOAD_W * 4) = P2;
      if (DAT_01fbb874 == 0) {
        DAT_01fbb874 = LOAD_I;
      }
    }
    LOAD_I = LOAD_I + 1;
  }
  DAT_020492a0 = DAT_01fbb874;
  return;
}


