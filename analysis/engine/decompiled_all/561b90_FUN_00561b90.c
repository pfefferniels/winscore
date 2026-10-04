// FUN_00561b90 @ 00561b90 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00561b90(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  unkbyte10 in_ST0;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  unkbyte10 Var6;
  unkbyte10 extraout_ST0_04;
  unkbyte10 extraout_ST0_05;
  float10 extraout_ST1;
  int local_e4;
  
  DAT_0078cd30 = DAT_01e99980;
  DAT_0078cd34 = DAT_01e9ad20 + 6;
  _DAT_009a7ab8 = DAT_01e9ad14 * 7 + 0x31;
  ffree(in_ST0);
  fVar5 = (float10)thunk_FUN_0054c419(&DAT_01cadd40,&DAT_00769e64);
  DAT_0078cd3c = 0;
  DAT_009a7ab0 = 0x31;
  DAT_0078cd38 = 1;
  DAT_009a7ab4 = f_m999;
  _DAT_01e9dc10 = f_m999;
  DAT_0078cd5c = f_0;
  for (iVar3 = DAT_0078cd30; 0 < iVar3; iVar3 = iVar3 + -1) {
    DAT_0078cd44 = (&ITEM_PTR0)[(&DAT_01e99988)[DAT_0078cd38]];
    fVar5 = (float10)(float)(&ITEM_P4)[DAT_0078cd44];
    if (((ABS(fVar5) < (float10)f_100) || (*param_1 != 0)) ||
       (*(float *)(&ITEM_P7 + DAT_0078cd44 * 4) == f_65)) {
      DAT_0078cd48 = (int)ROUND((float)(&ITEM_LEN)[DAT_0078cd44]);
      DAT_0078cd4c = (&DAT_01e9a2e8)[DAT_0078cd38];
      DAT_009a7aac = (&DAT_01e9a608)[DAT_0078cd38];
      if (DAT_009a7aac == 2) {
        DAT_009a7ab0 = *(int *)(DAT_0078cd38 * 4 + 0x1e99ca8);
        iVar4 = DAT_009a7ab0;
        if (DAT_009a7ab0 < 0) {
          iVar4 = -DAT_009a7ab0;
        }
        if (99 < iVar4) {
          DAT_009a7ab0 = 0;
        }
        if (DAT_0078b4e0 == 0x45) {
          if (DAT_009a7ab0 != 0) {
            iVar4 = DAT_009a7ab0 * 7;
            DAT_009a7ab0 = iVar4 + 0x32;
            DAT_0078cd54 = iVar4 + 0x38;
            DAT_0078cd58 = 2;
            local_e4 = 0x1c;
            DAT_009a7aa8 = 1;
            DAT_009a7aac = 2;
            do {
              DAT_0078cd50 = DAT_009a7ab0;
              for (iVar4 = (DAT_0078cd54 - DAT_009a7ab0) + 1; 0 < iVar4; iVar4 = iVar4 + -1) {
                DAT_0078cd58 = DAT_0078cd58 + 1;
                *(undefined4 *)(&DAT_01cadd3c + DAT_0078cd58 * 4) = (&DAT_0078da7c)[DAT_0078cd50];
                DAT_0078cd50 = DAT_0078cd50 + 1;
              }
              DAT_009a7aa8 = DAT_009a7aa8 + 7;
              local_e4 = local_e4 + -1;
            } while (0 < local_e4);
            if (DAT_009a7aac != 2) goto LAB_0056212f;
            DAT_009a7aac = 2;
            goto LAB_0056257c;
          }
        }
        else {
          ffree(fVar5);
          Var6 = FUN_00562cc6(&DAT_009a7ab0,&DAT_01e9ad1c,&DAT_0078cd50,&DAT_01e9ad20);
          DAT_009a7ab0 = DAT_009a7ab0 * 7 + 0x31;
          DAT_0078cd34 = DAT_01e9ad20 + 6;
          DAT_009a7aa8 = DAT_0078cd50;
          if (DAT_0078cd50 == 0) {
            if ((DAT_0078cd38 != 1) && (DAT_01e9ad18 != 0)) {
              DAT_0078cd50 = 100;
              if (DAT_01e9ad18 < 0) {
                DAT_0078cd50 = -100;
              }
              DAT_0078cd50 = DAT_01e9ad18 + DAT_0078cd50;
              goto LAB_00561f4d;
            }
            ffree(Var6);
            iVar4 = FUN_00562fbd(&ITEM_P3 + DAT_0078cd44);
            fVar5 = extraout_ST0_01;
            if (iVar4 == 0) {
              (&ITEM_P1)[DAT_0078cd44] = f_13;
            }
          }
          else {
LAB_00561f4d:
            bVar1 = 4 < DAT_0078cd48;
            ffree(Var6);
            iVar4 = FUN_00562fbd(&ITEM_P3 + DAT_0078cd44);
            if (bVar1 && iVar4 == 0) {
              (&ITEM_P5)[DAT_0078cd44] = (float)DAT_0078cd50;
            }
            fVar5 = extraout_ST0;
            if (DAT_0078cd48 < 6) {
              if (DAT_0078cd4c == 0) goto LAB_00562072;
              ffree(extraout_ST0);
              fVar5 = (float10)thunk_FUN_005239c9(&DAT_01e99988 + DAT_0078cd38,&DAT_00769e50);
            }
            ffree(fVar5);
            iVar4 = FUN_00562fbd(&ITEM_P3 + DAT_0078cd44);
            fVar5 = extraout_ST0_00;
            if (iVar4 == 0) {
              (&ITEM_P6)[DAT_0078cd44] = (float)DAT_0078cd4c;
            }
          }
LAB_00562072:
          DAT_01e9ad18 = DAT_009a7aa8;
          _DAT_009a7ab8 = DAT_009a7aa8 * 7 + 0x31;
        }
LAB_005620f8:
        ffree(fVar5);
        fVar5 = (float10)thunk_FUN_0054c419(&DAT_01cadd40,&DAT_00769e64);
        if (DAT_009a7aac == 2) goto LAB_0056257c;
      }
      else {
        if (DAT_009a7aac < 0) goto LAB_0056257c;
        DAT_0078cd5c = (float)(&DAT_01e9dc94)[DAT_0078cd38];
        if ((DAT_009a7aac != 0) && (_DAT_01e9dc10 != DAT_0078cd5c)) goto LAB_005620f8;
      }
LAB_0056212f:
      if (DAT_009a7ab4 < f_0) {
        DAT_009a7ab4 = DAT_0078cd5c;
      }
      DAT_009a7aa4 = (&DAT_01e99fc8)[DAT_0078cd38];
      if (DAT_0078b4e0 == 0x45) {
        DAT_009a7aa4 = DAT_01e99988 + DAT_009a7aa4;
      }
      DAT_0078cd58 = *(int *)(&DAT_0079f5c8 + DAT_0078cd4c * 4) + DAT_009a7aa4;
      _DAT_009a7a98 = *(int *)(DAT_0078cd38 * 4 + 0x1e99ca8);
      iVar4 = (DAT_0078cd58 + 6) % 7;
      DAT_0078cd40 = iVar4 + 1;
      if (DAT_0078cd40 < 1) {
        DAT_0078cd40 = iVar4 + 8;
      }
      DAT_009a7aac = DAT_0078cd58 + 100;
      iVar4 = (DAT_0078cd34 + DAT_0078cd40) % 7;
      DAT_009a7a9c = iVar4 + 1;
      if (DAT_009a7a9c < 1) {
        DAT_009a7a9c = iVar4 + 8;
      }
      DAT_0078cd54 = (&DAT_0078da7c)[DAT_009a7a9c + _DAT_009a7ab8];
      if (DAT_0078b4e0 == 0x45) {
        DAT_0078cd54 = DAT_0078cd54 - DAT_01e99988;
      }
      DAT_009a7aa0 = _DAT_009a7a98;
      if (_DAT_009a7a98 == 0) {
        if (DAT_01e9ad18 == 0) goto LAB_005623ae;
      }
      else {
        *(undefined4 *)(&DAT_01cadd3c + DAT_009a7aac * 4) = 1;
        if (DAT_009a7aa0 == 3) {
          DAT_009a7aa0 = 0;
        }
        DAT_009a7aa8 = 0x30;
        iVar4 = DAT_01e9ad20;
        if (DAT_01e9ad20 < 0) {
          iVar4 = -DAT_01e9ad20;
        }
        if (iVar4 == 7) {
          DAT_009a7aa8 = DAT_009a7ab0;
        }
        DAT_0078cd64 = (&DAT_0078da7c)[DAT_0078cd40 + DAT_009a7ab0];
        DAT_0078cd54 = (DAT_009a7aa0 - DAT_0078cd64) + DAT_0078cd54;
        if (DAT_0078cd54 == 0) {
          DAT_0078cd54 = 3;
        }
        else {
          if (DAT_0078cd54 < -2) {
            DAT_009a7aa4 = DAT_009a7aa4 + 1;
            DAT_0078cd54 = -2;
          }
          if (2 < DAT_0078cd54) {
            DAT_009a7aa4 = DAT_009a7aa4 + -1;
            DAT_0078cd54 = 2;
          }
LAB_005623ae:
          DAT_0078cd54 = *(int *)(&DAT_0079f5b8 + DAT_0078cd54 * 4);
          if ((DAT_0078b4e0 == 0x45) && (DAT_0078cd54 == 0)) {
            DAT_0078cd54 = 3;
          }
        }
        ffree(fVar5);
        iVar4 = FUN_00562fbd(&ITEM_P3 + DAT_0078cd44);
        fVar5 = extraout_ST0_02;
        if (iVar4 != 0) goto LAB_0056257c;
        DAT_0078cd50 = (int)ROUND((float)(&ITEM_P5)[DAT_0078cd44]);
        ffree(extraout_ST0_02);
        fVar5 = (float10)amod(&ITEM_P5 + DAT_0078cd44,&DAT_00769e48);
        _DAT_009a7a94 = (float)fVar5;
        DAT_0078cd50 = (DAT_0078cd50 / 10) * 10 + DAT_0078cd54;
        (&ITEM_P5)[DAT_0078cd44] = (float)DAT_0078cd50 + _DAT_009a7a94;
        fVar5 = extraout_ST1;
      }
      ffree(fVar5);
      iVar4 = FUN_00562fbd(&ITEM_P3 + DAT_0078cd44);
      fVar5 = extraout_ST0_03;
      if (iVar4 == 0) {
        DAT_009a7abc = DAT_01e9ad20 + DAT_009a7aa4;
        fVar5 = (float10)(float)(&ITEM_P4)[DAT_0078cd44];
        if ((float10)f_100 <= ABS(fVar5)) {
          DAT_0078cd50 = 100;
          if (DAT_009a7abc < 0) {
            DAT_0078cd50 = -100;
          }
          DAT_009a7abc = DAT_0078cd50 + DAT_009a7abc;
        }
        (&ITEM_P4)[DAT_0078cd44] = (float)DAT_009a7abc;
      }
    }
LAB_0056257c:
    DAT_0078cd38 = DAT_0078cd38 + 1;
  }
  ffree(fVar5);
  Var6 = thunk_FUN_0054c419(&DAT_01e9ad28,&DAT_0078cd30);
  DAT_0078cd3c = 0;
  ffree(Var6);
  Var6 = thunk_FUN_00557ede(&DAT_0078cd3c,&DAT_009a7a90,&DAT_009a7a8c,&DAT_009a7a88,&DAT_009a7a84);
  DAT_0078cd38 = 1;
  iVar3 = DAT_0078cd30;
