// FUN_0048f5a3 @ 0048f5a3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0048f5a3(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  int local_14;
  
  bVar6 = &stack0xfffffffc < (undefined1 *)0x34;
  local_14 = 0x200;
  DAT_0082981c = 1;
  do {
    iVar3 = 1;
    pbVar4 = &DAT_020b8e9f + DAT_0082981c;
    pbVar5 = &DAT_00762d0c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar2 = *pbVar5;
      bVar1 = *pbVar4;
      bVar6 = bVar1 < bVar2;
      pbVar4 = pbVar4 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar1 == bVar2);
    if (bVar6) {
      DAT_00829818 = DAT_0082981c;
      for (iVar3 = 0x201 - DAT_0082981c; 0 < iVar3; iVar3 = iVar3 + -1) {
        (&DAT_020b8e9f)[DAT_00829818] = 0x20;
        DAT_00829818 = DAT_00829818 + 1;
      }
      return;
    }
    DAT_0082981c = DAT_0082981c + 1;
    local_14 = local_14 + -1;
    bVar6 = false;
    if (local_14 < 1) {
      return;
    }
  } while( true );
}


