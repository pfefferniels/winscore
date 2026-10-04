// FUN_004e620c @ 004e620c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004e6a3f) */
/* WARNING: Removing unreachable block (ram,0x004e69ba) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e620c(void)

{
  undefined1 *puVar1;
  float fVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int iVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  bool bVar14;
  bool bVar15;
  undefined2 in_FPUControlWord;
  float10 fVar16;
  
  puVar8 = &stack0xfffffffc;
  puVar10 = (undefined4 *)&DAT_020b8ea0;
  puVar13 = (undefined4 *)&DAT_020b90a0;
  for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar13 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar13 = puVar13 + 1;
  }
  DAT_008d0db4 = 1;
  DAT_008d0db0 = 0;
  DAT_008d0dac = 1;
  DAT_008d0da8 = 1;
  do {
    while( true ) {
      cVar4 = (&DAT_020b909f)[DAT_008d0db4];
      _DAT_008d0db8 = CONCAT31(DAT_008d0db8_1,cVar4);
      if (cVar4 == '@') {
        DAT_008d0db0 = DAT_008d0db4 + 1;
      }
      if ((cVar4 == '/') || (cVar4 == ';')) break;
      *(undefined4 *)(puVar8 + -0x98) = 0;
LAB_004e6d56:
      DAT_008d0db4 = DAT_008d0db4 + 1;
      if (**(int **)(puVar8 + 8) < DAT_008d0db4) {
LAB_004e6d85:
        *(undefined4 *)(puVar8 + -0xb8) = 0;
        FUN_005f7950(puVar8 + -0xb8,0xb,0x784ff00,&DAT_00765f50,0);
        thunk_FUN_0042ac4e(&DAT_008d0dc0,0xd);
        FUN_005f33c9(puVar8,0x4e6de4);
        FUN_005f34d1(puVar8,0x4e6dff);
        return;
      }
      *(undefined4 *)(puVar8 + -8) = 0;
    }
    if (DAT_008d0db0 == 0) {
      DAT_008d0da4 = (DAT_008d0db4 + DAT_008d0dac) - DAT_008d0da8;
      iVar7 = DAT_008d0db4 - (DAT_008d0da8 + -1);
      if (iVar7 < 0) {
        iVar7 = 0;
      }
      *(int *)(puVar8 + -0xbc) = iVar7;
      FUN_005f46bc(puVar8,0x4e6cfd);
      FUN_005f34d1(puVar8,0x4e6d13);
      DAT_008d0dac = DAT_008d0da4 + 1;
      DAT_008d0da8 = DAT_008d0db4 + 1;
      if ((_DAT_008d0db8 & 0xff) != 0x3b) {
        *(undefined4 *)(puVar8 + -0x90) = 0;
        goto LAB_004e6d56;
      }
      DAT_008d0da0 = DAT_008d0da4;
      *(undefined4 *)(puVar8 + -0x8c) = 0;
LAB_004e6e1b:
      puVar10 = &DAT_009ae2bc;
      puVar13 = (undefined4 *)&DAT_020b8ea0;
      for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar13 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar13 = puVar13 + 1;
      }
      **(int **)(puVar8 + 8) = DAT_008d0da0;
      *(undefined4 *)(puVar8 + -0x20) = 0;
      return;
    }
    *(undefined4 *)(puVar8 + -0x94) = 0;
    DAT_008d0d9c = DAT_008d0db4;
    DAT_008d0da8 = DAT_008d0db4 + 1;
    DAT_008d0d98 = 0;
    iVar7 = (DAT_008d0db4 - DAT_008d0db0) + 1;
    *(int *)(puVar8 + -0x88) = iVar7;
    **(int **)(puVar8 + 0xc) = DAT_008d0db0;
    while (0 < iVar7) {
      bVar15 = iVar7 == 0;
      bVar14 = false;
      DAT_008d0db8_1 = (undefined3)(_DAT_008d0db8 >> 8);
      _DAT_008d0db8 = CONCAT31(DAT_008d0db8_1,(&DAT_020b909f)[**(int **)(puVar8 + 0xc)]);
      iVar7 = 1;
      pbVar9 = &DAT_008d0db8;
      pbVar12 = &DAT_00765fb8;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar14 = *pbVar9 < *pbVar12;
        bVar15 = *pbVar9 == *pbVar12;
        pbVar9 = pbVar9 + 1;
        pbVar12 = pbVar12 + 1;
      } while (bVar15);
      if (!bVar14) {
        iVar7 = 1;
        pbVar9 = &DAT_008d0db8;
        pbVar12 = &DAT_00765fb4;
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar14 = *pbVar9 < *pbVar12;
          bVar15 = *pbVar9 == *pbVar12;
          pbVar9 = pbVar9 + 1;
          pbVar12 = pbVar12 + 1;
        } while (bVar15);
        if (bVar14 || bVar15) {
          iVar7 = **(int **)(puVar8 + 0xc);
          iVar11 = (DAT_008d0d9c - (iVar7 + -1)) + -1;
          if (iVar11 < 0) {
            iVar11 = 0;
          }
          *(undefined4 *)(puVar8 + -0xb8) = 0;
          *(int *)(puVar8 + -200) = iVar11;
          *(undefined1 **)(puVar8 + -0xc4) = &DAT_020b909f + iVar7;
          *(int **)(puVar8 + -0xc0) = &DAT_008d0d98;
          FUN_005f9240(puVar8 + -0xb8,0x784ff00,&DAT_00765ff0,puVar8 + -200,&DAT_00794a9c);
          *(undefined4 *)(puVar8 + -0x7c) = 0;
          break;
        }
      }
      *(undefined4 *)(puVar8 + -0x84) = 0;
      *(undefined4 *)(puVar8 + -0x78) = 0;
      **(int **)(puVar8 + 0xc) = **(int **)(puVar8 + 0xc) + 1;
      *(int *)(puVar8 + -0x88) = *(int *)(puVar8 + -0x88) + -1;
      iVar7 = *(int *)(puVar8 + -0x88);
    }
    *(int *)(puVar8 + -0xbc) = DAT_01fbb700 * 4;
    FUN_005f33c9(puVar8,0x4e6436);
    FUN_005f33c9(puVar8,0x4e6452);
    FUN_005f33c9(puVar8,0x4e6474);
    FUN_005f34d1(puVar8,0x4e648f);
    DAT_008d0db0 = 0;
    *(undefined4 *)(puVar8 + -0xb8) = 0;
    *(undefined4 *)(puVar8 + -0xd0) = 0xd;
    *(undefined4 **)(puVar8 + -0xcc) = &DAT_008d0dc0;
    *(undefined4 *)(puVar8 + -200) = 3;
    *(undefined **)(puVar8 + -0xc4) = &DAT_00765f74;
    *(undefined4 *)(puVar8 + -0xc0) = 2;
    uVar6 = FUN_005f6540(puVar8 + -0xb8,0xb,0x784ff01,&DAT_00765f8c,puVar8 + -0xd0);
    *(undefined4 *)(puVar8 + -0x74) = uVar6;
    if (*(int *)(puVar8 + -0x74) != 0) goto LAB_004e6d85;
    DAT_008d0dc0._0_1_ = s__error_reading_00765fd7[1];
    DAT_008d0dc0._1_1_ = s__error_reading_00765fd7[2];
    DAT_008d0dc0._2_1_ = s__error_reading_00765fd7[3];
    DAT_008d0dc0._3_1_ = s__error_reading_00765fd7[4];
    DAT_008d0dc4._0_1_ = s__error_reading_00765fd7[5];
    DAT_008d0dc4._1_1_ = s__error_reading_00765fd7[6];
    DAT_008d0dc4._2_1_ = s__error_reading_00765fd7[7];
    DAT_008d0dc4._3_1_ = s__error_reading_00765fd7[8];
    DAT_008d0dc8._0_1_ = s__error_reading_00765fd7[9];
    DAT_008d0dc8._1_1_ = s__error_reading_00765fd7[10];
    DAT_008d0dc8._2_1_ = s__error_reading_00765fd7[0xb];
    DAT_008d0dc8._3_1_ = s__error_reading_00765fd7[0xc];
    DAT_008d0dcc = s__error_reading_00765fd7[0xd];
    *(undefined4 *)(puVar8 + -0xb8) = 0;
    *(undefined4 *)(puVar8 + -0xc0) = 0x100;
    *(undefined1 **)(puVar8 + -0xbc) = &DAT_007cb2d0;
    uVar6 = FUN_005fdbd0(puVar8 + -0xb8,0xb,0x784ff01,&DAT_00765f70,puVar8 + -0xc0,&DAT_00794ab0);
    *(undefined4 *)(puVar8 + -0x70) = uVar6;
    if (*(int *)(puVar8 + -0x70) != 0) goto LAB_004e6d85;
    *(undefined4 *)(puVar8 + -0xb8) = 0;
    FUN_005f7950(puVar8 + -0xb8,0xb,0x784ff00,&DAT_00765f50,0);
    thunk_FUN_0054c83c(&DAT_007cb2d0,1,&DAT_00765f6c);
    FUN_005f33c9(puVar8,0x4e6605);
    FUN_005f34d1(puVar8,0x4e6620);
    *(undefined4 *)(puVar8 + -0x68) = 0x100;
    DAT_008d0d94 = 1;
    while( true ) {
      if (((&DAT_020b8e9f)[DAT_008d0d94] == ':') || ((&DAT_020b8e9f)[DAT_008d0d94] == '\'')) {
        (&DAT_020b8e9f)[DAT_008d0d94] = 0x20;
      }
      if ((&DAT_020b8e9f)[DAT_008d0d94] == ']') break;
      *(undefined4 *)(puVar8 + -100) = 0;
      *(undefined4 *)(puVar8 + -0x10) = 0;
      DAT_008d0d94 = DAT_008d0d94 + 1;
      *(int *)(puVar8 + -0x68) = *(int *)(puVar8 + -0x68) + -1;
      if (*(int *)(puVar8 + -0x68) < 1) {
        *(undefined4 *)(puVar8 + -0xc) = 0;
        goto LAB_004e6d85;
      }
    }
    (&DAT_020b8e9f)[DAT_008d0d94] = (&DAT_020b909f)[DAT_008d0d9c];
    if (DAT_008d0d98 == 0) {
      DAT_008d0da0 = DAT_008d0d94;
      *(undefined4 *)(puVar8 + -0x5c) = 0;
    }
    else {
      *(undefined4 *)(puVar8 + -0x60) = 0;
      thunk_FUN_00518b3f(&DAT_008d0d94);
      DAT_008d0d90 = 99;
      *(undefined4 *)(puVar8 + -0x58) = 0x2d;
      DAT_008d0d8c = 1;
      do {
        if ((*(float *)(&P0 + DAT_008d0d8c * 4) != f_0) &&
           (*(float *)(&P0 + DAT_008d0d8c * 4) < (float)DAT_008d0d90)) {
          fVar2 = *(float *)(&P0 + DAT_008d0d8c * 4);
          *(undefined2 *)(puVar8 + -0xc0) = in_FPUControlWord;
          *(ushort *)(puVar8 + -0xbe) = (ushort)*(undefined4 *)(puVar8 + -0xc0) | 0xc00;
          *(int *)(puVar8 + -0xbc) = (int)ROUND(fVar2);
          in_FPUControlWord = *(undefined2 *)(puVar8 + -0xc0);
          DAT_008d0d90 = *(int *)(puVar8 + -0xbc);
        }
        DAT_008d0d8c = DAT_008d0d8c + 1;
        *(int *)(puVar8 + -0x58) = *(int *)(puVar8 + -0x58) + -1;
      } while (0 < *(int *)(puVar8 + -0x58));
      *(int *)(puVar8 + -0xbc) = DAT_008d0d98 - DAT_008d0d90;
      _DAT_008d0d88 = (float)*(int *)(puVar8 + -0xbc);
      DAT_008d0d84 = 0;
      *(undefined4 *)(puVar8 + -0x54) = 0x2d;
      DAT_008d0d8c = 1;
      do {
        if (*(float *)(&P0 + DAT_008d0d8c * 4) == f_0) {
          *(undefined4 *)(puVar8 + -0x50) = 0;
        }
        else {
          DAT_008d0d84 = DAT_008d0d84 + 1;
          *(float *)(&P0 + DAT_008d0d84 * 4) = _DAT_008d0d88 + *(float *)(&P0 + DAT_008d0d8c * 4);
        }
        *(undefined4 *)(puVar8 + -0x4c) = 0;
        DAT_008d0d8c = DAT_008d0d8c + 1;
        *(int *)(puVar8 + -0x54) = *(int *)(puVar8 + -0x54) + -1;
      } while (0 < *(int *)(puVar8 + -0x54));
      DAT_008d0d90 = 0;
      DAT_008d0da0 = 0;
      DAT_008d0dbc = 3;
LAB_004e6880:
      bVar5 = *(byte *)((int)&DAT_007cb2cc + DAT_008d0dbc + 3);
      _DAT_008d0db8 = CONCAT31(DAT_008d0db8_1,bVar5);
      if (bVar5 != 0x5d) {
        bVar14 = bVar5 < 0x2e;
        if (bVar5 == 0x2e) {
          *(undefined4 *)(puVar8 + -0x44) = 0;
LAB_004e68f4:
          DAT_008d0da0 = DAT_008d0da0 + 1;
          DAT_008d0d90 = DAT_008d0d90 + 1;
          *(undefined4 *)(puVar8 + -0xc0) = *(undefined4 *)(&P0 + DAT_008d0d90 * 4);
          fVar16 = (float10)FUN_005ff874(puVar8 + -0xc0,&DAT_00765fd4);
          if (fVar16 == (float10)f_0) {
            *(undefined4 *)(puVar8 + -0x3c) = 0;
            fVar2 = *(float *)(&P0 + DAT_008d0d90 * 4);
            *(undefined2 *)(puVar8 + -0xc0) = in_FPUControlWord;
            *(ushort *)(puVar8 + -0xbe) = (ushort)*(undefined4 *)(puVar8 + -0xc0) | 0xc00;
            *(int *)(puVar8 + -0xbc) = (int)ROUND(fVar2);
            in_FPUControlWord = *(undefined2 *)(puVar8 + -0xc0);
            _DAT_008d0d80 = *(undefined4 *)(puVar8 + -0xbc);
            *(undefined4 *)(puVar8 + -0xb8) = 0;
            *(undefined4 *)(puVar8 + -200) = 2;
            *(undefined1 **)(puVar8 + -0xc4) = &DAT_020b8e9f + DAT_008d0da0;
            *(undefined **)(puVar8 + -0xc0) = &DAT_008d0d80;
            FUN_005f34f0(puVar8 + -0xb8,0x784ff00,&DAT_00765ff0,puVar8 + -200,&DAT_00794ad8);
            DAT_008d0da0 = DAT_008d0da0 + 1;
          }
          else {
            *(undefined4 *)(puVar8 + -0xb8) = 0;
            *(undefined4 *)(puVar8 + -200) = 6;
            *(undefined1 **)(puVar8 + -0xc4) = &DAT_020b8e9f + DAT_008d0da0;
            *(undefined4 *)(puVar8 + -0xc0) = 4;
            *(undefined **)(puVar8 + -0xbc) = &P0 + DAT_008d0d90 * 4;
            FUN_005f34f0(puVar8 + -0xb8,0x784ff00,&DAT_00765fcc,puVar8 + -200,&DAT_00794ac4);
            DAT_008d0da0 = DAT_008d0da0 + 4;
            *(undefined4 *)(puVar8 + -0x34) = 0;
          }
          do {
            bVar5 = (&DAT_007cb2d0)[DAT_008d0dbc];
            _DAT_008d0db8 = CONCAT31(DAT_008d0db8_1,bVar5);
            bVar14 = bVar5 < 0x2e;
            if (bVar5 != 0x2e) {
              iVar7 = 1;
              pbVar9 = &DAT_008d0db8;
              pbVar12 = &DAT_00765fb8;
              do {
                if (iVar7 == 0) break;
                iVar7 = iVar7 + -1;
                bVar3 = *pbVar12;
                bVar5 = *pbVar9;
                bVar14 = bVar5 < bVar3;
                pbVar9 = pbVar9 + 1;
                pbVar12 = pbVar12 + 1;
              } while (bVar5 == bVar3);
              bVar15 = !bVar14 != 0;
              iVar7 = -(uint)!bVar14;
              bVar14 = iVar7 == 0;
              *(int *)(puVar8 + -0xbc) = iVar7;
              iVar7 = 1;
              pbVar9 = &DAT_008d0db8;
              pbVar12 = &DAT_00765fb4;
              do {
                if (iVar7 == 0) break;
                iVar7 = iVar7 + -1;
                bVar15 = *pbVar9 < *pbVar12;
                bVar14 = *pbVar9 == *pbVar12;
                pbVar9 = pbVar9 + 1;
                pbVar12 = pbVar12 + 1;
              } while (bVar14);
              if ((-(uint)(bVar15 || bVar14) & *(uint *)(puVar8 + -0xbc) & 1) == 0)
              goto LAB_004e6b44;
            }
            DAT_008d0dbc = DAT_008d0dbc + 1;
            *(undefined4 *)(puVar8 + -0x2c) = 0;
          } while( true );
        }
        iVar7 = 1;
        bVar15 = false;
        pbVar9 = &DAT_008d0db8;
        pbVar12 = &DAT_00765fb8;
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar14 = *pbVar9 < *pbVar12;
          bVar15 = *pbVar9 == *pbVar12;
          pbVar9 = pbVar9 + 1;
          pbVar12 = pbVar12 + 1;
        } while (bVar15);
        if (!bVar14) {
          iVar7 = 1;
          pbVar9 = &DAT_008d0db8;
          pbVar12 = &DAT_00765fb4;
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar14 = *pbVar9 < *pbVar12;
            bVar15 = *pbVar9 == *pbVar12;
            pbVar9 = pbVar9 + 1;
            pbVar12 = pbVar12 + 1;
          } while (bVar15);
          if (bVar14 || bVar15) goto LAB_004e68f4;
        }
        *(undefined4 *)(puVar8 + -0x40) = 0;
        pbVar9 = (byte *)((int)&DAT_020b8ea0 + DAT_008d0da0);
        DAT_008d0da0 = DAT_008d0da0 + 1;
        *pbVar9 = bVar5;
        goto LAB_004e6b77;
      }
      *(undefined4 *)(puVar8 + -0x48) = 0;
      puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_008d0da0);
      DAT_008d0da0 = DAT_008d0da0 + 1;
      *puVar1 = (&DAT_020b909f)[DAT_008d0d9c];
    }
    iVar7 = DAT_008d0da0;
    if (DAT_008d0da0 < 0) {
      iVar7 = 0;
    }
    *(int *)(puVar8 + -0xbc) = iVar7;
    FUN_005f46bc(puVar8,0x4e6c29);
    FUN_005f34d1(puVar8,0x4e6c3f);
    DAT_008d0dac = DAT_008d0da0 + DAT_008d0dac;
    if ((&DAT_020b8e9f)[DAT_008d0da0] == ';') goto LAB_004e6e1b;
    DAT_008d0db4 = DAT_008d0db4 + 1;
    *(undefined4 *)(puVar8 + -0x1c) = 0;
  } while( true );
LAB_004e6b44:
  *(undefined4 *)(puVar8 + -0x28) = 0;
LAB_004e6b77:
  DAT_008d0dbc = DAT_008d0dbc + 1;
  *(undefined4 *)(puVar8 + -0x24) = 0;
  goto LAB_004e6880;
}


