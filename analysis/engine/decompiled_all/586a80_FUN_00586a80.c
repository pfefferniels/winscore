// FUN_00586a80 @ 00586a80 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00586a80(void)

{
  int iVar1;
  
  if ((_DAT_020b8ea0 & 0xffffff) != 0x504553) {
    thunk_FUN_005725fa();
    thunk_FUN_0052f62e(&DAT_0076ad90);
  }
  if (P3 == f_0) {
    P3 = f_200;
  }
  DAT_01be12e0 = 0xfffffffe;
  thunk_FUN_0053fc37();
  if (DAT_0078b4e0 == 0x42) {
    DAT_01be12e0 = 0;
    thunk_FUN_00549422();
  }
  else {
    thunk_FUN_0049712c();
    DAT_009a927c = 1;
    DAT_01a9f300 = -1;
    DAT_0078de00 = (int)ROUND(P1);
    P6 = f_999;
    P7 = f_0;
    DAT_01fb8c60 = P1;
    LOAD_I = DAT_01a1c778;
    for (iVar1 = (ITEM_I - DAT_01a1c778) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      load_item_header();
      if (LOAD_STAFF == DAT_0078de00) {
        if (LOAD_CODE == 3) {
          if (LOAD_P3 < P2) {
            DAT_01a9f300 = 0;
            if (4 < LOAD_LEN) {
              DAT_01a9f300 = (int)ROUND((float)(&ITEM_P5)[LOAD_W]);
            }
            goto LAB_00586c19;
          }
        }
        else {
LAB_00586c19:
          if (LOAD_P3 < P2) goto LAB_00586ec6;
        }
        if (LOAD_CODE != 8) {
          if (LOAD_CODE == 1) {
            if (*(float *)(&ITEM_P7 + LOAD_W * 4) <= f_0) {
              _DAT_009a9278 = (float)(&ITEM_P6)[LOAD_W];
              if (_DAT_009a9278 == f_0) {
                DAT_009a9274 = f_1;
                if ((f_7 < (float)LOAD_LEN) && (*(float *)(&ITEM_P9 + LOAD_W * 4) != f_0)) {
                  DAT_009a9274 = f_0_5 / *(float *)(&ITEM_P9 + LOAD_W * 4);
                }
              }
              else {
                DAT_009a9274 = _DAT_009a9278 * f_2;
              }
              *(float *)(&ITEM_P7 + LOAD_W * 4) = DAT_009a9274;
            }
            if ((((9 < LOAD_LEN) && (P5 = *(float *)(&ITEM_P10 + LOAD_W * 4), P5 != f_20)) &&
                (P5 != f_0)) && (P5 != f_10)) goto LAB_00586ec6;
          }
          P5 = f_0;
          if (4 < LOAD_LEN) {
            P5 = (float)(&ITEM_P5)[LOAD_W];
          }
          if ((LOAD_CODE != 6) || ((float)(&ITEM_P6)[LOAD_W] <= P3)) {
            DAT_009a9270 = LOAD_LEN + 1;
            if (ABS(P3 - LOAD_P3) <= f_0_05) {
              (&ITEM_P3)[LOAD_W] = P3;
              LOAD_P3 = P3;
            }
            if ((LOAD_CODE != 5) && (LOAD_P3 < P6)) {
              P6 = LOAD_P3;
            }
            if (P3 < LOAD_P3) {
              if ((LOAD_CODE != 5) && (LOAD_CODE != 6)) {
                P7 = LOAD_P3 - f_0_1;
                goto LAB_00586f2d;
              }
            }
            else {
              if (DAT_009a927c == 1) {
                DAT_009a926c = LOAD_I;
              }
              (&DAT_01a18bd8)[DAT_009a927c] = LOAD_I;
              DAT_009a927c = DAT_009a927c + 1;
            }
          }
        }
      }
LAB_00586ec6:
      LOAD_I = LOAD_I + 1;
    }
    if (P7 == f_0) {
      P7 = P3;
    }
LAB_00586f2d:
    LOAD_I = DAT_009a927c + -1;
    DAT_01f95c88 = P6;
    DAT_01f95c80 = P7;
    DAT_01a18bdc = DAT_009a926c;
    DAT_009a9270 = ITEM_I;
    DAT_009a927c = LOAD_I;
    DAT_009a9268 = DAT_01a9f300;
    for (iVar1 = -LOAD_I / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
      P2 = (float)(int)(&DAT_01a18bd8)[LOAD_I];
      P3 = (float)DAT_009a9270;
      if (P3 != P2) {
        FUN_0058adc1(&DAT_0076ad90);
      }
      DAT_009a9270 = DAT_009a9270 + -1;
      LOAD_I = LOAD_I + -1;
    }
    DAT_009a926c = DAT_009a9270 + 1;
    DAT_01a9f300 = DAT_009a9268;
    P1 = DAT_01fb8c60;
    P2 = DAT_01f95c88;
    P3 = DAT_01f95c80;
    FUN_005870fd();
    DAT_01a18340 = DAT_01a18340 + 1;
    DAT_009a9264 = 1;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_009a9270 = (&ITEM_PTR0)[DAT_009a9264] + 2;
      if ((float)(&ITEM_LEN)[DAT_009a9270] == f_255) {
        (&ITEM_LEN)[DAT_009a9270] = DAT_01fb8c60;
      }
      DAT_009a9264 = DAT_009a9264 + 1;
    }
  }
  return;
}


