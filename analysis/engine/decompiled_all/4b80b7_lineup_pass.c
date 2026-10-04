// lineup_pass @ 004b80b7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lineup_pass(int *param_1,int *param_2,float *param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  
  DAT_01be1824 = DAT_0078b4e4;
  DAT_0078b4e4 = 0x58;
  thunk_FUN_004f7808();
  _DAT_0089f594 = *param_4;
  LOAD_I = 1;
  DAT_01be1800 = f_m9999;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    load_item_header();
    if ((*param_1 <= LOAD_STAFF) && (LOAD_STAFF <= *param_2)) {
      if (LOAD_CODE == 1) {
        DAT_01be1800 = LOAD_P3;
      }
      else {
        if ((((ABS(DAT_01be1800 - LOAD_P3) < f_0_1) && (*(float *)(&ITEM_P7 + LOAD_W * 4) < f_0)) &&
            (LOAD_CODE == 4)) && ((6 < LOAD_LEN && ((float)(&ITEM_P6)[LOAD_W] == f_0)))) {
          (&ITEM_P3)[LOAD_W] = DAT_01be1800 - f_0_001;
          DAT_0078b4ec = 0;
        }
        DAT_01be1800 = f_m9999;
      }
    }
    LOAD_I = LOAD_I + 1;
  }
  thunk_FUN_004f7808();
  _DAT_0089f590 = *param_3;
  _DAT_0089f58c = *param_4;
  LOAD_I = 1;
  do {
    load_item_header();
    if ((*param_1 <= LOAD_STAFF) && (LOAD_STAFF <= *param_2)) {
      if (LOAD_CODE == 8) {
        if (DAT_0078b4e0 == 0x4c) {
          _DAT_0089f590 = f_0;
          _DAT_0089f58c = DAT_01fbb8b8;
          if (2 < LOAD_LEN) {
            _DAT_0089f590 = LOAD_P3;
          }
          if ((5 < LOAD_LEN) && ((float)(&ITEM_P6)[LOAD_W] != f_0)) {
            _DAT_0089f58c = (float)(&ITEM_P6)[LOAD_W];
          }
        }
      }
      else if (((LOAD_CODE != 0x12) && (LOAD_CODE != 3)) && (LOAD_CODE != 0x11)) goto LAB_004b83eb;
      if (ITEM_I == LOAD_I) break;
      DAT_01be1814 = (&DAT_02091d20)[LOAD_I];
    }
LAB_004b83eb:
    LOAD_I = LOAD_I + 1;
  } while (LOAD_I < ITEM_I);
  DAT_01be1814 = (&ITEM_PTR0)[ITEM_I];
  DAT_01fbb8c8 = (int)ROUND((float)(&ITEM_P2)[DAT_01be1814]);
  if ((float)(&ITEM_LEN)[DAT_01be1814] < f_1) {
    DAT_01fbb8c8 = 1;
  }
  if (DAT_01fbb8c8 < *param_1) {
    return;
  }
  if (DAT_01fbb8c8 < *param_2) {
    *param_2 = DAT_01fbb8c8;
  }
  DAT_01be1814 = 1;
  DAT_01be1808 = *param_1;
  for (iVar2 = (*param_2 - DAT_01be1808) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
    DAT_01be180c = 0;
    LOAD_I = DAT_01be1814;
    DAT_01be1800 = f_m9999;
    for (iVar1 = (ITEM_I - DAT_01be1814) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      load_item_header();
      if ((DAT_01be1808 == LOAD_STAFF) && ((LOAD_CODE == 8 || (LOAD_CODE == 3)))) {
        if (LOAD_LEN < 3) {
          thunk_FUN_005239c9(&LOAD_I,&DAT_00764948);
        }
        if (LOAD_CODE == 3) {
          DAT_01be180c = LOAD_W + 3;
          if (DAT_01be1800 != f_m9999) {
LAB_004b8617:
            _DAT_01be1820 = (float)(&ITEM_LEN)[DAT_01be180c];
            if (((_DAT_01be1820 < P2) && (DAT_01be1800 == _DAT_01be1820)) && (P1 <= _DAT_01be1820))
            {
              (&ITEM_LEN)[DAT_01be180c] = DAT_01be1800 + f_1_5;
              DAT_0078b4ec = 0;
            }
            DAT_01be1814 = LOAD_I + 1;
            break;
          }
        }
        else {
          DAT_01be1800 = LOAD_P3;
          if (DAT_01be180c != 0) goto LAB_004b8617;
        }
      }
      LOAD_I = LOAD_I + 1;
    }
    DAT_01be1808 = DAT_01be1808 + 1;
  }
  thunk_FUN_004f7808();
  LOAD_I = 1;
  DAT_0078b4e4 = DAT_01be1824;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    load_item_header();
    if ((*param_1 <= LOAD_STAFF) && (LOAD_STAFF <= *param_2)) {
      _DAT_0089f588 = *(float *)(&ITEM_P8 + LOAD_W * 4);
      if (LOAD_CODE == 1) {
        if (ABS(DAT_01fbb8b8 - LOAD_P3) < f_1) {
          (&ITEM_P3)[LOAD_W] = DAT_01fbb8b8 - f_1;
        }
      }
      else if (LOAD_CODE == 6) {
        if (ABS(DAT_01fbb8b8 - (float)(&ITEM_P6)[LOAD_W]) < f_1) {
          (&ITEM_P6)[LOAD_W] = DAT_01fbb8b8 - f_1;
        }
      }
      else if (((LOAD_CODE == 5) && (_DAT_0089f588 == f_m1)) &&
              (ABS(DAT_01fbb8b8 - (float)(&ITEM_P6)[LOAD_W]) < f_1)) {
        (&ITEM_P6)[LOAD_W] = DAT_01fbb8b8 - f_1;
      }
    }
    LOAD_I = LOAD_I + 1;
  }
  if (DAT_0078b4e0 == 0x4c) {
    DAT_0089f580 = DAT_01be1824;
    DAT_01be1814 = DAT_0089f584;
    thunk_FUN_004c9510(param_1,param_2,&DAT_0089f590,&DAT_0089f58c);
    DAT_01be1824 = DAT_0089f580;
    if (*param_1 < 0) goto LAB_004b8b57;
    if (DAT_0089f580 == 0x4a) goto LAB_004b88b8;
  }
  else {
LAB_004b88b8:
    thunk_FUN_004b6f4a(param_1,param_2,&DAT_0089f590,&DAT_0089f58c,&DAT_0076493c);
  }
  LOAD_I = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    load_item_header();
    if (*param_1 <= LOAD_STAFF) {
      if (*param_2 < LOAD_STAFF) break;
      if (((((float)(&ITEM_P5)[LOAD_W] <= f_m2) && (LOAD_CODE == 2)) && (_DAT_0089f590 <= LOAD_P3))
         && (LOAD_P3 <= _DAT_0089f594)) {
        if (LOAD_LEN < 9) {
          DAT_01be1808 = 9 - LOAD_LEN;
          (&ITEM_LEN)[LOAD_W] = f_9;
          DAT_01be1810 = ITEM_WORDS;
          for (iVar1 = (((&DAT_02091d20)[LOAD_I] - ITEM_WORDS) + -1) / -1; 0 < iVar1;
              iVar1 = iVar1 + -1) {
            (&ITEM_LEN)[DAT_01be1808 + DAT_01be1810] = (&ITEM_LEN)[DAT_01be1810];
            DAT_01be1810 = DAT_01be1810 + -1;
          }
          DAT_01be1810 = 1;
          iVar1 = DAT_01be1808;
          while (iVar1 = iVar1 + -1, 0 < iVar1) {
            (&ITEM_LEN)[LOAD_LEN + LOAD_W + DAT_01be1810] = f_0;
            DAT_01be1810 = DAT_01be1810 + 1;
          }
          ITEM_WORDS = DAT_01be1808 + ITEM_WORDS;
          DAT_01be1810 = LOAD_I + 1;
          for (iVar1 = (ITEM_I - DAT_01be1810) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
            (&ITEM_PTR0)[DAT_01be1810] = (&ITEM_PTR0)[DAT_01be1810] + DAT_01be1808;
            DAT_01be1810 = DAT_01be1810 + 1;
          }
        }
        *(float *)(&ITEM_P9 + LOAD_W * 4) = f_m1;
      }
    }
    LOAD_I = LOAD_I + 1;
  }
LAB_004b8b57:
  DAT_0089f57c = DAT_02052740;
  DAT_02052740 = 0;
  draw_items();
  DAT_02052740 = DAT_0089f57c;
  DAT_0078b4f0 = 1;
  return;
}


