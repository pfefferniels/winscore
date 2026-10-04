// FUN_004681c0 @ 004681c0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004681c0(int *param_1)

{
  int iVar1;
  float10 in_ST0;
  
  if (((char)DAT_020b8ea0 == 'U') || ((char)DAT_020b8ea0 == 'D')) {
    if ((DAT_0078b4e4 == 0x50) || ((DAT_0078b4e4 == 0x49 || (DAT_0078b4e4 == 0x43)))) {
      DAT_00824640 = f_0_00175;
      if (DAT_0078b4e4 == 0x43) {
        DAT_00824640 = f_0_004445;
      }
      if (DAT_0078b4e4 == 0x50) {
        DAT_00824640 = f_0_126;
      }
      P2 = P2 / (DAT_00824640 * STEP);
    }
    DAT_00824644 = DAT_00790b34;
    if (*param_1 < 1) {
      if (DAT_00790b34 == f_0) {
        DAT_00824644 = f_1;
      }
      if ((DAT_020b8ea0._1_1_ == '*') || (DAT_020b8ea2 == '*')) {
        DAT_00824644 = P2;
      }
      if (DAT_020b8ea0._1_1_ == (char)DAT_020b8ea0) {
        DAT_00824644 = f_0_5;
      }
      if (DAT_020b8ea2 == (char)DAT_020b8ea0) {
        DAT_00824644 = f_0_2;
      }
    }
    DAT_00824640 = DAT_00824644;
    if (*param_1 == 1) {
      DAT_00824640 = DAT_0078d840;
    }
    if ((char)DAT_020b8ea0 == 'D') {
      in_ST0 = (float10)DAT_00824640;
      DAT_00824640 = (float)-in_ST0;
    }
    P1 = f_400;
    P2 = DAT_00824640;
    if (DAT_0078dc30 == 2) {
      P1 = f_2;
      P2 = DAT_020b9444;
    }
    P3 = f_0;
    DAT_00790b34 = DAT_00824644;
    if ((((DAT_0078dc30 != 1) && (DAT_020b9450 != f_999)) && (3 < DAT_020b8e50)) &&
       (DAT_020b8e50 < 7)) {
      P3 = f_500;
      P4 = DAT_00824640;
      P5 = f_0;
    }
    if (((DAT_0078dc30 == 0) && (DAT_020b8e50 == 4)) && (DAT_020b9458 == f_100)) {
      P5 = f_900;
      P6 = DAT_00824640;
      P7 = f_1100;
      P8 = DAT_00824640;
      P9 = f_1300;
      P10 = DAT_00824640;
      P11 = f_1500;
      P12 = DAT_00824640;
      P13 = f_1700;
      P14 = DAT_00824640;
    }
  }
  else {
    if (((DAT_0078b4e4 == 0x50) || (DAT_0078b4e4 == 0x49)) || (DAT_0078b4e4 == 0x43)) {
      _DAT_00824648 = f_0_0375;
      if (DAT_0078b4e4 == 0x43) {
        _DAT_00824648 = f_0_09525;
      }
      if (DAT_0078b4e4 == 0x50) {
        _DAT_00824648 = f_2_7;
      }
      P2 = P2 / _DAT_00824648;
    }
    DAT_00824644 = DAT_00790b30;
    if (*param_1 < 1) {
      if (DAT_00790b30 == f_0) {
        DAT_00824644 = f_1;
      }
      if ((DAT_020b8ea0._1_1_ == '*') || (DAT_020b8ea2 == '*')) {
        DAT_00824644 = P2;
      }
      if (DAT_020b8ea0._1_1_ == (char)DAT_020b8ea0) {
        DAT_00824644 = f_0_5;
      }
      if (DAT_020b8ea2 == (char)DAT_020b8ea0) {
        DAT_00824644 = f_0_2;
      }
    }
    DAT_00824640 = DAT_00824644;
    if (*param_1 == 1) {
      DAT_00824640 = DAT_0078d840;
    }
    if ((char)DAT_020b8ea0 == 'L') {
      in_ST0 = (float10)DAT_00824640;
      DAT_00824640 = (float)-in_ST0;
    }
    DAT_0082463c = 1;
    iVar1 = 6;
    DAT_00824638 = 1;
    do {
      DAT_00824634 = *(int *)(DAT_00824638 * 4 + 0x78d81c);
      if ((DAT_00824634 != 0) &&
         ((((DAT_020b8e50 != 4 || (DAT_020b9458 != f_m1)) || (DAT_020b9454 != f_0)) ||
          ((DAT_00824634 != 6 || (DAT_0078dc30 != 2)))))) {
        *(float *)(&P0 + DAT_0082463c * 4) = (float)(DAT_00824634 * 100);
        (&P1)[DAT_0082463c] = DAT_00824640;
        DAT_0082463c = DAT_0082463c + 2;
      }
      DAT_00824638 = DAT_00824638 + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
    *(float *)(&P0 + DAT_0082463c * 4) = f_0;
    DAT_00790b30 = DAT_00824644;
    if (((DAT_0078dc30 == 0) && (DAT_020b8e50 == 4)) && (DAT_020b9458 == f_100)) {
      *(float *)(&P0 + DAT_0082463c * 4) = f_800;
      (&P1)[DAT_0082463c] = DAT_00824640;
      (&P2)[DAT_0082463c] = f_1000;
      (&P3)[DAT_0082463c] = DAT_00824640;
      (&P4)[DAT_0082463c] = f_1200;
      (&P5)[DAT_0082463c] = DAT_00824640;
      (&P6)[DAT_0082463c] = f_1400;
      (&P7)[DAT_0082463c] = DAT_00824640;
      (&P8)[DAT_0082463c] = f_1600;
      (&P9)[DAT_0082463c] = DAT_00824640;
    }
  }
  P15 = f_0;
  DAT_020b8ea0._0_1_ = DAT_00761c44;
  ffree(in_ST0);
  return;
}


