// FUN_00422d98 @ 00422d98 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00422f87) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00422d98(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  short *psVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  short *psVar10;
  byte *pbVar11;
  int iVar12;
  undefined4 *puVar13;
  bool bVar14;
  bool bVar15;
  float10 fVar16;
  
  puVar6 = &stack0xfffffffc;
  DAT_01fb9630 = 1;
  DAT_007cc600 = 0;
  DAT_007cc604 = 1;
  DAT_00794834 = DAT_020b8e58;
  DAT_007d2c74 = 0;
  DAT_00794830 = 0;
  DAT_007d2c70 = 0;
  DAT_007d2c6c = 0;
  DAT_007d2c68 = 0;
  DAT_01fb8c90 = 0;
  FUN_005f34d1(&stack0xfffffffc,0x422e1b);
  DAT_0171b230 = 1;
LAB_00422e2a:
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            FUN_005f34d1(puVar6,0x422e47);
            puVar9 = (undefined4 *)&DAT_020b8ea0;
            puVar13 = &DAT_007d2c88;
            for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar13 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar13 = puVar13 + 1;
            }
            thunk_FUN_00549afb();
            if ((DAT_007cc600 != 0) ||
               (((uint)_DAT_020b90a0 & 0xff) != 0x3b && ((uint)_DAT_020b90a0 & 0xff) != 0x2f))
            break;
            *(undefined4 *)(puVar6 + -0x14c) = 0;
          }
          thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
          puVar9 = &DAT_007d2c88;
          puVar13 = (undefined4 *)&DAT_020b8ea0;
          for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar13 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar13 = puVar13 + 1;
          }
          if (DAT_020b90a0 == '\'') {
            _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,DAT_0075fa1c);
          }
          if (((uint)_DAT_020b90a0 & 0xff) != 0x2b) break;
          DAT_007d2c68 = DAT_007d2c68 + 1;
          *(undefined4 *)(puVar6 + -0x148) = 0;
        }
        if ((((uint)_DAT_020b90a0 & 0xff) != 0x2d) || ((&DAT_020b8e9f)[DAT_007cc600] == '@')) break;
        DAT_007d2c6c = DAT_007d2c6c + 1;
        *(undefined4 *)(puVar6 + -0x144) = 0;
      }
      iVar4 = FUN_005f4660(0x20);
      if (iVar4 == 0) break;
      thunk_FUN_004e5988();
      DAT_007cc600 = DAT_007cc600 + -3;
      FUN_005f46bc(puVar6,0x4245cb);
      FUN_005f34d1(puVar6,0x4245e1);
      thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
      *(undefined4 *)(puVar6 + -0x13c) = 0;
    }
    *(undefined4 *)(puVar6 + -0x140) = 0;
    iVar4 = 3;
    bVar14 = true;
    psVar7 = (short *)&DAT_020b90a0;
    psVar10 = &DAT_0075fa10;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar14 = *psVar7 == *psVar10;
      psVar7 = psVar7 + 1;
      psVar10 = psVar10 + 1;
    } while (bVar14);
    if ((bVar14) || (((uint)_DAT_020b90a0 & 0xff) == 0x26)) {
      DAT_009c6ae0 = 1;
    }
    else {
      iVar4 = 3;
      bVar14 = false;
      psVar7 = (short *)&DAT_020b90a0;
      psVar10 = &DAT_0075fa08;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar14 = *psVar7 == *psVar10;
        psVar7 = psVar7 + 1;
        psVar10 = psVar10 + 1;
      } while (bVar14);
      if ((!bVar14) && (((uint)_DAT_020b90a0 & 0xff) != 0x28)) {
        if (DAT_009a9488 == 0) {
LAB_00423339:
          if (((uint)_DAT_020b90a0 & 0xffff) != 0x467e) {
LAB_00423599:
            if (DAT_009c48f4 == 8) {
              if (DAT_007cc600 < 2) {
                DAT_020b8ea0._0_1_ = DAT_0075f984;
                DAT_007cc600 = 0;
                *(undefined4 *)(puVar6 + -0x128) = 0;
                goto LAB_00422e2a;
              }
              *(undefined4 *)(puVar6 + -300) = 0;
            }
            else {
              *(undefined4 *)(puVar6 + -0x130) = 0;
              if (DAT_009c48f4 == 0) {
                if (((uint)_DAT_020b90a0 & 0xff) == 0x7e) {
                  *(undefined4 *)(puVar6 + -0x124) = 0;
                  goto LAB_00422e2a;
                }
                if (((uint)_DAT_020b90a0 & 0xff) == 0x3b) {
                  if (DAT_0079485c <= DAT_007d2c5c) {
                    if ((&DAT_020b8e9e)[DAT_007cc600] == '/') {
                      DAT_007cc600 = DAT_007cc600 + -1;
                    }
                    (&DAT_020b8e9f)[DAT_007cc600] = SUB41(_DAT_020b90a0,0);
                    *(undefined4 *)(puVar6 + -0x11c) = 0;
LAB_00424753:
                    cVar1 = DAT_020b8ea0._1_1_;
                    DAT_01fb9630 = 0;
                    bVar14 = DAT_020b8ea0._1_1_ == ';';
                    DAT_020b8ea0._1_1_ = (char)i_991961176;
                    if (bVar14) {
                      DAT_020b8ea2 = (char)((uint)i_991961176 >> 8);
                      _DAT_020b8ea3 = (undefined2)((uint)i_991961176 >> 0x10);
                      DAT_020b8ea5 = DAT_0075f96c;
                      DAT_007cc600 = 5;
                      DAT_007d2c78 = i_845754664;
                      DAT_007d2c7c = DAT_0075f964;
                      if (DAT_01fb8c88 < 10) {
                        DAT_007d2c78 = i_828977448;
                        DAT_007d2c7c = DAT_0075f95c;
                      }
                      *(undefined4 *)(puVar6 + -0x16c) = 0;
                      *(int *)(puVar6 + -0x174) = DAT_007d2c78;
                      puVar6[-0x170] = DAT_007d2c7c;
                      *(undefined4 *)(puVar6 + -0x188) = 2;
                      *(char **)(puVar6 + -0x184) = &DAT_020b8ea2;
                      *(int **)(puVar6 + -0x180) = &DAT_01fb8c88;
                      *(undefined4 *)(puVar6 + -0x1a0) = *(undefined4 *)(puVar6 + -0x174);
                      puVar6[-0x19c] = puVar6[-0x170];
                      *(undefined1 **)(puVar6 + -400) = puVar6 + -0x1a0;
                      *(undefined4 *)(puVar6 + -0x198) = 5;
                      FUN_005f34f0(puVar6 + -0x16c,0x784ff08,&DAT_0075f950,puVar6 + -0x188,
                                   puVar6 + -0x198);
                      cVar1 = DAT_020b8ea0._1_1_;
                    }
                    else if ((DAT_020b8ea2 == ';') && ((char)DAT_020b8ea0 != '@')) {
                      _DAT_020b8ea3 = (undefined2)((uint)i_991961176 >> 8);
                      DAT_020b8ea5 = (undefined1)((uint)i_991961176 >> 0x18);
                      DAT_020b8ea6 = DAT_0075f96c;
                      DAT_007cc600 = 5;
                      DAT_007d2c78 = i_845754664;
                      DAT_007d2c7c = DAT_0075f964;
                      if (DAT_01fb8c88 < 10) {
                        DAT_007d2c78 = i_828977448;
                        DAT_007d2c7c = DAT_0075f95c;
                      }
                      *(undefined4 *)(puVar6 + -0x16c) = 0;
                      *(int *)(puVar6 + -0x174) = DAT_007d2c78;
                      puVar6[-0x170] = DAT_007d2c7c;
                      *(undefined4 *)(puVar6 + -0x188) = 2;
                      *(undefined1 **)(puVar6 + -0x184) = &DAT_020b8ea3;
                      *(int **)(puVar6 + -0x180) = &DAT_01fb8c88;
                      *(undefined4 *)(puVar6 + -0x1a0) = *(undefined4 *)(puVar6 + -0x174);
                      puVar6[-0x19c] = puVar6[-0x170];
                      *(undefined1 **)(puVar6 + -400) = puVar6 + -0x1a0;
                      *(undefined4 *)(puVar6 + -0x198) = 5;
                      DAT_020b8ea2 = DAT_020b8ea0._1_1_;
                      DAT_020b8ea0._1_1_ = cVar1;
                      FUN_005f34f0(puVar6 + -0x16c,0x784ff08,&DAT_0075f950,puVar6 + -0x188,
                                   puVar6 + -0x198);
                      cVar1 = DAT_020b8ea0._1_1_;
                    }
                    DAT_020b8ea0._1_1_ = cVar1;
                    *(undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600) = 0xd;
                    *(undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600 + 1) = 10;
                    DAT_0171b230 = 0;
                    FUN_005f34d1(puVar6,0x4249bc);
                    return;
                  }
                  *(undefined4 *)(puVar6 + -0x120) = 0;
                  goto LAB_00422e2a;
                }
                if (((uint)_DAT_020b90a0 & 0xffff) != 0x4b42) {
                  if (((uint)_DAT_020b90a0 & 0xff) != 0x5e) {
                    if (_DAT_020b90a0 == 803988.8) {
                      *(undefined4 *)(puVar6 + -0xf4) = 0;
                      return;
                    }
                    goto code_r0x0042364d;
                  }
                  goto LAB_004236b4;
                }
              }
              else {
                if (DAT_009c48f4 == 0x1b) {
                  _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,DAT_0075f9e8);
                }
                if (((uint)_DAT_020b90a0 & 0xff) == 0x5e) {
                  *(undefined4 *)(puVar6 + -0xa4) = 0;
LAB_004236b4:
                  iVar4 = thunk_FUN_005956b0();
                  if (iVar4 == 0) {
                    *(undefined4 *)(puVar6 + -0xfc) = 0;
                    DAT_020b8ea0._0_1_ = DAT_0075f970;
                    return;
                  }
                  if (0 < iVar4) {
                    *(undefined4 *)(puVar6 + -0xf8) = 0;
                    return;
                  }
                  *(undefined4 *)(puVar6 + -0x100) = 0;
                  goto LAB_00422e2a;
                }
                if (DAT_009c48f4 == 0x60) {
                  *(undefined4 *)(puVar6 + -0xa0) = 0;
                  _DAT_020b90a0 = f_803988_8;
                  return;
                }
                if (DAT_009c48f4 == 0x11) {
                  DAT_007d2c70 = 1;
                  *(undefined4 *)(puVar6 + -0x9c) = 0;
                  goto LAB_00422e2a;
                }
                **(undefined4 **)(puVar6 + 0xc) = 1;
                bVar14 = DAT_020b90a0 < 8;
                if (DAT_020b90a0 != 8) {
                  iVar4 = 1;
                  bVar15 = false;
                  pbVar8 = &DAT_020b90a0;
                  pbVar11 = &DAT_0075f9c8;
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar14 = *pbVar8 < *pbVar11;
                    bVar15 = *pbVar8 == *pbVar11;
                    pbVar8 = pbVar8 + 1;
                    pbVar11 = pbVar11 + 1;
                  } while (bVar15);
                  if (!bVar14) {
                    iVar4 = 1;
                    pbVar8 = &DAT_020b90a0;
                    pbVar11 = &DAT_0075f9c4;
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar14 = *pbVar8 < *pbVar11;
                      bVar15 = *pbVar8 == *pbVar11;
                      pbVar8 = pbVar8 + 1;
                      pbVar11 = pbVar11 + 1;
                    } while (bVar15);
                    if (bVar14 || bVar15) {
                      _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,DAT_020b90a0 - 0x20);
                    }
                  }
                  goto LAB_00423767;
                }
                *(undefined4 *)(puVar6 + -0x98) = 0;
              }
            }
