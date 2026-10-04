// FUN_0046f6c0 @ 0046f6c0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0046f6c0(int *param_1)

{
  if (f_0 < *(float *)(&DAT_020b943c + *param_1 * 4)) {
    DAT_01be6c60 = *param_1;
    DAT_01be6c64 = P48;
    FUN_0046f726();
    if (DAT_01be6c60 == 2) {
      *(float *)(&P0 + DAT_01f95c8c * 4) = DAT_01be6c64;
    }
  }
  return;
}


