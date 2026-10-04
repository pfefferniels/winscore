// FUN_00452648 @ 00452648 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00452648(int *param_1,int *param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  float fVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  undefined4 *puVar15;
  byte *pbVar16;
  undefined4 *puVar17;
  bool bVar18;
  bool bVar19;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  unkbyte10 extraout_ST0_02;
  unkbyte10 extraout_ST0_03;
  unkbyte10 extraout_ST0_04;
  unkbyte10 extraout_ST0_05;
  unkbyte10 extraout_ST0_06;
  unkbyte10 Var20;
  float10 extraout_ST0_07;
  float10 fVar21;
  unkbyte10 extraout_ST0_08;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  int local_1a4;
  uint local_1a0;
  int local_19c;
  undefined4 local_178;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 local_150;
  int iStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  int local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  int local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  int local_b8;
  undefined4 local_b4;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_7c;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  puVar22 = &stack0xfffffffc;
  puVar23 = &stack0xfffffffc;
  puVar24 = &stack0xfffffffc;
  puVar25 = &stack0xfffffffc;
  puVar26 = &stack0xfffffffc;
  puVar8 = &stack0xfffffffc;
  puVar10 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  puVar13 = &stack0xfffffffc;
  puVar11 = &stack0xfffffffc;
  puVar12 = &stack0xfffffffc;
  if (DAT_01fbb8a0 != 0x3ed) {
    DAT_01fbb8a0 = 0x3ed;
    DAT_007feaf0 = 1;
    ffree(in_ST0);
    thunk_FUN_00468df8(&DAT_007612bc);
    puVar12 = &stack0xfffffffc;
    in_ST0 = FUN_005f34d1(&stack0xfffffffc,0x454cab);
    if (9 < DAT_0078fb4c) {
      DAT_0078fb4c = 0;
    }
    DAT_007feae8 = 0;
    DAT_007feae4 = 0;
    goto LAB_00454cd0;
  }
  local_178 = 0;
