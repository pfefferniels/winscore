// FUN_0053fc37 @ 0053fc37 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0053fc37(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((P1 <= f_0) || (DAT_0078d894 < P1)) {
LAB_00540359:
    DAT_0078b4e0 = 0x42;
    draw_items();
  }
  else {
    DAT_0078b4e4 = 0x53;
    DAT_0099d208 = (int)ROUND(P1);
    DAT_0099d1f8 = 1;
    DAT_0099d204 = P1;
    DAT_0099d200 = P2;
    DAT_0099d1fc = P3;
    for (iVar3 = ITEM_I; 0 < iVar3; iVar3 = iVar3 + -1) {
      DAT_0099d1f4 = (&ITEM_PTR0)[DAT_0099d1f8];
      if (P1 == (float)(&ITEM_P2)[DAT_0099d1f4]) {
        DAT_0099d1f0 = (int)ROUND((float)(&ITEM_P1)[DAT_0099d1f4]);
        if (((((((6 < DAT_0099d1f0) && (DAT_0099d1f0 < 0x11)) && (DAT_0099d1f0 != 8)) &&
              (DAT_0099d1f0 != 0xe)) &&
             (((DAT_0099d1f0 != 7 || ((float)(&ITEM_P5)[DAT_0099d1f4] != f_1)) ||
              ((DAT_0099d1ec = (int)ROUND(*(float *)(&ITEM_P7 + DAT_0099d1f4 * 4)),
               DAT_0099d1ec != 0 && ((DAT_0099d1ec != 8 && (DAT_0099d1ec != -8)))))))) &&
            ((DAT_0099d1f0 != 9 ||
             ((((DAT_0099d1ec = (int)ROUND((float)(&ITEM_P5)[DAT_0099d1f4]), DAT_0099d1ec == 0x3b ||
                (DAT_0099d1ec == 0x43)) || (DAT_0099d1ec < 0x33)) || (0x44 < DAT_0099d1ec)))))) ||
           (((DAT_0099d1f0 == 4 && ((float)(&ITEM_P5)[DAT_0099d1f4] != f_999)) ||
            (((f_7 < (float)(&ITEM_P5)[DAT_0099d1f4] &&
              ((DAT_0099d1f0 == 0xe && (f_4 < (float)(&ITEM_LEN)[DAT_0099d1f4])))) ||
             (bVar1 = 0x10 < DAT_0099d1f0, iVar2 = thunk_FUN_005358e5(&DAT_0099d1f4),
             iVar2 != 0 && bVar1)))))) {
          (&ITEM_P2)[DAT_0099d1f4] = f_255;
        }
        else {
          (&ITEM_P2)[DAT_0099d1f4] = f_256;
        }
      }
      DAT_0099d1f8 = DAT_0099d1f8 + 1;
    }
    thunk_FUN_004f7808();
    DAT_01a1c778 = 0;
    DAT_0099d1f8 = 1;
    for (iVar3 = ITEM_I; 0 < iVar3; iVar3 = iVar3 + -1) {
      DAT_0099d1f4 = (&ITEM_PTR0)[DAT_0099d1f8] + 2;
      if ((DAT_01a1c778 == 0) && ((float)(&ITEM_LEN)[DAT_0099d1f4] == f_256)) {
        DAT_01a1c778 = DAT_0099d1f8;
      }
      if ((float)(&ITEM_LEN)[DAT_0099d1f4] == f_256) {
        (&ITEM_LEN)[DAT_0099d1f4] = DAT_0099d204;
      }
      DAT_0099d1f8 = DAT_0099d1f8 + 1;
    }
    LOAD_I = 1;
    DAT_01a9f304 = f_0;
    DAT_01a9f308 = f_0;
    P3 = DAT_0099d1fc;
    P2 = DAT_0099d200;
    P1 = DAT_0099d204;
    for (iVar3 = ITEM_I; 0 < iVar3; iVar3 = iVar3 + -1) {
      load_item_header();
      if ((((DAT_0099d208 == LOAD_STAFF) && (P2 <= LOAD_P3)) && (LOAD_P3 <= P3)) && (LOAD_CODE < 3))
      {
        DAT_01a9f30c = *(float *)(&ITEM_P7 + LOAD_W * 4);
        if ((DAT_01a9f304 == LOAD_P3) && (DAT_01a9f308 != DAT_01a9f30c)) {
          thunk_FUN_0054d831("Cannot re-edit counterpoint. See \"SEPX\" in Help.",0x31);
          DAT_0078b4e0 = 0x42;
          return;
        }
        if ((DAT_01a9f30c == f_0) || (LOAD_LEN < 7)) {
          if (DAT_01be12e0 == 0) goto LAB_00540359;
          if (LOAD_LEN < 7) {
            thunk_FUN_005239c9(&LOAD_I,&f_7);
          }
          DAT_01a9f30c = f_1;
          if (DAT_01a9f304 == LOAD_P3) {
            DAT_01a9f30c = DAT_01a9f308;
          }
          *(float *)(&ITEM_P7 + LOAD_W * 4) = DAT_01a9f30c;
        }
        if (f_64 < DAT_01a9f30c) {
          DAT_01a9f30c = f_64;
        }
        if ((DAT_01a9f304 == LOAD_P3) &&
           ((LOAD_CODE == 2 || ((DAT_01a9f30c != f_0 && (DAT_01a9f308 != DAT_01a9f30c))))))
        goto LAB_00540359;
        DAT_01a9f308 = DAT_01a9f30c;
        DAT_01a9f304 = LOAD_P3;
      }
      LOAD_I = LOAD_I + 1;
    }
  }
  return;
}


