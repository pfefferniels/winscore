// FUN_00479cf8 @ 00479cf8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479cf8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  DAT_008283f4 = 0;
  DAT_008283f0 = 1;
  iVar4 = ITEM_I;
  do {
    if (iVar4 < 1) {
      return;
    }
    DAT_008283ec = (&ITEM_PTR0)[DAT_008283f0];
    DAT_008283e8 = (int)ROUND((float)(&ITEM_P1)[DAT_008283ec]);
    if (DAT_008283e8 < 3) {
      DAT_008283f4 = 1;
    }
    else if ((DAT_008283f4 != 0) && (iVar2 = DAT_008283f0, DAT_008283e8 == 8)) {
      do {
        DAT_008283e4 = iVar2;
        iVar2 = DAT_008283e4 + -1;
        if (iVar2 < 1) {
          DAT_008283e4 = iVar2;
          return;
        }
        DAT_008283ec = (&ITEM_PTR0)[iVar2];
      } while ((float)(&ITEM_P1)[DAT_008283ec] != f_14);
      DAT_008283e0 = (float)(&ITEM_P3)[DAT_008283ec] - f_2;
      DAT_008283dc = 1;
      iVar3 = DAT_008283e4 + -2;
      DAT_008283e4 = iVar2;
      for (; 0 < iVar3; iVar3 = iVar3 + -1) {
        DAT_008283ec = (&ITEM_PTR0)[DAT_008283dc];
        if (((float)(&ITEM_P1)[DAT_008283ec] == f_5) &&
           (DAT_008283e0 <= (float)(&ITEM_P6)[DAT_008283ec])) {
          _DAT_008283d8 = (float)(&ITEM_P2)[DAT_008283ec];
          _DAT_008283d4 = f_0;
          if (f_8 <= (float)(&ITEM_LEN)[DAT_008283ec]) {
            _DAT_008283d4 = *(float *)(&ITEM_P8 + DAT_008283ec * 4);
          }
          DAT_008283d0 = 1;
          if (*(float *)(&ITEM_P7 + DAT_008283ec * 4) < f_0) {
            DAT_008283d0 = -1;
          }
          DAT_008283cc = 0;
          DAT_008283c8 = DAT_008283f0 + 1;
          for (iVar2 = (ITEM_I - DAT_008283c8) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
            DAT_008283c4 = (&ITEM_PTR0)[DAT_008283c8];
            DAT_008283c0 = (int)ROUND((float)(&ITEM_P1)[DAT_008283c4]);
            if (DAT_008283c0 == 1) goto LAB_0047a14d;
            iVar1 = DAT_008283cc;
            if ((DAT_008283c0 == 5) && (_DAT_008283d8 == (float)(&ITEM_P2)[DAT_008283c4])) {
              if (f_0 <= *(float *)(&ITEM_P7 + DAT_008283c4 * 4)) {
                if (DAT_008283d0 < 0) goto LAB_0047a083;
              }
              else if (0 < DAT_008283d0) goto LAB_0047a14d;
              _DAT_008283bc = f_0;
              if (f_8 <= (float)(&ITEM_LEN)[DAT_008283c4]) {
                _DAT_008283bc = *(float *)(&ITEM_P8 + DAT_008283c4 * 4);
              }
              iVar1 = DAT_008283c4;
              if (_DAT_008283d4 == _DAT_008283bc) goto LAB_0047a0ff;
            }
LAB_0047a083:
            DAT_008283cc = iVar1;
            DAT_008283c8 = DAT_008283c8 + 1;
          }
          iVar1 = DAT_008283cc;
          if (DAT_008283cc == 0) {
            (&ITEM_P6)[DAT_008283ec] = DAT_008283e0;
          }
          else {
LAB_0047a0ff:
            DAT_008283c4 = iVar1;
            (&ITEM_P6)[DAT_008283ec] = (&ITEM_P6)[DAT_008283c4];
            (&ITEM_P5)[DAT_008283ec] = (&ITEM_P5)[DAT_008283c4];
            (&ITEM_P1)[DAT_008283c4] = f_13;
          }
        }
LAB_0047a14d:
        DAT_008283dc = DAT_008283dc + 1;
      }
      DAT_008283f4 = 0;
    }
    DAT_008283f0 = DAT_008283f0 + 1;
    iVar4 = iVar4 + -1;
  } while( true );
}


