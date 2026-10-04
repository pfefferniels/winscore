// FUN_0052f62e @ 0052f62e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0052f62e(int *param_1)

{
  undefined1 *puVar1;
  undefined4 local_54;
  char *local_50;
  undefined4 local_4c;
  char *local_48;
  undefined4 local_44;
  char *local_40;
  int *local_3c [2];
  undefined4 local_34 [12];
  
  puVar1 = &stack0xfffffffc;
  local_34[0] = 0;
  local_54 = 0xc;
  local_50 = "!abandon.tmp";
  local_4c = 7;
  local_48 = "unknown";
  local_44 = 6;
  local_40 = "binary";
  local_3c[0] = (int *)0x2;
  FUN_005f6540(local_34,0xc,0x784ff00,&DAT_00768408,&local_54);
  if (*param_1 == 0) {
    DAT_0099a0fc = ITEM_WORDS;
    local_34[0] = 0;
    local_3c[0] = &ITEM_I;
    FUN_005fa4d0(local_34,0xc,0x784ff00,&DAT_00768404,local_3c);
    local_48 = (char *)&ITEM_P1;
    local_40 = (char *)ITEM_WORDS;
    if (ITEM_WORDS < 0) {
      local_40 = (char *)0x0;
    }
    DAT_0099a0f8 = (int)local_40 + 1;
    local_4c = 1;
    local_44 = 1;
    local_3c[0] = (int *)0x4;
    FUN_005fa9f0(local_34,&DAT_00768400,&local_4c);
    puVar1 = &stack0xfffffffc;
  }
  else {
    local_34[0] = 0;
    local_3c[0] = &ITEM_I;
    FUN_005f8240(local_34,0xc,0x784ff00,&DAT_00768404,local_3c);
    local_48 = (char *)&ITEM_P1;
    local_40 = (char *)DAT_0099a0fc;
    if (DAT_0099a0fc < 0) {
      local_40 = (char *)0x0;
    }
    DAT_0099a0f8 = (int)local_40 + 1;
    local_4c = 1;
    local_44 = 1;
    local_3c[0] = (int *)0x4;
    FUN_005f8730(local_34,&DAT_00768400,&local_4c);
    ITEM_WORDS = DAT_0099a0fc;
    DAT_02052740 = 0;
    if (DAT_0099a0fc < 2) {
      DAT_0078b4e4 = 0x53;
      puVar1 = &stack0xfffffffc;
      FUN_005f34d1(&stack0xfffffffc,0x52f835);
      thunk_FUN_00522bd8();
    }
  }
  *(undefined4 *)(puVar1 + -0x30) = 0;
  FUN_005f7950(puVar1 + -0x30,0xc,0x784ff00,&DAT_007683e8,0);
  return;
}


