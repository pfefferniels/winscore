// FUN_0046d088 @ 0046d088 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046d088(void)

{
  int iVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar7;
  unkbyte10 Var8;
  float10 extraout_ST1;
  undefined1 *puVar9;
  undefined4 local_2fc;
  undefined4 *local_2f8;
  undefined4 local_2f4;
  char *local_2f0;
  undefined4 *local_2ec;
  undefined4 *local_2e8;
  uint local_2e4;
  undefined4 local_2e0 [8];
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined4 local_2b8;
  undefined4 local_2b4;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  int local_240;
  undefined4 local_23c;
  undefined4 local_234;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
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
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_e8;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_bc;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_74;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_30;
  undefined4 local_28;
  
  puVar9 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if (P1 == f_0) {
    DAT_020527c0 = (&ITEM_PTR0)[EDIT_ITEM];
    local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
    DAT_020b8e50 = (uint)ROUND(DAT_020b9440);
    local_2e4 = DAT_020b8e50;
LAB_0046d108:
    DAT_0078b37c = DAT_020527c8;
    bVar5 = DAT_020b8e50 < 3;
    bVar6 = DAT_020b8e50 == 3;
    if ((int)DAT_020b8e50 < 4) {
      iVar1 = 1;
      pbVar3 = (byte *)&DAT_020b8ea0;
      pbVar4 = &DAT_00761f64;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pbVar3 < *pbVar4;
        bVar6 = *pbVar3 == *pbVar4;
        pbVar3 = pbVar3 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar6);
      if (!bVar5) {
        iVar1 = 1;
        pbVar3 = (byte *)&DAT_020b8ea0;
        pbVar4 = &DAT_00761f60;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pbVar3 < *pbVar4;
          bVar6 = *pbVar3 == *pbVar4;
          pbVar3 = pbVar3 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar6);
        if (bVar5 || bVar6) {
          if ((_DAT_020b8ea0 & 0xffff) != 0x4843) {
            local_2b4 = 0;
            goto LAB_0046dd8f;
          }
          if (DAT_020b8e50 == 1) goto LAB_0046dd8f;
          goto LAB_0046f62b;
        }
      }
      local_2b8 = 0;
    }
    else {
      local_2bc = 0;
    }
LAB_0046d190:
    DAT_020527c8 = DAT_0078b37c;
    DAT_01cb1064 = f_0;
    if (P1 != f_0) goto LAB_0046d88e;
    local_2a8 = 0;
    DAT_020527d4 = DAT_0078b4e0;
    DAT_020527d8 = DAT_0078b4e4;
    if (DAT_0078b4e0 == 0x20) {
      P2 = f_0;
      local_220 = 0;
      goto LAB_0046e8ec;
    }
    local_224 = 0;
    if ((DAT_0078b4e0 == 0x43) || (DAT_0078b4e0 == 0x58)) {
      local_21c = 0;
      if ((DAT_0078b4e0 == 0x58) && (DAT_0078b4e4 == 0x58)) {
        DAT_020527d8 = -1;
      }
      if ((DAT_020527d8 == 0x43) || (DAT_020527d8 == 0x58)) {
        local_140 = 0;
LAB_0046e8ec:
        local_10c = 0;
        if (DAT_0205274c == 0) {
          local_108 = 0;
LAB_0046e958:
          DAT_0205274c = 0;
          if (DAT_020527d4 == 0x20) {
            local_f8 = 0;
            goto LAB_0046ea60;
          }
          DAT_0078b4e0 = 0;
          DAT_00824d28 = (uint)ROUND(P2);
          if (((DAT_00824d28 != 0) || (DAT_020527d8 == 0x43)) &&
             (DAT_0078b4e0 = 0x49, EDIT_ITEM == DAT_00824d28)) {
            _DAT_00824d24 = DAT_0078dc30;
          }
          _DAT_01fbb804 = 19000;
          local_f4 = 0;
          local_2e4 = DAT_00824d28;
          goto LAB_0046ea0b;
        }
        DAT_020527d0 = EDIT_ITEM;
        if (DAT_0205274c != 0) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_00476628();
          DAT_0078b4f0 = 1;
          if (DAT_020527d8 != 0x58) {
            local_100 = 0;
            goto LAB_0046e958;
          }
          EDIT_ITEM = DAT_020527d0;
          DAT_0078dc45 = 0;
          local_fc = 0;
          goto LAB_0046ea60;
        }
        goto LAB_0046f62b;
      }
      if (DAT_020527d8 < 0x41) {
        local_13c = 0;
        goto LAB_0046e8ec;
      }
      if (DAT_020527d8 == 0x57) {
        local_138 = 0;
        if (DAT_020b8e50 == 2) {
          P1 = f_9;
          P2 = f_m1;
          local_110 = 0;
        }
        else {
          local_114 = 0;
        }
        goto LAB_0046df6c;
      }
      if (DAT_020527d8 == 0x54) {
        local_134 = 0;
        goto LAB_0046dda8;
      }
      DAT_020527d4 = 0;
      if (DAT_020527d8 == 0x44) {
        local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
        DAT_020527d4 = (uint)ROUND(P2);
        local_2e4 = DAT_020527d4;
        if (DAT_020527d4 != 0) {
          DAT_020b9474 = P2;
        }
      }
      else {
        local_130 = 0;
      }
      goto LAB_0046df17;
    }
    if (DAT_0078b4e0 == 0x49) {
      local_218 = 0;
LAB_0046e6f9:
      if (DAT_0078b4e0 == 0x4e) {
        DAT_0078b374 = 1;
      }
      if (((P2 == f_0) && ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x43)) || (P2 == f_0))
      goto LAB_0046f62b;
      DAT_020527d8 = 0;
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x43) {
        DAT_0078dc3d = P2;
        DAT_0078b4e4 = DAT_020527d8;
        goto LAB_0046f62b;
      }
      local_e8 = 0;
