// FUN_0044f600 @ 0044f600 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0044f81d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044f600(undefined4 param_1,undefined4 param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined2 in_FPUControlWord;
  
  puVar6 = &stack0xfffffffc;
  puVar7 = &stack0xfffffffc;
  if (DAT_020b8ea0 != 0x4d53) {
    FUN_005f33c9(&stack0xfffffffc,0x44f64a);
    FUN_005f34d1(puVar6,0x44f665);
    *(undefined4 *)(puVar6 + -0x7c) = 10;
    DAT_007fe688 = 1;
    do {
      FUN_005f34d1(puVar6,0x44f69f);
      DAT_007fe688 = DAT_007fe688 + 1;
      *(int *)(puVar6 + -0x7c) = *(int *)(puVar6 + -0x7c) + -1;
    } while (0 < *(int *)(puVar6 + -0x7c));
    thunk_FUN_00571f5d("Type Drawing number and name.",0x1e);
    if ((char)DAT_020b8ea0 == '\x02') {
      *(undefined4 *)(puVar6 + -0x78) = 0;
      return;
    }
    iVar3 = FUN_005f4660(0x20);
    if (iVar3 != 0) {
      FUN_005f33c9(puVar6,0x44f72c);
      FUN_005f34d1(puVar6,0x44f747);
      *(undefined4 *)(puVar6 + -0x74) = 0;
      return;
    }
    *(undefined4 *)(puVar6 + -0x70) = 0x17;
    DAT_007fe688 = 2;
    do {
      bVar12 = false;
      iVar3 = 1;
      pbVar8 = &DAT_020b8e9f + DAT_007fe688;
      pbVar10 = &DAT_00761038;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar2 = *pbVar10;
        bVar1 = *pbVar8;
        bVar12 = bVar1 < bVar2;
        pbVar8 = pbVar8 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar1 == bVar2);
      if (bVar12) {
        *(undefined4 *)(puVar6 + -0x6c) = 0;
        break;
      }
      DAT_007fe688 = DAT_007fe688 + 1;
      *(int *)(puVar6 + -0x70) = *(int *)(puVar6 + -0x70) + -1;
    } while (0 < *(int *)(puVar6 + -0x70));
    do {
      uVar5 = DAT_007fe688 + 1;
      bVar12 = uVar5 < 0x18;
      if (0x17 < (int)uVar5) goto LAB_0044f7f7;
      *(undefined4 *)(puVar6 + -0x68) = 0;
      iVar3 = 1;
      pbVar8 = (byte *)((int)&DAT_020b8ea0 + DAT_007fe688);
      pbVar10 = &DAT_00761038;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar2 = *pbVar10;
        bVar1 = *pbVar8;
        bVar12 = bVar1 < bVar2;
        pbVar8 = pbVar8 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar1 == bVar2);
      DAT_007fe688 = uVar5;
      if (!bVar12) {
        *(undefined4 *)(puVar6 + -0x5c) = 0;
        goto LAB_0044f802;
      }
      *(undefined4 *)(puVar6 + -0x60) = 0;
    } while( true );
  }
  puVar9 = &DAT_01cf8f44;
  puVar11 = &DAT_007fe6c8;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
  DAT_007fe690 = *param_3 % 10 + 1;
  DAT_007fe68c = (*param_3 / 10) * 10;
  puVar9 = (undefined4 *)(&DAT_007fe730 + DAT_007fe690 * 0x18);
  puVar11 = &DAT_007fe698;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
