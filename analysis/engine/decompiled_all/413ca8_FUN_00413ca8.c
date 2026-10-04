// FUN_00413ca8 @ 00413ca8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413ca8(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 in_ST0;
  unkbyte10 Var5;
  float10 extraout_ST0;
  float10 fVar6;
  float10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  int local_13c;
  int local_14;
  
  DAT_0078deb8 = DAT_01fb8c80;
  P1 = f_6;
  P2 = DAT_01fb8c60;
  DAT_0078cd30 = 0;
  if (DAT_01fb8cc4 == f_9999) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00410fd8();
    DAT_0078cd30 = 1;
    if (DAT_01fb8cc4 == f_9999) goto LAB_00415543;
  }
  DAT_01f95c80 = 0;
  do {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0041a14c(&DAT_01f95c80,&DAT_0078deb0,&DAT_01f95c88,&DAT_01f95c8c,
                                         &IP8,&DAT_01f95c90,&DAT_01f95c94,&DAT_007d13e0,
                                         &DAT_007d13dc,&DAT_007d13d8,&DAT_007d13d4);
    if (DAT_007d13d4 == DAT_007d13d8) {
      if ((0 < DAT_01f95c88) && (DAT_01f95c8c < DAT_01fb8c78)) {
        _DAT_007d13d0 = DAT_01f95c88 + -1;
        P8 = (float)IP8;
        DAT_007d13cc = 99;
        DAT_007d13c8 = 0;
        local_13c = 7;
        DAT_01f95c84 = 9;
        do {
          *(float *)(&P0 + DAT_01f95c84 * 4) = f_0;
          DAT_01f95c84 = DAT_01f95c84 + 1;
          local_13c = local_13c + -1;
        } while (0 < local_13c);
        DAT_01f95c84 = *(int *)(&DAT_01f995bc + DAT_01f95c88 * 4);
        in_ST0 = (float10)(float)(&DAT_01f95d50)[DAT_01f95c84 * 0xf];
        DAT_0078cd34 = (uint)((float10)f_100 <= ABS(in_ST0));
        if (*(int *)(&DAT_01f9929c + DAT_01f95c88 * 4) == 0) {
          DAT_0078cd38 = *(int *)(&DAT_01f995bc + DAT_01f95c8c * 4);
          DAT_007d13c4 = 0;
          bVar1 = false;
          DAT_007d13c0 = 99;
          DAT_0078cd3c = -99;
          do {
            if ((float)(&DAT_01f95d44)[DAT_01f95c84 * 0xf] == f_1) {
              DAT_01f95c9c = (int)ROUND((float)(&DAT_01f95d50)[DAT_01f95c84 * 0xf]);
              iVar3 = DAT_01f95c9c;
              if (DAT_01f95c9c < 0) {
                iVar3 = -DAT_01f95c9c;
              }
              if (iVar3 < 100) {
                if (DAT_01f95c9c < DAT_007d13c0) {
                  DAT_007d13c0 = DAT_01f95c9c;
                }
                if (DAT_0078cd3c < DAT_01f95c9c) {
                  DAT_0078cd3c = DAT_01f95c9c;
                }
                DAT_007d13bc = (float)(&DAT_01f95d4c)[DAT_01f95c84 * 0xf];
                DAT_01f95c9c = DAT_01f95c84;
                while (((DAT_01f95c9c = DAT_01f95c9c + 1, DAT_01f95c9c <= DAT_0078deb8 &&
                        (DAT_007d13bc == (float)(&DAT_01f95d4c)[DAT_01f95c9c * 0xf])) &&
                       ((float)(&DAT_01f95d44)[DAT_01f95c9c * 0xf] == f_1))) {
                  bVar1 = true;
                }
                if (bVar1) {
                  DAT_007d13c4 = DAT_007d13c4 + 1;
                  *(int *)(&DAT_01f9448c + DAT_007d13c4 * 4) = DAT_01f95c84;
                  DAT_007d13c4 = DAT_007d13c4 + 1;
                  DAT_01f95c84 = DAT_01f95c9c + -1;
                  *(int *)(&DAT_01f9448c + DAT_007d13c4 * 4) = DAT_01f95c84;
                  bVar1 = false;
                }
              }
            }
            DAT_01f95c84 = DAT_01f95c84 + 1;
          } while (DAT_01f95c84 <= DAT_0078cd38);
          DAT_007d13b8 = 1;
          if (7 - DAT_007d13c0 <= DAT_0078cd3c + -7) {
            DAT_007d13b8 = 2;
          }
          if (DAT_0078deb0 != 0) {
            DAT_007d13b8 = DAT_0078deb0 / 10;
          }
          if (DAT_007d13c4 != 0) {
            DAT_007d13bc = (float)(DAT_007d13b8 * 10);
            DAT_01f95c98 = 1;
            do {
              DAT_01f95c9c = *(int *)(&DAT_01f9448c + DAT_01f95c98 * 4);
              DAT_007d13b4 = DAT_007d13bc;
              DAT_007d13b0 = 0;
              DAT_007d13c0 = (int)ROUND((float)(&DAT_01f95d54)[DAT_01f95c9c * 0xf]);
              if (99 < DAT_007d13c0) {
                DAT_007d13c0 = DAT_007d13c0 + -100;
                DAT_007d13b0 = 100;
              }
              if (DAT_007d13b8 != DAT_007d13c0 / 10) {
                (&DAT_01f95d54)[DAT_01f95c9c * 0xf] = (float)(DAT_007d13c0 % 10 + DAT_007d13b0);
                (&DAT_01f95d60)[DAT_01f95c9c * 0xf] = f_0;
                DAT_007d13cc = (&DAT_01f94490)[DAT_01f95c98];
                DAT_007d13b0 = DAT_01f95c9c;
                for (iVar3 = (DAT_007d13cc - DAT_01f95c9c) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
                  *(float *)(&DAT_01f95d68 + DAT_007d13b0 * 0x3c) = f_0;
                  iVar4 = DAT_007d13b0 * 0x3c;
                  ffree(in_ST0);
                  fVar6 = (float10)amod(&DAT_01f95d64 + DAT_007d13b0 * 0x3c,&f_100);
                  *(float *)(&DAT_01f95d64 + iVar4) = (float)fVar6;
                  *(undefined4 *)(&DAT_01f98c58 + DAT_007d13b0 * 8) =
                       (&DAT_01f95d50)[DAT_007d13b0 * 0xf];
                  *(float *)(&DAT_01f98c5c + DAT_007d13b0 * 8) =
                       (float)(int)ROUND((float)(&DAT_01f95d54)[DAT_007d13b0 * 0xf]);
                  DAT_007d13b0 = DAT_007d13b0 + 1;
                  in_ST0 = extraout_ST1;
                }
                DAT_007d13ac = DAT_007d13cc;
                DAT_007d13b0 = DAT_01f95c9c;
                for (iVar3 = (DAT_007d13cc - DAT_01f95c9c) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
                  (&DAT_01f95d50)[DAT_007d13ac * 0xf] =
                       *(undefined4 *)(&DAT_01f98c58 + DAT_007d13b0 * 8);
                  (&DAT_01f95d54)[DAT_007d13ac * 0xf] =
                       *(undefined4 *)(&DAT_01f98c5c + DAT_007d13b0 * 8);
                  DAT_007d13ac = DAT_007d13ac + -1;
                  DAT_007d13b0 = DAT_007d13b0 + 1;
                }
                (&DAT_01f95d54)[DAT_01f95c9c * 0xf] =
                     DAT_007d13b4 + (float)(&DAT_01f95d54)[DAT_01f95c9c * 0xf];
                DAT_007d13b4 = (float)(DAT_007d13cc - DAT_01f95c9c);
                ffree(in_ST0);
                Var5 = thunk_FUN_004ee442(&DAT_007d13b4,&DAT_007d13cc);
                ffree(Var5);
                in_ST0 = (float10)thunk_FUN_0051c824(&DAT_01f95c9c,&DAT_007d13cc);
              }
              DAT_01f95c98 = DAT_01f95c98 + 2;
            } while (DAT_01f95c98 < DAT_007d13c4);
          }
          DAT_0078deb0 = DAT_007d13b8 * 10;
          DAT_007d13b8 = DAT_0078deb0;
          DAT_01f95c98 = DAT_01f95c88;
          for (iVar3 = (DAT_01f95c8c - DAT_01f95c88) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
            if (*(int *)(&DAT_01f9929c + DAT_01f95c98 * 4) == 0) {
              *(int *)(&DAT_01f9929c + DAT_01f95c98 * 4) = DAT_007d13b8;
              DAT_007d13c0 = *(int *)(&DAT_01f995bc + DAT_01f95c98 * 4);
              DAT_007d13b4 = (float)(&DAT_01f95d54)[DAT_007d13c0 * 0xf];
              DAT_01f95c9c = (int)ROUND(DAT_007d13b4) % 100;
              if (9 < DAT_01f95c9c) {
                if (DAT_007d13b8 == 0x14) {
                  if (DAT_01f95c9c < 0x14) {
                    DAT_007d13bc = f_10;
LAB_00414636:
                    (&DAT_01f95d54)[DAT_007d13c0 * 0xf] = DAT_007d13bc + DAT_007d13b4;
                  }
                }
                else if (0x13 < DAT_01f95c9c) {
                  DAT_007d13bc = f_m10;
                  goto LAB_00414636;
                }
                DAT_007d13bc = *(float *)(&DAT_01f95d6c + DAT_007d13c0 * 0x3c);
                if (DAT_007d13bc != f_0) {
                  DAT_01f95c9c = (int)ROUND(DAT_007d13bc);
                  DAT_0078cd3c = DAT_01f95c9c;
                  if (DAT_01f95c9c < 0) {
                    DAT_0078cd3c = -DAT_01f95c9c;
                  }
                  DAT_007d13bc = f_0;
                  ffree(in_ST0);
                  iVar4 = thunk_FUN_004d9413(&DAT_0078cd3c,&DAT_01f95c9c);
                  in_ST0 = extraout_ST0;
                  if (iVar4 != 0) {
                    ffree(extraout_ST0);
                    in_ST0 = (float10)thunk_FUN_004d9475(&DAT_007d13c0,&DAT_0078cd3c,&DAT_007d13bc,
                                                         &DAT_01f95c9c);
                  }
                  *(float *)(&DAT_01f95d6c + DAT_007d13c0 * 0x3c) =
                       (float)DAT_01f95c9c + DAT_007d13bc;
                }
              }
            }
            DAT_01f95c98 = DAT_01f95c98 + 1;
          }
        }
        DAT_007d13c4 = 0;
        DAT_007d13b0 = 0;
        DAT_007d13ac = 0;
        DAT_01f95c84 = DAT_01f95c88;
        for (iVar3 = (DAT_01f95c8c - DAT_01f95c88) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
          DAT_01f95c98 = *(int *)(&DAT_01f995bc + DAT_01f95c84 * 4);
          DAT_01f95c9c = (int)ROUND(*(float *)(&DAT_01f95d74 + DAT_01f95c98 * 0x3c));
          if (DAT_01f95c9c == 0) goto LAB_00415543;
          if (f_64 <= *(float *)(&DAT_0204929c + DAT_01f95c98 * 4)) {
            DAT_01f95c9c = 0;
          }
          else {
            if (DAT_01f95c9c < DAT_007d13cc) {
              DAT_007d13cc = DAT_01f95c9c;
            }
            if (DAT_007d13c8 < DAT_01f95c9c) {
              DAT_007d13c8 = DAT_01f95c9c;
            }
          }
          DAT_007d13c4 = DAT_007d13c4 + 1;
          *(undefined4 *)(DAT_007d13c4 * 4 + 0x1f9416c) = 0;
          if ((DAT_007d13d8 != 0) || (DAT_01f95c9c != 0)) {
            DAT_007d13b0 = DAT_007d13b0 + 1;
            DAT_007d13c0 = DAT_01f95c98;
            iVar4 = DAT_007d13c0;
            do {
              DAT_007d13c0 = iVar4;
              iVar4 = DAT_007d13c0 + 1;
              if ((DAT_0078deb8 < iVar4) || ((float)(&DAT_01f95d44)[iVar4 * 0xf] != f_1)) break;
            } while (*(float *)(&DAT_0204929c + iVar4 * 4) == f_0);
            iVar2 = DAT_007d13c0 * 0xf;
            ffree(in_ST0);
            DAT_007d13b8 = DAT_007d13c0;
            DAT_007d13c0 = iVar4;
            fVar6 = (float10)amod(&DAT_01f95d50 + iVar2,&f_100);
            DAT_007d13b4 = (float)fVar6;
            DAT_007d13a8 = DAT_007d13b4;
            ffree(extraout_ST1_00);
            in_ST0 = (float10)thunk_FUN_0041a776(&DAT_007d13b4,&DAT_007d13b8);
            if (DAT_007d13ac == 0) {
              DAT_007d13ac = (int)ROUND(DAT_007d13b4 - DAT_007d13a8);
            }
            *(float *)(&DAT_01f942fc + DAT_007d13b0 * 4) = DAT_007d13b4;
            *(int *)(&DAT_01f9448c + DAT_007d13b0 * 4) = DAT_007d13b8;
          }
          (&DAT_01f93fdc)[DAT_007d13c4] = DAT_01f95c9c;
          DAT_01f95c84 = DAT_01f95c84 + 1;
        }
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_00559f38(&DAT_007d13e0,&DAT_007d13dc,&DAT_0078deb0,&DAT_007d13b0
                                             ,&P3,&P6);
        DAT_01f95c84 = 1;
        DAT_01f95c9c = DAT_01f93fe0;
        DAT_007d13c0 = 0;
        do {
          iVar3 = DAT_01f95c84;
          DAT_0078cd3c = DAT_01f95c84;
          if (DAT_007d13c4 != DAT_01f95c84) {
            for (; DAT_007d13b8 = (&DAT_01f93fe0)[DAT_01f95c84], DAT_007d13b8 == 0;
                DAT_01f95c84 = DAT_01f95c84 + 1) {
            }
          }
          if (DAT_007d13cc != DAT_01f95c9c) {
            if (DAT_007d13c4 == DAT_01f95c84) {
              if (DAT_007d13c0 < DAT_01f95c9c) {
                *(undefined4 *)(iVar3 * 4 + 0x1f9416c) = 0xffffffff;
              }
            }
            else if (((DAT_007d13b8 != DAT_01f95c9c) && (DAT_007d13b8 < DAT_01f95c9c)) &&
                    (DAT_007d13c0 < DAT_01f95c9c)) {
              DAT_01f95c98 = 0xffffffff;
              if (DAT_007d13c0 < DAT_007d13b8) {
                DAT_01f95c98 = 1;
              }
              *(int *)(iVar3 * 4 + 0x1f9416c) = DAT_01f95c98;
            }
          }
          DAT_01f95c84 = DAT_01f95c84 + 1;
          DAT_007d13c0 = DAT_01f95c9c;
          DAT_01f95c9c = DAT_007d13b8;
        } while (DAT_01f95c84 <= DAT_007d13c4);
        iVar3 = (int)ROUND(_DAT_007d13e0);
        DAT_01f95c98 = 0;
        DAT_007d13a8 = f_0;
        if ((DAT_007d13d8 == 0) && (DAT_0078cd34 == 0)) {
          if (2 < DAT_007d13c8) {
            DAT_01f95c98 = 2;
            if ((0x13 < DAT_0078deb0 && 0xd < iVar3) || (iVar3 < 1 && DAT_0078deb0 < 0x14)) {
              DAT_01f95c98 = 4;
            }
            DAT_01f95c98 = DAT_007d13c8 * 3 + DAT_01f95c98 + -9;
          }
          if (DAT_0078deb0 < 0x14) {
            if ((9 < iVar3) && ((int)ROUND(_DAT_007d13dc) == iVar3)) {
              DAT_01f95c98 = DAT_01f95c98 + -2;
            }
          }
          else {
            DAT_01f95c98 = -DAT_01f95c98;
            if ((iVar3 < 5) && ((int)ROUND(_DAT_007d13dc) == iVar3)) {
              DAT_01f95c98 = DAT_01f95c98 + 2;
            }
          }
          DAT_007d13b4 = (float)DAT_01f95c98 / f_2;
        }
        else {
          DAT_007d13a8 = f_100;
          if (iVar3 < 0) {
            DAT_007d13a8 = f_m100;
          }
          if (DAT_007d13d8 != 0) {
            DAT_007d13cc = 2;
          }
          DAT_007d13b4 = f_0_8;
          if (0x13 < DAT_0078deb0) {
            in_ST0 = (float10)f_0_8;
            DAT_007d13b4 = (float)-in_ST0;
          }
        }
        P4 = DAT_007d13b4 + _DAT_007d13e0 + DAT_007d13a8;
        if (((DAT_0078cd34 != 0) && (f_90 < P4)) && (P4 < f_100)) {
          P4 = f_m100 - (f_100 - P4);
        }
        P5 = DAT_007d13b4 + _DAT_007d13dc;
        DAT_01f95c9c = DAT_01f93fe0;
        DAT_01f95c84 = 2;
        iVar3 = DAT_007d13c4;
        while (iVar3 = iVar3 + -1, 0 < iVar3) {
          DAT_01f95c98 = (&DAT_01f93fdc)[DAT_01f95c84];
          if ((DAT_01f95c98 != 0) && (DAT_01f93fe0 != DAT_01f95c98)) {
            DAT_0078cd40 = DAT_007d13cc;
            DAT_01f95c98 = 1;
            goto LAB_00415124;
          }
          DAT_01f95c84 = DAT_01f95c84 + 1;
        }
        DAT_007d13a4 = 0;
LAB_00414fb5:
        P7 = (float)(DAT_007d13cc + DAT_0078deb0);
        DAT_007d13b4 = P9;
        if ((DAT_007d13ac != 0) && (P10 != f_0)) {
          ffree(in_ST0);
          in_ST0 = (float10)FUN_004155ab(&P11,&P12);
          P9 = DAT_007d13bc * f_10 + P9;
          if (P13 != f_0) {
            ffree(in_ST0);
            in_ST0 = (float10)FUN_004155ab(&P14,&P15);
            P9 = DAT_007d13bc + P9;
          }
        }
        DAT_01fb8c80 = DAT_01fb8c80 + 1;
        if (DAT_01fb8c80 < 0xc9) {
          local_14 = 0xf;
          DAT_01f95c84 = 1;
          do {
            (&DAT_01f95d40)[DAT_01fb8c80 * 0xf + DAT_01f95c84] =
                 *(undefined4 *)(&P0 + DAT_01f95c84 * 4);
            DAT_01f95c84 = DAT_01f95c84 + 1;
            local_14 = local_14 + -1;
          } while (0 < local_14);
          if (DAT_007d13a4 < 0) {
            P9 = DAT_007d13b4;
LAB_00415124:
            DAT_0078cd3c = 10;
            P13 = f_0;
            P14 = f_0;
            P15 = f_0;
LAB_00415153:
            DAT_007d13a4 = 0;
            do {
              DAT_01f95c84 = (&DAT_01f93fdc)[DAT_01f95c98];
              if (DAT_01f95c84 != 0) {
                if (DAT_007d13cc != DAT_01f95c84) goto LAB_004151c4;
                DAT_0078cd40 = DAT_007d13cc;
                if (DAT_007d13c4 <= DAT_01f95c98) {
                  if (DAT_0078cd3c == 10) break;
                  goto LAB_00414fb5;
                }
              }
              DAT_01f95c98 = DAT_01f95c98 + 1;
            } while( true );
          }
          ffree(in_ST0);
          in_ST0 = (float10)FUN_004156ec();
          goto LAB_00415577;
        }
        goto LAB_004155a2;
      }
LAB_00415543:
      if (DAT_0078cd30 != 0) {
        DAT_01fb8cc0 = 1;
        goto LAB_004155a2;
      }
    }
LAB_00415577:
    DAT_01f95c80 = DAT_01f95c80 + 1;
    if (DAT_01fb8cc0 <= DAT_01f95c80) {
LAB_004155a2:
      ffree(in_ST0);
      return;
    }
  } while( true );
