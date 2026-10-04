// FUN_00410400 @ 00410400 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00410400(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined *local_34;
  undefined4 *local_30;
  undefined4 local_2c [8];
  undefined4 local_c;
  
  if (*param_1 == 1) {
    _DAT_007caeb4 = f_0;
  }
  *param_1 = 2;
  DAT_007caeb0 = (&ITEM_PTR0)[EDIT_ITEM];
  DAT_007caeac = (float)(&ITEM_P3)[DAT_007caeb0];
  if (_DAT_007caea8 == DAT_007caeac) {
    local_c = 0;
  }
  else {
    _DAT_007caeb4 = _DAT_007caeb4 + *(float *)(&ITEM_P7 + DAT_007caeb0 * 4);
    _DAT_007caea8 = DAT_007caeac;
  }
  local_30 = &ITEM_P1 + DAT_007caeb0;
  local_2c[0] = 0;
  local_3c = 0x11;
  local_38 = &DAT_009ae2bc;
  local_34 = (undefined *)0x4;
  FUN_005f34f0(local_2c,0x784ff00,&DAT_0075f30c,&local_3c,&DAT_0078b128);
  local_30 = (undefined4 *)(&ITEM_P7 + DAT_007caeb0 * 4);
  local_34 = (undefined *)0x4;
  FUN_005f3960(local_2c,&DAT_0075f308,&local_34);
  local_34 = &DAT_007caeb4;
  FUN_005f3960(local_2c,&DAT_0075f300,&local_34);
  puVar2 = &DAT_009ae2bc;
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


