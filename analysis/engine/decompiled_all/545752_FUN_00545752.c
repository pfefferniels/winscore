// FUN_00545752 @ 00545752 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00545752(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  DAT_0078cd30 = 1;
  DAT_0078cd34 = 1;
  ITEM_WORDS = *param_1 + ITEM_WORDS;
  DAT_0078cd38 = ITEM_WORDS + -1;
  DAT_02091d20 = 1;
  do {
    DAT_0078cd3c = (int)ROUND((float)(&ITEM_LEN)[DAT_0078cd30]);
    DAT_0078cd34 = DAT_0078cd34 + 1;
    if (DAT_01fbb79c <= DAT_0078cd34) {
      *param_1 = DAT_0078cd30 + -1;
      break;
    }
    DAT_0078cd30 = DAT_0078cd3c + DAT_0078cd30 + 1;
    (&ITEM_PTR0)[DAT_0078cd34] = DAT_0078cd30;
  } while (DAT_0078cd30 < DAT_0078cd38);
  LOAD_I = 1;
  iVar3 = DAT_0078cd34 + -1;
  DAT_0078cd40 = iVar3;
  for (; 0 < iVar3; iVar3 = iVar3 + -1) {
    load_item_header();
    if (LOAD_CODE == 0x10) {
      if ((LOAD_LEN < 0xe) || (*(float *)(&ITEM_P12 + LOAD_W * 4) == f_0)) {
        (&ITEM_P1)[LOAD_W] = f_99;
      }
    }
    else if (LOAD_CODE == 8) {
      IP2 = LOAD_STAFF;
      for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
        *(float *)(&P0 + iVar1 * 4) = f_0;
      }
      X_POS = LOAD_P3 * f_150;
      iVar1 = LOAD_LEN;
      if (LOAD_LEN < 0) {
        iVar1 = 0;
      }
      iVar5 = 1;
      iVar4 = LOAD_W;
      for (iVar2 = 1; iVar4 = iVar4 + 1, iVar2 <= iVar1; iVar2 = iVar2 + 1) {
        *(undefined4 *)(&P0 + iVar5 * 4) = (&ITEM_LEN)[iVar4];
        iVar5 = iVar5 + 1;
      }
      draw_staff();
    }
    LOAD_I = LOAD_I + 1;
  }
  return;
}


