// FUN_00417738 @ 00417738 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00417738(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  float10 in_ST0;
  float10 fVar5;
  unkbyte10 Var6;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  int local_154;
  int local_148;
  int local_6c;
  int local_3c;
  
  DAT_007d147c = 0;
  DAT_007d1478 = 0;
  DAT_007d1474 = 0;
  DAT_007d1470 = 0;
  if ((P1 != f_8) || (f_0 <= P2)) {
LAB_00417b2d:
    DAT_020527c8 = DAT_020527c4;
    _DAT_007d1464 = P2;
    DAT_007d1460 = EDIT_ITEM;
    IP2 = (int)ROUND(DAT_020b9444);
    DAT_0078b4e0 = (int)ROUND(DAT_020b9458 / f_10);
    DAT_007d145c = 1;
    IP7 = DAT_0078b4e0;
    if (P2 == f_98) {
      DAT_007d145c = 0;
    }
LAB_00417c07:
    DAT_007d1468 = 0;
    LOAD_I = 1;
    for (iVar3 = ITEM_I; 0 < iVar3; iVar3 = iVar3 + -1) {
      ffree(in_ST0);
      in_ST0 = (float10)load_item_header();
      if (((((f_0 < *(float *)(&ITEM_P7 + LOAD_W * 4)) && (6 < LOAD_LEN)) &&
           (LOAD_P3 <= DAT_020b9454 + f_0_04)) &&
          ((DAT_020b9448 - f_0_04 <= LOAD_P3 && (LOAD_CODE == 1)))) &&
         ((IP2 == LOAD_STAFF &&
          (((IP1 = ((int)ROUND((float)(&ITEM_P5)[LOAD_W]) % 100) / 10, DAT_007d145c == 0 ||
            (IP7 == IP1)) || (*(float *)(&ITEM_P12 + LOAD_W * 4) != f_0 && 0xb < LOAD_LEN)))))) {
        in_ST0 = (float10)(float)(&ITEM_P4)[LOAD_W];
        _DAT_007d1458 = (float)ABS(in_ST0);
        if (DAT_007d1468 < 1) {
          in_ST0 = (float10)DAT_020b944c;
          DAT_007d1454 = (float)ABS(in_ST0);
          DAT_020527c0 = (uint)(f_100 <= _DAT_007d1458);
          if ((DAT_020527c0 != 0) || (DAT_007d1454 < f_100)) {
            if ((DAT_020527c0 != 1) || (f_100 <= DAT_007d1454)) goto LAB_00417ebf;
            DAT_007d1454 = f_100;
            if (DAT_020b944c < f_0) {
              in_ST0 = (float10)f_100;
              DAT_007d1454 = (float)-in_ST0;
            }
            DAT_007d1454 = DAT_007d1454 + DAT_020b944c;
          }
          else {
            ffree(in_ST0);
            fVar5 = (float10)amod(&DAT_020b944c,&f_100);
            DAT_007d1454 = (float)fVar5;
            in_ST0 = extraout_ST1;
          }
          DAT_020b944c = DAT_007d1454;
          (&ITEM_P4)[(&ITEM_PTR0)[EDIT_ITEM]] = DAT_007d1454;
        }
LAB_00417ebf:
        if (DAT_020527c0 == 0) {
          if (_DAT_007d1458 < f_100) {
LAB_00417f0c:
            DAT_007d1450 = 0;
            DAT_007d1454 = *(float *)(&ITEM_P7 + LOAD_W * 4);
            if (f_64 <= DAT_007d1454) {
              DAT_007d1454 = f_0_25;
            }
            if (8 < LOAD_LEN) {
              DAT_007d1450 = (int)ROUND(*(float *)(&ITEM_P9 + LOAD_W * 4) / f_10) % 100;
              if (DAT_007d1450 == 1) {
                DAT_007d1454 = DAT_007d1454 / f_1_5;
              }
              if (DAT_007d1450 == 2) {
                DAT_007d1454 = DAT_007d1454 / f_1_75;
              }
            }
            if (f_0_5001 < DAT_007d1454) break;
            DAT_007d1468 = DAT_007d1468 + 1;
            ffree(in_ST0);
            in_ST0 = (float10)thunk_FUN_0054c590(&ITEM_P1 + LOAD_W,
                                                 &DAT_01e99944 + DAT_007d1468 * 0x3c,&DAT_0075f5f4);
            DAT_01f95c9c = 1;
            if (DAT_007d1454 < f_0_2501) {
              DAT_01f95c9c = 2;
            }
            if (DAT_007d1454 < f_0_1251) {
              DAT_01f95c9c = 3;
            }
            if (DAT_007d1454 < f_0_0626) {
              DAT_01f95c9c = 4;
            }
            if (DAT_007d1454 < f_0_0313) {
              DAT_01f95c9c = 5;
            }
            if (DAT_007d1454 < f_0_0157) {
              DAT_01f95c9c = 6;
            }
            *(float *)(DAT_007d1468 * 0x3c + 0x1e9995c) = (float)DAT_01f95c9c;
            if ((DAT_007d147c != 0) &&
               (((((DAT_007d1470 == DAT_007d1468 || (DAT_007d1474 == DAT_007d1468)) ||
                  (DAT_007d147c == DAT_007d1468)) || (DAT_007d1478 == DAT_007d1468)) &&
                ((float)(&DAT_01e9994c)[DAT_007d1468 * 0xf] < DAT_020b9454)))) {
              ffree(in_ST0);
              in_ST0 = (float10)thunk_FUN_0054c590(&DAT_01e99944 + DAT_007d1468 * 0x3c,
                                                   &DAT_01e99980 + DAT_007d1468 * 0xf,&DAT_0075f5f4)
              ;
              DAT_007d1468 = DAT_007d1468 + 1;
              (&DAT_01e9994c)[DAT_007d1468 * 0xf] =
                   *(float *)(DAT_007d1468 * 0x3c + 0x1e99910) + f_0_2;
              *(float *)(DAT_007d1468 * 0x3c + 0x1e9995c) = f_1;
            }
          }
        }
        else if (f_100 <= _DAT_007d1458) goto LAB_00417f0c;
      }
      LOAD_I = LOAD_I + 1;
    }
    if (DAT_007d1468 < 2) {
      if (DAT_0078b4e0 != IP7) goto LAB_004192ff;
      if (IP7 == 1) {
        IP7 = 2;
        DAT_007d1454 = f_13;
      }
      else {
        IP7 = 1;
        DAT_007d1454 = f_m13;
      }
      DAT_020b944c = DAT_007d1454 + DAT_020b944c;
      DAT_020b9450 = DAT_007d1454 + DAT_020b9450;
      goto LAB_00417c07;
    }
    DAT_01f95c9c = 0;
    while( true ) {
      DAT_020527c0 = 0;
      DAT_01f95c80 = 1;
      P1 = f_9990;
      for (iVar3 = DAT_007d1468; 0 < iVar3; iVar3 = iVar3 + -1) {
        if ((float)(&DAT_01e9994c)[DAT_01f95c80 * 0xf] <= P1) {
          P1 = (float)(&DAT_01e9994c)[DAT_01f95c80 * 0xf];
          DAT_020527c0 = DAT_01f95c80;
        }
        DAT_01f95c80 = DAT_01f95c80 + 1;
      }
      if (DAT_020527c0 == 0) break;
      DAT_01f95c9c = DAT_01f95c9c + 1;
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_0054c590(&DAT_01e99944 + DAT_020527c0 * 0x3c,
                                           DAT_01f95c9c * 0x3c + 0x1e9ce64,&DAT_0075f5f4);
      (&DAT_01e9994c)[DAT_020527c0 * 0xf] = f_9999;
    }
    DAT_01f95c80 = 1;
    DAT_020527c0 = 0;
    for (iVar3 = DAT_007d1468; 0 < iVar3; iVar3 = iVar3 + -1) {
      (&DAT_01fb8cc0)[DAT_01f95c80] = *(undefined4 *)(DAT_01f95c80 * 0x3c + 0x1e9ce7c);
      DAT_01f95c80 = DAT_01f95c80 + 1;
    }
    if (f_100 <= ABS(_DAT_01e9ceac)) {
      fVar5 = (float10)DAT_020b944c;
      if (ABS(fVar5) < (float10)f_100) {
        ffree(fVar5);
        fVar5 = (float10)amod(&DAT_020b944c,&f_100);
        DAT_020b944c = (float)fVar5;
        fVar5 = extraout_ST1_00;
      }
    }
    else {
      fVar5 = (float10)DAT_020b944c;
      if ((float10)f_100 <= ABS(fVar5)) {
        DAT_007d1454 = f_100;
        if (DAT_020b944c < f_0) {
          fVar5 = (float10)f_100;
          DAT_007d1454 = (float)-fVar5;
        }
        DAT_020b944c = DAT_007d1454 + DAT_020b944c;
      }
    }
    DAT_01f95c9c = 0;
    DAT_01f95c80 = 1;
    DAT_007d1454 = f_99;
    for (iVar3 = DAT_007d1468; 0 < iVar3; iVar3 = iVar3 + -1) {
      if (DAT_01fb8cc4 != (float)(&DAT_01fb8cc0)[DAT_01f95c80]) {
        DAT_01f95c9c = 1;
      }
      if ((float)(&DAT_01fb8cc0)[DAT_01f95c80] < DAT_007d1454) {
        DAT_007d1454 = (float)(&DAT_01fb8cc0)[DAT_01f95c80];
      }
      DAT_01f95c80 = DAT_01f95c80 + 1;
    }
    DAT_01f95c80 = 1;
    P1 = DAT_01fb8cc4;
    for (iVar3 = DAT_007d1468; 0 < iVar3; iVar3 = iVar3 + -1) {
      if (DAT_007d1454 == (float)(&DAT_01fb8cc0)[DAT_01f95c80]) {
        (&DAT_01fb8cc0)[DAT_01f95c80] = DAT_007d1454 + f_100;
      }
      DAT_01f95c80 = DAT_01f95c80 + 1;
    }
    DAT_020527c0 = (&ITEM_PTR0)[EDIT_ITEM];
    DAT_01f95c80 = (uint)ROUND((float)(&ITEM_LEN)[DAT_020527c0]);
    DAT_020b9458 = (float)(IP7 * 10) + DAT_007d1454;
    DAT_020b9454 = (float)(&DAT_01e9ce6c)[DAT_007d1468 * 0xf];
    DAT_020b9448 = DAT_01e9cea8;
    if (DAT_01f95c9c == 0) {
      ffree(fVar5);
      Var6 = thunk_FUN_0054c419(&DAT_020b945c,&DAT_0075f5c0);
      goto LAB_00418738;
    }
LAB_00418973:
    DAT_007d144c = 10;
    DAT_007d1448 = 0xb;
    DAT_007d1444 = 0xc;
    ffree(fVar5);
    Var6 = thunk_FUN_0054c419(&DAT_020b9464,&DAT_0075f61c);
LAB_004189a9:
    DAT_01f95c80 = 1;
    _DAT_007d1458 = f_99;
    for (iVar3 = DAT_007d1468; 0 < iVar3; iVar3 = iVar3 + -1) {
      if (((float)(&DAT_01fb8cc0)[DAT_01f95c80] < f_100) &&
         ((float)(&DAT_01fb8cc0)[DAT_01f95c80] < _DAT_007d1458)) {
        _DAT_007d1458 = (float)(&DAT_01fb8cc0)[DAT_01f95c80];
      }
      DAT_01f95c80 = DAT_01f95c80 + 1;
    }
    *(float *)(&DAT_020b943c + DAT_007d144c * 4) =
         (DAT_007d1454 * f_10 + _DAT_007d1458) - DAT_007d1454;
    DAT_01f95c9c = 0;
    DAT_01f95c80 = 1;
    iVar3 = DAT_007d1468;
joined_r0x00418a86:
    if (0 < iVar3) {
      iVar2 = (DAT_007d1468 - DAT_01f95c80) + 1;
      DAT_007d1440 = DAT_01f95c80;
      do {
        if (iVar2 < 1) {
LAB_00418b8a:
          DAT_01f95c9c = DAT_01f95c80;
          if (DAT_007d1468 <= (int)DAT_01f95c80) {
            *(float *)(&DAT_020b943c + DAT_007d1448 * 4) = f_0;
            *(float *)(&DAT_020b943c + DAT_007d1444 * 4) = f_m1;
            break;
          }
          bVar4 = DAT_007d1468 == DAT_01f95c80;
          bVar1 = 1 < (int)DAT_01f95c80;
          ffree(Var6);
          fVar5 = (float10)amod(DAT_01f95c80 * 4 + 0x1fb8cbc,&f_100);
          iVar3 = DAT_007d1448;
          if (bVar1 && fVar5 < (float10)(float)(&DAT_01fb8cc0)[DAT_01f95c80] || bVar4) {
            DAT_01f95c9c = DAT_007d1448;
            DAT_007d1448 = DAT_007d1444;
            DAT_007d1444 = iVar3;
          }
          *(float *)(&DAT_020b943c + DAT_007d1444 * 4) = f_0;
          *(undefined4 *)(&DAT_020b943c + DAT_007d1448 * 4) = (&DAT_01e9ce6c)[DAT_01f95c80 * 0xf];
          Var6 = extraout_ST1_01;
          if (f_99 <= (&DAT_01fb8cc4)[DAT_01f95c80]) break;
          DAT_01f95c9c = DAT_01f95c80 + 1;
          iVar3 = (DAT_007d1468 - DAT_01f95c9c) + 1;
          goto joined_r0x00418cc7;
        }
        if (f_99 <= (float)(&DAT_01fb8cc0)[DAT_01f95c80]) goto LAB_00418b47;
        if (_DAT_007d1458 == (float)(&DAT_01fb8cc0)[DAT_007d1440]) goto LAB_00418b8a;
        if (f_99 <= (float)(&DAT_01fb8cc0)[DAT_007d1440]) goto LAB_00418b47;
        DAT_007d1440 = DAT_007d1440 + 1;
        iVar2 = iVar2 + -1;
      } while( true );
    }
    goto LAB_00418d6e;
  }
  P1 = f_0;
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_0054c590(&DAT_020b947c,&DAT_007d1480,&DAT_0075f61c);
  DAT_007d146c = (int)ROUND((float)(&ITEM_LEN)[(&ITEM_PTR0)[EDIT_ITEM]]);
  if ((DAT_020b9470 != f_0) || (DAT_020b9474 == f_0 && DAT_020b9478 == f_0)) {
    DAT_007d1468 = (&DAT_02091d20)[EDIT_ITEM];
    local_154 = 6;
    DAT_01f95c80 = 1;
    do {
      if (*(float *)(&DAT_020b943c + DAT_01f95c80 * 4) !=
          (float)(&ITEM_LEN)[DAT_01f95c80 + DAT_007d1468]) {
        DAT_007d1468 = (&DAT_02091d18)[EDIT_ITEM];
        local_148 = 6;
        DAT_01f95c80 = 1;
        goto LAB_00417914;
      }
      DAT_01f95c80 = DAT_01f95c80 + 1;
      local_154 = local_154 + -1;
    } while (0 < local_154);
  }
