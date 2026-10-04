// FUN_00449b86 @ 00449b86 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00449b86(void)

{
  int iVar1;
  
  _DAT_007fdf34 = 1;
  _DAT_01fbb820 = 0;
  *DAT_01fbb844 = 0;
  DAT_00790c10 = 0;
  if ((P13 == f_0) && (P1 == f_11 || P1 == f_15)) {
    if (EDIT_ITEM == 0) {
      P13 = f_1;
    }
    draw_item();
    if (IP13 == 99) {
      return;
    }
  }
  iVar1 = 0x2d;
  DAT_02091d04 = 0x2d;
  do {
    if (*(float *)(&P0 + DAT_02091d04 * 4) != f_0) break;
    DAT_02091d04 = DAT_02091d04 + -1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  if (DAT_02091d04 < 3) {
    DAT_02091d04 = 3;
  }
  if ((P1 == f_15) || (P1 == f_11)) {
    DAT_02091d04 = 0x19;
  }
  thunk_FUN_00547799(&DAT_02091d04,&P1);
  if (EDIT_ITEM == 0) {
    thunk_FUN_0054e546(&DAT_007fdf30,&DAT_007fdf2c);
    DAT_00791470 = 0;
    if (P2 <= _DAT_007fdf2c) {
      DAT_00791470 = 0xffffffff;
    }
    if (_DAT_007fdf30 <= P2) {
      DAT_00791470 = 1;
    }
    draw_items();
  }
  else {
    thunk_FUN_00549b5b();
  }
  _DAT_007fdf1c = (int)ROUND(P2);
  return;
}


