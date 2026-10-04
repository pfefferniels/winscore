// FUN_00574d4c @ 00574d4c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00574d4c(float *param_1)

{
  int iVar1;
  int iVar2;
  unkbyte10 in_ST0;
  float10 fVar3;
  
  DAT_0078b4e4 = 0x53;
  ffree(in_ST0);
  fVar3 = (float10)thunk_FUN_004f7808();
  DAT_01c585d8 = 1;
  _DAT_009a8c54 = f_0;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    ffree(fVar3);
    LOAD_I = DAT_01c585d8;
    fVar3 = (float10)load_item_header();
    if ((LOAD_CODE == 8) && (DAT_01c585e0 + 1 <= LOAD_STAFF)) {
      _DAT_009a8c50 = (&STEP)[LOAD_STAFF] / f_25;
      _DAT_009a8c4c = (float)(&STAFF_STEP0)[LOAD_STAFF] / f_25;
      _DAT_009a8c48 = _DAT_009a8c4c;
      if (_DAT_009a8c50 < _DAT_009a8c4c) {
        _DAT_009a8c48 = _DAT_009a8c50;
      }
      _DAT_009a8c48 = _DAT_009a8c48 * f_175;
      _DAT_009a8c44 = _DAT_009a8c48 * *param_1;
      _DAT_009a8c40 = (int)ROUND(_DAT_009a8c50 * f_1925 + (float)(&CUR_STAFF)[LOAD_STAFF]);
      fVar3 = (float10)(int)(&STAFF_Y0)[LOAD_STAFF];
      DAT_009a8c3c = (int)ROUND((float10)_DAT_009a8c4c * (float10)f_525 + fVar3);
      DAT_01c585d4 = (float)(DAT_009a8c3c - _DAT_009a8c40);
      DAT_01c585d0 = _DAT_009a8c44 - DAT_01c585d4;
      if (f_0 < DAT_01c585d0) {
        DAT_009a8c38 = f_0;
        if (3 < LOAD_LEN) {
          DAT_009a8c38 = (float)(&ITEM_P4)[LOAD_W];
        }
        DAT_009a8c38 = DAT_01c585d0 / _DAT_009a8c48 + DAT_009a8c38 + _DAT_009a8c54;
        _DAT_009a8c54 = f_3;
        fVar3 = (float10)(LOAD_STAFF * 0xc4e + -0x6c1b);
        (&STAFF_Y0)[LOAD_STAFF] = (int)ROUND((float10)_DAT_009a8c48 * (float10)DAT_009a8c38 + fVar3)
        ;
        if (LOAD_LEN < 4) {
          ffree(fVar3);
          fVar3 = (float10)thunk_FUN_005239c9(&LOAD_I,&DAT_0076a664);
        }
        (&ITEM_P4)[LOAD_W] = DAT_009a8c38;
        LOAD_I = DAT_01c585d8 + 1;
        for (iVar1 = (ITEM_I - LOAD_I) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
          ffree(fVar3);
          fVar3 = (float10)load_item_header();
          if (LOAD_CODE == 8) {
            DAT_009a8c38 = f_0;
            if (3 < LOAD_LEN) {
              DAT_009a8c38 = (float)(&ITEM_P4)[LOAD_W];
            }
            fVar3 = (float10)DAT_01c585d0 / (float10)f_175;
            DAT_009a8c38 = (float)(fVar3 / ((float10)(float)(&STAFF_STEP0)[LOAD_STAFF] /
                                           (float10)f_25) + (float10)DAT_009a8c38);
            (&STAFF_Y0)[LOAD_STAFF] = (int)ROUND((float)(int)(&STAFF_Y0)[LOAD_STAFF] + DAT_01c585d0)
            ;
            if (LOAD_LEN < 4) {
              ffree(fVar3);
              fVar3 = (float10)thunk_FUN_005239c9(&LOAD_I,&DAT_0076a664);
            }
            (&ITEM_P4)[LOAD_W] = DAT_009a8c38;
          }
          LOAD_I = LOAD_I + 1;
        }
      }
    }
    DAT_01c585d8 = DAT_01c585d8 + 1;
  }
  ffree(fVar3);
  return;
}


