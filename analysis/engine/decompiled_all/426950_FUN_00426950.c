// FUN_00426950 @ 00426950 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426950(undefined4 *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  short *psVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 *puVar9;
  short *psVar10;
  byte *pbVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  bool bVar16;
  undefined4 *puStack_c8;
  
  puVar5 = &stack0xfffffffc;
  DAT_01fb9630 = 1;
  *param_1 = 0;
  DAT_00794834 = DAT_020b8e58;
  DAT_00794830 = 0;
  DAT_0171b230 = 1;
LAB_0042698d:
  puStack_c8 = (undefined4 *)0x426992;
  thunk_FUN_0054943a();
  puStack_c8 = (undefined4 *)0x4269af;
  FUN_005f34d1();
LAB_004269b3:
  puStack_c8 = (undefined4 *)0x4269d0;
  FUN_005f34d1();
  puVar9 = (undefined4 *)&DAT_020b8ea0;
  puVar13 = &DAT_007d2fe8;
  for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar13 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar13 = puVar13 + 1;
  }
  thunk_FUN_005494b2(&DAT_020b8ea0,0x200,*(undefined4 *)(puVar5 + 8));
  uVar14 = (undefined1 *)0xfffffffb < &puStack_c8;
  uVar15 = &stack0x00000000 == (undefined1 *)0xc4;
  do {
    puStack_c8 = (undefined4 *)0x426a06;
    thunk_FUN_00549afb();
    iVar4 = 1;
    pbVar7 = (byte *)&DAT_020b90a0;
    pbVar11 = &DAT_0075fb7c;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      uVar14 = *pbVar7 < *pbVar11;
      uVar15 = *pbVar7 == *pbVar11;
      pbVar7 = pbVar7 + 1;
      pbVar11 = pbVar11 + 1;
    } while ((bool)uVar15);
    if (!(bool)uVar14) {
      iVar4 = 1;
      pbVar7 = (byte *)&DAT_020b90a0;
      pbVar11 = &DAT_0075fb78;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        uVar14 = *pbVar7 < *pbVar11;
        uVar15 = *pbVar7 == *pbVar11;
        pbVar7 = pbVar7 + 1;
        pbVar11 = pbVar11 + 1;
      } while ((bool)uVar15);
      if ((bool)uVar14 || (bool)uVar15) {
        _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_020b90a0 + -0x20);
      }
    }
    puStack_c8 = (undefined4 *)0x20;
    iVar4 = FUN_005f4660();
    if (iVar4 != 0) {
      puStack_c8 = (undefined4 *)0x427643;
      thunk_FUN_004e5988();
      **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + -3;
      puStack_c8 = (undefined4 *)0x427680;
      FUN_005f46bc();
      puStack_c8 = (undefined4 *)0x427696;
      FUN_005f34d1();
      *(int *)(puVar5 + -0xb0) = **(int **)(puVar5 + 8) + 3;
      thunk_FUN_005494b2(&DAT_020b8ea0,0x200,puVar5 + -0xb0);
      *(undefined4 *)(puVar5 + -0x84) = 0;
      goto LAB_004269b3;
    }
    *(undefined4 *)(puVar5 + -0x88) = 0;
    puVar9 = &DAT_007d2fe8;
    puVar13 = (undefined4 *)&DAT_020b8ea0;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    if ((_DAT_020b90a0 & 0xffff) != 0x767e) break;
    *(undefined4 *)(puVar5 + -0x80) = 0;
    uVar14 = false;
    uVar15 = true;
  } while( true );
  if ((DAT_009a9488 == 0x460) || (DAT_009c48f4 == 0x1b)) {
    *(undefined4 *)(puVar5 + -0x7c) = 0;
LAB_004277a9:
    *(undefined4 *)(puVar5 + -0x40) = 0;
    DAT_020b8ea0._0_1_ = DAT_0075fb18;
    return;
  }
  if (DAT_009a9488 != 0) {
    *(undefined4 *)(puVar5 + -0x78) = 0;
    goto LAB_004269b3;
  }
  if (DAT_009c48f4 == 8) {
    DAT_009c48f4 = 0;
    *(undefined4 *)(puVar5 + -0x74) = 0;
LAB_0042728a:
    if (**(int **)(puVar5 + 8) < 1) {
      *(undefined4 *)(puVar5 + -0x4c) = 0;
      goto LAB_0042698d;
    }
    (&DAT_020b8e9f)[**(int **)(puVar5 + 8)] = 0x20;
    **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + -1;
    if (0 < **(int **)(puVar5 + 8)) {
      thunk_FUN_005494b2(&DAT_020b8ea0,0x200,*(undefined4 *)(puVar5 + 8));
      *(undefined4 *)(puVar5 + -0x44) = 0;
      goto LAB_004269b3;
    }
    *(undefined4 *)(puVar5 + -0x48) = 0;
    goto LAB_0042698d;
  }
  if ((_DAT_020b90a0 & 0xff) == 0x26) {
    *(undefined4 *)(puVar5 + -0x70) = 0;
LAB_00426b78:
    DAT_009c6ae0 = 1;
LAB_00427601:
    puVar9 = (undefined4 *)&DAT_020b8ea0;
    puVar13 = &DAT_009ae2bc;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    puStack_c8 = (undefined4 *)0x427619;
    _DAT_007d2fe0 = thunk_FUN_0052fef6();
    puVar9 = &DAT_009ae2bc;
    puVar13 = (undefined4 *)&DAT_020b8ea0;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    *(undefined4 *)(puVar5 + -0x68) = 0;
    goto LAB_004269b3;
  }
  if (((_DAT_020b90a0 & 0xff) == 0x28) || ((_DAT_020b90a0 & 0xff) == 0x25)) {
    *(undefined4 *)(puVar5 + -0x6c) = 0;
LAB_004275ef:
    DAT_009c6ae0 = 2;
    *(undefined4 *)(puVar5 + -100) = 0;
    goto LAB_00427601;
  }
  bVar16 = (_DAT_020b90a0 & 0xff) == 0x7e;
  if (bVar16) {
    iVar4 = 3;
    psVar6 = (short *)&DAT_020b90a0;
    psVar10 = &DAT_0075fb6c;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar16 = *psVar6 == *psVar10;
      psVar6 = psVar6 + 1;
      psVar10 = psVar10 + 1;
    } while (bVar16);
    if (bVar16) goto LAB_00426b78;
    iVar4 = 3;
    bVar16 = false;
    psVar6 = (short *)&DAT_020b90a0;
    psVar10 = &DAT_0075fb64;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar16 = *psVar6 == *psVar10;
      psVar6 = psVar6 + 1;
      psVar10 = psVar10 + 1;
    } while (bVar16);
    if (bVar16) goto LAB_004275ef;
    if (**(int **)(puVar5 + 8) == 0) {
      *(undefined4 *)(puVar5 + -0x60) = 0;
      goto LAB_004269b3;
    }
    puStack_c8 = &DAT_01a14950;
    FUN_004277c9(&DAT_007d2fdc);
    if ((&DAT_020b8e9f)[**(int **)(puVar5 + 8)] != ' ') {
      **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + 1;
    }
    if (DAT_007d2fd8 == DAT_007d2fdc) {
      *(undefined4 *)(puVar5 + -0x5c) = 0;
      goto LAB_004269b3;
    }
    if (DAT_007d2fd4 == DAT_007d2fdc) {
      DAT_007d2fd8 = DAT_007d2fdc;
      *(undefined1 *)((int)&DAT_020b8ea0 + **(int **)(puVar5 + 8)) = 0x20;
      (&DAT_020b8e9f)[**(int **)(puVar5 + 8)] = 0x3a;
      DAT_007d2fd4 = -99;
      *(undefined4 *)(puVar5 + -0x58) = 0;
      goto LAB_004269b3;
    }
    DAT_007d2fd4 = DAT_007d2fdc;
    DAT_007d2fd8 = 0;
    if ((&DAT_020b8e9f)[**(int **)(puVar5 + 8)] == '\0') {
      (&DAT_020b8e9f)[**(int **)(puVar5 + 8)] = 0x20;
    }
    **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + 1;
    if ((&DAT_020b8e9f)[**(int **)(puVar5 + 8)] == '\0') {
      (&DAT_020b8e9f)[**(int **)(puVar5 + 8)] = 0x20;
    }
    if (DAT_007d2fdc < 10) {
      iVar4 = **(int **)(puVar5 + 8);
      puVar5[-0xa9] = (char)DAT_007d2fdc + '0';
      (&DAT_020b8e9f)[iVar4] = puVar5[-0xa9];
    }
    else {
      iVar4 = **(int **)(puVar5 + 8);
      puVar5[-0xa9] = (char)(DAT_007d2fdc / 10) + '0';
      (&DAT_020b8e9f)[iVar4] = puVar5[-0xa9];
      **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + 1;
      iVar4 = **(int **)(puVar5 + 8);
      puVar5[-0xa9] = (char)(DAT_007d2fdc % 10) + '0';
      (&DAT_020b8e9f)[iVar4] = puVar5[-0xa9];
    }
    *(undefined4 *)(puVar5 + -0x54) = 0;
  }
  else {
    if (DAT_009c48f4 == 0) {
      if ((_DAT_020b90a0 & 0xffffff) == 0x204341) {
        _DAT_020b90a0 = CONCAT22(_DAT_020b90a2,DAT_0075fb60);
      }
      if ((undefined *)(_DAT_020b90a0 & 0xffffff) == &DAT_00544341) {
        _DAT_020b90a0 = 0x20544341;
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x545341) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb5e,DAT_0075fb5c);
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x534e54) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb5a,DAT_0075fb58);
      }
      if ((_DAT_020b90a0 & 0xffff) == 0x4e54) {
        _DAT_020b90a0 = CONCAT22(_DAT_020b90a2,DAT_0075fb54);
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x415453) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb52,DAT_0075fb50);
      }
      if ((undefined *)(_DAT_020b90a0 & 0xffffff) == &DAT_00524148) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb4e,DAT_0075fb4c);
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x545357) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb4a,DAT_0075fb48);
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x424e44) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb46,DAT_0075fb44);
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x425055) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb42,DAT_0075fb40);
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x41564f) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb3e,DAT_0075fb3c);
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x41424f) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb3a,DAT_0075fb38);
      }
      if (_DAT_020b90a0 == 0x31352035) {
        _DAT_020b90a0 = 0x20505050;
      }
      if (_DAT_020b90a0 == 0x32352035) {
        _DAT_020b90a0 = 0x20205050;
      }
      if (_DAT_020b90a0 == 0x33352035) {
        _DAT_020b90a0 = 0x20202050;
      }
      if (_DAT_020b90a0 == 0x34352035) {
        _DAT_020b90a0 = 0x2020504d;
      }
      if (_DAT_020b90a0 == 0x35352035) {
        _DAT_020b90a0 = 0x2020464d;
      }
      if (_DAT_020b90a0 == 0x36352035) {
        _DAT_020b90a0 = 0x20202046;
      }
      if (_DAT_020b90a0 == 0x37352035) {
        _DAT_020b90a0 = 0x20204646;
      }
      if (_DAT_020b90a0 == 0x38352035) {
        _DAT_020b90a0 = 0x20464646;
      }
      if (_DAT_020b90a0 == 0x30362035) {
        _DAT_020b90a0 = 0x20205046;
      }
      if (_DAT_020b90a0 == 0x31362035) {
        _DAT_020b90a0 = 0x20204653;
      }
      if (_DAT_020b90a0 == 0x32362035) {
        _DAT_020b90a0 = 0x205a4653;
      }
      if (_DAT_020b90a0 == 0x33362035) {
        _DAT_020b90a0 = 0x20205243;
      }
      if (_DAT_020b90a0 == 0x34362035) {
        _DAT_020b90a0 = 0x20204944;
      }
      if (_DAT_020b90a0 == 0x35362035) {
        _DAT_020b90a0 = 0x20204952;
      }
      if (_DAT_020b90a0 == 0x38362035) {
        _DAT_020b90a0 = 0x20204341;
      }
      if ((undefined *)(_DAT_020b90a0 & 0xffffff) == &DAT_00464346) {
        _DAT_020b90a0 = 0x20464946;
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x534346) {
        _DAT_020b90a0 = 0x20534946;
      }
      if ((_DAT_020b90a0 & 0xffffff) == 0x4e4346) {
        _DAT_020b90a0 = 0x204e4946;
      }
      if ((undefined *)(_DAT_020b90a0 & 0xffffff) == &DAT_00485243) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb36,DAT_0075fb34);
      }
      if ((undefined *)(_DAT_020b90a0 & 0xffffff) == &DAT_00484344) {
        _DAT_020b90a0 = CONCAT12(DAT_0075fb32,DAT_0075fb30);
      }
      if ((undefined *)(_DAT_020b90a0 & 0xffffff) == &DAT_004d5254) {
        _DAT_020b90a0 = CONCAT12(DAT_020b90a3,DAT_0075fb2c);
        _DAT_020b90a0 = CONCAT13(0x20,_DAT_020b90a0);
      }
      if ((undefined *)(_DAT_020b90a0 & 0xffffff) == &DAT_00474e46) {
        _DAT_020b90a0 = CONCAT22(DAT_0075fb28,CONCAT11((char)(_DAT_020b90a0 >> 0x18),DAT_020b90a0));
      }
      else {
        if ((_DAT_020b90a0 & 0xff) == 0x3b) {
          **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + 1;
          (&DAT_020b8e9f)[**(int **)(puVar5 + 8)] = (char)_DAT_020b90a0;
          *(undefined4 *)(puVar5 + -0x50) = 0;
LAB_00427754:
          DAT_01fb9630 = 0;
          *(undefined1 *)((int)&DAT_020b8ea0 + **(int **)(puVar5 + 8)) = 0xd;
          *(undefined1 *)((int)&DAT_020b8ea0 + **(int **)(puVar5 + 8) + 1) = 10;
          DAT_0171b230 = 0xffffffff;
          puStack_c8 = (undefined4 *)0x42779c;
          FUN_005f34d1(puVar5);
          return;
        }
        if ((_DAT_020b90a0 & 0xffff) == 0x4b42) goto LAB_0042728a;
        if ((_DAT_020b90a0 & 0xff) == 0x5e) goto LAB_004277a9;
        if ((_DAT_020b90a0 & 0xff) == 0x47) {
          *(undefined4 *)(puVar5 + -0x3c) = 0;
          DAT_020b8ea0._0_1_ = DAT_0075fb1c;
          return;
        }
      }
      thunk_FUN_0054c8e5(&DAT_020b90a0,1,*(undefined4 *)(puVar5 + 0xc));
      if ((_DAT_020b90a0 & 0xff) == 0x2f) {
        *(undefined4 *)(puVar5 + -0x38) = 0;
      }
      else {
        **(int **)(puVar5 + 0xc) = **(int **)(puVar5 + 0xc) + 1;
        (&DAT_020b90a0)[**(int **)(puVar5 + 0xc)] = 0x20;
        *(undefined4 *)(puVar5 + -0x34) = 0;
      }
    }
    else {
      **(undefined4 **)(puVar5 + 0xc) = 1;
    }
    **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + 1;
    DAT_007d2fd0 = **(int **)(puVar5 + 0xc) + **(int **)(puVar5 + 8) + -1;
    bVar16 = (_DAT_020b90a0 & 0xff) < 0x2d;
    if ((_DAT_020b90a0 & 0xff) == 0x2d) {
LAB_00427404:
      bVar16 = (byte)(&DAT_020b8e9e)[**(int **)(puVar5 + 8)] < 0x2d;
      if ((&DAT_020b8e9e)[**(int **)(puVar5 + 8)] == 0x2d) {
        *(undefined4 *)(puVar5 + -0x2c) = 0;
      }
      else {
        iVar4 = 1;
        pbVar7 = &DAT_020b8e9e + **(int **)(puVar5 + 8);
        pbVar11 = &DAT_0075fb20;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar2 = *pbVar11;
          bVar1 = *pbVar7;
          bVar16 = bVar1 < bVar2;
          pbVar7 = pbVar7 + 1;
          pbVar11 = pbVar11 + 1;
        } while (bVar1 == bVar2);
        if ((bVar16) && ((&DAT_020b8e9e)[**(int **)(puVar5 + 8)] != '/')) {
          (&DAT_020b8e9f)[**(int **)(puVar5 + 8)] = 0x2f;
          **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + 1;
          DAT_007d2fd0 = DAT_007d2fd0 + 1;
        }
        else {
          *(undefined4 *)(puVar5 + -0x28) = 0;
        }
      }
    }
    else {
      iVar4 = 1;
      pbVar7 = (byte *)&DAT_020b90a0;
      pbVar11 = &DAT_0075fb24;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar2 = *pbVar11;
        bVar1 = *pbVar7;
        bVar16 = bVar1 < bVar2;
        pbVar7 = pbVar7 + 1;
        pbVar11 = pbVar11 + 1;
      } while (bVar1 == bVar2);
      if (!(bool)(bVar16 | **(int **)(puVar5 + 8) == 1 | (_DAT_020b90a0 & 0xff) == 0x5d))
      goto LAB_00427404;
      *(undefined4 *)(puVar5 + -0x30) = 0;
    }
    iVar4 = **(int **)(puVar5 + 8);
    iVar12 = (DAT_007d2fd0 - iVar4) + 1;
    if (iVar12 < 0) {
      iVar12 = 0;
    }
    iVar8 = 1;
    for (iVar3 = 1; iVar3 <= iVar12; iVar3 = iVar3 + 1) {
      (&DAT_020b8e9f)[iVar4] = (&DAT_020b909f)[iVar8];
      iVar8 = iVar8 + 1;
      iVar4 = iVar4 + 1;
    }
    _DAT_007d2fcc = **(undefined4 **)(puVar5 + 8);
    **(int **)(puVar5 + 8) = **(int **)(puVar5 + 0xc) + **(int **)(puVar5 + 8) + -1;
  }
  if (0x455 < DAT_009a9488) {
    **(int **)(puVar5 + 8) = **(int **)(puVar5 + 8) + 1;
    (&DAT_020b8e9f)[**(int **)(puVar5 + 8)] = 0x25;
    *(undefined4 *)(puVar5 + -0x20) = 0;
    goto LAB_004269b3;
  }
  *(undefined4 *)(puVar5 + -0x24) = 0;
  *(undefined4 *)(puVar5 + -0x1c) = 0;
  if (DAT_009c48f4 == 0) {
    *(undefined4 *)(puVar5 + -0x18) = 0;
  }
  else if (((((_DAT_020b90a0 & 0xff) != 0x3b) && (DAT_020b90a0 != '\'')) &&
           ((_DAT_020b90a0 & 0xff) != 0x2f)) && ((_DAT_020b90a0 & 0xff) != 0x3a)) {
    *(undefined4 *)(puVar5 + -0x14) = 0;
    goto LAB_004275a4;
  }
  *(undefined4 *)(puVar5 + -0x10) = 0;
  if ((_DAT_020b90a0 & 0xff) == 0x3b) {
    *(undefined4 *)(puVar5 + -0xc) = 0;
    goto LAB_00427754;
  }
  thunk_FUN_005494b2(&DAT_020b8ea0,1,*(undefined4 *)(puVar5 + 8));
  if (DAT_01fb9630 == 0) {
    *(undefined4 *)(puVar5 + -8) = 0;
    goto LAB_00427754;
  }
LAB_004275a4:
  if (DAT_009c48f4 != 0xd) {
    *(undefined4 *)(puVar5 + -4) = 0;
    goto LAB_004269b3;
  }
  **(int **)(puVar5 + 0xc) = **(int **)(puVar5 + 8) + -1;
  goto LAB_00427754;
}


