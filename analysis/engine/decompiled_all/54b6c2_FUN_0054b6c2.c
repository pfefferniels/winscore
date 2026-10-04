// FUN_0054b6c2 @ 0054b6c2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054b6c2(void)

{
  undefined2 in_FPUControlWord;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28 [9];
  
  if (P2 != f_0) {
    DAT_01c25e80 = (int)ROUND(P2);
    local_30 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_01c25e84 = (int)ROUND(P3);
    local_2c = DAT_01c25e84;
  }
  local_28[0] = 0;
  local_3c = 0x10;
  local_38 = &DAT_009ae2bc;
  local_34 = &DAT_01c25e80;
  FUN_005f34f0(local_28,0x784ff00,&DAT_007693d0,&local_3c,&DAT_0079768c);
  local_34 = &DAT_01c25e84;
  FUN_005f3960(local_28,&DAT_007693cc,&local_34);
  return;
}


