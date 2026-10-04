// FUN_0054ec49 @ 0054ec49 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_0054ec49(undefined4 param_1)

{
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined *local_40;
  undefined4 local_3c;
  undefined4 local_34 [8];
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  
  DAT_009a2b90 = 0x21;
  local_14 = 0xffffffff;
  local_34[0] = 0;
  local_4c = 0x80;
  local_48 = param_1;
  local_44 = 3;
  local_40 = &DAT_00769670;
  local_3c = 2;
  local_10 = FUN_005f6540(local_34,0x21,0x784ff01,&DAT_00769660,&local_4c);
  if ((local_10 == 0) && (DAT_009a2b90 == 0x21)) {
    local_c = 0;
  }
  else {
    local_14 = 0;
  }
  local_34[0] = 0;
  FUN_005f7950(local_34,0x21,0x784ff00,&DAT_0076939c,0);
  return local_14;
}


