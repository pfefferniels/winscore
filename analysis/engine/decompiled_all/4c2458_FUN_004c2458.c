// FUN_004c2458 @ 004c2458 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004c2458(uint param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  *param_3 = 0;
  DAT_0089fa8c = *param_4 + 1;
  iVar4 = 0xd - DAT_0089fa8c;
  do {
    if (iVar4 < 1) {
      return;
    }
    if (*(char *)(DAT_0089fa8c + param_1 + -1) == 'X') {
      return;
    }
    bVar7 = CARRY4(DAT_0089fa8c,param_1);
    iVar3 = 1;
    pbVar5 = (byte *)(DAT_0089fa8c + param_1 + -1);
    pbVar6 = &DAT_00764d2c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar2 = *pbVar6;
      bVar1 = *pbVar5;
      bVar7 = bVar1 < bVar2;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (bVar1 == bVar2);
    if (!bVar7) {
      bVar7 = CARRY4(DAT_0089fa8c,param_1);
      bVar8 = DAT_0089fa8c + param_1 == 0;
      iVar3 = 1;
      pbVar5 = (byte *)(DAT_0089fa8c + param_1 + -1);
      pbVar6 = &DAT_00764d28;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      if (bVar7 || bVar8) {
        DAT_0089fa88 = DAT_0089fa8c;
        *param_3 = *(byte *)(DAT_0089fa8c + param_1 + -1) - 0x30;
        *(undefined1 *)(DAT_0089fa8c + param_1 + -1) = 0x20;
        bVar7 = CARRY4(DAT_0089fa8c,param_1);
        iVar4 = 1;
        pbVar5 = (byte *)(DAT_0089fa8c + param_1);
        pbVar6 = &DAT_00764d2c;
        break;
      }
    }
    DAT_0089fa8c = DAT_0089fa8c + 1;
    iVar4 = iVar4 + -1;
  } while( true );
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar2 = *pbVar6;
    bVar1 = *pbVar5;
    bVar7 = bVar1 < bVar2;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
    if (bVar1 != bVar2) break;
    if (iVar4 == 0) break;
  }
  if (!bVar7) {
    bVar7 = CARRY4(DAT_0089fa8c,param_1);
    bVar8 = (byte *)(DAT_0089fa8c + param_1) == (byte *)0x0;
    iVar4 = 1;
    pbVar5 = (byte *)(DAT_0089fa8c + param_1);
    pbVar6 = &DAT_00764d28;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pbVar5 < *pbVar6;
      bVar8 = *pbVar5 == *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (bVar8);
    if (bVar7 || bVar8) {
      DAT_0089fa88 = DAT_0089fa8c + 1;
      *param_3 = *param_3 * 10 + (uint)*(byte *)(DAT_0089fa8c + param_1) + -0x30;
      *(undefined1 *)(DAT_0089fa8c + param_1) = 0x20;
    }
  }
  *param_4 = DAT_0089fa88;
  return;
}


