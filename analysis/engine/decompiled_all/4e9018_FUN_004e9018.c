// FUN_004e9018 @ 004e9018 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004ea230) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e9018(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  unkbyte10 in_ST0;
  unkbyte10 Var5;
  unkbyte10 extraout_ST0;
  float10 fVar6;
  
  ffree(in_ST0);
  Var5 = thunk_FUN_005725fa();
  DAT_008d13a0 = 1;
  DAT_020527a0 = ITEM_WORDS;
  for (iVar1 = ITEM_I; ITEM_WORDS = DAT_020527a0, 0 < iVar1; iVar1 = iVar1 + -1) {
    _DAT_008d139c = (float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_008d13a0]];
    if (_DAT_008d1398 <= _DAT_008d139c) {
      (&ITEM_P2)[(&ITEM_PTR0)[DAT_008d13a0]] = _DAT_008d139c - _DAT_008d1398;
    }
    else {
      (&ITEM_P2)[(&ITEM_PTR0)[DAT_008d13a0]] = _DAT_008d1398 + _DAT_008d139c;
    }
    DAT_008d13a0 = DAT_008d13a0 + 1;
    DAT_020527a0 = ITEM_WORDS;
  }
  if (DAT_02052740 == 0) {
    DAT_00794c24 = DAT_00794c28 + 1;
    for (iVar1 = 1; iVar1 < 0x21; iVar1 = iVar1 + 1) {
      (&DAT_008d13a4)[iVar1] = 0;
    }
    _DAT_008d1394 = f_m999;
    DAT_008d13a8 = DAT_00794c24;
    DAT_008d13ac = DAT_00794c1c;
    if (DAT_00794c20 == 1) {
      DAT_008d13b0 = 1;
    }
    if (DAT_00794c20 == 4) {
      DAT_008d13b4 = 1;
    }
    if (DAT_00794c20 == 5) {
      DAT_008d13b8 = 1;
    }
    if (DAT_00794c20 == 10) {
      DAT_008d13bc = 1;
    }
    DAT_008d13c0 = DAT_00794c10;
    if (DAT_00794c14 != 0) {
      DAT_00794c04 = 1;
    }
    DAT_008d13c4 = DAT_00794c04;
    DAT_008d13c8 = DAT_00794c08;
    DAT_008d13cc = DAT_00794c18;
    DAT_008d13d0 = DAT_00794c14;
    ffree(Var5);
    DAT_008d1390 = thunk_FUN_0059a200(&DAT_008d13a8);
    Var5 = extraout_ST0;
    if (DAT_008d1390 == 2) goto LAB_004ea5c6;
    DAT_00794c24 = DAT_008d13a8 + -1;
    DAT_00794c1c = DAT_008d13ac;
    DAT_00794c20 = DAT_008d13b0;
    if (DAT_008d13b4 == 1) {
      DAT_00794c20 = 4;
    }
    if (DAT_008d13b8 == 1) {
      DAT_00794c20 = 5;
    }
    if (DAT_008d13bc == 1) {
      DAT_00794c20 = 10;
    }
    DAT_00794c10 = DAT_008d13c0;
    DAT_00794c04 = DAT_008d13c4;
    DAT_008d138c = DAT_008d13c0 + DAT_008d13c4;
    DAT_00794c08 = DAT_008d13c8;
    DAT_00794c18 = DAT_008d13cc;
    if (1 < DAT_00794c20) {
      DAT_00794c18 = 1;
    }
    if (DAT_008d13c0 != 0) {
      DAT_00794c18 = 1;
    }
    DAT_00794c14 = DAT_008d13d0;
  }
  else {
    DAT_00794c20 = (int)ROUND(P3);
    DAT_00794c10 = (int)ROUND(P4);
    DAT_008d138c = (int)ROUND(P5 + P4);
    DAT_00794c08 = (int)ROUND(P6);
    DAT_00794c24 = (int)ROUND(P2 - f_1);
    if (DAT_00794c14 != 0) {
      DAT_00794c24 = DAT_00794c28;
    }
    DAT_00794c18 = (int)ROUND(P7);
    DAT_00794c14 = (int)ROUND(P8);
    DAT_00794c04 = 1;
    DAT_008d13ac = 0;
    DAT_00794c1c = (uint)(DAT_00794c20 == 0);
    if (P2 == f_0) {
      DAT_00794c24 = 0;
      DAT_00794c20 = 1;
      DAT_00794c10 = 0;
      DAT_008d138c = 1;
      DAT_00794c08 = 1;
      DAT_00794c18 = 0;
      DAT_00794c04 = 1;
      DAT_00794c14 = 0;
      DAT_00794c1c = 0;
    }
  }
  if (DAT_00794c14 == 0) {
    DAT_00794c28 = 0;
  }
  DAT_008d1388 = 0;
  DAT_0078b4e0 = 1;
  DAT_0078b4e4 = 0x58;
  ffree(Var5);
  fVar6 = (float10)thunk_FUN_004f7808();
  LOAD_I = 1;
  _DAT_008d1384 = f_m999;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    ffree(fVar6);
    fVar6 = (float10)load_item_header();
    if (((LOAD_CODE == 0xe) &&
        (((LOAD_LEN < 5 || ((float)(&ITEM_P5)[LOAD_W] <= f_6)) && (_DAT_008d1384 != f_m999)))) &&
       (_DAT_008d1384 < LOAD_P3)) {
      DAT_008d1380 = LOAD_I + -1;
      iVar3 = -DAT_008d1380 / -1;
      while ((0 < iVar3 &&
             (DAT_008d137c = (int)ROUND((float)(&ITEM_P1)[(&ITEM_PTR0)[DAT_008d1380]]),
             DAT_008d137c != 0xe))) {
        if (DAT_008d137c < 3) goto LAB_004e9792;
        DAT_008d1380 = DAT_008d1380 + -1;
        iVar3 = iVar3 + -1;
      }
      (&ITEM_P1)[LOAD_W] = f_99;
    }
