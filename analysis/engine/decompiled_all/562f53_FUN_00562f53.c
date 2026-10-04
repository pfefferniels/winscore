// FUN_00562f53 @ 00562f53 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00562f53(int *param_1,int *param_2)

{
  DAT_01a1ad60 = *param_1;
  if (DAT_01a1ad60 < 0) {
    DAT_01a1ad60 = DAT_01a1ad60 + 7;
  }
  if (DAT_01a1ad60 % 2 != 0) {
    DAT_01a1ad60 = DAT_01a1ad60 + 7;
  }
  *param_2 = DAT_01a1ad60 / 2;
  return;
}


