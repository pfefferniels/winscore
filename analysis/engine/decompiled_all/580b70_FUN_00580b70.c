// FUN_00580b70 @ 00580b70 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00581640) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00580b70(int *param_1)

{
  byte bVar1;
  float fVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  char *pcVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar10;
  unkbyte10 Var11;
  float10 extraout_ST1;
  undefined4 uStack_224;
  undefined1 *puStack_220;
  undefined4 uStack_21c;
  uint uStack_218;
  int local_214;
  undefined4 auStack_210 [8];
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  int local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  int local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 local_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_c;
  
  if ((*param_1 == 8) && (DAT_020b8e60._3_1_ != 0x43)) {
    local_1f0 = 0;
  }
  else {
    DAT_009a9080 = P3;
    if ((DAT_02052740 == 0) && (P3 == f_0)) {
      P3 = f_100;
    }
  }
  if (0x19 < *param_1 - 1U) {
    if (*param_1 == 0x50) {
      P1 = f_0;
      local_e4 = 0;
    }
    else {
      if (*param_1 != 0x51) {
        if (*param_1 != 0x5e) {
          if (0x5a < *param_1) {
            local_1e8 = 0;
            goto LAB_005821b0;
          }
          if ((*param_1 < 0x53) || (0x56 < *param_1)) {
            if ((*param_1 < 0x57) || (0x5a < *param_1)) {
              if (0x52 < *param_1) goto LAB_00582b8b;
              if (0x4c < *param_1) {
                local_1d8 = 0;
                goto code_r0x0058217a;
              }
              if (*param_1 < 0x49) {
                local_1d0 = 0;
                goto LAB_005824fe;
              }
              local_1d4 = 0;
              goto LAB_00582537;
            }
            local_1e0 = 0;
            goto code_r0x00581e84;
          }
          local_1e4 = 0;
          goto code_r0x00581a26;
        }
        local_1ec = 0;
        P1 = f_12;
        P4 = f_18;
        P5 = f_10;
        P8 = f_101;
        P9 = f_101;
        local_c = 0;
        goto LAB_00582b19;
      }
      P1 = f_15;
    }
    P13 = f_m1;
    local_c0 = 0;
    goto LAB_00582b19;
  }
  iVar3 = *param_1 + -1;
  bVar9 = iVar3 == 0;
  switch(iVar3) {
  case 0:
code_r0x00581a26:
    P49._0_1_ = DAT_020b8e64;
    if (DAT_020b8ea0._1_1_ == 'N') {
      iVar3 = *param_1;
      if (iVar3 != 0x53) {
        if (iVar3 == 0x54) {
          P6 = f_1;
          P7 = f_2;
          local_1c4 = 0;
        }
        else if (iVar3 == 0x55) {
          P9 = f_1;
          P7 = f_0_5;
          local_1c0 = 0;
        }
        else {
          if (iVar3 != 0x56) goto LAB_00581d93;
          P9 = f_2;
          P7 = f_0_25;
          local_1bc = 0;
        }
        goto LAB_00581d20;
      }
LAB_00581d93:
      P6 = f_2;
      P7 = f_4;
      local_1c8 = 0;
    }
    else {
      local_1cc = 0;
      P48._0_1_ = DAT_020b8e64;
      if (DAT_020b8e64 == 0x44) {
        P48._0_1_ = DAT_020b8e65;
      }
      local_1b8 = 0xb;
      DAT_009a907c = 5;
      do {
        if ((*(char *)((int)&DAT_020b8e5c + DAT_009a907c + 3) == 'R') &&
           (*(char *)((int)&DAT_020b8e60 + DAT_009a907c) == 'H')) {
          local_1b4 = 0;
          ffree(in_ST0);
          Var11 = FUN_00582d05();
          ffree(Var11);
          in_ST0 = (float10)FUN_00582d05();
          if (*(char *)((int)&DAT_020b8e60 + DAT_009a907c + 1) != 'G') {
            ffree(in_ST0);
            in_ST0 = (float10)FUN_00582d56(DAT_009a907c + 0x20b8e5f,1,&f_1,&DAT_009a9078);
            if (-1 < DAT_009a9078) goto LAB_00581d20;
            local_1a8 = 0;
            goto LAB_00582b19;
          }
          local_1ac = 0;
          P8 = f_100;
          if (P4 < f_0) {
            in_ST0 = (float10)f_100;
            P8 = (float)-in_ST0;
          }
          P4 = P8 + P4;
          P8 = f_101;
          P9 = f_1;
          if (P5 == f_0) {
            P5 = f_10;
            if (P49._0_1_ == 0x44) {
              P5 = f_20;
              if (P4 == f_100) {
                P4 = f_113;
              }
            }
            else {
              local_194 = 0;
            }
          }
          else {
            local_198 = 0;
          }
          P7 = f_65;
          local_190 = 0;
          goto LAB_00581dd4;
        }
        DAT_009a907c = DAT_009a907c + 1;
        local_1b8 = local_1b8 + -1;
      } while (0 < local_1b8);
      if (P7 == f_0) {
        P7 = f_1;
      }
      local_1b0 = 0;
LAB_00581d20:
      if (P5 == f_0) {
        P5 = f_10;
        if (P49._0_1_ == 0x44) {
          P5 = f_20;
          if (P4 == f_0) {
            P4 = f_13;
          }
        }
        else {
          local_1a0 = 0;
        }
      }
      else {
        local_1a4 = 0;
      }
    }
    if (P4 == f_0) {
      P4 = f_1;
    }
LAB_00581dd4:
    P1 = f_0;
    if (P48._0_1_ == 0x46) {
      P1 = f_1;
    }
    if (P48._0_1_ == 0x53) {
      P1 = f_2;
    }
    if (P48._0_1_ == 0x4e) {
      P1 = f_3;
    }
    P5 = P1 + P5;
    P1 = f_1;
    local_19c = 0;
    break;
  case 1:
code_r0x00581e84:
    if (DAT_020b8e64 == 0x53) {
      local_18c = 0;
      P5 = f_2;
      P7 = f_0_25;
      local_15c = 0;
    }
    else if (DAT_020b8e64 == 0x45) {
      local_188 = 0;
      P5 = f_1;
      P7 = f_0_5;
      local_160 = 0;
    }
    else if (DAT_020b8e64 == 0x51) {
      local_184 = 0;
      P5 = f_0;
      P7 = f_1;
      local_158 = 0;
    }
    else if (DAT_020b8e64 == 0x48) {
      local_180 = 0;
      P5 = f_m1;
      P7 = f_2;
      local_164 = 0;
    }
    else if (DAT_020b8e64 == 0x57) {
      local_17c = 0;
      P5 = f_m2;
      P7 = f_4;
      local_168 = 0;
    }
    else {
      if (DAT_020b8e64 == 0x4f) goto LAB_0058248b;
      local_174 = 10;
      DAT_009a907c = 6;
      do {
        if ((*(char *)((int)&DAT_020b8e5c + DAT_009a907c + 3) == 'R') &&
           (*(char *)((int)&DAT_020b8e60 + DAT_009a907c) == 'H')) {
          local_170 = 0;
          ffree(in_ST0);
          Var11 = FUN_00582d05();
          ffree(Var11);
          in_ST0 = (float10)FUN_00582d05();
          if (*(char *)((int)&DAT_020b8e60 + DAT_009a907c + 1) == 'G') {
            P5 = f_1;
            P4 = f_100;
            P7 = f_65;
            local_150 = 0;
            goto LAB_00582100;
          }
          local_154 = 0;
          ffree(in_ST0);
          in_ST0 = (float10)FUN_00582d56(DAT_009a907c + 0x20b8e5f,1,&f_2,&DAT_009a9078);
          if (-1 < DAT_009a9078) goto LAB_00582100;
          local_14c = 0;
          goto LAB_00582b19;
        }
        DAT_009a907c = DAT_009a907c + 1;
        local_174 = local_174 + -1;
      } while (0 < local_174);
      local_16c = 0;
    }
LAB_00582100:
    P1 = f_2;
    P9 = f_0;
    if (P7 == f_0) {
      P7 = f_1;
    }
    local_148 = 0;
    break;
  case 2:
LAB_00582537:
    if (DAT_020b8e60._3_1_ == 0x4d) {
      local_144 = 0;
      P1 = f_11;
      DAT_009a9078 = 0;
      if (DAT_020b8e64 != 0x20) {
        DAT_009a9078 = DAT_020b8e64 - 0x30;
      }
      if ((9 < DAT_009a9078) && (DAT_020b8e65 != 0x20)) {
        DAT_009a9078 = DAT_020b8e65 - 0x30;
      }
      if ((DAT_009a9078 < 1) || (9 < DAT_009a9078)) {
        local_64 = 0;
      }
      else {
        local_214 = DAT_009a9078 + 10;
        P1 = (float)local_214;
        P3 = DAT_009a9080;
        ffree(in_ST0);
        in_ST0 = (float10)FUN_00582d05();
      }
      P10 = P1;
      P1 = f_5;
      if (P4 != f_0) {
        P1 = P4;
      }
      P7 = f_m10;
      if (DAT_020b8e64 == 0x44) {
        P7 = f_m20;
        if (P4 == f_0) {
          P1 = f_6;
        }
      }
      else {
        local_60 = 0;
      }
      P4 = P1;
      P1 = f_6;
      local_5c = 0;
    }
    else {
      *param_1 = *param_1 + -2;
      if (*param_1 == 0x48) {
        P5 = f_1;
      }
      if (*param_1 == 0x49) {
        P5 = f_2;
      }
      if (*param_1 == 0x2d) {
        P5 = f_3;
      }
      if (*param_1 == 0x4a) {
        P5 = f_4;
      }
      if ((DAT_020b8e64 == 0x4d) || (DAT_020b8e65 == 0x4d)) {
        P4 = f_100;
      }
      if (DAT_020b8e65 == 0x41) {
        P5 = f_66;
      }
      P1 = f_3;
      P3 = f_2;
      local_140 = 0;
    }
    break;
  case 3:
LAB_0058234b:
    P1 = f_4;
    if (*param_1 == 0x50) {
      if (P9 == f_0) {
        P9 = f_2;
      }
      if (DAT_020b8e64 == 0x20) {
        local_138 = 0;
      }
      else {
        P9 = P2;
        ffree(in_ST0);
        in_ST0 = (float10)FUN_00582d05();
      }
      P7 = f_1;
      if (P8 == f_0) {
        P8 = f_1;
      }
    }
    else {
      local_13c = 0;
    }
    goto LAB_005823e3;
  case 4:
    if (P8 == f_0) {
      P8 = f_m1;
    }
    DAT_009a9078 = 5;
    *param_1 = 5;
    bVar9 = DAT_020b8e64 < 0x44;
    bVar8 = DAT_020b8e64 == 0x44;
    if (bVar8) {
      *param_1 = 6;
    }
    iVar3 = 1;
    pbVar5 = (byte *)((int)&DAT_020b8e5c + *param_1 + 3);
    pbVar7 = &DAT_0076ab9c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar9 = *pbVar5 < *pbVar7;
      bVar8 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar8);
    if (bVar9) {
LAB_00580d38:
      uStack_12c = 0;
      goto LAB_00580d42;
    }
    iVar3 = 1;
    bVar9 = false;
    pbVar5 = (byte *)((int)&DAT_020b8e5c + *param_1 + 3);
    pbVar7 = &DAT_0076ab98;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar9 = *pbVar5 < *pbVar7;
      bVar8 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar8);
    if (!bVar9 && !bVar8) goto LAB_00580d38;
    P1 = P2;
    P3 = DAT_009a9080;
    ffree(in_ST0);
    in_ST0 = (float10)FUN_00582d05();
    fVar2 = P1;
    P8 = P1;
    P1 = f_2;
    P7 = f_0;
    if (fVar2 == f_3) {
      uStack_128 = 0;
    }
    else {
      P9 = fVar2;
      P8 = f_3;
      uStack_124 = 0;
    }
    goto LAB_00580d4e;
  case 5:
    if (DAT_020b8ea3 == 'T') {
LAB_0058248b:
      *param_1 = -1;
      goto LAB_00582b8b;
    }
    P1 = f_11;
    DAT_009a9078 = 0;
    if (DAT_020b8e64 != 0x20) {
      DAT_009a9078 = DAT_020b8e64 - 0x30;
    }
    if ((9 < DAT_009a9078) && (DAT_020b8e65 != 0x20)) {
      DAT_009a9078 = DAT_020b8e65 - 0x30;
    }
    if ((DAT_009a9078 < 1) || (9 < DAT_009a9078)) {
      uStack_114 = 0;
    }
    else {
      local_214 = DAT_009a9078 + 10;
      P1 = (float)local_214;
      P3 = DAT_009a9080;
      ffree(in_ST0);
      in_ST0 = (float10)FUN_00582d05();
    }
    if (P7 == f_0) {
      P7 = P1;
    }
    P1 = f_8;
    if (P4 != f_0) {
      P1 = P4;
    }
    if (DAT_020b8e64 == 0x44) {
      P7 = P7 + f_10;
      if (P4 == f_0) {
        P1 = f_6;
      }
    }
    else {
      uStack_110 = 0;
    }
    P4 = P1;
    P1 = f_6;
    uStack_10c = 0;
    goto LAB_005823e3;
  case 6:
  case 0x19:
    if (P2 == f_0) {
      uStack_80 = 0;
    }
    else {
      iStack_7c = 6;
      DAT_009a9078 = 4;
      do {
        bVar1 = *(byte *)((int)&DAT_020b8e5c + DAT_009a9078 + 3);
        bVar9 = bVar1 < 0x20;
        if (bVar1 == 0x20) {
          uStack_78 = 0;
          goto LAB_00581842;
        }
        iVar3 = 1;
        bVar8 = false;
        pbVar5 = (byte *)((int)&DAT_020b8e5c + DAT_009a9078 + 3);
        pbVar7 = &DAT_0076ab9c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pbVar5 < *pbVar7;
          bVar8 = *pbVar5 == *pbVar7;
          pbVar5 = pbVar5 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar8);
        if (!bVar9) {
          iVar3 = 1;
          pbVar5 = (byte *)((int)&DAT_020b8e5c + DAT_009a9078 + 3);
          pbVar7 = &DAT_0076ab98;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar9 = *pbVar5 < *pbVar7;
            bVar8 = *pbVar5 == *pbVar7;
            pbVar5 = pbVar5 + 1;
            pbVar7 = pbVar7 + 1;
          } while (bVar8);
          if (bVar9 || bVar8) {
            uStack_74 = 0;
            break;
          }
        }
        DAT_009a9078 = DAT_009a9078 + 1;
        iStack_7c = iStack_7c + -1;
      } while (0 < iStack_7c);
      P1 = P2;
      P3 = DAT_009a9080;
      ffree(in_ST0);
      in_ST0 = (float10)FUN_00582d05();
      P4 = P1;
    }
