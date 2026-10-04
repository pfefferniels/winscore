// FUN_004b8b97 @ 004b8b97 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b8b97(void)

{
  float fVar1;
  
  if (DAT_020b8ea2 == 'X') {
    DAT_01ade8b0 = P3;
    DAT_01ade8b4 = P4;
    DAT_01ade8a8 = (int)ROUND(P2);
    DAT_01ade8ac = (int)ROUND(P5);
    DAT_0089f5a8 = (int)ROUND(P6);
    P2 = P7;
  }
  else {
    DAT_01ade8b0 = P1;
    DAT_01ade8b4 = P2;
    if (P2 == f_0) {
      DAT_01ade8b4 = DAT_01fbb8b8;
    }
    DAT_0089f5a8 = DAT_01fbb7e0;
    P2 = DAT_01fbb7e4;
  }
  _DAT_0089f5a4 = 0;
  DAT_0078b4e4 = 0x58;
  thunk_FUN_004f7808();
  DAT_01ade8a0 = (float)(&STAFF_STEP0)[DAT_0089f5a8] / f_25;
  DAT_01fbb8d0 = DAT_01ade8a0 * f_1_5;
  DAT_01fbb860 = DAT_01ade8a8;
  DAT_01fbb864 = DAT_01ade8ac;
  DAT_01fbb868 = DAT_01ade8b0;
  DAT_01fbb86c = DAT_01ade8b4;
  DAT_01fbb870 = f_0;
  DAT_01fbb874 = 0;
  DAT_01fbb878 = 1;
  DAT_01fbb87c = ITEM_I;
  thunk_FUN_0049b1d8();
  DAT_0089f5a0 = f_0;
  LOAD_I = 0;
  DAT_01fbb8cc = 1;
  DAT_01e99ca0 = f_0;
  DAT_01e99980 = DAT_01ade8b0;
  while (LOAD_I = LOAD_I + 1, LOAD_I <= ITEM_I) {
    load_item_header();
    if ((((LOAD_CODE == 0x10) && (DAT_01ade8b0 <= LOAD_P3)) && (LOAD_P3 <= DAT_01ade8b4)) &&
       (-1 < LOAD_STAFF - DAT_0089f5a8)) {
      if (0 < LOAD_STAFF - DAT_0089f5a8) break;
      DAT_0089f59c = (float)(&ITEM_P4)[LOAD_W];
      if ((P2 == f_99) || (ABS(DAT_0089f59c - P2) <= f_1_9)) {
        fVar1 = DAT_0089f59c;
        if (DAT_0089f5a0 != f_0) {
          if (f_1 < ABS(DAT_0089f59c - DAT_0089f5a0)) {
            return;
          }
          (&ITEM_P4)[LOAD_W] = DAT_0089f5a0;
          fVar1 = DAT_0089f5a0;
        }
        DAT_0089f5a0 = fVar1;
        DAT_01fbb8cc = DAT_01fbb8cc + 1;
        DAT_01fbb8d4 = *(float *)(&ITEM_P11 + LOAD_W * 4);
        *(float *)(DAT_01fbb8cc * 4 + 0x1e99c9c) =
             DAT_01fbb8d0 + (float)(&ITEM_P13)[LOAD_W] + DAT_01fbb8d4;
        if ((1 < DAT_01fbb8cc) && (DAT_01fbb8d4 != f_0)) {
          *(float *)(DAT_01fbb8cc * 4 + 0x1e99c98) =
               *(float *)(DAT_01fbb8cc * 4 + 0x1e99c98) - DAT_01fbb8d4;
        }
        (&DAT_01e9997c)[DAT_01fbb8cc] = LOAD_P3;
      }
    }
  }
  if (DAT_01fbb8cc != 1) {
    if (f_0_2 < DAT_01ade8b4 - (float)(&DAT_01e9997c)[DAT_01fbb8cc]) {
      DAT_01fbb8cc = DAT_01fbb8cc + 1;
      (&DAT_01e9997c)[DAT_01fbb8cc] = DAT_01ade8b4;
    }
    DAT_01ade8a4 = 1;
    if (DAT_01e99984 - DAT_01ade8b0 <= f_0_2) {
      DAT_01ade8a4 = 2;
      DAT_01fbb8cc = DAT_01fbb8cc + -1;
    }
    thunk_FUN_004b5db0(&DAT_01fbb8cc,&DAT_01ade8b0,&DAT_01ade8b4,&DAT_01e9997c + DAT_01ade8a4,
                       DAT_01ade8a4 * 4 + 0x1e99c9c,&DAT_01e99fc0);
    draw_items();
  }
  return;
}


