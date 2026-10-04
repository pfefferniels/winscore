// FUN_00575e58 @ 00575e58 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00575e58(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  unkbyte10 Var8;
  float10 extraout_ST0;
  float10 fVar9;
  float10 extraout_ST1;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  
  puVar10 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar11 = &stack0xfffffffc;
  puVar12 = &stack0xfffffffc;
  if (DAT_0078b4e4 == 0x49) {
    FUN_005f33c9(&stack0xfffffffc,0x576cd0);
    Var8 = FUN_005f34d1(puVar12,0x576ceb);
    *(undefined4 *)(puVar12 + -0xf0) = 0;
    *(undefined4 *)(puVar12 + -0x100) = 5;
    *(undefined4 *)(puVar12 + -0xfc) = 0x9ae2c3;
    *(int **)(puVar12 + -0xf8) = &VEC_N;
    ffree(Var8);
    Var8 = FUN_005f34f0(puVar12 + -0xf0,0x784ff00,&DAT_0076a758,puVar12 + -0x100,&DAT_007a0320);
    uVar2 = DAT_01fbb7c0;
    *(undefined4 *)(puVar12 + -0xf0) = 0;
    *(undefined4 *)(puVar12 + -0x100) = 5;
    *(undefined4 *)(puVar12 + -0xfc) = 0x9ae2d4;
    *(undefined4 *)(puVar12 + -0xf8) = uVar2;
    ffree(Var8);
    Var8 = FUN_005f34f0(puVar12 + -0xf0,0x784ff00,&DAT_0076a758,puVar12 + -0x100,&DAT_007a0334);
    *(undefined4 *)(puVar12 + -0xf0) = 0;
    *(undefined4 *)(puVar12 + -0x100) = 2;
    *(undefined **)(puVar12 + -0xfc) = &DAT_0076a734;
    *(undefined4 *)(puVar12 + -0xf8) = 2;
    *(undefined4 *)(puVar12 + -0xf4) = 4;
    ffree(Var8);
    Var8 = FUN_005f6540(puVar12 + -0xf0,0xb,0x784ff00,&DAT_0076a724,puVar12 + -0x100);
    iVar4 = ITEM_I;
    *(int *)(puVar12 + -0xc0) = ITEM_I;
    DAT_009a8d58 = 1;
    while (0 < iVar4) {
      DAT_01c585d4 = *(int *)(&DAT_020359fc + DAT_009a8d58 * 4);
      DAT_01caea44 = (&DAT_02035a00)[DAT_009a8d58] + -1;
      *(undefined4 *)(puVar12 + -0xf0) = 0;
      *(int **)(puVar12 + -0xf8) = &DAT_009a8d58;
      ffree(Var8);
      Var8 = FUN_005fc330(puVar12 + -0xf0,0xb,0x784ff00,&DAT_0076a720,puVar12 + -0xf8,&DAT_007a0348)
      ;
      DAT_01c585d0 = DAT_01c585d4;
      DAT_009a8d54 = 1;
      iVar4 = ((DAT_01caea44 - DAT_01c585d4) + 3) / 3;
      *(int *)(puVar12 + -0xb8) = iVar4;
      while (0 < iVar4) {
        _DAT_009a8d50 =
             *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_01c585d0 * VEC_STRIDE) - VIEW_DX;
        _DAT_009a8d4c =
             *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_01c585d0 + 1) * VEC_STRIDE) +
             290000;
        _DAT_009a8d48 =
             *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_01c585d0 + 2) * VEC_STRIDE)
        ;
        *(undefined4 *)(puVar12 + -0xf0) = 0;
        *(int **)(puVar12 + -0xf8) = &DAT_009a8d54;
        ffree(Var8);
        Var8 = FUN_005fc330(puVar12 + -0xf0,0xb,0x784ff00,&DAT_0076a71c,puVar12 + -0xf8,
                            &DAT_007a0370);
        *(undefined **)(puVar12 + -0xf8) = &DAT_009a8d50;
        ffree(Var8);
        Var8 = FUN_005fc980(puVar12 + -0xf0,&DAT_0076a71c,puVar12 + -0xf8);
        *(undefined **)(puVar12 + -0xf8) = &DAT_009a8d4c;
        ffree(Var8);
        Var8 = FUN_005fc980(puVar12 + -0xf0,&DAT_0076a71c,puVar12 + -0xf8);
        *(undefined **)(puVar12 + -0xf8) = &DAT_009a8d48;
        ffree(Var8);
        Var8 = FUN_005fc980(puVar12 + -0xf0,&DAT_0076a720,puVar12 + -0xf8);
        DAT_009a8d54 = DAT_009a8d54 + 1;
        DAT_01c585d0 = DAT_01c585d0 + 3;
        *(int *)(puVar12 + -0xb8) = *(int *)(puVar12 + -0xb8) + -1;
        iVar4 = *(int *)(puVar12 + -0xb8);
      }
      DAT_009a8d58 = DAT_009a8d58 + 1;
      *(int *)(puVar12 + -0xc0) = *(int *)(puVar12 + -0xc0) + -1;
      iVar4 = *(int *)(puVar12 + -0xc0);
    }
    *(undefined4 *)(puVar12 + -0xf0) = 0;
    ffree(Var8);
    in_ST0 = (float10)FUN_005f7950(puVar12 + -0xf0,0xb,0x784ff00,&DAT_0076a718,0);
    *(undefined4 *)(puVar12 + -0xac) = 0;
  }
  else if (DAT_0078b4e4 == 0x4a) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00574370();
    DAT_01fbb7f8 = 0;
  }
  else if (DAT_0078b4e4 == 0x45) {
    FUN_005f33c9(&stack0xfffffffc,0x576b4d);
    Var8 = FUN_005f34d1(puVar11,0x576b68);
    *(undefined4 *)(puVar11 + -0xf0) = 0;
    *(undefined4 *)(puVar11 + -0x100) = 7;
    *(undefined4 *)(puVar11 + -0xfc) = 0x9ae2da;
    *(undefined4 **)(puVar11 + -0xf8) = &DAT_0078dc84;
    ffree(Var8);
    Var8 = FUN_005f34f0(puVar11 + -0xf0,0x784ff00,&DAT_0076a758,puVar11 + -0x100,&DAT_007a0390);
    *(undefined4 *)(puVar11 + -0xf0) = 0;
    *(undefined4 *)(puVar11 + -0x100) = 5;
    *(undefined4 *)(puVar11 + -0xfc) = 0x9ae2c6;
    *(undefined **)(puVar11 + -0xf8) = &DAT_0078dc80;
    ffree(Var8);
    FUN_005f34f0(puVar11 + -0xf0,0x784ff00,&DAT_0076a7e0,puVar11 + -0x100,&DAT_007a03a4);
    FUN_005f33c9(puVar11,0x576c3c);
    in_ST0 = (float10)FUN_005f34d1(puVar11,0x576c57);
    if (DAT_0078dc88 == 0) {
      *(undefined4 *)(puVar11 + -0x94) = 0;
    }
    else {
      DAT_0078b4e4 = 0x41;
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_004d1958();
      *(undefined4 *)(puVar11 + -0x90) = 0;
    }
  }
  else {
    for (iVar4 = 1; iVar4 < 0x15; iVar4 = iVar4 + 1) {
      *(float *)(iVar4 * 4 + 0x1c4cafc) = f_0;
    }
    if (P2 != f_0) {
      iVar4 = 2;
      for (iVar6 = 1; iVar6 < 0x15; iVar6 = iVar6 + 1) {
        *(undefined4 *)(iVar6 * 4 + 0x1c4cafc) = *(undefined4 *)(&P0 + iVar4 * 4);
        iVar4 = iVar4 + 1;
      }
    }
    if (DAT_01c4cb04 == f_0) {
      DAT_01c4cb04 = f_1;
    }
    if (DAT_020b8ea0._1_1_ == 'S') {
      DAT_01caea5c = 0x87a23;
      DAT_01caea58 = -0x87a23;
      LOAD_I = 1;
      for (iVar4 = ITEM_I; 0 < iVar4; iVar4 = iVar4 + -1) {
        ffree(in_ST0);
        in_ST0 = (float10)load_item_header();
        if (LOAD_CODE == 8) {
          _DAT_009a8d38 = (float)(&STAFF_STEP0)[LOAD_STAFF] / f_25;
          DAT_009a8d34 = (int)ROUND(_DAT_009a8d38 * f_1925 + (float)(int)(&STAFF_Y0)[LOAD_STAFF]);
          if (DAT_01caea58 < DAT_009a8d34) {
            DAT_01caea58 = DAT_009a8d34;
          }
          in_ST0 = (float10)(int)(&STAFF_Y0)[LOAD_STAFF];
          DAT_009a8d3c = (int)ROUND((float10)_DAT_009a8d38 * (float10)f_525 + in_ST0);
          if (DAT_009a8d3c < DAT_01caea5c) {
            DAT_01caea5c = DAT_009a8d3c;
          }
        }
        LOAD_I = LOAD_I + 1;
      }
    }
    else {
      ffree(in_ST0);
      in_ST0 = (float10)fit_view(&DAT_0076a814,&DAT_01caea58,&DAT_01caea5c,&DAT_009a8d44,
                                 &DAT_009a8d40);
    }
    DAT_01caea58 = DAT_01caea58 - VIEW_DY;
    DAT_01caea5c = DAT_01caea5c - VIEW_DY;
    DAT_01c585c0 = f_4000;
    if (DAT_0078b4e8 != 0) {
      DAT_01c585c0 = f_1574_803;
    }
    DAT_009a8d30 = (float)(DAT_01caea58 - DAT_01caea5c) / DAT_01c585c0;
    if (DAT_0078b4e4 != 0x46) {
      if (DAT_0078b4e8 == 0) {
        FUN_005f33c9(&stack0xfffffffc,0x5761ca);
        puVar3 = puVar10;
        Var8 = FUN_005f34d1(puVar10,0x5761e5);
        *(undefined4 *)(puVar3 + -0xf0) = 0;
        *(undefined4 *)(puVar3 + -0x100) = 7;
        *(undefined4 **)(puVar3 + -0xfc) = &DAT_020b90b7;
        *(float **)(puVar3 + -0xf8) = &DAT_009a8d30;
        ffree(Var8);
        FUN_005f34f0(puVar3 + -0xf0,0x784ff00,&DAT_0076a7e0,puVar3 + -0x100,&DAT_007a03cc);
        DAT_01caea50 = f_0_04375;
      }
      else {
        FUN_005f33c9(&stack0xfffffffc,0x576271);
        Var8 = FUN_005f34d1(puVar3,0x57628c);
        *(undefined4 *)(puVar3 + -0xf0) = 0;
        *(undefined4 *)(puVar3 + -0x100) = 7;
        *(undefined **)(puVar3 + -0xfc) = &DAT_020b90bb;
        *(float **)(puVar3 + -0xf8) = &DAT_009a8d30;
        ffree(Var8);
        FUN_005f34f0(puVar3 + -0xf0,0x784ff00,&DAT_0076a7e0,puVar3 + -0x100,&DAT_007a03b8);
        DAT_01caea50 = f_0_1111252;
        *(undefined4 *)(puVar3 + -0x6c) = 0;
      }
      while( true ) {
        FUN_005f33c9(puVar3,0x57631a);
        FUN_005f33c9(puVar3,0x57633c);
        Var8 = FUN_005f34d1(puVar3,0x576357);
        ffree(Var8);
        in_ST0 = (float10)thunk_FUN_0054943a();
        P1 = DAT_009a8d30;
        P2 = DAT_009a8d30;
        if (DAT_01c4cb00 == f_0) {
          *(undefined4 *)(puVar3 + -100) = 0;
          if (DAT_02052740 == 0) {
            P4 = (float)DAT_0078b4e8;
            ffree(in_ST0);
            iVar4 = thunk_FUN_0059a610(&P1);
            in_ST0 = extraout_ST0;
            if (iVar4 == 2) {
              *(undefined4 *)(puVar3 + -0x5c) = 0;
              goto LAB_005770cf;
            }
          }
          else {
            DAT_01c585c0 = DAT_009a8d30;
            ffree(in_ST0);
            in_ST0 = (float10)thunk_FUN_00518448();
            P2 = P1;
            P1 = DAT_01c585c0;
          }
          if (P2 == P1) {
            *(undefined4 *)(puVar3 + -0x58) = 0;
            goto LAB_005770cf;
          }
          _DAT_009a8d2c = P2;
        }
        else {
          _DAT_009a8d2c = DAT_01c4cb00;
          *(undefined4 *)(puVar3 + -0x60) = 0;
        }
        ffree(in_ST0);
        Var8 = thunk_FUN_005725fa();
        ffree(Var8);
        Var8 = thunk_FUN_0054c419(&DAT_01e9ae98,&MAX_STAFF);
        if (DAT_02052740 == 0) {
          puVar5 = &DAT_009ae2bc;
          puVar7 = (undefined4 *)&DAT_020b8ea0;
          for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        ffree(Var8);
        in_ST0 = (float10)thunk_FUN_00448235(&DAT_0076a794);
        if (DAT_01c585d4 < 2) {
          *(undefined4 *)(puVar3 + -0x54) = 0;
          goto LAB_005770cf;
        }
        if (P1 != f_0) break;
        *(undefined4 *)(puVar3 + -0x50) = 0;
      }
      *(int *)(puVar3 + -0xf4) = DAT_01caea40 + -1;
      P6 = (_DAT_009a8d2c - DAT_009a8d30) / (float)*(int *)(puVar3 + -0xf4);
      P1 = P6 / DAT_01caea50;
      if (DAT_01e9ae98 == 0) {
        *(undefined4 *)(puVar3 + -0x4c) = 0;
      }
      else {
        DAT_01caea48 = (&ITEM_PTR0)[DAT_01e9ae98];
        if ((f_8 <= (float)(&ITEM_LEN)[DAT_01caea48]) &&
           (*(float *)(&ITEM_P8 + DAT_01caea48 * 4) != f_0)) {
          *(float *)(&ITEM_P8 + DAT_01caea48 * 4) =
               (_DAT_009a8d2c - DAT_009a8d30) + *(float *)(&ITEM_P8 + DAT_01caea48 * 4);
        }
      }
      P2 = P1;
      P7 = P6;
      DAT_01caea40 = DAT_01caea40 + -1;
      DAT_01caea4c = 0;
      do {
        DAT_01caea4c = DAT_01caea4c + 1;
        DAT_01c585d0 = *(int *)(&DAT_01caea60 + DAT_01caea4c * 4) + 1;
        iVar4 = ((&DAT_01caea64)[DAT_01caea4c] - DAT_01c585d0) + 1;
        *(int *)(puVar3 + -0x48) = iVar4;
        while (0 < iVar4) {
          if (*(int *)(&DAT_01e9ae94 + DAT_01c585d0 * 4) == 0) {
            *(undefined4 *)(puVar3 + -0x44) = 0;
            DAT_01caea48 = 0;
          }
          else {
            DAT_01caea48 = (&ITEM_PTR0)[*(int *)(&DAT_01e9ae94 + DAT_01c585d0 * 4)];
            fVar1 = (float)(&ITEM_LEN)[DAT_01caea48];
            *(undefined2 *)(puVar3 + -0xf8) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0xf6) = (ushort)*(undefined4 *)(puVar3 + -0xf8) | 0xc00;
            *(int *)(puVar3 + -0xf4) = (int)ROUND(fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar3 + -0xf8);
            DAT_01caea44 = *(int *)(puVar3 + -0xf4);
            DAT_01c585c0 = f_0;
            if (3 < DAT_01caea44) {
              ffree(in_ST0);
              fVar9 = (float10)amod(&ITEM_P4 + DAT_01caea48,&f_1000);
              DAT_01c585c0 = (float)fVar9;
              in_ST0 = extraout_ST1;
            }
            if (DAT_01caea44 < 10) {
              *(undefined4 *)(puVar3 + -0x40) = 0;
LAB_005766f0:
              DAT_01caea54 = f_1;
              if ((4 < DAT_01caea44) && ((float)(&ITEM_P5)[DAT_01caea48] != f_0)) {
                DAT_01caea54 = (float)(&ITEM_P5)[DAT_01caea48];
              }
              DAT_01c585c0 = P1 / DAT_01caea54 + DAT_01c585c0;
            }
            else {
              if (*(float *)(&ITEM_P10 + DAT_01caea48 * 4) == f_0) {
                *(undefined4 *)(puVar3 + -0x3c) = 0;
                goto LAB_005766f0;
              }
              DAT_01c585c0 = P6 + *(float *)(&ITEM_P10 + DAT_01caea48 * 4) + f_10000;
              *(undefined4 *)(puVar3 + -0x38) = 0;
            }
            (&DAT_01e9997c)[DAT_01c585d0] = DAT_01c585c0;
          }
          *(undefined4 *)(puVar3 + -0x34) = 0;
          DAT_01c585d0 = DAT_01c585d0 + 1;
          *(int *)(puVar3 + -0x48) = *(int *)(puVar3 + -0x48) + -1;
          iVar4 = *(int *)(puVar3 + -0x48);
        }
        P1 = P2 + P1;
        P6 = P7 + P6;
        if (DAT_01caea40 <= DAT_01caea4c) goto LAB_005767ec;
        *(undefined4 *)(puVar3 + -0x30) = 0;
      } while( true );
    }
  }
