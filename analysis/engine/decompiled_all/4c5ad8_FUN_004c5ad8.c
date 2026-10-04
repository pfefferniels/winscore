// FUN_004c5ad8 @ 004c5ad8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c5ad8(int *param_1,int *param_2)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  uint local_184;
  int local_180;
  int local_15c;
  undefined4 local_158;
  undefined4 local_154;
  int local_150;
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
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  int local_e4;
  int local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  int local_c8;
  undefined4 local_c4;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  int local_b4;
  undefined4 local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2c;
  
  DAT_0089fc18 = 0;
  LOAD_I = 1;
  for (local_15c = ITEM_I; 0 < local_15c; local_15c = local_15c + -1) {
    load_item_header();
    if ((LOAD_STAFF < *param_1) || (*param_2 < LOAD_STAFF)) {
      local_158 = 0;
    }
    else if (LOAD_CODE == 0xe) {
      DAT_0089fc14 = 1;
      for (local_150 = DAT_0089fc18; 0 < local_150; local_150 = local_150 + -1) {
        if (ABS(LOAD_P3 - (float)(&DAT_01e9b8bc)[DAT_0089fc14]) < f_0_005) {
          local_14c = 0;
          goto LAB_004c5c04;
        }
        DAT_0089fc14 = DAT_0089fc14 + 1;
      }
      DAT_0089fc18 = DAT_0089fc18 + 1;
      (&DAT_01e9b8bc)[DAT_0089fc18] = LOAD_P3;
      *(int *)(&DAT_01e9df04 + DAT_0089fc18 * 4) = LOAD_W + 3;
    }
    else {
      local_154 = 0;
    }
LAB_004c5c04:
    local_148 = 0;
    LOAD_I = LOAD_I + 1;
  }
  DAT_0089fc10 = 0;
  DAT_0089fc0c = 1;
  do {
    LOAD_I = DAT_0089fc0c;
    load_item_header();
LAB_004c5c5f:
    if (*param_1 <= LOAD_STAFF) {
      if (LOAD_STAFF <= *param_2) {
        if ((LOAD_CODE < 3) && (f_64 <= *(float *)(&ITEM_P7 + LOAD_W * 4))) {
          _DAT_0089fc08 = LOAD_P3;
          DAT_0089fc04 = LOAD_STAFF;
          DAT_0089fc14 = DAT_0089fc0c;
          while (DAT_0089fc14 = DAT_0089fc14 + -1, 0 < DAT_0089fc14) {
            LOAD_I = DAT_0089fc14;
            load_item_header();
            if (DAT_0089fc04 != LOAD_STAFF) {
              local_134 = 0;
              goto LAB_004c5df0;
            }
            if (((LOAD_CODE < 0x11) && (3 < LOAD_CODE)) && (LOAD_CODE != 0xe)) {
              local_130 = 0;
            }
            else {
              if (LOAD_CODE != 0x12) {
                local_12c = 0;
                goto LAB_004c5e48;
              }
              if (((LOAD_LEN < 0xf || *(float *)(&ITEM_P15 + LOAD_W * 4) == f_0) &&
                  ((float)(&ITEM_P4)[LOAD_W] == f_0)) &&
                 (*(float *)(&ITEM_P14 + LOAD_W * 4) == f_0 || LOAD_LEN < 0xe)) goto LAB_004c5e48;
              local_128 = 0;
            }
          }
          local_138 = 0;
LAB_004c5df0:
          LOAD_STAFF = DAT_0089fc04;
          LOAD_W = *(int *)(&DAT_01e9df04 + DAT_0089fc00 * 4);
          LOAD_P3 = f_0;
          LOAD_I = 1;
          FUN_004c78f8(&DAT_00764e10,&DAT_0089fc10);
          goto LAB_004c5f10;
        }
        local_13c = 0;
        goto LAB_004c61b0;
      }
      local_140 = 0;
      goto LAB_004c61f4;
    }
    local_144 = 0;
LAB_004c61b0:
    DAT_0089fc0c = DAT_0089fc0c + 1;
    if (ITEM_I < DAT_0089fc0c) goto LAB_004c61f4;
    local_e8 = 0;
  } while( true );
