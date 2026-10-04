// FUN_004fb990 @ 004fb990 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fb990(void)

{
  float fVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined2 in_FPUControlWord;
  
  puVar5 = &stack0xfffffffc;
  VIEW_DY = 0;
  DAT_00901db0 = 1;
  DAT_00901db8 = f_999;
  DAT_00901db4 = f_0;
  for (iVar7 = ITEM_I; 0 < iVar7; iVar7 = iVar7 + -1) {
    DAT_00901dd8 = (&ITEM_PTR0)[DAT_00901db0];
    if ((((float)(&ITEM_P1)[DAT_00901dd8] == f_8) &&
        ((float)(&ITEM_P2)[DAT_00901dd8] <= DAT_00901db8)) &&
       (DAT_00901db8 = (float)(&ITEM_P2)[DAT_00901dd8], f_4 < (float)(&ITEM_LEN)[DAT_00901dd8])) {
      DAT_00901db4 = (float)(&ITEM_P5)[DAT_00901dd8];
    }
    DAT_00901db0 = DAT_00901db0 + 1;
  }
  FUN_005f46bc(&stack0xfffffffc,0x4fbad5);
  FUN_005f46bc(puVar5,0x4fbaf1);
  FUN_005f46bc(puVar5,0x4fbb0d);
  FUN_005f34d1(puVar5,0x4fbb23);
  while( true ) {
    DAT_01c4c780 = 1;
    DAT_01be0960 = 0;
    DAT_01c4c784 = 0;
    DAT_00901dac = 0;
    DAT_00901da8 = 0;
    DAT_00901dc8 = DAT_00901dcc;
    DAT_00901dca = DAT_00901dce;
    DAT_00795450 = ram0x00766b74;
    DAT_00901da4 = 0;
    if (DAT_01c58600 != 3) break;
    *(undefined4 *)(puVar5 + -0x290) = DAT_0078b464;
    *(undefined4 *)(puVar5 + -0x28c) = DAT_0078b468;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    FUN_005f33c9(puVar5,0x4fbbcd);
    FUN_005f33c9(puVar5,0x4fbbe9);
    *(undefined1 **)(puVar5 + -0x2a4) = puVar5 + -0x2b8;
    *(undefined4 *)(puVar5 + -0x2a8) = 0x10;
    *(undefined4 *)(puVar5 + -0x2a0) = 3;
    *(undefined4 *)(puVar5 + -0x29c) = extraout_EDX;
    *(undefined4 *)(puVar5 + -0x298) = 2;
    uVar3 = FUN_005f6540(puVar5 + -0x288,9,0x784ff01,&DAT_00766b58,puVar5 + -0x2a8);
    *(undefined4 *)(puVar5 + -600) = uVar3;
    if (*(int *)(puVar5 + -600) != 0) {
      FUN_005f33c9(puVar5,0x4fee2f);
      FUN_005f33c9(puVar5,0x4fee4b);
      FUN_005f33c9(puVar5,0x4fee67);
      FUN_005f34d1(puVar5,0x4fee82);
      goto LAB_004fee86;
    }
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(int **)(puVar5 + -0x290) = &DAT_01c4ef40;
    FUN_005ffa30(puVar5 + -0x288,9,0x784ff00,&DAT_00766b54,puVar5 + -0x290);
    *(uint **)(puVar5 + -0x290) = &DAT_01ba0d84;
    FUN_005ffd80(puVar5 + -0x288,&DAT_00766b54,puVar5 + -0x290);
    *(int **)(puVar5 + -0x290) = &MAX_STAFF;
    FUN_005ffd80(puVar5 + -0x288,&DAT_00766b54,puVar5 + -0x290);
    *(int **)(puVar5 + -0x290) = &DAT_01c58604;
    FUN_005ffd80(puVar5 + -0x288,&DAT_00766b54,puVar5 + -0x290);
    *(undefined4 **)(puVar5 + -0x290) = &DAT_01c5860c;
    FUN_005ffd80(puVar5 + -0x288,&DAT_00766b50,puVar5 + -0x290);
    bVar2 = 999 < DAT_01c58604;
    if (bVar2) {
      DAT_01c58604 = DAT_01c58604 / 1000;
    }
    else {
      *(undefined4 *)(puVar5 + -0x250) = 0;
    }
    DAT_0078b4e8 = (uint)bVar2;
    iVar7 = DAT_01c4ef40;
    if (DAT_01c4ef40 < 0) {
      iVar7 = 0;
    }
    DAT_00901db0 = iVar7 + 1;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x2a0) = 1;
    *(undefined4 **)(puVar5 + -0x29c) = &DAT_01c42500;
    *(undefined4 *)(puVar5 + -0x298) = 1;
    *(int *)(puVar5 + -0x294) = iVar7;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    FUN_005ffa30(puVar5 + -0x288,9,0x784ff00,&DAT_00766b4c,puVar5 + -0x2a0);
    *(undefined4 *)(puVar5 + -0x288) = 0;
    FUN_005fdbd0(puVar5 + -0x288,9,0x784ff00,&DAT_00766b48,0,&DAT_00795180);
    DAT_00901db0 = 1;
    for (iVar7 = DAT_01c4ef40; 0 < iVar7; iVar7 = iVar7 + -1) {
      *(undefined4 *)(puVar5 + -0x298) = 0x80;
      *(undefined **)(puVar5 + -0x294) = &DAT_01c4eec4 + DAT_00901db0 * 0x80;
      *(undefined4 *)(puVar5 + -0x290) = 0x80;
      FUN_005fe110(puVar5 + -0x288,&DAT_00766b44,puVar5 + -0x298);
      DAT_00901db0 = DAT_00901db0 + 1;
    }
    FUN_005fe110(puVar5 + -0x288,&DAT_00766b40,0);
    uVar4 = DAT_01ba0d84;
    if ((int)DAT_01ba0d84 < 0) {
      uVar4 = 0;
    }
    DAT_00901db0 = uVar4 + 1;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x2a0) = 1;
    *(undefined4 **)(puVar5 + -0x29c) = &DAT_01a75b20;
    *(undefined4 *)(puVar5 + -0x298) = 1;
    *(uint *)(puVar5 + -0x294) = uVar4;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    FUN_005ffa30(puVar5 + -0x288,9,0x784ff00,&DAT_00766b4c,puVar5 + -0x2a0);
    uVar4 = DAT_01ba0d84;
    if ((int)DAT_01ba0d84 < 0) {
      uVar4 = 0;
    }
    DAT_00901db0 = uVar4 + 1;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x2a0) = 1;
    *(undefined4 **)(puVar5 + -0x29c) = &DAT_01ba0d88;
    *(undefined4 *)(puVar5 + -0x298) = 1;
    *(uint *)(puVar5 + -0x294) = uVar4;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    FUN_005ffa30(puVar5 + -0x288,9,0x784ff00,&DAT_00766b3c,puVar5 + -0x2a0);
    uVar4 = DAT_01ba0d84;
    if ((int)DAT_01ba0d84 < 0) {
      uVar4 = 0;
    }
    DAT_00901db0 = uVar4 + 1;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x2a0) = 1;
    *(undefined4 **)(puVar5 + -0x29c) = &DAT_01a76ac0;
    *(undefined4 *)(puVar5 + -0x298) = 1;
    *(uint *)(puVar5 + -0x294) = uVar4;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    FUN_005ffa30(puVar5 + -0x288,9,0x784ff00,&DAT_00766b4c,puVar5 + -0x2a0);
    iVar7 = DAT_01c58604;
    if (DAT_01c58604 < 0) {
      iVar7 = 0;
    }
    DAT_00901db0 = iVar7 + 1;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x2a0) = 1;
    *(undefined **)(puVar5 + -0x29c) = &DAT_01c41ce4;
    *(undefined4 *)(puVar5 + -0x298) = 1;
    *(int *)(puVar5 + -0x294) = iVar7;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    FUN_005ffa30(puVar5 + -0x288,9,0x784ff00,&DAT_00766b3c,puVar5 + -0x2a0);
    iVar7 = DAT_01c58604;
    if (DAT_01c58604 < 0) {
      iVar7 = 0;
    }
    DAT_00901db0 = iVar7 + 1;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x2a0) = 1;
    *(undefined **)(puVar5 + -0x29c) = &DAT_01c420e8;
    *(undefined4 *)(puVar5 + -0x298) = 1;
    *(int *)(puVar5 + -0x294) = iVar7;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    FUN_005ffa30(puVar5 + -0x288,9,0x784ff00,&DAT_00766b4c,puVar5 + -0x2a0);
    *(undefined4 *)(puVar5 + -0x288) = 0;
    FUN_005f7950(puVar5 + -0x288,9,0x784ff00,&DAT_00766b38,0);
    if (DAT_00901da8 + DAT_00901dac == 0) goto LAB_004fc6a9;
    *(undefined4 *)(puVar5 + -0x22c) = 0;
    thunk_FUN_00518448();
    if (P3 == f_0) {
      *(undefined4 *)(puVar5 + -0x158) = 0;
LAB_004fc69a:
      *(undefined4 *)(puVar5 + -0x1c4) = 0;
      goto LAB_004fcd0e;
    }
    DAT_00901dc4 = DAT_00901dcc;
    DAT_00901dc6 = DAT_00901dce;
    if (DAT_0078b4e0 == 0x4e) {
      *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
      *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
      *(int *)(puVar5 + -0x28c) = (int)ROUND(P2);
      DAT_00901d84 = *(uint *)(puVar5 + -0x28c);
      *(undefined2 *)(puVar5 + -0x290) = *(undefined2 *)(puVar5 + -0x290);
      *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
      *(int *)(puVar5 + -0x28c) = (int)ROUND(P3);
      in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
      DAT_00901d74 = *(uint *)(puVar5 + -0x28c);
      if (DAT_00901d84 == 0) {
        DAT_00901d84 = 1;
      }
      DAT_00901dac = 1;
      if ((DAT_00901d74 == 0) || ((int)DAT_01ba0d84 < (int)DAT_00901d74)) {
        DAT_00901d74 = DAT_01ba0d84;
      }
      *(undefined4 *)(puVar5 + -0x150) = 0;
    }
    else {
      *(undefined4 *)(puVar5 + -0x154) = 0;
      DAT_01c4c780 = 1;
      DAT_01c4c784 = 0;
      *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
      *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
      *(int *)(puVar5 + -0x28c) = (int)ROUND(P2);
      DAT_00901dac = *(int *)(puVar5 + -0x28c);
      *(undefined2 *)(puVar5 + -0x290) = *(undefined2 *)(puVar5 + -0x290);
      *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
      *(int *)(puVar5 + -0x28c) = (int)ROUND(P3);
      in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
      DAT_00901da8 = *(int *)(puVar5 + -0x28c);
      DAT_00901d84 = 1;
      DAT_00901d74 = DAT_01ba0d84;
      *(uint *)(puVar5 + -0x14c) = DAT_01ba0d84;
      DAT_00901db0 = 1;
      DAT_00901d70 = DAT_00901dac;
      DAT_00901d6c = DAT_00901da8;
      while (0 < (int)DAT_01ba0d84) {
        if (*(int *)(&DAT_01a75b1c + DAT_00901db0 * 4) < 1) {
          DAT_00901d70 = DAT_00901d70 + -1;
          if (DAT_00901d70 == 0) {
            DAT_00901d84 = DAT_00901db0 + 1;
            if (DAT_00901d6c == 0) {
              *(undefined4 *)(puVar5 + -0x140) = 0;
              break;
            }
          }
          else {
            *(undefined4 *)(puVar5 + -0x144) = 0;
          }
          DAT_00901d6c = DAT_00901d6c + -1;
          if (DAT_00901d6c == 0) {
            *(undefined4 *)(puVar5 + -0x138) = 0;
            DAT_00901d74 = DAT_00901db0;
            break;
          }
          *(undefined4 *)(puVar5 + -0x13c) = 0;
        }
        else {
          *(undefined4 *)(puVar5 + -0x148) = 0;
        }
        *(undefined4 *)(puVar5 + -0x134) = 0;
        DAT_00901db0 = DAT_00901db0 + 1;
        *(int *)(puVar5 + -0x14c) = *(int *)(puVar5 + -0x14c) + -1;
        DAT_01ba0d84 = *(uint *)(puVar5 + -0x14c);
      }
    }
    DAT_01ba0d84 = (DAT_00901d74 - DAT_00901d84) + 1;
    if (DAT_00901d84 == 1) {
      *(undefined4 *)(puVar5 + -0x130) = 0;
      goto LAB_004fc69a;
    }
    DAT_00901d70 = DAT_01ba0d84;
    thunk_FUN_0054c4c6(&DAT_01a75b1c + DAT_00901d84 * 4,&DAT_01a75b20,&DAT_00901d70);
    *(uint *)(puVar5 + -0x290) = DAT_00901d70 * 2;
    thunk_FUN_0054c4c6(&DAT_01ba0d84 + DAT_00901d84,&DAT_01ba0d88,puVar5 + -0x290);
    thunk_FUN_0054c4c6(&DAT_01a76abc + DAT_00901d84 * 4,&DAT_01a76ac0,&DAT_00901d70);
    DAT_00901d70 = 0;
    *(int *)(puVar5 + -300) = DAT_01c4ef40;
    DAT_00901db0 = 1;
    iVar7 = DAT_01c4ef40;
    while (0 < iVar7) {
      DAT_00901d6c = *(int *)(&DAT_01c424fc + DAT_00901db0 * 4) + DAT_00901d70;
      if ((int)DAT_00901d84 <= DAT_00901d6c) {
        DAT_01c4c780 = DAT_00901d84 - DAT_00901d70;
        *(undefined4 *)(puVar5 + -0x124) = 0;
        DAT_01c4c784 = DAT_00901db0;
        goto LAB_004fc69a;
      }
      *(undefined4 *)(puVar5 + -0x128) = 0;
      DAT_00901db0 = DAT_00901db0 + 1;
      *(int *)(puVar5 + -300) = *(int *)(puVar5 + -300) + -1;
      DAT_00901d70 = DAT_00901d6c;
      iVar7 = *(int *)(puVar5 + -300);
    }
    DAT_01c58600 = 3;
    *(undefined4 *)(puVar5 + -0x120) = 0;
    DAT_00901d6c = DAT_00901d70;
  }
  *(undefined4 *)(puVar5 + -0x25c) = 0;
