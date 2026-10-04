// FUN_004aec88 @ 004aec88 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004aec88(void)

{
  int iVar1;
  
  DAT_01c589f0 = 0;
  DAT_0078b370 = 1;
  DAT_0078b374 = 0;
  DAT_0078b6a0 = 1;
  _DAT_0078b6a8 = 0;
  DAT_0089f0e0 = 0;
  _DAT_01c589f8 = f_1;
  _DAT_0089f0e4 = f_m27675;
  _DAT_01fb8c64 = f_999;
  DAT_020b8ea0._0_1_ = DAT_007642d4;
  for (iVar1 = MAX_STAFF + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    if (DAT_0089f0e0 == 0xc9) {
      _DAT_0089f0e4 = f_m24525;
    }
    (&STAFF_Y0)[DAT_0089f0e0] = (int)ROUND(_DAT_0089f0e4);
    (&STAFF_MID0)[DAT_0089f0e0] = (int)ROUND(_DAT_0089f0e4 + f_1225);
    _DAT_0089f0e4 = _DAT_0089f0e4 + f_3150;
    (&STAFF_STEP0)[DAT_0089f0e0] = f_25;
    DAT_0089f0e0 = DAT_0089f0e0 + 1;
  }
  ITEM_I = 0;
  EDIT_ITEM = 0;
  NPT = 1;
  DAT_02035a00 = 1;
  DAT_02091d20 = 1;
  DAT_020a55a0 = 1;
  ITEM_WORDS = 1;
  DAT_0078de10 = 200;
  _DAT_0089f0dc = 200;
  DAT_0078de00 = 1;
  DAT_0078de04 = 0;
  _DAT_0089f0d8 = 0;
  DAT_0078de08 = 0;
  DAT_01b12ca0 = 0;
  _DAT_01b12cac = 0;
  DAT_01b12ca4 = 0;
  DAT_01b12ca8 = 0;
  _DAT_01b12cb0 = 0;
  _DAT_01b12cb4 = 0;
  DAT_01b12cb8 = 0;
  _DAT_01b12c6c = 0;
  DAT_0089f0d4 = 1;
  DAT_0078de14 = DAT_007642c0;
  for (iVar1 = MAX_STAFF; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined4 *)(&DAT_01e67104 + DAT_0089f0d4 * 4) = 0;
    DAT_0089f0d4 = DAT_0089f0d4 + 1;
  }
  DAT_0078b4ec = 0;
  return;
}


