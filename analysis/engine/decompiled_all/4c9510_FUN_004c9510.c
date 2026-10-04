// FUN_004c9510 @ 004c9510 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c9510(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined2 in_FPUControlWord;
  
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  DAT_01add2e0 = 0;
  DAT_01add2ec = 0;
  LOAD_I = 1;
  iVar2 = ITEM_I;
  while ((0 < iVar2 && (load_item_header(), LOAD_STAFF <= *param_2))) {
    if (((LOAD_P3 <= DAT_01fbb8b8 + f_0_05) &&
        ((*param_1 <= LOAD_STAFF && (0x10 < LOAD_CODE || (LOAD_CODE == 0xe || LOAD_CODE < 4))))) &&
       ((DAT_01add2e0 == 0 ||
        ((LOAD_STAFF != (&DAT_01abaffc)[DAT_01add2e0] ||
         (LOAD_P3 != (float)(&DAT_01ab61dc)[DAT_01add2e0])))))) {
      DAT_01add2e0 = DAT_01add2e0 + 1;
      if (DAT_01add2ec != LOAD_STAFF) {
        if ((DAT_01add2ec != 0) &&
           (f_0_01 <= ABS(*(float *)(DAT_01add2e0 * 4 + 0x1ab61d8) - DAT_01fbb8b8))) {
          (&DAT_01abaffc)[DAT_01add2e0] = DAT_01add2ec;
          (&DAT_01ac4c3c)[DAT_01add2e0] = 0xfffffff2;
          (&DAT_01ab61dc)[DAT_01add2e0] = DAT_01fbb8b8;
          DAT_01add2e0 = DAT_01add2e0 + 1;
        }
        DAT_01add2ec = LOAD_STAFF;
        (&DAT_01abaffc)[DAT_01add2e0] = LOAD_STAFF;
        (&DAT_01ac4c3c)[DAT_01add2e0] = 0xe;
        (&DAT_01ab61dc)[DAT_01add2e0] = f_0;
        if (2 < DAT_01add2e0) {
          (&DAT_01ab61dc)[DAT_01add2e0] = DAT_01ab61e0;
        }
      }
      (&DAT_01ab61dc)[DAT_01add2e0] = LOAD_P3;
      (&DAT_01abaffc)[DAT_01add2e0] = LOAD_STAFF;
      (&DAT_01abfe1c)[DAT_01add2e0] = LOAD_W + 3;
      (&DAT_01ac4c3c)[DAT_01add2e0] = LOAD_CODE;
      if ((LOAD_CODE == 0xe) && (3 < LOAD_LEN)) {
        DAT_0089fcc8 = (int)ROUND((float)(&ITEM_P4)[LOAD_W] - f_1);
        DAT_01be180c = LOAD_STAFF + 1;
        for (iVar3 = ((DAT_0089fcc8 + LOAD_STAFF) - DAT_01be180c) + 1; 0 < iVar3; iVar3 = iVar3 + -1
            ) {
          DAT_01add2e0 = DAT_01add2e0 + 1;
          (&DAT_01ab61dc)[DAT_01add2e0] = LOAD_P3;
          (&DAT_01abaffc)[DAT_01add2e0] = DAT_01be180c;
          (&DAT_01abfe1c)[DAT_01add2e0] = LOAD_W + 3;
          (&DAT_01ac4c3c)[DAT_01add2e0] = LOAD_CODE;
          DAT_01be180c = DAT_01be180c + 1;
        }
      }
    }
    LOAD_I = LOAD_I + 1;
    iVar2 = iVar2 + -1;
  }
  if (f_0_01 <= ABS((float)(&DAT_01ab61dc)[DAT_01add2e0] - DAT_01fbb8b8)) {
    DAT_01add2e0 = DAT_01add2e0 + 1;
    (&DAT_01abaffc)[DAT_01add2e0] = DAT_01add2ec;
    (&DAT_01ac4c3c)[DAT_01add2e0] = 0xfffffff2;
    (&DAT_01ab61dc)[DAT_01add2e0] = DAT_01fbb8b8;
  }
  LOAD_I = 0;
  while( true ) {
    DAT_01be180c = 0;
    DAT_0089fcc8 = 1;
    DAT_01be1818 = f_990000;
    for (iVar2 = DAT_01add2e0; 0 < iVar2; iVar2 = iVar2 + -1) {
      iVar3 = DAT_01be180c;
      fVar1 = DAT_01be1818;
      if ((-1 < (int)(&DAT_01abfe1c)[DAT_0089fcc8]) &&
         (DAT_01aae48c = (float)((&DAT_01abaffc)[DAT_0089fcc8] * 1000) +
                         (float)(&DAT_01ab61dc)[DAT_0089fcc8], iVar3 = DAT_0089fcc8,
         fVar1 = DAT_01aae48c, DAT_01be1818 <= DAT_01aae48c)) {
        iVar3 = DAT_01be180c;
        fVar1 = DAT_01be1818;
      }
      DAT_01be1818 = fVar1;
      DAT_01be180c = iVar3;
      DAT_0089fcc8 = DAT_0089fcc8 + 1;
    }
    if (DAT_01be180c == 0) break;
    LOAD_I = LOAD_I + 1;
    *(undefined4 *)(LOAD_I * 4 + 0x1ac9a5c) = (&DAT_01ab61dc)[DAT_01be180c];
    *(undefined4 *)(LOAD_I * 4 + 0x1ace87c) = (&DAT_01abaffc)[DAT_01be180c];
    *(undefined4 *)(LOAD_I * 4 + 0x1ad84bc) = (&DAT_01ac4c3c)[DAT_01be180c];
    *(undefined4 *)(LOAD_I * 4 + 0x1ad369c) = (&DAT_01abfe1c)[DAT_01be180c];
    (&DAT_01abfe1c)[DAT_01be180c] = 0xffffffff;
  }
  thunk_FUN_0054c590(&DAT_01ac9a60,&DAT_01ab61e0,&LOAD_I);
  thunk_FUN_0054c4c6(&DAT_01ace880,&DAT_01abb000,&LOAD_I);
  thunk_FUN_0054c4c6(&DAT_01ad84c0,&DAT_01ac4c40,&LOAD_I);
  thunk_FUN_0054c4c6(&DAT_01ad36a0,&DAT_01abfe20,&LOAD_I);
  DAT_01add2e0 = LOAD_I;
  (&DAT_01abb000)[LOAD_I] = 9999;
  LOAD_I = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    load_item_header();
    if (((LOAD_P3 <= DAT_01fbb8b8 + f_0_05) &&
        (((((LOAD_CODE == 0x12 || (LOAD_CODE == 0x11)) || (LOAD_CODE < 4)) || (LOAD_CODE == 0xe)) &&
         ((DAT_01fbb8b8 + f_0_1 < LOAD_P3 && (*param_1 <= LOAD_STAFF)))))) &&
       (LOAD_STAFF <= *param_2)) goto LAB_004caff3;
    LOAD_I = LOAD_I + 1;
  }
  LOAD_I = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    load_item_header();
    if (((LOAD_P3 <= DAT_01fbb8b8 + f_0_05) && (LOAD_STAFF <= *param_2)) &&
       ((LOAD_CODE == 8 &&
        (((*param_1 <= LOAD_STAFF && (5 < LOAD_LEN)) && (DAT_01fbb8b8 < (float)(&ITEM_P6)[LOAD_W])))
        ))) {
      (&ITEM_P6)[LOAD_W] = DAT_01fbb8b8;
    }
    LOAD_I = LOAD_I + 1;
  }
  thunk_FUN_0054cd13(&DAT_01e99980,&DAT_00764ff4);
  _DAT_0089fcc4 = f_m14;
  DAT_0078b4ec = 1;
  DAT_01be1804 = 1;
  DAT_0089fcc0 = f_9999;
  DAT_0089fcbc = DAT_01fbb8b8;
  DAT_0089fcc8 = *param_1 + -1;
  DAT_01be1800 = 1;
