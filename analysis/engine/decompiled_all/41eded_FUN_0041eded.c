// FUN_0041eded @ 0041eded (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


int FUN_0041eded(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  int local_8;
  
  bVar4 = &stack0xfffffffc < (undefined1 *)0x24;
  bVar5 = &stack0x00000000 == (undefined1 *)0x28;
  local_8 = -1;
  iVar1 = 1;
  pbVar2 = param_1;
  pbVar3 = &DAT_0075f774;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar5 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar5);
  if (!bVar4) {
    iVar1 = 1;
    pbVar2 = param_1;
    pbVar3 = &DAT_0075f770;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pbVar2 < *pbVar3;
      bVar5 = *pbVar2 == *pbVar3;
      pbVar2 = pbVar2 + 1;
      pbVar3 = pbVar3 + 1;
    } while (bVar5);
    if (bVar4 || bVar5) {
      local_8 = *param_1 - 0x30;
    }
  }
  return local_8;
}


