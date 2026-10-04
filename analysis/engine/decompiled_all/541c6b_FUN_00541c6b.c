// FUN_00541c6b @ 00541c6b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00541c6b(int *param_1,int *param_2,int *param_3,int *param_4)

{
  float fVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar3;
  float10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  float10 extraout_ST1_01;
  undefined4 local_f4;
  uint local_f0;
  int local_ec;
  int local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
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
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
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
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_01a1c380 = 0;
  DAT_0099ea64 = 1;
  for (local_c8 = ITEM_I; 0 < local_c8; local_c8 = local_c8 + -1) {
    ffree(in_ST0);
    LOAD_I = DAT_0099ea64;
    in_ST0 = (float10)load_item_header();
    if (*param_2 < LOAD_STAFF) {
      local_c4 = 0;
      break;
    }
    if (LOAD_STAFF < *param_2) {
      local_c0 = 0;
    }
    else if (LOAD_CODE == 5) {
      local_bc = 0;
      if ((LOAD_LEN < 8) || (*(float *)(&ITEM_P8 + LOAD_W * 4) < f_1)) {
        if (DAT_01e67910 <= LOAD_P3) {
          if (DAT_01e67914 < LOAD_P3) {
            local_90 = 0;
            break;
          }
          DAT_0099ea54 = (float)(&ITEM_P6)[LOAD_W];
          LOAD_I = DAT_0099ea64 + 1;
          _DAT_0099ea58 = LOAD_P3;
          for (iVar2 = (ITEM_I - LOAD_I) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
            ffree(in_ST0);
            in_ST0 = (float10)load_item_header();
            if (*param_2 < LOAD_STAFF) {
              local_8c = 0;
              break;
            }
            if ((*param_4 == 0) && (LOAD_CODE == 5)) {
              if ((_DAT_0099ea58 == LOAD_P3) && (DAT_0099ea54 == (float)(&ITEM_P6)[LOAD_W])) {
                (&ITEM_P1)[LOAD_W] = f_99;
              }
            }
            else {
              local_88 = 0;
            }
            local_84 = 0;
            LOAD_I = LOAD_I + 1;
          }
        }
        else {
          local_94 = 0;
        }
      }
      else {
        local_98 = 0;
      }
    }
    else {
      if (LOAD_CODE == 6) {
        DAT_0099ea60 = DAT_0099ea64 + 1;
        for (local_b4 = (ITEM_I - DAT_0099ea60) + 1; 0 < local_b4; local_b4 = local_b4 + -1) {
          DAT_0099ea5c = (&ITEM_PTR0)[DAT_0099ea60];
          if (((LOAD_P3 == (float)(&ITEM_P3)[DAT_0099ea5c]) &&
              ((float)(&ITEM_P1)[DAT_0099ea5c] == f_6)) &&
             ((float)LOAD_STAFF == (float)(&ITEM_P2)[DAT_0099ea5c])) {
            if ((float)(&ITEM_P6)[DAT_0099ea5c] == (float)(&ITEM_P6)[LOAD_W]) {
              if (*param_1 == 1) {
                if (f_20 <= *(float *)(&ITEM_P7 + DAT_0099ea5c * 4)) {
                  (&ITEM_P1)[DAT_0099ea5c] = f_99;
                }
                if (f_20 <= *(float *)(&ITEM_P7 + LOAD_W * 4)) {
                  (&ITEM_P1)[LOAD_W] = f_99;
                }
              }
              else {
                if (*(float *)(&ITEM_P7 + DAT_0099ea5c * 4) < f_20) {
                  (&ITEM_P1)[DAT_0099ea5c] = f_99;
                }
                if (*(float *)(&ITEM_P7 + LOAD_W * 4) < f_20) {
                  (&ITEM_P1)[LOAD_W] = f_99;
                }
              }
            }
            else {
              local_ac = 0;
            }
          }
          else {
            local_b0 = 0;
          }
          local_a8 = 0;
          DAT_0099ea60 = DAT_0099ea60 + 1;
        }
      }
      else {
        local_b8 = 0;
      }
      if ((LOAD_CODE == 1) && (10 < LOAD_LEN)) {
        if (*(float *)(&ITEM_P11 + LOAD_W * 4) == f_0) {
          local_a0 = 0;
        }
        else {
          DAT_01a1c380 = DAT_01a1c380 + 1;
          if (100 < DAT_01a1c380) {
            DAT_01a1c380 = 100;
          }
          (&DAT_01a1c380)[DAT_01a1c380] = (int)LOAD_P3;
          local_f0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
          local_ec = (int)ROUND(*(float *)(&ITEM_P11 + LOAD_W * 4));
          (&DAT_01a1c510)[DAT_01a1c380] = local_ec;
          local_9c = 0;
        }
      }
      else {
        local_a4 = 0;
      }
    }
    local_80 = 0;
    DAT_0099ea64 = DAT_0099ea64 + 1;
  }
  DAT_0099ea50 = 0;
  DAT_0099ea4c = f_0;
  DAT_0099ea48 = f_0;
  LOAD_I = 1;
LAB_0054218e:
  do {
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    if (*param_2 < LOAD_STAFF) {
LAB_00542cc3:
      _DAT_0099ea08 = f_1;
      ffree(in_ST0);
      return;
    }
    if ((LOAD_CODE < 3) && (LOAD_STAFF == *param_2)) {
      if (LOAD_CODE < 3) {
        if (LOAD_P3 < DAT_01e67910) {
          local_70 = 0;
        }
        else {
          if (DAT_01e67914 < LOAD_P3) goto LAB_00542cc3;
          if (*param_3 == 0) {
            local_68 = 0;
          }
          else if ((LOAD_CODE == 2) && ((float)(&ITEM_P6)[LOAD_W] < f_0)) {
            local_64 = 0;
            goto LAB_00542c88;
          }
          DAT_0099ea44 = (&DAT_02091d20)[LOAD_I];
          if (LOAD_P3 == (float)(&ITEM_P3)[DAT_0099ea44]) {
            if ((float)(&ITEM_P4)[LOAD_W] == (float)(&ITEM_P4)[DAT_0099ea44]) {
              if ((LOAD_CODE == 1) && ((float)(&ITEM_P1)[DAT_0099ea44] == f_1)) {
                if (9 < LOAD_LEN) {
                  *(float *)(&ITEM_P10 + LOAD_W * 4) = f_0;
                }
                local_f4 = (&ITEM_P5)[DAT_0099ea44];
                ffree(in_ST0);
                fVar3 = (float10)FUN_005ff874(&local_f4,&DAT_00768db8);
                if ((float10)f_20 <= fVar3) {
                  P2 = (float)LOAD_I;
                  local_ec = LOAD_I + 1;
                  P3 = (float)local_ec;
                  ffree(extraout_ST1);
                  in_ST0 = (float10)thunk_FUN_0058adc1(&DAT_00768bf8);
                  local_50 = 0;
                  goto LAB_0054218e;
                }
                local_54 = 0;
                in_ST0 = extraout_ST1;
              }
              else {
                local_58 = 0;
              }
            }
            else {
              local_5c = 0;
            }
          }
          else {
            local_60 = 0;
          }
          DAT_0099ea40 = LOAD_I;
          DAT_0099ea3c = LOAD_I;
          if (*(float *)(&ITEM_P7 + LOAD_W * 4) <= f_0) {
            ffree(in_ST0);
            in_ST0 = (float10)FUN_005419d4(&LOAD_W,&LOAD_LEN);
          }
          DAT_0099ea54 = *(float *)(&ITEM_P7 + LOAD_W * 4);
          if (DAT_0099ea54 == f_64) {
            DAT_0099ea54 = f_65;
          }
          _DAT_0099ea38 = DAT_0099ea54;
          if ((DAT_0099ea54 == f_65) ||
             (in_ST0 = (float10)(float)(&ITEM_P4)[DAT_0099ea44], ABS(in_ST0) <= (float10)f_99)) {
            fVar1 = DAT_0099ea4c - DAT_0099ea48;
            if (0.0 <= fVar1 && fVar1 != 0.0) {
              DAT_0099ea54 = f_0;
              local_48 = 0;
            }
            else {
              iVar2 = LOAD_I;
              if (fVar1 == 0.0) {
                while( true ) {
                  DAT_0099ea34 = iVar2 + 1;
                  DAT_0099ea44 = (&ITEM_PTR0)[DAT_0099ea34];
                  local_f0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                  local_ec = (int)ROUND((float)(&ITEM_P2)[DAT_0099ea44]);
                  if (LOAD_STAFF != local_ec) break;
                  if (LOAD_P3 < (float)(&ITEM_P3)[DAT_0099ea44]) {
                    local_3c = 0;
                    goto LAB_0054287d;
                  }
                  if (*param_3 == 0) {
                    local_38 = 0;
LAB_00542583:
                    if ((float)(&ITEM_P1)[DAT_0099ea44] <= f_2) {
                      if (*(float *)(&ITEM_P7 + DAT_0099ea44 * 4) <= f_0) {
                        local_f0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                        _DAT_0099ea30 = (int)ROUND((float)(&ITEM_LEN)[DAT_0099ea44]);
                        ffree(in_ST0);
                        local_ec = _DAT_0099ea30;
                        in_ST0 = (float10)FUN_005419d4(&DAT_0099ea44,&DAT_0099ea30);
                      }
                      DAT_0099ea54 = *(float *)(&ITEM_P7 + DAT_0099ea44 * 4);
                      LOAD_I = DAT_0099ea34;
                      DAT_0099ea40 = DAT_0099ea34;
                      if (DAT_0099ea54 == f_64) {
                        DAT_0099ea54 = f_65;
                      }
                      if ((DAT_0099ea54 != f_65) &&
                         (in_ST0 = (float10)(float)(&ITEM_P4)[DAT_0099ea44],
                         (float10)f_99 < ABS(in_ST0))) {
                        local_2c = 0;
                        goto LAB_00542c88;
                      }
                      _DAT_0099ea2c = (float)(&ITEM_P4)[LOAD_W];
                      if (LOAD_CODE == 2) {
                        _DAT_0099ea2c = _DAT_0099ea2c + f_5;
                      }
                      _DAT_0099ea28 = (float)(&ITEM_P4)[DAT_0099ea44];
                      if ((float)(&ITEM_P1)[DAT_0099ea44] == f_2) {
                        _DAT_0099ea28 = _DAT_0099ea28 + f_5;
                      }
                      if (_DAT_0099ea28 < _DAT_0099ea2c) {
                        ffree(in_ST0);
                        in_ST0 = (float10)thunk_FUN_0054c669(&DAT_0099ea54,&DAT_0099ea38);
                      }
                      if (LOAD_P3 == (float)(&ITEM_P3)[DAT_0099ea44]) {
                        local_28 = 0;
                      }
                      else if (DAT_0099ea48 == DAT_0099ea4c) {
                        local_24 = 0;
                      }
                      else if (DAT_0099ea48 <= DAT_0099ea4c) {
                        if ((float)(&ITEM_P3)[DAT_0099ea44] < LOAD_P3) {
                          DAT_0099ea54 = f_0;
                          _DAT_0099ea38 = *(float *)(&ITEM_P7 + DAT_0099ea44 * 4);
                          if (_DAT_0099ea38 == f_64) {
                            _DAT_0099ea38 = f_65;
                          }
                        }
                      }
                      else if (LOAD_P3 < (float)(&ITEM_P3)[DAT_0099ea44]) {
                        DAT_0099ea54 = *(float *)(&ITEM_P7 + DAT_0099ea44 * 4);
                        _DAT_0099ea38 = f_0;
                        DAT_0099ea40 = DAT_0099ea34;
                        if (DAT_0099ea54 == f_64) {
                          DAT_0099ea54 = f_65;
                        }
                      }
                      goto LAB_0054287d;
                    }
                  }
                  else {
                    if (((float)(&ITEM_P1)[DAT_0099ea44] != f_2) ||
                       (f_0 <= (float)(&ITEM_P6)[DAT_0099ea44])) goto LAB_00542583;
                    local_34 = 0;
                  }
                  local_30 = 0;
                  iVar2 = DAT_0099ea34;
                }
                local_40 = 0;
                goto LAB_00542c88;
              }
              _DAT_0099ea38 = f_0;
              local_44 = 0;
            }
LAB_0054287d:
            DAT_0099ea50 = DAT_0099ea50 + 1;
            DAT_0099ea4c = DAT_0099ea54 + DAT_0099ea4c;
            DAT_0099ea48 = _DAT_0099ea38 + DAT_0099ea48;
            (&DAT_0099ef14)[DAT_0099ea50] = DAT_0099ea4c;
            (&DAT_0099ed84)[DAT_0099ea50] = DAT_0099ea48;
            if (DAT_0099ea50 == 1) {
              local_20 = 0;
            }
            else {
              if (DAT_0099ea48 == *(float *)(DAT_0099ea50 * 4 + 0x99ed80)) {
                DAT_0099ea3c = (&DAT_0099ea60)[DAT_0099ea50];
              }
              if (DAT_0099ea4c == *(float *)(DAT_0099ea50 * 4 + 0x99ef10)) {
                DAT_0099ea40 = *(int *)(DAT_0099ea50 * 4 + 0x99ebf0);
              }
            }
            (&DAT_0099ea64)[DAT_0099ea50] = DAT_0099ea3c;
            (&DAT_0099ebf4)[DAT_0099ea50] = DAT_0099ea40;
            if (DAT_0099ea3c == DAT_0099ea40) {
              local_1c = 0;
            }
            else {
              local_f4 = (&ITEM_P5)[(&ITEM_PTR0)[DAT_0099ea3c]];
              ffree(in_ST0);
              fVar3 = (float10)FUN_005ff874(&local_f4,&DAT_00768db8);
              local_f0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
              DAT_0099ea24 = (int)ROUND(fVar3 / (float10)f_10);
              local_f4 = (&ITEM_P5)[(&ITEM_PTR0)[DAT_0099ea40]];
              ffree(extraout_ST1_00);
              local_ec = DAT_0099ea24;
              fVar3 = (float10)FUN_005ff874(&local_f4,&DAT_00768db8);
              local_f0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
              local_ec = (int)ROUND(fVar3 / (float10)f_10);
              if ((float)(&ITEM_P1)[(&ITEM_PTR0)[DAT_0099ea3c]] == f_2) {
                DAT_0099ea24 = -1;
              }
              DAT_0099ea20 = local_ec;
              if ((float)(&ITEM_P1)[(&ITEM_PTR0)[DAT_0099ea40]] == f_2) {
                DAT_0099ea20 = -1;
              }
              DAT_0099ea1c = DAT_0099ea40;
              if (*param_1 == 1) {
                DAT_0099ea1c = DAT_0099ea3c;
              }
              (&ITEM_P1)[(&ITEM_PTR0)[DAT_0099ea1c]] = f_99;
              _DAT_0099ea18 = (&ITEM_P4)[(&ITEM_PTR0)[DAT_0099ea1c]];
              _DAT_0099ea10 = LOAD_P3 + f_2;
              DAT_0099ea40 = DAT_0099ea3c;
              DAT_0099ea14 = LOAD_I;
              LOAD_I = DAT_0099ea3c;
              in_ST0 = extraout_ST1_01;
              for (iVar2 = (ITEM_I - DAT_0099ea3c) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
                ffree(in_ST0);
                in_ST0 = (float10)load_item_header();
                if ((_DAT_0099ea10 < LOAD_P3) || (*param_2 < LOAD_STAFF)) {
                  local_18 = 0;
                  break;
                }
                if (LOAD_CODE == 6) {
                  if ((DAT_0099ea24 == 0) || (DAT_0099ea20 == 0)) {
                    local_10 = 0;
                  }
                  else {
                    local_f0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                    local_ec = (int)ROUND(*(float *)(&ITEM_P7 + LOAD_W * 4) / f_10);
                    if (*param_1 == 2) {
                      DAT_0099ea24 = DAT_0099ea20;
                    }
                    DAT_0099ea0c = local_ec;
                    if (local_ec == DAT_0099ea24) {
                      (&ITEM_P1)[LOAD_W] = f_99;
                    }
                  }
                }
                else {
                  local_14 = 0;
                }
                local_c = 0;
                LOAD_I = LOAD_I + 1;
              }
              LOAD_I = DAT_0099ea14;
            }
          }
          else {
            local_4c = 0;
          }
        }
      }
      else {
        local_74 = 0;
      }
    }
    else {
      local_78 = 0;
    }
LAB_00542c88:
    LOAD_I = LOAD_I + 1;
    if (ITEM_I < LOAD_I) goto LAB_00542cc3;
    local_8 = 0;
  } while( true );
}


