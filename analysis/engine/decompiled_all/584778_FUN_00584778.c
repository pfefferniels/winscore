// FUN_00584778 @ 00584778 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00584778(void)

{
  int iVar1;
  
  DAT_009a9104 = 0;
  DAT_01be0960 = 0;
  for (; (&DAT_01b11800)[DAT_01b11800] == 0; DAT_01b11800 = DAT_01b11800 + -1) {
  }
  DAT_009a9100 = 1;
  for (iVar1 = DAT_01b11800 + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    if ((&DAT_01b11800)[DAT_009a9100] == 0) {
      DAT_01be0960 = DAT_01be0960 + 1;
      (&DAT_01be0960)[DAT_01be0960] = DAT_009a9104;
      DAT_009a9104 = 0;
    }
    else {
      DAT_009a9104 = DAT_009a9104 + 1;
    }
    DAT_009a9100 = DAT_009a9100 + 1;
  }
  DAT_009a9100 = 1;
  for (iVar1 = DAT_01ba0d84; 0 < iVar1; iVar1 = iVar1 + -1) {
    (&DAT_01ba0d84)[DAT_009a9100] = (int)((float)(&DAT_01ba0d84)[DAT_009a9100] + f_0_01);
    DAT_009a9100 = DAT_009a9100 + 1;
  }
  thunk_FUN_00501a98();
  if (DAT_0078b4e0 != 0x2d) {
    ITEM_WORDS = 1;
    DAT_01ba0c60 = 0;
    DAT_009a9104 = 1;
    DAT_01ba207c = 0;
    DAT_01ba206c = 0;
    DAT_01ba2078 = 0;
    DAT_01ba2074 = 0;
    DAT_01ba0d38 = (float)DAT_01ba0d30;
    if (DAT_0078b4e8 != 0) {
      DAT_01be0954 = DAT_01be0954 / f_2_54;
    }
    DAT_01be12c8 = 0;
    _DAT_009a90fc = DAT_01be094c;
    while( true ) {
      if (DAT_009a9104 != DAT_01ba0c60) {
        if (DAT_01be0960 <= DAT_01be12c8) {
          return;
        }
        DAT_01be12c8 = DAT_01be12c8 + 1;
        DAT_00795464 = (&DAT_01be0960)[DAT_01be12c8] * DAT_01c58604;
        DAT_01be094c = _DAT_009a90fc / (float)DAT_00795464;
        if (f_2 < DAT_01be094c / (float)DAT_01c58604) {
          DAT_01be094c = (float)(DAT_01c58604 * 2);
        }
        DAT_01c58608 = DAT_01c58604 * DAT_00795464;
      }
      DAT_009a9104 = DAT_01ba0c60 + 1;
      DAT_01ba2074 = (&DAT_01b11800)[DAT_009a9104];
      DAT_01ba206c = DAT_01ba2074 + DAT_01ba206c;
      DAT_01ba0c60 = DAT_009a9104;
      thunk_FUN_004998c0();
      if (ITEM_WORDS < 0) break;
      DAT_01ba2068 = 0;
    }
    return;
  }
  return;
}