LAB_0046e78d:
      if (((DAT_020b9454 <= f_m4) && (DAT_020b8e50 == 1)) &&
         (DAT_0078b4e4 = DAT_020527d8, DAT_020527d8 == 0x50)) {
LAB_0046ee4c:
        if (DAT_020b945c < f_0) {
          DAT_00824d20 = -1;
          local_d4 = 0;
          goto LAB_0046efee;
        }
        local_d8 = 0;
        DAT_020527d4 = (uint)ROUND(P2);
        local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
        DAT_00824d1c = (uint)ROUND(DAT_020b9454);
        DAT_020527d8 = -((int)DAT_00824d1c % 10);
        P4 = DAT_020b944c;
        P5 = DAT_020b9450;
        DAT_00824d20 = 0;
        IP9 = 0;
        local_2e4 = DAT_00824d1c;
        goto LAB_0046ef2b;
      }
      local_dc = 0;
LAB_0046e7c0:
      DAT_0078b4e4 = DAT_020527d8;
      if (DAT_0205274c == 0) {
        if (((DAT_020527d8 != 0x48) && (DAT_020527d8 != 0x43)) &&
           ((local_bc = 0, DAT_020527d8 == 0x54 || ((DAT_020527d8 < 0x21 || (DAT_020527d8 == 0x44)))
            ))) {
          if (DAT_020527d8 == 0x20) {
            P2 = DAT_020b9448;
            P3 = DAT_0078d894 + f_1;
            DAT_0078b4e0 = 0x45;
            DAT_0078b4e4 = 0x44;
          }
          else {
            local_b0 = 0;
          }
LAB_0046ea0b:
          if ((DAT_020527d8 != 0x58) && ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x41)) {
            local_a8 = 0;
LAB_0046ea60:
            if (DAT_0205274c != 0) {
              _DAT_0078dee8 = 0;
            }
            if (DAT_020527d8 < 0) {
              DAT_00824d30 = 0x15;
              local_2e0[0] = 0;
              local_2fc = 0x12;
              local_2f8 = (undefined4 *)&DAT_00824d44;
              local_2f4 = 6;
              local_2f0 = "binary";
              local_2ec = (undefined4 *)0x2;
              local_2e8 = (undefined4 *)0x4;
              ffree(in_ST0);
              Var8 = FUN_005f6540(local_2e0,0x15,0x784ff00,&DAT_00761e94,&local_2fc);
              local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
              DAT_020527cc = (uint)ROUND(DAT_020b9444);
              local_2e0[0] = 0;
              local_2ec = (undefined4 *)0x1;
              ffree(Var8);
              local_2e4 = DAT_020527cc;
              Var8 = FUN_005fa4d0(local_2e0,DAT_00824d30,0x784ff00,&DAT_00761e90,&local_2ec);
              local_2ec = &DAT_020527cc;
              ffree(Var8);
              Var8 = FUN_005fa9f0(local_2e0,&DAT_00761e8c,&local_2ec);
              local_2ec = (undefined4 *)0x4;
              local_2e8 = &DAT_020b9448;
              ffree(Var8);
              Var8 = FUN_005fa9f0(local_2e0,&DAT_00761e88,&local_2ec);
              local_2ec = (undefined4 *)(DAT_020b9448 + f_10);
              ffree(Var8);
              Var8 = FUN_005fa9f0(local_2e0,&DAT_00761e84,&local_2ec);
              local_2ec = &DAT_020527cc;
              ffree(Var8);
              Var8 = FUN_005fa9f0(local_2e0,&DAT_00761e80,&local_2ec);
              DAT_020527cc = (&ITEM_PTR0)[EDIT_ITEM];
              local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
              DAT_020527c8 = (int)ROUND((float)(&ITEM_LEN)[DAT_020527cc]);
              local_2e0[0] = 0;
              local_2ec = &DAT_020527c8;
              ffree(Var8);
              local_2e4 = DAT_020527c8;
              Var8 = FUN_005fa4d0(local_2e0,DAT_00824d30,0x784ff00,&DAT_00761e8c,&local_2ec);
              local_2f8 = &ITEM_LEN + DAT_020527cc;
              local_2f0 = (char *)(DAT_020527c8 + 1);
              if ((int)local_2f0 < 0) {
                local_2f0 = (char *)0x0;
              }
              DAT_00824d40 = DAT_020527cc + (int)local_2f0;
              local_2fc = 1;
              local_2f4 = 1;
              local_2ec = (undefined4 *)0x4;
              ffree(Var8);
              Var8 = FUN_005fa9f0(local_2e0,&DAT_00761e7c,&local_2fc);
              local_2e0[0] = 0;
              ffree(Var8);
              in_ST0 = (float10)FUN_005f7950(local_2e0,DAT_00824d30,0x784ff00,&DAT_00761e78,0);
              P2 = f_0;
              DAT_0078b4e4 = 0x20;
              DAT_020527d8 = 0x20;
            }
          }
        }
      }
      else {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0054d831("Cannot perform function until done editing current item."
                                             ,0x38);
      }
      goto LAB_0046f62b;
    }
    if (DAT_0078b4e0 == 0x4e) {
      if (DAT_0078b4e4 != 0x41) {
        local_20c = 0;
        goto LAB_0046e6f9;
      }
      local_210 = 0;
LAB_0046d571:
      if ((DAT_0078b4e0 != 0x46) || ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x49)) {
        local_178 = 0;
        if ((DAT_0078b4e0 != 0x4a) || (DAT_020b8e50 != 0x10)) goto LAB_0046f62b;
        if (DAT_0078b4e4 == 0x52) {
          local_14c = 0;
          DAT_01cb1060 = f_m9999;
          DAT_01cb1064 = P2;
        }
        else {
          DAT_01cb1060 = P2;
          DAT_01cb1064 = P3;
          local_148 = 0;
        }
        goto LAB_0046d726;
      }
      DAT_020527d8 = 10;
      if (DAT_020b8e50 != 1) {
        if (DAT_020b8e50 != 5) {
          if (DAT_020b8e50 == 6) {
            local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
            local_2e4 = (uint)ROUND(DAT_020b9458);
            DAT_020527d4 = (int)local_2e4 % 100;
            if ((int)DAT_020527d4 < 0) {
              DAT_020527d4 = -DAT_020527d4;
            }
            if (9 < (int)DAT_020527d4) {
              if (0x13 < (int)DAT_020527d4) {
                DAT_020527d8 = -10;
              }
              if (DAT_020b9458 < f_0) {
                DAT_020527d8 = -DAT_020527d8;
              }
              P1 = f_700;
              local_164 = 0;
              goto LAB_0046e5f6;
            }
            local_168 = 0;
            goto LAB_0046d691;
          }
          if ((DAT_020b8e50 != 9) && (DAT_020b8e50 != 0xb)) goto LAB_0046f62b;
          if (DAT_020b9458 == f_0) {
            ffree(in_ST0);
            fVar7 = (float10)amod(&DAT_020b9454,&f_100);
            P2 = (float)fVar7;
            if (P2 == f_0) {
              P2 = f_1;
            }
            in_ST0 = (float10)P2;
            P2 = (float)-in_ST0;
            P1 = f_7;
            local_15c = 0;
            puVar2 = &stack0xfffffffc;
            goto LAB_0046f4ff;
          }
          local_160 = 0;
        }
        P1 = ram0x00761ee8;
        local_16c = 0;
        puVar2 = &stack0xfffffffc;
        goto LAB_0046f4ff;
      }
      local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
      local_2e4 = (uint)ROUND(DAT_020b9450);
      DAT_020527d4 = (int)local_2e4 % 100;
      if (9 < (int)DAT_020527d4) {
        if (0x13 < (int)DAT_020527d4) {
          DAT_020527d8 = -10;
        }
        P1 = f_500;
LAB_0046e5f6:
        P2 = (float)DAT_020527d8;
        local_170 = 0;
        puVar2 = &stack0xfffffffc;
        goto LAB_0046f4ff;
      }
      local_174 = 0;
    }
    else {
      local_214 = 0;
      if (DAT_0078b4e0 == 0x45) {
        local_208 = 0;
        goto LAB_0046e78d;
      }
      if (DAT_0078b4e0 == 0x53) {
        if (DAT_0078b4e4 == 0x5a) {
          local_200 = 0;
          goto LAB_0046d939;
        }
        if ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x50) {
          local_1fc = 0;
          goto LAB_0046e78d;
        }
        if (DAT_0078b4e4 == 0x48) {
          local_1f8 = 0;
          goto LAB_0046d571;
        }
      }
      else {
        local_204 = 0;
      }
      if ((DAT_0078b4e0 == 0x4c) || (DAT_0078b4e0 == 0x52)) {
        local_1f4 = 0;
        if (DAT_0078b4e4 == 0x45) {
          ffree(in_ST0);
          Var8 = thunk_FUN_00522bd8();
          ffree(Var8);
          in_ST0 = (float10)thunk_FUN_00518448();
          local_a0 = 0;
          goto LAB_0046f4ff;
        }
        local_a4 = 0;
        if (DAT_020b8e50 == 0x10) {
          if (((DAT_0078b4e4 == 0x4d) || (DAT_0078b4e4 == 0x53)) ||
             ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x50)) {
            ffree(in_ST0);
            in_ST0 = (float10)thunk_FUN_00470618();
            if (DAT_0078b4e0 != 0xffffffff) {
              DAT_020527ec = EDIT_ITEM;
              EDIT_ITEM = 0;
              ffree(in_ST0);
              in_ST0 = (float10)draw_items();
              EDIT_ITEM = DAT_020527ec;
              DAT_020527ec = 0;
            }
            goto LAB_0046f62b;
          }
          local_98 = 0;
        }
        else {
          local_9c = 0;
        }
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_004681c0(&DAT_00761f4c);
        local_8c = 0;
        goto LAB_0046df6c;
      }
      if ((DAT_0078b4e0 == 0x44) || (DAT_0078b4e0 == 0x55)) {
        local_1f0 = 0;
        if (DAT_0078b4e4 == 0x45) {
          if (DAT_0205274c != 0) {
            local_84 = 0;
            goto LAB_0046e78d;
          }
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0045deb2(&EDIT_ITEM);
          if (0 < DAT_0078b370) {
            EDIT_ITEM = EDIT_ITEM + -1;
          }
          DAT_0078dc45 = 0;
          DAT_0078b4e0 = 0x20;
          DAT_0078b4f0 = 1;
          local_80 = 0;
          goto LAB_0046ea60;
        }
        local_88 = 0;
        if (DAT_0078b4e4 == 0x52) goto LAB_0046f62b;
        local_7c = 0;
        if (DAT_0078b4e4 == 0x4e) {
          local_74 = 0;
          if (DAT_0205274c != 0) {
            local_68 = 0;
            goto LAB_0046e7c0;
          }
          if (DAT_01c26054 != 0) goto LAB_0046e474;
        }
        else {
          if ((_DAT_020b8ea0 & 0xffffff) != 0x524944) {
            local_6c = 0;
            goto LAB_0046df6c;
          }
LAB_0046e474:
          DAT_0078b378 = 1;
        }
        goto LAB_0046f62b;
      }
      if (DAT_0078b4e0 == 0x50) {
        local_1ec = 0;
        if (DAT_0078b4e4 == 0x54) {
          do {
            if ((DAT_020b8e50 != 0x10) && (DAT_020b8e50 != 10)) break;
            if (P2 == f_0) {
              ffree(in_ST0);
              fVar7 = (float10)amod(&DAT_020b9454,&f_100);
              P2 = (float)fVar7;
              if (P2 == f_0) {
                P2 = f_1;
              }
              P2 = (STEP * P2) / f_1_84375;
              P3 = STEP / f_25;
              FUN_005f33c9(&stack0xfffffffc,0x46f0af);
              Var8 = FUN_005f34d1(puVar9,0x46f0ca);
              ffree(Var8);
              Var8 = thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_00761e38,&DAT_00761e3c,"(1f7.2)",7,
                                        &P2);
              ffree(Var8);
              Var8 = thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_00761e28,&DAT_00761e2c,"(1f5.2)",7,
                                        &P3);
              ffree(Var8);
              Var8 = thunk_FUN_0054da52(&DAT_020b8ea0,0x200);
              ffree(Var8);
              in_ST0 = (float10)thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
              *(undefined4 *)(puVar9 + -0x28) = 0;
              break;
            }
            local_30 = 0;
            local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
            DAT_020527cc = (int)ROUND(DAT_020b9454) / 100;
            in_ST0 = ((float10)P2 * (float10)f_1_84375) / (float10)STEP;
            local_2e4 = DAT_020527cc * 100;
            P2 = (float)((float10)(int)local_2e4 + in_ST0);
            P1 = f_6;
            P3 = f_0;
            if (DAT_020b8e50 != 10) {
              P3 = f_7;
            }
            P4 = f_0;
            local_28 = 0;
LAB_0046d90e:
            while (local_298 = 0, P1 == f_30) {
              local_294 = 0;
LAB_0046d939:
              local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
              DAT_020527cc = (uint)ROUND(DAT_020b9440);
              if (((DAT_020527cc == 0x11) || (DAT_020527cc == 8)) ||
                 ((int)DAT_020527cc < 7 && 3 < (int)DAT_020527cc)) goto LAB_0046f62b;
              DAT_020527d4 = 6;
              if ((int)DAT_020527cc < 3) {
                DAT_020527d4 = 0xf;
              }
              if (DAT_020527cc == 0x12) {
                DAT_020527d4 = 7;
              }
              P50 = STEP / f_25;
              if (P50 == f_0) {
                P50 = f_1;
              }
              if (DAT_020527cc == 7) {
                DAT_020527d4 = 5;
                if (DAT_020b9458 == f_20) {
                  DAT_020527d4 = 9;
                }
LAB_0046dad1:
                if (P2 == f_0) {
                  ffree(in_ST0);
                  local_2e4 = DAT_020527cc;
                  fVar7 = (float10)amod(&DAT_020b943c + DAT_020527d4 * 4,&f_100);
                  P4 = (float)(fVar7 * (float10)P50);
                  in_ST0 = extraout_ST1;
                  if (P4 == f_0) {
                    P4 = P50;
                  }
                  goto LAB_0046f62b;
                }
                local_48 = 0;
                local_2e8 = (undefined4 *)
                            (CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
                DAT_020527d8 = (int)ROUND(*(float *)(&DAT_020b943c + DAT_020527d4 * 4)) / 100;
                in_ST0 = (float10)P2 / (float10)P50;
                local_2e4 = DAT_020527d8 * 100;
                P2 = (float)((float10)(int)local_2e4 + in_ST0);
              }
              else {
                if (DAT_020527cc != 0xe) goto LAB_0046dad1;
                if (DAT_020b9450 <= f_0) goto LAB_0046f62b;
                P4 = P50;
                if (DAT_020b9480 != f_0) {
                  P4 = DAT_020b9480;
                }
                if (P2 == f_0) goto LAB_0046f62b;
                DAT_020527d4 = 0x11;
                local_4c = 0;
                local_2e4 = 0xe;
              }
              P1 = (float)DAT_020527d4;
              DAT_020527d4 = 3;
              if ((DAT_020527cc != 0xc) || (DAT_020b9450 < f_0)) {
                local_40 = 0;
              }
              P3 = f_0;
              local_3c = 0;
            }
            if (P1 == f_24) {
              local_290 = 0;
              goto LAB_0046dd8f;
            }
            if (((DAT_020b9454 <= f_m4) && (DAT_020b8e50 == 1)) && (P1 == f_31)) {
              local_28c = 0;
              goto LAB_0046ee4c;
            }
            local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
            DAT_020527cc = (uint)ROUND(P1 - f_31);
            local_2e4 = DAT_020527cc;
            if (1 < (int)DAT_020527cc) goto LAB_0046dd78;
            if (DAT_020527cc != 1) goto LAB_0046df78;
          } while( true );
        }
        goto LAB_0046f62b;
      }
      if (DAT_0078b4e0 == 0x41) {
        if (DAT_0078b4e4 == 0x42) {
          local_1e4 = 0;
          if (DAT_0205274c == 0) {
            if (DAT_0078dd68 != 0) {
              ffree(in_ST0);
              Var8 = thunk_FUN_0054c419(&P1,&DAT_00761ef4);
              local_2ec = (undefined4 *)(DAT_0078dd68 / 2);
              if ((int)local_2ec < 0) {
                local_2ec = (undefined4 *)-(int)local_2ec;
              }
              ffree(Var8);
              Var8 = thunk_FUN_0054c590(&DAT_020492a0,&P1,&local_2ec);
              DAT_020527c0 = 0;
              if (P1 == f_16) {
                DAT_020527c0 = (&DAT_02091d20)[ITEM_I];
                DAT_00824d34 = 0xe;
                if (P14 == f_m1) {
                  DAT_00824d34 = 0x11;
                }
                local_2ec = (undefined4 *)(DAT_020492f0 / 2);
                ffree(Var8);
                Var8 = thunk_FUN_0054c590(&DAT_020492f4,&ITEM_LEN + DAT_00824d34 + DAT_020527c0,
                                          &local_2ec);
                local_2ec = (undefined4 *)(DAT_020492f0 / 2);
                ffree(Var8);
                Var8 = thunk_FUN_0054c590(&DAT_020492f4,&DAT_01fb8cf8,&local_2ec);
              }
              else {
                local_1cc = 0;
              }
              ffree(Var8);
              in_ST0 = (float10)thunk_FUN_00449b86();
              if (DAT_020527c0 != 0) {
                DAT_020492f0 = (DAT_020492f0 + 1) / 2;
                (&ITEM_LEN)[DAT_020527c0] = (float)(DAT_020492f0 + 0xd);
                ITEM_WORDS = DAT_020492f0 + ITEM_WORDS;
                (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
              }
              DAT_0078dd68 = 0;
            }
            goto LAB_0046f62b;
          }
LAB_0046e39e:
          local_1c4 = 0;
          local_1c0 = 0;
          if (DAT_01fbb7ec != -9999) goto LAB_0046f62b;
          local_1bc = 0;
          DAT_01fbb7ec = EDIT_ITEM;
          DAT_0205274c = 0;
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0058c344();
          DAT_01fbb7ec = 0;
          P1 = f_1;
          P2 = DAT_020b9440;
          P3 = f_0;
          local_184 = 0;
          puVar2 = &stack0xfffffffc;
          goto LAB_0046f4ff;
        }
        if (DAT_0078b4e4 != 0x55) {
          if (DAT_0078b4e4 == 0x44) {
            local_1dc = 0;
            goto LAB_0046df78;
          }
          P1 = f_3;
          P2 = DAT_020527e4;
          if (DAT_0078b4e4 != 0x20) goto LAB_0046f62b;
          local_1d4 = 0;
          goto LAB_0046df6c;
        }
        local_1e0 = 0;
        P1 = f_10;
        P2 = f_99;
        if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x58) {
          P2 = f_98;
        }
        local_1d0 = 0;
        goto LAB_0046df78;
      }
      local_1e8 = 0;
      if (DAT_0078b4e0 == 0x54) {
        if (DAT_0078b4e4 == 0x58) {
          local_1b0 = 0;
          if (DAT_020b8e50 != 0x10) {
            local_1a4 = 0;
          }
        }
        else {
          if (DAT_0078b4e4 == 0x50) {
            local_1ac = 0;
            goto LAB_0046e78d;
          }
          DAT_0078b374 = 0;
          local_1a8 = 0;
        }
        goto LAB_0046d691;
      }
      local_1b4 = 0;
      if (DAT_0078b4e0 != 0x3f) {
        local_198 = 0;
        if (DAT_0078b4e0 != 0x5a) {
          local_190 = 0;
          goto LAB_0046d571;
        }
        if (DAT_0205274c != 0) {
          DAT_01fbb7ec = -9999;
          local_188 = 0;
          goto LAB_0046e39e;
        }
        local_18c = 0;
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0058c344();
        goto LAB_0046f62b;
      }
      local_194 = 0;
    }
