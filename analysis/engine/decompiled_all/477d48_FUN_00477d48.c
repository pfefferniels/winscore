// FUN_00477d48 @ 00477d48 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477d48(void)

{
  float fVar1;
  int iVar2;
  int local_1c;
  
  P1 = f_0;
  P4 = 1.4013e-45;
  _DAT_00828384 = 1;
  P6 = 1.4013e-45;
  P7 = (float)ITEM_WORDS;
  thunk_FUN_0049836a(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&P6,&P7);
LAB_00477dc7:
  DAT_0078b4e4 = 0;
  ITEM_I = (int)P6;
  thunk_FUN_0049846f(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&P6);
  P10 = 0.0;
  DAT_00828380 = 0;
  LOAD_I = 0;
LAB_00477e08:
  LOAD_I = LOAD_I + 1;
  do {
    if (ITEM_I < LOAD_I) {
      P2 = f_9999;
      P6 = (float)ITEM_I;
      P8 = 0.0;
      break;
    }
    load_item_header();
    if (LOAD_CODE != 0) {
      if (LOAD_CODE == 5) {
        if (((LOAD_LEN < 8) ||
            (DAT_0082837c = (float)(int)ROUND(*(float *)(&ITEM_P8 + LOAD_W * 4)),
            (int)DAT_0082837c < 1)) || (2 < (int)DAT_0082837c)) goto LAB_00477e08;
        DAT_00828378 = (float)LOAD_I;
        goto LAB_00478220;
      }
      if (LOAD_CODE == 0xe) {
        if (P10 == 0.0) {
          if ((LOAD_LEN < 5) || ((float)(&ITEM_P5)[LOAD_W] != f_4)) goto LAB_00477ef3;
          P10 = 1.4013e-45;
          goto LAB_00477eb7;
        }
      }
      else {
LAB_00477eb7:
        if (LOAD_CODE != 0x12) goto LAB_00477f2a;
      }
      if ((DAT_00828380 != LOAD_CODE) || (f_0_05 < LOAD_P3 - _DAT_00828370)) goto LAB_00477f2a;
    }
LAB_00477ef3:
    thunk_FUN_005857c8(&LOAD_I);
  } while( true );
  do {
    P8 = (float)((int)P8 + 1);
LAB_0047835a:
    P11 = (float)(&ITEM_PTR0)[(int)P8];
    _DAT_0082836c = (float)(&ITEM_P1)[(int)P11];
    P12 = (float)(int)ROUND(_DAT_0082836c);
    P3 = (float)(&ITEM_P3)[(int)P11] + f_0_5;
    DAT_00828368 = (int)ROUND((float)(&ITEM_LEN)[(int)P11]);
    if (P12 == 1.4013e-45) goto LAB_0047881c;
    if (P12 == 2.8026e-45) {
      if (DAT_00828368 < 5) goto LAB_0047881c;
      DAT_0082837c = 0.0;
      P2 = (float)(&ITEM_P5)[(int)P11];
      if ((f_m2 < P2) || (P2 == f_m4)) goto LAB_0047881c;
      DAT_00828378 = (float)((int)P8 + 1);
      iVar2 = ((int)P6 - (int)DAT_00828378) + 1;
      if (0 < iVar2) {
        while( true ) {
          P13 = (float)(&ITEM_PTR0)[(int)DAT_00828378];
          if (P3 < (float)(&ITEM_P3)[(int)P13]) goto LAB_004789b9;
          DAT_00828374 = (int)ROUND((float)(&ITEM_P1)[(int)P13]);
          if (DAT_00828374 == 1) break;
          if (DAT_00828374 == 2) {
            if (((float)(&ITEM_LEN)[(int)P13] < f_5) || (P2 != (float)(&ITEM_P5)[(int)P13])) break;
            DAT_0082837c = (float)((int)DAT_0082837c + 1);
            (&P18)[(int)DAT_0082837c] = (float)((int)P13 + 1);
          }
          DAT_00828378 = (float)((int)DAT_00828378 + 1);
          iVar2 = iVar2 + -1;
          if (iVar2 < 1) goto LAB_004789ad;
        }
        goto LAB_0047881c;
      }
LAB_004789ad:
      DAT_00828378 = P6;
LAB_004789b9:
      for (; DAT_0082837c != 0.0; DAT_0082837c = (float)((int)DAT_0082837c + -1)) {
        (&ITEM_LEN)[(int)(&P18)[(int)DAT_0082837c]] = f_0;
      }
      P8 = (float)((int)DAT_00828378 + -1);
      goto LAB_00478a13;
    }
    if (P12 != 1.96182e-44) {
      if (P12 == 1.4013e-44) {
        if (DAT_00828368 < 8) goto LAB_00478a13;
      }
      else {
        if ((int)P12 < 0x11) goto LAB_00478a13;
        if ((0xd < DAT_00828368) && (*(float *)(&ITEM_P14 + (int)P11 * 4) = f_0, 0xe < DAT_00828368)
           ) {
          *(float *)(&ITEM_P15 + (int)P11 * 4) = f_0;
        }
        if (P12 != 2.52234e-44) goto LAB_00478a13;
        (&ITEM_P4)[(int)P11] = f_0;
        if (6 < DAT_00828368) {
          *(float *)(&ITEM_P7 + (int)P11 * 4) = f_0;
        }
        if ((DAT_01c4c78c != 1) || (P2 != P3)) {
          DAT_01c4c78c = DAT_01c4c78c + 1;
        }
        P2 = P3;
        if (DAT_01c4c78c == 1) goto LAB_00478a13;
      }
      DAT_00828378 = (float)((int)P8 + 1);
      iVar2 = ((int)P6 - (int)DAT_00828378) + 1;
      while( true ) {
        if ((iVar2 < 1) ||
           (DAT_00828364 = (&ITEM_PTR0)[(int)DAT_00828378],
           f_5 < (float)(&ITEM_P3)[DAT_00828364] - P3)) goto LAB_0047890c;
        if ((float)(&ITEM_P1)[DAT_00828364] == f_14) break;
        DAT_00828378 = (float)((int)DAT_00828378 + 1);
        iVar2 = iVar2 + -1;
      }
      (&ITEM_P3)[(int)P11] = (float)(&ITEM_P3)[DAT_00828364] + f_0_5;
      thunk_FUN_0049846f(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&P6);
      goto LAB_0047835a;
    }
LAB_0047890c:
    if (P12 == 1.4013e-44) break;
    (&ITEM_P2)[(int)P11] = f_1;
    if ((5 < DAT_00828368) && (P12 == 1.96182e-44)) {
      DAT_00828378 = 8.40779e-45;
      for (iVar2 = DAT_00828368 + -5; 0 < iVar2; iVar2 = iVar2 + -1) {
        (&ITEM_LEN)[(int)DAT_00828378 + (int)P11] = f_0;
        DAT_00828378 = (float)((int)DAT_00828378 + 1);
      }
    }
LAB_00478a13:
  } while ((int)P8 < (int)P6);
  P8 = 0.0;
  P9 = 0.0;
  P18 = DAT_01ba2084;
  do {
    P8 = (float)((int)P8 + 1);
    P11 = (float)(&ITEM_PTR0)[(int)P8];
    P12 = (float)(int)ROUND((float)(&ITEM_P1)[(int)P11]);
    DAT_00828368 = (int)ROUND((float)(&ITEM_LEN)[(int)P11] + f_1);
    if (P12 == 2.8026e-45) {
      P3 = (float)(&ITEM_P3)[(int)P11] + f_0_5;
      P16 = (float)(int)ROUND((float)(&ITEM_P5)[(int)P11]);
      if ((((-2 < (int)P16) || (P16 == -NAN)) ||
          ((8 < DAT_00828368 && (*(float *)(&ITEM_P8 + (int)P11 * 4) < f_0)))) ||
         (FUN_004790b6(&P8,&P6,&P16), P16 == 0.0)) goto LAB_00478f68;
      if (1 < DAT_01ba2080) {
        P3 = P3 - f_0_5;
        LOAD_I = (int)P8 + 1;
        iVar2 = ((int)P6 - LOAD_I) + 1;
        P2 = f_0;
        while ((0 < iVar2 && (load_item_header(), LOAD_CODE != 0xe))) {
          if (LOAD_CODE == 2) {
            if (P3 == LOAD_P3) {
              (&ITEM_P1)[LOAD_W] = f_0;
            }
          }
          else if (LOAD_CODE == 0) {
            P3 = LOAD_P3;
          }
          LOAD_I = LOAD_I + 1;
          iVar2 = iVar2 + -1;
        }
      }
      ITEM_I = (int)P6;
      LOAD_I = (int)P8;
      while (LOAD_I < ITEM_I) {
        LOAD_I = LOAD_I + 1;
        if ((float)(&ITEM_P1)[(&ITEM_PTR0)[LOAD_I]] == f_0) {
          thunk_FUN_005857c8(&LOAD_I);
          LOAD_I = LOAD_I + -1;
        }
      }
      P6 = (float)ITEM_I;
      thunk_FUN_0054c590(&ITEM_LEN + (int)P11,&DAT_01c6da5c + (int)P4 * 4,&DAT_0076234c);
      (&DAT_01c6da64)[(int)P4] = f_1;
      P2 = f_m2;
      if (1 < (int)P16) {
        P2 = (float)(-10 - (int)P16);
      }
      if ((int)P16 < 10) {
        iVar2 = DAT_01c5860c;
        if (DAT_01c5860c < 0) {
          iVar2 = -DAT_01c5860c;
        }
        if (iVar2 < 3) goto LAB_00478e4a;
      }
      else {
LAB_00478e4a:
        P2 = f_m5;
      }
      (&DAT_01c6da70)[(int)P4] = P2;
      *(float *)(&DAT_01c6da5c + (int)P4 * 4) = f_17;
      *(float *)((int)P4 * 4 + 0x1c6daa0) =
           (float)(int)P16 * *(float *)(&DAT_01c6da78 + (int)P4 * 4);
      local_1c = 7;
      DAT_00828368 = 10;
      do {
        *(float *)(&DAT_01c6da5c + (DAT_00828368 + (int)P4) * 4) = f_0;
        DAT_00828368 = DAT_00828368 + 1;
        local_1c = local_1c + -1;
      } while (0 < local_1c);
      (&DAT_01c6da7c)[(int)P4] = (float)(int)P16;
      (&DAT_01c6da80)[(int)P4] = f_m1;
      if ((int)P16 < 2) {
        P16 = 2.8026e-45;
      }
      if (6 < (int)P16) {
        P16 = 8.40779e-45;
      }
      *(float *)(&DAT_01c6da78 + (int)P4 * 4) = (float)(int)P16;
      DAT_00828368 = 0x12;
    }
    else {
      if ((P12 == 1.12104e-44) && (3 < DAT_00828368)) {
        P1 = (float)(&ITEM_P3)[(int)P11];
      }
LAB_00478f68:
      thunk_FUN_0054c590(&ITEM_LEN + (int)P11,&DAT_01c6da5c + (int)P4 * 4,&DAT_00828368);
      if (P12 == 1.96182e-44) {
        if (DAT_00828368 < 5) {
          *(float *)(&DAT_01c6da5c + (int)P4 * 4) = f_4;
          DAT_00828368 = 5;
        }
        *(float *)(&DAT_01c6da5c + (DAT_00828368 + (int)P4) * 4) = f_0;
        (&DAT_01c6da64)[(int)P4] = f_1;
        (&DAT_01c6da6c)[(int)P4] = P18;
      }
    }
    P9 = (float)((int)P9 + 1);
    (&DAT_01c4637c)[(int)P9] = P4;
    P4 = (float)(DAT_00828368 + (int)P4);
    if ((P12 == 1.4013e-45) || (P12 == 2.8026e-45)) {
      P10 = 1.4013e-45;
    }
    if ((int)P6 <= (int)P8) {
      DAT_01ba2064 = P9;
      DAT_01ba2068 = P4;
      (&DAT_01c46380)[(int)P9] = P4;
      return;
    }
  } while( true );
LAB_0047881c:
  DAT_00828378 = (float)((int)P8 + 1);
  for (iVar2 = ((int)P6 - (int)DAT_00828378) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
    if (P3 < (float)(&ITEM_P3)[(&ITEM_PTR0)[(int)DAT_00828378]]) goto LAB_00478893;
    DAT_00828378 = (float)((int)DAT_00828378 + 1);
  }
  DAT_00828378 = P6;
LAB_00478893:
  P8 = DAT_00828378;
  goto LAB_0047835a;
LAB_00478220:
  DAT_00828378 = (float)((int)DAT_00828378 + 1);
  if ((int)P6 < (int)DAT_00828378) goto LAB_00477e08;
  DAT_0082837c = (float)(&ITEM_PTR0)[(int)DAT_00828378];
  DAT_00828374 = (int)ROUND((float)(&ITEM_P1)[(int)DAT_0082837c]);
  if (DAT_00828374 < 3) goto LAB_00477e08;
  if (DAT_00828374 == 0xe) {
    (&ITEM_P3)[LOAD_W] = (float)(&ITEM_P3)[(int)DAT_0082837c] + f_0_02;
    P6 = (float)ITEM_I;
    goto LAB_00477dc7;
  }
  goto LAB_00478220;
LAB_00477f2a:
  if (LOAD_CODE < 3) {
    P10 = 1.4013e-45;
  }
  if (((((f_0 < *(float *)(&ITEM_P7 + LOAD_W * 4)) && (6 < LOAD_LEN)) && (LOAD_STAFF == 1)) &&
      ((1 < DAT_01ba2080 && (LOAD_CODE == 2)))) && ((float)(&ITEM_P5)[LOAD_W] == f_m2)) {
    P12 = 0.0;
    DAT_0082837c = (float)(LOAD_I + 1);
    for (iVar2 = (ITEM_I - (int)DAT_0082837c) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
      P8 = (float)(&ITEM_PTR0)[(int)DAT_0082837c];
      if (f_0_05 < (float)(&ITEM_P3)[(int)P8] - LOAD_P3) goto LAB_00478104;
      if ((((float)(&ITEM_P1)[(int)P8] != f_2) || (*(float *)(&ITEM_P7 + (int)P8 * 4) <= f_0)) ||
         (((float)(&ITEM_LEN)[(int)P8] < f_7 || ((float)(&ITEM_P5)[(int)P8] != f_m2))))
      goto LAB_0047816c;
      if (P12 == 0.0) {
        P12 = DAT_0082837c;
      }
      DAT_0082837c = (float)((int)DAT_0082837c + 1);
    }
    DAT_0082837c = (float)(ITEM_I + 1);
LAB_00478104:
    fVar1 = P12;
    if (P12 != 0.0) {
      do {
        P11 = fVar1;
        thunk_FUN_005857c8(&P12);
        P11 = (float)((int)P11 + 1);
        fVar1 = P11;
      } while ((int)P11 < (int)DAT_0082837c);
    }
  }
LAB_0047816c:
  _DAT_00828370 = LOAD_P3;
  if (LOAD_CODE != 0) {
    DAT_00828380 = LOAD_CODE;
  }
  goto LAB_00477e08;
}