LAB_0044f92d:
  if (**(int **)(puVar7 + 0x10) < 5000) {
    FUN_005f33c9(puVar7,0x44f95a);
    FUN_005f34d1(puVar7,0x44f975);
    *(undefined4 *)(puVar7 + -0xa4) = 0;
    *(undefined4 *)(puVar7 + -0xb8) = 4;
    *(undefined4 *)(puVar7 + -0xb4) = 0x20b8ea1;
    *(undefined4 *)(puVar7 + -0xb0) = *(undefined4 *)(puVar7 + 0x10);
    FUN_005f34f0(puVar7 + -0xa4,0x784ff00,&DAT_00760eec,puVar7 + -0xb8,&DAT_0078fa6c);
    FUN_005f33c9(puVar7,0x44f9eb);
    FUN_005f34d1(puVar7,0x44fa06);
    DAT_007fe684 = thunk_FUN_00595f30(&DAT_020b8ea0,1);
    if (DAT_007fe684 == 0) {
      *(undefined4 *)(puVar7 + -0x54) = 0;
      return;
    }
  }
  DAT_007fe680 = **(int **)(puVar7 + 0x10) % 10;
  _DAT_007fe67c = DAT_007fe68c / 10;
  *(undefined4 *)(puVar7 + -0xa4) = 0;
  *(undefined4 *)(puVar7 + -0xb8) = 3;
  *(char **)(puVar7 + -0xb4) = s_0000_drw_0078fabe;
  *(undefined **)(puVar7 + -0xb0) = &DAT_007fe67c;
  FUN_005f34f0(puVar7 + -0xa4,0x784ff00,&DAT_00760eec,puVar7 + -0xb8,&DAT_0078fa80);
  FUN_005f46bc(puVar7,0x44faea);
  FUN_005f46bc(puVar7,0x44fb06);
  FUN_005f34d1(puVar7,0x44fb1c);
  *(undefined4 *)(puVar7 + -0xa4) = 0;
  *(undefined4 *)(puVar7 + -0xb8) = 0x80;
  *(undefined4 **)(puVar7 + -0xb4) = &DAT_007fe6c8;
  *(uint **)(puVar7 + -0xb0) = &DAT_007fe694;
  FUN_005f47c0(puVar7 + -0xa4,0xffffffff,0x784ff00,&DAT_00760fd4,puVar7 + -0xb8);
  if ((DAT_007fe694 & 1) == 0) {
    iVar3 = **(int **)(puVar7 + 8);
    *(int *)(puVar7 + -0x2c) = iVar3;
    DAT_007fe688 = 1;
    while (0 < iVar3) {
      *(undefined2 *)(&DAT_01d9d0fe + DAT_007fe688 * 2) =
           *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fe688 * 2 + 2);
      *(int *)(puVar7 + -0xa8) = (&PT_X0)[DAT_007fe688] + -8000;
      *(float *)(&DAT_01dc41fc + DAT_007fe688 * 4) = (float)*(int *)(puVar7 + -0xa8) / f_100;
      *(int *)(puVar7 + -0xa8) = (&PT_Y0)[DAT_007fe688] + 32000;
      *(float *)(&DAT_01e123fc + DAT_007fe688 * 4) = (float)*(int *)(puVar7 + -0xa8) / f_100;
      DAT_007fe688 = DAT_007fe688 + 1;
      *(int *)(puVar7 + -0x2c) = *(int *)(puVar7 + -0x2c) + -1;
      iVar3 = *(int *)(puVar7 + -0x2c);
    }
    for (iVar3 = 1; iVar3 < 0xc; iVar3 = iVar3 + 1) {
      *(undefined2 *)(&DAT_007fe6ae + iVar3 * 2) = 1;
    }
    DAT_007fe688 = DAT_007fe680 + 2;
    iVar3 = 0xc - DAT_007fe688;
    *(int *)(puVar7 + -0x28) = iVar3;
    while (0 < iVar3) {
      *(short *)(&DAT_007fe6ae + DAT_007fe688 * 2) = (short)**(undefined4 **)(puVar7 + 8) + 1;
      DAT_007fe688 = DAT_007fe688 + 1;
      *(int *)(puVar7 + -0x28) = *(int *)(puVar7 + -0x28) + -1;
      iVar3 = *(int *)(puVar7 + -0x28);
    }
  }
  else {
    load_symbol_library(&DAT_007fe67c,&DAT_007fe6b0,&DAT_007fe748,0x18);
    if ((DAT_020b8ea0 != 0x4d53) && ((&DAT_007fe6b0)[DAT_007fe680] != (&DAT_007fe6b2)[DAT_007fe680])
       ) {
      FUN_005f33c9(puVar7,0x44fbfe);
      FUN_005f34d1(puVar7,0x44fc19);
      DAT_007fe690 = thunk_FUN_00595f30(&DAT_020b90a0,1);
      if (DAT_007fe690 != -1) {
        *(undefined4 *)(puVar7 + -0x48) = 0;
        DAT_007fe678 = 0xfffffc19;
        return;
      }
    }
    DAT_007fe690 = DAT_007fe680 + 1;
    DAT_007fe6b0 = 1;
    DAT_007fe678 = (int)(short)((&DAT_007fe6b0)[DAT_007fe690] -
                               *(short *)(&DAT_007fe6ae + DAT_007fe690 * 2));
    DAT_007fe674 = DAT_007fe678 - **(int **)(puVar7 + 8);
    if (DAT_007fe674 != 0) {
      if (DAT_007fe674 < 1) {
        DAT_007fe688 = (uint)DAT_007fe6c4;
        iVar3 = (((int)(short)(&DAT_007fe6b0)[DAT_007fe690] - (int)DAT_007fe6c4) + -1) / -1;
        *(int *)(puVar7 + -0x44) = iVar3;
        while (0 < iVar3) {
          *(undefined4 *)(&DAT_01dc41fc + (DAT_007fe688 - DAT_007fe674) * 4) =
               *(undefined4 *)(&DAT_01dc41fc + DAT_007fe688 * 4);
          *(undefined4 *)(&DAT_01e123fc + (DAT_007fe688 - DAT_007fe674) * 4) =
               *(undefined4 *)(&DAT_01e123fc + DAT_007fe688 * 4);
          *(undefined2 *)(&DAT_01d9d0fe + (DAT_007fe688 - DAT_007fe674) * 2) =
               *(undefined2 *)(&DAT_01d9d0fe + DAT_007fe688 * 2);
          DAT_007fe688 = DAT_007fe688 + -1;
          *(int *)(puVar7 + -0x44) = *(int *)(puVar7 + -0x44) + -1;
          iVar3 = *(int *)(puVar7 + -0x44);
        }
      }
      else {
        DAT_007fe688 = (short)(&DAT_007fe6b0)[DAT_007fe690] - DAT_007fe674;
        iVar3 = ((int)DAT_007fe6c4 - DAT_007fe688) + 1;
        *(int *)(puVar7 + -0x34) = iVar3;
        while (0 < iVar3) {
          *(undefined4 *)(&DAT_01dc41fc + DAT_007fe688 * 4) =
               *(undefined4 *)(&DAT_01dc41fc + (DAT_007fe674 + DAT_007fe688) * 4);
          *(undefined4 *)(&DAT_01e123fc + DAT_007fe688 * 4) =
               *(undefined4 *)(&DAT_01e123fc + (DAT_007fe674 + DAT_007fe688) * 4);
          *(undefined2 *)(&DAT_01d9d0fe + DAT_007fe688 * 2) =
               *(undefined2 *)(&DAT_01d9d0fe + (DAT_007fe674 + DAT_007fe688) * 2);
          DAT_007fe688 = DAT_007fe688 + 1;
          *(int *)(puVar7 + -0x34) = *(int *)(puVar7 + -0x34) + -1;
          iVar3 = *(int *)(puVar7 + -0x34);
        }
        *(undefined4 *)(puVar7 + -0x30) = 0;
      }
      DAT_007fe688 = DAT_007fe690 + 1;
      iVar3 = 0xc - DAT_007fe688;
      *(int *)(puVar7 + -0x40) = iVar3;
      while (0 < iVar3) {
        if (*(short *)(&DAT_007fe6ae + DAT_007fe688 * 2) != 0) {
          *(short *)(&DAT_007fe6ae + DAT_007fe688 * 2) =
               *(short *)(&DAT_007fe6ae + DAT_007fe688 * 2) - (short)DAT_007fe674;
        }
        DAT_007fe688 = DAT_007fe688 + 1;
        *(int *)(puVar7 + -0x40) = *(int *)(puVar7 + -0x40) + -1;
        iVar3 = *(int *)(puVar7 + -0x40);
      }
    }
    DAT_007fe670 = 0;
    DAT_007fe688 = (uint)*(short *)(&DAT_007fe6ae + DAT_007fe690 * 2);
    iVar3 = (int)(short)(&DAT_007fe6b0)[DAT_007fe690] -
            (int)*(short *)(&DAT_007fe6ae + DAT_007fe690 * 2);
    *(int *)(puVar7 + -0x3c) = iVar3;
    while (0 < iVar3) {
      DAT_007fe670 = DAT_007fe670 + 1;
      *(int *)(puVar7 + -0xa8) = (&PT_X0)[DAT_007fe670] + -8000;
      *(float *)(&DAT_01dc41fc + DAT_007fe688 * 4) = (float)*(int *)(puVar7 + -0xa8) / f_100;
      *(int *)(puVar7 + -0xa8) = (&PT_Y0)[DAT_007fe670] + 32000;
      *(float *)(&DAT_01e123fc + DAT_007fe688 * 4) = (float)*(int *)(puVar7 + -0xa8) / f_100;
      *(undefined2 *)(&DAT_01d9d0fe + DAT_007fe688 * 2) =
           *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fe670 * 2 + 2);
      DAT_007fe688 = DAT_007fe688 + 1;
      *(int *)(puVar7 + -0x3c) = *(int *)(puVar7 + -0x3c) + -1;
      iVar3 = *(int *)(puVar7 + -0x3c);
    }
    *(undefined4 *)(puVar7 + -0x38) = 0;
  }
  DAT_007fe680 = 0;
  *(undefined4 *)(puVar7 + -0x24) = 0xb;
  DAT_007fe688 = 1;
  do {
    if (DAT_007fe680 < *(short *)(&DAT_007fe6ae + DAT_007fe688 * 2)) {
      DAT_007fe680 = (int)*(short *)(&DAT_007fe6ae + DAT_007fe688 * 2);
    }
    DAT_007fe688 = DAT_007fe688 + 1;
    *(int *)(puVar7 + -0x24) = *(int *)(puVar7 + -0x24) + -1;
  } while (0 < *(int *)(puVar7 + -0x24));
  DAT_007fe6c4 = (short)DAT_007fe680;
  puVar9 = &DAT_007fe698;
  puVar11 = (undefined4 *)(&DAT_007fe730 + DAT_007fe690 * 0x18);
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
  *(undefined4 *)(puVar7 + -0xa4) = 0;
  *(undefined4 *)(puVar7 + -200) = 0x80;
  *(undefined4 **)(puVar7 + -0xc4) = &DAT_007fe6c8;
  *(undefined4 *)(puVar7 + -0xc0) = 7;
  *(char **)(puVar7 + -0xbc) = "unknown";
  *(undefined4 *)(puVar7 + -0xb8) = 6;
  *(char **)(puVar7 + -0xb4) = "binary";
  *(undefined4 *)(puVar7 + -0xb0) = 2;
  uVar4 = FUN_005f6540(puVar7 + -0xa4,9,0x784ff01,&DAT_00760f8c,puVar7 + -200);
  *(undefined4 *)(puVar7 + -0x20) = uVar4;
  if (*(int *)(puVar7 + -0x20) == 0) {
    *(undefined4 *)(puVar7 + -0xa4) = 0;
    *(undefined4 *)(puVar7 + -0xb0) = 0x16;
    *(undefined2 **)(puVar7 + -0xac) = &DAT_007fe6b0;
    uVar4 = FUN_005fa4d0(puVar7 + -0xa4,9,0x784ff01,&DAT_00760e50,puVar7 + -0xb0);
    *(undefined4 *)(puVar7 + -0x1c) = uVar4;
    if (*(int *)(puVar7 + -0x1c) == 0) {
      *(undefined4 *)(puVar7 + -0xa4) = 0;
      *(undefined4 *)(puVar7 + -0xb8) = 0xf0;
      *(undefined **)(puVar7 + -0xb4) = &DAT_007fe748;
      *(undefined4 *)(puVar7 + -0xb0) = 0x18;
      FUN_005fa4d0(puVar7 + -0xa4,9,0x784ff00,&DAT_00760f88,puVar7 + -0xb8);
      DAT_007fe66c = DAT_007fe6c4 + -1;
      iVar3 = DAT_007fe66c;
      if (DAT_007fe66c < 0) {
        iVar3 = 0;
      }
      DAT_007fe680 = iVar3 + 1;
      *(undefined4 *)(puVar7 + -0xa4) = 0;
      *(undefined4 *)(puVar7 + -0xc0) = 1;
      *(undefined4 **)(puVar7 + -0xbc) = &DAT_01dc4200;
      *(undefined4 *)(puVar7 + -0xb8) = 1;
      *(int *)(puVar7 + -0xb4) = iVar3;
      *(undefined4 *)(puVar7 + -0xb0) = 4;
      uVar4 = FUN_005fa4d0(puVar7 + -0xa4,9,0x784ff01,&DAT_00760f84,puVar7 + -0xc0);
      *(undefined4 *)(puVar7 + -0x14) = uVar4;
      if (*(int *)(puVar7 + -0x14) == 0) {
        iVar3 = DAT_007fe66c;
        if (DAT_007fe66c < 0) {
          iVar3 = 0;
        }
        DAT_007fe680 = iVar3 + 1;
        *(undefined4 *)(puVar7 + -0xa4) = 0;
        *(undefined4 *)(puVar7 + -0xc0) = 1;
        *(undefined4 **)(puVar7 + -0xbc) = &DAT_01e12400;
        *(undefined4 *)(puVar7 + -0xb8) = 1;
        *(int *)(puVar7 + -0xb4) = iVar3;
        *(undefined4 *)(puVar7 + -0xb0) = 4;
        uVar4 = FUN_005fa4d0(puVar7 + -0xa4,9,0x784ff01,&DAT_00760f84,puVar7 + -0xc0);
        *(undefined4 *)(puVar7 + -0x10) = uVar4;
        if (*(int *)(puVar7 + -0x10) == 0) {
          iVar3 = DAT_007fe66c;
          if (DAT_007fe66c < 0) {
            iVar3 = 0;
          }
          DAT_007fe680 = iVar3 + 1;
          *(undefined4 *)(puVar7 + -0xa4) = 0;
          *(undefined4 *)(puVar7 + -0xc0) = 1;
          *(undefined2 **)(puVar7 + -0xbc) = &DAT_01d9d100;
          *(undefined4 *)(puVar7 + -0xb8) = 1;
          *(int *)(puVar7 + -0xb4) = iVar3;
          *(undefined4 *)(puVar7 + -0xb0) = 2;
          uVar4 = FUN_005fa4d0(puVar7 + -0xa4,9,0x784ff01,&DAT_00760f80,puVar7 + -0xc0);
          *(undefined4 *)(puVar7 + -0xc) = uVar4;
          if (*(int *)(puVar7 + -0xc) == 0) {
            *(undefined4 *)(puVar7 + -0xa4) = 0;
            FUN_005f7950(puVar7 + -0xa4,9,0x784ff00,&DAT_00760e4c,0);
            FUN_00450f1b(*(undefined4 *)(puVar7 + 0x10),&DAT_007fe690,&DAT_007fe6c8,0x80,
                         &DAT_007fe748,0x18);
            FUN_005f33c9(puVar7,0x450526);
            FUN_005f34d1(puVar7,0x450541);
            **(undefined4 **)(puVar7 + 0xc) = 0;
            for (iVar3 = 1; iVar3 < 0x65; iVar3 = iVar3 + 1) {
              *(undefined4 *)(&DAT_01cb0ebc + iVar3 * 4) = 0xffffffff;
            }
            *(undefined4 *)(puVar7 + -4) = 0;
            return;
          }
        }
      }
    }
  }
  DAT_007fe678 = 0xfffffc19;
  return;
LAB_0044f7f7:
  DAT_007fe688 = 1;
LAB_0044f802:
  FUN_005f46bc(puVar6,0x44f841);
  puVar7 = puVar6;
  FUN_005f34d1(puVar6,0x44f857);
  *(undefined4 *)(puVar7 + -100) = 0;
  thunk_FUN_00518448();
  P2 = P1;
  *(undefined2 *)(puVar7 + -0xac) = in_FPUControlWord;
  *(ushort *)(puVar7 + -0xaa) = (ushort)*(undefined4 *)(puVar7 + -0xac) | 0xc00;
  *(int *)(puVar7 + -0xa8) = (int)ROUND(P1);
  **(undefined4 **)(puVar7 + 0x10) = *(undefined4 *)(puVar7 + -0xa8);
  DAT_007fe68c = (**(int **)(puVar7 + 0x10) / 10) * 10;
  goto LAB_0044f92d;
}


