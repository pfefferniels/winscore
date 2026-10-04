// FUN_0056b706 @ 0056b706 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0056b706(int param_1)

{
  if (0x59 < IP8) {
    DAT_01cadce4 = IP8;
  }
  DAT_0078b6a0 = DAT_01cadce4 % 1000;
  DAT_01cadce4 = DAT_01cadce4 % 100;
  if (DAT_01cadce4 == 0x5e) {
    P14 = *(float *)(param_1 + 0x14);
    P15._0_1_ = *(undefined1 *)(param_1 + 0x18);
  }
  else if (DAT_01cadce4 < 100) {
    load_font_metrics();
  }
  return;
}