LAB_004242a7:
            if (DAT_007cc600 < 1) {
              *(undefined4 *)(puVar6 + -0x118) = 0;
            }
            else if ((&DAT_020b8e9f)[DAT_007cc600] == '/') {
              DAT_007d2c58 = *(int *)(DAT_007d2c74 * 4 + 0x7ccacc);
              iVar4 = (DAT_00794834 - DAT_007d2c58) + 1;
              *(int *)(puVar6 + -0x110) = iVar4;
              while (0 < iVar4) {
                DAT_007d2c60 = (&ITEM_PTR0)[DAT_007d2c58];
                if ((float)(&ITEM_P1)[DAT_007d2c60] == f_1) {
                  *(float *)(&ITEM_P9 + DAT_007d2c60 * 4) = f_0;
                  (&ITEM_P6)[DAT_007d2c60] = f_0;
                  iVar4 = DAT_007d2c60 * 4;
                  fVar16 = (float10)amod(&ITEM_P8 + DAT_007d2c60 * 4,&DAT_0075f978);
                  *(float *)(&ITEM_P8 + iVar4) = (float)fVar16;
                  iVar4 = DAT_007d2c60;
                  fVar16 = (float10)amod(&ITEM_P4 + DAT_007d2c60,&DAT_0075f978);
                  (&ITEM_P4)[iVar4] = (float)fVar16;
                }
                else {
                  *(undefined4 *)(puVar6 + -0x10c) = 0;
                }
                *(undefined4 *)(puVar6 + -0x108) = 0;
                DAT_007d2c58 = DAT_007d2c58 + 1;
                *(int *)(puVar6 + -0x110) = *(int *)(puVar6 + -0x110) + -1;
                iVar4 = *(int *)(puVar6 + -0x110);
              }
              DAT_00794834 = *(int *)(DAT_007d2c74 * 4 + 0x7ccacc);
              DAT_00794830 = *(int *)(DAT_007d2c74 * 4 + 0x7cc870);
              DAT_007cc600 = (&DAT_007cd680)[DAT_007d2c74];
              thunk_FUN_004ddb6e(&DAT_00794834);
              DAT_007d2c74 = DAT_007d2c74 + -1;
              DAT_00794834 = DAT_00794834 + -1;
              DAT_007cc604 = DAT_007cc600 + 1;
              FUN_005f46bc(puVar6,0x4244b1);
              FUN_005f34d1(puVar6,0x4244c7);
              thunk_FUN_0054943a();
              thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
              *(undefined4 *)(puVar6 + -0x104) = 0;
            }
            else {
              DAT_007cc600 = DAT_007cc600 + -1;
              *(undefined4 *)(puVar6 + -0x114) = 0;
            }
            goto LAB_00422e2a;
          }
          uVar2 = (uint)_DAT_020b90a0 >> 0x10 & 0xff;
          DAT_007d2c60 = uVar2 - 0x30;
          switch(uVar2) {
          case 0x32:
            FUN_005f33c9(puVar6,&UNK_004233a3);
            FUN_005f34d1(puVar6,&UNK_004233be);
            *(undefined4 *)(puVar6 + -0xc0) = 0;
            break;
          case 0x33:
            FUN_005f33c9(puVar6,&UNK_004233ef);
            FUN_005f34d1(puVar6,&UNK_0042340a);
            *(undefined4 *)(puVar6 + -0xbc) = 0;
            break;
          case 0x34:
            FUN_005f33c9(puVar6,&UNK_0042343b);
            FUN_005f34d1(puVar6,&UNK_00423456);
            *(undefined4 *)(puVar6 + -0xb8) = 0;
            break;
          case 0x35:
            FUN_005f33c9(puVar6,&UNK_00423487);
            FUN_005f34d1(puVar6,&UNK_004234a2);
            *(undefined4 *)(puVar6 + -0xb4) = 0;
            break;
          case 0x36:
            FUN_005f33c9(puVar6,&UNK_004234d3);
            FUN_005f34d1(puVar6,&UNK_004234ee);
            *(undefined4 *)(puVar6 + -0xb0) = 0;
            break;
          case 0x37:
            FUN_005f33c9(puVar6,&UNK_0042351f);
            FUN_005f34d1(puVar6,&UNK_0042353a);
            *(undefined4 *)(puVar6 + -0xac) = 0;
            break;
          case 0x38:
            FUN_005f33c9(puVar6,&UNK_0042356b);
            FUN_005f34d1(puVar6,&UNK_00423586);
            *(undefined4 *)(puVar6 + -0xa8) = 0;
            break;
          default:
            goto LAB_00423599;
          }
        }
        else {
          switch(DAT_009c48f4) {
          case 0x71:
            FUN_005f33c9(puVar6,&UNK_0042305f);
            FUN_005f34d1(puVar6,&UNK_0042307a);
            *(undefined4 *)(puVar6 + -0xec) = 0;
            break;
          case 0x72:
            FUN_005f33c9(puVar6,&UNK_004230ab);
            FUN_005f34d1(puVar6,&UNK_004230c6);
            *(undefined4 *)(puVar6 + -0xe8) = 0;
            break;
          case 0x73:
            FUN_005f33c9(puVar6,&UNK_004230f7);
            FUN_005f34d1(puVar6,&UNK_00423112);
            *(undefined4 *)(puVar6 + -0xe4) = 0;
            break;
          case 0x74:
            FUN_005f33c9(puVar6,&UNK_00423143);
            FUN_005f34d1(puVar6,&UNK_0042315e);
            *(undefined4 *)(puVar6 + -0xe0) = 0;
            break;
          case 0x75:
            FUN_005f33c9(puVar6,&UNK_0042318f);
            FUN_005f34d1(puVar6,&UNK_004231aa);
            *(undefined4 *)(puVar6 + -0xdc) = 0;
            break;
          case 0x76:
            FUN_005f33c9(puVar6,&UNK_004231db);
            FUN_005f34d1(puVar6,&UNK_004231f6);
            *(undefined4 *)(puVar6 + -0xd8) = 0;
            break;
          case 0x77:
            FUN_005f33c9(puVar6,&UNK_00423227);
            FUN_005f34d1(puVar6,&UNK_00423242);
            *(undefined4 *)(puVar6 + -0xd4) = 0;
            break;
          case 0x78:
            FUN_005f33c9(puVar6,&UNK_00423273);
            FUN_005f34d1(puVar6,&UNK_0042328e);
            *(undefined4 *)(puVar6 + -0xd0) = 0;
            goto LAB_004236b4;
          case 0x79:
            FUN_005f33c9(puVar6,&UNK_004232bf);
            FUN_005f34d1(puVar6,&UNK_004232da);
            *(undefined4 *)(puVar6 + -0xcc) = 0;
            break;
          case 0x7a:
            FUN_005f33c9(puVar6,&UNK_0042330b);
            FUN_005f34d1(puVar6,&UNK_00423326);
            *(undefined4 *)(puVar6 + -200) = 0;
            break;
          case 0x7b:
            FUN_005f33c9(puVar6,&LAB_00424630);
            FUN_005f34d1(puVar6,&LAB_0042464b);
            *(undefined4 *)(puVar6 + -0xc4) = 0;
            return;
          default:
            goto LAB_00423339;
          }
        }
