// FUN_0042c9b0 @ 0042c9b0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0042c9b0(undefined4 *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  unkbyte10 Var4;
  float10 extraout_ST0;
  float10 fVar5;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  undefined1 *puVar6;
  uint local_fc;
  int local_f8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_bc;
  undefined4 local_b4;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_c;
  
  puVar6 = &stack0xfffffffc;
  DAT_01caf6a8 = *param_1;
  DAT_01caf688 = LOAD_I;
  DAT_01caf6ac = (int)ROUND(DAT_020b9440);
  local_fc = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_01caf6a0 = (int)ROUND(P2);
  if (DAT_0078b4e4 == 0x56) {
    local_d4 = 0;
LAB_0042cbac:
    local_fc = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    local_f8 = (int)ROUND(DAT_020b9444);
  }
  else {
    fVar1 = P3;
    fVar2 = P7;
    if (DAT_0078b4e4 == 0x4d) {
      local_fc = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      DAT_01caf6c0 = (int)ROUND(DAT_020b9440);
      local_f8 = DAT_01caf6c0;
      if ((DAT_01caf6c0 == 10) || (DAT_01caf6c0 == 0xe)) {
        local_cc = 0;
        ffree(in_ST0);
        fVar5 = (float10)amod(&DAT_020b9454,&f_100);
        P7 = (float)fVar5;
        in_ST0 = extraout_ST1_02;
        if (P7 == f_0) {
          P7 = f_1;
        }
      }
      else if (DAT_01caf6c0 == 0x11) {
        local_c8 = 0;
        ffree(in_ST0);
        fVar5 = (float10)amod(&DAT_020b9450,&f_100);
        P4 = (float)-((((ABS(fVar5) * (float10)STEP) / (float10)f_25) * (float10)f_2_82 -
                      (float10)f_1_6) / (float10)f_2);
        if (DAT_020b9458 != f_0) {
          P4 = DAT_020b9458 * P4;
        }
        local_b4 = 0;
        in_ST0 = extraout_ST1_01;
      }
      else {
        if (DAT_01caf6c0 != 0x12) goto LAB_0042d87c;
        P7 = DAT_020b9458;
        if (DAT_020b9458 == f_0) {
          P7 = f_1;
        }
        fVar2 = P7;
        if (P7 * DAT_020b944c < f_2) goto LAB_0042d87c;
        if (P8 != f_0) {
          FUN_005f33c9(&stack0xfffffffc,0x42d391);
          in_ST0 = (float10)FUN_005f34d1(puVar6,0x42d3ac);
          *(undefined4 *)(puVar6 + -0xb4) = 0;
          fVar1 = P3;
          fVar2 = P7;
          goto LAB_0042d87c;
        }
        local_bc = 0;
      }
      local_fc = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      IP9 = (int)ROUND(DAT_020b9444 + f_1);
      LOAD_I = 1;
      DAT_007f138c = f_999;
      local_f8 = IP9;
      P3 = f_0;
      for (local_b0 = ITEM_I; 0 < local_b0; local_b0 = local_b0 + -1) {
        ffree(in_ST0);
        in_ST0 = (float10)load_item_header();
        if (LOAD_CODE == 0xe) {
          if (DAT_01caf6c0 == 0xe) {
            if (DAT_01caf6a0 == LOAD_STAFF) {
              local_a4 = 0;
LAB_0042d581:
              DAT_01caf6bc = ABS(DAT_020b9448 - LOAD_P3);
              if (DAT_01caf6bc <= DAT_007f138c) {
                DAT_007f1384 = LOAD_P3;
                DAT_007f138c = DAT_01caf6bc;
              }
              else {
                local_94 = 0;
              }
            }
            else {
              local_a0 = 0;
            }
          }
          else {
            local_a8 = 0;
            if (LOAD_STAFF < IP9) {
              DAT_007f1388 = 1;
              if ((3 < LOAD_LEN) && ((float)(&ITEM_P4)[LOAD_W] != f_0)) {
                local_fc = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                DAT_007f1388 = (int)ROUND((float)(&ITEM_P4)[LOAD_W]);
                local_f8 = DAT_007f1388;
              }
              if (IP9 == DAT_007f1388 + LOAD_STAFF) goto LAB_0042d581;
              local_98 = 0;
            }
            else {
              local_9c = 0;
            }
          }
        }
        else {
          local_ac = 0;
        }
        local_90 = 0;
        LOAD_I = LOAD_I + 1;
      }
      fVar1 = P3;
      fVar2 = P7;
      if ((DAT_007f138c <= f_15) &&
         (P1 = f_3, P2 = DAT_007f1384, fVar1 = f_15, fVar2 = f_0, DAT_01caf6c0 != 0x11)) {
        if (DAT_01caf6c0 == 0x12) {
          DAT_007f138c = f_0_066;
          if (DAT_020b9450 < f_98) {
            if ((f_9 < DAT_020b9450) || (f_9 < DAT_020b9454)) {
              DAT_007f138c = f_0_122;
            }
            if ((f_19 < DAT_020b9450) || (f_19 < DAT_020b9454)) {
              DAT_007f138c = f_0_132;
            }
          }
        }
        else {
          fVar1 = P3;
          fVar2 = f_0;
          if (DAT_01caf6c0 == 0xe) goto LAB_0042d87c;
          DAT_01caf6c0 = (int)ROUND(DAT_020b9450);
          DAT_007f138c = f_0_038;
          if (1 < DAT_01caf6c0) {
            DAT_007f138c = f_0_046;
          }
          if (9 < DAT_01caf6c0) {
            DAT_007f138c = f_0_096;
          }
          if (DAT_01caf6c0 == 0xb) {
            DAT_007f138c = f_0_084;
          }
          if (99 < DAT_01caf6c0) {
            DAT_007f138c = f_0_148;
          }
          if ((DAT_01caf6c0 == 0x65) || (DAT_01caf6c0 == 0x6f)) {
            DAT_007f138c = f_0_14;
          }
          if ((1000 < DAT_01caf6c0) && (DAT_01caf6c0 < 0x403)) {
            DAT_007f138c = *(float *)(&DAT_0078dfa8 + DAT_01caf6c0 * 4);
          }
          if ((2000 < DAT_01caf6c0) && (DAT_01caf6c0 < 0x7eb)) {
            DAT_007f138c = *(float *)(s_Times_New_Roman_Times_New_Roman_B_0078cd70 +
                                     DAT_01caf6c0 * 4 + 0x230);
          }
        }
        P4 = -(P7 * DAT_007f138c * STEP);
        fVar1 = f_15;
        fVar2 = f_0;
      }
      goto LAB_0042d87c;
    }
    local_d0 = 0;
    local_f8 = DAT_01caf6a0;
    if (DAT_0078b4e4 != 0x4e) {
      local_70 = 0;
      if (DAT_0078b4e4 == 0x52) {
        if (DAT_01caf6ac != 5) goto LAB_0042d87c;
        ffree(in_ST0);
        Var4 = thunk_FUN_0054c4c6(&DAT_020b9448,&P3,&DAT_0075fe20);
        ffree(Var4);
        in_ST0 = (float10)thunk_FUN_0042c51c();
      }
      else {
        local_c = 0;
      }
      fVar1 = P3;
      fVar2 = P7;
      if (DAT_0078b4e4 == 0x44) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_0042bab0();
        fVar1 = P3;
        fVar2 = P7;
      }
      goto LAB_0042d87c;
    }
    if (DAT_01caf6ac == 5) {
      if (DAT_01caf6a0 == 0) {
        local_fc = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        local_f8 = (int)ROUND(DAT_020b9444);
      }
      DAT_01caf6a0 = local_f8;
      if (DAT_020b8ea2 == 'R') {
        ffree(in_ST0);
        in_ST0 = (float10)FUN_0042e6ab();
        fVar1 = P3;
        fVar2 = P7;
        goto LAB_0042d87c;
      }
      if (DAT_020b8ea2 == 'L') {
        ffree(in_ST0);
        in_ST0 = (float10)FUN_0042e94d();
        fVar1 = P3;
        fVar2 = P7;
        goto LAB_0042d87c;
      }
    }
    else {
      local_6c = 0;
    }
    P1 = f_0;
    if (local_f8 == 0) goto LAB_0042cbac;
    local_60 = 0;
  }
  DAT_01caf6a0 = local_f8;
  DAT_01caf6b0 = 1;
  DAT_01caf6c0 = 0;
  if (DAT_01caf6ac == 5) {
    local_fc = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_007f1380 = (int)ROUND(DAT_020b945c);
    local_f8 = DAT_007f1380;
    if ((DAT_007f1380 == 1) || (DAT_007f1380 == 2)) {
      DAT_01caf6c0 = DAT_007f1380;
    }
  }
  else {
    local_5c = 0;
  }
  ffree(in_ST0);
  in_ST0 = (float10)FUN_0042daf8(&f_3,&DAT_020b9448,&DAT_007f1380);
  fVar1 = P3;
  fVar2 = P7;
  if ((((3 < DAT_01caf6ac) && (DAT_01caf6ac < 8)) &&
      ((f_0 <= DAT_020b9458 || ((DAT_01caf6ac != 4 || (DAT_020b9454 != f_0)))))) &&
     ((DAT_020b9468 != f_0 || ((DAT_01caf6ac != 6 || (f_0 <= DAT_020b9458)))))) {
    if ((DAT_01caf6f0 != 1) || (P2 < DAT_020b9454)) {
      local_4c = 0;
      while( true ) {
        ffree(in_ST0);
        Var4 = FUN_0042daf8(&f_6,&DAT_020b9454,&DAT_007f137c);
        ffree(Var4);
        iVar3 = FUN_0042d9f9(&DAT_020b9454);
        in_ST0 = extraout_ST0;
        if (iVar3 == 0) break;
        local_44 = 0;
      }
    }
    else {
      P1 = f_6;
      P3 = f_3;
      P4 = P2 - f_4;
      if (DAT_020b945c <= f_m2) {
        P4 = P4 - f_5;
      }
      local_48 = 0;
    }
    if (DAT_01caf6ac == 5) {
      if (DAT_007f137c == DAT_007f1380) {
        P5 = f_4;
        P7 = f_5;
        DAT_007f138c = f_1;
        if (DAT_020b9458 < f_0) {
          in_ST0 = (float10)f_1;
          DAT_007f138c = (float)-in_ST0;
        }
        local_fc = (&ITEM_P4)[DAT_007f137c];
        ffree(in_ST0);
        fVar5 = (float10)FUN_005ff874(&local_fc,&f_100);
        P6 = (float)(fVar5 + (float10)DAT_007f138c);
        P8 = P6;
        in_ST0 = extraout_ST1_00;
        fVar1 = P3;
        fVar2 = P7;
      }
      else {
        if (DAT_0078b4e4 == 0x56) {
          ffree(in_ST0);
          in_ST0 = (float10)FUN_0042e11c(&DAT_007f1380,&DAT_007f137c);
        }
        if ((DAT_020b945c == f_m2) || (fVar1 = P3, fVar2 = P7, DAT_020b945c == f_m3)) {
          ffree(in_ST0);
          in_ST0 = (float10)FUN_0042d887(&DAT_020b944c,&DAT_007f1380,&DAT_007f1378);
          iVar3 = DAT_007f1378 % 2;
          if (iVar3 < 0) {
            iVar3 = -iVar3;
          }
          if (iVar3 == 0) {
            DAT_007f138c = (float)DAT_007f1378 - f_0_45;
            if (f_0 < DAT_020b9458) {
              DAT_007f138c = DAT_007f138c + f_0_9;
            }
          }
          else {
            DAT_007f138c = (float)(DAT_007f1378 + -1);
            if (f_0 < DAT_020b9458) {
              DAT_007f138c = (float)(DAT_007f1378 + 1);
            }
          }
          if ((10 < DAT_007f1378) && (f_0 < DAT_020b9458)) {
            DAT_007f138c = (float)(DAT_007f1378 + 1);
          }
          if ((DAT_007f1378 < 4) && (DAT_020b9458 < f_0)) {
            DAT_007f138c = (float)(DAT_007f1378 + -1);
          }
          P6 = DAT_007f138c;
          P8 = DAT_007f138c;
          fVar1 = P3;
          fVar2 = P7;
        }
      }
    }
    else {
      local_40 = 0;
      ffree(in_ST0);
      fVar5 = (float10)amod(&DAT_020b9458,&f_10);
      in_ST0 = extraout_ST1;
      fVar1 = P3;
      fVar2 = P7;
      if (fVar5 != (float10)f_0 || DAT_020b9468 != f_0) {
        DAT_01caf6b4 = 0xf;
        if (DAT_020b9458 < f_0) {
          DAT_01caf6b4 = 0xb;
        }
        local_2c = DAT_01caf6b4 + -10;
        for (DAT_01caf6b8 = 0xb;
            (fVar1 = P3, fVar2 = P7, 0 < local_2c && (DAT_01caf6b8 <= *param_2));
            DAT_01caf6b8 = DAT_01caf6b8 + 1) {
          if (DAT_01caf6b8 == 0xd) {
            local_24 = 0;
          }
          else if (f_0 < *(float *)(&DAT_020b943c + DAT_01caf6b8 * 4)) {
            DAT_01caf6bc = (float)DAT_01caf6b8;
            while( true ) {
              ffree(in_ST0);
              in_ST0 = (float10)FUN_0042daf8(&DAT_01caf6bc,&DAT_020b943c + DAT_01caf6b8 * 4,
                                             &DAT_007f1374);
              if ((DAT_01caf6b8 != 0xc) && (DAT_01caf6b8 != 0xf)) break;
              ffree(in_ST0);
              iVar3 = FUN_0042d9f9(&DAT_020b943c + DAT_01caf6b8 * 4);
              in_ST0 = extraout_ST0_00;
              if (iVar3 == 0) goto LAB_0042cf6d;
              local_18 = 0;
            }
            local_1c = 0;
          }
          else {
            local_20 = 0;
          }
LAB_0042cf6d:
          local_14 = 0;
          local_2c = local_2c + -1;
        }
      }
    }
  }
LAB_0042d87c:
  P7 = fVar2;
  P3 = fVar1;
  ffree(in_ST0);
  return;
}


