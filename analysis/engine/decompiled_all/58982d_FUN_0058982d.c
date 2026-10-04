// FUN_0058982d @ 0058982d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058982d(int *param_1)

{
  if (9 < *param_1) {
    DAT_009a92d0 = (char)(*param_1 / 10) + '0';
    FUN_005898bc(&DAT_009a92d0,1);
    *param_1 = *param_1 % 10;
  }
  DAT_009a92d0 = (char)*param_1 + '0';
  FUN_005898bc(&DAT_009a92d0,1);
  return;
}


