// FUN_0041c3b8 @ 0041c3b8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0041c84c) */
/* WARNING: Removing unreachable block (ram,0x0041d43a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041c3b8(void)

{
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  short *psVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  char *pcVar10;
  short *psVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  char *pcVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  undefined1 uVar18;
  undefined2 in_FPUControlWord;
  float10 fVar19;
  
  puVar6 = &stack0xfffffffc;
  thunk_FUN_00597b60(0xffffffff);
  _DAT_007d1654 = STEP / f_25;
  DAT_0078cae8 = f_5;
  if (_DAT_007d1654 < f_1) {
    DAT_0078cae8 = _DAT_007d1654 * f_4 + f_1;
  }
  DAT_007d1650 = 0;
  DAT_007cdda0 = 0;
  DAT_020b8e44 = ITEM_WORDS;
  DAT_007d164c = ITEM_I;
LAB_0041c445:
  DAT_0079485c = 0;
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    *(undefined4 *)(&DAT_007cc61c + iVar5 * 4) = 0;
  }
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    (&DAT_007cc874)[iVar5] = 0;
  }
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    *(undefined4 *)(iVar5 * 4 + 0x7ccacc) = 0;
  }
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    *(undefined4 *)(iVar5 * 4 + 0x7cd42c) = 0;
  }
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    (&DAT_007cd684)[iVar5] = 0;
  }
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    (&DAT_007cdb34)[iVar5] = 0;
  }
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    *(int *)(iVar5 * 4 + 0x7cd8dc) = i_0;
  }
  DAT_007d1648 = 0;
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    *(undefined4 *)(&DAT_007ccd24 + iVar5 * 4) = 0;
  }
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    *(undefined4 *)(&DAT_007ccf7c + iVar5 * 4) = 0;
  }
  for (iVar5 = 1; iVar5 < 0x97; iVar5 = iVar5 + 1) {
    *(undefined4 *)(&DAT_007cd1d4 + iVar5 * 4) = 0;
  }
  _DAT_007d1644 = 0;
  _DAT_007cc608 = 0;
  DAT_007cc60c = 1;
  DAT_007cbfa0 = -1;
  DAT_007d1640 = 0;
  _DAT_007d163c = 0;
  _DAT_007d1638 = 0;
  DAT_01fb9630 = 1;
  DAT_007cc600 = 0;
  DAT_007d1634 = 1;
  DAT_007cc604 = 1;
  _DAT_007d1630 = 0;
  DAT_01fb9634 = 0;
  DAT_007d1660 = DAT_0075f808;
  FUN_005f34d1(puVar6,0x41c64a);
  DAT_0078dec4 = 0xffffffff;
  _DAT_00794854 = 0x12;
  DAT_00794830 = 0;
  DAT_007d162c = 0;
  DAT_007d1628 = DAT_00794850;
  DAT_0171b230 = 2;
  DAT_0078d914 = 0;
  DAT_007d1624 = ITEM_WORDS;
  DAT_007d1620 = ITEM_I;
  DAT_007d161c = 0;
  _DAT_0078cae0 = 0;
  *(undefined2 *)(puVar6 + -0x238) = in_FPUControlWord;
  *(ushort *)(puVar6 + -0x236) = (ushort)*(undefined4 *)(puVar6 + -0x238) | 0xc00;
  *(int *)(puVar6 + -0x234) = (int)ROUND(P2);
  in_FPUControlWord = *(undefined2 *)(puVar6 + -0x238);
  CUR_STAFF = *(int *)(puVar6 + -0x234);
  _DAT_007d1618 = 0;
  if (DAT_0078d938 == 0) {
    *(undefined4 *)(puVar6 + -0x210) = 0;
  }
  else {
    DAT_007cc600 = DAT_0078d938;
    DAT_007cc604 = DAT_0078d938 + 1;
  }
LAB_0041c732:
  do {
    if ((0 < DAT_007cc600) &&
       ((&DAT_020b8e9f)[DAT_007cc600] == '/' || (&DAT_020b8e9f)[DAT_007cc600] == ':')) {
      FUN_0041f271();
    }
LAB_0041c77c:
    FUN_005f34d1(puVar6,0x41c799);
    if ((DAT_007cc600 != 0) && (DAT_007d161c == 0)) {
      DAT_007d161c = 1;
      thunk_FUN_00468df8(&DAT_0075f800);
    }
LAB_0041c7cc:
    FUN_005f34d1(puVar6,0x41c7e9);
    DAT_009a9484 = 0;
    puVar9 = (undefined4 *)&DAT_020b8ea0;
    puVar13 = &DAT_007d1b88;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
LAB_0041c808:
    thunk_FUN_00549afb();
    puVar9 = &DAT_007d1b88;
    puVar13 = (undefined4 *)&DAT_020b8ea0;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    DAT_007d1614 = DAT_009a9484;
    *(undefined4 *)(puVar6 + -0x20c) = 0;
    iVar5 = FUN_005f4660(0x20);
    if (iVar5 != 0) {
      thunk_FUN_004e5988();
      DAT_007cc600 = DAT_007cc600 + -3;
      FUN_005f46bc(puVar6,0x41ea05);
      FUN_005f34d1(puVar6,0x41ea1b);
      thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
      *(undefined4 *)(puVar6 + -0x200) = 0;
      goto LAB_0041c732;
    }
    *(undefined4 *)(puVar6 + -0x204) = 0;
    if ((DAT_009c48f4 == 8) || ((_DAT_020b90a0 & 0xffff) == 0x4b42)) {
      FUN_0041f35d(&DAT_007d1620);
      if (DAT_007cc600 == 0) {
        thunk_FUN_00468df8(&DAT_0075f764);
        DAT_007d161c = 0;
        *(undefined4 *)(puVar6 + -500) = 0;
      }
      else {
        *(undefined4 *)(puVar6 + -0x1f8) = 0;
      }
      goto LAB_0041c77c;
    }
    *(undefined4 *)(puVar6 + -0x1fc) = 0;
    if (DAT_009c48f4 == 8) {
      *(undefined4 *)(puVar6 + -0x1f0) = 0;
      goto LAB_0041e6d1;
    }
    if (DAT_007d1614 != 0x410) {
      if (DAT_007d1614 == 0x40e) {
        *(undefined4 *)(puVar6 + -0x1e8) = 0;
LAB_0041de8f:
        DAT_009c6ae0 = 1;
        goto LAB_0041deb1;
      }
      if (DAT_009c48f4 == 0xd) {
        *(undefined4 *)(puVar6 + -0x1e4) = 0;
        goto LAB_0041c7cc;
      }
      if (DAT_007d1614 == 0x40c) {
        ITEM_WORDS = DAT_007d1624;
        ITEM_I = DAT_007d1620;
        DAT_00794850 = DAT_007d1628;
        FUN_005f34d1(puVar6,0x41ea8d);
        FUN_005f34d1(puVar6,0x41eaae);
        DAT_007cc600 = 0;
        thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
        draw_items();
        thunk_FUN_00549422();
        *(undefined4 *)(puVar6 + -0x1e0) = 0;
        goto LAB_0041c445;
      }
      if ((_DAT_020b90a0 & 0xff) == 0x3b) {
        FUN_0041f271();
      }
      if (((_DAT_020b90a0 & 0xff) == 0x3d) || ((_DAT_020b90a0 & 0xff) == 0x2e)) {
        DAT_009c48f4 = 0;
        _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_0075f7f8);
        if (((&DAT_020b8e9f)[DAT_007cc600] != '/') &&
           ((&DAT_020b8e9f)[DAT_007cc600] != '.' && (&DAT_020b8e9f)[DAT_007cc600] != '=')) {
          puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600);
          DAT_007cc600 = DAT_007cc600 + 1;
          *puVar1 = 0x2b;
          *(undefined4 *)(puVar6 + -0x1dc) = 0;
          goto LAB_0041c732;
        }
      }
      if ((_DAT_020b90a0 & 0xff) == 0x7e) {
        iVar5 = 3;
        bVar16 = true;
        psVar7 = (short *)&DAT_020b90a0;
        psVar11 = &DAT_0075f7f0;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar16 = *psVar7 == *psVar11;
          psVar7 = psVar7 + 1;
          psVar11 = psVar11 + 1;
        } while (bVar16);
        if (bVar16) goto LAB_0041de8f;
        iVar5 = 3;
        bVar16 = false;
        psVar7 = (short *)&DAT_020b90a0;
        psVar11 = &DAT_0075f7e8;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar16 = *psVar7 == *psVar11;
          psVar7 = psVar7 + 1;
          psVar11 = psVar11 + 1;
        } while (bVar16);
        if (bVar16) goto LAB_0041de9c;
        DAT_007d1608 = DAT_01a14950 - VIEW_DX;
        _DAT_007d1604 = (float)DAT_01a1494c;
        *(int *)(puVar6 + -0x234) = (&STAFF_Y0)[CUR_STAFF] - VIEW_DY;
        _DAT_007d1600 = (float)*(int *)(puVar6 + -0x234);
        _DAT_007d15fc = _DAT_007d1604 - _DAT_007d1600;
        DAT_0079483c = (float)(&STAFF_STEP0)[CUR_STAFF] * f_7;
        _DAT_007d15f8 = _DAT_007d15fc / DAT_0079483c;
        fVar19 = (float10)anint(puVar6,0x41ca78);
        *(int *)(puVar6 + -0x234) = (int)ROUND(fVar19);
        DAT_007d1610 = *(int *)(puVar6 + -0x234);
        if (0 < DAT_00794830) {
          DAT_0079484c = (&DAT_007cbd3c)[DAT_00794830];
        }
        if (DAT_007d1608 < -600) {
          FUN_005f33c9(puVar6,0x41cadb);
          FUN_005f34d1(puVar6,0x41caf6);
          if ((f_m10_89 <= _DAT_007d15f8) && (_DAT_007d15f8 < f_m5_66)) {
            DAT_009c48f4 = 8;
          }
          if (f_m5_66 < _DAT_007d15f8) {
            FUN_005f33c9(puVar6,0x41cb5c);
            FUN_005f34d1(puVar6,0x41cb77);
          }
          if (f_m0_67 < _DAT_007d15f8) {
            FUN_005f33c9(puVar6,0x41cbac);
            FUN_005f34d1(puVar6,0x41cbc7);
          }
          if (f_4_3 < _DAT_007d15f8) {
            FUN_005f33c9(puVar6,0x41cbfc);
            FUN_005f34d1(puVar6,0x41cc17);
          }
          if (f_9 < _DAT_007d15f8) {
            FUN_005f33c9(puVar6,0x41cc4c);
            FUN_005f34d1(puVar6,0x41cc67);
          }
          if (f_14_07 < _DAT_007d15f8) {
            FUN_005f33c9(puVar6,0x41cc9c);
            FUN_005f34d1(puVar6,0x41ccb7);
          }
          if (f_18_36 < _DAT_007d15f8) {
            FUN_005f33c9(puVar6,0x41ccec);
            FUN_005f34d1(puVar6,0x41cd07);
          }
          if (f_23_83 < _DAT_007d15f8) {
            FUN_005f33c9(puVar6,0x41cd3c);
            FUN_005f34d1(puVar6,0x41cd57);
          }
          if (f_29_3 < _DAT_007d15f8) {
            FUN_005f33c9(puVar6,0x41cd8c);
            FUN_005f34d1(puVar6,0x41cda7);
          }
          *(undefined4 *)(puVar6 + -0x1d0) = 0;
          goto LAB_0041cfae;
        }
        switch(DAT_0079484c) {
        case 0:
        case 4:
          break;
        default:
          DAT_007d1610 = DAT_007d1610 + -0xc;
          *(undefined4 *)(puVar6 + -0x1cc) = 0;
          break;
        case 2:
          DAT_007d1610 = DAT_007d1610 + -6;
          *(undefined4 *)(puVar6 + -0x1c8) = 0;
          break;
        case 3:
          DAT_007d1610 = DAT_007d1610 + -8;
        }
        DAT_007d1664 = (DAT_007d1610 + 0x1b) / 7;
        puVar6[-0x231] = (char)DAT_007d1664 + '0';
        DAT_007d165c = CONCAT31(DAT_007d165c._1_3_,puVar6[-0x231]);
        DAT_007d1610 = (DAT_007d1610 + 0x1c) % 7;
        if (5 < DAT_007d1610) {
          DAT_007d1610 = DAT_007d1610 + -7;
        }
        puVar6[-0x231] = (char)DAT_007d1610 + 'B';
        puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600);
        DAT_007cc600 = DAT_007cc600 + 1;
        *puVar1 = puVar6[-0x231];
        if (DAT_007d1660 == 0x2020) {
          *(undefined4 *)(puVar6 + -0x1c4) = 0;
        }
        else {
          puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600);
          DAT_007cc600 = DAT_007cc600 + 1;
          *puVar1 = (undefined1)DAT_007d1660;
          if (DAT_007d1660._1_1_ == ' ') {
            *(undefined4 *)(puVar6 + -0x1c0) = 0;
          }
          else {
            pcVar10 = (char *)((int)&DAT_020b8ea0 + DAT_007cc600);
            DAT_007cc600 = DAT_007cc600 + 1;
            *pcVar10 = DAT_007d1660._1_1_;
          }
        }
        *(char *)((int)&DAT_020b8ea0 + DAT_007cc600) = (char)DAT_007d165c;
        *(undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600 + 1) = 0x2f;
        DAT_007cc600 = DAT_007cc600 + 2;
        _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_0075f798);
        FUN_005f34d1(puVar6,0x41cf9b);
        *(undefined4 *)(puVar6 + -0x1bc) = 0;
LAB_0041da9d:
        thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
        *(undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600) = 0x20;
        if ((_DAT_020b90a0 & 0xff) == 0x20) {
          bVar16 = 0 < DAT_007cc600;
          iVar5 = FUN_0041eded(&DAT_020b8e9f + DAT_007cc600,1);
          if ((-(uint)bVar16 & iVar5 >> 0x1f & 1) != 0) {
            *(undefined4 *)(puVar6 + -0xb0) = 0;
            goto LAB_0041c732;
          }
        }
        else {
          *(undefined4 *)(puVar6 + -0xb4) = 0;
        }
        if ((_DAT_020b90a0 & 0xff) == 0x2f) {
          *(undefined4 *)(puVar6 + -0xa8) = 0;
        }
        else {
          *(undefined4 *)(puVar6 + -0xac) = 0;
          if ((_DAT_020b90a0 & 0xff) == 0x3b) {
            *(undefined4 *)(puVar6 + -0xa4) = 0;
LAB_0041edb3:
            DAT_01fb9630 = 0;
            DAT_0171b230 = 0;
            FUN_005f34d1(puVar6,0x41ede0);
            return;
          }
          if ((_DAT_020b90a0 & 0xff) != 0x3a) {
            if ((_DAT_020b90a0 & 0xff) == 0x20) {
              *(undefined4 *)(puVar6 + -0x9c) = 0;
              *(undefined4 *)(puVar6 + -0x24) = 0;
            }
            else {
              *(undefined4 *)(puVar6 + -0x98) = 0;
            }
            goto LAB_0041c732;
          }
          *(undefined4 *)(puVar6 + -0xa0) = 0;
        }
LAB_0041db7b:
        FUN_005f46bc(puVar6,0x41dbb7);
        FUN_005f34d1(puVar6,0x41dbcd);
        if ((&DAT_020b8e9f)[DAT_007cc604] != '/') {
          if (*(char *)((int)&DAT_020b8ea0 + DAT_007cc604) == '[') {
            *(undefined4 *)(puVar6 + -0x90) = 0;
            DAT_007d1640 = 1;
          }
          else {
            if (((&DAT_020b8e9f)[DAT_007cc604] == 'X') || ((&DAT_020b8e9f)[DAT_007cc604] == 'Z')) {
              *(undefined4 *)(puVar6 + -0x8c) = 0;
              *(undefined4 *)(puVar6 + -0x68) = 0xc;
              DAT_007d1610 = 1;
              break;
            }
            if ((&DAT_020b8e9f)[DAT_007cc604] == ']') goto LAB_0041dc4b;
            *(undefined4 *)(puVar6 + -0x88) = 0;
          }
LAB_0041e3f8:
          if (DAT_01e62c84 != '@') {
            *(undefined4 *)(puVar6 + -0x50) = 0;
            goto LAB_0041e416;
          }
          iVar5 = thunk_FUN_004c2912(&DAT_01e62c84,0xc);
          uVar18 = iVar5 == 0;
          if (!(bool)uVar18) {
            *(undefined4 *)(puVar6 + -0x4c) = 0;
            goto LAB_0041e551;
          }
          DAT_007d15d0 = DAT_007cbfa0;
          DAT_0078dec4 = 0xffffffff;
          FUN_0041f839();
          DAT_007cbfa0 = DAT_007d15d0;
          DAT_0078dec4 = 0xffffffff;
          iVar5 = 5;
          pcVar10 = &DAT_020b90a0;
          pcVar14 = "ERROR";
          goto code_r0x0041e6c6;
        }
        *(undefined4 *)(puVar6 + -0x94) = 0;
LAB_0041dc4b:
        DAT_007d1664 = DAT_0079485c;
        DAT_007d15e4 = ITEM_I;
        if (DAT_007cc600 < 2) {
          if ((_DAT_020b90a0 & 0xff) != 0x2f) {
            *(undefined4 *)(puVar6 + -0x80) = 0;
            goto LAB_0041e70c;
          }
          DAT_020b8ea0._0_1_ = DAT_0075f768;
          DAT_007cc600 = 0;
          *(undefined4 *)(puVar6 + -0x7c) = 0;
          goto LAB_0041c808;
        }
        *(undefined4 *)(puVar6 + -0x84) = 0;
LAB_0041e70c:
        DAT_007d15e0 = 1;
        _DAT_007d15dc = 2;
        while ((DAT_007d1664 != 0 && ((&DAT_007cd684)[DAT_007d1664] == 0))) {
          DAT_007d1664 = DAT_007d1664 + -1;
          DAT_007d15e4 = DAT_007d15e4 + -1;
          DAT_007d15e0 = DAT_007d15e0 + 1;
          *(undefined4 *)(puVar6 + -0x74) = 0;
        }
        *(undefined4 *)(puVar6 + -0x78) = 0;
        DAT_0079483c = (float)i_0;
        thunk_FUN_004c2711(&DAT_007d1664,&DAT_007d15e4,&DAT_007d15e0,&DAT_007d15dc);
        DAT_007cc604 = DAT_007cc600 + 1;
        if (DAT_007d1640 != 0) {
          *(undefined4 *)(puVar6 + -0x6c) = 0;
LAB_0041e7d2:
          if ((&DAT_020b8e9e)[DAT_007cc600] == ']') {
            FUN_0041fab5(*(undefined4 *)(puVar6 + 0xc),&DAT_007cc600);
            DAT_007d1640 = 0;
          }
          else {
            *(undefined4 *)(puVar6 + -0x2c) = 0;
          }
          goto LAB_0041e806;
        }
        *(undefined4 *)(puVar6 + -0x70) = 0;
        goto LAB_0041c732;
      }
LAB_0041cfae:
      if ((_DAT_020b90a0 & 0xff) == 0x27) {
        DAT_009c48f4 = 0x3a;
        _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_0075f7c4);
      }
      if (DAT_020b90a0 == '\x11') {
        DAT_007d1648 = DAT_007d1648 + 1;
        DAT_007d1660 = DAT_0075f760;
        if (DAT_007d1648 == 2) {
          DAT_007d1660 = DAT_0075f75c;
        }
        if (DAT_007d1648 == 3) {
          DAT_007d1660 = DAT_0075f758;
        }
        *(undefined4 *)(puVar6 + -0x1b8) = 0;
        goto LAB_0041c732;
      }
      if ((DAT_009c48f4 == 0x3b) && ((&DAT_020b8e9f)[DAT_007cc600] == '/')) {
        *(undefined4 *)(puVar6 + -0x1b4) = 0;
LAB_0041ed05:
        if (DAT_009c48f4 != 0) {
          DAT_007cc600 = DAT_007cc600 + 1;
        }
        if ((&DAT_020b8e9e)[DAT_007cc600] == '/') {
          if (((&DAT_020b8e9d)[DAT_007cc600] == 'M') || ((&DAT_020b8e9c)[DAT_007cc600] == 'M')) {
            DAT_007cc600 = DAT_007cc600 + -1;
          }
        }
        else {
          *(undefined4 *)(puVar6 + -0x178) = 0;
        }
        (&DAT_020b8e9f)[DAT_007cc600] = 0x3b;
        *(undefined4 *)(puVar6 + -0x174) = 0;
        goto LAB_0041edb3;
      }
      if (DAT_009c48f4 == 8) {
        *(undefined4 *)(puVar6 + -0x1b0) = 0;
        goto LAB_0041e6d1;
      }
      if ((DAT_009c48f4 == 0x27) && ((short)DAT_009ae2bc != 0x7e7e)) {
        *(undefined4 *)(puVar6 + -0x1ac) = 0;
LAB_0041da5f:
        DAT_007d1634 = DAT_007d1634 + 1;
        puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600);
        DAT_007cc600 = DAT_007cc600 + 1;
        *puVar1 = (undefined1)DAT_009c48f4;
        _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,(undefined1)DAT_009c48f4);
        goto LAB_0041da9d;
      }
      if (DAT_009c48f4 == 0x25) {
        if (1 < DAT_007d1634) {
          DAT_007d1634 = DAT_007d1634 + -1;
        }
        *(undefined4 *)(puVar6 + -0x1a8) = 0;
        goto LAB_0041c7cc;
      }
      if (DAT_009c48f4 == 0x27) {
        if (DAT_007d1634 < DAT_007cc600) {
          DAT_007d1634 = DAT_007d1634 + 1;
        }
        *(undefined4 *)(puVar6 + -0x1a4) = 0;
        goto LAB_0041c7cc;
      }
      if (DAT_009c48f4 == 0x2e) {
        if (DAT_007d1634 < DAT_007cc600) {
          iVar5 = (DAT_007cc600 - DAT_007d1634) + 2;
          *(int *)(puVar6 + -0x1a0) = iVar5;
          DAT_007d1610 = DAT_007d1634;
          while (0 < iVar5) {
            (&DAT_020b8e9f)[DAT_007d1610] = *(undefined1 *)((int)&DAT_020b8ea0 + DAT_007d1610);
            DAT_007d1610 = DAT_007d1610 + 1;
            *(int *)(puVar6 + -0x1a0) = *(int *)(puVar6 + -0x1a0) + -1;
            iVar5 = *(int *)(puVar6 + -0x1a0);
          }
          DAT_007cc600 = DAT_007cc600 + -1;
          DAT_007cc604 = DAT_007cc604 + -1;
        }
        *(undefined4 *)(puVar6 + -0x19c) = 0;
      }
      else {
        if (DAT_009c48f4 == 0x23) {
          DAT_007d1634 = DAT_007cc600;
          *(undefined4 *)(puVar6 + -0x198) = 0;
          goto LAB_0041c7cc;
        }
        if (((DAT_009c48f4 != 0x24) || ((&DAT_020b8e9f)[DAT_007cc600] == '@')) ||
           ((&DAT_020b8e9f)[DAT_007cc600] == '-')) {
          if (DAT_009a9488 != 0) {
            switch(DAT_009c48f4) {
            case 0x71:
            case 0x75:
              FUN_005f33c9(puVar6,&UNK_0041d0ed);
              FUN_005f34d1(puVar6,&UNK_0041d108);
              *(undefined4 *)(puVar6 + -0x114) = 0;
              break;
            case 0x72:
              FUN_005f33c9(puVar6,&UNK_0041d139);
              FUN_005f34d1(puVar6,&UNK_0041d154);
              *(undefined4 *)(puVar6 + -0x110) = 0;
              break;
            case 0x73:
              FUN_005f33c9(puVar6,&UNK_0041d185);
              FUN_005f34d1(puVar6,&UNK_0041d1a0);
              *(undefined4 *)(puVar6 + -0x10c) = 0;
              break;
            case 0x74:
              FUN_005f33c9(puVar6,&UNK_0041d1d1);
              FUN_005f34d1(puVar6,&UNK_0041d1ec);
              *(undefined4 *)(puVar6 + -0x108) = 0;
              break;
            case 0x76:
              FUN_005f33c9(puVar6,&UNK_0041d21d);
              FUN_005f34d1(puVar6,&UNK_0041d238);
              *(undefined4 *)(puVar6 + -0x104) = 0;
              break;
            case 0x77:
              FUN_005f33c9(puVar6,&UNK_0041d269);
              FUN_005f34d1(puVar6,&UNK_0041d284);
              *(undefined4 *)(puVar6 + -0x100) = 0;
              break;
            case 0x78:
              FUN_005f33c9(puVar6,&UNK_0041dfa5);
              FUN_005f34d1(puVar6,&UNK_0041dfc0);
              *(undefined4 *)(puVar6 + -0xfc) = 0;
              goto LAB_0041e277;
            case 0x79:
              FUN_005f33c9(puVar6,&UNK_0041d2b5);
              FUN_005f34d1(puVar6,&UNK_0041d2d0);
              *(undefined4 *)(puVar6 + -0xf8) = 0;
              if (((&DAT_020b8e9f)[DAT_007cc600] == 'M') || ((&DAT_020b8e9e)[DAT_007cc600] == 'M'))
              {
                *(undefined4 *)(puVar6 + -0xe8) = 0;
              }
              else {
                *(undefined4 *)(puVar6 + -0xec) = 0;
              }
              break;
            case 0x7a:
              FUN_005f33c9(puVar6,&UNK_0041d340);
              FUN_005f34d1(puVar6,&UNK_0041d35b);
              *(undefined4 *)(puVar6 + -0xf4) = 0;
              break;
            case 0x7b:
              FUN_005f33c9(puVar6,&LAB_0041ecd7);
              FUN_005f34d1(puVar6,&LAB_0041ecf2);
              *(undefined4 *)(puVar6 + -0xf0) = 0;
              return;
            default:
              goto LAB_0041d36e;
            }
LAB_0041d76c:
            thunk_FUN_0054c8e5(&DAT_020b90a0,1,*(undefined4 *)(puVar6 + 0xc));
            DAT_007cc600 = DAT_007cc600 + 1;
            iVar5 = **(int **)(puVar6 + 0xc);
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            *(int *)(puVar6 + -0x234) = iVar5;
            *(undefined4 *)(puVar6 + -0x238) = 0;
            FUN_005f46bc(puVar6,0x41d7fe);
            FUN_005f34d1(puVar6,0x41d814);
            DAT_007d1634 = **(int **)(puVar6 + 0xc) + DAT_007cc600;
            DAT_007cc600 = DAT_007d1634 + -1;
            if ((((_DAT_020b90a0 >> 0x10 & 0xff) == 0x2f) || ((_DAT_020b90a0 & 0xff) != 0x3d)) ||
               ((_DAT_020b90a0 >> 8 & 0xff) == 0x2f)) {
              if (DAT_007d15f4 == 0) {
                *(undefined4 *)(puVar6 + -0x11c) = 0;
                if ((_DAT_020b90a0 & 0xff) == 0x52) {
                  DAT_00794838 = 0x28;
                  if ((_DAT_020b90a0 >> 8 & 0xff) == 0x57) {
                    DAT_00794838 = 0x29;
                  }
                }
                else {
                  *(undefined4 *)(puVar6 + -0xe4) = 0;
                }
                DAT_007cc600 = **(int **)(puVar6 + 0xc) + DAT_007cc604 + -1;
                *(undefined4 *)(puVar6 + -0x234) = 0;
                FUN_005f46bc(puVar6,0x41d934);
                FUN_005f34d1(puVar6,0x41d94a);
LAB_0041d94e:
                thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
                *(undefined4 *)(puVar6 + -0xe0) = 0;
                goto LAB_0041db7b;
              }
              thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
              FUN_005f46bc(puVar6,0x41e1b1);
              FUN_005f34d1(puVar6,0x41e1c7);
              *(undefined4 *)(puVar6 + -0x234) = 0;
              FUN_005f46bc(puVar6,0x41e224);
              FUN_005f34d1(puVar6,0x41e23a);
              DAT_007cc604 = **(int **)(puVar6 + 0xc) + DAT_007cc604;
              DAT_007cc600 = DAT_007cc604 + -1;
              *(undefined4 *)(puVar6 + -0x118) = 0;
              goto LAB_0041e3f8;
            }
            *(undefined4 *)(puVar6 + -0x120) = 0;
            goto LAB_0041c732;
          }
LAB_0041d36e:
          if (DAT_009c48f4 != 0) {
            if (DAT_009c48f4 == 0x1b) {
              _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_0075f76c);
            }
            if ((_DAT_020b90a0 & 0xff) == 0x5e) {
              *(undefined4 *)(puVar6 + -0xdc) = 0;
LAB_0041e277:
              DAT_007d165c = CONCAT31(DAT_007d165c._1_3_,(undefined1)DAT_020b8ea0);
              DAT_007d1610 = thunk_FUN_005956b0();
              if (DAT_007d1610 == 0) {
                DAT_020b8ea0._0_1_ = DAT_0075f754;
              }
              if (-1 < DAT_007d1610) {
                *(undefined4 *)(puVar6 + -0x140) = 0;
                return;
              }
              DAT_020b8ea0._0_1_ = (undefined1)DAT_007d165c;
              *(undefined4 *)(puVar6 + -0x13c) = 0;
            }
            else {
              thunk_FUN_0054c768(&DAT_020b90a0);
              if (DAT_009c48f4 == 0x23) {
                *(undefined4 *)(puVar6 + -0xd8) = 0;
                *(undefined4 *)(puVar6 + -0x20) = 0;
              }
              else if (((DAT_009c48f4 == 0x24) && ((&DAT_020b8e9f)[DAT_007cc600] != '@')) &&
                      ((&DAT_020b8e9f)[DAT_007cc600] != '-')) {
                *(undefined4 *)(puVar6 + -0xd4) = 0;
                *(undefined4 *)(puVar6 + -0x1c) = 0;
              }
              else if (DAT_009c48f4 == 0x25) {
                *(undefined4 *)(puVar6 + -0xd0) = 0;
                *(undefined4 *)(puVar6 + -0x18) = 0;
              }
              else if (DAT_009c48f4 == 0x27) {
                *(undefined4 *)(puVar6 + -0xcc) = 0;
                *(undefined4 *)(puVar6 + -0x14) = 0;
              }
              else if (DAT_009c48f4 == 0x2d) {
                _DAT_007d163c = 1;
                puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600);
                DAT_007cc600 = DAT_007cc600 + 1;
                *puVar1 = (char)_DAT_020b90a0;
                *(undefined4 *)(puVar6 + -200) = 0;
              }
              else {
                if (DAT_009c48f4 != 0x2e) {
                  if (DAT_009c48f4 != 8) {
                    if ((0x60 < DAT_009c48f4) && (DAT_009c48f4 < 0x7b)) {
                      DAT_009c48f4 = DAT_009c48f4 + -0x20;
                    }
                    goto LAB_0041da5f;
                  }
                  *(undefined4 *)(puVar6 + -0xb8) = 0;
                  goto LAB_0041e6d1;
                }
                *(undefined4 *)(puVar6 + -0xbc) = 0;
                *(undefined4 *)(puVar6 + -0xc) = 0;
              }
            }
            goto LAB_0041c732;
          }
          DAT_007d15f4 = 0;
          if ((_DAT_020b90a0 & 0xff) == 0x24) {
            uVar4 = _DAT_020b90a0 >> 8 & 0xff;
            bVar16 = uVar4 < 0x28;
            if (uVar4 == 0x28) {
              DAT_0078d914 = 1;
              *(undefined4 *)(puVar6 + -400) = 0;
            }
            else {
              iVar5 = 1;
              pbVar8 = &DAT_020b90a1;
              pbVar12 = &DAT_0075f778;
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar3 = *pbVar12;
                bVar2 = *pbVar8;
                bVar16 = bVar2 < bVar3;
                pbVar8 = pbVar8 + 1;
                pbVar12 = pbVar12 + 1;
              } while (bVar2 == bVar3);
              if (bVar16) {
                *(undefined4 *)(puVar6 + -0x18c) = 0;
                FUN_0041ee39(&DAT_007cc600,&DAT_007cc604);
                DAT_007d1648 = 0;
                if (DAT_007d1660 == 0x2020) {
                  *(undefined4 *)(puVar6 + -0x184) = 0;
                }
                else {
                  _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,(&DAT_020b8e9e)[DAT_007cc600]);
                  FUN_005f46bc(puVar6,0x41d45e);
                  FUN_005f34d1(puVar6,0x41d474);
                  if (DAT_0078d914 != 0) {
                    (&DAT_020b8e9f)[DAT_007cc600] = (&DAT_020b8e9e)[DAT_007cc600];
                    (&DAT_020b8e9e)[DAT_007cc600] = 0x28;
                    DAT_007cc600 = DAT_007cc600 + 1;
                    DAT_0078d914 = 0;
                  }
                  if (DAT_007d1660._1_1_ != ' ') {
                    DAT_007cc600 = DAT_007cc600 + 1;
                  }
                  (&DAT_020b8e9f)[DAT_007cc600] = (char)_DAT_020b90a0;
                  FUN_005f34d1(puVar6,0x41d516);
                  puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600);
                  DAT_007cc600 = DAT_007cc600 + 1;
                  *puVar1 = 0x2f;
                  DAT_007d1634 = DAT_007cc600 + 1;
                }
                *(undefined4 *)(puVar6 + -0x180) = 0;
                *(undefined4 *)(puVar6 + -0x17c) = 0;
                goto LAB_0041d94e;
              }
              DAT_007d1660 = _DAT_020b90a1;
              *(undefined4 *)(puVar6 + -0x188) = 0;
            }
            goto LAB_0041c732;
          }
          if ((_DAT_020b90a0 & 0xff) == 0x3b) goto LAB_0041ed05;
          if ((_DAT_020b90a0 & 0xffff) == 0x4b42) goto LAB_0041e6d1;
          if ((_DAT_020b90a0 & 0xff) != 0x2b) {
            if ((_DAT_020b90a0 & 0xff) == 0x3a) {
              (&DAT_020b8e9f)[DAT_007cc600] = 0x3a;
              DAT_01fb9634 = 1;
              *(undefined4 *)(puVar6 + -0x144) = 0;
              goto LAB_0041c732;
            }
            if ((_DAT_020b90a0 & 0xff) == 0x5e) goto LAB_0041e277;
            if ((_DAT_020b90a0 & 0xff) == 0x2f) {
LAB_0041d6e3:
              puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600);
              DAT_007cc600 = DAT_007cc600 + 1;
              *puVar1 = (char)_DAT_020b90a0;
              thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
              if ((&DAT_020b8e9e)[DAT_007cc600] != '/') {
                *(undefined4 *)(puVar6 + -0x138) = 0;
                goto LAB_0041db7b;
              }
              *(undefined4 *)(puVar6 + -0x134) = 0;
              goto LAB_0041dc4b;
            }
            if ((_DAT_020b90a0 & 0xffff) != 0x5543) {
              bVar16 = (_DAT_020b90a0 & 0xffff) < 0x4f43;
              bVar17 = (_DAT_020b90a0 & 0xffff) == 0x4f43;
              if (!bVar17) {
                iVar5 = 1;
                pbVar8 = (byte *)&DAT_020b90a0;
                pbVar12 = &DAT_0075f774;
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar16 = *pbVar8 < *pbVar12;
                  bVar17 = *pbVar8 == *pbVar12;
                  pbVar8 = pbVar8 + 1;
                  pbVar12 = pbVar12 + 1;
                } while (bVar17);
                bVar15 = (!bVar16 && !bVar17) != 0;
                iVar5 = -(uint)(!bVar16 && !bVar17);
                bVar16 = iVar5 == 0;
                *(int *)(puVar6 + -0x234) = iVar5;
                iVar5 = 1;
                pbVar8 = (byte *)&DAT_020b90a0;
                pbVar12 = &DAT_0075f770;
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar15 = *pbVar8 < *pbVar12;
                  bVar16 = *pbVar8 == *pbVar12;
                  pbVar8 = pbVar8 + 1;
                  pbVar12 = pbVar12 + 1;
                } while (bVar16);
                if ((-(uint)(bVar15 || bVar16) & *(uint *)(puVar6 + -0x234) & 1) == 0) {
                  if ((_DAT_020b90a0 & 0xff) == 0x4b) {
                    if ((_DAT_020b90a0 & 0xffff) == 0x534b) {
                      DAT_007d162c = 100;
                      *(undefined4 *)(puVar6 + -300) = 0;
                      goto LAB_0041c732;
                    }
                    if (DAT_007d162c != 0) {
                      _DAT_020b90a0 = CONCAT13(0x4e,_DAT_020b90a0);
                      DAT_020b90a4._0_1_ = DAT_0075f798;
                      DAT_007d162c = 0;
                    }
                  }
                  if (_DAT_020b90a0 == 0x4944494d) {
                    *(undefined4 *)(puVar6 + -0x128) = 0;
                    DAT_007d15f4 = 0;
                    return;
                  }
                  if ((_DAT_020b90a0 & 0xff) != 0x2f) goto LAB_0041d76c;
                  *(undefined4 *)(puVar6 + -0x124) = 0;
                  goto LAB_0041d6e3;
                }
              }
            }
            DAT_007d15f4 = 1;
            *(undefined4 *)(puVar6 + -0x130) = 0;
            goto LAB_0041d76c;
          }
          if ((&DAT_020b8e9f)[DAT_007cc600] == '/') {
            DAT_00794830 = DAT_00794830 + -1;
          }
          (&DAT_020b8e9f)[DAT_007cc600] = 0x2b;
          puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600);
          DAT_007cc600 = DAT_007cc600 + 1;
          *puVar1 = 0x2f;
          thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
          FUN_005f46bc(puVar6,0x41e0c6);
          FUN_005f34d1(puVar6,0x41e0dc);
          DAT_007cc604 = DAT_007cc600 + 1;
          DAT_007cdda0 = DAT_007cdda0 + -1;
          *(undefined4 *)(puVar6 + -0x148) = 0;
LAB_0041e416:
          _DAT_007d15cc = DAT_00794850;
          if (DAT_007cbfa0 < 0) {
            if (DAT_00794830 < 1) {
              *(undefined4 *)(puVar6 + -0x3c) = 0;
            }
            else {
              DAT_007cbfa0 = 4;
              if ((DAT_0079484c == 1) || (DAT_0079484c == 3)) {
                DAT_007cbfa0 = 3;
              }
              (&DAT_007cdb34)[DAT_00794830] = DAT_007cbfa0;
              (&DAT_007cbfa0)[DAT_00794830] = DAT_007cbfa0;
            }
          }
          else {
            *(undefined4 *)(puVar6 + -0x40) = 0;
          }
          thunk_FUN_004c04fb();
          (&DAT_007cc874)[DAT_00794830] = DAT_007cc604;
          if (_DAT_007d15cc == DAT_00794850) {
            *(undefined4 *)(puVar6 + -0x38) = 0;
          }
          else {
            DAT_007d1650 = DAT_007d1650 + 1;
            *(int *)(&DAT_007cbbac + DAT_007d1650 * 4) = ITEM_I;
          }
          DAT_007d15ec = DAT_007cc604;
          if (_DAT_020b90a0 != 0x2a2a2a2a) {
            *(undefined4 *)(puVar6 + -0x34) = 0;
            if (DAT_007d1640 != 0) {
              FUN_004209bb();
            }
            goto LAB_0041e7d2;
          }
LAB_0041e551:
          FUN_005f46bc(puVar6,0x41e58b);
          FUN_005f34d1(puVar6,0x41e5a1);
          DAT_007cc600 = DAT_007cc604 + -1;
          *(undefined4 *)(puVar6 + -0x30) = 0;
          _DAT_007cc614 = i_0;
          DAT_007d15ec = DAT_007cc600;
          if (DAT_007cc600 == 0) {
            FUN_005f34d1(puVar6,0x41e5f9);
            FUN_005f34d1(puVar6,0x41e61a);
            DAT_007d15ec = 1;
          }
          thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007d15ec);
          DAT_007cc604 = DAT_007cc600 + 1;
          DAT_007d1614 = 0;
          DAT_009a9488 = 0;
          if (0 < DAT_007d1620) {
            *(undefined4 *)(puVar6 + -0x150) = 0;
            goto LAB_0041c732;
          }
          DAT_00794850 = DAT_007d1628;
          *(undefined4 *)(puVar6 + -0x14c) = 0;
          goto LAB_0041c445;
        }
        DAT_007d1634 = 0;
        *(undefined4 *)(puVar6 + -0x194) = 0;
      }
      goto LAB_0041c7cc;
    }
    *(undefined4 *)(puVar6 + -0x1ec) = 0;
LAB_0041de9c:
    DAT_009c6ae0 = 2;
    *(undefined4 *)(puVar6 + -0x1d4) = 0;
LAB_0041deb1:
    puVar9 = (undefined4 *)&DAT_020b8ea0;
    puVar13 = &DAT_009ae2bc;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    _DAT_007d160c = thunk_FUN_0052fef6();
    puVar9 = &DAT_009ae2bc;
    puVar13 = (undefined4 *)&DAT_020b8ea0;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    FUN_005f34d1(puVar6,0x41deff);
    *(undefined4 *)(puVar6 + -0x1d8) = 0;
  } while( true );
  while( true ) {
    *(undefined4 *)(puVar6 + -100) = 0;
    *(undefined4 *)(puVar6 + -0x5c) = 0;
    DAT_007d1610 = DAT_007d1610 + 1;
    *(int *)(puVar6 + -0x68) = *(int *)(puVar6 + -0x68) + -1;
    if (*(int *)(puVar6 + -0x68) < 1) break;
    if ((*(char *)((int)&DAT_01e62c80 + DAT_007d1610 + 3) == 'X') ||
       (*(char *)((int)&DAT_01e62c80 + DAT_007d1610 + 3) == 'Z')) {
      DAT_007d1664 = DAT_007d1610;
      thunk_FUN_004c2458(&DAT_01e62c84,1,&DAT_007d15d8,&DAT_007d1664);
      *(undefined1 *)((int)&DAT_01e62c80 + DAT_007d1610 + 3) = 0x20;
      thunk_FUN_004c2458(&DAT_01e62c84,1,&DAT_007d15d4,&DAT_007d1664);
      *(undefined4 *)(puVar6 + -0x60) = 0;
      break;
    }
  }
  FUN_00421651(&DAT_007d164c,&DAT_007d15d8,&DAT_007d15d4,&DAT_00794850);
  if (DAT_007d15d8 == 999) {
    thunk_FUN_0054d831("Repeat source number too big.",0x1e);
    DAT_007cc600 = DAT_007cc604 + -1;
    thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
    *(undefined4 *)(puVar6 + -0x58) = 0;
  }
  else {
    FUN_005f34d1(puVar6,0x41e989);
    DAT_007cc604 = DAT_007cc600 + 1;
    DAT_007d15d8 = 0;
    _DAT_007d15d4 = 0;
    DAT_01fb9634 = 0;
    *(undefined4 *)(puVar6 + -0x54) = 0;
  }
  goto LAB_0041c732;
  while( true ) {
    iVar5 = iVar5 + -1;
    uVar18 = *pcVar10 == *pcVar14;
    pcVar10 = pcVar10 + 1;
    pcVar14 = pcVar14 + 1;
    if (!(bool)uVar18) break;
code_r0x0041e6c6:
    if (iVar5 == 0) break;
  }
  if (!(bool)uVar18) {
    *(undefined4 *)(puVar6 + -0x44) = 0;
LAB_0041e806:
    DAT_007cc604 = DAT_007cc600 + 1;
    *(undefined4 *)(puVar6 + -0x28) = 0;
    goto LAB_0041c732;
  }
  *(undefined4 *)(puVar6 + -0x48) = 0;
LAB_0041e6d1:
  if (DAT_007cc600 < 2) {
    *(undefined4 *)(puVar6 + -0x170) = 0;
    goto LAB_0041c732;
  }
  DAT_007d1610 = DAT_007cc600 + -1;
  *(int *)(puVar6 + -0x16c) = -DAT_007d1610 / -1;
  if (-DAT_007d1610 / -1 < 1) {
LAB_0041ec29:
    FUN_005f34d1(puVar6,0x41ec46);
    _DAT_007d15f0 = 0;
    thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
    ITEM_WORDS = DAT_020b8e44;
    ITEM_I = DAT_007d164c;
    DAT_00794850 = DAT_007d1628;
    draw_items();
    thunk_FUN_00549422();
    *(undefined4 *)(puVar6 + -0x15c) = 0;
  }
  else {
    while ((&DAT_020b8e9f)[DAT_007d1610] != '/') {
      *(undefined4 *)(puVar6 + -0x168) = 0;
      *(undefined4 *)(puVar6 + -0x160) = 0;
      DAT_007d1610 = DAT_007d1610 + -1;
      *(int *)(puVar6 + -0x16c) = *(int *)(puVar6 + -0x16c) + -1;
      if (*(int *)(puVar6 + -0x16c) < 1) goto LAB_0041ec29;
    }
    _DAT_007d15f0 = DAT_007d1610;
    *(undefined4 *)(puVar6 + -0x164) = 0;
    for (iVar5 = 1; iVar5 < 0x201; iVar5 = iVar5 + 1) {
      *(undefined1 *)(iVar5 + 0x7d1987) = (&DAT_020b8e9f)[iVar5];
    }
    DAT_00794850 = DAT_007d1628;
    DAT_007d1614 = 0;
    DAT_009c48f4 = 0;
    ITEM_WORDS = DAT_007d1624;
    ITEM_I = DAT_007d1620;
    FUN_005f34d1(puVar6,0x41ec16);
    *(undefined4 *)(puVar6 + -0x158) = 0;
  }
  goto LAB_0041c445;
}


