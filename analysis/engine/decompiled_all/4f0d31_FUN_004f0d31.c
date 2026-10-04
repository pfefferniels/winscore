// FUN_004f0d31 @ 004f0d31 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f0d31(float *param_1)

{
  undefined2 in_FPUControlWord;
  undefined *local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28 [9];
  
  local_30 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_008d1988 = (int)ROUND(*param_1);
  _DAT_008d1980 = (float)(DAT_008d1988 / 10000) / f_100;
  if (f_0_989 <= _DAT_008d1980) {
    _DAT_008d1980 = f_1;
  }
  _DAT_008d1984 = (DAT_008d1988 % 10000) / 100;
  _DAT_008d197c = (float)_DAT_008d1984 / f_100;
  if (f_0_989 <= _DAT_008d197c) {
    _DAT_008d197c = f_1;
  }
  local_2c = DAT_008d1988 % 100;
  _DAT_008d1978 = (float)local_2c / f_100;
  if (f_0_989 <= _DAT_008d1978) {
    _DAT_008d1978 = f_1;
  }
  local_28[0] = 0;
  local_34 = &DAT_008d1980;
  FUN_005fc330(local_28,0x18,0x784ff00,&DAT_007664b4,&local_34,&DAT_00794e10);
  local_34 = &DAT_008d197c;
  FUN_005fc980(local_28,&DAT_007664b4,&local_34);
  local_34 = &DAT_008d1978;
  FUN_005fc980(local_28,&DAT_007664b0,&local_34);
  return;
}


