// FUN_004a5ac9 @ 004a5ac9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004a5ac9(int *param_1)

{
  if ((*param_1 == 1) || (*param_1 != 2)) {
    DAT_00839154 = DAT_01ae2860 - DAT_01be6c40;
    DAT_0078d920 = (DAT_01be6c48 * DAT_00839154) / 0x96;
    if (DAT_0078d920 < -99) {
      DAT_0078d920 = -99;
    }
    else if (DAT_0078d920 < 0xd8) {
      if (DAT_0078d924 + -3 <= DAT_0078d920) {
        DAT_0078d924 = DAT_0078d920 + 3;
      }
    }
    else {
      DAT_0078d920 = 0xd7;
    }
  }
  else {
    DAT_00839154 = DAT_01ae2864 - DAT_01be6c40;
    DAT_0078d924 = (DAT_01be6c48 * DAT_00839154) / 0x96;
    if (DAT_0078d924 < -0x60) {
      DAT_0078d924 = -0x60;
    }
    else if (DAT_0078d924 < 0xdb) {
      if (DAT_0078d924 <= DAT_0078d920 + 3) {
        DAT_0078d920 = DAT_0078d924 + -3;
      }
    }
    else {
      DAT_0078d924 = 0xda;
    }
  }
  return;
}