LAB_00581842:
    P1 = f_14;
    if ((P4 == f_0) && (*param_1 == 0x1a)) {
      P4 = f_2;
    }
    if (P4 == f_0) {
      P4 = f_1;
    }
    if (DAT_020b8e60._3_1_ == 0x44) {
      P5 = f_1;
    }
    if (DAT_020b8e60._3_1_ == 0x48) {
      P5 = f_2;
    }
    if (DAT_020b8e60._3_1_ == 0x4c) {
      P5 = f_3;
    }
    if (DAT_020b8e60._3_1_ == 0x52) {
      P5 = f_4;
    }
    if (DAT_020b8e64 == 0x44) {
      P5 = f_5;
    }
    if (DAT_020b8e64 == 0x43) {
      P5 = f_8;
    }
    if ((DAT_020b8e64 == 0x4b) || (DAT_020b8e60._2_1_ == 'A')) {
      P5 = f_9;
    }
    uStack_70 = 0;
    break;
  case 7:
    P1 = f_8;
    if (DAT_020b8e60._3_1_ == 0x43) {
      *param_1 = 0x30;
      uStack_f0 = 0;
LAB_005824fe:
      if (((DAT_020b8e60._3_1_ != 0x53) && (*param_1 == 0x2f)) && (DAT_020b8e60._3_1_ != 0x55)) {
        local_38 = 0;
        goto LAB_00582537;
      }
      if ((*param_1 != 0x36) || (DAT_020b8e60._3_1_ != 0x50)) {
        *param_1 = *param_1 + -1;
        local_214 = *param_1 + 0x19;
        if (0x2b < *param_1) {
          local_214 = *param_1 + -0x17;
        }
        P5 = (float)local_214;
        if (*param_1 == 0x22) {
          P5 = f_111;
        }
        if (*param_1 == 0x37) {
          P5 = f_80;
        }
        if (*param_1 == 0x38) {
          P5 = f_81;
        }
        if (*param_1 == 0x3c) {
          P5 = f_38;
        }
        if (*param_1 == 0x3d) {
          P5 = f_119;
        }
        if (*param_1 == 0x3e) {
          P5 = f_78;
        }
        if (*param_1 == 0x3f) {
          P5 = f_73;
        }
        if (*param_1 == 0x40) {
          P5 = f_79;
        }
        if (*param_1 == 0x41) {
          P5 = f_72;
        }
        if (*param_1 == 0x42) {
          P5 = f_85;
        }
        if (*param_1 == 0x43) {
          P5 = f_113;
        }
        if (*param_1 == 0x44) {
          P5 = f_199;
        }
        if (*param_1 == 0x45) {
          P5 = f_75;
        }
        if (*param_1 == 0x46) {
          iVar3 = 1;
          bVar9 = true;
          bVar8 = false;
          pbVar5 = (byte *)((int)&DAT_020b8e60 + 3);
          pbVar7 = &DAT_0076aadc;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar8 = *pbVar5 < *pbVar7;
            bVar9 = *pbVar5 == *pbVar7;
            pbVar5 = pbVar5 + 1;
            pbVar7 = pbVar7 + 1;
          } while (bVar9);
          if (!bVar8) {
            iVar3 = 1;
            pbVar5 = (byte *)((int)&DAT_020b8e60 + 3);
            pbVar7 = &DAT_0076aad8;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar8 = *pbVar5 < *pbVar7;
              bVar9 = *pbVar5 == *pbVar7;
              pbVar5 = pbVar5 + 1;
              pbVar7 = pbVar7 + 1;
            } while (bVar9);
            if (bVar8 || bVar9) {
              P5 = f_0;
              local_214 = DAT_020b8e60._3_1_ - 0x2d;
              P7 = (float)local_214;
              P6 = P3 + f_40;
              local_28 = 0;
              goto LAB_005829b0;
            }
          }
          local_2c = 0;
          goto LAB_005829d2;
        }
        local_30 = 0;
        goto LAB_005829f2;
      }
      local_34 = 0;
      P7 = f_1;
      P8 = f_111;
      P9 = f_1111;
