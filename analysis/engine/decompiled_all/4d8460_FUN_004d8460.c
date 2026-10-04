// FUN_004d8460 @ 004d8460 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d8460(void)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  float10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  float10 extraout_ST1_05;
  int local_a0;
  
  puVar4 = &stack0xfffffffc;
  DAT_01f95c84 = 0;
  ffree(in_ST0);
  fVar5 = (float10)thunk_FUN_00547ae0(&DAT_008a05a4,&DAT_008a05a0,&DAT_01f95c84);
  *(undefined4 *)(&DAT_01f995bc + DAT_01fb8c78 * 4) =
       *(undefined4 *)(&DAT_01f995b8 + DAT_01fb8c78 * 4);
  DAT_0078cd38 = 0;
  DAT_0078cd34 = 1;
LAB_004d84c3:
  local_a0 = (DAT_01fb8cc0 - DAT_0078cd34) + 1;
  DAT_01f95c8c = DAT_0078cd34;
  if (0 < local_a0) {
    do {
      fVar5 = (float10)(float)(&DAT_01fb8cc0)[DAT_01f95c8c];
      if ((float10)f_1000 <= ABS(fVar5)) {
        fVar5 = (float10)(float)(&DAT_01fb8cc0)[DAT_01f95c8c];
        if (ABS(fVar5) < (float10)f_2000) goto LAB_004d86b3;
      }
      else {
        DAT_01f95c80 = (float)(&DAT_01fb8cc0)[DAT_01f95c8c];
        DAT_008a059c = (int)ROUND(DAT_01f95c80);
        P3 = DAT_01f95c80 - (float)DAT_008a059c;
        DAT_0078cd44 = (float)(&DAT_01f95d4c)[*(int *)(&DAT_01f995bc + DAT_008a059c * 4) * 0xf];
        if (DAT_008a059c < 1) {
          DAT_0078cd44 = DAT_008a05a4;
        }
        if (DAT_01fb8c78 <= DAT_008a059c) {
          DAT_0078cd44 = DAT_008a05a0;
        }
        P50 = (float)(&DAT_01f95d4c)[(&DAT_01f995c0)[DAT_008a059c] * 0xf];
        if (DAT_01fb8c78 + -1 <= DAT_008a059c) {
          P50 = DAT_008a05a0;
        }
        if (P3 != f_0) {
          DAT_0078cd44 = (P50 - DAT_0078cd44) * P3 + DAT_0078cd44;
        }
        DAT_0078cd38 = DAT_0078cd38 + 1;
        *(float *)(&DAT_01cadd3c + DAT_0078cd38 * 4) = DAT_0078cd44;
      }
      DAT_01f95c8c = DAT_01f95c8c + 1;
      local_a0 = local_a0 + -1;
      if (local_a0 < 1) break;
    } while( true );
  }
  DAT_008a0598 = 0;
  DAT_01fb8c6c = 0;
  DAT_01f95c88 = DAT_01fb8c78 + -1;
  DAT_01f95c8c = 0;
