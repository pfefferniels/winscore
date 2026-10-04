// FUN_004cf014 @ 004cf014 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


char * FUN_004cf014(char *param_1,undefined4 param_2,int *param_3)

{
  DAT_01aae32c = *param_3;
  if (DAT_01aae32c < 0) {
    DAT_01aae32c = -DAT_01aae32c;
  }
  if (DAT_01aae32c < 10) {
    DAT_01aae330 = 2;
  }
  else if (DAT_01aae32c < 100) {
    DAT_01aae330 = 3;
  }
  else if (DAT_01aae32c < 1000) {
    DAT_01aae330 = 4;
  }
  else if (DAT_01aae32c < 10000) {
    DAT_01aae330 = 5;
  }
  else {
    DAT_01aae330 = 6;
  }
  if (*param_3 < 0) {
    DAT_01aae330 = DAT_01aae330 + 1;
  }
  *param_1 = (char)DAT_01aae330 + '0';
  return param_1;
}


