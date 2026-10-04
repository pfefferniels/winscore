// FUN_004359d0 @ 004359d0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Heritage AFTER dead removal. Example location: r0x01c58944 : 0x00437801 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_004359d0(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  int *piVar6;
  byte *pbVar7;
  bool bVar8;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar9;
  unkbyte10 Var10;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 extraout_ST1_03;
  float10 extraout_ST1_04;
  float10 extraout_ST1_05;
  float10 extraout_ST1_06;
  float10 extraout_ST1_07;
  float local_27c;
  int local_278;
  undefined4 local_254;
  int local_250;
  undefined4 local_24c;
  int local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_14;
  undefined4 local_10;
  
  if (DAT_020b8e50 != 3) {
    local_250 = 0x1b;
    DAT_020527cc = 1;
LAB_00435d6f:
    if ((uint)*(ushort *)(s_TREBASALTTENPERSOPMEZBARTDOTUOTU_0078f3b0 + DAT_020527cc * 2 + 0x2e) !=
        (_DAT_020b8ea0 & 0xffff)) goto LAB_00435d98;
    switch(DAT_020527cc) {
    case 1:
      DAT_007f75c8 = f_10;
      if (f_10 <= DAT_020b9454) {
        in_ST0 = (float10)f_10;
        DAT_007f75c8 = (float)-in_ST0;
      }
      DAT_01c58934 = DAT_007f75c8 + DAT_020b9454;
      uStack_234 = 0;
      goto LAB_00437f8f;
    case 2:
      DAT_007f75c8 = DAT_020b948c;
      if (DAT_020b948c == f_0) {
        DAT_007f75c8 = f_1;
      }
      if (DAT_020b8ea3 == '-') {
        _DAT_01c5896c = DAT_007f75c8 - f_0_05;
      }
      if (DAT_020b8ea3 == '+') {
        _DAT_01c5896c = DAT_007f75c8 + f_0_05;
      }
      if (DAT_020b8ea3 == '*') {
        _DAT_01c5896c = f_0;
      }
      uStack_230 = 0;
      goto LAB_00437f8f;
    case 3:
      if ((DAT_020b8ea3 == '+') || (DAT_020b8ea3 == 'U')) {
        P2 = f_1;
      }
      if ((DAT_020b8ea3 == '-') || (DAT_020b8ea3 == 'D')) {
        P2 = f_m1;
      }
      ffree(in_ST0);
      in_ST0 = (float10)FUN_00438009();
      _DAT_020b8ea0 = CONCAT12(DAT_0076037a,DAT_00760378);
      if (DAT_01c58920 == f_999) goto LAB_00437ff5;
      uStack_228 = 0;
      goto LAB_00437f8f;
    case 4:
      goto LAB_004369d9;
    case 5:
      if (DAT_020b8ea2 == 'G') {
        uStack_218 = 0;
        DAT_007f75c8 = f_100;
        if (DAT_020b944c < f_0) {
          in_ST0 = (float10)f_100;
          DAT_007f75c8 = (float)-in_ST0;
        }
        ffree(in_ST0);
        fVar9 = (float10)amod(&DAT_020b944c,&f_100);
        DAT_01c5892c = (float)(fVar9 + (float10)DAT_007f75c8);
        if (DAT_020b8e50 == 2) {
          uStack_1f8 = 0;
          DAT_01c58930 = f_1;
        }
        else {
          DAT_01c5893c = f_101;
          DAT_01c58940 = f_1;
          if (DAT_020b9450 < f_10) {
            DAT_01c58930 = DAT_020b9450 + f_10;
            uStack_1f0 = 0;
          }
          else {
            uStack_1f4 = 0;
          }
        }
        DAT_01c58934 = f_0;
        _DAT_01c58938 = f_65;
        uStack_1ec = 0;
        in_ST0 = extraout_ST1;
      }
      else {
        if (DAT_020b8ea2 == 'U') {
          uStack_214 = 0;
          goto LAB_004362d3;
        }
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_00582d56(&DAT_020b8ea0,1,&DAT_020b9440,&DAT_020527cc);
        if (DAT_020527cc < 0) goto LAB_00437ff5;
        ffree(in_ST0);
        Var10 = thunk_FUN_0054c4c6(&P4,&DAT_020b8eac,&DAT_00760368);
        ffree(Var10);
        thunk_FUN_0054c419(&P5,&DAT_00760364);
        _DAT_01c58938 = DAT_020b8eb8;
        DAT_01c58934 = DAT_020b8eb4;
        if (DAT_020b8e50 == 2) {
          uStack_20c = 0;
          DAT_01c58930 = DAT_020b8eb0;
          DAT_01c5893c = f_0;
          DAT_01c58940 = f_0;
          in_ST0 = (float10)DAT_020b944c;
          if ((float10)f_100 <= ABS(in_ST0)) {
            ffree(in_ST0);
            fVar9 = (float10)amod(&DAT_020b944c,&f_100);
            DAT_01c5892c = (float)fVar9;
            uStack_1e4 = 0;
            in_ST0 = extraout_ST1_00;
          }
          else {
            uStack_1e8 = 0;
          }
        }
        else {
          DAT_01c58940 = DAT_020b8ec0;
          if (DAT_020b9450 < f_10) {
            DAT_01c58930 = DAT_020b9450 + f_10;
            if (f_7 <= DAT_020b944c) {
              P5 = DAT_01c58930 + f_10;
            }
          }
          else {
            uStack_208 = 0;
          }
          if ((f_101 <= DAT_020b945c) ||
             (in_ST0 = (float10)DAT_020b944c, (float10)f_100 <= ABS(in_ST0))) {
            DAT_01c5893c = f_0;
            in_ST0 = (float10)DAT_020b944c;
            if ((float10)f_100 <= ABS(in_ST0)) {
              ffree(in_ST0);
              fVar9 = (float10)amod(&DAT_020b944c,&f_100);
              DAT_01c5892c = (float)fVar9;
              uStack_1fc = 0;
              in_ST0 = extraout_ST1_01;
            }
            else {
              uStack_200 = 0;
            }
          }
          else {
            uStack_204 = 0;
          }
        }
      }
      goto LAB_00437f8f;
    case 6:
      if (DAT_020b8ea2 != 'P') {
        uStack_1e0 = 0;
        goto LAB_00437cd3;
      }
LAB_004362d3:
      local_27c = f_4 / DAT_020b9458;
      ffree(in_ST0);
      fVar9 = (float10)amod(&local_27c,&f_1);
      if (fVar9 == (float10)f_0) {
        _DAT_01c58938 = (DAT_020b9458 * f_2) / f_3;
        if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00554852) {
          _DAT_01c58938 = (DAT_020b9458 * f_4) / f_5;
        }
        if (DAT_020b8e50 == 1) {
          local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
          DAT_020527d4 = (int)ROUND(DAT_020b9460);
          local_278 = DAT_020527d4;
          if (DAT_020527d4 / 10 == 0) {
LAB_004363fd:
            uStack_1d0 = 0;
            in_ST0 = extraout_ST1_02;
            goto LAB_00437f8f;
          }
          uStack_1d8 = 0;
        }
        else {
          if (DAT_020b9454 == f_0) goto LAB_004363fd;
          uStack_1d4 = 0;
        }
      }
      else {
        uStack_1dc = 0;
      }
      _DAT_007f75c0 = 1;
      uStack_1cc = 0;
      in_ST0 = extraout_ST1_02;
      goto LAB_00437f8f;
    case 7:
    case 8:
      local_278 = (int)ROUND(DAT_020b9460);
      IP1 = local_278 % 10;
      DAT_0078b4e4 = (local_278 % 100) / 10;
      if (DAT_020b8e50 == 2) {
        DAT_0078b4e4 = (int)ROUND(DAT_020b9454);
        local_278 = DAT_0078b4e4;
      }
      local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
      DAT_007f75c8 = DAT_020b9458;
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f44) {
        uStack_1c8 = 0;
        if (DAT_0078b4e4 == 2) {
          DAT_007f75c8 = DAT_020b9458 / f_1_75;
        }
        _DAT_01c58938 = DAT_007f75c8 * f_1_5;
        DAT_007f75c8 = f_1;
      }
      else {
        if (DAT_0078b4e4 == 1) {
          DAT_007f75c8 = DAT_020b9458 / f_1_5;
        }
        _DAT_01c58938 = DAT_007f75c8 * f_1_75;
        DAT_007f75c8 = f_2;
        uStack_1c4 = 0;
      }
      if (DAT_020b8e50 == 1) {
        in_ST0 = (float10)IP1;
        DAT_01c58940 = (float)((float10)DAT_007f75c8 * (float10)f_10 + in_ST0);
      }
      else {
        DAT_01c58934 = DAT_007f75c8;
      }
      DAT_0078b4e0 = 0;
      DAT_0078b4e4 = 0;
      uStack_1c0 = 0;
      goto LAB_00437f8f;
    case 9:
      if (DAT_020b8ea2 == 'X') {
        uStack_1bc = 0;
        ffree(in_ST0);
        fVar9 = (float10)amod(&DAT_020b944c,&f_100);
        DAT_01c5892c = (float)fVar9;
        uStack_1b0 = 0;
        in_ST0 = extraout_ST1_03;
      }
      else {
        in_ST0 = (float10)DAT_020b944c;
        if ((float10)f_100 <= ABS(in_ST0)) goto LAB_00436636;
        DAT_007f75c8 = f_100;
        if (DAT_020b944c < f_0) {
          in_ST0 = (float10)f_100;
          DAT_007f75c8 = (float)-in_ST0;
        }
        DAT_01c5892c = DAT_007f75c8 + DAT_020b944c;
        uStack_1b4 = 0;
      }
      goto LAB_00437f8f;
    case 10:
      if ((_DAT_020b8ea0 & 0xffffff) != 0x445053) {
        uStack_1ac = 0;
        goto LAB_0043687a;
      }
      DAT_020527cc = 9;
      if (DAT_020b8e50 == 2) {
        DAT_020527cc = 6;
      }
      DAT_007f75c8 = *(float *)(&DAT_020b943c + DAT_020527cc * 4);
      if (DAT_020b8ea3 == 'N') {
        uStack_1a8 = 0;
        local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
        local_278 = (int)ROUND(DAT_007f75c8);
        IP4 = local_278 + 1000;
        if (1999 < IP4) {
          IP4 = local_278 + -1000;
        }
        *(float *)(&DAT_01c5891c + DAT_020527cc * 4) = (float)IP4;
        goto LAB_0043768c;
      }
      ffree(in_ST0);
      fVar9 = (float10)amod(&DAT_007f75c8,&f_1);
      _DAT_007f75bc = (float)fVar9;
      if (_DAT_020b8ea0 >> 0x18 == 0x2d) {
        _DAT_007f75b8 = _DAT_007f75bc - f_0_05;
      }
      else {
        _DAT_007f75b8 = _DAT_007f75bc + f_0_05;
      }
      if ((f_0_96 < _DAT_007f75b8) || (_DAT_007f75b8 < f_0)) {
        _DAT_007f75b8 = f_0;
      }
      local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
      local_278 = (int)ROUND(DAT_007f75c8);
      *(float *)(&DAT_01c5891c + DAT_020527cc * 4) = (float)local_278 + _DAT_007f75b8;
      uStack_1a4 = 0;
      in_ST0 = extraout_ST1_04;
      goto LAB_00437f8f;
    case 0xb:
    case 0xc:
