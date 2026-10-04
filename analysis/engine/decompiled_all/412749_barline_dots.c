// barline_dots @ 00412749 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void barline_dots(float *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  
  IP8 = 0;
  IP5 = 1;
  IP16 = 0;
  _DAT_007d1334 = f_42;
  if (P16 != f_0) {
    iVar1 = (int)ROUND(P16) / 100;
    _DAT_007d1334 = (float)(iVar1 * 7);
    IP16 = (int)ROUND(P16) % 100 - iVar1;
  }
  DAT_007d1330 = *param_2 + CUR_STAFF + -1;
  if (MAX_STAFF < DAT_007d1330) {
    DAT_007d1330 = MAX_STAFF;
  }
  P6 = f_0_58;
  if (P12 != f_0) {
    P6 = P12 * f_0_58;
  }
  P13 = f_1;
  DAT_007d1338 = STEP;
  P3 = X_POS;
  P7 = P6;
  DAT_007d132c = P12;
  P12 = f_0;
  DAT_007d1328 = CUR_STAFF;
  X_POS = _DAT_02052c08 * *param_1 + X_POS;
  for (iVar1 = (DAT_007d1330 - CUR_STAFF) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_007d1324 = (float)(&STAFF_STEP0)[DAT_007d1328];
    in_ST0 = (float10)DAT_007d1324 * (float10)_DAT_007d1334;
    Y_POS = (float)((float10)(int)(&STAFF_Y0)[DAT_007d1328] + in_ST0);
    iVar2 = 2;
    DAT_007d1320 = 1;
    do {
      STEP = DAT_007d1324;
      IP9 = 0;
      IP11 = 0;
      IP10 = 0;
      IP12 = 0;
      if (OUTPUT_MODE != -1) {
        IP12 = 0x3c;
      }
      ffree(in_ST0);
      in_ST0 = (float10)draw_box();
      STEP = f_14;
      if (IP16 != 0) {
        STEP = (float)(IP16 * 7);
      }
      Y_POS = DAT_007d1324 * STEP + Y_POS;
      DAT_007d1320 = DAT_007d1320 + 1;
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
    DAT_007d1328 = DAT_007d1328 + 1;
  }
  X_POS = P3;
  P12 = DAT_007d132c;
  STEP = DAT_007d1338;
  ffree(in_ST0);
  return;
}


