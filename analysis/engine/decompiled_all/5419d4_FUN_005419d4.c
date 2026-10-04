// FUN_005419d4 @ 005419d4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005419d4(int *param_1,int *param_2)

{
  float10 fVar1;
  
  DAT_0099e9f8 = 0;
  DAT_0099e9f4 = f_1;
  if ((float)(&ITEM_P1)[*param_1] == f_1) {
    DAT_0099e9f0 = (int)ROUND((float)(&ITEM_P6)[*param_1]);
    if (DAT_0099e9f0 == 1) {
      DAT_0099e9f4 = f_2;
    }
    if (DAT_0099e9f0 == 2) {
      DAT_0099e9f4 = f_4;
    }
    if (8 < *param_2) {
      DAT_0099e9ec = (int)ROUND(*(float *)(&ITEM_P9 + *param_1 * 4));
      if (DAT_0099e9ec < 0) {
        DAT_0099e9ec = 0;
      }
      DAT_0099e9f8 = DAT_0099e9ec / 10;
      _DAT_0099e9e8 = (float)(DAT_0099e9ec % 10);
      if (_DAT_0099e9e8 != f_0) {
        DAT_0099e9f4 = f_0_5 / _DAT_0099e9e8;
      }
    }
  }
  else {
    DAT_0099e9f0 = (int)ROUND((float)(&ITEM_P5)[*param_1]);
    fVar1 = (float10)FUN_00608dc0(f_2,DAT_0099e9f0 + 2);
    DAT_0099e9f4 = (float)((float10)f_4 / fVar1);
  }
  if (DAT_0099e9f8 == 1) {
    DAT_0099e9f4 = DAT_0099e9f4 / f_2 + DAT_0099e9f4;
  }
  *(float *)(&ITEM_P7 + *param_1 * 4) = DAT_0099e9f4;
  return;
}


