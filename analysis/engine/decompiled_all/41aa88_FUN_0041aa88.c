// FUN_0041aa88 @ 0041aa88 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041aa88(void)

{
  if (DAT_01fbb8a0 == 3) {
    if ((P2 == f_0) && (P3 == f_0)) {
      P2 = DAT_01fbb868;
      P3 = DAT_01fbb86c;
    }
    else if (P3 == f_0) {
      if ((DAT_01fbb8a4 == 10) && (P4 == f_0)) {
        P4 = P2;
        P2 = f_0;
      }
      P3 = P2 + DAT_01fbb86c;
      P2 = P2 + DAT_01fbb868;
    }
LAB_0041ae4e:
    DAT_01a14950 = (int)ROUND(P2 * f_150);
    DAT_01a14948 = (int)ROUND(P3 * f_150);
    if (DAT_01fbb8b8 < P1) {
      DAT_01a14950 = DAT_01a14950 + 34000;
      DAT_01a14948 = DAT_01a14948 + 34000;
    }
  }
  else {
    if (DAT_01fbb8a0 == 8) {
      if (P2 == f_0) {
        P2 = f_1;
      }
      DAT_01a1494c = ((&STAFF_MID0)[(int)ROUND(P1)] - VIEW_DY) + -1000;
      DAT_01a14944 = ((&STAFF_MID0)[(int)ROUND((P2 + P1) - f_1)] - VIEW_DY) + 1000;
      DAT_01a14950 = 0;
      DAT_01a14948 = RIGHT_LIMIT;
      if (DAT_01fbb8b8 < P1) {
        DAT_01a14950 = 34000;
        DAT_01a14948 = 64000;
      }
      P4 = (P2 + P1) - f_1;
      P2 = f_0;
      P3 = DAT_01fbb8b8;
      goto LAB_0041afb4;
    }
    if (DAT_01fbb8a0 == 9) {
      if (P2 == f_0) {
        P2 = f_1;
      }
      P4 = (P2 + P1) - f_1;
      DAT_01a14950 = -1000;
      DAT_01a14948 = 31000;
      if (DAT_01fbb8b8 < P1) {
        DAT_01a14950 = 33000;
        DAT_01a14948 = 65000;
      }
    }
    else {
      if ((P2 != f_0) || (P3 != f_0)) {
        if ((DAT_01fbb8a0 == 3) && (P3 == f_0)) {
          P3 = P2 + DAT_01fbb86c;
          P2 = P2 + DAT_01fbb868;
        }
        goto LAB_0041ae4e;
      }
      DAT_01a14950 = -1000;
      DAT_01a14948 = 31000;
      if (DAT_01fbb8b8 < P1) {
        DAT_01a14950 = 33000;
        DAT_01a14948 = 65000;
      }
      if (P1 == f_0) {
        P1 = f_1;
        P4 = DAT_01fbb8b8 - f_1;
      }
      P2 = f_0;
      P3 = DAT_01fbb8b8;
      if (DAT_01fbb8a0 == 10) {
        P4 = (float)(DAT_01fbb864 - DAT_01fbb860) + P1;
      }
    }
  }
  DAT_01a14944 = ((&STAFF_MID0)[(int)ROUND(P1)] - VIEW_DY) + -1000;
  if ((P4 == f_0) || (DAT_01fbb8a0 == 2 && DAT_01fbb8a4 == 10)) {
    P4 = P1;
  }
  DAT_01a1494c = ((&STAFF_MID0)[(int)ROUND(P4)] - VIEW_DY) + 1000;
LAB_0041afb4:
  _DAT_007d1554 = 1;
  if (DAT_01fbb8a0 == 3) {
    _DAT_007d1554 = 2;
  }
  DAT_01fbb8ac = DAT_01a14950;
  DAT_01fbb8b0 = DAT_01a14948;
  FUN_0041b6c4(&DAT_007d1554);
  DAT_01a14948 = 0;
  DAT_01a14944 = 0;
  return;
}


