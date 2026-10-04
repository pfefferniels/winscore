// FUN_0056ae82 @ 0056ae82 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056ae82(float *param_1)

{
  int iVar1;
  
  if (DAT_01cadce4 + -0x5e < 0) {
    if ((0x52 < DAT_01cadce4) && (DAT_01cadce4 < 0x58)) {
      DAT_01a27710 = DAT_01cadce4;
      return;
    }
LAB_0056b034:
    if (OUTPUT_MODE != 0) {
      DAT_01a1c840 = 3;
      iVar1 = thunk_FUN_0056daa0(&DAT_01a1c840);
      if (iVar1 == 1) {
        P6 = DAT_01c6da38;
        return;
      }
      if (iVar1 == 2) {
LAB_0056b075:
        if (DAT_01cadce4 < 10000) {
          FUN_0056b706(param_1,5);
        }
        DAT_01a1c848 = 0;
        return;
      }
      if (iVar1 == 3) goto LAB_0056b302;
    }
    if (DAT_01cadce4 < 0x46) {
      IP5 = DAT_01cadce4;
      DAT_01c6da38 = P6;
      DAT_01cadce4 = DAT_01cadce4 + 1;
      P6 = (P6 * *(float *)(&DAT_01cac100 + DAT_00791440 * 0x288 + DAT_01cadce4 * 4)) /
           *(float *)(&DAT_01c6da5c + DAT_01cadce4 * 4);
LAB_0056b288:
      FUN_0056beec();
      if (DAT_01a27710 == 0) {
        P6 = DAT_01c6da38;
        return;
      }
      DAT_01cadce4 = DAT_01a27710;
      DAT_01a27710 = 0;
    }
    else if (DAT_01cadce4 == 800) {
LAB_0056b132:
      IP5 = 0x21;
      DAT_01a1c840 = -1;
      iVar1 = 0x21;
      DAT_009a7fac = 1;
      do {
        if (DAT_01cadce4 == *(int *)(DAT_009a7fac * 4 + 0x79f810)) {
          IP5 = *(int *)(s_BODN0BODB0BODI0BDIB0MUSI0_0079f774 + DAT_009a7fac * 4 + 0x18);
          if ((0x16 < DAT_009a7fac) && (DAT_009a7fac != 0x21)) {
            P14 = (float)i_1329876802;
            P15._0_1_ = DAT_0076a1d8;
            DAT_01a1c840 = IP5;
            IP5 = IP5 + 0x5f;
          }
          goto LAB_0056b22e;
        }
        DAT_009a7fac = DAT_009a7fac + 1;
        iVar1 = iVar1 + -1;
      } while (0 < iVar1);
      if (DAT_01cadce4 == 800) {
        DAT_0078d858 = f_1;
      }
      else {
LAB_0056b22e:
        DAT_0078d858 = *(float *)(&DAT_01cac104 + DAT_00791440 * 0x288 + DAT_01cadce4 * 4);
      }
      _DAT_01c6da30 = DAT_0078d858 / (float)(&DAT_01c6da60)[IP5];
      P6 = _DAT_01c6da30 * DAT_01c6da38;
      if (IP5 < 0x4c) goto LAB_0056b288;
      if (-1 < DAT_01a1c840) {
        DAT_01cadce4 = DAT_01a1c840;
        goto LAB_0056b31d;
      }
      DAT_01cadce4 = IP5;
    }
  }
  else {
    if (DAT_01cadce4 + -0x5e < 1) {
      if (OUTPUT_MODE == 0) {
        P6 = DAT_01c6da38;
        return;
      }
      DAT_01a1c840 = 1;
      iVar1 = thunk_FUN_0056daa0(&DAT_01a1c840);
      if (iVar1 == 1) {
        P6 = DAT_01c6da38;
        return;
      }
      if (iVar1 == 2) goto LAB_0056b075;
      if (iVar1 != 3) goto LAB_0056aef9;
    }
    else {
LAB_0056aef9:
      if (DAT_01cadce4 < 1000) {
        if (0xa1 < DAT_01cadce4) goto LAB_0056b034;
        if (OUTPUT_MODE != 0) {
          DAT_01a1c840 = 2;
          iVar1 = thunk_FUN_0056daa0(&DAT_01a1c840);
          if (iVar1 == 1) {
            P6 = DAT_01c6da38;
            return;
          }
          if (iVar1 == 2) goto LAB_0056b075;
          if (iVar1 == 3) goto LAB_0056b302;
        }
        goto LAB_0056b132;
      }
      if (9999 < DAT_01cadce4) {
        X_POS = (float)(DAT_01cadce4 * 0xf + -150000);
      }
      if (OUTPUT_MODE == 0) goto LAB_0056b075;
      DAT_01a1c840 = 4;
      iVar1 = thunk_FUN_0056daa0(&DAT_01a1c840);
      if (iVar1 == 1) {
        P6 = DAT_01c6da38;
        return;
      }
      if ((iVar1 == 2) || (iVar1 != 3)) goto LAB_0056b075;
    }
LAB_0056b302:
    DAT_01a1c848 = 0;
  }
  P14 = *param_1;
  P15._0_1_ = *(undefined1 *)(param_1 + 1);
LAB_0056b31d:
  FUN_0056b529();
  P6 = DAT_01c6da38;
  return;
}


