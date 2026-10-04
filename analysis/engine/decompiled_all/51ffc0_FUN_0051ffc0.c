// FUN_0051ffc0 @ 0051ffc0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051ffc0(void)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  float10 fVar7;
  unkbyte10 Var8;
  unkbyte10 extraout_ST1;
  int local_cc;
  
  puVar5 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  if ((DAT_02052740 == 0) && (P2 == f_0)) {
    ffree(in_ST0);
    iVar4 = thunk_FUN_0059a8e0(&DAT_00796ae4);
    Var8 = extraout_ST0;
    in_ST0 = extraout_ST0;
    if (iVar4 == 2) goto LAB_005210d9;
  }
  else {
    bVar2 = P2 == f_0;
    if (bVar2) {
      ffree(in_ST0);
      in_ST0 = thunk_FUN_0054cc83(&DAT_020b8ea0,0x200);
    }
    DAT_01a1feac = (uint)!bVar2;
    local_cc = 4;
    DAT_01aad7e8 = 1;
    do {
      *(int *)(DAT_01aad7e8 * 4 + 0x796ae0) =
           (int)ROUND(*(float *)(&P0 + (DAT_01a1feac + DAT_01aad7e8) * 4));
      DAT_01aad7e8 = DAT_01aad7e8 + 1;
      local_cc = local_cc + -1;
    } while (0 < local_cc);
    if (DAT_00796af0 == 0) {
      DAT_00796af0 = 1;
    }
  }
  ffree(in_ST0);
  Var8 = thunk_FUN_005725fa();
  DAT_0094e438 = 0;
  DAT_0094e434 = DAT_00796ae4;
  puVar6 = &stack0xfffffffc;
  if (DAT_020b8ea3 != 'X') goto LAB_00520200;
  DAT_0094e430 = DAT_00796aec;
  DAT_0094e438 = DAT_00796ae8;
  while (DAT_0094e430 != DAT_0094e438) {
    DAT_00796ae8 = DAT_0094e438;
    puVar6 = puVar5;
    if (DAT_0094e430 < DAT_0094e438) {
      *(undefined4 *)(puVar5 + -0xb4) = 0;
      DAT_00796aec = DAT_0094e438 - DAT_0094e434;
      DAT_0094e438 = DAT_0094e438 - DAT_0094e434;
    }
    else {
      DAT_00796aec = DAT_0094e434 + DAT_0094e438;
      DAT_0094e438 = DAT_0094e434 + DAT_0094e438;
      *(undefined4 *)(puVar5 + -0xb0) = 0;
    }
LAB_00520200:
    DAT_01aad7c0 = DAT_00796ae4;
    DAT_01aad7c4 = DAT_00796af0;
    if (DAT_00796af0 == 0) {
      *(undefined4 *)(puVar6 + -0xac) = 0;
    }
    else {
      DAT_01aad7c8 = DAT_00796ae8;
      DAT_01aad7cc = DAT_00796aec;
      DAT_0078b4e4 = 0x58;
      if ((((DAT_00796aec < 1) || (DAT_00796ae8 < 1)) || (DAT_00796ae4 < 1)) || (DAT_00796af0 < 1))
      {
        *(undefined4 *)(puVar6 + -0xa8) = 0;
      }
      else {
        ffree(Var8);
        Var8 = thunk_FUN_0054946a(&DAT_00767b80,0x14);
        DAT_01aad7d0 = DAT_01aad7c0;
        DAT_01aad7c0 = DAT_01aad7c0 + -1;
        DAT_0094e42c = 0;
        if ((200 < DAT_01aad7c8 && DAT_01aad7cc < 200) || (DAT_01aad7c8 < 200 && 200 < DAT_01aad7cc)
           ) {
          ffree(Var8);
          Var8 = thunk_FUN_0054e546(&DAT_0094e428,&DAT_0094e424);
          *(undefined2 *)(puVar6 + -0xf4) = in_FPUControlWord;
          *(ushort *)(puVar6 + -0xf2) = (ushort)*(undefined4 *)(puVar6 + -0xf4) | 0xc00;
          *(int *)(puVar6 + -0xf0) = (int)ROUND(_DAT_0094e428 + f_1);
          in_FPUControlWord = *(undefined2 *)(puVar6 + -0xf4);
          DAT_0094e42c = *(int *)(puVar6 + -0xf0);
          if (DAT_01aad7c8 < 200) {
            DAT_01aad7c8 = DAT_0094e42c + DAT_01aad7c8;
          }
          if (DAT_01aad7cc < 200) {
            DAT_01aad7cc = DAT_0094e42c + DAT_01aad7cc;
          }
          DAT_01aad7d4 = DAT_01aad7c0 + DAT_01aad7c8;
          DAT_01aad7d8 = DAT_01aad7c0 + DAT_01aad7cc;
          *(int *)(puVar6 + -0xa4) = ITEM_I;
          LOAD_I = 1;
          iVar4 = ITEM_I;
          while (0 < iVar4) {
            ffree(Var8);
            Var8 = load_item_header();
            if (LOAD_STAFF < 200) {
              (&ITEM_P2)[LOAD_W] = (float)DAT_0094e42c + (float)(&ITEM_P2)[LOAD_W];
            }
            LOAD_I = LOAD_I + 1;
            *(int *)(puVar6 + -0xa4) = *(int *)(puVar6 + -0xa4) + -1;
            iVar4 = *(int *)(puVar6 + -0xa4);
          }
          ffree(Var8);
          Var8 = index_items();
        }
        DAT_01aad7d4 = DAT_01aad7c0 + DAT_01aad7c8;
        DAT_01aad7d8 = DAT_01aad7c0 + DAT_01aad7cc;
        ffree(Var8);
        Var8 = thunk_FUN_004f7808();
        DAT_01f95c80 = DAT_01aad7cc;
        DAT_01f95c84 = DAT_01aad7c8;
        if (DAT_01aad7c8 < DAT_01aad7cc) {
          *(undefined4 *)(puVar6 + -0xa0) = 0;
        }
        else {
          DAT_01f95c84 = DAT_01aad7cc;
          DAT_01f95c80 = DAT_01aad7c8;
        }
        DAT_01aad7dc = 0;
        DAT_01aad7e0 = 0;
        DAT_01aad7e4 = 0;
        DAT_01fbb878 = 1;
        DAT_0094e420 = -999;
        *(int *)(puVar6 + -0x9c) = ITEM_I;
        LOAD_I = 1;
        DAT_01fbb87c = ITEM_I;
        DAT_01fbb870 = f_0;
        iVar4 = ITEM_I;
        while (0 < iVar4) {
          ffree(Var8);
          Var8 = load_item_header();
          if (LOAD_STAFF < DAT_01f95c84) {
            *(undefined4 *)(puVar6 + -0x98) = 0;
          }
          else {
            if (DAT_01f95c80 < LOAD_STAFF) {
              *(undefined4 *)(puVar6 + -0x94) = 0;
              break;
            }
            if (DAT_01aad7cc == LOAD_STAFF) {
              if ((DAT_01aad7e0 == 0) && (LOAD_CODE < 3 || LOAD_CODE == 0x12)) {
                DAT_01aad7e0 = LOAD_W;
              }
              *(undefined4 *)(puVar6 + -0x8c) = 0;
            }
            else {
              *(undefined4 *)(puVar6 + -0x90) = 0;
              if ((LOAD_CODE < 3) || (LOAD_CODE == 0x12)) {
                if (DAT_01aad7dc == 0) {
                  DAT_01aad7dc = LOAD_W;
                }
                *(undefined4 *)(puVar6 + -0x84) = 0;
              }
              else {
                *(undefined4 *)(puVar6 + -0x88) = 0;
                if (LOAD_CODE == 0xe) {
                  if (DAT_01aad7dc == 0) {
                    *(undefined4 *)(puVar6 + -0x7c) = 0;
                  }
                  else {
                    ffree(Var8);
                    fVar7 = (float10)anint(puVar6,0x5205e8);
                    *(int *)(puVar6 + -0xf0) = (int)ROUND(fVar7);
                    DAT_01aad7f0 = *(int *)(puVar6 + -0xf0);
                    Var8 = extraout_ST1;
                    if (DAT_0094e420 == DAT_01aad7f0) {
                      *(undefined4 *)(puVar6 + -0x74) = 0;
                    }
                    else {
                      *(undefined4 *)(puVar6 + -0x78) = 0;
                      DAT_01aad7e4 = DAT_01aad7e4 + 1;
                      (&DAT_01e9997c)[DAT_01aad7e4] = LOAD_W;
                      DAT_0094e420 = DAT_01aad7f0;
                    }
                  }
                }
                else {
                  *(undefined4 *)(puVar6 + -0x80) = 0;
                }
              }
            }
          }
          *(undefined4 *)(puVar6 + -0x70) = 0;
          LOAD_I = LOAD_I + 1;
          *(int *)(puVar6 + -0x9c) = *(int *)(puVar6 + -0x9c) + -1;
          iVar4 = *(int *)(puVar6 + -0x9c);
        }
        if (DAT_01aad7e4 < DAT_01aad7c4) {
          *(undefined4 *)(puVar6 + -0x6c) = 0;
        }
        else {
          DAT_0094e420 = 1;
          *(int *)(puVar6 + -0x68) = DAT_01aad7d0;
          DAT_01aad7e8 = 1;
          DAT_01aad7f8 = DAT_01f95c80;
          iVar4 = DAT_01aad7d0;
          while (0 < iVar4) {
            iVar4 = (DAT_01fbb87c - DAT_0094e420) + 1;
            *(int *)(puVar6 + -100) = iVar4;
            DAT_01aad7f0 = DAT_0094e420;
            while (0 < iVar4) {
              DAT_01aad7ec = (&ITEM_PTR0)[DAT_01aad7f0];
              fVar1 = (float)(&ITEM_P2)[DAT_01aad7ec];
              *(undefined2 *)(puVar6 + -0xf4) = in_FPUControlWord;
              *(ushort *)(puVar6 + -0xf2) = (ushort)*(undefined4 *)(puVar6 + -0xf4) | 0xc00;
              *(int *)(puVar6 + -0xf0) = (int)ROUND(fVar1);
              in_FPUControlWord = *(undefined2 *)(puVar6 + -0xf4);
              if (-1 < *(int *)(puVar6 + -0xf0) - DAT_01aad7f8) {
                if (0 < *(int *)(puVar6 + -0xf0) - DAT_01aad7f8) break;
                if ((float)(&ITEM_P1)[DAT_01aad7ec] == f_18) {
                  if (f_195 <= (float)(&ITEM_P3)[DAT_01aad7ec]) {
                    ffree(Var8);
                    Var8 = thunk_FUN_0045deb2(&DAT_01aad7f0);
                    *(undefined4 *)(puVar6 + -0x58) = 0;
                    break;
                  }
                  *(undefined4 *)(puVar6 + -0x5c) = 0;
                }
                else {
                  *(undefined4 *)(puVar6 + -0x60) = 0;
                }
              }
              *(undefined4 *)(puVar6 + -0x54) = 0;
              DAT_01aad7f0 = DAT_01aad7f0 + 1;
              *(int *)(puVar6 + -100) = *(int *)(puVar6 + -100) + -1;
              iVar4 = *(int *)(puVar6 + -100);
            }
            DAT_01aad7f8 = DAT_01aad7f8 + 1;
            DAT_01aad7e8 = DAT_01aad7e8 + 1;
            *(int *)(puVar6 + -0x68) = *(int *)(puVar6 + -0x68) + -1;
            DAT_0094e420 = DAT_01aad7f0;
            iVar4 = *(int *)(puVar6 + -0x68);
          }
          DAT_0094e420 = DAT_01aad7c4;
          if (DAT_01aad7cc < DAT_01aad7c8) {
            DAT_0094e420 = DAT_01aad7e4 - DAT_01aad7c4;
          }
          if (DAT_0094e420 == 0) {
            DAT_01f95c8c = (float)(&ITEM_P3)[DAT_01aad7dc] - f_1;
            *(undefined4 *)(puVar6 + -0x4c) = 0;
          }
          else {
            *(undefined4 *)(puVar6 + -0x50) = 0;
            DAT_0094e420 = (&DAT_01e9997c)[DAT_0094e420] + 3;
            DAT_01f95c8c = (float)(&ITEM_LEN)[DAT_0094e420] + f_0_1;
          }
          *(int *)(puVar6 + -0xf0) = DAT_01aad7cc - DAT_01aad7c8;
          P1 = (float)*(int *)(puVar6 + -0xf0);
          DAT_01fbb874 = 0;
          if (DAT_01aad7cc < DAT_01aad7c8) {
            *(undefined4 *)(puVar6 + -0x48) = 0;
            DAT_01a1feb4 = DAT_01f95c8c;
            _DAT_01a1feb8 = DAT_01fbb8b8 - DAT_01f95c8c;
            DAT_01a1fea4 = (float)(&ITEM_P3)[DAT_01aad7e0] - f_1;
            DAT_01f95c90 = _DAT_01a1feb8 + f_10;
            ffree(Var8);
            DAT_01fbb860 = DAT_01aad7cc;
            DAT_01fbb864 = DAT_01aad7d8;
            DAT_01fbb868 = DAT_01a1fea4;
            DAT_01fbb86c = f_210;
            Var8 = thunk_FUN_0049b1d8();
            _DAT_01a1fea0 = DAT_01f95c90;
            ffree(Var8);
            Var8 = FUN_00521109();
            DAT_01fbb868 = DAT_01a1feb4;
            DAT_01fbb874 = 2;
            _DAT_01a1fea0 = DAT_01a1fea4 - DAT_01a1feb4;
            ffree(Var8);
            fVar7 = (float10)FUN_00521219();
            _DAT_01a1febc = DAT_01fbb8b8 - DAT_01a1fea4;
            DAT_01f95c8c = _DAT_01a1feb8 + _DAT_01a1febc + f_9_9;
            DAT_01f95c88 = (_DAT_01a1febc - f_1) / DAT_01f95c8c;
            DAT_01fbb874 = -1;
            DAT_01fbb86c = DAT_01f95c8c + DAT_01a1fea4;
          }
          else {
            DAT_01a1fea4 = (float)(&ITEM_P3)[DAT_01aad7e0];
            DAT_01a1feb4 = (float)(&ITEM_P3)[DAT_01aad7dc] - f_1;
            _DAT_01a1feb8 = DAT_01f95c8c - DAT_01a1feb4;
            _DAT_01a1fea0 = f_210 - DAT_01a1feb4;
            DAT_01fbb86c = DAT_01f95c8c;
            ffree(Var8);
            DAT_01f95c90 = _DAT_01a1fea0;
            DAT_01fbb868 = DAT_01a1feb4;
            FUN_00521219();
            DAT_01f95c8c = DAT_01fbb8b8 + _DAT_01a1feb8 + f_10;
            fVar7 = (float10)DAT_01fbb8b8 - (float10)DAT_01a1fea4;
            DAT_01f95c88 = (float)(fVar7 / ((float10)DAT_01f95c8c - (float10)DAT_01a1fea4));
            DAT_01fbb874 = 2;
            *(undefined4 *)(puVar6 + -0x44) = 0;
            DAT_01fbb86c = DAT_01f95c8c;
          }
          DAT_01fbb860 = DAT_01aad7cc;
          DAT_01fbb864 = DAT_01aad7d8;
          DAT_01fbb868 = DAT_01a1fea4;
          ffree(fVar7);
          Var8 = thunk_FUN_0049b1d8();
          ffree(Var8);
          Var8 = FUN_00521182();
          DAT_01fbb868 = f_210;
          DAT_01fbb86c = f_1000;
          if (DAT_01fbb874 < 0) {
            *(undefined4 *)(puVar6 + -0x40) = 0;
          }
          else {
            DAT_01fbb860 = DAT_01aad7c8;
            DAT_01fbb864 = DAT_01aad7d4;
          }
          DAT_01fbb874 = 0;
          ffree(Var8);
          thunk_FUN_0049b1d8();
          _DAT_01a1fea0 = (float)-(float10)DAT_01f95c90;
          ffree((float10)DAT_01f95c90);
          Var8 = FUN_00521109();
          if (DAT_0094e420 != 0) {
            (&ITEM_LEN)[DAT_0094e420] = DAT_01fbb8b8;
          }
          ffree(Var8);
          Var8 = FUN_0052127b();
          DAT_0078b4e0 = 0x4c;
          DAT_0078b4e4 = 0x4a;
          DAT_0078b4ec = 0;
          ffree(Var8);
          Var8 = lineup_pass(&DAT_01aad7c8,&DAT_01aad7d4,&DAT_01f95c8c,&DAT_01f95c90);
          DAT_0078b4e0 = 0x4c;
          DAT_0078b4e4 = 0x4a;
          ffree(Var8);
          Var8 = lineup_pass(&DAT_01aad7cc,&DAT_01aad7d8,&DAT_01f95c8c,&DAT_01f95c90);
          iVar4 = DAT_01aad7c0 + 1;
          *(int *)(puVar6 + -0x3c) = iVar4;
          DAT_01a1feb0 = 1;
          while (0 < iVar4) {
            DAT_01aad7e0 = 0;
            DAT_01aad7dc = 0;
            DAT_01aad7f0 = 0;
            DAT_01aad7d0 = 0;
            *(int *)(puVar6 + -0x38) = DAT_01fbb87c;
            DAT_01aad7e8 = 1;
            iVar4 = DAT_01fbb87c;
            while (0 < iVar4) {
              DAT_0094e420 = (&ITEM_PTR0)[DAT_01aad7e8];
              fVar1 = (float)(&ITEM_P2)[DAT_0094e420];
              *(undefined2 *)(puVar6 + -0xf4) = in_FPUControlWord;
              *(ushort *)(puVar6 + -0xf2) = (ushort)*(undefined4 *)(puVar6 + -0xf4) | 0xc00;
              *(int *)(puVar6 + -0xf0) = (int)ROUND(fVar1);
              in_FPUControlWord = *(undefined2 *)(puVar6 + -0xf4);
              DAT_01aad7f4 = *(int *)(puVar6 + -0xf0);
              if (DAT_01f95c80 < DAT_01aad7f4) {
                *(undefined4 *)(puVar6 + -0x34) = 0;
                break;
              }
              if (DAT_01aad7f4 < DAT_01f95c84) {
                *(undefined4 *)(puVar6 + -0x30) = 0;
              }
              else {
                if (DAT_01f95c84 == DAT_01aad7f4) {
                  DAT_01aad7f0 = DAT_0094e420;
                  if ((DAT_01aad7e0 != 0) ||
                     (iVar4 = DAT_01aad7e8, iVar3 = DAT_0094e420,
                     (float)(&ITEM_P1)[DAT_0094e420] != f_3)) {
                    *(undefined4 *)(puVar6 + -0x28) = 0;
                    iVar4 = _DAT_0094e41c;
                    iVar3 = DAT_01aad7e0;
                  }
                }
                else {
                  *(undefined4 *)(puVar6 + -0x2c) = 0;
                  iVar4 = _DAT_0094e41c;
                  iVar3 = DAT_01aad7e0;
                }
                DAT_01aad7e0 = iVar3;
                _DAT_0094e41c = iVar4;
                if (DAT_01f95c80 == DAT_01aad7f4) {
                  DAT_01aad7d0 = DAT_0094e420;
                  if ((float)(&ITEM_P1)[DAT_0094e420] == f_3) {
                    DAT_01aad7dc = DAT_0094e420;
                  }
                }
                else {
                  *(undefined4 *)(puVar6 + -0x24) = 0;
                }
              }
              *(undefined4 *)(puVar6 + -0x20) = 0;
              DAT_01aad7e8 = DAT_01aad7e8 + 1;
              *(int *)(puVar6 + -0x38) = *(int *)(puVar6 + -0x38) + -1;
              iVar4 = *(int *)(puVar6 + -0x38);
            }
            DAT_01f95c84 = DAT_01f95c84 + 1;
            DAT_01f95c80 = DAT_01f95c80 + 1;
            if ((DAT_01aad7dc == 0) || (DAT_01aad7e0 == 0)) {
              *(undefined4 *)(puVar6 + -0x1c) = 0;
            }
            else {
              DAT_01f95c8c = (float)(&ITEM_P5)[DAT_01aad7dc];
              if ((float)(&ITEM_LEN)[DAT_01aad7dc] < f_5) {
                DAT_01f95c8c = f_0;
              }
              DAT_01f95c90 = (float)(&ITEM_P5)[DAT_01aad7e0];
              if ((float)(&ITEM_LEN)[DAT_01aad7e0] < f_5) {
                DAT_01f95c90 = f_0;
              }
              if (DAT_01f95c90 == DAT_01f95c8c) {
                *(undefined4 *)(puVar6 + -0x18) = 0;
              }
              else {
                if ((float)(&ITEM_LEN)[DAT_01aad7e0] < f_5) {
                  *(float *)(puVar6 + -0xf8) = (float)(&ITEM_LEN)[DAT_01aad7e0] + f_2;
                  ffree(Var8);
                  Var8 = thunk_FUN_005239c9(&DAT_0094e41c,puVar6 + -0xf8);
                }
                (&ITEM_P4)[DAT_01aad7e0] = f_0;
                (&ITEM_P5)[DAT_01aad7e0] = DAT_01f95c8c;
              }
            }
            *(undefined4 *)(puVar6 + -0x14) = 0;
            DAT_01a1feb0 = DAT_01a1feb0 + 1;
            *(int *)(puVar6 + -0x3c) = *(int *)(puVar6 + -0x3c) + -1;
            iVar4 = *(int *)(puVar6 + -0x3c);
          }
          DAT_0078b4ec = 0;
          iVar4 = DAT_01aad7cc;
          iVar3 = DAT_01aad7d4;
          if (DAT_01aad7c8 < DAT_01aad7d8) {
            *(undefined4 *)(puVar6 + -0x10) = 0;
            iVar4 = DAT_01aad7c8;
            iVar3 = DAT_01aad7d8;
          }
          DAT_01aad7d8 = iVar3;
          DAT_01aad7c8 = iVar4;
          P2 = (float)DAT_01aad7c8;
          P3 = (float)DAT_01aad7d8;
          DAT_0078b4e4 = 0x58;
          ffree(Var8);
          DAT_020b8ea0 = DAT_00767b50;
          Var8 = thunk_FUN_00443b70();
          if (DAT_0094e42c == 0) {
            *(undefined4 *)(puVar6 + -0xc) = 0;
          }
          else {
            *(int *)(puVar6 + -8) = ITEM_I;
            LOAD_I = 1;
            iVar4 = ITEM_I;
            while (0 < iVar4) {
              ffree(Var8);
              Var8 = load_item_header();
              if (DAT_0094e42c <= LOAD_STAFF) {
                (&ITEM_P2)[LOAD_W] = (float)(&ITEM_P2)[LOAD_W] - (float)DAT_0094e42c;
              }
              LOAD_I = LOAD_I + 1;
              *(int *)(puVar6 + -8) = *(int *)(puVar6 + -8) + -1;
              iVar4 = *(int *)(puVar6 + -8);
            }
            ffree(Var8);
            Var8 = thunk_FUN_004f7808();
            ffree(Var8);
            Var8 = index_items();
            ffree(Var8);
            Var8 = draw_items();
          }
        }
      }
    }
LAB_005210d9:
    if (DAT_0094e438 == 0) goto LAB_005210ee;
    *(undefined4 *)(puVar6 + -4) = 0;
    puVar5 = puVar6;
  }
  *(undefined4 *)(puVar5 + -0xb8) = 0;
LAB_005210ee:
  _DAT_02052750 = 1;
  ffree(Var8);
  Var8 = thunk_FUN_00549422();
  ffree(Var8);
  return;
}


