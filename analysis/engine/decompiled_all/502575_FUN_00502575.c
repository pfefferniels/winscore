// FUN_00502575 @ 00502575 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00502575(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  undefined4 local_54;
  char *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44 [16];
  
  local_44[0] = 0;
  FUN_005f7950(local_44,*param_1,0x784ff00,&DAT_00766d5c,0);
  if (*param_4 == 0) {
    local_44[0] = 0;
    local_5c = 0x18;
    local_58 = (char *)param_2;
    local_54 = 7;
    local_50 = "unknown";
    local_4c = 0x200;
    local_48 = 2;
    iVar1 = FUN_005f6540(local_44,*param_1,0x784ff01,&DAT_00766d24,&local_5c);
  }
  else if (*param_4 < 1) {
    local_44[0] = 0;
    local_64 = 0x18;
    local_60 = param_2;
    local_5c = 7;
    local_58 = "unknown";
    local_54 = 6;
    local_50 = "binary";
    local_4c = 2;
    iVar1 = FUN_005f6540(local_44,*param_1,0x784ff01,&DAT_00766d38,&local_64);
  }
  else {
    local_44[0] = 0;
    local_64 = 0x18;
    local_60 = param_2;
    local_5c = 7;
    local_58 = "unknown";
    local_54 = 0xb;
    local_50 = "unformatted";
    local_4c = 0x200;
    local_48 = 2;
    iVar1 = FUN_005f6540(local_44,*param_1,0x784ff01,&DAT_00766d00,&local_64);
  }
  if (iVar1 != 0) {
    *param_1 = 0xffffffff;
  }
  return;
}


