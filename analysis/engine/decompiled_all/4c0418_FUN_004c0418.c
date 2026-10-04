// FUN_004c0418 @ 004c0418 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004c0418(int *param_1)

{
  int iVar1;
  
  iVar1 = -ITEM_I;
  *param_1 = ITEM_I;
  for (iVar1 = iVar1 / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
    LOAD_I = *param_1;
    load_item_header();
    if (LOAD_CODE == 1) {
      _DAT_0089fa18 = LOAD_P3;
      DAT_0089fa14 = *param_1;
      goto LAB_004c0497;
    }
    *param_1 = *param_1 + -1;
  }
  goto LAB_004c04e3;
  while (_DAT_0089fa18 == LOAD_P3) {
LAB_004c0497:
    DAT_0089fa14 = DAT_0089fa14 + -1;
    LOAD_I = DAT_0089fa14;
    load_item_header();
    if (LOAD_CODE != 1) break;
  }
LAB_004c04e3:
  return DAT_0089fa14 + 1;
}


