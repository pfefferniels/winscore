// FUN_00555488 @ 00555488 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00555488(void)

{
  float fVar1;
  float fVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 in_FPUControlWord;
  undefined2 uVar5;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  unkbyte10 Var6;
  float10 fVar7;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  float10 extraout_ST1_01;
  undefined1 *puVar8;
  int local_1b4;
  int local_1a8;
  
  puVar8 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if (P2 == f_0) {
    ffree(in_ST0);
    DAT_0078dc68 = thunk_FUN_0059ccb0(&DAT_0079ecd8);
    ffree(extraout_ST0);
    in_ST0 = thunk_FUN_00468df8(&DAT_00769a44);
    if (DAT_0078dc68 == 2) goto LAB_00557d5d;
    ffree(in_ST0);
    in_ST0 = thunk_FUN_005725fa();
    P1 = (float)_DAT_0079ecd8;
    P2 = (float)_DAT_0079ecdc;
    P20 = (float)_DAT_0079ed24;
    P10 = (float)DAT_0079ece8;
    P11 = (float)DAT_0079ece4;
    P3 = (float)_DAT_0079ece0;
    local_1a8 = 6;
    IP1 = 4;
    do {
      *(undefined4 *)(&IP0 + IP1 * 4) = *(undefined4 *)(&DAT_0079ecdc + IP1 * 4);
      IP1 = IP1 + 1;
      local_1a8 = local_1a8 + -1;
    } while (0 < local_1a8);
  }
  else {
    local_1b4 = 0xc;
    DAT_0078dc68 = 1;
    do {
      *(float *)(&P0 + DAT_0078dc68 * 4) = (&P1)[DAT_0078dc68];
      *(int *)(&IP0 + DAT_0078dc68 * 4) = (int)ROUND(*(float *)(&P0 + DAT_0078dc68 * 4));
      DAT_0078dc68 = DAT_0078dc68 + 1;
      local_1b4 = local_1b4 + -1;
    } while (0 < local_1b4);
    P20 = P12;
  }
  DAT_009a3c4c = IP4 * 100 + IP5;
  DAT_009a3c48 = IP6 * 100 + IP7;
  DAT_009a3c44 = IP8 * 100 + IP9;
  if ((f_2 <= P1) && (P1 <= (float)MAX_STAFF)) {
    if (P2 != f_0) {
      _DAT_0079ecdc = (int)ROUND(P2);
    }
    _DAT_0079ecd8 = (int)ROUND(P1);
    _DAT_0079ece0 = (int)ROUND(P3);
    DAT_0079ece4 = (int)ROUND(P11);
    DAT_0079ece8 = (int)ROUND(P10);
    DAT_0079ecec = IP4;
    DAT_0079ecf0 = IP5;
    _DAT_0079ecf4 = IP6;
    _DAT_0079ecf8 = IP7;
    _DAT_0079ecfc = IP8;
    _DAT_0079ed00 = IP9;
    _DAT_0079ed24 = (int)ROUND(P20);
    DAT_009a3c40 = (int)ROUND(P2);
    DAT_0078dc6c = DAT_009a3c40 % 100;
    DAT_01fb8c60 = P1;
    DAT_020527c4 = (int)ROUND(P1);
    DAT_009a3c3c = 0;
    DAT_020527c0 = ITEM_WORDS;
    DAT_009a3c38 = (int)ROUND(P3);
    if (DAT_009a3c38 == 0) {
      DAT_009a3c38 = DAT_020527c4 + -1;
    }
    IP1 = 0;
    DAT_020527cc = f_1;
    DAT_020527c8 = f_0;
    DAT_0078b4e4 = 0x58;
    ffree(in_ST0);
    Var6 = thunk_FUN_004f7808();
    LOAD_I = 1;
    IP16 = DAT_009a3c4c;
    IP17 = DAT_009a3c48;
    IP18 = DAT_009a3c44;
    for (iVar4 = ITEM_I; 0 < iVar4; iVar4 = iVar4 + -1) {
      ffree(Var6);
      Var6 = load_item_header();
      if ((LOAD_CODE == 8) && (DAT_020527c4 == LOAD_STAFF)) {
        DAT_0078dc5c = LOAD_W;
        IP11 = LOAD_LEN;
        if (3 < LOAD_LEN) {
          DAT_020527c8 = (float)(&ITEM_P4)[LOAD_W];
          if ((4 < LOAD_LEN) && ((float)(&ITEM_P5)[LOAD_W] != f_0)) {
            DAT_020527cc = (float)(&ITEM_P5)[LOAD_W];
          }
          goto LAB_00555ad2;
        }
      }
      else {
LAB_00555ad2:
        if (DAT_009a3c38 == LOAD_STAFF) {
          if (LOAD_CODE != 8) {
            DAT_02052740 = DAT_02052748;
            FUN_005f33c9(&stack0xfffffffc,0x555b7d);
            Var6 = FUN_005f34d1(puVar8,0x555b98);
            *(undefined4 *)(puVar8 + -0x1d4) = 0;
            *(undefined4 *)(puVar8 + -0x1e8) = 3;
            *(undefined4 *)(puVar8 + -0x1e4) = 0x9ae2d9;
            *(int **)(puVar8 + -0x1e0) = &DAT_009a3c38;
            ffree(Var6);
            Var6 = FUN_005f34f0(puVar8 + -0x1d4,0x784ff00,&DAT_00769a00,puVar8 + -0x1e8,
                                &DAT_0079ec98);
            ffree(Var6);
            in_ST0 = thunk_FUN_0054d831(&DAT_009ae2bc,0x200);
            *(undefined4 *)(puVar8 + -0x184) = 0;
            goto LAB_00557d5d;
          }
          IP1 = LOAD_W;
          IP2 = LOAD_LEN;
        }
      }
      LOAD_I = LOAD_I + 1;
    }
    DAT_0078b4e0 = 1.24716e-43;
    if (DAT_0079ece8 == 0) {
      DAT_0078b4e0 = 1.09301e-43;
    }
    DAT_009a3c34 = (int)DAT_0078b4e0;
    DAT_0078b4e0 = 1.24716e-43;
    if (DAT_0079ece4 == 1) {
      DAT_0078b4e0 = 1.09301e-43;
    }
    DAT_0078dc60 = DAT_0078b4e0;
    _DAT_01e9ebb8 = 0;
    _DAT_01e9ebb4 = 0;
    DAT_0078dc64 = 1;
    DAT_01e9ad20 = 0;
    LOAD_LEN = 0;
    DAT_01e9ad24 = 0;
    IP10 = 999;
    ffree(Var6);
    DAT_01e67910 = f_0;
    DAT_01e67914 = f_200;
    Var6 = thunk_FUN_004ebd10();
    ffree(Var6);
    in_ST0 = thunk_FUN_00563510();
    if (DAT_01e99980 != 0) {
      if ((DAT_0078dc6c == 0) && (DAT_01e9a2ec == 1)) {
        DAT_0078dc6c = 4;
      }
      if (DAT_0078dc6c == 0) {
        DAT_0078dc6c = 6;
      }
      DAT_020527cc = DAT_020527cc * f_1_4;
      fVar7 = (float10)DAT_020527c8 / (float10)f_1_4;
      DAT_020527c8 = (float)((fVar7 - (float10)DAT_0078dc6c) + (float10)f_1);
      (&ITEM_LEN)[ITEM_WORDS] = f_7;
      (&ITEM_P1)[ITEM_WORDS] = f_8;
      P2 = (float)DAT_009a3c38;
      (&ITEM_P2)[ITEM_WORDS] = P2;
      P3 = (float)(&ITEM_P3)[DAT_0078dc5c];
      if (IP11 < 3) {
        P3 = f_0;
      }
      (&ITEM_P3)[ITEM_WORDS] = P3;
      (&ITEM_P4)[ITEM_WORDS] = DAT_020527c8;
      (&ITEM_P5)[ITEM_WORDS] = DAT_020527cc;
      (&ITEM_P6)[ITEM_WORDS] = f_200;
      if (5 < IP11) {
        (&ITEM_P6)[ITEM_WORDS] = (&ITEM_P6)[DAT_0078dc5c];
      }
      *(float *)(&ITEM_P7 + ITEM_WORDS * 4) = (float)DAT_0078dc6c;
      ITEM_WORDS = ITEM_WORDS + 8;
      (&ITEM_LEN)[ITEM_WORDS] = f_4;
      (&ITEM_P1)[ITEM_WORDS] = f_14;
      (&ITEM_P2)[ITEM_WORDS] = P2;
      (&ITEM_P3)[ITEM_WORDS] = P3;
      (&ITEM_P4)[ITEM_WORDS] = f_2;
      ITEM_WORDS = ITEM_WORDS + 5;
      P1 = f_13;
      P5 = f_66;
      P6 = (float)-DAT_0078dc6c;
      if (DAT_0078dc6c == 6) {
        if (DAT_01e9a2ec == 1) {
          P6 = f_m16;
        }
      }
      else if (DAT_0078dc6c == 7) {
        P1 = f_15;
      }
      else if (DAT_0078dc6c == 5) {
        P6 = f_m15;
        if (DAT_01e9a2ec == 0) {
          P6 = f_m5;
        }
        P1 = f_0;
        P5 = f_55;
      }
      else {
        P6 = f_m14;
        if (DAT_01e9a2ec == 0) {
          P6 = f_m4;
        }
        P1 = f_9;
        P5 = f_44;
      }
      if (DAT_0078dc60 == 1.24716e-43) {
        (&ITEM_LEN)[ITEM_WORDS] = f_5;
        (&ITEM_P1)[ITEM_WORDS] = f_3;
        (&ITEM_P2)[ITEM_WORDS] = P2;
        (&ITEM_P3)[ITEM_WORDS] = P3 + f_2;
        (&ITEM_P4)[ITEM_WORDS] = f_0;
        (&ITEM_P5)[ITEM_WORDS] = P5;
        ITEM_WORDS = ITEM_WORDS + 6;
      }
      DAT_0078dc60 = 0.0;
      LOAD_I = 1;
      IP1 = DAT_01e99980;
      DAT_020527d4 = f_0;
      DAT_020527d0 = f_0;
      DAT_020527cc = f_0;
      iVar4 = ITEM_I;
      while (0 < iVar4) {
        ffree(fVar7);
        fVar7 = (float10)load_item_header();
        if (-1 < LOAD_STAFF - DAT_020527c4) {
          if (0 < LOAD_STAFF - DAT_020527c4) break;
          if ((LOAD_CODE == 3) || ((LOAD_CODE != 0xe && 6 < LOAD_CODE) && LOAD_CODE != 0x12)) {
            *(undefined4 *)(puVar3 + -0x170) = 0;
          }
          else {
            if (DAT_009a3c34 == 0x59) {
              DAT_009a3c3c = DAT_009a3c3c + 1;
              *(int *)(&DAT_01e9bcc4 + DAT_009a3c3c * 4) = LOAD_I;
            }
            else {
              *(undefined4 *)(puVar3 + -0x16c) = 0;
            }
            if (LOAD_CODE == 6) {
              *(undefined4 *)(puVar3 + -0x168) = 0;
            }
            else {
              ffree(fVar7);
              fVar7 = (float10)thunk_FUN_0054c590(&ITEM_LEN + LOAD_W,&ITEM_LEN + ITEM_WORDS,
                                                  &DAT_007699b0);
              (&ITEM_P2)[ITEM_WORDS] = P2;
              fVar2 = DAT_020527d0;
              if (LOAD_CODE == 1) {
                DAT_0078dc60 = (float)((int)DAT_0078dc60 + 1);
                ffree(fVar7);
                fVar7 = (float10)amod(&ITEM_P4 + ITEM_WORDS,&f_100);
                *(undefined2 *)(puVar3 + -0x1dc) = in_FPUControlWord;
                *(ushort *)(puVar3 + -0x1da) = (ushort)*(undefined4 *)(puVar3 + -0x1dc) | 0xc00;
                *(int *)(puVar3 + -0x1d8) = (int)ROUND(fVar7);
                uVar5 = *(undefined2 *)(puVar3 + -0x1dc);
                DAT_0078dc5c = *(int *)(puVar3 + -0x1d8);
                if (DAT_01e9a2ec == 1) {
                  DAT_0078dc5c = DAT_0078dc5c + -5;
                }
                (&DAT_01e99fc8)[(int)DAT_0078dc60] = DAT_0078dc5c;
                ffree(extraout_ST1);
                fVar7 = (float10)amod(&ITEM_P5 + ITEM_WORDS,&f_10);
                P5 = (float)fVar7;
                IP2 = (&DAT_01e9ad24)[(int)DAT_0078dc60];
                if (P5 == f_0) {
                  if (IP2 == 0) {
                    if (DAT_0078dc60 == 1.4013e-45) {
                      *(undefined4 *)(puVar3 + -0x158) = 0;
                    }
                    else {
                      LOAD_CODE = (&DAT_01e99fc8)[(int)DAT_0078dc60];
                      DAT_020527d4 = DAT_0078dc60;
                      while (DAT_020527d4 != 1.4013e-45) {
                        DAT_020527d4 = (float)((int)DAT_020527d4 + -1);
                        if (LOAD_CODE == (&DAT_01e99fc8)[(int)DAT_020527d4]) {
                          P5 = (float)*(int *)((int)DAT_020527d4 * 4 + 0x1e99ca8);
                          *(undefined4 *)(puVar3 + -0x14c) = 0;
                          goto LAB_005567a7;
                        }
                        *(undefined4 *)(puVar3 + -0x150) = 0;
                      }
                      *(undefined4 *)(puVar3 + -0x154) = 0;
                    }
                  }
                  else {
                    *(undefined4 *)(puVar3 + -0x15c) = 0;
                    IP2 = IP2 % 0xc;
                    IP4 = ((DAT_0078dc5c + 0x1b) % 7) * 2;
                    if (5 < IP4) {
                      IP4 = IP4 + -1;
                    }
                    if ((IP4 == 0) && (IP2 == 0xb)) {
                      IP4 = 0xc;
                    }
                    if ((IP4 == 0xb) && (IP2 == 0)) {
                      IP2 = 0xc;
                    }
                    IP4 = IP2 - IP4;
                    P5 = (float)(int)(&DAT_0079eccc)[IP4];
                  }
                }
                else {
                  *(undefined4 *)(puVar3 + -0x160) = 0;
                }
LAB_005567a7:
                (&ITEM_P5)[ITEM_WORDS] = P5;
                *(undefined2 *)(puVar3 + -0x1dc) = uVar5;
                *(ushort *)(puVar3 + -0x1da) = (ushort)*(undefined4 *)(puVar3 + -0x1dc) | 0xc00;
                *(int *)(puVar3 + -0x1d8) = (int)ROUND(P5);
                in_FPUControlWord = *(undefined2 *)(puVar3 + -0x1dc);
                *(undefined4 *)((int)DAT_0078dc60 * 4 + 0x1e99ca8) =
                     *(undefined4 *)(puVar3 + -0x1d8);
                (&ITEM_P6)[ITEM_WORDS] = P6;
                P5 = f_0;
                if ((int)(&DAT_01e9ad24)[(int)DAT_0078dc60] < 1) {
                  P5 = f_m1;
                }
                *(float *)(&ITEM_P8 + ITEM_WORDS * 4) = P5;
                LOAD_LEN = 8;
                *(undefined4 *)(puVar3 + -0x148) = 10;
                DAT_01a1ae4c = 9;
                do {
                  if ((DAT_01a1ae4c < 0x10) || (*(int *)(&IP0 + DAT_01a1ae4c * 4) == 0)) {
                    *(undefined4 *)(puVar3 + -0x144) = 0;
                    (&ITEM_LEN)[DAT_01a1ae4c + ITEM_WORDS] = f_0;
                  }
                  else {
                    LOAD_LEN = DAT_01a1ae4c;
                    (&ITEM_LEN)[DAT_01a1ae4c + ITEM_WORDS] =
                         (float)*(int *)(&IP0 + DAT_01a1ae4c * 4);
                    *(undefined4 *)(puVar3 + -0x140) = 0;
                  }
                  *(undefined4 *)(puVar3 + -0x13c) = 0;
                  DAT_01a1ae4c = DAT_01a1ae4c + 1;
                  *(int *)(puVar3 + -0x148) = *(int *)(puVar3 + -0x148) + -1;
                } while (0 < *(int *)(puVar3 + -0x148));
                *(float *)(&ITEM_P19 + ITEM_WORDS * 4) = f_0;
                (&DAT_01e99988)[(int)DAT_0078dc60] = ITEM_WORDS;
                *(float *)((int)DAT_0078dc60 * 4 + 0x1e9ec34) = f_0;
                ffree(extraout_ST1_00);
                fVar7 = (float10)anint(puVar3,0x55696f);
                *(int *)(puVar3 + -0x1d8) = (int)ROUND(fVar7);
                DAT_01a1ae4c = *(int *)(puVar3 + -0x1d8);
                LOAD_P3 = (float)DAT_01a1ae4c / f_100;
                if ((P5 == f_0) && (DAT_020527d4 == LOAD_P3)) {
                  *(float *)((int)DAT_0078dc60 * 4 + 0x1e9ec34) = LOAD_P3;
                }
                DAT_020527d4 = LOAD_P3;
                if ((float)(&ITEM_P6)[LOAD_W] == f_6) {
                  if (LOAD_LEN < 9) {
                    LOAD_LEN = 9;
                  }
                  *(float *)(&ITEM_P9 + ITEM_WORDS * 4) = f_m1;
                }
                else {
                  *(undefined4 *)(puVar3 + -0x138) = 0;
                }
                if (P20 == f_0) {
                  *(undefined4 *)(puVar3 + -0x134) = 0;
                  fVar7 = extraout_ST1_01;
                }
                else {
                  ffree(extraout_ST1_01);
                  fVar7 = (float10)thunk_FUN_0054c419(&ITEM_P1 + LOAD_LEN + ITEM_WORDS,&DAT_007699b0
                                                     );
                  LOAD_LEN = 0x14;
                  *(float *)(&ITEM_P20 + ITEM_WORDS * 4) = f_1;
                }
                (&ITEM_LEN)[ITEM_WORDS] = (float)LOAD_LEN;
                *(undefined4 *)(puVar3 + -0x130) = 0;
              }
              else {
                *(undefined4 *)(puVar3 + -0x164) = 0;
                if (LOAD_CODE == 5) {
                  if ((LOAD_LEN < 9) || (*(float *)(&ITEM_P9 + ITEM_WORDS * 4) < f_98)) {
                    fVar1 = *(float *)(&ITEM_P8 + ITEM_WORDS * 4);
                    *(undefined2 *)(puVar3 + -0x1dc) = in_FPUControlWord;
                    *(ushort *)(puVar3 + -0x1da) = (ushort)*(undefined4 *)(puVar3 + -0x1dc) | 0xc00;
                    *(int *)(puVar3 + -0x1d8) = (int)ROUND(fVar1);
                    in_FPUControlWord = *(undefined2 *)(puVar3 + -0x1dc);
                    LOAD_LEN = *(int *)(puVar3 + -0x1d8);
                    P5 = DAT_020527d0;
                    P7 = DAT_020527cc;
                    DAT_020527d0 = LOAD_P3;
                    fVar1 = (float)(&ITEM_P6)[ITEM_WORDS];
                    if ((LOAD_LEN < 1) &&
                       (f_3 < ABS(fVar1 - DAT_020527cc) || f_3 < ABS(LOAD_P3 - fVar2))) {
                      *(undefined4 *)(puVar3 + -0x124) = 0;
                      DAT_020527cc = fVar1;
                      goto LAB_005562df;
                    }
                    DAT_009a3c3c = DAT_009a3c3c + -1;
                    *(undefined4 *)(puVar3 + -0x120) = 0;
                    DAT_020527cc = fVar1;
                    goto LAB_00556acb;
                  }
                  *(undefined4 *)(puVar3 + -0x128) = 0;
                }
                else {
                  *(undefined4 *)(puVar3 + -300) = 0;
                  while (LOAD_CODE == 4) {
                    if ((LOAD_LEN < 5) || ((float)(&ITEM_P5)[ITEM_WORDS] != f_999)) {
                      *(undefined4 *)(puVar3 + -0x110) = 0;
                      goto LAB_00556aaa;
                    }
                    *(undefined4 *)(puVar3 + -0x114) = 0;
LAB_005562df:
                    if (LOAD_LEN / 2 == -1) {
                      *(undefined4 *)(puVar3 + -0x11c) = 0;
                      goto LAB_00556acb;
                    }
                    *(int *)(puVar3 + -0x1d8) = DAT_0078dc6c * -2 + 0xc;
                    P7 = f_14_5 - (float)*(int *)(puVar3 + -0x1d8);
                    (&ITEM_P4)[ITEM_WORDS] = P7;
                    (&ITEM_P5)[ITEM_WORDS] = P7;
                    P7 = f_0;
                    P5 = ((float)(&ITEM_P6)[ITEM_WORDS] - LOAD_P3) - f_10;
                    if (f_0 < P5) {
                      P7 = P5 / f_100;
                    }
                    *(float *)(&ITEM_P7 + ITEM_WORDS * 4) = P7 + f_1;
                    *(float *)(&ITEM_P8 + ITEM_WORDS * 4) = f_m1;
                    (&ITEM_LEN)[ITEM_WORDS] = f_13;
                    ffree(fVar7);
                    fVar7 = (float10)thunk_FUN_0054cd13(&ITEM_P9 + ITEM_WORDS * 4,&DAT_00769998);
                    (&ITEM_P13)[ITEM_WORDS] = f_0_5;
                    LOAD_LEN = 0xd;
                  }
                  *(undefined4 *)(puVar3 + -0x118) = 0;
                  if (LOAD_CODE == 0xe) {
                    LOAD_CODE = LOAD_LEN + 1;
                    iVar4 = 0xb - LOAD_CODE;
                    *(int *)(puVar3 + -0x108) = iVar4;
                    while (0 < iVar4) {
                      (&ITEM_LEN)[LOAD_CODE + ITEM_WORDS] = f_0;
                      LOAD_CODE = LOAD_CODE + 1;
                      *(int *)(puVar3 + -0x108) = *(int *)(puVar3 + -0x108) + -1;
                      iVar4 = *(int *)(puVar3 + -0x108);
                    }
                    (&ITEM_LEN)[ITEM_WORDS] = f_11;
                    *(float *)(&ITEM_P11 + ITEM_WORDS * 4) = P1;
                    LOAD_LEN = 0xb;
                  }
                  else {
                    *(undefined4 *)(puVar3 + -0x10c) = 0;
                  }
                  if (LOAD_CODE == 2) {
                    (&ITEM_P6)[ITEM_WORDS] = f_m1;
                  }
                }
              }
LAB_00556aaa:
              ITEM_WORDS = LOAD_LEN + ITEM_WORDS + 1;
            }
          }
        }
LAB_00556acb:
        *(undefined4 *)(puVar3 + -0x104) = 0;
        LOAD_I = LOAD_I + 1;
        *(int *)(puVar3 + -0x174) = *(int *)(puVar3 + -0x174) + -1;
        iVar4 = *(int *)(puVar3 + -0x174);
      }
      DAT_0078dc70 = 0;
      *(int *)(puVar3 + -0x100) = ITEM_I;
      LOAD_I = 1;
      iVar4 = ITEM_I;
joined_r0x00556b24:
      if (iVar4 < 1) goto LAB_00556df2;
      ffree(fVar7);
      fVar7 = (float10)load_item_header();
      if (-1 < LOAD_STAFF - DAT_020527c4) {
        if (LOAD_STAFF - DAT_020527c4 < 1) {
          if ((LOAD_CODE == 7) && (6 < LOAD_LEN)) {
            fVar2 = *(float *)(&ITEM_P7 + LOAD_W * 4);
            *(undefined2 *)(puVar3 + -0x1dc) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x1da) = (ushort)*(undefined4 *)(puVar3 + -0x1dc) | 0xc00;
            *(int *)(puVar3 + -0x1d8) = (int)ROUND(fVar2);
            in_FPUControlWord = *(undefined2 *)(puVar3 + -0x1dc);
            DAT_0078dc5c = *(int *)(puVar3 + -0x1d8);
            if ((DAT_0078dc5c == 8) || (DAT_0078dc5c == 0x58)) {
              *(undefined4 *)(puVar3 + -0xf8) = 0;
              DAT_0078dc5c = -0x50;
              *(undefined4 *)(puVar3 + -0xe8) = 0;
LAB_00556c2c:
              *(int *)(puVar3 + -0x1d8) = DAT_0078dc5c - DAT_0078dc6c;
              P1 = (float)*(int *)(puVar3 + -0x1d8);
              P3 = (float)(&ITEM_P3)[LOAD_W] - f_2;
              P6 = (float)(&ITEM_P6)[LOAD_W] + f_0_5;
              if (P6 == f_0) {
                P6 = P3 + f_2_5;
              }
              do {
                if ((float)(&ITEM_P1)[DAT_020527c0] == f_1) {
                  P5 = (float)(&ITEM_P3)[DAT_020527c0];
                  if (P3 <= P5) {
                    if (P6 < P5) goto LAB_00556d9b;
                    (&ITEM_P6)[DAT_020527c0] = P1;
                  }
                  else {
                    *(undefined4 *)(puVar3 + -0xe0) = 0;
                  }
                }
                else {
                  *(undefined4 *)(puVar3 + -0xe4) = 0;
                }
                fVar2 = (float)(&ITEM_LEN)[DAT_020527c0];
                *(undefined2 *)(puVar3 + -0x1dc) = in_FPUControlWord;
                *(ushort *)(puVar3 + -0x1da) = (ushort)*(undefined4 *)(puVar3 + -0x1dc) | 0xc00;
                *(int *)(puVar3 + -0x1d8) = (int)ROUND(fVar2);
                in_FPUControlWord = *(undefined2 *)(puVar3 + -0x1dc);
                DAT_0078dc5c = *(int *)(puVar3 + -0x1d8);
                DAT_020527c0 = DAT_0078dc5c + DAT_020527c0 + 1;
                if (ITEM_WORDS <= DAT_020527c0) {
                  *(undefined4 *)(puVar3 + -0xd4) = 0;
                  goto LAB_00556df2;
                }
                *(undefined4 *)(puVar3 + -0xd8) = 0;
              } while( true );
            }
            if (DAT_0078dc5c == 0xf) {
              *(undefined4 *)(puVar3 + -0xf4) = 0;
              DAT_0078dc5c = -0x96;
              goto LAB_00556c2c;
            }
            if (DAT_0078dc5c == -8) {
              DAT_0078dc5c = -0x5a;
              *(undefined4 *)(puVar3 + -0xec) = 0;
              goto LAB_00556c2c;
            }
            *(undefined4 *)(puVar3 + -0xf0) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0xfc) = 0;
          }
          goto LAB_00556db1;
        }
        goto LAB_00556df2;
      }
      goto LAB_00556db1;
    }
  }
