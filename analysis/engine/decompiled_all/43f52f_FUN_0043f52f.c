// FUN_0043f52f @ 0043f52f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043f52f(int *param_1)

{
  undefined4 local_64;
  char *local_60;
  undefined4 local_5c;
  char *local_58;
  undefined4 local_54;
  char *local_50;
  int *local_4c [2];
  undefined4 local_44;
  undefined4 local_40 [8];
  int local_20;
  undefined4 local_1c;
  
  DAT_007f7878 = 0xd;
  local_44 = 0;
  local_40[0] = 0;
  local_64 = 0x15;
  local_60 = "C:\\!TMP\\!savebeam.tmp";
  local_5c = 7;
  local_58 = "unknown";
  local_54 = 6;
  local_50 = "binary";
  local_4c[0] = (int *)0x2;
  local_20 = FUN_005f6540(local_40,0xd,0x784ff01,&DAT_007606b8,&local_64);
  if (local_20 == 0) {
    if (*param_1 == 0) {
      DAT_007f7874 = ITEM_WORDS + 5;
      (&ITEM_LEN)[DAT_007f7874] = f_m9999;
      *(float *)(&DAT_02053438 + DAT_007f7874 * 4) = f_5;
      *(float *)(&DAT_02053434 + DAT_007f7874 * 4) = (float)DAT_0078b4e8;
      DAT_0078dc90 = DAT_0078dc84;
      *(float *)(&DAT_02053430 + DAT_007f7874 * 4) = (float)_DAT_007f7870;
      *(undefined4 *)(&DAT_0205342c + DAT_007f7874 * 4) = DAT_0078dc90;
      local_40[0] = 0;
      local_4c[0] = &DAT_007f7874;
      FUN_005fa4d0(local_40,DAT_007f7878,0x784ff00,&DAT_007606b4,local_4c);
      local_58 = (char *)&ITEM_P1;
      local_50 = (char *)DAT_007f7874;
      if (DAT_007f7874 < 0) {
        local_50 = (char *)0x0;
      }
      DAT_007f786c = (int)local_50 + 1;
      local_5c = 1;
      local_54 = 1;
      local_4c[0] = (int *)0x4;
      FUN_005fa9f0(local_40,&DAT_007606b0,&local_5c);
      local_40[0] = 0;
      FUN_005f7950(local_40,DAT_007f7878,0x784ff00,&DAT_007606ac,0);
    }
    else {
      local_1c = 0;
      local_40[0] = 0;
      local_4c[0] = &ITEM_WORDS;
      FUN_005f8240(local_40,DAT_007f7878,0x784ff00,&DAT_007606b4,local_4c);
      local_58 = (char *)&ITEM_P1;
      local_50 = (char *)ITEM_WORDS;
      if (ITEM_WORDS < 0) {
        local_50 = (char *)0x0;
      }
      DAT_007f786c = (int)local_50 + 1;
      local_5c = 1;
      local_54 = 1;
      local_4c[0] = (int *)0x4;
      FUN_005f8730(local_40,&DAT_007606b0,&local_5c);
      local_40[0] = 0;
      FUN_005f7950(local_40,DAT_007f7878,0x784ff00,&DAT_007606ac,0);
      draw_items();
      P2 = f_0;
    }
  }
  return;
}