LAB_004151c4:
  DAT_007d13b8 = (&DAT_01f93fdc)[DAT_01f95c98];
  DAT_01f95c9c = DAT_01f95c98;
  if (DAT_007d13c4 == DAT_01f95c98) {
LAB_004152cc:
    DAT_007d13b4 = f_0;
    DAT_007d13a8 = (float)(&DAT_01f95d4c)
                          [*(int *)(&DAT_01f995bc + (DAT_01f95c98 + _DAT_007d13d0) * 4) * 0xf];
    if (-1 < *(int *)(DAT_01f95c98 * 4 + 0x1f9416c)) {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_0054c669(&DAT_007d13b4,&DAT_007d13a8);
    }
    (&P1)[DAT_0078cd3c] = DAT_007d13b4;
    (&P2)[DAT_0078cd3c] = DAT_007d13a8;
  }
  else {
    DAT_01f95c84 = DAT_01f95c98;
    while (DAT_007d13c4 != DAT_01f95c9c) {
      DAT_01f95c9c = DAT_01f95c9c + 1;
      DAT_007d13c0 = (&DAT_01f93fdc)[DAT_01f95c9c];
      if (DAT_007d13c0 != 0) {
        if (DAT_007d13c0 <= DAT_007d13cc) {
          DAT_01f95c9c = DAT_01f95c84;
          if (DAT_01f95c84 == DAT_01f95c98) goto LAB_004152cc;
          break;
        }
        DAT_01f95c84 = DAT_01f95c9c;
        if (DAT_007d13c0 < DAT_007d13b8) {
          DAT_007d13b8 = DAT_007d13c0;
        }
      }
    }
    (&P1)[DAT_0078cd3c] =
         (float)(&DAT_01f95d4c)[*(int *)(&DAT_01f995bc + (DAT_01f95c98 + _DAT_007d13d0) * 4) * 0xf];
    (&P2)[DAT_0078cd3c] =
         (float)(&DAT_01f95d4c)[*(int *)(&DAT_01f995bc + (DAT_01f95c9c + _DAT_007d13d0) * 4) * 0xf];
  }
  *(float *)(&P0 + DAT_0078cd3c * 4) = (float)(DAT_0078cd40 * 9 + DAT_007d13b8);
  DAT_01f95c84 = DAT_01f95c98;
  DAT_0078cd40 = DAT_007d13b8;
  for (iVar3 = (DAT_01f95c9c - DAT_01f95c98) + 1; DAT_007d13b8 = DAT_0078cd40, 0 < iVar3;
      iVar3 = iVar3 + -1) {
    if (DAT_0078cd40 == (&DAT_01f93fdc)[DAT_01f95c84]) {
      (&DAT_01f93fdc)[DAT_01f95c84] = DAT_007d13cc;
    }
    DAT_01f95c84 = DAT_01f95c84 + 1;
    DAT_0078cd40 = DAT_007d13b8;
  }
  DAT_01f95c84 = DAT_01f95c98;
  for (iVar3 = (DAT_01f95c9c - DAT_01f95c98) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
    DAT_01f95c98 = DAT_01f95c84;
    if (DAT_0078cd40 < (int)(&DAT_01f93fdc)[DAT_01f95c84]) goto LAB_004154bb;
    DAT_01f95c84 = DAT_01f95c84 + 1;
  }
  DAT_01f95c98 = DAT_01f95c9c + 1;
LAB_004154bb:
  if (DAT_007d13c4 < DAT_01f95c98) goto LAB_00414fb5;
  if (DAT_0078cd3c != 10) goto LAB_00415508;
  DAT_0078cd3c = 0xd;
  goto LAB_00415153;
LAB_00415508:
  DAT_007d13a4 = -1;
  goto LAB_00414fb5;
}


