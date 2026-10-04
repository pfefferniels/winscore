// FUN_005870fd @ 005870fd (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x005877f3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005870fd(void)

{
  undefined1 *puVar1;
  float fVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined2 in_FPUControlWord;
  undefined2 uVar8;
  unkbyte10 Var9;
  float10 fVar10;
  unkbyte10 extraout_ST0;
  
  puVar7 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x587127);
  Var9 = FUN_005f34d1(puVar7,0x587142);
  ffree(Var9);
  thunk_FUN_0058c248(&DAT_01a1f484,0x40,&DAT_0076ae44,&DAT_0076ae48,"(1f5.1)",7,&P1);
  Var9 = FUN_005f34d1(puVar7,0x58719d);
  ffree(Var9);
  Var9 = thunk_FUN_0058c248(&DAT_01a1f4c4,0x10,&DAT_0076ae30,&DAT_0076ae34,"(1f6.2)",7,&P2);
  ffree(Var9);
  Var9 = thunk_FUN_0058c248(&DAT_01a1f4c4,0x10,&DAT_0076ae48,&DAT_0076ae2c,"(1f6.2)",7,&P3);
  DAT_01a1f4c3 = 0;
  DAT_01a1f4d0._3_1_ = 0;
  DAT_01a9f328 = 0;
  _DAT_01a9f334 = f_m1;
  DAT_01a9f338 = -1;
  DAT_009a92b8 = 1;
  DAT_01f95c80 = 0;
  DAT_01a9f33c = 0;
  DAT_01a9f340 = 0;
  DAT_01a9f30c = 0;
  DAT_01a9f344 = -1;
  DAT_009a92b4 = 0;
  for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
    *(undefined1 *)((int)&DAT_01a1f4d0 + iVar6 + 3) = 0x20;
  }
  for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
    (&DAT_01a1f653)[iVar6] = 0x20;
  }
  for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
    (&DAT_01a1f7d3)[iVar6] = 0x20;
  }
  for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
    *(undefined1 *)(iVar6 + 0x1a1f953) = 0x20;
  }
  for (iVar6 = 1; iVar6 < 0x181; iVar6 = iVar6 + 1) {
    *(undefined1 *)(iVar6 + 0x1a1fad3) = 0x20;
  }
  DAT_020492a4 = 0;
  DAT_01a9f314 = 0;
  DAT_01a9f318 = 0;
  DAT_01a9f320 = 0;
  DAT_01f95c8c = 0;
  if (DAT_01a9f300 < 1) {
    *(undefined4 *)(puVar7 + -0x178) = 0;
  }
  else {
    DAT_009a92b4 = DAT_01a9f300;
    DAT_01a1f4d4_3 = (undefined1)((uint)i_790634541 >> 0x18);
    _DAT_01a1f4d4 =
         CONCAT21(*(undefined2 *)(s_RWRFRIRDRURPTRBAALTEPR_007a05b0 + DAT_01a9f300 * 2 + 0xc),
                  (char)i_790634541);
    DAT_01a9f314 = 4;
  }
  fVar2 = P1;
  DAT_01a9f300 = 0;
  *(undefined2 *)(puVar7 + -0x1a0) = in_FPUControlWord;
  *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
  *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
  LOAD_I = DAT_009a92b8;
  uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
  DAT_009a92b0 = *(int *)(puVar7 + -0x19c);
  _DAT_009a92ac = P2;
  _DAT_009a92a8 = P3;
  iVar6 = (ITEM_I - DAT_009a92b8) + 1;
  *(int *)(puVar7 + -0x174) = iVar6;
  while (0 < iVar6) {
    ffree(Var9);
    Var9 = load_item_header();
    if (((_DAT_009a92a8 < LOAD_P3) || (DAT_009a92b0 != LOAD_STAFF)) || (LOAD_P3 < _DAT_009a92ac)) {
      *(undefined4 *)(puVar7 + -0x170) = 0;
      goto LAB_00588362;
    }
    switch(LOAD_CODE) {
    default:
      if (*(char *)((int)&DAT_01a1f4d0 + DAT_01a9f314 + 3) == '/') {
        *(undefined4 *)(puVar7 + -0x16c) = 0;
      }
      else {
        puVar1 = &DAT_01a1f4d4 + DAT_01a9f314;
        DAT_01a9f314 = DAT_01a9f314 + 1;
        *puVar1 = 0x2f;
      }
      if (_DAT_01a9f334 == LOAD_P3) {
        *(undefined1 *)((int)&DAT_01a1f4d0 + DAT_01a9f314 + 3) = 0x27;
        *(undefined4 *)(puVar7 + -0x164) = 0;
      }
      else {
        *(undefined4 *)(puVar7 + -0x168) = 0;
        ffree(Var9);
        Var9 = FUN_0058991a();
        DAT_01a9f30c = DAT_01a9f30c + 1;
        (&DAT_01a18340)[DAT_01a9f30c] = LOAD_P3;
      }
      _DAT_01a9f334 = LOAD_P3;
      if (LOAD_LEN < 0xb) {
        *(undefined4 *)(puVar7 + -0x160) = 0;
      }
      else {
        fVar2 = *(float *)(&ITEM_P11 + LOAD_W * 4);
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f324 = *(int *)(puVar7 + -0x19c);
        if (DAT_01a9f324 != 0) {
          ffree(Var9);
          Var9 = FUN_00589e4a();
        }
      }
      DAT_01a9f324 = 0;
      if (0xb < LOAD_LEN) {
        fVar2 = *(float *)(&ITEM_P12 + LOAD_W * 4);
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f324 = *(int *)(puVar7 + -0x19c);
      }
      if (DAT_01a9f33c == DAT_01a9f324) {
        *(undefined4 *)(puVar7 + -0x15c) = 0;
      }
      else {
        ffree(Var9);
        Var9 = FUN_005898eb(s_S0S_S__007a0580 + DAT_01a9f324 * 2,2,&DAT_01a1f4d4 + DAT_01a9f314,1);
        DAT_01a9f33c = DAT_01a9f324;
        ffree(Var9);
        Var9 = FUN_005898bc(&DAT_0076adf8,1);
      }
      DAT_01a9f308 = 0;
      if (3 < LOAD_LEN) {
        fVar2 = (float)(&ITEM_P4)[LOAD_W];
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f308 = *(int *)(puVar7 + -0x19c);
      }
      DAT_01f95c84 = DAT_01a9f308;
      DAT_01a9f308 = DAT_01a9f308 % 100;
      DAT_01f95c88 = 0;
      if (LOAD_LEN < 5) {
        *(undefined4 *)(puVar7 + -0x158) = 0;
      }
      else {
        fVar2 = (float)(&ITEM_P5)[LOAD_W];
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f348 = *(int *)(puVar7 + -0x19c);
        DAT_01f95c88 = (DAT_01a9f348 % 100) / 10;
        if ((DAT_01f95c88 == 0) || (DAT_01a9f340 == DAT_01f95c88)) {
          *(undefined4 *)(puVar7 + -0x154) = 0;
        }
        else {
          if (DAT_01a9f308 < 7) {
            *(undefined4 *)(puVar7 + -0x150) = 0;
            if (DAT_01f95c88 == 1) {
              if (DAT_01a9f340 == 0) {
                *(undefined4 *)(puVar7 + -0x13c) = 0;
                goto LAB_00588037;
              }
LAB_00587fd8:
              DAT_01f95c88 = 0;
            }
            else {
              *(undefined4 *)(puVar7 + -0x140) = 0;
            }
          }
          else {
            if (DAT_01f95c88 == 2) {
              if (DAT_01a9f340 != 0) {
                *(undefined4 *)(puVar7 + -0x144) = 0;
                goto LAB_00587fd8;
              }
              *(undefined4 *)(puVar7 + -0x148) = 0;
              goto LAB_00588037;
            }
            *(undefined4 *)(puVar7 + -0x14c) = 0;
          }
          ffree(Var9);
          Var9 = FUN_005898eb(s_SOSUSD_007a0578 + DAT_01f95c88 * 2,2,&DAT_01a1f4d4 + DAT_01a9f314,1)
          ;
          DAT_01a9f340 = DAT_01f95c88;
          ffree(Var9);
          Var9 = FUN_005898bc(&DAT_0076adf8,1);
        }
      }
LAB_00588037:
      iVar6 = DAT_01f95c84;
      if (DAT_01f95c84 < 0) {
        iVar6 = -DAT_01f95c84;
      }
      if (iVar6 < 100) {
        *(undefined4 *)(puVar7 + -0x138) = 0;
        if (DAT_01a9f344 < 1) {
          *(undefined4 *)(puVar7 + -0x128) = 0;
        }
        else {
LAB_005880b6:
          ffree(Var9);
          Var9 = FUN_00589dd1(&DAT_01a9f344);
        }
      }
      else if ((LOAD_LEN < 7) || (*(float *)(&ITEM_P7 + LOAD_W * 4) < f_64)) {
        if (DAT_01a9f344 < 1) {
          *(undefined4 *)(puVar7 + -300) = 0;
          goto LAB_005880b6;
        }
        *(undefined4 *)(puVar7 + -0x130) = 0;
      }
      else {
        *(undefined4 *)(puVar7 + -0x134) = 0;
      }
      if (DAT_01f95c80 == 0) {
        ffree(Var9);
        Var9 = FUN_005898bc(&DAT_0076adf0,1);
      }
      DAT_01f95c80 = 1;
      DAT_01a9f308 = DAT_01a9f308 - (&DAT_007a059c)[DAT_009a92b4];
      DAT_01a9f324 = DAT_01a9f308 % 7;
      if (DAT_01a9f324 < 1) {
        DAT_01a9f324 = DAT_01a9f324 + 7;
      }
      if (5 < DAT_01a9f324) {
        DAT_01a9f324 = DAT_01a9f324 + -7;
      }
      puVar7[-0x199] = (char)DAT_01a9f324 + 'B';
      DAT_01a9f330._0_2_ = CONCAT11(DAT_01a9f330._1_1_,puVar7[-0x199]);
      ffree(Var9);
      Var9 = FUN_005898bc(&DAT_01a9f330,1);
      if (LOAD_LEN < 5) {
        *(undefined4 *)(puVar7 + -0x124) = 0;
      }
      else {
        fVar2 = (float)(&ITEM_P5)[LOAD_W];
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f34c = *(int *)(puVar7 + -0x19c);
        if (DAT_01a9f34c < 100) {
          *(undefined4 *)(puVar7 + -0x120) = 0;
        }
        else {
          ffree(Var9);
          Var9 = FUN_005898bc(&DAT_0076adec,1);
        }
        iVar6 = DAT_01a9f34c % 10;
        DAT_01a9f34c = iVar6;
        if (iVar6 < 6) {
          if (iVar6 < 4) {
            *(undefined4 *)(puVar7 + -0x118) = 0;
          }
          else {
            DAT_01a9f34c = iVar6 + -3;
            ffree(Var9);
            Var9 = FUN_005898bc(iVar6 + 0x7a0594,1);
          }
          if (DAT_01a9f34c == 0) {
            *(undefined4 *)(puVar7 + -0x114) = 0;
          }
          else {
            ffree(Var9);
            Var9 = FUN_005898bc(&DAT_007a0597 + DAT_01a9f34c,1);
          }
        }
        else {
          *(undefined4 *)(puVar7 + -0x11c) = 0;
        }
      }
      DAT_01a9f324 = (DAT_01a9f308 + 0x1b) / 7;
      if (DAT_01a9f338 == DAT_01a9f324) {
        *(undefined4 *)(puVar7 + -0x110) = 0;
      }
      else {
        puVar7[-0x199] = (char)DAT_01a9f324 + '0';
        DAT_01a9f330._0_2_ = CONCAT11(DAT_01a9f330._1_1_,puVar7[-0x199]);
        ffree(Var9);
        DAT_01a9f338 = DAT_01a9f324;
        Var9 = FUN_005898bc(&DAT_01a9f330,1);
        *(undefined4 *)(puVar7 + -0x10c) = 0;
      }
      break;
    case 2:
      ffree(Var9);
      Var9 = FUN_0058991a();
      DAT_01a9f308 = 0;
      if (4 < LOAD_LEN) {
        fVar2 = (float)(&ITEM_P5)[LOAD_W];
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f308 = *(int *)(puVar7 + -0x19c);
      }
      DAT_01a9f348 = 0;
      if (DAT_01a9f308 == -2) {
        *(undefined4 *)(puVar7 + -0x104) = 0;
      }
      else {
        if (DAT_01a9f308 == -4) {
          *(undefined4 *)(puVar7 + -0x100) = 0;
          DAT_01a9f348 = 1;
code_r0x005876a9:
          DAT_01a9f348 = DAT_01a9f348 + 1;
code_r0x005876b8:
          DAT_01a9f348 = DAT_01a9f348 + 1;
code_r0x005876c7:
          DAT_01a9f348 = DAT_01a9f348 + 1;
        }
        else {
          if ((LOAD_LEN < 8) || (f_0 <= *(float *)(&ITEM_P8 + LOAD_W * 4))) {
            if ((LOAD_LEN < 6) || (f_0 <= (float)(&ITEM_P6)[LOAD_W])) {
              fVar2 = (float)(&ITEM_P4)[LOAD_W];
              *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
              *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
              *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
              uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
              DAT_01a9f308 = *(int *)(puVar7 + -0x19c);
              iVar6 = DAT_01a9f308;
              if (DAT_01a9f308 < 0) {
                iVar6 = -DAT_01a9f308;
              }
              if (iVar6 < 100) {
                *(undefined4 *)(puVar7 + -0xf4) = 0;
                if (DAT_01a9f344 < 0) {
                  *(undefined4 *)(puVar7 + -0xe8) = 0;
                }
                else {
code_r0x00587686:
                  ffree(Var9);
                  Var9 = FUN_00589dd1(&DAT_01a9f344);
                }
              }
              else {
                DAT_01a9f308 = DAT_01a9f308 % 100;
                if (DAT_01a9f344 < 1) {
                  *(undefined4 *)(puVar7 + -0xec) = 0;
                  goto code_r0x00587686;
                }
                *(undefined4 *)(puVar7 + -0xf0) = 0;
              }
              if (-1 < DAT_01a9f308) {
                if (DAT_01a9f308 == 0) {
                  ffree(Var9);
                  Var9 = FUN_005898bc(&DAT_0076ae20,1);
                  *(undefined4 *)(puVar7 + -0xe0) = 0;
                  break;
                }
                goto code_r0x005876a9;
              }
              goto code_r0x005876b8;
            }
            *(undefined4 *)(puVar7 + -0xf8) = 0;
            goto code_r0x005876c7;
          }
          *(undefined4 *)(puVar7 + -0xfc) = 0;
        }
        DAT_01a9f348 = DAT_01a9f348 + 1;
      }
      DAT_01a9f348 = DAT_01a9f348 + 1;
      ffree(Var9);
      Var9 = FUN_005898eb(DAT_01a9f348 * 2 + 0x7a05ae,2,&DAT_01a1f4d4 + DAT_01a9f314,1);
      *(undefined4 *)(puVar7 + -0xe4) = 0;
      break;
    case 3:
      DAT_01a9f308 = 0;
      if (4 < LOAD_LEN) {
        fVar2 = (float)(&ITEM_P5)[LOAD_W];
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f308 = *(int *)(puVar7 + -0x19c);
      }
      if (4 < DAT_01a9f308) {
        DAT_01a9f308 = 0;
      }
      DAT_009a92b4 = DAT_01a9f308;
      DAT_01a9f314 = DAT_01a9f314 + 1;
      FUN_005f46bc(puVar7,&UNK_0058781e);
      Var9 = FUN_005f34d1(puVar7,&UNK_00587834);
      DAT_01a9f314 = DAT_01a9f314 + 1;
      *(undefined4 *)(puVar7 + -0xdc) = 0;
      break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
      DAT_01f95c8c = DAT_01f95c8c + 1;
      *(int *)(DAT_01f95c8c * 4 + 0x1a18598) = LOAD_W;
      *(undefined4 *)(puVar7 + -0x108) = 0;
      goto code_r0x00588334;
    case 8:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xf:
    case 0x10:
      goto LAB_00588362;
    case 0xe:
      if ((LOAD_LEN < 5) || ((float)(&ITEM_P5)[LOAD_W] <= f_7)) {
        ffree(Var9);
        Var9 = FUN_005898bc(&UNK_0076ae1c,1);
        DAT_01a9f308 = 1;
        if (3 < LOAD_LEN) {
          fVar2 = (float)(&ITEM_P4)[LOAD_W];
          *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
          *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
          *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
          uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
          DAT_01a9f308 = *(int *)(puVar7 + -0x19c);
        }
        if (DAT_01a9f308 < 0) {
          ffree(Var9);
          Var9 = FUN_005898bc(0x7a0595,1);
          *(undefined4 *)(puVar7 + -0xd0) = 0;
        }
        else {
          *(undefined4 *)(puVar7 + -0xd4) = 0;
          DAT_01a9f348 = 0;
          if (4 < LOAD_LEN) {
            fVar2 = (float)(&ITEM_P5)[LOAD_W];
            *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
            *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
            *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
            uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
            DAT_01a9f348 = *(int *)(puVar7 + -0x19c);
          }
          if ((DAT_01a9f348 == 0) || (7 < DAT_01a9f348)) {
            *(undefined4 *)(puVar7 + -0xcc) = 0;
          }
          else {
            ffree(Var9);
            Var9 = FUN_005898bc(DAT_01a9f348 + 0x7a058f,1);
            if (2 < DAT_01a9f348) {
              ffree(Var9);
              Var9 = FUN_005898bc(s_S0S_S__007a0580 + DAT_01a9f348 + 5,1);
            }
          }
          if (0 < DAT_01a9f308) {
            ffree(Var9);
            Var9 = FUN_0058982d(&DAT_01a9f308);
          }
          *(undefined4 *)(puVar7 + -200) = 0;
        }
        break;
      }
      *(undefined4 *)(puVar7 + -0xd8) = 0;
      goto LAB_00588362;
    case 0x11:
      fVar2 = (float)(&ITEM_P5)[LOAD_W];
      *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
      *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
      *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
      uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
      DAT_01a9f308 = *(int *)(puVar7 + -0x19c);
      uVar3 = UNK_0076ae18;
      if (DAT_01a9f308 < 0) {
        uVar3 = UNK_0076ae14;
      }
      DAT_01a9f330._0_2_ = CONCAT11(DAT_01a9f330._1_1_,uVar3);
      if (DAT_01a9f308 < 0) {
        DAT_01a9f308 = -DAT_01a9f308;
      }
      ffree(Var9);
      Var9 = FUN_005898bc(&UNK_0076ae10,1);
      *(int *)(puVar7 + -0x1a0) = DAT_01a9f308 % 100;
      ffree(Var9);
      Var9 = FUN_0058982d(puVar7 + -0x1a0);
      ffree(Var9);
      Var9 = FUN_005898bc(&DAT_01a9f330,1);
      if (100 < DAT_01a9f308) {
        ffree(Var9);
        Var9 = FUN_005898bc(&DAT_0076ae0c,1);
      }
      *(undefined4 *)(puVar7 + -0xc4) = 0;
      break;
    case 0x12:
      fVar2 = (float)(&ITEM_P5)[LOAD_W];
      *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
      *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
      *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
      uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
      DAT_01a9f308 = *(int *)(puVar7 + -0x19c);
      DAT_01a9f348 = 0;
      if (5 < LOAD_LEN) {
        fVar2 = (float)(&ITEM_P6)[LOAD_W];
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f348 = *(int *)(puVar7 + -0x19c);
      }
      if (DAT_01a9f308 < 0x62) {
        ffree(Var9);
        Var9 = FUN_0058982d(&DAT_01a9f308);
        ffree(Var9);
        Var9 = FUN_005898bc(&DAT_0076adfc,1);
        ffree(Var9);
        Var9 = FUN_0058982d(&DAT_01a9f348);
        *(undefined4 *)(puVar7 + -0xbc) = 0;
      }
      else {
        *(undefined4 *)(puVar7 + -0xc0) = 0;
        ffree(Var9);
        Var9 = FUN_005898bc(&DAT_0076ae08,1);
        DAT_01a9f330._0_2_ = _UNK_0076ae04;
        if (DAT_01a9f308 == 0x62) {
          DAT_01a9f330._0_2_ = _UNK_0076ae00;
        }
        ffree(Var9);
        Var9 = FUN_005898eb(&DAT_01a9f330,2,&DAT_01a1f4d4 + DAT_01a9f314,1);
      }
    }
    ffree(Var9);
    Var9 = FUN_005898bc(&DAT_0076adf8,1);
code_r0x00588334:
    DAT_020492a4 = DAT_020492a4 + 1;
    (&DAT_020492a4)[DAT_020492a4] = LOAD_W;
LAB_00588362:
    *(undefined4 *)(puVar7 + -0xb8) = 0;
    LOAD_I = LOAD_I + 1;
    *(int *)(puVar7 + -0x174) = *(int *)(puVar7 + -0x174) + -1;
    iVar6 = *(int *)(puVar7 + -0x174);
  }
  DAT_01a9f348 = 1;
  ffree(Var9);
  Var9 = FUN_0058a2ff(&DAT_01a9f314,&DAT_01a1f4d4,1);
  ffree(Var9);
  Var9 = FUN_0058a2ff(&DAT_01a9f318,&DAT_01a1f654,1);
  _DAT_009a92a4 = 0;
  DAT_01a9f314 = 0;
  DAT_01a9f318 = 0;
  *(int *)(puVar7 + -0xb4) = DAT_01f95c8c;
  DAT_009a929c = 1;
  _DAT_009a92a0 = f_0;
  iVar6 = DAT_01f95c8c;
  do {
    if (iVar6 < 1) {
      DAT_01a9f348 = 0;
      ffree(Var9);
      Var9 = FUN_0058976c(&DAT_01a1f7d4,1,&DAT_009a9290);
      ffree(Var9);
      Var9 = FUN_0058976c(&DAT_01a1f954,1,&DAT_009a928c);
      ffree(Var9);
      Var9 = FUN_0058976c(&DAT_01a1fad4,1,&DAT_009a9288);
      *(undefined4 *)(puVar7 + -0x198) = 0;
      *(undefined4 *)(puVar7 + -0x1a8) = 3;
      *(undefined **)(puVar7 + -0x1a4) = &DAT_0076adb8;
      *(undefined4 *)(puVar7 + -0x1a0) = 2;
      *(undefined4 *)(puVar7 + -0x19c) = 4;
      ffree(Var9);
      uVar5 = FUN_005f6540(puVar7 + -0x198,3,0x784ff01,&DAT_0076ada8,puVar7 + -0x1a8);
      *(undefined4 *)(puVar7 + -0x2c) = uVar5;
      if (*(int *)(puVar7 + -0x2c) == 0) {
        *(undefined4 *)(puVar7 + -0x198) = 0;
        *(undefined4 *)(puVar7 + -0x1a0) = 0x40;
        *(undefined4 **)(puVar7 + -0x19c) = &DAT_01a1f484;
        ffree(extraout_ST0);
        Var9 = FUN_005fc330(puVar7 + -0x198,3,0x784ff00,&DAT_0076ada4,puVar7 + -0x1a0,&DAT_007a04e8)
        ;
        *(undefined4 *)(puVar7 + -0x198) = 0;
        *(undefined4 *)(puVar7 + -0x1a0) = 0x10;
        *(undefined1 **)(puVar7 + -0x19c) = &DAT_01a1f4c4;
        ffree(Var9);
        Var9 = FUN_005fc330(puVar7 + -0x198,3,0x784ff00,&DAT_0076ada4,puVar7 + -0x1a0,&DAT_007a04fc)
        ;
        *(undefined4 *)(puVar7 + -0x20) = 0x180;
        DAT_01a9f308 = 1;
        do {
          if (*(char *)((int)&DAT_01a1f4d0 + DAT_01a9f308 + 3) == ';') {
            DAT_009a9284 = DAT_01a9f308;
          }
          if ((&DAT_01a1f653)[DAT_01a9f308] == ';') {
            DAT_009a9280 = DAT_01a9f308;
          }
          DAT_01a9f308 = DAT_01a9f308 + 1;
          *(int *)(puVar7 + -0x20) = *(int *)(puVar7 + -0x20) + -1;
        } while (0 < *(int *)(puVar7 + -0x20));
        *(undefined4 *)(puVar7 + -0x198) = 0;
        ffree(Var9);
        Var9 = FUN_005fc330(puVar7 + -0x198,3,0x784ff00,&DAT_0076ada0,0,&DAT_007a0510);
        DAT_01a9f308 = 1;
        for (iVar6 = DAT_009a9284; 0 < iVar6; iVar6 = iVar6 + -1) {
          *(undefined4 *)(puVar7 + -0x1a8) = 1;
          *(int *)(puVar7 + -0x1a4) = DAT_01a9f308 + 0x1a1f4d3;
          *(undefined4 *)(puVar7 + -0x1a0) = 1;
          ffree(Var9);
          Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad9c,puVar7 + -0x1a8);
          DAT_01a9f308 = DAT_01a9f308 + 1;
        }
        ffree(Var9);
        Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad98,0);
        *(undefined4 *)(puVar7 + -0x198) = 0;
        ffree(Var9);
        Var9 = FUN_005fc330(puVar7 + -0x198,3,0x784ff00,&DAT_0076ada0,0,&DAT_007a0524);
        DAT_01a9f308 = 1;
        for (iVar6 = DAT_009a9280; 0 < iVar6; iVar6 = iVar6 + -1) {
          *(undefined4 *)(puVar7 + -0x1a8) = 1;
          *(undefined **)(puVar7 + -0x1a4) = &DAT_01a1f653 + DAT_01a9f308;
          *(undefined4 *)(puVar7 + -0x1a0) = 1;
          ffree(Var9);
          Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad9c,puVar7 + -0x1a8);
          DAT_01a9f308 = DAT_01a9f308 + 1;
        }
        ffree(Var9);
        Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad98,0);
        *(undefined4 *)(puVar7 + -0x198) = 0;
        ffree(Var9);
        Var9 = FUN_005fc330(puVar7 + -0x198,3,0x784ff00,&DAT_0076ada0,0,&DAT_007a0538);
        DAT_01a9f308 = 1;
        for (iVar6 = DAT_009a9290; 0 < iVar6; iVar6 = iVar6 + -1) {
          *(undefined4 *)(puVar7 + -0x1a8) = 1;
          *(undefined **)(puVar7 + -0x1a4) = &DAT_01a1f7d3 + DAT_01a9f308;
          *(undefined4 *)(puVar7 + -0x1a0) = 1;
          ffree(Var9);
          Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad9c,puVar7 + -0x1a8);
          DAT_01a9f308 = DAT_01a9f308 + 1;
        }
        ffree(Var9);
        Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad98,0);
        *(undefined4 *)(puVar7 + -0x198) = 0;
        ffree(Var9);
        Var9 = FUN_005fc330(puVar7 + -0x198,3,0x784ff00,&DAT_0076ada0,0,&DAT_007a054c);
        DAT_01a9f308 = 1;
        for (iVar6 = DAT_009a928c; 0 < iVar6; iVar6 = iVar6 + -1) {
          *(undefined4 *)(puVar7 + -0x1a8) = 1;
          *(int *)(puVar7 + -0x1a4) = DAT_01a9f308 + 0x1a1f953;
          *(undefined4 *)(puVar7 + -0x1a0) = 1;
          ffree(Var9);
          Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad9c,puVar7 + -0x1a8);
          DAT_01a9f308 = DAT_01a9f308 + 1;
        }
        ffree(Var9);
        Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad98,0);
        *(undefined4 *)(puVar7 + -0x198) = 0;
        ffree(Var9);
        Var9 = FUN_005fc330(puVar7 + -0x198,3,0x784ff00,&DAT_0076ada0,0,&DAT_007a0560);
        DAT_01a9f308 = 1;
        for (iVar6 = DAT_009a9288; 0 < iVar6; iVar6 = iVar6 + -1) {
          *(undefined4 *)(puVar7 + -0x1a8) = 1;
          *(int *)(puVar7 + -0x1a4) = DAT_01a9f308 + 0x1a1fad3;
          *(undefined4 *)(puVar7 + -0x1a0) = 1;
          ffree(Var9);
          Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad9c,puVar7 + -0x1a8);
          DAT_01a9f308 = DAT_01a9f308 + 1;
        }
        ffree(Var9);
        Var9 = FUN_005fc980(puVar7 + -0x198,&DAT_0076ad98,0);
        *(undefined4 *)(puVar7 + -0x198) = 0;
        ffree(Var9);
        Var9 = FUN_005f7950(puVar7 + -0x198,3,0x784ff00,&DAT_0076ad94,0);
        DAT_01a18bdc = 1;
        *(int *)(puVar7 + -4) = DAT_020492a4;
        DAT_009a929c = 1;
        P2 = P1;
        DAT_01fb8c60 = P1;
        iVar6 = DAT_020492a4;
        while (iVar4 = DAT_020492a8, 0 < iVar6) {
          DAT_01a9f348 = (&DAT_020492a4)[DAT_009a929c];
          fVar2 = (float)(&ITEM_LEN)[DAT_01a9f348];
          *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
          *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
          *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2 + f_1);
          uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
          DAT_01a9f324 = *(int *)(puVar7 + -0x19c);
          (&DAT_01a18bdc)[DAT_009a929c] = (&DAT_01a18bd8)[DAT_009a929c] + DAT_01a9f324;
          ffree(Var9);
          Var9 = thunk_FUN_0054c590(&ITEM_LEN + DAT_01a9f348,
                                    (&DAT_01a18bd8)[DAT_009a929c] * 4 + 0x1a18e30,&DAT_01a9f324);
          DAT_009a929c = DAT_009a929c + 1;
          *(int *)(puVar7 + -4) = *(int *)(puVar7 + -4) + -1;
          iVar6 = *(int *)(puVar7 + -4);
        }
      }
      else {
        *(undefined4 *)(puVar7 + -0x3c) = 0;
        Var9 = extraout_ST0;
        iVar4 = ITEM_WORDS;
      }
      ITEM_WORDS = iVar4;
      ffree(Var9);
      return;
    }
    LOAD_W = *(int *)(DAT_009a929c * 4 + 0x1a18598);
    fVar2 = (float)(&ITEM_LEN)[LOAD_W];
    *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
    *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
    *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
    LOAD_LEN = *(int *)(puVar7 + -0x19c);
    fVar2 = (float)(&ITEM_P1)[LOAD_W];
    *(undefined2 *)(puVar7 + -0x1a0) = *(undefined2 *)(puVar7 + -0x1a0);
    *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
    *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
    uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
    LOAD_CODE = *(int *)(puVar7 + -0x19c);
    DAT_01a9f348 = 0;
    if (4 < LOAD_LEN) {
      fVar2 = (float)(&ITEM_P5)[LOAD_W];
      *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
      *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
      *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
      uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
      DAT_01a9f348 = *(int *)(puVar7 + -0x19c);
    }
    LOAD_P3 = (float)(&ITEM_P3)[LOAD_W];
    if (LOAD_CODE == 9) {
      DAT_01f95c8c = 0;
      if ((0x32 < DAT_01a9f348) && (DAT_01a9f348 < 0x45)) {
        DAT_01f95c8c = 1;
      }
      fVar2 = (float)(&ITEM_P4)[LOAD_W];
      *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
      *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
      *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
      uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
      DAT_009a92b4 = *(int *)(puVar7 + -0x19c);
      if (DAT_01f95c8c == 0) {
        *(undefined4 *)(puVar7 + -0xac) = 0;
LAB_00588e21:
        if (3 < DAT_009a92b4) {
          ffree(Var9);
          Var9 = FUN_0058a182(&DAT_0076adc4,1);
        }
        *(undefined4 *)(puVar7 + -0xa4) = 0;
      }
      else {
        LOAD_P3 = LOAD_P3 + f_0_5;
        if ((DAT_01a9f348 != 0x42) && (DAT_01a9f348 != 0x43)) goto LAB_00588e21;
        *(undefined4 *)(puVar7 + -0xa8) = 0;
        if (DAT_009a92b4 < 0xb) {
          ffree(Var9);
          Var9 = FUN_0058a182(&DAT_0076adc0,1);
        }
      }
      ffree(Var9);
      Var9 = FUN_0058abf6();
      if (DAT_01f95c8c == 0) {
        ffree(Var9);
        Var9 = FUN_0058a182(&DAT_0076ae0c,1);
        DAT_01f95c90 = (float)DAT_01a9f348;
        ffree(Var9);
        Var9 = FUN_0058a88e(&DAT_0076ad90,&DAT_01f95c90,&DAT_01a9f320,&DAT_01a1f7d4,1);
        *(undefined4 *)(puVar7 + -0x9c) = 0;
LAB_00588f6c:
        DAT_01a9f320 = DAT_01a9f320 + -1;
        *(undefined4 *)(puVar7 + -0x88) = 0;
LAB_00588f85:
        ffree(Var9);
        Var9 = FUN_0058abf6();
      }
      else {
        *(undefined4 *)(puVar7 + -0xa0) = 0;
        if (0x3b < DAT_01a9f348) {
          DAT_01a9f348 = DAT_01a9f348 + -1;
        }
        ffree(Var9);
        Var9 = FUN_0058a2d2(&DAT_01a9f348,&DAT_01a1f7d4 + DAT_01a9f320,1);
        DAT_01a9f320 = DAT_01a9f320 + 3;
        while ((&DAT_01a1f7d3)[DAT_01a9f320] == ' ') {
          DAT_01a9f320 = DAT_01a9f320 + -1;
          *(undefined4 *)(puVar7 + -0x94) = 0;
        }
        *(undefined4 *)(puVar7 + -0x98) = 0;
      }
      ffree(Var9);
      Var9 = FUN_0058a88e(&DAT_0076ae30,&DAT_01a9f310,&DAT_01a9f320,&DAT_01a1f7d4,1);
LAB_00588fba:
      *(undefined4 *)(puVar7 + -0x34) = 0;
    }
    else {
      *(undefined4 *)(puVar7 + -0xb0) = 0;
      ffree(Var9);
      Var9 = FUN_0058abf6();
      if (LOAD_CODE == 4) {
        if (DAT_01a9f348 == 999) {
          if (f_3 < (float)(&ITEM_P4)[LOAD_W]) {
            ffree(Var9);
            Var9 = FUN_0058a182(&DAT_0076adc4,1);
          }
          ffree(Var9);
          Var9 = FUN_0058a182(&DAT_0076ae08,1);
          if ((6 < LOAD_LEN) && (*(float *)(&ITEM_P7 + LOAD_W * 4) < f_0)) {
            ffree(Var9);
            Var9 = FUN_0058a182(&DAT_0076adc0,1);
          }
          goto LAB_00588d18;
        }
        *(undefined4 *)(puVar7 + -0x8c) = 0;
        goto LAB_00588fba;
      }
      *(undefined4 *)(puVar7 + -0x90) = 0;
      DAT_01a9f348 = 0;
      if (6 < LOAD_LEN) {
        fVar2 = *(float *)(&ITEM_P7 + LOAD_W * 4);
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f348 = *(int *)(puVar7 + -0x19c);
      }
      if (LOAD_CODE == 7) {
        iVar6 = DAT_01a9f348;
        if (DAT_01a9f348 < 0) {
          iVar6 = -DAT_01a9f348;
        }
        if (iVar6 == 8) {
          ffree(Var9);
          Var9 = FUN_0058a182(&DAT_0076adf0,1);
          if (DAT_01a9f348 < 0) {
            ffree(Var9);
            Var9 = FUN_0058a182(&DAT_0076adcc,1);
          }
          *(undefined4 *)(puVar7 + -0x7c) = 0;
        }
        else {
          *(undefined4 *)(puVar7 + -0x80) = 0;
          if (DAT_01a9f348 != 0) {
            *(undefined4 *)(puVar7 + -0x78) = 0;
            goto LAB_00588fba;
          }
          ffree(Var9);
          Var9 = FUN_0058a182(&DAT_0076add4,1);
          ffree(Var9);
          Var9 = FUN_0058a182(&DAT_0076ae20,1);
          if (LOAD_LEN < 8) {
            *(undefined4 *)(puVar7 + -0x74) = 0;
          }
          else {
            fVar2 = *(float *)(&ITEM_P8 + LOAD_W * 4);
            *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
            *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
            *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
            uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
            DAT_01a9f348 = *(int *)(puVar7 + -0x19c);
            if (DAT_01a9f348 != 0) {
              ffree(Var9);
              Var9 = FUN_0058a182(&DAT_007a0597 + DAT_01a9f348,1);
            }
          }
          ffree(Var9);
          Var9 = FUN_0058a182(&DAT_0076add0,1);
          *(undefined4 *)(puVar7 + -0x70) = 0;
        }
LAB_00588d18:
        ffree(Var9);
        Var9 = FUN_0058a88e(&DAT_0076ae30,&DAT_01a9f310,&DAT_01a9f320,&DAT_01a1f7d4,1);
        LOAD_P3 = (float)(&ITEM_P6)[LOAD_W];
        if (LOAD_CODE == 7) {
          LOAD_P3 = LOAD_P3 - f_4_167;
        }
        goto LAB_00588f6c;
      }
      *(undefined4 *)(puVar7 + -0x84) = 0;
      if (LOAD_CODE != 5) {
        *(undefined4 *)(puVar7 + -0x6c) = 0;
        if (-1 < DAT_01a9f348) {
          *(undefined4 *)(puVar7 + -0x38) = 0;
          goto LAB_00588716;
        }
        puVar1 = &DAT_01a1f7d4 + DAT_01a9f320;
        DAT_01a9f320 = DAT_01a9f320 + 1;
        *puVar1 = 0x54;
        puVar1 = &DAT_01a1f7d4 + DAT_01a9f320;
        DAT_01a9f320 = DAT_01a9f320 + 1;
        *puVar1 = 0x4d;
        fVar2 = *(float *)(&ITEM_P10 + LOAD_W * 4);
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f348 = *(int *)(puVar7 + -0x19c) % 10;
        puVar7[-0x199] = (char)DAT_01a9f348 + '0';
        puVar1 = &DAT_01a1f7d4 + DAT_01a9f320;
        DAT_01a9f320 = DAT_01a9f320 + 1;
        *puVar1 = puVar7[-0x199];
        if ((10 < LOAD_LEN) && (*(float *)(&ITEM_P11 + LOAD_W * 4) != f_0)) {
          LOAD_P3 = *(float *)(&ITEM_P11 + LOAD_W * 4);
        }
        goto LAB_00588f85;
      }
LAB_00588716:
      ffree(Var9);
      Var9 = FUN_0058abf6();
      DAT_009a9298 = DAT_01a9f310;
      LOAD_P3 = (float)(&ITEM_P6)[LOAD_W];
      ffree(Var9);
      Var9 = FUN_0058abf6();
      DAT_01a9f324 = 0;
      if (7 < LOAD_LEN) {
        fVar2 = *(float *)(&ITEM_P8 + LOAD_W * 4);
        *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
        *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
        *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
        uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
        DAT_01a9f324 = *(int *)(puVar7 + -0x19c);
      }
      if ((LOAD_CODE == 5) && (DAT_01a9f324 < -1)) {
        DAT_01a9f310 = DAT_01a9f310 + f_1_0Em4;
      }
      if (((DAT_01a9f310 != _DAT_009a9294) || (LOAD_CODE != _DAT_009a92a4)) ||
         (DAT_009a9298 != _DAT_009a92a0)) {
        _DAT_009a92a4 = LOAD_CODE;
        _DAT_009a92a0 = DAT_009a9298;
        _DAT_009a9294 = DAT_01a9f310;
        DAT_01f95c84 = 1;
        DAT_01f95c90 = *(float *)(&ITEM_P7 + LOAD_W * 4);
        if (LOAD_CODE == 6) {
          *(undefined4 *)(puVar7 + -100) = 0;
          if (f_20 <= DAT_01f95c90) {
            DAT_01f95c84 = -1;
          }
          if (DAT_009a9298 < f_1) {
            DAT_009a9298 = f_1;
          }
          if ((float)DAT_01a9f30c < DAT_01a9f310) {
            DAT_01a9f310 = (float)DAT_01a9f30c;
          }
          ffree(Var9);
          fVar10 = (float10)FUN_0058a88e(&DAT_0076ad90,&DAT_009a9298,&DAT_01a9f314,&DAT_01a1f954,1);
          if (DAT_01a9f324 == 0) {
            *(undefined4 *)(puVar7 + -0x4c) = 0;
          }
          else {
LAB_00588a76:
            *(int *)(puVar7 + -0x19c) = DAT_01a9f324 * 100;
            DAT_01a9f310 = (float)*(int *)(puVar7 + -0x19c) + DAT_01a9f310;
          }
        }
        else {
          if ((DAT_01a9f324 == 1) || (DAT_01a9f324 == 2)) {
            *(undefined4 *)(puVar7 + -0x60) = 0;
            goto LAB_00588fba;
          }
          fVar10 = (float10)DAT_01a9f310;
          if ((float10)DAT_01a9f30c < fVar10 - (float10)f_0_001) {
            if ((DAT_01a9f324 == -1) || (DAT_009a9298 < (float)DAT_01a9f30c)) {
              DAT_01a9f310 = f_99;
            }
          }
          else {
            *(undefined4 *)(puVar7 + -0x5c) = 0;
          }
          if (DAT_01f95c90 < f_0) {
            DAT_01f95c84 = -1;
          }
          if (DAT_009a9298 < f_1) {
            DAT_009a9298 = f_99;
            if (DAT_01a9f324 != -1) {
              DAT_009a9298 = f_0;
            }
          }
          else {
            *(undefined4 *)(puVar7 + -0x58) = 0;
          }
          ffree(fVar10 - (float10)f_0_001);
          fVar10 = (float10)FUN_0058a88e(&DAT_0076ad90,&DAT_009a9298,&DAT_01a9f318,&DAT_01a1fad4,1);
          if (DAT_01a9f324 == 3) {
            if ((8 < LOAD_LEN) && (*(float *)(&ITEM_P9 + LOAD_W * 4) != f_0)) {
              fVar2 = *(float *)(&ITEM_P9 + LOAD_W * 4);
              *(undefined2 *)(puVar7 + -0x1a0) = uVar8;
              *(ushort *)(puVar7 + -0x19e) = (ushort)*(undefined4 *)(puVar7 + -0x1a0) | 0xc00;
              *(int *)(puVar7 + -0x19c) = (int)ROUND(fVar2);
              uVar8 = *(undefined2 *)(puVar7 + -0x1a0);
              DAT_01a9f324 = *(int *)(puVar7 + -0x19c);
            }
            *(undefined4 *)(puVar7 + -0x50) = 0;
            goto LAB_00588a76;
          }
          *(undefined4 *)(puVar7 + -0x54) = 0;
        }
        if (0 < DAT_01f95c84) {
          DAT_01a9f310 = DAT_01a9f310 + f_10000;
        }
        if (DAT_01f95c84 < 0) {
          fVar10 = (float10)DAT_01a9f310;
          DAT_01a9f310 = (float)-fVar10;
        }
        if (LOAD_CODE == 5) {
          *(undefined4 *)(puVar7 + -0x48) = 0;
          ffree(fVar10);
          Var9 = FUN_0058a88e(&DAT_0076add8,&DAT_01a9f310,&DAT_01a9f318,&DAT_01a1fad4,1);
          *(undefined4 *)(puVar7 + -0x40) = 0;
        }
        else {
          ffree(fVar10);
          Var9 = FUN_0058a88e(&DAT_0076add8,&DAT_01a9f310,&DAT_01a9f314,&DAT_01a1f954,1);
          *(undefined4 *)(puVar7 + -0x44) = 0;
        }
        goto LAB_00588fba;
      }
      *(undefined4 *)(puVar7 + -0x68) = 0;
    }
    *(undefined4 *)(puVar7 + -0x30) = 0;
    DAT_009a929c = DAT_009a929c + 1;
    *(int *)(puVar7 + -0xb4) = *(int *)(puVar7 + -0xb4) + -1;
    iVar6 = *(int *)(puVar7 + -0xb4);
  } while( true );
}


