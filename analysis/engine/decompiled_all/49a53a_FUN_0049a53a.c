// FUN_0049a53a @ 0049a53a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049a53a(void)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  
  DAT_008388bc = 1;
  iVar2 = (DAT_01c2cc24 - DAT_01c2cc20) + 1;
  DAT_008388b8 = DAT_01c2cc20;
  do {
    if (iVar2 < 1) {
      DAT_008388b0 = 1;
      _DAT_008388a0 = f_1;
      for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
        DAT_008388a8 = (&ITEM_PTR0)[DAT_008388b0];
        DAT_008388b4 = (int)ROUND((float)(&ITEM_LEN)[DAT_008388a8]);
        DAT_008388ac = (int)ROUND((float)(&ITEM_P1)[DAT_008388a8]);
        if (DAT_008388ac == 8) {
          _DAT_008388a0 = f_1;
          if ((4 < DAT_008388b4) && ((float)(&ITEM_P5)[DAT_008388a8] != f_0)) {
            _DAT_008388a0 = (float)(&ITEM_P5)[DAT_008388a8];
          }
        }
        else if ((DAT_008388ac == 5) &&
                ((float)(&ITEM_P4)[DAT_008388a8] == (float)(&ITEM_P5)[DAT_008388a8])) {
          _DAT_0083889c = (float)(&ITEM_P6)[DAT_008388a8] - (float)(&ITEM_P3)[DAT_008388a8];
          if ((DAT_008388b4 < 8) || (f_m2 < *(float *)(&ITEM_P8 + DAT_008388a8 * 4))) {
            if (_DAT_0083889c < _DAT_008388a0 * f_2) {
              (&ITEM_P1)[DAT_008388a8] = f_13;
            }
          }
          else {
            DAT_008388a4 = f_9_5;
            if (*(float *)(&ITEM_P8 + DAT_008388a8 * 4) == f_m3) {
              DAT_008388a4 = f_11;
            }
            if (_DAT_0083889c <= _DAT_008388a0 * DAT_008388a4) {
              (&ITEM_P3)[DAT_008388a8] = _DAT_008388a0 * f_2 + (float)(&ITEM_P3)[DAT_008388a8];
              (&ITEM_P6)[DAT_008388a8] = _DAT_008388a0 * f_0_8 + (float)(&ITEM_P6)[DAT_008388a8];
              *(float *)(&ITEM_P8 + DAT_008388a8 * 4) = f_0;
              DAT_008388a4 = f_1;
              if (*(float *)(&ITEM_P7 + DAT_008388a8 * 4) < f_0) {
                in_ST0 = (float10)f_1;
                DAT_008388a4 = (float)-in_ST0;
              }
              (&ITEM_P4)[DAT_008388a8] = DAT_008388a4 + (float)(&ITEM_P4)[DAT_008388a8];
              (&ITEM_P5)[DAT_008388a8] = (&ITEM_P4)[DAT_008388a8];
            }
          }
        }
        DAT_008388b0 = DAT_008388b0 + 1;
      }
      ffree(in_ST0);
      return;
    }
    DAT_008388b4 = 0;
    DAT_008388b0 = DAT_008388bc;
    for (iVar1 = (ITEM_I - DAT_008388bc) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_008388ac = (&ITEM_PTR0)[DAT_008388b0];
      DAT_008388a8 = (int)ROUND((float)(&ITEM_P2)[DAT_008388ac]);
      if (DAT_008388b8 <= DAT_008388a8) {
        if (DAT_008388b8 < DAT_008388a8) goto LAB_0049a73a;
        DAT_008388a8 = (int)ROUND((float)(&ITEM_P1)[DAT_008388ac]);
        if (DAT_008388a8 == 1) break;
        if (DAT_008388a8 == 5) {
          DAT_008388b4 = DAT_008388b4 + 1;
          (&DAT_020492a4)[DAT_008388b4] = DAT_008388ac + 3;
        }
      }
      DAT_008388b0 = DAT_008388b0 + 1;
    }
    if (DAT_008388b4 != 0) {
      DAT_008388a4 = (float)(&ITEM_P3)[DAT_008388ac] - f_9;
      DAT_008388a8 = 1;
      for (iVar1 = DAT_008388b4; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_LEN)[(&DAT_020492a4)[DAT_008388a8]] = DAT_008388a4;
        DAT_008388a8 = DAT_008388a8 + 1;
      }
    }
LAB_0049a73a:
    DAT_008388b8 = DAT_008388b8 + 1;
    iVar2 = iVar2 + -1;
    DAT_008388bc = DAT_008388b0;
  } while( true );
}


