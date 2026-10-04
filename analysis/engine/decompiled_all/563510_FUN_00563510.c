// FUN_00563510 @ 00563510 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00563510(void)

{
  int iVar1;
  int iVar2;
  int local_bc;
  
  DAT_0078cd30 = DAT_01e99980;
  DAT_01e9ad14 = DAT_01e9ad14 * 7 + 0x31;
  thunk_FUN_0054c419(&DAT_01cadd40,&DAT_00769e80);
  DAT_0078cd3c = 0;
  DAT_0078cd40 = 0;
  DAT_0078cd38 = 1;
  DAT_009a7b08 = f_m999;
  _DAT_01e9dc10 = f_m999;
  DAT_0078cd5c = f_0;
  iVar2 = DAT_0078cd30;
  do {
    if (iVar2 < 1) {
      if (DAT_01e99984 != 0) {
        DAT_009a7ae0 = 0;
        DAT_0078cd50 = 0;
        DAT_0078cd38 = 1;
        _DAT_009a7ae4 = f_m999;
        DAT_009a7ae8 = f_m999;
        for (iVar2 = DAT_0078cd30; 0 < iVar2; iVar2 = iVar2 + -1) {
          DAT_0078cd54 = 1;
          DAT_0078cd44 = (&DAT_01e9a608)[DAT_0078cd38];
          if ((-1 < DAT_0078cd44) && (DAT_0078cd44 < 2)) {
            DAT_0078cd5c = (float)(&DAT_01e9dc94)[DAT_0078cd38];
            if (DAT_0078cd50 != 0) goto LAB_00563c3d;
LAB_00563e0a:
            DAT_0078cd54 = 0;
LAB_005640dc:
            do {
              if (DAT_01e99984 == DAT_0078cd50) {
                DAT_01e9dc18 = DAT_0078cd3c;
                return;
              }
              thunk_FUN_00557ede(&DAT_0078cd50,&DAT_009a7ae8,&DAT_009a7ae4,&DAT_009a7ad8,
                                 &DAT_009a7ad4);
              if (DAT_0078cd54 != 0) break;
LAB_00563c3d:
              if (DAT_0078cd5c < DAT_009a7ae8) break;
              if (_DAT_009a7ae4 < DAT_0078cd5c) {
                if ((DAT_0078cd5c <= DAT_009a7b08) && (DAT_01e9dc18 != 0)) {
                  DAT_009a7ae0 = DAT_009a7ae0 + 1;
                  if (DAT_01e9dc18 == DAT_009a7ae0) {
                    DAT_01e9dc18 = 0;
                  }
                  DAT_0078cd58 = *(int *)(DAT_009a7ae0 * 4 + 0x1e9dc44);
                  DAT_009a7af4 = *(int *)(DAT_009a7ae0 * 4 + 0x1e9dc6c);
                  DAT_009a7adc = (&DAT_01e9dc1c)[DAT_009a7ae0];
                  DAT_0078cd5c = f_m999;
                  DAT_009a7b00 = DAT_0078cd38;
LAB_00563ea3:
                  DAT_0078cd64 = 0;
                  iVar1 = (DAT_0078cd30 - DAT_009a7b00) + 1;
                  DAT_009a7b04 = DAT_009a7b00;
                  do {
                    if (((iVar1 < 1) ||
                        (DAT_0078cd4c = (&DAT_01e9a608)[DAT_009a7b04], DAT_0078cd4c == 2)) ||
                       (DAT_0078cd4c < 0)) goto LAB_005640d1;
                    if (*(int *)(DAT_009a7b04 * 4 + 0x1e99ca8) == 0) {
                      if (DAT_009a7af4 != (&DAT_01e9a2e8)[DAT_009a7b04]) goto LAB_005640d1;
                      DAT_0078cd60 = (float)(&DAT_01e9dc94)[DAT_009a7b04];
                      if (DAT_0078cd64 == 0) {
                        if (DAT_0078cd5c == DAT_0078cd60) goto LAB_00563fbf;
                        DAT_0078cd64 = 1;
                        DAT_0078cd5c = DAT_0078cd60;
                      }
                      else if (DAT_0078cd60 != DAT_0078cd5c) goto LAB_005640d1;
                      if (DAT_0078cd58 == (&DAT_01e99fc8)[DAT_009a7b04]) {
                        if ((_DAT_009a7ad8 <= DAT_0078cd60) && (DAT_0078cd60 <= _DAT_009a7ad4)) {
                          DAT_0078cd64 = (&DAT_01e9a9f0)[DAT_009a7b04];
                          *(undefined4 *)(&DAT_01e9cc64 + DAT_009a7adc * 4) =
                               *(undefined4 *)(&DAT_01e9cc64 + DAT_0078cd64 * 4);
                          (&DAT_01e9ad24)[DAT_0078cd64] = 0;
                          (&DAT_01e9a9f0)[DAT_009a7b04] = DAT_009a7adc;
                          DAT_0078cd54 = (uint)(DAT_009a7b08 != DAT_0078cd60);
                          goto LAB_005640dc;
                        }
                        goto LAB_005640d1;
                      }
                    }
LAB_00563fbf:
                    DAT_009a7b04 = DAT_009a7b04 + 1;
                    iVar1 = iVar1 + -1;
                  } while( true );
                }
                goto LAB_00563e0a;
              }
              if (DAT_0078cd38 < DAT_0078cd30) {
                if (DAT_0078cd30 == DAT_0078cd38) {
                  DAT_01e9dc18 = DAT_0078cd3c;
                  return;
                }
                DAT_0078cd58 = (&DAT_01e99fc8)[DAT_0078cd38];
                DAT_009a7af4 = (&DAT_01e9a2e8)[DAT_0078cd38];
                DAT_009a7adc = (&DAT_01e9a9f0)[DAT_0078cd38];
                _DAT_009a7afc = DAT_0078cd38;
                DAT_009a7b00 = DAT_0078cd38 + 1;
                DAT_009a7b04 = *(int *)(DAT_009a7b00 * 4 + 0x1e99ca8);
                if (((DAT_009a7b04 == 0) || (DAT_0078cd5c == (float)(&DAT_01e9dc94)[DAT_009a7b00]))
                   || ((DAT_0078cd58 == (&DAT_01e99fc8)[DAT_009a7b00] &&
                       (DAT_009a7b04 == *(int *)(DAT_0078cd38 * 4 + 0x1e99ca8)))))
                goto LAB_00563ea3;
              }
              else {
                DAT_0078cd3c = DAT_0078cd3c + 1;
                (&DAT_01e9dc1c)[DAT_0078cd3c] = (&DAT_01e9a9f0)[DAT_0078cd38];
                *(undefined4 *)(DAT_0078cd3c * 4 + 0x1e9dc44) = (&DAT_01e99fc8)[DAT_0078cd38];
                *(undefined4 *)(DAT_0078cd3c * 4 + 0x1e9dc6c) = (&DAT_01e9a2e8)[DAT_0078cd38];
              }
LAB_005640d1:
              DAT_0078cd54 = 1;
            } while( true );
          }
          DAT_0078cd38 = DAT_0078cd38 + 1;
        }
      }
      DAT_01e9dc18 = DAT_0078cd3c;
      return;
    }
    DAT_0078cd44 = (&ITEM_PTR0)[(&DAT_01e99988)[DAT_0078cd38]];
    DAT_0078cd48 = (int)ROUND((float)(&ITEM_LEN)[DAT_0078cd44]);
    DAT_0078cd4c = (&DAT_01e9a2e8)[DAT_0078cd38];
    DAT_009a7b04 = (&DAT_01e9a608)[DAT_0078cd38];
    if (DAT_009a7b04 == 2) {
      DAT_0078cd40 = *(int *)(DAT_0078cd38 * 4 + 0x1e99ca8);
      iVar1 = DAT_0078cd40;
      if (DAT_0078cd40 < 0) {
        iVar1 = -DAT_0078cd40;
      }
      if (99 < iVar1) {
        DAT_0078cd40 = 0;
      }
      if (DAT_0078cd40 == 0) {
LAB_005636f2:
        if (DAT_0078cd40 == 0) {
          thunk_FUN_0054c419(&DAT_01cadd40,&DAT_00769e80);
          if (DAT_009a7b04 != 2) goto LAB_00563824;
          goto LAB_00563b4c;
        }
      }
      else {
        DAT_0078cd40 = DAT_0078cd40 * 7 + 0x32;
      }
      DAT_0078cd54 = DAT_0078cd40 + 6;
      DAT_0078cd58 = 2;
      local_bc = 0x1c;
      DAT_009a7b00 = 1;
      do {
        DAT_0078cd50 = DAT_0078cd40;
        for (iVar1 = (DAT_0078cd54 - DAT_0078cd40) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
          DAT_0078cd58 = DAT_0078cd58 + 1;
          *(undefined4 *)(&DAT_01cadd3c + DAT_0078cd58 * 4) = (&DAT_0078da7c)[DAT_0078cd50];
          DAT_0078cd50 = DAT_0078cd50 + 1;
        }
        DAT_009a7b00 = DAT_009a7b00 + 7;
        local_bc = local_bc + -1;
      } while (0 < local_bc);
      if (DAT_009a7b04 == 2) {
        DAT_009a7b04 = 2;
      }
      else {
LAB_00563824:
        if (DAT_009a7b08 < f_0) {
          DAT_009a7b08 = DAT_0078cd5c;
        }
        DAT_0078cd60 = *(float *)(&ITEM_P7 + DAT_0078cd44 * 4);
        if (f_64 <= DAT_0078cd60) {
          DAT_01e9dc0c = DAT_01e9dc0c - f_0_05;
          if (DAT_01e9dc14 == 0) {
            for (DAT_01e9dc14 = DAT_01e9ad24;
                (1 < DAT_01e9dc14 &&
                (*(float *)(&DAT_01e9cc64 + DAT_01e9dc14 * 4) ==
                 *(float *)(&DAT_01e9cc60 + DAT_01e9dc14 * 4))); DAT_01e9dc14 = DAT_01e9dc14 + -1) {
            }
            *(float *)(&DAT_01e9cc64 + DAT_01e9dc14 * 4) = DAT_01e9dc0c;
          }
          DAT_0078cd60 = f_0_05;
        }
        DAT_01e9dc14 = 0;
        DAT_0078cd58 = *(int *)(&DAT_0079f610 + DAT_0078cd4c * 4) + (&DAT_01e99fc8)[DAT_0078cd38];
        DAT_009a7af8 = *(int *)(DAT_0078cd38 * 4 + 0x1e99ca8);
        iVar1 = (DAT_0078cd58 + 6) % 7;
        DAT_009a7af4 = iVar1 + 1;
        if (DAT_009a7af4 < 1) {
          DAT_009a7af4 = iVar1 + 8;
        }
        DAT_009a7b04 = DAT_0078cd58 + 100;
        DAT_0078cd64 = DAT_009a7af8;
        if (DAT_009a7af8 == 3) {
          DAT_0078cd64 = 0;
        }
        if (DAT_009a7af8 != 0) {
          *(int *)(&DAT_01cadd3c + DAT_009a7b04 * 4) = DAT_0078cd64;
        }
        _DAT_009a7afc =
             ((DAT_0078cd58 + 0x22) / 7) * 0xc + *(int *)(&DAT_0079f5f0 + DAT_009a7af4 * 4);
        DAT_01e9ad24 = DAT_01e9ad24 + 1;
        (&DAT_01e9ad24)[DAT_01e9ad24] = *(int *)(&DAT_01cadd3c + DAT_009a7b04 * 4) + _DAT_009a7afc;
        *(float *)(&DAT_01e9dfb4 + DAT_01e9ad24 * 4) = DAT_0078cd5c;
        if (_DAT_01e9dc10 == DAT_0078cd5c) {
          DAT_01e9dc0c = DAT_01e9dc08;
        }
        DAT_01e9dc08 = DAT_01e9dc0c;
        *(float *)(&DAT_01e9bcc4 + DAT_01e9ad24 * 4) = DAT_01e9dc0c;
        DAT_009a7af0 = DAT_0078cd60;
        if (DAT_0078cd60 == f_0) {
          DAT_009a7af0 = DAT_009a7aec;
        }
        DAT_009a7aec = DAT_009a7af0;
        DAT_01e9dc0c = DAT_009a7af0 + DAT_01e9dc0c;
        *(float *)(&DAT_01e9cc64 + DAT_01e9ad24 * 4) = DAT_01e9dc0c;
        (&DAT_01e9a9f0)[DAT_0078cd38] = DAT_01e9ad24;
        _DAT_01e9dc10 = DAT_0078cd5c;
      }
    }
    else {
      if (-1 < DAT_009a7b04) {
        DAT_0078cd5c = (float)(&DAT_01e9dc94)[DAT_0078cd38];
        if ((DAT_009a7b04 != 0) && (_DAT_01e9dc10 != DAT_0078cd5c)) goto LAB_005636f2;
        goto LAB_00563824;
      }
      DAT_01e9dc0c = DAT_01e9dc0c + *(float *)(&ITEM_P7 + DAT_0078cd44 * 4);
      DAT_01e9dc14 = 1;
      _DAT_01e9dc10 = f_0;
    }
LAB_00563b4c:
    DAT_0078cd38 = DAT_0078cd38 + 1;
    iVar2 = iVar2 + -1;
  } while( true );
}