LAB_0043687a:
      if (DAT_020b8ea2 == 'T') {
        uStack_19c = 0;
        goto LAB_00437cd3;
      }
      if (DAT_020b8ea2 == 'F') {
        uStack_198 = 0;
        goto LAB_004377c9;
      }
      if (DAT_020b8ea2 == 'R') {
        uStack_194 = 0;
        if (_DAT_020b8ea0 == 0x58525053) {
          _DAT_01c5896c = f_0;
        }
        else {
          DAT_007f75c8 = DAT_020b948c;
          if (DAT_020b948c == f_0) {
            DAT_007f75c8 = f_1;
          }
          _DAT_01c5896c = DAT_007f75c8 + f_0_02;
        }
        _DAT_020b8ea0 = 0x20202020;
        uStack_164 = 0;
      }
      else if (DAT_020b8ea2 == 'M') {
        DAT_01c58948 = f_0;
        DAT_01c58950 = f_0;
        _DAT_01c58954 = f_0;
        uStack_18c = 0;
      }
      else {
        uStack_190 = 0;
        local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
        DAT_020527d4 = (int)ROUND(DAT_020b9450);
        local_278 = DAT_020527d4;
        if (DAT_020527d4 % 10 != 0) {
          if ((_DAT_020b8ea0 & 0xff) == 0x41) {
            uStack_184 = 0;
            DAT_007f75c8 = f_0_22;
            if (DAT_020527d4 % 10 == 2) {
              DAT_007f75c8 = f_0_26;
            }
          }
          else {
            if ((_DAT_020b8ea0 & 0xff) == 0x4e) {
              uStack_180 = 0;
              goto LAB_00436c18;
            }
            DAT_007f75c8 = f_0_02;
            if (DAT_020b8ea3 == '-') {
              in_ST0 = (float10)f_0_02;
              DAT_007f75c8 = (float)-in_ST0;
            }
            ffree(in_ST0);
            fVar9 = (float10)amod(&DAT_020b9450,&f_1);
            DAT_007f75c8 = (float)(fVar9 + (float10)DAT_007f75c8);
            if ((f_0_985 < DAT_007f75c8) || (DAT_007f75c8 < f_0_01)) {
              DAT_007f75c8 = f_0;
            }
            uStack_17c = 0;
            in_ST0 = extraout_ST1_05;
          }
          goto LAB_00436c67;
        }
        uStack_188 = 0;
LAB_004369d9:
        if (DAT_020b8ea2 == 'V') {
          _DAT_01c58954 = f_0;
          uStack_224 = 0;
        }
        else if (DAT_020b8ea2 == 'H') {
          DAT_01c58950 = f_0;
          uStack_220 = 0;
        }
        else {
          if ((DAT_020b8ea2 == 'U') || (DAT_020b8ea2 == 'D')) {
            DAT_007f75c4 = 0xe;
            DAT_007f75c8 = DAT_020b9474;
          }
          else {
            DAT_007f75c4 = 0xd;
            DAT_007f75c8 = DAT_020b9470;
          }
          P2 = f_0_5;
          if ((DAT_020b8ea2 == 'L') || (DAT_020b8ea2 == 'D')) {
            in_ST0 = (float10)f_0_5;
            P2 = (float)-in_ST0;
          }
          *(float *)(&DAT_01c5891c + DAT_007f75c4 * 4) = P2 + DAT_007f75c8;
          uStack_21c = 0;
        }
      }
      goto LAB_00437f8f;
    case 0xd:
      if ((_DAT_020b8ea0 & 0xffffff) == 0x505453) {
        DAT_007f75c8 = f_0_5;
        uStack_15c = 0;
LAB_004371ef:
        DAT_01c5893c = DAT_007f75c8 + DAT_020b945c;
        uStack_154 = 0;
        goto LAB_00437f8f;
      }
      uStack_160 = 0;
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_004d5453) {
        DAT_007f75c8 = f_m0_5;
        goto LAB_004371ef;
      }
      uStack_158 = 0;
      if ((_DAT_020b8ea0 & 0xffffff) == 0x4e5453) {
        if (f_100 <= DAT_020b945c) {
          uStack_148 = 0;
        }
        else {
          uStack_14c = 0;
          while( true ) {
            ffree(in_ST0);
            Var10 = thunk_FUN_0046cf30(&IP1,&IP2,&IP3,&DAT_007f75c8,&DAT_020b944c);
            IP1 = IP2 * 10 + IP3;
            ffree(Var10);
            in_ST0 = (float10)thunk_FUN_0046cf30(&IP5,&IP2,&IP3,&DAT_007f75c8,&DAT_020b9450);
            if (0 < IP2) break;
            uStack_144 = 0;
            DAT_007f75c8 = f_10;
            if (6 < IP1) {
              DAT_007f75c8 = f_20;
            }
            DAT_020b9450 = DAT_007f75c8 + DAT_020b9450;
            DAT_020b945c = f_0;
            uStack_120 = 0;
          }
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0046cf30(&IP3,&IP4,&IP5,&DAT_007f75c8,&DAT_020b9460);
          IP5 = IP5 + -1;
          if (IP5 < 0) {
            IP5 = 0;
          }
          if ((IP1 < 0xf) || (IP2 < 2)) {
            uStack_140 = 0;
            if ((IP1 < 0) && (IP2 < 2)) {
              uStack_138 = 0;
              IP1 = -IP5 - IP1;
              goto LAB_00436fe1;
            }
            DAT_01c5893c = f_0;
            uStack_134 = 0;
          }
          else {
            IP1 = (IP1 - IP5) + -0xe;
            uStack_13c = 0;
LAB_00436fe1:
            DAT_01c5893c = (float)IP1;
            local_27c = P4;
            ffree(in_ST0);
            fVar9 = (float10)FUN_005ff874(&local_27c,&f_100);
            DAT_007f75c8 = (float)fVar9;
            if ((DAT_007f75b4 != 1) || (DAT_007f75c8 <= f_5)) {
              if ((DAT_007f75b4 != 2) || (f_9 <= DAT_007f75c8)) {
                in_ST0 = (float10)P4;
                if ((float10)f_100 <= ABS(in_ST0)) {
                  P15 = f_0_6;
                }
                if (P15 == f_0) {
                  P15 = f_1;
                }
                _DAT_007f75b0 = P15 * f_7;
                _DAT_007f75bc = ABS(DAT_007f75c8 - f_7);
                DAT_01c5893c = (_DAT_007f75bc - _DAT_007f75b0) / P15;
                if (_DAT_007f75ac == f_0) {
                  uStack_128 = 0;
                }
                else {
                  if (f_1 < _DAT_007f75ac) {
                    DAT_01c5893c = DAT_01c5893c - P15 * f_1_666;
                  }
                  if (f_2 < _DAT_007f75ac) {
                    local_278 = IP5 + -2;
                    DAT_01c5893c = DAT_01c5893c - (float)local_278 * f_2;
                  }
                  if (DAT_01c5893c < f_0) {
                    DAT_01c5893c = f_0;
                  }
                  uStack_124 = 0;
                }
              }
              else {
                uStack_12c = 0;
                in_ST0 = extraout_ST1_06;
              }
            }
            else {
              uStack_130 = 0;
              in_ST0 = extraout_ST1_06;
            }
          }
        }
        goto LAB_00437f8f;
      }
      uStack_150 = 0;
      if ((_DAT_020b8ea0 & 0xffffff) != 0x415453) goto LAB_00437ff5;
      uStack_11c = 0;
      goto LAB_00437cd3;
    case 0xe:
      if (DAT_020b8ea2 == 'M') {
        in_ST0 = (float10)DAT_020b9468;
        DAT_01c58948 = (float)-in_ST0;
        uStack_110 = 0;
        goto LAB_00437f8f;
      }
      uStack_114 = 0;
      if (DAT_020b8ea2 == 'I') {
        ffree(in_ST0);
        thunk_FUN_0046cf30(&IP1,&IP2,&IP3,&DAT_007f75c8,&DAT_020b9450);
        IP5 = 1;
        if (IP2 == 1) {
          IP5 = 2;
        }
        if (IP2 == 0) {
          IP5 = 0;
        }
        local_278 = IP5 * 10;
        in_ST0 = (float10)local_278 + (float10)(IP1 * 100) + (float10)DAT_007f75c8;
        DAT_01c58930 = (float)((float10)IP3 + in_ST0);
        uStack_108 = 0;
        goto LAB_00437f8f;
      }
      uStack_10c = 0;
      _DAT_007f75a8 = 1;
      uStack_104 = 0;
      break;
    case 0xf:
      _DAT_007f75a8 = 2;
      uStack_100 = 0;
      break;
    case 0x10:
      _DAT_007f75a8 = 3;
      if (DAT_020b8ea2 == 'C') {
        _DAT_007f75a8 = 0;
      }
      uStack_fc = 0;
      break;
    case 0x11:
      _DAT_007f75a8 = 4;
      if (DAT_020b8ea2 == 'S') {
        _DAT_007f75a8 = 5;
      }
      break;
    case 0x12:
      if (DAT_020b8ea2 != 'P') {
        uStack_f4 = 0;
        goto LAB_00437cd3;
      }
      DAT_007f75c8 = f_100;
      if (f_100 < DAT_020b9450) {
        DAT_007f75c8 = f_m100;
      }
      DAT_01c58930 = DAT_007f75c8 + DAT_020b9450;
      uStack_f0 = 0;
      goto LAB_00437f8f;
    case 0x13:
      if (DAT_020b8ea2 == 'T') {
        uStack_ec = 0;
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0046cf30(&IP1,&IP2,&IP3,&DAT_007f75c8,&DAT_020b9460);
        DAT_007f75c8 = f_1;
        if (IP3 == 9) {
          DAT_007f75c8 = f_0;
        }
        DAT_01c58940 = DAT_007f75c8 + DAT_020b9460;
        uStack_d8 = 0;
      }
      else {
        if (f_1 <= DAT_020b9458) {
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0054d831("Adjust stems only for 1/8, 1/16, etc.",0x26);
          DAT_0078b4e0 = 9999;
          goto LAB_00438000;
        }
        uStack_e8 = 0;
        P1 = f_0;
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0040bc18();
        if (P1 == f_0) goto LAB_00437ff5;
        DAT_01c5893c = P2;
        DAT_01c58940 = P4 + DAT_020b9460;
        uStack_dc = 0;
      }
      goto LAB_00437f8f;
    case 0x14:
      ffree(in_ST0);
      thunk_FUN_0046cf30(&IP1,&IP2,&IP3,&DAT_007f75c8,&DAT_020b9460);
      in_ST0 = (float10)(IP1 * 100) + (float10)DAT_007f75c8;
      local_278 = IP2 * 10;
      DAT_01c58940 = (float)((float10)local_278 + in_ST0);
      uStack_d4 = 0;
      goto LAB_00437f8f;
    case 0x15:
      if (DAT_020b8e50 == 2) {
        uStack_d0 = 0;
LAB_0043768c:
        if (DAT_020b8e50 == 2) {
          *(float *)(&DAT_01c5891c + DAT_020527cc * 4) = DAT_020b9454;
        }
        uStack_1a0 = 0;
      }
      else {
        local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
        local_278 = (int)ROUND(DAT_020b9460);
        IP5 = (local_278 % 1000) / 100;
        DAT_007f75c8 = f_100;
        if (IP5 == 1) {
          in_ST0 = (float10)f_100;
          DAT_007f75c8 = (float)-in_ST0;
        }
        DAT_01c58940 = DAT_007f75c8 + DAT_020b9460;
        uStack_cc = 0;
      }
      goto LAB_00437f8f;
    case 0x16:
    case 0x17:
      goto LAB_004377c9;
    case 0x18:
