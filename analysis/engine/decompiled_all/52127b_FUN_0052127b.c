// FUN_0052127b @ 0052127b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052127b(void)

{
  int iVar1;
  int iVar2;
  
  _DAT_0094e43c = ITEM_I;
  DAT_0078b4ec = 0;
  DAT_0078b4e4 = 0x58;
  thunk_FUN_004f7808();
  DAT_01aad7d0 = DAT_01aad7c8;
  DAT_01aad7ec = DAT_01aad7cc;
  if (DAT_01aad7cc < DAT_01aad7c8) {
    thunk_FUN_0054c68f(&DAT_01aad7d0,&DAT_01aad7ec);
  }
  DAT_0078b4e0 = 1;
  DAT_01aad7f8 = ITEM_I;
  iVar2 = ITEM_I;
  do {
    if (iVar2 < 1) {
      return;
    }
    LOAD_I = DAT_0078b4e0;
    load_item_header();
    if (DAT_01aad7d0 == LOAD_STAFF) {
      DAT_01aad7dc = 1;
      for (iVar1 = DAT_01aad7f8; 0 < iVar1; iVar1 = iVar1 + -1) {
        LOAD_I = DAT_01aad7dc;
        load_item_header();
        if (DAT_01aad7d0 == LOAD_STAFF) {
          if (LOAD_CODE < 3) {
            return;
          }
          if (LOAD_CODE == 0x12) {
            LOAD_I = 1;
            LOAD_CODE = 0x12;
            DAT_01a1feb0 = LOAD_LEN;
            DAT_01aad7e0 = LOAD_W;
            iVar2 = DAT_01aad7f8;
            goto joined_r0x00521418;
          }
        }
        DAT_01aad7dc = DAT_01aad7dc + 1;
      }
    }
    DAT_0078b4e0 = DAT_0078b4e0 + 1;
    iVar2 = iVar2 + -1;
  } while( true );
joined_r0x00521418:
  if (iVar2 < 1) {
LAB_005214c3:
    DAT_01a1feac = 0;
    DAT_01fbb87c = ITEM_I;
    for (iVar2 = DAT_01aad7c0 + 1; ITEM_I = DAT_01fbb87c, 0 < iVar2; iVar2 = iVar2 + -1) {
      (&ITEM_LEN)[ITEM_WORDS] = (float)DAT_01a1feb0;
      (&ITEM_P1)[ITEM_WORDS] = f_18;
      (&ITEM_P2)[ITEM_WORDS] = (float)(DAT_01a1feac + DAT_01aad7ec);
      (&ITEM_P3)[ITEM_WORDS] = f_199;
      DAT_01aad7e8 = 4;
      for (iVar1 = DAT_01a1feb0 + -3; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_LEN)[DAT_01aad7e8 + ITEM_WORDS] = (&ITEM_LEN)[DAT_01aad7e8 + DAT_01aad7e0];
        DAT_01aad7e8 = DAT_01aad7e8 + 1;
      }
      ITEM_I = ITEM_I + 1;
      ITEM_WORDS = DAT_01a1feb0 + ITEM_WORDS + 1;
      (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
      DAT_01a1feac = DAT_01a1feac + 1;
      DAT_01fbb87c = ITEM_I;
    }
    DAT_0078b4ec = 0;
    DAT_0078b4e4 = 0x58;
    thunk_FUN_004f7808();
    return;
  }
  load_item_header();
  if (((f_199 <= LOAD_P3) && (LOAD_CODE == 0xe)) && (DAT_01aad7ec == LOAD_STAFF)) {
    if ((LOAD_LEN < 5) || ((float)(&ITEM_P5)[LOAD_W] != f_2)) {
      (&ITEM_P3)[LOAD_W] = f_198;
    }
    goto LAB_005214c3;
  }
  LOAD_I = LOAD_I + 1;
  iVar2 = iVar2 + -1;
  goto joined_r0x00521418;
}


