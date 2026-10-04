// input_rhythm_spacing @ 0051cf40 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void input_rhythm_spacing(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  bool bVar5;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar6;
  unkbyte10 Var7;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 extraout_ST1_03;
  float10 extraout_ST1_04;
  float10 extraout_ST1_05;
  float10 extraout_ST1_06;
  float10 extraout_ST1_07;
  float10 extraout_ST1_08;
  undefined1 *puVar8;
  
  puVar8 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  _DAT_0094e3fc = (float)(&STAFF_STEP0)[(int)ROUND(DAT_01fb8c60)] / f_25;
  DAT_01f95c80 = DAT_01fb8c80;
  DAT_01f98f80 = f_m1;
  DAT_0094e3f8 = DAT_01e67910;
  DAT_0094e3f4 = DAT_01e67914;
  DAT_01e67918 = DAT_01e67910;
  DAT_01f95c84 = -1;
  DAT_01f95c88 = 0;
  DAT_0094e3f0 = f_0;
  _DAT_0094e3ec = f_0;
  DAT_01f95c8c = 0;
  if (DAT_01fb8c74 < 1) {
    DAT_0094e3e8 = f_0;
    do {
      DAT_01f95c90 = (int)ROUND((float)(&DAT_01f95d44)[DAT_01f95c80 * 0xf]);
      if (DAT_01f95c90 == 0x12) {
        DAT_0094e3e4 = f_4;
        if ((f_10 <= (float)(&DAT_01f95d54)[DAT_01f95c80 * 0xf]) ||
           (f_10 <= (float)(&DAT_01f95d58)[DAT_01f95c80 * 0xf])) {
          DAT_0094e3e4 = f_7;
        }
        DAT_0094e3e8 = f_1_5;
      }
      else {
        if (DAT_01f95c90 != 0x11) goto LAB_0051d2ec;
        ffree(in_ST0);
        fVar6 = (float10)amod(&DAT_01f95d54 + DAT_01f95c80 * 0xf,&f_100);
        DAT_0094e3e4 = (float)fVar6;
        in_ST0 = (float10)DAT_0094e3e4;
        DAT_0094e3e4 = (float)(ABS(in_ST0) * (float10)f_2_8 + (float10)f_0_5);
        DAT_0094e3e8 = f_2_5;
      }
      DAT_0094e3f4 = DAT_0094e3f4 - _DAT_0094e3fc * DAT_0094e3e4;
      (&DAT_01f95d4c)[DAT_01f95c80 * 0xf] = DAT_0094e3f4;
      DAT_01f95c80 = DAT_01f95c80 + -1;
    } while( true );
  }
  DAT_0094e3b0 = 1;
  if ((DAT_01f95d80 != f_14) && (DAT_01f99c00 == f_m14)) {
    DAT_01f99c00 = f_m99;
  }
  iVar2 = DAT_01fb8c74;
  for (DAT_01f95cc4 = 1; (0 < iVar2 && ((float)(&DAT_01f99bfc)[DAT_01f95cc4] <= f_0));
      DAT_01f95cc4 = DAT_01f95cc4 + 1) {
    iVar2 = iVar2 + -1;
  }
  DAT_01f95ca4 = (float)(&DAT_01f998dc)[DAT_01f95cc4];
  do {
    DAT_01f95cc4 = DAT_01f95cc4 + 1;
  } while ((float)(&DAT_01f99bfc)[DAT_01f95cc4] == f_m3);
  _DAT_01f95cb0 = (float)(&DAT_01f998dc)[DAT_01f95cc4];
  for (; DAT_01f95cac = (float)(&DAT_01f99bfc)[DAT_01f95cc4] - f_0_001, DAT_01f95ca8 = DAT_01f95ca4,
      DAT_01f95cac <= f_0; DAT_01f95cc4 = DAT_01f95cc4 + 1) {
  }
