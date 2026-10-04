// FUN_004b3907 @ 004b3907 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b3907(int *param_1,int *param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  int local_2c;
  
  local_2c = 0x13;
  *param_3 = 1;
  while ((&DAT_007924a7)[*param_3] != (&DAT_020b8e9f)[*param_1]) {
    *param_3 = *param_3 + 1;
    local_2c = local_2c + -1;
    if (local_2c < 1) {
      *param_3 = 0;
      return;
    }
  }
  if (*param_3 == 0xd) {
    return;
  }
  if (*param_3 == 0xe) {
    return;
  }
  if ((*param_3 < 7) || (9 < *param_3)) {
    DAT_0089f380 = *param_1 + 1;
    iVar3 = (*param_2 - DAT_0089f380) + 1;
    for (; ((0 < iVar3 && ((&DAT_020b8e9f)[DAT_0089f380] != '-')) &&
           (bVar7 = (byte)(&DAT_020b8e9f)[DAT_0089f380] < 0x2e,
           (&DAT_020b8e9f)[DAT_0089f380] != 0x2e)); DAT_0089f380 = DAT_0089f380 + 1) {
      iVar4 = 1;
      pbVar5 = &DAT_020b8e9f + DAT_0089f380;
      pbVar6 = &DAT_007645dc;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar2 = *pbVar6;
        bVar1 = *pbVar5;
        bVar7 = bVar1 < bVar2;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar1 == bVar2);
      bVar7 = !bVar7;
      bVar9 = !bVar7;
      iVar4 = 1;
      pbVar5 = &DAT_020b8e9f + DAT_0089f380;
      pbVar6 = &DAT_007645d8;
      bVar8 = bVar7;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pbVar5 < *pbVar6;
        bVar9 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar9);
      if ((bVar8 || bVar9) && bVar7) break;
      iVar3 = iVar3 + -1;
    }
  }
  else {
    if (*param_3 == 7) {
      DAT_0089f380 = 4;
    }
    if (*param_3 == 8) {
      DAT_0089f380 = 3;
    }
    if (*param_3 == 9) {
      DAT_0089f380 = 5;
    }
    *param_1 = *param_1 + DAT_0089f380;
    DAT_0089f384 = (&DAT_020b8e9e)[*param_1];
    if ((DAT_0089f384 != 'D') && (DAT_0089f384 != 'C')) {
      return;
    }
    DAT_0089f380 = (byte)(&DAT_020b8e9e)[*param_1] + 0x26cb;
  }
  *param_1 = DAT_0089f380;
  return;
}