LAB_00417b09:
  DAT_0078b4e0 = -99;
LAB_0041931f:
  ffree(in_ST0);
  return;
  while( true ) {
    DAT_01f95c80 = DAT_01f95c80 + 1;
    local_148 = local_148 + -1;
    if (local_148 < 1) break;
LAB_00417914:
    if (*(float *)(&DAT_020b943c + DAT_01f95c80 * 4) !=
        (float)(&ITEM_LEN)[DAT_01f95c80 + DAT_007d1468]) {
      in_ST0 = (float10)P2;
      DAT_007d1468 = (int)ROUND(-in_ST0);
      if (DAT_020b8ea2 == 'X') {
        P2 = f_98;
      }
      DAT_007d147c = DAT_007d1468;
      if (DAT_007d1468 < 100) goto LAB_00417b2d;
      DAT_007d1470 = DAT_007d1468 / 1000;
      iVar3 = (DAT_007d1468 % 1000) / 100;
      if (iVar3 == 0) {
        DAT_007d1474 = 0;
      }
      else {
        DAT_007d1474 = iVar3 + DAT_007d1470;
        if (0 < DAT_007d1470) {
          DAT_007d1474 = DAT_007d1474 + 1;
        }
        iVar3 = (DAT_007d1468 % 100) / 10;
        if (iVar3 == 0) {
          DAT_007d1478 = 0;
        }
        else {
          DAT_007d1478 = iVar3 + DAT_007d1474 + 1;
          if (DAT_007d1468 % 10 != 0) {
            DAT_007d147c = DAT_007d1478 + DAT_007d1468 % 10 + 1;
            goto LAB_00417b2d;
          }
          DAT_007d147c = 0;
        }
      }
      break;
    }
  }
  goto LAB_00417b09;