LAB_0051d49e:
  *(int *)(puVar3 + -0x210) = DAT_01fb8c88;
  DAT_01f95c90 = 1;
  iVar2 = DAT_01fb8c88;
  while (0 < iVar2) {
    ffree(in_ST0);
    in_ST0 = (float10)input_rhythm_value(&DAT_0094e3e0,&DAT_0094e3dc,&DAT_01fb8cc0 + DAT_01f95c90,
                                         &DAT_0094e3d8,&DAT_0094e3d4);
    DAT_01f95cbc = (uint)(_DAT_0094e3dc == f_0_0625);
    if (DAT_01f95cbc == 0) {
      *(undefined4 *)(puVar3 + -0x20c) = 0;
LAB_0051d551:
      if (DAT_01fb8c74 < 0) {
        fVar6 = (float10)FUN_006033ff(puVar3,0x51d575);
        DAT_0094e3e0 = (float)fVar6;
        in_ST0 = extraout_ST1;
      }
      _DAT_0094e3ec = DAT_0094e3e0 + _DAT_0094e3ec;
    }
    else {
      if (DAT_01fb8c74 < 1) {
        DAT_0094e3e0 = f_0_1;
        goto LAB_0051d551;
      }
      *(undefined4 *)(puVar3 + -0x208) = 0;
    }
    *(undefined4 *)(puVar3 + -0x204) = 0;
    DAT_01f95c90 = DAT_01f95c90 + 1;
    *(int *)(puVar3 + -0x210) = *(int *)(puVar3 + -0x210) + -1;
    iVar2 = *(int *)(puVar3 + -0x210);
  }
  DAT_0094e3d0 = 1;
  if (DAT_01fb8c74 < 1) {
    if (DAT_0094e3f4 <= DAT_0094e3f8) {
      DAT_0094e3f8 = DAT_0094e3cc;
    }
    _DAT_0094e3c8 = DAT_0094e3f4 - DAT_0094e3f8;
    *(int *)(puVar3 + -0x1fc) = DAT_01f95c80;
    DAT_01f95c90 = 1;
    DAT_0094e3cc = DAT_0094e3f8;
    DAT_0094e3e4 = _DAT_0094e3c8;
    iVar2 = DAT_01f95c80;
    while (0 < iVar2) {
      fVar1 = (float)(&DAT_01f95d44)[DAT_01f95c90 * 0xf];
      *(undefined2 *)(puVar3 + -0x25c) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x25a) = (ushort)*(undefined4 *)(puVar3 + -0x25c) | 0xc00;
      *(int *)(puVar3 + -600) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x25c);
      DAT_01f95c94 = *(int *)(puVar3 + -600);
      if (DAT_01f95c94 < 3) {
        *(undefined4 *)(puVar3 + -0x1f8) = 0;
      }
      else {
        if (DAT_01f95c94 == 0x11) {
          ffree(in_ST0);
          fVar6 = (float10)amod(&DAT_01f95d54 + DAT_01f95c90 * 0xf,&f_100);
          DAT_0094e3e8 = (float)fVar6;
          in_ST0 = (float10)DAT_0094e3e8;
          DAT_0094e3e8 = (float)(ABS(in_ST0) * (float10)f_2_8 + (float10)f_2);
          if ((DAT_01f95c90 < DAT_01f95c80) && ((&DAT_01f95d80)[DAT_01f95c90 * 0xf] == f_18)) {
            DAT_0094e3e8 = DAT_0094e3e8 - f_0_3;
          }
          if (DAT_01f95c90 == 1) {
            *(undefined4 *)(puVar3 + -0x1f0) = 0;
          }
          else {
            DAT_01f95c98 = DAT_01f95c90 + -1;
            if (f_2 < (float)(&DAT_01f95d44)[DAT_01f95c98 * 0xf]) {
              *(float *)(&DAT_01f95d7c + DAT_01f95c98 * 0x3c) =
                   _DAT_0094e3fc + *(float *)(&DAT_01f95d7c + DAT_01f95c98 * 0x3c);
            }
            *(undefined4 *)(puVar3 + -0x1ec) = 0;
          }
LAB_0051d9a5:
          DAT_0094e3e8 = _DAT_0094e3fc * DAT_0094e3e8;
          DAT_0094e3e4 = DAT_0094e3e4 - DAT_0094e3e8;
        }
        else {
          *(undefined4 *)(puVar3 + -500) = 0;
          if (DAT_01f95c80 != DAT_01f95c90) {
            DAT_01f95c98 = DAT_01f95c90 + 1;
            fVar1 = (float)(&DAT_01f95d44)[DAT_01f95c98 * 0xf];
            *(undefined2 *)(puVar3 + -0x25c) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x25a) = (ushort)*(undefined4 *)(puVar3 + -0x25c) | 0xc00;
            *(int *)(puVar3 + -600) = (int)ROUND(fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar3 + -0x25c);
            DAT_01f95cb8 = *(int *)(puVar3 + -600);
            if (DAT_01f95c94 == 0xe) {
              if ((DAT_01f95cb8 == 3) || (DAT_0094e3e8 = f_3_5, 0x10 < DAT_01f95cb8)) {
                DAT_0094e3e8 = f_1_5;
              }
              bVar5 = DAT_01f95cb8 == 1;
              ffree(in_ST0);
              fVar6 = (float10)amod(&DAT_01f95d54 + DAT_01f95c98 * 0xf,&f_10);
              if (bVar5 && fVar6 != (float10)f_0) {
                DAT_0094e3e8 = f_4_5;
              }
              *(undefined4 *)(puVar3 + -0x1e0) = 0;
              in_ST0 = extraout_ST1_00;
            }
            else {
              *(undefined4 *)(puVar3 + -0x1e4) = 0;
              if (DAT_01f95c94 == 0x12) {
                if ((f_10 <= (float)(&DAT_01f95d54)[DAT_01f95c90 * 0xf]) ||
                   (DAT_0094e3e8 = f_7, f_10 <= (float)(&DAT_01f95d58)[DAT_01f95c90 * 0xf])) {
                  DAT_0094e3e8 = f_9;
                }
                *(undefined4 *)(puVar3 + -0x1d8) = 0;
              }
              else {
                *(undefined4 *)(puVar3 + -0x1dc) = 0;
                DAT_0094e3e8 = f_8;
                if (DAT_01f95c90 < 3) {
                  DAT_0094e3e8 = f_9;
                }
                if (0x10 < DAT_01f95cb8) {
                  *(int *)(puVar3 + -600) = DAT_01f95cb8 + -0x13;
                  DAT_0094e3e8 = (float)*(int *)(puVar3 + -600) + DAT_0094e3e8;
                }
              }
            }
            goto LAB_0051d9a5;
          }
          *(undefined4 *)(puVar3 + -0x1e8) = 0;
          DAT_0094e3e8 = f_0;
        }
        *(float *)(&DAT_01f95d7c + DAT_01f95c90 * 0x3c) = DAT_0094e3e8;
      }
      *(undefined4 *)(puVar3 + -0x1d4) = 0;
      DAT_01f95c90 = DAT_01f95c90 + 1;
      *(int *)(puVar3 + -0x1fc) = *(int *)(puVar3 + -0x1fc) + -1;
      iVar2 = *(int *)(puVar3 + -0x1fc);
    }
  }
  else {
    *(undefined4 *)(puVar3 + -0x200) = 0;
  }
  DAT_01f95c90 = 0;
  if ((DAT_01fb8c74 < 1) || (ABS(_DAT_0094e3ec - _DAT_01f9a6f0) <= f_0_007)) {
    *(undefined4 *)(puVar3 + -0x1d0) = 0;
  }
  else {
    FUN_005f33c9(puVar3,0x51da63);
    Var7 = FUN_005f34d1(puVar3,0x51da7e);
    *(undefined4 *)(puVar3 + -0x254) = 0;
    *(undefined4 *)(puVar3 + -0x268) = 6;
    *(undefined4 *)(puVar3 + -0x264) = 0x20b8ec2;
    *(undefined **)(puVar3 + -0x260) = &DAT_01f9a6f0;
    ffree(Var7);
    Var7 = FUN_005f34f0(puVar3 + -0x254,0x784ff00,&DAT_00767a0c,puVar3 + -0x268,&DAT_00796a98);
    *(undefined4 *)(puVar3 + -0x254) = 0;
    *(undefined4 *)(puVar3 + -0x268) = 6;
    *(undefined **)(puVar3 + -0x264) = &DAT_020b8ef6;
    *(undefined **)(puVar3 + -0x260) = &DAT_0094e3ec;
    ffree(Var7);
    Var7 = FUN_005f34f0(puVar3 + -0x254,0x784ff00,&DAT_00767a0c,puVar3 + -0x268,&DAT_00796aac);
    ffree(Var7);
    in_ST0 = (float10)thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
  }
