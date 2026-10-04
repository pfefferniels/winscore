// FUN_004e7380 @ 004e7380 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e7380(void)

{
  int iVar1;
  int iVar2;
  
  _DAT_01e66cc4 = P1;
  DAT_01e66cc8 = P2;
  DAT_01e66ccc = P3;
  _DAT_01e66cd0 = P4;
  DAT_01e66cc0 = DAT_01e66cc0 + 1;
  _DAT_01e66cd4 = DAT_01a14950;
  _DAT_01e66cd8 = DAT_01a1494c;
  _DAT_01e66cdc = DAT_01a14948;
  _DAT_01e66ce0 = DAT_01a14944;
  DAT_01fbb874 = 0xffffffff;
  DAT_01fbb868 = P2;
  DAT_01fbb86c = P3;
  DAT_01fbb860 = (int)ROUND(P1);
  DAT_01fbb864 = (int)ROUND(P4);
  DAT_01fbb87c = ITEM_WORDS;
  thunk_FUN_0049b1d8();
  if (DAT_020492a0 != 0) {
    while( true ) {
      _DAT_008d110c = DAT_01e66ccc - DAT_01e66cc8;
      DAT_008d1108 = 1;
      DAT_019c6ae4 = DAT_01e66cc8;
      DAT_019c6adc = DAT_01e66ccc;
      for (iVar1 = DAT_020492a4; DAT_01e66cc8 = DAT_019c6ae4, DAT_01e66ccc = DAT_019c6adc, 0 < iVar1
          ; iVar1 = iVar1 + -1) {
        iVar2 = (&DAT_020492a4)[DAT_008d1108];
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        (&DAT_01e9997c)[DAT_008d1108] = iVar2;
        _DAT_008d1104 = (float)(&ITEM_LEN)[(&DAT_01e9997c)[DAT_008d1108]];
        *(float *)(DAT_008d1108 * 4 + 0x1e9e79c) = (_DAT_008d1104 - DAT_01e66cc8) / _DAT_008d110c;
        DAT_008d1108 = DAT_008d1108 + 1;
        DAT_019c6ae4 = DAT_01e66cc8;
        DAT_019c6adc = DAT_01e66ccc;
      }
      DAT_019c6ad8 = DAT_00794b7c;
      DAT_019c6ae0 = DAT_00794b80;
      DAT_008d1100 = thunk_FUN_0059b2a0();
      if (DAT_008d1100 == 2) break;
      if ((DAT_019c6ae0 != f_0) || (DAT_019c6ad8 != f_0)) {
        DAT_0078b4f0 = 1;
      }
      DAT_01e66cc8 = DAT_019c6ae0 + DAT_01e66cc8;
      DAT_01e66ccc = DAT_019c6ad8 + DAT_01e66ccc;
      DAT_01a14950 = (int)ROUND(DAT_01e66cc8 * f_150);
      DAT_01a14948 = (int)ROUND(DAT_01e66ccc * f_150);
      _DAT_008d10fc = DAT_01e66ccc - DAT_01e66cc8;
      DAT_008d1108 = 1;
      DAT_00794b80 = DAT_019c6ae0;
      DAT_00794b7c = DAT_019c6ad8;
      DAT_01a1494c = DAT_01e66ca4;
      DAT_01a14944 = DAT_01e66cac;
      for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_LEN)[(&DAT_01e9997c)[DAT_008d1108]] =
             _DAT_008d10fc * *(float *)(DAT_008d1108 * 4 + 0x1e9e79c) + DAT_01e66cc8;
        DAT_008d1108 = DAT_008d1108 + 1;
      }
      draw_items();
      thunk_FUN_0041b6c4(&DAT_00766024);
      thunk_FUN_00549422();
    }
    DAT_01e66cc0 = 0;
    DAT_020b8ea0._0_1_ = DAT_00766020;
    DAT_008d1100 = 2;
  }
  return;
}