LAB_004c9e0b:
  do {
    while( true ) {
      if (DAT_0089fcc8 == **(int **)(puVar4 + 0xc)) {
        *(undefined4 *)(puVar4 + -0x120) = 0;
        *(int *)(&DAT_01e9d1b8 + DAT_0089fcc8 * 4) = DAT_01be1804;
        thunk_FUN_004cc470(&DAT_01add2e4,*(undefined4 *)(puVar4 + 8),&DAT_0089fcc0,&DAT_0089fcbc);
        thunk_FUN_004c8290(*(undefined4 *)(puVar4 + 8),&DAT_0089fcc8,&DAT_01add2e4);
        if (DAT_0078b4ec == 0) {
          thunk_FUN_004c5ad8(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
        }
        DAT_0078b4ec = 1;
        **(float **)(puVar4 + 0x10) = DAT_0089fcc0;
        **(float **)(puVar4 + 0x14) = DAT_0089fcbc;
        FUN_004cb010(*(undefined4 *)(puVar4 + 8),*(undefined4 *)(puVar4 + 0xc));
        return;
      }
      DAT_0089fcc8 = DAT_0089fcc8 + 1;
      _DAT_0089fcb8 = (float)DAT_0089fcc8;
      DAT_01be1808 = -1;
      thunk_FUN_00534c40(&DAT_01be1800,&DAT_0089fcb8,&DAT_01be1808,&DAT_01e9cd08,&DAT_01e9bfc8,
                         &DAT_01be1810);
      *(int *)(&DAT_01e9d1b4 + DAT_0089fcc8 * 4) = DAT_01be1804;
      if (DAT_0089fcb4 == 0) {
        FUN_005f33c9(puVar4,0x4c9eba);
        FUN_005f34d1(puVar4,0x4c9ed5);
        thunk_FUN_0058c2c9(&DAT_009ae2bc,0x200,&DAT_00764fc0,&DAT_00764fc4,"(1i3)",5,&DAT_0089fcc8);
        thunk_FUN_0058c248(&DAT_009ae2bc,0x200,&DAT_00764fb0,&DAT_00764fb4,"(1f6.3)",7,&DAT_01be1810
                          );
        if (DAT_01fbb8a4 == 99) {
          FUN_005f33c9(puVar4,0x4c9f70);
        }
        thunk_FUN_0054946a(&DAT_009ae2bc,0x200);
        if (DAT_01fbb8a4 == 99) {
          *(undefined4 *)(puVar4 + -0x118) = 0;
          return;
        }
      }
      else {
        *(undefined4 *)(puVar4 + -0x11c) = 0;
      }
      if (DAT_01be1810 == f_0) break;
      *(undefined4 *)(puVar4 + -0x114) = 0;
      *(int *)(puVar4 + -0x108) = DAT_01be1808;
      DAT_01add2e0 = 1;
      iVar2 = DAT_01be1808;
      while (0 < iVar2) {
        if ((float)(&DAT_01e9bfc4)[DAT_01add2e0] == f_m140) {
          (&DAT_01e9bfc4)[DAT_01add2e0] = f_m14;
        }
        DAT_01add2e0 = DAT_01add2e0 + 1;
        *(int *)(puVar4 + -0x108) = *(int *)(puVar4 + -0x108) + -1;
        iVar2 = *(int *)(puVar4 + -0x108);
      }
      fVar1 = (float)(&DAT_01e9bfc4)[DAT_01be1808];
      *(undefined2 *)(puVar4 + -0x1bc) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0x1ba) = (ushort)*(undefined4 *)(puVar4 + -0x1bc) | 0xc00;
      *(int *)(puVar4 + -0x1b8) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0x1bc);
      DAT_01add2e0 = *(int *)(puVar4 + -0x1b8);
      if ((DAT_01add2e0 == -0xe) || (DAT_01add2e0 == -0x8c)) {
        if (DAT_01add2e0 == -0x8c) {
          (&DAT_01e9bfc4)[DAT_01be1808] = f_m14;
        }
        *(undefined4 *)(puVar4 + -0x100) = 0;
      }
      else {
        *(undefined4 *)(puVar4 + -0x104) = 0;
        if (DAT_01add2e0 < 0) {
          *(int *)(puVar4 + -0xf8) = ITEM_I;
          LOAD_I = 1;
          iVar2 = ITEM_I;
          while (0 < iVar2) {
            load_item_header();
            if ((LOAD_CODE == 8) && (LOAD_STAFF == **(int **)(puVar4 + 8))) {
              if (5 < LOAD_LEN) {
                DAT_0089fcbc = (float)(&ITEM_P6)[LOAD_W];
              }
              if (DAT_0089fcbc != f_0) {
                *(undefined4 *)(puVar4 + -0xec) = 0;
                goto LAB_004ca175;
              }
              *(undefined4 *)(puVar4 + -0xf0) = 0;
              break;
            }
            *(undefined4 *)(puVar4 + -0xf4) = 0;
            *(undefined4 *)(puVar4 + -0xe8) = 0;
            LOAD_I = LOAD_I + 1;
            *(int *)(puVar4 + -0xf8) = *(int *)(puVar4 + -0xf8) + -1;
            iVar2 = *(int *)(puVar4 + -0xf8);
          }
          DAT_0089fcbc = DAT_01fbb8b8;
        }
        else {
          *(undefined4 *)(puVar4 + -0xfc) = 0;
        }
LAB_004ca175:
        DAT_01be1808 = DAT_01be1808 + 1;
        (&DAT_01e9bfc4)[DAT_01be1808] = f_m14;
        (&DAT_01e9cd04)[DAT_01be1808] = DAT_0089fcbc;
      }
      DAT_01add2e0 = 1;
      while ((float)(&DAT_01e9cd04)[DAT_01add2e0] < f_0) {
        DAT_01add2e0 = DAT_01add2e0 + 1;
        if (DAT_01be1808 <= DAT_01add2e0) {
          *(undefined4 *)(puVar4 + -0xe0) = 0;
          goto LAB_004cadbb;
        }
        DAT_01be1808 = DAT_01be1808 + -1;
        *(undefined4 *)(puVar4 + -0xdc) = 0;
      }
      *(undefined4 *)(puVar4 + -0xe4) = 0;
      DAT_01be180c = 0;
      DAT_01aae494 = 0;
      *(int *)(puVar4 + -0xd8) = DAT_01be1808;
      DAT_01aae49c = 1;
      while (0 < DAT_01be1808) {
        DAT_01aae48c = (float)(&DAT_01e9bfc4)[DAT_01aae49c];
        if (f_0 < DAT_01aae48c) {
          *(undefined4 *)(puVar4 + -0xd4) = 0;
          DAT_01aae48c = DAT_01aae48c * f_4;
          goto LAB_004ca31d;
        }
        if (DAT_01aae48c == f_m14) {
          *(undefined4 *)(puVar4 + -0xd0) = 0;
LAB_004ca328:
          DAT_01be180c = DAT_01be180c + 1;
          (&DAT_01e9bfc4)[DAT_01be180c] = DAT_01aae48c;
          (&DAT_01e9cd04)[DAT_01be180c] = (&DAT_01e9cd04)[DAT_01aae49c];
        }
        else {
          if (DAT_01aae48c != f_m3) {
            *(undefined4 *)(puVar4 + -0xcc) = 0;
LAB_004ca31d:
            DAT_01aae494 = 1;
            goto LAB_004ca328;
          }
          if (DAT_01aae494 == 0) {
            *(undefined4 *)(puVar4 + -0xc4) = 0;
            DAT_01aae48c = f_m15;
            goto LAB_004ca31d;
          }
          *(undefined4 *)(puVar4 + -200) = 0;
        }
        *(undefined4 *)(puVar4 + -0xc0) = 0;
        DAT_01aae49c = DAT_01aae49c + 1;
        *(int *)(puVar4 + -0xd8) = *(int *)(puVar4 + -0xd8) + -1;
        DAT_01be1808 = *(int *)(puVar4 + -0xd8);
      }
      iVar2 = 0x97 - (DAT_01be180c + 1);
      *(int *)(puVar4 + -0xbc) = iVar2;
      DAT_01be1808 = DAT_01be180c;
      DAT_01be180c = DAT_01be180c + 1;
      while (0 < iVar2) {
        (&DAT_01e9bfc4)[DAT_01be180c] = f_0;
        DAT_01be180c = DAT_01be180c + 1;
        *(int *)(puVar4 + -0xbc) = *(int *)(puVar4 + -0xbc) + -1;
        iVar2 = *(int *)(puVar4 + -0xbc);
      }
      DAT_01be180c = DAT_01be1808 * 2 + 2;
      *(int *)(puVar4 + -0x1c0) = DAT_01be1808 + 1;
      thunk_FUN_0054c590(&DAT_01e9bfc4 + DAT_01add2e0,&DAT_01e9f4f4 + DAT_01be1804 * 4,
                         puVar4 + -0x1c0);
      thunk_FUN_0054c590(&DAT_01e9cd04 + DAT_01add2e0,&DAT_01e9d5b4 + DAT_01be1804 * 4,&DAT_01be1808
                        );
      DAT_01be1804 = DAT_01be1808 + DAT_01be1804;
      if (**(int **)(puVar4 + 8) < DAT_0089fcc8) {
        *(undefined4 *)(puVar4 + -0xb8) = 0;
        if ((float)(&DAT_01e9cd04)[DAT_01add2e0] < DAT_0089fcc0) {
          DAT_0089fcc0 = (float)(&DAT_01e9cd04)[DAT_01add2e0];
        }
        DAT_01aae490 = (float)(&DAT_01e9cd04)[DAT_01be1808];
        DAT_01aae48c = (float)(&DAT_01e9bfc4)[DAT_01be1808];
        if (DAT_01aae48c == f_m14) {
          if (DAT_0089fcbc < DAT_01aae490) {
            DAT_0089fcbc = DAT_01aae490;
          }
        }
        else {
          *(undefined4 *)(puVar4 + -0xac) = 0;
        }
        if (f_0_007 < ABS(DAT_01be1810 - DAT_01be1814)) {
          FUN_005f33c9(puVar4,0x4caebe);
          FUN_005f34d1(puVar4,0x4caed9);
          *(int *)(puVar4 + -0x1c0) = DAT_0089fcc8 + -1;
          thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00764f00,&DAT_00764f04,"(1i3)",5,
                             puVar4 + -0x1c0);
          thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_00764ef8,&DAT_00764efc,"(1f6.3)",7,
                             &DAT_01be1814);
          thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00764ef0,&DAT_00764ef4,"(1i3)",5,&DAT_0089fcc8
                            );
          thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_00764ee8,&DAT_00764eec,"(1f6.3)",7,
                             &DAT_01be1810);
          thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
          **(undefined4 **)(puVar4 + 8) = 0xffffffff;
          *(undefined4 *)(puVar4 + -0xa4) = 0;
          return;
        }
        *(undefined4 *)(puVar4 + -0xa8) = 0;
        DAT_01be180c = DAT_01add2e0;
        DAT_01aae498 = 1;
        DAT_01aae494 = 0;
        _DAT_01aae488 = f_0;
        DAT_01be1818 = f_0;
        DAT_01be1810 = f_0;
        do {
          DAT_01aae490 = *(float *)(&DAT_01e9cf5c + DAT_01aae498 * 4);
          DAT_01aae48c = (float)(&DAT_01e9bfc4)[DAT_01be180c];
          if (DAT_01aae48c == f_m14) {
            if (((DAT_01add2e4 == DAT_01aae498) || (f_0 <= DAT_01aae490)) || (DAT_01aae490 == f_m14)
               ) {
              *(undefined4 *)(puVar4 + -0x9c) = 0;
            }
            else {
              DAT_0089fcb0 = DAT_01aae498;
              while (DAT_0089fcb0 = DAT_0089fcb0 + 1, DAT_0089fcb0 <= DAT_01add2e4) {
                _DAT_0089fcac = *(float *)(&DAT_01e9cf5c + DAT_0089fcb0 * 4);
                if (f_0 <= _DAT_0089fcac) {
                  *(undefined4 *)(puVar4 + -0x94) = 0;
                  goto LAB_004ca6e0;
                }
                if (_DAT_0089fcac == f_m14) {
                  _DAT_01aae488 = f_0;
                  *(undefined4 *)(puVar4 + -0x8c) = 0;
                  goto LAB_004caa87;
                }
                *(undefined4 *)(puVar4 + -0x90) = 0;
              }
              *(undefined4 *)(puVar4 + -0x98) = 0;
            }
          }
          else {
            *(undefined4 *)(puVar4 + -0xa0) = 0;
          }
LAB_004ca6e0:
          if (DAT_01aae490 == f_0) {
            DAT_01aae490 = DAT_01aae48c;
          }
          if (((DAT_01aae490 == f_m17) && (DAT_01aae498 < DAT_01add2e4)) &&
             ((float)(&DAT_01e9cf60)[DAT_01aae498] == f_m14)) {
            _DAT_01aae488 = DAT_01aae490;
          }
          if ((DAT_01aae48c == f_0) || (DAT_01aae490 == DAT_01aae48c)) {
LAB_004caa87:
            FUN_004cb5f5();
          }
          else {
            *(undefined4 *)(puVar4 + -0x88) = 0;
            if (DAT_01aae490 <= f_0) {
              if (DAT_01aae48c <= f_0) {
                if (DAT_01aae490 < DAT_01aae48c) {
                  *(undefined4 *)(puVar4 + -0x74) = 0;
                  if (DAT_01aae48c == f_m14) {
                    if (_DAT_01aae488 < f_0) {
                      *(undefined4 *)(puVar4 + -0x60) = 0;
                      goto LAB_004caa71;
                    }
                  }
                  else {
                    *(undefined4 *)(puVar4 + -100) = 0;
                  }
LAB_004caa4d:
                  DAT_01aae498 = DAT_01aae498 + -1;
                  *(undefined4 *)(puVar4 + -0x5c) = 0;
                  DAT_01aae490 = DAT_01aae48c;
                  goto LAB_004caa87;
                }
                if (DAT_01aae490 == f_m14) {
                  if (_DAT_01aae488 < f_0) {
                    *(undefined4 *)(puVar4 + -0x6c) = 0;
                    goto LAB_004caa4d;
                  }
                }
                else {
                  *(undefined4 *)(puVar4 + -0x70) = 0;
                }
              }
              else {
                *(undefined4 *)(puVar4 + -0x78) = 0;
              }
LAB_004caa71:
              DAT_01be180c = DAT_01be180c + -1;
              *(undefined4 *)(puVar4 + -0x68) = 0;
              goto LAB_004caa87;
            }
            *(undefined4 *)(puVar4 + -0x7c) = 0;
            if (DAT_01aae48c < f_0) {
              *(undefined4 *)(puVar4 + -0x58) = 0;
              goto LAB_004caa4d;
            }
            DAT_01be1818 = DAT_01aae48c + DAT_01be1818;
            while( true ) {
              DAT_01be1810 = DAT_01aae490 + DAT_01be1810;
              FUN_004cb5f5();
              while (DAT_01be181c = DAT_01be1810 - DAT_01be1818, f_0_001 < DAT_01be181c) {
                *(undefined4 *)(puVar4 + -0x54) = 0;
                while( true ) {
                  iVar2 = DAT_01be180c + 1;
                  if (DAT_01be1808 < iVar2) {
                    *(undefined4 *)(puVar4 + -0x34) = 0;
                    DAT_01be180c = iVar2;
                    goto LAB_004cab0a;
                  }
                  DAT_01aae48c = (float)(&DAT_01e9bfc4)[iVar2];
                  if (f_0 < DAT_01aae48c) break;
                  if (DAT_01be181c <= f_0_02) {
                    *(undefined4 *)(puVar4 + -0x28) = 0;
                    goto LAB_004ca982;
                  }
                  *(undefined4 *)(puVar4 + -0x2c) = 0;
                  DAT_01aae490 = DAT_01aae48c;
                  DAT_01be180c = iVar2;
                  FUN_004cb5f5();
                  *(undefined4 *)(puVar4 + -0x24) = 0;
                }
                *(undefined4 *)(puVar4 + -0x30) = 0;
                DAT_01be1818 = DAT_01aae48c + DAT_01be1818;
                *(undefined4 *)(puVar4 + -0x20) = 0;
                DAT_01be180c = iVar2;
              }
              if (f_m0_001 <= DAT_01be181c) break;
              *(undefined4 *)(puVar4 + -0x50) = 0;
              while( true ) {
                iVar2 = DAT_01aae498 + 1;
                if (DAT_01add2e4 < iVar2) {
                  *(undefined4 *)(puVar4 + -0x48) = 0;
                  DAT_01aae498 = iVar2;
                  goto LAB_004cab0a;
                }
                DAT_01aae490 = *(float *)(&DAT_01e9cf5c + iVar2 * 4);
                if (f_0 < DAT_01aae490) break;
                if (f_m0_02 <= DAT_01be181c) {
                  *(undefined4 *)(puVar4 + -0x3c) = 0;
                  goto LAB_004ca982;
                }
                *(undefined4 *)(puVar4 + -0x40) = 0;
                DAT_01aae498 = iVar2;
                FUN_004cb5f5();
                *(undefined4 *)(puVar4 + -0x38) = 0;
              }
              *(undefined4 *)(puVar4 + -0x44) = 0;
              DAT_01aae498 = iVar2;
            }
LAB_004ca982:
            DAT_01be1818 = f_0;
            DAT_01be1810 = f_0;
            *(undefined4 *)(puVar4 + -0x4c) = 0;
          }
          if ((DAT_01be1808 <= DAT_01be180c) && (DAT_01add2e4 <= DAT_01aae498)) goto LAB_004cab00;
          if (DAT_01aae498 < DAT_01add2e4) {
            DAT_01aae498 = DAT_01aae498 + 1;
          }
          if (DAT_01be180c < DAT_01be1808) {
            DAT_01be180c = DAT_01be180c + 1;
          }
          *(undefined4 *)(puVar4 + -0x80) = 0;
        } while( true );
      }
      DAT_01be1814 = DAT_01be1810;
      *(int *)(puVar4 + -0x1c0) = DAT_01be1808 + DAT_01add2e0 + -1;
      FUN_004cb518(&DAT_01add2e0,puVar4 + -0x1c0,&DAT_01e9bfc8);
      DAT_01be180c = DAT_01aae498 + 1;
      iVar2 = 0x97 - DAT_01be180c;
      *(int *)(puVar4 + -0xb4) = iVar2;
      DAT_01add2e4 = DAT_01aae498;
      while (0 < iVar2) {
        *(float *)(&DAT_01e9cf5c + DAT_01be180c * 4) = f_0;
        DAT_01be180c = DAT_01be180c + 1;
        *(int *)(puVar4 + -0xb4) = *(int *)(puVar4 + -0xb4) + -1;
        iVar2 = *(int *)(puVar4 + -0xb4);
      }
      DAT_0089fcc0 = (float)(&DAT_01e9cd04)[DAT_01add2e0];
      DAT_0089fcbc = (float)(&DAT_01e9cd04)[DAT_01be1808];
      *(undefined4 *)(puVar4 + -0xb0) = 0;
    }
