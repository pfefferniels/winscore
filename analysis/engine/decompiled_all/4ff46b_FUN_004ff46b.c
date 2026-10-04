// FUN_004ff46b @ 004ff46b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ff46b(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_5c;
  char *local_58;
  undefined4 local_54;
  undefined2 *local_50;
  undefined4 local_4c;
  undefined4 local_40 [8];
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_10;
  undefined4 local_8;
  
  if (*param_1 == 3) {
    _DAT_009020b0 = 0x44;
    local_40[0] = 0;
    local_5c = 9;
    local_58 = "bars-page";
    local_54 = 3;
    local_50 = (undefined2 *)&DAT_00766b1c;
    local_4c = 2;
    local_1c = FUN_005f6540(local_40,7,0x784ff01,&DAT_00766b58,&local_5c);
    if (local_1c != 0) {
      return;
    }
    local_40[0] = 0;
    local_54 = 0x200;
    local_50 = &DAT_020b8ea0;
    local_4c = 1;
    local_18 = FUN_005fdbd0(local_40,7,0x784ff01,&DAT_00766adc,&local_54,&DAT_007953e4);
    if (local_18 != 0) {
      return;
    }
    local_40[0] = 0;
    FUN_005f7950(local_40,7,0x784ff00,&DAT_00766b38,0);
  }
  else {
    local_20 = 0;
  }
  for (iVar2 = 1; iVar2 < 0xc9; iVar2 = iVar2 + 1) {
    *(undefined4 *)(&DAT_009020b0 + iVar2 * 4) = 0;
  }
  thunk_FUN_0054eab7(&DAT_009020b4,&DAT_009020ac);
  DAT_009020a8 = 0;
  DAT_01b11800 = 0;
  DAT_009020a4 = 1;
  for (local_10 = (DAT_009020ac + 1) / 2; 0 < local_10; local_10 = local_10 + -1) {
    DAT_01b11800 = *(int *)(&DAT_009020b0 + DAT_009020a4 * 4) + DAT_01b11800;
    DAT_009020a8 = (&DAT_009020b4)[DAT_009020a4] + DAT_009020a8;
    DAT_009020a4 = DAT_009020a4 + 2;
  }
  if (DAT_009020a8 == *param_2) {
    _DAT_009020a0 = 0;
    _DAT_0090209c = 0;
    _DAT_00902098 = 1;
    DAT_00902094 = 0;
    DAT_009020a4 = 1;
    for (iVar2 = (DAT_009020ac + 1) / 2; 0 < iVar2; iVar2 = iVar2 + -1) {
      DAT_00902090 = *(int *)(&DAT_009020b0 + DAT_009020a4 * 4);
      DAT_0090208c = (&DAT_009020b4)[DAT_009020a4];
      DAT_00902088 = DAT_0090208c + _DAT_00902098 + -1;
      FUN_004ff7ed(&DAT_0090208c,&DAT_00902090,&DAT_00902098,&DAT_00902088,param_3,&DAT_009023d4);
      DAT_00902084 = 1;
      for (iVar1 = DAT_00902090; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_00902094 = DAT_00902094 + 1;
        (&DAT_01b11800)[DAT_00902094] = *(undefined4 *)(DAT_00902084 * 4 + 0x9023d0);
        DAT_00902084 = DAT_00902084 + 1;
      }
      DAT_00902094 = DAT_00902094 + 1;
      (&DAT_01b11800)[DAT_00902094] = 0;
      _DAT_00902098 = DAT_00902088 + 1;
      local_8 = 0;
      DAT_009020a4 = DAT_009020a4 + 2;
    }
    *param_1 = DAT_009020ac / 2;
  }
  else {
    FUN_004ff387(&DAT_009020a8,param_2);
    *param_1 = -1;
  }
  return;
}


