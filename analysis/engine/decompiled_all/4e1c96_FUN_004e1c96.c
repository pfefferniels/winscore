// FUN_004e1c96 @ 004e1c96 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004e1c96(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  DAT_008c8858 = (int)ROUND(DAT_01fb8c60);
  DAT_01b12c90 = 0;
  LOAD_I = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    load_item_header();
    if (((LOAD_CODE == 0x11) && (LOAD_P3 <= DAT_01e67914)) && (DAT_008c8858 == LOAD_STAFF)) {
      DAT_01b12c90 = (int)ROUND((float)(&ITEM_P5)[LOAD_W]);
      if ((LOAD_LEN < 5) || (DAT_01b12c90 == 0)) {
        DAT_01b12c90 = 1;
      }
      iVar3 = DAT_01b12c90;
      if (DAT_01b12c90 < 0) {
        iVar3 = -DAT_01b12c90;
      }
      if (99 < iVar3) {
        DAT_01b12c90 = 0;
      }
      iVar3 = DAT_01b12c90;
      for (iVar1 = 1; iVar1 < 0x65; iVar1 = iVar1 + 1) {
        *(int *)(&DAT_007cba1c + iVar1 * 4) = iVar3;
      }
    }
    LOAD_I = LOAD_I + 1;
  }
  return;
}