LAB_004e9792:
    LOAD_I = LOAD_I + 1;
    _DAT_008d1384 = LOAD_P3;
  }
  DAT_008d1378 = 0;
  DAT_008d137c = 1;
  DAT_008d1374 = 1;
LAB_004e97e9:
  do {
    LOAD_I = DAT_008d137c;
    for (iVar1 = (ITEM_I - DAT_008d137c) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      ffree(fVar6);
      fVar6 = (float10)load_item_header();
      if (DAT_008d1374 == LOAD_STAFF) {
        if (LOAD_CODE == 3) {
          DAT_008d1378 = DAT_008d1378 + 1;
          *(undefined4 *)(DAT_008d1378 * 4 + 0x1e9a14c) = 1;
          (&DAT_01e9a91c)[DAT_008d1378] = LOAD_STAFF;
          (&DAT_01e9b0ec)[DAT_008d1378] = LOAD_STAFF;
          (&DAT_01e9b8bc)[DAT_008d1378] = LOAD_I;
        }
        else {
          if ((LOAD_CODE != 0xe) ||
             ((f_4 < (float)(&ITEM_LEN)[LOAD_W] && (f_6 < (float)(&ITEM_P5)[LOAD_W]))))
          goto LAB_004e989e;
          DAT_008d1378 = DAT_008d1378 + 1;
          (&DAT_01e9a91c)[DAT_008d1378] = (int)ROUND((float)(&ITEM_P2)[LOAD_W]);
          DAT_008d1370 = 1;
          if ((f_3 < (float)(&ITEM_LEN)[LOAD_W]) && ((float)(&ITEM_P4)[LOAD_W] != f_0)) {
            DAT_008d1370 = (int)ROUND((float)(&ITEM_P4)[LOAD_W]);
          }
          *(int *)(DAT_008d1378 * 4 + 0x1e9a14c) = DAT_008d1370;
          (&DAT_01e9b0ec)[DAT_008d1378] = (&DAT_01e9a91c)[DAT_008d1378] + DAT_008d1370 + -1;
          (&DAT_01e9b8bc)[DAT_008d1378] = LOAD_I;
        }
        DAT_008d13a4 = LOAD_I + 1;
        iVar1 = (ITEM_I - DAT_008d13a4) + 1;
        goto joined_r0x004e9a9b;
      }
LAB_004e989e:
      LOAD_I = LOAD_I + 1;
    }
    DAT_008d1374 = DAT_008d1374 + 1;
  } while (DAT_008d1374 < 0x100);