LAB_004fc6a9:
  DAT_00901da0 = _DAT_01c41ce4 / f_25;
  _DAT_01ade87c = ram0x00766b74;
  DAT_00795460 = 1;
  DAT_00795470 = 1;
  DAT_00901dc4 = DAT_00901ddc;
  DAT_00901dc6 = DAT_00901dde;
  _DAT_00901d9c = 1;
  DAT_00901dc8 = DAT_00901ddc;
  DAT_00901dca = DAT_00901dde;
  DAT_00795450 = f_0;
  DAT_01ba0d30 = 0;
  DAT_01ba0d34 = 0;
  DAT_01ade878 = 200;
  DAT_00795440 = 0xfffffffe;
  DAT_00795444 = 0;
  DAT_01ba0d40 = 0;
  DAT_01be094c = f_10;
  DAT_01be0954 = f_10;
  _DAT_01be0950 = ram0x00766b74;
  if (DAT_0078b4e8 == 2) {
    DAT_01be0954 = f_720;
    _DAT_01be0950 = f_72;
  }
  else {
    *(undefined4 *)(puVar5 + -0x228) = 0;
  }
  if (DAT_0078b4e8 == 1) {
    DAT_01be0954 = f_25_4;
    _DAT_01be0950 = f_2_54;
    _DAT_00901d98 = 0;
    _DAT_00901d94 = 9999;
  }
  else {
    *(undefined4 *)(puVar5 + -0x224) = 0;
  }
  DAT_01fb8c60 = DAT_00901da0;
  DAT_00901d90 = thunk_FUN_0050273b(&DAT_020b8ea0,0x80);
  DAT_00901d8c = DAT_02052740;
  if (DAT_00901d90 == 0) {
    DAT_02052740 = 8;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x2a0) = 0x80;
    *(undefined2 **)(puVar5 + -0x29c) = &DAT_020b8ea0;
    *(undefined4 *)(puVar5 + -0x298) = 3;
    *(undefined **)(puVar5 + -0x294) = &DAT_00766b1c;
    *(undefined4 *)(puVar5 + -0x290) = 2;
    uVar3 = FUN_005f6540(puVar5 + -0x288,8,0x784ff01,&DAT_00766b58,puVar5 + -0x2a0);
    *(undefined4 *)(puVar5 + -0x21c) = uVar3;
    if (*(int *)(puVar5 + -0x21c) == 0) {
LAB_004fc8c1:
      thunk_FUN_00518448();
      *(undefined4 *)(puVar5 + -0x218) = 0x10;
      DAT_00901db0 = 1;
      do {
        if (*(int *)(&DAT_007953fc + DAT_00901db0 * 4) == _DAT_020b8ea0) {
          switch(DAT_00901db0) {
          case 1:
            goto LAB_004fc93e;
          case 2:
            if (DAT_020b8ea4 == 'I') {
              *(undefined4 *)(puVar5 + -0x20c) = 0;
              DAT_0078b4e8 = 1;
              _DAT_01be0950 = _UNK_00766b18;
              *(undefined4 *)(puVar5 + -0x1d0) = 0;
            }
            else {
              DAT_0079546c = 1;
              *(undefined4 *)(puVar5 + -0x208) = 0;
            }
            goto LAB_004fc8c1;
          case 3:
            DAT_0079546c = 0;
            *(undefined4 *)(puVar5 + -0x204) = 0;
            goto LAB_004fc8c1;
          case 4:
            *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
            *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
            *(int *)(puVar5 + -0x28c) = (int)ROUND(P2);
            in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
            DAT_00795440 = *(uint *)(puVar5 + -0x28c);
            *(undefined4 *)(puVar5 + -0x200) = 0;
            goto LAB_004fc8c1;
          case 5:
            _DAT_00901d9c = 1;
            DAT_00795444 = 0x46;
            *(undefined4 *)(puVar5 + -0x1fc) = 0;
            goto LAB_004fc8c1;
          case 6:
            _DAT_00901d9c = 2;
            DAT_00795444 = 0x45;
            *(undefined4 *)(puVar5 + -0x1f8) = 0;
            goto LAB_004fc8c1;
          case 7:
            DAT_00795454 = 0;
            *(undefined4 *)(puVar5 + -500) = 0;
            goto LAB_004fc8c1;
          case 8:
            DAT_00795454 = 1;
            *(undefined4 *)(puVar5 + -0x1f0) = 0;
            goto LAB_004fc8c1;
          case 9:
            *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
            *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
            *(int *)(puVar5 + -0x28c) = (int)ROUND(P2);
            in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
            DAT_01ba0d30 = *(int *)(puVar5 + -0x28c);
            *(undefined4 *)(puVar5 + -0x1ec) = 0;
            goto LAB_004fc8c1;
          case 10:
            *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
            *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
            *(int *)(puVar5 + -0x28c) = (int)ROUND(P2);
            in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
            DAT_01ba0d34 = *(int *)(puVar5 + -0x28c);
            DAT_01ade878 = DAT_01ade878 - DAT_01ba0d34;
            *(undefined4 *)(puVar5 + -0x1e8) = 0;
            goto LAB_004fc8c1;
          case 0xb:
            if (P2 == f_0) {
              FUN_005f34d1(puVar5,&UNK_004fcbd3);
              DAT_00795450 = f_0;
              *(undefined4 *)(puVar5 + -0x1e4) = 0;
            }
            else {
              DAT_00901dc8 = DAT_00901dcc;
              DAT_00901dca = DAT_00901dce;
              DAT_00795450 = ram0x00766b74;
              *(undefined4 *)(puVar5 + -0x1e0) = 0;
            }
            goto LAB_004fc8c1;
          case 0xc:
            DAT_00901da0 = P2;
            _DAT_01ade87c = P2 / DAT_01fb8c60;
            *(undefined4 *)(puVar5 + -0x1dc) = 0;
            goto LAB_004fc8c1;
          case 0xd:
            DAT_01be0954 = P2;
            *(undefined4 *)(puVar5 + -0x1d8) = 0;
            goto LAB_004fc8c1;
          case 0xe:
            DAT_0078b4e8 = 0;
            _DAT_01be0950 = ram0x00766b74;
            *(undefined4 *)(puVar5 + -0x1d4) = 0;
            goto LAB_004fc8c1;
          case 0xf:
            DAT_0078b4e8 = 2;
            _DAT_01be0950 = f_72;
            *(undefined4 *)(puVar5 + -0x1cc) = 0;
            goto LAB_004fc8c1;
          case 0x10:
            *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
            *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
            *(int *)(puVar5 + -0x28c) = (int)ROUND(P2);
            in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
            DAT_00795440 = *(uint *)(puVar5 + -0x28c);
            *(undefined4 *)(puVar5 + -0x1c8) = 0;
            goto LAB_004fc8c1;
          }
        }
        DAT_00901db0 = DAT_00901db0 + 1;
        *(int *)(puVar5 + -0x218) = *(int *)(puVar5 + -0x218) + -1;
        if (*(int *)(puVar5 + -0x218) < 1) {
          *(undefined4 *)(puVar5 + -0x214) = 0;
          goto LAB_004fcd0e;
        }
      } while( true );
    }
