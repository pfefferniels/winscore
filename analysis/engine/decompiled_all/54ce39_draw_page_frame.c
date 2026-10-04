// draw_page_frame @ 0054ce39 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_page_frame(void)

{
  int iVar1;
  
  DAT_009a23d4 = COLOR;
  DAT_009a23d0 = P2;
  DAT_009a23cc = EDIT_ITEM;
  DAT_009a23c8 = CUR_STAFF;
  if (PAPER == 0) goto LAB_0054d435;
  for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
    *(float *)(&P0 + iVar1 * 4) = f_0;
  }
  P26 = f_9900;
  if (DAT_020b8ea0 == 0x4320) {
code_r0x0054cef6:
    switch(PAPER) {
    default:
      P1 = f_69000;
      P2 = f_44500;
      thunk_FUN_00490cce(&P1,&P2);
      thunk_FUN_00579770(&DAT_00769450,1,&IP1);
code_r0x0054d376:
      P4 = f_129_8695;
      P7 = f_251_427;
      P3 = f_100;
      P6 = f_194_2845;
      break;
    case 2:
      P1 = f_69000;
      P2 = f_58500;
      thunk_FUN_00579770(&DAT_00769450,1,&IP1);
code_r0x0054cf38:
      P4 = f_164_15501;
      P7 = f_319_99802;
      P3 = f_100;
      P6 = f_194_2845;
      break;
    case 3:
      P1 = f_69500;
      P2 = f_72000;
      VIEW_DY = 0xa4d8;
      thunk_FUN_00579770(&DAT_00769450,1,&IP1);
code_r0x0054cfb5:
      P3 = _DAT_0079d6ec * f_11 - _DAT_0079d6ec;
      P4 = f_198_4405;
      P6 = f_251_427;
      P7 = f_388_569;
      break;
    case 4:
      P1 = f_69000;
      P2 = f_44500;
      VIEW_DY = 0x45ec;
      thunk_FUN_00579770(&DAT_00769450,1,&IP1);
code_r0x0054d03e:
      P1 = f_4;
      P2 = f_0;
      P3 = f_213_334;
      P6 = f_213_334;
      P4 = f_4_5;
      P5 = f_256;
      draw_item();
      IP1 = 0;
      IP2 = 55000;
      P4 = f_129_8695;
      P5 = f_0;
      P6 = f_388_569;
      P7 = f_251_427;
      P3 = _DAT_0079d6f0 * f_8_5 - _DAT_0079d6ec;
      break;
    case 5:
      P1 = f_69000;
      P2 = f_69000;
      VIEW_DY = 0xa0f0;
      thunk_FUN_00579770(&DAT_00769450,1,&IP1);
code_r0x0054d133:
      P4 = f_192_72626;
      P7 = f_377_1405;
      P6 = f_267_4269;
      P3 = _DAT_0079d6f0 * f_5_85 - _DAT_0079d6ec;
      break;
    case 6:
      P1 = f_69000;
      P2 = f_56500;
      VIEW_DY = 0x5014;
      thunk_FUN_00579770(&DAT_00769450,1,&IP1);
code_r0x0054d1bc:
      P4 = f_137_86946;
      P7 = f_267_4269;
      P6 = f_189_7131;
      P3 = _DAT_0079d6f0 * f_4_15 - _DAT_0079d6ec;
      break;
    case 7:
      P1 = f_69000;
      P2 = f_69000;
      VIEW_DY = 0x75f8;
      thunk_FUN_00579770(&DAT_00769450,1,&IP1);
code_r0x0054d245:
      P4 = f_163_01216;
      P6 = f_223_99861;
      P7 = f_317_7123;
      P3 = _DAT_0079d6f0 * f_4_9 - _DAT_0079d6ec;
      break;
    case 8:
      P1 = f_69000;
      P2 = f_69000;
      VIEW_DY = 0xa0f0;
      thunk_FUN_00579770(&DAT_00769450,1,&IP1);
code_r0x0054d2ce:
      P4 = (DAT_00791634 / f_2) * f_22_857 + f_4_156;
      P7 = DAT_00791634 * f_22_857;
      P6 = DAT_00791630 * f_22_857;
      P3 = _DAT_0079d6ec * DAT_00791630 - _DAT_0079d6ec;
    }
    if (DAT_020b8ea0 == 0x4320) {
      IP1 = -0x960;
      IP2 = 55000;
      thunk_FUN_00579770(&DAT_00769278,1,&IP1);
    }
    P1 = f_12;
    P2 = f_0;
    P8 = f_2;
    draw_item();
    EDIT_ITEM = -1;
    flush_points();
LAB_0054d435:
    if (DAT_020b8ea2 == 'E') {
      P6 = f_0;
      P7 = f_0;
      P1 = f_14;
      P3 = DAT_009a23d0;
      P2 = f_1;
      P26 = f_9020;
      P4 = f_30;
      P5 = f_7;
      P8 = f_2;
      P9 = f_3;
      P10 = f_m6;
      P11 = f_18;
    }
    else {
      if (DAT_0078d890 == 0) {
        COLOR = DAT_009a23d4;
        EDIT_ITEM = DAT_009a23cc;
        return;
      }
      for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
        *(float *)(&P0 + iVar1 * 4) = f_0;
      }
      COLOR = 0x962c;
      if (DAT_0078d890 < 0) {
        CUR_STAFF = DAT_009a23c8;
        thunk_FUN_00523c2d();
        COLOR = DAT_009a23d4;
        EDIT_ITEM = DAT_009a23cc;
        return;
      }
      P2 = (float)(DAT_0078d890 % 1000);
      DAT_009a23c4 = DAT_0078d890 / 1000;
      P1 = f_13;
      if (1 < DAT_009a23c4) {
        COLOR = 0x7ffd;
      }
      if (2 < DAT_009a23c4) {
        COLOR = (int)&DAT_00fd7f00;
      }
      if (DAT_009a23c4 < 4) {
        P6 = f_25 / (float)(&STAFF_STEP0)[(int)ROUND(P2)];
        DAT_009a23c0 = f_1 / P6;
        P4 = f_11 - f_11 / DAT_009a23c0;
        P5 = ((float)DAT_009a23c4 + f_1300) - f_1;
        if (DAT_01fbb8b8 == f_234) {
          P5 = f_1308;
        }
        if (DAT_01fbb8b8 == f_194) {
          P5 = f_1307;
        }
        if (DAT_01fbb8b8 == f_285) {
          P5 = f_1306;
        }
        if (DAT_01fbb8b8 == f_266) {
          P5 = f_1305;
        }
        if (DAT_01fbb8b8 == f_213) {
          P5 = f_1309;
        }
      }
      else {
        P3 = f_m7;
        if (P2 != f_0) {
          P3 = P2;
        }
        P2 = f_0;
        P4 = f_21;
        P5 = f_1303;
        P6 = f_3_333;
        if (4 < DAT_009a23c4) {
          P5 = f_1304;
          P6 = f_2_623;
        }
      }
    }
    draw_item();
    EDIT_ITEM = -1;
    flush_points();
    for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
      *(float *)(&P0 + iVar1 * 4) = f_0;
    }
    FUN_00549422();
    COLOR = DAT_009a23d4;
    EDIT_ITEM = DAT_009a23cc;
    return;
  }
  switch(PAPER) {
  case 1:
    goto code_r0x0054d376;
  case 2:
    goto code_r0x0054cf38;
  case 3:
    goto code_r0x0054cfb5;
  case 4:
    goto code_r0x0054d03e;
  case 5:
    goto code_r0x0054d133;
  case 6:
    goto code_r0x0054d1bc;
  case 7:
    goto code_r0x0054d245;
  case 8:
    goto code_r0x0054d2ce;
  default:
    goto code_r0x0054cef6;
  }
}


