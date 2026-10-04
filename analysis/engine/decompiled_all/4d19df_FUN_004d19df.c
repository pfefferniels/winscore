// FUN_004d19df @ 004d19df (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004d19df(int *param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  short *psVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  short *psVar10;
  bool bVar11;
  bool bVar12;
  undefined2 in_FPUControlWord;
  unkbyte10 extraout_ST0;
  unkbyte10 Var13;
  float10 fVar14;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  float10 extraout_ST0_02;
  unkbyte10 extraout_ST0_03;
  unkbyte10 extraout_ST0_04;
  unkbyte10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 extraout_ST0_07;
  float10 extraout_ST0_08;
  float10 extraout_ST0_09;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined4 local_11c;
  char *local_118;
  undefined4 *local_114;
  int *local_110;
  undefined4 local_108 [9];
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_b4;
  undefined4 local_ac;
  undefined4 local_a4;
  
  puVar15 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar16 = &stack0xfffffffc;
  puVar17 = &stack0xfffffffc;
  puVar6 = &DAT_01a14984;
  puVar9 = &DAT_008a0158;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar9 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar9 = puVar9 + 1;
  }
  DAT_019c69fc = 0;
  puVar6 = (undefined4 *)&DAT_019c6a58;
  puVar9 = &DAT_008a0114;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar9 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar9 = puVar9 + 1;
  }
  iVar2 = FUN_005f4660(0x20);
  if (iVar2 != 0) {
    pcVar4 = "PRINT.SCR               ";
    puVar6 = &DAT_008a0114;
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      puVar6 = puVar6 + 1;
    }
  }
  if (*param_1 == 0) {
    local_e4 = 0;
    local_108[0] = 0;
    local_11c = 0x18;
    local_118 = (char *)&DAT_008a0114;
    local_114 = &DAT_008a00a4;
    ffree(extraout_ST0);
    Var13 = FUN_005f47c0(local_108,0xffffffff,0x784ff00,&DAT_00765464,&local_11c);
    if ((DAT_008a00a4 & 1) == 0) {
      pcVar4 = "*** File not found. ***";
      puVar6 = &DAT_008a0114;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        puVar6 = puVar6 + 1;
      }
      FUN_005f33c9(&stack0xfffffffc,0x4d1b05);
      puVar3 = puVar15;
      Var13 = FUN_005f34d1(puVar15,0x4d1b20);
      DAT_019c69fc = 1;
      *(undefined4 *)(puVar3 + -0x80) = 0;
    }
    else {
      DAT_008a00ac = 8;
      param_2[0x12] = 0;
      if (DAT_0078b4e8 != 0) {
        param_2[0x12] = 1;
      }
      local_108[0] = 0;
      local_11c = 0x18;
      local_118 = (char *)&DAT_008a0114;
      local_114 = (undefined4 *)0x2;
      local_110 = (int *)0x4;
      ffree(Var13);
      fVar14 = (float10)FUN_005f6540(local_108,DAT_008a00ac,0x784ff00,&DAT_0076543c,&local_11c);
      param_2[0xd] = 0;
      param_2[0xe] = 0;
      param_2[0x13] = 0;
LAB_004d1bdc:
      *(undefined4 *)(puVar3 + -0x104) = 0;
      *(undefined4 *)(puVar3 + -0x110) = 0x30;
      *(undefined2 **)(puVar3 + -0x10c) = &DAT_020b8ea0;
      ffree(fVar14);
      iVar2 = FUN_005fdbd0(puVar3 + -0x104,8,0x784ff03,&DAT_00765438,puVar3 + -0x110,&DAT_0079396c);
      *(int *)(puVar3 + -0x78) = iVar2;
      Var13 = extraout_ST0_00;
      if (iVar2 == 0) {
        *(undefined4 *)(puVar3 + -0x110) = 0x80;
        *(int **)(puVar3 + -0x10c) = &DAT_008a0170;
        ffree(extraout_ST0_00);
        uVar1 = FUN_005fe110(puVar3 + -0x104,&DAT_00765434,puVar3 + -0x110);
        *(undefined4 *)(puVar3 + -0x78) = uVar1;
        Var13 = extraout_ST0_01;
      }
      if (*(int *)(puVar3 + -0x78) == -1) goto LAB_004d2f7c;
      if (*(int *)(puVar3 + -0x78) == 0) {
        puVar6 = &DAT_008a0170;
        puVar9 = &DAT_008a00c8;
        for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar9 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar9 = puVar9 + 1;
        }
        ffree(Var13);
        Var13 = thunk_FUN_0054c83c(&DAT_020b8ea0,0x30,&DAT_00765430);
        ffree(Var13);
        Var13 = thunk_FUN_0054c83c(&DAT_008a0170,0x80,&DAT_0076542c);
        DAT_008a00c4._0_3_ = (undefined3)_DAT_020b8ea0;
        ffree(Var13);
        fVar14 = (float10)FUN_004d2ffc();
        *(undefined4 *)(puVar3 + -0x74) = 0x13;
        DAT_008a00a8 = 1;
        while ((*(uint *)(s_LetterLegal_LedgerarchA_None_Hea_00793a28 + DAT_008a00a8 * 3 + 0x2d) &
               0xffffff) != (DAT_008a00c4 & 0xffffff)) {
          DAT_008a00a8 = DAT_008a00a8 + 1;
          *(int *)(puVar3 + -0x74) = *(int *)(puVar3 + -0x74) + -1;
          if (*(int *)(puVar3 + -0x74) < 1) goto LAB_004d2542;
        }
        *(undefined4 *)(puVar3 + -0x70) = 0;
        if (DAT_008a00a8 - 1 < 0x13) {
          bVar11 = DAT_008a00a8 == 0;
          bVar12 = DAT_008a00a8 - 1 == 0;
          switch(DAT_008a00a8 - 1) {
          case 1:
            _DAT_020b8ea0 = DAT_008a0170;
            _DAT_020b8ea4 = DAT_008a0174;
            DAT_020b8ea8 = DAT_008a0178;
            DAT_020b8eac = DAT_008a017c;
            ffree(fVar14);
            fVar14 = (float10)thunk_FUN_00518448();
            **(float **)(puVar3 + 0x10) = P1;
            *(undefined4 *)(puVar3 + -0x60) = 0;
            goto LAB_004d1bdc;
          case 2:
            iVar2 = 1;
            pbVar5 = (byte *)&DAT_008a00c8;
            pbVar8 = &UNK_00765428;
            goto code_r0x004d1dd1;
          case 3:
            _DAT_020b8ea0 = DAT_008a0170;
            _DAT_020b8ea4 = DAT_008a0174;
            DAT_020b8ea8 = DAT_008a0178;
            DAT_020b8eac = DAT_008a017c;
            ffree(fVar14);
            fVar14 = (float10)thunk_FUN_00518448();
            *(float *)(*(int *)(puVar3 + 0x10) + 4) = P1;
            *(float *)(*(int *)(puVar3 + 0x10) + 8) = P2;
            *(undefined4 *)(puVar3 + -0x54) = 0;
            goto LAB_004d1bdc;
          case 4:
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 8) = 0;
            iVar2 = FUN_005f4660(0x20);
            fVar14 = extraout_ST0_02;
            if (iVar2 != 0) {
              *(undefined4 *)(*(int *)(puVar3 + 0xc) + 8) = 1;
            }
          case 5:
            _DAT_020b8ea0 = DAT_008a0170;
            _DAT_020b8ea4 = DAT_008a0174;
            DAT_020b8ea8 = DAT_008a0178;
            DAT_020b8eac = DAT_008a017c;
            ffree(fVar14);
            fVar14 = (float10)thunk_FUN_00518448();
            *(undefined2 *)(puVar3 + -0x10c) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x10a) = (ushort)*(undefined4 *)(puVar3 + -0x10c) | 0xc00;
            *(int *)(puVar3 + -0x108) = (int)ROUND(P1);
            in_FPUControlWord = *(undefined2 *)(puVar3 + -0x10c);
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x20) = *(undefined4 *)(puVar3 + -0x108);
            *(undefined4 *)(puVar3 + -0x50) = 0;
            goto LAB_004d1bdc;
          case 6:
            _DAT_020b8ea0 = DAT_008a0170;
            _DAT_020b8ea4 = DAT_008a0174;
            DAT_020b8ea8 = DAT_008a0178;
            DAT_020b8eac = DAT_008a017c;
            ffree(fVar14);
            fVar14 = (float10)thunk_FUN_00518448();
            *(undefined2 *)(puVar3 + -0x10c) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x10a) = (ushort)*(undefined4 *)(puVar3 + -0x10c) | 0xc00;
            *(int *)(puVar3 + -0x108) = (int)ROUND(P1);
            in_FPUControlWord = *(undefined2 *)(puVar3 + -0x10c);
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x24) = *(undefined4 *)(puVar3 + -0x108);
            *(undefined4 *)(puVar3 + -0x4c) = 0;
            goto LAB_004d1bdc;
          case 7:
            bVar11 = true;
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 4) = 0;
            *(int *)(*(int *)(puVar3 + 0x10) + 0xc) = i_0;
            *(int *)(*(int *)(puVar3 + 0x10) + 0x10) = i_0;
            iVar2 = 3;
            psVar7 = (short *)&DAT_008a0170;
            psVar10 = (short *)"HEADER";
            goto code_r0x004d2001;
          case 8:
            **(undefined4 **)(puVar3 + 0xc) = 0;
            iVar2 = FUN_005f4660(0x20);
            if (iVar2 != 0) {
              **(undefined4 **)(puVar3 + 0xc) = 1;
            }
            *(undefined4 *)(puVar3 + -0x30) = 0;
            fVar14 = extraout_ST0_06;
            goto LAB_004d1bdc;
          case 9:
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x1c) = 0;
            iVar2 = FUN_005f4660(0x20);
            if (iVar2 != 0) {
              *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x1c) = 1;
            }
            *(undefined4 *)(puVar3 + -0x2c) = 0;
            fVar14 = extraout_ST0_07;
            goto LAB_004d1bdc;
          case 10:
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x10) = 0;
            iVar2 = FUN_005f4660(0x20);
            if (iVar2 != 0) {
              *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x10) = 1;
            }
            *(undefined4 *)(puVar3 + -0x28) = 0;
            fVar14 = extraout_ST0_08;
            goto LAB_004d1bdc;
          case 0xb:
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x2c) = 0;
            iVar2 = FUN_005f4660(0x20);
            if (iVar2 != 0) {
              *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x2c) = 1;
            }
            *(undefined4 *)(puVar3 + -0x24) = 0;
            fVar14 = extraout_ST0_09;
            goto LAB_004d1bdc;
          case 0xc:
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x48) = 0;
            DAT_0078b4e8 = 0;
            *(undefined4 *)(puVar3 + -0x20) = 0;
            goto LAB_004d1bdc;
          case 0xd:
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x48) = 1;
            DAT_0078b4e8 = 1;
            *(undefined4 *)(puVar3 + -0x1c) = 0;
            goto LAB_004d1bdc;
          case 0xe:
            ffree(fVar14);
            fVar14 = (float10)thunk_FUN_0054cd71(&DAT_008a0170,0x80,&DAT_0076542c,&DAT_008a00a8);
            puVar6 = &DAT_008a0170;
            puVar9 = &DAT_009af4bc;
            for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar9 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar9 = puVar9 + 1;
            }
            *(undefined4 *)(puVar3 + -0x18) = 0;
            goto LAB_004d1bdc;
          case 0xf:
            ffree(fVar14);
            fVar14 = (float10)thunk_FUN_0054cd71(&DAT_008a0170,0x80,&DAT_0076542c,&DAT_008a00a8);
            puVar6 = &DAT_008a0170;
            puVar9 = &DAT_009af53c;
            for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar9 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar9 = puVar9 + 1;
            }
            *(undefined4 *)(puVar3 + -0x14) = 0;
            goto LAB_004d1bdc;
          case 0x10:
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0xc) = 0;
            *(undefined4 *)(puVar3 + -0x10) = 0;
            goto LAB_004d1bdc;
          case 0x11:
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0xc) = 1;
            *(undefined4 *)(puVar3 + -0xc) = 0;
            goto LAB_004d1bdc;
          case 0x12:
            *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0xc) = 2;
            *(undefined4 *)(puVar3 + -8) = 0;
            goto LAB_004d1bdc;
          }
        }
        iVar2 = FUN_005f4660(0x20);
        if ((iVar2 == 0) && (_DAT_020b8ea0 != 0x3154504c)) {
          *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0xc) = 0;
          FUN_005f33c9(puVar3,0x4d24cd);
          fVar14 = (float10)FUN_005f34d1(puVar3,0x4d24e8);
        }
        else {
          *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0xc) = 1;
          FUN_005f33c9(puVar3,0x4d2517);
          fVar14 = (float10)FUN_005f34d1(puVar3,0x4d2532);
        }
        *(undefined4 *)(puVar3 + -100) = 0;
        goto LAB_004d1bdc;
      }
