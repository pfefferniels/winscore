// FUN_0041fab5 @ 0041fab5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041fab5(undefined4 param_1,int *param_2)

{
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  undefined2 in_FPUControlWord;
  float10 fVar15;
  
  puVar8 = &stack0xfffffffc;
  if (DAT_007cb2c4 == 0) {
    DAT_007cb2c4 = *param_2;
  }
  FUN_005f34d1(&stack0xfffffffc,0x41faf2);
  DAT_007d20d8 = 0;
  switch(DAT_01fbb700) {
  default:
    DAT_007d20e8 = 0x544f4d2e;
    DAT_007d20d4 = DAT_007cb2c0 + 2;
    DAT_007d20d0 = 0;
    while( true ) {
      DAT_007d20e4 = (&DAT_020b8e9f)[DAT_007d20d4];
      bVar11 = DAT_007d20e4 < 0x5d;
      if (DAT_007d20e4 == 0x5d) break;
      iVar7 = 1;
      bVar12 = false;
      pbVar9 = &DAT_007d20e4;
      pbVar10 = &DAT_0075f774;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar11 = *pbVar9 < *pbVar10;
        bVar12 = *pbVar9 == *pbVar10;
        pbVar9 = pbVar9 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar11) {
        iVar7 = 1;
        pbVar9 = &DAT_007d20e4;
        pbVar10 = &DAT_0075f770;
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar11 = *pbVar9 < *pbVar10;
          bVar12 = *pbVar9 == *pbVar10;
          pbVar9 = pbVar9 + 1;
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar11 && !bVar12) goto LAB_0041fc13;
        _DAT_007d20e0 = CONCAT31(DAT_007d20e0_1,DAT_007d20e4);
        *(undefined4 *)(puVar8 + -200) = 0;
        goto LAB_0041fdc8;
      }
LAB_0041fc13:
      *(undefined4 *)(puVar8 + -0xcc) = 0;
      iVar7 = 1;
      pbVar9 = &DAT_007d20e4;
      pbVar10 = &DAT_0075f778;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar11 = *pbVar9 < *pbVar10;
        bVar12 = *pbVar9 == *pbVar10;
        pbVar9 = pbVar9 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (bVar11) {
LAB_0041fdbe:
        *(undefined4 *)(puVar8 + -0xb4) = 0;
LAB_0041fdc8:
        if (DAT_007d20e4 == 0x58) {
          DAT_007d20dc = *(undefined1 *)((int)&DAT_020b8ea0 + DAT_007d20d4);
          iVar7 = 1;
          bVar11 = true;
          bVar12 = false;
          pbVar9 = &DAT_007d20dc;
          pbVar10 = &DAT_0075f774;
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar12 = *pbVar9 < *pbVar10;
            bVar11 = *pbVar9 == *pbVar10;
            pbVar9 = pbVar9 + 1;
            pbVar10 = pbVar10 + 1;
          } while (bVar11);
          if (!bVar12 && !bVar11) {
            iVar7 = 1;
            pbVar9 = &DAT_007d20dc;
            pbVar10 = &DAT_0075f770;
            do {
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              bVar12 = *pbVar9 < *pbVar10;
              bVar11 = *pbVar9 == *pbVar10;
              pbVar9 = pbVar9 + 1;
              pbVar10 = pbVar10 + 1;
            } while (bVar11);
            if (bVar12 || bVar11) {
              *(undefined4 *)(puVar8 + -0x9c) = 0;
              DAT_007d20cc = DAT_007d20d4 + 1;
              *(int *)(puVar8 + -0xf8) = DAT_007d20d4 + 3;
              fVar15 = (float10)thunk_FUN_005191dc(&DAT_007d20cc,puVar8 + -0xf8);
              *(undefined2 *)(puVar8 + -0xf8) = in_FPUControlWord;
              *(ushort *)(puVar8 + -0xf6) = (ushort)*(undefined4 *)(puVar8 + -0xf8) | 0xc00;
              *(int *)(puVar8 + -0xf4) = (int)ROUND(fVar15);
              in_FPUControlWord = *(undefined2 *)(puVar8 + -0xf8);
              DAT_007d20c8 = *(int *)(puVar8 + -0xf4);
              if ((&DAT_020b8e9e)[DAT_007d20d4] != '/') {
                DAT_007d20c4 = DAT_007d20d4 + -2;
                while ((&DAT_020b8e9f)[DAT_007d20c4] != '/') {
                  DAT_007d20c4 = DAT_007d20c4 + -1;
                  *(undefined4 *)(puVar8 + -0x8c) = 0;
                }
                *(undefined4 *)(puVar8 + -0x90) = 0;
                **(int **)(puVar8 + 0xc) = DAT_007d20d4 - DAT_007d20c4;
                DAT_007d20c0 = **(int **)(puVar8 + 0xc) * DAT_007d20c8 - **(int **)(puVar8 + 0xc);
                DAT_007d20bc = DAT_007d20d4 + 2;
                if ((*(char *)((int)&DAT_020b8ea0 + DAT_007d20d4 + 1) != '/') &&
                   (*(char *)((int)&DAT_020b8ea0 + DAT_007d20d4 + 1) != ']')) {
                  DAT_007d20bc = DAT_007d20d4 + 3;
                }
                DAT_007d20b8 = DAT_007d20c0 - (DAT_007d20bc - DAT_007d20d4);
                DAT_007d20cc = **(int **)(puVar8 + 8);
                iVar7 = ((DAT_007d20bc - DAT_007d20cc) + -1) / -1;
                *(int *)(puVar8 + -0x88) = iVar7;
                while (0 < iVar7) {
                  (&DAT_020b8e9f)[DAT_007d20b8 + DAT_007d20cc] = (&DAT_020b8e9f)[DAT_007d20cc];
                  DAT_007d20cc = DAT_007d20cc + -1;
                  *(int *)(puVar8 + -0x88) = *(int *)(puVar8 + -0x88) + -1;
                  iVar7 = *(int *)(puVar8 + -0x88);
                }
                DAT_007cb2c4 = DAT_007d20b8 + DAT_007cb2c4;
                **(int **)(puVar8 + 8) = **(int **)(puVar8 + 8) + DAT_007d20b8;
                iVar5 = **(int **)(puVar8 + 0xc);
                iVar7 = **(int **)(puVar8 + 0xc);
                *(int *)(puVar8 + -0x84) = iVar5;
                iVar5 = ((DAT_007d20c0 - iVar7) + iVar5) / iVar5;
                *(int *)(puVar8 + -0x80) = iVar5;
                DAT_007d20cc = DAT_007d20d4;
                while (0 < iVar5) {
                  FUN_005f46bc(puVar8,0x4200c2);
                  FUN_005f34d1(puVar8,0x4200d8);
                  DAT_007d20cc = *(int *)(puVar8 + -0x84) + DAT_007d20cc;
                  *(int *)(puVar8 + -0x80) = *(int *)(puVar8 + -0x80) + -1;
                  iVar5 = *(int *)(puVar8 + -0x80);
                }
                goto LAB_0042010d;
              }
              *(undefined4 *)(puVar8 + -0x94) = 0;
              iVar7 = DAT_007d20cc + -1;
              if (9 < DAT_007d20c8) {
                iVar7 = DAT_007d20cc;
              }
              DAT_007d20cc = iVar7;
              *(int *)(puVar8 + -0xf8) = DAT_007d20cc + 2;
              fVar15 = (float10)thunk_FUN_005191dc(&DAT_007d20cc,puVar8 + -0xf8);
              *(undefined2 *)(puVar8 + -0xf8) = in_FPUControlWord;
              *(ushort *)(puVar8 + -0xf6) = (ushort)*(undefined4 *)(puVar8 + -0xf8) | 0xc00;
              *(int *)(puVar8 + -0xf4) = (int)ROUND(fVar15);
              _DAT_007d20b4 = *(undefined4 *)(puVar8 + -0xf4);
              *(undefined4 *)(puVar8 + -0x78) = 0;
              goto LAB_004201d8;
            }
          }
          *(undefined4 *)(puVar8 + -0x98) = 0;
        }
        else {
          *(undefined4 *)(puVar8 + -0xa0) = 0;
        }
LAB_0042010d:
        DAT_007d20d4 = DAT_007d20d4 + 1;
        *(undefined4 *)(puVar8 + -0x7c) = 0;
      }
      else {
        iVar7 = 1;
        bVar11 = false;
        pbVar9 = &DAT_007d20e4;
        pbVar10 = &DAT_0075f874;
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar11 = *pbVar9 < *pbVar10;
          bVar12 = *pbVar9 == *pbVar10;
          pbVar9 = pbVar9 + 1;
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar11 && !bVar12) goto LAB_0041fdbe;
        if (DAT_007d20e4 != *(byte *)((int)&DAT_020b8ea0 + DAT_007d20d4)) {
          *(undefined4 *)(puVar8 + -0xb0) = 0;
          goto LAB_0041fdc8;
        }
        puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_007d20d4);
        DAT_007d20d4 = DAT_007d20d4 + 1;
        *puVar1 = 0x46;
        if (DAT_007d20e4 != *(byte *)((int)&DAT_020b8ea0 + DAT_007d20d4)) {
          *(undefined4 *)(puVar8 + -0xac) = 0;
          DAT_007d20d4 = DAT_007d20d4 + 1;
          goto LAB_0041fdc8;
        }
        puVar1 = &DAT_020b8e9f + DAT_007d20d4;
        DAT_007d20d4 = DAT_007d20d4 + 1;
        *puVar1 = 0x53;
        DAT_007d20d0 = 1;
        if (DAT_007d20e4 == *(byte *)((int)&DAT_020b8ea0 + DAT_007d20d4)) {
          (&DAT_020b8e9e)[DAT_007d20d4] = 0x4e;
          DAT_007d20d0 = 2;
          DAT_007d20d4 = DAT_007d20d4 + 1;
        }
        else {
          *(undefined4 *)(puVar8 + -0xa8) = 0;
        }
        DAT_007cb2c4 = DAT_007cb2c4 - DAT_007d20d0;
        iVar5 = DAT_007d20d4 + 1;
        *(int *)(puVar8 + -0xf8) = 0x3c - DAT_007d20d0;
        iVar7 = (int)&DAT_020b8ea0 + DAT_007d20d4;
        DAT_007d20d4 = iVar5;
        thunk_FUN_0054c5f8(iVar7,1,&DAT_020b8e9f + (iVar5 - DAT_007d20d0),1,puVar8 + -0xf8);
        *(undefined4 *)(puVar8 + -0xa4) = 0;
      }
    }
    *(undefined4 *)(puVar8 + -0xd0) = 0;
