// FUN_00542cda @ 00542cda (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00542cfa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00542cda(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 in_ST0;
  float10 fVar5;
  unkbyte10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  int local_10c;
  int local_108;
  int local_e0;
  int local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
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
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_0099f114 = 1;
  DAT_0099f110 = DAT_01fbb860;
  iVar2 = DAT_01fbb860;
  iVar4 = DAT_0099f0ec;
  for (local_e0 = (DAT_01fbb864 - DAT_01fbb860) + 1; DAT_0099f0ec = iVar2,
      DAT_01fbb860 = DAT_0099f0ec, 0 < local_e0; local_e0 = local_e0 + -1) {
    DAT_0099f118 = 0;
    _DAT_0099f11c = 0;
    _DAT_0099f10c = f_0;
    DAT_0099f108 = DAT_0099f114;
    for (local_dc = (ITEM_I - DAT_0099f114) + 1; DAT_0099f0ec = iVar4, 0 < local_dc;
        local_dc = local_dc + -1) {
      ffree(in_ST0);
      LOAD_I = DAT_0099f108;
      in_ST0 = (float10)load_item_header();
      if (((DAT_01e67914 < LOAD_P3) || (LOAD_STAFF < DAT_0099f110)) || (LOAD_P3 < DAT_01e67910)) {
        local_d8 = 0;
      }
      else {
        if (DAT_0099f110 < LOAD_STAFF) {
          local_d4 = 0;
          goto LAB_00542ea5;
        }
        if (LOAD_CODE == 1) {
          if (DAT_0099f118 == 0) {
            DAT_0099f118 = LOAD_I;
            _DAT_0099f104 = LOAD_P3;
            local_c8 = 0;
          }
          else {
            local_cc = 0;
            _DAT_0099f11c = LOAD_I;
            _DAT_0099f100 = LOAD_P3;
            _DAT_0099f10c = LOAD_P3;
          }
        }
        else {
          local_d0 = 0;
        }
      }
      local_c4 = 0;
      DAT_0099f108 = DAT_0099f108 + 1;
      iVar4 = DAT_0099f0ec;
    }
    DAT_0099f0fc = 0;
LAB_00542ea5:
    DAT_0099f0f8 = DAT_0099f114;
    DAT_0099f114 = DAT_0099f108;
    if (DAT_0099f0f4 == 0) {
      DAT_0099f108 = DAT_0099f0f8;
      for (local_bc = (ITEM_I - DAT_0099f0f8) + 1; 0 < local_bc; local_bc = local_bc + -1) {
        ffree(in_ST0);
        LOAD_I = DAT_0099f108;
        in_ST0 = (float10)load_item_header();
        if (((DAT_01e67914 < LOAD_P3) || (LOAD_P3 < DAT_01e67910)) ||
           ((LOAD_CODE != 5 || (LOAD_STAFF < DAT_0099f110)))) {
          local_b8 = 0;
        }
        else if ((LOAD_LEN < 8) || (*(float *)(&ITEM_P8 + LOAD_W * 4) < f_1)) {
          if (DAT_0099f110 < LOAD_STAFF) {
            local_b0 = 0;
            break;
          }
          DAT_0099f0f0 = LOAD_W;
          DAT_0099f0ec = LOAD_STAFF;
          DAT_0099f0e8 = LOAD_LEN;
          _DAT_0099f0e4 = LOAD_P3;
          _DAT_0099f0e0 = (float)(&ITEM_P6)[LOAD_W];
          _DAT_0099f0dc = (&ITEM_P4)[LOAD_W];
          _DAT_0099f0d8 = (&ITEM_P5)[LOAD_W];
          _DAT_0099f0d4 = *(float *)(&ITEM_P7 + LOAD_W * 4);
          DAT_0099f0d0 = 0;
          if ((7 < LOAD_LEN) &&
             (*(float *)(&ITEM_P8 + LOAD_W * 4) != f_m3 && *(float *)(&ITEM_P8 + LOAD_W * 4) != f_m2
             )) {
            DAT_0099f0d0 = 1;
          }
          if (_DAT_0099f104 <= LOAD_P3) {
            DAT_0099f0cc = DAT_0099f108 + -1;
            local_a8 = -DAT_0099f0cc / -1;
            if (0 < local_a8) {
LAB_005430cf:
              LOAD_I = DAT_0099f0cc;
              ffree(in_ST0);
              in_ST0 = (float10)load_item_header();
              if ((LOAD_CODE != 1) || (DAT_0099f0ec != LOAD_STAFF)) goto LAB_005430f9;
              if (_DAT_0099f0e4 - LOAD_P3 <= f_3) {
                local_10c = (&ITEM_P5)[LOAD_W];
                ffree(in_ST0);
                fVar5 = (float10)FUN_005ff874(&local_10c,&DAT_00768db8);
                DAT_0099f0c8 = (int)ROUND(fVar5 / (float10)f_10);
                local_10c = (&ITEM_P4)[LOAD_W];
                ffree(extraout_ST1);
                local_108 = DAT_0099f0c8;
                fVar5 = (float10)FUN_005ff874(&local_10c,&DAT_00768db8);
                _DAT_0099f0c4 = (float)fVar5;
                _DAT_0099f0c0 = *(float *)(&ITEM_P8 + LOAD_W * 4) + f_8;
                fVar5 = extraout_ST1_00;
                if (DAT_0099f0c8 == 2) {
                  fVar5 = (float10)_DAT_0099f0c0;
                  _DAT_0099f0c0 = (float)-fVar5;
                }
                _DAT_0099f0bc = _DAT_0099f0c0 + _DAT_0099f0c4;
                EDIT_ITEM = LOAD_I;
                DAT_0078b4e4 = 0x56;
                IP1 = 5;
                if (DAT_0099f0c8 == 2) {
                  fVar1 = f_0_5;
                  if (DAT_0099f0d0 != 0) {
                    fVar1 = f_2;
                  }
                  DAT_0099f0b8 = _DAT_0099f0c4 + fVar1;
                  (&ITEM_P4)[DAT_0099f0f0] = DAT_0099f0b8;
                  if (_DAT_0099f0d4 < f_0) {
                    fVar5 = (float10)_DAT_0099f0d4;
                    *(float *)(&ITEM_P7 + DAT_0099f0f0 * 4) = (float)-fVar5;
                  }
                }
                else {
                  fVar1 = f_0_5;
                  if (DAT_0099f0d0 != 0) {
                    fVar1 = f_2;
                  }
                  DAT_0099f0b8 = _DAT_0099f0c4 - fVar1;
                  (&ITEM_P4)[DAT_0099f0f0] = DAT_0099f0b8;
                  if (f_0 < _DAT_0099f0d4) {
                    fVar5 = (float10)_DAT_0099f0d4;
                    *(float *)(&ITEM_P7 + DAT_0099f0f0 * 4) = (float)-fVar5;
                  }
                }
                iVar2 = 1;
                iVar4 = DAT_0099f0f0;
                for (iVar3 = 1; iVar4 = iVar4 + 1, iVar3 < 9; iVar3 = iVar3 + 1) {
                  *(undefined4 *)(&DAT_020b943c + iVar2 * 4) = (&ITEM_LEN)[iVar4];
                  iVar2 = iVar2 + 1;
                }
                ffree(fVar5);
                in_ST0 = (float10)thunk_FUN_0042c9b0(&DAT_0099f0f0,&DAT_0099f0e8);
                (&ITEM_P4)[DAT_0099f0f0] = P6;
                (&ITEM_P5)[DAT_0099f0f0] = P8;
                EDIT_ITEM = 0;
                local_9c = 0;
                goto LAB_005436bb;
              }
              local_a0 = 0;
              goto LAB_0054368c;
            }
LAB_005433e0:
            if (_DAT_0099f0e0 <= _DAT_0099f10c) goto LAB_00543402;
            local_94 = 0;
          }
          else {
            local_ac = 0;
LAB_00543402:
            DAT_0099f0cc = DAT_0099f108 + 1;
            for (local_90 = (ITEM_I - DAT_0099f0cc) + 1; 0 < local_90; local_90 = local_90 + -1) {
              ffree(in_ST0);
              _DAT_0099f100 = f_m999;
              LOAD_I = DAT_0099f0cc;
              in_ST0 = (float10)load_item_header();
              if (DAT_0099f0ec < LOAD_STAFF) {
                local_8c = 0;
                break;
              }
              if ((LOAD_P3 < DAT_01e67910) || (DAT_01e67914 < LOAD_P3)) {
                local_88 = 0;
              }
              else {
                if (((_DAT_0099f0e0 <= LOAD_P3 + f_2) && (LOAD_CODE == 1)) &&
                   (DAT_0099f0ec == LOAD_STAFF)) {
                  _DAT_0099f100 = LOAD_P3;
                  DAT_0099f0fc = DAT_0099f0fc + 1;
                  if (DAT_0099f0fc < 2) {
                    local_10c = (&ITEM_P5)[LOAD_W];
                    ffree(in_ST0);
                    fVar5 = (float10)FUN_005ff874(&local_10c,&DAT_00768db8);
                    in_ST0 = extraout_ST1_01;
                    if ((float10)f_20 <= fVar5) {
                      if (_DAT_0099f0d4 < f_0) {
                        in_ST0 = (float10)_DAT_0099f0d4;
                        *(float *)(&ITEM_P7 + DAT_0099f0f0 * 4) = (float)-in_ST0;
                      }
                      DAT_0099f0b4 = (float)(&ITEM_P4)[LOAD_W] + f_0_5;
                      (&ITEM_P4)[DAT_0099f0f0] = DAT_0099f0b4;
                      (&ITEM_P5)[DAT_0099f0f0] = DAT_0099f0b4;
                    }
                    else {
                      if (f_0 < _DAT_0099f0d4) {
                        in_ST0 = (float10)_DAT_0099f0d4;
                        *(float *)(&ITEM_P7 + DAT_0099f0f0 * 4) = (float)-in_ST0;
                      }
                      DAT_0099f0b4 = (float)(&ITEM_P4)[LOAD_W] - f_0_5;
                      (&ITEM_P4)[DAT_0099f0f0] = DAT_0099f0b4;
                      (&ITEM_P5)[DAT_0099f0f0] = DAT_0099f0b4;
                    }
                    local_7c = 0;
                    goto LAB_005436bb;
                  }
                  local_80 = 0;
                  break;
                }
                local_84 = 0;
              }
              local_78 = 0;
              DAT_0099f0cc = DAT_0099f0cc + 1;
            }
          }
          if ((f_195 < _DAT_0099f0e0) || (_DAT_0099f0e0 < _DAT_0099f100 + f_2)) {
            local_74 = 0;
            break;
          }
LAB_0054368c:
          ffree(in_ST0);
          in_ST0 = (float10)FUN_0054037e(&DAT_0099f108);
          LOAD_I = LOAD_I + -1;
        }
        else {
          local_b4 = 0;
        }
LAB_005436bb:
        local_70 = 0;
        DAT_0099f108 = DAT_0099f108 + 1;
      }
    }
    else {
      local_c0 = 0;
    }
    local_6c = 0;
    DAT_0099f110 = DAT_0099f110 + 1;
    iVar2 = DAT_01fbb860;
    iVar4 = DAT_0099f0ec;
  }
  local_68 = (DAT_01fbb864 - DAT_0099f0ec) + 1;
  while( true ) {
    if (local_68 < 1) {
      ffree(in_ST0);
      return;
    }
    DAT_0099f108 = 1;
    local_64 = ITEM_I;
    if (0 < ITEM_I) break;
LAB_00543b4c:
    local_8 = 0;
    DAT_0099f0ec = DAT_0099f0ec + 1;
    local_68 = local_68 + -1;
  }