LAB_004c5e48:
  local_184 = 0xffffff9c - LOAD_CODE;
  FUN_004c78f8(&local_184,&DAT_0089fc10);
  if (2 < LOAD_CODE) goto LAB_004c5ee2;
  DAT_0089fc14 = DAT_0089fc14 + -1;
  if (DAT_0089fc14 < 1) {
    local_120 = 0;
    goto LAB_004c5f10;
  }
  LOAD_I = DAT_0089fc14;
  load_item_header();
  if ((DAT_0089fc04 != LOAD_STAFF) || (LOAD_P3 != (float)(&DAT_01e9bfc4)[DAT_0089fc10])) {
    local_11c = 0;
    goto LAB_004c5f10;
  }
  if (2 < LOAD_CODE) {
    local_114 = 0;
    goto LAB_004c5f10;
  }
  local_118 = 0;
  goto LAB_004c5e48;
LAB_004c5ee2:
  local_124 = 0;
LAB_004c5f10:
  LOAD_I = DAT_0089fc0c;
  load_item_header();
  do {
    FUN_004c78f8(&LOAD_CODE,&DAT_0089fc10);
LAB_004c5f34:
    DAT_0089fc0c = DAT_0089fc0c + 1;
    if (ITEM_I < DAT_0089fc0c) {
      local_110 = 0;
LAB_004c615b:
      LOAD_STAFF = DAT_0089fc04;
      LOAD_W = *(int *)(&DAT_01e9df04 + DAT_0089fc00 * 4);
      LOAD_P3 = DAT_01fbb8b8;
      LOAD_I = 1;
      FUN_004c78f8(&DAT_00764e10,&DAT_0089fc10);
      goto LAB_004c61b0;
    }
    LOAD_I = DAT_0089fc0c;
    load_item_header();
    if (DAT_0089fc04 != LOAD_STAFF) {
      local_10c = 0;
      goto LAB_004c615b;
    }
    if ((2 < LOAD_CODE) || (*(float *)(&ITEM_P7 + LOAD_W * 4) < f_64)) {
      if ((LOAD_CODE < 0x11) && ((3 < LOAD_CODE && (LOAD_CODE != 0xe)))) {
        local_104 = 0;
      }
      else {
        if (LOAD_CODE != 0x12) {
          local_100 = 0;
LAB_004c6084:
          _DAT_0089fc08 = LOAD_P3;
          break;
        }
        if (((*(float *)(&ITEM_P15 + LOAD_W * 4) == f_0 || LOAD_LEN < 0xf) &&
            ((float)(&ITEM_P4)[LOAD_W] == f_0)) &&
           (*(float *)(&ITEM_P14 + LOAD_W * 4) == f_0 || LOAD_LEN < 0xe)) goto LAB_004c6084;
        local_fc = 0;
      }
      goto LAB_004c5f34;
    }
    local_108 = 0;
  } while( true );
LAB_004c6090:
  local_184 = -LOAD_CODE;
  FUN_004c78f8(&local_184,&DAT_0089fc10);
  while( true ) {
    DAT_0089fc0c = DAT_0089fc0c + 1;
    if (ITEM_I < DAT_0089fc0c) {
      local_f8 = 0;
      goto LAB_004c61f4;
    }
    LOAD_I = DAT_0089fc0c;
    load_item_header();
    if ((DAT_0089fc04 != LOAD_STAFF) || (_DAT_0089fc08 != LOAD_P3)) {
      local_f4 = 0;
      goto LAB_004c5c5f;
    }
    if (LOAD_CODE < 3) break;
    local_ec = 0;
  }
  local_f0 = 0;
  goto LAB_004c6090;