LAB_00436c18:
      if ((_DAT_020b8ea0 & 0xffffff) == 0x54534e) {
        local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
        IP5 = (int)ROUND(DAT_020b9450);
        IP4 = (IP5 / 100) * 100;
        ffree(in_ST0);
        local_278 = IP5;
        in_ST0 = (float10)amod(&DAT_020b9450,&f_10);
        DAT_01c58930 = (float)((float10)IP4 + in_ST0);
        DAT_01c5893c = f_0;
        local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
        local_278 = (int)ROUND(DAT_020b9460);
        IP4 = local_278 % 10;
        DAT_01c58940 = DAT_020b9460 - (float)IP4;
        uStack_170 = 0;
        goto LAB_00437f8f;
      }
      uStack_174 = 0;
      if (DAT_020b8e50 == 2) {
        uStack_16c = 0;
        goto LAB_0043794d;
      }
      DAT_007f75c8 = f_0;
      uStack_168 = 0;
LAB_00436c67:
      DAT_01c58930 = (float)DAT_020527d4 + DAT_007f75c8;
      uStack_178 = 0;
      goto LAB_00437f8f;
    case 0x19:
      ffree(in_ST0);
      in_ST0 = (float10)FUN_004385a7();
      goto LAB_00438000;
    case 0x1a:
      if (DAT_020b8ea2 == 'M') {
        _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,UNK_007602f8);
      }
      if (((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4c) || ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x52)) {
        DAT_01c58944 = f_10;
        if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4c) {
          DAT_01c58944 = f_20;
        }
        uStack_bc = 0;
      }
      else {
        uStack_c0 = 0;
LAB_004377c9:
        DAT_007f75c4 = 10;
        DAT_01c58944 = f_0_5;
        if ((_DAT_020b8ea0 & 0xff) == 0x4c) {
          in_ST0 = (float10)f_0_5;
          DAT_01c58944 = (float)-in_ST0;
        }
        DAT_01c58944 = DAT_020b9464 + DAT_01c58944;
        if ((_DAT_020b8ea0 & 0xff) == 0x4e) {
          DAT_01c58944 = f_0;
        }
        _DAT_020b8ea0 = 0x20202020;
        uStack_c8 = 0;
      }
      goto LAB_00437f8f;
    case 0x1b:
      goto code_r0x00437efb;
    default:
      goto LAB_00435d98;
    }
    local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
    local_278 = (int)ROUND(DAT_020b9450);
    DAT_007f75a4 = local_278;
    if (100 < local_278) {
      DAT_007f75a4 = local_278 % 100;
    }
    DAT_007f75a4 = (DAT_007f75a4 / 10) * 10 + _DAT_007f75a8;
    ffree(in_ST0);
    in_ST0 = (float10)amod(&DAT_020b9450,&f_1);
    DAT_01c58930 = (float)((float10)DAT_007f75a4 + in_ST0);
    uStack_f8 = 0;
    goto LAB_00437f8f;
  }
  local_254 = 0;
  local_5c = 0x10;
  DAT_020527cc = 1;
