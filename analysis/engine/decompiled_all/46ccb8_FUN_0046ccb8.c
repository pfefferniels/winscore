// FUN_0046ccb8 @ 0046ccb8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ccb8(void)

{
  float10 in_ST0;
  
  _DAT_020b8e66 = 0;
  if ((P1 == f_34) || (DAT_020b8ea0 == 0x5543)) {
    if ((DAT_020b9440 <= f_2) || (DAT_020b9440 == f_6)) {
      P8 = f_0;
      in_ST0 = (float10)DAT_020b944c;
      if (((ABS(in_ST0) < (float10)f_100) || (DAT_020b8ea2 == 'X')) &&
         ((in_ST0 = (float10)DAT_020b944c, (float10)f_100 <= ABS(in_ST0) || (DAT_020b8ea2 != 'X'))))
      {
        P8 = f_100;
        if (DAT_020b944c < f_0) {
          in_ST0 = (float10)f_100;
          P8 = (float)-in_ST0;
        }
        if (DAT_020b8ea2 == 'X') {
          in_ST0 = (float10)P8;
          P8 = (float)-in_ST0;
        }
      }
      P1 = f_4;
      P2 = P8 + DAT_020b944c;
      P3 = f_0;
    }
  }
  else if ((DAT_020b8e50 != 2) && (DAT_020b8ea0 == 0x4441)) {
    if (DAT_020b9458 < f_1) {
      P1 = f_0;
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_0040bc18();
      if (P1 != f_0) goto LAB_0046cf29;
    }
    DAT_0078b4e0 = 0;
    DAT_0078b4e4 = 0;
    _DAT_020b8e66 = 1;
  }
LAB_0046cf29:
  ffree(in_ST0);
  return;
}