LAB_004fee86:
    thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
    DAT_01c58600 = 0;
    DAT_0078b4e0 = 0x2d;
    return;
  }
  *(undefined4 *)(puVar5 + -0x220) = 0;
LAB_004fcd0e:
  DAT_02052740 = DAT_00901d8c;
  DAT_01be094c = DAT_01be0954 / _DAT_01be0950;
  DAT_00901d84 = DAT_00795440;
  if (DAT_00795440 == 0xfffffffe) {
    DAT_00901d84 = 0;
  }
LAB_004fcd49:
  DAT_01b12d68 = DAT_01ba0d84;
  DAT_01b12d6c = DAT_00795454;
  DAT_00901d80 = DAT_00795440;
  if (DAT_00795440 == 0xfffffffe) {
    DAT_00901d80 = 0;
  }
  DAT_01b12d70 = DAT_00901d80;
  DAT_01b12da4 = DAT_00795440;
  DAT_01b12da8 = DAT_00795444 + -0x45;
  DAT_01b12d78 = DAT_01ba0d30;
  DAT_01b12d7c = DAT_01ba0d34;
  if (DAT_00901d88 == 0) {
    DAT_00901d88 = 1;
  }
  DAT_01b12d80 = DAT_00901d88;
  DAT_00795470 = DAT_00901d88;
  DAT_01b12d84 = DAT_0079546c;
  _DAT_01b12d88 = 0;
  _DAT_01b12d8c = 0;
  DAT_01b12d90 = 0;
  *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
  *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
  *(int *)(puVar5 + -0x28c) = (int)ROUND(DAT_00795450);
  in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
  DAT_01b12d94 = *(int *)(puVar5 + -0x28c);
  DAT_01b12d98 = 0;
  DAT_01b12d9c = DAT_01ba0d40;
  DAT_01b12da0 = 0;
  DAT_00901e34 = DAT_01be0954;
  if (_DAT_00901d7c == f_0) {
    DAT_00901db4 = DAT_00901da0;
  }
  DAT_00901e40 = DAT_00901db4;
  DAT_01b12dac = DAT_0078b4e8;
  DAT_00901dd4 = thunk_FUN_005998c0(&DAT_01b12d68,&DAT_00901e34);
  if (DAT_00901dd4 == 7) {
    if (DAT_01b12d98 == 0) {
      *(undefined4 *)(puVar5 + -0x1bc) = 0;
LAB_004fede7:
      *(undefined4 *)(puVar5 + -4) = 0;
      DAT_0078b4e0 = 0x45;
      DAT_0078b4e4 = 0x58;
      DAT_01ba0d40 = 0;
      DAT_01c58600 = 0;
      return;
    }
    *(undefined4 *)(puVar5 + -0x1c0) = 0;
  }
  else if (DAT_00901dd4 == 0) {
    DAT_0078b4e4 = 0;
    FUN_005f34d1(puVar5,0x4fed9b);
    ITEM_WORDS = 1;
    *DAT_01fbb844 = 0;
    *(undefined4 *)(puVar5 + -0x1b8) = 0;
    goto LAB_004fede7;
  }
  if (DAT_01b12d98 != 0) {
    FUN_005f46bc(puVar5,0x4fcf34);
    FUN_005f46bc(puVar5,0x4fcf50);
    FUN_005f46bc(puVar5,0x4fcf6c);
    FUN_005f34d1(puVar5,0x4fcf82);
    DAT_00901d78 = 0xb;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x2a0) = 0x80;
    *(undefined2 **)(puVar5 + -0x29c) = &DAT_020b8ea0;
    *(undefined4 *)(puVar5 + -0x298) = 7;
    *(char **)(puVar5 + -0x294) = "unknown";
    *(undefined4 *)(puVar5 + -0x290) = 2;
    uVar3 = FUN_005f6540(puVar5 + -0x288,0xb,0x784ff01,&DAT_00766b58,puVar5 + -0x2a0);
    *(undefined4 *)(puVar5 + -0x1b4) = uVar3;
    if (*(int *)(puVar5 + -0x1b4) != 0) goto LAB_004fee86;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    *(int **)(puVar5 + -0x28c) = &DAT_01b12d80;
    uVar3 = FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff01,&DAT_00766b08,puVar5 + -0x290,
                         &DAT_00795194);
    *(undefined4 *)(puVar5 + -0x1b0) = uVar3;
    if (*(int *)(puVar5 + -0x1b0) != 0) goto LAB_004fee86;
    DAT_00901db0 = DAT_01b12d84;
    if (DAT_01b12d84 == 0) {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      uVar3 = FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff01,&DAT_00766b40,0,&DAT_007951b4);
      *(undefined4 *)(puVar5 + -0x1ac) = uVar3;
      iVar7 = *(int *)(puVar5 + -0x1ac);
    }
    else {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      uVar3 = FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff01,&DAT_00766b40,0,&DAT_007951c8);
      *(undefined4 *)(puVar5 + -0x1a8) = uVar3;
      iVar7 = *(int *)(puVar5 + -0x1a8);
    }
    if (iVar7 != 0) goto LAB_004fee86;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    *(uint **)(puVar5 + -0x28c) = &DAT_01b12d70;
    uVar3 = FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff01,&DAT_00766b08,puVar5 + -0x290,
                         &DAT_007951dc);
    *(undefined4 *)(puVar5 + -0x1a4) = uVar3;
    if (*(int *)(puVar5 + -0x1a4) != 0) goto LAB_004fee86;
    if (DAT_01b12d70 == 0) {
      *(undefined4 *)(puVar5 + -0x1a0) = 0;
    }
    else {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      *(undefined4 *)(puVar5 + -0x290) = 4;
      *(uint **)(puVar5 + -0x28c) = &DAT_01b12da4;
      uVar3 = FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff01,&DAT_00766b08,puVar5 + -0x290,
                           &DAT_007951fc);
      *(undefined4 *)(puVar5 + -0x19c) = uVar3;
      if (*(int *)(puVar5 + -0x19c) != 0) goto LAB_004fee86;
      DAT_00901db0 = DAT_01b12da8;
      if (DAT_01b12da8 == 0) {
        *(undefined4 *)(puVar5 + -0x288) = 0;
        FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b40,0,&DAT_0079521c);
      }
      else {
        *(undefined4 *)(puVar5 + -0x288) = 0;
        FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b40,0,&DAT_00795230);
      }
    }
    DAT_00901db0 = DAT_01b12d6c;
    if (DAT_01b12d6c == 0) {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b40,0,&DAT_00795240);
    }
    else {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b40,0,&DAT_00795254);
    }
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    *(int **)(puVar5 + -0x28c) = &DAT_01b12d94;
    FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b08,puVar5 + -0x290,&DAT_00795268)
    ;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    *(int **)(puVar5 + -0x28c) = &DAT_01b12d78;
    FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b08,puVar5 + -0x290,&DAT_00795288)
    ;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    *(int **)(puVar5 + -0x28c) = &DAT_01b12d7c;
    FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b08,puVar5 + -0x290,&DAT_007952a8)
    ;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    *(float **)(puVar5 + -0x28c) = &DAT_00901e40;
    FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b04,puVar5 + -0x290,&DAT_007952c8)
    ;
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x290) = 4;
    *(float **)(puVar5 + -0x28c) = &DAT_00901e34;
    FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b04,puVar5 + -0x290,&DAT_007952e8)
    ;
    if (DAT_01b12d9c != 0) {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      *(undefined4 *)(puVar5 + -0x290) = 4;
      *(int **)(puVar5 + -0x28c) = &DAT_01b12d9c;
      FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b08,puVar5 + -0x290,
                   &DAT_00795308);
    }
    DAT_00901db0 = DAT_01b12dac;
    if (DAT_01b12dac == 0) {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b40,0,&DAT_0079532c);
    }
    if (DAT_00901db0 == 1) {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b40,0,&DAT_00795340);
    }
    if (DAT_00901db0 == 2) {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      FUN_005fc330(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b40,0,&DAT_00795358);
    }
    *(undefined4 *)(puVar5 + -0x288) = 0;
    FUN_005f7950(puVar5 + -0x288,DAT_00901d78,0x784ff00,&DAT_00766b38,0);
    if (DAT_00901dd4 == 7) {
      *(undefined4 *)(puVar5 + -0x160) = 0;
      goto LAB_004fede7;
    }
  }
  DAT_0078b4e8 = DAT_01b12dac;
  DAT_00795454 = DAT_01b12d6c;
  DAT_00795450 = (float)DAT_01b12d94;
  _DAT_007953fc = DAT_01b12d94;
  DAT_00795460 = DAT_01b12d80;
  DAT_0079546c = DAT_01b12d84;
  DAT_00795440 = DAT_01b12da4;
  if (DAT_01b12d70 == 0) {
    DAT_00795440 = 0xfffffffe;
  }
  DAT_00795444 = 0x46;
  _DAT_00901d9c = 1;
  if (DAT_01b12da8 == 0) {
    DAT_00795444 = 0x45;
    _DAT_00901d9c = 2;
  }
  DAT_01ba0d30 = DAT_01b12d78;
  DAT_01ba0d34 = DAT_01b12d7c;
  DAT_01be0954 = DAT_00901e34;
  _DAT_01be0950 = ram0x00766b74;
  if (DAT_01b12dac == 1) {
    _DAT_01be0950 = f_2_54;
  }
  else if (DAT_01b12dac == 2) {
    _DAT_01be0950 = f_72;
  }
  DAT_01be094c = DAT_00901e34 / _DAT_01be0950;
  DAT_00901da0 = DAT_00901e40;
  _DAT_01ade87c = DAT_00901e40 / DAT_01fb8c60;
  *(undefined4 *)(puVar5 + -0x15c) = 0;
