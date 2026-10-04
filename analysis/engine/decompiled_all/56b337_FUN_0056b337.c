// FUN_0056b337 @ 0056b337 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056b337(float *param_1)

{
  int iVar1;
  
  if (DAT_01cadce4 == 0x5e) {
    return;
  }
  DAT_009a7fb8 = P14;
  DAT_009a7fbc = P15._0_1_;
  if (DAT_01cadce4 < 0x58) {
    if (DAT_01cadce4 < 0x46) {
      if (((OUTPUT_MODE == 0) || (DAT_01a1c840 = DAT_0078b6a0 % 100, DAT_01a1c840 < 0x5a)) ||
         (0x61 < DAT_01a1c840)) {
        IP5 = DAT_01cadce4;
        FUN_0056beec();
        return;
      }
      goto LAB_0056b4ed;
    }
  }
  else {
    if (999 < DAT_01cadce4) {
      if (DAT_01cadce4 < 10000) {
        FUN_0056b706(param_1,5);
        return;
      }
      X_POS = (float)(DAT_01cadce4 * 0xf + -150000);
      return;
    }
    if (((0x5e < DAT_01cadce4) && (DAT_01cadce4 != 0x92)) && (DAT_01cadce4 < 0xa2)) {
      iVar1 = FUN_0056b7ae(&P14,5);
      if (iVar1 == 0) {
        _DAT_009a7fb4 = DAT_0078b6a0 % 100;
        return;
      }
      goto LAB_0056b4ed;
    }
  }
  P14 = *param_1;
  P15._0_1_ = *(undefined1 *)(param_1 + 1);
LAB_0056b4ed:
  FUN_0056b529();
  P15._0_1_ = DAT_009a7fbc;
  P14 = DAT_009a7fb8;
  return;
}