LAB_004192ff:
  P1 = f_0;
  goto LAB_0041931f;
joined_r0x00418cc7:
  if (iVar3 < 1) goto LAB_00418d0c;
  if (f_99 <= (float)(&DAT_01fb8cc0)[DAT_01f95c9c]) goto LAB_00418d1b;
  DAT_01f95c9c = DAT_01f95c9c + 1;
  iVar3 = iVar3 + -1;
  goto joined_r0x00418cc7;
LAB_00418d0c:
  DAT_01f95c9c = DAT_007d1468 + 1;
LAB_00418d1b:
  *(undefined4 *)(&DAT_020b943c + DAT_007d1444 * 4) =
       *(undefined4 *)(DAT_01f95c9c * 0x3c + 0x1e9ce30);
LAB_00418d6e:
  local_6c = DAT_007d1468;
  DAT_01f95c80 = 1;
  if (0 < DAT_007d1468) {
    while ((int)DAT_01f95c80 <= DAT_01f95c9c) {
      if (_DAT_007d1458 == (float)(&DAT_01fb8cc0)[DAT_01f95c80]) {
        DAT_007d1444 = DAT_01f95c80;
        for (iVar3 = (DAT_007d1468 - DAT_01f95c80) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
          if ((DAT_01f95c9c < DAT_007d1444) ||
             (_DAT_007d1458 != (float)(&DAT_01fb8cc0)[DAT_007d1444])) goto LAB_00418e89;
          (&DAT_01fb8cc0)[DAT_007d1444] = _DAT_007d1458 + f_100;
          DAT_007d1444 = DAT_007d1444 + 1;
        }
      }
      DAT_01f95c80 = DAT_01f95c80 + 1;
      local_6c = local_6c + -1;
      if (local_6c < 1) break;
    }
  }
