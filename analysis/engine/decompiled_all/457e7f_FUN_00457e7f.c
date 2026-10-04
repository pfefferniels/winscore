// FUN_00457e7f @ 00457e7f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00457e7f(int *param_1)

{
  DAT_007feca8 = DAT_01c17df0;
  if (*param_1 == 0) {
    DAT_007feca4 = 3;
    if (DAT_01c17df0 == 1) {
      DAT_007feca4 = 5;
    }
    if (DAT_01c17df0 == 2) {
      DAT_007feca4 = 6;
    }
    if (DAT_01c17df0 == 4) {
      DAT_007feca4 = 7;
    }
    if (4 < (int)DAT_01c17df0) {
      DAT_007feca4 = DAT_01c17df0;
    }
    FUN_004584ba();
  }
  else {
    DAT_007feca4 = (uint)(DAT_01c17df0 == 5);
    if (DAT_01c17df0 == 6) {
      DAT_007feca4 = 2;
    }
    if (DAT_01c17df0 == 7) {
      DAT_007feca4 = 4;
    }
  }
  DAT_01c17df0 = DAT_007feca4;
  return;
}