LAB_004201d8:
    DAT_007d20b0 = DAT_007cb2c4;
    DAT_007d20d4 = DAT_007cb2c0 + 2;
    DAT_007d20d0 = 0;
LAB_004201fb:
    DAT_007d20e4 = (&DAT_020b8e9f)[DAT_007d20d4];
    bVar11 = false;
    if (DAT_007d20d0 == 0) {
      if (DAT_007d20e4 != 0x4f) {
        bVar11 = DAT_007d20e4 < 0x50;
        bVar12 = DAT_007d20e4 == 0x50;
        if (!bVar12) {
          *(undefined4 *)(puVar8 + -0x70) = 0;
          iVar7 = 1;
          pbVar9 = &DAT_007d20e4;
          pbVar10 = &DAT_0075f874;
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar11 = *pbVar9 < *pbVar10;
            bVar12 = *pbVar9 == *pbVar10;
            pbVar9 = pbVar9 + 1;
            pbVar10 = pbVar10 + 1;
          } while (bVar12);
          if (bVar11 || bVar12) {
LAB_0042028a:
            bVar11 = DAT_007d20e4 < 0x43;
            bVar12 = false;
            if (DAT_007d20e4 == 0x43) {
              bVar13 = *(char *)((int)&DAT_020b8ea0 + DAT_007d20d4) != 'C';
              bVar14 = *(char *)((int)&DAT_020b8ea0 + DAT_007d20d4) != 'O';
              bVar11 = false;
              bVar12 = bVar13 && bVar14;
              if (!bVar13 || !bVar14) {
                *(undefined4 *)(puVar8 + -100) = 0;
                goto LAB_004202e8;
              }
            }
            DAT_007d20d0 = 1;
            goto LAB_00420371;
          }
          iVar7 = 1;
          pbVar9 = &DAT_007d20e4;
          pbVar10 = &DAT_0075f870;
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar3 = *pbVar10;
            bVar2 = *pbVar9;
            bVar11 = bVar2 < bVar3;
            pbVar9 = pbVar9 + 1;
            pbVar10 = pbVar10 + 1;
          } while (bVar2 == bVar3);
          if (!bVar11) goto LAB_0042028a;
          *(undefined4 *)(puVar8 + -0x68) = 0;
LAB_004202e8:
          while( true ) {
            iVar7 = DAT_007d20d4 + 1;
            cVar4 = *(char *)((int)&DAT_020b8ea0 + DAT_007d20d4);
            DAT_007d20d4 = iVar7;
            if (((cVar4 == ']') || (cVar4 == '/')) || (cVar4 == ':')) break;
            *(undefined4 *)(puVar8 + -0x34) = 0;
          }
          if (cVar4 != ']') {
            DAT_007d20d0 = 0;
            goto LAB_00420609;
          }
          *(undefined4 *)(puVar8 + -0x30) = 0;
          DAT_007d20e4 = 0x5d;
          break;
        }
      }
      DAT_0078dec4 = DAT_007d20e4 - 0x50;
      *(undefined4 *)(puVar8 + -0x6c) = 0;
    }
    else {
      *(undefined4 *)(puVar8 + -0x74) = 0;
      bVar12 = false;
LAB_00420371:
      iVar7 = 1;
      pbVar9 = &DAT_007d20e4;
      pbVar10 = &DAT_0075f774;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar11 = *pbVar9 < *pbVar10;
        bVar12 = *pbVar9 == *pbVar10;
        pbVar9 = pbVar9 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar12);
      if (!bVar11) {
        iVar7 = 1;
        pbVar9 = &DAT_007d20e4;
        pbVar10 = &DAT_0075f770;
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar11 = *pbVar9 < *pbVar10;
          bVar12 = *pbVar9 == *pbVar10;
          pbVar9 = pbVar9 + 1;
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (bVar11 || bVar12) {
          _DAT_007d20e0 = CONCAT31(DAT_007d20e0_1,DAT_007d20e4);
          if (*(char *)((int)&DAT_020b8ea0 + DAT_007d20d4) != ']') {
            DAT_007d20d0 = 0;
            *(undefined4 *)(puVar8 + -0x58) = 0;
            DAT_007d20d4 = DAT_007d20d4 + 1;
            goto LAB_00420609;
          }
          *(undefined4 *)(puVar8 + -0x5c) = 0;
          DAT_007d20d4 = DAT_007d20d4 + 1;
          break;
        }
      }
      *(undefined4 *)(puVar8 + -0x60) = 0;
      bVar11 = false;
      bVar12 = DAT_0078dec4 == 0;
      if (DAT_0078dec4 < 0) {
LAB_00420458:
        *(undefined4 *)(puVar8 + -0x54) = 0;
      }
      else {
        iVar7 = 1;
        pbVar9 = &DAT_007d20e4;
        pbVar10 = &DAT_0075f778;
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar11 = *pbVar9 < *pbVar10;
          bVar12 = *pbVar9 == *pbVar10;
          pbVar9 = pbVar9 + 1;
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (bVar11) goto LAB_00420458;
        iVar7 = 1;
        bVar11 = false;
        pbVar9 = &DAT_007d20e4;
        pbVar10 = &DAT_0075f874;
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar11 = *pbVar9 < *pbVar10;
          bVar12 = *pbVar9 == *pbVar10;
          pbVar9 = pbVar9 + 1;
          pbVar10 = pbVar10 + 1;
        } while (bVar12);
        if (!bVar11 && !bVar12) goto LAB_00420458;
        DAT_007d20d8 = DAT_0078dec8;
        DAT_0078dec8 = DAT_007d20e4 - 0x42;
        if (DAT_0078dec8 < 1) {
          DAT_0078dec8 = DAT_007d20e4 - 0x3b;
        }
      }
      if (((DAT_007d20e4 == 0x5d) || (DAT_007d20e4 == 0x3b)) ||
         ((DAT_007d20e4 == 0x2f || (DAT_007d20e4 == 0x3a)))) {
        if ((&DAT_020b8e9e)[DAT_007d20d4] == '/') {
          *(undefined4 *)(puVar8 + -0x4c) = 0;
        }
        else {
          if ((&DAT_020b8e9e)[DAT_007d20d4] == ']') {
            *(undefined4 *)(puVar8 + -0x48) = 0;
            break;
          }
          DAT_007cb2c4 = DAT_007cb2c4 + 1;
          iVar7 = (DAT_007d20d4 + -0x180) / -1;
          *(int *)(puVar8 + -0x44) = iVar7;
          DAT_007d20c4 = 0x17f;
          while (0 < iVar7) {
            (&DAT_020b8e9f)[DAT_007d20c4] = (&DAT_020b8e9e)[DAT_007d20c4];
            DAT_007d20c4 = DAT_007d20c4 + -1;
            *(int *)(puVar8 + -0x44) = *(int *)(puVar8 + -0x44) + -1;
            iVar7 = *(int *)(puVar8 + -0x44);
          }
          if (DAT_0078dec4 < 0) {
            *(undefined4 *)(puVar8 + -0x40) = 0;
          }
          else {
            if (3 < DAT_007d20d8 - DAT_0078dec8) {
              DAT_007cbfa0 = DAT_007cbfa0 + 1;
            }
            if (3 < DAT_0078dec8 - DAT_007d20d8) {
              DAT_007cbfa0 = DAT_007cbfa0 + -1;
            }
          }
          (&DAT_020b8e9f)[DAT_007d20d4] = (char)_DAT_007d20e0;
          if (DAT_007d20e4 == 0x5d) {
            *(undefined4 *)(puVar8 + -0x3c) = 0;
            break;
          }
          DAT_007d20d0 = 0;
          *(undefined4 *)(puVar8 + -0x38) = 0;
          DAT_007d20d4 = DAT_007d20d4 + 1;
        }
      }
      else {
        *(undefined4 *)(puVar8 + -0x50) = 0;
      }
    }