LAB_00435a05:
  if ((*(uint *)(DAT_020527cc * 3 + 0x78f3ad) & 0xffffff) != (_DAT_020b8ea0 & 0xffffff))
  goto code_r0x00435a28;
  local_58 = 0;
  if (DAT_020527cc < 6) {
LAB_00435c80:
    local_278 = DAT_020527cc + -1;
    DAT_01c58930 = (float)local_278;
    goto LAB_00435c9d;
  }
  switch(DAT_020527cc) {
  case 6:
    DAT_01c5892c = f_m4;
    goto LAB_00435aa2;
  case 7:
    DAT_01c5892c = f_m2;
    uStack_44 = 0;
LAB_00435aa2:
    DAT_01c58930 = f_2;
    uStack_48 = 0;
    goto LAB_00435ca9;
  case 8:
    DAT_01c58930 = f_1;
    DAT_01c5892c = f_m2;
    uStack_40 = 0;
    goto LAB_00435ca9;
  case 9:
    DAT_01c58930 = f_0_8;
    uStack_3c = 0;
    break;
  case 10:
    DAT_01c58930 = f_0_88;
    uStack_38 = 0;
    break;
  case 0xb:
    DAT_01c58930 = f_0_15;
    uStack_34 = 0;
    break;
  case 0xc:
    DAT_01c58930 = f_1_8;
    uStack_30 = 0;
    break;
  case 0xd:
    in_ST0 = (float10)DAT_020b944c;
    if (ABS(in_ST0) < (float10)f_100) {
      DAT_007f75c8 = f_100;
      if (DAT_020b944c < f_0) {
        in_ST0 = (float10)f_100;
        DAT_007f75c8 = (float)-in_ST0;
      }
      goto LAB_00435c62;
    }
    goto LAB_00436636;
  case 0xe:
    DAT_01c58930 = f_66;
    uStack_24 = 0;
    break;
  case 0xf:
    if ((P2 != f_4) && (P2 != f_5)) goto LAB_00436636;
    DAT_01c58930 = P2 * f_11;
    uStack_1c = 0;
    break;
  case 0x10:
    in_ST0 = (float10)DAT_020b944c;
    if (ABS(in_ST0) < (float10)f_100) goto LAB_00436636;
    DAT_007f75c8 = f_100;
    if (f_0 < DAT_020b944c) {
      in_ST0 = (float10)f_100;
      DAT_007f75c8 = (float)-in_ST0;
    }
    uStack_14 = 0;
LAB_00435c62:
    DAT_01c5892c = DAT_007f75c8 + DAT_020b944c;
    uStack_28 = 0;
    goto LAB_00437f8f;
  default:
    goto LAB_00435c80;
  }