LAB_005829b0:
      P1 = f_7;
      local_f8 = 0;
      P4 = f_m1;
      break;
    }
    uStack_f4 = 0;
    goto LAB_00582b41;
  case 8:
    P1 = f_9;
    uStack_ec = 0;
    break;
  case 9:
    P1 = f_10;
    P4 = f_13;
    P5 = f_1;
    uStack_e8 = 0;
    break;
  case 10:
  case 0xb:
code_r0x0058229b:
    P1 = f_4;
    if (P4 == f_0) {
      P4 = f_m1;
    }
    P5 = f_999;
    if (*param_1 == 0xc) {
      P7 = f_m1;
    }
    if (DAT_020b8ea2 == '-') {
      P11 = f_1;
      if ((char)DAT_020b8ea0 == 'D') {
        P7 = f_m1;
      }
      local_68 = 0;
    }
    else {
      local_6c = 0;
    }
    goto LAB_005823e3;
  case 0xc:
    if (DAT_020b8e64 == 0x20) {
      uStack_bc = 0;
    }
    else {
      P1 = P2;
      P3 = DAT_009a9080;
      ffree(in_ST0);
      in_ST0 = (float10)FUN_00582d05();
      if (DAT_020b8e65 == 0x46) {
        in_ST0 = (float10)P1;
        P1 = (float)-in_ST0;
      }
      P5 = P1;
      if (DAT_020b8e66 == 'B') {
        P6 = f_1;
      }
      if (DAT_020b8e66 == 'A') {
        P6 = f_2;
      }
      if (DAT_020b8e66 == 'T') {
        P6 = f_3;
      }
    }
    if (P5 == f_0) {
      P5 = f_2;
    }
    P1 = _UNK_0076ab48;
    uStack_b8 = 0;
    break;
  case 0xd:
    if (DAT_020b8e60._3_1_ == 0x52) goto LAB_0058248b;
    uStack_b4 = 0;
    if ((DAT_020b8e64 == 0x20) || (DAT_020b8e65 == 0x20)) {
      uStack_ac = 0;
    }
    else {
      P1 = P2;
      P50 = f_4;
      P3 = DAT_009a9080;
      ffree(in_ST0);
      Var11 = FUN_00582d05();
      if ((DAT_020b8e66 == ':') || (DAT_020b8e66 == '\'')) {
        uStack_a8 = 0;
        DAT_009a907c = 8;
        uStack_90 = 0;
code_r0x00581623:
        uStack_224 = 2;
        puStack_220 = &DAT_020b909f + DAT_009a907c;
        auStack_210[0] = 0;
        uStack_21c = 0x9a9074;
        ffree(Var11);
        in_ST0 = (float10)FUN_005f9240(auStack_210,0x784ff00,&UNK_0076ab40,&uStack_224,0x7a04b0);
        P50 = (float)iRam009a9074;
      }
      else {
        if ((DAT_020b8e67 == ':') || (DAT_020b8e67 == '\'')) {
          uStack_a4 = 0;
          DAT_009a907c = 9;
          goto code_r0x00581623;
        }
        ffree(Var11);
        fVar10 = (float10)amod(&P1,&f_10);
        P50 = (float)fVar10;
        in_ST0 = extraout_ST1;
        if (P50 == f_6) {
          P50 = f_16;
          if (f_100 <= P1) {
            uStack_218 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
            local_214 = (int)ROUND(P1) / 100;
            P1 = (float)local_214;
          }
          uStack_9c = 0;
        }
        else {
          uStack_a0 = 0;
          if (((P50 != f_8) && (P50 != f_2)) && (P50 != f_4)) {
            uStack_98 = 0;
            goto code_r0x005816d2;
          }
          uStack_218 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
          local_214 = (int)ROUND(P1) / 10;
          P1 = (float)local_214;
          uStack_94 = 0;
        }
      }
      P5 = P1;
      P6 = P50;
      P50 = f_0;
    }
