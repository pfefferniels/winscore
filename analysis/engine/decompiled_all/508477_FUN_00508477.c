// FUN_00508477 @ 00508477 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00508477(undefined4 param_1)

{
  int iVar1;
  
  DAT_00940388 = DAT_01b9d5c4 + 1;
  if (*(float *)(&ITEM_P12 + LOAD_W * 4) != f_1) {
    DAT_00940388 = DAT_01b9d5c4 + -1;
  }
  DAT_01b9d5cc = 1;
  iVar1 = ITEM_I;
  do {
    if (iVar1 < 1) {
      return;
    }
    DAT_01b9d5d0 = (&ITEM_PTR0)[DAT_01b9d5cc];
    DAT_00940384 = (int)ROUND((float)(&ITEM_P2)[DAT_01b9d5d0]);
    if (DAT_00940388 <= DAT_00940384) {
      if (DAT_00940388 < DAT_00940384) {
        return;
      }
      if (LOAD_P3 < (float)(&ITEM_P3)[DAT_01b9d5d0]) {
        return;
      }
      if ((float)(&ITEM_P1)[DAT_01b9d5d0] == f_3) {
        DAT_00940384 = (int)ROUND((float)(&ITEM_LEN)[DAT_01b9d5d0]);
        FUN_00508616(param_1,&DAT_00940384,&ITEM_P5 + DAT_01b9d5d0);
      }
    }
    DAT_01b9d5cc = DAT_01b9d5cc + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


