// FUN_004cfb85 @ 004cfb85 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004cfd4e) */
/* WARNING: Removing unreachable block (ram,0x004cfbb6) */
/* WARNING: Removing unreachable block (ram,0x004cfcdc) */
/* WARNING: Removing unreachable block (ram,0x004cfdcd) */

void FUN_004cfb85(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  undefined4 uStack_58;
  int local_24;
  
  local_24 = 0x7f;
  DAT_0089fe60 = 2;
  do {
    uStack_58 = 0x20;
    iVar3 = FUN_005f4660();
    if (iVar3 != 0) break;
    DAT_0089fe60 = DAT_0089fe60 + 1;
    local_24 = local_24 + -1;
  } while (0 < local_24);
LAB_004cfc03:
  do {
    DAT_0089fe60 = DAT_0089fe60 + -1;
    if (DAT_0089fe60 == 0) {
      return;
    }
    uStack_58 = 0x4cfc5a;
    FUN_005f46bc();
    uStack_58 = 0x4cfc70;
    FUN_005f34d1();
    bVar6 = (undefined1 *)0xfffffffb < &uStack_58;
    bVar7 = &stack0x00000000 == (undefined1 *)0x54;
    iVar3 = 1;
    pbVar4 = (byte *)&DAT_0089fe58;
    pbVar5 = &DAT_00765260;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pbVar4 < *pbVar5;
      bVar7 = *pbVar4 == *pbVar5;
      pbVar4 = pbVar4 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar7);
    if (!bVar6) {
      iVar3 = 1;
      pbVar4 = (byte *)&DAT_0089fe58;
      pbVar5 = &DAT_0076525c;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pbVar4 < *pbVar5;
        bVar7 = *pbVar4 == *pbVar5;
        pbVar4 = pbVar4 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (bVar6 || bVar7) {
        iVar3 = 1;
        pbVar4 = (byte *)&DAT_0089fe58;
        pbVar5 = &DAT_0076525c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar2 = *pbVar5;
          bVar1 = *pbVar4;
          bVar6 = bVar1 < bVar2;
          pbVar4 = pbVar4 + 1;
          pbVar5 = pbVar5 + 1;
        } while (bVar1 == bVar2);
        if (bVar6) goto LAB_004cfda5;
        uStack_58 = 0x4cfcfd;
        FUN_005f46bc();
        uStack_58 = 0x4cfd13;
        FUN_005f34d1();
        goto LAB_004cfc03;
      }
    }
    iVar3 = 1;
    pbVar4 = (byte *)&DAT_0089fe58;
    pbVar5 = &DAT_00765258;
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
LAB_004cfda5:
      DAT_0089fe58 = DAT_0089fe58 + '\x01';
      uStack_58 = 0x4cfdee;
      FUN_005f46bc();
      uStack_58 = 0x4cfe04;
      FUN_005f34d1();
      return;
    }
    uStack_58 = 0x4cfd6f;
    FUN_005f46bc();
    uStack_58 = 0x4cfd85;
    FUN_005f34d1();
  } while( true );
}


