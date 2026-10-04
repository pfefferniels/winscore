// FUN_0055945e @ 0055945e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0055945e(undefined4 param_1,undefined4 param_2,float *param_3)

{
  DAT_009a3c64 = (int)ROUND(*param_3);
  IP3 = DAT_009a3c64 / 100;
  if (IP3 != 0) {
    FUN_005594eb(param_1);
  }
  IP3 = DAT_009a3c64 % 100;
  if (IP3 != 0) {
    FUN_005594eb(param_2);
  }
  return;
}


