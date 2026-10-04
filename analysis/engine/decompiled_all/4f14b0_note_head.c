// note_head @ 004f14b0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void note_head(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  uint local_7c;
  int local_78;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_01a9f328 = (float)OUTPUT_MODE;
  DAT_01a9f318 = DAT_01f95ce0;
  DAT_008d19cc = STEP;
  DAT_01a9f324 = X_POS;
  DAT_01a9f31c = (int)ROUND(X_POS);
  local_7c = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  local_78 = (int)ROUND(Y_POS);
  DAT_01a9f314 = IP6;
  if ((9 < IP6) && (IP6 < 0x14)) {
    DAT_01a9f314 = IP6 + -10;
  }
  if (DAT_01a9f314 < 8) {
    local_54 = 0;
  }
  else {
    if (DAT_01a9f314 == 8) {
      DAT_01a9f314 = 0x5f;
    }
    if (DAT_01a9f314 == 9) {
      DAT_01a9f314 = 0x8b;
    }
  }
  DAT_01a9f30c = DAT_01a9f314;
  if (DAT_01a9f314 < 0) {
    DAT_01a9f30c = -DAT_01a9f314;
  }
  DAT_01a9f320 = local_78;
  DAT_01a9f33c = local_78;
  if ((0x13 < DAT_01a9f30c) && (DAT_01a9f30c < 0x1a)) {
    local_50 = 0;
    _DAT_008d19c8 = P15;
    if (P15 == f_0) {
      _DAT_008d19c8 = f_1;
    }
    _DAT_01a9f32c = X_POS / f_150;
    DAT_01f95cf0 = DAT_01f95ce0 * f_17_1;
    _DAT_008d19c4 = DAT_01a9f314 % 1000;
    ffree(in_ST0);
    in_ST0 = (float10)FUN_004f1bd4(&DAT_008d19c8);
    if (-1 < OUTPUT_MODE) {
      ffree(in_ST0);
      in_ST0 = (float10)FUN_004f1d5e(&DAT_008d19c8);
    }
    P17 = f_0_1;
    if (P5 < f_20) {
      P17 = f_m0_1;
    }
    X_POS = DAT_01a9f324;
    Y_POS = DAT_01a9f328;
    local_3c = 0;
    goto LAB_004f19ff;
  }
  DAT_01a9f30c = NPT;
  if (DAT_01a9f314 < 3) {
    if (OUTPUT_MODE != -1) {
      local_48 = 0;
      if (DAT_01a9f314 != 0) {
        local_38 = 0;
        goto LAB_004f1713;
      }
      if (_DAT_01f93fc0 * DAT_01f95ce0 == _DAT_0078b6ac) {
        local_34 = 0;
        DAT_008d19c0 = 1;
        for (iVar1 = DAT_008d19bc; 0 < iVar1; iVar1 = iVar1 + -1) {
          (&PT_X0)[DAT_01a9f30c] = *(int *)(DAT_008d19c0 * 4 + 0x1a9e91c) + DAT_01a9f31c;
          (&PT_Y0)[DAT_01a9f30c] = *(int *)(DAT_008d19c0 * 4 + 0x1a9ed04) + DAT_01a9f33c;
          *(undefined2 *)((int)&DAT_01fbb8dc + DAT_01a9f30c * 2 + 2) =
               *(undefined2 *)(DAT_008d19c0 * 2 + 0x1a9f0ee);
          DAT_01a9f30c = DAT_01a9f30c + 1;
          DAT_008d19c0 = DAT_008d19c0 + 1;
        }
        local_2c = 0;
        NPT = DAT_01a9f30c;
        goto LAB_004f19ff;
      }
      _DAT_0078b6ac = _DAT_01f93fc0 * DAT_01f95ce0;
      local_30 = 0;
    }
    STEP = DAT_01f95ce0;
    local_7c = DAT_01a9f314 + 0xb;
    ffree(in_ST0);
    in_ST0 = (float10)draw_clef(&DAT_01a9f324,&Y_POS,&local_7c,&DAT_01f93fc0,&f_1);
    if (DAT_01a9f328 == -NAN) {
      local_40 = 0;
    }
    else {
      local_44 = 0;
      DAT_008d19bc = 0;
      DAT_008d19c0 = DAT_01a9f30c;
      for (iVar1 = NPT - DAT_01a9f30c; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_008d19bc = DAT_008d19bc + 1;
        *(int *)(DAT_008d19bc * 4 + 0x1a9e91c) = (&PT_X0)[DAT_008d19c0] - DAT_01a9f31c;
        *(int *)(DAT_008d19bc * 4 + 0x1a9ed04) = (&PT_Y0)[DAT_008d19c0] - DAT_01a9f33c;
        *(undefined2 *)(DAT_008d19bc * 2 + 0x1a9f0ee) =
             *(undefined2 *)((int)&DAT_01fbb8dc + DAT_008d19c0 * 2 + 2);
        DAT_008d19c0 = DAT_008d19c0 + 1;
      }
    }
  }
  else {
    local_4c = 0;
LAB_004f1713:
    STEP = DAT_01f95ce0;
    if (DAT_01a9f314 < 7) {
      local_28 = 0;
      if (DAT_01a9f314 == -3) {
        DAT_01a9f314 = 3;
      }
      local_7c = DAT_01a9f314 + 0xb;
      ffree(in_ST0);
      in_ST0 = (float10)draw_clef(&DAT_01a9f324,&Y_POS,&local_7c,&DAT_01f93fc0,&f_1);
      local_1c = 0;
    }
    else if (DAT_01a9f314 == 7) {
      local_24 = 0;
    }
    else {
      ffree(in_ST0);
      in_ST0 = (float10)draw_symbol(&DAT_01a9f324,&Y_POS,&DAT_01a9f314,&DAT_00766504,&DAT_00766504,
                                    &f_0,&DAT_007664a4,&f_0);
      local_20 = 0;
    }
  }