joined_r0x00562618:
  if (iVar3 < 1) {
    DAT_01e9dc18 = DAT_0078cd3c;
    ffree(Var6);
    return;
  }
  DAT_009a7aac = (&DAT_01e9a608)[DAT_0078cd38];
  if (((-1 < DAT_009a7aac) && (DAT_009a7aac < 2)) &&
     ((DAT_009a7aac < 1 || (-1 < (int)(&DAT_01e9ad24)[DAT_009a7aac])))) {
    DAT_0078cd4c = (&DAT_01e9a2e8)[DAT_0078cd38];
    DAT_0078cd58 = (&DAT_01e99fc8)[DAT_0078cd38];
    DAT_0078cd5c = (float)(&DAT_01e9dc94)[DAT_0078cd38];
    if ((DAT_01e99984 != 0) && (*(int *)(DAT_0078cd38 * 4 + 0x1e99ca8) == 0)) {
      if (DAT_0078cd5c <= DAT_009a7ab4) {
        do {
          if ((DAT_0078cd5c < _DAT_009a7a90) || (DAT_0078cd5c <= _DAT_009a7a8c)) break;
          if (_DAT_009a7a88 <= DAT_0078cd5c) goto LAB_00562996;
          ffree(Var6);
          Var6 = thunk_FUN_00557ede(&DAT_0078cd3c,&DAT_009a7a90,&DAT_009a7a8c,&DAT_009a7a88,
                                    &DAT_009a7a84);
        } while (DAT_01e99984 != 0);
      }
      else if (DAT_009a7aac == 1) {
        do {
          if (DAT_0078cd5c <= _DAT_009a7a8c) break;
          if ((_DAT_009a7a88 <= DAT_0078cd5c) && (DAT_0078cd5c <= _DAT_009a7a84)) {
            DAT_0078cd50 = DAT_0078cd38;
            do {
              DAT_0078cd50 = DAT_0078cd50 + -1;
              if ((((DAT_0078cd50 == 0) ||
                   (DAT_009a7aac = (&DAT_01e9a608)[DAT_0078cd50], DAT_009a7aac < 0)) ||
                  (1 < DAT_009a7aac)) || (DAT_0078cd4c != (&DAT_01e9a2e8)[DAT_0078cd50]))
              goto LAB_0056288c;
              DAT_0078cd60 = (float)(&DAT_01e9dc94)[DAT_0078cd50];
            } while (DAT_0078cd60 == DAT_0078cd5c);
            do {
              if (DAT_0078cd58 == (&DAT_01e99fc8)[DAT_0078cd50]) goto LAB_00562996;
              DAT_0078cd50 = DAT_0078cd50 + -1;
            } while ((DAT_0078cd50 != 0) && (DAT_0078cd60 == (float)(&DAT_01e9dc94)[DAT_0078cd50]));
          }
LAB_0056288c:
          ffree(Var6);
          Var6 = thunk_FUN_00557ede(&DAT_0078cd3c,&DAT_009a7a90,&DAT_009a7a8c,&DAT_009a7a88,
                                    &DAT_009a7a84);
        } while (DAT_01e99984 != 0);
      }
    }
    DAT_009a7aa8 = DAT_0078cd38 + 1;
    iVar4 = (DAT_0078cd30 - DAT_009a7aa8) + 1;
    do {
      if ((iVar4 < 1) || (DAT_0078cd4c != (&DAT_01e9a2e8)[DAT_009a7aa8])) break;
      DAT_009a7aac = (&DAT_01e9a608)[DAT_009a7aa8];
      if (-1 < DAT_009a7aac) {
        if ((DAT_009a7aac == 1) && (DAT_0078cd5c != (float)(&DAT_01e9dc94)[DAT_009a7aa8])) break;
        if (DAT_0078cd58 == (&DAT_01e99fc8)[DAT_009a7aa8]) {
          if (*(int *)(DAT_009a7aa8 * 4 + 0x1e99ca8) != 0) break;
          DAT_0078cd44 = (&ITEM_PTR0)[(&DAT_01e99988)[DAT_009a7aa8]] + 5;
          ffree(Var6);
          iVar2 = FUN_00562fbd(&DAT_02053434 + DAT_0078cd44 * 4);
          if (iVar2 == 0) {
            DAT_0078cd64 = (int)ROUND((float)(&ITEM_LEN)[DAT_0078cd44]);
            (&ITEM_LEN)[DAT_0078cd44] = (float)((DAT_0078cd64 / 10) * 10);
          }
          (&DAT_01e9ad24)[DAT_009a7aa8] = 0xffffffff;
          Var6 = extraout_ST0_05;
        }
      }
      DAT_009a7aa8 = DAT_009a7aa8 + 1;
      iVar4 = iVar4 + -1;
    } while( true );
  }
  goto LAB_00562c7d;
LAB_00562996:
  DAT_0078cd44 = (&ITEM_PTR0)[(&DAT_01e99988)[DAT_0078cd38]] + 5;
  ffree(Var6);
  iVar4 = FUN_00562fbd(&DAT_02053434 + DAT_0078cd44 * 4);
  if (iVar4 == 0) {
    DAT_0078cd64 = (int)ROUND((float)(&ITEM_LEN)[DAT_0078cd44]);
    (&ITEM_LEN)[DAT_0078cd44] = (float)((DAT_0078cd64 / 10) * 10);
  }
  ffree(extraout_ST0_04);
  Var6 = thunk_FUN_00557ede(&DAT_0078cd3c,&DAT_009a7a90,&DAT_009a7a8c,&DAT_009a7a88,&DAT_009a7a84);
LAB_00562c7d:
  DAT_0078cd38 = DAT_0078cd38 + 1;
  iVar3 = iVar3 + -1;
  goto joined_r0x00562618;
}


