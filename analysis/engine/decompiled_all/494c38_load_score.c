// load_score @ 00494c38 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00494cb8) */
/* WARNING: Removing unreachable block (ram,0x00494d55) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void load_score(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  bool bVar11;
  undefined2 in_FPUControlWord;
  undefined1 *puVar12;
  int local_d8;
  
  puVar12 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  if ((DAT_009ae2bc & 0xffffff) != 0x527e7e) {
    if ((short)DAT_01c4cb60 != 0x5c5c) {
      local_d8 = 0x7f;
      DAT_0082a1f8 = 2;
      do {
        iVar4 = FUN_005f4660(0x20);
        if (iVar4 != 0) break;
        DAT_0082a1f8 = DAT_0082a1f8 + 1;
        local_d8 = local_d8 + -1;
      } while (0 < local_d8);
      DAT_0082a1f4 = DAT_0082a1f8 + 1;
      iVar4 = (DAT_0082a1f8 - DAT_0082a1f4) + 5;
      while ((0 < iVar4 && (iVar2 = FUN_00601a30(0x20), iVar2 == 0))) {
        DAT_0082a1f4 = DAT_0082a1f4 + 1;
        iVar4 = iVar4 + -1;
      }
      FUN_005f46bc(&stack0xfffffffc,0x494dec);
      puVar5 = puVar12;
      FUN_005f34d1(puVar12,0x494e02);
    }
    *(undefined4 *)(puVar5 + -0xfc) = 0;
    *(undefined4 *)(puVar5 + -0x110) = 0x80;
    *(undefined4 **)(puVar5 + -0x10c) = &DAT_01c4cb60;
    *(uint **)(puVar5 + -0x108) = &DAT_0082a1fc;
    FUN_005f47c0(puVar5 + -0xfc,0xffffffff,0x784ff00,&DAT_007630e8,puVar5 + -0x110);
    if ((DAT_0082a1fc & 1) == 0) {
      thunk_FUN_0042ac4e(&DAT_01c4cb60,0x80);
      puVar7 = &DAT_0082a20c;
      puVar9 = &DAT_01b12cc0;
      for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      DAT_01b12d40 = DAT_0082a1f0;
      DAT_0078b4e0 = 0;
      DAT_0078b4e4 = 0;
      draw_items();
      *(undefined4 *)(puVar5 + -0xbc) = 0;
      return;
    }
    *(undefined4 *)(puVar5 + -0xc0) = 0;
    puVar6 = puVar5;
  }
  DAT_0082a1ec = DAT_0078de00;
  thunk_FUN_004a5309(&DAT_01c4cb60,0x80);
  puVar7 = &DAT_01b12cc0;
  puVar9 = &DAT_0082a20c;
  for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  DAT_0082a1f0 = DAT_01b12d40;
  DAT_0082a1e8 = 0;
  LOAD_LEN = ITEM_WORDS;
  if (DAT_0078b4e4 == 0x4d) {
    *(undefined4 *)(puVar6 + -0xb8) = 0;
    if (DAT_0078b378 == 2) {
      *(undefined4 *)(puVar6 + -0xb0) = 0;
      if (DAT_0078de00 == 0) {
        DAT_0078de00 = 1;
      }
LAB_00495267:
      if (DAT_01b12cb8 != 0) {
        (&DAT_01b12ca8)[DAT_01b12cb8] = DAT_0078de00;
      }
      goto LAB_00495297;
    }
    DAT_0078de00 = 0;
    DAT_0082a1e4 = DAT_0078b4e4;
    if (DAT_01b12cb8 == 0) {
      if ((_DAT_020b8ea0 & 0xffffff) == 0x524d47) {
        DAT_0078de00 = 0xc9;
        *(undefined4 *)(puVar6 + -0xac) = 0;
      }
      else {
        if ((_DAT_020b8ea0 & 0xffffff) != 0x4c4d47) {
          DAT_0082a1e8 = 1;
          if (DAT_02052740 == 5) {
            *(undefined4 *)(puVar6 + -0xa4) = 0;
            goto LAB_0049515f;
          }
          DAT_02091d04 = 0xfffffb2e;
          thunk_FUN_0054e546(&DAT_0082a208,&DAT_0082a1e0);
          if ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x49) {
            *(undefined2 *)(puVar6 + -0x104) = in_FPUControlWord;
            *(ushort *)(puVar6 + -0x102) = (ushort)*(undefined4 *)(puVar6 + -0x104) | 0xc00;
            *(int *)(puVar6 + -0x100) = (int)ROUND(DAT_0082a208);
            in_FPUControlWord = *(undefined2 *)(puVar6 + -0x104);
            *(undefined4 *)(puVar6 + -0xfc) = 0;
            *(undefined4 *)(puVar6 + -0x110) = 3;
            *(uint **)(puVar6 + -0x10c) = &DAT_009ae2bc;
            *(undefined4 *)(puVar6 + -0x108) = *(undefined4 *)(puVar6 + -0x100);
            FUN_005f34f0(puVar6 + -0xfc,0x784ff00,&DAT_007630e0,puVar6 + -0x110,&DAT_00791678);
            if (DAT_0078dd50 != -0x241c) {
              *(undefined4 *)(puVar6 + -0x98) = 0;
              DAT_009ae2bc = DAT_009ae2bc & 0xffffff;
              thunk_FUN_00571f5d("Type a number for staff offset.",0x1f);
              DAT_02091d04 = 0;
              if ((char)DAT_020b8ea0 == '\x02') {
                *(undefined4 *)(puVar6 + -0x90) = 0;
                goto LAB_00495b72;
              }
              goto LAB_00495148;
            }
            P1 = DAT_0082a208;
            *(undefined4 *)(puVar6 + -0x94) = 0;
            goto LAB_00495170;
          }
          *(undefined2 *)(puVar6 + -0x104) = in_FPUControlWord;
          *(ushort *)(puVar6 + -0x102) = (ushort)*(undefined4 *)(puVar6 + -0x104) | 0xc00;
          *(int *)(puVar6 + -0x100) = (int)ROUND(DAT_0082a208);
          in_FPUControlWord = *(undefined2 *)(puVar6 + -0x104);
          DAT_0082a1dc = *(int *)(puVar6 + -0x100);
          *(undefined4 *)(puVar6 + -0xa0) = 0;
          goto LAB_00495200;
        }
        DAT_0078de00 = 1;
        if (DAT_0082a1ec != 0) {
          DAT_0078de00 = DAT_0082a1ec;
        }
        *(undefined4 *)(puVar6 + -0xa8) = 0;
      }
LAB_0049523f:
      _DAT_01e66d00 = 0;
      _DAT_0082a1d8 = (&DAT_02091d20)[ITEM_I] + -1;
      *(undefined4 *)(puVar6 + -0x88) = 0;
      goto LAB_00495267;
    }
LAB_00495148:
    DAT_0082a1dc = DAT_0078b378;
    DAT_0078b378 = 0x1b;
LAB_0049515f:
    thunk_FUN_00518448();
    DAT_0078b378 = DAT_0082a1dc;
LAB_00495170:
    DAT_0078dd50 = 0;
    DAT_0078b4e4 = DAT_0082a1e4;
    FUN_005f33c9(puVar6,0x4951a2);
    FUN_005f34d1(puVar6,0x4951bd);
    *(undefined2 *)(puVar6 + -0x104) = in_FPUControlWord;
    *(ushort *)(puVar6 + -0x102) = (ushort)*(undefined4 *)(puVar6 + -0x104) | 0xc00;
    *(int *)(puVar6 + -0x100) = (int)ROUND(P1);
    in_FPUControlWord = *(undefined2 *)(puVar6 + -0x104);
    DAT_0082a1dc = *(int *)(puVar6 + -0x100);
LAB_00495200:
    P1 = f_0;
    if ((DAT_0082a1dc != 0) || (DAT_01b12cb8 == 0)) {
      DAT_0078de00 = DAT_0082a1e8 + DAT_0082a1dc;
      goto LAB_0049523f;
    }
    *(undefined4 *)(puVar6 + -0x8c) = 0;
    goto LAB_0049561c;
  }
  DAT_0078b4f0 = 0;
  *(undefined4 *)(puVar6 + -0xb4) = 0;
LAB_00495297:
  *(undefined4 *)(puVar6 + -0x84) = 0;
  DAT_0082a1d4 = DAT_0078b4e8;
  DAT_0082a1d0 = 3;
  thunk_FUN_0054cd71(&DAT_01c4cb60,0x80,&DAT_007630b4,&DAT_0082a1cc);
  thunk_FUN_00529628(&DAT_0082a1d0,&LOAD_LEN,&DAT_01e99980,&DAT_0082a1c8,&DAT_01c4cb60,0x80);
  if (DAT_0078b4e0 == -99) {
    *(undefined4 *)(puVar6 + -0x80) = 0;
    return;
  }
  if (DAT_0078b4e0 < 0) {
    *(undefined4 *)(puVar6 + -0x7c) = 0;
LAB_00495623:
    if (DAT_01b12cb8 != 0) {
      (&DAT_01b12c9c)[DAT_01b12cb8] = 0;
      (&DAT_01b12ca8)[DAT_01b12cb8] = 0;
      DAT_01b12cb8 = 0;
    }
    DAT_0078de00 = DAT_0082a1ec;
  }
  else {
    if (DAT_0078b4e4 == 0x4d) {
      DAT_0078b4f0 = 1;
    }
    else {
      puVar7 = &DAT_01c4cb60;
      puVar9 = &DAT_0078b510;
      for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      if (DAT_0078b690 == 0x504d542e) {
        *(undefined4 *)(puVar6 + -0x78) = 0;
      }
      else {
        DAT_0078b4f0 = 0;
        FUN_005f33c9(puVar6,0x49539e);
        FUN_005f34d1(puVar6,0x4953b9);
        *(undefined4 *)(puVar6 + -0xfc) = 0;
        *(undefined4 *)(puVar6 + -0x118) = 0x80;
        *(undefined **)(puVar6 + -0x114) = &DAT_0082a28c;
        *(undefined4 *)(puVar6 + -0x110) = 7;
        *(char **)(puVar6 + -0x10c) = "unknown";
        *(undefined4 *)(puVar6 + -0x108) = 2;
        uVar3 = FUN_005f6540(puVar6 + -0xfc,7,0x784ff01,&DAT_00763084,puVar6 + -0x118);
        *(undefined4 *)(puVar6 + -0x74) = uVar3;
        if (*(int *)(puVar6 + -0x74) != 0) goto LAB_00495cb8;
        *(undefined4 *)(puVar6 + -0xfc) = 0;
        *(undefined4 *)(puVar6 + -0x108) = 0x80;
        *(undefined4 **)(puVar6 + -0x104) = &DAT_01c4cb60;
        uVar3 = FUN_005fc330(puVar6 + -0xfc,7,0x784ff01,&DAT_00763080,puVar6 + -0x108,&DAT_0079168c)
        ;
        *(undefined4 *)(puVar6 + -0x70) = uVar3;
        if (*(int *)(puVar6 + -0x70) != 0) goto LAB_00495cb8;
        *(undefined4 *)(puVar6 + -0xfc) = 0;
        FUN_005f7950(puVar6 + -0xfc,7,0x784ff00,&DAT_0076307c,0);
      }
    }
    if (DAT_0078b4e0 < 0) {
      *(undefined4 *)(puVar6 + -0x68) = 0;
      goto LAB_00495623;
    }
    if (DAT_0078b4e4 == 0x4d) {
      DAT_020527a0 = ITEM_WORDS;
    }
    DAT_0082a1d0 = LOAD_LEN + ITEM_WORDS + -1;
    if (DAT_0082a1d0 < 4) {
      *(undefined4 *)(puVar6 + -100) = 0;
      return;
    }
    if (DAT_0082a1d0 <= DAT_020b8e20) {
      *(undefined4 *)(puVar6 + -0x60) = 0;
      thunk_FUN_0054c590(&DAT_01e99980,&ITEM_LEN + ITEM_WORDS,&LOAD_LEN);
      iVar4 = ITEM_I + 1;
      ITEM_I = ITEM_I + 1;
      if (DAT_0078b4e4 != 0x4d) {
        _DAT_020b8e40 = 0;
        *(undefined4 *)(puVar6 + -0x54) = 0;
LAB_004956af:
        DAT_0078de00 = DAT_0082a1ec;
        _DAT_00793ab0 = NPT;
        IP12 = 1;
        thunk_FUN_00545752(&LOAD_LEN);
        if (DAT_0078b4e4 == 0x1a0a) {
          *(undefined4 *)(puVar6 + -0x48) = 0;
          return;
        }
        if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x49) {
          index_items();
          *(int *)(puVar6 + -0x44) = ITEM_I;
          LOAD_I = 1;
          iVar4 = ITEM_I;
          while (0 < iVar4) {
            load_item_header();
            if ((((LOAD_CODE == 8) && (LOAD_STAFF == 1)) &&
                (_DAT_0082a200 = *(float *)(&ITEM_P8 + LOAD_W * 4), 7 < LOAD_LEN)) &&
               (_DAT_0082a200 != f_0)) {
              if (DAT_0078b4e8 == 1) {
                _DAT_0082a200 = _DAT_0082a200 / f_2_54;
              }
              fVar1 = *(float *)(&ITEM_P8 + LOAD_W * 4);
              *(undefined2 *)(puVar6 + -0x104) = in_FPUControlWord;
              *(ushort *)(puVar6 + -0x102) = (ushort)*(undefined4 *)(puVar6 + -0x104) | 0xc00;
              *(int *)(puVar6 + -0x100) = (int)ROUND(fVar1 * f_4000 - f_24000);
              DAT_0082a1c0 = *(int *)(puVar6 + -0x100);
              *(undefined4 *)(puVar6 + -0x40) = 0;
              goto LAB_00495911;
            }
            LOAD_I = LOAD_I + 1;
            *(int *)(puVar6 + -0x44) = *(int *)(puVar6 + -0x44) + -1;
            iVar4 = *(int *)(puVar6 + -0x44);
          }
          FUN_005f33c9(puVar6,0x495832);
          FUN_005f34d1(puVar6,0x49584d);
          thunk_FUN_00571f5d(&DAT_00763038,0x31);
          DAT_02091d04 = 0;
          puVar7 = &DAT_009ae2bc;
          puVar9 = (undefined4 *)&DAT_020b8ea0;
          for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
          }
          thunk_FUN_00518448();
          if ((P1 == f_0) || ((char)DAT_020b8ea0 == '\x02')) {
            *(undefined4 *)(puVar6 + -0x3c) = 0;
            ITEM_WORDS = DAT_020527a0;
            return;
          }
          if (DAT_0078b4e8 == 1) {
            P1 = P1 / f_2_54;
          }
          *(undefined2 *)(puVar6 + -0x104) = in_FPUControlWord;
          *(ushort *)(puVar6 + -0x102) = (ushort)*(undefined4 *)(puVar6 + -0x104) | 0xc00;
          *(int *)(puVar6 + -0x100) = (int)ROUND(P1 * f_4000 - f_24000);
          DAT_0082a1c0 = *(int *)(puVar6 + -0x100);
LAB_00495911:
          *(int *)(puVar6 + -0x38) = ITEM_I;
          LOAD_I = 1;
          iVar4 = ITEM_I;
          while (0 < iVar4) {
            load_item_header();
            if (LOAD_CODE == 8) {
              if (DAT_0082a1dc + 1 == LOAD_STAFF) {
                _DAT_0082a1bc = LOAD_STAFF * 0xc4e + -0x6a0e;
                _DAT_0082a1b8 = DAT_0082a1c0 - _DAT_0082a1bc;
                _DAT_0082a1b4 = (float)(&ITEM_P4)[LOAD_W];
                _DAT_0082a204 = 1;
                _DAT_0082a1b0 = (float)(&STAFF_STEP0)[LOAD_STAFF] * f_7;
                (&ITEM_P4)[LOAD_W] = (float)_DAT_0082a1b8 / _DAT_0082a1b0;
                _DAT_0082a1b4 = (_DAT_0082a1b4 - (float)(&ITEM_P4)[LOAD_W]) * _DAT_0082a1b0;
                DAT_0082a1ac = LOAD_STAFF + 1;
              }
              else {
                *(undefined4 *)(puVar6 + -0x30) = 0;
              }
            }
            else {
              *(undefined4 *)(puVar6 + -0x34) = 0;
            }
            *(undefined4 *)(puVar6 + -0x2c) = 0;
            LOAD_I = LOAD_I + 1;
            *(int *)(puVar6 + -0x38) = *(int *)(puVar6 + -0x38) + -1;
            iVar4 = *(int *)(puVar6 + -0x38);
          }
          *(int *)(puVar6 + -0x28) = ITEM_I;
          LOAD_I = 1;
          iVar4 = ITEM_I;
          while (0 < iVar4) {
            load_item_header();
            if (LOAD_CODE == 8) {
              if (LOAD_STAFF < DAT_0082a1ac) {
                *(undefined4 *)(puVar6 + -0x20) = 0;
              }
              else {
                _DAT_0082a1b0 = (float)(&ITEM_P5)[LOAD_W] * f_175;
                if ((LOAD_LEN < 5) || (_DAT_0082a1b0 == f_0)) {
                  _DAT_0082a1b0 = f_175;
                }
                _DAT_0082a200 = _DAT_0082a1b4 / ((float)(&STAFF_STEP0)[LOAD_STAFF] * f_7);
                (&ITEM_P4)[LOAD_W] = (float)(&ITEM_P4)[LOAD_W] - _DAT_0082a200;
              }
            }
            else {
              *(undefined4 *)(puVar6 + -0x24) = 0;
            }
            *(undefined4 *)(puVar6 + -0x1c) = 0;
            LOAD_I = LOAD_I + 1;
            *(int *)(puVar6 + -0x28) = *(int *)(puVar6 + -0x28) + -1;
            iVar4 = *(int *)(puVar6 + -0x28);
          }
        }
        DAT_0082a1dc = DAT_02052740;
        if (-1 < DAT_02052740) {
          DAT_02052740 = -1;
        }
        IP1 = 0;
LAB_00495b72:
        bVar11 = true;
        *(undefined4 *)(puVar6 + -0x18) = 0;
        iVar4 = 3;
        pcVar8 = (char *)((int)&DAT_0078b518 + 3);
        pcVar10 = "DO!";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar11 = *pcVar8 == *pcVar10;
          pcVar8 = pcVar8 + 1;
          pcVar10 = pcVar10 + 1;
        } while (bVar11);
        if ((bVar11) || (_DAT_01b12c50 != f_0)) {
          draw_items();
        }
        else {
          _DAT_0082a204 = 1;
          thunk_FUN_00535d00(&DAT_0082a204);
          puVar7 = &DAT_01c4cb60;
          puVar9 = &DAT_0078b510;
          for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
          }
        }
        DAT_020527e8 = ITEM_I;
        DAT_02052740 = DAT_0082a1dc;
        if ((DAT_01e62c98 == 0) && (DAT_0082a1dc == 0)) {
          DAT_0078b4e4 = 0x48;
        }
        else {
          *(undefined4 *)(puVar6 + -0x14) = 0;
        }
        DAT_0078d8e0 = 0;
        DAT_01e62c98 = 0;
        while( true ) {
          DAT_0078d8e0 = DAT_0078d8e0 + 1;
          if ((float)(&ITEM_LEN)[(&ITEM_PTR0)[DAT_0078d8e0]] < f_3) {
            thunk_FUN_005239c9(&DAT_0078d8e0,&f_3);
          }
          if (ITEM_I <= DAT_0078d8e0) break;
          *(undefined4 *)(puVar6 + -0x10) = 0;
        }
        thunk_FUN_0054e9f2();
        DAT_0078b4ec = 0;
        FUN_00495d4f(&DAT_0078b510,0x80);
        *(undefined4 *)(puVar6 + -0xc) = 0;
        return;
      }
      *(undefined4 *)(puVar6 + -0x58) = 0;
      DAT_0078b4e8 = DAT_0082a1d4;
      ITEM_I = iVar4;
      FUN_00496388(&LOAD_LEN);
      if ((DAT_01b12c8c & 1) == 0) {
        _DAT_0082a1c4 = (&ITEM_PTR0)[ITEM_I];
        _DAT_0082a1d8 = DAT_01b12c80;
        _DAT_01e66d00 = 1;
        if ((DAT_01b12c8c & 1) == 0) {
          _DAT_01b12c60 = NPT;
          _DAT_01b12c64 = ITEM_WORDS;
          _DAT_01b12c68 = ITEM_I + -1;
          _DAT_01b12c6c = 1;
          goto LAB_004956af;
        }
        *(undefined4 *)(puVar6 + -0x4c) = 0;
      }
      else {
        *(undefined4 *)(puVar6 + -0x50) = 0;
      }
LAB_0049561c:
      *(undefined4 *)(puVar6 + -8) = 0;
      goto LAB_00495623;
    }
    *(undefined4 *)(puVar6 + -0x5c) = 0;
  }
  *(undefined4 *)(puVar6 + -4) = 0;
LAB_00495cb8:
  if (DAT_0078b4e4 == 0x4d) {
    _DAT_0078b694 = 1;
  }
  if (DAT_01b12cb8 != 0) {
    (&DAT_01b12c9c)[DAT_01b12cb8] = 1;
    DAT_01b12cb8 = 0;
  }
  _DAT_0082a1a8 = 0;
  return;
}