LAB_00557d5d:
  ffree(in_ST0);
  return;
LAB_00556d9b:
  *(undefined4 *)(puVar3 + -0xdc) = 0;
LAB_00556db1:
  *(undefined4 *)(puVar3 + -0xd0) = 0;
  LOAD_I = LOAD_I + 1;
  *(int *)(puVar3 + -0x100) = *(int *)(puVar3 + -0x100) + -1;
  iVar4 = *(int *)(puVar3 + -0x100);
  goto joined_r0x00556b24;
LAB_00556df2:
  IP10 = 999;
  *(float *)(puVar3 + -0xcc) = DAT_0078dc60;
  DAT_0078dc68 = 1;
  fVar2 = DAT_0078dc60;
  while (0 < (int)fVar2) {
    DAT_01a1ae40 = (&DAT_01e99988)[DAT_0078dc68];
    if (f_0 <= *(float *)(&ITEM_P8 + DAT_01a1ae40 * 4)) {
      IP8 = 0;
      ffree(fVar7);
      fVar7 = (float10)FUN_00557e05();
      if (DAT_009a3c40 == 0x6a) {
        IP8 = IP8 + 100;
      }
      *(float *)(&ITEM_P8 + DAT_01a1ae40 * 4) = (float)IP8;
    }
    else {
      *(undefined4 *)(puVar3 + -200) = 0;
    }
    (&DAT_01e99fc8)[DAT_0078dc68] = 0;
    if (*(float *)(DAT_0078dc68 * 4 + 0x1e9ec34) == f_0) {
      *(undefined4 *)(puVar3 + -0xc4) = 0;
      DAT_0078dc5c = 0;
    }
    else {
      while( true ) {
        IP1 = DAT_0078dc68;
        if (DAT_0078dc5c == 0) {
          IP1 = DAT_0078dc68 + -1;
        }
        DAT_0078dc5c = (&DAT_01e99988)[IP1];
        fVar2 = *(float *)(&ITEM_P8 + DAT_0078dc5c * 4);
        *(undefined2 *)(puVar3 + -0x1dc) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x1da) = (ushort)*(undefined4 *)(puVar3 + -0x1dc) | 0xc00;
        *(int *)(puVar3 + -0x1d8) = (int)ROUND(fVar2);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0x1dc);
        (&DAT_01e9a9f0)[IP1] = *(undefined4 *)(puVar3 + -0x1d8);
        if (DAT_0078dc68 == IP1) break;
        *(undefined4 *)(puVar3 + -0xc0) = 0;
      }
      *(undefined4 *)(puVar3 + -0xbc) = 0;
    }
    *(undefined4 *)(puVar3 + -0xb8) = 0;
    DAT_0078dc68 = DAT_0078dc68 + 1;
    *(int *)(puVar3 + -0xcc) = *(int *)(puVar3 + -0xcc) + -1;
    fVar2 = *(float *)(puVar3 + -0xcc);
  }
  DAT_0078dc68 = 1;
