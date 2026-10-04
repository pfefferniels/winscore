// FUN_005644b8 @ 005644b8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x005652b2) */
/* WARNING: Removing unreachable block (ram,0x00565c7c) */
/* WARNING: Removing unreachable block (ram,0x00565fac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005644b8(void)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  bool bVar13;
  bool bVar14;
  undefined2 in_FPUControlWord;
  undefined2 uVar15;
  unkbyte10 in_ST0;
  float10 fVar16;
  unkbyte10 Var17;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  unkbyte10 extraout_ST0_02;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  float *pfStack_238;
  int local_1b4;
  int local_170;
  
  puVar9 = &stack0xfffffffc;
  puVar18 = &stack0xfffffffc;
  puVar7 = &stack0xfffffffc;
  puVar19 = &stack0xfffffffc;
  puVar20 = &stack0xfffffffc;
  DAT_01a1fe18 = 1;
  DAT_009a7b8c = DAT_02052740;
  DAT_00796fd0 = f_0;
  DAT_00796fd4 = f_0;
  if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x57) {
    pfStack_238 = (float *)0x564528;
    FUN_005f33c9();
    pfStack_238 = (float *)0x564543;
    fVar16 = (float10)FUN_005f34d1();
    if (P2 < f_0) {
      fVar16 = (float10)P2;
      P2 = (float)-fVar16;
      DAT_020b8ec6 = DAT_0076a004;
    }
    *(undefined4 *)(puVar9 + -0x20c) = 0;
    *(undefined4 *)(puVar9 + -0x220) = 4;
    *(undefined1 **)(puVar9 + -0x21c) = &DAT_020b8ea6;
    *(float **)(puVar9 + -0x218) = &P2;
    ffree(fVar16);
    in_ST0 = FUN_005f34f0(puVar9 + -0x20c,0x784ff00,&DAT_00769ffc,puVar9 + -0x220,&DAT_0079f630);
    puVar10 = (undefined4 *)&DAT_020b8ea0;
    puVar12 = (undefined4 *)&DAT_020b90a0;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    DAT_0078b4e4 = 0x46;
    *(undefined4 *)(puVar9 + -0x1e8) = 0;
    goto LAB_00566ca3;
  }
  if (DAT_0078b4e4 == 0x41) {
    ffree(in_ST0);
    pfStack_238 = (float *)0x566c99;
    in_ST0 = thunk_FUN_00555488();
    goto LAB_00566ca3;
  }
  if (DAT_0078b4e4 == 0x52) {
    DAT_01fbb8a0 = 0xb;
    DAT_01fbb8a4 = 0xb;
    goto LAB_00566ca3;
  }
  if (DAT_0078b4e4 == 0x59) {
    ffree(in_ST0);
    pfStack_238 = (float *)0x566c64;
    in_ST0 = FUN_00567e5b();
    goto LAB_00566ca3;
  }
  if (DAT_0078b4e4 == 0x49) {
    pfStack_238 = (float *)&DAT_009a7b7c;
    ffree(in_ST0);
    FUN_00602c70(&DAT_009a7b88,&DAT_009a7b84,&DAT_009a7b80);
    pfStack_238 = (float *)0x566ace;
    FUN_005f33c9();
    pfStack_238 = (float *)0x566ae9;
    Var17 = FUN_005f34d1();
    *(undefined4 *)(puVar20 + -0x20c) = 0;
    *(undefined4 *)(puVar20 + -0x220) = 2;
    *(undefined4 *)(puVar20 + -0x21c) = 0x9ae2c3;
    *(undefined **)(puVar20 + -0x218) = &DAT_009a7b88;
    ffree(Var17);
    Var17 = FUN_005f34f0(puVar20 + -0x20c,0x784ff00,&DAT_00769e88,puVar20 + -0x220,&DAT_0079f644);
    *(undefined4 *)(puVar20 + -0x20c) = 0;
    *(undefined4 *)(puVar20 + -0x220) = 2;
    *(undefined4 *)(puVar20 + -0x21c) = 0x9ae2c6;
    *(undefined **)(puVar20 + -0x218) = &DAT_009a7b84;
    ffree(Var17);
    Var17 = FUN_005f34f0(puVar20 + -0x20c,0x784ff00,&DAT_00769e88,puVar20 + -0x220,&DAT_0079f658);
    *(undefined4 *)(puVar20 + -0x20c) = 0;
    *(undefined4 *)(puVar20 + -0x220) = 2;
    *(undefined4 *)(puVar20 + -0x21c) = 0x9ae2ca;
    *(undefined **)(puVar20 + -0x218) = &DAT_009a7b80;
    ffree(Var17);
    Var17 = FUN_005f34f0(puVar20 + -0x20c,0x784ff00,&DAT_00769e88,puVar20 + -0x220,&DAT_0079f66c);
    *(undefined4 *)(puVar20 + -0x20c) = 0;
    *(undefined4 *)(puVar20 + -0x220) = 2;
    *(undefined4 *)(puVar20 + -0x21c) = 0x9ae2cd;
    *(undefined **)(puVar20 + -0x218) = &DAT_009a7b7c;
    ffree(Var17);
    in_ST0 = FUN_005f34f0(puVar20 + -0x20c,0x784ff00,&DAT_00769e88,puVar20 + -0x220,&DAT_0079f680);
    *(undefined4 *)(puVar20 + -0x1b8) = 0;
    goto LAB_00566ca3;
  }
  if ((_DAT_020b8ea0 & 0xffffff) == 0x445854) {
    local_1b4 = 0x1fd;
    DAT_009a7b78 = 4;
    do {
      if ((&DAT_020b909f)[DAT_009a7b78] != ' ') {
        if (((&DAT_020b909f)[DAT_009a7b78] == '[') || ((&DAT_020b909f)[DAT_009a7b78] == ']')) {
          pfStack_238 = (float *)0x22;
          ffree(in_ST0);
          in_ST0 = thunk_FUN_0054d831("Can\'t use [ or ] as text divider.");
        }
        else {
          DAT_0078b390 = (&DAT_020b8e9f)[DAT_009a7b78];
        }
        break;
      }
      DAT_009a7b78 = DAT_009a7b78 + 1;
      local_1b4 = local_1b4 + -1;
    } while (0 < local_1b4);
    goto LAB_00566ca3;
  }
  if ((_DAT_020b8ea0 & 0xffffff) == 0x4c5054) {
    _DAT_01b12c50 = f_0;
    pfStack_238 = (float *)0x5668c3;
    FUN_005f33c9();
    pfStack_238 = (float *)0x5668de;
    in_ST0 = FUN_005f34d1();
    *(undefined4 *)(puVar19 + -0x194) = 0x7d;
    DAT_009a7b78 = 4;
    do {
      if ((&DAT_020b8e9f)[DAT_009a7b78] == 'N') {
        _DAT_01b12c50 = f_1;
        pfStack_238 = (float *)0x56697f;
        FUN_005f33c9();
        pfStack_238 = (float *)0x56699a;
        in_ST0 = FUN_005f34d1();
        *(undefined4 *)(puVar19 + -0x18c) = 0;
        goto LAB_00566ca3;
      }
      *(undefined4 *)(puVar19 + -400) = 0;
      *(undefined4 *)(puVar19 + -0x188) = 0;
      DAT_009a7b78 = DAT_009a7b78 + 1;
      *(int *)(puVar19 + -0x194) = *(int *)(puVar19 + -0x194) + -1;
    } while (0 < *(int *)(puVar19 + -0x194));
    *(undefined4 *)(puVar19 + -0x184) = 0;
    goto LAB_00566ca3;
  }
  DAT_01a1c850 = DAT_0078b378;
  DAT_0078b378 = 0xb;
  if (DAT_0078b4e4 == 0x5a) {
    ffree(in_ST0);
    in_ST0 = thunk_FUN_00582b96(&DAT_009a7b78);
    P2 = (float)DAT_009a7b78;
  }
  if (P2 == f_0) {
    DAT_01fbb7f8 = 0;
    DAT_0078b378 = 199;
    ffree(in_ST0);
    pfStack_238 = (float *)0x564724;
    in_ST0 = thunk_FUN_00518448();
    DAT_009a7b78 = DAT_01fbb7e4;
    puVar7 = &stack0xfffffffc;
    if ((DAT_01fbb7fc != 0x1b) && (puVar7 = &stack0xfffffffc, DAT_01fbb7f8 < 0x3c)) {
      DAT_0078b378 = 0xb;
      if (DAT_01fbb7e4 == 0) {
        local_170 = 10;
        DAT_009a7b78 = 0xb;
        do {
          *(undefined4 *)(&P0 + DAT_009a7b78 * 4) =
               *(undefined4 *)(&DAT_020b9358 + DAT_009a7b78 * 4);
          DAT_009a7b78 = DAT_009a7b78 + -1;
          local_170 = local_170 + -1;
          puVar7 = &stack0xfffffffc;
        } while (0 < local_170);
      }
      else {
        pfStack_238 = (float *)&DAT_01fbb7ec;
        ffree(in_ST0);
        Var17 = FUN_005684e9(&DAT_01fbb7e8);
        ffree(Var17);
        pfStack_238 = (float *)0x5647ed;
        Var17 = thunk_FUN_00571d69();
        ffree(Var17);
        pfStack_238 = (float *)0x564802;
        fVar16 = (float10)anint();
        *(int *)(puVar18 + -0x210) = (int)ROUND(fVar16);
        DAT_009a7b78 = *(int *)(puVar18 + -0x210);
        if (DAT_009a7b78 < 3) {
          DAT_009a7b78 = 0;
        }
        P3 = (float)DAT_009a7b78;
        ffree(extraout_ST1);
        pfStack_238 = (float *)0x56484d;
        fVar16 = (float10)anint();
        *(int *)(puVar18 + -0x210) = (int)ROUND(fVar16);
        DAT_009a7b78 = *(int *)(puVar18 + -0x210) + 1;
        P4 = (float)DAT_009a7b78;
        puVar7 = puVar18;
        if ((DAT_01b1176c == 0x1b) || (DAT_01a1ad34 < DAT_01fbb7ec)) {
          *(undefined4 *)(puVar18 + -0x174) = 0;
          goto LAB_00566770;
        }
        P2 = (float)IP3;
        P5 = f_0;
        *(undefined4 *)(puVar18 + -0x170) = 0;
        in_ST0 = extraout_ST1_00;
      }
      goto LAB_005648b6;
    }
  }
  else {
LAB_005648b6:
    DAT_01a1c848 = P3;
    pfStack_238 = (float *)&DAT_00769ff8;
    ffree(in_ST0);
    fVar16 = (float10)amod(&DAT_01a1c848);
    P3 = (float)fVar16;
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x20) {
      P3 = f_100;
    }
    DAT_01c6da40 = 0;
    _DAT_009a7b70 = P3;
    if ((DAT_0078b4e4 == 0x43) && (DAT_01c6da40 = 1, (_DAT_020b8ea0 >> 0x10 & 0xff) == 0x58)) {
      DAT_01c6da40 = -1;
    }
    DAT_01a1c84c = 0;
    if (DAT_0078b4e4 == 0x54) {
      DAT_01a1c84c = ITEM_I + 1;
      _DAT_009a7b70 = f_1;
    }
    else {
      *(undefined4 *)(puVar7 + -0x168) = 0;
    }
    _DAT_01c4d118 = DAT_01a1c84c;
    if (P2 == f_0) {
      P2 = f_1;
    }
    *(undefined2 *)(puVar7 + -0x214) = in_FPUControlWord;
    *(ushort *)(puVar7 + -0x212) = (ushort)*(undefined4 *)(puVar7 + -0x214) | 0xc00;
    *(int *)(puVar7 + -0x210) = (int)ROUND(P2);
    uVar15 = *(undefined2 *)(puVar7 + -0x214);
    CUR_STAFF = *(int *)(puVar7 + -0x210);
    STEP = (float)(&STAFF_STEP0)[CUR_STAFF];
    Var17 = extraout_ST1_01;
    if (DAT_01a1c84c == 0) {
      *(undefined4 *)(puVar7 + -0x164) = 0;
LAB_00564a46:
      DAT_01a1c854 = ITEM_I + 1;
      if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x22) {
        pfStack_238 = (float *)0x1;
        ffree(Var17);
        Var17 = thunk_FUN_0054c473(&DAT_020b8ea0);
        *(undefined4 *)(puVar7 + -0x154) = 0x1ff;
        DAT_009a7b78 = 2;
        do {
          cVar1 = *(char *)((int)&DAT_01caea3c + DAT_009a7b78 + 3);
          _DAT_009a7b94 = CONCAT31(DAT_009a7b94_1,cVar1);
          if ((cVar1 == '~') && (*(char *)((int)&DAT_01caea40 + DAT_009a7b78) == '~')) {
            *(undefined4 *)(puVar7 + -0x150) = 0;
            goto LAB_00564ea0;
          }
          (&DAT_020b8e9e)[DAT_009a7b78] = cVar1;
          DAT_009a7b78 = DAT_009a7b78 + 1;
          *(int *)(puVar7 + -0x154) = *(int *)(puVar7 + -0x154) + -1;
        } while (0 < *(int *)(puVar7 + -0x154));
      }
      else {
        *(undefined4 *)(puVar7 + -0x158) = 0;
      }
      if (DAT_02052740 == 0) {
        *(undefined4 *)(puVar7 + -0x14c) = 5;
        DAT_009a7b6c = 2;
        do {
          *(undefined4 *)(DAT_009a7b6c * 4 + 0x9a7d94) = *(undefined4 *)(&P0 + DAT_009a7b6c * 4);
          DAT_009a7b6c = DAT_009a7b6c + 1;
          *(int *)(puVar7 + -0x14c) = *(int *)(puVar7 + -0x14c) + -1;
        } while (0 < *(int *)(puVar7 + -0x14c));
        ffree(Var17);
        thunk_FUN_0054c590(&P1,&DAT_020b9440,&DAT_00769fec);
        pfStack_238 = (float *)0x564bcc;
        FUN_005f33c9();
        pfStack_238 = (float *)0x564be7;
        FUN_005f34d1();
        while( true ) {
          pfStack_238 = (float *)0x564c09;
          FUN_005f33c9();
          pfStack_238 = (float *)0x564c24;
          Var17 = FUN_005f34d1();
          ffree(Var17);
          iVar5 = thunk_FUN_0059c000(&DAT_009a7d98);
          if (iVar5 == 2) {
            pfStack_238 = (float *)0x56662b;
            FUN_005f34d1();
            pfStack_238 = (float *)0x56664c;
            FUN_005f34d1();
            pfStack_238 = (float *)0x56666d;
            in_ST0 = FUN_005f34d1();
            *(undefined4 *)(puVar7 + -0x144) = 0;
            goto LAB_00566ca3;
          }
          *(undefined4 *)(puVar7 + -0x148) = 0;
          *(undefined4 *)(puVar7 + -0x140) = 5;
          DAT_009a7b6c = 2;
          do {
            *(undefined4 *)(&P0 + DAT_009a7b6c * 4) = *(undefined4 *)(DAT_009a7b6c * 4 + 0x9a7d94);
            DAT_009a7b6c = DAT_009a7b6c + 1;
            *(int *)(puVar7 + -0x140) = *(int *)(puVar7 + -0x140) + -1;
          } while (0 < *(int *)(puVar7 + -0x140));
          puVar10 = &DAT_009ae2bc;
          puVar12 = (undefined4 *)&DAT_020b8ea0;
          for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
          DAT_0078b390 = DAT_007a0b7c;
          if ((DAT_007a0b7c != 0x5b) && (DAT_007a0b7c != 0x5d)) break;
          pfStack_238 = (float *)0x22;
          ffree(extraout_ST0);
          thunk_FUN_0054d831("Can\'t use [ or ] as text divider.");
          DAT_0078b390 = DAT_00769fb0;
          *(undefined4 *)(puVar7 + -0x13c) = 0;
        }
        _DAT_009a7b70 = P3;
        *(undefined2 *)(puVar7 + -0x214) = uVar15;
        *(ushort *)(puVar7 + -0x212) = (ushort)*(undefined4 *)(puVar7 + -0x214) | 0xc00;
        *(int *)(puVar7 + -0x210) = (int)ROUND(P2);
        uVar15 = *(undefined2 *)(puVar7 + -0x214);
        CUR_STAFF = *(int *)(puVar7 + -0x210);
        STEP = (float)(&STAFF_STEP0)[CUR_STAFF];
        Var17 = extraout_ST0;
      }
      else {
        *(undefined4 *)(puVar7 + -0x20c) = 0;
        pfStack_238 = (float *)&DAT_0079f694;
        ffree(Var17);
        iVar5 = FUN_005fdbd0(puVar7 + -0x20c,DAT_02052740,0x784ff02,&DAT_00769fac,0);
        *(int *)(puVar7 + -0x138) = iVar5;
        Var17 = extraout_ST0_00;
        if (iVar5 == 0) {
          iVar5 = 0x200;
          DAT_009a7b68 = 1;
          do {
            *(undefined4 *)(puVar7 + -0x220) = 1;
            *(undefined1 **)(puVar7 + -0x21c) = &DAT_020b8e9f + DAT_009a7b68;
            *(undefined4 *)(puVar7 + -0x218) = 1;
            ffree(Var17);
            iVar6 = FUN_005fe110(puVar7 + -0x20c,&DAT_00769fa8,puVar7 + -0x220);
            *(int *)(puVar7 + -0x138) = iVar6;
            Var17 = extraout_ST0_01;
            if (iVar6 != 0) goto LAB_00564e80;
            DAT_009a7b68 = DAT_009a7b68 + 1;
            iVar5 = iVar5 + -1;
          } while (0 < iVar5);
          ffree(extraout_ST0_01);
          uVar3 = FUN_005fe110(puVar7 + -0x20c,&DAT_00769fa4,0);
          *(undefined4 *)(puVar7 + -0x138) = uVar3;
          Var17 = extraout_ST0_02;
        }
LAB_00564e80:
        if (*(int *)(puVar7 + -0x138) == -1) goto LAB_005666ce;
        puVar10 = (undefined4 *)&DAT_020b8ea0;
        puVar12 = &DAT_019c5e84;
        for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
      }
LAB_00564ea0:
      ffree(Var17);
      Var17 = thunk_FUN_0054c8e5(&DAT_020b8ea0,0x200,&DAT_01b12c7c);
      bVar13 = (undefined1 *)0xfffffffb < &pfStack_238;
      bVar14 = &stack0x00000000 == (undefined1 *)0x234;
      iVar5 = 1;
      pbVar8 = (byte *)&DAT_019c5e84;
      pbVar11 = &DAT_00769fa0;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar13 = *pbVar8 < *pbVar11;
        bVar14 = *pbVar8 == *pbVar11;
        pbVar8 = pbVar8 + 1;
        pbVar11 = pbVar11 + 1;
      } while (bVar14);
      if (bVar13 || bVar14) {
        puVar10 = (undefined4 *)&DAT_020b8ea0;
        puVar12 = &DAT_019c5e84;
        for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
      }
      DAT_01caea40 = 0;
      do {
        iVar5 = DAT_01caea40 + 1;
        if (*(char *)((int)&DAT_020b8ea0 + DAT_01caea40) == '_') {
          iVar6 = 1;
          bVar13 = true;
          bVar14 = false;
          pbVar8 = (byte *)((int)&DAT_020b8ea0 + DAT_01caea40 + 1);
          pbVar11 = &DAT_0076a004;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar14 = *pbVar8 < *pbVar11;
            bVar13 = *pbVar8 == *pbVar11;
            pbVar8 = pbVar8 + 1;
            pbVar11 = pbVar11 + 1;
          } while (bVar13);
          if (bVar14) {
LAB_0056510a:
            if (*(char *)((int)&DAT_020b8ea0 + DAT_01caea40 + 1) == '/') {
              DAT_01caea40 = DAT_01caea40 + 8;
              *(undefined4 *)(puVar7 + -300) = 0;
              goto LAB_00565340;
            }
            *(int *)(puVar7 + -0x220) = DAT_01caea40 + 4;
            iVar6 = (DAT_01b12c7c - *(int *)(puVar7 + -0x220)) + 3;
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            *(int *)(puVar7 + -0x224) = iVar6;
            puVar9 = puVar7 + -0x230;
            for (uVar4 = *(int *)(puVar7 + -0x224) + 7U & 0xfffffff8; 0x1000 < (int)uVar4;
                uVar4 = uVar4 - 0x1000) {
              puVar9 = puVar9 + -0x1000;
            }
            *(uint *)(puVar7 + -0x210) = (int)puVar9 - uVar4;
            *(int *)(puVar7 + -0x214) = DAT_01caea40 + 2;
            *(undefined4 *)(puVar7 + -0x21c) = 1;
            DAT_01caea40 = iVar5;
            while (*(int *)(puVar7 + -0x21c) <= *(int *)(puVar7 + -0x224)) {
              *(undefined1 *)(*(int *)(puVar7 + -0x21c) + *(int *)(puVar7 + -0x210) + -1) =
                   (&DAT_020b8e9f)[*(int *)(puVar7 + -0x214)];
              *(int *)(puVar7 + -0x214) = *(int *)(puVar7 + -0x214) + 1;
              *(int *)(puVar7 + -0x21c) = *(int *)(puVar7 + -0x21c) + 1;
            }
            *(undefined4 *)(puVar7 + -0x218) = *(undefined4 *)(puVar7 + -0x220);
            *(undefined4 *)(puVar7 + -0x21c) = 1;
            while (*(int *)(puVar7 + -0x21c) <= *(int *)(puVar7 + -0x224)) {
              (&DAT_020b8e9f)[*(int *)(puVar7 + -0x218)] =
                   *(undefined1 *)(*(int *)(puVar7 + -0x21c) + *(int *)(puVar7 + -0x210) + -1);
              *(int *)(puVar7 + -0x218) = *(int *)(puVar7 + -0x218) + 1;
              *(int *)(puVar7 + -0x21c) = *(int *)(puVar7 + -0x21c) + 1;
            }
            DAT_01b12c7c = DAT_01b12c7c + 2;
            *(undefined4 *)(puVar7 + -0x128) = 0;
          }
          else {
            iVar6 = 1;
            bVar14 = false;
            pbVar8 = (byte *)((int)&DAT_020b8ea0 + DAT_01caea40 + 1);
            pbVar11 = &DAT_00769f9c;
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar14 = *pbVar8 < *pbVar11;
              bVar13 = *pbVar8 == *pbVar11;
              pbVar8 = pbVar8 + 1;
              pbVar11 = pbVar11 + 1;
            } while (bVar13);
            if (!bVar14 && !bVar13) goto LAB_0056510a;
            *(undefined4 *)(puVar7 + -0x130) = 0;
            iVar6 = 1;
            pbVar8 = &DAT_020b8ea2 + DAT_01caea40;
            pbVar11 = &DAT_0076a004;
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar14 = *pbVar8 < *pbVar11;
              bVar13 = *pbVar8 == *pbVar11;
              pbVar8 = pbVar8 + 1;
              pbVar11 = pbVar11 + 1;
            } while (bVar13);
            if (!bVar14) {
              iVar6 = 1;
              pbVar8 = &DAT_020b8ea2 + DAT_01caea40;
              pbVar11 = &DAT_00769f9c;
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar14 = *pbVar8 < *pbVar11;
                bVar13 = *pbVar8 == *pbVar11;
                pbVar8 = pbVar8 + 1;
                pbVar11 = pbVar11 + 1;
              } while (bVar13);
              if (bVar14 || bVar13) {
                *(undefined4 *)(puVar7 + -0x124) = 0;
                DAT_01caea40 = iVar5;
                goto LAB_00565340;
              }
            }
            *(int *)(puVar7 + -0x220) = DAT_01caea40 + 4;
            iVar6 = (DAT_01b12c7c - *(int *)(puVar7 + -0x220)) + 2;
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            *(int *)(puVar7 + -0x224) = iVar6;
            puVar9 = puVar7 + -0x230;
            for (uVar4 = *(int *)(puVar7 + -0x224) + 7U & 0xfffffff8; 0x1000 < (int)uVar4;
                uVar4 = uVar4 - 0x1000) {
              puVar9 = puVar9 + -0x1000;
            }
            *(uint *)(puVar7 + -0x210) = (int)puVar9 - uVar4;
            *(int *)(puVar7 + -0x214) = DAT_01caea40 + 3;
            *(undefined4 *)(puVar7 + -0x21c) = 1;
            DAT_01caea40 = iVar5;
            while (*(int *)(puVar7 + -0x21c) <= *(int *)(puVar7 + -0x224)) {
              *(undefined1 *)(*(int *)(puVar7 + -0x21c) + *(int *)(puVar7 + -0x210) + -1) =
                   (&DAT_020b8e9f)[*(int *)(puVar7 + -0x214)];
              *(int *)(puVar7 + -0x214) = *(int *)(puVar7 + -0x214) + 1;
              *(int *)(puVar7 + -0x21c) = *(int *)(puVar7 + -0x21c) + 1;
            }
            *(undefined4 *)(puVar7 + -0x218) = *(undefined4 *)(puVar7 + -0x220);
            *(undefined4 *)(puVar7 + -0x21c) = 1;
            while (*(int *)(puVar7 + -0x21c) <= *(int *)(puVar7 + -0x224)) {
              (&DAT_020b8e9f)[*(int *)(puVar7 + -0x218)] =
                   *(undefined1 *)(*(int *)(puVar7 + -0x21c) + *(int *)(puVar7 + -0x210) + -1);
              *(int *)(puVar7 + -0x218) = *(int *)(puVar7 + -0x218) + 1;
              *(int *)(puVar7 + -0x21c) = *(int *)(puVar7 + -0x21c) + 1;
            }
            DAT_01b12c7c = DAT_01b12c7c + 1;
          }
          *(undefined4 *)(puVar7 + -0x234) = 0x5652d6;
          *(undefined1 **)(puVar7 + -0x238) = puVar7;
          *(undefined4 *)(puVar7 + -0x23c) = 0x5652d6;
          FUN_005f46bc();
          *(undefined4 *)(puVar7 + -0x234) = 0x5652ec;
          *(undefined4 *)(puVar7 + -0x238) = *(undefined4 *)(puVar7 + -0x238);
          *(undefined4 *)(puVar7 + -0x23c) = 0x5652ec;
          FUN_005f34d1();
          *(undefined4 *)(puVar7 + -0x234) = 0x56530e;
          *(undefined4 *)(puVar7 + -0x238) = *(undefined4 *)(puVar7 + -0x238);
          *(undefined4 *)(puVar7 + -0x23c) = 0x56530e;
          FUN_005f33c9();
          *(undefined4 *)(puVar7 + -0x234) = 0x565329;
          *(undefined4 *)(puVar7 + -0x238) = *(undefined4 *)(puVar7 + -0x238);
          *(undefined4 *)(puVar7 + -0x23c) = 0x565329;
          Var17 = FUN_005f34d1();
          puVar9 = *(undefined1 **)(puVar7 + -0x238);
          *(undefined4 *)(puVar7 + -0x234) = 0x200;
          *(char **)(puVar7 + -0x238) = &DAT_020b90a0;
          ffree(Var17);
          *(undefined4 *)(puVar7 + -0x23c) = 0x565340;
          Var17 = thunk_FUN_0054d831();
          puVar7 = puVar9;
        }
        else {
          *(undefined4 *)(puVar7 + -0x134) = 0;
          DAT_01caea40 = iVar5;
        }
LAB_00565340:
        if (DAT_01b12c7c <= DAT_01caea40) goto LAB_0056535d;
        *(undefined4 *)(puVar7 + -0x120) = 0;
      } while( true );
    }
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x52) {
      *(undefined4 *)(puVar7 + -0x160) = 0;
      goto LAB_00564a46;
    }
    ffree(extraout_ST1_01);
    pfStack_238 = (float *)0x564a2e;
    Var17 = FUN_00567bc7();
    if (-1 < DAT_0078b4e0) goto LAB_00564a46;
    *(undefined4 *)(puVar7 + -0x15c) = 0;
  }
LAB_00566770:
  *(undefined4 *)(puVar7 + -4) = 0;
  goto LAB_00566777;
LAB_0056535d:
  if (DAT_01b12c7c == 0) {
    if (DAT_01a1c84c == 0) {
      *(undefined4 *)(puVar7 + -0x118) = 0;
      goto LAB_00566730;
    }
    *(undefined4 *)(puVar7 + -0x114) = 0;
    goto LAB_005665b6;
  }
  *(undefined4 *)(puVar7 + -0x11c) = 0;
  while (DAT_0078b390 == (&DAT_020b8e9f)[DAT_01b12c7c]) {
    if (DAT_01b12c7c == 1) {
      *(undefined4 *)(puVar7 + -0x10c) = 0;
      goto LAB_00566730;
    }
    DAT_01b12c7c = DAT_01b12c7c + -1;
    *(undefined4 *)(puVar7 + -0x108) = 0;
  }
  *(undefined4 *)(puVar7 + -0x110) = 0;
  if (_DAT_009a7b70 == f_0) {
    DAT_01caea40 = 0;
    puVar10 = &DAT_009ae2bc;
    puVar12 = (undefined4 *)&DAT_020b90a0;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    if (DAT_02052740 != 0) {
      puVar10 = &DAT_019c5e84;
      puVar12 = (undefined4 *)&DAT_020b90a0;
      for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
    }
    *(int *)(puVar7 + -0x100) = DAT_01b12c7c;
    DAT_009a7b78 = 1;
    iVar6 = DAT_01caea40;
    iVar5 = DAT_01b12c7c;
    while (DAT_01b12c7c = iVar6, 0 < iVar5) {
      DAT_01caea40 = DAT_01b12c7c;
      if ((&DAT_020b909f)[DAT_009a7b78] == '-') {
        if ((&DAT_020b90a0)[DAT_009a7b78] == '-') {
          (&DAT_020b909f)[DAT_009a7b78] = 0x3f;
          (&DAT_020b90a0)[DAT_009a7b78] = 0x3f;
          *(undefined4 *)(puVar7 + -0xf4) = 0;
        }
        else {
          *(undefined4 *)(puVar7 + -0xf8) = 0;
          DAT_01caea40 = DAT_01b12c7c + 1;
          *(undefined1 *)((int)&DAT_020b8ea0 + DAT_01b12c7c) = 0x21;
          (&DAT_020b909f)[DAT_009a7b78] = 0x21;
        }
      }
      else {
        *(undefined4 *)(puVar7 + -0xfc) = 0;
      }
      puVar9 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01caea40);
      DAT_01caea40 = DAT_01caea40 + 1;
      *puVar9 = (&DAT_020b909f)[DAT_009a7b78];
      DAT_009a7b78 = DAT_009a7b78 + 1;
      *(int *)(puVar7 + -0x100) = *(int *)(puVar7 + -0x100) + -1;
      iVar6 = DAT_01caea40;
      iVar5 = *(int *)(puVar7 + -0x100);
    }
    puVar10 = (undefined4 *)&DAT_020b8ea0;
    puVar12 = &DAT_019c5e84;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    DAT_01caea40 = 0;
LAB_0056555d:
    do {
      iVar5 = DAT_01caea40 + 1;
      cVar1 = *(char *)((int)&DAT_020b8ea0 + DAT_01caea40);
      _DAT_009a7b94 = CONCAT31(DAT_009a7b94_1,cVar1);
      if ((((cVar1 == ']') || (cVar1 == '[')) || (cVar1 == '!')) || (cVar1 == '?')) {
        if (*(char *)((int)&DAT_020b8ea0 + DAT_01caea40 + 1) == cVar1) {
          if ((&DAT_020b8ea2)[DAT_01caea40] == cVar1) {
            *(undefined4 *)(puVar7 + -0xe8) = 0;
            DAT_01caea40 = iVar5;
            goto LAB_0056555d;
          }
          DAT_01caea48 = 1;
          if (iVar5 != 1) {
            DAT_01caea44 = DAT_01caea40;
            DAT_01caea40 = iVar5;
            goto LAB_00565650;
          }
          *(undefined4 *)(puVar7 + -0xe4) = 0;
          DAT_01caea40 = iVar5;
          while (DAT_01caea48 != 0) {
            DAT_01caea48 = DAT_01caea48 + -1;
            DAT_01caea40 = DAT_01caea40 + 2;
            DAT_01caea44 = DAT_01caea40;
            if (DAT_01b12c7c < DAT_01caea40) goto LAB_00565777;
            *(undefined4 *)(puVar7 + -0xd4) = 0;
LAB_00565650:
            if (DAT_0078b390 == (&DAT_020b8e9f)[DAT_01caea44]) {
              *(undefined4 *)(puVar7 + -0xe0) = 0;
            }
            else {
              DAT_009a7b78 = DAT_01b12c7c + 1;
              iVar5 = (DAT_01caea40 - DAT_009a7b78) / -1;
              *(int *)(puVar7 + -0xdc) = iVar5;
              DAT_01b12c7c = DAT_009a7b78;
              while (0 < iVar5) {
                (&DAT_020b8e9f)[DAT_009a7b78] = (&DAT_020b8e9e)[DAT_009a7b78];
                DAT_009a7b78 = DAT_009a7b78 + -1;
                *(int *)(puVar7 + -0xdc) = *(int *)(puVar7 + -0xdc) + -1;
                iVar5 = *(int *)(puVar7 + -0xdc);
              }
              (&DAT_020b8e9f)[DAT_01caea40] = DAT_0078b390;
              DAT_01caea40 = DAT_01caea40 + 1;
            }
          }
          *(undefined4 *)(puVar7 + -0xd8) = 0;
        }
        else {
          *(undefined4 *)(puVar7 + -0xec) = 0;
          DAT_01caea40 = iVar5;
        }
      }
      else {
        *(undefined4 *)(puVar7 + -0xf0) = 0;
        DAT_01caea40 = iVar5;
      }
LAB_00565777:
      if (DAT_01b12c7c <= DAT_01caea40) goto LAB_00565794;
      *(undefined4 *)(puVar7 + -0xd0) = 0;
    } while( true );
  }
  *(undefined4 *)(puVar7 + -0x104) = 0;
LAB_00565794:
  _DAT_009a7b64 = 0;
  DAT_0078b4f0 = 1;
  _DAT_009a7b60 = NPT;
  _DAT_01c4d11c = ITEM_WORDS;
  DAT_01b12c78 = 0;
  P1 = f_16;
  DAT_009a7b5c = 1;
  pfStack_238 = &f_100;
  ffree(Var17);
  fVar16 = (float10)amod(&P6);
  if (fVar16 == (float10)f_0) {
    P6 = P6 + f_1;
  }
  pfStack_238 = &f_100;
  ffree(extraout_ST1_02);
  fVar16 = (float10)amod(&P6);
  P48 = (float)fVar16;
  if (P5 == f_0) {
    P5 = f_1;
  }
  Var17 = extraout_ST1_03;
  if (_DAT_009a7b70 == f_0) {
    if ((P2 == f_0) && (DAT_020b90a0 == '\"')) {
      *(undefined4 *)(puVar7 + -200) = 0;
    }
    else {
      DAT_01c4d114 = 0;
      DAT_01c4d10c = 1;
      DAT_009a7b58 = 1;
      puVar10 = (undefined4 *)&DAT_020b8ea0;
      puVar12 = &DAT_009a7b98;
      for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      ffree(extraout_ST1_03);
      Var17 = thunk_FUN_0054c590(&P1,&DAT_01e60600,&DAT_00769f44);
      ffree(Var17);
      Var17 = thunk_FUN_00523c07(&DAT_00769f40);
      puVar10 = &DAT_009a7b98;
      puVar12 = (undefined4 *)&DAT_020b8ea0;
      for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      ffree(Var17);
      Var17 = thunk_FUN_0054c590(&DAT_01e60600,&P1,&DAT_00769f44);
      if (DAT_009a7b58 != 0) {
        *(undefined4 *)(puVar7 + -0xc4) = 0;
        goto LAB_00565980;
      }
      if (DAT_01b1176c == 0x1b) {
        *(undefined4 *)(puVar7 + -0xc0) = 0;
        goto LAB_00566770;
      }
      P3 = f_1;
    }
    _DAT_009a7b70 = f_1;
  }
  else {
    *(undefined4 *)(puVar7 + -0xcc) = 0;
  }
LAB_00565980:
  DAT_009a7b54 = ITEM_WORDS + 1;
  DAT_020b8e44 = 0;
  iVar5 = (DAT_01b12c7c - DAT_009a7b5c) + 1;
  *(int *)(puVar7 + -0xbc) = iVar5;
  DAT_01c4d110 = ITEM_WORDS;
  DAT_009a7b78 = DAT_009a7b5c;
  DAT_009a7b50 = DAT_01b12c7c;
  while (DAT_01b12c7c = DAT_009a7b50, 0 < iVar5) {
    cVar1 = (&DAT_020b8e9f)[DAT_009a7b78];
    DAT_009a7b94_1 = (undefined3)(_DAT_009a7b94 >> 8);
    _DAT_009a7b94 = CONCAT31(DAT_009a7b94_1,cVar1);
    if (_DAT_009a7b70 == f_0) {
      if (((cVar1 != ']') && (cVar1 != '[')) && ((cVar1 != '!' && (cVar1 != '?')))) {
        *(undefined4 *)(puVar7 + -0xb4) = 0;
        goto LAB_00565ae9;
      }
      if (*(char *)((int)&DAT_020b8ea0 + DAT_009a7b78) == cVar1) {
        DAT_020b8e44 = 1;
        DAT_01b12c78 = 1;
        if ((cVar1 == '?') || (cVar1 == ']')) {
          DAT_01b12c78 = -1;
          if (DAT_01c6da40 != 0) {
            *(float *)(&ITEM_P11 + DAT_01c4d114 * 4) = f_0;
          }
        }
        else {
          *(undefined4 *)(puVar7 + -0xac) = 0;
        }
        goto LAB_00565ae9;
      }
      *(undefined4 *)(puVar7 + -0xb0) = 0;
    }
    else {
      *(undefined4 *)(puVar7 + -0xb8) = 0;
LAB_00565ae9:
      if ((uint)DAT_0078b390 == (_DAT_009a7b94 & 0xff)) {
        if ((&DAT_020b8e9e)[DAT_009a7b78] != '_') {
          _DAT_01c4d118 = ITEM_I + 1;
          DAT_009a7b50 = DAT_009a7b78 + -1;
          *(undefined4 *)(puVar7 + -0xa0) = 0;
          break;
        }
        *(undefined4 *)(puVar7 + -0xa4) = 0;
      }
      else {
        *(undefined4 *)(puVar7 + -0xa8) = 0;
      }
    }
    *(undefined4 *)(puVar7 + -0x9c) = 0;
    DAT_009a7b78 = DAT_009a7b78 + 1;
    *(int *)(puVar7 + -0xbc) = *(int *)(puVar7 + -0xbc) + -1;
    DAT_009a7b50 = DAT_01b12c7c;
    iVar5 = *(int *)(puVar7 + -0xbc);
  }
  if (DAT_020b8e44 != 0) {
    if (DAT_01b12c7c <= DAT_009a7b50) {
      *(undefined4 *)(puVar7 + -0x94) = 0;
LAB_005660f6:
      IP1 = 4;
      DAT_009a7b40 = ITEM_WORDS;
      (&ITEM_P1)[ITEM_WORDS] = f_4;
      (&ITEM_P2)[DAT_009a7b40] = P2;
      (&ITEM_P3)[DAT_009a7b40] = P48 + P3;
      P3 = P48 * f_6_1 + P3;
      DAT_009a7b3c = 6;
      DAT_009a7b44 = P4;
      _DAT_009a7b38 = f_0;
      if (DAT_01b12c78 < 0) {
        *(undefined4 *)(puVar7 + -0x50) = 0;
      }
      else {
        DAT_009a7b44 = P48 * f_0_8 + P4;
        _DAT_009a7b38 = f_1;
        DAT_009a7b3c = 9;
        *(float *)(&ITEM_P7 + DAT_009a7b40 * 4) = f_1;
        if (DAT_0078b4a0 == 0) {
          *(undefined4 *)(puVar7 + -0x4c) = 0;
        }
        else {
          pfStack_238 = (float *)&DAT_00769ef8;
          ffree(Var17);
          Var17 = thunk_FUN_0054c419(&ITEM_P10 + DAT_009a7b40 * 4);
          *(float *)(&ITEM_P14 + DAT_009a7b40 * 4) = (float)DAT_0078b4a0;
          DAT_009a7b3c = 0xe;
        }
      }
      (&ITEM_LEN)[DAT_009a7b40] = (float)DAT_009a7b3c;
      (&ITEM_P4)[DAT_009a7b40] = DAT_009a7b44;
      (&ITEM_P5)[DAT_009a7b40] = DAT_009a7b44;
      ITEM_WORDS = DAT_009a7b3c + DAT_009a7b40 + 1;
      if (DAT_01c6da40 == 0) {
        *(undefined4 *)(puVar7 + -0x48) = 0;
      }
      else {
        DAT_009a7b78 = DAT_009a7b50 + 2;
        iVar5 = (DAT_01b12c7c - DAT_009a7b78) + 1;
        *(int *)(puVar7 + -0x44) = iVar5;
        while (0 < iVar5) {
          bVar2 = (&DAT_020b8e9f)[DAT_009a7b78];
          DAT_009a7b94_1 = (undefined3)(_DAT_009a7b94 >> 8);
          _DAT_009a7b94 = CONCAT31(DAT_009a7b94_1,bVar2);
          if (DAT_0078b390 == bVar2) {
            *(undefined4 *)(puVar7 + -0x40) = 0;
            break;
          }
          if ((*(byte *)((int)&DAT_020b8ea0 + DAT_009a7b78) == bVar2) &&
             (bVar2 == 0x21 || bVar2 == 0x5b)) {
            *(undefined4 *)(puVar7 + -0x3c) = 0;
            break;
          }
          if ((bVar2 == 0x3f) || (bVar2 == 0x5d)) {
            if (bVar2 == *(byte *)((int)&DAT_020b8ea0 + DAT_009a7b78)) {
              *(float *)(&ITEM_P11 + DAT_01c4d110 * 4) = f_0;
              *(undefined4 *)(puVar7 + -0x30) = 0;
              break;
            }
            *(undefined4 *)(puVar7 + -0x34) = 0;
          }
          else {
            *(undefined4 *)(puVar7 + -0x38) = 0;
          }
          *(undefined4 *)(puVar7 + -0x2c) = 0;
          DAT_009a7b78 = DAT_009a7b78 + 1;
          *(int *)(puVar7 + -0x44) = *(int *)(puVar7 + -0x44) + -1;
          iVar5 = *(int *)(puVar7 + -0x44);
        }
      }
      DAT_009a7b44 = (float)(&ITEM_P3)[DAT_01c4d110] + *(float *)(&ITEM_P11 + DAT_01c4d110 * 4);
      _DAT_009a7b34 = (float)(&ITEM_P3)[DAT_01c4d114] + *(float *)(&ITEM_P11 + DAT_01c4d114 * 4);
      if (DAT_009a7b40 <= DAT_01c4d110) {
        DAT_009a7b44 = f_9999;
      }
      if (DAT_01c4d114 == 0) {
        _DAT_009a7b34 = f_m9999;
      }
      ffree(Var17);
      Var17 = FUN_00568573(&DAT_009a7b34,&DAT_009a7b44,&DAT_01c4d114,&DAT_01c4d110,&P2,&DAT_009a7b38
                           ,&ITEM_P3 + DAT_009a7b40,&DAT_009a7b30,&ITEM_P6 + DAT_009a7b40,
                           &DAT_009a7b2c,&DAT_009a7b28);
      DAT_01b12c78 = 0;
      if (DAT_009a7b3c < 9) {
        *(undefined4 *)(puVar7 + -0x28) = 0;
      }
      else {
        *(undefined4 *)(&ITEM_P8 + DAT_009a7b40 * 4) = DAT_009a7b2c;
        *(undefined4 *)(&ITEM_P9 + DAT_009a7b40 * 4) = DAT_009a7b28;
      }
      if (DAT_009a7b50 < DAT_01b12c7c) {
        *(undefined4 *)(puVar7 + -0x24) = 0;
        goto LAB_005664f6;
      }
      goto LAB_00566542;
    }
    DAT_009a7b5c = DAT_009a7b50 + 2;
    *(undefined4 *)(puVar7 + -0x90) = 0;
    goto LAB_00565980;
  }
  *(undefined4 *)(puVar7 + -0x98) = 0;
  _DAT_009a7b4c = 0xb;
  if (P14 == f_m1) {
    _DAT_009a7b4c = 0x10;
  }
  ffree(Var17);
  Var17 = thunk_FUN_0054c590(&P1,&ITEM_LEN + DAT_009a7b54,&DAT_009a7b4c);
  DAT_020b8e44 = DAT_009a7b54 * 4 + 0x31;
  if (P14 == f_m1) {
    DAT_020b8e44 = DAT_009a7b54 * 4 + 0x3d;
  }
  DAT_01c4d104 = DAT_020b8e44;
  if ((&DAT_020b8e9f)[DAT_009a7b5c] == '_') {
    *(undefined4 *)(puVar7 + -0x8c) = 0;
  }
  else {
    pfStack_238 = (float *)0x565ca0;
    FUN_005f46bc();
    pfStack_238 = (float *)0x565cb6;
    Var17 = FUN_005f34d1();
    DAT_020b8e44 = DAT_020b8e44 + 3;
  }
  iVar5 = (DAT_009a7b50 - DAT_009a7b5c) + 1;
  *(int *)(puVar7 + -0x88) = iVar5;
  DAT_009a7b78 = DAT_009a7b5c;
  while (0 < iVar5) {
    *(undefined1 *)((int)&ITEM_LEN + DAT_020b8e44 + 3) = (&DAT_020b8e9f)[DAT_009a7b78];
    DAT_020b8e44 = DAT_020b8e44 + 1;
    DAT_009a7b78 = DAT_009a7b78 + 1;
    *(int *)(puVar7 + -0x88) = *(int *)(puVar7 + -0x88) + -1;
    iVar5 = *(int *)(puVar7 + -0x88);
  }
  while (s_______09___InchesMetricParallel_P_0078da40[0] ==
         *(char *)((int)&ITEM_LEN + DAT_020b8e44 + 2)) {
    DAT_020b8e44 = DAT_020b8e44 + -1;
    *(undefined4 *)(puVar7 + -0x80) = 0;
  }
  *(undefined4 *)(puVar7 + -0x84) = 0;
  *(char *)((int)&ITEM_LEN + DAT_020b8e44 + 3) = s_______09___InchesMetricParallel_P_0078da40[0];
  *(char *)((int)&ITEM_P1 + DAT_020b8e44) = s_______09___InchesMetricParallel_P_0078da40[0];
  *(char *)((int)&ITEM_P1 + DAT_020b8e44 + 1) = s_______09___InchesMetricParallel_P_0078da40[0];
  DAT_009a7b78 = DAT_020b8e44 - DAT_01c4d104;
  DAT_01c4d108 = DAT_009a7b78;
  *(float *)(&ITEM_P12 + DAT_01c4d110 * 4) = (float)DAT_009a7b78;
  _DAT_009a7b48 = 0xd;
  if (*(float *)(&ITEM_P14 + DAT_01c4d110 * 4) == f_m1) {
    _DAT_009a7b48 = 0x10;
  }
  DAT_009a7b78 = (DAT_009a7b78 + 3) / 4 + _DAT_009a7b48;
  (&ITEM_LEN)[DAT_01c4d110] = (float)DAT_009a7b78;
  ITEM_WORDS = DAT_009a7b78 + DAT_01c4d110 + 1;
  *(undefined2 *)(puVar7 + -0x214) = uVar15;
  *(ushort *)(puVar7 + -0x212) = (ushort)*(undefined4 *)(puVar7 + -0x214) | 0xc00;
  *(int *)(puVar7 + -0x210) = (int)ROUND(P8);
  uVar15 = *(undefined2 *)(puVar7 + -0x214);
  IP8 = *(int *)(puVar7 + -0x210);
  DAT_009a7b44 = DAT_020b9470;
  ffree(Var17);
  Var17 = text_parse(DAT_01c4d104 + 0x205343f,1,&DAT_01c4d108);
  DAT_020b9470 = DAT_009a7b44;
  (&ITEM_P13)[DAT_01c4d110] = P13;
  iVar5 = DAT_01c4d110;
  if (f_700 <= DAT_01a1c848) {
    pfStack_238 = (float *)&DAT_00769ff8;
    ffree(Var17);
    fVar16 = (float10)amod(&DAT_01a1c848);
    (&ITEM_P3)[iVar5] = (float)(fVar16 - (float10)P13 / (float10)f_2);
  }
  DAT_01c4d108 = DAT_020b8e44 + -1;
  DAT_009a7b78 = DAT_020b8e44;
  while (*(char *)((int)&ITEM_LEN + DAT_009a7b78 + 3) != '_') {
    DAT_009a7b78 = DAT_009a7b78 + -1;
    if (DAT_009a7b78 < DAT_01c4d104) goto LAB_00565f92;
    *(undefined4 *)(puVar7 + -0x78) = 0;
  }
  *(undefined4 *)(puVar7 + -0x7c) = 0;
LAB_00565f92:
  pfStack_238 = (float *)0x565fce;
  FUN_005f46bc();
  pfStack_238 = (float *)0x565fe4;
  Var17 = FUN_005f34d1();
  if (_DAT_009a7b70 == f_0) {
    *(undefined4 *)(puVar7 + -0x74) = 0;
    if (P13 == f_0) {
      if (_DAT_009a7b70 != f_0) {
        pfStack_238 = (float *)0x2a;
        ffree(Var17);
        Var17 = thunk_FUN_0054d831(&DAT_00769f08);
      }
      *(undefined4 *)(puVar7 + -100) = 0;
    }
    else {
      *(undefined4 *)(puVar7 + -0x68) = 0;
      _DAT_009a7b60 = 1;
      DAT_0078b378 = 0x6f;
      ffree(Var17);
      pfStack_238 = (float *)0x56603d;
      Var17 = FUN_00566cb2();
      if (IP1 == -999) {
        *(undefined4 *)(puVar7 + -0x60) = 0;
        goto LAB_00566783;
      }
      if (DAT_0078dd50 != 0) {
        DAT_0078dd50 = 0;
        *(undefined4 *)(puVar7 + -0x5c) = 0;
        goto LAB_00566730;
      }
      if (DAT_01b12c78 != 0) {
        *(undefined4 *)(puVar7 + -0x58) = 0;
        goto LAB_005660f6;
      }
    }
    IP1 = 0;
    *(undefined4 *)(puVar7 + -0x54) = 0;
  }
  if (DAT_009a7b50 < DAT_01b12c7c) {
    P3 = P13 + P3 + f_2;
LAB_005664f6:
    DAT_009a7b5c = DAT_009a7b50 + 2;
    DAT_01c4d114 = DAT_01c4d110;
    *(undefined4 *)(puVar7 + -0x6c) = 0;
    goto LAB_00565980;
  }
  *(undefined4 *)(puVar7 + -0x70) = 0;
LAB_00566542:
  ITEM_I = DAT_01a1c854;
  if (DAT_02052740 == 0) {
    DAT_009a7b24 = DAT_01a1c848;
    ffree(Var17);
    pfStack_238 = (float *)0x566573;
    Var17 = draw_items();
    ffree(Var17);
    pfStack_238 = (float *)0x56657a;
    Var17 = thunk_FUN_00549422();
    DAT_01a1c848 = DAT_009a7b24;
  }
  else {
    *(undefined4 *)(puVar7 + -0x20) = 0;
  }
  DAT_020527e8 = ITEM_I;
  DAT_01fbb8a0 = 0xffffff9d;
LAB_005665b6:
  if (DAT_01a1c84c == 0) goto LAB_005666c7;
  P4 = P4 - (P48 * STEP * f_5) / f_25;
  pfStack_238 = (float *)&DAT_00769ff8;
  ffree(Var17);
  fVar16 = (float10)amod(&DAT_01a1c848);
  P3 = (float)fVar16;
  *(undefined4 *)(puVar7 + -0x18) = 0;
  Var17 = extraout_ST1_04;
  goto LAB_00564a46;
LAB_005666c7:
  *(undefined4 *)(puVar7 + -0x1c) = 0;
LAB_005666ce:
  if (DAT_02052740 == 0) {
    *(undefined4 *)(puVar7 + -0x14) = 0;
    *(undefined4 *)(puVar7 + -0x20c) = 0;
    ffree(Var17);
    FUN_005f7950(puVar7 + -0x20c,0,0x784ff00,&DAT_00769ee0,0);
    DAT_02052740 = 0;
  }
  else {
    ffree(Var17);
    pfStack_238 = (float *)0x566722;
    Var17 = draw_items();
    ffree(Var17);
    pfStack_238 = (float *)0x566729;
    thunk_FUN_00549422();
    *(undefined4 *)(puVar7 + -0x10) = 0;
  }
LAB_00566730:
  pfStack_238 = (float *)0x56674d;
  FUN_005f34d1();
  *(undefined4 *)(puVar7 + -8) = 0;
LAB_00566777:
  DAT_0078b378 = DAT_01a1c850;
LAB_00566783:
  P2 = f_0;
  pfStack_238 = (float *)0x5667ac;
  FUN_005f34d1(puVar7);
  DAT_01fbb8a0 = 0;
  pfStack_238 = (float *)0x5667d5;
  Var17 = FUN_005f34d1(puVar7);
  if ((DAT_0078d890 != 0) && (DAT_0078d890 = 0, IP1 != -999)) {
    ffree(Var17);
    pfStack_238 = (float *)0x5667fd;
    draw_items();
  }
  DAT_02052740 = DAT_009a7b8c;
  if (DAT_009a7b8c == 0) {
    pfStack_238 = (float *)0x566830;
    FUN_005f33c9(puVar7);
    pfStack_238 = (float *)0x56684b;
    FUN_005f34d1(puVar7);
  }
  pfStack_238 = (float *)0x56686d;
  FUN_005f33c9(puVar7);
  pfStack_238 = (float *)0x566888;
  in_ST0 = FUN_005f34d1(puVar7);
  DAT_0078b4e0 = 0;
LAB_00566ca3:
  ffree(in_ST0);
  return;
}


