// FUN_00468df8 @ 00468df8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00468df8(int *param_1)

{
  float10 in_ST0;
  unkbyte10 Var1;
  
  DAT_00824660 = *param_1;
  if (*param_1 < 0) {
    if (EDIT_ITEM == 0) {
      ffree(in_ST0);
      Var1 = thunk_FUN_005979a0(0x86);
      DAT_0082465c = 0;
    }
    else {
      DAT_00824660 = (&DAT_00790b34)[DAT_020b8e50];
      if (DAT_020b8e50 == 7) {
        DAT_00824660 = 0xc6;
        if ((((DAT_020b9458 == f_155) || (DAT_020b9458 == f_15)) ||
            (in_ST0 = (float10)DAT_020b9458, ABS(in_ST0) == (float10)f_8)) ||
           (in_ST0 = (float10)DAT_020b9458, ABS(in_ST0) == (float10)f_88)) {
          DAT_00824660 = 0xbe;
        }
        if (DAT_020b9458 == f_1) {
          DAT_00824660 = 0xc5;
        }
        if (DAT_020b9458 == f_0) {
          DAT_00824660 = 0xca;
        }
        if (DAT_0082465c != DAT_00824660) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_005979a0(DAT_00824660);
        }
        DAT_0082465c = DAT_00824660;
      }
      else if (DAT_020b8e50 == 0xc) {
        DAT_00824660 = 0xc3;
        if (f_1 < DAT_020b9450) {
          DAT_00824660 = 0xda;
        }
        if (DAT_020b9450 == f_10) {
          DAT_00824660 = 0xcc;
        }
        if (DAT_020b9450 < f_0) {
          DAT_00824660 = 0xcd;
        }
      }
      if ((_DAT_020b8ea0 & 0xffffff) == 0x525452) {
        DAT_0078b4e0 = 0;
        P1 = f_1;
        P2 = (float)DAT_020b8e50;
        P3 = f_0;
        DAT_0082465c = 0;
      }
      ffree(in_ST0);
      Var1 = thunk_FUN_005979a0(DAT_00824660);
      DAT_0082465c = DAT_00824660;
    }
  }
  else {
    ffree(in_ST0);
    Var1 = thunk_FUN_005979a0(DAT_00824660);
  }
  ffree(Var1);
  return;
}


