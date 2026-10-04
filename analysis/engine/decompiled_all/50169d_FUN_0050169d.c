// FUN_0050169d @ 0050169d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050169d(void)

{
  int iVar1;
  
  DAT_00902888 = 1;
  DAT_0090288c = ITEM_WORDS;
  for (iVar1 = DAT_01ba2080; 0 < iVar1; iVar1 = iVar1 + -1) {
    (&ITEM_P2)[DAT_0090288c] = (float)DAT_00902888;
    (&ITEM_LEN)[DAT_0090288c] = f_5;
    (&ITEM_P1)[DAT_0090288c] = f_8;
    (&ITEM_P3)[DAT_0090288c] = f_0;
    (&ITEM_P4)[DAT_0090288c] = f_0;
    (&ITEM_P5)[DAT_0090288c] = f_0_9;
    DAT_0090288c = DAT_0090288c + 6;
    DAT_00902888 = DAT_00902888 + 1;
  }
  DAT_00902884 = thunk_FUN_0059b160(&DAT_00902890,&DAT_00902880);
  if (DAT_00902884 == 2) {
    DAT_0078b4e0 = 0x2d;
  }
  else {
    DAT_0090287c = (float)_DAT_00902898;
    if (DAT_0090287c < f_0) {
      DAT_0090287c = f_0;
    }
    else {
      DAT_00902888 = 1;
      for (iVar1 = DAT_01ba2080; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_P2)[DAT_0090288c] = (float)DAT_00902888;
        (&ITEM_LEN)[DAT_0090288c] = f_5;
        (&ITEM_P1)[DAT_0090288c] = f_3;
        (&ITEM_P3)[DAT_0090288c] = f_1;
        (&ITEM_P4)[DAT_0090288c] = f_0;
        (&ITEM_P5)[DAT_0090288c] = DAT_0090287c;
        DAT_0090288c = DAT_0090288c + 6;
        DAT_00902888 = DAT_00902888 + 1;
      }
    }
    if (DAT_0090289c != 0) {
      DAT_00902888 = 1;
      for (iVar1 = DAT_01ba2080; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_P2)[DAT_0090288c] = (float)DAT_00902888;
        (&ITEM_LEN)[DAT_0090288c] = f_6;
        (&ITEM_P1)[DAT_0090288c] = f_17;
        (&ITEM_P3)[DAT_0090288c] = f_2;
        (&ITEM_P4)[DAT_0090288c] = f_0;
        (&ITEM_P5)[DAT_0090288c] = (float)DAT_0090289c;
        (&ITEM_P6)[DAT_0090288c] = DAT_0090287c;
        DAT_0090288c = DAT_0090288c + 7;
        DAT_00902888 = DAT_00902888 + 1;
      }
    }
    if (DAT_00902890 != 0) {
      DAT_00902888 = 1;
      for (iVar1 = DAT_01ba2080; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_P2)[DAT_0090288c] = (float)DAT_00902888;
        (&ITEM_LEN)[DAT_0090288c] = f_6;
        (&ITEM_P1)[DAT_0090288c] = f_18;
        (&ITEM_P3)[DAT_0090288c] = f_3;
        (&ITEM_P4)[DAT_0090288c] = f_0;
        (&ITEM_P5)[DAT_0090288c] = (float)DAT_00902890;
        (&ITEM_P6)[DAT_0090288c] = (float)_DAT_00902894;
        DAT_0090288c = DAT_0090288c + 7;
        DAT_00902888 = DAT_00902888 + 1;
      }
    }
    ITEM_WORDS = DAT_0090288c;
  }
  return;
}


