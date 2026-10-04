// FUN_004790b6 @ 004790b6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004790b6(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  *param_3 = 0;
  DAT_008283a0 = *param_1;
  if (DAT_008283a0 != 1) {
    DAT_0082839c = DAT_008283a0 + -1;
    for (iVar1 = -DAT_0082839c / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_00828398 = (&ITEM_PTR0)[DAT_0082839c];
      DAT_00828394 = (int)ROUND((float)(&ITEM_P1)[DAT_00828398]);
      if (DAT_00828394 == 0xe) break;
      if ((DAT_00828394 != 0) && (DAT_00828394 < 3)) {
        return;
      }
      DAT_0082839c = DAT_0082839c + -1;
    }
  }
  DAT_0082839c = DAT_008283a0 + 1;
  for (iVar1 = *param_2 - DAT_0082839c; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_00828398 = (&ITEM_PTR0)[DAT_0082839c];
    DAT_00828394 = (int)ROUND((float)(&ITEM_P1)[DAT_00828398]);
    if ((DAT_00828394 < 3) && (DAT_00828394 != 0)) {
      if (DAT_01ba2080 < 2) {
        return;
      }
      if (P3 < (float)(&ITEM_P3)[DAT_00828398]) {
        return;
      }
      if (DAT_00828394 == 1) {
        return;
      }
      if ((float)(&ITEM_P5)[DAT_00828398] != f_m2) {
        return;
      }
    }
    if (DAT_00828394 == 0xe) break;
    DAT_0082839c = DAT_0082839c + 1;
  }
  DAT_00828390 = DAT_00828398 + 1;
  *param_3 = *param_3 + 1;
  if ((DAT_0082839c != *param_2) &&
     (((float)(&ITEM_LEN)[DAT_00828398] < f_5 ||
      ((DAT_0082838c = (int)ROUND((float)(&ITEM_P5)[DAT_00828398]), DAT_0082838c != -1 &&
       (DAT_0082838c < 1 || 6 < DAT_0082838c)))))) {
    DAT_0082838c = 0;
    DAT_008283a0 = DAT_0082839c;
    do {
      DAT_008283a0 = DAT_008283a0 + 1;
      DAT_00828398 = (&ITEM_PTR0)[DAT_008283a0];
      DAT_00828394 = (int)ROUND((float)(&ITEM_P1)[DAT_00828398]);
      DAT_00828388 = (int)ROUND((float)(&ITEM_LEN)[DAT_00828398]);
      if (DAT_00828394 == 2) {
        if (DAT_00828388 < 7) {
          return;
        }
        if (*(float *)(&ITEM_P7 + DAT_00828398 * 4) == f_0) {
          return;
        }
        if (f_m2 < (float)(&ITEM_P5)[DAT_00828398]) {
          return;
        }
        if ((7 < DAT_00828388) && (*(float *)(&ITEM_P8 + DAT_00828398 * 4) < f_0)) {
          return;
        }
        iVar1 = DAT_00828398;
        if (DAT_0082838c != 0) {
          return;
        }
      }
      else {
        iVar1 = DAT_0082838c;
        if ((DAT_00828394 != 0) && (DAT_00828394 != 3)) {
          if (DAT_00828394 != 0xe) {
            return;
          }
          (&ITEM_LEN)[DAT_00828390] = f_0;
          DAT_00828390 = DAT_00828398 + 1;
          iVar1 = DAT_0082838c;
          if (DAT_0082838c != 0) {
            (&ITEM_P1)[DAT_0082838c] = f_0;
            *param_3 = *param_3 + 1;
            DAT_0082838c = 0;
            iVar1 = DAT_0082838c;
            if (((4 < DAT_00828388) &&
                (DAT_00828388 = (int)ROUND((float)(&ITEM_P5)[DAT_00828398]), DAT_00828388 != 0)) &&
               (DAT_00828388 != 7)) {
              DAT_0082838c = 0;
              return;
            }
          }
        }
      }
      DAT_0082838c = iVar1;
    } while (DAT_008283a0 < *param_2);
  }
  return;
}


