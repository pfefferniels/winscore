// FUN_005611da @ 005611da (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00561590) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005611da(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 in_ST0;
  float10 fVar4;
  float10 extraout_ST1;
  
  DAT_01ba0bd8 = 1;
  DAT_01ba0bd4 = 0;
  do {
    DAT_01ba0bd4 = DAT_01ba0bd4 + 1;
    if ((&DAT_01e9a2e8)[DAT_01ba0bd4] != *param_1) {
      DAT_01ba0be0 = *param_1;
      DAT_01ba0be4 = (&DAT_01e9a2e8)[DAT_01ba0bd4];
      _DAT_01ba0be8 = *(int *)(&DAT_0079f504 + (DAT_01ba0be4 * 4 + DAT_01ba0be0) * 4);
      DAT_01ba0bec = DAT_01ba0bd4;
      for (iVar2 = (DAT_01e99980 - DAT_01ba0bd4) + 1; DAT_01ba0bd4 = DAT_01e99980, 0 < iVar2;
          iVar2 = iVar2 + -1) {
        if (DAT_01ba0be4 != (&DAT_01e9a2e8)[DAT_01ba0bec]) {
          DAT_01ba0bd4 = DAT_01ba0bec + -1;
          break;
        }
        DAT_01ba0bf0 = (&DAT_01e9a608)[DAT_01ba0bec];
        if ((DAT_01ba0bf0 != 2) && (-1 < DAT_01ba0bf0)) {
          DAT_01ba0bf0 = (&DAT_01e99fc8)[DAT_01ba0bec] + _DAT_01ba0be8;
          (&DAT_01e99fc8)[DAT_01ba0bec] = DAT_01ba0bf0;
          DAT_01ba0bf4 = (&ITEM_PTR0)[(&DAT_01e99988)[DAT_01ba0bec]] + 4;
          if (f_4 <= *(float *)(&DAT_0205342c + DAT_01ba0bf4 * 4)) {
            DAT_009a7a6c = (int)ROUND((float)(&ITEM_LEN)[DAT_01ba0bf4]);
            iVar3 = DAT_009a7a6c;
            if (DAT_009a7a6c < 0) {
              iVar3 = -DAT_009a7a6c;
            }
            iVar1 = DAT_01ba0bf0;
            if ((99 < iVar3) && (iVar1 = DAT_01ba0bf0 + 100, DAT_009a7a6c < 0)) {
              iVar1 = DAT_01ba0bf0 + -100;
            }
            DAT_01ba0bf0 = iVar1;
            (&ITEM_LEN)[DAT_01ba0bf4] = (float)DAT_01ba0bf0;
          }
        }
        (&DAT_01e9a2e8)[DAT_01ba0bec] = *param_1;
        DAT_01ba0bec = DAT_01ba0bec + 1;
      }
      DAT_01ba0c04 = (float)DAT_01ba0be0;
      DAT_01ba0bf8 = (int)ROUND(DAT_01fb8c60);
      DAT_01ba0bdc = (&DAT_01e99988)[DAT_01ba0bd4];
      DAT_01ba0c08 = (float)_DAT_01ba0be8;
      _DAT_01ba0c0c = (float)(&ITEM_P3)[(&ITEM_PTR0)[DAT_01ba0bd8]] - f_4;
      _DAT_01ba0c10 = (float)(&ITEM_P3)[(&ITEM_PTR0)[DAT_01ba0bdc]] + f_4;
      LOAD_I = 1;
      for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
        ffree(in_ST0);
        in_ST0 = (float10)load_item_header();
        if (DAT_01ba0bf8 == LOAD_STAFF) {
          if ((LOAD_CODE == 6) && (4 < LOAD_LEN)) {
            if ((LOAD_P3 < _DAT_01ba0c0c) || (_DAT_01ba0c10 < LOAD_P3)) goto LAB_005616b3;
            _DAT_01ba0c00 = DAT_01ba0c08;
            _DAT_01ba0c14 = (float)(&ITEM_P4)[LOAD_W];
            in_ST0 = (float10)_DAT_01ba0c14;
            if ((float10)f_100 <= ABS(in_ST0)) {
              ffree(in_ST0);
              fVar4 = (float10)amod(&DAT_01ba0c14,&f_100);
              _DAT_01ba0c00 = (float)fVar4;
              _DAT_01ba0c00 = DAT_01ba0c08 + _DAT_01ba0c00;
              _DAT_01ba0c14 = f_100;
              in_ST0 = extraout_ST1;
              if (_DAT_01ba0c00 < f_0) {
                in_ST0 = (float10)f_100;
                _DAT_01ba0c14 = (float)-in_ST0;
              }
            }
            (&ITEM_P4)[LOAD_W] = _DAT_01ba0c00 + _DAT_01ba0c14;
            (&ITEM_P5)[LOAD_W] = DAT_01ba0c08 + (float)(&ITEM_P5)[LOAD_W];
          }
          if (LOAD_CODE == 0x11) {
            if (LOAD_LEN < 6) {
              ffree(in_ST0);
              in_ST0 = (float10)thunk_FUN_005239c9(&LOAD_I,&DAT_00769e38);
            }
            (&ITEM_P6)[LOAD_W] = (float)DAT_01ba0be0;
          }
        }
LAB_005616b3:
        LOAD_I = LOAD_I + 1;
      }
      DAT_01ba0bd8 = DAT_01ba0bdc + 1;
    }
  } while (DAT_01ba0bd4 < DAT_01e99980);
  DAT_01ba0bd8 = 0;
  LOAD_I = 1;
  iVar2 = ITEM_I;
  do {
    if (iVar2 < 1) {
      ffree(in_ST0);
      return;
    }
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    if ((DAT_01ba0bf8 == LOAD_STAFF) && (LOAD_CODE == 3)) {
      if (DAT_01ba0bd8 == 0) {
        DAT_01ba0bd8 = 1;
        if (LOAD_LEN < 5) {
          if (DAT_01ba0be0 == 0) goto LAB_005617e2;
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_005239c9(&LOAD_I,&DAT_00769e34);
        }
        (&ITEM_P5)[LOAD_W] = DAT_01ba0c04;
      }
      else {
        (&ITEM_P1)[LOAD_W] = f_13;
      }
    }
LAB_005617e2:
    LOAD_I = LOAD_I + 1;
    iVar2 = iVar2 + -1;
  } while( true );
}