LAB_0045266e:
  if ((_DAT_020b8ea0 & 0xff) != 0x58) {
    puVar15 = (undefined4 *)&DAT_020b90a0;
    puVar17 = &DAT_009ae2bc;
    for (iVar6 = 0x80; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar17 = *puVar15;
      puVar15 = puVar15 + 1;
      puVar17 = puVar17 + 1;
    }
    switch(*param_1) {
    case 0x71:
      DAT_007feaf0 = DAT_007feaf0 + -1;
      if (DAT_007feaf0 < 1) {
        DAT_007feaf0 = *param_2;
      }
      uStack_164 = 0;
      goto LAB_00454cee;
    case 0x72:
      DAT_007feaf0 = DAT_007feaf0 + 1;
      if (*param_2 < DAT_007feaf0) {
        DAT_007feaf0 = 1;
      }
      uStack_160 = 0;
      puVar13 = &stack0xfffffffc;
      goto LAB_00454cee;
    case 0x73:
      if (DAT_0078faf4 == 0x2020) {
        uStack_15c = 0;
        goto LAB_00454b8c;
      }
      if (DAT_007feae8 == 0) {
        DAT_007feae8 = DAT_007feaf0;
        FUN_005f33c9(&stack0xfffffffc,&UNK_00452985);
        puVar11 = puVar23;
        Var20 = FUN_005f34d1(puVar23,&UNK_004529a0);
        ffree(Var20);
        thunk_FUN_0044efa3(&PT_X0 + DAT_007feae8,&PT_Y0 + DAT_007feae8);
        *(undefined4 *)(puVar11 + -0x154) = 0;
        goto LAB_00454b8c;
      }
      if (DAT_007feae8 != DAT_007feaf0) {
        DAT_007feae0 = DAT_007feaf0;
        if (DAT_007feaf0 < DAT_007feae8) {
          ffree(in_ST0);
          thunk_FUN_0054c68f(&DAT_007feae8,&DAT_007feae0);
        }
        goto code_r0x00452ae7;
      }
      DAT_007feae8 = 1;
      DAT_007feae0 = *param_2;
      break;
    case 0x74:
code_r0x00452bb1:
      ffree(in_ST0);
      in_ST0 = thunk_FUN_00450d32(param_2);
      local_150 = 0;
      puVar12 = &stack0xfffffffc;
      goto LAB_00454cd0;
    case 0x75:
      goto code_r0x004537a3;
    case 0x76:
      DAT_007feadc = (undefined *)(DAT_007feaf0 + 1);
      iStack_14c = (*param_2 - (int)DAT_007feadc) + 1;
      if (0 < iStack_14c) goto code_r0x00452a5b;
      goto code_r0x00452aa1;
    case 0x77:
code_r0x00452b64:
      ffree(in_ST0);
      in_ST0 = thunk_FUN_0045058c(param_2,&DAT_007feaf0);
      local_140 = 0;
      goto LAB_00454cd0;
    case 0x78:
      goto LAB_004546c9;
    case 0x79:
      DAT_007feae8 = 1;
      DAT_007feae0 = *param_2;
      uStack_13c = 0;
code_r0x00452ae7:
      FUN_005f33c9(&stack0xfffffffc,&UNK_00452b05);
      puVar8 = puVar24;
      in_ST0 = FUN_005f34d1(puVar24,&UNK_00452b20);
      break;
    case 0x7a:
      goto code_r0x00453a39;
    default:
      if (*param_1 != 0) {
LAB_00454c41:
        ffree(in_ST0);
        in_ST0 = FUN_00454dbe(param_1,&DAT_007feaf0,param_2,param_3);
        local_168 = 0;
        puVar12 = &stack0xfffffffc;
        goto LAB_00454cd0;
      }
      local_16c = 0;
      if ((_DAT_020b8ea0 & 0xffffff) == 0x524c43) {
        ffree(in_ST0);
        thunk_FUN_004585b9(param_2);
        DAT_007feae8 = 0;
        local_138 = 0;
        puVar11 = &stack0xfffffffc;
        goto LAB_00454b8c;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 0x4c43) {
        local_134 = 0;
        goto code_r0x00452b64;
      }
      if ((_DAT_020b8ea0 & 0xff) == 0x51) {
        ffree(in_ST0);
        in_ST0 = thunk_FUN_0044dc3e(&DAT_007feaf0);
        local_130 = 0;
        puVar12 = &stack0xfffffffc;
        goto LAB_00454cd0;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 0x4553) {
        local_12c = 0;
        goto code_r0x00452bb1;
      }
      if ((_DAT_020b8ea0 & 0xff) == 0x58) {
        ffree(in_ST0);
        thunk_FUN_00468df8(&DAT_007612bc);
        puVar9 = &stack0xfffffffc;
        goto LAB_004546c9;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 0x4544) {
        *param_1 = 0x2e;
        local_120 = 0;
        goto LAB_00454c41;
      }
      if ((_DAT_020b8ea0 & 0xffffff) == 0x444552) {
        DAT_007feaf0 = -2;
        local_11c = 0;
        puVar12 = &stack0xfffffffc;
        goto LAB_00454cd0;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 0x4e55) {
        DAT_007feaf0 = -1;
        local_118 = 0;
        puVar12 = &stack0xfffffffc;
        goto LAB_00454cd0;
      }
      cVar5 = DAT_020b8ea0._1_1_;
      if ((_DAT_020b8ea0 & 0xff) == 0x48) {
        if (DAT_020b8ea0._1_1_ != 'Z') {
          DAT_007feaf0 = 1;
          local_110 = 0;
          puVar13 = &stack0xfffffffc;
          goto LAB_00454cee;
        }
        local_114 = 0;
        if ((1 < DAT_007feaf0) && (*(short *)((int)&DAT_01fbb8dc + DAT_007feaf0 * 2 + 2) < 1)) {
          (&PT_Y0)[DAT_007feaf0] = *(undefined4 *)(&DAT_02004cb8 + DAT_007feaf0 * 4);
          ffree(in_ST0);
          DAT_007fead4 = thunk_FUN_00450b9c(&DAT_007feaf0);
          local_1a4 = DAT_007feaf0 + -1;
          ffree(extraout_ST0);
          DAT_007fead0 = thunk_FUN_00450b9c(&local_1a4);
          *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fead4 + 1) * VEC_STRIDE) =
               *(undefined4 *)
                ((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fead0 + 1) * VEC_STRIDE);
          local_108 = 0;
          puVar12 = &stack0xfffffffc;
          in_ST0 = extraout_ST0_00;
          goto LAB_00454cd0;
        }
        local_10c = 0;
        puVar11 = &stack0xfffffffc;
        goto LAB_00454b8c;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 0x5256) {
        if ((1 < DAT_007feaf0) && (*(short *)((int)&DAT_01fbb8dc + DAT_007feaf0 * 2 + 2) < 1)) {
          (&PT_X0)[DAT_007feaf0] = *(undefined4 *)(&DAT_01fd3f78 + DAT_007feaf0 * 4);
          ffree(in_ST0);
          DAT_007fead4 = thunk_FUN_00450b9c(&DAT_007feaf0);
          local_1a4 = DAT_007feaf0 + -1;
          ffree(extraout_ST0_01);
          DAT_007fead0 = thunk_FUN_00450b9c(&local_1a4);
          *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fead4 * VEC_STRIDE) =
               *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fead0 * VEC_STRIDE);
          local_100 = 0;
          puVar12 = &stack0xfffffffc;
          in_ST0 = extraout_ST0_02;
          goto LAB_00454cd0;
        }
        local_104 = 0;
        puVar11 = &stack0xfffffffc;
        goto LAB_00454b8c;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 0x4b53) {
        *param_1 = 0x76;
        local_fc = 0;
      }
      else {
        if ((_DAT_020b8ea0 & 0xffff) != 0x5453) {
          bVar18 = (byte)DAT_020b8ea0 < 0xd;
          if ((byte)DAT_020b8ea0 == 0xd) goto code_r0x0045281f;
          iVar6 = 1;
          bVar19 = false;
          pbVar14 = (byte *)&DAT_020b8ea0;
          pbVar16 = &DAT_00761280;
          goto code_r0x00452e54;
        }
        *param_1 = 0x71;
        if (_DAT_020b8ea0 >> 0x18 == 0x2b) {
          *param_1 = 0x72;
        }
        local_f8 = 0;
      }
      goto LAB_0045266e;
    }
    *(undefined4 *)(puVar8 + -0x150) = 0;
    puVar10 = puVar8;
    goto LAB_00453e04;
  }
  if (DAT_0078faf4 == 0x2020) {
    puVar11 = &stack0xfffffffc;
    if (DAT_0078faf0 != 0) {
      ffree(in_ST0);
      thunk_FUN_00468df8(&DAT_007612b4);
      DAT_0078faf0 = 0;
      puVar11 = &stack0xfffffffc;
    }
  }
  else {
    ffree(in_ST0);
    thunk_FUN_00468df8(&DAT_007612bc);
    FUN_005f34d1(&stack0xfffffffc,0x45287b);
    DAT_0078faf0 = 0;
    puVar11 = puVar22;
  }
  *(undefined4 *)(puVar11 + -0x16c) = 0;
LAB_00454b8c:
  _DAT_020b8ea0 = CONCAT22(_DAT_020b8ea2,DAT_007611ec);
  Var20 = FUN_005f34d1(puVar11,0x454bbb);
  **(undefined4 **)(puVar11 + 8) = 0;
  *(undefined4 *)(puVar11 + -0xb8) = 0;
  goto LAB_00454db3;
