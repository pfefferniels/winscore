// FUN_0049b1d8 @ 0049b1d8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049b1d8(void)

{
  int iVar1;
  int iVar2;
  
  DAT_008388fc = DAT_01fbb860;
  DAT_008388f8 = DAT_01fbb864;
  if (DAT_01fbb864 < DAT_01fbb860) {
    DAT_008388f8 = DAT_01fbb860;
  }
  if ((DAT_01fbb860 == 1) && (MAX_STAFF < DAT_008388f8)) {
    DAT_008388fc = 9999;
  }
  DAT_020492a0 = 0;
  DAT_020492a4 = 0;
  _DAT_01b117c8 = DAT_01fbb868;
  _DAT_01b117cc = DAT_01fbb86c;
  if (DAT_01fbb86c == f_0) {
    _DAT_01b117cc = f_200;
  }
  if (_DAT_01b117cc < DAT_01fbb868) {
    thunk_FUN_0054c669(&DAT_01b117c8,&DAT_01b117cc);
  }
  _DAT_01b117c8 = _DAT_01b117c8 - f_0_001;
  _DAT_01b117cc = _DAT_01b117cc + f_0_001;
  DAT_008388f4 = DAT_01fbb87c;
  if (DAT_01fbb87c < 0) {
    DAT_008388f4 = -DAT_01fbb87c;
  }
  if (DAT_01fbb878 == 0) {
    DAT_01fbb878 = 1;
  }
  iVar1 = (DAT_008388f4 - DAT_01fbb878) + 1;
  LOAD_I = DAT_01fbb878;
  do {
    if (iVar1 < 1) {
      for (iVar1 = 1; iVar1 < 0x13; iVar1 = iVar1 + 1) {
        *(float *)(iVar1 * 4 + 0x1c5855c) = f_0;
      }
      return;
    }
    load_item_header();
    if (DAT_008388fc == 9999) {
LAB_0049b368:
      if (DAT_01fbb87c < 1) {
        if (((LOAD_CODE < 0x11) && (3 < LOAD_CODE)) && (LOAD_CODE != 0xe)) goto LAB_0049b9eb;
      }
      else if (DAT_01c58560 != f_0) {
        iVar2 = 0x11;
        DAT_01b117c0 = 2;
        do {
          if ((float)LOAD_CODE == *(float *)(DAT_01b117c0 * 4 + 0x1c5855c)) goto LAB_0049b47f;
          DAT_01b117c0 = DAT_01b117c0 + 1;
          iVar2 = iVar2 + -1;
        } while (0 < iVar2);
        if (((float)LOAD_CODE != DAT_01c58560) ||
           ((DAT_0078b4e4 == 0x57 && (f_m2 < (float)(&ITEM_P5)[LOAD_W])))) goto LAB_0049b9eb;
      }
LAB_0049b47f:
      DAT_00838900 = 0;
      if ((LOAD_P3 < _DAT_01b117c8) || (_DAT_01b117cc < LOAD_P3)) {
LAB_0049b5be:
        if (((5 < LOAD_LEN) && (3 < LOAD_CODE)) && (LOAD_CODE < 9)) {
          if ((DAT_00838900 == 0) && (DAT_01fbb874 == -0x43 || 0 < DAT_01fbb874)) goto LAB_0049b9eb;
          if ((LOAD_CODE == 8) && ((float)(&ITEM_P6)[LOAD_W] == f_0)) {
            (&ITEM_P6)[LOAD_W] = DAT_01fbb8b8;
          }
          if (((((LOAD_CODE != 4) || (LOAD_LEN < 7)) || (f_0 <= *(float *)(&ITEM_P7 + LOAD_W * 4)))
              || ((float)(&ITEM_P6)[LOAD_W] != f_0)) && (FUN_0049ba5b(&DAT_0076344c), 7 < LOAD_LEN))
          {
            if (LOAD_CODE == 4) {
              if (*(float *)(&ITEM_P7 + LOAD_W * 4) == f_100) {
                FUN_0049ba5b(&DAT_00763438);
                DAT_01b117d4 = 10;
                while ((DAT_01b117d4 <= LOAD_LEN &&
                       (FUN_0049ba5b(&DAT_01b117d4), DAT_01b117d4 != 0x10))) {
                  DAT_01b117d4 = DAT_01b117d4 + 2;
                }
              }
            }
            else if (5 < LOAD_CODE) {
              if (LOAD_CODE + -7 < 0) {
                if (10 < LOAD_LEN) {
                  if (f_0 < *(float *)(&ITEM_P11 + LOAD_W * 4)) {
                    FUN_0049ba5b(&DAT_00763448);
                  }
                  if ((f_0 <= *(float *)(&ITEM_P7 + LOAD_W * 4)) && (0xb < LOAD_LEN)) {
                    if (f_0 < *(float *)(&ITEM_P12 + LOAD_W * 4)) {
                      FUN_0049ba5b(&DAT_00763444);
                    }
                    if ((0xd < LOAD_LEN) && ((float)(&ITEM_P13)[LOAD_W] != f_0)) {
                      if (f_0 < *(float *)(&ITEM_P14 + LOAD_W * 4)) {
                        FUN_0049ba5b(&DAT_00763440);
                      }
                      if (0xe < LOAD_LEN) {
                        LOAD_LEN = 0xf;
                        goto LAB_0049b8d6;
                      }
                    }
                  }
                }
              }
              else if ((LOAD_CODE + -7 < 1) &&
                      (LOAD_CODE = (int)ROUND(*(float *)(&ITEM_P7 + LOAD_W * 4)), 0x13 < LOAD_CODE))
              {
                LOAD_LEN = 8;
LAB_0049b8d6:
                if (f_0 < (float)(&ITEM_LEN)[LOAD_LEN + LOAD_W]) {
                  FUN_0049ba5b(&LOAD_LEN);
                }
              }
            }
          }
        }
        if (DAT_00838900 == 0) goto LAB_0049b9eb;
      }
      else {
        DAT_00838900 = 1;
        if (DAT_020492a4 < DAT_0204e0c8) {
          DAT_020492a4 = DAT_020492a4 + 1;
        }
        if (DAT_01fbb874 == 0x44) {
          (&DAT_020492a4)[DAT_020492a4] = LOAD_I;
        }
        else {
          (&DAT_020492a4)[DAT_020492a4] = LOAD_W + 3;
          if (LOAD_LEN < 2) {
            thunk_FUN_005239c9(&LOAD_I,&DAT_00763458);
            (&ITEM_P2)[LOAD_W] = f_1;
            LOAD_LEN = 2;
          }
          if (DAT_01fbb874 != 1) {
            if (LOAD_LEN < 3) {
              thunk_FUN_005239c9(&LOAD_I,&DAT_00763450);
            }
            goto LAB_0049b5be;
          }
        }
      }
      if (DAT_020492a0 == 0) {
        DAT_020492a0 = LOAD_I;
      }
    }
    else if (DAT_008388fc <= LOAD_STAFF) {
      if (LOAD_STAFF <= DAT_008388f8) goto LAB_0049b368;
      if (DAT_01fbb87c < 1) {
        DAT_01fbb87c = LOAD_I + -1;
        return;
      }
    }
LAB_0049b9eb:
    LOAD_I = LOAD_I + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


