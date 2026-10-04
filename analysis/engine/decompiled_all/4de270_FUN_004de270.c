// FUN_004de270 @ 004de270 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x004df3a0) */
/* WARNING: Removing unreachable block (ram,0x004df400) */
/* WARNING: Removing unreachable block (ram,0x004df460) */
/* WARNING: Removing unreachable block (ram,0x004df4c0) */
/* WARNING: Removing unreachable block (ram,0x004df520) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004de270(void)

{
  undefined1 *puVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  float10 fVar13;
  
  puVar9 = &stack0xfffffffc;
LAB_004de27c:
  do {
    *(undefined4 *)(puVar9 + -0x2f0) = 0;
    *(undefined4 *)(puVar9 + -0x2f4) = 1;
    while (*(int *)(puVar9 + -0x2f4) < 0xd) {
      (&DAT_01cade58)[*(int *)(puVar9 + -0x2f0)] = 0x20;
      *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
      *(int *)(puVar9 + -0x2f4) = *(int *)(puVar9 + -0x2f4) + 1;
    }
    *(undefined4 *)(puVar9 + -0x2f0) = 0xfffffff9;
    for (iVar6 = 1; iVar6 < 0x10; iVar6 = iVar6 + 1) {
      *(int *)(puVar9 + -0x2f8) = *(int *)(puVar9 + -0x2f0) * 0xc;
      iVar8 = 0;
      for (iVar11 = 1; iVar11 < 0xd; iVar11 = iVar11 + 1) {
        *(int *)(puVar9 + -0x2fc) = *(int *)(puVar9 + -0x2f8) + iVar8;
        (&DAT_01aad694)[*(int *)(puVar9 + -0x2fc)] = 0x20;
        iVar8 = iVar8 + 1;
      }
      *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
    }
    DAT_008a0704 = 0;
    _DAT_008a0700 = 0;
    _DAT_008a06fc = 0;
    FUN_005f34d1(puVar9,0x4de37e);
    DAT_009a9494 = 0;
    FUN_005f34d1(puVar9,0x4de3a7);
    DAT_0078d938 = 0;
    DAT_0079484c = 0;
    thunk_FUN_0041ef66(&DAT_008a0704);
    DAT_00794830 = 0;
    if (DAT_00794850 == f_0) {
      DAT_00794850 = f_5;
    }
    if ((DAT_0079484c != 0) && (DAT_01fbb700 == 1)) {
      puVar10 = (undefined4 *)&DAT_020b8ea0;
      puVar12 = (undefined4 *)&DAT_020b90a0;
      for (iVar6 = 0x80; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      DAT_0078d938 = 4;
    }
    if (DAT_01fbb700 == 1) {
      DAT_008a06f8 = 0;
      DAT_01ade7e8 = 0;
      fVar13 = (float10)FUN_00604db0(&f_0);
      _DAT_008a06f4 = (float)fVar13;
      DAT_01ade7d4 = 1;
      fVar13 = (float10)FUN_00604db0(&f_0);
      _DAT_008a06f4 = (float)fVar13;
      FUN_004e1c96();
      thunk_FUN_0054c5f8(&DAT_0078cbc0,1,&DAT_01aad640,1,&DAT_00765db8);
      FUN_004e19fa();
      FUN_005f34d1(puVar9,0x4de4cd);
      thunk_FUN_0054c419(&DAT_01aad820,&DAT_00765db4);
      DAT_01ade7f0 = 0;
      DAT_01b12c9c = 1;
      DAT_00794840 = 0;
      thunk_FUN_00468df8(&DAT_00765db0);
      DAT_008a06f0 = 0;
      DAT_0078dec4 = -1;
      DAT_01ade7dc = 0;
      DAT_0078dec8 = 0;
    }
    else {
      thunk_FUN_00468df8(&DAT_00765dac);
    }
    _DAT_0078d93c = 0x1e;
    DAT_009a9490 = 1;
    DAT_00794840 = 0;
    thunk_FUN_0054946a(&DAT_00765d90,0x19);
    _DAT_008a06ec = f_9999;
LAB_004de583:
    *(undefined4 *)(puVar9 + -0x2cc) = 0;
    if (DAT_01fbb700 == 2) {
      DAT_009a9494 = 9999;
    }
    DAT_008a0704 = thunk_FUN_00597550(&IP1);
    iVar6 = DAT_009a9494;
    if (DAT_008a0704 == 0) {
      *(undefined4 *)(puVar9 + -0x2c8) = 0;
      return;
    }
    if ((DAT_009a9494 == 0) || (DAT_009a9494 == 9999)) {
      *(undefined4 *)(puVar9 + -0x2c4) = 0;
      DAT_0078d934 = IP1;
      _DAT_008a06e4 = IP1 & 0xff;
      DAT_01ade7c0 = IP2 & 0xff;
      if (DAT_01ade7c0 != 0x90) break;
      uVar7 = (uint)IP2 >> 8 & 0xff;
      DAT_01ade7e4 = (uint)IP2 >> 0x10;
      DAT_01ade7e0 = uVar7;
      if ((DAT_01fbb7e0 == uVar7) && (DAT_01fbb7e4 == DAT_01ade7e4)) {
        *(undefined4 *)(puVar9 + -0x274) = 0;
        goto LAB_004de583;
      }
      if ((DAT_01fbb700 == 2) && (DAT_01ade7e4 == 0)) {
        *(undefined4 *)(puVar9 + -0x270) = 0;
        goto LAB_004de583;
      }
      if (DAT_0078b4a8 == 0x18) {
        DAT_01ade7e0 = uVar7 + 0xc;
      }
      if (DAT_0078b4a8 == 0x30) {
        DAT_01ade7e0 = DAT_01ade7e0 - 0xc;
      }
      *(undefined4 *)(puVar9 + -0x26c) = 0;
      DAT_01fbb7e0 = uVar7;
      DAT_01fbb7e4 = DAT_01ade7e4;
      if ((int)DAT_01ade7e0 < 0x30) {
        (&DAT_01aad7f0)[DAT_01ade7e0] = 0;
        if ((DAT_01ade7e4 != 0) && (DAT_01ade7e0 != 0)) {
          DAT_01ade7ec = 1;
          switch(DAT_01ade7e0) {
          default:
            *(undefined4 *)(puVar9 + -0x254) = 0;
            goto LAB_004df662;
          case 0x25:
            *(undefined4 *)(puVar9 + -0x250) = 0;
            break;
          case 0x26:
            if (DAT_008a06f8 == 0) goto DAT_004dec87;
            *(undefined4 *)(puVar9 + -0x24c) = 0;
            goto LAB_004df354;
          case 0x27:
DAT_004dec87:
            *(undefined4 *)(puVar9 + -0x248) = 0;
            break;
          case 0x28:
            if (DAT_008a06f8 != 0) {
              *(undefined4 *)(puVar9 + -0x244) = 0;
              goto LAB_004df354;
            }
            *(undefined4 *)(puVar9 + -0x240) = 0;
            goto DAT_004df7e4;
          case 0x29:
            if (DAT_008a06f8 != 0) {
              *(undefined4 *)(puVar9 + -0x23c) = 0;
              goto LAB_004df354;
            }
            *(undefined4 *)(puVar9 + -0x238) = 0;
            break;
          case 0x2a:
            *(undefined4 *)(puVar9 + -0x234) = 0;
            break;
          case 0x2b:
            if (DAT_008a06f8 != 0) {
              *(undefined4 *)(puVar9 + -0x230) = 0;
              goto LAB_004df354;
            }
            *(undefined4 *)(puVar9 + -0x22c) = 0;
            break;
          case 0x2c:
            *(undefined4 *)(puVar9 + -0x228) = 0;
            goto code_r0x004df8df;
          case 0x2d:
            if (DAT_008a06f8 != 0) {
              *(undefined4 *)(puVar9 + -0x224) = 0;
              goto LAB_004df354;
            }
            *(undefined4 *)(puVar9 + -0x220) = 0;
            goto code_r0x004df926;
          case 0x2e:
            *(undefined4 *)(puVar9 + -0x21c) = 0;
            goto code_r0x004df94a;
          case 0x2f:
            DAT_008a06f8 = DAT_008a06f8 + 1;
            DAT_01ade7e0 = 0;
            DAT_01ade7e4 = 0;
            *(undefined4 *)(puVar9 + -0x218) = 0;
            goto LAB_004de583;
          }
LAB_004dedfd:
          if (((int)DAT_01ade7e0 < 0x79) && (0x23 < (int)DAT_01ade7e0)) {
            if ((DAT_01ade7f0 == 1) && (DAT_01ade7e0 == 0x27)) {
              thunk_FUN_0054946a("**** Type Notes, etc. ****",0x1b);
              puVar1 = &DAT_020b90a0 + DAT_0078d938;
              DAT_0078d938 = DAT_0078d938 + 1;
              *puVar1 = 0x2f;
              *(undefined4 *)(puVar9 + -0x200) = 0;
              goto LAB_004e18ae;
            }
            if ((DAT_01ade7e4 == 0) || ((int)DAT_01ade7c0 < 0x90)) {
              (&DAT_01aad7f0)[DAT_01ade7e0] = 0;
              DAT_01ade7d4 = 1;
              *(undefined4 *)(puVar9 + -0x1f8) = 0;
              *(undefined4 *)(puVar9 + -500) = 0x6d;
              DAT_008a06dc = 0xc;
              do {
                if ((&DAT_01aad7f0)[DAT_008a06dc] != 0) {
                  DAT_01ade7d4 = 0;
                  *(undefined4 *)(puVar9 + -0x1ec) = 0;
                  goto LAB_004de583;
                }
                *(undefined4 *)(puVar9 + -0x1f0) = 0;
                *(undefined4 *)(puVar9 + -0x1e8) = 0;
                DAT_008a06dc = DAT_008a06dc + 1;
                *(int *)(puVar9 + -500) = *(int *)(puVar9 + -500) + -1;
              } while (0 < *(int *)(puVar9 + -500));
              *(undefined4 *)(puVar9 + -0x1e4) = 0;
              goto LAB_004de583;
            }
            *(undefined4 *)(puVar9 + -0x1fc) = 0;
            (&DAT_01aad7f0)[DAT_01ade7e0] = 1;
            DAT_01ade7ec = 1;
            if (DAT_008a06d8 == -1) {
              thunk_FUN_0054c473(&DAT_020b90a0,1);
              DAT_0078b388 = 1;
              DAT_008a06d8 = 1;
              goto LAB_004e043d;
            }
            *(undefined4 *)(puVar9 + -0x1e0) = 0;
            if (DAT_0078d934 != -0x100) {
              if (DAT_008a06f8 == 2) {
                DAT_008a06f8 = 0;
                if ((int)DAT_01ade7e0 < 0x30) {
                  *(undefined4 *)(puVar9 + -0x150) = 0;
                  if ((DAT_008a06d0 != 99) || (DAT_0078d934 < 0xc)) {
LAB_004df354:
                    DAT_008a06f8 = 0;
                    /* WARNING (jumptable): Ignoring partial resolution of indirect */
                    /* WARNING: Ignoring partial resolution of indirect */
                    DAT_01e62c84 = 0x2f;
                    DAT_01ade7ec = 2;
                    if (DAT_01ade7e0 == 0x2d) {
                      FUN_005f46bc(puVar9,0x4df3c4);
                      FUN_005f34d1(puVar9,0x4df3da);
                    }
                    if (DAT_01ade7e0 == 0x2b) {
                      FUN_005f46bc(puVar9,0x4df424);
                      FUN_005f34d1(puVar9,0x4df43a);
                    }
                    if (DAT_01ade7e0 == 0x29) {
                      FUN_005f46bc(puVar9,0x4df484);
                      FUN_005f34d1(puVar9,0x4df49a);
                    }
                    if (DAT_01ade7e0 == 0x28) {
                      FUN_005f46bc(puVar9,0x4df4e4);
                      FUN_005f34d1(puVar9,0x4df4fa);
                    }
                    if (DAT_01ade7e0 == 0x26) {
                      FUN_005f46bc(puVar9,0x4df544);
                      FUN_005f34d1(puVar9,0x4df55a);
                    }
                    DAT_01ade7ec = DAT_01ade7ec + 1;
                    *(undefined4 *)(puVar9 + -0x128) = 0;
                    goto LAB_004e0a19;
                  }
                  *(undefined4 *)(puVar9 + -300) = 0;
                }
                else {
                  *(undefined4 *)(puVar9 + -0x154) = 0;
                }
                goto LAB_004deefb;
              }
              if (DAT_01ade7e8 == 1) {
                *(undefined4 *)(puVar9 + -0x14c) = 0;
                goto LAB_004e0216;
              }
              if (DAT_008a06f8 != 0) {
                DAT_008a06f8 = 0;
                *(undefined4 *)(puVar9 + -0x144) = 0;
                goto LAB_004e01ff;
              }
              *(undefined4 *)(puVar9 + -0x148) = 0;
              if (((int)DAT_01ade7e0 < 0x24) || (0x2f < (int)DAT_01ade7e0)) {
                *(undefined4 *)(puVar9 + -0xb8) = 0;
                DAT_008a06d8 = DAT_0078d938 + 1;
                if (DAT_008a06d8 < 2) {
                  *(undefined4 *)(puVar9 + -0x80) = 0;
                }
                else {
                  if ((f_2 < _DAT_008a06c0) && ((&DAT_020b909f)[DAT_0078d938] == ':')) {
                    (&DAT_020b909f)[DAT_0078d938] = 0x2f;
                  }
                  cVar2 = (&DAT_020b909e)[DAT_008a06d8];
                  if ((((cVar2 == '[') || (cVar2 == ',')) || (cVar2 == ':')) || (cVar2 == '/')) {
                    *(undefined4 *)(puVar9 + -0x7c) = 0;
                  }
                  else {
                    cVar2 = DAT_00765c90;
                    if (DAT_01ade7d4 == 0) {
                      cVar2 = DAT_00765c88;
                    }
                    _DAT_01e62c84 = CONCAT31(_DAT_01e62c85,cVar2);
                    DAT_01ade7ec = 2;
                  }
                }
                DAT_01ade7d4 = 0;
                DAT_01ade7f8 = (int)DAT_01ade7e0 % 0xc;
                DAT_01ade7dc = (int)DAT_01ade7e0 / 0xc - DAT_01b12c9c;
                if (DAT_01ade7f0 < 6) {
                  DAT_01ade7f4 = (int)(char)(&DAT_01cade64)[DAT_01ade7f8];
                  DAT_01ade7c7 = (&DAT_01cade58)[DAT_01ade7f8];
                }
                else {
                  DAT_01ade7f4 = 0;
                  iVar6 = DAT_01ade7f8;
                  if (4 < DAT_01ade7f8) {
                    iVar6 = DAT_01ade7f8 + 1;
                  }
                  DAT_008a06bc = iVar6 / 2 + 1;
                  puVar9[-0x2f5] = (char)DAT_008a06bc + 'B';
                  DAT_01ade7c7 = puVar9[-0x2f5];
                  if (5 < DAT_008a06bc) {
                    puVar9[-0x2f5] = (char)DAT_008a06bc + ';';
                    DAT_01ade7c7 = puVar9[-0x2f5];
                  }
                }
                DAT_01ade7cc = DAT_01ade7c7 - 0x42;
                if (DAT_01ade7cc < 1) {
                  DAT_01ade7cc = DAT_01ade7c7 - 0x3b;
                }
                if ((DAT_01ade7cc == 7) && (DAT_01ade7f4 == 2)) {
                  DAT_01ade7dc = DAT_01ade7dc + -1;
                }
                if ((DAT_01ade7cc == 1) && (DAT_01ade7f4 == 1)) {
                  DAT_01ade7dc = DAT_01ade7dc + 1;
                }
                DAT_01ade7d0 = *(int *)(&DAT_01cadd20 + DAT_01ade7dc * 0x1c + DAT_01ade7cc * 4);
                DAT_00794848 = DAT_01ade7f0;
                if (DAT_01ade7f0 == 0) {
                  DAT_00794848 = DAT_01ade7f4;
                  *(undefined4 *)(puVar9 + -0x78) = 0;
                  if ((DAT_01ade7f4 != 0) && (DAT_01ade7f4 != 3)) {
                    *(undefined4 *)(puVar9 + -0x58) = 0;
                    goto LAB_004dfd89;
                  }
                  if (DAT_01ade7d0 != 0) {
                    DAT_01ade7f0 = 3;
                    *(undefined4 *)(&DAT_01cadd20 + DAT_01ade7cc * 4 + DAT_01ade7dc * 0x1c) = 0;
                    *(undefined4 *)(puVar9 + -0x50) = 0;
                    goto LAB_004dfef0;
                  }
                  *(undefined4 *)(puVar9 + -0x54) = 0;
                }
                else if (DAT_01ade7f0 == DAT_01ade7f4) {
                  *(undefined4 *)(puVar9 + -0x74) = 0;
LAB_004dfd89:
                  if (DAT_01ade7f4 ==
                      *(int *)(&DAT_01cadd20 + DAT_01ade7cc * 4 + DAT_01ade7dc * 0x1c)) {
                    *(undefined4 *)(puVar9 + -0x4c) = 0;
                    goto LAB_004dfffb;
                  }
                  DAT_01ade7f0 = DAT_01ade7f4;
LAB_004dfef0:
                  DAT_008a06b8 = DAT_01ade7f0;
                  if (DAT_01ade7f0 == 3) {
                    DAT_008a06b8 = 0;
                  }
                  *(int *)(&DAT_01cadd20 + DAT_01ade7dc * 0x1c + DAT_01ade7cc * 4) = DAT_008a06b8;
                }
                else {
                  switch(DAT_01ade7f0) {
                  case 1:
                    switch(DAT_01ade7f8) {
                    case 0:
                    case 2:
                    case 5:
                    case 7:
                    case 9:
                      break;
                    case 1:
                    case 3:
                    case 6:
                    case 8:
                    case 10:
                      goto code_r0x004dfd82;
                    case 4:
                    case 0xb:
                      goto LAB_004dfdd8;
                    default:
                      goto code_r0x004dfd6e;
                    }
                  case 2:
code_r0x004dfd6e:
                    switch(DAT_01ade7f8) {
                    case 0:
                    case 5:
                      goto DAT_004dfe28;
                    default:
                      goto code_r0x004dfd82;
                    case 2:
                    case 4:
                    case 7:
                    case 9:
                    case 0xb:
                      break;
                    }
                  case 3:
code_r0x004dfd82:
                    switch(DAT_01ade7f4) {
                    case 0:
                      goto LAB_004dfef0;
                    case 1:
                    case 4:
                      goto DAT_004dfe28;
                    case 2:
                    case 5:
                      goto LAB_004dfdd8;
                    case 3:
                      goto LAB_004dfd89;
                    default:
                      goto code_r0x004dfdd1;
                    }
                  case 4:
code_r0x004dfdd1:
                    switch(DAT_01ade7f8) {
                    case 0:
                    case 2:
                    case 5:
                    case 7:
                    case 9:
LAB_004dfdd8:
                      DAT_01ade7c7 = DAT_01ade7c7 + 1;
                      if ('G' < (char)DAT_01ade7c7) {
                        DAT_01ade7c7 = 0x41;
                      }
                      if (DAT_01ade7c7 == 0x43) {
                        DAT_01ade7dc = DAT_01ade7dc + 1;
                      }
                      goto LAB_004dfe6b;
                    case 1:
                    case 3:
                    case 4:
                    case 6:
                    case 8:
                    case 10:
                    case 0xb:
                      break;
                    default:
                      goto code_r0x004dfe21;
                    }
                  case 5:
code_r0x004dfe21:
                    switch(DAT_01ade7f8) {
                    case 0:
                    case 1:
                    case 3:
                    case 5:
                    case 6:
                    case 8:
                    case 10:
                      break;
                    default:
                      goto DAT_004dfe28;
                    }
                  }
                  DAT_01ade7f0 = 0;
                  if ((DAT_01ade7f8 == 5) && (DAT_01ade7cc == 3)) {
LAB_004dff72:
                    DAT_01ade7c7 = DAT_01ade7c7 + 1;
                    *(undefined4 *)(puVar9 + -0x70) = 0;
LAB_004dffdb:
                    DAT_01aad7b0 = 0;
                    _DAT_01aad7ac = DAT_01ade7f8;
                    FUN_004e1970();
                  }
                  else {
                    if ((DAT_01ade7f8 == 0) && (DAT_01ade7cc == 7)) {
                      DAT_01ade7dc = DAT_01ade7dc + 1;
                      *(undefined4 *)(puVar9 + -0x6c) = 0;
                      goto LAB_004dff72;
                    }
                    if ((DAT_01ade7f8 == 0xb) && (DAT_01ade7cc == 1)) {
                      DAT_01ade7dc = DAT_01ade7dc + -1;
                      *(undefined4 *)(puVar9 + -0x68) = 0;
LAB_004dffc9:
                      DAT_01ade7c7 = DAT_01ade7c7 - 1;
                      goto LAB_004dffdb;
                    }
                    if ((DAT_01ade7f8 == 4) && (DAT_01ade7cc == 4)) goto LAB_004dffc9;
                  }
                  *(undefined4 *)(puVar9 + -100) = 0;
                }
LAB_004dfffb:
                if (DAT_0078dec4 < 0) {
                  *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x50;
                  DAT_0078dec4 = 0;
                  DAT_01ade7ec = DAT_01ade7ec + 1;
                }
                else {
                  *(undefined4 *)(puVar9 + -0x48) = 0;
                }
                *(byte *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = DAT_01ade7c7;
                if (DAT_01ade7f0 == 0) {
                  *(undefined4 *)(puVar9 + -0x44) = 0;
                  DAT_01ade7ec = DAT_01ade7ec + 1;
                }
                else {
                  DAT_008a06b4 = DAT_01ade7f0;
                  if (3 < DAT_01ade7f0) {
                    DAT_008a06b4 = DAT_01ade7f0 + -3;
                  }
                  puVar1 = &DAT_01e62c84 + DAT_01ade7ec;
                  DAT_01ade7ec = DAT_01ade7ec + 1;
                  *puVar1 = (&DAT_007947d7)[DAT_008a06b4];
                  if (DAT_01ade7f0 == DAT_008a06b4) {
                    *(undefined4 *)(puVar9 + -0x40) = 0;
                    DAT_01ade7ec = DAT_01ade7ec + 1;
                  }
                  else {
                    puVar1 = &DAT_01e62c84 + DAT_01ade7ec;
                    DAT_01ade7ec = DAT_01ade7ec + 1;
                    *puVar1 = (&DAT_007947d7)[DAT_008a06b4];
                    DAT_01ade7ec = DAT_01ade7ec + 1;
                  }
                }
                *(undefined4 *)(puVar9 + -0x3c) = 0;
                if (DAT_008a06f0 != DAT_01ade7dc) {
                  puVar9[-0x2f5] = (char)DAT_01ade7dc + '0';
                  *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = puVar9[-0x2f5];
                }
                DAT_008a06f0 = DAT_01ade7dc;
                DAT_01ade7f0 = 0;
                DAT_008a06c4 = (char)DAT_01ade7c7 + -0x43;
                if (DAT_008a06c4 < 0) {
                  DAT_008a06c4 = (char)DAT_01ade7c7 + -0x3c;
                }
                DAT_008a06c4 = DAT_01ade7dc * 7 + DAT_008a06c4;
                iVar6 = DAT_0078dec8 - DAT_008a06c4;
                if (iVar6 < 0) {
                  iVar6 = -iVar6;
                }
                if (iVar6 < 4) {
                  DAT_01ade7ec = DAT_01ade7ec + -1;
                }
                else {
                  puVar9[-0x2f5] = (char)DAT_01ade7dc + '0';
                  *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = puVar9[-0x2f5];
                }
                DAT_0078dec8 = DAT_008a06c4;
                goto LAB_004e0a19;
              }
              switch(DAT_01ade7e0) {
              case 0x24:
LAB_004df662:
                DAT_01ade7ec = 1;
                _DAT_01e62c84 = CONCAT11(0x4d,DAT_01e62c84);
                FUN_004e19fa();
                DAT_01ade7e4 = 0;
                DAT_01ade7ec = 2;
                DAT_008a06c4 = DAT_01ade7f0 / 3;
                if (DAT_01ade7f0 == 0) {
                  *(undefined4 *)(puVar9 + -0xa8) = 0;
                }
                else {
                  iVar6 = DAT_01ade7f0 % 3;
                  if (iVar6 == 0) {
                    *(undefined4 *)(puVar9 + -0xa4) = 0;
                  }
                  else {
                    _DAT_01e62c84 = CONCAT12(DAT_00765ca8,_DAT_01e62c84);
                    if (iVar6 == 2) {
                      _DAT_01e62c84 = CONCAT13(0x48,_DAT_01e62c84);
                    }
                    DAT_01ade7ec = iVar6 + 2;
                  }
                  if (DAT_008a06c4 != 0) {
                    DAT_01ade7f8 = DAT_008a06c4 / 10;
                    if (DAT_01ade7f8 != 0) {
                      puVar9[-0x2f5] = (char)DAT_01ade7f8 + '0';
                      puVar1 = &DAT_01e62c84 + DAT_01ade7ec;
                      DAT_01ade7ec = DAT_01ade7ec + 1;
                      *puVar1 = puVar9[-0x2f5];
                    }
                    puVar9[-0x2f5] = (char)(DAT_008a06c4 % 10) + '0';
                    puVar1 = &DAT_01e62c84 + DAT_01ade7ec;
                    DAT_01ade7ec = DAT_01ade7ec + 1;
                    *puVar1 = puVar9[-0x2f5];
                  }
                }
                puVar1 = &DAT_01e62c84 + DAT_01ade7ec;
                DAT_01ade7ec = DAT_01ade7ec + 1;
                *puVar1 = 0x20;
                DAT_008a0704 = 4;
                goto LAB_004df99f;
              default:
                DAT_01ade7f0 = DAT_01ade7f0 + 1;
                if (DAT_01ade7f0 == 2) {
                  DAT_01ade7f0 = 4;
                }
                *(undefined4 *)(puVar9 + -0xb4) = 0;
                goto LAB_004de583;
              case 0x26:
                DAT_01ade7f0 = DAT_01ade7f0 + 3;
                *(undefined4 *)(puVar9 + -0xb0) = 0;
                goto LAB_004de583;
              case 0x27:
                DAT_01ade7f0 = DAT_01ade7f0 + 2;
                if (DAT_01ade7f0 == 4) {
                  DAT_01ade7f0 = 5;
                }
                *(undefined4 *)(puVar9 + -0xac) = 0;
                goto LAB_004de583;
              case 0x28:
DAT_004df7e4:
                DAT_01ade7ec = 2;
                DAT_01ade7e4 = 0;
                DAT_00794838 = 0x28;
                goto code_r0x004df834;
              case 0x29:
                _DAT_01e62c86 = CONCAT11(DAT_01e62c87,UNK_00765ca4);
                DAT_00794838 = 0x29;
                DAT_01ade7ec = 3;
                *(undefined4 *)(puVar9 + -0x90) = 0;
code_r0x004df834:
                _DAT_01e62c84 = CONCAT22(_DAT_01e62c86,0x5200);
                DAT_008a0704 = 3;
                if (DAT_01ade7f0 != 0) {
                  *(undefined4 *)(puVar9 + -0x9c) = 0;
                  _DAT_01e62c84 = CONCAT12(UNK_00765ca0,0x5200);
                  *(undefined4 *)(puVar9 + -0x94) = 0;
                  goto code_r0x004df97a;
                }
                if (DAT_00794840 != 0) {
                  iVar6 = DAT_01ade7ec + 1;
                  if (DAT_00794840 == 1) {
                    puVar1 = &DAT_01e62c84 + DAT_01ade7ec;
                    DAT_01ade7ec = DAT_01ade7ec + 1;
                    *puVar1 = 0x55;
                    iVar6 = DAT_01ade7ec;
                  }
                  DAT_01ade7ec = iVar6;
                  if (DAT_00794840 == 2) {
                    *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x44;
                  }
                }
                *(undefined4 *)(puVar9 + -0x98) = 0;
                goto LAB_004df99f;
              case 0x2a:
                goto LAB_004e0fff;
              case 0x2b:
                goto LAB_004e187c;
              case 0x2c:
code_r0x004df8df:
                uVar3 = DAT_00765ca8;
                if (DAT_00794840 == -1) {
                  DAT_00794830 = DAT_00794830 + -1;
                  uVar3 = UNK_00765c9c;
                }
                _DAT_01e62c86 = CONCAT11(DAT_01e62c87,uVar3);
                DAT_00794840 = -1;
                break;
              case 0x2d:
code_r0x004df926:
                _DAT_01e62c86 = CONCAT11(DAT_01e62c87,UNK_00765c98);
                DAT_00794840 = 0;
                *(undefined4 *)(puVar9 + -0x88) = 0;
                break;
              case 0x2e:
code_r0x004df94a:
                _DAT_01e62c86 = CONCAT11(DAT_01e62c87,UNK_00765c94);
                DAT_00794840 = 1;
                *(undefined4 *)(puVar9 + -0x84) = 0;
                break;
              case 0x2f:
                if (DAT_01b12c9c != 99) {
                  iRam008a06cc = DAT_01b12c9c;
                }
                DAT_01b12c9c = 99;
                *(undefined4 *)(puVar9 + -0xbc) = 0;
                goto LAB_004de583;
              }
              _DAT_01e62c84 = CONCAT22(_DAT_01e62c86,0x5300);
code_r0x004df97a:
              DAT_01ade7ec = 3;
              DAT_01ade7e0 = 0;
              DAT_01ade7e4 = 0;
              *(undefined4 *)(puVar9 + -0x8c) = 0;
LAB_004df99f:
              _DAT_01e62c84 = CONCAT31(_DAT_01e62c85,DAT_00765c90);
              DAT_01ade7f0 = 0;
              *(undefined4 *)(puVar9 + -0xa0) = 0;
              goto LAB_004e0a19;
            }
            *(undefined4 *)(puVar9 + -0x158) = 0;
          }
          else {
            *(undefined4 *)(puVar9 + -0x204) = 0;
          }
          goto LAB_004de583;
        }
        *(undefined4 *)(puVar9 + -600) = 0;
        goto LAB_004de583;
      }
      *(undefined4 *)(puVar9 + -0x214) = 0;
      if (DAT_01fbb700 != 2) {
        if (DAT_008a06f8 != 1) {
          if (DAT_008a06f8 != 2) goto LAB_004dedfd;
          *(undefined4 *)(puVar9 + -0x208) = 0;
LAB_004e01ff:
          if (DAT_01ade7e8 == 0) {
            FUN_005f33c9(puVar9,0x4e035b);
            FUN_005f34d1(puVar9,0x4e0376);
            if ((int)DAT_01ade7e0 < 0x3c) {
              DAT_01ade7e0 = 0x41;
            }
            DAT_020b8eb0._2_2_ = *(undefined2 *)(&DAT_00794764 + DAT_01ade7e0 * 2);
            _DAT_01e62c84 = CONCAT21(DAT_020b8eb0._2_2_,DAT_00765c90);
            DAT_01ade7e8 = 1;
            thunk_FUN_0054da52(&DAT_020b8ea0,1);
            thunk_FUN_0054da52(&DAT_020b8ea0,1);
            thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
            *(undefined4 *)(puVar9 + -200) = 0;
          }
          else {
            *(undefined4 *)(puVar9 + -0xcc) = 0;
LAB_004e0216:
            uVar5 = DAT_01e62c88;
            if ((DAT_01ade7e4 != 0) && (DAT_0078d934 != -0x100)) {
              DAT_01ade7ec = 5;
              DAT_01ade7e8 = 0;
              DAT_008a06f8 = 0;
              cVar2 = DAT_00765c84;
              if (DAT_01ade7e0 == 0x3c) {
                cVar2 = DAT_00765c80;
              }
              if (DAT_01ade7e0 == 0x3e) {
                cVar2 = DAT_00765c7c;
              }
              if (DAT_01ade7e0 == 0x41) {
                cVar2 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x3c];
              }
              DAT_01e62c88 = CONCAT31(DAT_01e62c88._1_3_,cVar2);
              if (DAT_01ade7e0 == 0x43) {
                DAT_01e62c88._2_2_ = SUB42(uVar5,2);
                DAT_01e62c88 = CONCAT22(DAT_01e62c88._2_2_,DAT_00765c78);
              }
              if (DAT_01ade7e0 == 0x45) {
                DAT_01e62c88 = CONCAT22(DAT_01e62c88._2_2_,DAT_00765c74);
              }
              if (DAT_01ade7e0 == 0x47) {
                DAT_01e62c88 = CONCAT22(DAT_01e62c88._2_2_,DAT_00765c70);
              }
              if (0x41 < (int)DAT_01ade7e0) {
                DAT_01ade7ec = 6;
              }
              thunk_FUN_0054946a(&DAT_00765c6c,1);
              *(undefined4 *)(puVar9 + -0xc0) = 0;
              goto LAB_004e0a19;
            }
            *(undefined4 *)(puVar9 + -0xc4) = 0;
          }
          goto LAB_004de583;
        }
        *(undefined4 *)(puVar9 + -0x20c) = 0;
