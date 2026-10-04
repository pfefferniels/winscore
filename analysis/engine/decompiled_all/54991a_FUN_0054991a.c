// FUN_0054991a @ 0054991a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054991a(undefined4 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  int local_1c;
  int local_14;
  
  bVar6 = &stack0xfffffffc < (undefined1 *)0x3c;
  bVar7 = &stack0x00000000 == (undefined1 *)0x40;
  puVar4 = (undefined4 *)&DAT_020b90a0;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *param_1;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  }
  local_1c = 0x200;
  DAT_009a204c = 0x200;
  do {
    iVar2 = 1;
    pbVar3 = &DAT_020b8e9f + DAT_009a204c;
    pbVar5 = &DAT_00769150;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pbVar3 < *pbVar5;
      bVar7 = *pbVar3 == *pbVar5;
      pbVar3 = pbVar3 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar7);
    if (!bVar6 && !bVar7) break;
    DAT_009a204c = DAT_009a204c + -1;
    local_1c = local_1c + -1;
    bVar6 = false;
    bVar7 = local_1c == 0;
  } while (0 < local_1c);
  puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_009a204c);
  DAT_009a204c = DAT_009a204c + 1;
  *puVar1 = 0;
  DAT_009a2048 = DAT_009a204c;
  _DAT_009a2044 = thunk_FUN_00596cc0(&DAT_020b8ea0,&DAT_020b90a0,DAT_009a204c,DAT_009a204c);
  local_14 = 0x200;
  DAT_009a204c = 1;
  do {
    if ((&DAT_020b8e9f)[DAT_009a204c] == '\r') {
      DAT_009a2050 = DAT_009a204c;
      for (iVar2 = 0x201 - DAT_009a204c; 0 < iVar2; iVar2 = iVar2 + -1) {
        (&DAT_020b8e9f)[DAT_009a2050] = 0x20;
        DAT_009a2050 = DAT_009a2050 + 1;
      }
      return;
    }
    DAT_009a204c = DAT_009a204c + 1;
    local_14 = local_14 + -1;
  } while (0 < local_14);
  return;
}


