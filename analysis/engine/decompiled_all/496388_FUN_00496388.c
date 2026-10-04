// FUN_00496388 @ 00496388 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496388(int *param_1)

{
  int iVar1;
  float10 in_ST0;
  
  DAT_01b12c80 = (&ITEM_PTR0)[ITEM_I];
  DAT_0082a44c = *param_1 + DAT_01b12c80;
  DAT_01b12c88 = 0;
  DAT_01b12c8c = 0;
  DAT_0082a460 = -(uint)(DAT_0078de00 != 1);
  DAT_0082a45c = -(uint)(DAT_0078de04 != 0);
  DAT_0082a458 = -(uint)((int)ROUND(DAT_01fbb8b8) != DAT_0078de10);
  DAT_0082a454 = -(uint)(DAT_0078de08 != 0);
  DAT_0082a450 = -(uint)(DAT_0078de0c != f_1);
  do {
    DAT_0082a448 = (int)ROUND((float)(&ITEM_LEN)[DAT_01b12c80]);
    DAT_0082a444 = DAT_01b12c80 + 1;
    DAT_01b12c84 = DAT_01b12c80 + 2;
    DAT_0082a440 = DAT_01b12c80 + 3;
    DAT_0082a43c = (int)ROUND((float)(&ITEM_LEN)[DAT_0082a444]);
    DAT_0082a464 = -(uint)(DAT_0082a43c == 8);
    if (DAT_0078b378 == 2) {
      DAT_0082a438 = 3;
      if ((DAT_0082a464 & 1) == 0) {
LAB_004965c3:
        if (((DAT_0082a45c & 1) != 0) && (DAT_0082a448 < 3)) {
LAB_004965e9:
          if (DAT_0082a448 < DAT_0082a438) {
            DAT_0082a434 = DAT_0082a438 - DAT_0082a448;
            iVar1 = DAT_0082a448 + DAT_01b12c80;
            DAT_0082a42c = (DAT_0082a44c - iVar1) + -1;
            DAT_0082a428 = DAT_0082a42c + iVar1 + DAT_0082a434;
            for (iVar1 = (((DAT_0082a42c + iVar1) - DAT_0082a428) + -1) / -1; 0 < iVar1;
                iVar1 = iVar1 + -1) {
              (&ITEM_LEN)[DAT_0082a428] = (&ITEM_LEN)[DAT_0082a428 - DAT_0082a434];
              DAT_0082a428 = DAT_0082a428 + -1;
            }
            (&ITEM_LEN)[DAT_01b12c80] = (float)DAT_0082a438;
            DAT_0082a430 = DAT_0082a448 + 1;
            for (iVar1 = (DAT_0082a438 - DAT_0082a430) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
              (&ITEM_LEN)[DAT_0082a430 + DAT_01b12c80] = f_0;
              DAT_0082a430 = DAT_0082a430 + 1;
            }
            DAT_0082a44c = DAT_0082a434 + DAT_0082a44c;
            *param_1 = *param_1 + DAT_0082a434;
            DAT_0082a448 = DAT_0082a438;
          }
        }
      }
      else if (DAT_0082a448 < 6) {
        if ((DAT_0082a458 & 1) == 0) {
          if (((DAT_0082a450 & 1) == 0) || (4 < DAT_0082a448)) {
            if (((DAT_0082a454 & 1) == 0) || (3 < DAT_0082a448)) goto LAB_004965c3;
            DAT_0082a438 = 4;
          }
          else {
            DAT_0082a438 = 5;
          }
        }
        else {
          DAT_0082a438 = 6;
        }
        goto LAB_004965e9;
      }
    }
    if ((DAT_0082a464 & 1) == 0) {
      if ((DAT_0082a460 & 1) != 0) {
        ffree(in_ST0);
        in_ST0 = (float10)FUN_00496a83();
      }
      if ((DAT_0078b378 == 2) && (2 < DAT_0082a448)) {
        if ((float)(&ITEM_LEN)[DAT_0082a440] <= f_100) {
          if ((DAT_0082a45c & 1) != 0) {
            (&ITEM_LEN)[DAT_0082a440] = (float)DAT_0078de04 + (float)(&ITEM_LEN)[DAT_0082a440];
          }
        }
        else if ((DAT_0082a458 & 1) != 0) {
          (&ITEM_LEN)[DAT_0082a440] =
               (float)(DAT_0078de10 - (int)ROUND(DAT_01fbb8b8)) + (float)(&ITEM_LEN)[DAT_0082a440];
        }
      }
    }
    else {
      if ((DAT_0082a460 & 1) != 0) {
        ffree(in_ST0);
        in_ST0 = (float10)FUN_00496a83();
      }
      if (DAT_0078b378 == 2) {
        if ((DAT_0082a45c & 1) != 0) {
          (&ITEM_LEN)[DAT_0082a440] = (float)DAT_0078de04;
        }
        if ((DAT_0082a454 & 1) != 0) {
          (&ITEM_P4)[DAT_01b12c80] = (float)DAT_0078de08 + (float)(&ITEM_P4)[DAT_01b12c80];
        }
        if ((DAT_0082a450 & 1) != 0) {
          (&ITEM_P5)[DAT_01b12c80] = DAT_0078de0c;
        }
        if ((DAT_0082a458 & 1) != 0) {
          (&ITEM_P6)[DAT_01b12c80] = (float)DAT_0078de10;
        }
        DAT_0082a424 = (int)ROUND((float)(&ITEM_LEN)[DAT_01b12c84]);
        DAT_0082a420 = DAT_0078de0c * f_25;
        (&STAFF_STEP0)[DAT_0082a424] = DAT_0082a420;
        if (DAT_0082a448 < 4) {
          _DAT_0082a41c = (float)DAT_0078de08;
        }
        else {
          _DAT_0082a41c = (float)(&ITEM_P4)[DAT_01b12c80];
        }
        in_ST0 = (float10)(DAT_0082a424 + -1) * (float10)f_3150;
        _DAT_0082a418 =
             (float)(((float10)_DAT_0082a41c * (float10)f_7 * (float10)DAT_0082a420 + in_ST0) -
                    (float10)f_24000);
        (&STAFF_Y0)[DAT_0082a424] = (int)ROUND(_DAT_0082a418 - DAT_0082a420 * f_21);
      }
    }
    DAT_01b12c80 = DAT_0082a448 + DAT_01b12c80 + 1;
    if (DAT_0082a44c + -1 <= DAT_01b12c80) {
      ffree(in_ST0);
      return;
    }
  } while( true );
}


