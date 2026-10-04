// FUN_004ef47d @ 004ef47d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004ef47d(void)

{
  DAT_01be6c64 = DAT_01be6c64 + -1;
  if (DAT_01be6c64 < 1) {
    DAT_01be6c64 = 1;
  }
  if (DAT_01be6c84 == 4) {
    DAT_01be6c84 = 1;
  }
  if (DAT_01be6c84 == 5) {
    DAT_01be6c84 = 4;
  }
  DAT_01be6c7c = (int)*(short *)(DAT_01be6c64 * 0x28 + DAT_01be6c84 * 10 + DAT_01be6c74 * 2 +
                                0x794cd0);
  return;
}


