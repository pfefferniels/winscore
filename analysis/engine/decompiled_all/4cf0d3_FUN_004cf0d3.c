// FUN_004cf0d3 @ 004cf0d3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cf0d3(void)

{
  undefined4 *local_34 [2];
  undefined4 local_2c [8];
  int local_c;
  
  DAT_01aae330 = ((float)_DAT_0078cb00 + DAT_01aae32c) * _DAT_01aae320;
  if (DAT_01aae330 < f_0) {
    DAT_01aae330 = f_0;
  }
  local_2c[0] = 0;
  local_34[0] = &DAT_01aae330;
  local_c = FUN_005fc330(local_2c,0x18,0x784ff01,&DAT_007650e4,local_34,&DAT_00792f00);
  if (local_c != 0) {
    FUN_004cf1c2();
  }
  return;
}


