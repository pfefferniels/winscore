// FUN_0052789c @ 0052789c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00527f44) */
/* WARNING: Removing unreachable block (ram,0x00527917) */
/* WARNING: Removing unreachable block (ram,0x00527b47) */
/* WARNING: Removing unreachable block (ram,0x00527dd7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052789c(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  float10 fVar11;
  
  puVar6 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x5278c5);
  if (DAT_01fbb700 == 2) {
    *(undefined4 *)(puVar6 + -0x80) = 0;
    DAT_0094eb1c = 1;
    DAT_0094eb20 = 3;
    DAT_0094eb28 = 1;
    while( true ) {
      iVar4 = FUN_005f4660(0x20);
      if (iVar4 != 0) {
        *(undefined4 *)(puVar6 + -0x48) = 0;
        _DAT_0094eb04 = f_8;
        DAT_0094eb08 = DAT_0094eb20 + 1;
        goto LAB_00527c6b;
      }
      cVar2 = *(char *)((int)&DAT_007cb2cc + DAT_0094eb20 + 3);
      _DAT_0094eb3c = CONCAT31(DAT_0094eb3c_1,cVar2);
      if (cVar2 == ']') break;
      if (cVar2 == 'G') {
        DAT_0094eb20 = DAT_0094eb20 + 2;
        *(undefined4 *)(puVar6 + -0x40) = 0;
      }
      else if (cVar2 == '/') {
        DAT_0094eb20 = DAT_0094eb20 + 1;
        *(undefined4 *)(puVar6 + -0x3c) = 0;
      }
      else {
        iVar4 = 0x3d - DAT_0094eb20;
        *(int *)(puVar6 + -0x38) = iVar4;
        DAT_0094eb08 = DAT_0094eb20;
        while( true ) {
          bVar10 = iVar4 == 0;
          bVar9 = false;
          if (iVar4 < 1) break;
          bVar3 = *(byte *)((int)&DAT_007cb2cc + DAT_0094eb08 + 3);
          DAT_0094eb3c_1 = (undefined3)(_DAT_0094eb3c >> 8);
          _DAT_0094eb3c = CONCAT31(DAT_0094eb3c_1,bVar3);
          bVar9 = bVar3 < 0x58;
          if ((((bVar3 == 0x58) || (bVar9 = bVar3 < 0x5d, bVar3 == 0x5d)) ||
              (bVar9 = bVar3 < 0x2e, bVar3 == 0x2e)) || (bVar9 = bVar3 < 0x2f, bVar3 == 0x2f)) {
            bVar10 = true;
            *(undefined4 *)(puVar6 + -0x34) = 0;
            break;
          }
          DAT_0094eb08 = DAT_0094eb08 + 1;
          *(int *)(puVar6 + -0x38) = *(int *)(puVar6 + -0x38) + -1;
          iVar4 = *(int *)(puVar6 + -0x38);
        }
        DAT_0094eb38 = *(byte *)((int)&DAT_007cb2cc + DAT_0094eb20 + 3);
        _DAT_0094eb04 = f_0;
        iVar4 = 1;
        pbVar7 = &DAT_0094eb38;
        pbVar8 = &DAT_00767edc;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar9 = *pbVar7 < *pbVar8;
          bVar10 = *pbVar7 == *pbVar8;
          pbVar7 = pbVar7 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar10);
        if (bVar9 || bVar10) {
          DAT_0094eb00 = DAT_0094eb38 - 0x30;
          DAT_0094eb28 = (byte)(&DAT_007cb2d0)[DAT_0094eb20] - 0x30;
          if ((-1 < DAT_0094eb28) && (DAT_0094eb28 < 10)) {
            DAT_0094eb00 = DAT_0094eb00 * 10 + DAT_0094eb28;
          }
          _DAT_0094eb04 = (float)DAT_0094eb00;
          *(undefined4 *)(puVar6 + -0x2c) = 0;
LAB_00527c6b:
          _DAT_0094eb04 = _DAT_0094eb04 / P2;
          _DAT_0094eafc = 0;
          if (_DAT_0094eb04 == f_0_5) {
            _DAT_020b90a0 = DAT_00767ef0;
            DAT_0094eb1c = 2;
          }
          else {
            fVar11 = (float10)anint(puVar6,0x527ccd);
            *(int *)(puVar6 + -0xa4) = (int)ROUND(fVar11);
            DAT_0094eaf8 = *(int *)(puVar6 + -0xa4);
            *(undefined4 *)(puVar6 + -0xa0) = 0;
            *(undefined4 *)(puVar6 + -0xb0) = 2;
            *(char **)(puVar6 + -0xac) = &DAT_020b90a0;
            *(int **)(puVar6 + -0xa8) = &DAT_0094eaf8;
            FUN_005f34f0(puVar6 + -0xa0,0x784ff00,&DAT_00767e1c,puVar6 + -0xb0,&DAT_00796d04);
            if (DAT_020b90a0 == ' ') {
              FUN_005f33c9(puVar6,0x527d6e);
            }
            DAT_0094eb1c = 1;
            if (9 < DAT_0094eaf8) {
              DAT_0094eb1c = 2;
            }
          }
          DAT_0094eb28 = DAT_0094eb08 - DAT_0094eb20;
          if (DAT_0094eb1c == DAT_0094eb28) {
            *(undefined4 *)(puVar6 + -0xa4) = 0;
            FUN_005f46bc(puVar6,0x527e06);
            FUN_005f34d1(puVar6,0x527e1c);
          }
          else if (DAT_0094eb1c < DAT_0094eb28) {
            FUN_005f46bc(puVar6,0x527e85);
            FUN_005f34d1(puVar6,0x527e9b);
            *(char *)((int)&DAT_007cb2cc + DAT_0094eb20 + 3) = DAT_020b90a0;
            DAT_0094eb08 = DAT_0094eb08 + -1;
          }
          else {
            iVar4 = (DAT_0094eb08 + -0x3d) / -1;
            *(int *)(puVar6 + -0x14) = iVar4;
            DAT_0094eb10 = 0x3c;
            while (0 < iVar4) {
              *(undefined1 *)((int)&DAT_007cb2cc + DAT_0094eb10 + 3) =
                   *(undefined1 *)((int)&DAT_007cb2cc + DAT_0094eb10 + 2);
              DAT_0094eb10 = DAT_0094eb10 + -1;
              *(int *)(puVar6 + -0x14) = *(int *)(puVar6 + -0x14) + -1;
              iVar4 = *(int *)(puVar6 + -0x14);
            }
            FUN_005f46bc(puVar6,0x527f66);
            FUN_005f34d1(puVar6,0x527f7c);
          }
        }
        else {
          *(undefined4 *)(puVar6 + -0x30) = 0;
          *(undefined4 *)(puVar6 + -0x28) = 10;
          DAT_0094eb00 = 1;
          do {
            if (s_TSTETQTHDWHQEST_00796d38[DAT_0094eb00 + 7] == DAT_0094eb38) {
              _DAT_0094eb04 = *(float *)(DAT_0094eb00 * 4 + 0x796d54);
            }
            DAT_0094eb00 = DAT_0094eb00 + 1;
            *(int *)(puVar6 + -0x28) = *(int *)(puVar6 + -0x28) + -1;
          } while (0 < *(int *)(puVar6 + -0x28));
          FUN_005f46bc(puVar6,0x527b6b);
          FUN_005f34d1(puVar6,0x527b81);
          *(undefined4 *)(puVar6 + -0x24) = 4;
          DAT_0094eb00 = 1;
          do {
            if (*(short *)(&DAT_00796d36 + DAT_0094eb00 * 2) == DAT_0094eb30) {
              _DAT_0094eb04 = *(float *)(s_TSTETQTHDWHQEST_00796d38 + DAT_0094eb00 * 4 + 0xc);
            }
            DAT_0094eb00 = DAT_0094eb00 + 1;
            *(int *)(puVar6 + -0x24) = *(int *)(puVar6 + -0x24) + -1;
          } while (0 < *(int *)(puVar6 + -0x24));
          if ((_DAT_0094eb3c & 0xff) != 0x58) {
            *(undefined4 *)(puVar6 + -0x1c) = 0;
            goto LAB_00527c6b;
          }
          *(undefined4 *)(puVar6 + -0x20) = 0;
        }
        iVar4 = 0x3d - DAT_0094eb08;
        *(int *)(puVar6 + -0x10) = iVar4;
        DAT_0094eb28 = DAT_0094eb08;
        while (0 < iVar4) {
          if (*(char *)((int)&DAT_007cb2cc + DAT_0094eb28 + 3) == ']') {
            *(undefined4 *)(puVar6 + -0xc) = 0;
            return;
          }
          if (*(char *)((int)&DAT_007cb2cc + DAT_0094eb28 + 3) == '/') {
            *(undefined4 *)(puVar6 + -8) = 0;
            break;
          }
          DAT_0094eb28 = DAT_0094eb28 + 1;
          *(int *)(puVar6 + -0x10) = *(int *)(puVar6 + -0x10) + -1;
          iVar4 = *(int *)(puVar6 + -0x10);
        }
        DAT_0094eb20 = DAT_0094eb28 + 1;
        *(undefined4 *)(puVar6 + -4) = 0;
      }
    }
    *(undefined4 *)(puVar6 + -0x44) = 0;
  }
  else {
    DAT_0094eb28 = 0;
    DAT_0094eb24 = 4;
    DAT_0094eb20 = 3;
    DAT_0094eb1c = 1;
LAB_0052804a:
    bVar3 = *(byte *)((int)&DAT_007cb2cc + DAT_0094eb20 + 3);
    _DAT_0094eb3c = CONCAT31(DAT_0094eb3c_1,bVar3);
    DAT_0094eb38 = *(byte *)((int)&DAT_007cb2cc + DAT_0094eb20 + 2);
    if (((bVar3 == 0x52) || (bVar3 == 0x4b)) || (bVar9 = bVar3 < 0x4d, bVar3 == 0x4d)) {
LAB_00528136:
      DAT_0094eb14 = DAT_0094eb20;
      DAT_0094eb18 = DAT_0094eb20;
      iVar4 = 0x81 - DAT_0094eb20;
      *(int *)(puVar6 + -0x7c) = iVar4;
      while (0 < iVar4) {
        cVar2 = *(char *)((int)&DAT_007cb2cc + DAT_0094eb14 + 3);
        DAT_0094eb3c_1 = (undefined3)(_DAT_0094eb3c >> 8);
        _DAT_0094eb3c = CONCAT31(DAT_0094eb3c_1,cVar2);
        DAT_0094eb20 = DAT_0094eb14;
        if ((cVar2 == '/') || (cVar2 == ']')) {
          *(undefined4 *)(puVar6 + -0x78) = 0;
          goto LAB_005284f2;
        }
        (&DAT_020b909f)[DAT_0094eb1c] = cVar2;
        DAT_0094eb1c = DAT_0094eb1c + 1;
        DAT_0094eb14 = DAT_0094eb14 + 1;
        *(int *)(puVar6 + -0x7c) = *(int *)(puVar6 + -0x7c) + -1;
        iVar4 = *(int *)(puVar6 + -0x7c);
      }
    }
    else {
      iVar4 = 1;
      pbVar7 = &DAT_0094eb3c;
      pbVar8 = &DAT_00767ee8;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar1 = *pbVar8;
        bVar3 = *pbVar7;
        bVar9 = bVar3 < bVar1;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar3 == bVar1);
      bVar10 = !bVar9 != 0;
      iVar4 = -(uint)!bVar9;
      bVar9 = iVar4 == 0;
      *(int *)(puVar6 + -0xa4) = iVar4;
      iVar4 = 1;
      pbVar7 = &DAT_0094eb3c;
      pbVar8 = &DAT_00767ee4;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar10 = *pbVar7 < *pbVar8;
        bVar9 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar9);
      *(uint *)(puVar6 + -0xa4) = -(uint)(bVar10 || bVar9) & *(uint *)(puVar6 + -0xa4);
      if ((-(uint)(DAT_0094eb38 == 0x20 || DAT_0094eb38 == 0x2f) & *(uint *)(puVar6 + -0xa4) & 1) !=
          0) goto LAB_00528136;
    }
    if ((((_DAT_0094eb3c & 0xff) != 0x5d) && ((_DAT_0094eb3c & 0xff) != 0x2f)) &&
       ((_DAT_0094eb3c & 0xff) != 0x3a)) {
      if (((_DAT_0094eb3c & 0xff) == 0x50) ||
         (bVar9 = (_DAT_0094eb3c & 0xff) < 0x4f, (_DAT_0094eb3c & 0xff) == 0x4f)) {
        *(undefined4 *)(puVar6 + -0x70) = 0;
        goto LAB_005284f2;
      }
      iVar4 = 1;
      bVar10 = false;
      pbVar7 = &DAT_0094eb3c;
      pbVar8 = &DAT_00767edc;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pbVar7 < *pbVar8;
        bVar10 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar10);
      if (bVar9) {
LAB_0052849d:
        *(undefined4 *)(puVar6 + -0x6c) = 0;
      }
      else {
        iVar4 = 1;
        bVar9 = false;
        pbVar7 = &DAT_0094eb3c;
        pbVar8 = &DAT_00767ee0;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar9 = *pbVar7 < *pbVar8;
          bVar10 = *pbVar7 == *pbVar8;
          pbVar7 = pbVar7 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar10);
        if (!bVar9 && !bVar10) goto LAB_0052849d;
        DAT_0094eb34 = *(byte *)((int)&DAT_007cb2cc + DAT_0094eb20 + 2);
        if ((DAT_0094eb34 == 0x53) || (bVar9 = DAT_0094eb34 < 0x4e, DAT_0094eb34 == 0x4e)) {
LAB_00528494:
          *(undefined4 *)(puVar6 + -0x68) = 0;
        }
        else {
          iVar4 = 1;
          pbVar7 = &DAT_0094eb34;
          pbVar8 = &DAT_00767edc;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar1 = *pbVar8;
            bVar3 = *pbVar7;
            bVar9 = bVar3 < bVar1;
            pbVar7 = pbVar7 + 1;
            pbVar8 = pbVar8 + 1;
          } while (bVar3 == bVar1);
          bVar10 = !bVar9 != 0;
          iVar4 = -(uint)!bVar9;
          bVar9 = iVar4 == 0;
          *(int *)(puVar6 + -0xa4) = iVar4;
          iVar4 = 1;
          pbVar7 = &DAT_0094eb34;
          pbVar8 = &DAT_00767ee0;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar10 = *pbVar7 < *pbVar8;
            bVar9 = *pbVar7 == *pbVar8;
            pbVar7 = pbVar7 + 1;
            pbVar8 = pbVar8 + 1;
          } while (bVar9);
          if ((-(uint)(bVar10 || bVar9) & *(uint *)(puVar6 + -0xa4) & 1) != 0) goto LAB_00528494;
          if (((&DAT_007cb2d0)[DAT_0094eb20] == 'O') || ((&DAT_007cb2d0)[DAT_0094eb20] == 'T')) {
            *(undefined4 *)(puVar6 + -100) = 0;
          }
          else {
            DAT_0094eb28 = (_DAT_0094eb3c & 0xff) - 0x42;
            if (DAT_0094eb28 < 1) {
              DAT_0094eb28 = (_DAT_0094eb3c & 0xff) - 0x3b;
            }
            FUN_0052859d(&DAT_007cb2d0,1,&DAT_0094eb20,&DAT_0094eb24,&DAT_0094eb10);
            DAT_0094eb28 = DAT_007cb2cc + DAT_0094eb24 * 7 + DAT_0094eb28;
            DAT_0094eb24 = (DAT_0094eb28 + -1) / 7;
            iVar4 = (DAT_0094eb28 + -1) % 7;
            DAT_0094eb0c = iVar4 + 1;
            if (5 < DAT_0094eb0c) {
              DAT_0094eb0c = iVar4 + -6;
            }
            bVar9 = false;
            bVar10 = (DAT_0094eb0c + 0x42U & 0xff) == 0;
            puVar6[-0xa1] = (char)(DAT_0094eb0c + 0x42U);
            iVar4 = DAT_0094eb10;
            _DAT_0094eb3c = CONCAT31(DAT_0094eb3c_1,puVar6[-0xa1]);
            iVar5 = 1;
            pbVar7 = (byte *)((int)&DAT_007cb2cc + DAT_0094eb10 + 3);
            pbVar8 = &DAT_00767ee4;
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar9 = *pbVar7 < *pbVar8;
              bVar10 = *pbVar7 == *pbVar8;
              pbVar7 = pbVar7 + 1;
              pbVar8 = pbVar8 + 1;
            } while (bVar10);
            if (bVar9 || bVar10) {
              puVar6[-0xa1] = (char)DAT_0094eb24 + '0';
              *(undefined1 *)((int)&DAT_007cb2cc + iVar4 + 3) = puVar6[-0xa1];
            }
            else {
              *(undefined4 *)(puVar6 + -0x60) = 0;
            }
          }
        }
      }
      (&DAT_020b909f)[DAT_0094eb1c] = (char)_DAT_0094eb3c;
      DAT_0094eb1c = DAT_0094eb1c + 1;
      DAT_0094eb20 = DAT_0094eb20 + 1;
      *(undefined4 *)(puVar6 + -0x5c) = 0;
      goto LAB_0052804a;
    }
    *(undefined4 *)(puVar6 + -0x74) = 0;
LAB_005284f2:
    (&DAT_020b909f)[DAT_0094eb1c] = (char)_DAT_0094eb3c;
    if ((_DAT_0094eb3c & 0xff) != 0x5d) {
      *(undefined4 *)(puVar6 + -0x58) = 0;
      DAT_0094eb1c = DAT_0094eb1c + 1;
      DAT_0094eb20 = DAT_0094eb20 + 1;
      *(undefined4 *)(puVar6 + -0x50) = 0;
      goto LAB_0052804a;
    }
    (&DAT_020b90a0)[DAT_0094eb1c] = 0x2f;
    *(undefined4 *)(puVar6 + -0x54) = 0;
    DAT_007cb2cc = 0;
    thunk_FUN_0054c5f8(&DAT_020b90a0,1,&DAT_007cb2d2,1,&DAT_00767ecc);
    *(undefined4 *)(puVar6 + -0x4c) = 0;
  }
  return;
}