code_r0x004fd732:
  _DAT_00901d68 = DAT_00901da0 * f_0_01;
  *(uint *)(puVar5 + -0x11c) = DAT_01ba0d84;
  DAT_00901db0 = 1;
  DAT_00901d58 = DAT_01ba0d30;
  uVar4 = DAT_01ba0d84;
  while (DAT_01be0940 = DAT_00901d58, 0 < (int)uVar4) {
    iVar7 = *(int *)(&DAT_01a75b1c + DAT_00901db0 * 4);
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    *(int *)(puVar5 + -0x28c) = iVar7;
    *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
    *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
    *(int *)(puVar5 + -0x28c) = (int)ROUND((float)*(int *)(puVar5 + -0x28c) * _DAT_00901d68 + f_0_5)
    ;
    in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
    DAT_00795464 = *(uint *)(puVar5 + -0x28c);
    (&DAT_01e9b0ec)[DAT_00901db0] = DAT_00795464;
    DAT_00901d58 = DAT_00795464 + DAT_01be0940;
    DAT_00901db0 = DAT_00901db0 + 1;
    *(int *)(puVar5 + -0x11c) = *(int *)(puVar5 + -0x11c) + -1;
    uVar4 = *(uint *)(puVar5 + -0x11c);
  }
  DAT_01e9b0f0 = (DAT_01ba0d30 + DAT_01e9b0f0) - DAT_01ba0d34;
  if (DAT_01fb8c60 == f_0) {
    DAT_01fb8c60 = unique0x1000135d;
  }
  if (DAT_01c58604 == 0) {
    DAT_01c58604 = 1;
  }
  *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
  *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
  *(int *)(puVar5 + -0x28c) = (int)ROUND(DAT_01be094c / ((float)DAT_01c58604 * DAT_00901da0));
  DAT_00795464 = *(uint *)(puVar5 + -0x28c);
  if (DAT_00795464 == 0) {
    DAT_00795464 = 1;
  }
  _DAT_00901d60 = DAT_01c58604;
  _DAT_00901d5c = DAT_00795464;
  DAT_01be0948 = 1;
  *(undefined2 *)(puVar5 + -0x290) = *(undefined2 *)(puVar5 + -0x290);
  *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
  *(int *)(puVar5 + -0x28c) = (int)ROUND((float)DAT_00901d58 / (float)DAT_01ade878 + f_0_6);
  in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
  DAT_01ba0d68 = *(uint *)(puVar5 + -0x28c);
  DAT_01be0944 = 30000;
  DAT_00901d54 = 0;
  _DAT_00901d64 = f_0;
  DAT_00901d88 = DAT_00795460;
  if (DAT_0078b4e0 == 0x55) {
    *(undefined4 *)(puVar5 + -0x118) = 0;
    thunk_FUN_004bbc93(&DAT_00901d50,&DAT_01a76ac0,&DAT_01e9b0f0,&DAT_01e99980,&DAT_01ba0d84,
                       &DAT_00901d4c);
    DAT_0078b4e0 = 0;
    if (DAT_00901d4c == 0) {
      *(undefined4 *)(puVar5 + -0x10c) = 0;
      goto LAB_004fdb26;
    }
    DAT_00901da4 = 1;
    if (DAT_01e99980 != 0) {
      *(undefined4 *)(puVar5 + -0x108) = 0;
      goto LAB_004fe938;
    }
  }
  else {
    if (DAT_00901da4 != 0) {
      *(undefined4 *)(puVar5 + -0x114) = 0;
      goto LAB_004fe938;
    }
    *(undefined4 *)(puVar5 + -0x110) = 0;
  }
  DAT_00795468 = DAT_00795460;
