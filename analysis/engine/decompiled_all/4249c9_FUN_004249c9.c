// FUN_004249c9 @ 004249c9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004249c9(int *param_1)

{
  float10 fVar1;
  undefined4 local_34 [3];
  int local_28;
  
  DAT_007d2e8c = (&ITEM_PTR0)[*param_1];
  local_28 = DAT_007d2e8c * 4;
  local_34[0] = (&ITEM_P4)[DAT_007d2e8c];
  fVar1 = (float10)FUN_005ff874(local_34,&DAT_0075f978);
  *(float *)((int)&ITEM_P4 + local_28) = (float)fVar1;
  (&ITEM_P6)[DAT_007d2e8c] = f_0;
  *(float *)(&ITEM_P9 + DAT_007d2e8c * 4) = f_0;
  *(float *)(&ITEM_P8 + DAT_007d2e8c * 4) = f_0;
  if ((float)(&ITEM_P1)[DAT_007d2e8c] == f_2) {
    (&ITEM_P5)[DAT_007d2e8c] = f_0;
  }
  _DAT_007d2e88 = *param_1;
  thunk_FUN_004ddb6e(&DAT_007d2e88);
  return;
}