LAB_00435c9d:
  DAT_01c5892c = f_0;
LAB_00435ca9:
  DAT_01c58934 = f_0;
  DAT_0078b4e0 = 0x20;
  local_4c = 0;
  goto LAB_00437f8f;
LAB_00435d98:
  DAT_020527cc = DAT_020527cc + 1;
  local_250 = local_250 + -1;
  if (local_250 < 1) goto LAB_004378af;
  goto LAB_00435d6f;
LAB_004378af:
  if (DAT_020b8e50 == 2) {
    local_24c = 0;
    if ((_DAT_020b8ea0 & 0xff) == 0x52) {
      iVar3 = 1;
      bVar8 = false;
      pbVar5 = (byte *)((int)&DAT_020b8ea0 + 1);
      pbVar7 = &DAT_007602ec;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar2 = *pbVar7;
        bVar1 = *pbVar5;
        bVar8 = bVar1 < bVar2;
        pbVar5 = pbVar5 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar1 == bVar2);
      if (bVar8) goto LAB_00438000;
      if (DAT_020b8ea0._1_1_ == 'F') {
        local_ac = 0;
        DAT_007f75c8 = f_m1;
        if (DAT_020b8ea2 == '-') {
          DAT_007f75c8 = f_m2;
        }
        if (DAT_007f75c8 == DAT_020b945c) {
          DAT_007f75c8 = f_0;
        }
        DAT_01c5893c = DAT_007f75c8;
        local_9c = 0;
      }
      else if (DAT_020b8ea0._1_1_ == 'I') {
        local_a8 = 0;
        DAT_007f75c8 = f_m1;
        if (DAT_020b9454 == f_m1) {
          DAT_007f75c8 = f_0;
        }
        DAT_01c58934 = DAT_007f75c8;
        local_98 = 0;
      }
      else if (DAT_020b8ea0._1_1_ == 'P') {
        local_a4 = 0;
        if (DAT_020b8ea2 == 'R') {
          local_94 = 0;
          DAT_0078b4e0 = 0;
          local_27c = DAT_020b9450;
          ffree(in_ST0);
          fVar9 = (float10)FUN_005ff874(&local_27c,&f_100);
          in_ST0 = extraout_ST1_07;
          if (fVar9 < (float10)f_m3) goto LAB_00438000;
          DAT_007f75c8 = f_100;
          if (DAT_020b9450 < f_0) {
            DAT_007f75c8 = -f_100;
          }
          in_ST0 = (float10)DAT_020b9450;
          if ((float10)f_100 <= ABS(in_ST0)) {
            in_ST0 = (float10)DAT_007f75c8;
            DAT_007f75c8 = (float)-in_ST0;
          }
          DAT_01c58930 = DAT_007f75c8 + DAT_020b9450;
          local_88 = 0;
        }
        else {
          DAT_01c58930 = f_m4;
          DAT_01c5893c = f_0;
          DAT_01c58940 = f_m1;
          DAT_01c58934 = f_0;
          local_90 = 0;
        }
      }
      else {
        DAT_007f75c8 = f_1;
        if (DAT_020b8ea0._1_1_ == 'D') {
          in_ST0 = (float10)f_1;
          DAT_007f75c8 = (float)-in_ST0;
        }
        DAT_01c5892c = DAT_007f75c8 + DAT_020b944c;
        local_a0 = 0;
      }
    }
    else {
      local_b4 = 0;
      if ((_DAT_020b8ea0 & 0xffff) == 0x4257) {
        DAT_01c58930 = f_m5;
        if (P2 < f_4) {
          DAT_01c58930 = f_m2;
        }
      }
      else {
        local_84 = 0;
        if ((_DAT_020b8ea0 & 0xffff) != 0x5545) {
          local_7c = 0;
          if ((_DAT_020b8ea0 & 0xff) == 0x4d) {
            DAT_01c5893c = DAT_020b945c - P2;
            local_70 = 0;
          }
          else {
            local_74 = 0;
            if ((_DAT_020b8ea0 & 0xff) == 0x50) {
              DAT_01c5893c = P2 + DAT_020b945c;
              local_68 = 0;
            }
            else {
              local_6c = 0;
LAB_0043794d:
              if ((_DAT_020b8ea0 & 0xffffff) != 0x4e4f4e) goto LAB_00437ff5;
              DAT_01c5893c = f_0;
              local_60 = 0;
            }
          }
          goto LAB_00437f8f;
        }
        DAT_01c58930 = f_m10 - P2;
        local_78 = 0;
      }
      DAT_01c5893c = P2;
      DAT_01c58940 = f_m1;
      DAT_01c58934 = f_0;
      local_80 = 0;
    }
  }
  else {
LAB_00437cd3:
    if (DAT_020b8ea2 == '*') {
      _DAT_020b8ea0 = CONCAT12(DAT_020b90a2,DAT_020b8ea0);
    }
    local_248 = 0x24;
    DAT_020527cc = 1;
    do {
      if ((*(uint *)(s_TREBASALTTENPERSOPMEZBARTDOTUOTU_0078f3b0 + DAT_020527cc * 3 + 0x65) &
          0xffffff) == (_DAT_020b8ea0 & 0xffffff)) {
        local_244 = 0;
        if (DAT_020527cc == 0x1d) {
          DAT_01c58948 = DAT_020b9468;
          if (f_30 <= DAT_020b9468) {
            if (f_30 < DAT_020b9468) {
              DAT_01c58948 = DAT_020b9468 - f_1;
            }
            if (_DAT_020b8ea0 >> 0x18 == 0x2b) {
              DAT_01c58948 = DAT_020b9468 + f_1;
            }
          }
          else {
            DAT_01c58948 = f_30;
          }
        }
        else {
          if ((DAT_020527cc == 7) && (f_1 < P2)) {
            local_27c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
            DAT_020527cc = (int)ROUND(P2 + f_24);
            local_278 = DAT_020527cc;
          }
          DAT_01c58948 = (float)DAT_020527cc;
        }
        local_238 = 0;
        goto LAB_00437f8f;
      }
      DAT_020527cc = DAT_020527cc + 1;
      local_248 = local_248 + -1;
    } while (0 < local_248);
    if ((_DAT_020b8ea0 & 0xffff) == 0x4d4d) {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00468df8(&DAT_007602dc);
    }
    if ((_DAT_020b8ea0 & 0xffff) == 0x4852) {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00468df8(&DAT_007602d8);
    }
    if ((_DAT_020b8ea0 & 0xffff) == 0x4141) {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00468df8(&DAT_007602d4);
    }
    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) != &DAT_004d5254) {
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_0054d7d4(&DAT_020b8ea0,0x7f);
      DAT_0078b4e0 = 0;
LAB_00437ff5:
      DAT_007f75c4 = 2;
      goto LAB_00438000;
    }
    local_240 = 0;
