// FUN_00413188 @ 00413188 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413188(void)

{
  undefined2 in_FPUControlWord;
  undefined1 *puVar1;
  undefined4 uStack_64;
  char *pcStack_60;
  undefined4 uStack_5c;
  char *pcStack_58;
  undefined4 *puStack_54;
  int iStack_50;
  undefined4 auStack_4c [10];
  int iStack_24;
  int iStack_14;
  undefined4 uStack_8;
  
  puVar1 = &stack0xfffffffc;
  switch(DAT_019c5ca8) {
  default:
    FUN_005f33c9(&stack0xfffffffc,0x4135b5);
    FUN_005f34d1(puVar1,0x4135d0);
    thunk_FUN_0054aaf8();
    FUN_005f34d1(puVar1,0x4135f6);
    *(undefined4 *)(puVar1 + -0x28) = 0;
    break;
  case 2:
    auStack_4c[0] = 0;
    uStack_64 = 0xd;
    pcStack_60 = "\\!TMP\\!BB.dat";
    uStack_5c = 7;
    pcStack_58 = "unknown";
    puStack_54 = (undefined4 *)0x2;
    FUN_005f6540(auStack_4c,8,0x784ff00,&DAT_0075f48c,&uStack_64);
    auStack_4c[0] = 0;
    puStack_54 = &DAT_019c5ca0;
    iStack_24 = FUN_005fc330(auStack_4c,8,0x784ff01,&DAT_0075f488,&puStack_54,&DAT_0078b2a8);
    if (iStack_24 == 0) {
      puStack_54 = &DAT_019c5c9c;
      iStack_24 = FUN_005fc980(auStack_4c,&DAT_0075f488,&puStack_54);
      if (iStack_24 == 0) {
        puStack_54 = &DAT_019c5c98;
        iStack_24 = FUN_005fc980(auStack_4c,&DAT_0075f488,&puStack_54);
        if (iStack_24 == 0) {
          puStack_54 = &DAT_019c5c94;
          iStack_24 = FUN_005fc980(auStack_4c,&DAT_0075f484,&puStack_54);
        }
      }
    }
    if (iStack_24 == 0) {
      auStack_4c[0] = 0;
      FUN_005f7950(auStack_4c,8,0x784ff00,&DAT_0075f480,0);
    }
    break;
  case 3:
    auStack_4c[0] = 0;
    uStack_64 = 0xd;
    pcStack_60 = "\\!TMP\\!BB.dat";
    uStack_5c = 7;
    pcStack_58 = "unknown";
    puStack_54 = (undefined4 *)0x2;
    FUN_005f6540(auStack_4c,8,0x784ff00,&DAT_0075f48c,&uStack_64);
    auStack_4c[0] = 0;
    puStack_54 = &DAT_019c5ca0;
    iStack_14 = FUN_005fdbd0(auStack_4c,8,0x784ff01,&DAT_0075f488,&puStack_54,&DAT_0078b2bc);
    if (iStack_14 == 0) {
      puStack_54 = &DAT_019c5c9c;
      iStack_14 = FUN_005fe110(auStack_4c,&DAT_0075f488,&puStack_54);
      if (iStack_14 == 0) {
        puStack_54 = &DAT_019c5c98;
        iStack_14 = FUN_005fe110(auStack_4c,&DAT_0075f488,&puStack_54);
        if (iStack_14 == 0) {
          puStack_54 = &DAT_019c5c94;
          iStack_14 = FUN_005fe110(auStack_4c,&DAT_0075f484,&puStack_54);
        }
      }
    }
    if (iStack_14 == 0) {
      auStack_4c[0] = 0;
      FUN_005f7950(auStack_4c,8,0x784ff00,&DAT_0075f480,0);
    }
    break;
  case 4:
    _DAT_007d136c = DAT_01fbb780;
    _DAT_007d1368 = DAT_01fbb784;
    _DAT_007d1364 = DAT_01fbb788;
    _DAT_007d1360 = DAT_01fbb78c;
    uStack_8 = 0;
    goto LAB_00413574;
  case 5:
    _DAT_007d135c = *(float *)(&DAT_0078b2d0 + DAT_019c5ca4 * 4);
    _DAT_007d136c = (int)ROUND(_DAT_007d135c * DAT_019c5ca0);
    _DAT_007d1368 = (int)ROUND(_DAT_007d135c * DAT_019c5c9c);
    _DAT_007d1364 = (int)ROUND(_DAT_007d135c * DAT_019c5c98);
    puStack_54 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
    _DAT_007d1360 = (int)ROUND(_DAT_007d135c * DAT_019c5c94);
    iStack_50 = _DAT_007d1360;
LAB_00413574:
    FUN_00413608(&DAT_007d136c,&DAT_007d1368,&DAT_007d1364,&DAT_007d1360);
  }
  return;
}