code_r0x005816d2:
    if (P5 == f_0) {
      P5 = f_4;
    }
    if (P6 == f_0) {
      P6 = f_4;
    }
code_r0x005824c5:
    P1 = f_18;
    local_88 = 0;
    break;
  case 0xe:
  case 0xf:
    P1 = f_5;
    iVar3 = 5;
    pcVar4 = (char *)&DAT_020b8ea0;
    pcVar6 = "ENDIF";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar9 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar9);
    if (bVar9) {
      ffree(in_ST0);
      in_ST0 = (float10)FUN_0058353a();
      *param_1 = -99;
      goto LAB_00582b8b;
    }
    uStack_d8 = 0;
    if ((DAT_020b8e60._3_1_ == 0x20) || (DAT_020b8e60._3_1_ == 0x49)) {
      P8 = f_1;
      uStack_cc = 0;
    }
    else {
      uStack_d0 = 0;
      P3 = DAT_009a9080;
      ffree(in_ST0);
      in_ST0 = (float10)FUN_00582d05();
      local_214 = DAT_020b8e60._3_1_ - 0x30;
      P8 = (float)local_214;
      if (P8 == f_3) {
        P8 = f_4;
        P9 = f_3;
      }
      else {
        uStack_c8 = 0;
      }
    }
    if (P4 == f_0) {
      P4 = f_15;
    }
    if (P7 == f_0) {
      P7 = f_5;
    }
    uStack_c4 = 0;
    goto LAB_005823e3;
  default:
