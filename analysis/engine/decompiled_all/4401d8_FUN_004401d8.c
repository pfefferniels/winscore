// FUN_004401d8 @ 004401d8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004401d8(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  undefined1 *puVar2;
  int local_8c;
  uint local_88;
  int local_84;
  undefined4 local_60;
  undefined4 local_5c;
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
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  puVar2 = &stack0xfffffffc;
  thunk_FUN_005725fa();
  DAT_007f7a0c = ITEM_I;
  DAT_0078d880 = EDIT_ITEM;
  DAT_020b8e44 = ITEM_WORDS;
  _DAT_007f7a08 = ITEM_I + 1;
  DAT_0078b4f0 = 1;
  DAT_01c5867c = 0;
  DAT_007f7a04 = 0;
  _DAT_01cb106c = DAT_020b944c;
  _DAT_01cb1070 = P4;
  if (P4 == f_0) {
    DAT_01c585c8 = (&ITEM_PTR0)[EDIT_ITEM];
    _DAT_01cb1070 = f_5;
    DAT_01c585cc = (&DAT_02091d18)[EDIT_ITEM];
    if ((((float)(&ITEM_P3)[DAT_01c585cc] == (float)(&ITEM_P3)[DAT_01c585c8]) &&
        ((float)(&ITEM_P1)[DAT_01c585cc] == f_16)) &&
       ((float)(&ITEM_P2)[DAT_01c585cc] == (float)(&ITEM_P2)[DAT_01c585c8])) {
      _DAT_01cb1070 = ABS((float)(&ITEM_P4)[DAT_01c585cc] - (float)(&ITEM_P4)[DAT_01c585c8]);
    }
    if (ITEM_I == EDIT_ITEM) {
      local_5c = 0;
    }
    else {
      DAT_01c585cc = (&DAT_02091d20)[EDIT_ITEM];
      if ((((float)(&ITEM_P3)[DAT_01c585cc] == (float)(&ITEM_P3)[DAT_01c585c8]) &&
          ((float)(&ITEM_P1)[DAT_01c585cc] == f_16)) &&
         ((float)(&ITEM_P2)[DAT_01c585cc] == (float)(&ITEM_P2)[DAT_01c585c8])) {
        _DAT_01cb1070 = ABS((float)(&ITEM_P4)[DAT_01c585cc] - (float)(&ITEM_P4)[DAT_01c585c8]);
      }
    }
  }
  else {
    local_60 = 0;
  }
  IP8 = (int)ROUND(DAT_020b945c);
  DAT_01c58648 = EDIT_ITEM;
  local_88 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  local_84 = (int)ROUND(P3);
  if (local_84 < 0) {
    _DAT_01cb106c = DAT_020b944c;
    DAT_01c5867c = 0;
    DAT_01c5864c = local_84;
    DAT_01c58648 = EDIT_ITEM;
    DAT_007f7a0c = ITEM_I;
    DAT_007f7a04 = 0;
    DAT_0078d880 = EDIT_ITEM;
    DAT_0078b4f0 = 1;
    return;
  }
  DAT_01c5864c = local_84;
  if (local_84 == 0) {
    DAT_01c5864c = 999;
  }
  DAT_01c58658 = DAT_01c5864c;
  DAT_01c5864c = EDIT_ITEM + DAT_01c5864c + -1;
  if (ITEM_I < DAT_01c5864c) {
    DAT_01c5864c = ITEM_I;
  }
  _DAT_01c58670 = P2 - DAT_020b9448;
  DAT_01c58640 = DAT_020b9448;
  DAT_01c58644 = P2;
  _DAT_007f7a00 = f_0;
  DAT_020b9450 = f_1;
  DAT_020b9464 = f_0;
  P48 = DAT_020b9454;
  if (DAT_020b9454 == f_0) {
    P48 = f_1;
  }
  DAT_007f79fc = P48;
  DAT_01c58654 = 0xb;
  if (DAT_020b9474 == f_m1) {
    DAT_01c58654 = 0x10;
  }
  thunk_FUN_0054c590(&DAT_020b9440,&P1,&DAT_01c58654);
  P6 = P48;
  P10 = f_0;
  DAT_01c58654 = 1;
  while( true ) {
    DAT_01c5865c = (&ITEM_PTR0)[DAT_01c58648];
    iVar1 = FUN_00441157(&DAT_01c5865c);
    if (iVar1 != 0) break;
    local_88 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_01c585cc = (int)ROUND(*(float *)(&ITEM_P12 + DAT_01c5865c * 4));
    DAT_007f79f8 = 0xd;
    if (*(float *)(&ITEM_P14 + DAT_01c5865c * 4) == f_m1) {
      DAT_007f79f8 = 0x10;
    }
    DAT_007f79f4 = (DAT_007f79f8 + DAT_01c5865c) * 4 + 1;
    local_84 = DAT_01c585cc;
    FUN_004411bd(&ITEM_P1 + DAT_007f79f8 + DAT_01c5865c,1,&DAT_01c585cc,&DAT_01c58654);
    DAT_007f79f4 = DAT_01c58654 + -1;
    if (DAT_01c5864c == DAT_01c58648) {
      local_50 = 0;
      goto LAB_0044074d;
    }
    while( true ) {
      *(undefined1 *)((int)&DAT_009a9498 + DAT_01c58654 + 3) = 0x20;
      DAT_01c585e0._0_1_ = *(char *)((int)&DAT_009a9498 + DAT_01c58654 + 2);
      DAT_01c58654 = DAT_01c58654 + 1;
      if ((((char)DAT_01c585e0 != '!') && ((char)DAT_01c585e0 != '.')) &&
         ((char)DAT_01c585e0 != '?')) break;
      local_4c = 0;
    }
    DAT_01c58648 = DAT_01c58648 + 1;
    local_48 = 0;
  }
  local_54 = 0;
  DAT_01c58648 = DAT_01c58648 + -1;
