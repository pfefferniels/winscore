// FUN_004d4f89 @ 004d4f89 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d4f89(int *param_1)

{
  undefined2 in_FPUControlWord;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  undefined4 local_30 [8];
  undefined4 local_10;
  
  *param_1 = *param_1 + 1;
  local_38 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_008a0354 = (int)ROUND(_DAT_01b11798);
  local_34 = DAT_008a0354;
  if ((DAT_008a0354 != 0) || (f_1 < DAT_01b1179c)) {
    local_10 = 0;
    thunk_FUN_004f0d31(&DAT_01b1179c);
  }
  else {
    local_30[0] = 0;
    local_3c = &DAT_01b1179c;
    FUN_005fc330(local_30,0x18,0x784ff00,&DAT_00765534,&local_3c,&DAT_00793c4c);
  }
  return;
}


