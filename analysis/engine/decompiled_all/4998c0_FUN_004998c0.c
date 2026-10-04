// FUN_004998c0 @ 004998c0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004998c0(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  float local_cc;
  uint local_c8;
  float local_c4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  if (DAT_01ba207c == 0) {
    _DAT_00838898 = f_0;
  }
  if (DAT_01ba2078 < 0) {
    DAT_01ba2078 = -DAT_01ba2078;
    local_9c = 0;
    goto LAB_0049990e;
  }
  local_a0 = 0;
  do {
    DAT_01ba207c = DAT_01ba207c + 1;
    while( true ) {
      thunk_FUN_00497f00(&DAT_01c4eec4 + DAT_01ba207c * 0x80,0x80,&DAT_01c6da60,&DAT_01c46380,
                         &DAT_01ba2068,&DAT_01ba2064,&ITEM_WORDS);
      if (ITEM_WORDS < 0) {
        return;
      }
      if (DAT_01ba207c != 1) break;
      thunk_FUN_00584c27();
      if (DAT_01c4c784 == 0) {
        local_90 = 0;
        goto LAB_004999f5;
      }
      DAT_01ba207c = DAT_01c4c784;
      if (DAT_01c4c784 < 2) goto LAB_004999e7;
      local_8c = 0;
    }
    local_94 = 0;
LAB_004999e7:
    if (DAT_01c4c784 != 0) {
      FUN_0049aa8c();
    }
LAB_004999f5:
    DAT_01ba2070 = *(int *)(&DAT_01c424fc + DAT_01ba207c * 4);
    DAT_01ba2078 = DAT_01ba2070 + DAT_01ba2078;
    if (ITEM_WORDS == 1) {
      local_88 = 0;
    }
    else {
      local_cc = f_m10;
      thunk_FUN_005037af(&local_cc,&DAT_007633f8,&DAT_007633fc,&DAT_01c6da60,&DAT_01c46380,
                         &DAT_01ba2064,&DAT_01ba2068);
      _DAT_00838898 = _DAT_00838898 + f_200;
      DAT_00838894 = 1;
      for (local_84 = DAT_020492a4; 0 < local_84; local_84 = local_84 + -1) {
        DAT_00838890 = *(int *)(&DAT_02049a74 + DAT_00838894 * 4);
        if (DAT_00838890 < 0) {
          DAT_00838890 = -DAT_00838890;
        }
        *(float *)(&DAT_01c6da5c + DAT_00838890 * 4) =
             _DAT_00838898 + *(float *)(&DAT_01c6da5c + DAT_00838890 * 4);
        DAT_00838894 = DAT_00838894 + 1;
      }
    }
    thunk_FUN_0054c590(&DAT_01c6da60,&ITEM_LEN + ITEM_WORDS,&DAT_01ba2068);
    ITEM_WORDS = DAT_01ba2068 + ITEM_WORDS + -1;
LAB_0049990e:
    if (DAT_01ba2074 <= DAT_01ba2078) {
      DAT_00838868 = _DAT_00838898 + (float)(&DAT_01ba0d84)[DAT_01ba206c];
      thunk_FUN_0049836a(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I,&ITEM_WORDS);
      if (DAT_020b8e20 <= ITEM_WORDS) {
        return;
      }
      if (DAT_020b8e20 / 10 <= ITEM_I) {
        return;
      }
      local_7c = 0;
      thunk_FUN_00479cf8();
      do {
        DAT_00838890 = ITEM_I;
        local_74 = -ITEM_I / -1;
        DAT_00838894 = ITEM_I;
        while( true ) {
          if (local_74 < 1) {
            if (DAT_01ba2074 == DAT_01ba2078) {
              local_60 = 0;
              DAT_00838868 = f_0;
              DAT_00838894 = ITEM_I;
              for (local_14 = -ITEM_I / -1; 0 < local_14; local_14 = local_14 + -1) {
                DAT_00838870 = (float)(&ITEM_P3)[(&ITEM_PTR0)[DAT_00838894]];
                if ((int)DAT_00838868 < (int)DAT_00838870) {
                  DAT_00838868 = DAT_00838870;
                }
                DAT_00838894 = DAT_00838894 + -1;
              }
              goto LAB_0049a2fc;
            }
            DAT_01ba2068 = 1;
            _DAT_00838884 = DAT_00838868 - f_2;
            DAT_00838894 = 1;
            local_5c = ITEM_I;
            goto joined_r0x00499e28;
          }
          DAT_0083888c = (&ITEM_PTR0)[DAT_00838894];
          if ((float)(&ITEM_P1)[DAT_0083888c] == f_13) break;
          local_70 = 0;
          local_64 = 0;
          DAT_00838894 = DAT_00838894 + -1;
          local_74 = local_74 + -1;
        }
        DAT_00838888 = (float)(&DAT_02091d20)[DAT_00838894];
        local_cc = (float)((ITEM_WORDS - (int)DAT_00838888) + 1);
        thunk_FUN_0054c590(&ITEM_LEN + (int)DAT_00838888,&ITEM_LEN + DAT_0083888c,&local_cc);
        DAT_00838888 = (float)((int)DAT_00838888 - DAT_0083888c);
        ITEM_WORDS = ITEM_WORDS - (int)DAT_00838888;
        DAT_0083888c = DAT_00838894 + 1;
        for (local_6c = (ITEM_I - DAT_0083888c) + 1; 0 < local_6c; local_6c = local_6c + -1) {
          (&ITEM_PTR0)[DAT_0083888c] = (&DAT_02091d20)[DAT_0083888c] - (int)DAT_00838888;
          DAT_0083888c = DAT_0083888c + 1;
        }
        ITEM_I = ITEM_I + -1;
        local_68 = 0;
      } while( true );
    }
    local_80 = 0;
  } while( true );