LAB_004d86f8:
  if (DAT_01fb8cc0 <= (int)DAT_01f95c8c) {
    *(undefined4 *)(puVar4 + -0x88) = 0;
LAB_004d940a:
    ffree(fVar5);
    return;
  }
  iVar3 = DAT_01f95c8c + 1;
  DAT_01f95c90 = 0;
  DAT_01f95c80 = (float)(&DAT_01fb8cc0)[iVar3];
  while( true ) {
    *(undefined2 *)(puVar4 + -0xc4) = in_FPUControlWord;
    *(ushort *)(puVar4 + -0xc2) = (ushort)*(undefined4 *)(puVar4 + -0xc4) | 0xc00;
    *(int *)(puVar4 + -0xc0) = (int)ROUND(DAT_01f95c80);
    in_FPUControlWord = *(undefined2 *)(puVar4 + -0xc4);
    DAT_008a05a8 = *(int *)(puVar4 + -0xc0);
    bVar2 = DAT_008a05a8 < 1;
    if (bVar2) {
      DAT_008a05a8 = -DAT_008a05a8;
    }
    else {
      *(undefined4 *)(puVar4 + -0x84) = 0;
    }
    DAT_0078cd30 = (uint)bVar2;
    if (0x270e < DAT_008a05a8) {
      DAT_0078cd34 = DAT_0078cd30;
      DAT_01f95c94 = DAT_008a05a8 / 10000;
      if ((DAT_008a05a8 % 10000 != 0) ||
         (DAT_01f95c98 = DAT_01f95c94, *(int *)(&DAT_01aada3c + iVar3 * 4) != 0)) {
        DAT_01f95c98 = -DAT_01f95c94;
      }
      ffree(fVar5);
      DAT_01f95c8c = iVar3;
      fVar5 = (float10)thunk_FUN_0054c419(&P7,&DAT_007657e8);
      P2 = DAT_01fb8c60;
      *(undefined4 *)(puVar4 + -0x7c) = 0;
      goto LAB_004d86f8;
    }
    *(undefined4 *)(puVar4 + -0x80) = 0;
    DAT_0078cd3c = DAT_008a05a8;
    if (DAT_008a05a8 < 1000) {
      *(undefined4 *)(puVar4 + -0x78) = 0;
      DAT_01f95c8c = iVar3;
      goto LAB_004d8898;
    }
    DAT_0078cd3c = DAT_008a05a8 + -1000;
    if ((DAT_01f95c94 < 0x5f) || (99 < DAT_01f95c94)) break;
    DAT_01f95c80 = DAT_01f95c80 - f_1000;
    *(undefined4 *)(puVar4 + -0x70) = 0;
  }
  *(undefined4 *)(puVar4 + -0x74) = 0;
  DAT_01f95c8c = DAT_01f95c8c + 2;
  if (DAT_01fb8cc0 < (int)DAT_01f95c8c) {
LAB_004d93e4:
    DAT_01f95c8c = 0x4e;
    ffree(fVar5);
    fVar5 = (float10)thunk_FUN_005259e5(&DAT_01f95c8c);
    *(undefined4 *)(puVar4 + -0x68) = 0;
    goto LAB_004d940a;
  }
  *(undefined4 *)(puVar4 + -0x6c) = 0;
  fVar1 = (float)(&DAT_01fb8cc0)[DAT_01f95c8c];
  *(undefined2 *)(puVar4 + -0xc4) = in_FPUControlWord;
  *(ushort *)(puVar4 + -0xc2) = (ushort)*(undefined4 *)(puVar4 + -0xc4) | 0xc00;
  *(int *)(puVar4 + -0xc0) = (int)ROUND(fVar1);
  in_FPUControlWord = *(undefined2 *)(puVar4 + -0xc4);
  DAT_01f95c90 = *(int *)(puVar4 + -0xc0);
LAB_004d8898:
  if (DAT_01f95c80 < f_1000) {
    ffree(fVar5);
    fVar5 = (float10)anint(puVar4,0x4d88c0);
    *(int *)(puVar4 + -0xc0) = (int)ROUND(fVar5);
    DAT_0078cd3c = *(int *)(puVar4 + -0xc0);
    fVar5 = extraout_ST1;
  }
  if (DAT_01f95c88 < DAT_0078cd3c) {
    DAT_0078cd3c = DAT_01f95c88;
  }
  DAT_008a059c = DAT_0078cd3c;
  if (DAT_0078cd3c < 1) {
    DAT_0078cd3c = 1;
  }
  DAT_0078cd30 = *(uint *)(&DAT_01f995bc + DAT_0078cd3c * 4);
  if ((DAT_01f95c94 < 0x2d) && (DAT_0078cd34 == 0)) {
    *(undefined4 *)(puVar4 + -100) = 0;
LAB_004d8db6:
    ffree(fVar5);
    DAT_0078cd38 = FUN_004d9413(&DAT_01f95c94,&DAT_01f95c98);
    fVar5 = extraout_ST0;
    if (DAT_01f95c90 == 0) {
      DAT_008a0598 = DAT_008a0598 + 1;
    }
    while( true ) {
      DAT_01f95c80 = f_0;
      if (DAT_0078cd38 != 0) {
        ffree(fVar5);
        fVar5 = (float10)FUN_004d9475(&DAT_0078cd30,&DAT_01f95c94,&DAT_01f95c80,&DAT_01f95c98);
      }
      *(float *)(&DAT_01f95d6c + DAT_0078cd30 * 0x3c) = (float)DAT_01f95c98 + DAT_01f95c80;
      if (DAT_01f95c90 <= DAT_0078cd3c) break;
      DAT_0078cd3c = DAT_0078cd3c + 1;
      DAT_0078cd30 = *(uint *)(&DAT_01f995bc + DAT_0078cd3c * 4);
      *(undefined4 *)(puVar4 + -4) = 0;
    }
    *(undefined4 *)(puVar4 + -8) = 0;
    goto LAB_004d86f8;
  }
