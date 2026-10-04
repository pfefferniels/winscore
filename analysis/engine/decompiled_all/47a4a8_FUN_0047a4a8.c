// FUN_0047a4a8 @ 0047a4a8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047a4a8(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var2;
  float10 fVar3;
  uint local_ec;
  int local_e8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  int local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
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
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
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
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_008284c8 = 0;
  while( true ) {
    DAT_008284c8 = DAT_008284c8 + 1;
    while (DAT_008284c4 = (&ITEM_PTR0)[DAT_008284c8], (float)(&ITEM_P1)[DAT_008284c4] == f_8) {
      ffree(in_ST0);
      in_ST0 = thunk_FUN_005857c8(&DAT_008284c8);
      local_c0 = 0;
    }
    local_c4 = 0;
    if (ITEM_I <= DAT_008284c8) break;
    local_bc = 0;
  }
  ffree(in_ST0);
  Var2 = FUN_0047b2fd();
  local_b8 = 7;
  DAT_008284c4 = 1;
  do {
    DAT_008284c8 = DAT_01c2cc20;
    DAT_008284c0 = ITEM_WORDS;
    for (local_b4 = (DAT_01c2cc24 - DAT_01c2cc20) + 1; ITEM_WORDS = DAT_008284c0, 0 < local_b4;
        local_b4 = local_b4 + -1) {
      local_ec = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      local_e8 = (int)ROUND(*(float *)(&DAT_01c29bf8 + DAT_008284c4 * 0x3000 + DAT_008284c8 * 0x30))
      ;
      if (local_e8 == 0) {
        local_b0 = 0;
      }
      else {
        if (DAT_008284c4 < 6) {
          local_ac = 0;
          if (DAT_008284c4 == 5) {
            iVar1 = local_e8;
            *(undefined4 *)(&DAT_01c3bc10 + DAT_008284c8 * 0x30) =
                 *(undefined4 *)(&DAT_01c38c0c + DAT_008284c8 * 0x30);
            DAT_008284c0 = iVar1;
            P1 = *(float *)(&DAT_01c3bbf8 + DAT_008284c8 * 0x30);
            iVar1 = DAT_008284c0;
            if ((P1 != f_0) && (P1 < f_6)) {
              *(float *)(&DAT_01c3bbf8 + DAT_008284c8 * 0x30) = f_6;
              iVar1 = DAT_008284c0;
            }
          }
          else {
            local_88 = 0;
            iVar1 = local_e8;
          }
        }
        else {
          DAT_008284bc = 1;
          while( true ) {
            DAT_008284c0 = local_e8;
            DAT_008284b8 = (&ITEM_PTR0)[DAT_008284bc];
            local_ec = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
            local_e8 = (int)ROUND((float)(&ITEM_P2)[DAT_008284b8]);
            if (DAT_008284c8 == local_e8) {
              local_ec = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
              local_e8 = (int)ROUND((float)(&ITEM_P1)[DAT_008284b8]);
              DAT_008284b4 = local_e8;
              if (local_e8 < 3) {
                local_a4 = 0;
                iVar1 = DAT_008284c0;
                goto LAB_0047a83a;
              }
              if (-1 < local_e8 + -0x11) {
                if (local_e8 + -0x11 < 1) {
                  if (DAT_008284c4 == 6) {
                    ffree(Var2);
                    Var2 = thunk_FUN_005857c8(&DAT_008284bc);
                    DAT_008284bc = DAT_008284bc + -1;
                    local_9c = 0;
                  }
                  else {
                    local_a0 = 0;
                  }
                }
                else {
                  if (DAT_008284c4 == 7) {
                    *(float *)(&DAT_01c3ebf8 + DAT_008284c8 * 0x30) = f_0;
                    local_94 = 0;
                    goto LAB_0047a90d;
                  }
                  local_98 = 0;
                }
              }
            }
            else {
              local_a8 = 0;
              DAT_008284b4 = local_e8;
            }
            if (ITEM_I <= DAT_008284bc) break;
            DAT_008284bc = DAT_008284bc + 1;
            local_8c = 0;
            local_e8 = DAT_008284c0;
          }
          local_90 = 0;
          iVar1 = DAT_008284c0;
        }
LAB_0047a83a:
        DAT_008284c0 = iVar1;
        DAT_008284c0 = DAT_008284c0 + 1;
        if (DAT_008284c4 == 7) {
          local_84 = 0;
        }
        else {
          ffree(Var2);
          Var2 = thunk_FUN_0054c590(&DAT_01c29bf8 + DAT_008284c4 * 0x3000 + DAT_008284c8 * 0x30,
                                    &ITEM_LEN + ITEM_WORDS,&DAT_008284c0);
          if (DAT_008284c4 == 7) {
            *(float *)(&DAT_01c3ebf8 + DAT_008284c8 * 0x30) = f_0;
          }
          ITEM_WORDS = DAT_008284c0 + ITEM_WORDS;
          if (DAT_008284c4 == 5) {
            ffree(Var2);
            Var2 = thunk_FUN_0058554d(DAT_008284c8 * 0x30 + 0x1c38bf8);
          }
          else {
            local_80 = 0;
          }
        }
      }
LAB_0047a90d:
      local_7c = 0;
      DAT_008284c8 = DAT_008284c8 + 1;
      DAT_008284c0 = ITEM_WORDS;
    }
    local_78 = 0;
    DAT_008284c4 = DAT_008284c4 + 1;
    local_b8 = local_b8 + -1;
  } while (0 < local_b8);
  ffree(Var2);
  Var2 = thunk_FUN_0049836a(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I,&DAT_008284c0);
  DAT_0078b4e4 = 0x53;
  ffree(Var2);
  fVar3 = (float10)thunk_FUN_0049846f(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I);
  LOAD_I = 0;
  while( true ) {
    LOAD_I = LOAD_I + 1;
    ffree(fVar3);
    fVar3 = (float10)load_item_header();
    if (LOAD_CODE < 3) break;
    if (((LOAD_CODE == 0xe) && (4 < LOAD_LEN)) && ((float)(&ITEM_P5)[LOAD_W] == f_4)) {
      local_6c = (ITEM_I - (LOAD_I + 1)) + 1;
      DAT_008284c4 = LOAD_I;
      DAT_008284b4 = LOAD_W;
      LOAD_I = LOAD_I + 1;
      for (; 0 < local_6c; local_6c = local_6c + -1) {
        ffree(fVar3);
        fVar3 = (float10)load_item_header();
        if (LOAD_CODE < 3) {
          (&ITEM_P3)[DAT_008284b4] = LOAD_P3 - f_0_5;
          ffree(fVar3);
          fVar3 = (float10)thunk_FUN_0049846f(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I);
          local_64 = 0;
          goto LAB_0047ab2b;
        }
        local_68 = 0;
        local_60 = 0;
        LOAD_I = LOAD_I + 1;
      }
    }
    else {
      local_70 = 0;
    }
    if (ITEM_I <= LOAD_I) goto LAB_0047ab2b;
    local_5c = 0;
  }
  local_74 = 0;
