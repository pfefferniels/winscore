// FUN_0044b928 @ 0044b928 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0044c150) */
/* WARNING: Removing unreachable block (ram,0x0044c0d5) */
/* WARNING: Removing unreachable block (ram,0x0044c1b3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044b928(void)

{
  undefined2 uVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  bool bVar11;
  undefined2 in_FPUControlWord;
  
  puVar5 = &stack0xfffffffc;
  if (0 < ITEM_I) {
    thunk_FUN_0054d831("Must do restart (RS) before using \"DRAW.\"",0x2a);
    return;
  }
  do {
    DAT_0171b230 = 0;
    _DAT_0078df18 = DAT_01a14950 - DAT_0078df10;
    DAT_0078df1c = DAT_0078df14 + DAT_01a1494c;
    bVar11 = DAT_0078df1c == 0;
    iVar4 = 3;
    pcVar6 = &DAT_007a0b7e;
    pcVar9 = "===";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar11 = *pcVar6 == *pcVar9;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar11);
    if (((bVar11) || ((_DAT_007a0b7c & 0xffffff) == 0x307e7e)) ||
       ((_DAT_007a0b7c & 0xffff) == 0x3d3d)) {
      thunk_FUN_0045bc18(&DAT_0078fab4);
      *(undefined4 *)(puVar5 + -0x170) = 0;
      return;
    }
    iVar4 = 5;
    bVar11 = false;
    pcVar6 = (char *)&DAT_009ae2bc;
    pcVar9 = "~~046";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar11 = *pcVar6 == *pcVar9;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar11);
    if (bVar11) {
      FUN_005f33c9(puVar5,0x44b9f4);
      FUN_005f34d1(puVar5,0x44ba0f);
      FUN_005f33c9(puVar5,0x44ba31);
      FUN_005f34d1(puVar5,0x44ba4c);
    }
    if (DAT_01fbb8a0 == 0) {
      DAT_007fe104 = thunk_FUN_00595e00();
      if (DAT_007fe104 < 0) {
        *(undefined4 *)(puVar5 + -0x168) = 0;
LAB_0044cd96:
        if ((DAT_0078fab0 != 0) && (1 < DAT_0078fab4)) {
          FUN_005f33c9(puVar5,0x44cdce);
          FUN_005f34d1(puVar5,0x44cde9);
          DAT_020b90b3._2_1_ = 0xd;
          DAT_020b90b3._3_1_ = 10;
          DAT_007fe0e8 = (undefined *)thunk_FUN_00595f30(&DAT_020b90a0,1);
          if (DAT_007fe0e8 == (undefined *)0x0) {
            DAT_007fe10c = (undefined *)0x0;
            if (DAT_007fe0fc == 0) {
              *(undefined4 *)(puVar5 + -0xd8) = 0;
              DAT_007fe10c = (undefined *)0x0;
              return;
            }
            *(undefined4 *)(puVar5 + -0xdc) = 0;
            DAT_007fe0e8 = (undefined *)0x0;
            goto LAB_0044ce48;
          }
          *(undefined4 *)(puVar5 + -0xe0) = 0;
        }
        DAT_01fbb8a0 = 0;
        thunk_FUN_0054946a("**** Leaving Draw Mode ****",0x1c);
        FUN_005f33c9(puVar5,0x44cee2);
        FUN_005f34d1(puVar5,0x44cefd);
        thunk_FUN_00468df8(&DAT_00760da0);
        DAT_00791448 = 0;
        VEC_N = 1;
        *DAT_01fbb7c0 = 0;
        DAT_020b90a0 = 0;
        thunk_FUN_00579770(&DAT_00760d9c,1,&DAT_020b90a0);
        *(undefined4 *)(puVar5 + -0xd4) = 0;
        return;
      }
      DAT_0078fab4 = 0;
      DAT_007fe10c = (undefined *)0x0;
      _DAT_007fe100 = 0;
      _DAT_01cf8f40 = 0;
      FUN_005f33c9(puVar5,0x44cfa2);
      FUN_005f34d1(puVar5,0x44cfbd);
      thunk_FUN_00468df8(&DAT_00760d84);
      FUN_0044de36();
      if (DAT_007fe104 == 1) {
        *(undefined4 *)(puVar5 + -0x164) = 0;
        goto LAB_0044daa1;
      }
      if (DAT_007fe104 != 2) {
        DAT_01fbb8a0 = 1000;
        if (DAT_007fe104 != 3) {
          *(undefined4 *)(puVar5 + -0x158) = 0;
          DAT_007fe10c = (undefined *)0x1;
          DAT_01fbb8a0 = 1000;
          return;
        }
        *(undefined4 *)(puVar5 + -0x15c) = 0;
        goto LAB_0044d4d3;
      }
      *(undefined4 *)(puVar5 + -0x160) = 0;
LAB_0044d007:
      FUN_005f34d1(puVar5,0x44d024);
      FUN_005f33c9(puVar5,0x44d046);
      FUN_005f34d1(puVar5,0x44d061);
      thunk_FUN_00571f5d(&DAT_00760d6c,0x15);
      if ((char)DAT_020b8ea0 == '\x02') {
        *(undefined4 *)(puVar5 + -0xa4) = 0;
        return;
      }
      iVar4 = FUN_005f4660(0x20);
      if (iVar4 != 0) {
        *(undefined4 *)(puVar5 + -0xa0) = 0;
        goto LAB_0044d0bf;
      }
      thunk_FUN_00518448();
      P2 = P1;
LAB_0044d117:
      *(undefined2 *)(puVar5 + -0x1a0) = in_FPUControlWord;
      *(ushort *)(puVar5 + -0x19e) = (ushort)*(undefined4 *)(puVar5 + -0x1a0) | 0xc00;
      *(int *)(puVar5 + -0x19c) = (int)ROUND(P2);
      in_FPUControlWord = *(undefined2 *)(puVar5 + -0x1a0);
      DAT_0078faac = *(int *)(puVar5 + -0x19c);
      goto LAB_0044d156;
    }
    *(undefined4 *)(puVar5 + -0x16c) = 0;
    if (DAT_01fbb8a0 == 0x3ec) {
      *(undefined4 *)(puVar5 + -0x150) = 0;
      DAT_01fbb8a0 = 0x3eb;
      return;
    }
    *(undefined4 *)(puVar5 + -0x154) = 0;
    if ((DAT_01fbb8a0 != 0x3ed) && (DAT_009ae2bc == 0x31317e7e)) {
      if ((char)DAT_009ae2c0 == '4') {
        FUN_005f33c9(puVar5,0x44bad7);
        FUN_005f34d1(puVar5,0x44baf2);
      }
      if ((char)DAT_009ae2c0 == '3') {
        FUN_005f33c9(puVar5,0x44bb23);
        FUN_005f34d1(puVar5,0x44bb3e);
      }
    }
    puVar7 = &DAT_009ae2bc;
    puVar10 = (undefined4 *)&DAT_020b8ea0;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    DAT_007fe0fc = 0;
    iVar4 = FUN_005f4660(0x20);
    if (iVar4 == 0) {
      FUN_005f33c9(puVar5,0x44bba2);
      FUN_005f34d1(puVar5,0x44bbbd);
    }
    bVar11 = iVar4 == 0 && &stack0x00000000 == (undefined1 *)0x1c4;
    iVar4 = 5;
    pcVar6 = (char *)&DAT_009ae2bc;
    pcVar9 = "~~046";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar11 = *pcVar6 == *pcVar9;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar11);
    if (bVar11) {
      FUN_005f33c9(puVar5,0x44bbf4);
      FUN_005f34d1(puVar5,0x44bc0f);
      FUN_005f33c9(puVar5,0x44bc31);
      FUN_005f34d1(puVar5,0x44bc4c);
    }
    thunk_FUN_0054c78b(&DAT_007fe0f8);
    if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x7e) {
      *(undefined4 *)(puVar5 + -0x198) = 0;
      *(undefined4 *)(puVar5 + -0x1a8) = 3;
      *(char **)(puVar5 + -0x1a4) = &DAT_020b8ea2;
      *(int **)(puVar5 + -0x1a0) = &DAT_007fe0fc;
      FUN_005f9240(puVar5 + -0x198,0x784ff00,&DAT_00760eec,puVar5 + -0x1a8,&DAT_0078f970);
      if (DAT_01fbb8a0 != 0x3ed) {
        if (DAT_007fe0fc != 0x74) {
          if (DAT_007fe0fc != 0x79) {
            if (DAT_007fe0fc == 0x7a) {
              *(undefined4 *)(puVar5 + -0x138) = 0;
            }
            else {
              if (DAT_007fe0fc != 0x7b) {
                if (DAT_007fe0fc != 0x2e) {
                  thunk_FUN_00454dbe(&DAT_007fe0fc,&DAT_0078fab4,&DAT_0078fab4,&DAT_0078fab8);
                  if (0x28 < DAT_007fe0fc) {
                    *(undefined4 *)(puVar5 + -300) = 0;
                    _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00760ee8);
                    goto LAB_0044bd74;
                  }
                  *(undefined4 *)(puVar5 + -0x128) = 0;
                  goto LAB_0044cd3c;
                }
                *(undefined4 *)(puVar5 + -0x130) = 0;
                goto LAB_0044c800;
              }
              *(undefined4 *)(puVar5 + -0x134) = 0;
            }
            goto LAB_0044c764;
          }
          *(undefined4 *)(puVar5 + -0x13c) = 0;
          goto LAB_0044c904;
        }
        *(undefined4 *)(puVar5 + -0x140) = 0;
        goto LAB_0044c6b1;
      }
      *(undefined4 *)(puVar5 + -0x144) = 0;
LAB_0044cacc:
      *(undefined4 *)(puVar5 + -0x110) = 0;
      if ((_DAT_020b8ea0 & 0xff) == 0x58) {
        FUN_005f34d1(puVar5,0x44cb12);
        if (DAT_0078faf0 != 0) {
          DAT_0078faf0 = 0;
          thunk_FUN_00468df8(&DAT_00760e0c);
          FUN_0044e9e5(&DAT_00760e08);
          FUN_0044efa3(&DAT_00760e04,&DAT_00760e04);
          goto LAB_0044cb6d;
        }
        *(undefined4 *)(puVar5 + -0x108) = 0;
      }
      else {
        *(undefined4 *)(puVar5 + -0x10c) = 0;
LAB_0044cb6d:
        thunk_FUN_00452648(&DAT_007fe0fc,&DAT_0078fab4,&DAT_0078fab8);
        FUN_005f34d1(puVar5,0x44cbaa);
        if ((_DAT_020b8ea0 & 0xff) == 0x40) {
          *(undefined4 *)(puVar5 + -0x104) = 0;
          return;
        }
        if ((_DAT_020b8ea0 & 0xff) != 0x58) {
          *(undefined4 *)(puVar5 + -0x100) = 0;
LAB_0044cbed:
          FUN_005f33c9(puVar5,0x44cc0b);
          FUN_005f34d1(puVar5,0x44cc26);
          *(undefined4 *)(puVar5 + -0x198) = 0;
          *(undefined4 *)(puVar5 + -0x1a8) = 4;
          *(undefined **)(puVar5 + -0x1a4) = &DAT_020b90b0;
          *(int **)(puVar5 + -0x1a0) = &DAT_0078fab4;
          FUN_005f34f0(puVar5 + -0x198,0x784ff00,&DAT_00760eec,puVar5 + -0x1a8,&DAT_0078f9ac);
          _DAT_0078fab8 = 1;
          _DAT_007fe0f0 = 0;
          thunk_FUN_00452648(&DAT_007fe0f0,&DAT_0078fab4,&DAT_0078fab8);
          _DAT_007fe0ec = 1;
          FUN_005f34d1(puVar5,0x44ccdc);
          *(undefined4 *)(puVar5 + -0xe4) = 0;
          return;
        }
      }
      FUN_0044e9e5(&DAT_00760e08);
      FUN_0044efa3(&DAT_00760e04,&DAT_00760e04);
      *(undefined4 *)(puVar5 + -0xfc) = 0;
      goto LAB_0044daa1;
    }
    *(undefined4 *)(puVar5 + -0x14c) = 0;
LAB_0044bd74:
    iVar4 = FUN_005f4660(0x20);
    if (iVar4 == 0) {
      FUN_005f33c9(puVar5,0x44bdb9);
      FUN_005f34d1(puVar5,0x44bdd4);
    }
    FUN_005f34d1(puVar5,0x44bdf5);
    if (((_DAT_020b8ea0 & 0xff) == 0x7e) || ((_DAT_020b8ea0 & 0xff) == 0x7c)) {
      if (DAT_01fbb8a0 == 0x3ed) {
        *(undefined4 *)(puVar5 + -0x120) = 0;
        goto LAB_0044cacc;
      }
      *(undefined4 *)(puVar5 + -0x11c) = 0;
      goto LAB_0044ce64;
    }
    *(undefined4 *)(puVar5 + -0x124) = 0;
    if ((_DAT_020b8ea0 & 0xffff) == 0x4c41) {
      _DAT_0078fab8 = 0;
      FUN_005f34d1(puVar5,0x44bf93);
      *(undefined4 *)(puVar5 + -0x118) = 0;
      _DAT_007fe0f4 = i_538976288;
      return;
    }
    if ((_DAT_020b8ea0 & 0xffff) == 0x4e4f) {
      *(undefined4 *)(puVar5 + -0x114) = 0;
      _DAT_0078fab8 = 1;
      return;
    }
    if (DAT_01fbb8a0 == 0x3ed) goto LAB_0044cacc;
    if ((_DAT_020b8ea0 & 0xffff) == 0x5244) goto LAB_0044daa1;
    if ((_DAT_020b8ea0 & 0xffff) == 0x4445) goto LAB_0044cbed;
    if ((DAT_007fe0fc == 0x78) || ((_DAT_020b8ea0 & 0xff) == 0x58)) goto LAB_0044cd96;
    if ((_DAT_020b8ea0 & 0xffffff) == 0x444c44) {
      if (DAT_0078fab4 == 0) {
        *(undefined4 *)(puVar5 + -0xd0) = 0;
        return;
      }
      FUN_005f34d1(puVar5,0x44c001);
      FUN_005f33c9(puVar5,0x44c023);
      FUN_005f34d1(puVar5,0x44c03e);
      *(undefined4 *)(puVar5 + -0xcc) = 0x80;
      DAT_007fe0e4 = 1;
      goto LAB_0044c057;
    }
    if ((_DAT_020b8ea0 & 0xff) == 0x47) {
      DAT_007fe108 = DAT_020b8ea0._1_1_;
      _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00760ea0);
      thunk_FUN_00518448();
      if (((_DAT_020b8ea0 >> 8 & 0xff) == 0x2a) || ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x2a)) {
        *(undefined4 *)(puVar5 + -0xb0) = 0;
        goto LAB_0044d117;
      }
      if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x4e) {
        DAT_0078faac = DAT_0078faac + 1;
        *(undefined4 *)(puVar5 + -0xac) = 0;
      }
      else {
        if ((_DAT_020b8ea0 >> 8 & 0xff) != 0x42) goto LAB_0044d007;
        DAT_0078faac = DAT_0078faac + -1;
        *(undefined4 *)(puVar5 + -0xa8) = 0;
      }
      goto LAB_0044d156;
    }
    if ((_DAT_020b8ea0 & 0xffff) != 0x5352) break;
    DAT_01fbb8a0 = 0;
    *(undefined4 *)(puVar5 + -0x90) = 0;
  } while( true );
  if ((_DAT_020b8ea0 & 0xffff) == 0x4943) {
    thunk_FUN_0045a8d7(&DAT_0078fab4);
    *(undefined4 *)(puVar5 + -0x8c) = 0;
    return;
  }
  if ((_DAT_020b8ea0 & 0xffff) == 0x4353) {
    if (DAT_0078fab4 < 2) {
      *(undefined4 *)(puVar5 + -0x88) = 0;
      goto LAB_0044d0bf;
    }
    if ((DAT_020b8ea2 == '\r') || (DAT_020b8ea2 == 'X')) {
      *(undefined4 *)(puVar5 + -0x84) = 0;
      FUN_005f33c9(puVar5,0x44c39b);
      FUN_005f34d1(puVar5,0x44c3b6);
      thunk_FUN_00571f5d("Type output file name. (Default = DRW.TMP)",0x2b);
      if ((char)DAT_020b8ea0 == '\x02') {
        *(undefined4 *)(puVar5 + -0x7c) = 0;
        return;
      }
      puVar7 = (undefined4 *)&DAT_020b8ea0;
      puVar10 = (undefined4 *)&DAT_020b90a0;
      for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar10 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar10 = puVar10 + 1;
      }
      iVar4 = FUN_005f4660(0x20);
      if ((iVar4 != 0) || (DAT_020b90a0 == '\0')) {
        FUN_005f33c9(puVar5,0x44c444);
        FUN_005f34d1(puVar5,0x44c45f);
      }
      puVar7 = (undefined4 *)&DAT_020b90a0;
      puVar10 = &DAT_007fe128;
      for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar10 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    else {
      *(undefined4 *)(puVar5 + -0x80) = 0;
    }
    DAT_020b911f = 0;
    *(undefined4 *)(puVar5 + -0x198) = 0;
    *(undefined4 *)(puVar5 + -0x1a8) = 0x80;
    *(undefined4 **)(puVar5 + -0x1a4) = &DAT_007fe128;
    *(undefined4 *)(puVar5 + -0x1a0) = 2;
    *(undefined4 *)(puVar5 + -0x19c) = 4;
    FUN_005f6540(puVar5 + -0x198,3,0x784ff00,&DAT_00760e58,puVar5 + -0x1a8);
    *(int *)(puVar5 + -0x74) = DAT_0078fab4;
    DAT_007fe0f8 = 1;
    iVar4 = DAT_0078fab4;
    while (0 < iVar4) {
      iVar4 = (&PT_X0)[DAT_007fe0f8];
      *(undefined4 *)(puVar5 + -0x198) = 0;
      *(int *)(puVar5 + -0x1a0) = (iVar4 + -8000) / 100;
      FUN_005fc330(puVar5 + -0x198,3,0x784ff00,&DAT_00760e54,puVar5 + -0x1a0,&DAT_0078f9d4);
      *(int *)(puVar5 + -0x1a0) = ((&PT_Y0)[DAT_007fe0f8] + 32000) / 100;
      FUN_005fc980(puVar5 + -0x198,&DAT_00760e54,puVar5 + -0x1a0);
      *(undefined4 *)(puVar5 + -0x1a0) = 2;
      *(int *)(puVar5 + -0x19c) = DAT_007fe0f8 * 2 + 0x1fbb8de;
      FUN_005fc980(puVar5 + -0x198,&DAT_00760e50,puVar5 + -0x1a0);
      DAT_007fe0f8 = DAT_007fe0f8 + 1;
      *(int *)(puVar5 + -0x74) = *(int *)(puVar5 + -0x74) + -1;
      iVar4 = *(int *)(puVar5 + -0x74);
    }
    *(undefined4 *)(puVar5 + -0x198) = 0;
    FUN_005f7950(puVar5 + -0x198,3,0x784ff00,&DAT_00760e4c,0);
    DAT_0078fab0 = 0;
    IP2 = 0;
    IP3 = 0;
    *(undefined4 *)(puVar5 + -0x68) = 0;
    goto LAB_0044daa1;
  }
  if (((_DAT_020b8ea0 & 0xffff) != 0x4552) && ((_DAT_020b8ea0 & 0xffff) != 0x4d52)) {
    if (((_DAT_020b8ea0 & 0xffff) == 0x4153) || ((_DAT_020b8ea0 & 0xffff) == 0x4d53)) {
      FUN_0044f600(&DAT_0078fab4,&DAT_0078fab0,&DAT_0078faac);
      *(undefined4 *)(puVar5 + -0x3c) = 0;
    }
    else {
      if ((_DAT_020b8ea0 & 0xffff) == 0x4553) {
LAB_0044c6b1:
        FUN_00450d32(&DAT_0078fab4);
        *(undefined4 *)(puVar5 + -0x38) = 0;
        goto LAB_0044cd3c;
      }
      if (DAT_01fbb8a0 < 0x3ea) {
        if ((_DAT_020b8ea0 & 0xffff) == 0x4d53) {
          FUN_0044f600(&DAT_0078fab4,&DAT_0078fab0,&DAT_0078faac);
          *(undefined4 *)(puVar5 + -0x10) = 0;
        }
        else if ((_DAT_020b8ea0 & 0xffff) == 0x5453) {
          if (_DAT_020b8ea0 >> 0x18 != 0x2b) {
            *(undefined4 *)(puVar5 + -8) = 0;
            return;
          }
          *(undefined4 *)(puVar5 + -0xc) = 0;
        }
        else if ((_DAT_020b8ea0 & 0xffff) == 0x4e49) {
          *(undefined4 *)(puVar5 + -4) = 0;
        }
        goto LAB_0044d0bf;
      }
      DAT_007fe10c = (undefined *)0x0;
      FUN_005f34d1(puVar5,0x44c704);
      if ((DAT_007fe0fc == 0x77) || ((_DAT_020b8ea0 & 0xffff) == 0x4c43)) {
        FUN_0045058c(&DAT_0078fab4,&DAT_00760e10);
        *(undefined4 *)(puVar5 + -0x30) = 0;
        goto LAB_0044cd3c;
      }
      if ((DAT_007fe0fc == 0x79) || ((_DAT_020b8ea0 & 0xffff) == 0x4d4a)) {
LAB_0044c904:
        thunk_FUN_0054946a("#### Jump ****",0xf);
        FUN_005f33c9(puVar5,0x44c933);
        FUN_005f34d1(puVar5,0x44c94e);
        IP1 = 1;
        IP3 = 1;
        IP2 = (int)&DAT_0100962c;
        *(undefined4 *)(puVar5 + -0x2c) = 0;
        goto LAB_0044d0bf;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 0x464a) {
LAB_0044c764:
        FUN_005f33c9(puVar5,0x44c782);
        FUN_005f34d1(puVar5,0x44c79d);
        IP1 = 2;
        IP3 = 1;
        if ((DAT_007fe0fc == 0x7b) || ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x58)) {
          IP1 = 3;
        }
        IP2 = (int)&DAT_010000ff;
      }
      else {
        if ((_DAT_020b8ea0 & 0xffff) == 0x4544) {
LAB_0044c800:
          if (DAT_0078fab4 < 2) {
            *(undefined4 *)(puVar5 + -0x28) = 0;
            return;
          }
          VEC_N = FUN_00450b9c(&DAT_0078fab4);
          *DAT_01fbb7c0 = VEC_N + -1;
          DAT_0078fab4 = DAT_0078fab4 + -1;
          _DAT_01c25e58 = DAT_0078fab4;
LAB_0044cd3c:
          FUN_0044e9e5(&DAT_0078fab4);
          *(undefined4 *)(puVar5 + -0x24) = 0;
          return;
        }
        if ((_DAT_020b8ea0 & 0xff) == 0x51) {
          FUN_0044dc3e(&DAT_0078fab4);
          *(undefined4 *)(puVar5 + -0x20) = 0;
          goto LAB_0044cd3c;
        }
        if (((((_DAT_020b8ea0 & 0xff) == 0x44) || ((_DAT_020b8ea0 & 0xff) == 0x55)) ||
            ((_DAT_020b8ea0 & 0xff) == 0x4c)) || ((_DAT_020b8ea0 & 0xff) == 0x52)) {
          thunk_FUN_004552cc(&DAT_0078fab4,&DAT_0078fab8,&DAT_00760e34,&DAT_00760e34);
          *(undefined4 *)(puVar5 + -0x1c) = 0;
          goto LAB_0044cd3c;
        }
      }
LAB_0044ce48:
      if (DAT_007fe10c != (undefined *)0x0) {
        *(undefined4 *)(puVar5 + -0x14) = 0;
LAB_0044ce64:
        DAT_007fe10c = (undefined *)0x1;
        FUN_0044e255(&DAT_0078fab4,&DAT_007fe10c);
        *(undefined4 *)(puVar5 + -0xec) = 0;
        DAT_0078fab0 = 1;
        return;
      }
      *(undefined4 *)(puVar5 + -0x18) = 0;
    }
LAB_0044d0bf:
    FUN_005f34d1(puVar5,0x44d0dc);
    FUN_005f34d1(puVar5,0x44d0fd);
    return;
  }
  DAT_0078faf4 = DAT_020b8ea0;
  if ((DAT_020b8ea2 == '\r') || (DAT_020b8ea2 == 'X')) {
    *(undefined4 *)(puVar5 + -100) = 0;
LAB_0044d4d3:
    FUN_005f34d1(puVar5,0x44d4f0);
    FUN_005f33c9(puVar5,0x44d512);
    FUN_005f34d1(puVar5,0x44d52d);
    thunk_FUN_00571f5d("Type input file name. (Default = DRW.TMP)",0x2a);
    if ((char)DAT_020b8ea0 == '\x02') {
      *(undefined4 *)(puVar5 + -0x5c) = 0;
      return;
    }
    puVar7 = (undefined4 *)&DAT_020b8ea0;
    puVar10 = (undefined4 *)&DAT_020b90a0;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    iVar4 = FUN_005f4660(0x20);
    if ((iVar4 != 0) || (DAT_020b90a0 == '\0')) {
      FUN_005f33c9(puVar5,0x44d5bb);
      FUN_005f34d1(puVar5,0x44d5d6);
    }
  }
  else {
    FUN_00450bb7();
    *(undefined4 *)(puVar5 + -0x60) = 0;
  }
  DAT_020b911f = 0;
  *(undefined4 *)(puVar5 + -0x198) = 0;
  *(undefined4 *)(puVar5 + -0x1b0) = 0x200;
  *(char **)(puVar5 + -0x1ac) = &DAT_020b90a0;
  *(undefined4 *)(puVar5 + -0x1a8) = 3;
  *(undefined **)(puVar5 + -0x1a4) = &DAT_00760d30;
  *(undefined4 *)(puVar5 + -0x1a0) = 2;
  uVar3 = FUN_005f6540(puVar5 + -0x198,3,0x784ff01,&DAT_00760d20,puVar5 + -0x1b0);
  *(undefined4 *)(puVar5 + -0x58) = uVar3;
  if (*(int *)(puVar5 + -0x58) == 0) {
    thunk_FUN_0054cd71(&DAT_020b90a0,1,&DAT_00760d1c,&DAT_007fe0e8);
    thunk_FUN_00579770(&DAT_00760d9c,1,&DAT_020b90a0);
    if (DAT_0078faf4 == 0x4d52) {
      *(undefined4 *)(puVar5 + -0x54) = 0;
    }
    else {
      DAT_0078fab4 = 0;
      VEC_N = 0x19;
      FUN_005f34d1(puVar5,0x44d6e6);
    }
    while( true ) {
      DAT_0078fab4 = DAT_0078fab4 + 1;
      *(undefined1 **)(puVar5 + -0x19c) = puVar5 + -0x238;
      iVar4 = 1;
      for (iVar8 = 1; iVar8 < 0x79; iVar8 = iVar8 + 1) {
        *(undefined1 *)(*(int *)(puVar5 + -0x19c) + -1 + iVar8) = (&DAT_020b8e9f)[iVar4];
        iVar4 = iVar4 + 1;
      }
      *(undefined4 *)(puVar5 + -0x198) = 0;
      *(undefined4 *)(puVar5 + -0x1b0) = 0x78;
      *(undefined4 *)(puVar5 + -0x1ac) = *(undefined4 *)(puVar5 + -0x19c);
      *(undefined4 *)(puVar5 + -0x1a8) = 1;
      *(undefined **)(puVar5 + -0x23c) = &DAT_0078f9f4;
      *(undefined1 **)(puVar5 + -0x240) = puVar5 + -0x1b0;
      *(undefined **)(puVar5 + -0x244) = &DAT_00760d18;
      *(undefined4 *)(puVar5 + -0x248) = 0x784ff01;
      *(undefined4 *)(puVar5 + -0x24c) = 3;
      *(undefined1 **)(puVar5 + -0x250) = puVar5 + -0x198;
      *(undefined4 *)(puVar5 + -0x254) = 0x44d798;
      iVar4 = FUN_005fdbd0();
      *(int *)(puVar5 + -0x50) = iVar4;
      if (iVar4 == 0) {
        iVar8 = 1;
        for (iVar4 = 1; iVar4 < 0x79; iVar4 = iVar4 + 1) {
          (&DAT_020b8e9f)[iVar8] = *(undefined1 *)(*(int *)(puVar5 + -0x19c) + -1 + iVar4);
          iVar8 = iVar8 + 1;
        }
        *(undefined4 *)(puVar5 + -0x240) = 0;
        *(undefined **)(puVar5 + -0x244) = &DAT_00760d14;
        *(undefined1 **)(puVar5 + -0x248) = puVar5 + -0x198;
        *(undefined4 *)(puVar5 + -0x24c) = 0x44d7f4;
        uVar3 = FUN_005fe110();
        *(undefined4 *)(puVar5 + -0x50) = uVar3;
      }
      if (*(int *)(puVar5 + -0x50) != 0) break;
      *(undefined4 *)(puVar5 + -0x1c4) = 0x44d814;
      thunk_FUN_00518448();
      *(undefined2 *)(puVar5 + -0x1a0) = in_FPUControlWord;
      *(ushort *)(puVar5 + -0x19e) = (ushort)*(undefined4 *)(puVar5 + -0x1a0) | 0xc00;
      *(int *)(puVar5 + -0x19c) = (int)ROUND(P1 * f_100 + f_8000);
      uVar1 = *(undefined2 *)(puVar5 + -0x1a0);
      (&PT_X0)[DAT_0078fab4] = *(undefined4 *)(puVar5 + -0x19c);
      *(undefined2 *)(puVar5 + -0x1a0) = uVar1;
      *(ushort *)(puVar5 + -0x19e) = (ushort)*(undefined4 *)(puVar5 + -0x1a0) | 0xc00;
      *(int *)(puVar5 + -0x19c) = (int)ROUND(P2 * f_100 - f_32000);
      uVar1 = *(undefined2 *)(puVar5 + -0x1a0);
      (&PT_Y0)[DAT_0078fab4] = *(undefined4 *)(puVar5 + -0x19c);
      *(undefined2 *)(puVar5 + -0x1a0) = uVar1;
      *(ushort *)(puVar5 + -0x19e) = (ushort)*(undefined4 *)(puVar5 + -0x1a0) | 0xc00;
      *(int *)(puVar5 + -0x19c) = (int)ROUND(P3);
      in_FPUControlWord = *(undefined2 *)(puVar5 + -0x1a0);
      *(undefined2 *)((int)&DAT_01fbb8dc + DAT_0078fab4 * 2 + 2) = *(undefined2 *)(puVar5 + -0x19c);
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
           (&PT_X0)[DAT_0078fab4] + DAT_0078df10;
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
           (&PT_Y0)[DAT_0078fab4] - DAT_0078df14;
      DAT_007fe0e8 = (undefined *)0x0;
      if (P3 == f_1) {
        DAT_007fe0e8 = &DAT_0100962c;
      }
      if (f_1 < P3) {
        DAT_007fe0e8 = &DAT_010000ff;
      }
      *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
           DAT_007fe0e8;
      VEC_N = VEC_N + 3;
      *(undefined4 *)(puVar5 + -0x4c) = 0;
    }
    DAT_0078fab4 = DAT_0078fab4 + -1;
    _DAT_01c25e58 = DAT_0078fab4;
    *DAT_01fbb7c0 = VEC_N + -1;
  }
  else {
    thunk_FUN_0042ac4e(&DAT_020b90a0,0x80);
    *(undefined4 *)(puVar5 + -0x40) = 0;
  }
  *(undefined4 *)(puVar5 + -0x198) = 0;
  FUN_005f7950(puVar5 + -0x198,3,0x784ff00,&DAT_00760e4c,0);
  goto LAB_0044da78;
  while( true ) {
    *(undefined4 *)(puVar5 + -200) = 0;
    *(undefined4 *)(puVar5 + -0xc0) = 0;
    DAT_007fe0e4 = DAT_007fe0e4 + 1;
    *(int *)(puVar5 + -0xcc) = *(int *)(puVar5 + -0xcc) + -1;
    if (*(int *)(puVar5 + -0xcc) < 1) break;
LAB_0044c057:
    if ((&DAT_020b8e9f)[DAT_007fe0e4] == '\0') {
      (&DAT_020b8e9f)[DAT_007fe0e4] = 0x20;
      *(undefined4 *)(puVar5 + -0xc4) = 0;
      break;
    }
  }
  *(undefined4 *)(puVar5 + -0x198) = 0;
  *(undefined4 *)(puVar5 + -0x1a8) = 4;
  *(int *)(puVar5 + -0x1a4) = DAT_007fe0e4 + 0x20b8ea9;
  *(int **)(puVar5 + -0x1a0) = &DAT_0078faac;
  FUN_005f34f0(puVar5 + -0x198,0x784ff00,&DAT_00760eec,puVar5 + -0x1a8,&DAT_0078f9c0);
  (&DAT_020b8e9f)[DAT_007fe0e4] = 10;
  FUN_005f46bc(puVar5,0x44c174);
  FUN_005f34d1(puVar5,0x44c18a);
  DAT_007fe0e4 = DAT_007fe0e4 + 0xf;
  FUN_005f46bc(puVar5,0x44c1d7);
  FUN_005f34d1(puVar5,0x44c1ed);
  DAT_007fe0e0 = thunk_FUN_00595f30(&DAT_020b8ea0,1);
  if (DAT_007fe0e0 == 0) {
    *(undefined4 *)(puVar5 + -0xb8) = 0;
    return;
  }
  *(undefined4 *)(puVar5 + -0xb4) = 0;
LAB_0044d156:
  DAT_007fe0dc = DAT_0078faac / 10;
  load_symbol_library(&DAT_007fe0dc,&DAT_01c2cd10,&DAT_01c2cc20,0x18);
  if ((_DAT_020b8ea0 & 0xff) != 0x23) {
    *(undefined2 *)(puVar5 + -0x1a0) = in_FPUControlWord;
    *(ushort *)(puVar5 + -0x19e) = (ushort)*(undefined4 *)(puVar5 + -0x1a0) | 0xc00;
    *(int *)(puVar5 + -0x19c) = (int)ROUND(P1);
    in_FPUControlWord = *(undefined2 *)(puVar5 + -0x1a0);
    DAT_0078faac = *(int *)(puVar5 + -0x19c);
  }
  FUN_00450f1b(&DAT_0078faac,&DAT_007fe0dc,&DAT_01cf8f44,0x80,&DAT_01c2cc20,0x18);
  if (DAT_007fe108 == 'M') {
    *(undefined4 *)(puVar5 + -0x9c) = 0;
  }
  else {
    DAT_0078fab4 = 0;
    VEC_N = 0x19;
  }
  DAT_007fe0f8 = (int)*(short *)(&DAT_01c2cd0e + DAT_007fe0dc * 2);
  iVar4 = (int)*(short *)(&DAT_01c2cd10 + DAT_007fe0dc * 2) -
          (int)*(short *)(&DAT_01c2cd0e + DAT_007fe0dc * 2);
  *(int *)(puVar5 + -0x98) = iVar4;
  while (0 < iVar4) {
    DAT_0078fab4 = DAT_0078fab4 + 1;
    fVar2 = *(float *)(&DAT_01dc41fc + DAT_007fe0f8 * 4);
    *(undefined2 *)(puVar5 + -0x1a0) = in_FPUControlWord;
    *(ushort *)(puVar5 + -0x19e) = (ushort)*(undefined4 *)(puVar5 + -0x1a0) | 0xc00;
    *(int *)(puVar5 + -0x19c) = (int)ROUND(fVar2 * f_100 + f_8000);
    uVar1 = *(undefined2 *)(puVar5 + -0x1a0);
    (&PT_X0)[DAT_0078fab4] = *(undefined4 *)(puVar5 + -0x19c);
    fVar2 = *(float *)(&DAT_01e123fc + DAT_007fe0f8 * 4);
    *(undefined2 *)(puVar5 + -0x1a0) = uVar1;
    *(ushort *)(puVar5 + -0x19e) = (ushort)*(undefined4 *)(puVar5 + -0x1a0) | 0xc00;
    *(int *)(puVar5 + -0x19c) = (int)ROUND(fVar2 * f_100 - f_32000);
    in_FPUControlWord = *(undefined2 *)(puVar5 + -0x1a0);
    (&PT_Y0)[DAT_0078fab4] = *(undefined4 *)(puVar5 + -0x19c);
    *(undefined2 *)((int)&DAT_01fbb8dc + DAT_0078fab4 * 2 + 2) =
         *(undefined2 *)(&DAT_01d9d0fe + DAT_007fe0f8 * 2);
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
         (&PT_X0)[DAT_0078fab4] + DAT_0078df10;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
         (&PT_Y0)[DAT_0078fab4] - DAT_0078df14;
    DAT_007fe10c = (undefined *)(int)*(short *)((int)&DAT_01fbb8dc + DAT_0078fab4 * 2 + 2);
    if ((int)DAT_007fe10c < 0) {
      DAT_007fe10c = (undefined *)0x0;
    }
    if (1 < (int)DAT_007fe10c) {
      DAT_007fe10c = &DAT_010000ff;
    }
    if (DAT_007fe10c == (undefined *)0x1) {
      DAT_007fe10c = &DAT_0100962c;
    }
    *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) = DAT_007fe10c;
    VEC_N = VEC_N + 3;
    DAT_007fe0f8 = DAT_007fe0f8 + 1;
    *(int *)(puVar5 + -0x98) = *(int *)(puVar5 + -0x98) + -1;
    iVar4 = *(int *)(puVar5 + -0x98);
  }
  _DAT_01c25e58 = DAT_0078fab4;
  *DAT_01fbb7c0 = VEC_N + -1;
  DAT_01fbb8a0 = 0x3ea;
  *(undefined4 *)(puVar5 + -0x94) = 0;
LAB_0044da78:
  FUN_0044e9e5(&DAT_0078fab4);
  IP2 = 0;
  IP3 = 0;
  *(undefined4 *)(puVar5 + -0x44) = 0;
LAB_0044daa1:
  DAT_01fbb8a0 = 0x3ea;
  FUN_005f33c9(puVar5,0x44daca);
  FUN_005f34d1(puVar5,0x44dae5);
  *(undefined4 *)(puVar5 + -0x198) = 0;
  *(undefined4 *)(puVar5 + -0x1a8) = 4;
  *(int **)(puVar5 + -0x1a4) = &DAT_009ae2bc;
  *(int **)(puVar5 + -0x1a0) = &DAT_0078faac;
  FUN_005f34f0(puVar5 + -0x198,0x784ff00,&DAT_00760eec,puVar5 + -0x1a8,&DAT_0078f984);
  *(undefined4 *)(puVar5 + -0x198) = 0;
  *(undefined4 *)(puVar5 + -0x1a8) = 4;
  *(undefined4 **)(puVar5 + -0x1a4) = &DAT_009ae2d1;
  *(int **)(puVar5 + -0x1a0) = &DAT_0078fab4;
  FUN_005f34f0(puVar5 + -0x198,0x784ff00,&DAT_00760eec,puVar5 + -0x1a8,&DAT_0078f998);
  FUN_005f34d1(puVar5,0x44dbb4);
  thunk_FUN_00468df8(&DAT_00760d84);
  *(undefined4 *)(puVar5 + -0xf0) = 0;
  return;
}


