// FUN_0050273b @ 0050273b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_0050273b(undefined4 param_1)

{
  int iVar1;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  undefined4 local_30 [8];
  undefined4 local_10;
  
  local_10 = 1;
  local_30[0] = 0;
  local_44 = 0x80;
  local_40 = param_1;
  local_3c = &DAT_009029d4;
  iVar1 = FUN_005f47c0(local_30,0xffffffff,0x784ff01,&DAT_00766d60,&local_44);
  if ((iVar1 == 0) && ((DAT_009029d4 & 1) != 0)) {
    local_10 = 0;
  }
  return local_10;
}


