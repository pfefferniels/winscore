// input_main @ 0052c6a0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void input_main(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined2 in_FPUControlWord;
  undefined2 uVar8;
  unkbyte10 in_ST0;
  unkbyte10 Var9;
  float10 fVar10;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  
  puVar2 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  DAT_00796fd4 = DAT_01fbb8b8;
  DAT_01a1fe18 = ITEM_I;
  if (-1 < DAT_02052740) {
    ffree(in_ST0);
    Var9 = push_words(&DAT_00768298,&P1);
    DAT_00999fe4 = PAPER;
    if (PAPER == 0) goto LAB_0052c7c1;
    PAPER = 0;
    ffree(Var9);
    Var9 = draw_items();
    ffree(Var9);
    Var9 = thunk_FUN_00549422();
    ffree(Var9);
    Var9 = pop_words(&DAT_00768298,&P1);
    puVar1 = &stack0xfffffffc;
    goto LAB_0052c7c1;
  }
  DAT_00999fe8 = 0;
  ffree(in_ST0);
  Var9 = thunk_FUN_00530dd8(&DAT_00999fe8);
  if (DAT_020b90a0 != '^') {
LAB_0052e07c:
    DAT_01fbb700 = 0;
    ffree(Var9);
    return;
  }
  if ((char)DAT_020b8ea0 != '$') {
    DAT_020b8ea0 = CONCAT11(DAT_020b8ea0._1_1_,DAT_0076829c);
    goto LAB_0052d811;
  }
  ffree(Var9);
  Var9 = FUN_0052f62e(&DAT_007682a0);
  puVar2 = &stack0xfffffffc;
LAB_0052dbdc:
  DAT_01fbb700 = 0;
  DAT_0078d890 = 0;
  ffree(Var9);
  Var9 = draw_items();
  ffree(Var9);
  Var9 = thunk_FUN_00549422();
  ffree(Var9);
  Var9 = thunk_FUN_00468df8(&DAT_00768194);
  ffree(Var9);
  Var9 = thunk_FUN_0054943a();
  ffree(Var9);
  Var9 = thunk_FUN_0054946a(&DAT_0076817c,0x16);
  DAT_0171b230 = 0xffffffff;
  *(undefined4 *)(puVar2 + -0x34) = 0;