LAB_0051db53:
  DAT_01f95c90 = DAT_01f95c90 + 1;
  DAT_0094e3f0 = f_0;
  fVar1 = (float)(&DAT_01f95d44)[DAT_01f95c90 * 0xf];
  *(undefined2 *)(puVar3 + -0x25c) = in_FPUControlWord;
  *(ushort *)(puVar3 + -0x25a) = (ushort)*(undefined4 *)(puVar3 + -0x25c) | 0xc00;
  *(int *)(puVar3 + -600) = (int)ROUND(fVar1);
  in_FPUControlWord = *(undefined2 *)(puVar3 + -0x25c);
  DAT_01f95cb8 = *(int *)(puVar3 + -600);
  if (2 < DAT_01f95cb8) {
    _DAT_0094e3c4 = *(float *)(&DAT_01f95d7c + DAT_01f95c90 * 0x3c);
    *(float *)(&DAT_01f95d7c + DAT_01f95c90 * 0x3c) = f_0;
    if (DAT_01fb8c74 < 1) {
      if (DAT_01f95c80 == DAT_01f95c90) {
        DAT_0094e3f8 = DAT_0094e3f4;
      }
      if (DAT_01f95c90 == 1) {
        *(undefined4 *)(puVar3 + -0x1bc) = 0;
      }
      else if (*(float *)(DAT_01f95c90 * 0x3c + 0x1f95d08) <= f_2) {
        if (DAT_01f95cb8 == 0xe) {
          *(undefined4 *)(puVar3 + -0x1b4) = 0;
        }
        else {
          DAT_0094e3e8 = _DAT_0094e3c4 / f_3;
          DAT_0094e3e4 = DAT_0094e3e8 + DAT_0094e3e4;
          DAT_0094e3f8 = DAT_0094e3f8 - DAT_0094e3e8;
        }
      }
      else {
        *(undefined4 *)(puVar3 + -0x1b8) = 0;
      }
      (&DAT_01f95d4c)[DAT_01f95c90 * 0xf] = DAT_0094e3f8;
      DAT_0094e3f8 = _DAT_0094e3c4 + DAT_0094e3f8;
      *(undefined4 *)(puVar3 + -0x1b0) = 0;
      goto LAB_0051ec81;
    }
    *(undefined4 *)(puVar3 + -0x1c0) = 0;
    if ((DAT_01f95c90 != 1) || (DAT_01f95cb8 != 0xe)) {
      *(undefined4 *)(puVar3 + -0x44) = 0;
      DAT_01f95c98 = DAT_01f95c90 + -1;
      while (DAT_0094e3e8 = (float)(&DAT_01f95d4c)[DAT_01f95c98 * 0xf], DAT_0094e3e8 < f_0) {
        DAT_01f95c98 = DAT_01f95c98 + -1;
        if (DAT_01f95c98 < 1) goto LAB_0051e9ec;
        *(undefined4 *)(puVar3 + -0x34) = 0;
      }
      *(undefined4 *)(puVar3 + -0x38) = 0;
LAB_0051e9ec:
      _DAT_01f95cb4 = (float)DAT_01f95cb8;
      iVar2 = (DAT_01fb8c74 - DAT_0094e3b0) + 1;
      *(int *)(puVar3 + -0x30) = iVar2;
      DAT_01f95c98 = DAT_0094e3b0;
      while (0 < iVar2) {
        in_ST0 = (float10)(float)(&DAT_01f99bfc)[DAT_01f95c98];
        if (-in_ST0 == (float10)DAT_01f95cb8) {
          *(undefined4 *)(puVar3 + -0x2c) = 0;
          DAT_01f95ca0 = (float)(&DAT_01f998dc)[DAT_01f95c98];
          DAT_0094e3b0 = DAT_01f95c98 + 1;
          if (DAT_01f95c90 == 1) {
            *(undefined4 *)(puVar3 + -0x24) = 0;
            goto LAB_0051eb93;
          }
          if (DAT_0094e3e8 <= DAT_01f95ca0) {
            *(undefined4 *)(puVar3 + -0x20) = 0;
            goto LAB_0051eb93;
          }
          if (DAT_01f95cb8 == 0xe) {
            *(int *)(puVar3 + -0x18) = 0x65 - DAT_0094e3b0;
            DAT_0094e3ac = DAT_0094e3b0;
            if (0x65 - DAT_0094e3b0 < 1) goto LAB_0051eb87;
            goto LAB_0051eaf9;
          }
          *(undefined4 *)(puVar3 + -0x1c) = 0;
          goto LAB_0051eb87;
        }
        DAT_01f95c98 = DAT_01f95c98 + 1;
        *(int *)(puVar3 + -0x30) = *(int *)(puVar3 + -0x30) + -1;
        iVar2 = *(int *)(puVar3 + -0x30);
      }
      *(undefined4 *)(puVar3 + -0x28) = 0;
      goto LAB_0051eb87;
    }
    if (DAT_01f99c00 == f_m14) {
      *(undefined4 *)(puVar3 + -0x40) = 0;
      goto LAB_0051e9ec;
    }
    DAT_01f95ca0 = f_0;
    *(undefined4 *)(puVar3 + -0x3c) = 0;
    goto LAB_0051eb93;
  }
  *(undefined4 *)(puVar3 + -0x1c4) = 0;
  DAT_01f95c88 = DAT_01f95c88 + 1;
  ffree(in_ST0);
  in_ST0 = (float10)input_rhythm_value(&DAT_0094e3e0,&DAT_0094e3dc,&DAT_01fb8cc0 + DAT_01f95c88,
                                       &DAT_0094e3d8,&DAT_0094e3d4);
  (&DAT_01fb8cc0)[DAT_01f95c88] = (int)DAT_0094e3e0;
  _DAT_0094e3c0 = DAT_0094e3e0;
  fVar1 = (float)(&DAT_01f95d50)[DAT_01f95c90 * 0xf];
  *(undefined2 *)(puVar3 + -0x25c) = in_FPUControlWord;
  *(ushort *)(puVar3 + -0x25a) = (ushort)*(undefined4 *)(puVar3 + -0x25c) | 0xc00;
  *(int *)(puVar3 + -600) = (int)ROUND(fVar1);
  in_FPUControlWord = *(undefined2 *)(puVar3 + -0x25c);
  DAT_01f95c98 = *(int *)(puVar3 + -600);
  DAT_01f95cbc = (uint)(_DAT_0094e3dc == f_0_0625);
  if (DAT_01f95cbc == 0) {
    *(undefined4 *)(puVar3 + -0x1ac) = 0;
  }
  else {
    iVar2 = DAT_01f95c98;
    if (DAT_01f95c98 < 0) {
      iVar2 = -DAT_01f95c98;
    }
    if (iVar2 < 100) {
      DAT_01f95cc0 = 100;
      if (DAT_01f95c98 < 0) {
        DAT_01f95cc0 = -100;
      }
      DAT_01f95c98 = DAT_01f95cc0 + DAT_01f95c98;
      (&DAT_01f95d50)[DAT_01f95c90 * 0xf] = (float)DAT_01f95c98;
    }
    else {
      *(undefined4 *)(puVar3 + -0x1a8) = 0;
    }
  }
  *(float *)(&DAT_01f95d5c + DAT_01f95c90 * 0x3c) = DAT_0094e3e0;
  if (DAT_01f95cb8 == 2) {
    in_ST0 = (float10)DAT_0094e3e0;
    (&DAT_01fb8cc0)[DAT_01f95c88] = (int)(float)-in_ST0;
    if (DAT_01f95cbc == 0) {
      *(undefined4 *)(puVar3 + -0x1a0) = 0;
    }
    else {
      *(float *)(&DAT_01f95d5c + DAT_01f95c90 * 0x3c) = f_65;
      *(undefined4 *)(puVar3 + -0x19c) = 0;
LAB_0051e2ca:
      _DAT_0094e3c0 = f_0_1;
    }
  }
  else {
    *(undefined4 *)(puVar3 + -0x1a4) = 0;
    iVar2 = DAT_01f95c98;
    if (DAT_01f95c98 < 0) {
      iVar2 = -DAT_01f95c98;
    }
    if (iVar2 < 100) {
      *(undefined4 *)(puVar3 + -0x198) = 0;
    }
    else {
      DAT_01f95cc0 = DAT_01f95c98 % 100;
      ffree(in_ST0);
      fVar6 = (float10)amod(&DAT_01f95d60 + DAT_01f95c90 * 0xf,&f_100);
      DAT_0094e3bc = (float)(fVar6 * (float10)f_2);
      DAT_0094e3e8 = f_0;
      ffree(extraout_ST1_01);
      fVar6 = (float10)amod(&DAT_01f95d54 + DAT_01f95c90 * 0xf,&f_100);
      if ((float10)f_20 <= fVar6) {
        if ((DAT_01f95cbc == 0) && (0xd < DAT_01f95cc0)) {
          DAT_01f95cc0 = DAT_01f95cc0 + -0xc;
          *(undefined4 *)(puVar3 + -0x18c) = 0;
          goto LAB_0051de40;
        }
        *(undefined4 *)(puVar3 + -400) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x194) = 0;
        if (DAT_01f95cc0 < 1) {
          DAT_01f95cc0 = 2 - DAT_01f95cc0;
LAB_0051de40:
          DAT_0094e3e8 = (float)DAT_01f95cc0 * f_1_66666 - f_2;
        }
        else {
          *(undefined4 *)(puVar3 + -0x188) = 0;
        }
      }
      if ((DAT_0094e3e8 < DAT_0094e3bc) && ((float)(&DAT_01f95db8)[DAT_01f95c90 * 0xf] < f_0)) {
        DAT_0094e3e8 = DAT_0094e3bc;
      }
      if (DAT_01f95cbc == 0) {
        *(undefined4 *)(puVar3 + -0x184) = 0;
      }
      else {
        if (DAT_0094e3e8 == f_0) {
          DAT_0094e3e8 = f_1;
        }
        DAT_0094e3e8 = DAT_0094e3e8 + f_100;
      }
      (&DAT_01f95d60)[DAT_01f95c90 * 0xf] = DAT_0094e3e8;
      iVar2 = DAT_01f95c90;
      in_ST0 = extraout_ST1_02;
      if (DAT_01f95cbc != 0) {
        DAT_01f95c98 = DAT_01f95c90 + 1;
        DAT_01f95c94 = *(int *)(&DAT_01f9929c + DAT_0094e3d0 * 4);
        if (DAT_01f95c94 == 0) {
          ffree(extraout_ST1_02);
          fVar6 = (float10)amod(&DAT_01f95d54 + DAT_01f95c90 * 0xf,&f_10);
          (&DAT_01f95d54)[iVar2 * 0xf] = (float)fVar6;
          in_ST0 = extraout_ST1_03;
        }
        while (*(float *)(&DAT_01f95d7c + DAT_01f95c98 * 0x3c) < f_0) {
          (&DAT_01f95d4c)[DAT_01f95c98 * 0xf] = f_m1;
          fVar1 = (float)(&DAT_01f95d50)[DAT_01f95c98 * 0xf];
          *(undefined2 *)(puVar3 + -0x25c) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x25a) = (ushort)*(undefined4 *)(puVar3 + -0x25c) | 0xc00;
          *(int *)(puVar3 + -600) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x25c);
          DAT_01f95cc0 = *(int *)(puVar3 + -600);
          iVar2 = DAT_01f95cc0;
          if (DAT_01f95cc0 < 0) {
            iVar2 = -DAT_01f95cc0;
          }
          if (iVar2 < 100) {
            DAT_01f95cbc = 100;
            if (DAT_01f95cc0 < 0) {
              DAT_01f95cbc = 0xffffff9c;
            }
            *(uint *)(puVar3 + -600) = DAT_01f95cc0 + DAT_01f95cbc;
            (&DAT_01f95d50)[DAT_01f95c98 * 0xf] = (float)*(int *)(puVar3 + -600);
          }
          else {
            *(undefined4 *)(puVar3 + -0x178) = 0;
          }
          *(float *)(&DAT_01f95d5c + DAT_01f95c98 * 0x3c) = f_64;
          if (DAT_01f95c94 == 0) {
            if ((float)(&DAT_01f95d50)[DAT_01f95c98 * 0xf] <=
                (float)(&DAT_01f95d50)[DAT_01f95c90 * 0xf]) {
              ffree(in_ST0);
              Var7 = thunk_FUN_0054c669(&DAT_01f95d50 + DAT_01f95c90 * 0xf,
                                        &DAT_01f95d50 + DAT_01f95c98 * 0xf);
              ffree(Var7);
              in_ST0 = (float10)thunk_FUN_0054c669(&DAT_01f95d54 + DAT_01f95c90 * 0xf,
                                                   &DAT_01f95d54 + DAT_01f95c98 * 0xf);
            }
            else {
              *(undefined4 *)(puVar3 + -0x170) = 0;
            }
          }
          else {
            *(undefined4 *)(puVar3 + -0x174) = 0;
          }
          DAT_01f95c98 = DAT_01f95c98 + 1;
          *(undefined4 *)(puVar3 + -0x16c) = 0;
        }
        *(undefined4 *)(puVar3 + -0x17c) = 0;
        if (DAT_01f95c94 == 0) {
          (&DAT_01f95d54)[DAT_01f95c90 * 0xf] = (float)(&DAT_01f95d54)[DAT_01f95c90 * 0xf] + f_10;
          *(undefined4 *)(&DAT_01f9929c + DAT_0094e3d0 * 4) = 10;
        }
        else {
          *(undefined4 *)(puVar3 + -0x168) = 0;
        }
        (&DAT_01f95d4c)[DAT_01f95c90 * 0xf] = f_m1;
        *(float *)(&DAT_01f95d5c + DAT_01f95c90 * 0x3c) = f_65;
        *(float *)(&DAT_01f95d64 + DAT_01f95c90 * 0x3c) = f_1;
        *(float *)(&DAT_01f95d74 + DAT_01f95c90 * 0x3c) = f_1;
        DAT_01f95c9c = DAT_01f95c98 - DAT_01f95c90;
        if (DAT_01f95c9c < 2) {
          *(undefined4 *)(puVar3 + -0x164) = 0;
        }
        else {
          *(int *)(puVar3 + -600) = DAT_01f95c9c + -1;
          DAT_0094e3f0 = (float)*(int *)(puVar3 + -600);
          *(int *)(puVar3 + -0x260) = DAT_01f95c98 + -1;
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_004ee442(&DAT_0094e3f0,puVar3 + -0x260);
          (&DAT_01f95d60)[DAT_01f95c90 * 0xf] = (float)DAT_01be6c60 * f_1_6666 - f_0_3333;
        }
        _DAT_0094e3dc = f_9999;
        if (0 < DAT_01fb8c74) {
          DAT_01f95c90 = DAT_01f95c98 + -1;
          (&DAT_01f98f7c)[DAT_0094e3d0] = f_m1;
          DAT_0094e3d0 = DAT_0094e3d0 + 1;
          *(undefined4 *)(puVar3 + -0x15c) = 0;
          goto LAB_0051ec81;
        }
        *(undefined4 *)(puVar3 + -0x160) = 0;
        goto LAB_0051e2ca;
      }
      *(undefined4 *)(puVar3 + -0x180) = 0;
    }
  }
  DAT_0094e3b8 = f_0;
  DAT_01f95cc0 = DAT_01f95c90;
  if (DAT_01f95cb8 == 2) {
    *(undefined4 *)(puVar3 + -0x158) = 0;
    if (f_0 <= (float)(&DAT_01f95d58)[DAT_01f95c90 * 0xf]) {
      if (*(float *)(&DAT_01f95d7c + DAT_01f95c90 * 0x3c) == f_0) {
        (&DAT_01f95d58)[DAT_01f95c90 * 0xf] = _DAT_0094e3d8 / f_10;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x14c) = 0;
    }
  }
  else {
    if (_DAT_0094e3dc != f_9999) {
      if (_DAT_0094e3d8 == f_0) goto LAB_0051e3bd;
      if (*(int *)(&DAT_01f9929c + DAT_0094e3d0 * 4) != 0x14) goto LAB_0051e3bd;
      _DAT_0094e3d8 = _DAT_0094e3d8 + f_100;
      goto LAB_0051e3bd;
    }
    *(undefined4 *)(puVar3 + -0x154) = 0;
  }
  while( true ) {
    DAT_01f95ca0 = DAT_0094e3f8;
    if (0 < DAT_01fb8c74) {
      *(undefined4 *)(puVar3 + -0x148) = 0;
      if (DAT_01f95c8c < 0) {
        *(undefined4 *)(puVar3 + -0x9c) = 0;
      }
      else {
        DAT_01f95c8c = -1;
        DAT_0094e3f8 = DAT_01f95ca8;
        DAT_0094e3e4 = DAT_0094e3f4 - DAT_01f95ca8;
      }
      while (DAT_01f95cac <= DAT_0094e3f8) {
        while( true ) {
          DAT_01f95cc4 = DAT_01f95cc4 + 1;
          DAT_01f95c94 = DAT_01f95cc4;
          while ((float)(&DAT_01f99bfc)[DAT_01f95c94] == f_m3) {
            DAT_01f95c94 = DAT_01f95c94 + 1;
            *(undefined4 *)(puVar3 + -0x90) = 0;
          }
          *(undefined4 *)(puVar3 + -0x94) = 0;
          if (DAT_01f95c84 < 0) {
            _DAT_01f95cb0 = (float)(&DAT_01f998dc)[DAT_01f95c94];
          }
          DAT_01f95c84 = -1;
          if (f_0 <= *(float *)(DAT_01f95cc4 * 4 + 0x1f99bf8)) {
            DAT_01f95ca8 = *(float *)(DAT_01f95cc4 * 4 + 0x1f998d8);
            DAT_01f95ca4 = DAT_01f95cac;
          }
          else {
            *(undefined4 *)(puVar3 + -0x8c) = 0;
          }
          DAT_01f95cac = (float)(&DAT_01f99bfc)[DAT_01f95cc4] - f_0_001;
          if (f_0 < DAT_01f95cac) break;
          DAT_01f95c84 = 0;
          *(undefined4 *)(puVar3 + -0x84) = 0;
        }
        *(undefined4 *)(puVar3 + -0x88) = 0;
      }
      *(undefined4 *)(puVar3 + -0x98) = 0;
      in_ST0 = ((float10)_DAT_01f95cb0 - (float10)DAT_01f95ca8) *
               ((float10)DAT_0094e3f8 - (float10)DAT_01f95ca4);
      DAT_01f95ca0 = (float)(in_ST0 / ((float10)DAT_01f95cac - (float10)DAT_01f95ca4) +
                            (float10)DAT_01f95ca8);
      *(undefined4 *)(puVar3 + -0x80) = 0;
    }
    (&DAT_01f95d4c)[DAT_01f95c90 * 0xf] = DAT_01f95ca0;
    if ((float)(&DAT_01f95d44)[DAT_01f95c90 * 0xf] == f_2) {
      if (f_3 < (float)(&DAT_01f95d60)[DAT_01f95c90 * 0xf]) {
        (&DAT_01f95d54)[DAT_01f95c90 * 0xf] = f_m5;
      }
      if ((float)(&DAT_01f95d54)[DAT_01f95c90 * 0xf] <= f_m1) {
        (&DAT_01f95d50)[DAT_01f95c90 * 0xf] = f_0;
        *(float *)(&DAT_01f95d64 + DAT_01f95c90 * 0x3c) = f_m1;
      }
      else {
        *(undefined4 *)(puVar3 + -0x140) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x144) = 0;
    }
    if (DAT_01f95cb8 == 1) {
      if ((DAT_0094e3d0 < 2) || (DAT_01f95ca0 != (float)(&DAT_01f98f78)[DAT_0094e3d0])) {
        (&DAT_01f98f7c)[DAT_0094e3d0] = DAT_01f95ca0;
        DAT_0094e3d0 = DAT_0094e3d0 + 1;
      }
      else {
        *(undefined4 *)(puVar3 + -0x138) = 0;
      }
      iVar2 = DAT_01f95c90;
      if (_DAT_0094e3dc < f_4) {
        ffree(in_ST0);
        fVar6 = (float10)thunk_FUN_0051c5db(&DAT_0094e3dc);
        (&DAT_01f95d58)[iVar2 * 0xf] = (float)fVar6;
        in_ST0 = extraout_ST1_04;
      }
      else {
        *(undefined4 *)(puVar3 + -0x134) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x13c) = 0;
    }
    if (DAT_01f95c80 <= DAT_01f95c90) {
      *(undefined4 *)(puVar3 + -0x130) = 0;
      goto LAB_0051e7d0;
    }
    DAT_01f95c94 = DAT_01f95c90 + 1;
    if (f_0 <= *(float *)(&DAT_01f95d7c + DAT_01f95c94 * 0x3c)) {
      *(undefined4 *)(puVar3 + -300) = 0;
      goto LAB_0051e7d0;
    }
    if ((float)(&DAT_01f95d44)[DAT_01f95c94 * 0xf] != f_1) break;
    (&DAT_01f95d4c)[DAT_01f95c94 * 0xf] = DAT_01f95ca0;
    *(float *)(&DAT_01f95d5c + DAT_01f95c94 * 0x3c) = DAT_0094e3e0;
    DAT_01f95c90 = DAT_01f95c94;
    *(undefined4 *)(puVar3 + -0x124) = 0;
LAB_0051e3bd:
    if (*(float *)(&DAT_01f95d7c + DAT_01f95c90 * 0x3c) == f_m1) {
      DAT_0094e3d4 = f_0;
    }
    *(float *)(&DAT_01f95d64 + DAT_01f95c90 * 0x3c) = _DAT_0094e3d8 + DAT_0094e3d4;
    *(float *)(&DAT_01f95d74 + DAT_01f95c90 * 0x3c) = DAT_0094e3d4;
    DAT_0094e3f0 = f_0;
    *(undefined4 *)(puVar3 + -0x150) = 0;
  }
  *(undefined4 *)(puVar3 + -0x128) = 0;
