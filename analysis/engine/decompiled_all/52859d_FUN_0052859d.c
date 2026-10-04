// FUN_0052859d @ 0052859d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0052859d(uint param_1,undefined4 param_2,int *param_3,int *param_4,uint *param_5)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  
  *param_5 = *param_3 + 1;
  do {
    bVar4 = CARRY4(*param_5,param_1);
    iVar1 = *param_5 + param_1;
    bVar5 = iVar1 == 0;
    DAT_0094eb4c = *(byte *)(iVar1 + -1);
    iVar1 = 1;
    pbVar2 = &DAT_0094eb4c;
    pbVar3 = &DAT_00767ef4;
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
      pbVar2 = &DAT_0094eb4c;
      pbVar3 = &DAT_00767ee4;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pbVar2 < *pbVar3;
        bVar5 = *pbVar2 == *pbVar3;
        pbVar2 = pbVar2 + 1;
        pbVar3 = pbVar3 + 1;
      } while (bVar5);
      if (bVar4 || bVar5) {
        *param_4 = DAT_0094eb4c - 0x30;
        return;
      }
    }
    *param_5 = *param_5 + 1;
    if (*param_3 + 4 <= (int)*param_5) {
      return;
    }
  } while( true );
}