code_r0x004fda51:
  DAT_01b11800 = 1;
  DAT_00901da4 = 0;
  for (iVar7 = 1; iVar7 < 0x3e9; iVar7 = iVar7 + 1) {
    (&DAT_01b11800)[iVar7] = 0;
  }
  thunk_FUN_004b9c10(&DAT_01e9b0f0,&DAT_01ba0d84,&DAT_01e9d030,&DAT_01e9a150,&ITEM_P1,&DAT_01a76ac0,
                     &DAT_01e9c090);
LAB_004fdac3:
  DAT_01aea640 = 0;
  FUN_005f34d1(puVar5,0x4fdae8);
  for (iVar7 = 1; iVar7 < 0xb; iVar7 = iVar7 + 1) {
    *(undefined4 *)(iVar7 * 4 + 0x78d89c) = 0xffffffff;
  }
  thunk_FUN_00502f69();
  DAT_01be0960 = 0;
  *(undefined4 *)(puVar5 + -0x104) = 0;
LAB_004fdb26:
  DAT_01be0944 = 30000;
  DAT_01be0948 = 1;
  DAT_00795468 = DAT_00795460;
  _DAT_00901d48 = 0;
  DAT_00901d44 = 0;
  DAT_00901db0 = DAT_01ba0d68;
code_r0x004fdb64:
  DAT_01b12d68 = DAT_00795464;
  DAT_00901d40 = (int)DAT_01ba0d68 / (int)DAT_00795464;
  _DAT_00901d3c = (float)(int)DAT_01ba0d68;
  _DAT_00901d38 = (float)(int)DAT_00795464;
  DAT_00901db8 = _DAT_00901d3c / _DAT_00901d38;
  *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
  *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
  *(int *)(puVar5 + -0x28c) = (int)ROUND(DAT_00901db8 * f_100);
  in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
  _DAT_00901dd0 = *(uint *)(puVar5 + -0x28c);
  _DAT_00901d34 = (float)(int)_DAT_00901dd0 / f_100;
  if ((int)DAT_01ba0d68 % (int)DAT_00795464 != 0) {
    DAT_00901d40 = DAT_00901d40 + 1;
  }
  DAT_01b12d6c = DAT_00901d40;
  DAT_00901e38 = DAT_00901db8;
code_r0x004fdc41:
  thunk_FUN_00549422();
  if ((DAT_01c58610 == 1) || (DAT_01c58610 != 2)) {
    DAT_00901dd4 = thunk_FUN_00599bd0(&DAT_01b12d68,&DAT_00901e34);
    *(undefined4 *)(puVar5 + -0x100) = 0;
    goto LAB_004fdc9f;
  }
  DAT_01b12d64 = 1;
  _DAT_00901d30 = 0;
  _DAT_00901d2c = 1;
LAB_004fdd2a:
  while (DAT_00901dd4 = thunk_FUN_00599d30(&DAT_01b12d68,&DAT_00901e34), DAT_00901dd4 == 9999) {
    DAT_01ba0d40 = 0;
    *(undefined4 *)(puVar5 + -0xfc) = 0;
  }
  DAT_01ba0d5c = DAT_01b12d90;
  DAT_01ba0d48 = DAT_01b12d94;
  _DAT_00901d30 = DAT_01b12d98;
  _DAT_00901d28 = DAT_01b12d9c;
  DAT_01b12d64 = DAT_01b12da0;
  _DAT_01b12d60 = DAT_01b12da4;
  _DAT_00901d34 = DAT_00901e38;