LAB_00418e89:
  if (DAT_007d144c == 0xd) goto LAB_00418f37;
  DAT_01f95c9c = 0;
  DAT_01f95c80 = 1;
  iVar3 = DAT_007d1468;
  while( true ) {
    if (iVar3 < 1) goto LAB_00418f37;
    if ((float)(&DAT_01fb8cc0)[DAT_01f95c80] < f_99) break;
    DAT_01f95c80 = DAT_01f95c80 + 1;
    iVar3 = iVar3 + -1;
  }
  DAT_007d144c = 0xd;
  DAT_007d1448 = 0xe;
  DAT_007d1444 = 0xf;
  goto LAB_004189a9;
LAB_00418b47:
  DAT_01f95c80 = DAT_01f95c80 + 1;
  iVar3 = iVar3 + -1;
  goto joined_r0x00418a86;
LAB_00418f37:
  local_3c = 0x15;
  DAT_01f95c80 = 0x15;
  do {
    if (*(float *)(&DAT_020b943c + DAT_01f95c80 * 4) != f_0) break;
    DAT_01f95c80 = DAT_01f95c80 - 1;
    local_3c = local_3c + -1;
  } while (0 < local_3c);
  DAT_007d143c = DAT_01f95c80;
  _DAT_007d1438 = (int)ROUND((float)(&ITEM_LEN)[DAT_020527c0]);
  (&ITEM_LEN)[DAT_020527c0] = (float)(int)DAT_01f95c80;
  DAT_007d1434 = DAT_007d1460 + 1;
  _DAT_007d1430 = (&ITEM_PTR0)[DAT_007d1434];
  ffree(Var6);
  Var6 = FUN_00419328(&DAT_007d1438,&DAT_007d143c,&DAT_007d1430,&DAT_007d1434);
  DAT_020527c8 = DAT_007d143c;
