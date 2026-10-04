// FUN_004277c9 @ 004277c9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004277c9(int *param_1,int *param_2)

{
  int iVar1;
  
  _DAT_007d31f0 = (float)((*param_2 - VIEW_DX) / 0x96);
  DAT_007d31ec = 1;
  _DAT_007d31f4 = f_99999;
  for (iVar1 = DAT_01e6078c; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_007d31e8 = ABS(_DAT_007d31f0 - (float)(&DAT_01e6078c)[DAT_007d31ec]);
    if (DAT_007d31e8 < _DAT_007d31f4) {
      _DAT_007d31f4 = DAT_007d31e8;
      *param_1 = DAT_007d31ec;
    }
    DAT_007d31ec = DAT_007d31ec + 1;
  }
  *param_1 = *param_1 + -1;
  return;
}


