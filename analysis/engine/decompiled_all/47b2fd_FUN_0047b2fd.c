// FUN_0047b2fd @ 0047b2fd (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047b2fd(void)

{
  int iVar1;
  
  LOAD_I = 0;
  DAT_008284e4 = 0;
LAB_0047b316:
  LOAD_I = LOAD_I + 1;
LAB_0047b327:
  load_item_header();
  if (LOAD_CODE < 3) {
    DAT_008284e4 = 1;
  }
  if (LOAD_CODE == 0x12) {
LAB_0047b3f0:
    _DAT_008284dc = (float)(&ITEM_P2)[LOAD_W];
    if ((LOAD_CODE == 0xe) && (3 < LOAD_LEN)) {
      (&ITEM_P4)[LOAD_W] = *(undefined4 *)(&DAT_01c2619c + (int)ROUND(_DAT_008284dc) * 4);
    }
    DAT_008284d8 = LOAD_I + 1;
    iVar1 = (ITEM_I - DAT_008284d8) + 1;
    if (0 < iVar1) {
      do {
        DAT_008284d4 = (&ITEM_PTR0)[DAT_008284d8];
        if (_DAT_008284dc == (float)(&ITEM_P2)[DAT_008284d4]) {
          DAT_008284e0 = (int)ROUND((float)(&ITEM_P1)[DAT_008284d4]);
          if ((DAT_008284e0 < 3) || ((LOAD_CODE != 0x12 && (DAT_008284e0 == 0x11)))) break;
          if (LOAD_CODE == DAT_008284e0) goto LAB_0047b547;
        }
        DAT_008284d8 = DAT_008284d8 + 1;
        iVar1 = iVar1 + -1;
        if (iVar1 < 1) break;
      } while( true );
    }
    goto LAB_0047b647;
  }
  if (LOAD_CODE != 0xe) goto LAB_0047b647;
  DAT_008284e0 = 0;
  if (4 < LOAD_LEN) {
    DAT_008284e0 = (int)ROUND((float)(&ITEM_P5)[LOAD_W]);
  }
  if ((7 < DAT_008284e0) && (f_0 <= (float)(&ITEM_P4)[LOAD_W])) goto LAB_0047b607;
  if (DAT_008284e4 != 0) goto LAB_0047b3f0;
  if ((DAT_008284e0 != 0) && (DAT_008284e0 == 4)) goto LAB_0047b647;
  goto LAB_0047b607;
LAB_0047b547:
  if ((LOAD_CODE == 0xe) &&
     ((4 < LOAD_LEN ||
      (((f_5 <= (float)(&ITEM_LEN)[DAT_008284d4] && (f_8 <= (float)(&ITEM_P5)[DAT_008284d4])) &&
       (f_0 <= (float)(&ITEM_P4)[DAT_008284d4])))))) {
    thunk_FUN_005857c8(&DAT_008284d8);
    goto LAB_0047b327;
  }
LAB_0047b607:
  thunk_FUN_005857c8(&LOAD_I);
  goto LAB_0047b327;
LAB_0047b647:
  if (ITEM_I <= LOAD_I) {
    return;
  }
  goto LAB_0047b316;
}


