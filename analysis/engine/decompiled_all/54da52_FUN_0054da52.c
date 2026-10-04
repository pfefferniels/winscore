// FUN_0054da52 @ 0054da52 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054da52(int param_1)

{
  DAT_009a2aa4 = 1;
  do {
    if ((*(char *)(param_1 + -1 + DAT_009a2aa4) == '|') &&
       (*(char *)(param_1 + DAT_009a2aa4) == '|')) {
      *(undefined1 *)(param_1 + -1 + DAT_009a2aa4) = 0xd;
      DAT_009a2aa4 = DAT_009a2aa4 + 1;
      *(undefined1 *)(param_1 + -1 + DAT_009a2aa4) = 10;
    }
    DAT_009a2aa4 = DAT_009a2aa4 + 1;
  } while (DAT_009a2aa4 < 0xa1);
  return;
}