LAB_0051e7d0:
  DAT_0094e3f0 = DAT_0094e3f8;
  if (DAT_01fb8c74 < 0) {
    fVar6 = (float10)FUN_006033ff(puVar3,0x51e800);
    _DAT_0094e3c0 = (float)fVar6;
    in_ST0 = extraout_ST1_05;
  }
  DAT_0094e3f8 = (_DAT_0094e3c0 / _DAT_0094e3ec) * DAT_0094e3e4 + DAT_0094e3f8;
  if ((float)(&DAT_01f95d44)[DAT_01f95cc0 * 0xf] == f_1) {
    *(undefined4 *)(puVar3 + -0x120) = 0;
  }
  else if (*(float *)(&DAT_01f95d7c + DAT_01f95cc0 * 0x3c) == f_0) {
    if (_DAT_0094e3dc < f_4) {
      ffree(in_ST0);
      fVar6 = (float10)thunk_FUN_0051c5db(&DAT_0094e3dc);
      DAT_0094e3d4 = (float)-fVar6;
      in_ST0 = extraout_ST1_06;
    }
    (&DAT_01f95d54)[DAT_01f95cc0 * 0xf] = DAT_0094e3d4;
  }
  else {
    *(undefined4 *)(puVar3 + -0x11c) = 0;
  }
  goto LAB_0051ec81;