code_r0x0042364d:
        thunk_FUN_0054c8e5(&DAT_020b90a0,1,*(undefined4 *)(puVar6 + 0xc));
        DAT_009c48f4 = 0;
        *(undefined4 *)(puVar6 + -0xf0) = 0;
LAB_00423767:
        iVar4 = DAT_007cc600 + 1;
        DAT_007d2c58 = **(int **)(puVar6 + 0xc) + iVar4 + -1;
        if ((&DAT_020b8e9f)[DAT_007cc600] == 'T') {
          if (((uint)_DAT_020b90a0 & 0xff) == 0x32) {
            _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,DAT_0075f9c0);
          }
          if (((uint)_DAT_020b90a0 & 0xff) == 0x34) {
            _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,DAT_0075f9bc);
          }
          if (((uint)_DAT_020b90a0 & 0xff) == 0x38) {
            _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,DAT_0075f9b8);
          }
        }
        else {
          *(undefined4 *)(puVar6 + -0x94) = 0;
        }
        if ((&DAT_020b8e9e)[DAT_007cc600] == 'T') {
          if ((((uint)_DAT_020b90a0 & 0xff) == 0x36) && ((&DAT_020b8e9f)[DAT_007cc600] == '1')) {
            _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,DAT_0075f9b4);
          }
          else {
            *(undefined4 *)(puVar6 + -0x8c) = 0;
            DAT_007cc600 = iVar4;
          }
          if ((((uint)_DAT_020b90a0 & 0xff) == 0x32) && ((&DAT_020b8e9e)[DAT_007cc600] == '3')) {
            DAT_007cc600 = DAT_007cc600 + -1;
            _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,DAT_0075f9b0);
          }
          else {
            *(undefined4 *)(puVar6 + -0x88) = 0;
          }
        }
        else {
          *(undefined4 *)(puVar6 + -0x90) = 0;
          DAT_007cc600 = iVar4;
        }
        if (DAT_007d2c70 == 0) {
          *(undefined4 *)(puVar6 + -0x84) = 0;
        }
        else {
          **(int **)(puVar6 + 0xc) = **(int **)(puVar6 + 0xc) + 1;
          DAT_007d2c58 = DAT_007d2c58 + 1;
          (&DAT_020b909f)[**(int **)(puVar6 + 0xc)] = 0x2e;
          DAT_007d2c70 = 0;
        }
        while (DAT_007d2c68 != 0) {
          **(int **)(puVar6 + 0xc) = **(int **)(puVar6 + 0xc) + 1;
          DAT_007d2c58 = DAT_007d2c58 + 1;
          (&DAT_020b909f)[**(int **)(puVar6 + 0xc)] = (&DAT_020b909e)[**(int **)(puVar6 + 0xc)];
          (&DAT_020b909e)[**(int **)(puVar6 + 0xc)] = 0x2e;
          DAT_007d2c68 = DAT_007d2c68 + -1;
          *(undefined4 *)(puVar6 + -0x7c) = 0;
        }
        *(undefined4 *)(puVar6 + -0x80) = 0;
        if (DAT_007d2c6c == 0) {
          *(undefined4 *)(puVar6 + -0x78) = 0;
        }
        else {
          **(int **)(puVar6 + 0xc) = **(int **)(puVar6 + 0xc) + 1;
          DAT_007d2c58 = DAT_007d2c58 + 1;
          DAT_007d2c60 = **(int **)(puVar6 + 0xc);
          iVar4 = (1 - DAT_007d2c60) / -1;
          *(int *)(puVar6 + -0x74) = iVar4;
          while (0 < iVar4) {
            (&DAT_020b909f)[DAT_007d2c60] = (&DAT_020b909e)[DAT_007d2c60];
            DAT_007d2c60 = DAT_007d2c60 + -1;
            *(int *)(puVar6 + -0x74) = *(int *)(puVar6 + -0x74) + -1;
            iVar4 = *(int *)(puVar6 + -0x74);
          }
          _DAT_020b90a1 = (undefined3)((uint)_DAT_020b90a0 >> 8);
          _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,DAT_0075f9b0);
          if (1 < DAT_007d2c6c) {
            if (((uint)_DAT_020b90a0 & 0xffff) == 0x5754) {
              **(int **)(puVar6 + 0xc) = **(int **)(puVar6 + 0xc) + 2;
              DAT_007d2c58 = DAT_007d2c58 + 2;
              FUN_005f33c9(puVar6,0x423a81);
              FUN_005f34d1(puVar6,0x423a9c);
            }
            if (((uint)_DAT_020b90a0 & 0xffff) == 0x4854) {
              **(int **)(puVar6 + 0xc) = **(int **)(puVar6 + 0xc) + 1;
              DAT_007d2c58 = DAT_007d2c58 + 1;
              FUN_005f33c9(puVar6,0x423aee);
              FUN_005f34d1(puVar6,0x423b09);
            }
            if (((uint)_DAT_020b90a0 & 0xffff) == 0x5154) {
              _DAT_020b90a0 = (float)CONCAT22(_DAT_020b90a2,DAT_0075f9a0);
            }
            if (((uint)_DAT_020b90a0 & 0xffff) == 0x4554) {
              _DAT_020b90a0 = (float)CONCAT22(_DAT_020b90a2,DAT_0075f99c);
            }
            if (((uint)_DAT_020b90a0 & 0xffff) == 0x5354) {
              _DAT_020b90a0 = (float)CONCAT22(_DAT_020b90a2,DAT_0075f998);
            }
            if (((uint)_DAT_020b90a0 & 0xffff) == 0x3354) {
              FUN_005f33c9(puVar6,0x423bab);
              FUN_005f34d1(puVar6,0x423bc6);
            }
            if (((uint)_DAT_020b90a0 & 0xffff) == 0x3654) {
              FUN_005f33c9(puVar6,0x423bfa);
              FUN_005f34d1(puVar6,0x423c15);
            }
          }
          DAT_007d2c6c = 0;
        }
        iVar4 = (DAT_007d2c58 - DAT_007cc600) + 1;
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        iVar5 = 1;
        iVar3 = DAT_007cc600;
        for (iVar12 = 1; iVar12 <= iVar4; iVar12 = iVar12 + 1) {
          (&DAT_020b8e9f)[iVar3] = (&DAT_020b909f)[iVar5];
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 1;
        }
        DAT_007cc600 = **(int **)(puVar6 + 0xc) + DAT_007cc600 + -1;
        thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
        if ((&DAT_020b8e9f)[DAT_007cc600] == '/') {
          DAT_00794830 = DAT_00794830 + 1;
          if (*(char *)((int)&DAT_020b8ea0 + DAT_007cc604) == '[') {
            DAT_007cb2c0 = DAT_007cc604;
            DAT_007cb2c8 = (int)(char)(&DAT_020b8e9f)[DAT_007cc604];
          }
          else {
            *(undefined4 *)(puVar6 + -0x6c) = 0;
          }
          if ((&DAT_020b8e9e)[DAT_007cc600] == ']') {
            DAT_007cb2c4 = DAT_007cc600;
            thunk_FUN_0041fab5(*(undefined4 *)(puVar6 + 0xc),&DAT_007d2c54);
            _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,(&DAT_020b8e9f)[DAT_007cc600]);
          }
          else {
            *(undefined4 *)(puVar6 + -0x68) = 0;
          }
        }
        else {
          *(undefined4 *)(puVar6 + -0x70) = 0;
        }
        *(undefined4 *)(puVar6 + -100) = 0;
        if (DAT_01fb8c88 <= DAT_00794830) goto LAB_0042422a;
        do {
          if (DAT_009c48f4 == 0) {
            *(undefined4 *)(puVar6 + -0x5c) = 0;
          }
          else if (((((uint)_DAT_020b90a0 & 0xff) != 0x3b) && (DAT_020b90a0 != '\'')) &&
                  (((uint)_DAT_020b90a0 & 0xff) != 0x2f)) {
            *(undefined4 *)(puVar6 + -0x58) = 0;
            goto LAB_00424277;
          }
          FUN_005f34d1(puVar6,0x423dd9);
          FUN_005f46bc(puVar6,0x423e17);
          FUN_005f34d1(puVar6,0x423e2d);
          if (DAT_01e62c85 == '[') {
            FUN_005f33c9(puVar6,0x423e5e);
          }
          if ((&DAT_020b8e9e)[DAT_007cc600] == ']') {
            *(undefined4 *)(puVar6 + -0x50) = 0xc;
            DAT_007d2c58 = 0xc;
            do {
              if (*(char *)((int)&DAT_01e62c80 + DAT_007d2c58 + 3) == ']') {
                *(char *)((int)&DAT_01e62c80 + DAT_007d2c58 + 3) = (&DAT_01e62c84)[DAT_007d2c58];
                (&DAT_01e62c84)[DAT_007d2c58] = 0x20;
                *(undefined4 *)(puVar6 + -0x48) = 0;
                break;
              }
              *(undefined4 *)(puVar6 + -0x4c) = 0;
              *(undefined4 *)(puVar6 + -0x44) = 0;
              DAT_007d2c58 = DAT_007d2c58 + -1;
              *(int *)(puVar6 + -0x50) = *(int *)(puVar6 + -0x50) + -1;
            } while (0 < *(int *)(puVar6 + -0x50));
          }
          else {
            *(undefined4 *)(puVar6 + -0x54) = 0;
          }
          *(undefined4 *)(puVar6 + -0x40) = 0xc;
          DAT_007d2c58 = 1;
          do {
            if (('`' < *(char *)((int)&DAT_01e62c80 + DAT_007d2c58 + 3)) &&
               (*(char *)((int)&DAT_01e62c80 + DAT_007d2c58 + 3) < '{')) {
              *(char *)((int)&DAT_01e62c80 + DAT_007d2c58 + 3) =
                   *(char *)((int)&DAT_01e62c80 + DAT_007d2c58 + 3) + -0x20;
            }
            DAT_007d2c58 = DAT_007d2c58 + 1;
            *(int *)(puVar6 + -0x40) = *(int *)(puVar6 + -0x40) + -1;
          } while (0 < *(int *)(puVar6 + -0x40));
          DAT_007d2c74 = DAT_007d2c74 + 1;
          *(int *)(DAT_007d2c74 * 4 + 0x7ccacc) = DAT_00794834 + 1;
          (&DAT_007cc874)[DAT_007d2c74] = DAT_00794830;
          (&DAT_007cd684)[DAT_007d2c74] = DAT_007cc600;
          thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007cc600);
          *(undefined1 *)((int)&DAT_020b8ea0 + DAT_007cc600) = 0;
          DAT_0079483c = f_0;
          if (DAT_01e62c84 == '@') {
            FUN_00424a9f();
            if (_DAT_020b90a0 == 3.528607e+09) {
              *(undefined4 *)(puVar6 + -0x38) = 0;
              goto LAB_004242a7;
            }
            if ((&DAT_020b8e9f)[DAT_007cc600] == ';') {
              *(undefined4 *)(puVar6 + -0x34) = 0;
              goto LAB_00424753;
            }
            *(undefined4 *)(puVar6 + -0x30) = 0;
          }
          else {
            *(undefined4 *)(puVar6 + -0x3c) = 0;
            if (((uint)_DAT_020b90a0 & 0xff) == 0x3b) {
              *(undefined4 *)(puVar6 + -0x2c) = 0;
              goto LAB_00424753;
            }
            if (DAT_01e62c84 == 'X') {
              push_words(&DAT_0075f988,&DAT_020b8ea0);
              DAT_0079483c = f_0;
              FUN_00425722(&DAT_007cc600);
              pop_words(&DAT_0075f988,&DAT_020b8ea0);
              if (DAT_0079483c == f_99) {
                *(undefined4 *)(puVar6 + -0x24) = 0;
                goto LAB_004242a7;
              }
              *(undefined4 *)(puVar6 + -0x20) = 0;
            }
            else {
              *(undefined4 *)(puVar6 + -0x28) = 0;
              push_words(&DAT_0075f988,&DAT_020b8ea0);
              thunk_FUN_004c4148(&DAT_007cc600);
              pop_words(&DAT_0075f988,&DAT_020b8ea0);
              if (_DAT_020b90a0 == 1.5113662e-13) {
                FUN_005f46bc(puVar6,0x4240ce);
                FUN_005f34d1(puVar6,0x4240e4);
                DAT_007cc600 = DAT_007cc604 + -1;
                if (0 < DAT_007d2c74) {
                  DAT_007d2c74 = DAT_007d2c74 + -1;
                }
                DAT_007d2c58 = DAT_007cc600;
                if (DAT_007cc600 == 0) {
                  DAT_007d2c58 = 1;
                }
                thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007d2c58);
                *(undefined4 *)(puVar6 + -0x18) = 0;
                goto LAB_00422e2a;
              }
              *(undefined4 *)(puVar6 + -0x1c) = 0;
            }
          }
          DAT_007cc604 = DAT_007cc600 + 1;
          if (DAT_00794830 < DAT_01fb8c88) goto LAB_0042426a;
          *(undefined4 *)(puVar6 + -0x14) = 0;
