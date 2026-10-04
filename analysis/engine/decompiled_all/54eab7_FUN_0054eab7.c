// FUN_0054eab7 @ 0054eab7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054eab7(int param_1,int *param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  
  *param_2 = 0;
  for (iVar1 = 1; iVar1 < 0xc9; iVar1 = iVar1 + 1) {
    *(undefined4 *)(iVar1 * 4 + param_1 + -4) = 0;
  }
  DAT_009a2b88 = 0;
  do {
    bVar5 = 0xfffffffe < DAT_009a2b88;
    uVar3 = DAT_009a2b88 + 1;
    bVar6 = uVar3 == 0;
    iVar1 = 1;
    pbVar2 = (byte *)((int)&DAT_020b8ea0 + DAT_009a2b88);
    pbVar4 = &DAT_00769450;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pbVar2 < *pbVar4;
      bVar6 = *pbVar2 == *pbVar4;
      pbVar2 = pbVar2 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar6);
    if (!bVar5) {
      iVar1 = 1;
      pbVar2 = (byte *)((int)&DAT_020b8ea0 + DAT_009a2b88);
      pbVar4 = &DAT_00769658;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pbVar2 < *pbVar4;
        bVar6 = *pbVar2 == *pbVar4;
        pbVar2 = pbVar2 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar6);
      if (bVar5 || bVar6) {
        DAT_009a2b88 = uVar3;
        *param_2 = *param_2 + 1;
        do {
          *(uint *)(*param_2 * 4 + param_1 + -4) =
               *(int *)(param_1 + -4 + *param_2 * 4) * 10 +
               (uint)(byte)(&DAT_020b8e9f)[DAT_009a2b88] + -0x30;
          bVar5 = 0xfffffffe < DAT_009a2b88;
          uVar3 = DAT_009a2b88 + 1;
          bVar6 = uVar3 == 0;
          iVar1 = 1;
          pbVar2 = (byte *)((int)&DAT_020b8ea0 + DAT_009a2b88);
          pbVar4 = &DAT_00769450;
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pbVar2 < *pbVar4;
            bVar6 = *pbVar2 == *pbVar4;
            pbVar2 = pbVar2 + 1;
            pbVar4 = pbVar4 + 1;
          } while (bVar6);
          if (bVar5) break;
          iVar1 = 1;
          bVar5 = false;
          pbVar2 = (byte *)((int)&DAT_020b8ea0 + DAT_009a2b88);
          pbVar4 = &DAT_00769658;
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pbVar2 < *pbVar4;
            bVar6 = *pbVar2 == *pbVar4;
            pbVar2 = pbVar2 + 1;
            pbVar4 = pbVar4 + 1;
          } while (bVar6);
          DAT_009a2b88 = uVar3;
        } while (bVar5 || bVar6);
      }
    }
    DAT_009a2b88 = uVar3;
    if ((499 < (int)DAT_009a2b88) || (199 < *param_2)) {
      return;
    }
  } while( true );
}