LAB_0046d691:
    local_1a0 = 0;
    DAT_01cb1064 = f_m1;
    local_19c = 0;
LAB_0046d726:
    P1 = f_1;
    P2 = f_16;
    P3 = f_0;
    local_144 = 0;
    goto LAB_0046df6c;
  }
  local_2c0 = 0;
LAB_0046f1df:
  if (((_DAT_020b8ea0 >> 8 & 0xff) == 0x70) || ((_DAT_020b8ea0 >> 8 & 0xff) == 0x50)) {
    _DAT_00824d38 = 0;
    local_240 = 7;
    DAT_020527cc = 4;
    do {
      DAT_00824d3c = (&DAT_020b909f)[DAT_020527cc];
      if ((((DAT_00824d3c == '/') || (DAT_00824d3c == '*')) || (DAT_00824d3c == '+')) ||
         (DAT_00824d3c == '-')) {
        local_23c = 0;
        if (DAT_00824d3c == '+') {
          local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
          local_2e4 = (uint)ROUND(P3);
          P2 = P4 + *(float *)(&DAT_020b943c + local_2e4 * 4);
        }
        else if (DAT_00824d3c == '-') {
          local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
          local_2e4 = (uint)ROUND(P3);
          P2 = *(float *)(&DAT_020b943c + local_2e4 * 4) - P4;
        }
        else if (DAT_00824d3c == '*') {
          local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
          local_2e4 = (uint)ROUND(P3);
          P2 = P4 * *(float *)(&DAT_020b943c + local_2e4 * 4);
        }
        else if (DAT_00824d3c == '/') {
          local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
          local_2e4 = (uint)ROUND(P3);
          P2 = *(float *)(&DAT_020b943c + local_2e4 * 4) / P4;
        }
        P3 = f_0;
        P4 = f_0;
        goto LAB_0046f450;
      }
      DAT_020527cc = DAT_020527cc + 1;
      local_240 = local_240 + -1;
    } while (0 < local_240);
    goto LAB_0046f62b;
  }