LAB_004fdc9f:
  DAT_00795464 = DAT_01b12d68;
  DAT_00901d40 = DAT_01b12d6c;
  switch(DAT_00901dd4) {
  case 1:
    goto code_r0x004fe416;
  case 3:
    goto LAB_004fede7;
  case 4:
    goto DAT_004fddbf;
  case 5:
    FUN_004ff19c(&UNK_00766aec);
    *(undefined4 *)(puVar5 + -0xdc) = 0;
    goto code_r0x004fdc41;
  case 6:
    for (iVar7 = 1; iVar7 < 0x65; iVar7 = iVar7 + 1) {
      *(float *)(iVar7 * 4 + 0x1a72dbc) = f_0;
    }
    DAT_01a72dc0 = (float)DAT_00901d40;
    DAT_01a72dc4 = (float)(int)DAT_00795464;
    *(undefined4 *)(puVar5 + -0xd8) = 0;
    *(undefined4 *)(puVar5 + -0x4c) = 100;
    DAT_00901d4c = 1;
    do {
      fVar1 = *(float *)(DAT_00901d4c * 4 + 0x1a72dbc);
      *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
      *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
      *(int *)(puVar5 + -0x28c) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
      *(undefined4 *)(&DAT_01e9d02c + DAT_00901d4c * 4) = *(undefined4 *)(puVar5 + -0x28c);
      DAT_00901d4c = DAT_00901d4c + 1;
      *(int *)(puVar5 + -0x4c) = *(int *)(puVar5 + -0x4c) + -1;
    } while (0 < *(int *)(puVar5 + -0x4c));
    DAT_00901d80 = uRam01e9d034;
    iRam00901d10 = iRam01e9d038;
    DAT_00901d4c = iRam01e9d03c;
    goto code_r0x004fe76c;
  case 7:
    _DAT_00901d24 = 0x42;
    goto code_r0x004fe25d;
  case 8:
    DAT_00901d80 = func_0x00401faf();
    puVar6 = &DAT_009ae2bc;
    puVar8 = (undefined4 *)&DAT_020b8ea0;
    for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    if (DAT_00901d80 == 3) {
      *(undefined4 *)(puVar5 + -0xd4) = 0;
code_r0x004fde6b:
      _DAT_00901d24 = 0x44;
      *(undefined4 *)(puVar5 + -0x288) = 0;
      *(undefined4 *)(puVar5 + -0x2a0) = 9;
      *(char **)(puVar5 + -0x29c) = "bars-line";
      *(undefined4 *)(puVar5 + -0x298) = 3;
      *(undefined **)(puVar5 + -0x294) = &DAT_00766b1c;
      *(undefined4 *)(puVar5 + -0x290) = 2;
      uVar3 = FUN_005f6540(puVar5 + -0x288,7,0x784ff01,&DAT_00766b58,puVar5 + -0x2a0);
      *(undefined4 *)(puVar5 + -200) = uVar3;
      if (*(int *)(puVar5 + -200) == 0) {
        *(undefined4 *)(puVar5 + -0x288) = 0;
        *(undefined4 *)(puVar5 + -0x298) = 0x200;
        *(undefined2 **)(puVar5 + -0x294) = &DAT_020b8ea0;
        *(undefined4 *)(puVar5 + -0x290) = 1;
        uVar3 = FUN_005fdbd0(puVar5 + -0x288,7,0x784ff01,&DAT_00766adc,puVar5 + -0x298,0x79536c);
        *(undefined4 *)(puVar5 + -0xc4) = uVar3;
        if (*(int *)(puVar5 + -0xc4) == 0) {
          *(undefined4 *)(puVar5 + -0x288) = 0;
          FUN_005f7950(puVar5 + -0x288,7,0x784ff00,&DAT_00766b38,0);
          goto code_r0x004fdf99;
        }
      }
      FUN_005f33c9(puVar5,&UNK_004fe215);
      FUN_005f34d1(puVar5,&UNK_004fe230);
      *(undefined4 *)(puVar5 + -0x9c) = 0;
      goto code_r0x004fe3f6;
    }
    if ((DAT_00901d80 != 2) && ((char)DAT_020b8ea0 != '\0')) {
      if (DAT_00901d80 != 1) goto code_r0x004fde6b;
      *(undefined4 *)(puVar5 + -0xcc) = 0;
code_r0x004fdf99:
      for (iVar7 = 1; iVar7 < 0x3e9; iVar7 = iVar7 + 1) {
        (&DAT_01b11800)[iVar7] = 0;
      }
      thunk_FUN_0054eab7(&DAT_01b11804,&DAT_01b11800);
      if ((&DAT_01b11800)[DAT_01b11800] != 0) {
        DAT_01b11800 = DAT_01b11800 + 1;
      }
      DAT_01ba0d64 = 0;
      DAT_01ba0d60 = 99999;
      iRam00901d20 = 0;
      _DAT_00901dd0 = 0;
      iRam00901d18 = 0;
      *(undefined4 *)(puVar5 + -0xbc) = 1000;
      DAT_00901dd8 = 1;
      while( true ) {
        iRam00901d1c = 0;
        if ((&DAT_01b11800)[DAT_00901dd8] == 0) {
          if ((&DAT_01b11804)[DAT_00901dd8] != 0) {
            *(undefined4 *)(puVar5 + -0xb0) = 0;
            goto code_r0x004fe16e;
          }
          *(undefined4 *)(puVar5 + -0xb4) = 0;
          goto code_r0x004fe958;
        }
        *(undefined4 *)(puVar5 + -0xb8) = 0;
        _DAT_00901dd0 = (&DAT_01b11800)[DAT_00901dd8] + _DAT_00901dd0;
        iVar7 = (&DAT_01b11800)[DAT_00901dd8];
        *(int *)(puVar5 + -0xac) = iVar7;
        iRam00901d14 = 1;
        while (0 < iVar7) {
          iRam00901d18 = iRam00901d18 + 1;
          iRam00901d1c = (&DAT_01e9b0ec)[iRam00901d18] + iRam00901d1c;
          iRam00901d14 = iRam00901d14 + 1;
          *(int *)(puVar5 + -0xac) = *(int *)(puVar5 + -0xac) + -1;
          iVar7 = *(int *)(puVar5 + -0xac);
        }
        iRam00901d20 = iRam00901d20 + 1;
        (&DAT_01be0960)[iRam00901d20] = iRam00901d1c;
        if (DAT_01ba0d64 < iRam00901d1c) {
          DAT_01ba0d64 = iRam00901d1c;
        }
        if (iRam00901d1c < DAT_01ba0d60) {
          DAT_01ba0d60 = iRam00901d1c;
        }
        iRam00901d1c = 0;
        if (DAT_01ba0d84 == _DAT_00901dd0) break;
code_r0x004fe16e:
        iRam00901d1c = 0;
        if ((int)DAT_01ba0d84 < (int)_DAT_00901dd0) {
          *(undefined4 *)(puVar5 + -0xa4) = 0;
          goto code_r0x004fe958;
        }
        DAT_00901dd8 = DAT_00901dd8 + 1;
        *(int *)(puVar5 + -0xbc) = *(int *)(puVar5 + -0xbc) + -1;
        if (*(int *)(puVar5 + -0xbc) < 1) {
          FUN_005f33c9(puVar5,&UNK_004fe1c9);
          FUN_005f34d1(puVar5,&UNK_004fe1e4);
          *(undefined4 *)(puVar5 + -0xa0) = 0;
          goto code_r0x004fe3f6;
        }
      }
      *(undefined4 *)(puVar5 + -0xa8) = 0;
      break;
    }
    *(undefined4 *)(puVar5 + -0xd0) = 0;
    goto code_r0x004fdc41;
  case 9:
    DAT_0078b4e0 = 0x55;
    goto code_r0x004fd732;
  case 10:
    goto DAT_004fdcd9;
  case 0xb:
    DAT_00795468 = func_0x00403dfa();
    puVar6 = &DAT_009ae2bc;
    puVar8 = (undefined4 *)&DAT_020b8ea0;
    for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    FUN_004ff46b(&DAT_00795468,&DAT_01ba0d84,&DAT_01e9b0f0);
    if (DAT_00795468 < 1) {
      *(undefined4 *)(puVar5 + -0xf4) = 0;
      return;
    }
    DAT_01b11800 = DAT_00795468 + DAT_01b11800;
    *(undefined4 *)(puVar5 + -0xf0) = 0;
    break;
  default:
    _DAT_00901d24 = 0;
    *(undefined4 *)(puVar5 + -0xf8) = 0;
  case 2:
    DAT_01be0960 = DAT_00901d54;
    if (DAT_00901da4 == 0) {
      *(undefined4 *)(puVar5 + -0x68) = 0;
      goto LAB_004fcd49;
    }
    *(undefined4 *)(puVar5 + -0x6c) = 0;
LAB_004fe938:
    if (DAT_01ba0d84 != (&DAT_01e99974)[DAT_00901d4c]) {
      *(undefined4 *)(puVar5 + -0x30) = 0;
      goto code_r0x004fe958;
    }
    DAT_00795468 = DAT_00795460;
    DAT_00901d0c = 0;
    DAT_00901d08 = 1;
    DAT_00901d44 = 1;
    _DAT_00901d50 = f_0;
    DAT_00901d04 = 0;
    DAT_01b11800 = 1;
    while( true ) {
      _DAT_00901d48 = (&DAT_01e9997c)[DAT_00901d44] - DAT_00901d0c;
      DAT_01be0948 = DAT_00901d0c + 1;
      DAT_00901d0c = (&DAT_01e9997c)[DAT_00901d44];
      DAT_00901d00 = (&DAT_01e99980)[DAT_00901d44] / 100;
      DAT_00795464 = (&DAT_01e99980)[DAT_00901d44] % 100;
      DAT_01ba0d68 = DAT_00901d00 * DAT_00795464;
      DAT_01be0940 = 0;
      *(int *)(puVar5 + -0x2c) = _DAT_00901d48;
      DAT_00901cfc = DAT_01be0948;
      iVar7 = _DAT_00901d48;
      while (0 < iVar7) {
        DAT_01be0940 = (&DAT_01e9b0ec)[DAT_00901cfc] + DAT_01be0940;
        DAT_00901cfc = DAT_00901cfc + 1;
        *(int *)(puVar5 + -0x2c) = *(int *)(puVar5 + -0x2c) + -1;
        iVar7 = *(int *)(puVar5 + -0x2c);
      }
      *(int *)(puVar5 + -0x28c) = DAT_01be0948 * 4;
      thunk_FUN_004b9c10((int)&DAT_01e9b0ec + *(int *)(puVar5 + -0x28c),&DAT_00901d48,
                         &DAT_01e9d02c + DAT_00901d08 * 4,DAT_01be0948 * 4 + 0x1e9a14c,
                         &ITEM_LEN + DAT_01be0948,&DAT_01a76abc + DAT_01be0948 * 4,
                         DAT_01be0948 * 4 + 0x1e9c08c);
      DAT_00901d04 = DAT_01ba0d68 + DAT_00901d04;
      DAT_00901d44 = DAT_00901d44 + 2;
      if (DAT_00901d00 == 1) {
        *(undefined4 *)(puVar5 + -0x28) = 0;
      }
      else {
        DAT_00901cfc = DAT_01ba0d68 + DAT_00901d08 + 1;
        iVar7 = (int)((DAT_00795464 + DAT_00901d08) - DAT_00901cfc) / -1;
        *(int *)(puVar5 + -0x24) = iVar7;
        while (0 < iVar7) {
          *(undefined4 *)(&DAT_01e9d02c + DAT_00901cfc * 4) =
               *(undefined4 *)(&DAT_01c424f8 + DAT_00901cfc * 4);
          DAT_00901cfc = DAT_00901cfc + -1;
          *(int *)(puVar5 + -0x24) = *(int *)(puVar5 + -0x24) + -1;
          iVar7 = *(int *)(puVar5 + -0x24);
        }
        *(undefined4 *)(&DAT_01e9d02c + (DAT_00795464 + DAT_00901d08) * 4) = 0;
        DAT_00901d08 = DAT_00795464 + DAT_00901d08 + 1;
      }
      DAT_00901d08 = DAT_00795464 + DAT_00901d08 + 1;
      _DAT_00901d50 = (float)DAT_00901d00 + _DAT_00901d50;
      if (DAT_00901d4c <= (int)DAT_00901d44) break;
      *(undefined4 *)(puVar5 + -0x20) = 0;
    }
    DAT_01ba0d68 = DAT_00901d04;
    DAT_01be0940 = DAT_00901d58;
    *(undefined4 *)(puVar5 + -0x1c) = 0;
  }
  goto LAB_004fdac3;
