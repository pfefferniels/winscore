// FUN_00476063 @ 00476063 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00476063(int *param_1)

{
  if (0 < DAT_00795470) {
    DAT_00827010 = DAT_00795460;
    if (DAT_0079546c == 0) {
      DAT_0082700c = f_1;
      if (DAT_00795460 % 2 != 0) {
        DAT_0082700c = f_197;
      }
    }
    else {
      DAT_0082700c = f_99_5;
      if (9 < DAT_00795460) {
        DAT_0082700c = f_98_3;
      }
      if (99 < DAT_00795460) {
        DAT_0082700c = f_96_6;
      }
    }
    *(float *)(&DAT_01ba213c + *param_1 * 4) = f_6;
    (&DAT_01ba2140)[*param_1] = f_10;
    (&DAT_01ba2144)[*param_1] = (float)((&DAT_01be0960)[DAT_01be12c8] * DAT_01c2cc24);
    (&DAT_01ba2148)[*param_1] = DAT_0082700c;
    (&DAT_01ba214c)[*param_1] = f_24;
    (&DAT_01ba2150)[*param_1] = (float)DAT_00827010;
    (&DAT_01ba2154)[*param_1] = f_201_1;
    *param_1 = *param_1 + 7;
    ITEM_I = ITEM_I + 1;
  }
  DAT_00795460 = DAT_00795460 + 1;
  return;
}


