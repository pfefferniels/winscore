// FUN_0042e94d @ 0042e94d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0042e94d(void)

{
  int iVar1;
  
  LOAD_I = 1;
  DAT_01caf6c8 = f_90999;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if (((LOAD_P3 <= DAT_01caf6c8) && (LOAD_CODE == 1)) && (DAT_01caf6a0 == LOAD_STAFF)) {
      DAT_01caf6c8 = LOAD_P3;
    }
    LOAD_I = LOAD_I + 1;
  }
  if (DAT_01caf6c8 != f_90999) {
    LOAD_P3 = STEP * f_0_2;
    if ((DAT_020b945c < f_m1) && (LOAD_P3 = STEP * f_0_38, LOAD_P3 < f_6)) {
      LOAD_P3 = f_6;
    }
    P2 = DAT_01caf6c8 - LOAD_P3;
    P1 = f_3;
    FUN_0042e82d(&DAT_0075fe6c);
  }
  return;
}