code_r0x0045281f:
  *param_1 = 0x72;
  local_f4 = 0;
  goto LAB_0045266e;
  while( true ) {
    iVar6 = iVar6 + -1;
    bVar18 = *pbVar14 < *pbVar16;
    bVar19 = *pbVar14 == *pbVar16;
    pbVar14 = pbVar14 + 1;
    pbVar16 = pbVar16 + 1;
    if (!bVar19) break;
code_r0x00452e54:
    if (iVar6 == 0) break;
  }
  if (bVar18) {
LAB_00452f14:
    if ((_DAT_020b8ea0 & 0xffff) == 0x4854) {
      ffree(in_ST0);
      in_ST0 = thunk_FUN_00459c07(param_2);
      local_e8 = 0;
      puVar12 = &stack0xfffffffc;
      goto LAB_00454cd0;
    }
    if ((_DAT_020b8ea0 & 0xffff) == 0x4652) {
      local_e4 = 0;
LAB_004534cd:
      VEC_N = 0x19;
      local_98 = *param_2;
      DAT_007feac8 = (undefined *)0x1;
      while (0 < local_98) {
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
             (&PT_X0)[(int)DAT_007feac8] + DAT_0078df10;
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
             (&PT_Y0)[(int)DAT_007feac8] - DAT_0078df14;
        DAT_007feac4 = (undefined *)0x0;
        if (*(short *)((int)&DAT_01fbb8dc + (int)DAT_007feac8 * 2 + 2) == 1) {
          DAT_007feac4 = &DAT_0100962c;
        }
        if (1 < *(short *)((int)&DAT_01fbb8dc + (int)DAT_007feac8 * 2 + 2)) {
          DAT_007feac4 = &DAT_010000ff;
        }
        *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
             DAT_007feac4;
        VEC_N = VEC_N + 3;
        DAT_007feac8 = DAT_007feac8 + 1;
        local_98 = local_98 + -1;
      }
      *DAT_01fbb7c0 = VEC_N + -1;
      if ((_DAT_020b8ea0 & 0xffff) == 0x4652) {
        local_94 = 0;
        puVar13 = &stack0xfffffffc;
        goto LAB_00454cee;
      }
      local_90 = 0;
      puVar12 = &stack0xfffffffc;
    }
    else {
      if ((_DAT_020b8ea0 & 0xffffff) == 0x505043) {
        DAT_007fead8 = 0;
        local_e0 = *param_2;
        DAT_007feadc = (undefined *)0x1;
        _DAT_007feacc = VEC_N;
        for (; 0 < local_e0; local_e0 = local_e0 + -1) {
          if (*(short *)((int)&DAT_01fbb8dc + (int)DAT_007feadc * 2 + 2) < 1) {
            local_dc = 0;
            if (*(short *)((int)&DAT_01fbb8dc + (int)DAT_007feadc * 2 + 2) < 0) {
              if (DAT_007fead8 == 0) {
                local_d4 = 0;
              }
              else {
                *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
                     (&PT_X0)[DAT_007fead8] + DAT_0078df10;
                *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
                     (&PT_Y0)[DAT_007fead8] - DAT_0078df14;
                *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
                     0x1000000;
                VEC_N = VEC_N + 3;
                DAT_007fead8 = 0;
              }
              *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
                   (&PT_X0)[(int)DAT_007feadc] + DAT_0078df10;
              *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
                   (&PT_Y0)[(int)DAT_007feadc] - DAT_0078df14;
              *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) = 0;
              VEC_N = VEC_N + 3;
            }
          }
          else {
            local_d8 = 0;
            DAT_007fead8 = (int)DAT_007feadc;
          }
          local_d0 = 0;
          DAT_007feadc = (undefined *)((int)DAT_007feadc + 1);
        }
        *DAT_01fbb7c0 = VEC_N + -1;
        DAT_007feaf0 = 1;
        local_cc = 0;
        puVar13 = &stack0xfffffffc;
        goto LAB_00454cee;
      }
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00455043) {
        *param_1 = *param_2;
LAB_00453203:
        DAT_007fead8 = 0;
        local_c8 = *param_2;
        DAT_007feadc = (undefined *)0x1;
        if (0 < *param_2) {
          while (-1 < *(short *)((int)&DAT_01fbb8dc + (int)DAT_007feadc * 2 + 2)) {
            DAT_007feadc = (undefined *)((int)DAT_007feadc + 1);
            local_c8 = local_c8 + -1;
            if (local_c8 < 1) goto LAB_004534b3;
          }
          local_c4 = 0;
          local_b8 = -(int)DAT_007feadc / -1;
          DAT_007fead8 = (int)DAT_007feadc;
          while (0 < local_b8) {
            if (0 < *(short *)((int)&DAT_01fbb8dc + DAT_007fead8 * 2 + 2)) {
              local_b4 = 0;
              break;
            }
            DAT_007fead8 = DAT_007fead8 + -1;
            local_b8 = local_b8 + -1;
          }
          DAT_007feac8 = (undefined *)(DAT_007fead8 + 1);
          local_b0 = (*param_2 - (int)DAT_007feac8) + 1;
          DAT_007feaec = DAT_007fead8;
          if (0 < local_b0) {
            do {
              if (*(short *)((int)&DAT_01fbb8dc + (int)DAT_007feac8 * 2 + 2) == 0) {
                local_ac = 0;
              }
              else {
                DAT_007fead8 = DAT_007fead8 + 1;
                (&PT_X0)[DAT_007fead8] = (&PT_X0)[(int)DAT_007feac8];
                (&PT_Y0)[DAT_007fead8] = (&PT_Y0)[(int)DAT_007feac8];
                *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fead8 * 2 + 2) = 0;
                if (*(short *)((int)&DAT_01fbb8dc + (int)DAT_007feac8 * 2 + 2) == -3)
                goto LAB_004533d7;
                local_a8 = 0;
              }
              local_9c = 0;
              DAT_007feac8 = DAT_007feac8 + 1;
              local_b0 = local_b0 + -1;
              if (local_b0 < 1) break;
            } while( true );
          }
          goto LAB_004534cd;
        }