LAB_0051d2ec:
  DAT_0094e3f4 = DAT_0094e3f4 - _DAT_0094e3fc * DAT_0094e3e8;
  puVar3 = &stack0xfffffffc;
  if (DAT_01fb8c88 != DAT_01fb8cc0) {
    if (DAT_01fb8cc0 < DAT_01fb8c88) {
      DAT_01f95c90 = DAT_01fb8cc0 + 1;
      for (iVar2 = (DAT_01fb8c88 - DAT_01f95c90) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
        (&DAT_01fb8cc0)[DAT_01f95c90] = (int)f_64;
        DAT_01f95c90 = DAT_01f95c90 + 1;
      }
    }
    FUN_005f33c9(&stack0xfffffffc,0x51d3ba);
    Var7 = FUN_005f34d1(puVar8,0x51d3d5);
    *(undefined4 *)(puVar8 + -0x254) = 0;
    *(undefined4 *)(puVar8 + -0x268) = 2;
    *(undefined2 **)(puVar8 + -0x264) = &DAT_020b8eac;
    *(int **)(puVar8 + -0x260) = &DAT_01fb8cc0;
    ffree(Var7);
    Var7 = FUN_005f34f0(puVar8 + -0x254,0x784ff00,&DAT_00767a9c,puVar8 + -0x268,&DAT_00796a70);
    *(undefined4 *)(puVar8 + -0x254) = 0;
    *(undefined4 *)(puVar8 + -0x268) = 2;
    *(undefined4 **)(puVar8 + -0x264) = &DAT_020b8eb8;
    *(int **)(puVar8 + -0x260) = &DAT_01fb8c88;
    ffree(Var7);
    Var7 = FUN_005f34f0(puVar8 + -0x254,0x784ff00,&DAT_00767a9c,puVar8 + -0x268,&DAT_00796a84);
    ffree(Var7);
    in_ST0 = (float10)thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
    puVar3 = puVar8;
  }
  goto LAB_0051d49e;