LAB_004e9bf1:
  DAT_008d13a0 = DAT_008d1378;
  for (iVar1 = -DAT_008d1378 / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_008d1390 = (&DAT_01e9b0ec)[DAT_008d13a0];
    if (_DAT_008d1398 < (float)DAT_008d1390) {
      DAT_008d1390 = (int)ROUND((float)DAT_008d1390 - _DAT_008d1398);
    }
    _DAT_008d1368 = (float)(&STAFF_STEP0)[DAT_008d1390] / f_25;
    DAT_008d1364 = _DAT_008d1368 * f_1_15;
    DAT_008d1360 = _DAT_008d1368 * f_2_4;
    DAT_008d135c = _DAT_008d1368 * f_3_7;
    DAT_008d1388 = 0;
    DAT_008d1390 = (&DAT_01e9b8bc)[DAT_008d13a0];
    _DAT_008d1358 = f_0;
    for (iVar3 = ((&DAT_01e9997c)[DAT_008d13a0] - DAT_008d1390) + 1; 0 < iVar3; iVar3 = iVar3 + -1)
    {
      ffree(fVar6);
      LOAD_I = DAT_008d1390;
      fVar6 = (float10)load_item_header();
      iVar4 = DAT_00794c24;
      if (LOAD_STAFF == (&DAT_01e9a91c)[DAT_008d13a0]) {
        DAT_008d1354 = LOAD_P3;
        if (LOAD_CODE == 3) {
          if (DAT_008d1388 == 0) {
LAB_004ea14a:
            DAT_008d136c = DAT_008d136c + 1;
            if (DAT_008d138c <= DAT_008d136c) {
              DAT_00794c24 = DAT_00794c24 + 1;
              if ((DAT_00794c24 == 0) || (_DAT_008d1358 != f_0)) goto LAB_004ea388;
              _DAT_008d1358 = (float)(int)DAT_00794c1c;
              if (((DAT_00794c24 != 1) || ((DAT_00794c04 != 1 || (DAT_00794c18 != 0)))) &&
                 ((DAT_00794c20 < 2 || (DAT_00794c24 % DAT_00794c20 == 0)))) {
                iVar4 = ITEM_WORDS;
                for (iVar2 = 1; iVar2 < 0x12; iVar2 = iVar2 + 1) {
                  (&ITEM_LEN)[iVar4] = f_0;
                  iVar4 = iVar4 + 1;
                }
                (&ITEM_LEN)[ITEM_WORDS] = f_15;
                (&ITEM_P1)[ITEM_WORDS] = f_10;
                (&ITEM_P2)[ITEM_WORDS] = (float)(int)(&DAT_01e9b0ec)[DAT_008d13a0];
                _DAT_008d1340 = DAT_008d1364;
                if (9 < DAT_00794c24) {
                  _DAT_008d1340 = DAT_008d1360;
                }
                if (99 < DAT_00794c24) {
                  _DAT_008d1340 = DAT_008d135c;
                }
                fVar6 = (float10)_DAT_008d1340;
                *(float *)(&ITEM_P15 + ITEM_WORDS * 4) = (float)-fVar6;
                (&ITEM_P6)[ITEM_WORDS] = f_1;
                (&ITEM_P3)[ITEM_WORDS] = DAT_008d1354;
                (&ITEM_P4)[ITEM_WORDS] = f_13;
                (&ITEM_P5)[ITEM_WORDS] = (float)DAT_00794c24;
                ITEM_WORDS = ITEM_WORDS + 0x10;
                _DAT_008d1394 = DAT_008d1354;
                ITEM_I = ITEM_I + 1;
                (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
              }
            }
            DAT_008d1388 = 1;
          }
        }
        else if (((LOAD_CODE != 2) || (LOAD_LEN < 5)) || (f_m1 <= (float)(&ITEM_P5)[LOAD_W])) {
          if (((LOAD_CODE == 0xe) && ((float)(&ITEM_P5)[LOAD_W] <= f_6 || LOAD_LEN < 5)) &&
             (_DAT_008d1394 != LOAD_P3)) {
            if (((DAT_00794c08 != 0) && (4 < LOAD_LEN)) && ((float)(&ITEM_P5)[LOAD_W] == f_3)) {
              DAT_008d134c = 0;
              DAT_008d1348 = (&DAT_01e9b8bc)[DAT_008d13a0];
              for (iVar4 = ((&DAT_01e9997c)[DAT_008d13a0] - DAT_008d1348) + 1; 0 < iVar4;
                  iVar4 = iVar4 + -1) {
                ffree(fVar6);
                LOAD_I = DAT_008d1348;
                fVar6 = (float10)load_item_header();
                if (((LOAD_CODE == 5) && (7 < LOAD_LEN)) &&
                   (*(float *)(&ITEM_P8 + LOAD_W * 4) == f_1)) {
                  _DAT_008d1344 = LOAD_P3 - f_2;
                  if (_DAT_008d1344 < f_20) {
                    _DAT_008d1344 = f_m1;
                  }
                  LOAD_I = (&DAT_01e9b8bc)[DAT_008d13a0];
                  for (iVar2 = ((&DAT_01e9997c)[DAT_008d13a0] - LOAD_I) + 1; 0 < iVar2;
                      iVar2 = iVar2 + -1) {
                    ffree(fVar6);
                    fVar6 = (float10)load_item_header();
                    if (DAT_008d1354 <= LOAD_P3) break;
                    if (((LOAD_CODE == 0xe) && (LOAD_LEN < 5 || (float)(&ITEM_P5)[LOAD_W] <= f_2))
                       && (_DAT_008d1344 <= LOAD_P3)) {
                      DAT_008d134c = DAT_008d134c + 1;
                    }
                    LOAD_I = LOAD_I + 1;
                  }
                }
                DAT_008d1348 = DAT_008d1348 + 1;
              }
              DAT_00794c24 = DAT_00794c24 - DAT_008d134c;
            }
            goto LAB_004ea14a;
          }
        }
        else {
          DAT_008d1350 = (int)ROUND((float)(&ITEM_P5)[LOAD_W]);
          if ((DAT_008d1350 < -10) && (-0x14 < DAT_008d1350)) {
            DAT_00794c24 = (DAT_00794c24 - DAT_008d1350) + -0xb;
          }
          if ((7 < LOAD_LEN) && (f_0 < *(float *)(&ITEM_P8 + LOAD_W * 4))) {
            DAT_00794c24 = (int)ROUND(((float)iVar4 + *(float *)(&ITEM_P8 + LOAD_W * 4)) - f_1);
          }
        }
      }
LAB_004ea388:
      DAT_008d1390 = DAT_008d1390 + 1;
    }
    if (DAT_008d138c <= DAT_008d136c) {
      DAT_00794c24 = DAT_00794c24 + -1;
    }
    if ((((DAT_00794c20 == 0) || ((DAT_00794c24 + 1) % DAT_00794c20 == 0)) && (_DAT_008d1358 == f_0)
        ) && (DAT_008d138c <= DAT_008d136c)) {
      ITEM_I = ITEM_I + -1;
      ITEM_WORDS = ITEM_WORDS + -0x10;
    }
    DAT_008d136c = DAT_008d136c + -1;
    DAT_008d13a0 = DAT_008d13a0 + -1;
  }
  if (DAT_00794c14 != 0) {
    DAT_00794c18 = 0;
    DAT_00794c28 = DAT_00794c24;
  }
  DAT_008d13a0 = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    _DAT_008d139c = (float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_008d13a0]];
    if (_DAT_008d1398 <= _DAT_008d139c) {
      (&ITEM_P2)[(&ITEM_PTR0)[DAT_008d13a0]] = _DAT_008d139c - _DAT_008d1398;
    }
    else {
      (&ITEM_P2)[(&ITEM_PTR0)[DAT_008d13a0]] = _DAT_008d1398 + _DAT_008d139c;
    }
    DAT_008d13a0 = DAT_008d13a0 + 1;
  }
  LOAD_I = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    ffree(fVar6);
    fVar6 = (float10)load_item_header();
    if (LOAD_CODE == 99) {
      (&ITEM_P1)[LOAD_W] = f_14;
    }
    LOAD_I = LOAD_I + 1;
  }
  ffree(fVar6);
  Var5 = draw_items();
LAB_004ea5c6:
  ffree(Var5);
  Var5 = thunk_FUN_00468df8(&DAT_00766144);
  _DAT_009c6ad4 = f_0;
  ffree(Var5);
  return;
joined_r0x004e9a9b:
  if (iVar1 < 1) goto LAB_004e9bc3;
  if ((float)(int)(&DAT_01e9b0ec)[DAT_008d1378] < (float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_008d13a4]])
  goto LAB_004e9b06;
  DAT_008d13a4 = DAT_008d13a4 + 1;
  iVar1 = iVar1 + -1;
  goto joined_r0x004e9a9b;
LAB_004e9b06:
  (&DAT_01e9997c)[DAT_008d1378] = DAT_008d13a4 + -1;
  DAT_008d1374 = (int)ROUND((float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_008d13a4]]);
  if (ITEM_I <= DAT_008d13a4) {
LAB_004e9bc3:
    (&DAT_01e9997c)[DAT_008d1378] = ITEM_I;
    DAT_008d136c = 0;
    goto LAB_004e9bf1;
  }
  DAT_008d137c = DAT_008d13a4;
  goto LAB_004e97e9;
}


