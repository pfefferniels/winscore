// FUN_0041ee39 @ 0041ee39 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041ee39(int *param_1)

{
  undefined1 *puVar1;
  undefined4 local_64;
  undefined *local_60;
  undefined4 *local_5c;
  undefined4 local_54 [8];
  undefined4 local_34;
  
  puVar1 = &stack0xfffffffc;
  _DAT_00794854 = 0x12;
  if (DAT_0079484c == 1) {
    _DAT_00794854 = 6;
  }
  if (DAT_0079484c == 2) {
    _DAT_00794854 = 0xc;
  }
  if (DAT_0079484c == 3) {
    _DAT_00794854 = 10;
  }
  local_34 = 0;
  *param_1 = *param_1 + 1;
  local_54[0] = 0;
  local_64 = 2;
  local_60 = &DAT_020b90a1;
  local_5c = &DAT_007d1d88;
  FUN_005f9240(local_54,0x784ff00,&DAT_0075f820,&local_64,&DAT_0078e810);
  FUN_005f46bc(&stack0xfffffffc,0x41ef2b);
  FUN_005f34d1(puVar1,0x41ef41);
  *param_1 = *param_1 + 2;
  (&DAT_020b8e9f)[*param_1] = 0x2f;
  return;
}