LAB_0051eaf9:
  do {
    if ((float)(&DAT_01f99bfc)[DAT_0094e3ac] == f_m14) {
      if (DAT_0094e3e8 <= (float)(&DAT_01f998dc)[DAT_0094e3ac]) {
        DAT_01f95ca0 = (float)(&DAT_01f998dc)[DAT_0094e3ac];
        *(undefined4 *)(puVar3 + -0xc) = 0;
        goto LAB_0051eb93;
      }
      *(undefined4 *)(puVar3 + -0x10) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0x14) = 0;
    }
    *(undefined4 *)(puVar3 + -8) = 0;
    DAT_0094e3ac = DAT_0094e3ac + 1;
    *(int *)(puVar3 + -0x18) = *(int *)(puVar3 + -0x18) + -1;
  } while (0 < *(int *)(puVar3 + -0x18));
LAB_0051eb87:
  DAT_01f95ca0 = DAT_0094e3e8;
LAB_0051eb93:
  (&DAT_01f95d4c)[DAT_01f95c90 * 0xf] = DAT_01f95ca0;
  *(undefined4 *)(puVar3 + -4) = 0;
LAB_0051ec81:
  if (DAT_01f95c80 <= DAT_01f95c90) goto LAB_0051ec9e;
  *(undefined4 *)(puVar3 + -0x118) = 0;
  goto LAB_0051db53;
