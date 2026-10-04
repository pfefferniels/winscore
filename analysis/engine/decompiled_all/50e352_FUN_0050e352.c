// FUN_0050e352 @ 0050e352 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050e352(void)

{
  int iVar1;
  int *local_44;
  undefined1 *local_40;
  undefined4 local_38 [8];
  undefined4 local_18;
  
  _DAT_01cadcf8 = IP10;
  iVar1 = 0x5a - IP11;
  IP11 = 0x5a - IP10;
  _DAT_0078d86c = STEP * f_3_5 * _DAT_01c58a08;
  DAT_00940e2c = DAT_007673c8;
  _DAT_01c58a04 = Y_POS;
  IP10 = iVar1;
  if (DAT_01cadcec == _DAT_01c58a08) {
    local_18 = 0;
  }
  else {
    DAT_0078d870 = DAT_01cadcec / _DAT_01c58a08;
    _DAT_01c58a04 = Y_POS / DAT_0078d870;
    DAT_00940e2c = DAT_007673c4;
    local_38[0] = 0;
    local_44 = (int *)&DAT_0078d870;
    FUN_005fc330(local_38,0x18,0x784ff00,&DAT_0076737c,&local_44,&DAT_00795d70);
  }
  _DAT_00940e28 = X_POS;
  if (f_199 < P2) {
    _DAT_00940e28 = X_POS + f_34050;
  }
  local_38[0] = 0;
  local_44 = (int *)&DAT_00940e28;
  FUN_005fc330(local_38,0x18,0x784ff00,&DAT_00767380,&local_44,&DAT_00795d98);
  local_44 = (int *)&DAT_01c58a04;
  FUN_005fc980(local_38,&DAT_00767380,&local_44);
  local_44 = (int *)&DAT_0078d86c;
  FUN_005fc980(local_38,&DAT_00767380,&local_44);
  local_44 = &IP10;
  FUN_005fc980(local_38,&DAT_007673c0,&local_44);
  local_44 = &IP11;
  FUN_005fc980(local_38,&DAT_007673bc,&local_44);
  if (DAT_01cadcec != _DAT_01c58a08) {
    local_44 = (int *)(f_1 / DAT_0078d870);
    local_38[0] = 0;
    FUN_005fc330(local_38,0x18,0x784ff00,&DAT_007673b8,&local_44,&DAT_00795dcc);
  }
  DAT_00940e30 = DAT_007673b4;
  if (DAT_01f93e80 == 2) {
    DAT_00940e30 = DAT_007673b0;
  }
  local_38[0] = 0;
  local_44 = (int *)0x1;
  local_40 = &DAT_00940e30;
  FUN_005fc330(local_38,0x18,0x784ff00,&DAT_007673ac,&local_44,&DAT_00795df4);
  local_44 = (int *)0x1;
  local_40 = &DAT_00940e2c;
  FUN_005fc980(local_38,&DAT_00767390,&local_44);
  return;
}


