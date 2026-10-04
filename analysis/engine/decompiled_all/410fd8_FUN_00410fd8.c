// FUN_00410fd8 @ 00410fd8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00410fd8(void)

{
  int iVar1;
  float10 in_ST0;
  
  if (DAT_01fb8cc8 == f_9) {
    DAT_01fb8cc8 = f_1_5;
  }
  _DAT_007d12c4 = DAT_01fb8cc8 / f_2;
  _DAT_007d12c0 = _DAT_007d12c4 - f_0_001;
  DAT_01fb8cb0 = (int)ROUND(DAT_01fb8ccc);
  DAT_01fb8cc0 = 0;
  DAT_01fb8ca4 = 0;
  DAT_01fb8cac = 0;
  if (DAT_01fb8cb0 != 0) {
    do {
      do {
        DAT_01fb8cac = DAT_01fb8cac + 1;
        if (DAT_01fb8c80 < DAT_01fb8cac) goto LAB_004115ab;
      } while (((f_2 < (float)(&DAT_01f95d44)[DAT_01fb8cac * 0xf]) ||
               (_DAT_01fb8ca0 = *(float *)(&DAT_0204929c + DAT_01fb8cac * 4), _DAT_01fb8ca0 == f_0))
              || (f_64 <= _DAT_01fb8ca0));
      if ((float)(&DAT_01f95d44)[DAT_01fb8cac * 0xf] == f_1) {
        DAT_01fb8ca4 = DAT_01fb8ca4 + 1;
      }
      DAT_01fb8cb0 = DAT_01fb8cb0 + -1;
    } while (0 < DAT_01fb8cb0);
  }
  DAT_01fb8ca8 = 0;
  DAT_01fb8cb4 = 0;
  do {
    DAT_01fb8ca8 = DAT_01fb8ca8 + 1;
    if ((((float)(&DAT_01f95d44)[DAT_01fb8ca8 * 0xf] == f_1) &&
        (_DAT_01fb8ca0 = *(float *)(&DAT_0204929c + DAT_01fb8ca8 * 4), _DAT_01fb8ca0 != f_0)) &&
       (iVar1 = DAT_01fb8cb4 + 1, DAT_01fb8cb4 = iVar1, f_64 <= _DAT_01fb8ca0)) {
      while (DAT_01fb8ca8 < DAT_01fb8c80) {
        DAT_01fb8ca8 = DAT_01fb8ca8 + 1;
        _DAT_01fb8ca0 = *(float *)(&DAT_0204929c + DAT_01fb8ca8 * 4);
        if (_DAT_01fb8ca0 != f_0) {
          if (_DAT_01fb8ca0 < f_64) break;
          if ((float)(&DAT_01f95d44)[DAT_01fb8ca8 * 0xf] == f_1) {
            DAT_01fb8cb4 = DAT_01fb8cb4 + 1;
          }
        }
      }
      ffree(in_ST0);
      DAT_01fb8cb0 = iVar1;
      in_ST0 = (float10)FUN_004115b4(&DAT_01fb8cb0,&DAT_01fb8cb4);
      if ((float)(&DAT_01f95d44)[DAT_01fb8ca8 * 0xf] == f_1) {
        DAT_01fb8cb4 = DAT_01fb8cb4 + 1;
      }
    }
  } while (DAT_01fb8ca8 < DAT_01fb8c80);
  _DAT_007d12bc = f_0;
  DAT_01fb8cb4 = DAT_01fb8ca4;
  DAT_01fb8cb8 = 0;
LAB_00411346:
  if (DAT_01fb8cac < DAT_01fb8c80) goto LAB_00411360;
  goto LAB_004114f8;
LAB_00411360:
  DAT_01fb8cac = DAT_01fb8cac + 1;
  if (((float)(&DAT_01f95d44)[DAT_01fb8cac * 0xf] <= f_2) &&
     (_DAT_01fb8ca0 = *(float *)(&DAT_0204929c + DAT_01fb8cac * 4), _DAT_01fb8ca0 != f_0)) {
    if ((float)(&DAT_01f95d44)[DAT_01fb8cac * 0xf] == f_2) {
      if (f_64 <= _DAT_01fb8ca0) goto LAB_00411346;
    }
    else {
      DAT_01fb8cb4 = DAT_01fb8cb4 + 1;
      if (f_64 <= _DAT_01fb8ca0) goto LAB_00411346;
      DAT_01fb8ca8 = (int)ROUND(*(float *)(&DAT_01f95d74 + DAT_01fb8cac * 0x3c));
      if ((DAT_01fb8ca8 != 0) && (DAT_01fb8ca4 = DAT_01fb8cb4, DAT_01fb8cb8 == 0)) {
        DAT_01fb8cb8 = DAT_01fb8cb4;
      }
    }
    _DAT_007d12bc = _DAT_01fb8ca0 + _DAT_007d12bc;
    if ((DAT_01fb8ca8 == 0) || (_DAT_007d12c0 <= _DAT_007d12bc)) {
LAB_004114f8:
      if (DAT_01fb8cb8 != 0) {
        ffree(in_ST0);
        in_ST0 = (float10)FUN_004115b4(&DAT_01fb8cb8,&DAT_01fb8ca4);
      }
      if (DAT_01fb8c80 <= DAT_01fb8cac) {
LAB_004115ab:
        ffree(in_ST0);
        return;
      }
      if (_DAT_007d12c0 <= _DAT_007d12bc) {
        do {
          _DAT_007d12bc = _DAT_007d12bc - _DAT_007d12c4;
        } while (_DAT_007d12c0 < _DAT_007d12bc);
        in_ST0 = (float10)_DAT_007d12bc;
        if (ABS(in_ST0) <= (float10)f_0_001) {
          _DAT_007d12bc = f_0;
        }
      }
    }
  }
  goto LAB_00411346;
}


