// FUN_0047c3e8 @ 0047c3e8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047c3e8(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  float10 in_ST0;
  float10 fVar4;
  unkbyte10 Var5;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined1 *puVar6;
  
  puVar6 = &stack0xfffffffc;
  DAT_01fbb770 = (int)ROUND(DAT_01fb8c60);
  DAT_01be12e4 = 0;
  DAT_01ba0b70 = 0;
  DAT_01ba0b74 = 0;
  DAT_01ba0b7c = 0;
  DAT_00828540 = 0;
  DAT_0082853c = 0;
  LOAD_I = 1;
  DAT_01e67940 = DAT_01e67910;
  DAT_01e67944 = DAT_01e67914;
  _DAT_01be12f4 = f_0;
  _DAT_01ba0ba8 = f_0;
  for (iVar3 = ITEM_I; 0 < iVar3; iVar3 = iVar3 + -1) {
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    if (((DAT_01fbb770 == LOAD_STAFF) && (DAT_01e67940 <= LOAD_P3)) && (LOAD_CODE != 0x10)) {
      if (DAT_01e67944 < LOAD_P3) break;
      if (LOAD_CODE == 6) {
        if (6 < LOAD_LEN) {
          if ((*(float *)(&ITEM_P7 + LOAD_W * 4) < f_0) ||
             (DAT_01ba0bac = (float)(&ITEM_P6)[LOAD_W], DAT_01e67944 < DAT_01ba0bac)) {
LAB_0047cba7:
            FUN_005f33c9(&stack0xfffffffc,0x47cbc5);
            Var5 = FUN_005f34d1(puVar6,0x47cbe0);
            ffree(Var5);
            Var5 = thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_00762440,&DAT_00762444,"(1i4)",5,
                                      &LOAD_I);
            ffree(Var5);
            in_ST0 = (float10)thunk_FUN_0054d831(&DAT_020b90a0,0x200);
            *(undefined4 *)(puVar6 + -0x108) = 0;
            goto LAB_0047dc8b;
          }
          DAT_01ba0b78 = 0;
          if (_DAT_01ba0ba8 != LOAD_P3) {
            DAT_0082853c = 0;
          }
          DAT_00828540 = DAT_00828540 + 1;
          DAT_00828538 = LOAD_I;
          if (DAT_0082853c != 0) {
            DAT_00828538 = -LOAD_I;
          }
          *(int *)(DAT_00828540 * 4 + 0x1b9e2bc) = DAT_00828538;
          *(int *)(DAT_00828540 * 4 + 0x1b9e44c) = LOAD_LEN;
          DAT_00828534 = 1;
          for (iVar2 = LOAD_LEN; 0 < iVar2; iVar2 = iVar2 + -1) {
            *(undefined4 *)(DAT_00828540 * 0x48 + DAT_00828534 * 4 + 0x1b9e594) =
                 (&ITEM_LEN)[DAT_00828534 + LOAD_W];
            DAT_00828534 = DAT_00828534 + 1;
          }
          DAT_0082853c = 1;
          DAT_00828538 = 1;
          _DAT_01ba0ba8 = LOAD_P3;
          for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
            DAT_00828534 = (&ITEM_PTR0)[DAT_00828538];
            if (((float)(&ITEM_P1)[DAT_00828534] == f_1) &&
               (LOAD_STAFF == (int)ROUND((float)(&ITEM_P2)[DAT_00828534]))) {
              DAT_01e6794c = f_0;
              if (f_3 <= (float)(&ITEM_LEN)[DAT_00828534]) {
                DAT_01e6794c = (float)(&ITEM_P3)[DAT_00828534];
              }
              if (ABS(DAT_01e6794c - LOAD_P3) <= f_0_01) {
                if (LOAD_P3 != DAT_01e6794c) {
                  (&ITEM_P3)[LOAD_W] = DAT_01e6794c;
                }
                if (DAT_01ba0b78 < 0x33) {
                  DAT_01ba0b78 = DAT_01ba0b78 + 1;
                }
              }
              else {
                if (f_0_01 < ABS(DAT_01e6794c - DAT_01ba0bac)) goto LAB_0047cacf;
                if (DAT_01ba0bac != DAT_01e6794c) {
                  (&ITEM_P6)[LOAD_W] = DAT_01e6794c;
                }
                if (DAT_01ba0b78 < 0x32) {
                  DAT_01ba0b78 = DAT_01ba0b78 + 0x32;
                }
              }
              DAT_01ba0ba0 = f_0;
              if (f_7 <= (float)(&ITEM_LEN)[DAT_00828534]) {
                DAT_01ba0ba0 = *(float *)(&ITEM_P7 + DAT_00828534 * 4);
              }
              if ((f_0_99 <= DAT_01ba0ba0) && (DAT_01ba0ba0 < f_64)) goto LAB_0047cba7;
              if (0x32 < DAT_01ba0b78) break;
            }
LAB_0047cacf:
            DAT_00828538 = DAT_00828538 + 1;
          }
          DAT_01ba0b70 = DAT_01ba0b70 + 1;
          (&DAT_01b9d63c)[DAT_01ba0b70] = LOAD_I;
        }
      }
      else {
        if (LOAD_CODE == 5) {
          if ((LOAD_LEN + -7 < 0) ||
             (((LOAD_LEN != 7 &&
               ((DAT_01ba0b90 = (int)ROUND(*(float *)(&ITEM_P8 + LOAD_W * 4)), DAT_01ba0b90 == 1 ||
                (DAT_01ba0b90 == 2)))) || (*(float *)(&ITEM_P7 + LOAD_W * 4) == f_0))))
          goto LAB_0047cb3c;
          DAT_01ba0b74 = DAT_01ba0b74 + 1;
          *(int *)(DAT_01ba0b74 * 4 + 0x1b9d7cc) = LOAD_I;
        }
        if (LOAD_CODE == 1) {
          if (99 < DAT_01be12e4) goto LAB_0047dc7c;
          if (9 < LOAD_LEN) {
            ffree(in_ST0);
            fVar4 = (float10)amod(&ITEM_P10 + LOAD_W * 4,&f_10);
            in_ST0 = extraout_ST1;
            if (fVar4 != (float10)f_0) {
              if ((DAT_01ba0b7c == 0) && (f_10 <= (float)(&ITEM_P5)[LOAD_W])) {
                DAT_01ba0b7c = 1;
              }
              goto LAB_0047cb3c;
            }
          }
          DAT_01be12e4 = DAT_01be12e4 + 1;
          *(float *)(DAT_01be12e4 * 4 + 0x1b9df9c) = LOAD_P3;
          *(int *)(DAT_01be12e4 * 4 + 0x1b9e12c) = LOAD_I;
        }
      }
    }