LAB_004deefb:
        DAT_0078d934 = (int)DAT_01ade7e0 % 0xc + 1;
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x2f;
        puVar1 = &DAT_01e62c84 + DAT_01ade7ec;
        DAT_01ade7ec = DAT_01ade7ec + 1;
        *puVar1 = 0x4b;
        DAT_01ade7e4 = 0;
        if (DAT_008a06f8 == 6) {
          DAT_008a06f8 = 0;
          if (DAT_0078d934 == 7) {
            DAT_008a06c8 = 6;
            *(undefined4 *)(puVar9 + -0x124) = 0;
          }
          else {
            DAT_008a06c8 = 7;
            if (DAT_0078d934 != 0xc) {
              *(undefined4 *)(puVar9 + -0x11c) = 0;
              goto LAB_004df1bc;
            }
            *(undefined4 *)(puVar9 + -0x120) = 0;
          }
          goto LAB_004df192;
        }
        if (DAT_01ade7e0 == 0x60) {
          DAT_01b12c90 = 0;
          DAT_008a06f8 = 0;
          _DAT_01e62c84 = DAT_008a071c;
          DAT_01e62c88._0_1_ = (char)DAT_008a0720;
          DAT_01e62c88._1_1_ = DAT_008a0720._1_1_;
          DAT_01e62c88._2_1_ = DAT_008a0720._2_1_;
          DAT_01e62c88._3_1_ = DAT_008a0720._3_1_;
          DAT_01e62c8c._0_1_ = (char)DAT_008a0724;
          DAT_01e62c8c._1_1_ = DAT_008a0724._1_1_;
          DAT_01e62c8c._2_1_ = DAT_008a0724._2_1_;
          DAT_01e62c8c._3_1_ = DAT_008a0724._3_1_;
          (&DAT_01e62c86)[DAT_01ade7ec] = 0x4e;
          *(undefined4 *)(puVar9 + -0x118) = 0;
          goto LAB_004df257;
        }
        if (DAT_01ade7e0 == 0x5a) {
          DAT_008a06c8 = 6;
          *(undefined4 *)(puVar9 + -0x114) = 0;
          goto LAB_004df192;
        }
        if (DAT_01ade7e0 == 0x5f) {
          DAT_008a06c8 = 7;
          *(undefined4 *)(puVar9 + -0x110) = 0;
          goto LAB_004df192;
        }
        if (DAT_01ade7e0 == 0x55) {
          DAT_008a06c8 = 7;
          *(undefined4 *)(puVar9 + -0x10c) = 0;
          goto LAB_004df1bc;
        }
        DAT_008a06f8 = 0;
        switch(DAT_0078d934) {
        default:
          DAT_008a06c4 = (int)DAT_01ade7e0 / 0xc + -5;
          FUN_005f33c9(puVar9,0x4df2a2);
          FUN_005f34d1(puVar9,0x4df2bd);
          *(undefined4 *)(puVar9 + -0x2ec) = 0;
          *(undefined4 *)(puVar9 + -0x308) = 2;
          *(undefined4 **)(puVar9 + -0x304) = &DAT_020b8eb4;
          *(int **)(puVar9 + -0x300) = &DAT_008a06c4;
          FUN_005f34f0(puVar9 + -0x2ec,0x784ff00,&DAT_00765cc4,puVar9 + -0x308,&DAT_007947c0);
          thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_00765cc0);
          DAT_01b12c9c = DAT_008a06c4 + 1;
          *(undefined4 *)(puVar9 + -0x104) = 0;
          goto LAB_004de583;
        case 2:
          DAT_008a06c8 = 5;
          *(undefined4 *)(puVar9 + -0x100) = 0;
          goto LAB_004df192;
        case 3:
          DAT_008a06c8 = 2;
          *(undefined4 *)(puVar9 + -0xfc) = 0;
          break;
        case 4:
          DAT_008a06c8 = 3;
          *(undefined4 *)(puVar9 + -0xf8) = 0;
          goto LAB_004df192;
        case 5:
          DAT_008a06c8 = 4;
          *(undefined4 *)(puVar9 + -0xf4) = 0;
          break;
        case 6:
          DAT_008a06c8 = 1;
          *(undefined4 *)(puVar9 + -0xf0) = 0;
          goto LAB_004df192;
        case 7:
          DAT_008a06c8 = 6;
          *(undefined4 *)(puVar9 + -0xec) = 0;
          break;
        case 8:
          DAT_008a06c8 = 1;
          *(undefined4 *)(puVar9 + -0xe8) = 0;
          break;
        case 9:
          DAT_008a06c8 = 4;
          *(undefined4 *)(puVar9 + -0xe4) = 0;
          goto LAB_004df192;
        case 10:
          DAT_008a06c8 = 3;
          *(undefined4 *)(puVar9 + -0xe0) = 0;
          break;
        case 0xb:
          DAT_008a06c8 = 2;
          *(undefined4 *)(puVar9 + -0xdc) = 0;