LAB_004fc93e:
  *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
  *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
  *(int *)(puVar5 + -0x28c) = (int)ROUND(P2);
  in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
  DAT_00795470 = *(int *)(puVar5 + -0x28c);
  DAT_00795460 = DAT_00795470;
  if (DAT_00795470 < 1) {
    DAT_00795460 = 1;
  }
  *(undefined4 *)(puVar5 + -0x210) = 0;
  DAT_00901d88 = DAT_00795470;
  goto LAB_004fc8c1;
DAT_004fdcd9:
  func_0x00401fb4();
  if (DAT_0078b4e0 == 0x42) {
    *(undefined4 *)(puVar5 + -0xe8) = 0;
  }
  else {
    *(undefined4 *)(puVar5 + -0xec) = 0;
    DAT_01ba0d40 = 1;
    uRam00901dc0 = DAT_00901dcc;
    uRam00901dc2 = DAT_00901dce;
    *(undefined4 *)(puVar5 + -0xe4) = 0;
  }
  goto LAB_004fdd2a;
code_r0x004fe25d:
  DAT_00901d80 = func_0x004033c8();
  if (DAT_00901d80 == 2) goto code_r0x004fe2ae;
  puVar6 = &DAT_009ae2bc;
  puVar8 = (undefined4 *)&DAT_020b8ea0;
  for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
  }
  thunk_FUN_00518448();
  if ((DAT_00901d80 == 1) && ((char)DAT_020b8ea0 == '\0')) {
    *(undefined4 *)(puVar5 + -0x90) = 0;
    goto code_r0x004fe25d;
  }
  if (DAT_00901d80 == 3) {
    *(undefined4 *)(puVar5 + -0x288) = 0;
    *(undefined4 *)(puVar5 + -0x2a0) = 8;
    *(char **)(puVar5 + -0x29c) = "sys-pageBARS-LINE";
    *(undefined4 *)(puVar5 + -0x298) = 3;
    *(undefined **)(puVar5 + -0x294) = &DAT_00766b1c;
    *(undefined4 *)(puVar5 + -0x290) = 2;
    uVar3 = FUN_005f6540(puVar5 + -0x288,7,0x784ff01,&DAT_00766b58,puVar5 + -0x2a0);
    *(undefined4 *)(puVar5 + -0x88) = uVar3;
    if (*(int *)(puVar5 + -0x88) == 0) {
      *(undefined4 *)(puVar5 + -0x288) = 0;
      *(undefined4 *)(puVar5 + -0x298) = 0x200;
      *(undefined2 **)(puVar5 + -0x294) = &DAT_020b8ea0;
      *(undefined4 *)(puVar5 + -0x290) = 1;
      uVar3 = FUN_005fdbd0(puVar5 + -0x288,7,0x784ff01,&DAT_00766adc,puVar5 + -0x298,0x795380);
      *(undefined4 *)(puVar5 + -0x84) = uVar3;
      if (*(int *)(puVar5 + -0x84) == 0) {
        thunk_FUN_00518448();
        *(undefined4 *)(puVar5 + -0x288) = 0;
        FUN_005f7950(puVar5 + -0x288,7,0x784ff00,&DAT_00766b38,0);
        goto code_r0x004fe615;
      }
    }
    FUN_005f33c9(puVar5,&UNK_004fe3d7);
    FUN_005f34d1(puVar5,&UNK_004fe3f2);
code_r0x004fe3f6:
    thunk_FUN_0042ac4e(&DAT_020b90a0,0x80);
    *(undefined4 *)(puVar5 + -0x98) = 0;
    goto code_r0x004fdc41;
  }
  *(undefined4 *)(puVar5 + -0x8c) = 0;
