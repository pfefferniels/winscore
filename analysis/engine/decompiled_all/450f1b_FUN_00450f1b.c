// FUN_00450f1b @ 00450f1b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00450f1b(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined1 *puVar1;
  undefined4 local_3c;
  char *local_38;
  int *local_34;
  undefined4 local_28 [9];
  
  puVar1 = &stack0xfffffffc;
  *param_2 = *param_1 % 10 + 1;
  local_28[0] = 0;
  local_3c = 4;
  local_38 = s_Number__Name__0078fac8 + 9;
  local_34 = param_1;
  FUN_005f34f0(local_28,0x784ff00,&DAT_00760eec,&local_3c,&DAT_0078fa94);
  param_5 = *param_2 * 0x18 + param_5;
  s_Number__Name__0078fac8._20_4_ = *(undefined4 *)(param_5 + -0x18);
  s_Number__Name__0078fac8._24_4_ = *(undefined4 *)(param_5 + -0x14);
  s_Number__Name__0078fac8._28_2_ = *(undefined2 *)(param_5 + -0x10);
  s_Number__Name__0078fac8[0x1e] = '\0';
  FUN_005f34d1(&stack0xfffffffc,0x450fca);
  thunk_FUN_0054cb15(*(undefined4 *)(puVar1 + 0x10),0x80,&DAT_007fe8f4,&DAT_00760d1c);
  FUN_005f46bc(puVar1,0x451017);
  FUN_005f46bc(puVar1,0x451033);
  FUN_005f34d1(puVar1,0x451049);
  thunk_FUN_00579770(&DAT_00760d9c,1,&DAT_020b90a0);
  return;
}


