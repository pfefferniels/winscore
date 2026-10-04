// FUN_0053bfc6 @ 0053bfc6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053bfc6(int *param_1,float *param_2,float *param_3)

{
  unkbyte10 in_ST0;
  unkbyte10 Var1;
  
  DAT_0099ca0c = *param_1;
  IP8 = 0;
  P17 = f_0;
  ffree(in_ST0);
  push_words(&DAT_00768b28,&P5);
  P5 = (float)DAT_0099ca0c;
  P18 = f_0;
  P9 = f_0;
  if (IP14 != 0) {
    if (IP14 < 0) {
      IP14 = -IP14;
    }
    if (999 < IP14) {
      IP14 = IP14 + -1000;
    }
    IP7 = IP14 + 1000;
    if (IP14 == 0x22) {
      IP7 = 1000;
    }
  }
  P14 = f_0;
  P15 = f_0;
  if (DAT_0099ca0c < 10) {
    _DAT_0099ca08 = f_7_1;
  }
  else {
    _DAT_0099ca08 = f_14_5;
    if (DAT_0099ca0c < 0x14) {
      _DAT_0099ca08 = f_13_5;
    }
    if (DAT_0099ca0c == 0xb) {
      _DAT_0099ca08 = f_12;
    }
  }
  X_POS = (float)(((float10)*param_2 + (float10)*param_3) - (float10)STEP * (float10)_DAT_0099ca08);
  ffree((float10)*param_2 + (float10)*param_3);
  Var1 = draw_number(&DAT_0099ca0c);
  ffree(Var1);
  Var1 = pop_words(&DAT_00768b28,&P5);
  ffree(Var1);
  return;
}


