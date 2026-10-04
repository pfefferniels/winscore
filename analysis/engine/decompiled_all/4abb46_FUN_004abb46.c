// FUN_004abb46 @ 004abb46 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004abb46(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  float fVar1;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [2];
  undefined4 *local_4c;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  int *local_34;
  undefined4 local_30;
  undefined4 local_2c [10];
  
  fVar1 = f_51_33723;
  if (*param_4 == 2) {
    fVar1 = (float)i_1414418246;
  }
  if (*param_4 == 3) {
    fVar1 = (float)i_1414419024;
  }
  DAT_00791f8c._0_2_ = (undefined2)((uint)fVar1 >> 0x10);
  DAT_00791f88._2_2_ = SUB42(fVar1,0);
  local_2c[0] = 0;
  local_3c = 3;
  local_38 = &DAT_00791f94;
  local_34 = param_3;
  FUN_005f34f0(local_2c,0x784ff00,&DAT_00763cac,&local_3c,&DAT_00791cd4);
  local_44 = *param_3;
  if (local_44 < 0) {
    local_44 = 0;
  }
  local_2c[0] = 0;
  local_64 = CONCAT22(DAT_00791f88._2_2_,(undefined2)DAT_00791f88);
  local_60 = CONCAT22(DAT_00791f8c._2_2_,(undefined2)DAT_00791f8c);
  local_34 = (int *)DAT_00791f90;
  local_30 = DAT_00791f94;
  local_40 = param_1;
  local_5c = DAT_00791f90;
  local_58 = DAT_00791f94;
  local_4c = &local_64;
  local_54[0] = 0x10;
  local_3c = local_64;
  local_38 = (undefined4 *)local_60;
  FUN_005fc330(local_2c,8,0x784ff08,&DAT_00763d88,&local_44,local_54);
  return;
}


