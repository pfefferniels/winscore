// FUN_0046f726 @ 0046f726 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0046f726(void)

{
  DAT_01f95c8c = DAT_01f95c8c + 2;
  *(float *)(&DAT_020b9358 + DAT_01f95c8c * 4) = (float)DAT_01be6c60;
  *(float *)(&P0 + DAT_01f95c8c * 4) = DAT_01be6c64 + *(float *)(&DAT_020b943c + DAT_01be6c60 * 4);
  return;
}


