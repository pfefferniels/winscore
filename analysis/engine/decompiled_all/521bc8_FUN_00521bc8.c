// FUN_00521bc8 @ 00521bc8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00521bc8(void)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  
  DAT_0094e488 = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_0094e484 = (&ITEM_PTR0)[DAT_0094e488];
    if ((((float)(&ITEM_P1)[DAT_0094e484] == f_2) &&
        (DAT_0094e480 = (int)ROUND((float)(&ITEM_LEN)[DAT_0094e484]), 4 < DAT_0094e480)) &&
       (DAT_0094e47c = (int)ROUND((float)(&ITEM_P5)[DAT_0094e484]), DAT_0094e47c < -1)) {
      if (7 < DAT_0094e480) {
        DAT_0094e478 = DAT_0094e484 + 8;
        if ((DAT_0094e47c == -2) && ((float)(&ITEM_LEN)[DAT_0094e478] == f_1)) {
          (&ITEM_LEN)[DAT_0094e478] = DAT_00795450;
        }
        if ((DAT_00795454 == 0) && (DAT_0094e47c < -0xb)) {
          DAT_0094e47c = -2;
          if (f_1 < (float)(&ITEM_LEN)[DAT_0094e478]) {
            DAT_0094e47c = -5;
          }
          (&ITEM_P5)[DAT_0094e484] = (float)DAT_0094e47c;
        }
      }
      _DAT_0094e474 = (float)(&ITEM_P3)[DAT_0094e484];
      _DAT_0094e470 = (float)(&ITEM_P2)[DAT_0094e484];
      in_ST0 = (float10)f_9999;
      _DAT_0094e468 = (float)-in_ST0;
      DAT_0094e478 = 1;
      _DAT_0094e46c = f_9999;
      for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
        DAT_0094e464 = (&ITEM_PTR0)[DAT_0094e478];
        if (((float)(&ITEM_P1)[DAT_0094e464] == f_14) &&
           (_DAT_0094e460 = (float)(&ITEM_P2)[DAT_0094e464], _DAT_0094e460 <= _DAT_0094e470)) {
          DAT_0094e45c = (int)ROUND((float)(&ITEM_LEN)[DAT_0094e464]);
          DAT_0094e458 = f_0;
          if (2 < DAT_0094e45c) {
            DAT_0094e458 = (float)(&ITEM_P3)[DAT_0094e464];
          }
          _DAT_0094e454 = f_1;
          if ((3 < DAT_0094e45c) && (f_1 != f_0)) {
            _DAT_0094e454 = (float)(&ITEM_P4)[DAT_0094e464];
          }
          if (_DAT_0094e470 < _DAT_0094e454 + _DAT_0094e460) {
            if ((DAT_0094e458 < _DAT_0094e46c) && (_DAT_0094e474 < DAT_0094e458)) {
              _DAT_0094e46c = DAT_0094e458;
              DAT_0094e450 = 0;
              if (4 < DAT_0094e45c) {
                DAT_0094e450 = (int)ROUND((float)(&ITEM_P5)[DAT_0094e464]);
              }
            }
            if ((_DAT_0094e468 < DAT_0094e458) && (DAT_0094e458 < _DAT_0094e474)) {
              _DAT_0094e468 = DAT_0094e458;
              DAT_0094e44c = 0;
              if (4 < DAT_0094e45c) {
                DAT_0094e44c = (int)ROUND((float)(&ITEM_P5)[DAT_0094e464]);
              }
            }
          }
        }
        DAT_0094e478 = DAT_0094e478 + 1;
      }
      if (_DAT_0094e46c != f_9999) {
        if (f_9 < _DAT_0094e474 - _DAT_0094e468) {
          _DAT_0094e468 = _DAT_0094e474 - f_3;
          DAT_0094e44c = 0;
        }
        if (DAT_0094e47c == -5) {
          _DAT_0094e46c = _DAT_0094e46c - *(float *)(&DAT_00796b1c + DAT_0094e450 * 4);
          DAT_0094e458 = (_DAT_0094e46c - _DAT_0094e474) +
                         _DAT_0094e468 + (float)(&DAT_00796afc)[DAT_0094e44c];
          DAT_0094e464 = (int)ROUND(_DAT_0094e470);
          _DAT_0094e468 = (float)(&STAFF_STEP0)[DAT_0094e464] / f_25;
          if (f_3_5 < (_DAT_0094e46c - DAT_0094e458) / _DAT_0094e468) {
            DAT_0094e458 = _DAT_0094e46c - _DAT_0094e468 * f_3_5;
          }
        }
        else {
          DAT_0094e458 = f_0_056;
          if (DAT_0094e47c == -4) {
            DAT_0094e458 = f_0_137;
          }
          DAT_0094e464 = (int)ROUND(_DAT_0094e470);
          in_ST0 = ((float10)_DAT_0094e46c - (float10)_DAT_0094e468) * (float10)f_0_5 +
                   (float10)_DAT_0094e468;
          DAT_0094e458 = (float)(in_ST0 - (float10)DAT_0094e458 *
                                          (float10)(float)(&STAFF_STEP0)[DAT_0094e464]);
        }
        if (DAT_0094e480 < 9) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_005239c9(&DAT_0094e488,&f_9);
        }
        if (DAT_0094e480 < 8) {
          *(float *)(&ITEM_P8 + DAT_0094e484 * 4) = f_0;
        }
        *(float *)(&ITEM_P9 + DAT_0094e484 * 4) = DAT_0094e458;
      }
    }
    DAT_0094e488 = DAT_0094e488 + 1;
  }
  ffree(in_ST0);
  return;
}


