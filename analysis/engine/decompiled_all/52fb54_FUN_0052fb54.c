// FUN_0052fb54 @ 0052fb54 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0052fb54(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  LOAD_I = 1;
  iVar1 = ITEM_I;
  do {
    if (iVar1 < 1) {
      return;
    }
    load_item_header();
    if (LOAD_I == 1) {
LAB_0052fbe5:
      DAT_0099a110 = LOAD_CODE;
      DAT_020527e4 = LOAD_P3;
    }
    else if (((DAT_020527e4 != LOAD_P3) && (LOAD_CODE == 1)) && (LOAD_STAFF == *param_1)) {
      if ((DAT_0099a110 == 1) && (LOAD_P3 - DAT_020527e4 < f_3)) {
        thunk_FUN_004b80b7(param_1,param_1,param_2,param_3);
        return;
      }
      goto LAB_0052fbe5;
    }
    LOAD_I = LOAD_I + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


