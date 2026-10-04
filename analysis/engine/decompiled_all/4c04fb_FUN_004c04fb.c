// FUN_004c04fb @ 004c04fb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004c0d5c) */
/* WARNING: Removing unreachable block (ram,0x004c0564) */
/* WARNING: Removing unreachable block (ram,0x004c0c54) */
/* WARNING: Removing unreachable block (ram,0x004c0835) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x01e62c84 : 0x004c0807 */
/* WARNING: Removing unreachable block (ram,0x004c084f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_004c04fb(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  byte *pbVar7;
  int *piVar8;
  undefined4 *puVar9;
  char *pcVar10;
  byte *pbVar11;
  int *piVar12;
  bool bVar13;
  bool bVar14;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 extraout_ST0;
  unkbyte10 Var15;
  float10 fVar16;
  
  puVar5 = &stack0xfffffffc;
  if (DAT_020b90a0 == '/') {
    DAT_0089fa74 = DAT_0089fa74 + 1;
  }
  if (DAT_020b90a0 == '+') {
    DAT_00794850 = DAT_00794850 - DAT_0078cae8;
  }
  iVar3 = ITEM_WORDS;
  for (iVar6 = 1; iVar6 < 0x1c; iVar6 = iVar6 + 1) {
    (&ITEM_LEN)[iVar3] = f_0;
    iVar3 = iVar3 + 1;
  }
  DAT_00794834 = ITEM_WORDS;
  DAT_0089fa84 = ITEM_WORDS;
  DAT_0089fa70 = 1;
  _DAT_01fb9638 = DAT_0078cae8;
  _DAT_0089fa6c = 0;
  _DAT_0089fa68 = 0;
  DAT_007cb2c4 = 0;
  DAT_0089fa64 = 0;
  _DAT_0089fa60 = 0;
  ffree(in_ST0);
  iVar3 = FUN_004c2912(&DAT_01e62c84,0xc);
  fVar16 = extraout_ST0;
  if (iVar3 == 0) {
    if (DAT_00794830 == 0) {
      _DAT_0089fa5c = f_0;
      DAT_0089fa58 = 0;
      _DAT_0089fa54 = 99;
      DAT_0078cae4 = 0;
      DAT_0078dec4 = -1;
      puVar5 = &stack0xfffffffc;
    }
LAB_004c066b:
    do {
      *(undefined4 *)(puVar5 + -0x130) = 0xc;
      DAT_0089fa50 = 1;
      while (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) != '[') {
        *(undefined4 *)(puVar5 + -300) = 0;
        if (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == ']') {
          DAT_007cb2c4 = DAT_007cc600;
          ffree(fVar16);
          fVar16 = (float10)thunk_FUN_0054c5f8(&DAT_01e62c84 + DAT_0089fa50,1,
                                               DAT_0089fa50 + 0x1e62c83,1,&DAT_00764d34);
          *(undefined4 *)(puVar5 + -0x120) = 0;
          goto LAB_004c066b;
        }
        *(undefined4 *)(puVar5 + -0x124) = 0;
        if (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == '@') {
          *(undefined4 *)(puVar5 + -0x118) = 0;
          goto LAB_004c244f;
        }
        *(undefined4 *)(puVar5 + -0x11c) = 0;
        if ((&DAT_01e62c84)[DAT_0089fa50] == '[') {
          *(undefined4 *)(puVar5 + -0x114) = 0;
        }
        else if ((*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == 'X') ||
                (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == 'Z')) {
          DAT_01ade7ec = DAT_0089fa50;
          ffree(fVar16);
          fVar16 = (float10)FUN_004c2458(&DAT_01e62c84,1,&DAT_0089fa64,&DAT_01ade7ec);
          DAT_0089fa80 = *(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3);
          *(undefined1 *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) = 0x20;
          *(undefined4 *)(puVar5 + -0x10c) = 0;
        }
        else {
          *(undefined4 *)(puVar5 + -0x110) = 0;
          if ((*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == 'O') ||
             (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == 'P')) {
            if ((&DAT_01e62c84)[DAT_0089fa50] == '[') {
              *(undefined4 *)(puVar5 + -0x104) = 0;
            }
            else if (((int)DAT_0089fa50 < 2) ||
                    (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 2) != 'R')) {
              if ((&DAT_01e62c84)[DAT_0089fa50] == 'R') {
                *(undefined4 *)(puVar5 + -0xfc) = 0;
              }
              else if (DAT_0089fa50 == 1) {
                DAT_0078dec4 = 1;
                if (DAT_01e62c84 == 'O') {
                  DAT_0078dec4 = -1;
                }
                *(undefined4 *)(puVar5 + -0x160) = 0xb;
                *(undefined4 *)(puVar5 + -0x164) = 0xb;
                FUN_005f46bc(puVar5,0x4c0880);
                fVar16 = (float10)FUN_005f34d1(puVar5,0x4c0896);
              }
              else {
                *(undefined4 *)(puVar5 + -0xf8) = 0;
              }
            }
            else {
              *(undefined4 *)(puVar5 + -0x100) = 0;
            }
          }
          else {
            *(undefined4 *)(puVar5 + -0x108) = 0;
          }
        }
        *(undefined4 *)(puVar5 + -0xf4) = 0;
        DAT_0089fa50 = DAT_0089fa50 + 1;
        *(int *)(puVar5 + -0x130) = *(int *)(puVar5 + -0x130) + -1;
        if (*(int *)(puVar5 + -0x130) < 1) {
          if (DAT_01ade7e8 == 0) goto LAB_004c0a01;
          *(undefined4 *)(puVar5 + -0xf0) = 0;
          goto LAB_004c1d2d;
        }
      }
      DAT_007cb2c0 = DAT_007cc604;
      DAT_007cb2c8 = (int)*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 2);
      ffree(fVar16);
      fVar16 = (float10)thunk_FUN_0054c5f8(&DAT_01e62c84 + DAT_0089fa50,1,&DAT_01e62c84,1,
                                           &DAT_00764d30);
      *(undefined4 *)(puVar5 + -0x128) = 0;
    } while( true );
  }
  goto LAB_004c244f;
LAB_004c0a01:
  DAT_01ade7c4 = *(byte *)((int)&DAT_01e62c80 + DAT_0089fa70 + 3);
  if (((DAT_01ade7c4 != 0x27) && (DAT_01ade7c4 != 0x2f)) && (DAT_01ade7c4 != 0x3a)) {
    *(undefined4 *)(puVar5 + -0xec) = 0;
    bVar13 = DAT_01ade7c4 < 0x50;
    bVar14 = DAT_01ade7c4 == 0x50;
    if (!bVar14) goto LAB_004c0a9a;
    bVar13 = (byte)(&DAT_01e62c84)[DAT_0089fa70] < 0x52;
    bVar14 = true;
    if ((&DAT_01e62c84)[DAT_0089fa70] == 0x52) goto LAB_004c0a9a;
    *(undefined4 *)(puVar5 + -0xe4) = 0;
  }
  DAT_0089fa70 = DAT_0089fa70 + 1;
  *(undefined4 *)(puVar5 + -0xe8) = 0;
  goto LAB_004c0a01;
LAB_004c0a9a:
  iVar3 = 1;
  pbVar7 = &DAT_01ade7c4;
  pbVar11 = &DAT_00764d2c;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar13 = *pbVar7 < *pbVar11;
    bVar14 = *pbVar7 == *pbVar11;
    pbVar7 = pbVar7 + 1;
    pbVar11 = pbVar11 + 1;
  } while (bVar14);
  if (bVar13 || bVar14) {
LAB_004c0bd4:
    if (DAT_01ade7c4 == 0x51) {
      DAT_0089fa58 = 1;
      if ((DAT_01e62c85 == 0x2d) || (DAT_01e62c85 == 0x30)) {
        DAT_0089fa58 = 0;
      }
      *(undefined4 *)(puVar5 + -0xdc) = 0;
      goto LAB_004c244f;
    }
    if (DAT_01ade7c4 == 0x2d) {
      FUN_005f46bc(puVar5,0x4c0c78);
      FUN_005f34d1(puVar5,0x4c0c8e);
      DAT_0079484c = 0;
      _DAT_00794854 = 0x12;
      if (DAT_0089fa78 == 0x4142) {
        DAT_0079484c = 1;
        _DAT_00794854 = 6;
      }
      else if (DAT_0089fa78 == 0x4c41) {
        DAT_0079484c = 2;
        _DAT_00794854 = 0xc;
      }
      else if (DAT_0089fa78 == 0x4554) {
        DAT_0079484c = 3;
        _DAT_00794854 = 10;
      }
      *(undefined4 *)(puVar5 + -0xd8) = 0;
      goto LAB_004c222f;
    }
    DAT_01ade7ec = DAT_0089fa70;
    FUN_005f46bc(puVar5,0x4c0d7e);
    fVar16 = (float10)FUN_005f34d1(puVar5,0x4c0d94);
    DAT_01ade7c4 = (byte)DAT_0089fa78;
    if ((((byte)DAT_0089fa78 == 0x54) || (DAT_0089fa78 == 0x4c41)) ||
       ((DAT_0089fa78 == 0x4142 || (DAT_0089fa78 == 0x5250)))) {
      *(undefined4 *)(puVar5 + -0xd4) = 0;
LAB_004c1e75:
      DAT_0089fa4c = f_5;
      DAT_0089fa48 = f_3;
      *(undefined4 *)(puVar5 + -0xb4) = 5;
      DAT_0089fa44 = 0;
      do {
        if (*(ushort *)(s_TRBAALTEPR_007925e0 + DAT_0089fa44 * 2) == DAT_0089fa78) {
          DAT_0079484c = DAT_0089fa44;
          _DAT_00794854 = (&DAT_007925ec)[DAT_0089fa44];
        }
        *(undefined4 *)(puVar5 + -0xb0) = 0;
        DAT_0089fa44 = DAT_0089fa44 + 1;
        *(int *)(puVar5 + -0xb4) = *(int *)(puVar5 + -0xb4) + -1;
      } while (0 < *(int *)(puVar5 + -0xb4));
      DAT_0089fa40 = DAT_0079484c;
      if (((byte)DAT_0089fa78 == 0x3d) || ((byte)DAT_0089fa78 == 0x2e)) {
        DAT_0079484c = 0x68;
      }
      if ((DAT_0089fa78 == 0x3d3d) || (DAT_0089fa78 == 0x2e2e)) {
        DAT_0079484c = 0xc6;
      }
      (&ITEM_P5)[DAT_00794834] = (float)DAT_0079484c;
      DAT_00794850 = DAT_0078cae8 + DAT_00794850;
      LOAD_P3 = DAT_00794850;
      (&ITEM_P4)[DAT_0089fa84] = f_0;
      DAT_00794850 = DAT_00794850 + f_2;
      _DAT_01fb9638 = _DAT_01fb9638 + f_2;
      DAT_007cc610 = 0xd;
      DAT_007cc60c = DAT_0079484c;
      DAT_0079484c = DAT_0089fa40;
      *(undefined4 *)(puVar5 + -0xac) = 0;
      goto LAB_004c2007;
    }
    if (((_DAT_01e62c84 & 0xffffff) == 0x545543) || (DAT_0089fa78 == 0x4f43)) {
      *(undefined4 *)(puVar5 + -0xd0) = 0;
      IP1 = 99;
      if (DAT_0089fa78 == 0x5543) {
        IP1 = 0x62;
      }
      *(undefined4 *)(puVar5 + -0x80) = 0;
    }
    else {
      bVar14 = (byte)DAT_0089fa78 < 0x52;
      if ((byte)DAT_0089fa78 == 0x52) {
        *(undefined4 *)(puVar5 + -0xcc) = 0;
        DAT_0089fa4c = f_5;
        DAT_0089fa48 = f_2;
        DAT_0079483c = f_0;
        DAT_0089fa80 = DAT_01e62c86;
        if ((DAT_0089fa78 == 0x5552) || (DAT_01e62c86 == 'U')) {
          DAT_0079483c = f_6;
        }
        if ((DAT_0089fa78 == 0x4452) || (DAT_01e62c86 == 'D')) {
          DAT_0079483c = f_m6;
        }
        (&ITEM_P4)[DAT_00794834] = DAT_0079483c;
        DAT_0079483c = f_0;
        if (DAT_0089fa78 == 0x5752) {
          DAT_0079483c = f_m2;
        }
        if (DAT_0089fa78 == 0x5052) {
          DAT_0079483c = f_m4;
        }
        (&ITEM_P5)[DAT_00794834] = DAT_0079483c;
        DAT_00794850 = DAT_0078cae8 + DAT_00794850;
        DAT_01fb9634 = 0;
        DAT_007cc610 = 0xc;
        *(undefined2 *)(puVar5 + -0x164) = in_FPUControlWord;
        *(ushort *)(puVar5 + -0x162) = (ushort)*(undefined4 *)(puVar5 + -0x164) | 0xc00;
        *(int *)(puVar5 + -0x160) = (int)ROUND(DAT_0079483c);
        in_FPUControlWord = *(undefined2 *)(puVar5 + -0x164);
        DAT_007cc60c = *(int *)(puVar5 + -0x160);
        bVar14 = DAT_0089fa78 < 0x4652;
        if (DAT_0089fa78 == 0x4652) {
          *(float *)(&ITEM_P8 + DAT_00794834 * 4) = f_m1;
          *(undefined4 *)(puVar5 + -0xa0) = 0;
LAB_004c1056:
          DAT_0089fa4c = f_8;
          *(undefined4 *)(puVar5 + -0x98) = 0;
        }
        else {
          *(undefined4 *)(puVar5 + -0xa4) = 0;
          iVar3 = 1;
          bVar13 = false;
          pbVar7 = &DAT_01e62c85;
          pbVar11 = &DAT_00764d2c;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar14 = *pbVar7 < *pbVar11;
            bVar13 = *pbVar7 == *pbVar11;
            pbVar7 = pbVar7 + 1;
            pbVar11 = pbVar11 + 1;
          } while (bVar13);
          if (!bVar14) {
            iVar3 = 1;
            pbVar7 = &DAT_01e62c85;
            pbVar11 = &DAT_00764d28;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar14 = *pbVar7 < *pbVar11;
              bVar13 = *pbVar7 == *pbVar11;
              pbVar7 = pbVar7 + 1;
              pbVar11 = pbVar11 + 1;
            } while (bVar13);
            if (bVar14 || bVar13) {
              ffree(fVar16);
              fVar16 = (float10)FUN_004c2458(&DAT_01e62c84,1,&DAT_0089fa3c,&DAT_01ade7ec);
              *(float *)(&ITEM_P8 + DAT_00794834 * 4) = (float)DAT_0089fa3c;
              goto LAB_004c1056;
            }
          }
          *(undefined4 *)(puVar5 + -0x9c) = 0;
        }
        goto LAB_004c172d;
      }
      iVar3 = 1;
      bVar13 = false;
      pbVar7 = &DAT_01ade7c4;
      pbVar11 = &DAT_00764d04;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar14 = *pbVar7 < *pbVar11;
        bVar13 = *pbVar7 == *pbVar11;
        pbVar7 = pbVar7 + 1;
        pbVar11 = pbVar11 + 1;
      } while (bVar13);
      if (!bVar14) {
        iVar3 = 1;
        pbVar7 = &DAT_01ade7c4;
        pbVar11 = &DAT_00764d00;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar14 = *pbVar7 < *pbVar11;
          bVar13 = *pbVar7 == *pbVar11;
          pbVar7 = pbVar7 + 1;
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (bVar14 || bVar13) {
          *(undefined4 *)(puVar5 + -200) = 0;
          DAT_007abac8 = 0;
          DAT_0089fa38 = 0;
          _DAT_0089fa34 = 0;
LAB_004c10c5:
          *(undefined4 *)(puVar5 + -0x5c) = 0xc;
          DAT_0089fa50 = 0xc;
          do {
            if (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == 'U') {
              DAT_007abac8 = 1;
              *(undefined1 *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) = 0x20;
            }
            else if (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == 'J') {
              DAT_007abac8 = -1;
              *(undefined1 *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) = 0x20;
            }
            if (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == '+') {
              DAT_0089fa38 = 1;
            }
            if (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == '-') {
              DAT_0089fa38 = -1;
            }
            if (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == ' ') {
              *(undefined4 *)(puVar5 + -0x58) = 0;
            }
            else if (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 2) == ' ') goto LAB_004c11d7;
            *(undefined4 *)(puVar5 + -0x4c) = 0;
            DAT_0089fa50 = DAT_0089fa50 - 1;
            *(int *)(puVar5 + -0x5c) = *(int *)(puVar5 + -0x5c) + -1;
            if (*(int *)(puVar5 + -0x5c) < 1) {
              DAT_01ade7c4 = (&DAT_01e62c84)[DAT_0089fa70];
              DAT_01ade7ec = 1;
              ffree(fVar16);
              FUN_004c2458(&DAT_01e62c84,1,&DAT_0089fa3c,&DAT_01ade7ec);
              if (DAT_0089fa3c != 0) {
                DAT_007cbfa0 = DAT_0089fa3c;
              }
              if ((DAT_007cbfa0 == -1) &&
                 ((DAT_007cbfa0 = 4, DAT_0079484c == 1 || (DAT_0079484c == 3)))) {
                DAT_007cbfa0 = 3;
              }
              DAT_00794844 = 0;
              iVar3 = (int)*(char *)((int)&DAT_01e62c80 + DAT_0089fa70 + 3);
              DAT_0089fa30 = iVar3 + -0x42;
              if (DAT_0089fa30 < 1) {
                DAT_0089fa30 = iVar3 + -0x3b;
              }
              if (((DAT_007abac8 == 0) && (DAT_0089fa3c == 0)) && (-1 < DAT_0078dec4)) {
                if (DAT_0089fa30 - _DAT_0089fa54 < -3) {
                  DAT_007cbfa0 = DAT_007cbfa0 + 1;
                }
                if (3 < DAT_0089fa30 - _DAT_0089fa54) {
                  DAT_007cbfa0 = DAT_007cbfa0 + -1;
                }
              }
              else {
                *(undefined4 *)(puVar5 + -0x48) = 0;
              }
              _DAT_0089fa54 = DAT_0089fa30;
              if (DAT_01ade7c4 == 0x28) {
                _DAT_0089fa34 = 100;
                DAT_01ade7c4 = (&DAT_01e62c85)[DAT_0089fa70];
                DAT_0089fa70 = DAT_0089fa70 + 1;
              }
              if (*(byte *)((int)&DAT_01e62c80 + DAT_0089fa70 + 3) == DAT_01ade7c4) {
                DAT_00794844 = 1;
                bVar14 = (&DAT_01e62c85)[DAT_0089fa70] < DAT_01ade7c4;
                if ((&DAT_01e62c85)[DAT_0089fa70] == DAT_01ade7c4) {
                  DAT_00794844 = 2;
                }
                *(undefined4 *)(puVar5 + -0x44) = 0;
              }
              else if (DAT_01ade7c4 == 0x46) {
                DAT_00794844 = 1;
                bVar14 = (&DAT_01e62c85)[DAT_0089fa70] < 0x46;
                if ((&DAT_01e62c85)[DAT_0089fa70] == 0x46) {
                  DAT_00794844 = 4;
                }
                *(undefined4 *)(puVar5 + -0x40) = 0;
              }
              else {
                if (DAT_01ade7c4 == 0x4e) {
                  DAT_00794844 = 3;
                }
                if (DAT_01ade7c4 == 0x53) {
                  DAT_00794844 = 2;
                }
                bVar14 = (&DAT_01e62c85)[DAT_0089fa70] < 0x53;
                if ((&DAT_01e62c85)[DAT_0089fa70] == 0x53) {
                  DAT_00794844 = 5;
                }
              }
              goto LAB_004c14ae;
            }
          } while( true );
        }
      }
      if ((byte)DAT_0089fa78 == 0x4b) {
        *(undefined4 *)(puVar5 + -0xc4) = 0;
        DAT_0089fa4c = f_6;
        DAT_0089fa48 = f_17;
        DAT_01ade7ec = 1;
        ffree(fVar16);
        fVar16 = (float10)FUN_004c2458(&DAT_01e62c84,1,&DAT_0089fa3c,&DAT_01ade7ec);
        DAT_0089fa44 = DAT_0089fa3c;
        if (_DAT_01e62c84 >> 0x18 == 0x4e) {
          DAT_0089fa3c = DAT_0089fa3c + 100;
        }
        DAT_007cc60c = DAT_0089fa3c * 10 + DAT_0079484c;
        if ((_DAT_01e62c84 >> 0x10 & 0xff) == 0x46) {
          DAT_0089fa3c = -DAT_0089fa3c;
        }
        if (DAT_0089fa3c < 0) {
          DAT_007cc60c = -DAT_007cc60c;
        }
        (&ITEM_P5)[DAT_00794834] = (float)DAT_0089fa3c;
        (&ITEM_P6)[DAT_00794834] = (float)DAT_0079484c;
        (&ITEM_P4)[DAT_0089fa84] = f_0;
        LOAD_P3 = DAT_0078cae8 + DAT_00794850;
        *(int *)(puVar5 + -0x160) = DAT_0089fa44 * 3;
        DAT_00794850 = ((float)*(int *)(puVar5 + -0x160) + LOAD_P3) - f_5;
        *(int *)(puVar5 + -0x160) = DAT_0089fa44 * 3 + -5;
        _DAT_01fb9638 = (float)*(int *)(puVar5 + -0x160);
        DAT_007cc610 = 0x11;
        *(undefined4 *)(puVar5 + -0xa8) = 0;
        goto LAB_004c2007;
      }
      if ((byte)DAT_0089fa78 == 0x4d) {
        *(undefined4 *)(puVar5 + -0xc0) = 0;
        DAT_0089fa4c = f_5;
        DAT_0089fa48 = f_14;
        DAT_00794844 = 0;
        DAT_01ade7ec = 1;
        ffree(fVar16);
        fVar16 = (float10)FUN_004c2458(&DAT_01e62c84,1,&DAT_0089fa3c,&DAT_01ade7ec);
        bVar14 = false;
        if (DAT_0089fa3c != 0) {
          DAT_0078cae4 = DAT_0089fa3c;
        }
        do {
          DAT_01ade7c4 = (&DAT_01e62c84)[DAT_0089fa70];
          iVar3 = 1;
          pbVar7 = &DAT_01ade7c4;
          pbVar11 = &DAT_00764cdc;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar2 = *pbVar11;
            bVar1 = *pbVar7;
            bVar14 = bVar1 < bVar2;
            pbVar7 = pbVar7 + 1;
            pbVar11 = pbVar11 + 1;
          } while (bVar1 == bVar2);
          if (bVar14) {
            *(undefined4 *)(puVar5 + -0x94) = 0;
            goto LAB_004c1aed;
          }
          if ((DAT_01ade7c4 != 0x44) || (DAT_00794844 = 1, (&DAT_01e62c85)[DAT_0089fa70] != 0x48))
          goto LAB_004c1a1c;
          bVar14 = 0xfffffffe < DAT_0089fa70;
          DAT_0089fa70 = DAT_0089fa70 + 1;
          *(undefined4 *)(puVar5 + -0x90) = 0;
        } while( true );
      }
      if ((byte)DAT_0089fa78 == 0x53) {
        *(undefined4 *)(puVar5 + -0xbc) = 0;
        DAT_00794840 = 99;
        if (DAT_0089fa78 == 0x4f53) {
          DAT_00794840 = 0;
          *(undefined4 *)(puVar5 + -0x78) = 0;
        }
        else if (DAT_0089fa78 == 0x5553) {
          DAT_00794840 = 1;
          *(undefined4 *)(puVar5 + -0x74) = 0;
        }
        else if (DAT_0089fa78 == 0x4453) {
          DAT_00794840 = -1;
          *(undefined4 *)(puVar5 + -0x70) = 0;
        }
        else {
          if (DAT_0089fa78 == 0x3053) {
            DAT_007abacc = 0;
            *(undefined4 *)(puVar5 + -0x6c) = 0;
            goto LAB_004c222f;
          }
          if (DAT_0089fa78 == 0x2b53) {
            DAT_007abacc = 1;
            *(undefined4 *)(puVar5 + -0x68) = 0;
            goto LAB_004c222f;
          }
          if (DAT_0089fa78 == 0x2d53) {
            DAT_007abacc = 2;
            *(undefined4 *)(puVar5 + -100) = 0;
            goto LAB_004c222f;
          }
        }
        DAT_007cc610 = 10;
        *(undefined4 *)(puVar5 + -0x60) = 0;
        goto LAB_004c222f;
      }
      if ((byte)DAT_0089fa78 == 0x3d) goto LAB_004c1e75;
      *(undefined4 *)(puVar5 + -0xb8) = 0;
LAB_004c1d2d:
      bVar14 = false;
      IP1 = 99;
      iVar3 = 3;
      piVar8 = (int *)&DAT_01e62c84;
      piVar12 = &DAT_00764cd0;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar14 = *piVar8 == *piVar12;
        piVar8 = piVar8 + 1;
        piVar12 = piVar12 + 1;
      } while (bVar14);
      if (bVar14) {
        IP1 = 0x62;
      }
    }
    IP2 = 0;
  }
  else {
    iVar3 = 1;
    pbVar7 = &DAT_01ade7c4;
    pbVar11 = &DAT_00764d28;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar13 = *pbVar7 < *pbVar11;
      bVar14 = *pbVar7 == *pbVar11;
      pbVar7 = pbVar7 + 1;
      pbVar11 = pbVar11 + 1;
    } while (bVar14);
    if (!bVar13 && !bVar14) goto LAB_004c0bd4;
    *(undefined4 *)(puVar5 + -0xe0) = 0;
    IP1 = (_DAT_01e62c84 & 0xff) - 0x30;
    if (DAT_01e62c85 != 0x20) {
      IP1 = IP1 * 10 + (uint)DAT_01e62c85 + -0x30;
    }
    DAT_0089fa50 = 3;
    while (*(char *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3) == ' ') {
      DAT_0089fa50 = DAT_0089fa50 + 1;
      *(undefined4 *)(puVar5 + -0x88) = 0;
    }
    uVar4 = (uint)*(byte *)((int)&DAT_01e62c80 + DAT_0089fa50 + 3);
    bVar14 = uVar4 < 0x30;
    IP2 = uVar4 - 0x30;
    bVar13 = IP2 == 0;
    DAT_0089fa80 = (&DAT_01e62c84)[DAT_0089fa50];
    iVar3 = 1;
    pbVar7 = (byte *)&DAT_0089fa80;
    pbVar11 = &DAT_00764d2c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar14 = *pbVar7 < *pbVar11;
      bVar13 = *pbVar7 == *pbVar11;
      pbVar7 = pbVar7 + 1;
      pbVar11 = pbVar11 + 1;
    } while (bVar13);
    if (!bVar14 && !bVar13) {
      iVar3 = 1;
      pbVar7 = (byte *)&DAT_0089fa80;
      pbVar11 = &DAT_00764d28;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar14 = *pbVar7 < *pbVar11;
        bVar13 = *pbVar7 == *pbVar11;
        pbVar7 = pbVar7 + 1;
        pbVar11 = pbVar11 + 1;
      } while (bVar13);
      if (bVar14 || bVar13) {
        IP2 = IP2 * 10 + (uint)(byte)(&DAT_01e62c84)[DAT_0089fa50] + -0x30;
      }
    }
    *(undefined4 *)(puVar5 + -0x84) = 0;
  }
  DAT_0089fa4c = f_6;
  DAT_0089fa48 = f_18;
  (&ITEM_P4)[DAT_00794834] = f_0;
  (&ITEM_P5)[DAT_00794834] = (float)IP1;
  (&ITEM_P6)[DAT_00794834] = (float)IP2;
  LOAD_P3 = DAT_0078cae8 + DAT_00794850;
  if ((IP2 == 0x10) || (DAT_00794850 = LOAD_P3, 9 < IP1)) {
    DAT_00794850 = LOAD_P3 + f_2;
  }
  DAT_01ade7e8 = 0;
  DAT_01ade7ec = 5;
  DAT_007cc610 = 0x12;
  DAT_007cc60c = IP1 * 100 + IP2;
  *(undefined4 *)(puVar5 + -0x7c) = 0;
  goto LAB_004c2007;
LAB_004c11d7:
  iVar3 = 0xd - DAT_0089fa50;
  *(int *)(puVar5 + -0x54) = iVar3;
  DAT_01ade7ec = DAT_0089fa50;
  while (0 < iVar3) {
    *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 2) =
         *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3);
    *(undefined1 *)((int)&DAT_01e62c80 + DAT_01ade7ec + 3) = 0x20;
    DAT_01ade7ec = DAT_01ade7ec + 1;
    *(int *)(puVar5 + -0x54) = *(int *)(puVar5 + -0x54) + -1;
    iVar3 = *(int *)(puVar5 + -0x54);
  }
  *(undefined4 *)(puVar5 + -0x50) = 0;
  goto LAB_004c10c5;
LAB_004c14ae:
  iVar3 = 1;
  pbVar7 = &DAT_01ade7c4;
  pbVar11 = &DAT_00764d04;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar2 = *pbVar11;
    bVar1 = *pbVar7;
    bVar14 = bVar1 < bVar2;
    pbVar7 = pbVar7 + 1;
    pbVar11 = pbVar11 + 1;
  } while (bVar1 == bVar2);
  if (bVar14) goto LAB_004c14f1;
  bVar14 = 0xfffffffe < DAT_0089fa70;
  DAT_01ade7c4 = (&DAT_01e62c85)[DAT_0089fa70];
  *(undefined4 *)(puVar5 + -0x38) = 0;
  DAT_0089fa70 = DAT_0089fa70 + 1;
  goto LAB_004c14ae;
LAB_004c14f1:
  *(undefined4 *)(puVar5 + -0x3c) = 0;
  DAT_0089fa4c = f_5;
  DAT_0089fa48 = f_1;
  if (DAT_007abac8 == 0) {
    *(undefined4 *)(puVar5 + -0x34) = 0;
  }
  else {
    if ((0 < DAT_007abac8) && (DAT_0089fa30 <= DAT_0089fa2c)) {
      DAT_007cbfa0 = DAT_007cbfa0 + 1;
    }
    if ((DAT_007abac8 < 0) && (DAT_0089fa2c <= DAT_0089fa30)) {
      DAT_007cbfa0 = DAT_007cbfa0 + -1;
    }
  }
  DAT_0089fa2c = DAT_0089fa30;
  DAT_007cc610 = DAT_0089fa30;
  DAT_0089fa44 = DAT_007cbfa0 * 7 + DAT_0089fa30 + *(int *)(&DAT_00792600 + DAT_0079484c * 4) +
                 -0x1c;
  *(int *)(puVar5 + -0x160) = DAT_007cb2cc + DAT_0089fa44;
  (&ITEM_P4)[DAT_00794834] = (float)*(int *)(puVar5 + -0x160);
  DAT_0079483c = f_0;
  _DAT_0089fa28 = f_0;
  if (DAT_0089fa58 != 0) {
    if (f_0 <= (float)(&ITEM_P4)[DAT_00794834]) {
      (&ITEM_P4)[DAT_00794834] = (float)(&ITEM_P4)[DAT_00794834] + f_100;
    }
    else {
      (&ITEM_P4)[DAT_00794834] = (float)(&ITEM_P4)[DAT_00794834] - f_100;
    }
  }
  if (DAT_00794840 == 0) {
    *(undefined4 *)(puVar5 + -0x30) = 0;
  }
  else {
    DAT_0079483c = f_10;
    if (DAT_00794840 < 0) {
      DAT_0079483c = f_20;
    }
  }
  fVar16 = (float10)DAT_00794844 + (float10)DAT_0079483c;
  (&ITEM_P5)[DAT_00794834] = (float)((float10)_DAT_0089fa34 + fVar16);
  if (DAT_007abac8 == 0) {
    *(undefined4 *)(puVar5 + -0x2c) = 0;
  }
  else {
    _DAT_0089fa28 = f_1;
  }
  if (DAT_01fb9634 == 0) {
    if (DAT_00794844 == 4) {
      DAT_00794850 = DAT_00794850 + f_3;
    }
    DAT_00794850 = DAT_0078cae8 + DAT_00794850;
    if ((DAT_020b90a0 == ':') || (DAT_020b90a0 == '\'')) {
      DAT_01fb9634 = 1;
    }
  }
  else {
    *(undefined4 *)(puVar5 + -0x28) = 0;
  }
LAB_004c172d:
  LOAD_P3 = DAT_00794850;
  if (DAT_020b90a0 != ':') {
    DAT_01fb9634 = 0;
  }
  if (DAT_007abacc == 0) {
    *(undefined4 *)(puVar5 + -0x24) = 0;
  }
  else {
    DAT_0089fa4c = f_12;
    *(float *)(&ITEM_P12 + DAT_0089fa84 * 4) = (float)DAT_007abacc;
  }
  goto LAB_004c2007;
LAB_004c1a1c:
  if (DAT_01ade7c4 == 0x48) {
    DAT_00794844 = 2;
  }
  if (DAT_01ade7c4 == 0x4c) {
    DAT_00794844 = 3;
  }
  if (DAT_01ade7c4 == 0x52) {
    DAT_00794844 = 4;
  }
  if (DAT_01ade7c4 == 0x53) {
    DAT_00794844 = 7;
  }
  if (DAT_01ade7c4 == 0x49) {
    DAT_0078cae4 = -DAT_0078cae4;
    if (DAT_0078cae4 == 0) {
      DAT_0078cae4 = -1;
    }
  }
  else if ((&DAT_01e62c85)[DAT_0089fa70] == 0x44) {
    DAT_00794844 = 5;
    DAT_0089fa70 = DAT_0089fa70 + 1;
  }
LAB_004c1aed:
  (&ITEM_P4)[DAT_00794834] = (float)DAT_0078cae4;
  if (DAT_0078cae4 < 0) {
    DAT_0078cae4 = -DAT_0078cae4;
  }
  (&ITEM_P5)[DAT_00794834] = (float)DAT_00794844;
  if (DAT_00794844 != 0) {
    DAT_00794850 = DAT_00794850 + f_2;
  }
  if ((DAT_00794844 == 3) || (DAT_00794844 == 5)) {
    DAT_00794850 = DAT_00794850 + f_2;
  }
  LOAD_P3 = DAT_0078cae8 + DAT_00794850;
  DAT_00794850 = LOAD_P3;
  if (DAT_00794844 < 4) {
    DAT_00794850 = LOAD_P3 - f_2;
  }
  DAT_00794848 = 0;
  DAT_00794844 = 0;
  DAT_007cc610 = 0xe;
  DAT_007cc60c = DAT_0078cae4;
  *(undefined4 *)(puVar5 + -0x8c) = 0;
LAB_004c2007:
  if (((DAT_020b90a0 == ':') || (DAT_0089fa38 == 0)) || (DAT_020b90a0 == '/')) {
    *(undefined4 *)(puVar5 + -0x20) = 0;
  }
  else {
    DAT_0089fa84 = (&DAT_02091d20)[ITEM_I];
    DAT_0089fa24 = DAT_0089fa38 * 7 + DAT_0089fa44;
    if (DAT_0089fa58 != 0) {
      if (-1 < DAT_0089fa24) {
        DAT_0089fa24 = DAT_0089fa24 + 100;
      }
      if (DAT_0089fa24 < 0) {
        DAT_0089fa24 = DAT_0089fa24 + -100;
      }
    }
    ITEM_WORDS = DAT_0089fa84;
    (&ITEM_P4)[DAT_0089fa84] = (float)DAT_0089fa24;
    (&ITEM_P5)[DAT_0089fa84] = (float)DAT_00794844;
    DAT_0089fa38 = 0;
  }
  while( true ) {
    (&ITEM_LEN)[DAT_0089fa84] = DAT_0089fa4c;
    (&ITEM_P1)[DAT_0089fa84] = DAT_0089fa48;
    (&ITEM_P2)[DAT_0089fa84] = DAT_01fb8c60;
    (&ITEM_P3)[DAT_0089fa84] = LOAD_P3;
    *(undefined2 *)(puVar5 + -0x164) = in_FPUControlWord;
    *(ushort *)(puVar5 + -0x162) = (ushort)*(undefined4 *)(puVar5 + -0x164) | 0xc00;
    *(int *)(puVar5 + -0x160) = (int)ROUND((float)DAT_00794834 + DAT_0089fa4c + f_1);
    DAT_00794834 = *(int *)(puVar5 + -0x160);
    *(int *)(puVar5 + -0x160) = ITEM_WORDS + 1;
    *(undefined2 *)(puVar5 + -0x164) = *(undefined2 *)(puVar5 + -0x164);
    *(ushort *)(puVar5 + -0x162) = (ushort)*(undefined4 *)(puVar5 + -0x164) | 0xc00;
    *(int *)(puVar5 + -0x160) = (int)ROUND((float)*(int *)(puVar5 + -0x160) + DAT_0089fa4c);
    in_FPUControlWord = *(undefined2 *)(puVar5 + -0x164);
    ITEM_WORDS = *(int *)(puVar5 + -0x160);
    ITEM_I = ITEM_I + 1;
    (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
    DAT_0089fa50 = ITEM_I;
    puVar9 = (undefined4 *)&DAT_020b8ea0;
    pcVar10 = &DAT_020b90a0;
    for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined4 *)pcVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      pcVar10 = pcVar10 + 4;
    }
    ffree(fVar16);
    thunk_FUN_004ddb6e(&DAT_0089fa50);
    pcVar10 = &DAT_020b90a0;
    puVar9 = (undefined4 *)&DAT_020b8ea0;
    for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      puVar9 = puVar9 + 1;
    }
LAB_004c222f:
    DAT_00794830 = DAT_00794830 + 1;
    (&DAT_007cbfa0)[DAT_00794830] = DAT_007cbfa0;
    (&DAT_007cb6fc)[DAT_00794830] = DAT_00794850;
    Var15 = FUN_005f34d1(puVar5,0x4c2283);
    _DAT_0089fa20 = 2;
    ffree(Var15);
    fVar16 = (float10)FUN_004c25e4(&DAT_0089fa20);
    if (DAT_0089fa38 == 0) break;
    DAT_00794834 = ITEM_WORDS;
    DAT_0089fa84 = ITEM_WORDS;
    DAT_0089fa24 = DAT_0089fa38 * 7 + DAT_0089fa44;
    if (DAT_0089fa58 != 0) {
      if (-1 < DAT_0089fa24) {
        DAT_0089fa24 = DAT_0089fa24 + 100;
      }
      if (DAT_0089fa24 < 0) {
        DAT_0089fa24 = DAT_0089fa24 + -100;
      }
    }
    (&ITEM_P4)[ITEM_WORDS] = (float)DAT_0089fa24;
    (&ITEM_P5)[DAT_00794834] = (float)DAT_00794844;
    DAT_0089fa38 = 0;
    *(undefined4 *)(puVar5 + -0x18) = 0;
  }
  *(undefined4 *)(puVar5 + -0x1c) = 0;
  if (DAT_0089fa64 == 0) {
    *(undefined4 *)(puVar5 + -0x14) = 0;
  }
  else {
    DAT_01ade7ec = DAT_0079485c;
    DAT_0089fa1c = ITEM_I;
    LOAD_I = 1;
    _DAT_0089fa20 = 2;
    while ((&DAT_007cd684)[DAT_01ade7ec] == 0) {
      DAT_01ade7ec = DAT_01ade7ec - 1;
      DAT_0089fa1c = DAT_0089fa1c + -1;
      LOAD_I = LOAD_I + 1;
      *(undefined4 *)(puVar5 + -0xc) = 0;
    }
    *(undefined4 *)(puVar5 + -0x10) = 0;
    while( true ) {
      ffree(fVar16);
      fVar16 = (float10)FUN_004c2711(&DAT_01ade7ec,&DAT_0089fa1c,&LOAD_I,&DAT_0089fa20);
      if (DAT_0089fa64 < 3) break;
      DAT_0089fa64 = DAT_0089fa64 + -1;
      _DAT_0089fa20 = 1;
      *(undefined4 *)(puVar5 + -4) = 0;
    }
    *(undefined4 *)(puVar5 + -8) = 0;
  }
LAB_004c244f:
  ffree(fVar16);
  return;
}


