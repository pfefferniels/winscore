// FUN_0049bf20 @ 0049bf20 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049bf20(int *param_1)

{
  int iVar1;
  int iVar2;
  
  DAT_01ba2084 = f_1;
  do {
    _DAT_00838958 = f_m999;
    _DAT_00838954 = (float)*param_1;
    if (DAT_01ba0d80 != 0) {
      DAT_0083894c = (int)ROUND(_DAT_00838954);
      iVar1 = DAT_01c4c838;
      for (iVar2 = DAT_01c4c83c - DAT_01c4c838; 0 < iVar2; iVar2 = iVar2 + -1) {
        DAT_00838944 = (&DAT_01c4637c)[iVar1];
        if ((DAT_0083894c == (int)ROUND((float)(&DAT_01c6da64)[DAT_00838944])) &&
           ((float)(&DAT_01c6da60)[DAT_00838944] == f_8)) {
          _DAT_00838958 = f_m1;
          if (f_3 <= *(float *)(&DAT_01c6da5c + DAT_00838944 * 4)) {
            _DAT_00838958 = (float)(&DAT_01c6da68)[DAT_00838944] - f_1;
          }
          break;
        }
        iVar1 = iVar1 + 1;
      }
    }
    DAT_00838950 = DAT_01ba0d80;
    DAT_00838948 = DAT_01c4c838;
    for (iVar2 = DAT_01c4c83c - DAT_01c4c838; 0 < iVar2; iVar2 = iVar2 + -1) {
      DAT_00838944 = (&DAT_01c4637c)[DAT_00838948];
      if (DAT_0083894c == (int)ROUND((float)(&DAT_01c6da64)[DAT_00838944])) {
        (&DAT_01c6da64)[DAT_00838944] = DAT_01ba2084;
        DAT_00838940 = (int)ROUND((float)(&DAT_01c6da60)[DAT_00838944]);
        if (DAT_00838940 == 8) {
          DAT_0083893c = (int)ROUND(*(float *)(&DAT_01c6da5c + DAT_00838944 * 4));
          if (2 < DAT_0083893c) {
            _DAT_00838958 = (float)(&DAT_01c6da68)[DAT_00838944] - f_1;
          }
          DAT_00838940 = 5;
          if (6 < DAT_0083893c) {
            DAT_00838940 = 7;
          }
          thunk_FUN_0054c590(&DAT_01c6da5c + DAT_00838944 * 4,&ITEM_LEN + ITEM_WORDS,&DAT_00763488);
          (&ITEM_LEN)[ITEM_WORDS] = (float)DAT_00838940;
          (&ITEM_P4)[ITEM_WORDS] = f_0;
          (&ITEM_P5)[ITEM_WORDS] = f_0_9;
          _DAT_01c41ce4 = f_22_5;
          ITEM_WORDS = DAT_00838940 + ITEM_WORDS + 1;
LAB_0049c6d7:
          (&DAT_01c6da60)[DAT_00838944] = f_0;
        }
        else {
          DAT_0083893c = (int)ROUND(*(float *)(&DAT_01c6da5c + DAT_00838944 * 4) + f_1);
          if ((((DAT_00838950 == 0) || (DAT_0083893c < 4)) ||
              (_DAT_00838958 <= (float)(&DAT_01c6da68)[DAT_00838944])) &&
             (((DAT_00838940 != 5 || (DAT_0083893c < 9)) ||
              ((float)(&DAT_01c6da70)[DAT_00838944] <= f_189)))) {
            if (((DAT_00838940 == 9) || (DAT_00838940 == 10)) || (DAT_00838940 == 0x10)) {
              if (6 < DAT_0083893c) {
                if (((6 < DAT_0083893c) && (DAT_01fbb8b8 <= (float)(&DAT_01c6da74)[DAT_00838944]))
                   || (DAT_01c4c848 = (int)ROUND((float)(&DAT_01c6da74)[DAT_00838944] / f_100),
                      DAT_01c4c848 == 2)) goto LAB_0049c6ea;
                if (DAT_01c4c848 == 3) {
                  (&DAT_01c6da74)[DAT_00838944] = f_0;
                }
              }
              if ((7 < DAT_0083893c) && (*(float *)(&DAT_01c6da78 + DAT_00838944 * 4) < f_0))
              goto LAB_0049c6ea;
            }
            if (DAT_00838940 != 0) {
              if (DAT_00838940 == 2) {
                DAT_00838940 = DAT_00838948;
                _DAT_00838938 = (float)(&DAT_01c6da68)[DAT_00838944];
                _DAT_00838934 = (float)(&DAT_01c6da74)[DAT_00838944];
                _DAT_01c4c858 = *(float *)(&DAT_01c6da78 + DAT_00838944 * 4);
                do {
                  if (DAT_01c4c83c == DAT_00838940) goto LAB_0049c55f;
                  DAT_00838940 = DAT_00838940 + 1;
                  DAT_01c4c84c = (&DAT_01c4637c)[DAT_00838940];
                  if (f_0_02 < ABS((float)(&DAT_01c6da68)[DAT_01c4c84c] - _DAT_00838938))
                  goto LAB_0049c55f;
                } while ((((float)(&DAT_01c6da60)[DAT_01c4c84c] != f_2) ||
                         ((int)ROUND((float)(&DAT_01c6da64)[DAT_01c4c84c]) != DAT_0083894c)) ||
                        (_DAT_01c4c858 != *(float *)(&DAT_01c6da78 + DAT_01c4c84c * 4)));
                if (_DAT_00838934 < f_0) goto LAB_0049c6d7;
                if ((float)(&DAT_01c6da74)[DAT_01c4c84c] <= f_0) {
                  (&DAT_01c6da60)[DAT_01c4c84c] = f_0;
                }
LAB_0049c55f:
                if (0xd < DAT_0083893c) {
                  FUN_0049cc74(&DAT_00838944);
                }
              }
              thunk_FUN_0054c590(&DAT_01c6da5c + DAT_00838944 * 4,&ITEM_LEN + ITEM_WORDS,
                                 &DAT_0083893c);
              ITEM_WORDS = DAT_0083893c + ITEM_WORDS;
              goto LAB_0049c6d7;
            }
          }
        }
      }
LAB_0049c6ea:
      DAT_00838948 = DAT_00838948 + 1;
    }
    if ((float)DAT_01ba2080 <= DAT_01ba2084) {
      return;
    }
    DAT_01ba2084 = DAT_01ba2084 + f_1;
    *param_1 = *param_1 + 1;
  } while( true );
}