LAB_00420609:
    DAT_007d20d4 = DAT_007d20d4 + 1;
    *(undefined4 *)(puVar8 + -0x2c) = 0;
    goto LAB_004201fb;
  case 2:
    DAT_007d20e8 = 0x48524d2e;
    *(undefined4 *)(puVar8 + -0xc4) = 0;
    break;
  case 3:
    DAT_007d20e8 = 0x4b524d2e;
    *(undefined4 *)(puVar8 + -0xc0) = 0;
    break;
  case 4:
    DAT_007d20e8 = 0x4d424d2e;
    *(undefined4 *)(puVar8 + -0xbc) = 0;
    break;
  case 5:
    DAT_007d20e8 = 0x4c534d2e;
    *(undefined4 *)(puVar8 + -0xb8) = 0;
  }
  DAT_007cb2c8 = (uint)(byte)(&DAT_020b8e9f)[DAT_007cb2c0];
  do {
    FUN_005f33c9(puVar8,0x420679);
    FUN_005f34d1(puVar8,0x420694);
    puVar8[-0xf1] = (undefined1)DAT_007cb2c8;
    DAT_020b90a4._2_1_ = puVar8[-0xf1];
    ram0x020b90a7 = DAT_007d20e8;
    *(undefined4 *)(puVar8 + -0xf0) = 0;
    *(undefined4 *)(puVar8 + -0x108) = 0xb;
    *(undefined1 **)(puVar8 + -0x104) = &DAT_020b90a0;
    *(undefined4 *)(puVar8 + -0x100) = 3;
    *(undefined **)(puVar8 + -0xfc) = &DAT_0075f864;
    *(undefined4 *)(puVar8 + -0xf8) = 2;
    uVar6 = FUN_005f6540(puVar8 + -0xf0,0xb,0x784ff01,&DAT_0075f854,puVar8 + -0x108);
    *(undefined4 *)(puVar8 + -0x28) = uVar6;
    if (*(int *)(puVar8 + -0x28) == 0) {
LAB_0042081f:
      DAT_007d20ec = i_912339240;
      DAT_007d20f0 = DAT_0075f848;
      DAT_007d20f2 = DAT_0075f84a;
      DAT_007d20d4 = (DAT_007cb2c4 - DAT_007cb2c0) + 2;
      *(undefined4 *)(puVar8 + -0xf0) = 0;
      *(undefined4 *)(puVar8 + -0x100) = 3;
      *(undefined4 *)(puVar8 + -0xfc) = 0x7d20ef;
      *(int **)(puVar8 + -0xf8) = &DAT_007d20d4;
      FUN_005f34f0(puVar8 + -0xf0,0x784ff00,&DAT_0075f820,puVar8 + -0x100,&DAT_0078e824);
      iVar7 = (DAT_007cb2c4 - (DAT_007cb2c0 + -1)) + 1;
      if (iVar7 < 0) {
        iVar7 = 0;
      }
      *(undefined4 *)(puVar8 + -0xf0) = 0;
      *(int *)(puVar8 + -0xf8) = DAT_007d20ec;
      *(undefined2 *)(puVar8 + -0xf4) = DAT_007d20f0;
      puVar8[-0xf2] = DAT_007d20f2;
      *(int *)(puVar8 + -0x100) = iVar7;
      *(undefined1 **)(puVar8 + -0xfc) = &DAT_020b8e9f + DAT_007cb2c0;
      *(undefined4 *)(puVar8 + -0x118) = *(undefined4 *)(puVar8 + -0xf8);
      *(undefined2 *)(puVar8 + -0x114) = *(undefined2 *)(puVar8 + -0xf4);
      puVar8[-0x112] = puVar8[-0xf2];
      *(undefined1 **)(puVar8 + -0x108) = puVar8 + -0x118;
      *(undefined4 *)(puVar8 + -0x110) = 7;
      FUN_005fc330(puVar8 + -0xf0,0xb,0x784ff08,&DAT_0075f840,puVar8 + -0x100,puVar8 + -0x110);
      *(undefined4 *)(puVar8 + -0xf0) = 0;
      FUN_005f7950(puVar8 + -0xf0,0xb,0x784ff00,&DAT_0075f83c,0);
      **(int **)(puVar8 + 8) = **(int **)(puVar8 + 8) - (DAT_007d20b0 - DAT_007cb2c4);
      *(undefined4 *)(puVar8 + -0x18) = 0;
      return;
    }
    if (((&DAT_020b8e9f)[**(int **)(puVar8 + 8)] == ';') &&
       ((&DAT_020b8e9e)[**(int **)(puVar8 + 8)] != ']')) {
      *(undefined4 *)(puVar8 + -0x14) = 0;
LAB_004207ad:
      *(undefined4 *)(puVar8 + -0xf0) = 0;
      *(undefined4 *)(puVar8 + -0x108) = 0xb;
      *(undefined1 **)(puVar8 + -0x104) = &DAT_020b90a0;
      *(undefined4 *)(puVar8 + -0x100) = 3;
      *(undefined **)(puVar8 + -0xfc) = &DAT_0075f84c;
      *(undefined4 *)(puVar8 + -0xf8) = 2;
      FUN_005f6540(puVar8 + -0xf0,0xb,0x784ff00,&DAT_0075f854,puVar8 + -0x108);
      *(undefined4 *)(puVar8 + -8) = 0;
      goto LAB_0042081f;
    }
    DAT_007d20c4 = thunk_FUN_00579410(&DAT_0075f850);
    if (DAT_007d20c4 != 0) goto LAB_004207ad;
    *(undefined4 *)(puVar8 + -0x10) = 0;
    DAT_007cb2c8 = DAT_007cb2c8 + 1;
    *(undefined4 *)(puVar8 + -4) = 0;
  } while( true );
}


