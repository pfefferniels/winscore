// FUN_0055b1f8 @ 0055b1f8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055b1f8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  unkbyte10 Var6;
  float10 fVar7;
  float10 extraout_ST1;
  undefined1 *puVar8;
  
  puVar8 = &stack0xfffffffc;
  if (ITEM_I < 2) goto LAB_0055c36a;
  DAT_01e9ad1c = 0;
  if (DAT_01ba0d40 == 0) {
    DAT_009a3d38 = 0;
    DAT_01ba0d48 = 0;
    _DAT_01b12d60 = 0;
    DAT_01b12d64 = 0;
  }
  if ((DAT_01fbb8a0 == 0) && ((DAT_02052740 != 0 || (P2 != f_0)))) {
    DAT_01fbb8d4 = (int)ROUND(P2);
    DAT_01fb8c60 = P3;
    DAT_01e67910 = P4;
    DAT_01e67914 = P5;
    if (P5 == f_0) {
      DAT_01e67914 = DAT_01fbb8b8;
    }
    if (P6 == f_0) {
      P6 = P3;
    }
    DAT_01c58604 = (int)ROUND((P6 - P3) + f_1);
    DAT_01b12d64 = (int)ROUND(P7);
    DAT_009a3d30 = (int)ROUND(P8);
    if (P8 != f_0) {
      DAT_009a3d38 = 1;
    }
    DAT_01ba0d48 = (uint)(P9 == f_0);
    _DAT_01b12d60 = (int)ROUND(P10);
    DAT_0078b4e4 = 0x58;
    ffree(in_ST0);
    Var6 = thunk_FUN_004f7808();
  }
  else {
    if (DAT_01ba0d40 == 0) {
      ffree(in_ST0);
      DAT_009a3d3c = thunk_FUN_00599e90(&DAT_01b12d68,&DAT_009a3d2c);
      in_ST0 = extraout_ST0;
      if (DAT_009a3d3c == 2) goto LAB_0055c36a;
      DAT_01ba0d5c = DAT_01b12d90;
      DAT_01ba0d48 = DAT_01b12d94;
      DAT_009a3d30 = DAT_01b12d9c;
      _DAT_01b12d60 = DAT_01b12da4;
      DAT_01b12d64 = DAT_01b12da0;
      DAT_01c58604 = (int)ROUND((P4 - P1) + f_1);
      DAT_01fb8c60 = P1;
    }
    else {
      DAT_01c58604 = 1;
      P2 = f_0;
      P3 = DAT_01fbb8b8;
      DAT_01fb8c60 = f_1;
    }
    DAT_009a3d38 = DAT_01b12d98;
    if (-1 < DAT_009a3d30) {
      DAT_009a3d38 = 1;
    }
    DAT_01fbb8d4 = DAT_01ba0d5c;
    DAT_0078b4e4 = 0x58;
    ffree(in_ST0);
    Var6 = thunk_FUN_004f7808();
    DAT_01e67910 = P2;
    DAT_01e67914 = P3;
    DAT_01e99988 = 0;
    if (P3 == f_0) {
      P3 = DAT_01fbb8b8;
    }
  }
  IP1 = (int)DAT_01e67910;
  IP2 = (int)DAT_01e67914;
  if (DAT_009a3d38 == 1) {
    _DAT_009a3d28 = DAT_009a3d30;
  }
  DAT_0078de00 = (int)ROUND(DAT_01fb8c60);
  ffree(Var6);
  DAT_009a3d24 = DAT_0078de00;
  Var6 = thunk_FUN_005725fa();
  iVar4 = DAT_01fbb8d4;
  DAT_020527a0 = 0xfffffffe;
  iVar3 = DAT_01fbb8d4;
  if (DAT_01fbb8d4 < 0) {
    iVar3 = -DAT_01fbb8d4;
  }
  if (iVar3 == 99) {
    ffree(Var6);
    Var6 = thunk_FUN_004ebd10();
    if (0 < DAT_01e99980) {
      if (DAT_01e99988 < 0) {
        DAT_01fbb8cc = 1;
        DAT_009a3d44 = 0;
        DAT_0078b4e0 = 0x45;
        DAT_009a3cdc = 1;
        for (iVar4 = DAT_01e99980; 0 < iVar4; iVar4 = iVar4 + -1) {
          DAT_009a3d20 = *(int *)(DAT_009a3cdc * 4 + 0x1e99ca8);
          iVar3 = DAT_009a3d44;
          if ((DAT_009a3d20 != 3) && (iVar3 = DAT_009a3d20, DAT_009a3d44 != 0)) {
            if (DAT_009a3d44 < 1) {
              iVar3 = DAT_009a3d44;
              if (0 < DAT_009a3d20) {
LAB_0055b7e5:
                ffree(Var6);
                Var6 = thunk_FUN_0054d831("*** Can\'t mix sharps and flats.",0x20);
                DAT_01fbb8cc = 0;
                goto LAB_0055c301;
              }
            }
            else {
              iVar3 = DAT_009a3d44;
              if (DAT_009a3d20 < 0) goto LAB_0055b7e5;
            }
          }
          DAT_009a3d44 = iVar3;
          DAT_009a3cdc = DAT_009a3cdc + 1;
        }
        if (DAT_009a3d44 < 0) {
          DAT_01e99988 = -1;
          DAT_01e9ad14 = 5;
        }
        else {
          if (DAT_009a3d44 < 1) {
            ffree(Var6);
            Var6 = thunk_FUN_0054d831(&DAT_00769c04,0x20);
            DAT_01fbb8cc = 0;
            goto LAB_0055c301;
          }
          DAT_01e99988 = 1;
          DAT_01e9ad14 = -5;
        }
        DAT_01e9ad20 = 0;
        _DAT_009a3d0c = (float)DAT_01e99988;
        DAT_009a3d20 = -1;
        goto LAB_0055b9e6;
      }
      ffree(Var6);
      Var6 = thunk_FUN_0054d831("*** No enharmonic change with key signature.",0x2d);
    }
  }
  else {
    DAT_01e9ad1c = DAT_01fbb8d4;
    DAT_009a3d20 = DAT_01fbb8d4 + 7;
    if (0xd < DAT_009a3d20) {
      DAT_009a3d20 = DAT_01fbb8d4 + -5;
    }
    if (0xd < DAT_009a3d20) {
      DAT_009a3d20 = DAT_009a3d20 + -0xc;
    }
    if (DAT_009a3d20 < 1) {
      DAT_009a3d20 = DAT_009a3d20 + 0xc;
    }
    if (DAT_009a3d20 < 1) {
      DAT_009a3d20 = DAT_009a3d20 + 0xc;
    }
    DAT_01e9ad14 = *(int *)(&DAT_0079f26c + DAT_009a3d20 * 4);
    DAT_009a3d20 = DAT_01fbb8d4;
    if (DAT_01fbb8d4 < 0) {
      DAT_009a3d20 = -DAT_01fbb8d4;
    }
    iVar3 = DAT_009a3d20 % 0xc;
    DAT_01fbb8c8 = *(int *)(&DAT_0079f240 + iVar3 * 4);
    if (0xb < DAT_009a3d20) {
      DAT_01fbb8c8 = DAT_01fbb8c8 + 7;
    }
    if (0x17 < DAT_009a3d20) {
      DAT_01fbb8c8 = DAT_01fbb8c8 + 7;
    }
    bVar5 = DAT_01fbb8d4 < 0;
    DAT_01fbb8d4 = iVar3;
    if (bVar5) {
      DAT_01fbb8d4 = -iVar3;
    }
    DAT_009a3d1c = DAT_01fbb8d4;
    if (iVar4 < 0) {
      DAT_01fbb8c8 = -DAT_01fbb8c8;
    }
    DAT_01e9ad20 = DAT_01fbb8c8;
LAB_0055b9e6:
    DAT_009a3d14 = 1;
    DAT_009a3d18 = DAT_01fbb8d4;
    iVar4 = DAT_009a3d10;
    DAT_009a3d10 = DAT_01e99988;
    for (iVar3 = DAT_01c58604; iVar1 = DAT_01c58604, iVar2 = DAT_0078de00,
        DAT_01e99988 = DAT_009a3d10, 0 < iVar3; iVar3 = iVar3 + -1) {
      DAT_01e9ad18 = 0;
      IP2 = (int)(DAT_01fbb8b8 + f_0_01);
      ffree(Var6);
      DAT_01fbb8d4 = DAT_009a3d18;
      IP1 = (int)f_0;
      Var6 = thunk_FUN_004ebd10();
      if (DAT_01fbb8d4 == 99) {
        DAT_01e99988 = DAT_009a3d10;
      }
      if (0 < DAT_01e99980) {
        for (iVar4 = 1; iVar4 < 0xc9; iVar4 = iVar4 + 1) {
          (&DAT_009a3d44)[iVar4] = (&DAT_01e99988)[iVar4];
        }
        ffree(Var6);
        Var6 = FUN_0055c373(&DAT_00769bfc,&DAT_009a3d24,&DAT_009a3d48);
        DAT_01ba0bf8 = DAT_009a3d24;
        if (DAT_009a3d38 != 0) {
          ffree(Var6);
          Var6 = thunk_FUN_005611da(&DAT_009a3d28);
        }
        if ((DAT_01b12d64 != 0) && (DAT_009a3d1c != 0)) {
          LOAD_I = 1;
          for (iVar4 = ITEM_I; 0 < iVar4; iVar4 = iVar4 + -1) {
            ffree(Var6);
            Var6 = load_item_header();
            if (DAT_009a3d24 == LOAD_STAFF) {
              if (LOAD_CODE < 3) break;
              if (LOAD_CODE == 0x11) goto LAB_0055bc0c;
            }
            LOAD_I = LOAD_I + 1;
          }
          ffree(Var6);
          Var6 = thunk_FUN_00562cc6(&DAT_00769bf8,&DAT_01e9ad1c,&DAT_009a3d20,&DAT_01e9ad20);
          ffree(Var6);
          Var6 = thunk_FUN_004ec885(&DAT_009a3d20,&DAT_01e9a2ec);
          DAT_01e9ad18 = DAT_009a3d20;
          DAT_01e9ad14 = DAT_009a3d20;
        }
LAB_0055bc0c:
        DAT_01e9dc18 = 0;
        DAT_009a3d20 = 0;
        _DAT_009a3d0c = (float)DAT_01e9ad20;
        DAT_01fbb8c8 = DAT_01e99984;
        ffree(Var6);
        fVar7 = (float10)thunk_FUN_00561b90(&DAT_01b12d60);
        if (DAT_0078b4e0 != 0x45) {
          if ((DAT_009a3d08 != 0x45) && (DAT_009a3d1c % 0xc != 0)) {
            DAT_01fbb8d4 = 0;
            LOAD_I = 1;
            for (iVar4 = ITEM_I; 0 < iVar4; iVar4 = iVar4 + -1) {
              ffree(fVar7);
              fVar7 = (float10)load_item_header();
              if ((((6 < LOAD_LEN) && (LOAD_CODE == 0xc)) && (LOAD_STAFF == DAT_009a3d24)) &&
                 (((float)(&ITEM_P5)[LOAD_W] < f_0 && (*(float *)(&ITEM_P7 + LOAD_W * 4) != f_0))))
              {
                DAT_009a3d44 = (int)ROUND(*(float *)(&ITEM_P7 + LOAD_W * 4));
                LOAD_STAFF = *(int *)(&DAT_0079f1e0 + (DAT_009a3d44 / 10) * 4);
                LOAD_LEN = DAT_009a3d44 % 10;
                if (LOAD_LEN == 2) {
                  LOAD_LEN = -1;
                }
                LOAD_LEN = ((LOAD_STAFF - LOAD_LEN) + DAT_009a3d1c) % 0xc;
                if (LOAD_LEN < 1) {
                  LOAD_LEN = LOAD_LEN + 0xc;
                }
                *(float *)(&ITEM_P7 + LOAD_W * 4) = (float)*(int *)(&DAT_0079f1b0 + LOAD_LEN * 4);
                if ((DAT_01fbb8d4 == 0) && (f_m2 <= (float)(&ITEM_P5)[LOAD_W])) {
                  DAT_01fbb8d4 = 1;
                  ffree(fVar7);
                  fVar7 = (float10)thunk_FUN_0054d831(&DAT_00769ba4,0x4d);
                }
              }
              LOAD_I = LOAD_I + 1;
            }
          }
          DAT_0078b4e0 = 0;
          if (DAT_01ba0d48 == 0) {
            DAT_0078b4e0 = 0x4e;
          }
        }
        if ((DAT_01fbb8c8 != 0) || (DAT_01e9dc1c != 0)) {
          DAT_009a3d04 = (int)ROUND(DAT_01e67910 - f_0_5);
          DAT_009a3d00 = (int)ROUND(DAT_01e67914 + f_0_5);
          LOAD_I = 1;
          for (iVar4 = ITEM_I; 0 < iVar4; iVar4 = iVar4 + -1) {
            ffree(fVar7);
            fVar7 = (float10)load_item_header();
            if ((((LOAD_STAFF == DAT_009a3d24) && (LOAD_CODE == 6)) && (5 < LOAD_LEN)) &&
               ((DAT_01fbb8d4 = (int)ROUND(LOAD_P3), DAT_01fbb8d4 <= DAT_009a3d00 &&
                (DAT_01fbb8d4 = (int)ROUND((float)(&ITEM_P6)[LOAD_W]), DAT_009a3d04 <= DAT_01fbb8d4)
                ))) {
              (&ITEM_P5)[LOAD_W] = _DAT_009a3d0c + (float)(&ITEM_P5)[LOAD_W];
              DAT_01fbb8c4 = (float)(&ITEM_P4)[LOAD_W];
              fVar7 = (float10)DAT_01fbb8c4;
              if ((float10)f_100 <= ABS(fVar7)) {
                ffree(fVar7);
                fVar7 = (float10)amod(&DAT_01fbb8c4,&f_100);
                _DAT_01fbb8c0 = (float)(fVar7 + (float10)_DAT_009a3d0c);
                DAT_01fbb8c4 = f_100;
                fVar7 = extraout_ST1;
                if (_DAT_01fbb8c0 < f_0) {
                  fVar7 = (float10)f_100;
                  DAT_01fbb8c4 = (float)-fVar7;
                }
                DAT_01fbb8c4 = _DAT_01fbb8c0 + DAT_01fbb8c4;
              }
              else {
                DAT_01fbb8c4 = _DAT_009a3d0c + DAT_01fbb8c4;
              }
              (&ITEM_P4)[LOAD_W] = DAT_01fbb8c4;
            }
            LOAD_I = LOAD_I + 1;
          }
        }
        if (DAT_0078b4e0 != 0x4e) {
          DAT_009a3cfc = DAT_01e99980;
          ffree(fVar7);
          fVar7 = (float10)thunk_FUN_0047c3e8(&DAT_00769b98);
          DAT_01e99980 = DAT_009a3cfc;
        }
        ffree(fVar7);
        Var6 = FUN_0055c373(&DAT_00769b98,&DAT_009a3d24,&DAT_009a3d48);
      }
      DAT_009a3d24 = DAT_009a3d24 + 1;
      DAT_01fb8c60 = (float)DAT_009a3d24;
      DAT_009a3d14 = DAT_009a3d14 + 1;
      iVar4 = DAT_009a3d10;
      DAT_009a3d10 = DAT_01e99988;
      DAT_01fbb8d4 = DAT_009a3d1c;
    }
    for (; DAT_009a3d10 = iVar4, DAT_009a3d14 = iVar2, 0 < iVar1; iVar1 = iVar1 + -1) {
      ffree(Var6);
      _DAT_009a3ce0 = f_200;
      _DAT_009a3ce4 = f_0;
      Var6 = thunk_FUN_004b80b7(&DAT_009a3d14,&DAT_009a3d14,&DAT_009a3ce4,&DAT_009a3ce0);
      iVar2 = DAT_009a3d14 + 1;
      iVar4 = DAT_009a3d10;
    }
  }
LAB_0055c301:
  ffree(Var6);
  Var6 = FUN_0055e50b();
  ffree(Var6);
  draw_items();
  FUN_005f33c9(&stack0xfffffffc,0x55c33b);
  in_ST0 = FUN_005f34d1(puVar8,0x55c356);
  DAT_0078b4e0 = 0;
  DAT_01fbb700 = 0;
LAB_0055c36a:
  ffree(in_ST0);
  return;
}


