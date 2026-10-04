// FUN_0054cc83 @ 0054cc83 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054cc83(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_84 [20];
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_28 [9];
  
  if (DAT_02052748 != DAT_02052740) {
    local_28[0] = 0;
    local_34 = 0x50;
    local_30 = param_1;
    FUN_005fdbd0(local_28,DAT_02052740,0x784ff00,&DAT_007694b4,&local_34,&DAT_007978e4);
  }
  puVar2 = local_84;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  _DAT_009a23b0 = FUN_005ff950(local_84,0x50);
  thunk_FUN_00518b3f(&DAT_009a23b0);
  return;
}


