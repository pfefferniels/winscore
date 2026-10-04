// FUN_00450bb7 @ 00450bb7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00450bb7(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  undefined1 *puVar9;
  int local_18;
  
  puVar9 = &stack0xfffffffc;
  local_18 = 0x80;
  DAT_007fe8dc = 1;
  do {
    if (((&DAT_020b8e9f)[DAT_007fe8dc] == '\r') || ((&DAT_020b8e9f)[DAT_007fe8dc] == ' ')) break;
    DAT_007fe8dc = DAT_007fe8dc + 1;
    local_18 = local_18 + -1;
  } while (0 < local_18);
  DAT_007fe8d8 = 0;
  FUN_005f34d1(&stack0xfffffffc,0x450c3e);
  DAT_007fe8d4 = DAT_007fe8dc + 1;
  iVar6 = 0x81 - DAT_007fe8d4;
  *(int *)(puVar9 + -0xc) = iVar6;
  do {
    if (iVar6 < 1) {
LAB_00450ca2:
      iVar6 = 0x81 - DAT_007fe8d4;
      DAT_007fe8dc = DAT_007fe8d4;
      iVar3 = DAT_007fe8d8;
      do {
        if (iVar6 < 1) {
          DAT_007fe8d8 = iVar3;
          return;
        }
        bVar8 = false;
        iVar4 = 1;
        pbVar5 = &DAT_020b8e9f + DAT_007fe8dc;
        pbVar7 = &DAT_00760f60;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar2 = *pbVar7;
          bVar1 = *pbVar5;
          bVar8 = bVar1 < bVar2;
          pbVar5 = pbVar5 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar1 == bVar2);
        if (bVar8) {
          DAT_007fe8d8 = iVar3;
          *(undefined4 *)(puVar9 + -4) = 0;
          return;
        }
        DAT_007fe8d8 = iVar3 + 1;
        (&DAT_020b90a0)[iVar3] = (&DAT_020b8e9f)[DAT_007fe8dc];
        DAT_007fe8dc = DAT_007fe8dc + 1;
        iVar6 = iVar6 + -1;
        iVar3 = DAT_007fe8d8;
      } while( true );
    }
    bVar8 = false;
    iVar6 = 1;
    pbVar5 = &DAT_020b8e9f + DAT_007fe8d4;
    pbVar7 = &DAT_00761038;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar2 = *pbVar7;
      bVar1 = *pbVar5;
      bVar8 = bVar1 < bVar2;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar1 == bVar2);
    if (!bVar8) {
      *(undefined4 *)(puVar9 + -8) = 0;
      goto LAB_00450ca2;
    }
    DAT_007fe8d4 = DAT_007fe8d4 + 1;
    *(int *)(puVar9 + -0xc) = *(int *)(puVar9 + -0xc) + -1;
    iVar6 = *(int *)(puVar9 + -0xc);
  } while( true );
}