LAB_0046f450:
  if (DAT_020b8e50 == 6) {
    puVar2 = &stack0xfffffffc;
    if ((P1 == f_9) && (puVar2 = &stack0xfffffffc, P2 == f_m1)) {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00419498();
      puVar2 = &stack0xfffffffc;
    }
  }
  else {
    local_234 = 0;
    puVar2 = &stack0xfffffffc;
  }
LAB_0046f4ff:
  while( true ) {
    ffree(in_ST0);
    Var8 = thunk_FUN_00449ea8(&DAT_020527c8);
    if ((DAT_020b8e50 != 6) || ((_DAT_020b8ea0 & 0xffffff) != 0x584e2a)) break;
    P1 = f_9;
    P2 = f_m1;
    P3 = f_0;
    ffree(Var8);
    thunk_FUN_00419498();
    in_ST0 = (float10)FUN_005f34d1(puVar2,0x46f57b);
    *(undefined4 *)(puVar2 + -0x228) = 0;
  }
  *(undefined4 *)(puVar2 + -0x22c) = 0;
  DAT_0205274c = 1;
  *(undefined2 *)(puVar2 + -0x2e4) = in_FPUControlWord;
  *(ushort *)(puVar2 + -0x2e2) = (ushort)*(undefined4 *)(puVar2 + -0x2e4) | 0xc00;
  *(int *)(puVar2 + -0x2e0) = (int)ROUND(DAT_020b9440);
  DAT_020b8e50 = *(uint *)(puVar2 + -0x2e0);
  ffree(Var8);
  in_ST0 = (float10)thunk_FUN_0054de6b();
  *(undefined4 *)(puVar2 + -0x224) = 0;
