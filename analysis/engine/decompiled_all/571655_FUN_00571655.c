// FUN_00571655 @ 00571655 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00571655(int param_1)

{
  if (0x59 < IP8) {
    DAT_01cadce4 = IP8;
  }
  DAT_0078b6a0 = DAT_01cadce4 % 1000;
  DAT_01cadce4 = DAT_01cadce4 % 100;
  if (DAT_01cadce4 < 0x5a) {
    load_font_metrics();
  }
  else if (DAT_01cadce4 != 99) {
    param_1 = DAT_01cadce4 * 5 + param_1;
    P14 = *(float *)(param_1 + -0x1c2);
    P15._0_1_ = *(undefined1 *)(param_1 + -0x1be);
  }
  return;
}