LAB_00556fbb:
  DAT_0078dc5c = 0;
  while (DAT_0078dc68 < (int)DAT_0078dc60) {
    *(undefined4 *)(puVar3 + -0xb4) = 0;
    iVar4 = DAT_0078dc68 + 1;
    if ((*(float *)(iVar4 * 4 + 0x1e9ec34) == f_0) || ((int)(&DAT_01e9a9ec)[iVar4] < 0)) {
      *(undefined4 *)(puVar3 + -0xa8) = 0;
      if (DAT_0078dc5c != 0) {
        DAT_01a1ae4c = DAT_0078dc68;
        goto LAB_0055709e;
      }
      *(undefined4 *)(puVar3 + -0xa0) = 0;
      DAT_0078dc68 = iVar4;
    }
    else {
      if (DAT_0078dc5c == 0) {
        DAT_0078dc5c = DAT_0078dc68;
      }
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      DAT_0078dc68 = iVar4;
    }
  }
  if (DAT_0078dc5c != 0) {
    DAT_01a1ae4c = DAT_0078dc68;
    *(undefined4 *)(puVar3 + -0xac) = 0;
LAB_0055709e:
    do {
      DAT_0078dc70 = DAT_0078dc5c + 1;
      iVar4 = (DAT_01a1ae4c - DAT_0078dc70) + 1;
      *(int *)(puVar3 + -0x9c) = iVar4;
      while( true ) {
        if (iVar4 < 1) {
          iVar4 = (DAT_0078dc5c - DAT_01a1ae4c) / -1;
          *(int *)(puVar3 + -0x8c) = iVar4;
          LOAD_LEN = DAT_01a1ae4c;
          if (0 < iVar4) goto LAB_00557274;
          goto LAB_00557448;
        }
        LOAD_W = DAT_0078dc70 + -1;
        if ((int)(&DAT_01e9ad24)[DAT_0078dc70] < (int)(&DAT_01e9ad24)[LOAD_W]) break;
        *(undefined4 *)(puVar3 + -0x98) = 0;
        *(undefined4 *)(puVar3 + -0x90) = 0;
        DAT_0078dc70 = DAT_0078dc70 + 1;
        *(int *)(puVar3 + -0x9c) = *(int *)(puVar3 + -0x9c) + -1;
        iVar4 = *(int *)(puVar3 + -0x9c);
      }
      ffree(fVar7);
      LOAD_LEN = DAT_0078dc70;
      Var6 = thunk_FUN_0054c68f(&DAT_01e9a9f0 + DAT_0078dc70,&DAT_01e9a9f0 + LOAD_W);
      ffree(Var6);
      Var6 = thunk_FUN_0054c68f(&DAT_01e9ad24 + LOAD_LEN,&DAT_01e9ad24 + LOAD_W);
      LOAD_LEN = (&DAT_01e99988)[DAT_0078dc70];
      LOAD_W = (&DAT_01e99984)[DAT_0078dc70];
      ffree(Var6);
      Var6 = thunk_FUN_0054c669(&ITEM_P4 + LOAD_LEN,&ITEM_P4 + LOAD_W);
      ffree(Var6);
      Var6 = thunk_FUN_0054c669(&ITEM_P5 + LOAD_LEN,&ITEM_P5 + LOAD_W);
      ffree(Var6);
      Var6 = thunk_FUN_0054c669(&ITEM_P7 + LOAD_LEN * 4,&ITEM_P7 + LOAD_W * 4);
      ffree(Var6);
      fVar7 = (float10)thunk_FUN_0054c669(&ITEM_P8 + LOAD_LEN * 4,&ITEM_P8 + LOAD_W * 4);
      *(undefined4 *)(puVar3 + -0x94) = 0;
    } while( true );
  }
  *(undefined4 *)(puVar3 + -0xb0) = 0;