LAB_004534b3:
        puVar11 = &stack0xfffffffc;
        if (*param_2 == *param_1) goto LAB_00454b8c;
        local_c0 = 0;
        goto LAB_004534cd;
      }
      if ((_DAT_020b8ea0 & 0xffffff) == 0x445043) {
        ffree(in_ST0);
        iVar6 = thunk_FUN_00450b9c(param_2);
        VEC_N = iVar6 + 3;
        *DAT_01fbb7c0 = iVar6 + 2;
        local_8c = 0;
        puVar13 = &stack0xfffffffc;
        in_ST0 = extraout_ST0_03;
        goto LAB_00454cee;
      }
      if (((((_DAT_020b8ea0 & 0xffff) == 0x4f52) || ((_DAT_020b8ea0 & 0xffff) == 0x4953)) ||
          ((_DAT_020b8ea0 & 0xff) == 0x4d)) ||
         (((_DAT_020b8ea0 & 0xff) == 0x43 || ((_DAT_020b8ea0 & 0xffff) == 0x4744)))) {
        DAT_0078faf4 = DAT_020b8ea0;
        DAT_0078faf0 = 1;
        if ((_DAT_020b8ea0 & 0xffff) == 0x4953) {
          local_88 = 0;
          goto LAB_0045456e;
        }
        if (DAT_007feae4 != 0) {
          local_84 = 0;
          goto LAB_00453d2e;
        }
        DAT_007feae8 = 0;
        DAT_007feae4 = 1;
        _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_007611e8);
        FUN_005f33c9(&stack0xfffffffc,0x454c16);
        Var20 = FUN_005f34d1(puVar26,0x454c31);
        *(undefined4 *)(puVar26 + -0x7c) = 0;
        goto LAB_00454da0;
      }
      if ((((_DAT_020b8ea0 & 0xff) == 0x44) || ((_DAT_020b8ea0 & 0xff) == 0x55)) ||
         (((_DAT_020b8ea0 & 0xff) == 0x4c || ((_DAT_020b8ea0 & 0xff) == 0x52)))) {
        *param_1 = DAT_007feaf0;
        if ((DAT_007feae8 != 0) || (*param_3 == 0)) {
          *param_1 = *param_2;
        }
        ffree(in_ST0);
        in_ST0 = FUN_004552cc(param_1,param_3,&DAT_007feae8,&DAT_007feae0);
        puVar15 = &DAT_009ae2bc;
        puVar17 = (undefined4 *)&DAT_020b90a0;
        for (iVar6 = 0x80; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar17 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar17 = puVar17 + 1;
        }
        local_40 = 0;
        puVar12 = &stack0xfffffffc;
      }
      else {
        if ((_DAT_020b8ea0 & 0xffff) != 0x4e49) {
          if ((_DAT_020b8ea0 & 0xff) == 0x41) {
code_r0x00453a39:
            Var20 = FUN_005f34d1(&stack0xfffffffc,0x453a56);
            ffree(Var20);
            DAT_007fead8 = thunk_FUN_0059ad60(&DAT_007feaf4,&DAT_007feaac);
            if (DAT_007fead8 != 2) {
              fVar3 = (float)_DAT_007feaf4;
              iVar6 = DAT_007feaf0 * 2;
              P1 = fVar3;
              *(undefined2 *)(puVar25 + -0x19c) = in_FPUControlWord;
              *(ushort *)(puVar25 + -0x19a) = (ushort)*(undefined4 *)(puVar25 + -0x19c) | 0xc00;
              *(int *)(puVar25 + -0x198) = (int)ROUND(fVar3);
              *(undefined2 *)((int)&DAT_01fbb8dc + iVar6 + 2) = *(undefined2 *)(puVar25 + -0x198);
              ffree(extraout_ST0_05);
              DAT_007feadc = (undefined *)thunk_FUN_00450b9c(&DAT_007feaf0);
              DAT_007feac4 = (undefined *)0x1000000;
              if (P1 == f_1) {
                DAT_007feac4 = &DAT_0100962c;
              }
              if (f_1 < P1) {
                DAT_007feac4 = DAT_007feac4 + 0xff;
              }
              if (P1 == f_0) {
                DAT_007feac4 = (undefined *)0x0;
              }
              *(undefined **)
               ((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + ((int)DAT_007feadc + 2) * VEC_STRIDE) =
                   DAT_007feac4;
              *(undefined4 *)(puVar25 + -0x30) = 0;
              puVar12 = puVar25;
              in_ST0 = extraout_ST0_06;
              goto LAB_00454cd0;
            }
            *(undefined4 *)(puVar25 + -0x34) = 0;
            puVar11 = puVar25;
          }
          else if ((_DAT_020b8ea0 & 0xff) == 0x7e) {
            if (cVar5 != 'v') {
              local_30 = 0;
              ffree(in_ST0);
              Var20 = FUN_00455e89(&DAT_007feadc,param_2,&DAT_007feae4);
              DAT_007feaf0 = (int)DAT_007feadc;
              ffree(Var20);
              in_ST0 = thunk_FUN_0044ec7c(&PT_X0 + (int)DAT_007feadc,&PT_Y0 + (int)DAT_007feadc);
              local_28 = 0;
              puVar12 = &stack0xfffffffc;
              goto LAB_00454cd0;
            }
            if (DAT_007feac0 == 0) {
              DAT_007feac0 = 1;
              _DAT_007feabc = *param_2;
            }
            ffree(in_ST0);
            FUN_0045623f(&DAT_007feac0,&DAT_007feabc,param_3);
            local_2c = 0;
            puVar11 = &stack0xfffffffc;
          }
          else {
            local_24 = 0;
            puVar11 = &stack0xfffffffc;
          }
          goto LAB_00454b8c;
        }
        *param_3 = 1;
        ffree(in_ST0);
        FUN_00455887(&DAT_007feaf0,param_2,&DAT_0078fb4c);
code_r0x004537a3:
        _DAT_007feab4 =
             (float)(int)(&PT_X0)[DAT_007feaf0] +
             (float)(int)((&DAT_01fd3f80)[DAT_007feaf0] - (&PT_X0)[DAT_007feaf0]) / f_2;
        local_19c = (&DAT_02004cc0)[DAT_007feaf0] - (&PT_Y0)[DAT_007feaf0];
        _DAT_007feab0 =
             (float)((float10)(int)(&PT_Y0)[DAT_007feaf0] + (float10)local_19c / (float10)f_2);
        ffree((float10)local_19c / (float10)f_2);
        Var20 = thunk_FUN_004509c3(&DAT_007feaf0,param_2);
        DAT_007feaf0 = DAT_007feaf0 + 1;
        (&PT_X0)[DAT_007feaf0] = (int)ROUND(_DAT_007feab4);
        local_1a0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        local_19c = (int)ROUND(_DAT_007feab0);
        (&PT_Y0)[DAT_007feaf0] = local_19c;
        *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007feaf0 * 2 + 2) = 0;
        ffree(Var20);
        DAT_007fead8 = thunk_FUN_00450b9c(&DAT_007feaf0);
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_007fead8 * VEC_STRIDE) =
             (int)ROUND((float)DAT_0078df10 + _DAT_007feab4);
        local_1a0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        local_19c = (int)ROUND(_DAT_007feab0 - (float)DAT_0078df14);
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fead8 + 1) * VEC_STRIDE) =
             (int)ROUND(_DAT_007feab0 - (float)DAT_0078df14);
        *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_007fead8 + 2) * VEC_STRIDE) = 0;
        *param_2 = *param_2 + 1;
        DAT_01d953e0 = DAT_007feaf0;
        _DAT_01c25e58 = *param_2;
        local_3c = 0;
        puVar12 = &stack0xfffffffc;
        in_ST0 = extraout_ST0_04;
      }
    }
