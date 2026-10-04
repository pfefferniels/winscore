// FUN_004fa548 @ 004fa548 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fa548(int *param_1)

{
  int iVar1;
  int iVar2;
  
  DAT_009012cc = 1;
  iVar2 = *param_1;
  DAT_009012c4 = 1;
  _DAT_009012c8 = (float)i_0;
  do {
    if (iVar2 < 1) {
      return;
    }
    DAT_01a72fc4 = DAT_01a72fc4 + 1;
    if (1 < DAT_01a72fc4) {
      _DAT_009012c8 = (float)(&DAT_01ba0d80)[DAT_01a72fc4];
    }
    if (f_200 <= _DAT_009012c8) {
      _DAT_009012c8 = (float)i_0;
    }
    _DAT_009012c0 = (float)(&DAT_01ba0d84)[DAT_01a72fc4];
    while (((DAT_009012bc = (&ITEM_PTR0)[DAT_009012cc],
            (float)_DAT_01a72fc0 != (float)(&ITEM_P2)[DAT_009012bc] ||
            (f_2 < (float)(&ITEM_P1)[DAT_009012bc])) ||
           (_DAT_009012b8 = (float)(&ITEM_P3)[DAT_009012bc], _DAT_009012b8 < _DAT_009012c8))) {
      DAT_009012cc = DAT_009012cc + 1;
      if (ITEM_I <= DAT_009012cc) {
        return;
      }
    }
    if (_DAT_009012b8 <= _DAT_009012c0) {
      if ((float)(&ITEM_P1)[DAT_009012bc] != f_2) {
        DAT_01a72fc8 = DAT_01a72fc8 + 1;
        DAT_009012b4 = DAT_009012cc + 1;
        for (iVar1 = (ITEM_I - DAT_009012b4) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
          DAT_009012bc = (&ITEM_PTR0)[DAT_009012b4];
          if ((float)(&ITEM_P1)[DAT_009012bc] == f_14) goto LAB_004fa8c1;
          DAT_009012b4 = DAT_009012b4 + 1;
        }
      }
      DAT_01a72fc8 = DAT_01a72fc8 + 1;
      DAT_009012b0 = 0;
      (&DAT_01a72fc8)[DAT_01a72fc8] =
           (int)((float)(&DAT_01a72fc8)[DAT_01a72fc8] + *(float *)(&ITEM_P7 + DAT_009012bc * 4));
      DAT_009012b4 = DAT_009012cc + 1;
      for (iVar1 = (ITEM_I - DAT_009012b4) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_009012bc = (&ITEM_PTR0)[DAT_009012b4];
        if ((float)_DAT_01a72fc0 == (float)(&ITEM_P2)[DAT_009012bc]) {
          if ((DAT_009012b0 == 0) && ((float)(&ITEM_P1)[DAT_009012bc] == f_2)) {
            (&DAT_01a72fc8)[DAT_01a72fc8] =
                 (int)((float)(&DAT_01a72fc8)[DAT_01a72fc8] +
                      *(float *)(&ITEM_P7 + DAT_009012bc * 4));
          }
          if ((float)(&ITEM_P1)[DAT_009012bc] == f_1) {
            DAT_009012b0 = 1;
          }
        }
        if ((float)(&ITEM_P1)[DAT_009012bc] == f_14) break;
        DAT_009012b4 = DAT_009012b4 + 1;
      }
      if (DAT_009012b0 != 0) {
LAB_004fa8c1:
        DAT_009012ac = DAT_009012b4 + -1;
        for (iVar1 = (DAT_009012cc - DAT_009012ac) / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
          DAT_009012bc = (&ITEM_PTR0)[DAT_009012ac];
          if ((float)_DAT_01a72fc0 == (float)(&ITEM_P2)[DAT_009012bc]) {
            if ((float)(&ITEM_P1)[DAT_009012bc] == f_1) break;
            if ((float)(&ITEM_P1)[DAT_009012bc] == f_2) {
              *(float *)(&DAT_01a72fcc + DAT_01a72fc8 * 4) =
                   *(float *)(&DAT_01a72fcc + DAT_01a72fc8 * 4) +
                   *(float *)(&ITEM_P7 + DAT_009012bc * 4);
            }
          }
          DAT_009012ac = DAT_009012ac + -1;
        }
      }
    }
    *(int *)(&DAT_01a76abc + DAT_01a72fc8 * 4) =
         (int)ROUND((float)(&DAT_01a72fc8)[DAT_01a72fc8] * f_100);
    DAT_009012c4 = DAT_009012c4 + 1;
    iVar2 = iVar2 + -1;
  } while( true );
}