LAB_004df192:
          (&DAT_01e62c85)[DAT_01ade7ec] = 0x46;
          goto LAB_004df1d9;
        case 0xc:
          DAT_008a06c8 = 5;
          *(undefined4 *)(puVar9 + -0xd8) = 0;
        }
LAB_004df1bc:
        (&DAT_01e62c85)[DAT_01ade7ec] = 0x53;
        *(undefined4 *)(puVar9 + -0xd4) = 0;
LAB_004df1d9:
        puVar9[-0x2f5] = (char)DAT_008a06c8 + '0';
        (&DAT_01e62c84)[DAT_01ade7ec] = puVar9[-0x2f5];
        DAT_01b12c90 = DAT_008a06c8;
        if ((&DAT_01e62c85)[DAT_01ade7ec] == 'F') {
          DAT_01b12c90 = -DAT_008a06c8;
        }
        DAT_008a071c = _DAT_01e62c84;
        DAT_008a0720._0_1_ = (char)DAT_01e62c88;
        DAT_008a0720._1_1_ = DAT_01e62c88._1_1_;
        DAT_008a0720._2_1_ = DAT_01e62c88._2_1_;
        DAT_008a0720._3_1_ = DAT_01e62c88._3_1_;
        DAT_008a0724._0_1_ = (char)DAT_01e62c8c;
        DAT_008a0724._1_1_ = DAT_01e62c8c._1_1_;
        DAT_008a0724._2_1_ = DAT_01e62c8c._2_1_;
        DAT_008a0724._3_1_ = DAT_01e62c8c._3_1_;
        DAT_01ade7ec = DAT_01ade7ec + 2;
