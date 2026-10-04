// FUN_0058c2c9 @ 0058c2c9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058c2c9(int param_1,undefined4 param_2,int *param_3,int *param_4,undefined4 *param_5,
                 undefined4 param_6,undefined4 param_7)

{
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c [2];
  undefined4 *local_44;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_28 [9];
  
  local_3c = *param_4 - (*param_3 + -1);
  if (local_3c < 0) {
    local_3c = 0;
  }
  local_38 = *param_3 + -1 + param_1;
  local_28[0] = 0;
  local_34 = param_7;
  local_54 = *param_5;
  local_50 = param_5[1];
  local_44 = &local_54;
  local_4c[0] = 8;
  FUN_005f34f0(local_28,0x784ff08,&DAT_0076aee0,&local_3c,local_4c);
  return;
}