LAB_00454cd0:
    ffree(in_ST0);
    in_ST0 = FUN_00455887(&DAT_007feaf0,*(undefined4 *)(puVar12 + 0xc),&DAT_0078fb4c);
    puVar13 = puVar12;
    goto LAB_00454cee;
  }
  iVar6 = 1;
  bVar18 = false;
  pbVar14 = (byte *)&DAT_020b8ea0;
  pbVar16 = &DAT_0076127c;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar18 = *pbVar14 < *pbVar16;
    bVar19 = *pbVar14 == *pbVar16;
    pbVar14 = pbVar14 + 1;
    pbVar16 = pbVar16 + 1;
  } while (bVar19);
  if (!bVar18 && !bVar19) goto LAB_00452f14;
  if (DAT_007feae4 != 1) {
    ffree(in_ST0);
    in_ST0 = thunk_FUN_00518448();
    local_1a0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    local_19c = (int)ROUND((float)DAT_007feaf0 + P1);
    DAT_007feaf0 = local_19c;
    if (local_19c < 1) {
      DAT_007feaf0 = 1;
    }
    if (*param_2 < DAT_007feaf0) {
      DAT_007feaf0 = *param_2;
    }
    local_ec = 0;
    puVar13 = &stack0xfffffffc;
    goto LAB_00454cee;
  }
  local_f0 = 0;
LAB_00453d2e:
  ffree(in_ST0);
  in_ST0 = thunk_FUN_00518448();
  if ((P1 == f_0) || (P2 == f_0)) {
    local_7c = 0;
    puVar11 = &stack0xfffffffc;
    goto LAB_00454b8c;
  }
  DAT_007feae8 = (int)ROUND(P1);
  local_1a0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_007feae0 = (int)ROUND(P2);
  local_19c = DAT_007feae0;
  puVar10 = &stack0xfffffffc;
  if (DAT_007feae0 < DAT_007feae8) {
    ffree(in_ST0);
    in_ST0 = thunk_FUN_0054c68f(&DAT_007feae8,&DAT_007feae0);
    puVar10 = &stack0xfffffffc;
  }