LAB_0055777a:
  if (DAT_009a3c34 != 0x59) {
    *(undefined4 *)(puVar3 + -0x34) = 0;
LAB_00557d4a:
    ffree(fVar7);
    in_ST0 = draw_items();
    goto LAB_00557d5d;
  }
  DAT_0078dc68 = 0;
  P1 = f_1;
  P2 = (float)(&ITEM_P2)[DAT_01e9998c];
  P4 = f_0_9;
  P5 = f_20;
  P6 = f_7;
  P7 = f_m2;
  P8 = f_m1_5;
  ffree(fVar7);
  fVar7 = (float10)thunk_FUN_0054cd13(&P9,&DAT_00769970);
  P15 = f_0_8;
  P17 = f_m0_7;
  do {
    DAT_0078dc68 = DAT_0078dc68 + 1;
    LOAD_I = *(int *)(&DAT_01e9bcc4 + DAT_0078dc68 * 4);
    ffree(fVar7);
    fVar7 = (float10)load_item_header();
    if (LOAD_CODE == 1) {
      *(undefined4 *)(puVar3 + -0x30) = 0;
      if (LOAD_P3 != DAT_020527d4) {
        DAT_020527d4 = LOAD_P3;
        ffree(fVar7);
        thunk_FUN_0054c590(&P1,&ITEM_P1 + ITEM_WORDS,&DAT_00769964);
        (&ITEM_P3)[ITEM_WORDS] = LOAD_P3;
        DAT_0078dc70 = 0x11;
        fVar2 = (float)(&ITEM_P6)[LOAD_W];
        *(undefined2 *)(puVar3 + -0x1dc) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x1da) = (ushort)*(undefined4 *)(puVar3 + -0x1dc) | 0xc00;
        *(int *)(puVar3 + -0x1d8) = (int)ROUND(fVar2);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0x1dc);
        LOAD_I = *(int *)(puVar3 + -0x1d8);
        if ((LOAD_I == 1) || (LOAD_I == 2)) {
          (&ITEM_P6)[ITEM_WORDS] = f_9;
          DAT_0078dc70 = 0xf;
        }
        else {
          *(undefined4 *)(puVar3 + -0x10) = 0;
        }
        fVar7 = (float10)(float)(&ITEM_P4)[LOAD_W];
        if ((float10)f_100 <= ABS(fVar7)) {
          (&ITEM_P4)[ITEM_WORDS] = f_m2_2;
          (&ITEM_P5)[ITEM_WORDS] = f_10;
          *(float *)(&ITEM_P8 + ITEM_WORDS * 4) = f_100;
          *(float *)(&ITEM_P10 + ITEM_WORDS * 4) = f_m2_5;
          *(float *)(&ITEM_P15 + ITEM_WORDS * 4) = f_0_55;
          DAT_0078dc70 = 0xf;
        }
        else {
          *(undefined4 *)(puVar3 + -0xc) = 0;
        }
        if (LOAD_LEN < 0xb) {
          *(undefined4 *)(puVar3 + -8) = 0;
        }
        else {
          fVar7 = (float10)*(float *)(&ITEM_P11 + LOAD_W * 4);
          *(undefined2 *)(puVar3 + -0x1dc) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x1da) = (ushort)*(undefined4 *)(puVar3 + -0x1dc) | 0xc00;
          *(int *)(puVar3 + -0x1d8) = (int)ROUND(ABS(fVar7));
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x1dc);
          LOAD_I = *(int *)(puVar3 + -0x1d8);
          *(int *)(puVar3 + -0x1d8) = -LOAD_I;
          *(float *)(&ITEM_P11 + ITEM_WORDS * 4) = (float)*(int *)(puVar3 + -0x1d8);
        }
        if (8 < LOAD_LEN) {
          *(undefined4 *)(&ITEM_P9 + ITEM_WORDS * 4) = *(undefined4 *)(&ITEM_P9 + LOAD_W * 4);
        }
        goto LAB_00557d08;
      }
      *(undefined4 *)(puVar3 + -0x14) = 0;
    }
    else {
      *(int *)(puVar3 + -0x1e0) = LOAD_LEN + 1;
      ffree(fVar7);
      fVar7 = (float10)thunk_FUN_0054c590(&ITEM_LEN + LOAD_W,&ITEM_LEN + ITEM_WORDS,puVar3 + -0x1e0)
      ;
      (&ITEM_P2)[ITEM_WORDS] = P2;
      if (LOAD_CODE == 5) {
        ffree(fVar7);
        thunk_FUN_0054cd13(&ITEM_P9 + ITEM_WORDS * 4,&DAT_00769998);
        DAT_020527cc = ABS(*(float *)(&ITEM_P7 + LOAD_W * 4));
        fVar7 = (float10)DAT_020527cc;
        *(float *)(&ITEM_P7 + ITEM_WORDS * 4) = (float)-fVar7;
        (&ITEM_P13)[ITEM_WORDS] = f_0_7;
        (&ITEM_P3)[ITEM_WORDS] = LOAD_P3 - f_1_4;
        (&ITEM_P4)[ITEM_WORDS] = f_1;
        (&ITEM_P5)[ITEM_WORDS] = f_1;
        *(float *)(&ITEM_P8 + ITEM_WORDS * 4) = f_m2;
        (&ITEM_P13)[ITEM_WORDS] = f_0_7;
        DAT_0078dc70 = 0xd;
        *(undefined4 *)(puVar3 + -0x28) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x2c) = 0;
        if (LOAD_CODE == 6) {
          ffree(fVar7);
          fVar7 = (float10)thunk_FUN_0054cd13(&ITEM_P1 + LOAD_LEN + ITEM_WORDS,&DAT_007699b0);
          (&ITEM_P18)[ITEM_WORDS] = f_0_8;
          (&ITEM_P4)[ITEM_WORDS] = f_2_1;
          (&ITEM_P5)[ITEM_WORDS] = f_2_1;
          DAT_020527cc = *(float *)(&ITEM_P7 + LOAD_W * 4);
          if (DAT_020527cc < f_20) {
            DAT_020527cc = DAT_020527cc + f_10;
          }
          *(float *)(&ITEM_P7 + ITEM_WORDS * 4) = DAT_020527cc;
          DAT_0078dc70 = 0x12;
          *(undefined4 *)(puVar3 + -0x20) = 0;
        }
        else {
          *(undefined4 *)(puVar3 + -0x24) = 0;
          if (LOAD_CODE != 2) {
            *(undefined4 *)(puVar3 + -0x1c) = 0;
            goto LAB_00557d30;
          }
          (&ITEM_P4)[ITEM_WORDS] = f_m7;
          *(float *)(&ITEM_P15 + ITEM_WORDS * 4) = f_0_7;
          ffree(fVar7);
          fVar7 = (float10)thunk_FUN_0054cd13(&ITEM_P8 + ITEM_WORDS * 4,&DAT_0076994c);
          DAT_0078dc70 = 0xf;
          *(undefined4 *)(puVar3 + -0x18) = 0;
        }
      }