LAB_0047ab2b:
  DAT_008284c8 = ITEM_I;
  for (local_58 = -ITEM_I / -1; 0 < local_58; local_58 = local_58 + -1) {
    DAT_008284c4 = (&ITEM_PTR0)[DAT_008284c8];
    if ((int)ROUND((float)(&ITEM_P1)[DAT_008284c4]) == 0xe) {
      local_54 = 0;
      break;
    }
    if ((int)ROUND((float)(&ITEM_P1)[DAT_008284c4]) == 0x12) {
      P1 = (float)(&ITEM_P3)[DAT_008284c4];
      DAT_008284bc = DAT_008284c8 + -1;
      for (iVar1 = -DAT_008284bc / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_008284c0 = (&ITEM_PTR0)[DAT_008284bc];
        if ((int)ROUND((float)(&ITEM_P1)[DAT_008284c0]) == 0xe) {
          if (P1 < (float)(&ITEM_P3)[DAT_008284c0]) {
            local_48 = 0;
            goto LAB_0047ae01;
          }
          local_44 = 0;
          break;
        }
        local_4c = 0;
        local_40 = 0;
        DAT_008284bc = DAT_008284bc + -1;
      }
      DAT_008284b4 = (int)ROUND((float)(&ITEM_LEN)[DAT_008284c4] + f_1);
      if (0xc < DAT_008284b4) {
        DAT_008284b4 = 0xc;
      }
      local_ec = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      DAT_008284c0 = (int)ROUND((float)(&ITEM_P2)[DAT_008284c4]);
      ffree(fVar3);
      local_e8 = DAT_008284c0;
      fVar3 = (float10)thunk_FUN_0054c590(&ITEM_LEN + DAT_008284c4,
                                          &DAT_01c3ebf8 + DAT_008284c0 * 0x30,&DAT_008284b4);
      if (DAT_008284b4 == 0xc) {
        *(float *)(&DAT_01c3ebf8 + DAT_008284c0 * 0x30) = f_11;
      }
      *(float *)(&DAT_01c3ec04 + DAT_008284c0 * 0x30) = f_15;
    }
    else {
      local_50 = 0;
    }
    local_3c = 0;
    DAT_008284c8 = DAT_008284c8 + -1;
  }