LAB_00543776:
  LOAD_I = DAT_0099f108;
  ffree(in_ST0);
  in_ST0 = (float10)load_item_header();
  if (((DAT_01e67914 < LOAD_P3) || (LOAD_P3 < DAT_01e67910)) ||
     ((LOAD_CODE != 5 || (DAT_0099f0ec != LOAD_STAFF)))) {
    local_60 = 0;
  }
  else if ((LOAD_LEN < 8) || (*(float *)(&ITEM_P8 + LOAD_W * 4) < f_1)) {
    DAT_0099f0b0 = (&DAT_02091d20)[DAT_0099f108];
    if (((float)(&ITEM_P1)[DAT_0099f0b0] == f_5) &&
       ((float)(&ITEM_P4)[DAT_0099f0b0] == (float)(&ITEM_P4)[LOAD_W])) {
      local_10c = LOAD_I + 1;
      ffree(in_ST0);
      in_ST0 = (float10)FUN_0054037e(&local_10c);
      local_54 = 0;
    }
    else {
      local_58 = 0;
      _DAT_0099f0ac = (float)(&ITEM_P6)[LOAD_W];
      _DAT_0099f100 = LOAD_P3;
      if (_DAT_0099f104 <= LOAD_P3) {
        DAT_0099f0cc = DAT_0099f108 + -4;
        for (local_4c = (ITEM_I - DAT_0099f0cc) + 1; 0 < local_4c; local_4c = local_4c + -1) {
          ffree(in_ST0);
          LOAD_I = DAT_0099f0cc;
          in_ST0 = (float10)load_item_header();
          if (DAT_0099f0ec != LOAD_STAFF) {
            local_48 = 0;
            goto LAB_00543b1a;
          }
          if ((LOAD_P3 < DAT_01e67910) || (DAT_01e67914 < LOAD_P3)) {
            local_44 = 0;
          }
          else if (LOAD_CODE == 1) {
            if (LOAD_P3 == _DAT_0099f10c) {
              local_3c = 0;
              goto LAB_00543b4c;
            }
            if (_DAT_0099f100 + f_3 < LOAD_P3) {
              local_38 = 0;
              goto LAB_00543afd;
            }
            if (ABS(LOAD_P3 - _DAT_0099f100) < f_3) {
              local_34 = 0;
              local_28 = (ITEM_I - DAT_0099f0cc) + 1;
              DAT_0099f0a8 = DAT_0099f0cc;
              goto joined_r0x00543a10;
            }
          }
          else {
            local_40 = 0;
          }
          local_30 = 0;
          DAT_0099f0cc = DAT_0099f0cc + 1;
        }
        local_2c = 0;
LAB_00543afd:
        ffree(in_ST0);
        in_ST0 = (float10)FUN_0054037e(&DAT_0099f108);
      }
      else {
        local_50 = 0;
      }
    }
  }
  else {
    local_5c = 0;
  }
  goto LAB_00543b1a;