LAB_0044074d:
  DAT_01c58658 = (DAT_01c58648 - DAT_0078d880) + 1;
  DAT_01c585cc = DAT_007f79f4;
  DAT_01c58660 = 0;
  DAT_01c585dc = 1;
  DAT_007f79f0 = 1;
  DAT_0078b4f0 = 0xffffffff;
  DAT_01c58674 = f_0;
  do {
    thunk_FUN_00470fc8(&DAT_009a949c,1);
    if (DAT_01c585c4 == 0) {
      DAT_01c585c4 = DAT_01c585cc;
    }
    local_8c = (DAT_01c585c4 - DAT_007f79f0) + 1;
    thunk_FUN_0042fa58(DAT_007f79f0 + 0x9a949b,1,&local_8c);
    DAT_01c58674 = P13 + DAT_01c58674;
    if ((DAT_007f79f0 != 1) || (DAT_01c58674 <= _DAT_01c58670)) {
      if ((_DAT_01c58670 < DAT_01c58674) || (DAT_01c585cc == DAT_01c585c4)) {
        local_40 = 0;
        if ((DAT_01c585cc == DAT_01c585c4) && (DAT_01c58674 <= _DAT_01c58670)) {
          local_38 = 0;
          goto LAB_004409a1;
        }
        DAT_01c58660 = DAT_01c58660 + 1;
        (&DAT_01e9997c)[DAT_01c58660] = DAT_007f79f0 + -1;
        if ((0xc6 < DAT_01c58660) || (DAT_01c585cc == DAT_01c585c4)) {
          local_34 = 0;
LAB_004409a1:
          DAT_01c58660 = DAT_01c58660 + 1;
          (&DAT_01e9997c)[DAT_01c58660] = DAT_01c585cc;
          DAT_01c58664 = 0;
          DAT_01c58668 = 1;
          DAT_01c585c4 = (&ITEM_PTR0)[EDIT_ITEM];
          _DAT_007f79e8 = DAT_020b944c;
          DAT_007f79e4 = DAT_020b945c;
          while( true ) {
            DAT_01c58664 = DAT_01c58664 + 1;
            DAT_01c585d4 = (&DAT_01e9997c)[DAT_01c58664];
            DAT_007f79e0 = DAT_01c585d4 + 1;
            for (; *(char *)((int)&DAT_009a9498 + DAT_01c58668 + 3) == ' ';
                DAT_01c58668 = DAT_01c58668 + 1) {
              local_24 = 0;
            }
            local_28 = 0;
            FUN_0044122d(&DAT_009a949c,1,&DAT_01fb8cf8,1);
            thunk_FUN_0042fa58(&DAT_01fb8cf8,1,&DAT_01c585c0);
            (&DAT_007f7a0c)[DAT_01c58664] = (int)P13;
            _DAT_007f79dc = 0xe;
            if (*(float *)(&ITEM_P14 + (&ITEM_PTR0)[EDIT_ITEM] * 4) == f_m1) {
              _DAT_007f79dc = 0x11;
            }
            thunk_FUN_0054c590(&ITEM_LEN + (&ITEM_PTR0)[EDIT_ITEM],&ITEM_LEN + ITEM_WORDS,
                               &DAT_007f79dc);
            if (DAT_007f7a04 != 0) {
              (&ITEM_P4)[ITEM_WORDS] = _DAT_007f79e8 - _DAT_01cb1070;
            }
            DAT_007f7a04 = 1;
            _DAT_007f79e8 = (float)(&ITEM_P4)[ITEM_WORDS];
            *(float *)(&ITEM_P8 + ITEM_WORDS * 4) = DAT_007f79e4;
            (&ITEM_P13)[ITEM_WORDS] = P13;
            *(float *)(&ITEM_P12 + ITEM_WORDS * 4) = (float)DAT_01c585c0;
            (&ITEM_P5)[ITEM_WORDS] = f_1;
            *(float *)(&ITEM_P10 + ITEM_WORDS * 4) = f_0;
            if ((DAT_01c58660 == DAT_01c58664) || (DAT_020b8ea2 != 'J')) {
              local_20 = 0;
            }
            else {
              DAT_01c58668 = 0;
              DAT_01c5865c = 1;
              for (local_1c = DAT_01c585c0; 0 < local_1c; local_1c = local_1c + -1) {
                if ((&DAT_01fb8cf7)[DAT_01c5865c] == ' ') {
                  DAT_01c58668 = DAT_01c58668 + 1;
                }
                DAT_01c5865c = DAT_01c5865c + 1;
              }
              if (DAT_01c58668 == 0) {
                local_18 = 0;
              }
              else {
                DAT_01cb1060 = DAT_01c58640;
                DAT_01cb1064 = DAT_01c58644;
                P48 = DAT_007f79fc;
                thunk_FUN_0042fa58(&DAT_01fb8cf8,1,&DAT_01c585c0);
                thunk_FUN_00471190();
                thunk_FUN_0042fa58(&DAT_01fb8cf8,1,&DAT_01c585c0);
                *(float *)(&ITEM_P10 + ITEM_WORDS * 4) = P10;
                (&ITEM_P13)[ITEM_WORDS] = P13;
              }
            }
            FUN_00441091(&DAT_01fb8cf8,1,&ITEM_WORDS,&DAT_01c585c0);
            DAT_01c5865c = (DAT_01c585c0 + 3) / 4 + _DAT_007f79dc;
            (&ITEM_LEN)[ITEM_WORDS] = (float)DAT_01c5865c;
            ITEM_WORDS = DAT_01c5865c + ITEM_WORDS + 1;
            ITEM_I = ITEM_I + 1;
            (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
            if (DAT_01c58664 < DAT_01c58658) {
              EDIT_ITEM = EDIT_ITEM + 1;
            }
            DAT_01c58668 = DAT_007f79e0;
            if (DAT_01c58660 == DAT_01c58664) break;
            local_14 = 0;
          }
          EDIT_ITEM = DAT_0078d880;
          DAT_01c585c4 = ITEM_WORDS - DAT_020b8e44;
          DAT_01c5865c = (&ITEM_PTR0)[DAT_01c58658 + DAT_0078d880] - (&ITEM_PTR0)[DAT_0078d880];
          DAT_01c585c8 = DAT_01c5865c - DAT_01c585c4;
          if (DAT_01c585c8 != 0) {
            DAT_01c58668 = DAT_007f79e0;
            if (DAT_01c585c8 < 1) {
              DAT_01c585cc = ITEM_WORDS;
              for (local_10 = (((&ITEM_PTR0)[DAT_01c58658 + DAT_0078d880] - ITEM_WORDS) + -1) / -1;
                  0 < local_10; local_10 = local_10 + -1) {
                (&ITEM_LEN)[DAT_01c585cc - DAT_01c585c8] = (&ITEM_LEN)[DAT_01c585cc];
                DAT_01c585cc = DAT_01c585cc + -1;
              }
              local_c = 0;
            }
            else {
              DAT_01c585cc = (&ITEM_PTR0)[DAT_01c58658 + DAT_0078d880];
              for (local_8 = (ITEM_WORDS - DAT_01c585cc) + 1; 0 < local_8; local_8 = local_8 + -1) {
                (&ITEM_LEN)[DAT_01c585cc - DAT_01c585c8] = (&ITEM_LEN)[DAT_01c585cc];
                DAT_01c585cc = DAT_01c585cc + 1;
              }
            }
          }
          ITEM_WORDS = DAT_020b8e44 - DAT_01c585c8;
          thunk_FUN_0054c590(&ITEM_LEN + ITEM_WORDS,&ITEM_LEN + (&ITEM_PTR0)[EDIT_ITEM],
                             &DAT_01c585c4);
          local_88 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
          DAT_01c5865c = (int)ROUND((float)(&ITEM_LEN)[(&ITEM_PTR0)[EDIT_ITEM]] + f_1);
          local_84 = DAT_01c5865c;
          thunk_FUN_0054c590(&ITEM_LEN + (&ITEM_PTR0)[EDIT_ITEM],&ITEM_LEN + ITEM_WORDS,
                             &DAT_01c5865c);
          DAT_0078b4e0 = 0;
          FUN_005f34d1(&stack0xfffffffc,0x441005);
          ITEM_I = DAT_007f7a0c;
          EDIT_ITEM = 0;
          draw_items();
          EDIT_ITEM = 0;
          P1 = f_0;
          DAT_0078b4e0 = 0xffffffff;
          FUN_005f33c9(puVar2,0x44105f);
          FUN_005f34d1(puVar2,0x44107a);
          P2 = (float)DAT_0078d880;
          return;
        }
        DAT_01c58674 = P13;
        DAT_01fb8cf8._0_1_ = DAT_00760754;
        thunk_FUN_0042fa58(&DAT_01fb8cf8,1,&DAT_00760750);
        DAT_007f79ec = DAT_007f79f0;
        while( true ) {
          DAT_01c58674 = DAT_01c58674 - P13;
          if ((&DAT_009a949c)[DAT_007f79ec] != ' ') break;
          local_30 = 0;
          DAT_007f79ec = DAT_007f79ec + 1;
        }
        local_2c = 0;
        DAT_007f79ec = DAT_007f79ec + 1;
      }
    }
    else {
      local_44 = 0;
    }
    DAT_007f79f0 = DAT_01c585c4 + 1;
    DAT_01c585dc = DAT_01c585c8;
    local_3c = 0;
  } while( true );
}