LAB_004df257:
        FUN_004e19fa();
        *(undefined4 *)(puVar9 + -0xd0) = 0;
        goto LAB_004e0a19;
      }
      *(undefined4 *)(puVar9 + -0x210) = 0;
LAB_004e043d:
      if ((int)DAT_01ade7e0 < 0x3c) {
        *(undefined4 *)(puVar9 + -0x1dc) = 0;
        goto LAB_004de583;
      }
      DAT_01ade7ec = 2;
      _DAT_008a06d4 = 0;
      if ((0x4b < (int)DAT_01ade7e0) && ((int)DAT_01ade7e0 < 0x57)) {
        _DAT_01e62c84 = CONCAT11(0x54,DAT_01e62c84);
        DAT_01ade7e0 = DAT_01ade7e0 - 0xc;
        DAT_01ade7ec = 3;
      }
      if ((0x57 < (int)DAT_01ade7e0) && ((int)DAT_01ade7e0 < 100)) {
        switch(DAT_01ade7e0) {
        case 0x58:
          DAT_01ade7ec = 5;
          DAT_01e62c84 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3c];
          DAT_01e62c85 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3d];
          DAT_01e62c86 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3e];
          DAT_01e62c87 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3f];
          DAT_01e62c88._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x40];
          DAT_01e62c88._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x41];
          DAT_01e62c88._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x42];
          DAT_01e62c88._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x43];
          DAT_01e62c8c._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x44];
          DAT_01e62c8c._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x45];
          DAT_01e62c8c._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x46];
          DAT_01e62c8c._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x47];
          *(undefined4 *)(puVar9 + -0x18c) = 0;
          break;
        case 0x59:
        case 0x5a:
          DAT_01ade7ec = 4;
          DAT_01e62c84 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x30];
          DAT_01e62c85 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x31];
          DAT_01e62c86 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x32];
          DAT_01e62c87 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x33];
          DAT_01e62c88._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x34];
          DAT_01e62c88._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x35];
          DAT_01e62c88._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x36];
          DAT_01e62c88._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x37];
          DAT_01e62c8c._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x38];
          DAT_01e62c8c._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x39];
          DAT_01e62c8c._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3a];
          DAT_01e62c8c._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3b];
          if (DAT_01ade7e0 != 0x5a) {
            *(undefined4 *)(puVar9 + -0x184) = 0;
            break;
          }
          *(undefined4 *)(puVar9 + -0x188) = 0;
          goto code_r0x004e086d;
        case 0x5b:
        case 0x5c:
          DAT_01ade7ec = 2;
          DAT_01e62c84 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x24];
          DAT_01e62c85 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x25];
          DAT_01e62c86 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x26];
          DAT_01e62c87 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x27];
          DAT_01e62c88._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x28];
          DAT_01e62c88._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x29];
          DAT_01e62c88._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2a];
          DAT_01e62c88._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2b];
          DAT_01e62c8c._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2c];
          DAT_01e62c8c._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2d];
          DAT_01e62c8c._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2e];
          DAT_01e62c8c._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2f];
          if (DAT_01ade7e0 == 0x5c) {
            *(undefined4 *)(puVar9 + -0x180) = 0;
            goto code_r0x004e086d;
          }
          *(undefined4 *)(puVar9 + -0x17c) = 0;
          break;
        case 0x5d:
        case 0x5e:
          DAT_01ade7ec = 3;
          DAT_01e62c84 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x18];
          DAT_01e62c85 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x19];
          DAT_01e62c86 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1a];
          DAT_01e62c87 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1b];
          DAT_01e62c88._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1c];
          DAT_01e62c88._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1d];
          DAT_01e62c88._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1e];
          DAT_01e62c88._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1f];
          DAT_01e62c8c._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x20];
          DAT_01e62c8c._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x21];
          DAT_01e62c8c._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x22];
          DAT_01e62c8c._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x23];
          if (DAT_01ade7e0 == 0x5e) {
            *(undefined4 *)(puVar9 + -0x178) = 0;
            goto code_r0x004e086d;
          }
          *(undefined4 *)(puVar9 + -0x174) = 0;
          break;
        case 0x5f:
          DAT_01ade7ec = 3;
          DAT_01e62c84 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xc];
          DAT_01e62c85 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xd];
          DAT_01e62c86 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xe];
          DAT_01e62c87 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xf];
          DAT_01e62c88._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x10];
          DAT_01e62c88._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x11];
          DAT_01e62c88._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x12];
          DAT_01e62c88._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x13];
          DAT_01e62c8c._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x14];
          DAT_01e62c8c._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x15];
          DAT_01e62c8c._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x16];
          DAT_01e62c8c._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x17];
          if (DAT_01ade7e0 == 0x61) {
            *(undefined4 *)(puVar9 + -0x170) = 0;
            goto code_r0x004e086d;
          }
          *(undefined4 *)(puVar9 + -0x16c) = 0;
          break;
        case 0x60:
        case 0x61:
          DAT_01ade7ec = 3;
          DAT_01e62c84 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0];
          DAT_01e62c85 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[1];
          DAT_01e62c86 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[2];
          DAT_01e62c87 = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[3];
          DAT_01e62c88._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[4];
          DAT_01e62c88._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[5];
          DAT_01e62c88._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[6];
          DAT_01e62c88._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[7];
          DAT_01e62c8c._0_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[8];
          DAT_01e62c8c._1_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[9];
          DAT_01e62c8c._2_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[10];
          DAT_01e62c8c._3_1_ = s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xb];
          *(undefined4 *)(puVar9 + -0x168) = 0;
          break;
        default:
          goto code_r0x004e0691;
        }
        goto code_r0x004e092f;
      }