LAB_0046f62b:
  ffree(in_ST0);
  return;
LAB_0046d88e:
  if (((DAT_020b8e50 == 0xe) || (DAT_020b8e50 == 0x12)) || (DAT_020b8e50 == 10)) {
    if ((P1 != f_9) || (f_0 <= P2)) {
      local_2a0 = 0;
      goto LAB_0046d90e;
    }
    DAT_0078b4e4 = 0x4d;
    P1 = f_0;
    local_29c = 0;
LAB_0046df17:
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0042c9b0(&DAT_00824d30,&DAT_020527c8);
    if ((DAT_020527d4 == 0) || (DAT_020527d8 != 0x44)) {
      local_12c = 0;
    }
    else {
      P15 = f_14;
      P16 = (float)(int)DAT_020527d4;
      local_128 = 0;
    }
  }
  else {
    local_2a4 = 0;
  }
LAB_0046df6c:
  local_27c = 0;
LAB_0046dfa6:
  if ((P1 != f_10) || (P2 != f_98 && P2 != f_99)) {
    if ((_DAT_020b8ea0 & 0xffff) == 0x5543) {
      P1 = f_400;
      P2 = f_100;
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x58) {
        in_ST0 = (float10)DAT_020b944c;
        if (ABS(in_ST0) < (float10)f_100) {
          local_268 = 0;
          goto LAB_0046d108;
        }
        if (DAT_020b944c <= f_0) {
          local_260 = 0;
        }
        else {
          local_264 = 0;
        }
      }
      else {
        local_26c = 0;
        in_ST0 = (float10)DAT_020b944c;
        if ((float10)f_100 <= ABS(in_ST0)) {
          local_25c = 0;
          goto LAB_0046d108;
        }
        if (f_0 <= DAT_020b944c) {
          local_258 = 0;
          puVar2 = &stack0xfffffffc;
          goto LAB_0046f4ff;
        }
      }
      in_ST0 = (float10)f_100;
      P2 = (float)-in_ST0;
      local_254 = 0;
      puVar2 = &stack0xfffffffc;
      goto LAB_0046f4ff;
    }
    local_270 = 0;
    if (f_0 <= P2) {
      local_250 = 0;
      puVar2 = &stack0xfffffffc;
      goto LAB_0046f4ff;
    }
    if (P2 == f_m9999) {
      local_24c = 0;
      puVar2 = &stack0xfffffffc;
      goto LAB_0046f4ff;
    }
    if (P1 != f_8) {
      local_248 = 0;
      goto LAB_0046f1df;
    }
    if (DAT_0078b4e0 != 0xffffff9d) goto LAB_0046f1df;
    local_244 = 0;
    goto LAB_0046d108;
  }
  if (-1 < DAT_0078b374) goto LAB_0046f1a1;
  local_278 = 0;
  goto LAB_0046d108;
