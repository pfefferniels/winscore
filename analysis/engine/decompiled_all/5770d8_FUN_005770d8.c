// FUN_005770d8 @ 005770d8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005770d8(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var5;
  unkbyte10 Var6;
  float10 fVar7;
  unkbyte10 in_ST1;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  unkbyte10 extraout_ST1_05;
  unkbyte10 extraout_ST1_06;
  unkbyte10 extraout_ST1_07;
  unkbyte10 extraout_ST1_08;
  unkbyte10 extraout_ST1_09;
  unkbyte10 extraout_ST1_10;
  unkbyte10 extraout_ST1_11;
  unkbyte10 extraout_ST1_12;
  unkbyte10 extraout_ST1_13;
  unkbyte10 extraout_ST1_14;
  unkbyte10 extraout_ST1_15;
  unkbyte10 extraout_ST1_16;
  unkbyte10 extraout_ST1_17;
  unkbyte10 extraout_ST1_18;
  unkbyte10 extraout_ST1_19;
  unkbyte10 extraout_ST1_20;
  unkbyte10 extraout_ST1_21;
  unkbyte10 extraout_ST1_22;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  float local_e4 [2];
  float local_dc;
  uint local_d8;
  int local_d4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar8 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  puVar10 = &stack0xfffffffc;
  if ((DAT_01fbb8a0 < 0) || (DAT_01fbb8a0 == 0xf)) {
    local_b0 = 0;
    if (((_DAT_020b8ea0 & 0xff) == 0x7c) || ((_DAT_020b8ea0 & 0xff) == 0x7e)) {
      DAT_009a8d84 = VEC_N;
      DAT_01fbb8a0 = 6;
      ffree(in_ST1);
      ffree(in_ST0);
      Var5 = region_select();
      local_a4 = 0;
      Var6 = extraout_ST1_03;
    }
    else {
      ffree(in_ST1);
      ffree(in_ST0);
      Var6 = thunk_FUN_00518448();
      if (P3 == f_0) {
        P3 = f_200;
      }
      DAT_009a8d84 = VEC_N;
      ffree(extraout_ST1_01);
      ffree(Var6);
      Var5 = thunk_FUN_0041aa88();
      Var6 = extraout_ST1_02;
    }
    if (DAT_009a8d8c != 0) {
      local_a0 = 0;
      goto LAB_0057767a;
    }
    ffree(Var6);
    ffree(Var5);
    in_ST0 = ask_source_box(&DAT_009a8d80,&DAT_0076a860);
    if (DAT_009a8d80 == 0) {
      FUN_005f33c9(&stack0xfffffffc,0x577319);
      puVar2 = puVar9;
      Var6 = FUN_005f34d1(puVar9,0x577334);
      VEC_N = DAT_009a8d84;
      ffree(extraout_ST1_05);
      ffree(Var6);
      in_ST0 = thunk_FUN_00549422();
      *(undefined4 *)(puVar2 + -0x98) = 0;
      in_ST1 = extraout_ST1_06;
      goto LAB_00577357;
    }
    if (DAT_009a8d80 == -2) {
      ffree(extraout_ST1_04);
      ffree(in_ST0);
      draw_items();
      local_98 = 0;
    }
    else {
      if (DAT_009a8d98 == 'M') {
        DAT_01fbb868 = P2;
        DAT_01fbb86c = P3;
        DAT_009a8d7c = (int)ROUND(P4);
        if ((int)ROUND(P4) == 0) {
          DAT_009a8d7c = (int)ROUND(P1);
        }
        if (P3 == f_0) {
          DAT_01fbb86c = f_200;
        }
        local_94 = 0;
        local_d8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        local_d4 = (int)ROUND(P1);
        in_ST1 = extraout_ST1_04;
        DAT_009a8d90 = local_d4;
        if (local_d4 == 0) {
          DAT_009a8d90 = 999;
        }
        goto LAB_0057773f;
      }
      DAT_01fbb8a0 = -1;
      DAT_01fbb860 = (int)ROUND(P1);
      _DAT_009a8d78 = P2;
      if (P4 != f_0) {
        _DAT_009a8d78 = P4;
      }
      local_d8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      local_d4 = (int)ROUND(_DAT_009a8d78);
      if (MAX_STAFF < DAT_01fbb860) {
        DAT_01fbb860 = 1;
        DAT_01fbb864 = MAX_STAFF;
      }
      else {
        local_90 = 0;
        DAT_01fbb864 = local_d4;
      }
      DAT_01fbb868 = P2;
      DAT_01fbb86c = P3;
      if (DAT_02052748 == DAT_02052740) {
        _DAT_02052750 = 0;
        ffree(extraout_ST1_04);
        ffree(in_ST0);
        Var6 = thunk_FUN_00571f5d("Type number of staff containing notes to be adjusted.",0x36);
        if ((char)DAT_020b8ea0 == '\x02') {
          ffree(extraout_ST1_09);
          ffree(Var6);
          Var6 = thunk_FUN_0054d831(&DAT_0076a84c,0x13);
          ffree(extraout_ST1_10);
          ffree(Var6);
          draw_items();
          local_88 = 0;
          goto LAB_00577e9d;
        }
        ffree(extraout_ST1_09);
        ffree(Var6);
        Var5 = thunk_FUN_00518448();
        local_84 = 0;
        Var6 = extraout_ST1_11;
      }
      else {
        local_8c = 0;
        ffree(extraout_ST1_04);
        ffree(in_ST0);
        Var5 = thunk_FUN_00518448();
        Var6 = extraout_ST1_08;
      }
LAB_0057767a:
      if ((_DAT_020b8ea0 & 0xff) == 0x58) {
        ffree(Var6);
        ffree(Var5);
        fVar7 = (float10)thunk_FUN_0054d831(&DAT_0076a84c,0x13);
        local_80 = 0;
        Var6 = extraout_ST1_12;
        goto LAB_00577e4b;
      }
      local_d8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      DAT_009a8d90 = (int)ROUND(P1);
      local_d4 = DAT_009a8d90;
      if ((DAT_009a8d90 == 0) || (DAT_009a8d74 == 0x1b)) {
        local_7c = 0;
      }
      else {
        if (DAT_0078b4e0 != 0x42) {
          DAT_0078b4e4 = 0x58;
          ffree(Var6);
          ffree(Var5);
          in_ST0 = thunk_FUN_004f7808();
          DAT_009a8d88 = 0;
          local_74 = 0;
          in_ST1 = extraout_ST1_13;
          goto LAB_0057773f;
        }
        local_78 = 0;
      }
    }
  }
  else {
    _DAT_009a8d94 = _DAT_020b8ea0;
    local_d8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_009a8d90 = (int)ROUND(P2);
    DAT_009a8d8c = 0;
    DAT_009a8d88 = -1;
    DAT_009a8d98 = DAT_020b8ea2;
    local_d4 = DAT_009a8d90;
    if (DAT_020b8ea2 == 'U') {
LAB_00577357:
      puVar3 = (undefined4 *)&DAT_020b90a0;
      puVar4 = &DAT_009ae2bc;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      ffree(in_ST1);
      ffree(in_ST0);
      fVar7 = (float10)thunk_FUN_004a1240(&DAT_0076a868);
      *(undefined4 *)(puVar2 + -0xa4) = 0;
      Var6 = extraout_ST1_07;
      goto LAB_00577f0c;
    }
    local_ac = 0;
    if (P2 == f_0) {
      ffree(in_ST1);
      ffree(in_ST0);
      thunk_FUN_0041b68a();
      FUN_005f33c9(&stack0xfffffffc,0x5771d6);
      Var6 = FUN_005f34d1(puVar8,0x5771f1);
      puVar3 = (undefined4 *)&DAT_020b90a0;
      puVar4 = &DAT_009ae2bc;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      ffree(extraout_ST1);
      ffree(Var6);
      fVar7 = (float10)thunk_FUN_004a1240(&DAT_0076a868);
      *(undefined4 *)(puVar8 + -0x68) = 0;
      Var6 = extraout_ST1_00;
      goto LAB_00577f0c;
    }
    local_70 = 0;
LAB_0057773f:
    if (DAT_009a8d90 == 0) {
      local_68 = 0;
    }
    else {
      ffree(in_ST1);
      ffree(in_ST0);
      fVar7 = (float10)thunk_FUN_005725fa();
      LOAD_I = 1;
      Var6 = extraout_ST1_14;
      for (local_64 = ITEM_I; 0 < local_64; local_64 = local_64 + -1) {
        ffree(Var6);
        ffree(fVar7);
        fVar7 = (float10)load_item_header();
        Var6 = extraout_ST1_15;
        if ((LOAD_CODE == 1) && (4 < LOAD_LEN)) {
          if (DAT_009a8d88 < 0) {
            if ((LOAD_STAFF < DAT_009a8d90) || (DAT_009a8d7c < LOAD_STAFF)) {
              local_5c = 0;
            }
            else {
              if ((DAT_01fbb868 <= LOAD_P3) && (LOAD_P3 <= DAT_01fbb86c)) {
                local_54 = 0;
                goto LAB_00577831;
              }
              local_58 = 0;
            }
          }
          else if ((MAX_STAFF < DAT_009a8d90) || (LOAD_STAFF == DAT_009a8d90)) {
LAB_00577831:
            DAT_01c585c4 = (float)(&ITEM_P4)[LOAD_W];
            fVar7 = (float10)DAT_01c585c4;
            if (ABS(fVar7) < (float10)f_100) {
              local_d8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
              local_d4 = (int)ROUND((float)(&ITEM_P5)[LOAD_W]);
              DAT_009a8d70 = local_d4 % 100;
              if (DAT_009a8d70 < 10) {
                local_48 = 0;
              }
              else if (DAT_009a8d88 < 0) {
                local_44 = 0;
                _DAT_009a8d6c = f_0;
                if (7 < LOAD_LEN) {
                  _DAT_009a8d6c = *(float *)(&ITEM_P8 + LOAD_W * 4);
                }
                if (DAT_009a8d70 < 0x14) {
                  DAT_01c585c4 = DAT_01c585c4 + _DAT_009a8d6c;
                  local_30 = 0;
                }
                else {
                  local_34 = 0;
                  DAT_01c585c4 = f_14 - (DAT_01c585c4 - _DAT_009a8d6c);
                }
                if (f_8 <= DAT_01c585c4) {
                  _DAT_009a8d68 = f_m1_5;
                  if (DAT_01c585c4 < f_10) {
                    _DAT_009a8d68 = (f_10 - DAT_01c585c4) * f_0_5 - f_1_5;
                  }
                  if (LOAD_LEN < 9) {
                    local_28 = 0;
                  }
                  else {
                    local_d8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                    DAT_009a8d70 = (int)ROUND(*(float *)(&ITEM_P9 + LOAD_W * 4));
                    local_d4 = DAT_009a8d70;
                    if (0 < DAT_009a8d70 % 10) {
                      _DAT_009a8d68 = _DAT_009a8d68 + f_0_5;
                    }
                  }
                  if (_DAT_009a8d6c < f_0) {
                    _DAT_009a8d6c = f_0;
                  }
                  if (LOAD_LEN < 8) {
                    ffree(extraout_ST1_15);
                    ffree(fVar7);
                    fVar7 = (float10)thunk_FUN_005239c9(&LOAD_I,&f_8);
                    Var6 = extraout_ST1_16;
                  }
                  *(float *)(&ITEM_P8 + LOAD_W * 4) = _DAT_009a8d68 + _DAT_009a8d6c;
                }
                else {
                  local_2c = 0;
                }
              }
              else if ((LOAD_P3 < DAT_01fbb868) || (DAT_01fbb86c < LOAD_P3)) {
                local_40 = 0;
              }
              else {
                if (DAT_009a8d88 == 0x50) goto LAB_00577f0c;
                DAT_009a8d88 = DAT_009a8d88 + 1;
                (&DAT_01caea3c)[DAT_009a8d88] = LOAD_I;
                (&DAT_01caeb7c)[DAT_009a8d88] = DAT_009a8d70 / 10;
                local_38 = 0;
              }
            }
            else {
              local_4c = 0;
            }
          }
          else {
            local_50 = 0;
          }
        }
        else {
          local_60 = 0;
        }
        local_24 = 0;
        LOAD_I = LOAD_I + 1;
      }
      if (DAT_009a8d88 < 1) {
        local_20 = 0;
      }
      else {
        DAT_01fbb874 = 0;
        DAT_01fbb878 = 1;
        DAT_01fbb868 = (float)(&ITEM_P3)[(&ITEM_PTR0)[DAT_01caea40]];
        DAT_01c585c8 = (float)(&ITEM_P3)[(&ITEM_PTR0)[(&DAT_01caea3c)[DAT_009a8d88]]] - DAT_01fbb868
        ;
        DAT_009a8d64 = ((float)(&STAFF_STEP0)[DAT_01fbb860] * f_2_8333) / f_25;
        _DAT_009a8d60 = 0;
        DAT_009a8d5c = 2;
        DAT_01fbb870 = f_0;
        DAT_01fbb87c = ITEM_I;
        DAT_01c585c4 = DAT_01fbb868;
        DAT_01c585cc = f_1000;
        DAT_009a8d70 = DAT_01caeb80;
        local_1c = DAT_009a8d88;
        while (local_1c = local_1c + -1, 0 < local_1c) {
          if ((&DAT_01caeb7c)[DAT_009a8d5c] - DAT_009a8d70 < 0) {
            fVar7 = (float10)DAT_009a8d64;
            DAT_01c585c0 = (float)-fVar7;
            local_14 = 0;
          }
          else {
            DAT_01c585c0 = f_0;
            if ((&DAT_01caeb7c)[DAT_009a8d5c] != DAT_009a8d70) {
              local_18 = 0;
              DAT_01c585c0 = DAT_009a8d64;
            }
          }
          DAT_01fbb86c = (float)(&ITEM_P3)[(&ITEM_PTR0)[(&DAT_01caea3c)[DAT_009a8d5c]]];
          P2 = DAT_01fbb86c - DAT_01fbb868;
          if (P2 == f_0) {
            local_10 = 0;
            goto LAB_00577e9d;
          }
          ffree(Var6);
          ffree(fVar7);
          thunk_FUN_0049b1d8();
          fVar7 = (((float10)DAT_01c585c0 + (float10)DAT_01fbb86c) - (float10)DAT_01fbb868) /
                  (float10)P2;
          local_dc = (float)((float10)DAT_01c585cc + (float10)DAT_01fbb868);
          local_e4[0] = (float)fVar7;
          ffree(fVar7);
          ffree((float10)DAT_01c585cc + (float10)DAT_01fbb868);
          fVar7 = (float10)thunk_FUN_0049bb13(&DAT_0076a814,&DAT_01fbb868,&local_dc,local_e4);
          DAT_01c585cc = DAT_01c585c0 + DAT_01c585cc;
          DAT_009a8d70 = (&DAT_01caeb7c)[DAT_009a8d5c];
          local_c = 0;
          DAT_009a8d5c = DAT_009a8d5c + 1;
          DAT_01fbb868 = DAT_01fbb86c;
          Var6 = extraout_ST1_17;
        }
        DAT_01fbb86c = DAT_01c585cc + DAT_01fbb86c;
        DAT_01fbb868 = DAT_01c585c4 + f_1000;
        ffree(Var6);
        ffree(fVar7);
        Var6 = thunk_FUN_0049b1d8();
        P2 = DAT_01fbb86c - DAT_01fbb868;
        if (P2 == f_0) {
          local_8 = 0;
          goto LAB_00577e9d;
        }
        local_dc = DAT_01c585c8 / P2;
        ffree(extraout_ST1_18);
        ffree(Var6);
        fVar7 = (float10)thunk_FUN_0049bb13(&DAT_0076a814,&DAT_01fbb868,&DAT_01c585c4,&local_dc);
        Var6 = extraout_ST1_19;
      }
      DAT_0078b4f0 = 1;
LAB_00577e4b:
      DAT_0078b4e0 = 0x5a;
      DAT_0078b4e4 = 0;
      P2 = f_0;
      P3 = f_0;
      P4 = f_0;
      ffree(Var6);
      ffree(fVar7);
      Var6 = draw_items();
      ffree(extraout_ST1_20);
      ffree(Var6);
      thunk_FUN_00549422();
    }
  }
LAB_00577e9d:
  DAT_0078b4e0 = 0;
  _DAT_009c6ad4 = f_0;
  FUN_005f33c9(&stack0xfffffffc,0x577ecf);
  Var6 = FUN_005f34d1(puVar10,0x577eea);
  DAT_01fbb8a0 = 0;
  ffree(extraout_ST1_21);
  ffree(Var6);
  fVar7 = (float10)thunk_FUN_00468df8(&DAT_0076a82c);
  Var6 = extraout_ST1_22;
LAB_00577f0c:
  ffree(Var6);
  ffree(fVar7);
  return;
}