LAB_004f19ff:
  if ((9 < IP6) && (IP6 < 0x14)) {
    IP6 = IP6 + -10;
    _DAT_01a9f32c = f_1_4;
    STEP = DAT_01f95ce0;
    DAT_01a9f328 = f_m13_8;
    DAT_01a9f31c = IP5 % 10;
    if (DAT_01a9f31c == 0) {
      local_14 = 0;
    }
    else {
      DAT_01a9f328 = f_m13_8 - f_14_4;
      if (DAT_01a9f31c == 4) {
        DAT_01a9f328 = DAT_01a9f328 - f_12_6;
      }
    }
    while( true ) {
      DAT_01a9f328 = DAT_01f95ce0 * DAT_01a9f328 + DAT_01a9f324;
      ffree(in_ST0);
      in_ST0 = (float10)draw_symbol(&DAT_01a9f328,&Y_POS,&DAT_007664f0,&DAT_01a9f32c,&f_1_4,&f_0,
                                    &DAT_007664a4,&f_0);
      if (_DAT_01a9f32c < f_0) break;
      in_ST0 = (float10)_DAT_01a9f32c;
      _DAT_01a9f32c = (float)-in_ST0;
      DAT_01a9f328 = f_31_2;
      if (IP9 < 10) {
        local_c = 0;
      }
      else {
        DAT_01a9f328 = f_39_2;
        if (0x13 < IP9 % 100) {
          DAT_01a9f328 = f_51_2;
        }
      }
      if (_DAT_01f93fc0 != f_1) {
        in_ST0 = (float10)DAT_01a9f328 - (float10)f_17;
        DAT_01a9f328 = (float)((float10)_DAT_01f93fc0 * (float10)f_17 + in_ST0);
      }
      local_8 = 0;
    }
  }
  STEP = DAT_008d19cc;
  ffree(in_ST0);
  return;
}