LAB_00418738:
  ffree(Var6);
  Var6 = thunk_FUN_0054c590(&DAT_020b9440,&ITEM_P1 + DAT_020527c0,&DAT_01f95c80);
  DAT_01f95c9c = 1;
  iVar3 = DAT_007d1468;
  while( true ) {
    if (iVar3 < 1) {
      ffree(Var6);
      Var6 = thunk_FUN_0054c590(&DAT_020b9440,&ITEM_P1 + ITEM_WORDS,&DAT_01f95c80);
      (&ITEM_LEN)[ITEM_WORDS] = (float)(int)DAT_01f95c80;
      ITEM_WORDS = DAT_01f95c80 + ITEM_WORDS + 1;
      DAT_0205274c = 1;
      DAT_020527d4 = 0x20;
      DAT_020527d8 = 0;
      P2 = f_0;
      if (_DAT_007d1464 == f_98) {
        P1 = f_9;
        P2 = f_m1;
        ffree(Var6);
        Var6 = FUN_00419498();
        if (P2 != f_0) {
          DAT_020b9460 = P2;
          if ((int)DAT_020527c8 < 9) {
            DAT_007d143c = (&DAT_02091d20)[EDIT_ITEM];
            DAT_020527c0 = (&ITEM_PTR0)[EDIT_ITEM];
            (&ITEM_LEN)[DAT_020527c0] = f_9;
            DAT_01f95c9c = 9 - DAT_020527c8;
            DAT_01f95c80 = DAT_01f95c9c + ITEM_WORDS;
            ITEM_WORDS = DAT_01f95c80;
            for (iVar3 = (int)((DAT_007d143c - DAT_01f95c80) + -1) / -1; 0 < iVar3;
                iVar3 = iVar3 + -1) {
              (&ITEM_LEN)[DAT_01f95c80] = (&ITEM_LEN)[DAT_01f95c80 - DAT_01f95c9c];
              DAT_01f95c80 = DAT_01f95c80 + -1;
            }
            if (DAT_020527c8 == 7) {
              *(float *)(&ITEM_P8 + DAT_020527c0 * 4) = f_0;
            }
            *(float *)(&ITEM_P9 + DAT_020527c0 * 4) = P2;
            DAT_020527c8 = 9;
            DAT_01f95c80 = EDIT_ITEM + 1;
            for (iVar3 = (ITEM_I - DAT_01f95c80) + 2; 0 < iVar3; iVar3 = iVar3 + -1) {
              (&ITEM_PTR0)[DAT_01f95c80] = (&ITEM_PTR0)[DAT_01f95c80] + DAT_01f95c9c;
              DAT_01f95c80 = DAT_01f95c80 + 1;
            }
          }
          else {
            *(float *)(&ITEM_P9 + DAT_020527c0 * 4) = P2;
          }
        }
      }
      _DAT_007d142c = 0x20204441;
      if (DAT_007d145c == 0) {
        DAT_020b8ea2 = DAT_0075f5b4;
      }
      ffree(Var6);
      in_ST0 = (float10)thunk_FUN_0040cde4(&DAT_0075f5b0);
      goto LAB_0041931f;
    }
    if ((float)(&DAT_01fb8cc0)[DAT_01f95c9c] < f_99) break;
    DAT_01f95c9c = DAT_01f95c9c + 1;
    iVar3 = iVar3 + -1;
  }
  DAT_007d146c = DAT_007d146c + 1;
  if (DAT_007d146c < 0xd) {
    DAT_007d146c = 0xd;
  }
  DAT_01f95c80 = DAT_007d146c + ITEM_WORDS;
  DAT_007d1460 = DAT_007d1460 + 1;
  ITEM_WORDS = DAT_01f95c80;
  for (iVar3 = (int)(((&ITEM_PTR0)[DAT_007d1460] - DAT_01f95c80) + -1) / -1; 0 < iVar3;
      iVar3 = iVar3 + -1) {
    (&ITEM_LEN)[DAT_01f95c80] = (&ITEM_LEN)[DAT_01f95c80 - DAT_007d146c];
    DAT_01f95c80 = DAT_01f95c80 + -1;
  }
  DAT_01f95c9c = ITEM_I + 2;
  ITEM_I = ITEM_I + 1;
  for (iVar3 = (DAT_007d1460 - DAT_01f95c9c) / -1; 0 < iVar3; iVar3 = iVar3 + -1) {
    (&ITEM_PTR0)[DAT_01f95c9c] = (&DAT_02091d18)[DAT_01f95c9c] + DAT_007d146c;
    DAT_01f95c9c = DAT_01f95c9c + -1;
  }
  DAT_01f95c80 = (&ITEM_PTR0)[DAT_007d1460];
  ffree(Var6);
  fVar5 = (float10)thunk_FUN_0054c590(&ITEM_LEN + DAT_020527c0,&ITEM_LEN + DAT_01f95c80,
                                      &DAT_007d146c);
  (&ITEM_LEN)[DAT_01f95c80] = (float)(DAT_007d146c + -1);
  DAT_01f95c9c = 1;
  DAT_020527c0 = DAT_01f95c80;
  goto LAB_00418973;
}