LAB_0046dd78:
  if ((int)DAT_020527cc < 6) {
    if (DAT_020527cc == 4) goto LAB_0046df17;
    if (DAT_020527cc == 5) {
LAB_0046dda8:
      if (DAT_020b8e50 != 0x10) goto LAB_0046f62b;
      P6 = DAT_020b9470 / f_2;
      P3 = f_11;
      P4 = f_0;
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4e) {
        DAT_0078b4e4 = 0x4e;
        DAT_01caf6ac = DAT_020b8e50;
        P4 = STEP * f_0_064 - P6;
        local_2e8 = (undefined4 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
        DAT_01caf6a0 = (uint)ROUND(DAT_020b9444);
        _DAT_00824d2c = DAT_020b9448;
        DAT_01caf6b0 = 1;
        DAT_01caf6c0 = 0;
        ffree(in_ST0);
        local_2e4 = DAT_01caf6a0;
        in_ST0 = (float10)thunk_FUN_0042daf8(&f_3,&DAT_00824d2c,&DAT_00824d34);
        local_11c = 0;
      }
      else {
        local_120 = 0;
        if (P2 == f_0) {
          P2 = DAT_00790c94;
        }
        DAT_00790c94 = P2;
        P2 = P2 - P6;
      }
      P1 = f_3;
      local_118 = 0;
      goto LAB_0046df6c;
    }
LAB_0046dd8f:
    ffree(in_ST0);
    DAT_0078b37c = DAT_020527c8;
    in_ST0 = (float10)thunk_FUN_0046ccb8();
    if (_DAT_020b8e66 != 0) goto LAB_0046f62b;
    goto LAB_0046d190;
  }
