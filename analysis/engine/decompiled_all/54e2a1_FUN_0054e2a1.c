// FUN_0054e2a1 @ 0054e2a1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054e2a1(char *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  char *pcVar2;
  byte *pbVar3;
  char *pcVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  undefined4 *puStack_48;
  int local_c;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x38;
  iVar1 = 5;
  pcVar2 = param_1;
  pcVar4 = "20000";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar6);
  if (!bVar6) {
    DAT_009a2ac0 = *param_1;
    FUN_0054c768(&DAT_009a2ac0);
    bVar6 = (undefined1 *)0xfffffffb < &puStack_48;
    bVar7 = &stack0x00000000 == (undefined1 *)0x44;
    iVar1 = 1;
    pbVar3 = (byte *)&DAT_009a2ac0;
    pbVar5 = &DAT_00769150;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pbVar3 < *pbVar5;
      bVar7 = *pbVar3 == *pbVar5;
      pbVar3 = pbVar3 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar7);
    if (!bVar6 && !bVar7) {
      if ((param_1[1] != 'U') && (param_1[1] != 'u')) {
        local_c = 7;
        DAT_009a2ac8 = 1;
        do {
          if (*(char *)(DAT_009a2ac8 + 0x79d6f3) == DAT_009a2ac0) {
            return;
          }
          DAT_009a2ac8 = DAT_009a2ac8 + 1;
          local_c = local_c + -1;
        } while (0 < local_c);
      }
      puStack_48 = &DAT_009a2ac8;
      FUN_0054cd71(param_1,0x80,&DAT_007695fc);
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_3 = *(undefined4 *)param_1;
        param_1 = param_1 + 4;
        param_3 = param_3 + 1;
      }
    }
  }
  return;
}


