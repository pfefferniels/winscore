// FUN_005358e5 @ 005358e5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_005358e5(int *param_1)

{
  undefined4 uVar1;
  
  DAT_0099a7ec = *param_1;
  DAT_0099a7e8 = (int)ROUND((float)(&ITEM_LEN)[DAT_0099a7ec]);
  if ((DAT_0099a7e8 < 0xe) ||
     ((*(float *)(&ITEM_P14 + DAT_0099a7ec * 4) == f_0 &&
      ((DAT_0099a7e8 < 0xf || (*(float *)(&ITEM_P15 + DAT_0099a7ec * 4) == f_0)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


