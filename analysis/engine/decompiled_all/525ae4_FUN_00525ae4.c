// FUN_00525ae4 @ 00525ae4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00525ae4(void)

{
  int iVar1;
  int iVar2;
  
  DAT_0094ea50 = (int)ROUND(DAT_01fb8c60);
  LOAD_I = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    load_item_header();
    if ((LOAD_CODE == 8) && (DAT_0094ea50 == LOAD_STAFF)) goto LAB_00525b92;
    LOAD_I = LOAD_I + 1;
  }
  draw_item();
  thunk_FUN_00547799(&DAT_00767dcc,&P1);
LAB_00525b92:
  DAT_01e6790c = 0;
  LOAD_I = 1;
  _DAT_0094ea4c = f_0;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    load_item_header();
    if (((LOAD_CODE == 3) && (DAT_0094ea50 == LOAD_STAFF)) && (_DAT_0094ea4c <= LOAD_P3)) {
      DAT_01e6790c = 0;
      if (4 < LOAD_LEN) {
        DAT_01e6790c = (int)ROUND((float)(&ITEM_P5)[LOAD_W]);
      }
      _DAT_0094ea4c = LOAD_P3;
    }
    LOAD_I = LOAD_I + 1;
  }
  DAT_0079484c = DAT_01e6790c;
  _DAT_0094ea48 = NPT;
  for (iVar2 = 1; iVar1 = DAT_00791480, iVar2 < 0x33; iVar2 = iVar2 + 1) {
    *(undefined4 *)(&DAT_020b943c + iVar2 * 4) = *(undefined4 *)(&P0 + iVar2 * 4);
  }
  DAT_0094ea44 = 1;
  iVar2 = ITEM_I;
  while ((0 < iVar2 &&
         (((float)(&ITEM_P1)[(&ITEM_PTR0)[DAT_0094ea44]] != f_8 ||
          (P2 != (float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_0094ea44]]))))) {
    DAT_0094ea44 = DAT_0094ea44 + 1;
    iVar2 = iVar2 + -1;
  }
  DAT_0094ea40 = DAT_00791480;
  DAT_00791480 = 0;
  DAT_00790c10 = 0;
  DAT_00791470 = 1;
  if (iVar1 == 0) {
    EDIT_ITEM = DAT_0094ea44;
    thunk_FUN_00585d20();
  }
  EDIT_ITEM = 0;
  DAT_00791480 = DAT_0094ea40;
  for (iVar2 = 1; iVar2 < 0x33; iVar2 = iVar2 + 1) {
    *(undefined4 *)(&P0 + iVar2 * 4) = *(undefined4 *)(&DAT_020b943c + iVar2 * 4);
  }
  DAT_00791470 = 0;
  if (DAT_0094ea3c != 0) {
    if (DAT_0094ea38 < 0xf) {
      P3 = f_15;
    }
    else {
      P3 = (float)DAT_0094ea38;
    }
    P4 = f_21;
    IP4 = 0x15;
    DAT_01f95cf0 = f_30;
    item_position();
    DAT_01f95ce0 = STEP;
    P20 = STEP * f_7;
    note_ledger_lines();
    P4 = f_m7;
    IP4 = -7;
    item_position();
    note_ledger_lines();
  }
  return;
}