LAB_004d8944:
  if (DAT_01f95c90 == 0) {
    DAT_008a0598 = DAT_008a0598 + 1;
    DAT_0078cd44 = *(float *)(&DAT_01cadd3c + DAT_008a0598 * 4);
  }
  else {
    DAT_0078cd44 = (float)(&DAT_01f95d4c)[*(int *)(&DAT_01f995bc + DAT_0078cd3c * 4) * 0xf];
  }
  if (DAT_0078cd34 == 0) {
    if (DAT_01f95c94 < 0x25) {
      *(undefined4 *)(puVar4 + -0x5c) = 0;
      goto LAB_004d8db6;
    }
    if (DAT_01f95c94 != 99) goto LAB_004d89ee;
    *(undefined4 *)(puVar4 + -0x58) = 0;
    P6 = DAT_0078cd4c + DAT_0078cd44;
    DAT_01f95c90 = 0;
    DAT_01f95c94 = DAT_0078cd50;
    *(undefined4 *)(puVar4 + -0xc) = 0;
  }
  else {
    *(undefined4 *)(puVar4 + -0x60) = 0;
LAB_004d89ee:
    P3 = DAT_0078cd44;
    if ((DAT_01f95c94 < 0x47) || (DAT_0078cd34 != 0)) {
      P1 = f_9;
      DAT_01f95c80 = f_0;
      DAT_0078cd38 = DAT_01f95c98;
      ffree(fVar5);
      fVar5 = (float10)FUN_004d9475(&DAT_0078cd30,&DAT_01f95c94,&DAT_01f95c80,&DAT_01f95c98);
      P4 = f_m2;
      if (DAT_01f95c98 < 0) {
        P4 = f_14;
      }
      DAT_01f95c98 = DAT_0078cd38;
      P4 = DAT_01f95c80 + P4;
      P5 = (float)DAT_01f95c94;
      if (DAT_0078cd34 == 0) {
        P15 = DAT_0078b488;
      }
      P6 = f_1;
    }
    else {
      *(undefined4 *)(puVar4 + -0x54) = 0;
      if (0x5e < DAT_01f95c94) {
        *(undefined4 *)(puVar4 + -0x44) = 0;
        if (DAT_01fb8cc0 == DAT_01f95c8c) {
          *(undefined4 *)(puVar4 + -0x34) = 0;
          goto LAB_004d93e4;
        }
        fVar1 = (float)(&DAT_01fb8cc4)[DAT_01f95c8c];
        *(undefined2 *)(puVar4 + -0xc4) = in_FPUControlWord;
        *(ushort *)(puVar4 + -0xc2) = (ushort)*(undefined4 *)(puVar4 + -0xc4) | 0xc00;
        *(int *)(puVar4 + -0xc0) = (int)ROUND(fVar1);
        in_FPUControlWord = *(undefined2 *)(puVar4 + -0xc4);
        DAT_0078cd48 = *(int *)(puVar4 + -0xc0);
        if (DAT_01f95c88 < DAT_0078cd48) {
          DAT_0078cd48 = DAT_01f95c88;
        }
        DAT_0078cd38 = DAT_0078cd3c;
        DAT_0078cd50 = DAT_01f95c94;
        if ((DAT_01f95c94 < 0x61) || (0x77 < DAT_01f95c94)) {
          *(undefined4 *)(puVar4 + -0x30) = 0;
          *(undefined2 *)(puVar4 + -0xc4) = in_FPUControlWord;
          *(ushort *)(puVar4 + -0xc2) = (ushort)*(undefined4 *)(puVar4 + -0xc4) | 0xc00;
          *(int *)(puVar4 + -0xc0) = (int)ROUND(DAT_01fb8c60 + f_1);
          in_FPUControlWord = *(undefined2 *)(puVar4 + -0xc4);
          DAT_0078cd4c = (float)(&STAFF_STEP0)[*(int *)(puVar4 + -0xc0)] / f_6;
          P1 = f_7;
          P5 = f_1;
          DAT_0078cd54 = f_1_5;
          if (DAT_01f95c94 != 0x5f) {
            P4 = f_12_5;
            if (DAT_01f95c94 < 100) {
              *(undefined4 *)(puVar4 + -0x20) = 0;
              P7 = f_8;
              P12 = f_m1;
            }
            else {
              P7 = f_0;
              *(int *)(puVar4 + -0xc0) = DAT_01f95c94 % 10;
              P8 = (float)*(int *)(puVar4 + -0xc0);
              *(undefined4 *)(puVar4 + -0x1c) = 0;
            }
            goto LAB_004d91fa;
          }
          *(undefined4 *)(puVar4 + -0x24) = 0;
          P7 = f_m8;
          P12 = f_1;
          P4 = f_m1_5;
LAB_004d906e:
          iVar3 = (DAT_0078cd48 - DAT_0078cd3c) + 1;
          *(int *)(puVar4 + -0x14) = iVar3;
          _DAT_008a0594 = f_99;
          while (0 < iVar3) {
            DAT_008a059c = *(int *)(&DAT_01f995bc + DAT_0078cd38 * 4);
            ffree(fVar5);
            fVar5 = (float10)amod(&DAT_01f95d50 + DAT_008a059c * 0xf,&DAT_00765850);
            DAT_0078cd58 = (float)fVar5;
            ffree(extraout_ST1_02);
            fVar5 = (float10)amod(&DAT_01f95d54 + DAT_008a059c * 0xf,&DAT_00765850);
            if ((float10)f_20 <= fVar5) {
              DAT_0078cd58 = DAT_0078cd58 - f_7;
            }
            if (DAT_0078cd58 < _DAT_008a0594) {
              _DAT_008a0594 = DAT_0078cd58;
            }
            DAT_0078cd38 = DAT_0078cd38 + 1;
            *(int *)(puVar4 + -0x14) = *(int *)(puVar4 + -0x14) + -1;
            fVar5 = extraout_ST1_03;
            iVar3 = *(int *)(puVar4 + -0x14);
          }
          if (_DAT_008a0594 < f_4) {
            P4 = (_DAT_008a0594 - f_3_5) - DAT_0078cd54;
          }
        }
        else {
          DAT_0078cd4c = f_0;
          P1 = f_4;
          P4 = f_0;
          DAT_0078cd54 = f_0;
          P5 = f_999;
          if (DAT_01f95c94 == 0x62) {
            P7 = f_m1;
          }
          if (0 < DAT_01f95c98) {
            *(undefined4 *)(puVar4 + -0x2c) = 0;
            goto LAB_004d906e;
          }
          P4 = f_14;
          *(undefined4 *)(puVar4 + -0x28) = 0;
LAB_004d91fa:
          _DAT_008a0594 = f_m99;
          for (iVar3 = (DAT_0078cd48 - DAT_0078cd3c) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
            DAT_008a059c = *(int *)(&DAT_01f995bc + DAT_0078cd38 * 4);
            ffree(fVar5);
            fVar5 = (float10)amod(&DAT_01f95d50 + DAT_008a059c * 0xf,&DAT_00765850);
            DAT_0078cd58 = (float)fVar5;
            ffree(extraout_ST1_04);
            fVar5 = (float10)amod(&DAT_01f95d54 + DAT_008a059c * 0xf,&DAT_00765850);
            if (fVar5 < (float10)f_20) {
              DAT_0078cd58 = DAT_0078cd58 + f_7;
            }
            if (_DAT_008a0594 < DAT_0078cd58) {
              _DAT_008a0594 = DAT_0078cd58;
            }
            DAT_0078cd38 = DAT_0078cd38 + 1;
            fVar5 = extraout_ST1_05;
          }
          if (f_10 < _DAT_008a0594) {
            P4 = (_DAT_008a0594 + f_3_5) - DAT_0078cd54;
          }
          *(undefined4 *)(puVar4 + -0x18) = 0;
        }
        DAT_01f95c94 = 99;
        *(undefined4 *)(puVar4 + -0x10) = 0;
        goto LAB_004d86f8;
      }
      if (DAT_01fb8c6c == 0) {
        DAT_01fb8c6c = DAT_01fb8c80;
      }
      P1 = f_6;
      *(int *)(puVar4 + -0xc0) = DAT_01f95c94 + -0x50;
      P10 = (float)*(int *)(puVar4 + -0xc0);
      P5 = f_0;
      P6 = f_0;
      P14 = f_0;
      ffree(fVar5);
      fVar5 = (float10)amod(&DAT_01f95d54 + DAT_0078cd30 * 0xf,&DAT_00765850);
      P7 = (float)-fVar5;
      if (((float)(&DAT_01f95d58)[DAT_0078cd30 * 0xf] < f_2) ||
         (f_3 < (float)(&DAT_01f95d58)[DAT_0078cd30 * 0xf])) {
        *(undefined4 *)(puVar4 + -0x40) = 0;
      }
      else {
        P14 = f_1_6;
        if (f_m10 <= P7) {
          P14 = f_m1_23;
        }
      }
      DAT_01f95c80 = f_2;
      if (0x5b < DAT_01f95c94) {
        DAT_01f95c80 = f_1;
      }
      DAT_01f95c80 = DAT_01f95c80 - (float)(&DAT_01f95d60)[DAT_0078cd30 * 0xf];
      fVar1 = *(float *)(&DAT_01f95d64 + DAT_0078cd30 * 0x3c);
      *(undefined2 *)(puVar4 + -0xc4) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0xc2) = (ushort)*(undefined4 *)(puVar4 + -0xc4) | 0xc00;
      *(int *)(puVar4 + -0xc0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0xc4);
      if (*(int *)(puVar4 + -0xc0) % 10 == 0) {
        *(undefined4 *)(puVar4 + -0x3c) = 0;
      }
      else {
        if (f_m20 < P7) {
          DAT_01f95c80 = DAT_01f95c80 + f_1;
        }
        (&DAT_01f95d60)[DAT_0078cd30 * 0xf] = (float)(&DAT_01f95d60)[DAT_0078cd30 * 0xf] + f_0_5;
      }
      fVar5 = extraout_ST1_00;
      if (f_m20 < P7) {
        fVar5 = (float10)DAT_01f95c80;
        DAT_01f95c80 = (float)-fVar5;
      }
      ffree(fVar5);
      fVar5 = (float10)amod(&DAT_01f95d50 + DAT_0078cd30 * 0xf,&DAT_00765850);
      P4 = (float)(fVar5 + (float10)DAT_01f95c80);
      *(undefined4 *)(puVar4 + -0x38) = 0;
      fVar5 = extraout_ST1_01;
    }
  }
  DAT_01fb8c80 = DAT_01fb8c80 + 1;
  if (200 < DAT_01fb8c80) {
    *(undefined4 *)(puVar4 + -0x50) = 0;
    goto LAB_004d940a;
  }
  iVar3 = 0xf;
  DAT_0078cd38 = 1;
  do {
    (&DAT_01f95d40)[DAT_0078cd38 + DAT_01fb8c80 * 0xf] = *(undefined4 *)(&P0 + DAT_0078cd38 * 4);
    DAT_0078cd38 = DAT_0078cd38 + 1;
    iVar3 = iVar3 + -1;
  } while (0 < iVar3);
  if (DAT_01f95c90 <= DAT_0078cd3c) goto LAB_004d932c;
  DAT_0078cd3c = DAT_0078cd3c + 1;
  DAT_0078cd30 = *(uint *)(&DAT_01f995bc + DAT_0078cd3c * 4);
  *(undefined4 *)(puVar4 + -0x48) = 0;
  goto LAB_004d8944;
LAB_004d86b3:
  DAT_0078cd34 = DAT_01f95c8c + 2;
  goto LAB_004d84c3;
LAB_004d932c:
  *(undefined4 *)(puVar4 + -0x4c) = 0;
  goto LAB_004d86f8;
}


