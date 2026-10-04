// FUN_004ebd10 @ 004ebd10 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ebd10(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffffc;
  thunk_FUN_0054c419(&DAT_01e9a9f4,&DAT_00766380);
  DAT_01e9dc1c = 0;
  DAT_01fbb770 = (int)ROUND(DAT_01fb8c60);
  _DAT_008d16c8 = DAT_01e67910 - f_0_001;
  _DAT_008d16c4 = DAT_01e67914 + f_0_001;
  DAT_008d16c0 = 0;
  DAT_01e99988 = -1;
  DAT_008d16bc = 1;
  DAT_01e99984 = 0;
  DAT_008d16b8 = 0;
  LOAD_I = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    load_item_header();
    if (DAT_01fbb770 == LOAD_STAFF) {
      if (_DAT_008d16c4 < LOAD_P3) break;
      if (LOAD_CODE < 3) {
        if (_DAT_008d16c8 <= LOAD_P3) {
          if (LOAD_LEN < 7) {
LAB_004ec2eb:
            DAT_008d16bc = 0xffffffff;
            FUN_005f33c9(&stack0xfffffffc,0x4ec314);
            FUN_005f34d1(puVar4,0x4ec32f);
            thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_00766340,&DAT_00766344,"(1i4)",5,&LOAD_I);
            thunk_FUN_0054d831(&DAT_020b90a0,0x200);
            FUN_005f33c9(puVar4,0x4ec39a);
            FUN_005f34d1(puVar4,0x4ec3b5);
            *(undefined4 *)(puVar4 + -0x9c) = 0;
            DAT_01e99980 = DAT_008d16bc;
            return;
          }
          fVar1 = *(float *)(&ITEM_P7 + LOAD_W * 4);
          if (fVar1 > 0.0 || fVar1 == 0.0) {
            if (fVar1 <= 0.0) goto LAB_004ec2eb;
            if (DAT_008d16b8 == 0) {
              _DAT_008d16b4 = LOAD_P3;
              DAT_008d16b8 = 1;
            }
            if (LOAD_CODE == 2) {
              DAT_008d16b0 = 0xffffffff;
              DAT_008d16ac = 0;
            }
            else {
              DAT_008d16b0 = (int)ROUND((float)(&ITEM_P5)[LOAD_W]);
              if (LOAD_LEN < 5) {
                DAT_008d16b0 = 0;
              }
              DAT_008d16ac = (&DAT_00794cbc)[DAT_008d16b0 % 10];
              DAT_008d16b0 = 0;
              if (3 < LOAD_LEN) {
                DAT_008d16b0 = (int)ROUND((float)(&ITEM_P4)[LOAD_W]);
              }
              (&DAT_01e99fc8)[DAT_008d16bc] = DAT_008d16b0 % 100;
              DAT_008d16b0 = 0;
            }
            goto LAB_004ec226;
          }
        }
      }
      else if (LOAD_CODE == 5) {
        if (((6 < LOAD_LEN) && (LOAD_LEN < 8 || *(float *)(&ITEM_P8 + LOAD_W * 4) <= f_0)) &&
           ((float)(&ITEM_P4)[LOAD_W] == (float)(&ITEM_P5)[LOAD_W])) {
          DAT_01e99984 = DAT_01e99984 + 1;
          (&DAT_01e9a928)[DAT_01e99984] = LOAD_I;
        }
      }
      else if (LOAD_CODE == 3) {
        DAT_008d16c0 = 0;
        if (4 < LOAD_LEN) {
          _DAT_008d16a8 = (float)(&ITEM_P5)[LOAD_W];
          DAT_008d16c0 = (int)ROUND(_DAT_008d16a8);
          if ((DAT_0078b378 == 0xf) && (_DAT_008d16a8 == f_0_8)) {
            DAT_008d16c0 = 4;
          }
        }
      }
      else if (LOAD_CODE == 0x11) {
        if (DAT_01e99988 < 0) {
          DAT_01e99988 = DAT_008d16b8;
        }
        DAT_008d16b0 = 2;
        DAT_008d16ac = 0;
        if (4 < LOAD_LEN) {
          DAT_008d16ac = (int)ROUND((float)(&ITEM_P5)[LOAD_W]);
        }
LAB_004ec226:
        *(int *)(DAT_008d16bc * 4 + 0x1e99ca8) = DAT_008d16ac;
        (&DAT_01e99988)[DAT_008d16bc] = LOAD_I;
        (&DAT_01e9a2e8)[DAT_008d16bc] = DAT_008d16c0;
        (&DAT_01e9a608)[DAT_008d16bc] = DAT_008d16b0;
        (&DAT_01e9dc94)[DAT_008d16bc] = LOAD_P3;
        DAT_008d16bc = DAT_008d16bc + 1;
      }
      else if ((LOAD_CODE == 6) && (6 < LOAD_LEN)) {
        DAT_01e9dc1c = 1;
      }
    }
    LOAD_I = LOAD_I + 1;
  }
  DAT_008d16bc = DAT_008d16bc + -1;
  if (DAT_008d16bc != 0) {
    DAT_008d16b8 = 0;
    LOAD_I = 1;
    iVar2 = ITEM_I;
    while ((0 < iVar2 && (load_item_header(), LOAD_STAFF <= DAT_01fbb770))) {
      if ((LOAD_P3 <= _DAT_008d16c4) && ((LOAD_CODE == 0xe && (_DAT_008d16b4 <= LOAD_P3)))) {
        DAT_008d16a4 = 1;
        if (3 < LOAD_LEN) {
          DAT_008d16a4 = (int)ROUND((float)(&ITEM_P4)[LOAD_W]);
        }
        if (DAT_008d16a4 == 0) {
          DAT_008d16a4 = 1;
        }
        if (DAT_01fbb770 - LOAD_STAFF < DAT_008d16a4) {
          if (DAT_008d16b8 != 0) {
            DAT_008d16a4 = 1;
            for (iVar3 = DAT_008d16b8; 0 < iVar3; iVar3 = iVar3 + -1) {
              if (LOAD_P3 == (float)(&DAT_01e9a9f0)[DAT_008d16a4]) goto LAB_004ec58a;
              DAT_008d16a4 = DAT_008d16a4 + 1;
            }
          }
          DAT_008d16b8 = DAT_008d16b8 + 1;
          (&DAT_01e9a9f0)[DAT_008d16b8] = LOAD_P3;
        }
      }
LAB_004ec58a:
      LOAD_I = LOAD_I + 1;
      iVar2 = iVar2 + -1;
    }
    if (DAT_008d16b8 != 0) {
      DAT_008d16a4 = 1;
      do {
        DAT_008d16a4 = DAT_008d16a4 + 1;
        while (((float)(&DAT_01e9a9f0)[DAT_008d16a4] <= (float)(&DAT_01e9a9ec)[DAT_008d16a4] &&
               (thunk_FUN_0054c669(&DAT_01e9a9f0 + DAT_008d16a4,&DAT_01e9a9ec + DAT_008d16a4),
               DAT_008d16a4 != 2))) {
          DAT_008d16a4 = DAT_008d16a4 + -1;
        }
      } while (DAT_008d16a4 < DAT_008d16b8);
      do {
        DAT_008d16b8 = DAT_008d16b8 + 1;
      } while ((float)(&DAT_01e9a9f0)[DAT_008d16b8] != f_0);
      (&DAT_01e9a9f0)[DAT_008d16b8] = f_9999;
      DAT_008d16a4 = 1;
      DAT_008d16a0 = 1;
      if (DAT_01e9a60c == 0) {
        DAT_01e9a60c = 1;
      }
      _DAT_008d16a8 = DAT_01e9a9f4;
      do {
        if ((_DAT_008d16a8 <= (float)(&DAT_01e9dc94)[DAT_008d16a0]) &&
           (DAT_008d169c = (&DAT_01e9a608)[DAT_008d16a0], -1 < DAT_008d169c)) {
          if (DAT_008d169c == 0) {
            (&DAT_01e9a608)[DAT_008d16a0] = 1;
            _DAT_008d16a8 = (float)(&DAT_01e9dc94)[DAT_008d16a0];
            DAT_008d169c = DAT_008d16a0;
            while ((DAT_008d169c = DAT_008d169c + 1, (&DAT_01e9a608)[DAT_008d169c] == 0 &&
                   (_DAT_008d16a8 == (float)(&DAT_01e9dc94)[DAT_008d169c]))) {
              (&DAT_01e9a608)[DAT_008d169c] = 1;
            }
          }
          do {
            DAT_008d16a4 = DAT_008d16a4 + 1;
            _DAT_008d16a8 = (float)(&DAT_01e9a9f0)[DAT_008d16a4];
            if (DAT_008d16b8 <= DAT_008d16a4) break;
          } while (_DAT_008d16a8 < (float)(&DAT_01e9dc94)[DAT_008d16a0]);
        }
        if (DAT_008d16bc == DAT_008d16a0) {
          DAT_01e99980 = DAT_008d16bc;
          return;
        }
        DAT_008d16a0 = DAT_008d16a0 + 1;
      } while( true );
    }
  }
  DAT_01e99980 = DAT_008d16bc;
  return;
}