LAB_0046df78:
  if (DAT_020b8e50 != 6) {
    local_288 = 0;
    puVar2 = &stack0xfffffffc;
    goto LAB_0046f4ff;
  }
  if ((_DAT_020b8ea0 & 0xffff) != 0x4441) {
    local_284 = 0;
    goto LAB_0046dfa6;
  }
  if (DAT_0205274c != 0) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00476628();
    DAT_0205274c = 0;
  }
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_0040cde4(&DAT_00761e20);
  goto LAB_0046f62b;
LAB_0046ef2b:
  IP8 = DAT_00824d20;
  IP10 = 999;
  IP6 = DAT_00824d1c;
  ffree(in_ST0);
  in_ST0 = (float10)note_special_head();
  if (((int)DAT_020527d4 <= IP9) || (DAT_020527d8 == DAT_00824d20)) goto LAB_0046efb3;
  if (f_40 < (float)DAT_00824d20) goto LAB_0046f62b;
  DAT_00824d20 = DAT_00824d20 + 1;
  local_c8 = 0;
  goto LAB_0046ef2b;
LAB_0046efb3:
  local_d0 = 0;
  if (DAT_00824d20 < IP8) {
    DAT_00824d20 = IP8;
  }
LAB_0046efee:
  P1 = f_8;
  P2 = (float)DAT_00824d20;
  P3 = f_0;
  local_c4 = 0;
  puVar2 = &stack0xfffffffc;
  goto LAB_0046f4ff;
LAB_0046f1a1:
  ffree(in_ST0);
  in_ST0 = (float10)thunk_FUN_00417738();
  goto LAB_0046f62b;
}