LAB_00453e04:
  if (**(int **)(puVar10 + 0xc) < DAT_007feae0) {
    DAT_007feae0 = **(int **)(puVar10 + 0xc);
  }
  ffree(in_ST0);
  Var20 = thunk_FUN_0044ec7c(&PT_X0 + DAT_007feae8,&PT_Y0 + DAT_007feae8);
  ffree(Var20);
  in_ST0 = thunk_FUN_0044efa3(&PT_X0 + DAT_007feae0,&PT_Y0 + DAT_007feae0);
  if (DAT_0078faf4 == 0x4f43) {
    ffree(in_ST0);
    Var20 = FUN_00455887(&DAT_007feaf0,*(undefined4 *)(puVar10 + 0xc),&DAT_0078fb4c);
    ffree(Var20);
    FUN_00455c1c(*(undefined4 *)(puVar10 + 0xc),&DAT_007feae8,&DAT_007feae0);
    DAT_01d953e0 = DAT_007feae8;
    DAT_007feac0 = DAT_007feae8;
    _DAT_007feabc = DAT_007feae0;
    *(undefined4 *)(puVar10 + -0x74) = 0;
LAB_00453f75:
    **(undefined4 **)(puVar10 + 8) = 0;
    Var20 = FUN_005f34d1(puVar10,0x453f99);
    ffree(Var20);
    thunk_FUN_00468df8(&DAT_007612bc);
    *(undefined4 *)(puVar10 + -0x70) = 0;
    puVar11 = puVar10;
    goto LAB_00454b8c;
  }
  if (DAT_0078faf4 == 0x204d) {
    DAT_01d953e0 = DAT_007feae8;
    DAT_007feac0 = DAT_007feae8;
    _DAT_007feabc = DAT_007feae0;
    ffree(in_ST0);
    FUN_00455887(&DAT_007feaf0,*(undefined4 *)(puVar10 + 0xc),&DAT_0078fb4c);
    FUN_005f33c9(puVar10,0x453f56);
    FUN_005f34d1(puVar10,0x453f71);
    goto LAB_00453f75;
  }
  if (DAT_0078faf4 == 0x4f52) {
    ffree(in_ST0);
    Var20 = FUN_00455887(&DAT_007feaf0,*(undefined4 *)(puVar10 + 0xc),&DAT_0078fb4c);
    do {
      ffree(Var20);
      DAT_007fead8 = thunk_FUN_0059c770();
      if (DAT_007fead8 == 2) {
        fVar21 = (float10)DAT_007feab8;
        DAT_007feab8 = (float)-fVar21;
        *(undefined4 *)(puVar10 + -0x6c) = 0;
      }
      else if (DAT_007fead8 == 3) {
        *(undefined4 *)(puVar10 + -0x68) = 0;
        fVar21 = extraout_ST0_07;
      }
      else {
        puVar15 = &DAT_009ae2bc;
        puVar17 = (undefined4 *)&DAT_020b8ea0;
        for (iVar6 = 0x80; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar17 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar17 = puVar17 + 1;
        }
        bVar18 = (byte)DAT_020b8ea0 < 0x20;
        if ((char)(byte)DAT_020b8ea0 < '!') {
          *(undefined4 *)(puVar10 + -100) = 0;
          goto LAB_00454aeb;
        }
        iVar6 = 1;
        pbVar14 = (byte *)&DAT_020b8ea0;
        pbVar16 = &DAT_00761280;
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar2 = *pbVar16;
          bVar1 = *pbVar14;
          bVar18 = bVar1 < bVar2;
          pbVar14 = pbVar14 + 1;
          pbVar16 = pbVar16 + 1;
        } while (bVar1 == bVar2);
        if (bVar18) goto LAB_0045412c;
        ffree(extraout_ST0_07);
        fVar21 = (float10)thunk_FUN_00518448();
        if (P1 == f_0) {
          P1 = DAT_007feab8;
        }
        DAT_007feab8 = P1;
      }
      ffree(fVar21);
      Var20 = FUN_00455fef(&DAT_007feae8,&DAT_007feae0,&DAT_007feab8);
      piVar4 = DAT_01fbb7c0;
      DAT_007feaf0 = 1;
      ffree(Var20);
      iVar6 = thunk_FUN_00450b9c(*(undefined4 *)(puVar10 + 0xc));
      *piVar4 = iVar6 + 2;
      ffree(extraout_ST0_08);
      thunk_FUN_00549422();
      Var20 = FUN_005f34d1(puVar10,0x454110);
      *(undefined4 *)(puVar10 + -0x5c) = 0;
    } while( true );
  }
  if (DAT_0078faf4 == 0x4744) {
    ffree(in_ST0);
    Var20 = FUN_00455887(&DAT_007feaf0,*(undefined4 *)(puVar10 + 0xc),&DAT_0078fb4c);
    if (DAT_007feae0 < DAT_007feae8) {
      ffree(Var20);
      Var20 = thunk_FUN_0054c68f(&DAT_007feae8,&DAT_007feae0);
    }
    DAT_007fead8 = DAT_007feae8;
    DAT_007feae8 = DAT_007feae8 + 1;
    DAT_007feaf0 = DAT_007feae0 + -1;
    if (DAT_007feaf0 < DAT_007feae8) {
      *(undefined4 *)(puVar10 + -0x58) = 0;
    }
    else {
      **(int **)(puVar10 + 0xc) = (**(int **)(puVar10 + 0xc) - (DAT_007feaf0 - DAT_007feae8)) + -1;
      _DAT_01c25e58 = **(int **)(puVar10 + 0xc);
      *(int *)(puVar10 + -0x1a0) = DAT_007feaf0 + 1;
      ffree(Var20);
      Var20 = thunk_FUN_00450b9c(puVar10 + -0x1a0);
      iVar6 = (**(int **)(puVar10 + 0xc) - DAT_007feae8) + 1;
      *(int *)(puVar10 + -0x54) = iVar6;
      DAT_007feadc = (undefined *)DAT_007feae8;
      while (0 < iVar6) {
        DAT_007feaf0 = DAT_007feaf0 + 1;
        (&PT_X0)[(int)DAT_007feadc] = (&PT_X0)[DAT_007feaf0];
        (&PT_Y0)[(int)DAT_007feadc] = (&PT_Y0)[DAT_007feaf0];
        *(undefined2 *)((int)&DAT_01fbb8dc + (int)DAT_007feadc * 2 + 2) =
             *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007feaf0 * 2 + 2);
        DAT_007feadc = (undefined *)((int)DAT_007feadc + 1);
        *(int *)(puVar10 + -0x54) = *(int *)(puVar10 + -0x54) + -1;
        iVar6 = *(int *)(puVar10 + -0x54);
      }
      VEC_N = 0x19;
      iVar6 = **(int **)(puVar10 + 0xc);
      *(int *)(puVar10 + -0x50) = iVar6;
      DAT_007feadc = (undefined *)0x1;
      while (0 < iVar6) {
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
             (&PT_X0)[(int)DAT_007feadc] + DAT_0078df10;
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
             (&PT_Y0)[(int)DAT_007feadc] - DAT_0078df14;
        DAT_007feac8 = (undefined *)0x0;
        if (*(short *)((int)&DAT_01fbb8dc + (int)DAT_007feadc * 2 + 2) == 1) {
          DAT_007feac8 = &DAT_0100962c;
        }
        if (1 < *(short *)((int)&DAT_01fbb8dc + (int)DAT_007feadc * 2 + 2)) {
          DAT_007feac8 = &DAT_010000ff;
        }
        *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
             DAT_007feac8;
        VEC_N = VEC_N + 3;
        DAT_007feadc = (undefined *)((int)DAT_007feadc + 1);
        *(int *)(puVar10 + -0x50) = *(int *)(puVar10 + -0x50) + -1;
        iVar6 = *(int *)(puVar10 + -0x50);
      }
      *DAT_01fbb7c0 = VEC_N + -1;
    }
    DAT_007feae8 = 0;
    DAT_007feae0 = 0;
    ffree(Var20);
    thunk_FUN_00468df8(&DAT_007612bc);
    FUN_005f34d1(puVar10,0x45445a);
    DAT_0078faf0 = 0;
    *(undefined4 *)(puVar10 + -0x4c) = 0;
    puVar11 = puVar10;
    goto LAB_00454b8c;
  }
  if (DAT_0078faf4 != 0x5243) {
    FUN_005f33c9(puVar10,0x4544a2);
    in_ST0 = FUN_005f34d1(puVar10,0x4544bd);
  }
  if (DAT_0078faf4 == 0x5243) {
    ffree(in_ST0);
    Var20 = FUN_00455887(&DAT_007feaf0,*(undefined4 *)(puVar10 + 0xc),&DAT_0078fb4c);
    ffree(Var20);
    thunk_FUN_004575c8(*(undefined4 *)(puVar10 + 0xc),&DAT_007feae8,&DAT_007feae0);
    DAT_007feae8 = 0;
    DAT_007feae0 = 0;
    in_ST0 = FUN_005f34d1(puVar10,0x454545);
  }
  else {
    *(undefined4 *)(puVar10 + -0x48) = 0;
  }
  DAT_007feae4 = 0;
  if (DAT_0078faf4 == 0x4953) {
    *(undefined4 *)(puVar10 + -0x44) = 0;
LAB_0045456e:
    ffree(in_ST0);
    thunk_FUN_0054946a(&DAT_00761254,1);
    FUN_005f33c9(puVar10,0x45459f);
    Var20 = FUN_005f34d1(puVar10,0x4545ba);
    DAT_007feae8 = 1;
    DAT_007feae0 = **(int **)(puVar10 + 0xc);
    ffree(Var20);
    thunk_FUN_00571f5d("Type numbers for size x, size y.",0x21);
    Var20 = FUN_005f34d1(puVar10,0x454604);
    if ((byte)DAT_020b8ea0 != '\x02') {
      ffree(Var20);
      in_ST0 = thunk_FUN_00518448();
      fVar3 = P2;
      P3 = P2;
      P2 = P1;
      if (fVar3 == f_0) {
        P3 = P1;
      }
      if (P1 == f_0) {
        P2 = DAT_007feaa8;
        P3 = DAT_007feaa4;
      }
      else {
        *(undefined4 *)(puVar10 + -0x18) = 0;
      }
      DAT_007feaa8 = P2;
      DAT_007feaa4 = P3;
      if (P2 == f_0) goto code_r0x004546b6;
      ffree(in_ST0);
      Var20 = FUN_00455887(&DAT_007feaf0,*(undefined4 *)(puVar10 + 0xc),&DAT_0078fb4c);
      DAT_007feaa0 = (&PT_X0)[DAT_007feae8];
      DAT_007fea9c = (&PT_Y0)[DAT_007feae8];
      *(int *)(puVar10 + -0x198) = (DAT_007feaa0 + -8000) / 100;
      _DAT_007feab4 = P2 * (float)*(int *)(puVar10 + -0x198);
      ffree(Var20);
      fVar21 = (float10)anint(puVar10,0x454814);
      *(int *)(puVar10 + -0x198) = (int)ROUND(fVar21);
      DAT_007feaa0 = (*(int *)(puVar10 + -0x198) * 100 - DAT_007feaa0) + 8000;
      *(int *)(puVar10 + -0x198) = (DAT_007fea9c + 19000) / 100;
      _DAT_007feab4 = P3 * (float)*(int *)(puVar10 + -0x198);
      ffree(extraout_ST1);
      fVar21 = (float10)anint(puVar10,0x454889);
      *(int *)(puVar10 + -0x198) = (int)ROUND(fVar21);
      DAT_007fea9c = (*(int *)(puVar10 + -0x198) * 100 - DAT_007fea9c) + -19000;
      VEC_N = 0x19;
      iVar6 = **(int **)(puVar10 + 0xc);
      *(int *)(puVar10 + -0x10) = iVar6;
      DAT_007feadc = (undefined *)0x1;
      iVar7 = (int)DAT_007feadc;
      Var20 = extraout_ST1_00;
      while (DAT_007feadc = (undefined *)iVar7, 0 < iVar6) {
        if ((iVar7 < DAT_007feae8) || (DAT_007feae0 < iVar7)) {
          *(undefined4 *)(puVar10 + -0xc) = 0;
        }
        else {
          *(int *)(puVar10 + -0x198) = ((&PT_X0)[iVar7] + -8000) / 100;
          _DAT_007feab4 = P2 * (float)*(int *)(puVar10 + -0x198);
          ffree(Var20);
          fVar21 = (float10)anint(puVar10,0x454959);
          *(int *)(puVar10 + -0x198) = (int)ROUND(fVar21);
          (&PT_X0)[iVar7] = (*(int *)(puVar10 + -0x198) * 100 - DAT_007feaa0) + 8000;
          *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
               (&PT_X0)[(int)DAT_007feadc] + DAT_0078df10;
          iVar6 = (int)DAT_007feadc;
          *(int *)(puVar10 + -0x198) = ((&PT_Y0)[(int)DAT_007feadc] + 19000) / 100;
          _DAT_007feab4 = P3 * (float)*(int *)(puVar10 + -0x198);
          ffree(extraout_ST1_01);
          fVar21 = (float10)anint(puVar10,0x454a14);
          *(int *)(puVar10 + -0x198) = (int)ROUND(fVar21);
          (&PT_Y0)[iVar6] = (*(int *)(puVar10 + -0x198) * 100 - DAT_007fea9c) + -19000;
          *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
               (&PT_Y0)[(int)DAT_007feadc] - DAT_0078df14;
          Var20 = extraout_ST1_02;
        }
        VEC_N = VEC_N + 3;
        iVar7 = (int)DAT_007feadc + 1;
        *(int *)(puVar10 + -0x10) = *(int *)(puVar10 + -0x10) + -1;
        iVar6 = *(int *)(puVar10 + -0x10);
      }
      P2 = (float)DAT_007feaa0;
      P3 = (float)DAT_007fea9c;
      DAT_007feae8 = 0;
      ffree(Var20);
      Var20 = thunk_FUN_00549422();
      *(undefined4 *)(puVar10 + -8) = 0;
      goto LAB_00454da0;
    }
    *(undefined4 *)(puVar10 + -0x1c) = 0;
    puVar9 = puVar10;
    goto LAB_004546c9;
  }
  *(undefined4 *)(puVar10 + -0x40) = 0;