code_r0x00437efb:
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x2b) {
      if ((DAT_020b9468 < f_41) || (f_43 < DAT_020b9468)) {
        DAT_020b9468 = f_40;
      }
      DAT_01c58948 = DAT_020b9468 + f_1;
    }
    else {
      if (P2 == f_0) {
        P2 = f_1;
      }
      DAT_01c58948 = P2 + f_40;
    }
    local_b8 = 0;
  }
  goto LAB_00437f8f;
code_r0x00435a28:
  DAT_020527cc = DAT_020527cc + 1;
  local_5c = local_5c + -1;
  bVar8 = local_5c == 0;
  if (local_5c < 1) goto LAB_00435ccc;
  goto LAB_00435a05;
LAB_00435ccc:
  iVar3 = 1;
  piVar4 = (int *)((int)&DAT_020b8ea0 + 1);
  piVar6 = &DAT_0076038c;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar8 = *piVar4 == *piVar6;
    piVar4 = piVar4 + 1;
    piVar6 = piVar6 + 1;
  } while (bVar8);
  if (!bVar8) {
LAB_00436636:
    P1 = f_1;
    P2 = (float)DAT_020b8e50;
    goto LAB_00438000;
  }
  local_54 = 0;
  _DAT_01c58958 = f_0_5;
  if ((_DAT_020b8ea0 & 0xff) == 0x4c) {
    in_ST0 = (float10)f_0_5;
    _DAT_01c58958 = (float)-in_ST0;
  }
  _DAT_01c58958 = _DAT_01c58958 + DAT_020b9478;
  if ((_DAT_020b8ea0 & 0xff) == 0x4e) {
    _DAT_01c58958 = f_0;
  }
  local_10 = 0;
LAB_00437f8f:
  DAT_0205274c = 1;
  ffree(in_ST0);
  Var10 = thunk_FUN_00467fc1();
  ffree(Var10);
  Var10 = thunk_FUN_00449ea8(&DAT_020527c8);
  ffree(Var10);
  in_ST0 = (float10)thunk_FUN_0048ecfb();
  DAT_0078b4e0 = 0xffffffff;
LAB_00438000:
  ffree(in_ST0);
  return;
}


