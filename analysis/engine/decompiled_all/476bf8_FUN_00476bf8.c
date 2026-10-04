// FUN_00476bf8 @ 00476bf8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00476bf8(void)

{
  if (DAT_0078b374 != -1) {
    if (EDIT_ITEM == 0) {
      if ((DAT_020527d8 != 0x43) && (P2 == f_0)) {
        if (DAT_0078dca8 != DAT_0078dc78) {
          DAT_0078dc78 = DAT_0078dca8;
        }
        DAT_00790da4 = 0;
      }
    }
    else if (DAT_00790da4 == 0) {
      DAT_00790da4 = 1;
      DAT_0078dca8 = DAT_0078dc78;
      if ((-1 < DAT_0078dca4) && (DAT_0078dc78 != DAT_0078dca4)) {
        DAT_0078dc78 = DAT_0078dca4;
      }
    }
  }
  return;
}