LAB_0052dc3a:
  do {
    DAT_009ae4bc = 0;
    DAT_01fbb700 = 0;
    DAT_01f9a6f4 = 0;
    if (DAT_00999fe4 != 0) {
      PAPER = DAT_00999fe4;
      ffree(Var9);
      Var9 = draw_items();
    }
    if ((((DAT_020b90a0 == '^') || ((char)DAT_020b8ea0 == '^')) || (DAT_020b90a0 == 'I')) ||
       (DAT_020b90a0 == 'i')) {
      *(undefined4 *)(puVar2 + -0x28) = 0;
      goto LAB_0052e07c;
    }
    if (((DAT_00796fac != 0) || (DAT_02052740 != 0)) || ((char)DAT_020b8ea0 == 'A')) {
      *(undefined4 *)(puVar2 + -0x24) = 0;
      goto LAB_0052e07c;
    }
    *(int *)(puVar2 + -0x20) = ITEM_I;
    DAT_00999fe8 = 1;
    iVar4 = ITEM_I;
    while (0 < iVar4) {
      DAT_00999fac = (&ITEM_PTR0)[DAT_00999fe8];
      DAT_0079483c = (float)(&ITEM_P1)[DAT_00999fac];
      if (((DAT_0079483c < f_14) && (DAT_0079483c != f_3)) &&
         ((DAT_0079483c != f_8 &&
          (*(int *)(puVar2 + -0x158) = DAT_00999fe0 + 1,
          (float)*(int *)(puVar2 + -0x158) == (float)(&ITEM_P2)[DAT_00999fac])))) {
        *(undefined4 *)(puVar2 + -0x1c) = 0;
        goto LAB_0052e07c;
      }
      DAT_00999fe8 = DAT_00999fe8 + 1;
      *(int *)(puVar2 + -0x20) = *(int *)(puVar2 + -0x20) + -1;
      iVar4 = *(int *)(puVar2 + -0x20);
    }
    FUN_005f33c9(puVar2,0x52dde2);
    Var9 = FUN_005f34d1(puVar2,0x52ddfd);
    *(undefined4 *)(puVar2 + -0x154) = 0;
    *(undefined4 *)(puVar2 + -0x168) = 3;
    *(undefined4 **)(puVar2 + -0x164) = &DAT_020b8eb8;
    *(int *)(puVar2 + -0x160) = DAT_00999fe0 + 1;
    ffree(Var9);
    Var9 = FUN_005f34f0(puVar2 + -0x154,0x784ff00,&DAT_00768150,puVar2 + -0x168,&DAT_00796f0c);
    ffree(Var9);
    DAT_00999fe8 = thunk_FUN_00596010(&DAT_020b8ea0,1);
    DAT_00796fac = DAT_009a9494;
    if (-1 < DAT_00999fe8) {
      *(undefined4 *)(puVar2 + -0x14) = 0;
      Var9 = extraout_ST0_00;
      goto LAB_0052e07c;
    }
    FUN_005f33c9(puVar2,0x52deb8);
    Var9 = FUN_005f34d1(puVar2,0x52ded3);
    if (DAT_00999fdc != 0) {
      DAT_020b8ea2 = DAT_0076819c;
    }
    *(int *)(puVar2 + -0x10) = ITEM_I;
    LOAD_I = 1;
    iVar4 = ITEM_I;
    while (0 < iVar4) {
      ffree(Var9);
      Var9 = load_item_header();
      if ((LOAD_CODE == 8) && (DAT_00999fe0 == LOAD_STAFF)) {
        *(undefined4 *)(puVar2 + -0xc) = 0;
        break;
      }
      LOAD_I = LOAD_I + 1;
      *(int *)(puVar2 + -0x10) = *(int *)(puVar2 + -0x10) + -1;
      iVar4 = *(int *)(puVar2 + -0x10);
    }
    *(int *)(puVar2 + -0x158) = DAT_00999fe0 + 1;
    P2 = (float)*(int *)(puVar2 + -0x158);
    P3 = LOAD_P3;
    P4 = f_0;
    P5 = (float)(&ITEM_P5)[LOAD_W];
    P6 = f_0;
    if (5 < LOAD_LEN) {
      P6 = (float)(&ITEM_P6)[LOAD_W];
    }
    iVar4 = 2;
    for (iVar7 = 1; iVar7 < 6; iVar7 = iVar7 + 1) {
      *(undefined4 *)(puVar2 + iVar7 * 4 + -0x16c) = *(undefined4 *)(&P0 + iVar4 * 4);
      iVar4 = iVar4 + 1;
    }
    *(undefined4 *)(puVar2 + -0x154) = 0;
    *(undefined4 *)(puVar2 + -0x178) = 0x25;
    *(undefined1 **)(puVar2 + -0x174) = &DAT_020b8ea3;
    *(undefined4 *)(puVar2 + -0x170) = 0x14;
    *(undefined1 **)(puVar2 + -0x16c) = puVar2 + -0x168;
    ffree(Var9);
    Var9 = FUN_005f34f0(puVar2 + -0x154,0x784ff00,&DAT_00768140,puVar2 + -0x178,&DAT_00796f20);
    ffree(Var9);
    Var9 = thunk_FUN_00518448();
    *(undefined4 *)(puVar2 + -4) = 0;
    puVar1 = puVar2;
LAB_0052c7c1:
    ffree(Var9);
    FUN_0052f62e(&DAT_00768294);
    DAT_00794840 = 0;
    for (iVar4 = 1; iVar4 < 0x181; iVar4 = iVar4 + 1) {
      (&DAT_01a1f7d3)[iVar4] = 0x20;
    }
    for (iVar4 = 1; iVar4 < 0x181; iVar4 = iVar4 + 1) {
      *(undefined1 *)(iVar4 + 0x1a1f953) = 0x20;
    }
    for (iVar4 = 1; iVar4 < 0x181; iVar4 = iVar4 + 1) {
      *(undefined1 *)(iVar4 + 0x1a1fad3) = 0x20;
    }
    puVar2 = puVar1;
    Var9 = FUN_005f34d1(puVar1,0x52c865);
    DAT_009ae4bc = 1;
    DAT_01fb8c74 = 0;
    DAT_01fb8cc0 = 0;
    DAT_01a1f480 = 0;
    DAT_0078dec0 = 0x1c;
    DAT_00791448 = ITEM_I + 1;
    DAT_01a14954 = 0x20202020;
    DAT_0078dec4 = 0xffffffff;
    puVar3 = (undefined4 *)&DAT_020b90a0;
    puVar5 = (undefined4 *)&DAT_020b8ea0;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    DAT_0078d938 = 0;
    if (DAT_020b8ea0 != 0x5053) {
      puVar3 = (undefined4 *)&DAT_020b8ea0;
      puVar5 = &DAT_01a1f484;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    DAT_0078dd60 = 1;
    *(undefined2 *)(puVar2 + -0x15c) = in_FPUControlWord;
    *(ushort *)(puVar2 + -0x15a) = (ushort)*(undefined4 *)(puVar2 + -0x15c) | 0xc00;
    *(int *)(puVar2 + -0x158) = (int)ROUND(P2);
    uVar8 = *(undefined2 *)(puVar2 + -0x15c);
    CUR_STAFF = *(int *)(puVar2 + -0x158);
    _DAT_00999ff0 = -(uint)(DAT_0078d894 < _DAT_01fb8c64);
    if (P2 <= f_0) {
      ffree(Var9);
      Var9 = FUN_0052f485();
    }
    *(undefined2 *)(puVar2 + -0x15c) = uVar8;
    *(ushort *)(puVar2 + -0x15a) = (ushort)*(undefined4 *)(puVar2 + -0x15c) | 0xc00;
    *(int *)(puVar2 + -0x158) = (int)ROUND(P2);
    in_FPUControlWord = *(undefined2 *)(puVar2 + -0x15c);
    DAT_00999fe0 = *(int *)(puVar2 + -0x158);
    DAT_01fb8c60 = P2;
    if (MAX_STAFF < DAT_00999fe0) {
      *(undefined4 *)(puVar2 + -0x124) = 0;
    }
    else {
      if (DAT_020b8ea2 == 'Z') {
        *(undefined4 *)(puVar2 + -0x154) = 0;
        *(undefined4 *)(puVar2 + -0x168) = 3;
        *(undefined4 *)(puVar2 + -0x164) = 0x1a1f486;
        *(int **)(puVar2 + -0x160) = &DAT_00999fe0;
        ffree(Var9);
        Var9 = FUN_005f34f0(puVar2 + -0x154,0x784ff00,&DAT_00768284,puVar2 + -0x168,&DAT_00796e80);
      }
      DAT_01a1f3b8 = 0;
      DAT_00999fdc = 0;
      if ((DAT_020b8ea2 == 'x') || (DAT_020b8ea2 == 'X')) {
        ffree(Var9);
        Var9 = push_words(&DAT_00768280,&P1);
        P1 = f_3;
        P7 = f_99;
        ffree(Var9);
        Var9 = thunk_FUN_00449b86();
        DAT_01a1f3b8 = ITEM_I;
        ffree(Var9);
        Var9 = pop_words(&DAT_00768280,&P1);
      }
      DAT_01f9a6f4 = 1;
      DAT_01e6790c = *(undefined4 *)(&DAT_01e67504 + DAT_00999fe0 * 4);
      DAT_0079484c = 0;
      P1 = f_8;
      if (DAT_020b90a2 == 'Z') {
        iVar4 = 3;
        iVar6 = 3;
        for (iVar7 = 1; iVar7 < 5; iVar7 = iVar7 + 1) {
          *(undefined4 *)(&P0 + iVar6 * 4) = *(undefined4 *)(&DAT_0099a000 + iVar4 * 4);
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 1;
        }
      }
      else {
        iVar7 = 1;
        for (iVar4 = 1; iVar4 < 7; iVar4 = iVar4 + 1) {
          *(undefined4 *)(&DAT_0099a000 + iVar4 * 4) = *(undefined4 *)(&P0 + iVar7 * 4);
          iVar7 = iVar7 + 1;
        }
      }
      ffree(Var9);
      Var9 = thunk_FUN_00525ae4();
      if (DAT_02052740 == 0) {
        ffree(Var9);
        fVar10 = (float10)thunk_FUN_0054e546(&DAT_00999fd8,&DAT_00999fd4);
        *(undefined2 *)(puVar2 + -0x15c) = in_FPUControlWord;
        *(ushort *)(puVar2 + -0x15a) = (ushort)*(undefined4 *)(puVar2 + -0x15c) | 0xc00;
        *(int *)(puVar2 + -0x158) = (int)ROUND(DAT_00999fd8);
        *(undefined2 *)(puVar2 + -0x160) = *(undefined2 *)(puVar2 + -0x15c);
        *(ushort *)(puVar2 + -0x15e) = (ushort)*(undefined4 *)(puVar2 + -0x160) | 0xc00;
        *(int *)(puVar2 + -0x15c) = (int)ROUND(DAT_00999fd4);
        in_FPUControlWord = *(undefined2 *)(puVar2 + -0x160);
        if (*(int *)(puVar2 + -0x15c) == *(int *)(puVar2 + -0x158)) {
          *(undefined4 *)(puVar2 + -0x11c) = 0;
        }
        else {
          _DAT_0099a000 = (float)DAT_00999fe0;
          fVar10 = (float10)DAT_00999fd8 - (float10)DAT_00999fe0;
          _DAT_0078cad0 = (float)(fVar10 / ((float10)DAT_00999fd8 - (float10)DAT_00999fd4));
        }
        ffree(fVar10);
        Var9 = push_words(&DAT_00768298,&P1);
        if (0 < DAT_00791480) {
          ffree(Var9);
          Var9 = thunk_FUN_00535d00(&DAT_00768294);
        }
        _DAT_0078cad0 = f_99;
        ffree(Var9);
        Var9 = pop_words(&DAT_00768298,&P1);
        P3 = DAT_00999fd0;
      }
      DAT_00796fb0 = P3;
      DAT_00796fb4 = P6;
      if (P6 == f_0) {
        DAT_00796fb4 = DAT_01fbb8b8;
      }
      DAT_020b8e54 = ITEM_WORDS;
      DAT_01fbb700 = 0;
      DAT_020b8e58 = ITEM_I;
      if (DAT_02052740 == -1) {
        *(undefined4 *)(puVar2 + -0x118) = 0;
LAB_0052d21a:
        ffree(Var9);
        Var9 = thunk_FUN_005253e2();
        DAT_0078b4e4 = 0x58;
        DAT_0078b4e0 = 0;
        DAT_00796fd4 = DAT_01fbb8b8;
        ffree(Var9);
        Var9 = thunk_FUN_004f7808();
        ffree(Var9);
        Var9 = thunk_FUN_0051c338();
        if (0 < DAT_01fb8c74) {
          DAT_00796fd0 = DAT_01f998e0;
LAB_0052d285:
          P1 = DAT_00796fd0;
          P2 = DAT_00796fd4;
          if (DAT_00796fd0 < DAT_00796fb0) {
            P1 = DAT_00796fb0;
          }
          if (DAT_00796fd4 == f_0) {
            P2 = DAT_01fbb8b8;
          }
          if (DAT_00796fb4 < P2) {
            P2 = DAT_00796fb4;
          }
          DAT_00794850 = P1 - f_5;
          Var9 = FUN_005f34d1(puVar2,0x52d329);
          *(undefined4 *)(puVar2 + -0x154) = 0;
          *(undefined4 *)(puVar2 + -0x168) = 0x10;
          *(char **)(puVar2 + -0x164) = &DAT_01a1f4c4;
          *(float **)(puVar2 + -0x160) = &P1;
          ffree(Var9);
          Var9 = FUN_005f34f0(puVar2 + -0x154,0x784ff00,&DAT_00768210,puVar2 + -0x168,&DAT_00796ebc)
          ;
          if (f_257 <= _DAT_01fb8c64) {
            DAT_00796fd0 = P1;
            DAT_00796fd4 = P2;
          }
          else {
            *(undefined4 *)(puVar2 + -0xf4) = 0;
          }
          while (DAT_01a1f4c4 == ' ') {
            FUN_005f33c9(puVar2,0x52d3ea);
            Var9 = FUN_005f34d1(puVar2,0x52d405);
            *(undefined4 *)(puVar2 + -0xec) = 0;
          }
          *(undefined4 *)(puVar2 + -0xf0) = 0;
          *(undefined4 *)(puVar2 + -0x154) = 0;
          *(undefined4 *)(puVar2 + -0x168) = 6;
          *(undefined4 *)(puVar2 + -0x164) = 0x1a1f4cb;
          *(float **)(puVar2 + -0x160) = &P2;
          ffree(Var9);
          Var9 = FUN_005f34f0(puVar2 + -0x154,0x784ff00,&DAT_00768210,puVar2 + -0x168,&DAT_00796ed0)
          ;
          ffree(Var9);
          Var9 = thunk_FUN_00526042(&DAT_00999ff0);
          P2 = (float)IP2;
          if (-1 < DAT_02052740) {
            DAT_01fbb700 = 1;
            *(undefined4 *)(puVar2 + -0xe0) = 0;
            goto LAB_0052d4c5;
          }
          *(undefined4 *)(puVar2 + -0xe4) = 0;
LAB_0052d71c:
          if (DAT_02052740 < 1) {
            ffree(Var9);
            Var9 = draw_items();
            ffree(Var9);
            Var9 = thunk_FUN_00549422();
          }
          else {
            *(undefined4 *)(puVar2 + -0xdc) = 0;
          }
          if (DAT_01fbb700 != 6) goto LAB_0052d4c5;
          *(undefined4 *)(puVar2 + -0xd8) = 0;
LAB_0052d756:
          if (DAT_02052740 <= DAT_02052748) {
            *(undefined4 *)(puVar2 + -0x8c) = 0;
            do {
              if ((char)DAT_020b8ea0 != '^') {
                if (DAT_01a1f3b8 == 0) goto LAB_0052d901;
                ffree(Var9);
                thunk_FUN_0045deb2(&DAT_01a1f3b8);
                DAT_01a1f3b8 = 0;
                DAT_00999fdc = 1;
                goto LAB_0052d901;
              }
              *(undefined4 *)(puVar2 + -0x84) = 0;
LAB_0052d891:
              do {
                DAT_00999fb8 = DAT_01fbb700;
                DAT_01fbb700 = -1;
                DAT_02052740 = -1;
                ITEM_WORDS = DAT_020b8e54;
                ITEM_I = DAT_020b8e58;
                ffree(Var9);
                Var9 = thunk_FUN_00530dd8(&DAT_00999fb8);
                if (DAT_01fbb700 < 6) {
                  if (DAT_00999fb8 != 0) {
                    DAT_01fbb700 = DAT_00999fb8;
                    DAT_02052740 = 0;
                    *(undefined4 *)(puVar2 + -0x74) = 0;
LAB_0052d4c5:
                    _DAT_00999fc8 = 1;
                    if ((DAT_02052740 < 1) && (2 < DAT_01fbb700)) {
                      ffree(Var9);
                      Var9 = thunk_FUN_00523c07(&DAT_007682a0);
                    }
LAB_0052d4f6:
                    ffree(Var9);
                    Var9 = FUN_0052e0a3(&DAT_00999fcc,&DAT_00999fc4);
                    if ((char)DAT_020b8ea0 == '$') {
                      *(undefined4 *)(puVar2 + -0xd4) = 0;
LAB_0052dbc1:
                      ffree(Var9);
                      Var9 = FUN_0052f62e(&DAT_007682a0);
                      *(undefined4 *)(puVar2 + -0x38) = 0;
                      goto LAB_0052dbdc;
                    }
                    if (DAT_020b90a0 == '^') {
LAB_0052d811:
                      if (DAT_01fbb700 < 3) {
                        if ((char)DAT_020b8ea0 == '!') {
                          DAT_020b8ea0 = CONCAT11(DAT_020b8ea0._1_1_,DAT_00768198);
                          *(undefined4 *)(puVar2 + -0xc4) = 0;
                          goto LAB_0052dbc1;
                        }
                        *(undefined4 *)(puVar2 + -200) = 0;
                        goto LAB_0052d891;
                      }
                      *(undefined4 *)(puVar2 + -0xcc) = 0;
LAB_0052d824:
                      if (DAT_01fbb700 == 0) {
                        *(undefined4 *)(puVar2 + -0x44) = 0;
                        goto LAB_0052dc3a;
                      }
                      ffree(Var9);
                      DAT_00999fe8 = thunk_FUN_005956b0();
                      if (-1 < DAT_00999fe8) {
                        Var9 = extraout_ST0;
                        if (DAT_00999fe8 < 1) goto LAB_0052dbc1;
                        *(undefined4 *)(puVar2 + -0x3c) = 0;
                        goto LAB_0052d9de;
                      }
                      *(undefined4 *)(puVar2 + -0x40) = 0;
                      Var9 = extraout_ST0;
                      goto LAB_0052d4f6;
                    }
                    *(undefined4 *)(puVar2 + -0xd0) = 0;
                    *(undefined4 *)(puVar2 + -0xc0) = 0;
                    if ((2 < DAT_01fbb700) && ((char)DAT_020b8ea0 == 'G')) {
                      *(undefined4 *)(puVar2 + -0xbc) = 0;
                      goto LAB_0052d756;
                    }
                    if ((char)DAT_020b8ea0 == '^') {
                      *(undefined4 *)(puVar2 + -0xb8) = 0;
                      goto LAB_0052d9de;
                    }
                    if ((char)DAT_020b8ea0 == '!') {
                      *(undefined4 *)(puVar2 + -0xb4) = 0;
                      goto LAB_0052d824;
                    }
                    if (DAT_01fbb700 < 3) goto LAB_0052d633;
                    if ((char)DAT_020b8ea0 == ';') {
                      DAT_01fbb700 = DAT_01fbb700 + 1;
                      if (DAT_01fbb700 == 6) {
                        *(undefined4 *)(puVar2 + -0xb0) = 0;
                        goto LAB_0052d756;
                      }
                      *(undefined4 *)(puVar2 + -0xac) = 0;
                      goto LAB_0052d4f6;
                    }
                    if ((char)DAT_020b8ea0 == 'G') {
                      DAT_01fbb700 = 6;
                    }
LAB_0052d633:
                    switch(DAT_01fbb700) {
                    case 1:
                    case 5:
                      break;
                    case 2:
                      ITEM_WORDS = DAT_020b8e54;
                      ITEM_I = DAT_020b8e58;
                      *(undefined4 *)(puVar2 + -0x98) = 0;
                      break;
                    case 3:
                      uRam00999fc0 = DAT_01fb8c80;
                      *(undefined4 *)(puVar2 + -0x94) = 0;
                      break;
                    case 4:
                      uRam00999fbc = DAT_01fb8c80;
                      *(undefined4 *)(puVar2 + -0x90) = 0;
                      break;
                    default:
                      ffree(Var9);
                      Var9 = thunk_FUN_00526042(&DAT_00999ff0);
                      if (DAT_01fbb700 != 899) goto LAB_0052d7f7;
                      *(undefined4 *)(puVar2 + -0xa8) = 0;
                      DAT_0078b378 = 0;
                      DAT_0078b4ec = 0;
                      DAT_01b12c70 = 0;
                      DAT_0205274c = 0;
                      ITEM_WORDS = DAT_020b8e54;
                      ITEM_I = DAT_020b8e58;
                      goto LAB_0052dbdc;
                    }
                    ffree(Var9);
                    Var9 = func_0x004050dd(&DAT_00999fc8,&DAT_00999fc4);
                    if (_DAT_02052754 == 0) {
                      ffree(Var9);
                      Var9 = input_store_items();
                      DAT_01fbb700 = DAT_01fbb700 + 1;
                      *(undefined4 *)(puVar2 + -0x9c) = 0;
                    }
                    else {
                      *(undefined4 *)(puVar2 + -0xa0) = 0;
                      *(undefined4 *)(puVar2 + -0x54) = 0;
                      Var9 = FUN_005f34d1(puVar2,&UNK_0052d6ef);
                      *(undefined4 *)(puVar2 + -0x50) = 0;
                    }
                    goto LAB_0052d71c;
                  }
                  *(undefined4 *)(puVar2 + -0x78) = 0;
                  goto LAB_0052e07c;
                }
                ffree(Var9);
                Var9 = draw_items();
                ffree(Var9);
                thunk_FUN_00549422();
                *(undefined4 *)(puVar2 + -0x7c) = 0;
LAB_0052d901:
                FUN_005f33c9(puVar2,0x52d91f);
                Var9 = FUN_005f34d1(puVar2,0x52d93a);
                ffree(Var9);
                Var9 = thunk_FUN_00596140();
                ffree(Var9);
                Var9 = thunk_FUN_0054946a(&DAT_020b90a0,0x200);
                ffree(Var9);
                Var9 = thunk_FUN_00468df8(&DAT_007681a0);
                DAT_0171b230 = 1;
                ffree(Var9);
                Var9 = thunk_FUN_00549afb();
                DAT_020b8ea0 = CONCAT11(DAT_020b8ea0._1_1_,DAT_020b90a0);
                ffree(Var9);
                Var9 = thunk_FUN_0054c768(&DAT_020b8ea0);
                DAT_0171b230 = 0xffffffff;
                ffree(Var9);
                Var9 = thunk_FUN_0054da52(&DAT_020b90a0,1);
              } while ((char)DAT_020b8ea0 == 'E');
              *(undefined4 *)(puVar2 + -0x80) = 0;
LAB_0052d9de:
              if ((char)DAT_020b8ea0 == 'A') {
                ffree(Var9);
                Var9 = thunk_FUN_005725fa();
                ffree(Var9);
                Var9 = FUN_0052f62e(&DAT_007682a0);
                *(undefined4 *)(puVar2 + -0x6c) = 0;
                goto LAB_0052dbdc;
              }
              *(undefined4 *)(puVar2 + -0x70) = 0;
              if ((char)DAT_020b8ea0 == 'L') {
                DAT_020b8ea0 = 0x4a4c;
              }
              if (((char)DAT_020b8ea0 == 'S') || ((char)DAT_020b8ea0 == 'L')) {
                *(undefined4 *)(puVar2 + -0x68) = 0;
LAB_0052dae3:
                ffree(Var9);
                Var9 = thunk_FUN_00526451();
                if (DAT_020b8ea0._1_1_ == 'J') {
                  DAT_0078b4e0 = 0x4c;
                  DAT_0078b4e4 = 0x4a;
                  ffree(Var9);
                  Var9 = thunk_FUN_004b80b7(&IP2,&IP2,&f_0,&DAT_01fbb8b8);
                  *(undefined4 *)(puVar2 + -0x58) = 0;
                }
                else {
                  *(undefined4 *)(puVar2 + -0x5c) = 0;
                }
                goto LAB_0052dbdc;
              }
              if ((char)DAT_020b8ea0 == '\r') {
                DAT_020b8ea0 = CONCAT11(DAT_020b8ea0._1_1_,DAT_0076819c);
              }
              if (((char)DAT_020b8ea0 == 'X') || ((char)DAT_020b8ea0 == ';')) {
                *(undefined4 *)(puVar2 + -100) = 0;
                goto LAB_0052dae3;
              }
              *(undefined4 *)(puVar2 + -0x60) = 0;
            } while( true );
          }
          ffree(Var9);
          Var9 = input_store_items();
          ffree(Var9);
          Var9 = thunk_FUN_00549422();
          *(undefined4 *)(puVar2 + -0x88) = 0;
          goto LAB_0052dbdc;
        }
        ffree(Var9);
        Var9 = thunk_FUN_0054d831(&DAT_0076821c,0x1d);
        *(undefined4 *)(puVar2 + -0xfc) = 0;
      }
      else {
        if (DAT_02052740 != 0) {
          DAT_00999fd8 = P2;
          DAT_00999fd4 = P1;
          DAT_02052740 = 0;
          EDIT_ITEM = LOAD_I;
          ffree(Var9);
          Var9 = thunk_FUN_00585d20();
          DAT_02052740 = 5;
          EDIT_ITEM = 0;
          ffree(Var9);
          Var9 = draw_items();
          P2 = DAT_00999fd8;
          P1 = DAT_00999fd4;
          ffree(Var9);
          Var9 = thunk_FUN_00518448();
          if ((DAT_020b8ea0 == 0x5053) || (DAT_020b8ea0 == 0x505a)) {
            Var9 = FUN_005f34d1(puVar2,0x52ce8a);
            DAT_020b8ea0 = DAT_0076826c;
            *(undefined2 *)(puVar2 + -0x15c) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0x15a) = (ushort)*(undefined4 *)(puVar2 + -0x15c) | 0xc00;
            *(int *)(puVar2 + -0x158) = (int)ROUND(P2);
            in_FPUControlWord = *(undefined2 *)(puVar2 + -0x15c);
            DAT_0078d960 = *(int *)(puVar2 + -0x158);
            _DAT_01fb8c64 = P2;
            *(undefined4 *)(puVar2 + -0x154) = 0;
            *(undefined4 *)(puVar2 + -0x168) = 3;
            *(char **)(puVar2 + -0x164) = &DAT_020b8ea2;
            *(int **)(puVar2 + -0x160) = &DAT_0078d960;
            ffree(Var9);
            Var9 = FUN_005f34f0(puVar2 + -0x154,0x784ff00,&DAT_00768284,puVar2 + -0x168,
                                &DAT_00796e94);
            *(undefined4 *)(puVar2 + -0x110) = 0;
            goto LAB_0052d21a;
          }
          if ((P1 != f_0) || (P2 != f_0)) {
            _DAT_01fb8c64 = f_999;
          }
          if (P2 == f_0) {
            P2 = DAT_00796fb4;
          }
          DAT_00796fd4 = P2;
          DAT_00796fd0 = P1;
          if (P2 == f_0) {
            DAT_00796fd4 = DAT_01fbb8b8;
          }
          ffree(Var9);
          thunk_FUN_005253e2();
          *(undefined4 *)(puVar2 + -0x10c) = 0;
          goto LAB_0052d285;
        }
        FUN_005f33c9(puVar2,0x52cf71);
        Var9 = FUN_005f34d1(puVar2,0x52cf8c);
        DAT_0078b4e4 = 0x43;
        ffree(Var9);
        Var9 = thunk_FUN_0053ec10();
        ffree(Var9);
        Var9 = thunk_FUN_00549422();
        ffree(Var9);
        thunk_FUN_00525e62();
        if (_DAT_01fb8c64 < f_256) {
          P1 = f_10;
        }
        DAT_00796fd0 = P1;
        if (DAT_00796fd4 == f_0) {
          DAT_00796fd4 = DAT_01fbb8b8;
        }
        FUN_005f33c9(puVar2,0x52d018);
        Var9 = FUN_005f34d1(puVar2,0x52d033);
        *(undefined4 *)(puVar2 + -0x154) = 0;
        *(undefined4 *)(puVar2 + -0x168) = 3;
        *(undefined **)(puVar2 + -0x164) = &DAT_007a0b96;
        *(int **)(puVar2 + -0x160) = &DAT_00999fe0;
        ffree(Var9);
        Var9 = FUN_005f34f0(puVar2 + -0x154,0x784ff00,&DAT_00768284,puVar2 + -0x168,&DAT_00796ea8);
        IP8 = DAT_00999fe0;
        *(undefined2 *)(puVar2 + -0x15c) = in_FPUControlWord;
        *(ushort *)(puVar2 + -0x15a) = (ushort)*(undefined4 *)(puVar2 + -0x15c) | 0xc00;
        *(int *)(puVar2 + -0x158) = (int)ROUND(DAT_00796fd0);
        IP5 = *(int *)(puVar2 + -0x158);
        *(undefined2 *)(puVar2 + -0x15c) = *(undefined2 *)(puVar2 + -0x15c);
        *(ushort *)(puVar2 + -0x15a) = (ushort)*(undefined4 *)(puVar2 + -0x15c) | 0xc00;
        *(int *)(puVar2 + -0x158) = (int)ROUND(DAT_00796fd4);
        in_FPUControlWord = *(undefined2 *)(puVar2 + -0x15c);
        IP6 = *(int *)(puVar2 + -0x158);
        ffree(Var9);
        input_range_dialog(&DAT_00999fcc);
        Var9 = FUN_005f34d1(puVar2,0x52d14b);
        if (DAT_00999fcc != 2) {
          if (IP7 != 0) {
            _DAT_00999ff0 = -1;
            if (IP7 != 0) {
              _DAT_00999ff0 = 0;
            }
            DAT_0078d960 = IP7;
            FUN_005f33c9(puVar2,0x52d1c5);
            Var9 = FUN_005f34d1(puVar2,0x52d1e0);
            DAT_0078b4e4 = 0x43;
            ffree(Var9);
            Var9 = thunk_FUN_0053ec10();
            _DAT_01fb8c64 = (float)DAT_0078d960;
            DAT_00796fd0 = f_10;
            DAT_00796fb0 = f_10;
            goto LAB_0052d21a;
          }
          *(undefined4 *)(puVar2 + -0x100) = 0;
          goto LAB_0052d285;
        }
        *(undefined4 *)(puVar2 + -0x104) = 0;
      }
    }
  } while( true );
LAB_0052d7f7:
  DAT_01fbb700 = 1;
  *(undefined4 *)(puVar2 + -0xa4) = 0;
  goto LAB_0052d4c5;
}


