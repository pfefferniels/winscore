// FUN_00522234 @ 00522234 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00522234(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  
  DAT_0094e4c8 = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    DAT_0094e4c4 = *(int *)(DAT_0094e4c8 * 4 + param_2 + -4);
    if (((*(float *)(param_1 + DAT_0094e4c4 * 4) == f_2) &&
        (DAT_0094e4c0 = (int)ROUND(*(float *)(param_1 + -4 + DAT_0094e4c4 * 4)), 4 < DAT_0094e4c0))
       && (DAT_0094e4bc = (int)ROUND(*(float *)(param_1 + 0x10 + DAT_0094e4c4 * 4)),
          DAT_0094e4bc < -1)) {
      if (0x10 < DAT_0094e4c0) {
        *(float *)(param_1 + 0x40 + DAT_0094e4c4 * 4) = f_0;
      }
      if (7 < DAT_0094e4c0) {
        DAT_0094e4b8 = DAT_0094e4c4 + 8;
        if ((DAT_0094e4bc == -2) && (*(float *)(param_1 + -4 + DAT_0094e4b8 * 4) == f_1)) {
          *(undefined4 *)(param_1 + -4 + DAT_0094e4b8 * 4) = DAT_00795450;
        }
        if ((DAT_00795454 == 0) && (DAT_0094e4bc < -0xb)) {
          DAT_0094e4bc = -2;
          if (f_1 < *(float *)(param_1 + -4 + DAT_0094e4b8 * 4)) {
            DAT_0094e4bc = -5;
          }
          *(float *)(param_1 + 0x10 + DAT_0094e4c4 * 4) = (float)DAT_0094e4bc;
        }
      }
      _DAT_0094e4b4 = *(float *)(param_1 + 8 + DAT_0094e4c4 * 4);
      _DAT_0094e4b0 = *(float *)(param_1 + 4 + DAT_0094e4c4 * 4);
      in_ST0 = (float10)f_9999;
      _DAT_0094e4a8 = (float)-in_ST0;
      DAT_0094e4b8 = 1;
      _DAT_0094e4ac = f_9999;
      for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_0094e4a4 = *(int *)(DAT_0094e4b8 * 4 + param_2 + -4);
        if ((*(float *)(param_1 + DAT_0094e4a4 * 4) == f_14) &&
           (_DAT_0094e4a0 = *(float *)(param_1 + 4 + DAT_0094e4a4 * 4),
           _DAT_0094e4a0 <= _DAT_0094e4b0)) {
          DAT_0094e49c = (int)ROUND(*(float *)(param_1 + -4 + DAT_0094e4a4 * 4));
          DAT_0094e498 = f_0;
          if (2 < DAT_0094e49c) {
            DAT_0094e498 = *(float *)(param_1 + 8 + DAT_0094e4a4 * 4);
          }
          _DAT_0094e494 = f_1;
          if ((3 < DAT_0094e49c) && (f_1 != f_0)) {
            _DAT_0094e494 = *(float *)(param_1 + 0xc + DAT_0094e4a4 * 4);
          }
          if (_DAT_0094e4b0 < _DAT_0094e494 + _DAT_0094e4a0) {
            if ((DAT_0094e498 < _DAT_0094e4ac) && (_DAT_0094e4b4 < DAT_0094e498)) {
              _DAT_0094e4ac = DAT_0094e498;
              DAT_0094e490 = 0;
              if (4 < DAT_0094e49c) {
                DAT_0094e490 = (int)ROUND(*(float *)(param_1 + 0x10 + DAT_0094e4a4 * 4));
              }
            }
            if ((_DAT_0094e4a8 < DAT_0094e498) && (DAT_0094e498 < _DAT_0094e4b4)) {
              _DAT_0094e4a8 = DAT_0094e498;
              DAT_0094e48c = 0;
              if (4 < DAT_0094e49c) {
                DAT_0094e48c = (int)ROUND(*(float *)(param_1 + 0x10 + DAT_0094e4a4 * 4));
              }
            }
          }
        }
        DAT_0094e4b8 = DAT_0094e4b8 + 1;
      }
      if (_DAT_0094e4ac != f_9999) {
        if (f_9 < _DAT_0094e4b4 - _DAT_0094e4a8) {
          _DAT_0094e4a8 = _DAT_0094e4b4 - f_3;
          DAT_0094e48c = 0;
        }
        if (DAT_0094e4bc == -5) {
          _DAT_0094e4ac = _DAT_0094e4ac - *(float *)(&DAT_00796b5c + DAT_0094e490 * 4);
          DAT_0094e498 = (_DAT_0094e4ac - _DAT_0094e4b4) +
                         _DAT_0094e4a8 + (float)(&DAT_00796b3c)[DAT_0094e48c];
          DAT_0094e4a4 = (int)ROUND(_DAT_0094e4b0);
          _DAT_0094e4a8 = (float)(&STAFF_STEP0)[DAT_0094e4a4] / f_25;
          if (f_3_5 < (_DAT_0094e4ac - DAT_0094e498) / _DAT_0094e4a8) {
            DAT_0094e498 = _DAT_0094e4ac - _DAT_0094e4a8 * f_3_5;
          }
        }
        else {
          DAT_0094e498 = f_0_056;
          if (DAT_0094e4bc == -4) {
            DAT_0094e498 = f_0_137;
          }
          DAT_0094e4a4 = (int)ROUND(_DAT_0094e4b0);
          in_ST0 = ((float10)_DAT_0094e4ac - (float10)_DAT_0094e4a8) * (float10)f_0_5 +
                   (float10)_DAT_0094e4a8;
          DAT_0094e498 = (float)(in_ST0 - (float10)DAT_0094e498 *
                                          (float10)(float)(&STAFF_STEP0)[DAT_0094e4a4]);
        }
        if (DAT_0094e4c0 < 9) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_005239c9(&DAT_0094e4c8,&f_9);
        }
        if (DAT_0094e4c0 < 8) {
          *(float *)(param_1 + 0x1c + DAT_0094e4c4 * 4) = f_0;
        }
        *(float *)(param_1 + 0x20 + DAT_0094e4c4 * 4) = DAT_0094e498;
      }
    }
    DAT_0094e4c8 = DAT_0094e4c8 + 1;
  }
  ffree(in_ST0);
  return;
}


