// FUN_0056ece5 @ 0056ece5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056ece5(undefined4 *param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 local_44;
  int local_40;
  undefined *local_3c;
  undefined4 local_30 [8];
  undefined4 local_10;
  
  puVar4 = &stack0xfffffffc;
  if ((IP8 < 1000) && (99 < *param_4)) {
    local_10 = 0;
    puVar2 = &DAT_0076a3a8;
    puVar3 = param_1;
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    _DAT_009a8230 = P8 * _DAT_01aae320;
    if (P8 == f_0) {
      _DAT_009a8230 = DAT_01aae324;
    }
    local_40 = (int)param_1 + 0x11;
    local_30[0] = 0;
    local_44 = 6;
    local_3c = &DAT_009a8230;
    FUN_005f34f0(local_30,0x784ff00,&DAT_0076a374,&local_44,&DAT_0079fd18);
    *param_3 = *param_3 + 0x20;
  }
  else {
    FUN_005f33c9(&stack0xfffffffc,0x56edc1);
    FUN_005f34d1(puVar4,0x56eddc);
    **(int **)(puVar4 + 0x10) = **(int **)(puVar4 + 0x10) + 5;
    *(undefined4 *)(puVar4 + -8) = 0;
  }
  return;
}


