// FUN_004da9c3 @ 004da9c3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004da9c3(int *param_1)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  float10 fVar10;
  int local_24;
  
  DAT_01aad7c8 = DAT_01fb8cc0;
  DAT_01aad7c0 = *param_1;
  if (DAT_01fbb700 != 5) {
    if ((((char)DAT_020b8ea0 == 'B') || ((char)DAT_020b8ea0 == 'A')) && (DAT_020b8ea0._1_1_ != '['))
    {
      if (((DAT_0078d918 == 99) || (DAT_0078d91c == 0)) || (DAT_0078d91c == 4)) {
        DAT_020b8ea0._0_1_ = DAT_00765930;
      }
      else if ((DAT_0078d91c == 2) || (DAT_0078d918 == 0x62)) {
        DAT_020b8ea0._0_1_ = DAT_0076592c;
      }
      else if (DAT_0078d91c == 1) {
        DAT_020b8ea0._0_1_ = DAT_00765938;
      }
      else if (DAT_0078d91c == 8) {
        if (((DAT_0078d918 == 8) || (DAT_0078d918 == 2)) || (DAT_0078d918 == 4)) {
          DAT_020b8ea0._0_1_ = DAT_00765930;
        }
        else if (((DAT_0078d918 == 0xc) || (DAT_0078d918 == 9)) ||
                ((DAT_0078d918 == 3 || (DAT_0078d918 == 6)))) {
          DAT_020b8ea0._0_1_ = DAT_00765934;
        }
        else {
          DAT_01aad7c0 = 0;
        }
      }
      else {
        DAT_01aad7c0 = 0;
      }
      if (DAT_01aad7c0 == 0) {
        *param_1 = 0;
        return;
      }
      DAT_020b8ea0._1_1_ = 'B';
      DAT_020b8ea2 = DAT_00765928;
      DAT_01aad7d0 = 1;
LAB_004dadf2:
      DAT_01ade8e0 = f_0;
      fVar10 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7d0,1,&DAT_01aad7c0);
      DAT_01fb8cc8 = (float)fVar10;
      iVar4 = thunk_FUN_00526ec4(&DAT_0078d8e0,&DAT_01aad7c0,&DAT_01fbb704);
      if (iVar4 == 0) {
        fVar10 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
        DAT_01ade8e0 = (float)fVar10;
      }
      DAT_01fb8cc4 = f_9999;
      *param_1 = 999;
      DAT_01fb8cc0 = 2;
      return;
    }
    DAT_01aad7d0 = 0;
    local_24 = 10;
    DAT_01aad7c4 = 1;
    do {
      if (DAT_01aad7d0 == 0) {
        bVar7 = (byte)(&DAT_020b8e9f)[DAT_01aad7c4] < 0x2e;
        if ((&DAT_020b8e9f)[DAT_01aad7c4] != 0x2e) {
          iVar4 = 1;
          pbVar5 = &DAT_020b8e9f + DAT_01aad7c4;
          pbVar6 = &DAT_0076591c;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar3 = *pbVar6;
            bVar2 = *pbVar5;
            bVar7 = bVar2 < bVar3;
            pbVar5 = pbVar5 + 1;
            pbVar6 = pbVar6 + 1;
          } while (bVar2 == bVar3);
          bVar7 = !bVar7;
          bVar9 = !bVar7;
          iVar4 = 1;
          pbVar5 = &DAT_020b8e9f + DAT_01aad7c4;
          pbVar6 = &DAT_00765918;
          bVar8 = bVar7;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar8 = *pbVar5 < *pbVar6;
            bVar9 = *pbVar5 == *pbVar6;
            pbVar5 = pbVar5 + 1;
            pbVar6 = pbVar6 + 1;
          } while (bVar9);
          if (!bVar8 && !bVar9 || !bVar7) goto LAB_004daadb;
        }
        DAT_01aad7d0 = DAT_01aad7c4;
      }
LAB_004daadb:
      if ((DAT_01aad7d0 != 0) && ((&DAT_020b8e9f)[DAT_01aad7c4] == 'B')) {
        if ((*(char *)((int)&DAT_020b8ea0 + DAT_01aad7c4) != '[') &&
           ((&DAT_020b8e9e)[DAT_01aad7c4] != '@')) goto LAB_004dadf2;
        break;
      }
      DAT_01aad7c4 = DAT_01aad7c4 + 1;
      local_24 = local_24 + -1;
    } while (0 < local_24);
  }
  pcVar1 = &DAT_020b8e9f + DAT_01aad7c0;
  if (*pcVar1 == '+') {
    DAT_01aad7c0 = DAT_01aad7c0 + 1;
  }
  DAT_01aad7c4 = (uint)(*pcVar1 == '+');
  iVar4 = DAT_01fb8cc0 + 1;
  DAT_01aad7c8 = iVar4;
  fVar10 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
  (&DAT_01fb8cc0)[iVar4] = (int)(float)fVar10;
  DAT_01aad7d4 = thunk_FUN_00526ec4(&DAT_0078d8e0,&DAT_01aad7c0,&DAT_01fbb704);
  if ((&DAT_020b8e9f)[DAT_01aad7c0] == '+') {
    DAT_01aad7c4 = 1;
    DAT_01aad7c0 = DAT_01aad7c0 + 1;
  }
  fVar10 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
  DAT_01ade8e0 = (float)fVar10;
  if (DAT_01aad7c4 != 0) {
    (&DAT_01fb8cc0)[DAT_01aad7c8] = (int)((float)(&DAT_01fb8cc0)[DAT_01aad7c8] + f_10000);
  }
  *param_1 = DAT_01fbb704;
  DAT_01fb8cc0 = DAT_01aad7c8;
  return;
}


