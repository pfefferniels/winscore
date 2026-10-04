// FUN_0050defa @ 0050defa (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050defa(int param_1,int param_2)

{
  undefined2 in_FPUControlWord;
  undefined4 *local_54;
  undefined1 *local_50;
  int local_4c;
  undefined4 local_48 [8];
  undefined4 local_28;
  int local_20;
  undefined4 local_14;
  undefined4 local_c;
  
  if ((_DAT_01eae1b4 == DAT_01cf8ecc) && (_DAT_00940e1c == DAT_01cf8ed0)) {
    local_28 = 0;
  }
  else {
    _DAT_01eae1b4 = DAT_01cf8ecc;
    _DAT_00940e1c = DAT_01cf8ed0;
    local_48[0] = 0;
    FUN_005fc330(local_48,0x18,0x784ff00,&DAT_0076739c,0,&DAT_00795c58);
    DAT_00940e20 = DAT_00767398;
    local_20 = 0x23;
    DAT_01cf8ec0 = 0xf;
    do {
      local_54 = (undefined4 *)(DAT_01cf8ecc * *(float *)(param_1 + -4 + DAT_01cf8ec0 * 4));
      local_48[0] = 0;
      FUN_005fc330(local_48,0x18,0x784ff00,&DAT_00767394,&local_54,&DAT_00795cec);
      local_54 = (undefined4 *)(DAT_01cf8ed0 * *(float *)(param_2 + -4 + DAT_01cf8ec0 * 4));
      FUN_005fc980(local_48,&DAT_00767394,&local_54);
      local_54 = (undefined4 *)0x1;
      local_50 = &DAT_00940e20;
      FUN_005fc980(local_48,&DAT_00767390,&local_54);
      DAT_00940e20 = DAT_0076738c;
      DAT_01cf8ec0 = DAT_01cf8ec0 + 1;
      local_20 = local_20 + -1;
    } while (0 < local_20);
    local_48[0] = 0;
    FUN_005fc330(local_48,0x18,0x784ff00,&DAT_0076739c,0,&DAT_00795d18);
  }
  DAT_01aae32c = f_m1;
  thunk_FUN_004cf0d3();
  if (IP2 < 0xc9) {
    local_14 = 0;
  }
  else {
    DAT_01cf8ed4 = DAT_01cf8ed4 + f_34050;
    DAT_01cf8ec8 = DAT_01cf8ec8 + f_34050;
  }
  local_48[0] = 0;
  local_54 = &DAT_01cf8ed4;
  FUN_005fc330(local_48,0x18,0x784ff00,&DAT_00767380,&local_54,&DAT_00795d54);
  local_54 = &DAT_01cf8edc;
  FUN_005fc980(local_48,&DAT_00767380,&local_54);
  local_54 = &DAT_01cf8ec8;
  FUN_005fc980(local_48,&DAT_00767380,&local_54);
  local_54 = (undefined4 *)&DAT_01cf8ed8;
  FUN_005fc980(local_48,&DAT_0076737c,&local_54);
  local_50 = (undefined1 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
  DAT_01cf8ec4 = (int)ROUND((DAT_01cf8ec8 - DAT_01cf8ed4) / _DAT_01cf8ed8 + f_1);
  if (IP12 == 0) {
    local_c = 0;
    local_4c = DAT_01cf8ec4;
    thunk_FUN_004cf166();
  }
  else {
    DAT_01cf8ed4 = (float)DAT_01cf8ec4 * _DAT_01cf8ed8 + DAT_01cf8ed4;
  }
  return;
}