LAB_0051ec9e:
  DAT_01f95c9c = DAT_0094e3d0 + -1;
  iVar2 = -DAT_01f95c80 / -1;
  *(int *)(puVar3 + -0x114) = iVar2;
  DAT_01f95c90 = DAT_01f95c80;
  while (0 < iVar2) {
    if ((float)(&DAT_01f95d4c)[DAT_01f95c90 * 0xf] < f_0) {
      if (DAT_01f95c80 == DAT_01f95c90) {
        (&DAT_01f95d4c)[DAT_01f95c90 * 0xf] = DAT_0094e3f4 - f_4;
        *(undefined4 *)(puVar3 + -0x108) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x10c) = 0;
        DAT_0094e3b4 = DAT_01f95c90 + -1;
        while (fVar1 = (float)(&DAT_01f95d4c)[DAT_0094e3b4 * 0xf], fVar1 <= f_0) {
          DAT_0094e3b4 = DAT_0094e3b4 + -1;
          if (DAT_0094e3b4 < 1) goto LAB_0051ed7e;
          *(undefined4 *)(puVar3 + -0x100) = 0;
        }
        *(undefined4 *)(puVar3 + -0x104) = 0;
LAB_0051ed7e:
        DAT_0094e3f0 = (float)(&DAT_01f95d88)[DAT_01f95c90 * 0xf];
        fVar1 = DAT_0094e3f0 - fVar1;
        DAT_0094e3e8 = f_3;
        if (fVar1 <= f_4) {
          DAT_0094e3e8 = fVar1 / f_2;
        }
        DAT_0094e3b8 = DAT_0094e3f0;
        if (f_0 <= (float)(&DAT_01f95db8)[DAT_01f95c90 * 0xf]) {
          *(undefined4 *)(puVar3 + -0xfc) = 0;
          DAT_0094e3b8 = DAT_0094e3f0 - DAT_0094e3e8;
        }
        (&DAT_01f95d4c)[DAT_01f95c90 * 0xf] = DAT_0094e3b8;
        (&DAT_01f98f7c)[DAT_01f95c9c] = DAT_0094e3b8;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x110) = 0;
    }
    if ((f_0 <= *(float *)(&DAT_01f95d7c + DAT_01f95c90 * 0x3c)) &&
       ((float)(&DAT_01f95d44)[DAT_01f95c90 * 0xf] == f_1)) {
      DAT_01f95c9c = DAT_01f95c9c + -1;
    }
    DAT_01f95c90 = DAT_01f95c90 + -1;
    *(int *)(puVar3 + -0x114) = *(int *)(puVar3 + -0x114) + -1;
    iVar2 = *(int *)(puVar3 + -0x114);
  }
  DAT_01f95c90 = 0;
  do {
    iVar2 = DAT_01f95c90 + 1;
    if (f_10 <= *(float *)(&DAT_01f95d64 + iVar2 * 0x3c)) {
      DAT_0094e3e8 = (float)(&DAT_01f95d4c)[iVar2 * 0xf];
      DAT_01f95c9c = DAT_01f95c90 + 2;
      iVar4 = (DAT_01f95c80 - DAT_01f95c9c) + 1;
      *(int *)(puVar3 + -0xf4) = iVar4;
      DAT_01f95c90 = iVar2;
      while (0 < iVar4) {
        if (DAT_0094e3e8 != (float)(&DAT_01f95d4c)[DAT_01f95c9c * 0xf]) {
          *(undefined4 *)(puVar3 + -0xf0) = 0;
          break;
        }
        DAT_0094e3f0 = *(float *)(&DAT_01f95d64 + DAT_01f95c9c * 0x3c);
        DAT_0094e3b8 = (float)(&DAT_01f95d50)[DAT_01f95c9c * 0xf];
        if (f_100 <= DAT_0094e3f0) {
          if (DAT_0094e3b8 - *(float *)(&DAT_01f95d14 + DAT_01f95c9c * 0x3c) == f_2) {
            ffree(in_ST0);
            fVar6 = (float10)amod(&DAT_0094e3b8,&f_2);
            in_ST0 = extraout_ST1_07;
            if (fVar6 != (float10)f_0) {
              iVar2 = DAT_01f95c9c * 0x3c;
              ffree(extraout_ST1_07);
              fVar6 = (float10)amod(&DAT_0094e3f0,&f_10);
              *(float *)(&DAT_01f95d64 + iVar2) = (float)fVar6;
              in_ST0 = extraout_ST1_08;
            }
          }
          else {
            *(undefined4 *)(puVar3 + -0xe8) = 0;
          }
        }
        else {
          *(undefined4 *)(puVar3 + -0xec) = 0;
        }
        *(undefined4 *)(puVar3 + -0xe4) = 0;
        DAT_01f95c9c = DAT_01f95c9c + 1;
        *(int *)(puVar3 + -0xf4) = *(int *)(puVar3 + -0xf4) + -1;
        iVar4 = *(int *)(puVar3 + -0xf4);
      }
      DAT_01f95c90 = DAT_01f95c9c + -1;
    }
    else {
      *(undefined4 *)(puVar3 + -0xf8) = 0;
      DAT_01f95c90 = iVar2;
    }
    if (DAT_01f95c80 <= DAT_01f95c90) break;
    *(undefined4 *)(puVar3 + -0xe0) = 0;
  } while( true );
  if (DAT_01fb8c74 < 1) {
    iVar2 = DAT_01f95c80 + -2;
    *(int *)(puVar3 + -0xd8) = iVar2;
    DAT_01f95c90 = 2;
    while (0 < iVar2) {
      if ((float)(&DAT_01f95d44)[DAT_01f95c90 * 0xf] == f_3) {
        if (*(float *)(DAT_01f95c90 * 0x3c + 0x1f95d08) == f_14) {
          *(undefined4 *)(puVar3 + -0xd0) = 0;
        }
        else {
          DAT_0094e3e8 = _DAT_0094e3fc * f_7;
          DAT_0094e3f0 = (float)(&DAT_01f95d88)[DAT_01f95c90 * 0xf];
          in_ST0 = (float10)DAT_0094e3f0 - (float10)(float)(&DAT_01f95d10)[DAT_01f95c90 * 0xf];
          if ((float10)DAT_0094e3e8 + (float10)f_0_625 <= in_ST0) {
            (&DAT_01f95d4c)[DAT_01f95c90 * 0xf] = DAT_0094e3f0 - DAT_0094e3e8;
          }
          else {
            *(undefined4 *)(puVar3 + -0xcc) = 0;
          }
        }
      }
      else {
        *(undefined4 *)(puVar3 + -0xd4) = 0;
      }
      *(undefined4 *)(puVar3 + -200) = 0;
      DAT_01f95c90 = DAT_01f95c90 + 1;
      *(int *)(puVar3 + -0xd8) = *(int *)(puVar3 + -0xd8) + -1;
      iVar2 = *(int *)(puVar3 + -0xd8);
    }
  }
  else {
    *(undefined4 *)(puVar3 + -0xdc) = 0;
    iVar2 = DAT_01f95c80 + -1;
    *(int *)(puVar3 + -0x7c) = iVar2;
    DAT_01f95c90 = 2;
    while (0 < iVar2) {
      fVar1 = (float)(&DAT_01f95d44)[DAT_01f95c90 * 0xf];
      *(undefined2 *)(puVar3 + -0x25c) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x25a) = (ushort)*(undefined4 *)(puVar3 + -0x25c) | 0xc00;
      *(int *)(puVar3 + -600) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x25c);
      DAT_01f95cb8 = *(int *)(puVar3 + -600);
      if (DAT_01f95cb8 < 3) {
        *(undefined4 *)(puVar3 + -0x78) = 0;
      }
      else {
        DAT_0094e3bc = (float)(&DAT_01f95d4c)[DAT_01f95c90 * 0xf];
        DAT_0094e3b8 = (float)(&DAT_01f95d10)[DAT_01f95c90 * 0xf];
        DAT_0094e3f0 = (float)(&DAT_01f95d88)[DAT_01f95c90 * 0xf];
        if (DAT_01f95c80 <= DAT_01f95c90) {
          DAT_0094e3f0 = DAT_01e67914;
        }
        if ((DAT_0094e3f0 < DAT_0094e3bc) || (DAT_0094e3b8 == DAT_0094e3bc)) {
          if (DAT_01f95cb8 == 3) {
            *(undefined4 *)(puVar3 + -0x6c) = 0;
            DAT_0094e3e8 = f_6_5;
LAB_0051f35c:
            if (DAT_0094e3f0 - DAT_0094e3bc < DAT_0094e3e8) {
              DAT_0094e3e8 = (DAT_0094e3f0 - DAT_0094e3bc) / f_2;
            }
            DAT_0094e3e8 = DAT_0094e3f0 - _DAT_0094e3fc * DAT_0094e3e8;
            *(undefined4 *)(puVar3 + -0x54) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x70) = 0;
            if (DAT_01f95cb8 == 0xe) {
              DAT_0094e3e8 = DAT_01fbb8b8;
              if (DAT_01f95c90 < DAT_01f95c80) {
                DAT_0094e3e8 = DAT_0094e3f0 - _DAT_0094e3fc * f_2_5;
              }
              *(undefined4 *)(puVar3 + -100) = 0;
            }
            else {
              *(undefined4 *)(puVar3 + -0x68) = 0;
              if (DAT_01f95cb8 == 0x11) {
                if (DAT_01f95c90 < DAT_01f95c80) {
                  *(undefined4 *)(puVar3 + -0x5c) = 0;
                  in_ST0 = (float10)(float)(&DAT_01f95d54)[DAT_01f95c90 * 0xf];
                  DAT_0094e3e8 = (float)((ABS(in_ST0) - (float10)f_1) * (float10)f_2_5 +
                                        (float10)f_4_5);
                  goto LAB_0051f35c;
                }
                DAT_0094e3e8 = _DAT_0094e3fc * f_2 + DAT_0094e3b8;
                *(undefined4 *)(puVar3 + -0x58) = 0;
              }
              else {
                *(undefined4 *)(puVar3 + -0x60) = 0;
                DAT_0094e3e8 = f_1_5;
                if (DAT_01f95c90 == 1) {
                  *(undefined4 *)(puVar3 + -0x50) = 0;
                }
                else {
                  fVar1 = *(float *)(DAT_01f95c90 * 0x3c + 0x1f95d08);
                  *(undefined2 *)(puVar3 + -0x25c) = in_FPUControlWord;
                  *(ushort *)(puVar3 + -0x25a) = (ushort)*(undefined4 *)(puVar3 + -0x25c) | 0xc00;
                  *(int *)(puVar3 + -600) = (int)ROUND(fVar1);
                  in_FPUControlWord = *(undefined2 *)(puVar3 + -0x25c);
                  DAT_01f95cb8 = *(int *)(puVar3 + -600);
                  if (DAT_01f95cb8 == 3) {
                    DAT_0094e3e8 = f_5_5;
                  }
                  if ((DAT_01f95cb8 != 0xe) && (DAT_01f95c80 <= DAT_01f95c90)) {
                    DAT_0094e3b8 = DAT_0094e3f0;
                  }
                }
                DAT_0094e3e8 = _DAT_0094e3fc * DAT_0094e3e8 + DAT_0094e3b8;
              }
            }
          }
          (&DAT_01f95d4c)[DAT_01f95c90 * 0xf] = DAT_0094e3e8;
        }
        else {
          *(undefined4 *)(puVar3 + -0x74) = 0;
        }
      }
      *(undefined4 *)(puVar3 + -0x4c) = 0;
      DAT_01f95c90 = DAT_01f95c90 + 1;
      *(int *)(puVar3 + -0x7c) = *(int *)(puVar3 + -0x7c) + -1;
      iVar2 = *(int *)(puVar3 + -0x7c);
    }
    *(undefined4 *)(puVar3 + -0x48) = 0;
  }
  *(int *)(puVar3 + -0xc4) = DAT_01f95c80;
  DAT_01f95c90 = 1;
  iVar2 = DAT_01f95c80;
  while (0 < iVar2) {
    if (*(float *)(&DAT_01f95d7c + DAT_01f95c90 * 0x3c) < f_0) {
      *(float *)(&DAT_0204929c + DAT_01f95c90 * 4) = f_0;
      *(undefined4 *)(puVar3 + -0xbc) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0xc0) = 0;
      *(undefined4 *)(&DAT_0204929c + DAT_01f95c90 * 4) =
           *(undefined4 *)(&DAT_01f95d5c + DAT_01f95c90 * 0x3c);
    }
    *(undefined4 *)(puVar3 + -0xb8) = 0;
    DAT_01f95c90 = DAT_01f95c90 + 1;
    *(int *)(puVar3 + -0xc4) = *(int *)(puVar3 + -0xc4) + -1;
    iVar2 = *(int *)(puVar3 + -0xc4);
  }
  ffree(in_ST0);
  Var7 = thunk_FUN_0051c824(&DAT_007679d8,&DAT_01f95c80);
  (&DAT_01f98f7c)[DAT_0094e3d0] = DAT_01fbb8b8;
  DAT_01fb8c78 = DAT_0094e3d0;
  *(undefined4 *)(puVar3 + -0xb4) = 0;
  ffree(Var7);
  return;
}


