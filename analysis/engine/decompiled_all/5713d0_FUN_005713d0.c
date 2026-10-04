// FUN_005713d0 @ 005713d0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005713d0(float *param_1)

{
  int iVar1;
  
  if (DAT_01cadce4 == 0x5e) {
    return;
  }
  DAT_009a83cc = P14;
  DAT_009a83d0 = P15._0_1_;
  if (DAT_01cadce4 < 0x58) {
    if (DAT_01cadce4 < 0x46) {
      DAT_01a1c840 = DAT_0078b6a0 % 100;
      if ((DAT_01a1c840 < 0x5a) || (0x61 < DAT_01a1c840)) {
        IP5 = DAT_01cadce4;
        thunk_FUN_0056beec();
        return;
      }
      goto LAB_00571577;
    }
  }
  else {
    if (999 < DAT_01cadce4) {
      if (DAT_01cadce4 < 10000) {
        FUN_00571655(param_1,5);
        return;
      }
      X_POS = (float)(DAT_01cadce4 * 0xf + -150000);
      return;
    }
    if (((0x5e < DAT_01cadce4) && (DAT_01cadce4 != 0x92)) && (DAT_01cadce4 < 0xa2)) {
      iVar1 = thunk_FUN_0056b7ae(&P14,5);
      if (iVar1 == 0) {
        _DAT_009a83c8 = DAT_0078b6a0 % 100;
        return;
      }
      goto LAB_00571577;
    }
  }
  P14 = *param_1;
  P15._0_1_ = *(undefined1 *)(param_1 + 1);
LAB_00571577:
  thunk_FUN_0056b529();
  P15._0_1_ = DAT_009a83d0;
  P14 = DAT_009a83cc;
  return;
}