code_r0x0058217a:
    if (*param_1 == 0x52) {
      local_58 = 0;
LAB_005829d2:
      P5 = f_70;
      if (*param_1 == 0x52) {
        P5 = f_71;
      }
LAB_005829f2:
      if (*param_1 == 0x47) {
        P5 = f_86;
      }
      if ((((*param_1 == 0x38) || (*param_1 == 0x37)) || (*param_1 < 0x2c)) || (0x3b < *param_1)) {
        if (*param_1 == 0x3c) {
          local_20 = 0;
          goto LAB_00582a5f;
        }
        if (P4 == f_0) {
          P4 = f_m2;
          if (((*param_1 != 0x3d) && (*param_1 != 0x45)) &&
             ((*param_1 != 0x29 && (*param_1 != 0x2a)))) {
            local_14 = 0;
            goto LAB_00582ad1;
          }
          local_18 = 0;
          goto LAB_00582ac5;
        }
        local_1c = 0;
      }
      else {
        local_24 = 0;
        if (DAT_020b8e60._3_1_ == 0x53) {
          P5 = P5 + f_4;
        }
LAB_00582a5f:
        P6 = f_0_25;
LAB_00582ac5:
        P4 = f_13;
      }
LAB_00582ad1:
      P1 = f_9;
      break;
    }
    *param_1 = *param_1 + 1;
    if (0x4d < *param_1) {
      if (*param_1 == 0x50) {
        local_50 = 0;
        goto LAB_0058234b;
      }
      if ((*param_1 == 0x4f) && (DAT_020b8e60._3_1_ != 0x4d)) goto LAB_0058248b;
      local_214 = *param_1 + 0x14;
      P5 = (float)local_214;
      local_48 = 0;
      goto code_r0x005824c5;
    }
    local_54 = 0;