LAB_005430f9:
  local_a4 = 0;
  local_98 = 0;
  DAT_0099f0cc = DAT_0099f0cc + -1;
  local_a8 = local_a8 + -1;
  if (local_a8 < 1) goto LAB_005433e0;
  goto LAB_005430cf;
joined_r0x00543a10:
  if (local_28 < 1) goto LAB_00543aed;
  ffree(in_ST0);
  LOAD_I = DAT_0099f0a8;
  in_ST0 = (float10)load_item_header();
  if (DAT_0099f0ec != LOAD_STAFF) {
    local_24 = 0;
    goto LAB_00543b1a;
  }
  if (((DAT_01e67914 < LOAD_P3) || (LOAD_CODE != 1)) || (LOAD_P3 < DAT_01e67910)) {
    local_20 = 0;
  }
  else {
    if (_DAT_0099f0ac + f_3 < LOAD_P3) {
      local_1c = 0;
      goto LAB_00543afd;
    }
    if (ABS(LOAD_P3 - _DAT_0099f0ac) < f_3) {
      local_18 = 0;
      goto LAB_00543b1a;
    }
  }
  local_14 = 0;
  DAT_0099f0a8 = DAT_0099f0a8 + 1;
  local_28 = local_28 + -1;
  goto joined_r0x00543a10;
LAB_00543aed:
  local_10 = 0;
LAB_00543b1a:
  local_c = 0;
  DAT_0099f108 = DAT_0099f108 + 1;
  local_64 = local_64 + -1;
  if (local_64 < 1) goto LAB_00543b4c;
  goto LAB_00543776;
}