LAB_00454aeb:
  DAT_01fbb8a0 = 0x3ea;
  FUN_005f33c9(puVar10,0x454b14);
  Var20 = FUN_005f34d1(puVar10,0x454b2f);
  ffree(Var20);
  Var20 = thunk_FUN_0044e9e5(&DAT_007fead8);
  ffree(Var20);
  Var20 = thunk_FUN_00468df8(&DAT_007612b4);
  DAT_007feae8 = 0;
  *DAT_01fbb7c0 = VEC_N + -1;
  *(undefined4 *)(puVar10 + -0x120) = 0;
  goto LAB_00454da0;
LAB_004533d7:
  DAT_007feadc = DAT_007feac8 + 1;
  local_a4 = (*param_2 - (int)DAT_007feadc) + 1;
  while (0 < local_a4) {
    DAT_007fead8 = DAT_007fead8 + 1;
    (&PT_X0)[DAT_007fead8] = (&PT_X0)[(int)DAT_007feadc];
    (&PT_Y0)[DAT_007fead8] = (&PT_Y0)[(int)DAT_007feadc];
    *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fead8 * 2 + 2) =
         *(undefined2 *)((int)&DAT_01fbb8dc + (int)DAT_007feadc * 2 + 2);
    DAT_007feadc = DAT_007feadc + 1;
    local_a4 = local_a4 + -1;
  }
  *param_2 = DAT_007fead8;
  _DAT_01c25e58 = DAT_007fead8;
  local_a0 = 0;
  goto LAB_00453203;