LAB_005821b0:
    if ((*param_1 == 0x5f) || (*param_1 == 0x60)) {
      local_44 = 0;
      goto code_r0x0058229b;
    }
    if (*param_1 == 0x61) {
      local_40 = 0;
      goto LAB_0058234b;
    }
    P7 = f_8;
    P12 = f_m1;
    if ((*param_1 == 0x13) || (*param_1 == 0x5c)) {
      in_ST0 = (float10)f_8;
      P7 = (float)-in_ST0;
      P12 = f_1;
      if (P4 == f_0) {
        P4 = f_m2;
      }
    }
    if (P4 == f_0) {
      P4 = f_14;
    }
    if ((*param_1 == 0x14) || (*param_1 == 0x5d)) {
      P7 = f_15;
    }
    P1 = f_7;
    local_3c = 0;
    goto LAB_00582402;
  case 0x13:
    P1 = f_7;
    if (DAT_020b8e65 == 0x46) {
      P8 = f_1;
    }
    if (DAT_020b8e65 == 0x53) {
      P8 = f_2;
    }
    if (DAT_020b8e65 == 0x4e) {
      P8 = f_3;
    }
    goto LAB_005810cb;
  case 0x14:
    P7 = f_m1;
    P6 = f_0;
    if (P5 == f_0) {
      P5 = P4 + f_12;
    }
    P1 = f_4;
    uStack_84 = 0;
    break;
  case 0x15:
    goto LAB_00581096;
  case 0x16:
    P5 = f_1;
    goto LAB_00581096;
  case 0x17:
    P1 = f_12;
    P5 = f_m4;
    if (P7 == f_0) {
      P7 = f_10;
    }
    if (P4 == f_0) {
      P4 = f_16;
    }
    uStack_dc = 0;
    break;
  case 0x18:
    if (P8 == f_0) {
      P8 = f_m2;
    }
    DAT_009a9078 = 4;
    uStack_130 = 0;
