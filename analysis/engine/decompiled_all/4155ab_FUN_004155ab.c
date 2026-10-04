// FUN_004155ab @ 004155ab (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004155ab(float *param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = (DAT_01f95c8c - DAT_01f95c88) + 1;
  _DAT_007d13e4 = f_0;
  DAT_01f95c84 = DAT_01f95c88;
  do {
    if (iVar1 < 1) {
      return;
    }
    if (DAT_0078deb0 != *(int *)(&DAT_01f9929c + DAT_01f95c84 * 4)) {
      DAT_0078deb4 = (float)(&DAT_01f95d4c)[*(int *)(&DAT_01f995bc + DAT_01f95c84 * 4) * 0xf];
      if (DAT_0078deb4 == *param_1) {
        if (_DAT_007d13e4 != f_0) {
          _DAT_007d13e4 = f_3;
          return;
        }
        _DAT_007d13e4 = f_1;
      }
      else if (DAT_0078deb4 == *param_2) {
        if (_DAT_007d13e4 != f_0) {
          _DAT_007d13e4 = f_3;
          return;
        }
        _DAT_007d13e4 = f_2;
      }
    }
    DAT_01f95c84 = DAT_01f95c84 + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