LAB_004c61f4:
  DAT_0089fc0c = 1;
  iVar1 = DAT_0089fc0c;
  DAT_0089fc0c = DAT_0089fc10;
  while (local_e4 = DAT_0089fc10 + -1, DAT_0089fc10 = DAT_0089fc0c, 0 < local_e4) {
    DAT_0089fbfc = (float)(&DAT_01e9bfc4)[iVar1];
    DAT_0089fc14 = iVar1 + 1;
    for (local_e0 = (DAT_0089fc0c - DAT_0089fc14) + 1; DAT_0089fc0c = iVar1, 0 < local_e0;
        local_e0 = local_e0 + -1) {
      if (ABS((float)(&DAT_01e9bfc4)[DAT_0089fc14] - DAT_0089fbfc) < f_0_01) {
        (&DAT_01e9bfc4)[DAT_0089fc14] = DAT_0089fbfc;
      }
      DAT_0089fc14 = DAT_0089fc14 + 1;
      iVar1 = DAT_0089fc0c;
    }
    local_dc = 0;
    iVar1 = DAT_0089fc0c + 1;
    DAT_0089fc0c = DAT_0089fc10;
    DAT_0089fc10 = local_e4;
  }
  do {
    DAT_0089fbf8 = f_0;
    DAT_0089fbfc = (float)(&DAT_01e9bfc4)[DAT_0089fc0c];
LAB_004c6311:
    DAT_0089fc0c = DAT_0089fc0c + -1;
    if (DAT_0089fc0c == 0) goto LAB_004c63af;
    if (-1 < (int)(&DAT_01e9997c)[DAT_0089fc0c]) break;
    local_d4 = 0;
  } while( true );
  if (DAT_0089fbf8 != (float)(&DAT_01e9bfc4)[DAT_0089fc0c]) {
    DAT_0089fbfc = DAT_0089fbfc - f_0_11;
  }
  DAT_0089fbf8 = (float)(&DAT_01e9bfc4)[DAT_0089fc0c];
  (&DAT_01e9bfc4)[DAT_0089fc0c] = DAT_0089fbfc;
  local_d0 = 0;
  goto LAB_004c6311;
