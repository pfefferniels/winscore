// FUN_0042e6ab @ 0042e6ab (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0042e6ab(void)

{
  int iVar1;
  float10 in_ST0;
  
  LOAD_I = 1;
  DAT_01caf6c8 = f_m90999;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    if ((LOAD_CODE == 0xe) &&
       (((DAT_01caf6a0 == LOAD_STAFF ||
         (((3 < LOAD_LEN && (LOAD_STAFF <= DAT_01caf6a0)) &&
          (in_ST0 = ((float10)LOAD_STAFF + (float10)(float)(&ITEM_P4)[LOAD_W]) - (float10)f_1,
          (float10)DAT_01caf6a0 <= in_ST0)))) && (DAT_01caf6c8 < LOAD_P3)))) {
      DAT_01caf6c8 = LOAD_P3;
    }
    LOAD_I = LOAD_I + 1;
  }
  if (DAT_01caf6c8 != f_m90999) {
    if (DAT_020b945c == f_m1) {
      in_ST0 = (float10)DAT_01caf6c8 - (float10)f_0_6;
      DAT_01caf6c8 = (float)(in_ST0 - (float10)STEP * (float10)f_0_056);
    }
    P2 = DAT_01caf6c8;
    ffree(in_ST0);
    P1 = f_6;
    in_ST0 = (float10)FUN_0042e82d(&DAT_0075fe5c);
  }
  ffree(in_ST0);
  return;
}


