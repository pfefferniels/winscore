// FUN_00442800 @ 00442800 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00442800(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  unkbyte10 extraout_ST0_02;
  unkbyte10 extraout_ST0_03;
  unkbyte10 extraout_ST0_04;
  unkbyte10 extraout_ST0_05;
  unkbyte10 extraout_ST0_06;
  unkbyte10 extraout_ST0_07;
  unkbyte10 extraout_ST0_08;
  unkbyte10 extraout_ST0_09;
  unkbyte10 Var6;
  float10 fVar7;
  undefined1 *puVar8;
  int local_50;
  
  puVar8 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  if ((((DAT_01fbb8a4 != 9) && (DAT_01fbb86c == _DAT_01fbb884)) && (DAT_01fbb868 == DAT_01fbb880))
     && ((float)DAT_01fbb860 == P1)) {
    ffree(in_ST0);
    in_ST0 = thunk_FUN_0054d831("Cannot move or copy to same place.",0x23);
    DAT_01fbb8a0 = 0;
    goto LAB_004435b3;
  }
  DAT_007f7e34 = 0;
  _DAT_007f7e30 = 0;
  if (DAT_01fbb8a0 == 0x11) {
    if (DAT_01fbb8a4 == 10) {
      DAT_02052760 = (int)ROUND(P4);
    }
    ffree(in_ST0);
    in_ST0 = thunk_FUN_00518448();
    local_50 = 0x12;
    DAT_01fbb88c = 1;
    do {
      *(undefined4 *)(DAT_01fbb88c * 4 + 0x1c5855c) = *(undefined4 *)(&P0 + DAT_01fbb88c * 4);
      DAT_01fbb88c = DAT_01fbb88c + 1;
      local_50 = local_50 + -1;
    } while (0 < local_50);
    goto LAB_00443128;
  }
  _DAT_01c4ef4c = ITEM_I;
  if (DAT_01fbb8a4 == 0) {
    DAT_01fbb88c = 3;
    if (DAT_0078b4e4 == 0x53) {
      DAT_01fbb88c = 1;
    }
    if (ITEM_I != 0) {
      DAT_0078b4e0 = 0x15;
      FUN_005f33c9(&stack0xfffffffc,0x4429df);
      puVar5 = puVar8;
      Var6 = FUN_005f33c9(puVar8,0x4429fb);
      *(undefined1 **)(puVar5 + -0x10c) = puVar5 + -0x128;
      *(undefined4 *)(puVar5 + -0x110) = 0x11;
      *(undefined4 *)(puVar5 + -0x108) = 2;
      *(undefined4 *)(puVar5 + -0x104) = 4;
      ffree(Var6);
      uVar2 = FUN_005f6540(puVar5 + -0xf4,DAT_0078b4e0,0x784ff01,&DAT_007607bc,puVar5 + -0x110);
      *(undefined4 *)(puVar5 + -0xc4) = uVar2;
      in_ST0 = extraout_ST0;
      if (*(int *)(puVar5 + -0xc4) == 0) {
        *(undefined4 *)(puVar5 + -0xf4) = 0;
        *(float **)(puVar5 + -0x100) = &P1;
        ffree(extraout_ST0);
        iVar1 = FUN_005ffa30(puVar5 + -0xf4,DAT_0078b4e0,0x784ff01,&DAT_007607b8,puVar5 + -0x100);
        *(int *)(puVar5 + -0xc0) = iVar1;
        in_ST0 = extraout_ST0_00;
        if (iVar1 == 0) {
          *(float **)(puVar5 + -0x100) = &P2;
          ffree(extraout_ST0_00);
          iVar1 = FUN_005ffd80(puVar5 + -0xf4,&DAT_007607b8,puVar5 + -0x100);
          *(int *)(puVar5 + -0xc0) = iVar1;
          in_ST0 = extraout_ST0_01;
          if (iVar1 == 0) {
            *(float **)(puVar5 + -0x100) = &P3;
            ffree(extraout_ST0_01);
            iVar1 = FUN_005ffd80(puVar5 + -0xf4,&DAT_007607b8,puVar5 + -0x100);
            *(int *)(puVar5 + -0xc0) = iVar1;
            in_ST0 = extraout_ST0_02;
            if (iVar1 == 0) {
              *(float **)(puVar5 + -0x100) = &P4;
              ffree(extraout_ST0_02);
              iVar1 = FUN_005ffd80(puVar5 + -0xf4,&DAT_007607b8,puVar5 + -0x100);
              *(int *)(puVar5 + -0xc0) = iVar1;
              in_ST0 = extraout_ST0_03;
              if (iVar1 == 0) {
                *(float **)(puVar5 + -0x100) = &P5;
                ffree(extraout_ST0_03);
                iVar1 = FUN_005ffd80(puVar5 + -0xf4,&DAT_007607b8,puVar5 + -0x100);
                *(int *)(puVar5 + -0xc0) = iVar1;
                in_ST0 = extraout_ST0_04;
                if (iVar1 == 0) {
                  *(int **)(puVar5 + -0x100) = &DAT_01fbb860;
                  ffree(extraout_ST0_04);
                  iVar1 = FUN_005ffd80(puVar5 + -0xf4,&DAT_007607b4,puVar5 + -0x100);
                  *(int *)(puVar5 + -0xc0) = iVar1;
                  in_ST0 = extraout_ST0_05;
                  if (iVar1 == 0) {
                    *(int **)(puVar5 + -0x100) = &DAT_01fbb864;
                    ffree(extraout_ST0_05);
                    iVar1 = FUN_005ffd80(puVar5 + -0xf4,&DAT_007607b4,puVar5 + -0x100);
                    *(int *)(puVar5 + -0xc0) = iVar1;
                    in_ST0 = extraout_ST0_06;
                    if (iVar1 == 0) {
                      *(float **)(puVar5 + -0x100) = &DAT_01fbb868;
                      ffree(extraout_ST0_06);
                      iVar1 = FUN_005ffd80(puVar5 + -0xf4,&DAT_007607b8,puVar5 + -0x100);
                      *(int *)(puVar5 + -0xc0) = iVar1;
                      in_ST0 = extraout_ST0_07;
                      if (iVar1 == 0) {
                        *(float **)(puVar5 + -0x100) = &DAT_01fbb86c;
                        ffree(extraout_ST0_07);
                        uVar2 = FUN_005ffd80(puVar5 + -0xf4,&DAT_007607b0,puVar5 + -0x100);
                        *(undefined4 *)(puVar5 + -0xc0) = uVar2;
                        in_ST0 = extraout_ST0_08;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if (*(int *)(puVar5 + -0xc0) == 0) {
          *(undefined4 *)(puVar5 + -0xf4) = 0;
          ffree(in_ST0);
          Var6 = FUN_005f7950(puVar5 + -0xf4,DAT_0078b4e0,0x784ff00,&DAT_007607ac,0);
          IP21 = 0x43;
          IP22 = 0;
          *(undefined4 *)(puVar5 + -0xb8) = 0;
          ffree(Var6);
          in_ST0 = thunk_FUN_004a1240(&DAT_007607a8);
          *(undefined4 *)(puVar5 + -0xac) = 0;
          puVar3 = puVar5;
          goto LAB_00442d28;
        }
      }
    }
    IP21 = 0;
    *(undefined4 *)(puVar5 + -0xb4) = 0;
  }
  else {
LAB_00442d28:
    if (**(int **)(puVar3 + 8) == 2) {
      DAT_01fbb8a0 = 3;
      *(undefined4 *)(puVar3 + -0xa8) = 0;
      goto LAB_004435b3;
    }
    if ((MAX_STAFF < DAT_01fbb88c) && (DAT_01fbb890 <= MAX_STAFF)) {
      *(undefined4 *)(puVar3 + -0xa4) = 0;
    }
    else {
      if (MAX_STAFF < DAT_01fbb890) {
        DAT_01fbb890 = DAT_01fbb860;
      }
      if ((DAT_01fbb880 == f_0) && (_DAT_01fbb884 == f_0)) {
        DAT_01fbb880 = DAT_01fbb868;
        _DAT_01fbb884 = DAT_01fbb86c;
      }
      else {
        *(undefined4 *)(puVar3 + -0xa0) = 0;
      }
      if ((DAT_01fbb868 == f_0) && (DAT_01fbb880 == f_0)) {
        if (_DAT_01fbb884 != f_0) {
          *(undefined4 *)(puVar3 + -0x98) = 0;
          goto LAB_00442e42;
        }
        DAT_007f7e2c = 1;
        *(undefined4 *)(puVar3 + -0x94) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x9c) = 0;
LAB_00442e42:
        if ((_DAT_01fbb884 == f_0) && (DAT_01fbb880 != f_0)) {
          _DAT_007f7e28 = DAT_01fbb880;
          *(undefined4 *)(puVar3 + -0x8c) = 0;
LAB_00442fa5:
          DAT_007f7e2c = 2;
          if (DAT_01fbb890 == DAT_01fbb860) {
            DAT_007f7e2c = 0;
          }
          *(undefined4 *)(puVar3 + -0x7c) = 0;
        }
        else {
          *(undefined4 *)(puVar3 + -0x90) = 0;
          if (_DAT_01fbb884 == f_0) {
            _DAT_01fbb884 = DAT_01fbb86c;
          }
          if ((DAT_01fbb880 == DAT_01fbb868) && (_DAT_01fbb884 == DAT_01fbb86c)) {
            DAT_007f7e2c = 1;
            *(undefined4 *)(puVar3 + -0x84) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x88) = 0;
            _DAT_007f7e24 = DAT_01fbb86c - DAT_01fbb868;
            DAT_007f7e20 = _DAT_01fbb884 - DAT_01fbb880;
            if (_DAT_007f7e24 == f_0) {
              _DAT_007f7e24 = DAT_007f7e20;
            }
            if (ABS(_DAT_007f7e24 - DAT_007f7e20) <= f_0_001) {
              _DAT_007f7e28 = DAT_01fbb880 - DAT_01fbb868;
              goto LAB_00442fa5;
            }
            *(undefined4 *)(puVar3 + -0x80) = 0;
            _DAT_007f7e28 = DAT_007f7e20 / _DAT_007f7e24;
            DAT_007f7e2c = -1;
            if (DAT_01fbb890 != DAT_01fbb860) {
              DAT_007f7e2c = 3;
            }
          }
        }
      }
      DAT_01fbb874 = DAT_007f7e2c;
      if ((DAT_01fbb8a4 == 2) && (DAT_007f7e2c < 1)) {
        DAT_01fbb874 = -0x43;
      }
      if (**(int **)(puVar3 + 8) == 0) {
        DAT_01fbb878 = 1;
      }
      DAT_01fbb87c = ITEM_I;
      if (DAT_01fbb8a4 == 0xd) {
        ffree(in_ST0);
        in_ST0 = thunk_FUN_00468df8(&DAT_007607a0);
        if (DAT_007f7e34 == 0) {
          ffree(in_ST0);
          in_ST0 = thunk_FUN_005725fa();
        }
        DAT_007f7e34 = 1;
        *(undefined4 *)(puVar3 + -0x74) = 0;
        goto LAB_00443307;
      }
      *(undefined4 *)(puVar3 + -0x78) = 0;
      if (DAT_02052740 == 0) {
        puVar4 = puVar3;
        if (DAT_01fbb8a0 == 10) {
          *(undefined4 *)(puVar3 + -0x6c) = 0;
LAB_00443128:
          ffree(in_ST0);
          Var6 = thunk_FUN_0049b1d8();
          DAT_01fbb8a0 = 0;
          ffree(Var6);
          in_ST0 = thunk_FUN_00468df8(&DAT_007607a0);
          puVar3 = puVar4;
          if (DAT_020492a0 != 0) {
            *(undefined4 *)(puVar4 + -0x48) = 0;
            if (DAT_01fbb8a4 < 3) {
              *(undefined4 *)(puVar4 + -0x40) = 0;
            }
            else {
              if (DAT_01fbb8a4 == 10) {
                *(undefined2 *)(puVar4 + -0xfc) = in_FPUControlWord;
                *(ushort *)(puVar4 + -0xfa) = (ushort)*(undefined4 *)(puVar4 + -0xfc) | 0xc00;
                *(int *)(puVar4 + -0xf8) = (int)ROUND(P4);
                DAT_02052760 = *(int *)(puVar4 + -0xf8);
              }
              if (DAT_01fbb8a4 == 9) {
                ffree(in_ST0);
                in_ST0 = thunk_FUN_00445143();
                *(undefined4 *)(puVar4 + -0x38) = 0;
                goto LAB_004435b3;
              }
              *(undefined4 *)(puVar4 + -0x3c) = 0;
              _DAT_007f7e1c = NPT;
              if (MAX_STAFF < DAT_01fbb890) {
                if ((DAT_01fbb860 != 1) || (MAX_STAFF != DAT_01fbb864)) {
                  if (DAT_01c58560 != f_0) {
                    ffree(in_ST0);
                    in_ST0 = FUN_00442155();
                    *(undefined4 *)(puVar4 + -0x28) = 0;
                    goto LAB_00443453;
                  }
                  *(undefined4 *)(puVar4 + -0x2c) = 0;
                  goto LAB_00443578;
                }
                *(undefined4 *)(puVar4 + -0x30) = 0;
              }
              else {
                *(undefined4 *)(puVar4 + -0x34) = 0;
              }
            }
            goto LAB_004434c2;
          }
        }
        else {
          if (((DAT_01fbb8a4 != 9) && (DAT_02052760 == 0)) && (2 < DAT_01fbb8a4)) {
            *(undefined4 *)(puVar3 + -0x68) = 0;
            goto LAB_00443128;
          }
          if (DAT_01c58560 == f_0) {
            ffree(in_ST0);
            uVar2 = thunk_FUN_0059b4e0(&DAT_007f7e4c);
            **(undefined4 **)(puVar3 + 8) = uVar2;
            in_ST0 = extraout_ST0_09;
            if (**(int **)(puVar3 + 8) == 2) {
              *(undefined4 *)(puVar3 + -0x60) = 0;
              goto LAB_00443578;
            }
            *(undefined4 *)(puVar3 + -0x5c) = 0x12;
            DAT_01fbb88c = 1;
            do {
              *(float *)(DAT_01fbb88c * 4 + 0x1c5855c) =
                   (float)*(int *)(DAT_01fbb88c * 4 + 0x7f7e48);
              DAT_01fbb88c = DAT_01fbb88c + 1;
              *(int *)(puVar3 + -0x5c) = *(int *)(puVar3 + -0x5c) + -1;
            } while (0 < *(int *)(puVar3 + -0x5c));
          }
          else {
            *(undefined4 *)(puVar3 + -100) = 0;
          }
          if (DAT_01fbb8a4 != 9) {
            *(undefined4 *)(puVar3 + -0x58) = 0;
            goto LAB_00443128;
          }
          ffree(in_ST0);
          Var6 = thunk_FUN_00445143();
          DAT_01fbb8a0 = 0;
          ffree(Var6);
          in_ST0 = thunk_FUN_00468df8(&DAT_007607a0);
          if (DAT_020492a0 != 0) {
            ffree(in_ST0);
            in_ST0 = thunk_FUN_00549422();
            *(undefined4 *)(puVar3 + -0x50) = 0;
            goto LAB_004435b3;
          }
          *(undefined4 *)(puVar3 + -0x54) = 0;
        }
        ffree(in_ST0);
        in_ST0 = thunk_FUN_0054d831(&DAT_00760790,0xf);
        *(undefined4 *)(puVar3 + -0x44) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x70) = 0;
        ffree(in_ST0);
        in_ST0 = thunk_FUN_0049b1d8();
LAB_004434c2:
        while( true ) {
          if (DAT_007f7e34 == 0) {
            ffree(in_ST0);
            in_ST0 = thunk_FUN_005725fa();
            DAT_007f7e34 = 1;
            if ((DAT_01fbb8a4 == 2) || (DAT_01fbb8a4 != 10 && DAT_02052760 != 0)) {
              _DAT_007f7e30 = DAT_01fbb864 - DAT_01fbb860;
            }
          }
          if (1 < DAT_01fbb8a4) {
            ffree(in_ST0);
            in_ST0 = FUN_0044236f();
          }
          DAT_01fbb870 = f_0;
          DAT_01c58560 = f_0;
LAB_00443307:
          if ((DAT_007f7e2c < 1) || (_DAT_01fbb888 != f_0)) {
            *(undefined4 *)(puVar3 + -0x24) = 0;
          }
          else {
            *(int *)(puVar3 + -0xf8) = DAT_01fbb890 - DAT_01fbb860;
            iVar1 = *(int *)(puVar3 + -0xf8);
            P1 = (float)iVar1;
            fVar7 = (float10)_DAT_007f7e30 +
                    (float10)iVar1 + (float10)*(float *)(&DAT_02053438 + DAT_020492a8 * 4);
            if ((float10)DAT_01fbb860 == fVar7) {
              fVar7 = (float10)iVar1 + (float10)f_1;
              P1 = (float)((float10)_DAT_007f7e30 + fVar7);
              DAT_02052760 = (DAT_02052760 - _DAT_007f7e30) + -1;
            }
            else {
              *(undefined4 *)(puVar3 + -0x20) = 0;
            }
            ffree(fVar7);
            in_ST0 = thunk_FUN_004e7eea();
          }
          puVar4 = puVar3;
          if (DAT_01fbb8a4 == 10) {
            *(undefined4 *)(puVar3 + -0x1c) = 0;
          }
          else {
            if (_DAT_01fbb888 != f_0) {
              ffree(in_ST0);
              in_ST0 = FUN_004424e8();
            }
            if ((DAT_007f7e2c == 1) || (_DAT_007f7e28 == f_0)) {
              *(undefined4 *)(puVar3 + -0x18) = 0;
            }
            else {
              ffree(in_ST0);
              in_ST0 = thunk_FUN_0049bb13(&DAT_007f7e2c,&DAT_01fbb868,&DAT_01fbb880,&DAT_007f7e28);
              DAT_01fbb8a0 = 0;
              if (IP22 == 0x4a) {
                *(undefined4 *)(puVar3 + -0x14) = 0;
                goto LAB_004435b3;
              }
            }
          }
LAB_00443453:
          if (DAT_020492a0 < 1) {
            *(undefined4 *)(puVar4 + -0x10) = 0;
            goto LAB_004435b3;
          }
          puVar3 = puVar4;
          if (DAT_02052760 == 0) {
            *(undefined4 *)(puVar4 + -0xc) = 0;
            goto LAB_00443557;
          }
          DAT_02052760 = (DAT_02052760 - _DAT_007f7e30) + -1;
          DAT_01fbb860 = (DAT_01fbb890 - _DAT_007f7e30) + -1;
          if (DAT_02052760 < DAT_01fbb890) break;
          *(undefined4 *)(puVar4 + -8) = 0;
        }
        DAT_02052760 = 0;
      }
LAB_00443557:
      ffree(in_ST0);
      Var6 = draw_items();
      ffree(Var6);
      in_ST0 = thunk_FUN_00549422();
      DAT_020527e8 = ITEM_I;
      *(undefined4 *)(puVar3 + -4) = 0;
    }
LAB_00443578:
    DAT_0078b4ec = 0;
    DAT_0078b4f0 = 1;
    _DAT_009c6ad4 = f_0;
  }
  DAT_0078b4e0 = 0;
LAB_004435b3:
  ffree(in_ST0);
  return;
}