LAB_004c63af:
  local_d8 = 0;
  local_cc = 0;
  DAT_0089fc0c = 2;
  for (local_c8 = DAT_0089fc10 + -2; 0 < local_c8; local_c8 = local_c8 + -1) {
    if (((int)(&DAT_01e9997c)[DAT_0089fc0c] < 0) || ((&DAT_01e99978)[DAT_0089fc0c] == -0xe)) {
      local_c4 = 0;
    }
    else {
      DAT_0089fc00 = 0;
      DAT_0089fc14 = 1;
      for (local_c0 = DAT_0089fc18; 0 < local_c0; local_c0 = local_c0 + -1) {
        if (((float)(&DAT_01e9b8bc)[DAT_0089fc14] <= (float)(&DAT_01e9bfc4)[DAT_0089fc0c]) &&
           ((float)(&DAT_01e9bfc0)[DAT_0089fc0c] <= (float)(&DAT_01e9b8bc)[DAT_0089fc14])) {
          DAT_0089fc00 = DAT_0089fc14;
        }
        DAT_0089fc14 = DAT_0089fc14 + 1;
      }
      if (DAT_0089fc00 == 0) {
        local_bc = 0;
      }
      else {
        DAT_0089fc14 = DAT_0089fc0c + -1;
        (&DAT_01e9bfc4)[DAT_0089fc14] = (&DAT_01e9b8bc)[DAT_0089fc00];
        *(undefined4 *)(&DAT_01ea0164 + DAT_0089fc14 * 4) =
             *(undefined4 *)(&DAT_01e9df04 + DAT_0089fc00 * 4);
        (&DAT_01e9997c)[DAT_0089fc14] = 0xffffff8e;
        (&DAT_01ea20a4)[DAT_0089fc14] = 1;
      }
    }
    local_b8 = 0;
    DAT_0089fc0c = DAT_0089fc0c + 1;
  }
  DAT_0089fc0c = DAT_0089fc10 + -1;
  for (local_b4 = (1 - DAT_0089fc0c) / -1; 0 < local_b4; local_b4 = local_b4 + -1) {
    if (((int)(&DAT_01e9997c)[DAT_0089fc0c] < 0) || ((&DAT_01e99980)[DAT_0089fc0c] == -0xe)) {
      local_b0 = 0;
    }
    else {
      DAT_0089fc00 = 0;
      DAT_0089fc14 = 1;
      for (local_ac = DAT_0089fc18; 0 < local_ac; local_ac = local_ac + -1) {
        if (((float)(&DAT_01e9bfc4)[DAT_0089fc0c] <= (float)(&DAT_01e9b8bc)[DAT_0089fc14]) &&
           ((float)(&DAT_01e9b8bc)[DAT_0089fc14] <= (float)(&DAT_01e9bfc8)[DAT_0089fc0c])) {
          DAT_0089fc00 = DAT_0089fc14;
        }
        DAT_0089fc14 = DAT_0089fc14 + 1;
      }
      if (DAT_0089fc00 == 0) {
        local_a8 = 0;
      }
      else {
        DAT_0089fc14 = DAT_0089fc0c + 1;
        (&DAT_01e9bfc4)[DAT_0089fc14] = (&DAT_01e9b8bc)[DAT_0089fc00];
        *(undefined4 *)(&DAT_01ea0164 + DAT_0089fc14 * 4) =
             *(undefined4 *)(&DAT_01e9df04 + DAT_0089fc00 * 4);
        (&DAT_01e9997c)[DAT_0089fc14] = 0xfffffff2;
        (&DAT_01ea20a4)[DAT_0089fc14] = 1;
      }
    }
    local_a4 = 0;
    DAT_0089fc0c = DAT_0089fc0c + -1;
  }
  DAT_0089fc0c = 1;
  for (local_a0 = DAT_0089fc10; 0 < local_a0; local_a0 = local_a0 + -1) {
    DAT_0089fc14 = *(int *)(&DAT_01e9e224 + DAT_0089fc0c * 4);
    DAT_0089fbf4 = (float)(&STAFF_STEP0)[DAT_0089fc14] / f_25;
    LOAD_W = *(int *)(&DAT_01ea0164 + DAT_0089fc0c * 4) + -3;
    local_184 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    LOAD_LEN = (int)ROUND((float)(&ITEM_LEN)[LOAD_W]);
    DAT_0089fc00 = (int)(&DAT_01e9997c)[DAT_0089fc0c] % 100;
    local_180 = LOAD_LEN;
    if ((((DAT_0089fc00 == -0x12) || (DAT_0089fc00 == -0x11)) || (-4 < DAT_0089fc00)) ||
       (DAT_0089fc00 == -0xe)) {
      FUN_004c7374(&DAT_0089fc00,&DAT_0089fbf8,&DAT_0089fbf0);
      DAT_0089fbec = DAT_0089fbf4;
      if (0 < (int)(&DAT_01e9997c)[DAT_0089fc0c]) {
        DAT_0089fbec = DAT_0089fbf4 * f_0_6;
      }
      *(float *)(&DAT_01ea4f84 + DAT_0089fc0c * 4) = DAT_0089fbec * _DAT_0089fbf0;
      *(float *)(&DAT_01ea3fe4 + DAT_0089fc0c * 4) = DAT_0089fbec * DAT_0089fbf8;
    }
    else {
      local_9c = 0;
    }
    local_98 = 0;
    DAT_0089fc0c = DAT_0089fc0c + 1;
  }
  DAT_0089fc14 = 0;
  DAT_0089fbfc = f_0;
  while( true ) {
    DAT_0089fc00 = 0;
    DAT_0089fc0c = 1;
    DAT_0089fbec = f_9999;
    for (local_94 = DAT_0089fc10; 0 < local_94; local_94 = local_94 + -1) {
      if (((int)(&DAT_01ea20a4)[DAT_0089fc0c] < 0) ||
         (DAT_0089fbec < (float)(&DAT_01e9bfc4)[DAT_0089fc0c])) {
        local_90 = 0;
      }
      else {
        DAT_0089fbec = (float)(&DAT_01e9bfc4)[DAT_0089fc0c];
        DAT_0089fc00 = DAT_0089fc0c;
      }
      local_8c = 0;
      DAT_0089fc0c = DAT_0089fc0c + 1;
    }
    if (DAT_0089fc00 == 0) break;
    DAT_0089fc14 = DAT_0089fc14 + 1;
    (&DAT_01e9cf64)[DAT_0089fc14] = DAT_0089fbec;
    DAT_0089fbfc = DAT_0089fbec;
    (&DAT_01e9a91c)[DAT_0089fc14] = DAT_0089fc00;
    (&DAT_01ea20a4)[DAT_0089fc00] = -(&DAT_01ea20a4)[DAT_0089fc00];
    local_84 = 0;
  }
  local_88 = 0;
  local_80 = 0;
  DAT_0089fc0c = 1;
  DAT_0089fc00 = 0;
  do {
    if ((float)(&DAT_01e9cf64)[DAT_0089fc0c] == (float)(&DAT_01e9cf68)[DAT_0089fc0c]) {
      _DAT_0089fbf0 = (float)(&DAT_01e9cf64)[DAT_0089fc0c];
      DAT_0089fbfc = f_m99;
      DAT_0089fbf8 = f_m99;
      DAT_0089fc14 = DAT_0089fc0c;
      for (local_78 = (DAT_0089fc10 - DAT_0089fc0c) + 1; 0 < local_78; local_78 = local_78 + -1) {
        if (_DAT_0089fbf0 < (float)(&DAT_01e9cf64)[DAT_0089fc14]) {
          local_74 = 0;
          break;
        }
        DAT_0089fc00 = (&DAT_01e9a91c)[DAT_0089fc14];
        if (DAT_0089fbfc < *(float *)(&DAT_01ea3fe4 + DAT_0089fc00 * 4)) {
          DAT_0089fbfc = *(float *)(&DAT_01ea3fe4 + DAT_0089fc00 * 4);
        }
        if (DAT_0089fbf8 < *(float *)(&DAT_01ea4f84 + DAT_0089fc00 * 4)) {
          DAT_0089fbf8 = *(float *)(&DAT_01ea4f84 + DAT_0089fc00 * 4);
        }
        DAT_0089fc14 = DAT_0089fc14 + 1;
      }
      LOAD_I = DAT_0089fc0c;
      for (local_70 = DAT_0089fc14 - DAT_0089fc0c; 0 < local_70; local_70 = local_70 + -1) {
        DAT_0089fc00 = (&DAT_01e9a91c)[LOAD_I];
        *(float *)(&DAT_01ea3fe4 + DAT_0089fc00 * 4) = DAT_0089fbfc;
        *(float *)(&DAT_01ea4f84 + DAT_0089fc00 * 4) = DAT_0089fbf8;
        LOAD_I = LOAD_I + 1;
      }
      DAT_0089fc0c = DAT_0089fc14 + -1;
    }
    else {
      local_7c = 0;
    }
    DAT_0089fc0c = DAT_0089fc0c + 1;
    if (DAT_0089fc10 <= DAT_0089fc0c) break;
    local_6c = 0;
  } while( true );
  DAT_0089fc0c = 1;
  local_68 = DAT_0089fc10;
  while (local_68 = local_68 + -1, iVar1 = DAT_0089fc10, 0 < local_68) {
    DAT_0089fc00 = (&DAT_01e9a91c)[DAT_0089fc0c];
    DAT_0089fc04 = (&DAT_01e9a920)[DAT_0089fc0c];
    if ((*(int *)(&DAT_01e9e224 + DAT_0089fc00 * 4) == *(int *)(&DAT_01e9e224 + DAT_0089fc04 * 4))
       || ((float)(&DAT_01e9cf64)[DAT_0089fc0c] == (float)(&DAT_01e9cf68)[DAT_0089fc0c])) {
      local_64 = 0;
    }
    else if (((int)(&DAT_01e9997c)[DAT_0089fc00] < -99) &&
            ((int)(&DAT_01e9997c)[DAT_0089fc04] < -99)) {
      (&DAT_01e9cf64)[DAT_0089fc0c] = (&DAT_01e9cf68)[DAT_0089fc0c];
      (&DAT_01e9a91c)[DAT_0089fc0c] = (&DAT_01e9a920)[DAT_0089fc0c];
      (&DAT_01e9bfc4)[DAT_0089fc00] = (&DAT_01e9bfc4)[DAT_0089fc04];
      *(undefined4 *)(&DAT_01ea0164 + DAT_0089fc00 * 4) =
           *(undefined4 *)(&DAT_01ea0164 + DAT_0089fc04 * 4);
      (&DAT_01e9997c)[DAT_0089fc00] = (&DAT_01e9997c)[DAT_0089fc04];
      (&DAT_01ea20a4)[DAT_0089fc00] = (&DAT_01ea20a4)[DAT_0089fc04];
      *(undefined4 *)(&DAT_01ea3fe4 + DAT_0089fc00 * 4) =
           *(undefined4 *)(&DAT_01ea3fe4 + DAT_0089fc04 * 4);
      *(undefined4 *)(&DAT_01ea4f84 + DAT_0089fc00 * 4) =
           *(undefined4 *)(&DAT_01ea4f84 + DAT_0089fc04 * 4);
    }
    else {
      local_60 = 0;
    }
    local_5c = 0;
    DAT_0089fc0c = DAT_0089fc0c + 1;
  }