LAB_004d254e:
      puVar6 = &DAT_007653f4;
      puVar9 = &DAT_008a0114;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar9 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar9 = puVar9 + 1;
      }
      ffree(Var13);
      thunk_FUN_0054d831("Error reading file.",0x14);
      FUN_005f33c9(puVar3,0x4d2592);
      Var13 = FUN_005f34d1(puVar3,0x4d25ad);
      DAT_019c69fc = 1;
      *(undefined4 *)(puVar3 + -0x68) = 0;
    }
  }
  else if (*param_1 == 2) {
    local_e0 = 0;
    *(int *)(param_3 + 0xc) = i_0;
    *(int *)(param_3 + 0x10) = i_0;
    FUN_005f34d1(&stack0xfffffffc,0x4d2613);
    for (iVar2 = 1; iVar2 < 0x21; iVar2 = iVar2 + 1) {
      *(undefined4 *)(iVar2 * 4 + *(int *)(puVar16 + 0xc) + -4) = 0;
    }
    for (iVar2 = 1; iVar2 < 0x21; iVar2 = iVar2 + 1) {
      *(int *)(*(int *)(puVar16 + 0x10) + -4 + iVar2 * 4) = i_0;
    }
    **(float **)(puVar16 + 0x10) = f_1;
    *(undefined4 *)(*(int *)(puVar16 + 0x10) + 4) = DAT_01c60caa;
    *(undefined4 *)(*(int *)(puVar16 + 0x10) + 8) = DAT_01c60cae;
    *(undefined4 *)(*(int *)(puVar16 + 0xc) + 0x20) = 600;
    *(undefined4 *)(*(int *)(puVar16 + 0xc) + 0x24) = 4;
    *(undefined4 *)(*(int *)(puVar16 + 0xc) + 0x28) = 1;
    **(undefined4 **)(puVar16 + 0xc) = 0;
    *(undefined4 *)(*(int *)(puVar16 + 0xc) + 0x10) = 0;
    *(undefined4 *)(*(int *)(puVar16 + 0xc) + 0x2c) = 0;
    puVar3 = puVar16;
    Var13 = FUN_005f34d1(puVar16,0x4d26d4);
  }
  else {
    DAT_008a00ac = 8;
    local_108[0] = 0;
    local_11c = 0x18;
    local_118 = (char *)&DAT_008a0114;
    local_114 = (undefined4 *)0x2;
    local_110 = (int *)0x4;
    ffree(extraout_ST0);
    Var13 = FUN_005f6540(local_108,8,0x784ff00,&DAT_0076543c,&local_11c);
    DAT_008a00b0 = DAT_0076538c;
    puVar6 = &DAT_008a0114;
    puVar9 = &DAT_008a00e8;
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    ffree(Var13);
    Var13 = thunk_FUN_0054cd71(&DAT_01a14984,0x80,&DAT_0076542c,&DAT_008a00a8);
    if (param_2[3] == 0) {
      puVar6 = &DAT_01a14984;
      puVar9 = &DAT_009af4bc;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar9 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar9 = puVar9 + 1;
      }
    }
    local_108[0] = 0;
    local_114 = (undefined4 *)0x80;
    local_110 = &DAT_009af4bc;
    ffree(Var13);
    Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_00765434,&local_114,&DAT_007936a4);
    if (param_2[3] == 2) {
      puVar6 = &DAT_01a14984;
      pcVar4 = s___computer_printer_0078dccc;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined4 *)pcVar4 = *puVar6;
        puVar6 = puVar6 + 1;
        pcVar4 = pcVar4 + 4;
      }
    }
    local_108[0] = 0;
    local_114 = (undefined4 *)0x80;
    local_110 = (int *)s___computer_printer_0078dccc;
    ffree(Var13);
    Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_00765434,&local_114,&DAT_007936d0);
    local_110 = param_2 + 3;
    local_108[0] = 0;
    local_114 = (undefined4 *)0x4;
    ffree(Var13);
    Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_007653dc,&local_114,&DAT_007936fc);
    local_118 = s_EPSLPTNET_00793a1c + param_2[3] * 3;
    local_11c = 3;
    local_114 = (undefined4 *)0x3;
    ffree(Var13);
    Var13 = FUN_005fc980(local_108,&DAT_007653d8,&local_11c);
    local_118 = s_No_Yes_007939fc + *param_2 * 3 + 0x18;
    local_108[0] = 0;
    local_11c = 3;
    local_114 = (undefined4 *)0x3;
    ffree(Var13);
    Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_007653d8,&local_11c,&DAT_00793730);
    local_108[0] = 0;
    local_114 = (undefined4 *)0x4;
    local_110 = (int *)param_3;
    ffree(Var13);
    Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_007653d4,&local_114,&DAT_0079375c);
    if (param_2[10] == 6) {
      local_108[0] = 0;
      local_114 = (undefined4 *)0x20;
      local_110 = (int *)&DAT_019c6a04;
      ffree(Var13);
      Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_00765434,&local_114,&DAT_007937b0);
    }
    else {
      local_108[0] = 0;
      local_114 = (undefined4 *)0x20;
      local_110 = &DAT_019c6a24;
      ffree(Var13);
      Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_00765434,&local_114,&DAT_00793784);
    }
    local_110 = param_2 + 10;
    local_108[0] = 0;
    local_114 = (undefined4 *)0x4;
    ffree(Var13);
    Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_00765424,&local_114,&DAT_007937dc);
    local_110 = (int *)(param_3 + 4);
    local_108[0] = 0;
    local_114 = (undefined4 *)0x4;
    ffree(Var13);
    Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_007653d0,&local_114,&DAT_007937f0);
    local_110 = (int *)(param_3 + 8);
    local_114 = (undefined4 *)0x4;
    ffree(Var13);
    Var13 = FUN_005fc980(local_108,&DAT_007653d0,&local_114);
    local_118 = s_No_Yes_007939fc + param_2[2] * 3 + 0x18;
    local_11c = 3;
    local_114 = (undefined4 *)0x3;
    ffree(Var13);
    Var13 = FUN_005fc980(local_108,&DAT_007653cc,&local_11c);
    local_110 = param_2 + 8;
    local_114 = (undefined4 *)0x4;
    ffree(Var13);
    Var13 = FUN_005fc980(local_108,&DAT_007653dc,&local_114);
    local_110 = param_2 + 9;
    local_114 = (undefined4 *)0x4;
    ffree(Var13);
    Var13 = FUN_005fc980(local_108,&DAT_007653dc,&local_114);
    local_118 = s_LetterLegal_LedgerarchA_None_Hea_00793a28 + param_2[1] * 6 + 0x18;
    local_11c = 6;
    local_114 = (undefined4 *)0x6;
    ffree(Var13);
    Var13 = FUN_005fc980(local_108,&DAT_007653d8,&local_11c);
    if (param_2[1] == 0) {
      local_b4 = 0;
    }
    else {
      local_108[0] = 0;
      local_114 = (undefined4 *)0x12;
      local_110 = (int *)&DAT_007a0b7c;
      ffree(Var13);
      Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_00765434,&local_114,&DAT_007938c0);
      if (param_2[1] == 2) {
        local_ac = 0;
      }
      else {
        local_110 = (int *)(param_3 + 0xc);
        local_108[0] = 0;
        local_114 = (undefined4 *)0x4;
        ffree(Var13);
        Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_007653d4,&local_114,&DAT_00793690);
      }
      if (param_2[1] == 1) {
        local_a4 = 0;
      }
      else {
        local_110 = (int *)(param_3 + 0x10);
        local_108[0] = 0;
        local_114 = (undefined4 *)0x4;
        ffree(Var13);
        Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_007653d4,&local_114,&DAT_00793690);
      }
    }
    local_118 = s_No_Yes_007939fc + param_2[7] * 3 + 0x18;
    local_108[0] = 0;
    local_11c = 3;
    local_114 = (undefined4 *)0x3;
    ffree(Var13);
    Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_007653d8,&local_11c,&DAT_007938d4);
    DAT_008a00a8 = (uint)(param_2[4] != 0);
    local_118 = s_No_Yes_007939fc + DAT_008a00a8 * 3 + 0x18;
    local_108[0] = 0;
    local_11c = 3;
    local_114 = (undefined4 *)0x3;
    ffree(Var13);
    Var13 = FUN_005fc330(local_108,8,0x784ff00,&DAT_007653d8,&local_11c,&DAT_00793900);
    local_118 = s_No_Yes_007939fc + param_2[0xb] * 3 + 0x18;
    local_108[0] = 0;
    local_11c = 3;
    local_114 = (undefined4 *)0x3;
    ffree(Var13);
    FUN_005fc330(local_108,8,0x784ff00,&DAT_007653d8,&local_11c,&DAT_0079392c);
    FUN_005f33c9(&stack0xfffffffc,0x4d2ebe);
    puVar3 = puVar17;
    Var13 = FUN_005f34d1(puVar17,0x4d2ed9);
    if (*(int *)(*(int *)(puVar3 + 0xc) + 0x48) != 0) {
      FUN_005f33c9(puVar3,0x4d2f04);
      Var13 = FUN_005f34d1(puVar3,0x4d2f1f);
    }
    *(undefined4 *)(puVar3 + -0x104) = 0;
    *(undefined4 *)(puVar3 + -0x110) = 6;
    *(undefined2 **)(puVar3 + -0x10c) = &DAT_020b8ea0;
    ffree(Var13);
    Var13 = FUN_005fc330(puVar3 + -0x104,8,0x784ff00,&DAT_00765434,puVar3 + -0x110,&DAT_00793958);
    *(undefined4 *)(puVar3 + -0x88) = 0;
  }