code_r0x004fe615:
  for (iVar7 = 1; iVar7 < 0x65; iVar7 = iVar7 + 1) {
    *(float *)(iVar7 * 4 + 0x1a72dbc) = f_0;
  }
  thunk_FUN_0054c590(&P1,&DAT_01a72dc0,&DAT_00766ab0);
  *(undefined4 *)(puVar5 + -0x7c) = 0;
  DAT_00901d80 = 0;
  *(undefined4 *)(puVar5 + -0x58) = 100;
  DAT_00901d4c = 1;
  do {
    fVar1 = *(float *)(DAT_00901d4c * 4 + 0x1a72dbc);
    *(undefined2 *)(puVar5 + -0x290) = in_FPUControlWord;
    *(ushort *)(puVar5 + -0x28e) = (ushort)*(undefined4 *)(puVar5 + -0x290) | 0xc00;
    *(int *)(puVar5 + -0x28c) = (int)ROUND(fVar1);
    in_FPUControlWord = *(undefined2 *)(puVar5 + -0x290);
    iVar7 = *(int *)(puVar5 + -0x28c);
    if (iVar7 == 0) {
      *(undefined4 *)(puVar5 + -0x54) = 0;
      goto code_r0x004fe726;
    }
    DAT_00901d80 = iVar7 + DAT_00901d80;
    (&DAT_01be0960)[DAT_00901d4c] = iVar7;
    DAT_00901d4c = DAT_00901d4c + 1;
    *(int *)(puVar5 + -0x58) = *(int *)(puVar5 + -0x58) + -1;
  } while (0 < *(int *)(puVar5 + -0x58));
  DAT_00901d4c = 100;
code_r0x004fe726:
  DAT_00901d54 = DAT_00901d4c;
  DAT_01be0960 = DAT_00901d4c;
  _DAT_01e9d030 = 1;
  iRam00901d10 = 0;
  DAT_00901d4c = 0;
  _DAT_00901d5c = DAT_01be0964;
  *(undefined4 *)(puVar5 + -0x50) = 0;
code_r0x004fe76c:
  DAT_00795460 = DAT_00901d88;
  if ((iRam00901d10 == 0) && (DAT_00901d4c == 0)) {
    DAT_01ba0d68 = _DAT_01e9d030;
    DAT_00795464 = _DAT_00901d5c;
    if (DAT_00901d80 == 0) {
      *(undefined4 *)(puVar5 + -0x44) = 0;
      goto code_r0x004fda51;
    }
    DAT_00795464 = DAT_00901d80;
    DAT_01ba0d68 = DAT_00901d80 * _DAT_01e9d030;
    if ((int)DAT_01ba0d68 <= (int)DAT_01ba0d84) {
      *(undefined4 *)(puVar5 + -0x40) = 0;
      goto code_r0x004fda51;
    }
    DAT_01ba0d68 = DAT_00901db0;
  }
  else {
    *(undefined4 *)(puVar5 + -0x48) = 0;
    DAT_01b11800 = 0;
    iRam00901d10 = 0;
    *(undefined4 *)(puVar5 + -0x18) = 100;
    DAT_00901db0 = 100;
    do {
      DAT_00901d00 = *(int *)(&DAT_01e9d02c + DAT_00901db0 * 4);
      DAT_00901d44 = DAT_00901d00 + DAT_00901d44;
      if ((DAT_01b11800 != 0) && (DAT_00901d00 != 0)) {
        iRam00901d10 = iRam00901d10 + 1;
      }
      if ((DAT_00901d00 == 0) && (DAT_00901d44 == 0)) {
        DAT_01b11800 = DAT_00901db0;
      }
      DAT_00901db0 = DAT_00901db0 - 1;
      *(int *)(puVar5 + -0x18) = *(int *)(puVar5 + -0x18) + -1;
    } while (0 < *(int *)(puVar5 + -0x18));
    *(uint *)(puVar5 + -0x290) = DAT_01b11800 + 1;
    thunk_FUN_0054c4c6(&DAT_01e9d030,&DAT_01b11804,puVar5 + -0x290);
    if (DAT_01ba0d84 == DAT_00901d44) {
      *(undefined4 *)(puVar5 + -0x10) = 0;
      goto LAB_004fdac3;
    }
    *(undefined4 *)(puVar5 + -0x14) = 0;
  }
code_r0x004fe958:
  FUN_005f33c9(puVar5,0x4fe976);
  FUN_005f34d1(puVar5,0x4fe991);
  *(undefined4 *)(puVar5 + -0x288) = 0;
  *(undefined4 *)(puVar5 + -0x298) = 3;
  *(undefined4 *)(puVar5 + -0x294) = 0x20b90b6;
  *(undefined **)(puVar5 + -0x290) = &DAT_00901dd0;
  FUN_005f34f0(puVar5 + -0x288,0x784ff00,&DAT_00766a80,puVar5 + -0x298,&DAT_00795394);
  *(undefined4 *)(puVar5 + -0x288) = 0;
  *(undefined4 *)(puVar5 + -0x298) = 3;
  *(undefined4 *)(puVar5 + -0x294) = 0x20b90ba;
  *(uint **)(puVar5 + -0x290) = &DAT_01ba0d84;
  FUN_005f34f0(puVar5 + -0x288,0x784ff00,&DAT_00766a80,puVar5 + -0x298,&DAT_007953a8);
  thunk_FUN_0054d831(&DAT_020b90a0,0x200);
  *(undefined4 *)(puVar5 + -0x34) = 0;
  _DAT_00901d50 = (float)(int)DAT_01ba0d68 / (float)(int)DAT_00795464;
  goto LAB_004fdb26;
code_r0x004fe2ae:
  *(undefined4 *)(puVar5 + -0x94) = 0;
  goto code_r0x004fdc41;
DAT_004fddbf:
  FUN_004ff19c(&UNK_00766af0);
  *(undefined4 *)(puVar5 + -0xe0) = 0;
  goto code_r0x004fdc41;
code_r0x004fe416:
  func_0x00403959();
  if (ITEM_WORDS < 0) {
    *(undefined4 *)(puVar5 + -0xc) = 0;
    return;
  }
  if (DAT_0078b4e0 != 0x2d) goto LAB_004fede7;
  *(undefined4 *)(puVar5 + -8) = 0;
  goto code_r0x004fdb64;
}