LAB_0042422a:
          cVar1 = (&DAT_020b8e9f)[DAT_007cc600];
          _DAT_020b90a0 = (float)CONCAT31(_DAT_020b90a1,cVar1);
          if ((cVar1 == '/') || (cVar1 == ';')) {
            (&DAT_020b8e9f)[DAT_007cc600] = 0x3b;
            DAT_007cc600 = DAT_007cc600 + 1;
            *(undefined4 *)(puVar6 + -0x60) = 0;
            goto LAB_00424745;
          }
        } while( true );
      }
      DAT_009c6ae0 = 2;
      *(undefined4 *)(puVar6 + -0x134) = 0;
    }
    puVar9 = (undefined4 *)&DAT_020b8ea0;
    puVar13 = &DAT_009ae2bc;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    _DAT_007d2c64 = thunk_FUN_0052fef6();
    puVar9 = &DAT_009ae2bc;
    puVar13 = (undefined4 *)&DAT_020b8ea0;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar13 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    }
    *(undefined4 *)(puVar6 + -0x138) = 0;
  } while( true );
LAB_0042426a:
  if (DAT_01fb9630 == 0) {
    *(undefined4 *)(puVar6 + -0x10) = 0;
    goto LAB_00424753;
  }
LAB_00424277:
  if (DAT_009c48f4 == 0xd) {
LAB_00424745:
    **(int **)(puVar6 + 0xc) = DAT_007cc600 + -1;
    goto LAB_00424753;
  }
  *(undefined4 *)(puVar6 + -0xc) = 0;
  goto LAB_00422e2a;
}