LAB_004d2f7c:
  *(undefined4 *)(puVar3 + -0x104) = 0;
  ffree(Var13);
  FUN_005f7950(puVar3 + -0x104,8,0x784ff00,&DAT_007653b8,0);
  FUN_005f33c9(puVar3,0x4d2fcc);
  Var13 = FUN_005f34d1(puVar3,0x4d2fe7);
  ffree(Var13);
  return (float10)*(float *)(puVar3 + -0xe4);
LAB_004d2542:
  *(undefined4 *)(puVar3 + -0x6c) = 0;
  goto LAB_004d1bdc;
  while( true ) {
    iVar2 = iVar2 + -1;
    bVar11 = *psVar7 == *psVar10;
    psVar7 = psVar7 + 1;
    psVar10 = psVar10 + 1;
    if (!bVar11) break;
code_r0x004d2001:
    if (iVar2 == 0) break;
  }
  if (bVar11) {
    *(undefined4 *)(*(int *)(puVar3 + 0xc) + 4) = 1;
  }
  iVar2 = 3;
  psVar7 = (short *)&DAT_008a0170;
  psVar10 = (short *)0x765410;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar11 = *psVar7 == *psVar10;
    psVar7 = psVar7 + 1;
    psVar10 = psVar10 + 1;
  } while (bVar11);
  if (bVar11) {
    *(undefined4 *)(*(int *)(puVar3 + 0xc) + 4) = 2;
  }
  if (DAT_008a0170 == 0x48544f42) {
    *(undefined4 *)(*(int *)(puVar3 + 0xc) + 4) = 3;
  }
  if (*(int *)(*(int *)(puVar3 + 0xc) + 4) == 0) {
    *(undefined4 *)(puVar3 + -0x48) = 0;
  }
  else {
    *(undefined4 *)(puVar3 + -0x104) = 0;
    *(undefined4 *)(puVar3 + -0x110) = 0x80;
    *(undefined1 **)(puVar3 + -0x10c) = &DAT_007a0b7c;
    ffree(fVar14);
    uVar1 = FUN_005fdbd0(puVar3 + -0x104,8,0x784ff01,&DAT_00765434,puVar3 + -0x110,0x7939a0);
    *(undefined4 *)(puVar3 + -0x44) = uVar1;
    Var13 = extraout_ST0_03;
    if (*(int *)(puVar3 + -0x44) != 0) goto LAB_004d254e;
    DAT_008a00a8 = 4;
    if (*(int *)(*(int *)(puVar3 + 0xc) + 4) == 2) {
      DAT_008a00a8 = 5;
    }
    *(undefined4 *)(puVar3 + -0x104) = 0;
    *(undefined4 *)(puVar3 + -0x110) = 0x30;
    *(undefined2 **)(puVar3 + -0x10c) = &DAT_020b8ea0;
    ffree(extraout_ST0_03);
    uVar1 = FUN_005fdbd0(puVar3 + -0x104,8,0x784ff01,&DAT_00765434,puVar3 + -0x110,0x7939b4);
    *(undefined4 *)(puVar3 + -0x40) = uVar1;
    Var13 = extraout_ST0_04;
    if (*(int *)(puVar3 + -0x40) != 0) goto LAB_004d254e;
    ffree(extraout_ST0_04);
    fVar14 = (float10)thunk_FUN_00518448();
    if ((P1 == (float)i_0) && (P1 = _UNK_0076540c, DAT_008a00a8 == 4)) {
      fVar14 = (float10)_UNK_0076540c;
      P1 = (float)-fVar14;
    }
    *(float *)(*(int *)(puVar3 + 0x10) + -4 + DAT_008a00a8 * 4) = P1;
    if (*(int *)(*(int *)(puVar3 + 0xc) + 4) == 3) {
      *(undefined4 *)(puVar3 + -0x104) = 0;
      *(undefined4 *)(puVar3 + -0x110) = 0x30;
      *(undefined2 **)(puVar3 + -0x10c) = &DAT_020b8ea0;
      ffree(fVar14);
      uVar1 = FUN_005fdbd0(puVar3 + -0x104,8,0x784ff01,&DAT_00765434,puVar3 + -0x110,0x7939c8);
      *(undefined4 *)(puVar3 + -0x38) = uVar1;
      Var13 = extraout_ST0_05;
      if (*(int *)(puVar3 + -0x38) != 0) goto LAB_004d254e;
      ffree(extraout_ST0_05);
      fVar14 = (float10)thunk_FUN_00518448();
      if (P1 == (float)i_0) {
        P1 = _UNK_0076540c;
      }
      *(float *)(*(int *)(puVar3 + 0x10) + 0x10) = P1;
      *(undefined4 *)(puVar3 + -0x34) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0x3c) = 0;
    }
  }
  goto LAB_004d1bdc;
  while( true ) {
    iVar2 = iVar2 + -1;
    bVar11 = *pbVar5 < *pbVar8;
    bVar12 = *pbVar5 == *pbVar8;
    pbVar5 = pbVar5 + 1;
    pbVar8 = pbVar8 + 1;
    if (!bVar12) break;
code_r0x004d1dd1:
    if (iVar2 == 0) break;
  }
  if (bVar11 || bVar12) {
    puVar6 = &DAT_008a00c8;
    puVar9 = (undefined4 *)&DAT_019c6a04;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
  }
  else {
    puVar6 = &DAT_008a00c8;
    puVar9 = &DAT_019c6a24;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
  }
  *(undefined4 *)(puVar3 + -0x104) = 0;
  *(undefined4 *)(puVar3 + -0x110) = 4;
  *(int *)(puVar3 + -0x10c) = *(int *)(puVar3 + 0xc) + 0x28;
  ffree(fVar14);
  fVar14 = (float10)FUN_005fdbd0(puVar3 + -0x104,8,0x784ff00,&DAT_00765424,puVar3 + -0x110,0x79398c)
  ;
  *(undefined4 *)(puVar3 + -0x58) = 0;
  goto LAB_004d1bdc;
}


