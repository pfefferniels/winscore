// FUN_004a3172 @ 004a3172 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a3172(void)

{
  int iVar1;
  
  thunk_FUN_00597b60(0xffffffff);
  DAT_00838bc8 = (int)ROUND(P1);
  DAT_00838bc4 = (int)ROUND(P4);
  DAT_00838bc0 = P2;
  DAT_00838bbc = P3;
  if (ITEM_I != 0) {
    if ((DAT_02052740 < 1) || (DAT_0078b378 != 0)) {
      VEC_LAST_PEN = 0;
      VEC_N = 1;
      DAT_00791474 = 0;
      if (DAT_00795448 == 0) {
        *DAT_01fbb844 = 0;
      }
      DAT_0078b6a0 = DAT_00791444;
      _DAT_00838bb8 = OUTPUT_MODE;
      ITEM_COUNT_SAVE = ITEM_I;
      ITEM_I = 1;
      do {
        NPT = 1;
        DAT_00838bb4 = (&ITEM_PTR0)[ITEM_I];
        DAT_00838bb0 = (int)ROUND((float)(&ITEM_LEN)[DAT_00838bb4]);
        if ((((float)(&ITEM_P1)[DAT_00838bb4] == f_16) &&
            (f_1 < *(float *)(&ITEM_P12 + DAT_00838bb4 * 4))) &&
           (DAT_00838bb0 = 0xc, *(float *)(&ITEM_P14 + DAT_00838bb4 * 4) == f_m1)) {
          DAT_00838bb0 = 0x10;
        }
        iVar1 = 0x2d;
        DAT_00838bac = 1;
        do {
          if (DAT_00838bb0 < DAT_00838bac) {
            *(float *)(&P0 + DAT_00838bac * 4) = f_0;
          }
          else {
            DAT_00838bb4 = DAT_00838bb4 + 1;
            *(undefined4 *)(&P0 + DAT_00838bac * 4) = (&ITEM_LEN)[DAT_00838bb4];
          }
          DAT_00838bac = DAT_00838bac + 1;
          iVar1 = iVar1 + -1;
        } while (0 < iVar1);
        if (P1 == f_13) {
          _DAT_00838ba8 = f_0;
        }
        else {
          (&DAT_020a55a0)[ITEM_I] = *(undefined4 *)(&DAT_020a559c + ITEM_I * 4);
          IP2 = (int)ROUND(P2);
          if (((P3 <= DAT_00838bbc) && (DAT_00838bc0 <= P3)) &&
             ((DAT_00838bc8 <= IP2 && (IP2 <= DAT_00838bc4)))) {
            DAT_020527ec = ITEM_I;
          }
          draw_item();
          DAT_01e66cb0 = (uint)(ITEM_I == DAT_020527ec);
          if (1 < NPT) {
            flush_points();
          }
          DAT_01e66cb0 = 0;
          COLOR = 0;
          DAT_020527ec = 0;
          DAT_01b11790 = 0;
        }
        ITEM_I = ITEM_I + 1;
        *(int *)(&DAT_020359fc + ITEM_I * 4) = VEC_N;
        NPT = 1;
      } while (ITEM_I <= ITEM_COUNT_SAVE);
      ITEM_I = ITEM_COUNT_SAVE;
      *DAT_01fbb7c0 = VEC_N + -1;
      P1 = (float)DAT_00838bc8;
      P4 = (float)DAT_00838bc4;
      P2 = DAT_00838bc0;
      P3 = DAT_00838bbc;
      P5 = f_0;
      P6 = f_0;
      DAT_01a14950 = DAT_01e66ca0;
      DAT_01a1494c = DAT_01e66ca4;
      DAT_01a14948 = DAT_01e66ca8;
      DAT_01a14944 = DAT_01e66cac;
      if (DAT_0078d890 != 0) {
        draw_page_frame();
      }
      thunk_FUN_0041b6c4(&DAT_007637b4);
      P1 = (float)DAT_00838bc8;
      P4 = (float)DAT_00838bc4;
      P2 = DAT_00838bc0;
      P3 = DAT_00838bbc;
    }
    else {
      index_items();
    }
  }
  return;
}