LAB_004cadbb:
    if (DAT_0089fcc8 == **(int **)(puVar4 + 8)) {
      **(int **)(puVar4 + 8) = **(int **)(puVar4 + 8) + 1;
    }
    puVar5 = puVar4;
    if (**(int **)(puVar4 + 0xc) < **(int **)(puVar4 + 8)) {
LAB_004caff3:
      **(undefined4 **)(puVar5 + 8) = 0xffffffff;
      *(undefined4 *)(puVar5 + -0x10c) = 0;
      return;
    }
    *(undefined4 *)(puVar4 + -0x110) = 0;
  } while( true );
LAB_004cab00:
  *(undefined4 *)(puVar4 + -0x84) = 0;
LAB_004cab0a:
  FUN_004cb518(&DAT_00764f68,&DAT_01aae494,&DAT_01ea1438);
  DAT_01aae494 = DAT_01add2e0 + -1;
  iVar2 = (DAT_01be1808 - DAT_01add2e0) + 1;
  *(int *)(puVar4 + -0x1c) = iVar2;
  DAT_01add2e4 = DAT_01aae498;
  DAT_01aae498 = DAT_01add2e0;
  while (0 < iVar2) {
    DAT_01aae490 = (float)(&DAT_01e9bfc4)[DAT_01aae498];
    if (f_0 < DAT_01aae490) {
      DAT_01aae494 = DAT_01aae494 + 1;
      (&DAT_01e9bfc4)[DAT_01aae494] = DAT_01aae490;
    }
    else {
      *(undefined4 *)(puVar4 + -0x18) = 0;
    }
    *(undefined4 *)(puVar4 + -0x14) = 0;
    DAT_01aae498 = DAT_01aae498 + 1;
    *(int *)(puVar4 + -0x1c) = *(int *)(puVar4 + -0x1c) + -1;
    iVar2 = *(int *)(puVar4 + -0x1c);
  }
  DAT_01add2e0 = DAT_01add2e0 + -1;
  DAT_01be180c = 0;
  DAT_01be1808 = DAT_01aae494;
  (&DAT_01e9cf60)[DAT_01add2e4] = f_0;
  (&DAT_01e9bfc8)[DAT_01be1808] = f_0;
  FUN_004cb78b();
  DAT_01add2e0 = 0;
  DAT_01aae498 = 0;
  while (DAT_01add2e0 < DAT_01be180c) {
    DAT_01add2e0 = DAT_01add2e0 + 1;
    DAT_01be1818 = *(float *)(&DAT_01e9c21c + DAT_01add2e0 * 4);
    if (DAT_01be1818 < f_0) {
      *(undefined4 *)(puVar4 + -0xc) = 0;
    }
    DAT_01aae498 = DAT_01aae498 + 1;
    *(float *)(&DAT_01e9cf5c + DAT_01aae498 * 4) = DAT_01be1818;
    *(undefined4 *)(puVar4 + -8) = 0;
  }
  *(undefined4 *)(puVar4 + -0x10) = 0;
  DAT_01add2e4 = DAT_01aae498;
  *(undefined4 *)(puVar4 + -4) = 0;
  goto LAB_004c9e0b;
}