LAB_00557d08:
      (&ITEM_LEN)[ITEM_WORDS] = (float)DAT_0078dc70;
      ITEM_WORDS = DAT_0078dc70 + ITEM_WORDS + 1;
    }
LAB_00557d30:
    if (DAT_009a3c3c <= DAT_0078dc68) goto LAB_00557d4a;
    *(undefined4 *)(puVar3 + -4) = 0;
  } while( true );
LAB_00557274:
  LOAD_W = LOAD_LEN + -1;
  do {
    if ((int)(&DAT_01e9a9f0)[LOAD_LEN] < (int)(&DAT_01e9a9f0)[LOAD_W]) {
      *(undefined4 *)(puVar3 + -0x88) = 0;
    }
    else {
      LOAD_I = (&DAT_01e9a9f0)[LOAD_W] + 1;
      if (DAT_0078dc6c < LOAD_I) {
        ffree(fVar7);
        fVar7 = (float10)FUN_00557d66();
        *(undefined4 *)(puVar3 + -0x80) = 0;
        goto LAB_00556fbb;
      }
      *(undefined4 *)(puVar3 + -0x84) = 0;
      (&DAT_01e9a9f0)[LOAD_W] = LOAD_I;
      *(float *)(&ITEM_P8 + (&DAT_01e99988)[LOAD_W] * 4) = (float)LOAD_I;
    }
    while (0 < (int)((&DAT_01e9a9f0)[LOAD_W] - (&DAT_01e9a9f0)[LOAD_LEN])) {
      if ((&DAT_01e9a9f0)[LOAD_W] - (&DAT_01e9a9f0)[LOAD_LEN] == 1) {
        *(undefined4 *)(puVar3 + -0x78) = 0;
        *(undefined4 *)(puVar3 + -0x6c) = 0;
        LOAD_LEN = LOAD_LEN + -1;
        *(int *)(puVar3 + -0x8c) = *(int *)(puVar3 + -0x8c) + -1;
        if (*(int *)(puVar3 + -0x8c) < 1) goto LAB_00557448;
        goto LAB_00557274;
      }
      iVar4 = ((LOAD_LEN - DAT_01a1ae4c) + -1) / -1;
      *(int *)(puVar3 + -0x74) = iVar4;
      LOAD_I = DAT_01a1ae4c;
      while (0 < iVar4) {
        LOAD_CODE = (&DAT_01e99988)[LOAD_I] + 8;
        (&ITEM_LEN)[LOAD_CODE] = (float)(&ITEM_LEN)[LOAD_CODE] + f_1;
        (&DAT_01e9a9f0)[LOAD_I] = (&DAT_01e9a9f0)[LOAD_I] + 1;
        LOAD_I = LOAD_I + -1;
        *(int *)(puVar3 + -0x74) = *(int *)(puVar3 + -0x74) + -1;
        iVar4 = *(int *)(puVar3 + -0x74);
      }
      *(undefined4 *)(puVar3 + -0x70) = 0;
    }
    *(undefined4 *)(puVar3 + -0x7c) = 0;
  } while( true );
