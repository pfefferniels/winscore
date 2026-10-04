// FUN_0042c51c @ 0042c51c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0042c51c(void)

{
  float10 in_ST0;
  
  if (DAT_020b945c < f_1) {
    DAT_007f1354 = DAT_020b9454 - DAT_020b9448;
    if ((DAT_020b945c < f_m1) && (f_m4 < DAT_020b945c)) {
      DAT_007f1354 = DAT_020b945c * f_2 + DAT_007f1354;
    }
    in_ST0 = (float10)DAT_007f1354 / (float10)f_20 + (float10)f_0_9;
    DAT_007f1354 = (float)(ABS((float10)DAT_020b9450 - (float10)DAT_020b944c) * (float10)f_0_1 +
                          in_ST0);
    if (DAT_020b9458 < f_0) {
      in_ST0 = (float10)DAT_007f1354;
      DAT_007f1354 = (float)-in_ST0;
    }
    P1 = f_7;
    P2 = DAT_007f1354;
    P3 = f_0;
  }
  ffree(in_ST0);
  return;
}


