// FUN_005077a2 @ 005077a2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005077a2(void)

{
  undefined1 *puVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 in_FPUControlWord;
  undefined2 uVar5;
  float10 in_ST0;
  unkbyte10 Var6;
  float10 fVar7;
  float10 in_ST1;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  unkbyte10 extraout_ST1_05;
  float10 extraout_ST1_06;
  float10 extraout_ST1_07;
  float10 extraout_ST1_08;
  float10 extraout_ST1_09;
  float10 extraout_ST1_10;
  float10 extraout_ST1_11;
  float10 in_ST2;
  float10 in_ST3;
  float10 in_ST4;
  float10 in_ST5;
  float10 in_ST6;
  
  puVar4 = &stack0xfffffffc;
  DAT_0094037c = 1;
  DAT_00940378 = 0x14;
  _DAT_00940374 = 0;
  DAT_00940370 = 0;
  DAT_01b34584 = 0;
  for (iVar3 = 1; iVar3 < 0x2711; iVar3 = iVar3 + 1) {
    *(undefined1 *)((int)&DAT_01b408d8 + iVar3 + 3) = 0;
  }
  DAT_0094036c = 1;
  do {
    DAT_01b9d5c4 = *(int *)(DAT_01b34580 * 0x40 + DAT_0094036c * 4 + 0x1f9393c);
    if (DAT_01b9d5c4 == 0) {
      *(undefined4 *)(puVar4 + -0x84) = 0;
    }
    else {
      *(int *)(puVar4 + -0x80) = ITEM_I;
      LOAD_I = 1;
      iVar3 = ITEM_I;
      while (0 < iVar3) {
        ffree(in_ST1);
        ffree(in_ST0);
        in_ST0 = (float10)load_item_header();
        in_ST1 = extraout_ST1;
        if (LOAD_STAFF < DAT_01b9d5c4) {
          *(undefined4 *)(puVar4 + -0x7c) = 0;
        }
        else {
          if (DAT_01b9d5c4 < LOAD_STAFF) {
            *(undefined4 *)(puVar4 + -0x78) = 0;
            break;
          }
          *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
          *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
          *(int *)(puVar4 + -0xac) = (int)ROUND(LOAD_P3 * f_2);
          in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
          DAT_00940368 = *(int *)(puVar4 + -0xac);
          if ((DAT_01b2a160 < DAT_0094037c) ||
             (DAT_00940368 < (&DAT_01b2a160)[DAT_0094037c] - DAT_00940370)) {
            *(undefined4 *)(puVar4 + -0x74) = 0;
          }
          else {
            if ((DAT_01b34584 == 0) || (*(char *)((int)&DAT_01b34588 + DAT_01b34584 + 3) == '\x0e'))
            {
              *(undefined4 *)(puVar4 + -0x70) = 0;
            }
            else {
              puVar1 = &DAT_01b3458c + DAT_01b34584;
              DAT_01b34584 = DAT_01b34584 + 1;
              *puVar1 = 0xe;
              *(int *)(&DAT_01b36c98 + DAT_01b34584 * 4) = (&DAT_01b2a160)[DAT_0094037c];
            }
            DAT_0094037c = DAT_0094037c + 1;
          }
          if (2 < LOAD_CODE) {
            *(undefined4 *)(puVar4 + -0x6c) = 0;
            if (LOAD_CODE == 3) {
              ffree(extraout_ST1);
              ffree(in_ST0);
              in_ST0 = (float10)FUN_00508616(&DAT_00940378,&LOAD_LEN,&ITEM_P5 + LOAD_W);
              *(undefined4 *)(puVar4 + -0x30) = 0;
              in_ST1 = extraout_ST1_01;
            }
            else {
              *(undefined4 *)(puVar4 + -0x34) = 0;
              if (LOAD_CODE == 5) {
                if ((LOAD_LEN < 8) || (*(float *)(&ITEM_P8 + LOAD_W * 4) < f_1)) {
                  ffree(extraout_ST1);
                  ffree(in_ST0);
                  in_ST1 = in_ST2;
                  in_ST2 = in_ST3;
                  in_ST3 = in_ST4;
                  in_ST4 = in_ST5;
                  in_ST5 = in_ST6;
                  in_ST0 = (float10)amod(&ITEM_P4 + LOAD_W,&DAT_00766f94);
                  *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
                  *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
                  *(int *)(puVar4 + -0xac) = (int)ROUND((float10)DAT_00940378 + in_ST0);
                  _DAT_00940358 = *(undefined4 *)(puVar4 + -0xac);
                  fVar2 = (float)(&ITEM_P5)[LOAD_W];
                  *(undefined2 *)(puVar4 + -0xb0) = *(undefined2 *)(puVar4 + -0xb0);
                  *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
                  *(int *)(puVar4 + -0xac) = (int)ROUND((float)DAT_00940378 + fVar2);
                  in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
                  _DAT_0094035c = *(int *)(puVar4 + -0xac);
LAB_00507bf6:
                  ffree(in_ST1);
                  ffree(in_ST0);
                  fVar7 = (float10)anint(puVar4,0x507c1a);
                  *(int *)(puVar4 + -0xac) = (int)ROUND(fVar7);
                  *(int *)(puVar4 + -0xac) = DAT_00940370 + *(int *)(puVar4 + -0xac);
                  DAT_00940364 = (float)*(int *)(puVar4 + -0xac);
                  *(undefined4 *)(puVar4 + -0x24) = 0;
                  in_ST0 = extraout_ST1_00;
                  goto LAB_005082e3;
                }
                *(undefined4 *)(puVar4 + -0x28) = 0;
              }
              else {
                *(undefined4 *)(puVar4 + -0x2c) = 0;
                if (LOAD_CODE == 7) {
                  if (LOAD_LEN < 7) {
                    *(undefined4 *)(puVar4 + -0x1c) = 0;
                  }
                  else {
                    fVar2 = *(float *)(&ITEM_P7 + LOAD_W * 4);
                    *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
                    *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
                    *(int *)(puVar4 + -0xac) = (int)ROUND(fVar2);
                    in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
                    _DAT_0094035c = *(int *)(puVar4 + -0xac);
                    if (_DAT_0094035c == 0x9b) {
                      _DAT_0094035c = 0xf;
                    }
                    if ((_DAT_0094035c % 8 == 0) || (_DAT_0094035c == 0xf)) {
                      _DAT_00940358 = 0;
                      *(undefined4 *)(puVar4 + -0x14) = 0;
                      goto LAB_00507bf6;
                    }
                    *(undefined4 *)(puVar4 + -0x18) = 0;
                  }
                }
                else {
                  *(undefined4 *)(puVar4 + -0x20) = 0;
                  if (LOAD_CODE == 0x11) {
                    _DAT_0094035c = 0;
                    if (4 < LOAD_LEN) {
                      fVar2 = (float)(&ITEM_P5)[LOAD_W];
                      *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
                      *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
                      *(int *)(puVar4 + -0xac) = (int)ROUND(fVar2);
                      in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
                      _DAT_0094035c = *(int *)(puVar4 + -0xac);
                    }
                    iVar3 = _DAT_0094035c;
                    if (_DAT_0094035c < 0) {
                      iVar3 = -_DAT_0094035c;
                    }
                    if (99 < iVar3) {
                      DAT_00940368 = 100;
                    }
                    _DAT_00940358 = 0;
                    DAT_00940364 = f_0;
                    goto LAB_005082e3;
                  }
                  *(undefined4 *)(puVar4 + -0x10) = 0;
                }
              }
            }
            goto LAB_0050837e;
          }
          DAT_00940364 = *(float *)(&ITEM_P7 + LOAD_W * 4);
          fVar7 = in_ST6;
          if ((LOAD_LEN < 7) || (DAT_00940364 <= f_0)) {
            if (DAT_00940364 < f_0) {
              *(undefined4 *)(puVar4 + -100) = 0;
              goto LAB_0050837e;
            }
            FUN_005f33c9(puVar4,0x507d00);
            Var6 = FUN_005f34d1(puVar4,0x507d1b);
            *(undefined4 *)(puVar4 + -0xa8) = 0;
            *(undefined4 *)(puVar4 + -0xb8) = 5;
            *(undefined4 *)(puVar4 + -0xb4) = 0x20b90b9;
            *(int **)(puVar4 + -0xb0) = &LOAD_I;
            ffree(extraout_ST1_02);
            ffree(Var6);
            Var6 = FUN_005f34f0(puVar4 + -0xa8,0x784ff00,&DAT_00766f34,puVar4 + -0xb8,&DAT_007956c8)
            ;
            *(undefined4 *)(puVar4 + -0xa8) = 0;
            *(undefined4 *)(puVar4 + -0xb8) = 3;
            *(undefined1 **)(puVar4 + -0xb4) = &DAT_020b90c7;
            *(int **)(puVar4 + -0xb0) = &LOAD_STAFF;
            ffree(extraout_ST1_03);
            ffree(Var6);
            Var6 = FUN_005f34f0(puVar4 + -0xa8,0x784ff00,&DAT_00766f34,puVar4 + -0xb8,&DAT_007956dc)
            ;
            *(undefined4 *)(puVar4 + -0xa8) = 0;
            *(undefined4 *)(puVar4 + -0xb8) = 6;
            *(undefined **)(puVar4 + -0xb4) = &DAT_020b90d2;
            *(float **)(puVar4 + -0xb0) = &LOAD_P3;
            ffree(extraout_ST1_04);
            ffree(Var6);
            Var6 = FUN_005f34f0(puVar4 + -0xa8,0x784ff00,&DAT_00766f2c,puVar4 + -0xb8,&DAT_007956f0)
            ;
            ffree(extraout_ST1_05);
            ffree(Var6);
            in_ST0 = (float10)thunk_FUN_0054d831(&DAT_020b90a0,0x200);
            DAT_00940364 = f_4;
            in_ST1 = extraout_ST1_06;
            if (LOAD_CODE == 2) {
              *(undefined4 *)(puVar4 + -0x54) = 0;
              if (LOAD_LEN < 5) {
                *(undefined4 *)(puVar4 + -0x40) = 0;
              }
              else {
                _DAT_00940360 = (float)(&ITEM_P5)[LOAD_W];
                if (f_0 <= _DAT_00940360) {
                  ffree(extraout_ST1_06);
                  fVar7 = (float10)FUN_006033ff(puVar4,0x507ef6);
                  DAT_00940364 = (float)((float10)f_1 / fVar7);
                  in_ST0 = extraout_ST1_08;
                  fVar7 = in_ST6;
                }
                else {
                  in_ST1 = -(float10)_DAT_00940360;
                  ffree(in_ST1);
                  fVar7 = (float10)FUN_006033ff(puVar4,0x507ec7);
                  DAT_00940364 = (float)fVar7;
                  in_ST0 = extraout_ST1_07;
                  fVar7 = in_ST6;
                }
              }
            }
            else {
              if (LOAD_LEN < 6) {
                *(undefined4 *)(puVar4 + -0x50) = 0;
              }
              else {
                fVar2 = (float)(&ITEM_P6)[LOAD_W];
                *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
                *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
                *(int *)(puVar4 + -0xac) = (int)ROUND(fVar2);
                in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
                DAT_00940368 = *(int *)(puVar4 + -0xac);
                if (DAT_00940368 == 0) {
                  *(undefined4 *)(puVar4 + -0x4c) = 0;
                  fVar7 = in_ST6;
                }
                else {
                  if (DAT_00940368 == 1) {
                    DAT_00940364 = f_2;
                  }
                  if (DAT_00940368 == 2) {
                    DAT_00940364 = f_4;
                  }
                  fVar7 = in_ST6;
                  if (DAT_00940368 == 3) {
                    DAT_00940364 = f_8;
                  }
                }
              }
              if (LOAD_LEN < 9) {
                *(undefined4 *)(puVar4 + -0x48) = 0;
              }
              else {
                fVar2 = *(float *)(&ITEM_P9 + LOAD_W * 4);
                *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
                *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
                *(int *)(puVar4 + -0xac) = (int)ROUND(fVar2);
                in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
                iVar3 = *(int *)(puVar4 + -0xac);
                *(int *)(puVar4 + -0xac) = iVar3 % 10;
                _DAT_00940360 = (float)*(int *)(puVar4 + -0xac) * f_2;
                if (_DAT_00940360 == f_0) {
                  _DAT_00940360 = f_1;
                }
                DAT_00940368 = (iVar3 % 100) / 10;
                _DAT_00940360 = f_1 / _DAT_00940360;
                DAT_00940364 = _DAT_00940360;
                if (DAT_00940368 != 0) {
                  DAT_00940364 = _DAT_00940360 / f_2 + _DAT_00940360;
                }
                if (1 < DAT_00940368) {
                  DAT_00940364 = _DAT_00940360 / f_4 + DAT_00940364;
                }
                *(undefined4 *)(puVar4 + -0x44) = 0;
                fVar7 = in_ST6;
              }
            }
          }
          else {
            *(undefined4 *)(puVar4 + -0x68) = 0;
          }
          if (LOAD_CODE == 2) {
            _DAT_0094035c = 0;
            _DAT_00940358 = 0;
LAB_005082d3:
            *(undefined4 *)(puVar4 + -0x38) = 0;
          }
          else {
            DAT_00940368 = DAT_00940378;
            if ((0xb < LOAD_LEN) && (fVar7 = in_ST6, *(float *)(&ITEM_P12 + LOAD_W * 4) != f_0)) {
              ffree(in_ST1);
              ffree(in_ST0);
              in_ST0 = (float10)FUN_00508477(&DAT_00940368);
              in_ST1 = extraout_ST1_09;
            }
            ffree(in_ST1);
            ffree(in_ST0);
            in_ST1 = in_ST3;
            in_ST3 = in_ST5;
            in_ST5 = fVar7;
            fVar7 = (float10)amod(&ITEM_P4 + LOAD_W,&DAT_00766f94);
            *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
            *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
            *(int *)(puVar4 + -0xac) = (int)ROUND((float10)DAT_00940368 + fVar7);
            uVar5 = *(undefined2 *)(puVar4 + -0xb0);
            _DAT_00940358 = *(undefined4 *)(puVar4 + -0xac);
            ffree(in_ST2);
            ffree(fVar7);
            in_ST2 = in_ST4;
            in_ST4 = in_ST6;
            in_ST6 = in_ST5;
            fVar7 = (float10)amod(&ITEM_P5 + LOAD_W,&DAT_00766f20);
            *(undefined2 *)(puVar4 + -0xb0) = uVar5;
            *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
            *(int *)(puVar4 + -0xac) = (int)ROUND(fVar7);
            in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
            _DAT_0094035c = *(int *)(puVar4 + -0xac);
            if (LOAD_LEN < 5) {
              _DAT_0094035c = 0;
            }
            in_ST0 = extraout_ST1_10;
            if ((10 < LOAD_LEN) && (*(float *)(&ITEM_P7 + LOAD_W * 4) < f_64)) {
              fVar2 = *(float *)(&ITEM_P11 + LOAD_W * 4);
              *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
              *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
              *(int *)(puVar4 + -0xac) = (int)ROUND(fVar2);
              in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
              DAT_00940368 = *(int *)(puVar4 + -0xac);
              if (DAT_00940368 < 0) {
                DAT_00940368 = -DAT_00940368;
              }
              if ((DAT_00940368 == 0x13) || (DAT_00940368 < 10 && 6 < DAT_00940368)) {
                _DAT_0094035c = _DAT_0094035c + 100;
              }
              goto LAB_005082d3;
            }
            *(undefined4 *)(puVar4 + -0x3c) = 0;
          }
LAB_005082e3:
          puVar1 = &DAT_01b42fec + DAT_01b34584;
          DAT_01b34584 = DAT_01b34584 + 1;
          *puVar1 = DAT_0094035c;
          *(undefined1 *)((int)&DAT_01b408d8 + DAT_01b34584 + 3) = DAT_00940358;
          *(float *)(&DAT_01b456f8 + DAT_01b34584 * 4) = DAT_00940364;
          *(undefined1 *)((int)&DAT_01b34588 + DAT_01b34584 + 3) = (undefined1)LOAD_CODE;
          iVar3 = DAT_01b34584 * 4;
          ffree(in_ST1);
          ffree(in_ST0);
          fVar7 = (float10)anint(puVar4,0x50835f);
          *(int *)(puVar4 + -0xac) = (int)ROUND(fVar7);
          *(int *)(&DAT_01b36c98 + iVar3) = DAT_00940370 + *(int *)(puVar4 + -0xac);
          in_ST0 = extraout_ST1_11;
        }
LAB_0050837e:
        *(undefined4 *)(puVar4 + -0xc) = 0;
        LOAD_I = LOAD_I + 1;
        *(int *)(puVar4 + -0x80) = *(int *)(puVar4 + -0x80) + -1;
        iVar3 = *(int *)(puVar4 + -0x80);
      }
      DAT_00940370 = DAT_00940370 + 400;
    }
    *(undefined4 *)(puVar4 + -8) = 0;
    DAT_0094036c = DAT_0094036c + 1;
    *(int *)(puVar4 + -0x88) = *(int *)(puVar4 + -0x88) + -1;
    if (*(int *)(puVar4 + -0x88) < 1) {
      while( true ) {
        puVar1 = &DAT_01b42fec + DAT_01b34584;
        DAT_01b34584 = DAT_01b34584 + 1;
        *puVar1 = 0;
        *(undefined1 *)((int)&DAT_01b408d8 + DAT_01b34584 + 3) = 0;
        *(float *)(&DAT_01b456f8 + DAT_01b34584 * 4) = f_0;
        *(undefined1 *)((int)&DAT_01b34588 + DAT_01b34584 + 3) = 0xe;
        *(int *)(&DAT_01b36c98 + DAT_01b34584 * 4) = DAT_00940370;
        if (*(char *)((int)&DAT_01b34588 + DAT_01b34584 + 2) == '\x0e') break;
        *(undefined4 *)(puVar4 + -4) = 0;
      }
      ffree(in_ST1);
      ffree(in_ST0);
      return;
    }
  } while( true );
}