LAB_00557448:
  LOAD_I = 0;
  LOAD_CODE = 99;
  LOAD_LEN = 0;
  DAT_0078b4e4 = 99;
  iVar4 = (DAT_01a1ae4c - DAT_0078dc5c) + 1;
  *(int *)(puVar3 + -0x68) = iVar4;
  DAT_0078dc70 = DAT_0078dc5c;
  while (0 < iVar4) {
    DAT_01a1ae40 = (&DAT_01e99988)[DAT_0078dc70];
    IP9 = 0;
    IP8 = (&DAT_01e9a9f0)[DAT_0078dc70];
    ffree(fVar7);
    fVar7 = (float10)FUN_00557e05();
    if (LOAD_I < IP9) {
      LOAD_I = IP9;
    }
    if (IP8 < DAT_0078b4e4) {
      DAT_0078b4e4 = IP8;
    }
    if (IP8 < LOAD_LEN) {
      *(undefined4 *)(puVar3 + -100) = 0;
    }
    else {
      LOAD_LEN = IP8;
      IP11 = DAT_0078dc70;
    }
    if ((0 < IP9) && (IP9 < LOAD_CODE)) {
      LOAD_CODE = IP9;
    }
    DAT_0078dc70 = DAT_0078dc70 + 1;
    *(int *)(puVar3 + -0x68) = *(int *)(puVar3 + -0x68) + -1;
    iVar4 = *(int *)(puVar3 + -0x68);
  }
  if (5 < LOAD_I - LOAD_CODE) goto code_r0x00557585;
  *(undefined4 *)(puVar3 + -0x60) = 0;