LAB_004c6ddc:
  DAT_0089fc0c = iVar1;
  if (((-100 < (int)(&DAT_01e9997c)[DAT_0089fc0c]) && ((int)(&DAT_01ea20a4)[DAT_0089fc0c] < 1)) &&
     ((int)(&DAT_01e9997c)[DAT_0089fc0c] < 0)) {
    local_58 = 0;
    LOAD_P3 = (float)(&DAT_01e9bfc4)[DAT_0089fc0c];
    (&DAT_01ea20a4)[DAT_0089fc0c] = 1;
    DAT_0089fc00 = 1;
    DAT_01ea3048 = DAT_0089fc0c;
    FUN_004c795b(&DAT_0089fc0c,&DAT_0089fbf0,&DAT_0089fc04);
    do {
      DAT_0089fc14 = DAT_0089fc04 + -1;
      local_4c = -DAT_0089fc14 / -1;
      while( true ) {
        if (local_4c < 1) {
          if ((_DAT_0089fbf0 == f_1) || (_DAT_0089fbf0 <= f_0)) {
            local_44 = 0;
            goto LAB_004c70a9;
          }
          DAT_0089fc14 = DAT_0089fc10;
          goto LAB_004c6fa8;
        }
        if (LOAD_P3 == (float)(&DAT_01e9bfc4)[DAT_0089fc14]) break;
        DAT_0089fc14 = DAT_0089fc14 + -1;
        local_4c = local_4c + -1;
      }
      local_48 = 0;
      FUN_004c795b(&DAT_0089fc14,&DAT_0089fbec,&DAT_0089fc04);
      (&DAT_01ea20a4)[DAT_0089fc14] = 1;
      DAT_0089fc00 = DAT_0089fc00 + 1;
      *(int *)(DAT_0089fc00 * 4 + 0x1ea3044) = DAT_0089fc14;
      if (DAT_0089fbec < _DAT_0089fbf0) {
        _DAT_0089fbf0 = DAT_0089fbec;
      }
      local_2c = 0;
    } while( true );
  }
  goto LAB_004c70a9;