joined_r0x00499e28:
  if (local_5c < 1) goto LAB_0049a157;
  DAT_00838890 = (&ITEM_PTR0)[DAT_00838894];
  if ((float)(&ITEM_P1)[DAT_00838890] == f_5) {
    if (_DAT_00838884 <= (float)(&ITEM_P6)[DAT_00838890]) {
      local_c8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      DAT_00838880 = (float)(int)ROUND((float)(&ITEM_LEN)[DAT_00838890] + f_1);
      local_c4 = DAT_00838880;
      thunk_FUN_0054c590(&ITEM_LEN + DAT_00838890,&DAT_01c6da5c + DAT_01ba2068 * 4,&DAT_00838880);
      (&ITEM_P6)[DAT_00838890] = DAT_00838868;
      (&DAT_01c6da68)[DAT_01ba2068] = DAT_00838868;
      DAT_01ba2068 = (int)DAT_00838880 + DAT_01ba2068;
    }
    else {
      local_54 = 0;
    }
  }
  else {
    local_58 = 0;
  }
  if (DAT_00838868 < (float)(&ITEM_P3)[DAT_00838890]) {
    local_50 = 0;
    DAT_00838878 = DAT_00838894 + -1;
    _DAT_0083887c = 0;
    local_48 = -DAT_00838878 / -1;
    DAT_00838894 = DAT_00838878;
    goto joined_r0x00499fc6;
  }
  DAT_00838894 = DAT_00838894 + 1;
  local_5c = local_5c + -1;
  goto joined_r0x00499e28;
LAB_0049a157:
  local_4c = 0;
  goto LAB_0049a15e;
joined_r0x00499fc6:
  if (local_48 < 1) goto LAB_0049a14e;
  LOAD_I = DAT_00838878;
  load_item_header();
  if (LOAD_CODE == 0xe) {
    if (LOAD_LEN < 5) {
      local_40 = 0;
    }
    else {
      local_c8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      local_c4 = (float)(int)ROUND((float)(&ITEM_P5)[LOAD_W]);
      if (((int)local_c4 < 4) || (6 < (int)local_c4)) {
        local_3c = 0;
      }
      else {
        _DAT_0083887c = 1;
        if (4 < (int)local_c4) {
          _DAT_0083887c = 3;
        }
        DAT_00838888 = local_c4;
        (&ITEM_P5)[LOAD_W] = (float)_DAT_0083887c;
        LOAD_LEN = LOAD_LEN + 1;
        thunk_FUN_0054c590(&ITEM_LEN + LOAD_W,&DAT_01c6da5c + DAT_01ba2068 * 4,&LOAD_LEN);
        (&DAT_01c6da70)[DAT_01ba2068] = f_4;
        (&DAT_01c6da68)[DAT_01ba2068] = DAT_00838868;
        DAT_01ba2068 = LOAD_LEN + DAT_01ba2068;
        local_38 = 0;
        local_2c = 0;
      }
    }
    goto LAB_0049a15e;
  }
  local_44 = 0;
  local_34 = 0;
  DAT_00838878 = DAT_00838878 + -1;
  local_48 = local_48 + -1;
  goto joined_r0x00499fc6;
