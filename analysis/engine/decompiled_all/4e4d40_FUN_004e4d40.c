// FUN_004e4d40 @ 004e4d40 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004e523d) */
/* WARNING: Removing unreachable block (ram,0x004e5310) */
/* WARNING: Removing unreachable block (ram,0x004e5386) */
/* WARNING: Removing unreachable block (ram,0x004e53a4) */
/* WARNING: Removing unreachable block (ram,0x004e54ab) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e4d40(void)

{
  float fVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  uint uVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  undefined2 in_FPUControlWord;
  
  puVar6 = &stack0xfffffffc;
  _DAT_008d092c = 0;
  puVar7 = (undefined4 *)&DAT_020b8ea0;
  puVar10 = (undefined4 *)&DAT_020b90a0;
  for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar10 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar10 = puVar10 + 1;
  }
  DAT_008d0928 = 0;
  DAT_008d0924 = 0;
LAB_004e4d77:
  uVar9 = DAT_008d0928 + 1;
  if ((&DAT_020b90a0)[DAT_008d0928] == ';') {
    *(undefined4 *)(puVar6 + -0x7c) = 0;
    DAT_008d0928 = uVar9;
    return;
  }
  if ((&DAT_020b90a0)[DAT_008d0928] == 'X') {
    *(undefined4 *)(puVar6 + -0x74) = 0;
    *(undefined4 *)(puVar6 + -0x34) = 0x200;
    DAT_008d0920 = 1;
    do {
      if ((&DAT_020b8e9f)[DAT_008d0920] == 'X') {
        *(undefined4 *)(puVar6 + -0x30) = 0;
        break;
      }
      DAT_008d0920 = DAT_008d0920 + 1;
      *(int *)(puVar6 + -0x34) = *(int *)(puVar6 + -0x34) + -1;
    } while (0 < *(int *)(puVar6 + -0x34));
    DAT_008d0914 = (char)(&DAT_020b90a1)[DAT_008d0928] + -0x31;
    DAT_008d0928 = DAT_008d0928 + 4;
    DAT_008d090c = 0;
    puVar7 = (undefined4 *)&DAT_020b8ea0;
    puVar10 = &DAT_01e99980;
    DAT_008d0910 = uVar9;
    DAT_008d0924 = uVar9;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    FUN_005f34d1(puVar6,0x4e4e87);
    iVar5 = 0x201 - DAT_008d0928;
    *(int *)(puVar6 + -0x2c) = iVar5;
    DAT_008d0908 = DAT_008d0928;
    iVar4 = DAT_008d090c;
    while (0 < iVar5) {
      DAT_008d090c = iVar4 + 1;
      *(undefined1 *)((int)&DAT_020b8ea0 + iVar4) = (&DAT_020b909f)[DAT_008d0908];
      if (((&DAT_020b909f)[DAT_008d0908] == '/') || ((&DAT_020b909f)[DAT_008d0908] == ';')) {
        *(undefined4 *)(puVar6 + -0x28) = 0;
        goto LAB_004e4f2a;
      }
      DAT_008d0908 = DAT_008d0908 + 1;
      *(int *)(puVar6 + -0x2c) = *(int *)(puVar6 + -0x2c) + -1;
      iVar4 = DAT_008d090c;
      iVar5 = *(int *)(puVar6 + -0x2c);
    }
    *(undefined4 *)(puVar6 + -0x24) = 0;
    DAT_008d090c = iVar4;
LAB_004e4f2a:
    DAT_008d0904 = DAT_02052740;
    DAT_02052740 = 0;
    DAT_008d0900 = DAT_008d0908;
    puVar7 = (undefined4 *)&DAT_020b90a0;
    puVar10 = &DAT_009ae2bc;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    thunk_FUN_00518448();
    DAT_02052740 = DAT_008d0904;
    puVar7 = &DAT_009ae2bc;
    puVar10 = (undefined4 *)&DAT_020b90a0;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    puVar7 = &DAT_01e99980;
    puVar10 = (undefined4 *)&DAT_020b8ea0;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    DAT_008d090c = 0;
    DAT_008d0924 = 0;
    while (DAT_008d0924 = DAT_008d0924 + 1, *(float *)(&P0 + DAT_008d0924 * 4) != f_0) {
      DAT_008d090c = DAT_008d090c + 1;
      fVar1 = *(float *)(&P0 + DAT_008d0924 * 4);
      *(undefined2 *)(puVar6 + -0xa4) = in_FPUControlWord;
      *(ushort *)(puVar6 + -0xa2) = (ushort)*(undefined4 *)(puVar6 + -0xa4) | 0xc00;
      *(int *)(puVar6 + -0xa0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar6 + -0xa4);
      *(undefined4 *)(&IP0 + DAT_008d090c * 4) = *(undefined4 *)(puVar6 + -0xa0);
      DAT_008d090c = DAT_008d090c + 1;
      *(int *)(&IP0 + DAT_008d090c * 4) = *(int *)(DAT_008d090c * 4 + 0x2091c38) + DAT_008d0914;
      *(undefined4 *)(puVar6 + -0x1c) = 0;
    }
    *(undefined4 *)(puVar6 + -0x20) = 0;
    *(undefined4 *)(puVar6 + -0x18) = 0;
    bVar12 = 0xfffffffc < DAT_008d0910;
    uVar9 = DAT_008d0910 + 3;
    DAT_008d08fc = uVar9;
    do {
      bVar13 = uVar9 == 0;
      iVar5 = 1;
      pbVar8 = &DAT_020b909f + DAT_008d08fc;
      pbVar11 = &DAT_00765f20;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar12 = *pbVar8 < *pbVar11;
        bVar13 = *pbVar8 == *pbVar11;
        pbVar8 = pbVar8 + 1;
        pbVar11 = pbVar11 + 1;
      } while (bVar13);
      if (bVar12) {
LAB_004e5443:
        *(undefined4 *)(puVar6 + -0x14) = 0;
      }
      else {
        iVar5 = 1;
        bVar12 = false;
        pbVar8 = &DAT_020b909f + DAT_008d08fc;
        pbVar11 = &DAT_00765f1c;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar12 = *pbVar8 < *pbVar11;
          bVar13 = *pbVar8 == *pbVar11;
          pbVar8 = pbVar8 + 1;
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (!bVar12 && !bVar13) goto LAB_004e5443;
        DAT_008d08f8 = 1;
        DAT_008d08e8 = (&DAT_020b909f)[DAT_008d08fc];
        DAT_008d08e9 = (&DAT_020b90a0)[DAT_008d08fc];
        DAT_008d08ea = (&DAT_020b90a1)[DAT_008d08fc];
        iVar5 = 1;
        pbVar8 = &DAT_008d08e9;
        pbVar11 = &DAT_00765f20;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar12 = *pbVar8 < *pbVar11;
          bVar13 = *pbVar8 == *pbVar11;
          pbVar8 = pbVar8 + 1;
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (bVar12) {
LAB_004e5141:
          DAT_008d08e9 = 0x20;
        }
        else {
          iVar5 = 1;
          bVar12 = false;
          pbVar8 = &DAT_008d08e9;
          pbVar11 = &DAT_00765f1c;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar12 = *pbVar8 < *pbVar11;
            bVar13 = *pbVar8 == *pbVar11;
            pbVar8 = pbVar8 + 1;
            pbVar11 = pbVar11 + 1;
          } while (bVar13);
          if (!bVar12 && !bVar13) goto LAB_004e5141;
        }
        bVar12 = DAT_008d08e9 < 0x20;
        bVar13 = DAT_008d08e9 == 0x20;
        if (!bVar13) {
          DAT_008d08f8 = 2;
        }
        iVar5 = 1;
        pbVar8 = (byte *)&DAT_008d08ea;
        pbVar11 = &DAT_00765f1c;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar12 = *pbVar8 < *pbVar11;
          bVar13 = *pbVar8 == *pbVar11;
          pbVar8 = pbVar8 + 1;
          pbVar11 = pbVar11 + 1;
        } while (bVar13);
        if (bVar12 || bVar13) {
          iVar5 = 1;
          pbVar8 = (byte *)&DAT_008d08ea;
          pbVar11 = &DAT_00765f20;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar3 = *pbVar11;
            bVar2 = *pbVar8;
            bVar12 = bVar2 < bVar3;
            pbVar8 = pbVar8 + 1;
            pbVar11 = pbVar11 + 1;
          } while (bVar2 == bVar3);
          if ((bVar12) || (DAT_008d08e9 == 0x20)) goto LAB_004e519f;
        }
        else {
LAB_004e519f:
          DAT_008d08ea = DAT_00765f18;
        }
        if (DAT_008d08ea != ' ') {
          DAT_008d08f8 = 3;
        }
        *(undefined4 *)(puVar6 + -0x9c) = 0;
        *(undefined4 *)(puVar6 + -0xb0) = 3;
        *(undefined1 **)(puVar6 + -0xac) = &DAT_008d08e8;
        *(int **)(puVar6 + -0xa8) = &DAT_008d08f4;
        FUN_005f9240(puVar6 + -0x9c,0x784ff00,&DAT_00765f10,puVar6 + -0xb0,&DAT_007949d4);
        FUN_005f46bc(puVar6,0x4e5261);
        FUN_005f34d1(puVar6,0x4e5277);
        DAT_008d0920 = DAT_008d08f8 + DAT_008d0920;
        (&DAT_020b8e9f)[DAT_008d0920] = 0x20;
        DAT_008d08f0 = DAT_008d08f8;
        DAT_008d08f4 = DAT_008d0914 + DAT_008d08f4;
        if (9 < DAT_008d08f4) {
          DAT_008d08f8 = 2;
        }
        if (99 < DAT_008d08f4) {
          DAT_008d08f8 = 3;
        }
        *(undefined4 *)(puVar6 + -0x9c) = 0;
        *(undefined4 *)(puVar6 + -0xb0) = 3;
        *(int *)(puVar6 + -0xac) = (int)&DAT_020b8ea0 + DAT_008d0920;
        *(int **)(puVar6 + -0xa8) = &DAT_008d08f4;
        DAT_008d0920 = DAT_008d0920 + 1;
        FUN_005f34f0(puVar6 + -0x9c,0x784ff00,&DAT_00765f10,puVar6 + -0xb0,&DAT_007949e8);
        if (DAT_008d08f8 == 2) {
          FUN_005f46bc(puVar6,0x4e53c3);
          FUN_005f34d1(puVar6,0x4e53d9);
        }
        if (DAT_008d08f8 == 1) {
          (&DAT_020b8e9f)[DAT_008d0920] = *(undefined1 *)((int)&DAT_020b8ea0 + DAT_008d0920 + 1);
        }
        (&DAT_020b8e9f)[DAT_008d08f8 + DAT_008d0920] = 0x2f;
        DAT_008d0920 = DAT_008d08f8 + DAT_008d0920 + 1;
        DAT_008d08fc = DAT_008d08f0 + DAT_008d08fc;
      }
      DAT_008d08fc = DAT_008d08fc + 1;
      bVar12 = DAT_008d08fc < DAT_008d0900;
      uVar9 = DAT_008d08fc - DAT_008d0900;
      if ((int)DAT_008d0900 <= (int)DAT_008d08fc) goto LAB_004e54ad;
      *(undefined4 *)(puVar6 + -8) = 0;
    } while( true );
  }
  *(undefined4 *)(puVar6 + -0x78) = 0;
  DAT_008d0928 = uVar9;
  goto LAB_004e54f4;
LAB_004e54ad:
  FUN_005f46bc(puVar6,0x4e54ce);
  FUN_005f34d1(puVar6,0x4e54e4);
  DAT_008d0928 = DAT_008d0900;
LAB_004e54f4:
  if (**(int **)(puVar6 + 8) <= (int)DAT_008d0928) {
    **(int **)(puVar6 + 8) = DAT_008d0920 + -1;
    (&DAT_020b8e9f)[**(int **)(puVar6 + 8)] = 0x3b;
    return;
  }
  *(undefined4 *)(puVar6 + -4) = 0;
  goto LAB_004e4d77;
}