code_r0x004e0691:
      uVar4 = _DAT_01e62c86;
      switch(DAT_01ade7e0) {
      case 0x3e:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x44;
        *(undefined4 *)(puVar9 + -0x1d0) = 0;
        break;
      case 0x3f:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x57;
        *(undefined4 *)(puVar9 + -0x1cc) = 0;
        goto code_r0x004e086d;
      case 0x40:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x57;
        *(undefined4 *)(puVar9 + -0x1c8) = 0;
        break;
      case 0x41:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x48;
        *(undefined4 *)(puVar9 + -0x1c4) = 0;
        break;
      case 0x42:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x48;
        goto code_r0x004e086d;
      case 0x43:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x51;
        *(undefined4 *)(puVar9 + -0x1b8) = 0;
        break;
      case 0x44:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x51;
        *(undefined4 *)(puVar9 + -0x1b4) = 0;
        goto code_r0x004e086d;
      case 0x45:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x45;
        *(undefined4 *)(puVar9 + -0x1b0) = 0;
        break;
      case 0x46:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x45;
        *(undefined4 *)(puVar9 + -0x1ac) = 0;
        goto code_r0x004e086d;
      case 0x47:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x53;
        *(undefined4 *)(puVar9 + -0x1a8) = 0;
        break;
      case 0x48:
        _DAT_01e62c84 = CONCAT12(DAT_00765c7c,0x3300);
        if (DAT_01ade7ec == 2) {
          *(undefined4 *)(puVar9 + -0x1a4) = 0;
        }
        else {
          _DAT_01e62c84 = CONCAT12(s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x3c],0x3400);
          *(undefined4 *)(puVar9 + -0x1a0) = 0;
        }
        goto code_r0x004e0903;
      case 0x49:
        *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x53;
        *(undefined4 *)(puVar9 + -0x19c) = 0;
code_r0x004e086d:
        while( true ) {
          puVar1 = &DAT_01e62c84 + DAT_01ade7ec;
          DAT_01ade7ec = DAT_01ade7ec + 1;
          *puVar1 = 0x2e;
          if (_DAT_008a0700 == 0) break;
          _DAT_008a0700 = 0;
          *(undefined4 *)(puVar9 + -0x1bc) = 0;
        }
        *(undefined4 *)(puVar9 + -0x1c0) = 0;
        break;
      case 0x4a:
        _DAT_01e62c84 = CONCAT12(DAT_00765c84,0x3600);
        if (DAT_01ade7ec == 2) {
          *(undefined4 *)(puVar9 + -0x198) = 0;
        }
        else {
          _DAT_01e62c84 = CONCAT12(UNK_00765be8,0x3900);
        }
code_r0x004e0903:
        DAT_01ade7ec = 3;
        *(undefined4 *)(puVar9 + -0x194) = 0;
        break;
      case 0x4b:
        _DAT_01e62c84 = CONCAT22(uVar4,0x4700);
        *(undefined4 *)(puVar9 + -400) = 0;
        break;
      default:
        if (DAT_01ade7e0 != 0x3c) {
          if ((int)DAT_01ade7e0 % 0xc != 6) {
            if ((int)DAT_01ade7e0 % 0xc != 7) {
              DAT_01ade7ec = 1;
              _DAT_01e62c84 = CONCAT31(_DAT_01e62c85,DAT_00765c6c);
              *(undefined4 *)(puVar9 + -0x1d4) = 0;
              goto LAB_004e0a19;
            }
            goto LAB_004e187c;
          }
          goto LAB_004e0fff;
        }
        _DAT_008a0700 = 1;
        *(undefined4 *)(puVar9 + -0x1d8) = 0;
        goto LAB_004de583;
      }
code_r0x004e092f:
      uVar7 = _DAT_01e62c84;
      cVar2 = DAT_01e62c85;
      _DAT_01e62c84 = CONCAT31(_DAT_01e62c85,cVar2);
      if (2 < DAT_01ade7ec) {
        _DAT_01e62c86 = SUB42(uVar7,2);
        _DAT_01e62c84 = CONCAT22(_DAT_01e62c86,(short)(uVar7 >> 8));
      }
      if (3 < DAT_01ade7ec) {
        _DAT_01e62c84 = CONCAT12(DAT_01e62c87,_DAT_01e62c84);
      }
      *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x2f;
      *(undefined4 *)(puVar9 + -0x15c) = 0;
      goto LAB_004e0a19;
    }
    DAT_008a06e8 = DAT_009a9494;
    DAT_009a9494 = 0;
    if (iVar6 != 0x2a) {
      if (iVar6 == 0x2b) {
        *(undefined4 *)(puVar9 + -700) = 0;
        goto LAB_004e187c;
      }
      if (iVar6 == 0x1b) {
        FUN_005f33c9(puVar9,0x4de647);
        FUN_005f34d1(puVar9,0x4de662);
        FUN_005f33c9(puVar9,0x4de684);
        FUN_005f34d1(puVar9,0x4de69f);
        DAT_0078b4e0 = 0x53;
        iVar6 = thunk_FUN_005956b0();
        if (iVar6 == 0) {
          *(undefined4 *)(puVar9 + -0x2b4) = 0;
          DAT_009a9490 = 0;
          DAT_009a9494 = 0;
          DAT_020b8ea0._0_1_ = DAT_00765be0;
          return;
        }
        if (0 < iVar6) {
          *(undefined4 *)(puVar9 + -0x2b0) = 0;
          DAT_009a9490 = 0;
          DAT_009a9494 = 0;
          DAT_020b8ea0._0_1_ = DAT_00765bdc;
          return;
        }
        *(undefined4 *)(puVar9 + -0x2b8) = 0;
        goto LAB_004de583;
      }
      if ((0x30 < iVar6) && (iVar6 < 0x41)) {
        DAT_01e62c88._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4c];
        DAT_01e62c88._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4d];
        DAT_01e62c88._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4e];
        DAT_01e62c88._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4f];
        DAT_01e62c8c._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x50];
        DAT_01e62c8c._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x51];
        DAT_01e62c8c._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x52];
        DAT_01e62c8c._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x53];
        DAT_01ade7ec = 4;
        DAT_008a06e8._0_1_ = (char)iVar6;
        puVar9[-0x2f5] = (char)DAT_008a06e8;
        DAT_01e62c87 = SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._72_4_,3);
        _DAT_01e62c84 = (undefined2)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._72_4_;
        _DAT_01e62c84 = CONCAT12(puVar9[-0x2f5],_DAT_01e62c84);
        DAT_01b12c90 = 0x30 - iVar6;
        if (0x3a < iVar6) {
          puVar9[-0x2f5] = (char)DAT_008a06e8 + -10;
          _DAT_01e62c84 = CONCAT12(puVar9[-0x2f5],_DAT_01e62c84);
          _DAT_01e62c84 = CONCAT13('S',_DAT_01e62c84);
          DAT_01b12c90 = iVar6 + -0x3a;
        }
        DAT_008a06e8 = iVar6;
        FUN_004e19fa();
        *(undefined4 *)(puVar9 + -0x2ac) = 0;
        goto LAB_004e0a19;
      }
      if ((iVar6 == -99) || (iVar6 == -0x62)) {
        DAT_01e62c84 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xc];
        DAT_01e62c85 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xd];
        DAT_01e62c86 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xe];
        DAT_01e62c87 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xf];
        DAT_01e62c88._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x10];
        DAT_01e62c88._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x11];
        DAT_01e62c88._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x12];
        DAT_01e62c88._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x13];
        DAT_01e62c8c._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x14];
        DAT_01e62c8c._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x15];
        DAT_01e62c8c._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x16];
        DAT_01e62c8c._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x17];
        if (iVar6 == -0x62) {
          DAT_01e62c84 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0];
          DAT_01e62c85 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[1];
          DAT_01e62c86 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[2];
          DAT_01e62c87 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[3];
          DAT_01e62c88._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[4];
          DAT_01e62c88._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[5];
          DAT_01e62c88._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[6];
          DAT_01e62c88._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[7];
          DAT_01e62c8c._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[8];
          DAT_01e62c8c._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[9];
          DAT_01e62c8c._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[10];
          DAT_01e62c8c._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xb];
        }
        DAT_01ade7ec = 4;
        FUN_005f34d1(puVar9,0x4deabf);
        DAT_01ade7e8 = 99;
        *(undefined4 *)(puVar9 + -0x2a8) = 0;
      }
      else {
        if (iVar6 == -1) {
          DAT_01e62c84 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3c];
          DAT_01e62c85 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3d];
          DAT_01e62c86 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3e];
          DAT_01e62c87 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3f];
          DAT_01e62c88._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x40];
          DAT_01e62c88._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x41];
          DAT_01e62c88._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x42];
          DAT_01e62c88._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x43];
          DAT_01e62c8c._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x44];
          DAT_01e62c8c._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x45];
          DAT_01e62c8c._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x46];
          DAT_01e62c8c._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x47];
          *(undefined4 *)(puVar9 + -0x2a4) = 0;
        }
        else if (iVar6 == -2) {
          DAT_01e62c84 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x30];
          DAT_01e62c85 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x31];
          DAT_01e62c86 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x32];
          DAT_01e62c87 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x33];
          DAT_01e62c88._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x34];
          DAT_01e62c88._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x35];
          DAT_01e62c88._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x36];
          DAT_01e62c88._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x37];
          DAT_01e62c8c._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x38];
          DAT_01e62c8c._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x39];
          DAT_01e62c8c._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3a];
          DAT_01e62c8c._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3b];
          *(undefined4 *)(puVar9 + -0x2a0) = 0;
        }
        else if (iVar6 == -3) {
          DAT_01e62c84 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x24];
          DAT_01e62c85 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x25];
          DAT_01e62c86 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x26];
          DAT_01e62c87 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x27];
          DAT_01e62c88._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x28];
          DAT_01e62c88._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x29];
          DAT_01e62c88._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2a];
          DAT_01e62c88._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2b];
          DAT_01e62c8c._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2c];
          DAT_01e62c8c._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2d];
          DAT_01e62c8c._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2e];
          DAT_01e62c8c._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2f];
          *(undefined4 *)(puVar9 + -0x29c) = 0;
        }
        else if (iVar6 == -4) {
          DAT_01e62c84 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x18];
          DAT_01e62c85 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x19];
          DAT_01e62c86 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1a];
          DAT_01e62c87 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1b];
          DAT_01e62c88._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1c];
          DAT_01e62c88._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1d];
          DAT_01e62c88._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1e];
          DAT_01e62c88._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1f];
          DAT_01e62c8c._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x20];
          DAT_01e62c8c._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x21];
          DAT_01e62c8c._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x22];
          DAT_01e62c8c._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x23];
          *(undefined4 *)(puVar9 + -0x298) = 0;
        }
        else {
          if (iVar6 != -5) {
            if ((iVar6 < -0x30) && (-0x44 < iVar6)) {
              DAT_01e62c88._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[4];
              DAT_01e62c88._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[5];
              DAT_01e62c88._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[6];
              DAT_01e62c88._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[7];
              DAT_01e62c8c._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[8];
              DAT_01e62c8c._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[9];
              DAT_01e62c8c._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[10];
              DAT_01e62c8c._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xb];
              if (iVar6 < -0x38) {
                DAT_01e62c88._1_3_ = SUB43(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._4_4_,1);
                DAT_01e62c88 = CONCAT31(DAT_01e62c88._1_3_,
                                        s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x3c]);
                DAT_008a06e8 = iVar6 + 10;
              }
              puVar9[-0x2f5] = -(char)DAT_008a06e8;
              _DAT_01e62c86 = SUB42(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._0_4_,2);
              DAT_01e62c84 = (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._0_4_;
              _DAT_01e62c84 = CONCAT11(puVar9[-0x2f5],DAT_01e62c84);
              DAT_01ade7ec = 5;
              *(undefined4 *)(puVar9 + -0x28c) = 0;
              goto LAB_004e0a19;
            }
            if (iVar6 == -0x61) {
              DAT_01e62c84 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x30];
              DAT_01e62c85 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x31];
              DAT_01e62c86 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x32];
              DAT_01e62c87 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x33];
              DAT_01e62c88._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x34];
              DAT_01e62c88._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x35];
              DAT_01e62c88._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x36];
              DAT_01e62c88._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x37];
              DAT_01e62c8c._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x38];
              DAT_01e62c8c._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x39];
              DAT_01e62c8c._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x3a];
              DAT_01e62c8c._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x3b];
              DAT_01ade7ec = 5;
              *(undefined4 *)(puVar9 + -0x288) = 0;
            }
            else if (iVar6 == -0x60) {
              DAT_01e62c84 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x24];
              DAT_01e62c85 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x25];
              DAT_01e62c86 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x26];
              DAT_01e62c87 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x27];
              DAT_01e62c88._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x28];
              DAT_01e62c88._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x29];
              DAT_01e62c88._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2a];
              DAT_01e62c88._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2b];
              DAT_01e62c8c._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2c];
              DAT_01e62c8c._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2d];
              DAT_01e62c8c._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2e];
              DAT_01e62c8c._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2f];
              DAT_01ade7ec = 6;
              *(undefined4 *)(puVar9 + -0x284) = 0;
            }
            else {
              if (-0x5d < iVar6) {
                *(undefined4 *)(puVar9 + -0x27c) = 0;
                goto LAB_004de583;
              }
              DAT_01e62c84 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x18];
              DAT_01e62c85 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x19];
              DAT_01e62c86 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1a];
              DAT_01e62c87 = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1b];
              DAT_01e62c88._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1c];
              DAT_01e62c88._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1d];
              DAT_01e62c88._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1e];
              DAT_01e62c88._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1f];
              DAT_01e62c8c._0_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x20];
              DAT_01e62c8c._1_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x21];
              DAT_01e62c8c._2_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x22];
              DAT_01e62c8c._3_1_ = s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x23];
              if (iVar6 == -0x5e) {
                _DAT_01e62c86 = SUB42(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._24_4_,2);
                DAT_01e62c84 = (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._24_4_;
                _DAT_01e62c84 = CONCAT11(0x36,DAT_01e62c84);
              }
              if (iVar6 == -0x5f) {
                _DAT_01e62c84 = CONCAT11(0x39,DAT_01e62c84);
              }
              DAT_01ade7ec = 6;
              *(undefined4 *)(puVar9 + -0x280) = 0;
            }
            goto LAB_004e0a19;
          }
          DAT_01e62c84 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xc];
          DAT_01e62c85 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xd];
          DAT_01e62c86 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xe];
          DAT_01e62c87 = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xf];
          DAT_01e62c88._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x10];
          DAT_01e62c88._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x11];
          DAT_01e62c88._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x12];
          DAT_01e62c88._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x13];
          DAT_01e62c8c._0_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x14];
          DAT_01e62c8c._1_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x15];
          DAT_01e62c8c._2_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x16];
          DAT_01e62c8c._3_1_ = s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x17];
          *(undefined4 *)(puVar9 + -0x294) = 0;
        }
        DAT_01ade7ec = 3;
        *(undefined4 *)(puVar9 + -0x290) = 0;
      }