LAB_0047cb3c:
    LOAD_I = LOAD_I + 1;
  }
  if (DAT_01be12e4 != 0) {
    DAT_01ba0b80 = *param_1;
    if (DAT_01ba0b80 == 3) {
      DAT_01be12f0 = f_5020;
    }
    if (DAT_01ba0b80 == 4) {
      DAT_01be12f0 = f_5010;
    }
    DAT_01ba0b98 = 1;
    DAT_01ba0b78 = 0;
    DAT_01ba0b90 = 0;
    DAT_01ba0b8c = 0;
    DAT_01ba0b9c = -1;
    DAT_01be12e8 = 1;
    _DAT_01ba0ba8 = f_0;
    for (iVar3 = DAT_01be12e4; 0 < iVar3; iVar3 = iVar3 + -1) {
      DAT_01ba0b88 = 0;
      DAT_01ba0bac = f_0;
      while( true ) {
        DAT_00828530 = (&ITEM_PTR0)[*(int *)(DAT_01be12e8 * 4 + 0x1b9e12c)];
        DAT_01ba0b7c = (int)ROUND((float)(&ITEM_LEN)[DAT_00828530]);
        DAT_01e67940 = *(float *)(DAT_01be12e8 * 4 + 0x1b9df9c);
        if (DAT_01ba0b7c < 5) break;
        _DAT_0082852c = 0x404;
        if (100 < (int)ROUND((float)(&ITEM_P5)[DAT_00828530])) {
          _DAT_0082852c = 0x1b74;
        }
        DAT_01ba0b94 = (int)ROUND((float)(&ITEM_P5)[DAT_00828530]) % 100;
        if (9 < DAT_01ba0b94) {
          if ((DAT_01ba0b8c != 0) && (_DAT_01ba0ba8 == DAT_01e67940)) goto LAB_0047dc7c;
          DAT_01ba0b8c = 1;
          if (DAT_01ba0b80 < 3) {
            if ((DAT_01ba0b80 != 1) && (DAT_01ba0b80 == 2)) goto LAB_0047d0a8;
LAB_0047d063:
            DAT_01be12f0 = f_5010;
            if (DAT_01ba0b94 < 0x14) {
              DAT_01be12f0 = f_5020;
            }
          }
          else if (4 < DAT_01ba0b80) goto LAB_0047d063;
          DAT_01ba0b90 = DAT_01ba0b90 + 1;
          (&DAT_01fb8cc0)[DAT_01ba0b90] = (int)DAT_01be12f0;
LAB_0047d0a8:
          if ((10 < DAT_01ba0b7c) &&
             (DAT_01ba0ba4 = (int)ROUND(*(float *)(&ITEM_P11 + DAT_00828530 * 4)), DAT_01ba0ba4 != 0
             )) {
            DAT_01ba0b78 = DAT_01ba0b78 + 1;
            bVar1 = DAT_01ba0ba4 < 1;
            if (bVar1) {
              DAT_01ba0ba4 = -DAT_01ba0ba4;
            }
            DAT_01be12ec = (uint)bVar1;
            *(float *)(DAT_01ba0b78 * 4 + 0x1b9de0c) =
                 (float)(int)(DAT_01ba0ba4 * 10000 + DAT_01be12ec);
            *(int *)(DAT_01ba0b78 * 4 + 0x1b9dc7c) = DAT_01ba0b98;
          }
          goto LAB_0047d1b3;
        }
        if ((_DAT_01ba0ba8 == DAT_01e67940) ||
           (((5 < DAT_01ba0b7c &&
             (DAT_01be12ec = (uint)ROUND((float)(&ITEM_P6)[DAT_00828530]), 1 < (int)DAT_01be12ec))
            && (((int)DAT_01be12ec < 4 ||
                (DAT_01be12ec != 0x5f && (DAT_01be12ec != 0x8b && 10 < (int)DAT_01be12ec)))))))
        goto LAB_0047d0a8;
        DAT_01be12ec = DAT_01be12e8;
        do {
          do {
            DAT_01be12ec = DAT_01be12ec + 1;
            if ((DAT_01be12e4 < (int)DAT_01be12ec) ||
               (DAT_01ba0b7c = (&ITEM_PTR0)[*(int *)(DAT_01be12ec * 4 + 0x1b9e12c)],
               DAT_01e67940 != (float)(&ITEM_P3)[DAT_01ba0b7c])) goto LAB_0047dc7c;
          } while ((float)(&ITEM_LEN)[DAT_01ba0b7c] < f_5);
          ffree(in_ST0);
          fVar4 = (float10)amod(&ITEM_P5 + DAT_01ba0b7c,&f_100);
          in_ST0 = extraout_ST1_00;
        } while (fVar4 < (float10)f_10);
        ffree(extraout_ST1_00);
        in_ST0 = (float10)thunk_FUN_0054c68f(DAT_01be12ec * 4 + 0x1b9e12c,
                                             DAT_01be12e8 * 4 + 0x1b9e12c);
        _DAT_01ba0ba8 = f_0;
      }
      DAT_01ba0b94 = 0;
LAB_0047d1b3:
      DAT_01ba0b94 = DAT_01ba0b94 % 10;
      if (6 < DAT_01ba0b7c) {
        DAT_01ba0bac = *(float *)(&ITEM_P7 + DAT_00828530 * 4);
      }
      DAT_00828528 = (int)ROUND((float)(&ITEM_P4)[DAT_00828530]);
      if (DAT_01ba0bac < f_64) {
        iVar2 = DAT_00828528;
        if (DAT_00828528 < 0) {
          iVar2 = -DAT_00828528;
        }
        if (iVar2 < 100) {
          if (-1 < DAT_01ba0b9c) {
            DAT_01ba0ba0 = f_8000;
LAB_0047d2a8:
            DAT_01ba0b90 = DAT_01ba0b90 + 1;
            (&DAT_01fb8cc0)[DAT_01ba0b90] = (int)DAT_01ba0ba0;
            DAT_01ba0b9c = -DAT_01ba0b9c;
          }
        }
        else if (DAT_01ba0b9c < 1) {
          DAT_01ba0ba0 = f_8001;
          goto LAB_0047d2a8;
        }
      }
      DAT_01ba0b90 = DAT_01ba0b90 + 1;
      (&DAT_01fb8cc0)[DAT_01ba0b90] =
           (int)(float)(DAT_01ba0b94 * 100 + _DAT_0082852c + DAT_00828528 % 100);
      if (_DAT_01ba0ba8 == DAT_01e67940) {
        in_ST0 = (float10)(float)(&DAT_01fb8cc0)[DAT_01ba0b90];
        (&DAT_01fb8cc0)[DAT_01ba0b90] = (int)(float)-in_ST0;
        DAT_01ba0bac = f_0;
      }
      else {
        DAT_01ba0b8c = 0;
        if (8 < DAT_01ba0b7c) {
          DAT_01be12ec = (uint)ROUND(*(float *)(&ITEM_P9 + DAT_00828530 * 4));
          DAT_01ba0b88 = ((int)DAT_01be12ec % 100) / 10;
        }
        if (DAT_01ba0bac == f_0) goto LAB_0047dc7c;
        DAT_01ba0b98 = DAT_01ba0b98 + 1;
      }
      *(float *)(DAT_01be12e8 * 4 + 0x1b9d95c) = DAT_01ba0bac;
      *(int *)(DAT_01be12e8 * 4 + 0x1b9daec) = DAT_01ba0b88;
      DAT_01be12e8 = DAT_01be12e8 + 1;
      _DAT_01ba0ba8 = DAT_01e67940;
    }
    DAT_01be12e0 = 1;
    ffree(in_ST0);
    DAT_01fb8cc0 = DAT_01ba0b90;
    Var5 = thunk_FUN_0054cd13(&DAT_01f95d80,&DAT_00762424);
    ffree(Var5);
    Var5 = input_pitches();
    DAT_01be12e0 = 0;
    DAT_01ba0b84 = 0;
    DAT_01ba0ba4 = 1000;
    DAT_01be12e8 = 1;
    iVar3 = DAT_01be12e8;
    DAT_01be12e8 = DAT_01fb8c74;
    for (iVar2 = DAT_01be12e4; 0 < iVar2; iVar2 = iVar2 + -1) {
      DAT_01e67940 = *(float *)(iVar3 * 4 + 0x1b9d95c);
      if (f_64 < DAT_01e67940) {
        DAT_01e67940 = f_64;
      }
      DAT_01fb8c74 = DAT_01be12e8;
      if (DAT_01e67940 != f_0) {
        DAT_01ba0b84 = DAT_01ba0b84 + 1;
        (&DAT_01fb8cc0)[DAT_01ba0b84] =
             (int)((float)(*(int *)(iVar3 * 4 + 0x1b9daec) * DAT_01ba0ba4) + DAT_01e67940);
        DAT_01be12e8 = iVar3;
        iVar3 = DAT_01be12e8;
      }
      DAT_01be12e8 = iVar3;
      iVar3 = DAT_01be12e8 + 1;
      DAT_01be12e8 = DAT_01fb8c74;
    }
    DAT_01fb8c74 = 0;
    ffree(Var5);
    DAT_01fb8cc0 = DAT_01ba0b84;
    in_ST0 = (float10)input_rhythm_spacing();
    DAT_01fb8c74 = DAT_01be12e8;
    if (DAT_01ba0b78 != 0) {
      DAT_01ba0b90 = 0;
      DAT_01ba0b78 = DAT_01ba0b78 * 2;
      DAT_01be12e8 = 1;
      for (iVar3 = (DAT_01ba0b78 + 1) / 2; 0 < iVar3; iVar3 = iVar3 + -1) {
        DAT_01ba0b90 = DAT_01ba0b90 + 1;
        (&DAT_01fb8cc0)[DAT_01be12e8] = *(undefined4 *)(DAT_01ba0b90 * 4 + 0x1b9de0c);
        (&DAT_01fb8cc4)[DAT_01be12e8] = (float)*(int *)(DAT_01ba0b90 * 4 + 0x1b9dc7c);
        DAT_01be12e8 = DAT_01be12e8 + 2;
      }
      ffree(in_ST0);
      DAT_01fb8cc0 = DAT_01ba0b78;
      in_ST0 = (float10)thunk_FUN_004d8460();
    }
    if (DAT_01ba0b70 != 0) {
      DAT_01fbb700 = 4;
      ffree(in_ST0);
      Var5 = FUN_0047dc96(&DAT_01ba0b98,&DAT_01be12e4,&DAT_01ba0b70,&DAT_01b9d640);
      DAT_01be12ec = DAT_01fb8c80;
      ffree(Var5);
      Var5 = thunk_FUN_00413ca8();
      ffree(Var5);
      in_ST0 = (float10)FUN_0047e0a9(&DAT_01be12e4,&DAT_01ba0b70,&DAT_01b9d640);
      DAT_01ba0b70 = DAT_01fb8c80 - DAT_01be12ec;
    }
    if ((DAT_01ba0b74 != 0) && (*param_1 != 2)) {
      DAT_01fbb700 = 5;
      ffree(in_ST0);
      Var5 = FUN_0047dc96(&DAT_01ba0b98,&DAT_01be12e4,&DAT_01ba0b74,&DAT_01b9d7d0);
      ffree(Var5);
      Var5 = thunk_FUN_0053d1e0();
      DAT_01ba0b70 = DAT_01ba0b70 + DAT_01be12e4;
      ffree(Var5);
      in_ST0 = (float10)FUN_0047e0a9(&DAT_01ba0b70,&DAT_01ba0b74,&DAT_01b9d7d0);
    }
    DAT_01be12ec = 1;
    for (iVar3 = DAT_01be12e4; 0 < iVar3; iVar3 = iVar3 + -1) {
      DAT_00828530 = (&ITEM_PTR0)[*(int *)(DAT_01be12ec * 4 + 0x1b9e12c)];
      DAT_01ba0b94 = (int)ROUND((float)(&ITEM_LEN)[DAT_00828530]);
      if (DAT_01ba0b94 < 0xb) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_005239c9(DAT_01be12ec * 4 + 0x1b9e12c,&DAT_00762420);
      }
      *(undefined4 *)(&ITEM_P8 + DAT_00828530 * 4) = (&DAT_01f95d60)[DAT_01be12ec * 0xf];
      (&ITEM_P4)[DAT_00828530] = (&DAT_01f95d50)[DAT_01be12ec * 0xf];
      (&ITEM_P5)[DAT_00828530] = (&DAT_01f95d54)[DAT_01be12ec * 0xf];
      *(undefined4 *)(&ITEM_P10 + DAT_00828530 * 4) =
           *(undefined4 *)(&DAT_01f95d68 + DAT_01be12ec * 0x3c);
      *(undefined4 *)(&ITEM_P11 + DAT_00828530 * 4) =
           *(undefined4 *)(&DAT_01f95d6c + DAT_01be12ec * 0x3c);
      *(undefined4 *)(&ITEM_P9 + DAT_00828530 * 4) =
           *(undefined4 *)(&DAT_01f95d64 + DAT_01be12ec * 0x3c);
      DAT_01be12ec = DAT_01be12ec + 1;
    }
    if (DAT_01ba0b70 != 0) {
      DAT_01be12e8 = 0;
      while (DAT_01be12e8 = DAT_01be12e8 + 1, (int)DAT_01be12e8 < DAT_00828540) {
        while ((int)(&DAT_01b9e2c0)[DAT_01be12e8] < 1) {
          LOAD_I = *(int *)(DAT_01be12e8 * 4 + 0x1b9e2bc);
          LOAD_W = (&ITEM_PTR0)[LOAD_I];
          DAT_00828538 = (int)ROUND(*(float *)(&ITEM_P7 + LOAD_W * 4) / f_10);
          if (-1 < DAT_00828538) {
            DAT_01e67940 = (float)(&ITEM_P4)[LOAD_W];
            DAT_01e67944 = (float)(&ITEM_P5)[LOAD_W];
            goto LAB_0047da74;
          }
          while( true ) {
            DAT_01be12e8 = DAT_01be12e8 + 1;
            if (DAT_00828540 < (int)DAT_01be12e8) goto LAB_0047dc20;
            iVar3 = *(int *)(DAT_01be12e8 * 4 + 0x1b9e2bc);
            LOAD_I = -iVar3;
            if (LOAD_I < 0) break;
            LOAD_W = (&ITEM_PTR0)[-iVar3];
LAB_0047da74:
            DAT_01be12e4 = *(int *)(DAT_01be12e8 * 4 + 0x1b9e44c);
            if (6 < DAT_01be12e4) {
              DAT_00828530 = 1;
              for (iVar3 = DAT_01be12e4; 0 < iVar3; iVar3 = iVar3 + -1) {
                (&ITEM_LEN)[DAT_00828530 + LOAD_W] =
                     *(undefined4 *)(DAT_00828530 * 4 + DAT_01be12e8 * 0x48 + 0x1b9e594);
                DAT_00828530 = DAT_00828530 + 1;
              }
              DAT_00828534 = (int)ROUND(*(float *)(&ITEM_P7 + LOAD_W * 4));
              *(float *)(&ITEM_P7 + LOAD_W * 4) = (float)(DAT_00828534 % 10 + DAT_00828538 * 10);
              (&ITEM_P4)[LOAD_W] = DAT_01e67940;
              (&ITEM_P5)[LOAD_W] = DAT_01e67944;
            }
          }
        }
      }
LAB_0047dc20:
      P2 = DAT_01fb8c60;
      P3 = f_1;
      P4 = DAT_01fbb8b8;
      P5 = DAT_01fb8c60;
      DAT_00828524 = ITEM_I;
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_0040cde4(&DAT_01b9e130);
      ITEM_I = DAT_00828524;
    }
LAB_0047dc7c:
    DAT_01be12e4 = 0;
  }
LAB_0047dc8b:
  ffree(in_ST0);
  return;
}


