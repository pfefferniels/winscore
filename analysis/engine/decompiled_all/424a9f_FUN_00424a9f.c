// FUN_00424a9f @ 00424a9f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00424a9f(void)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  float10 fVar13;
  
  puVar6 = &stack0xfffffffc;
  puVar7 = (undefined4 *)&DAT_020b8ea0;
  puVar9 = (undefined4 *)&DAT_020b90a0;
  for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  FUN_005f46bc(&stack0xfffffffc,0x424b1b);
  FUN_005f34d1(puVar6,0x424b31);
  *(int *)(puVar6 + -0xa0) = (DAT_007cc600 - DAT_007cc604) + 1;
  thunk_FUN_00518b3f(puVar6 + -0xa0);
  DAT_0079483c = P2;
  puVar7 = (undefined4 *)&DAT_020b90a0;
  puVar9 = (undefined4 *)&DAT_020b8ea0;
  for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  DAT_007d2eb4 = 3;
  DAT_020b90a0 = *(char *)((int)&DAT_020b8ea0 + DAT_007cc604);
  if (DAT_020b90a0 == '-') {
    DAT_020b90a0 = *(char *)((int)&DAT_020b8ea0 + DAT_007cc604 + 1);
  }
  _DAT_007d2ec4 = CONCAT31(DAT_007d2ec4_1,DAT_020b90a0);
  _DAT_007d2eb8 = 0x544f4d2e;
  if (DAT_01fbb700 == 2) {
    _DAT_007d2eb8 = 0x48524d2e;
  }
  FUN_005f33c9(puVar6,0x424c0b);
  FUN_005f33c9(puVar6,0x424c27);
  FUN_005f33c9(puVar6,0x424c43);
  FUN_005f33c9(puVar6,0x424c5f);
  FUN_005f34d1(puVar6,0x424c7a);
  *(undefined4 *)(puVar6 + -0x98) = 0;
  *(undefined4 *)(puVar6 + -0xb0) = 0xb;
  *(char **)(puVar6 + -0xac) = &DAT_020b90a0;
  *(undefined4 *)(puVar6 + -0xa8) = 3;
  *(undefined **)(puVar6 + -0xa4) = &DAT_0075fa78;
  *(undefined4 *)(puVar6 + -0xa0) = 2;
  uVar4 = FUN_005f6540(puVar6 + -0x98,0xb,0x784ff01,&DAT_0075fa68,puVar6 + -0xb0);
  *(undefined4 *)(puVar6 + -0x78) = uVar4;
  if (*(int *)(puVar6 + -0x78) == 0) {
    *(undefined4 *)(puVar6 + -0x98) = 0;
    *(undefined4 *)(puVar6 + -0xa0) = 0x100;
    *(undefined1 **)(puVar6 + -0x9c) = &DAT_007cb2d0;
    uVar4 = FUN_005fdbd0(puVar6 + -0x98,0xb,0x784ff01,&DAT_0075fa64,puVar6 + -0xa0,&DAT_0078e900);
    *(undefined4 *)(puVar6 + -0x74) = uVar4;
    if (*(int *)(puVar6 + -0x74) == 0) {
      *(undefined4 *)(puVar6 + -0x98) = 0;
      FUN_005f7950(puVar6 + -0x98,0xb,0x784ff00,&DAT_0075fa60,0);
      *(undefined4 *)(puVar6 + -0x6c) = 0x3c;
      DAT_007d2eb0 = 1;
      do {
        thunk_FUN_0054c768(DAT_007d2eb0 + 0x7cb2cf);
        DAT_007d2eb0 = DAT_007d2eb0 + 1;
        *(int *)(puVar6 + -0x6c) = *(int *)(puVar6 + -0x6c) + -1;
      } while (0 < *(int *)(puVar6 + -0x6c));
      thunk_FUN_0041f64f();
      _DAT_007d2eac = 0;
      for (iVar5 = 1; iVar5 < 0xd; iVar5 = iVar5 + 1) {
        *(undefined1 *)((int)&DAT_01e62c80 + iVar5 + 3) = 0x20;
      }
      if (*(char *)((int)&DAT_020b8ea0 + DAT_007cc604) != '-') {
        do {
          DAT_007d2eb0 = 1;
          while( true ) {
            cVar2 = *(char *)((int)&DAT_007cb2cc + DAT_007d2eb4 + 3);
            _DAT_007d2ec4 = CONCAT31(DAT_007d2ec4_1,cVar2);
            if (((cVar2 == ']') || (cVar2 == '/')) || (cVar2 == ':')) break;
            *(char *)((int)&DAT_01e62c80 + DAT_007d2eb0 + 3) = cVar2;
            DAT_007d2eb0 = DAT_007d2eb0 + 1;
            DAT_007d2eb4 = DAT_007d2eb4 + 1;
            *(undefined4 *)(puVar6 + -0x60) = 0;
          }
          *(undefined4 *)(puVar6 + -100) = 0;
          *(char *)((int)&DAT_01e62c80 + DAT_007d2eb0 + 3) = cVar2;
          if ((_DAT_007d2ec4 & 0xff) == 0x5d) {
            *(undefined1 *)((int)&DAT_01e62c80 + DAT_007d2eb0 + 3) = 0x2f;
          }
          DAT_020b90a0 = DAT_007d2ec4;
          if ((_DAT_01e62c84 & 0xff) == 0x58) {
            *(undefined4 *)(puVar6 + -0x5c) = 0;
          }
          else {
            if (DAT_0079483c != f_0) {
              bVar11 = (_DAT_01e62c84 & 0xff) < 0x47;
              bVar12 = (_DAT_01e62c84 & 0xff) == 0x47;
              if (!bVar12) {
                _DAT_007d2ec0 = CONCAT31(DAT_007d2ec0_1,DAT_01e62c84);
                _DAT_007d2ea8 = f_0;
                iVar5 = 1;
                pbVar8 = &DAT_007d2ec0;
                pbVar10 = &DAT_0075fa58;
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar11 = *pbVar8 < *pbVar10;
                  bVar12 = *pbVar8 == *pbVar10;
                  pbVar8 = pbVar8 + 1;
                  pbVar10 = pbVar10 + 1;
                } while (bVar12);
                if (bVar11 || bVar12) {
                  DAT_007d2ea4 = (_DAT_01e62c84 & 0xff) - 0x30;
                  DAT_007d2ea0 = (_DAT_01e62c84 >> 8 & 0xff) - 0x30;
                  if ((-1 < DAT_007d2ea0) && (DAT_007d2ea0 < 10)) {
                    DAT_007d2ea4 = DAT_007d2ea4 * 10 + DAT_007d2ea0;
                  }
                  _DAT_007d2ea8 = (float)DAT_007d2ea4;
                  *(undefined4 *)(puVar6 + -0x50) = 0;
                }
                else {
                  *(undefined4 *)(puVar6 + -0x54) = 0;
                  *(undefined4 *)(puVar6 + -0x4c) = 10;
                  DAT_007d2eb0 = 1;
                  do {
                    if ((uint)*(byte *)(DAT_007d2eb0 + 0x78e92f) == (_DAT_01e62c84 & 0xff)) {
                      _DAT_007d2ea8 = *(float *)(DAT_007d2eb0 * 4 + 0x78e944);
                    }
                    DAT_007d2eb0 = DAT_007d2eb0 + 1;
                    *(int *)(puVar6 + -0x4c) = *(int *)(puVar6 + -0x4c) + -1;
                  } while (0 < *(int *)(puVar6 + -0x4c));
                  DAT_007d2ebc = _DAT_01e62c84;
                  *(undefined4 *)(puVar6 + -0x48) = 4;
                  DAT_007d2eb0 = 1;
                  do {
                    if ((ushort)(*(byte *)(DAT_007d2eb0 + 0x78e92b) + 0x2000) == _DAT_01e62c84) {
                      _DAT_007d2ea8 = *(float *)(s_WHQEST_0078e931 + DAT_007d2eb0 * 4 + 3);
                    }
                    DAT_007d2eb0 = DAT_007d2eb0 + 1;
                    *(int *)(puVar6 + -0x48) = *(int *)(puVar6 + -0x48) + -1;
                  } while (0 < *(int *)(puVar6 + -0x48));
                  if (_DAT_007d2ea8 != f_0) {
                    *(undefined4 *)(puVar6 + -0x44) = 0;
                  }
                }
                _DAT_007d2ea8 = _DAT_007d2ea8 / DAT_0079483c;
                FUN_005f33c9(puVar6,0x425340);
                FUN_005f34d1(puVar6,0x42535b);
                DAT_007d2e9c = 0;
                if (_DAT_007d2ea8 == f_0_5) {
                  _DAT_01e62c84 = i_538981678;
                  DAT_01e62c88 = i_538976288;
                  DAT_01e62c8c = i_538976288;
                }
                else {
                  fVar13 = (float10)FUN_005ff381(puVar6,0x4253ae);
                  *(int *)(puVar6 + -0x9c) = (int)ROUND(fVar13);
                  _DAT_007d2e98 = *(undefined4 *)(puVar6 + -0x9c);
                  *(undefined4 *)(puVar6 + -0x98) = 0;
                  *(undefined4 *)(puVar6 + -0xa8) = 0xc;
                  *(undefined1 **)(puVar6 + -0xa4) = &DAT_01e62c84;
                  *(undefined **)(puVar6 + -0xa0) = &DAT_007d2e98;
                  FUN_005f34f0(puVar6 + -0x98,0x784ff00,&DAT_0075f950,puVar6 + -0xa8,&DAT_0078e914);
                  if ((_DAT_01e62c84 & 0xff) == 0x20) {
                    FUN_005f33c9(puVar6,0x42544f);
                    FUN_005f34d1(puVar6,0x42546a);
                  }
                }
                DAT_007d2e94 = 0;
                *(undefined4 *)(puVar6 + -0x3c) = 0xb;
                DAT_007d2eb0 = 2;
                do {
                  cVar2 = (&DAT_020b909f)[DAT_007d2eb0];
                  _DAT_007d2ec0 = CONCAT31(DAT_007d2ec0_1,cVar2);
                  if (cVar2 == '.') {
                    DAT_007d2e94 = 1;
                  }
                  if (cVar2 == 'X') {
                    DAT_007d2e9c = DAT_007d2eb0;
                  }
                  if ((cVar2 == '/') || (cVar2 == ';')) {
                    *(undefined4 *)(puVar6 + -0x38) = 0;
                    break;
                  }
                  DAT_007d2eb0 = DAT_007d2eb0 + 1;
                  *(int *)(puVar6 + -0x3c) = *(int *)(puVar6 + -0x3c) + -1;
                } while (0 < *(int *)(puVar6 + -0x3c));
                FUN_005f33c9(puVar6,0x42553d);
                iVar5 = FUN_005ff950(puVar6 + -0xa8,0xc);
                DAT_007d2e90 = iVar5;
                if (DAT_007d2e94 != 0) {
                  DAT_007d2e90 = iVar5 + 1;
                  (&DAT_01e62c84)[iVar5] = 0x2e;
                }
                puVar1 = &DAT_01e62c84 + DAT_007d2e90;
                DAT_007d2e90 = DAT_007d2e90 + 1;
                *puVar1 = (char)_DAT_007d2ec0;
                if (DAT_007d2e9c != 0) {
                  FUN_005f46bc(puVar6,0x425602);
                  FUN_005f34d1(puVar6,0x425618);
                }
                goto LAB_00425625;
              }
            }
            *(undefined4 *)(puVar6 + -0x58) = 0;
          }
LAB_00425625:
          thunk_FUN_004c4148(&DAT_007cc600);
          DAT_00794830 = DAT_00794830 + 1;
          if ((_DAT_007d2ec4 & 0xff) == 0x5d) goto LAB_00425694;
          DAT_007d2eb4 = DAT_007d2eb4 + 1;
          for (iVar5 = 1; iVar5 < 0xd; iVar5 = iVar5 + 1) {
            *(undefined1 *)((int)&DAT_01e62c80 + iVar5 + 3) = 0x20;
          }
          *(undefined4 *)(puVar6 + -0x30) = 0;
        } while( true );
      }
      *(undefined4 *)(puVar6 + -0x68) = 0;
      *(undefined4 *)(puVar6 + -0x28) = 0x3c;
      DAT_007d2ea4 = 0x3c;
      do {
        if (*(char *)((int)&DAT_007cb2cc + DAT_007d2ea4 + 3) == ']') {
          *(undefined4 *)(puVar6 + -0x24) = 0;
          break;
        }
        DAT_007d2ea4 = DAT_007d2ea4 + -1;
        *(int *)(puVar6 + -0x28) = *(int *)(puVar6 + -0x28) + -1;
      } while (0 < *(int *)(puVar6 + -0x28));
      DAT_007d2eb0 = DAT_007d2ea4;
      iVar5 = -DAT_007d2ea4 / -1;
      *(int *)(puVar6 + -0x20) = iVar5;
      while (0 < iVar5) {
        if ((*(char *)((int)&DAT_007cb2cc + DAT_007d2eb0 + 3) == '/') ||
           (*(char *)((int)&DAT_007cb2cc + DAT_007d2eb0 + 3) == '[')) {
          for (iVar5 = 1; iVar5 < 0xd; iVar5 = iVar5 + 1) {
            *(undefined1 *)((int)&DAT_01e62c80 + iVar5 + 3) = 0x20;
          }
          DAT_007d2ea0 = DAT_007d2eb0 + 1;
          DAT_007d2e90 = 0;
          iVar5 = 0x3d - DAT_007d2ea0;
          DAT_007d2eb4 = DAT_007d2ea0;
          *(int *)(puVar6 + -0x18) = iVar5;
          iVar3 = DAT_007d2e90;
          while (DAT_007d2e90 = iVar3, 0 < iVar5) {
            DAT_007d2e90 = iVar3 + 1;
            cVar2 = *(char *)((int)&DAT_007cb2cc + DAT_007d2ea0 + 3);
            DAT_007d2ec4_1 = (undefined3)(_DAT_007d2ec4 >> 8);
            if (cVar2 == ']') {
              cVar2 = DAT_0075fa5c;
            }
            _DAT_007d2ec4 = CONCAT31(DAT_007d2ec4_1,cVar2);
            (&DAT_01e62c84)[iVar3] = cVar2;
            if (((_DAT_007d2ec4 & 0xff) == 0x2f) || ((_DAT_007d2ec4 & 0xff) == 0x3a)) {
              DAT_020b90a0 = DAT_007d2ec4;
              thunk_FUN_004c4148(&DAT_007cc600);
              if ((_DAT_007d2ec4 & 0xff) != 0x3a) {
                *(undefined4 *)(puVar6 + -0x10) = 0;
                break;
              }
              DAT_007d2e90 = 0;
              for (iVar5 = 1; iVar5 < 0xd; iVar5 = iVar5 + 1) {
                *(undefined1 *)((int)&DAT_01e62c80 + iVar5 + 3) = 0x20;
              }
            }
            else {
              *(undefined4 *)(puVar6 + -0x14) = 0;
            }
            *(undefined4 *)(puVar6 + -0xc) = 0;
            DAT_007d2ea0 = DAT_007d2ea0 + 1;
            *(int *)(puVar6 + -0x18) = *(int *)(puVar6 + -0x18) + -1;
            iVar3 = DAT_007d2e90;
            iVar5 = *(int *)(puVar6 + -0x18);
          }
        }
        else {
          *(undefined4 *)(puVar6 + -0x1c) = 0;
        }
        *(undefined4 *)(puVar6 + -8) = 0;
        DAT_007d2eb0 = DAT_007d2eb0 + -1;
        *(int *)(puVar6 + -0x20) = *(int *)(puVar6 + -0x20) + -1;
        iVar5 = *(int *)(puVar6 + -0x20);
      }
      *(undefined4 *)(puVar6 + -4) = 0;
      goto LAB_0042569b;
    }
  }
  FUN_005f33c9(puVar6,0x4256db);
  FUN_005f34d1(puVar6,0x4256f6);
  DAT_020b90b0 = DAT_007d2ec4;
  thunk_FUN_0054d831(&DAT_020b90a0,0x200);
  return;
LAB_00425694:
  *(undefined4 *)(puVar6 + -0x34) = 0;
LAB_0042569b:
  *(undefined4 *)(puVar6 + -0x2c) = 0;
  DAT_00794830 = DAT_00794830 + -1;
  DAT_007cb2cc = 0;
  return;
}