LAB_00557751:
  if ((int)DAT_0078dc60 + -1 <= DAT_0078dc68) goto LAB_0055777a;
  *(undefined4 *)(puVar3 + -0x38) = 0;
  goto LAB_00556fbb;
code_r0x00557585:
  if (*(float *)(&ITEM_P8 + (&DAT_01e99988)[DAT_01a1ae4c] * 4) == f_1) {
    *(undefined4 *)(puVar3 + -0x5c) = 0;
    iVar4 = DAT_01a1ae4c - DAT_0078dc5c;
    *(int *)(puVar3 + -0x44) = iVar4;
    DAT_0078dc70 = DAT_0078dc5c;
joined_r0x005575cb:
    if (0 < iVar4) {
      if (DAT_0078dc6c != (&DAT_01e9a9f0)[DAT_0078dc70]) goto code_r0x005575ea;
      *(undefined4 *)(puVar3 + -0x40) = 0;
LAB_00557743:
      ffree(fVar7);
      fVar7 = (float10)FUN_00557d66();
      *(undefined4 *)(puVar3 + -0x50) = 0;
      goto LAB_00557751;
    }
    *(undefined4 *)(puVar3 + -0x3c) = 0;
  }
  else {
    iVar4 = (DAT_01a1ae4c - IP11) + 1;
    *(int *)(puVar3 + -0x58) = iVar4;
    DAT_0078dc70 = IP11;
    while (0 < iVar4) {
      DAT_01a1ae40 = (&DAT_01e99988)[DAT_0078dc70] + 8;
      if ((float)(&ITEM_LEN)[DAT_01a1ae40] <= f_0) goto LAB_00557743;
      *(undefined4 *)(puVar3 + -0x54) = 0;
      (&ITEM_LEN)[DAT_01a1ae40] = (float)(&ITEM_LEN)[DAT_01a1ae40] - f_1;
      (&DAT_01e9a9f0)[DAT_0078dc70] = (&DAT_01e9a9f0)[DAT_0078dc70] + -1;
      *(undefined4 *)(puVar3 + -0x4c) = 0;
      DAT_0078dc70 = DAT_0078dc70 + 1;
      *(int *)(puVar3 + -0x58) = *(int *)(puVar3 + -0x58) + -1;
      iVar4 = *(int *)(puVar3 + -0x58);
    }
    *(undefined4 *)(puVar3 + -0x48) = 0;
  }
  goto LAB_00557448;
code_r0x005575ea:
  DAT_01a1ae40 = (&DAT_01e9a9f0)[DAT_0078dc70] + 1;
  (&DAT_01e9a9f0)[DAT_0078dc70] = DAT_01a1ae40;
  *(float *)(&ITEM_P8 + (&DAT_01e99988)[DAT_0078dc70] * 4) = (float)DAT_01a1ae40;
  DAT_0078dc70 = DAT_0078dc70 + 1;
  *(int *)(puVar3 + -0x44) = *(int *)(puVar3 + -0x44) + -1;
  iVar4 = *(int *)(puVar3 + -0x44);
  goto joined_r0x005575cb;
}


