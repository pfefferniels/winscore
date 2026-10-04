// FUN_0042e82d @ 0042e82d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0042e82d(int *param_1)

{
  int iVar1;
  
  DAT_01caf6c4 = *(float *)(&DAT_020b943c + *param_1 * 4);
  LOAD_I = 1;
  DAT_01caf6c8 = f_99999;
  DAT_01caf6dc = f_0;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if (((LOAD_CODE == 1) && (DAT_01caf6a0 == LOAD_STAFF)) &&
       (DAT_01caf6d8 = ABS(DAT_01caf6c4 - LOAD_P3), DAT_01caf6d8 <= DAT_01caf6c8)) {
      DAT_01caf6dc = LOAD_P3;
      DAT_01caf6c8 = DAT_01caf6d8;
    }
    LOAD_I = LOAD_I + 1;
  }
  if (DAT_01caf6dc != f_0) {
    P3 = (float)*param_1;
    P4 = DAT_01caf6dc;
  }
  return;
}


