// FUN_00535693 @ 00535693 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00535693(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((LOAD_CODE == 0x12) && (3 < LOAD_LEN)) {
    _DAT_0099a7d0 = f_1;
    if ((6 < LOAD_LEN) && (*(float *)(&ITEM_P7 + LOAD_W * 4) != f_0)) {
      _DAT_0099a7d0 = *(float *)(&ITEM_P7 + LOAD_W * 4);
    }
    if (f_2 < ABS(_DAT_0099a7d0 * (float)(&ITEM_P4)[LOAD_W])) {
      uVar1 = 1;
    }
  }
  return uVar1;
}


