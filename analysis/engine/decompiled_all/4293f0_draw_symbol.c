// draw_symbol @ 004293f0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_symbol(float *param_1,float *param_2,int *param_3,float *param_4,float *param_5,
                int *param_6,undefined4 *param_7,int *param_8)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  undefined1 local_1a4 [116];
  undefined4 uStack_130;
  int *piStack_12c;
  undefined4 *puStack_128;
  undefined4 *puStack_124;
  undefined4 *puStack_120;
  undefined4 *puStack_11c;
  undefined *puStack_118;
  float *pfStack_114;
  float *pfStack_110;
  float *pfStack_10c;
  undefined4 *puStack_108;
  undefined4 local_f4;
  undefined1 *local_f0;
  undefined4 local_ec;
  undefined *local_e8;
  undefined1 *local_e4;
  undefined1 *local_e0;
  undefined4 local_dc [10];
  undefined4 local_b4;
  undefined4 local_b0;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_c;
  undefined4 local_8;
  
  pfStack_10c = (float *)&DAT_0075fc68;
  pfStack_110 = (float *)&DAT_01cf8f00;
  pfStack_114 = &P5;
  ffree(in_ST0);
  puStack_118 = (undefined *)0x42941b;
  fVar4 = (float10)thunk_FUN_0054c590();
  if ((0x513 < *param_3) && (*param_3 < 0x519)) {
    if ((IP1 == 1) || ((IP11 != 0 && (OUTPUT_MODE < 1)))) goto LAB_0042a5e3;
    if (IP2 != 0) {
      *param_4 = f_25 / (float)(&STAFF_STEP0)[IP2];
    }
  }
  puStack_108 = (undefined4 *)&DAT_0075fc60;
  pfStack_10c = param_4;
  ffree(fVar4);
  pfStack_110 = (float *)0x42949f;
  fVar4 = (float10)amod();
  DAT_007d3720 = (float)fVar4;
  _DAT_007d371c = *param_5;
  if (DAT_007d3720 == f_0) {
    DAT_007d3720 = f_1;
  }
  if (_DAT_007d371c == f_0) {
    _DAT_007d371c = DAT_007d3720;
  }
  if (*param_3 < 0) {
    *param_3 = 0;
  }
  DAT_007d3718 = *param_3;
  if ((*param_3 < 3000) || (0xc1b < *param_3)) {
    DAT_007d3714 = (undefined1 *)IP10;
    if ((P1 == f_10) || (P1 == f_18)) {
      local_e4 = (undefined1 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
      DAT_007d3714 = (undefined1 *)(int)ROUND(P16);
      local_e0 = DAT_007d3714;
    }
    DAT_007d3710 = *param_6;
    _DAT_007d370c = *param_1;
    _DAT_007d3708 = *param_2;
    DAT_007d3704 = OUTPUT_MODE;
    if (IP1 == 0xb) {
      ffree(extraout_ST1);
      puStack_108 = (undefined4 *)0x42a347;
      fVar4 = (float10)thunk_FUN_00432518();
      if (IP13 == 99) goto LAB_0042a5e3;
      if ((DAT_007d3714 != (undefined1 *)0x0) && (DAT_007d3704 == -1)) {
        pfStack_10c = (float *)&DAT_007d3714;
        ffree(fVar4);
        pfStack_110 = (float *)0x42a382;
        fVar4 = (float10)thunk_FUN_004d4ed2();
      }
      DAT_007d36f4 = (int)*(short *)(&DAT_01cb0e90 + IP5 * 2);
      DAT_007d36fc = (short)(&DAT_01cb0e92)[IP5] + -1;
      DAT_007d3720 = STEP * DAT_007d3720;
      _DAT_007d371c = STEP * _DAT_007d371c;
      DAT_007d3700 = DAT_007d36f4;
      _DAT_007d36f8 = NPT;
      for (local_a8 = (DAT_007d36fc - DAT_007d36f4) + 1; 0 < local_a8; local_a8 = local_a8 + -1) {
        _DAT_007d36f0 = DAT_007d3720 * *(float *)(&DAT_01dc41fc + DAT_007d36f4 * 4) + _DAT_007d370c;
        _DAT_007d36ec = _DAT_007d371c * *(float *)(&DAT_01e123fc + DAT_007d36f4 * 4) + _DAT_007d3708
        ;
        DAT_007d36e8 = (int)*(short *)(&DAT_01d9d0fe + DAT_007d36f4 * 2);
        if (DAT_007d36e8 < 0) {
          DAT_007d36e8 = 0;
        }
        pfStack_10c = (float *)&DAT_007d36e8;
        pfStack_110 = (float *)&DAT_007d36ec;
        pfStack_114 = (float *)&DAT_007d36f0;
        ffree(fVar4);
        puStack_118 = (undefined *)0x42a48c;
        fVar4 = (float10)add_point();
        DAT_007d36f4 = DAT_007d36f4 + 1;
      }
      if ((DAT_007d3714 != (undefined1 *)0x0) && (DAT_007d3704 == -1)) {
        ffree(fVar4);
        puStack_108 = (undefined4 *)0x42a4d3;
        fVar4 = (float10)thunk_FUN_004d4f3f();
      }
      local_a4 = 0;
LAB_0042a4dd:
      if ((float)*param_8 == f_0) {
        local_48 = 0;
      }
      else if ((P1 == f_16) && (DAT_007d3704 == -1)) {
        local_44 = 0;
      }
      else {
        puStack_108 = param_7;
        pfStack_10c = (float *)&DAT_007d3708;
        pfStack_110 = (float *)&DAT_007d370c;
        pfStack_114 = (float *)&DAT_007d36f8;
        ffree(fVar4);
        puStack_118 = (undefined *)0x42a53c;
        fVar4 = (float10)FUN_0042a5f4();
      }
      if (DAT_007d3704 < 0) {
        if ((DAT_007d3714 != (undefined1 *)0x0) && (DAT_007d3704 == -1)) {
          ffree(fVar4);
          puStack_108 = (undefined4 *)0x42a58c;
          fVar4 = (float10)thunk_FUN_004d4f3f();
        }
        local_3c = 0;
      }
      else {
        local_40 = 0;
        if ((0 < (int)DAT_007d3714) && (DAT_007d3710 == 0)) {
          DAT_007d3710 = (int)DAT_007d3714 * 0x65;
        }
      }
      if (DAT_007d3710 != 0) {
        puStack_108 = (undefined4 *)&DAT_007d36f8;
        pfStack_10c = (float *)&DAT_007d3710;
        ffree(fVar4);
        pfStack_110 = (float *)0x42a5b1;
        fVar4 = (float10)FUN_0042a8ae();
      }
      local_38 = 0;
    }
    else {
      local_b0 = 0;
      if (OUTPUT_MODE == -99) {
        pfStack_10c = (float *)param_7;
        pfStack_110 = (float *)param_8;
        pfStack_114 = (float *)&DAT_007d3708;
        puStack_118 = &DAT_007d370c;
        puStack_11c = (undefined4 *)&DAT_007d371c;
        puStack_120 = &DAT_007d3720;
        puStack_124 = &DAT_007d3714;
        puStack_128 = &DAT_007d3718;
        piStack_12c = param_3;
        ffree(extraout_ST1);
        uStack_130 = 0x42a323;
        fVar4 = (float10)thunk_FUN_00429178();
        _DAT_007d36e4 = 0xffffffff;
        local_9c = 0;
      }
      else {
        local_a0 = 0;
        fVar4 = extraout_ST1;
        if (OUTPUT_MODE == 0) {
          local_98 = 0;
        }
        else {
          local_94 = 0x15;
          DAT_007d36e0 = 1;
          do {
            if (DAT_007d3718 ==
                *(int *)(s_pizz_arcoa_tempo8va8ba15macresc__0078ea10 + DAT_007d36e0 * 4 + 0x9c)) {
              local_90 = 0;
              goto LAB_00429e8b;
            }
            DAT_007d36e0 = DAT_007d36e0 + 1;
            local_94 = local_94 + -1;
          } while (0 < local_94);
          DAT_007d36e0 = 0;
          if (((IP1 == 0x10) || (-1 < OUTPUT_MODE)) || (4999 < DAT_007d3718)) {
            local_8c = 0;
          }
          else if (((OUTPUT_MODE == -2) || (DAT_0078b4e0 == 0x56ce)) ||
                  ((*param_6 != 0 || ((*param_8 != 0 || (_DAT_007d371c != DAT_007d3720)))))) {
            local_88 = 0;
          }
          else {
            puStack_108 = &DAT_007d3718;
            pfStack_10c = &DAT_007d3720;
            pfStack_110 = (float *)&DAT_007d3708;
            pfStack_114 = (float *)&DAT_007d370c;
            ffree(extraout_ST1);
            puStack_118 = (undefined *)0x429b52;
            fVar4 = (float10)thunk_FUN_005344ba();
            if (DAT_01eae1b8 == 0) {
              if (0 < DAT_0078b6bc) {
                local_80 = 0;
                goto LAB_0042a5b8;
              }
              _DAT_007d370c = f_0;
              _DAT_007d3708 = f_0;
            }
            else {
              local_84 = 0;
            }
          }
        }
        DAT_007d36f4 = 1;
        for (local_7c = DAT_0078ea0c; 0 < local_7c; local_7c = local_7c + -1) {
          if (*param_3 == *(int *)(&DAT_01cb0ebc + DAT_007d36f4 * 4)) {
            local_78 = 0;
            goto LAB_00429dd2;
          }
          DAT_007d36f4 = DAT_007d36f4 + 1;
        }
        DAT_007d36fc = *param_3 / 10;
        puStack_108 = (undefined4 *)0x18;
        pfStack_10c = (float *)&DAT_007ec1e0;
        pfStack_110 = (float *)&DAT_007d3750;
        pfStack_114 = (float *)&DAT_007d36fc;
        ffree(fVar4);
        puStack_118 = (undefined *)0x429c38;
        fVar4 = (float10)load_symbol_library();
        if (DAT_007d36fc != -999) {
          DAT_007d36fc = *param_3 % 10 + 1;
          DAT_0078eb04 = 1;
          DAT_0078ea0c = DAT_0078ea0c + 1;
          if ((100 < DAT_0078ea0c) ||
             (10000 < (*(int *)(&DAT_0078eb00 + DAT_0078ea0c * 4) +
                      (int)*(short *)(&DAT_007d3750 + DAT_007d36fc * 2)) -
                      (int)*(short *)(&DAT_007d374e + DAT_007d36fc * 2))) {
            DAT_0078ea0c = 1;
          }
          *(int *)(&DAT_01cb0ebc + DAT_0078ea0c * 4) = *param_3;
          DAT_007d36dc = *(int *)(&DAT_0078eb00 + DAT_0078ea0c * 4) + -1;
          DAT_007d36f4 = (int)*(short *)(&DAT_007d374e + DAT_007d36fc * 2);
          for (local_70 = (int)*(short *)(&DAT_007d3750 + DAT_007d36fc * 2) -
                          (int)*(short *)(&DAT_007d374e + DAT_007d36fc * 2); 0 < local_70;
              local_70 = local_70 + -1) {
            DAT_007d36dc = DAT_007d36dc + 1;
            *(undefined4 *)(&DAT_007e21c4 + DAT_007d36dc * 4) =
                 *(undefined4 *)(&DAT_01dc41fc + DAT_007d36f4 * 4);
            *(undefined4 *)(DAT_007d36dc * 4 + 0x7d8584) =
                 *(undefined4 *)(&DAT_01e123fc + DAT_007d36f4 * 4);
            *(undefined2 *)(DAT_007d36dc * 2 + 0x7d3766) =
                 *(undefined2 *)(&DAT_01d9d0fe + DAT_007d36f4 * 2);
            DAT_007d36f4 = DAT_007d36f4 + 1;
          }
          (&DAT_0078eb04)[DAT_0078ea0c] = DAT_007d36dc + 1;
          DAT_007d36f4 = DAT_0078ea0c;
LAB_00429dd2:
          DAT_007d36d8 = 0;
          DAT_007d36dc = *(int *)(&DAT_0078eb00 + DAT_007d36f4 * 4);
          for (local_6c = (&DAT_0078eb04)[DAT_007d36f4] - DAT_007d36dc; 0 < local_6c;
              local_6c = local_6c + -1) {
            DAT_007d36d8 = DAT_007d36d8 + 1;
            *(undefined4 *)(&DAT_01dc41fc + DAT_007d36d8 * 4) =
                 *(undefined4 *)(&DAT_007e21c4 + DAT_007d36dc * 4);
            *(undefined4 *)(&DAT_01e123fc + DAT_007d36d8 * 4) =
                 *(undefined4 *)(DAT_007d36dc * 4 + 0x7d8584);
            *(undefined2 *)(&DAT_01d9d0fe + DAT_007d36d8 * 2) =
                 *(undefined2 *)(DAT_007d36dc * 2 + 0x7d3766);
            DAT_007d36dc = DAT_007d36dc + 1;
          }
LAB_00429e8b:
          P10 = f_0;
          if (DAT_007d36e0 == 0) {
            if (0x2c < DAT_007d3718) {
              DAT_007d3714 = DAT_007d3714 + -1;
            }
            if ((0x31 < DAT_007d3718) && (DAT_007d3718 < 5000)) {
              DAT_007d3720 = DAT_007d3720 * f_0_3;
              _DAT_007d371c = _DAT_007d371c * f_0_3;
            }
            if ((DAT_007d3714 != (undefined1 *)0x0) && (DAT_007d3704 == -1)) {
              pfStack_10c = (float *)&DAT_007d3714;
              ffree(fVar4);
              pfStack_110 = (float *)0x42a1e3;
              fVar4 = (float10)thunk_FUN_004d4ed2();
            }
            local_64 = 0;
            DAT_007d3720 = STEP * DAT_007d3720;
            _DAT_007d371c = STEP * _DAT_007d371c;
            DAT_007d36f4 = 1;
            _DAT_007d36f8 = NPT;
            for (local_4c = DAT_007d36d8; 0 < local_4c; local_4c = local_4c + -1) {
              _DAT_007d36f0 =
                   DAT_007d3720 * *(float *)(&DAT_01dc41fc + DAT_007d36f4 * 4) + _DAT_007d370c;
              _DAT_007d36ec =
                   _DAT_007d371c * *(float *)(&DAT_01e123fc + DAT_007d36f4 * 4) + _DAT_007d3708;
              DAT_007d36e8 = (int)*(short *)(&DAT_01d9d0fe + DAT_007d36f4 * 2);
              if (DAT_007d36e8 < 0) {
                DAT_007d36e8 = 0;
              }
              pfStack_10c = (float *)&DAT_007d36e8;
              pfStack_110 = (float *)&DAT_007d36ec;
              pfStack_114 = (float *)&DAT_007d36f0;
              ffree(fVar4);
              puStack_118 = (undefined *)0x42a2bc;
              fVar4 = (float10)add_point();
              DAT_007d36f4 = DAT_007d36f4 + 1;
            }
            goto LAB_0042a4dd;
          }
          local_68 = 0;
          DAT_01cb1068 = 0;
          DAT_007d36d4 = *(int *)(&DAT_0078ec90 + DAT_007d36e0 * 4);
          iVar3 = DAT_01cb1068;
          for (local_60 = *(int *)(&DAT_0078ec94 + DAT_007d36e0 * 4) - DAT_007d36d4; 0 < local_60;
              local_60 = local_60 + -1) {
            DAT_01cb1068 = iVar3 + 1;
            *(undefined1 *)((int)&DAT_020b8ea0 + iVar3) =
                 *(undefined1 *)((int)&DAT_0078ea0c + DAT_007d36d4 + 3);
            DAT_007d36d4 = DAT_007d36d4 + 1;
            iVar3 = DAT_01cb1068;
          }
          IP8 = 0x3ea;
          if (DAT_007d36e0 < 4) {
            IP8 = 1000;
          }
          DAT_01cb1068 = iVar3;
          if (0x31 < *param_3) {
            local_5c = 0;
            P5 = f_1_05;
            if (*param_3 == 0x114) {
              IP8 = IP14 + 1000;
              _DAT_007d36f0 = P3;
              fVar1 = P9;
              if (IP1 == 2) {
                fVar4 = ((float10)P11 + (float10)f_12) * (float10)f_7 * (float10)STEP;
                Y_POS = (float)((float10)(int)(&STAFF_Y0)[CUR_STAFF] + fVar4);
                fVar1 = f_0;
                if (f_0 < P9) {
                  _DAT_007d36f0 = P9;
                  fVar1 = f_0;
                }
              }
              P9 = fVar1;
              _DAT_007d36d0 = STEP / f_25;
              if (P12 != f_0) {
                _DAT_007d36d0 = P12 * _DAT_007d36d0;
              }
              _DAT_007d36cc = _DAT_007d36d0 * f_3_15;
              X_POS = ((P16 + _DAT_007d36f0) - _DAT_007d36cc) * f_150;
              P5 = f_0;
            }
            goto LAB_0042a076;
          }
          local_58 = 0;
          P5 = f_0;
          P10 = f_0_6;
          goto LAB_0042a0bb;
        }
        local_74 = 0;
      }
    }
  }
  else {
    local_b4 = 0;
    if (DAT_0078ed80 == 0) {
      DAT_007d36c4 = 0;
      DAT_007d36fc = 3;
      local_dc[0] = 0;
      local_ec = 0x80;
      local_e8 = &DAT_0078ed84;
      local_e4 = (undefined1 *)0x2;
      local_e0 = (undefined1 *)0x4;
      pfStack_10c = (float *)&local_ec;
      pfStack_110 = (float *)&DAT_0075fc48;
      pfStack_114 = (float *)0x784ff01;
      puStack_118 = (undefined *)0x3;
      puStack_11c = local_dc;
      ffree(extraout_ST1);
      puStack_120 = (undefined4 *)0x4295b7;
      local_30 = FUN_005f6540();
      fVar4 = extraout_ST0;
      if (local_30 == 0) {
        if (-1 < DAT_007d36fc) {
          DAT_007ebe08 = 1;
          while( true ) {
            local_f0 = local_1a4;
            iVar3 = 1;
            for (iVar2 = 1; iVar2 < 0xa1; iVar2 = iVar2 + 1) {
              local_1a4[iVar2 + -1] = (&DAT_020b8e9f)[iVar3];
              iVar3 = iVar3 + 1;
            }
            local_dc[0] = 0;
            local_f4 = 0xa0;
            local_ec = 1;
            ffree(fVar4);
            local_e4 = local_f0;
            local_e0 = local_f0;
            local_28 = FUN_005fdbd0(local_dc,DAT_007d36fc,0x784ff01,&DAT_0075fc44,&local_f4,
                                    &DAT_0078e9e0);
            fVar4 = extraout_ST0_00;
            if (local_28 == 0) {
              iVar2 = 1;
              for (iVar3 = 1; iVar3 < 0xa1; iVar3 = iVar3 + 1) {
                (&DAT_020b8e9f)[iVar2] = local_e4[iVar3 + -1];
                iVar2 = iVar2 + 1;
              }
              ffree(extraout_ST0_00);
              local_28 = FUN_005fe110(local_dc,&DAT_0075fc40,0);
              fVar4 = extraout_ST0_01;
            }
            if (local_28 != 0) break;
            if (((char)DAT_020b8ea0 == '%') || ((char)DAT_020b8ea0 == ' ')) {
              local_24 = 0;
            }
            else {
              pfStack_10c = (float *)&DAT_01cb1068;
              pfStack_110 = (float *)0x200;
              pfStack_114 = (float *)&DAT_020b8ea0;
              ffree(fVar4);
              puStack_118 = (undefined *)0x429758;
              fVar4 = (float10)thunk_FUN_0054c8e5();
              DAT_007d36c4 = DAT_007d36c4 + 1;
              DAT_007d36f4 = *(int *)(&DAT_007ebe04 + DAT_007d36c4 * 4);
              (&DAT_007ebe08)[DAT_007d36c4] = DAT_01cb1068 + DAT_007d36f4 + -5;
              DAT_007d36c0 = 6;
              for (local_20 = DAT_01cb1068 + -5; 0 < local_20; local_20 = local_20 + -1) {
                (&DAT_007ebf23)[DAT_007d36f4] = (&DAT_020b8e9f)[DAT_007d36c0];
                if ((699 < DAT_007d36f4) || (0x45 < DAT_007d36c4)) {
                  local_18 = 0;
                  goto LAB_0042983e;
                }
                local_1c = 0;
                DAT_007d36f4 = DAT_007d36f4 + 1;
                DAT_007d36c0 = DAT_007d36c0 + 1;
              }
              local_14 = 0;
            }
          }
LAB_0042983e:
          local_dc[0] = 0;
          pfStack_10c = (float *)0x0;
          pfStack_110 = (float *)&DAT_0075fc3c;
          pfStack_114 = (float *)0x784ff00;
          puStack_118 = (undefined *)DAT_007d36fc;
          puStack_11c = local_dc;
          ffree(fVar4);
          puStack_120 = (undefined4 *)0x42986e;
          fVar4 = (float10)FUN_005f7950();
          DAT_0078ed80 = 1;
          goto LAB_0042987c;
        }
        local_2c = 0;
      }
    }
    else {
      local_34 = 0;
      fVar4 = extraout_ST1;
LAB_0042987c:
      DAT_007d3718 = DAT_007d3718 + -2999;
      puStack_108 = (undefined4 *)0x1;
      pfStack_10c = (float *)&DAT_020b8ea0;
      ffree(fVar4);
      pfStack_110 = (float *)0x4298a1;
      fVar4 = (float10)thunk_FUN_0054c473();
      DAT_01cb1068 = 0;
      DAT_007d36f4 = *(int *)(&DAT_007ebe04 + DAT_007d3718 * 4);
      iVar3 = DAT_01cb1068;
      for (local_c = (&DAT_007ebe08)[DAT_007d3718] - DAT_007d36f4; 0 < local_c;
          local_c = local_c + -1) {
        DAT_01cb1068 = iVar3 + 1;
        *(undefined *)((int)&DAT_020b8ea0 + iVar3) = (&DAT_007ebf23)[DAT_007d36f4];
        DAT_007d36f4 = DAT_007d36f4 + 1;
        iVar3 = DAT_01cb1068;
      }
      P5 = f_1_05;
      if (P16 != f_0) {
        P5 = P16;
      }
      if (P17 != f_0) {
        P10 = P17;
      }
      local_8 = 0;
      DAT_01cb1068 = iVar3;
LAB_0042a076:
      P6 = DAT_007d3720 * f_1_05;
      P7 = _DAT_007d371c * f_1_05;
LAB_0042a0bb:
      local_54 = 0;
      P11 = f_0;
      if (P26 != f_0) {
        P14 = f_m1;
        P16 = P26;
      }
      DAT_007d36c8 = DAT_020b945c;
      ffree(fVar4);
      puStack_108 = (undefined4 *)0x42a10c;
      fVar4 = (float10)draw_text();
      local_e4 = (undefined1 *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
      IP8 = (int)ROUND(P8);
      DAT_020b945c = DAT_007d36c8;
      DAT_020b9470 = f_0;
      local_50 = 0;
      local_e0 = (undefined1 *)IP8;
    }
  }
LAB_0042a5b8:
  if (IP1 != 0xb) {
    pfStack_10c = (float *)&DAT_0075fc68;
    pfStack_110 = &P5;
    pfStack_114 = (float *)&DAT_01cf8f00;
    ffree(fVar4);
    puStack_118 = (undefined *)0x42a5e0;
    fVar4 = (float10)thunk_FUN_0054c590();
  }
LAB_0042a5e3:
  ffree(fVar4);
  return;
}