LAB_00580d42:
    P1 = f_3;
LAB_00580d4e:
    P10 = f_14;
    if (*(char *)((int)&DAT_020b8e5c + DAT_009a9078 + 3) == 'D') {
      in_ST0 = (float10)P1;
      P1 = (float)-in_ST0;
      P10 = f_0;
    }
    else {
      uStack_120 = 0;
    }
    if (P7 == f_0) {
      P7 = P1;
    }
    if (P4 == f_0) {
      P4 = P10;
    }
    P10 = f_0;
    P1 = f_5;
    uStack_11c = 0;
LAB_005823e3:
    if (P5 == f_0) {
      P5 = P4;
    }
LAB_00582402:
    if (P3 == f_0) {
      P3 = f_100;
    }
    if (P6 == f_0) {
      P6 = P3 + f_20;
    }
    if (*param_1 == 0x61) {
      P7 = f_m4;
    }
    local_134 = 0;
  }
LAB_00582b19:
  if ((DAT_02052740 == 0) && (P3 == f_0)) {
    P3 = f_100;
  }
LAB_00582b41:
  if ((P2 == f_0) || (DAT_0078d894 < P2)) {
    ffree(in_ST0);
    in_ST0 = (float10)FUN_00582b96(param_1);
    P2 = (float)*param_1;
  }
LAB_00582b8b:
  ffree(in_ST0);
  return;
LAB_00581096:
  P1 = f_12;
  if (P6 == f_0) {
    P6 = f_10;
  }
  uStack_e0 = 0;
LAB_005810cb:
  if (P4 == f_0) {
    P4 = f_15;
  }
  if (*param_1 == 0x16) {
    uStack_fc = 0;
    goto LAB_00582b19;
  }
  uStack_100 = 0;
  goto LAB_00582402;
}