LAB_0047ae01:
  DAT_008284bc = 0;
  DAT_008284b0 = 0;
  DAT_008284c8 = 1;
  _DAT_008284ac = f_0;
  do {
    DAT_008284c4 = (&ITEM_PTR0)[DAT_008284c8];
    local_ec = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_008284b4 = (int)ROUND((float)(&ITEM_P1)[DAT_008284c4]);
    if (DAT_008284b4 == 0x11) {
      DAT_01ba0d4c = 0;
      local_ec = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      iVar1 = (int)ROUND((float)(&ITEM_P2)[DAT_008284c4]);
      DAT_008284c0 = iVar1;
      local_e8 = iVar1;
      if ((DAT_008284b0 != iVar1) || (_DAT_008284ac != (float)(&ITEM_P5)[DAT_008284c4])) {
        local_34 = 0;
        _DAT_008284ac = (float)(&ITEM_P5)[DAT_008284c4];
        fVar3 = (float10)(float)(&ITEM_P5)[DAT_008284c4];
        DAT_008284b0 = iVar1;
        if (ABS(fVar3) <= (float10)f_100) {
          local_ec = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
          local_e8 = (int)ROUND((float)(&ITEM_LEN)[DAT_008284c4] + f_1);
          DAT_008284b4 = local_e8;
          if (0xc < local_e8) {
            DAT_008284b4 = 0xc;
          }
          ffree(fVar3);
          fVar3 = (float10)thunk_FUN_0054c590(&ITEM_LEN + DAT_008284c4,&DAT_01c3bbf8 + iVar1 * 0x30,
                                              &DAT_008284b4);
          if (DAT_008284b4 == 0xc) {
            *(float *)(&DAT_01c3bbf8 + DAT_008284c0 * 0x30) = f_11;
          }
          *(float *)(&DAT_01c3bc04 + DAT_008284c0 * 0x30) = f_9;
          local_28 = 0;
        }
        else {
          local_2c = 0;
          *(float *)(&DAT_01c3bbf8 + iVar1 * 0x30) = f_0;
          if (DAT_008284bc == 0) {
            ffree(fVar3);
            fVar3 = (float10)thunk_FUN_005857c8(&DAT_008284c8);
            local_20 = 0;
            goto LAB_0047b0ae;
          }
          local_24 = 0;
        }
        goto LAB_0047b09f;
      }
      ffree(fVar3);
      fVar3 = (float10)thunk_FUN_005857c8(&DAT_008284c8);
      local_30 = 0;
    }
    else {
      local_38 = 0;
      local_e8 = DAT_008284b4;
      if (DAT_008284b4 < 3) {
        DAT_008284bc = 1;
        local_e8 = DAT_008284b4;
      }
LAB_0047b09f:
      DAT_008284c8 = DAT_008284c8 + 1;
    }
LAB_0047b0ae:
    if (ITEM_I < DAT_008284c8) break;
    local_1c = 0;
  } while( true );
  P1 = DAT_01ba0d38;
  P2 = f_0;
  if (DAT_01ba0d38 == f_0) {
    local_18 = 0;
  }
  else {
    P2 = DAT_01fbb8b8;
    ffree(fVar3);
    Var2 = thunk_FUN_005037af(&f_0,&P2,&DAT_007623c0,&ITEM_P1,&DAT_02091d20,&ITEM_I,&ITEM_WORDS);
    ffree(Var2);
    fVar3 = (float10)thunk_FUN_0058548e(&f_0,&P2,&P1,&P2);
  }
  local_ec = DAT_01c2cc24 + 1;
  ffree(fVar3);
  Var2 = thunk_FUN_0054c590(&DAT_01c41ce0,&STAFF_STEP0,&local_ec);
  P1 = f_0;
  P2 = f_0;
  if (DAT_01ba0d40 != 0) {
    ffree(Var2);
    Var2 = thunk_FUN_0055b1f8();
  }
  DAT_0078b4e0 = 0x4c;
  P2 = DAT_01fbb8b8;
  DAT_0078b4e4 = 0x4a;
  LOAD_I = ITEM_I;
  ffree(Var2);
  Var2 = load_item_header();
  if (((LOAD_CODE == 0xe) && (LOAD_LEN == 5)) && ((float)(&ITEM_P5)[LOAD_W] == f_1)) {
    LOAD_I = ITEM_I + -1;
    for (local_10 = -LOAD_I / -1; 0 < local_10; local_10 = local_10 + -1) {
      ffree(Var2);
      Var2 = load_item_header();
      if (LOAD_CODE < 3) {
        local_c = 0;
        goto LAB_0047b2be;
      }
      if (LOAD_CODE == 0xe) {
        local_8 = 0;
        break;
      }
      LOAD_I = LOAD_I + -1;
    }
    ffree(Var2);
    Var2 = thunk_FUN_005857c8(&ITEM_I);
  }
  else {
    local_14 = 0;
  }
LAB_0047b2be:
  ffree(Var2);
  Var2 = lineup_pass(&DAT_01c2cc20,&DAT_01c2cc24,&P1,&P2);
  ffree(Var2);
  Var2 = FUN_0047b668();
  DAT_01ba0d38 = (float)DAT_01ba0d34;
  ffree(Var2);
  return;
}


