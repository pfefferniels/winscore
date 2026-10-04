// FUN_005495d1 @ 005495d1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_005495d1(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_1c;
  int local_14;
  
  puVar2 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)&DAT_020b90a0;
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_009a1e28 = 0;
  if (*param_3 != 0) {
    local_1c = 0x200;
    DAT_009a1e28 = 1;
    do {
      if ((&DAT_020b909f)[DAT_009a1e28] == '\0') goto LAB_00549669;
      DAT_009a1e28 = DAT_009a1e28 + 1;
      local_1c = local_1c + -1;
    } while (0 < local_1c);
  }
  DAT_020b8ea0._0_1_ = 0;
LAB_00549669:
  DAT_009a1e2c = DAT_009a1e28;
  iVar1 = thunk_FUN_00596a30(&DAT_020b8ea0,&DAT_020b90a0,DAT_009a1e28,DAT_009a1e28);
  *param_3 = iVar1;
  local_14 = 0x200;
  DAT_009a1e28 = 1;
  do {
    if ((&DAT_020b8e9f)[DAT_009a1e28] == '\r') {
      DAT_009a1e2c = DAT_009a1e28;
      for (iVar1 = 0x201 - DAT_009a1e28; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&DAT_020b8e9f)[DAT_009a1e2c] = 0x20;
        DAT_009a1e2c = DAT_009a1e2c + 1;
      }
      DAT_0078b4e4 = DAT_009a1e28;
      return;
    }
    DAT_009a1e28 = DAT_009a1e28 + 1;
    local_14 = local_14 + -1;
  } while (0 < local_14);
  return;
}


