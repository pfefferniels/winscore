// FUN_0058c248 @ 0058c248 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058c248(int param_1,undefined4 param_2,int *param_3,int *param_4,undefined4 *param_5,
                 undefined4 param_6,undefined4 param_7)

{
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
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
  local_5c = *param_5;
  local_58 = param_5[1];
  local_54 = param_5[2];
  local_44 = &local_5c;
  local_4c[0] = 0xc;
  FUN_005f34f0(local_28,0x784ff08,&DAT_0076aed8,&local_3c,local_4c);
  return;
}