LAB_0045412c:
  *(undefined4 *)(puVar10 + -0x60) = 0;
  puVar9 = puVar10;
LAB_004546c9:
  *DAT_01fbb7c0 = VEC_N + -1;
  FUN_005f33c9(puVar9,0x4546f8);
  FUN_005f34d1(puVar9,0x454713);
  DAT_007feae4 = 0;
  DAT_007feae8 = 0;
  DAT_007feaf0 = 1;
  _DAT_020b8ea0 = CONCAT22((short)(_DAT_020b8ea0 >> 0x10),DAT_00761210);
  in_ST0 = FUN_005f34d1(puVar9,0x454771);
  *(undefined4 *)(puVar9 + -0x124) = 0;
  puVar13 = puVar9;
  goto LAB_00454cee;
code_r0x004546b6:
  *(undefined4 *)(puVar10 + -0x14) = 0;
  goto LAB_0045456e;
  while( true ) {
    DAT_007feadc = (undefined *)((int)DAT_007feadc + 1);
    iStack_14c = iStack_14c + -1;
    if (iStack_14c < 1) break;
code_r0x00452a5b:
    if (*(short *)((int)&DAT_01fbb8dc + (int)DAT_007feadc * 2 + 2) != 0) {
      uStack_148 = 0;
      goto code_r0x00452aac;
    }
  }
code_r0x00452aa1:
  DAT_007feadc = (undefined *)0x1;
code_r0x00452aac:
  DAT_007feaf0 = (int)DAT_007feadc;
  uStack_144 = 0;
  puVar13 = &stack0xfffffffc;
LAB_00454cee:
  ffree(in_ST0);
  Var20 = thunk_FUN_0044e9e5(&DAT_007feaf0);
  if ((DAT_007feae8 != 0) && (DAT_0078faf4 == 0x204d)) {
    ffree(Var20);
    Var20 = thunk_FUN_0044efa3(&PT_X0 + DAT_007feae8,&PT_Y0 + DAT_007feae8);
    if (DAT_007feae0 != 0) {
      FUN_005f33c9(puVar13,0x454d67);
      Var20 = FUN_005f34d1(puVar13,0x454d82);
    }
  }
  _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_007611e8);
  *(undefined4 *)(puVar13 + -0x170) = 0;
LAB_00454da0:
  puVar15 = (undefined4 *)&DAT_020b90a0;
  puVar17 = &DAT_009ae2bc;
  for (iVar6 = 0x80; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar17 = *puVar15;
    puVar15 = puVar15 + 1;
    puVar17 = puVar17 + 1;
  }
LAB_00454db3:
  ffree(Var20);
  return;
}


