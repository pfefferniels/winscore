// FUN_00571059 @ 00571059 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00571059(float *param_1)

{
  int iVar1;
  
  if (DAT_01cadce4 + -0x5e < 0) {
    if ((0x52 < DAT_01cadce4) && (DAT_01cadce4 < 0x58)) {
      DAT_01a27710 = DAT_01cadce4;
      return;
    }
LAB_00571138:
    DAT_01a1c840 = 3;
  }
  else if (DAT_01cadce4 + -0x5e < 1) {
    DAT_01a1c840 = 1;
  }
  else if (DAT_01cadce4 < 1000) {
    if (0xa1 < DAT_01cadce4) goto LAB_00571138;
    DAT_01a1c840 = 2;
  }
  else {
    if (9999 < DAT_01cadce4) {
      X_POS = (float)(DAT_01cadce4 * 0xf + -150000);
    }
    DAT_01a1c840 = 4;
  }
  _DAT_009a83c0 = IP5;
  iVar1 = thunk_FUN_0056daa0(&DAT_01a1c840);
  if (iVar1 == 1) {
    P6 = DAT_01c6da38;
    return;
  }
  if (iVar1 == 2) {
    if (DAT_01cadce4 < 10000) {
      FUN_00571655(param_1,5);
    }
    DAT_01a1c848 = 0;
    return;
  }
  if (iVar1 == 3) {
    DAT_01a1c848 = 0;
  }
  else {
    IP5 = 0x21;
    DAT_01a1c840 = -1;
    iVar1 = 0x21;
    DAT_009a83bc = 1;
    do {
      if (DAT_01cadce4 == *(int *)(DAT_009a83bc * 4 + 0x7a0204)) {
        IP5 = *(int *)(s_BODN0BODB0BODI0BDIB0MUSI0_007a0168 + DAT_009a83bc * 4 + 0x18);
        if ((0x16 < DAT_009a83bc) && (DAT_009a83bc != 0x21)) {
          P14 = (float)i_1329876802;
          P15._0_1_ = DAT_0076a468;
          DAT_01a1c840 = IP5;
          IP5 = IP5 + 0x5f;
        }
        goto LAB_0057128c;
      }
      DAT_009a83bc = DAT_009a83bc + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
    if (DAT_01cadce4 == 800) {
      DAT_0078d858 = f_1;
    }
    else {
LAB_0057128c:
      DAT_0078d858 = *(float *)(&DAT_01cac104 + DAT_00791440 * 0x288 + DAT_01cadce4 * 4);
    }
    _DAT_01c6da30 = DAT_0078d858 / (float)(&DAT_01c6da60)[IP5];
    P6 = _DAT_01c6da30 * DAT_01c6da38;
    if (IP5 < 0x4c) {
      thunk_FUN_0056beec();
      if (DAT_01a27710 == 0) {
        P6 = DAT_01c6da38;
        return;
      }
      DAT_01cadce4 = DAT_01a27710;
      DAT_01a27710 = 0;
    }
    else {
      if (-1 < DAT_01a1c840) {
        DAT_01cadce4 = DAT_01a1c840;
        goto LAB_0057137e;
      }
      DAT_01cadce4 = IP5;
    }
  }
  DAT_009a83b8 = P14;
  P14 = *param_1;
  P15._0_1_ = *(undefined1 *)(param_1 + 1);
LAB_0057137e:
  thunk_FUN_0056b529();
  P14 = DAT_009a83b8;
  P6 = DAT_01c6da38;
  return;
}


