// FUN_0056ebb4 @ 0056ebb4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0056ebb4(void)

{
  DAT_01a2770c = 0x30;
  DAT_009a822c = DAT_01cadce4;
  if (DAT_01cadce4 < 0x28) {
    DAT_01a2770c = 0x32;
    DAT_009a822c = DAT_01cadce4 + 0x1e;
  }
  DAT_01a27718 = -0x53;
  if (DAT_009a822c == 0x2c) {
    DAT_01a27718 = -0x4b;
  }
  if (DAT_009a822c == 0x30) {
    DAT_01a27718 = -0x47;
  }
  if (DAT_009a822c == 0x35) {
    DAT_01a27718 = -0x3e;
  }
  if (DAT_009a822c == 0x36) {
    DAT_01a27718 = -0x43;
  }
  if (DAT_009a822c == 0x3c) {
    DAT_01a27718 = -0x3e;
  }
  if (0x3f < DAT_009a822c) {
    DAT_01a27718 = -0x3d;
  }
  DAT_01a27718 = (DAT_01a27710 + DAT_01a27718) % 8 + ((DAT_01a27710 + DAT_01a27718) / 8) * 10;
  return;
}