LAB_004c6fa8:
  if (LOAD_P3 == (float)(&DAT_01e9bfc4)[DAT_0089fc14]) {
    DAT_0089fc04 = DAT_0089fc14;
    for (iVar1 = -DAT_0089fc14 / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
      *(float *)(&DAT_01ea3fe4 + DAT_0089fc04 * 4) =
           _DAT_0089fbf0 * *(float *)(&DAT_01ea3fe4 + DAT_0089fc04 * 4);
      *(float *)(&DAT_01ea4f84 + DAT_0089fc04 * 4) =
           _DAT_0089fbf0 * *(float *)(&DAT_01ea4f84 + DAT_0089fc04 * 4);
      if ((int)(&DAT_01e9997c)[DAT_0089fc04] < -100) {
        local_3c = 0;
        break;
      }
      DAT_0089fc04 = DAT_0089fc04 + -1;
    }
    DAT_0089fc14 = DAT_0089fc04;
  }
  else {
    local_40 = 0;
  }
  DAT_0089fc14 = DAT_0089fc14 + -1;
  if (DAT_0089fc14 < 3) goto LAB_004c7099;
  local_38 = 0;
  goto LAB_004c6fa8;
LAB_004c7099:
  local_34 = 0;
LAB_004c70a9:
  if (DAT_0089fc0c + -1 < 2) {
    DAT_0089fc0c = 1;
    do {
      if (-1 < (int)(&DAT_01e9997c)[DAT_0089fc0c]) {
        (&DAT_01e9cf60)[DAT_0089fc0c] =
             (float)(&DAT_01ea4f80)[DAT_0089fc0c] + *(float *)(&DAT_01ea3fe4 + DAT_0089fc0c * 4);
        DAT_0089fbfc = *(float *)(&DAT_01ea4f84 + DAT_0089fc0c * 4);
        DAT_0089fc04 = DAT_0089fc0c + 1;
        for (iVar1 = (DAT_0089fc10 - DAT_0089fc04) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
          (&DAT_01e9cf60)[DAT_0089fc04] =
               DAT_0089fbfc + *(float *)(&DAT_01ea3fe4 + DAT_0089fc04 * 4);
          if ((float)(&DAT_01e9bfc4)[DAT_0089fc04] != (float)(&DAT_01e9bfc0)[DAT_0089fc04]) {
            DAT_0089fbfc = *(float *)(&DAT_01ea4f84 + DAT_0089fc04 * 4);
          }
          if ((int)(&DAT_01e9997c)[DAT_0089fc04] < 0) break;
          DAT_0089fc04 = DAT_0089fc04 + 1;
        }
        DAT_0089fc04 = DAT_0089fc0c;
      }
      DAT_0089fc0c = DAT_0089fc0c + 1;
      if (DAT_0089fc10 <= DAT_0089fc0c) {
        DAT_0089fc0c = DAT_0089fc10;
        do {
          DAT_0089fbfc = (float)(&DAT_01e9bfc4)[DAT_0089fc0c];
          DAT_0089fbf8 = f_0;
          while( true ) {
            DAT_0089fc0c = DAT_0089fc0c + -1;
            if (DAT_0089fc0c < 2) {
              return;
            }
            if ((int)(&DAT_01e9997c)[DAT_0089fc0c] < 0) break;
            if (DAT_0089fbf8 != (float)(&DAT_01e9bfc4)[DAT_0089fc0c]) {
              DAT_0089fbfc = DAT_0089fbfc - (float)(&DAT_01e9cf64)[DAT_0089fc0c];
            }
            DAT_0089fbf8 = (float)(&DAT_01e9bfc4)[DAT_0089fc0c];
            if (((int)(&DAT_01e99978)[DAT_0089fc0c] < 0) &&
               (DAT_0089fbfc < (float)(&DAT_01e9bfc0)[DAT_0089fc0c] + f_0_1)) {
              DAT_0089fbfc = (float)(&DAT_01e9bfc0)[DAT_0089fc0c] + f_0_1;
            }
            (&DAT_01e9bfc4)[DAT_0089fc0c] = DAT_0089fbfc;
            (&ITEM_LEN)[*(int *)(&DAT_01ea0164 + DAT_0089fc0c * 4)] = DAT_0089fbfc;
          }
        } while( true );
      }
    } while( true );
  }
  local_50 = 0;
  iVar1 = DAT_0089fc0c + -1;
  goto LAB_004c6ddc;
}