LAB_004e0a19:
      DAT_00794830 = DAT_00794830 + 1;
      (&DAT_007cb56c)[DAT_00794830] = ITEM_WORDS;
      *(int *)(&DAT_007cbbac + DAT_00794830 * 4) = DAT_00794840;
      (&DAT_007cb6fc)[DAT_00794830] = DAT_00794850;
      *(int *)(&DAT_007cba1c + DAT_00794830 * 4) = DAT_01b12c90;
      (&DAT_007cb88c)[DAT_00794830] = DAT_0079484c;
      (&DAT_007cb3dc)[DAT_00794830] = DAT_0078d938;
      iVar6 = DAT_00794830;
      iVar11 = 0;
      iVar8 = 0;
      *(undefined4 *)(puVar9 + -0x2f0) = 1;
      while (*(int *)(puVar9 + -0x2f0) < 0xd) {
        *(undefined1 *)(iVar8 * 100 + iVar6 + 0x8c3897) = (&DAT_01cade64)[iVar11];
        iVar11 = iVar11 + 1;
        iVar8 = iVar8 + 1;
        *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
      }
      *(int *)(puVar9 + -0x300) = DAT_00794830;
      *(undefined4 *)(puVar9 + -0x2f0) = 1;
      *(undefined4 *)(puVar9 + -0x2f8) = 1;
      while (*(int *)(puVar9 + -0x2f8) < 0xb) {
        iVar6 = *(int *)(puVar9 + -0x2f8);
        iVar11 = *(int *)(puVar9 + -0x2f0);
        *(undefined4 *)(puVar9 + -0x2f4) = 1;
        *(undefined4 *)(puVar9 + -0x2fc) = 1;
        while (*(int *)(puVar9 + -0x2fc) < 8) {
          *(undefined4 *)
           (*(int *)(puVar9 + -0x300) * 4 + *(int *)(puVar9 + -0x2f4) * 400 + iVar11 * 0xaf0 +
           0x8bbeb4) = *(undefined4 *)(&DAT_01cadd20 + *(int *)(puVar9 + -0x2fc) * 4 + iVar6 * 0x1c)
          ;
          *(int *)(puVar9 + -0x2f4) = *(int *)(puVar9 + -0x2f4) + 1;
          *(int *)(puVar9 + -0x2fc) = *(int *)(puVar9 + -0x2fc) + 1;
        }
        *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
        *(int *)(puVar9 + -0x2f8) = *(int *)(puVar9 + -0x2f8) + 1;
      }
      *(int *)(puVar9 + -0x304) = DAT_00794830;
      *(undefined4 *)(puVar9 + -0x2f0) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2f4) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2fc) = 1;
      while (*(int *)(puVar9 + -0x2fc) < 0x10) {
        iVar6 = *(int *)(puVar9 + -0x2f0);
        iVar11 = *(int *)(puVar9 + -0x2f4);
        *(undefined4 *)(puVar9 + -0x2f8) = 1;
        *(undefined4 *)(puVar9 + -0x300) = 1;
        while (*(int *)(puVar9 + -0x300) < 8) {
          *(undefined4 *)
           (*(int *)(puVar9 + -0x304) * 4 + *(int *)(puVar9 + -0x2f8) * 400 + iVar11 * 0xaf0 +
           0x8b7224) = *(undefined4 *)(*(int *)(puVar9 + -0x300) * 4 + iVar6 * 0x1c + 0x78db40);
          *(int *)(puVar9 + -0x2f8) = *(int *)(puVar9 + -0x2f8) + 1;
          *(int *)(puVar9 + -0x300) = *(int *)(puVar9 + -0x300) + 1;
        }
        *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
        *(int *)(puVar9 + -0x2f4) = *(int *)(puVar9 + -0x2f4) + 1;
        *(int *)(puVar9 + -0x2fc) = *(int *)(puVar9 + -0x2fc) + 1;
      }
      *(int *)(puVar9 + -0x304) = DAT_00794830;
      *(undefined4 *)(puVar9 + -0x2f0) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2f8) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2fc) = 1;
      while (*(int *)(puVar9 + -0x2fc) < 0x10) {
        iVar6 = *(int *)(puVar9 + -0x2f0);
        *(int *)(puVar9 + -0x308) = *(int *)(puVar9 + -0x2f8) * 0x4b0;
        *(undefined4 *)(puVar9 + -0x2f4) = 0;
        iVar11 = 0;
        *(undefined4 *)(puVar9 + -0x300) = 1;
        while (*(int *)(puVar9 + -0x300) < 0xd) {
          (&DAT_008c62c7)[iVar11 * 100 + *(int *)(puVar9 + -0x308) + *(int *)(puVar9 + -0x304)] =
               (&DAT_01aad694)[*(int *)(puVar9 + -0x2f4) + iVar6 * 0xc];
          *(int *)(puVar9 + -0x2f4) = *(int *)(puVar9 + -0x2f4) + 1;
          iVar11 = iVar11 + 1;
          *(int *)(puVar9 + -0x300) = *(int *)(puVar9 + -0x300) + 1;
        }
        *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
        *(int *)(puVar9 + -0x2f8) = *(int *)(puVar9 + -0x2f8) + 1;
        *(int *)(puVar9 + -0x2fc) = *(int *)(puVar9 + -0x2fc) + 1;
      }
      *(int *)(puVar9 + -0x2f8) = DAT_00794830;
      iVar11 = 0;
      iVar6 = 0;
      for (iVar8 = 1; iVar8 < 0xd; iVar8 = iVar8 + 1) {
        *(undefined1 *)(iVar6 * 100 + *(int *)(puVar9 + -0x2f8) + 0x8c3d47) =
             (&DAT_01cade58)[iVar11];
        iVar11 = iVar11 + 1;
        iVar6 = iVar6 + 1;
      }
      *(int *)(puVar9 + -0x308) = DAT_00794830;
      *(undefined4 *)(puVar9 + -0x2f0) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2f8) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x300) = 1;
      while (*(int *)(puVar9 + -0x300) < 0x10) {
        iVar6 = *(int *)(puVar9 + -0x2f0);
        iVar11 = *(int *)(puVar9 + -0x2f8);
        *(undefined4 *)(puVar9 + -0x2f4) = 0;
        *(undefined4 *)(puVar9 + -0x2fc) = 0;
        *(undefined4 *)(puVar9 + -0x304) = 1;
        while (*(int *)(puVar9 + -0x304) < 0xd) {
          *(int *)(&DAT_008a8f94 +
                  *(int *)(puVar9 + -0x2fc) * 400 + iVar11 * 0x12c0 + *(int *)(puVar9 + -0x308) * 4)
               = (int)(char)(&DAT_01aad748)[*(int *)(puVar9 + -0x2f4) + iVar6 * 0xc];
          *(int *)(puVar9 + -0x2f4) = *(int *)(puVar9 + -0x2f4) + 1;
          *(int *)(puVar9 + -0x2fc) = *(int *)(puVar9 + -0x2fc) + 1;
          *(int *)(puVar9 + -0x304) = *(int *)(puVar9 + -0x304) + 1;
        }
        *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
        *(int *)(puVar9 + -0x2f8) = *(int *)(puVar9 + -0x2f8) + 1;
        *(int *)(puVar9 + -0x300) = *(int *)(puVar9 + -0x300) + 1;
      }
      *(int *)(&DAT_008b2594 + DAT_00794830 * 4) = DAT_01ade7dc;
      if ((DAT_01fbb700 == 1) && ((_DAT_01e62c84 >> 8 & 0xff) != 0x53)) {
        thunk_FUN_004dce58();
      }
      FUN_004e1b9f(&DAT_01ade7ec);
      if (DAT_01fbb700 == 2) {
        if ((DAT_01fb8c88 == DAT_00794830) && ((&DAT_020b8e9f)[DAT_0078d938] == '/')) {
          DAT_0078d938 = DAT_0078d938 + -1;
        }
        iVar6 = thunk_FUN_004c2912(&DAT_01e62c84,0xc);
        if (iVar6 == 0) {
          thunk_FUN_004c4148(&DAT_0078d938);
          if (DAT_01fb8c88 == DAT_00794830) {
            *(undefined4 *)(puVar9 + -0x34) = 0;
LAB_004e187c:
            DAT_01ade7ec = 1;
                    /* WARNING: Ignoring partial resolution of indirect */
            DAT_01e62c84 = 0x3b;
            FUN_004e1b9f(&DAT_01ade7ec);
LAB_004e18ae:
            FUN_005f34d1(puVar9,0x4e18cb);
            DAT_008a0704 = 0;
            *(int *)(puVar9 + -0xc) = DAT_0078d938;
            DAT_01ade7ec = 1;
            iVar11 = DAT_008a0704;
            iVar6 = DAT_0078d938;
            while (0 < iVar6) {
              if ((char)(&DAT_020b909f)[DAT_01ade7ec] < ' ') {
                *(undefined4 *)(puVar9 + -8) = 0;
                DAT_008a0704 = iVar11;
              }
              else {
                DAT_008a0704 = iVar11 + 1;
                *(undefined1 *)((int)&DAT_020b8ea0 + iVar11) = (&DAT_020b909f)[DAT_01ade7ec];
              }
              *(undefined4 *)(puVar9 + -4) = 0;
              DAT_01ade7ec = DAT_01ade7ec + 1;
              *(int *)(puVar9 + -0xc) = *(int *)(puVar9 + -0xc) + -1;
              iVar11 = DAT_008a0704;
              iVar6 = *(int *)(puVar9 + -0xc);
            }
            DAT_01e62c8c._0_1_ = (char)DAT_01e62c8c;
            DAT_01e62c8c._1_1_ = SUB41(DAT_01e62c8c,1);
            DAT_01e62c8c._2_1_ = SUB41(DAT_01e62c8c,2);
            DAT_01e62c8c._3_1_ = SUB41(DAT_01e62c8c,3);
            DAT_01e62c88._0_1_ = (char)DAT_01e62c88;
            DAT_01e62c88._1_1_ = SUB41(DAT_01e62c88,1);
            DAT_01e62c88._2_1_ = SUB41(DAT_01e62c88,2);
            DAT_01e62c88._3_1_ = SUB41(DAT_01e62c88,3);
            DAT_009a9494 = 0;
            DAT_009a9490 = 0;
            DAT_008a0724._0_1_ = (char)DAT_008a0724;
            DAT_008a0724._1_1_ = SUB41(DAT_008a0724,1);
            DAT_008a0724._2_1_ = SUB41(DAT_008a0724,2);
            DAT_008a0724._3_1_ = SUB41(DAT_008a0724,3);
            DAT_008a0720._0_1_ = (char)DAT_008a0720;
            DAT_008a0720._1_1_ = SUB41(DAT_008a0720,1);
            DAT_008a0720._2_1_ = SUB41(DAT_008a0720,2);
            DAT_008a0720._3_1_ = SUB41(DAT_008a0720,3);
            DAT_008a0704 = iVar11;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x50] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._80_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x51] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._80_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x52] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._80_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x53] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._80_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4c] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._76_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4d] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._76_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4e] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._76_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4f] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._76_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x48] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._72_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x49] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._72_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4a] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._72_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x4b] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._72_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x44] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._68_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x45] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._68_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x46] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._68_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x47] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._68_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x40] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._64_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x41] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._64_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x42] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._64_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x43] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._64_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3c] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._60_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3d] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._60_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3e] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._60_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3f] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._60_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x38] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._56_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x39] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._56_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3a] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._56_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x3b] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._56_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x34] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._52_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x35] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._52_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x36] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._52_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x37] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._52_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x30] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._48_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x31] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._48_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x32] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._48_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x33] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._48_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2c] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._44_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2d] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._44_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2e] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._44_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2f] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._44_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x28] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._40_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x29] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._40_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2a] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._40_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x2b] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._40_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x24] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._36_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x25] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._36_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x26] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._36_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x27] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._36_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x20] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._32_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x21] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._32_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x22] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._32_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x23] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._32_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1c] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._28_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1d] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._28_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1e] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._28_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1f] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._28_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x18] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._24_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x19] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._24_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1a] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._24_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x1b] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._24_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x14] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._20_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x15] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._20_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x16] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._20_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x17] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._20_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x10] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._16_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x11] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._16_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x12] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._16_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0x13] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._16_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xc] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._12_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xd] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._12_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xe] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._12_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xf] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._12_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[8] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._8_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[9] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._8_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[10] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._8_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0xb] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._8_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[4] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._4_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[5] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._4_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[6] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._4_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[7] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._4_4_,3);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[0] =
                 (char)s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._0_4_;
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[1] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._0_4_,1);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[2] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._0_4_,2);
            s__2_4__PR__TE__AL__BA__TR__K1F___00765d30[3] =
                 SUB41(s__2_4__PR__TE__AL__BA__TR__K1F___00765d30._0_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x38] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._56_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x39] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._56_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x3a] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._56_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x3b] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._56_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x34] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._52_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x35] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._52_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x36] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._52_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x37] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._52_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x30] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._48_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x31] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._48_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x32] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._48_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x33] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._48_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2c] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._44_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2d] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._44_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2e] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._44_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2f] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._44_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x28] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._40_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x29] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._40_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2a] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._40_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x2b] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._40_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x24] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._36_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x25] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._36_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x26] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._36_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x27] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._36_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x20] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._32_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x21] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._32_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x22] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._32_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x23] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._32_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1c] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._28_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1d] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._28_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1e] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._28_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1f] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._28_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x18] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._24_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x19] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._24_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1a] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._24_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x1b] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._24_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x14] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._20_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x15] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._20_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x16] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._20_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x17] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._20_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x10] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._16_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x11] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._16_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x12] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._16_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0x13] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._16_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xc] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._12_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xd] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._12_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xe] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._12_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xf] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._12_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[8] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._8_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[9] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._8_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[10] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._8_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0xb] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._8_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[4] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._4_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[5] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._4_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[6] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._4_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[7] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._4_4_,3);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[0] =
                 (char)s__CUT__COM__3_16__12_16__12_8_8_00765cf0._0_4_;
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[1] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._0_4_,1);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[2] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._0_4_,2);
            s__CUT__COM__3_16__12_16__12_8_8_00765cf0[3] =
                 SUB41(s__CUT__COM__3_16__12_16__12_8_8_00765cf0._0_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x44] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._68_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x45] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._68_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x46] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._68_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x47] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._68_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x40] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._64_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x41] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._64_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x42] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._64_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x43] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._64_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3c] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._60_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3d] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._60_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3e] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._60_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3f] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._60_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x38] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._56_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x39] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._56_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3a] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._56_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x3b] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._56_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x34] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._52_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x35] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._52_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x36] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._52_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x37] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._52_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x30] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._48_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x31] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._48_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x32] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._48_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x33] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._48_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2c] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._44_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2d] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._44_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2e] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._44_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2f] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._44_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x28] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._40_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x29] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._40_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2a] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._40_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x2b] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._40_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x24] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._36_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x25] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._36_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x26] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._36_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x27] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._36_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x20] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._32_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x21] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._32_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x22] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._32_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x23] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._32_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1c] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._28_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1d] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._28_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1e] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._28_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1f] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._28_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x18] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._24_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x19] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._24_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1a] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._24_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x1b] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._24_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x14] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._20_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x15] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._20_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x16] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._20_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x17] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._20_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x10] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._16_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x11] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._16_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x12] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._16_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0x13] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._16_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xc] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._12_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xd] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._12_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xe] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._12_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xf] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._12_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[8] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._8_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[9] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._8_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[10] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._8_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0xb] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._8_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[4] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._4_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[5] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._4_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[6] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._4_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[7] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._4_4_,3);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[0] =
                 (char)s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._0_4_;
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[1] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._0_4_,1);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[2] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._0_4_,2);
            s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec[3] =
                 SUB41(s_40_20_10_5_2_5_1_25_Top_meter_nu_00765bec._0_4_,3);
            return;
          }
          goto LAB_004e0fca;
        }
        DAT_00794830 = DAT_00794830 + -1;
        DAT_0078d938 = DAT_0078d938 + -1;
        *(undefined4 *)(puVar9 + -0x38) = 0;
      }
      else {
LAB_004e0fca:
        FUN_005f34d1(puVar9,0x4e0fe7);
      }
      _DAT_008a0700 = 0;
      *(undefined4 *)(puVar9 + -0x30) = 0;
      goto LAB_004de583;
    }
    *(undefined4 *)(puVar9 + -0x2c0) = 0;