LAB_0049a14e:
  local_30 = 0;
LAB_0049a15e:
  DAT_00838888 = (float)(ITEM_WORDS - DAT_00838890);
  thunk_FUN_0054c590(&ITEM_LEN + DAT_00838890,&DAT_01c6da5c + DAT_01ba2068 * 4,&DAT_00838888);
  DAT_01ba2068 = (int)DAT_00838888 + DAT_01ba2068;
  local_28 = (ITEM_I - DAT_00838894) + 1;
  ITEM_WORDS = DAT_00838890;
  DAT_00838888 = (float)ITEM_I;
  ITEM_I = DAT_00838894;
  LOAD_I = DAT_00838894;
  do {
    if (local_28 < 1) {
      local_18 = 0;
LAB_0049a2fc:
      thunk_FUN_005037af(&f_0,&DAT_00838868,&DAT_007633fc,&ITEM_P1,&DAT_02091d20,&ITEM_I,&ITEM_WORDS
                        );
      thunk_FUN_0058548e(&f_0,&DAT_00838868,&DAT_007633d8,&f_200);
      DAT_00838880 = (float)(&DAT_01b11804)[DAT_01ba0c60];
      if (DAT_00838880 == 0.0) {
        DAT_01ba0c60 = DAT_01ba0c60 + 1;
      }
      thunk_FUN_0047a4a8();
      FUN_0049a53a();
      thunk_FUN_00475020(&DAT_00838880);
      ITEM_WORDS = 1;
      if (DAT_01ba2074 == DAT_01ba2078) {
        ITEM_WORDS = 1;
        DAT_01ba2078 = 0;
        _DAT_00838898 = f_0;
      }
      else {
        thunk_FUN_0054c590(&DAT_01c6da60,&ITEM_P1,&DAT_01ba2068);
        ITEM_WORDS = DAT_01ba2068;
        thunk_FUN_0049836a(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I,&ITEM_WORDS);
        thunk_FUN_005037af(&f_0,&DAT_007633d4,&DAT_007633fc,&ITEM_P1,&DAT_02091d20,&ITEM_I,
                           &ITEM_WORDS);
        DAT_00838870 = DAT_00838868 - f_10;
        DAT_00838894 = 1;
        for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
          DAT_00838890 = *(int *)(&DAT_02049a74 + DAT_00838894 * 4);
          if (DAT_00838890 < 0) {
            DAT_00838890 = -DAT_00838890;
          }
          (&ITEM_LEN)[DAT_00838890] = (float)(&ITEM_LEN)[DAT_00838890] - DAT_00838870;
          DAT_00838894 = DAT_00838894 + 1;
        }
        _DAT_00838898 = _DAT_00838898 - DAT_00838870;
        DAT_01ba2078 = DAT_01ba2074 - DAT_01ba2078;
      }
      return;
    }
    load_item_header();
    if (LOAD_CODE < 3) {
      local_24 = 0;
      goto LAB_0049a2fc;
    }
    if (LOAD_CODE < 0x11) {
      local_20 = 0;
    }
    else {
      LOAD_W = LOAD_W + 3;
      local_c8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      local_c4 = (float)(int)ROUND((float)(&ITEM_LEN)[LOAD_W] * f_100);
      DAT_00838868 = (float)(int)local_c4 / f_100;
      DAT_00838870 = local_c4;
      (&ITEM_LEN)[LOAD_W] = DAT_00838868;
      ITEM_WORDS = (&DAT_02091d20)[LOAD_I];
      ITEM_I = LOAD_I;
    }
    local_1c = 0;
    LOAD_I = LOAD_I + 1;
    local_28 = local_28 + -1;
  } while( true );
}