LAB_005770cf:
  ffree(in_ST0);
  return;
LAB_005767ec:
  DAT_01c585d0 = DAT_01caea64 + 1;
  iVar4 = (DAT_01c585d4 - DAT_01c585d0) + 1;
  *(int *)(puVar3 + -0x2c) = iVar4;
  P6 = f_0;
  P7 = f_0;
  while (0 < iVar4) {
    DAT_01caea44 = *(int *)(&DAT_01e9ae94 + DAT_01c585d0 * 4);
    if (DAT_01caea44 != 0) {
LAB_00576856:
      DAT_01caea48 = (&ITEM_PTR0)[DAT_01caea44];
      if ((float)(&ITEM_LEN)[DAT_01caea48] < f_4) {
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_005239c9(&DAT_01caea44,&f_4);
      }
      else {
        *(undefined4 *)(puVar3 + -0x24) = 0;
      }
      DAT_01c585c0 = (float)(&DAT_01e9997c)[DAT_01c585d0];
      if (f_10000 <= DAT_01c585c0) {
        *(float *)(&ITEM_P10 + DAT_01caea48 * 4) = DAT_01c585c0 - f_10000;
        *(undefined4 *)(puVar3 + -0x1c) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x20) = 0;
        IP7 = -1;
        IP2 = DAT_01c585d0;
        P8 = f_0;
        P5 = f_0;
        if (f_4 < (float)(&ITEM_LEN)[DAT_01caea48]) {
          P5 = (float)(&ITEM_P5)[DAT_01caea48];
        }
        fVar1 = (float)(&ITEM_P4)[DAT_01caea48];
        *(undefined2 *)(puVar3 + -0xf8) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0xf6) = (ushort)*(undefined4 *)(puVar3 + -0xf8) | 0xc00;
        *(int *)(puVar3 + -0xf4) = (int)ROUND(fVar1 / f_1000);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0xf8);
        DAT_01caea5c = *(int *)(puVar3 + -0xf4);
        if (DAT_01caea5c < 0) {
          DAT_01caea5c = -DAT_01caea5c;
        }
        if (DAT_01c585c0 < f_0) {
          DAT_01caea5c = -DAT_01caea5c;
        }
        *(int *)(puVar3 + -0xf4) = DAT_01caea5c * 1000;
        DAT_01caea54 = (float)*(int *)(puVar3 + -0xf4) + DAT_01c585c0;
        P4 = DAT_01c585c0;
        (&ITEM_P4)[DAT_01caea48] = DAT_01caea54;
      }
      LOAD_I = DAT_01caea44 + -1;
      *(int *)(puVar3 + -0x18) = -LOAD_I / -1;
      if (0 < -LOAD_I / -1) {
        do {
          ffree(in_ST0);
          in_ST0 = (float10)load_item_header();
          if ((LOAD_CODE == 8) && (DAT_01c585d0 == LOAD_STAFF)) {
            P2 = f_0;
            if (3 < LOAD_LEN) {
              P2 = (float)(&ITEM_P4)[LOAD_W];
            }
            if (DAT_01caea54 != P2) goto LAB_00576ad0;
            *(undefined4 *)(puVar3 + -0x10) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x14) = 0;
          }
          *(undefined4 *)(puVar3 + -8) = 0;
          LOAD_I = LOAD_I + -1;
          *(int *)(puVar3 + -0x18) = *(int *)(puVar3 + -0x18) + -1;
          if (*(int *)(puVar3 + -0x18) < 1) break;
        } while( true );
      }
      ffree(in_ST0);
      in_ST0 = (float10)draw_staff();
      goto LAB_00576aef;
    }
    *(undefined4 *)(puVar3 + -0x28) = 0;
LAB_00576aef:
    *(undefined4 *)(puVar3 + -4) = 0;
    DAT_01c585d0 = DAT_01c585d0 + 1;
    *(int *)(puVar3 + -0x2c) = *(int *)(puVar3 + -0x2c) + -1;
    iVar4 = *(int *)(puVar3 + -0x2c);
  }
  ffree(in_ST0);
  in_ST0 = (float10)draw_items();
  DAT_0078b4f0 = 1;
  goto LAB_005770cf;
LAB_00576ad0:
  DAT_01caea44 = LOAD_I;
  *(undefined4 *)(puVar3 + -0xc) = 0;
  goto LAB_00576856;
}