LAB_004e0fff:
    *(undefined4 *)(puVar9 + -0x2c) = 0;
    if (DAT_00794830 == 1) {
      FUN_005f34d1(puVar9,0x4e102c);
      thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_00765be4);
    }
    if (DAT_00794830 == 0) {
      *(undefined4 *)(puVar9 + -0x28) = 0;
      goto LAB_004de27c;
    }
    if (DAT_01fbb700 == 2) {
      while( true ) {
        thunk_FUN_004249c9(&DAT_00794834);
        DAT_00794834 = DAT_00794834 + -1;
        if ((float)(&ITEM_P3)[(&ITEM_PTR0)[DAT_00794834]] !=
            (float)(&ITEM_P3)[(&DAT_02091d20)[DAT_00794834]]) break;
        *(undefined4 *)(puVar9 + -0x24) = 0;
      }
      DAT_00794830 = DAT_00794830 + -1;
      while( true ) {
        if (DAT_0078d938 != 0) {
          (&DAT_020b909f)[DAT_0078d938] = 0x20;
        }
        DAT_01ade7ec = DAT_0078d938 + -1;
        if ((DAT_01ade7ec == 0) || ((&DAT_020b909e)[DAT_0078d938] == '/')) break;
        *(undefined4 *)(puVar9 + -0x20) = 0;
        DAT_0078d938 = DAT_01ade7ec;
      }
      *(undefined4 *)(puVar9 + -0x1c) = 0;
      DAT_0078d938 = DAT_01ade7ec;
    }
    else {
      if (DAT_00794850 != (float)(&DAT_007cb6fc)[DAT_00794830]) {
        *(undefined4 *)(puVar9 + -0x18) = 0;
      }
      ITEM_WORDS = (&DAT_007cb56c)[DAT_00794830];
      iVar6 = 0xc;
      for (iVar11 = 1; iVar11 < 0x6e; iVar11 = iVar11 + 1) {
        (&DAT_01aad7f0)[iVar6] = 0;
        iVar6 = iVar6 + 1;
      }
      DAT_00794850 = (float)(&DAT_007cb6fc)[DAT_00794830];
      _DAT_008a06ec = f_9999;
      DAT_01ade7d4 = 1;
      DAT_0078d938 = (&DAT_007cb3dc)[DAT_00794830];
      DAT_0079484c = (&DAT_007cb88c)[DAT_00794830];
      DAT_0078dec4 = -1;
      DAT_00794830 = DAT_00794830 + -1;
      DAT_0078dec8 = 0;
      *(int *)(puVar9 + -0x2fc) = DAT_00794830;
      *(undefined4 *)(puVar9 + -0x2f0) = 1;
      *(undefined4 *)(puVar9 + -0x2f8) = 1;
      while (*(int *)(puVar9 + -0x2f8) < 0xb) {
        iVar6 = *(int *)(puVar9 + -0x2f0);
        iVar11 = *(int *)(puVar9 + -0x2f8);
        *(undefined4 *)(puVar9 + -0x2f4) = 1;
        for (iVar8 = 1; iVar8 < 8; iVar8 = iVar8 + 1) {
          *(undefined4 *)(&DAT_01cadd20 + iVar8 * 4 + iVar11 * 0x1c) =
               *(undefined4 *)
                (*(int *)(puVar9 + -0x2f4) * 400 + iVar6 * 0xaf0 + *(int *)(puVar9 + -0x2fc) * 4 +
                0x8bbeb4);
          *(int *)(puVar9 + -0x2f4) = *(int *)(puVar9 + -0x2f4) + 1;
        }
        *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
        *(int *)(puVar9 + -0x2f8) = *(int *)(puVar9 + -0x2f8) + 1;
      }
      *(int *)(puVar9 + -0x300) = DAT_00794830;
      *(undefined4 *)(puVar9 + -0x2f0) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2f8) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2fc) = 1;
      while (*(int *)(puVar9 + -0x2fc) < 0x10) {
        iVar6 = *(int *)(puVar9 + -0x2f0);
        iVar11 = *(int *)(puVar9 + -0x2f8);
        *(undefined4 *)(puVar9 + -0x2f4) = 1;
        for (iVar8 = 1; iVar8 < 8; iVar8 = iVar8 + 1) {
          *(undefined4 *)(iVar8 * 4 + iVar11 * 0x1c + 0x78db40) =
               *(undefined4 *)
                (*(int *)(puVar9 + -0x2f4) * 400 + iVar6 * 0xaf0 + *(int *)(puVar9 + -0x300) * 4 +
                0x8b7224);
          *(int *)(puVar9 + -0x2f4) = *(int *)(puVar9 + -0x2f4) + 1;
        }
        *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
        *(int *)(puVar9 + -0x2f8) = *(int *)(puVar9 + -0x2f8) + 1;
        *(int *)(puVar9 + -0x2fc) = *(int *)(puVar9 + -0x2fc) + 1;
      }
      *(int *)(puVar9 + -0x304) = DAT_00794830;
      *(undefined4 *)(puVar9 + -0x2f0) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2f8) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2fc) = 1;
      while (*(int *)(puVar9 + -0x2fc) < 0x10) {
        *(int *)(puVar9 + -0x308) = *(int *)(puVar9 + -0x2f0) * 0x4b0;
        iVar6 = *(int *)(puVar9 + -0x2f8);
        *(undefined4 *)(puVar9 + -0x2f4) = 0;
        iVar11 = 0;
        *(undefined4 *)(puVar9 + -0x300) = 1;
        while (*(int *)(puVar9 + -0x300) < 0xd) {
          (&DAT_01aad694)[iVar11 + iVar6 * 0xc] =
               (&DAT_008c62c7)
               [*(int *)(puVar9 + -0x2f4) * 100 + *(int *)(puVar9 + -0x308) +
                *(int *)(puVar9 + -0x304)];
          *(int *)(puVar9 + -0x2f4) = *(int *)(puVar9 + -0x2f4) + 1;
          iVar11 = iVar11 + 1;
          *(int *)(puVar9 + -0x300) = *(int *)(puVar9 + -0x300) + 1;
        }
        *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
        *(int *)(puVar9 + -0x2f8) = *(int *)(puVar9 + -0x2f8) + 1;
        *(int *)(puVar9 + -0x2fc) = *(int *)(puVar9 + -0x2fc) + 1;
      }
      *(int *)(puVar9 + -0x2f8) = DAT_00794830;
      iVar11 = 0;
      iVar6 = 0;
      for (iVar8 = 1; iVar8 < 0xd; iVar8 = iVar8 + 1) {
        (&DAT_01cade58)[iVar6] =
             *(undefined1 *)(iVar11 * 100 + *(int *)(puVar9 + -0x2f8) + 0x8c3d47);
        iVar11 = iVar11 + 1;
        iVar6 = iVar6 + 1;
      }
      *(int *)(puVar9 + -0x304) = DAT_00794830;
      *(undefined4 *)(puVar9 + -0x2f0) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2f4) = 0xfffffff9;
      *(undefined4 *)(puVar9 + -0x2fc) = 1;
      while (*(int *)(puVar9 + -0x2fc) < 0x10) {
        iVar6 = *(int *)(puVar9 + -0x2f0);
        *(int *)(puVar9 + -0x308) = *(int *)(puVar9 + -0x2f4) * 0xc;
        iVar11 = 0;
        *(undefined4 *)(puVar9 + -0x2f8) = 0;
        *(undefined4 *)(puVar9 + -0x300) = 1;
        while (*(int *)(puVar9 + -0x300) < 0xd) {
          (&DAT_01aad748)[*(int *)(puVar9 + -0x2f8) + *(int *)(puVar9 + -0x308)] =
               (&DAT_008a8f94)[iVar11 * 400 + iVar6 * 0x12c0 + *(int *)(puVar9 + -0x304) * 4];
          iVar11 = iVar11 + 1;
          *(int *)(puVar9 + -0x2f8) = *(int *)(puVar9 + -0x2f8) + 1;
          *(int *)(puVar9 + -0x300) = *(int *)(puVar9 + -0x300) + 1;
        }
        *(int *)(puVar9 + -0x2f0) = *(int *)(puVar9 + -0x2f0) + 1;
        *(int *)(puVar9 + -0x2f4) = *(int *)(puVar9 + -0x2f4) + 1;
        *(int *)(puVar9 + -0x2fc) = *(int *)(puVar9 + -0x2fc) + 1;
      }
      *(int *)(puVar9 + -0x2f8) = DAT_00794830;
      iVar11 = 0;
      iVar6 = 0;
      for (iVar8 = 1; iVar8 < 0xd; iVar8 = iVar8 + 1) {
        (&DAT_01cade64)[iVar6] =
             *(undefined1 *)(iVar11 * 100 + *(int *)(puVar9 + -0x2f8) + 0x8c3897);
        iVar11 = iVar11 + 1;
        iVar6 = iVar6 + 1;
      }
      DAT_01ade7dc = *(int *)(&DAT_008b2594 + DAT_00794830 * 4);
      ITEM_I = ITEM_I + -1;
      DAT_01b12c90 = *(int *)(&DAT_007cba1c + DAT_00794830 * 4);
      DAT_00794840 = *(int *)(&DAT_007cbbac + DAT_00794830 * 4);
      thunk_FUN_004ddb6e(&ITEM_I);
    }
    (&DAT_020b90a0)[DAT_0078d938] = 0;
    puVar10 = (undefined4 *)&DAT_020b90a0;
    puVar12 = (undefined4 *)&DAT_020b8ea0;
    for (iVar6 = 0x80; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_0078d938);
    if (DAT_00794830 != 0) {
      *(undefined4 *)(puVar9 + -0x14) = 0;
      goto LAB_004de583;
    }
    FUN_005f34d1(puVar9,0x4e17a9);
    FUN_005f34d1(puVar9,0x4e17ca);
    *(undefined4 *)(puVar9 + -0x10) = 0;
  } while( true );
  *(undefined4 *)(puVar9 + -0x278) = 0;
  goto LAB_004de583;
DAT_004dfe28:
  DAT_01ade7c7 = DAT_01ade7c7 - 1;
  if ((char)DAT_01ade7c7 < 'A') {
    DAT_01ade7c7 = 0x47;
  }
  if (DAT_01ade7c7 == 0x42) {
    DAT_01ade7dc = DAT_01ade7dc + -1;
  }
  *(undefined4 *)(puVar9 + -0x60) = 0;
LAB_004dfe6b:
  DAT_01ade7f4 = 0;
  DAT_01aad7b0 = DAT_01ade7f0;
  if (DAT_01ade7f0 == 3) {
    DAT_01aad7b0 = 0;
  }
  _DAT_01aad7ac = DAT_01ade7f8;
  FUN_004e1970();
  DAT_01ade7cc = DAT_01ade7c7 - 0x42;
  if (DAT_01ade7cc < 1) {
    DAT_01ade7cc = DAT_01ade7c7 - 0x3b;
  }
  DAT_01ade7d0 = *(int *)(&DAT_01cadd20 + DAT_01ade7dc * 0x1c + DAT_01ade7cc * 4);
  *(undefined4 *)(puVar9 + -0x5c) = 0;
  goto LAB_004dfef0;
}


