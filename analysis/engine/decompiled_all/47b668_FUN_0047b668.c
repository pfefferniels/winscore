// FUN_0047b668 @ 0047b668 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047b668(void)

{
  int iVar1;
  int iVar2;
  int local_44;
  
  if (-1 < (int)(DAT_00795440 + 1)) {
    if ((int)(DAT_00795440 + 1) < 1) {
      DAT_00795440 = 0;
    }
    if (1 < (int)DAT_00795440) {
      LOAD_P3 = DAT_01ba0d38 + f_0_1;
      FUN_0047bbee(&DAT_00795440,&LOAD_P3);
    }
  }
  _DAT_00828500 = (float)DAT_01c2cc20;
  DAT_008284fc = 1;
  iVar2 = ITEM_I;
  do {
    if (iVar2 < 1) {
      if ((DAT_00795444 == 0x45) && (DAT_00795440 != 0xfffffffe)) {
        ITEM_I = ITEM_I + -1;
        DAT_008284fc = 8;
        if (999 < (int)DAT_00795440) {
          DAT_008284fc = 0x13;
        }
        ITEM_WORDS = ITEM_WORDS - DAT_008284fc;
      }
      return;
    }
    DAT_008284f8 = (&ITEM_PTR0)[DAT_008284fc];
    LOAD_CODE = (int)ROUND((float)(&ITEM_P1)[DAT_008284f8]);
    DAT_008284f4 = (int)ROUND((float)(&ITEM_LEN)[DAT_008284f8]);
    if ((LOAD_CODE < 4) || (8 < LOAD_CODE)) {
      if (LOAD_CODE == 0xe) {
        _DAT_008284ec = (float)(&ITEM_P3)[DAT_008284f8];
        if ((DAT_008284e8 - f_0_1 <= _DAT_008284ec) && (_DAT_008284ec <= DAT_008284e8 + f_0_1)) {
          (&ITEM_P3)[DAT_008284f8] = DAT_008284e8;
        }
        if (((DAT_00795440 < 0x80000000) && (DAT_01ba0d38 + f_4 < _DAT_008284ec)) &&
           (_DAT_00828500 == (float)(&ITEM_P2)[DAT_008284f8])) {
          LOAD_I = DAT_008284fc + -1;
          for (iVar1 = -LOAD_I / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
            load_item_header();
            if (LOAD_CODE < 3) {
              DAT_00795440 = DAT_00795440 + 1;
              if (DAT_00795444 == 0x45) {
                FUN_0047bbee(&DAT_00795440,&DAT_008284ec);
              }
              break;
            }
            if (LOAD_CODE == 0xe) break;
            LOAD_I = LOAD_I + -1;
          }
        }
      }
      else if ((((LOAD_CODE == 2) && (7 < DAT_008284f4)) &&
               ((DAT_00795440 < 0x80000000 &&
                ((_DAT_00828500 == (float)(&ITEM_P2)[DAT_008284f8] &&
                 ((float)(&ITEM_P5)[DAT_008284f8] != f_m4)))))) &&
              (f_0 < *(float *)(&ITEM_P8 + DAT_008284f8 * 4))) {
        DAT_00795440 = (uint)ROUND(((float)(int)DAT_00795440 +
                                   *(float *)(&ITEM_P8 + DAT_008284f8 * 4)) - f_1);
      }
    }
    else {
      if (((DAT_00795440 < 0x80000000) && (LOAD_CODE == 8)) &&
         ((float)DAT_01c2cc24 == (float)(&ITEM_P2)[DAT_008284f8])) {
        DAT_008284f0 = DAT_008284f8;
      }
      if (5 < DAT_008284f4) {
        if ((LOAD_CODE == 6) && (10 < DAT_008284f4)) {
          local_44 = 5;
          DAT_008284f0 = 0xb;
          do {
            if (f_204 < (float)(&ITEM_LEN)[DAT_008284f0 + DAT_008284f8]) {
              (&ITEM_LEN)[DAT_008284f0 + DAT_008284f8] = f_204;
            }
            if (DAT_008284f0 == DAT_008284f4) break;
            DAT_008284f0 = DAT_008284f0 + 1;
            local_44 = local_44 + -1;
          } while (0 < local_44);
        }
        if (f_202 < (float)(&ITEM_P6)[DAT_008284f8]) {
          (&ITEM_P6)[DAT_008284f8] = f_202;
        }
      }
    }
    DAT_008284fc = DAT_008284fc + 1;
    iVar2 = iVar2 + -1;
  } while( true );
}


