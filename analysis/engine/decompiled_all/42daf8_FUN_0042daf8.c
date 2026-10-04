// FUN_0042daf8 @ 0042daf8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042daf8(undefined4 *param_1,float *param_2,int *param_3)

{
  int iVar1;
  
  do {
    DAT_01caf6c8 = f_99999;
    DAT_01caf6f0 = 0;
    DAT_01caf6f4 = 0;
    *param_3 = 0;
    DAT_007f13ac = 1;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      LOAD_I = DAT_007f13ac;
      load_item_header();
      if ((DAT_01caf6a8 != LOAD_W) && (DAT_01caf6a0 == LOAD_STAFF)) {
        if ((DAT_01caf6c0 == 0) || (LOAD_CODE != 0xe)) {
          if ((DAT_01caf6c0 != 0) || (2 < LOAD_CODE)) goto LAB_0042dc35;
          DAT_01caf6f4 = DAT_01caf6f4 + 1;
        }
        DAT_01caf6dc = ABS(LOAD_P3 - *param_2);
        if (DAT_01caf6dc < DAT_01caf6c8) {
          DAT_01caf6c8 = DAT_01caf6dc;
          *param_3 = LOAD_W;
          DAT_01caf6d0 = LOAD_LEN;
          if (DAT_01caf6f0 == 0) {
            DAT_01caf6f0 = DAT_01caf6f4;
          }
        }
      }
LAB_0042dc35:
      DAT_007f13ac = DAT_007f13ac + 1;
    }
    if (*param_3 == 0) {
      return;
    }
    *(undefined4 *)(&P0 + DAT_01caf6b0 * 4) = *param_1;
    DAT_01caf6dc = f_0;
    if (2 < DAT_01caf6d0) {
      DAT_01caf6dc = (float)(&ITEM_P3)[*param_3];
    }
    if ((((DAT_020b948c == f_0) && (*(float *)(&ITEM_P7 + *param_3 * 4) < f_20)) &&
        (DAT_01caf6ac == 6)) &&
       ((f_20 <= (float)(&ITEM_LEN)[*param_3] && (*(float *)(&ITEM_P20 + *param_3 * 4) != f_0)))) {
      _DAT_007f13a8 = (STEP * f_2_8333) / f_25;
      DAT_01caf6dc = (_DAT_007f13a8 * (float)(&ITEM_LEN)[(int)ROUND((float)*param_3 + f_20)] +
                     DAT_01caf6dc) - _DAT_007f13a8;
    }
    if ((DAT_01caf6ac == 6) && (DAT_020b9458 < f_0)) {
      if ((5 < DAT_01caf6d0) &&
         ((((float)(&ITEM_P1)[*param_3] == f_1 &&
           (LOAD_I = (int)ROUND((float)(&ITEM_P6)[*param_3]), 1 < LOAD_I)) && (LOAD_I < 4)))) {
        (&P1)[DAT_01caf6b0] = DAT_01caf6dc;
        DAT_01caf6dc = f_1_6;
        if (f_m10 <= DAT_020b9458) {
          DAT_01caf6dc = f_m1_23;
        }
        if ((9 < DAT_01caf6d0) && (*(float *)(&ITEM_P10 + *param_3 * 4) != f_0)) {
          LOAD_P3 = *(float *)(&ITEM_P10 + *param_3 * 4);
          if (LOAD_P3 == f_10) {
            LOAD_P3 = f_3_26;
          }
          if (LOAD_P3 == f_20) {
            LOAD_P3 = f_m3_26;
          }
          DAT_01caf6dc = LOAD_P3 + DAT_01caf6dc;
        }
        DAT_01caf6b0 = DAT_01caf6b0 + 2;
        *(float *)(&P0 + DAT_01caf6b0 * 4) = f_14;
      }
      goto LAB_0042e0e3;
    }
    if (DAT_01caf6c0 + -1 < 0) goto LAB_0042e0e3;
    if (DAT_01caf6c0 + -1 < 1) {
      if (DAT_01caf6b0 == 1) {
        if ((4 < DAT_01caf6d0) && ((float)(&ITEM_P5)[*param_3] == f_3)) {
LAB_0042e093:
          DAT_01caf6dc = DAT_020b9448;
        }
        goto LAB_0042e0e3;
      }
      if (_DAT_007f13a4 != DAT_01caf6dc) {
LAB_0042e017:
        DAT_01caf6d0 = (int)ROUND((float)(&ITEM_P2)[*param_3]);
        DAT_01caf6c8 = f_2_3;
        if (DAT_01caf6c0 == 2) {
          DAT_01caf6c8 = f_1;
        }
        DAT_01caf6dc = DAT_01caf6dc - (DAT_01caf6c8 * (float)(&STAFF_STEP0)[DAT_01caf6d0]) / f_25;
        goto LAB_0042e0e3;
      }
    }
    else {
      if (DAT_01caf6b0 == 1) {
        if ((4 < DAT_01caf6d0) && ((float)(&ITEM_P5)[*param_3] == f_3)) goto LAB_0042e017;
        goto LAB_0042e093;
      }
      if (f_4 < DAT_01caf6dc - P2) goto LAB_0042e0e3;
    }
    *param_2 = *param_2 + f_2;
    if (DAT_01fbb8b8 < *param_2) {
      DAT_01caf6dc = DAT_020b9454;
      if (DAT_01fbb8b8 < DAT_020b9454) {
        DAT_01caf6dc = DAT_01fbb8b8;
      }
LAB_0042e0e3:
      (&P1)[DAT_01caf6b0] = DAT_01caf6dc;
      DAT_01caf6b0 = DAT_01caf6b0 + 2;
      DAT_01caf68c = DAT_01caf6dc;
      return;
    }
  } while( true );
}


