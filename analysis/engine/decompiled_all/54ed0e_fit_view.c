// fit_view @ 0054ed0e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fit_view(int *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  undefined4 local_d4;
  uint local_d0;
  float local_cc;
  int local_a8;
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
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  int local_4c;
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
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*param_1 != 1) {
    DAT_009a2bfc = PAPER;
    PAPER = 0;
    DAT_009a2bf8 = DAT_01c585d8;
    ffree(in_ST0);
    in_ST0 = (float10)draw_items();
    DAT_01c585d8 = DAT_009a2bf8;
    PAPER = DAT_009a2bfc;
  }
  DAT_009a2bf4 = (uint)(*param_1 < 0);
  *param_3 = 7.78498e-40;
  DAT_009a2bf0 = *param_3;
  *param_2 = (float)-(int)*param_3;
  DAT_009a2bec = *param_2;
  *param_5 = *param_2;
  *param_4 = *param_3;
  DAT_009a2be8 = 1;
  fVar1 = _DAT_009a2b98;
  local_a8 = ITEM_I;
  do {
    _DAT_009a2b98 = fVar1;
    if (local_a8 < 1) {
      if (*param_5 == -NAN) {
        *param_5 = 0.0;
      }
      if (*param_4 == 7.78498e-40) {
        *param_4 = 0.0;
      }
      if (*param_2 == -NAN) {
        *param_2 = 0.0;
      }
      if (*param_3 == 7.78498e-40) {
        *param_3 = 0.0;
      }
      *param_5 = (float)((int)*param_5 + 0x32);
      *param_4 = (float)((int)*param_4 + -0x32);
      DAT_009a2ba4 = *param_2;
      _DAT_009a2ba0 = *param_3;
      IP6 = 0;
      *param_2 = (float)(VIEW_DY + (int)*param_2);
      *param_3 = (float)((int)*param_3 + VIEW_DY + -0x32);
      DAT_01be6ca4 = *param_4;
      DAT_01be6cac = *param_5;
      DAT_01be6ca8 = *param_3;
      DAT_01be6cb0 = *param_2;
      if (-1 < *param_1) {
        ffree(in_ST0);
        Var3 = thunk_FUN_00579770(&DAT_00769284,1,&IP1);
        _DAT_01be6ca0 = IP2;
        _DAT_01b12d48 = IP1;
        IP2 = ((int)DAT_009a2ba4 - (int)_DAT_009a2ba0) + 4000;
        IP10 = IP1;
        IP3 = (int)*param_5 - (int)*param_4;
        IP4 = (int)*param_2 - (int)*param_3;
        if (IP4 < 60000) {
          IP4 = 60000;
        }
        ffree(Var3);
        IP1 = (int)*param_5 + 0x4b0;
        in_ST0 = (float10)thunk_FUN_00579770(&DAT_0076927c,1,&IP1);
        if ((*param_1 != 1) && (*param_1 != 2)) {
          if ((undefined *)(_DAT_020b90a0 & 0xffffff) == &DAT_00544f42) {
            *param_2 = (float)((int)*param_2 + -1000);
          }
          VIEW_DY = (int)*param_2 + 3000;
        }
        *param_2 = DAT_01be6cb0;
        *param_3 = DAT_01be6ca8;
      }
      ffree(in_ST0);
      return;
    }
    DAT_009a2be4 = (&ITEM_PTR0)[DAT_009a2be8];
    local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_009a2be0 = (float)(int)ROUND((float)(&ITEM_P1)[DAT_009a2be4]);
    local_cc = DAT_009a2be0;
    if (*param_1 == -2) {
      if ((DAT_009a2bf4 != 1) || (f_200 <= (float)(&ITEM_P2)[DAT_009a2be4])) {
LAB_0054ee9b:
        if ((*(float *)(&ITEM_P11 + DAT_009a2be4 * 4) == f_0) ||
           ((DAT_009a2be0 != 1.26117e-44 || ((float)(&ITEM_LEN)[DAT_009a2be4] <= f_10_5)))) {
          if ((f_0 <= *(float *)(&ITEM_P7 + DAT_009a2be4 * 4)) ||
             ((DAT_009a2be0 != 1.12104e-44 || ((float)(&ITEM_LEN)[DAT_009a2be4] < f_7)))) {
            if (DAT_009a2be0 == 1.96182e-44) {
              if (*param_1 != 2) {
                local_90 = 0;
                goto LAB_00550133;
              }
              local_94 = 0;
            }
            if ((DAT_009a2be0 == 1.12104e-44) || (*param_1 != 0x53)) {
              if (DAT_009a2be0 == 9.80909e-45) {
                DAT_009a2bdc = 0.0;
                if (f_6 < (float)(&ITEM_LEN)[DAT_009a2be4]) {
                  local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                  DAT_009a2bdc = (float)(int)ROUND(*(float *)(&ITEM_P7 + DAT_009a2be4 * 4));
                  local_cc = DAT_009a2bdc;
                }
                if ((((DAT_009a2bdc == 2.17201e-43) || (DAT_009a2bdc == 1.23314e-43)) ||
                    (DAT_009a2bdc == 2.10195e-44)) ||
                   ((DAT_009a2bdc == 1.12104e-44 || (DAT_009a2bdc == -NAN)))) {
                  DAT_009a2bd8 = (float)(&ITEM_P5)[DAT_009a2be4];
                  if (DAT_009a2bd8 == f_0) {
                    DAT_009a2bd8 = f_1;
                  }
                  _DAT_009a2bd4 = DAT_009a2bd8;
                  local_84 = 0;
LAB_0054f356:
                  DAT_009a2bcc = (int)ROUND((float)(&ITEM_P2)[DAT_009a2be4]);
                  _DAT_009a2bc8 = (float)(&STAFF_STEP0)[DAT_009a2bcc] / f_25;
                  _DAT_009a2bc4 = (float)(&ITEM_P13)[DAT_009a2be4] * f_150;
                  for (DAT_009a2bdc = *(float *)(&DAT_020a559c + DAT_009a2be8 * 4);
                      *(char *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
                               (int)DAT_009a2bdc * DAT_01fbb83c) != '\0';
                      DAT_009a2bdc = (float)((int)DAT_009a2bdc + 1)) {
                    local_58 = 0;
                  }
                  local_5c = 0;
                  DAT_009a2bdc = (float)((int)DAT_009a2bdc + 4);
                  local_54 = 4;
                  DAT_009a2bd0 = 1;
                  do {
                    DAT_009a2bdc = (float)((int)DAT_009a2bdc + 1);
                    *(undefined1 *)(DAT_009a2bd0 + 0x9a2b97) =
                         *(undefined1 *)
                          ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
                          (int)DAT_009a2bdc * DAT_01fbb83c);
                    DAT_009a2bd0 = DAT_009a2bd0 + 1;
                    local_54 = local_54 + -1;
                  } while (0 < local_54);
                  _DAT_009a2bd4 = (_DAT_009a2bd4 + f_0_15) * f_630 * _DAT_009a2bc8;
                  DAT_009a2bdc = (float)((int)DAT_009a2bdc + 0x14);
                  local_50 = 4;
                  DAT_009a2bd0 = 1;
                  do {
                    DAT_009a2bdc = (float)((int)DAT_009a2bdc + 1);
                    *(undefined1 *)(DAT_009a2bd0 + 0x9a2b97) =
                         *(undefined1 *)
                          ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
                          (int)DAT_009a2bdc * DAT_01fbb83c);
                    DAT_009a2bd0 = DAT_009a2bd0 + 1;
                    local_50 = local_50 + -1;
                  } while (0 < local_50);
                  DAT_009a2bc0 = _DAT_009a2b98;
                  local_4c = 4;
                  DAT_009a2bd0 = 1;
                  do {
                    DAT_009a2bdc = (float)((int)DAT_009a2bdc + 1);
                    *(undefined1 *)(DAT_009a2bd0 + 0x9a2b97) =
                         *(undefined1 *)
                          ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
                          (int)DAT_009a2bdc * DAT_01fbb83c);
                    DAT_009a2bd0 = DAT_009a2bd0 + 1;
                    local_4c = local_4c + -1;
                  } while (0 < local_4c);
                  DAT_009a2bbc = _DAT_009a2b98;
                  local_48 = 4;
                  DAT_009a2bd0 = 1;
                  do {
                    DAT_009a2bdc = (float)((int)DAT_009a2bdc + 1);
                    *(undefined1 *)(DAT_009a2bd0 + 0x9a2b97) =
                         *(undefined1 *)
                          ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
                          (int)DAT_009a2bdc * DAT_01fbb83c);
                    DAT_009a2bd0 = DAT_009a2bd0 + 1;
                    local_48 = local_48 + -1;
                  } while (0 < local_48);
                  _DAT_009a2bb8 = ((_DAT_009a2bd4 - f_94_5) / f_630 - f_1) * f_200;
                  local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                  DAT_009a2bb4 = (float)(int)ROUND((float)(int)_DAT_009a2b98 - _DAT_009a2bb8);
                  local_cc = DAT_009a2bb4;
                  if ((DAT_009a2bb4 == 0.0) && (DAT_009a2bbc == 0.0)) {
                    local_44 = 0;
                  }
                  else if (((int)DAT_009a2bb4 < -200000) || (100000 < (int)DAT_009a2bb4)) {
                    local_40 = 0;
                  }
                  else {
                    if ((-0x30d41 < (int)DAT_009a2bbc) && ((int)DAT_009a2bbc < 0x186a1)) {
                      if ((int)DAT_009a2bb4 < (int)*param_3) {
                        *param_3 = DAT_009a2bb4;
                      }
                      DAT_009a2bb4 = (float)(int)ROUND((float)(int)DAT_009a2bb4 + _DAT_009a2bd4);
                      if ((int)*param_2 < (int)DAT_009a2bb4) {
                        *param_2 = DAT_009a2bb4;
                      }
                      if ((int)DAT_009a2bbc < (int)*param_4) {
                        *param_4 = DAT_009a2bbc;
                      }
                      local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                      local_cc = (float)(int)ROUND((float)(int)DAT_009a2bbc + _DAT_009a2bc4);
                      DAT_009a2bbc = local_cc;
                      if ((int)*param_5 < (int)local_cc) {
                        *param_5 = local_cc;
                      }
                      DAT_009a2bdc = (float)((int)DAT_009a2bdc + 2);
                      while (DAT_009a2bc0 = (float)((int)DAT_009a2bc0 + -1), 0 < (int)DAT_009a2bc0)
                      {
                        DAT_009a2bdc = (float)((int)DAT_009a2bdc + 10);
                        local_34 = 0;
                      }
                      local_38 = 0;
                      goto LAB_0054f839;
                    }
                    local_3c = 0;
                  }
                  goto LAB_00550133;
                }
                local_88 = 0;
              }
              else if (DAT_009a2be0 == 1.26117e-44) {
                DAT_009a2bd8 = f_1;
                if (f_6 <= (float)(&ITEM_LEN)[DAT_009a2be4]) {
                  DAT_009a2bd8 = (float)(&ITEM_P6)[DAT_009a2be4];
                }
                _DAT_009a2bd4 = f_1;
                if (f_7 <= (float)(&ITEM_LEN)[DAT_009a2be4]) {
                  _DAT_009a2bd4 = *(float *)(&ITEM_P7 + DAT_009a2be4 * 4);
                }
                if (_DAT_009a2bd4 == f_0) {
                  _DAT_009a2bd4 = DAT_009a2bd8;
                }
                if (f_5 <= (float)(&ITEM_LEN)[DAT_009a2be4]) {
                  local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                  local_cc = (float)(int)ROUND((float)(&ITEM_P5)[DAT_009a2be4]);
                  local_7c = 0x15;
                  DAT_009a2bcc = 1;
                  do {
                    if (local_cc == *(float *)(s__XNADQ_0079d6f5 + DAT_009a2bcc * 4 + 3)) {
                      local_78 = 0;
                      goto LAB_0054f356;
                    }
                    DAT_009a2bcc = DAT_009a2bcc + 1;
                    local_7c = local_7c + -1;
                  } while (0 < local_7c);
                  local_74 = 0;
                }
                else {
                  local_80 = 0;
                }
              }
              else {
                if ((DAT_009a2be0 == 2.24208e-44) || (DAT_009a2be0 == 1.4013e-44)) {
                  DAT_009a2b9a = (char)((uint)fVar1 >> 0x10);
                  if ((DAT_009a2b9a == '9') &&
                     ((DAT_009a2b98 = SUB41(fVar1,0), DAT_009a2b98 == '_' &&
                      (DAT_009a2b99 = (char)((uint)fVar1 >> 8), DAT_009a2b99 == '9')))) {
                    local_6c = 0;
                    goto LAB_00550133;
                  }
                  if (DAT_009a2be0 == 1.4013e-44) {
                    if (*(float *)(&ITEM_P7 + DAT_009a2be4 * 4) == f_1094) {
                      local_64 = 0;
                      goto LAB_0054f839;
                    }
                    _DAT_009a2bd4 = f_1;
                    if (f_6 <= (float)(&ITEM_LEN)[DAT_009a2be4]) {
                      fVar2 = (float10)amod(&ITEM_P6 + DAT_009a2be4,&f_100);
                      _DAT_009a2bd4 = (float)fVar2;
                      in_ST0 = extraout_ST1_00;
                    }
                    local_60 = 0;
                  }
                  else {
                    local_68 = 0;
                    fVar2 = (float10)amod(&ITEM_P7 + DAT_009a2be4 * 4,&f_100);
                    _DAT_009a2bd4 = (float)fVar2;
                    in_ST0 = extraout_ST1;
                  }
                  DAT_009a2bd8 = f_0;
                  if (f_5 < (float)(&ITEM_LEN)[DAT_009a2be4]) {
                    fVar2 = (float10)amod(&ITEM_P6 + DAT_009a2be4,&f_100);
                    DAT_009a2bd8 = (float)fVar2;
                    in_ST0 = extraout_ST1_01;
                  }
                  if (DAT_009a2bd8 == f_0) {
                    DAT_009a2bd8 = f_1;
                  }
                  if (_DAT_009a2bd4 == f_0) {
                    _DAT_009a2bd4 = DAT_009a2bd8;
                  }
                  goto LAB_0054f356;
                }
                local_70 = 0;
              }
LAB_0054f839:
              if ((((float)(&ITEM_P5)[DAT_009a2be4] == f_0) || (DAT_009a2be0 != 4.2039e-45)) ||
                 ((float)(&ITEM_LEN)[DAT_009a2be4] < f_5)) {
                local_30 = 0;
                DAT_009a2bf0 = 7.78498e-40;
                DAT_009a2bec = -NAN;
                DAT_009a2bd0 = *(int *)(&DAT_020359fc + DAT_009a2be8 * 4);
                for (local_18 = (((&DAT_02035a00)[DAT_009a2be8] - DAT_009a2bd0) + 2) / 3;
                    0 < local_18; local_18 = local_18 + -1) {
                  DAT_009a2bbc = *(float *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                           DAT_009a2bd0 * VEC_STRIDE);
                  DAT_009a2bb4 = *(float *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                           (DAT_009a2bd0 + 1) * VEC_STRIDE);
                  if ((int)*param_5 < (int)DAT_009a2bbc) {
                    *param_5 = DAT_009a2bbc;
                  }
                  if ((int)DAT_009a2bbc < (int)*param_4) {
                    *param_4 = DAT_009a2bbc;
                    _DAT_009a2bb0 = DAT_009a2be0;
                    _DAT_009a2bac = DAT_009a2be8;
                  }
                  if ((int)DAT_009a2bec < (int)DAT_009a2bb4) {
                    DAT_009a2bec = DAT_009a2bb4;
                  }
                  if ((int)DAT_009a2bb4 < (int)DAT_009a2bf0) {
                    DAT_009a2bf0 = DAT_009a2bb4;
                  }
                  if ((int)*param_2 < (int)DAT_009a2bb4) {
                    *param_2 = DAT_009a2bb4;
                  }
                  if ((int)DAT_009a2bb4 < (int)*param_3) {
                    *param_3 = DAT_009a2bb4;
                  }
                  DAT_009a2bd0 = DAT_009a2bd0 + 3;
                }
                if (((*(float *)(&ITEM_P7 + DAT_009a2be4 * 4) < f_10) ||
                    (DAT_009a2be0 != 1.68156e-44)) || (f_0 <= (float)(&ITEM_P5)[DAT_009a2be4])) {
                  local_14 = 0;
                }
                else {
                  _DAT_009a2b98 = (float)(&ITEM_P6)[DAT_009a2be4];
                  if (_DAT_009a2b98 == f_0) {
                    _DAT_009a2b98 = f_1;
                  }
                  fVar1 = _DAT_009a2b98 *
                          (float)(&STAFF_STEP0)[(int)ROUND((float)(&ITEM_P2)[DAT_009a2be4])];
                  _DAT_009a2b98 = f_1;
                  if ((f_16 <= (float)(&ITEM_LEN)[DAT_009a2be4]) &&
                     (*(float *)(&ITEM_P16 + DAT_009a2be4 * 4) != f_0)) {
                    _DAT_009a2b98 = *(float *)(&ITEM_P16 + DAT_009a2be4 * 4) * f_0_9;
                  }
                  _DAT_009a2bc8 = _DAT_009a2b98 * (fVar1 / f_25);
                  fVar2 = (float10)(int)DAT_009a2bf0;
                  local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                  local_cc = (float)(int)ROUND(fVar2 - (float10)_DAT_009a2bc8 * (float10)f_450);
                  DAT_009a2ba8 = local_cc;
                  if ((int)local_cc < (int)*param_3) {
                    *param_3 = local_cc;
                  }
                  local_d4 = *(undefined4 *)(&ITEM_P7 + DAT_009a2be4 * 4);
                  ffree(fVar2);
                  fVar2 = (float10)FUN_005ff874(&local_d4,&f_10);
                  if (fVar2 == (float10)f_0) {
                    in_ST0 = (float10)(int)DAT_009a2bec;
                    local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                    local_cc = (float)(int)ROUND((float10)_DAT_009a2bc8 * (float10)f_800 + in_ST0);
                    DAT_009a2ba8 = local_cc;
                    if ((int)*param_2 < (int)local_cc) {
                      *param_2 = local_cc;
                    }
                  }
                  else {
                    local_10 = 0;
                    in_ST0 = extraout_ST1_02;
                  }
                }
              }
              else {
                local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                local_cc = (float)(int)ROUND((float)(&ITEM_P2)[DAT_009a2be4]);
                _DAT_009a2bc8 = (float)(&STAFF_STEP0)[(int)local_cc] / f_25;
                if ((f_5 < (float)(&ITEM_LEN)[DAT_009a2be4]) &&
                   ((float)(&ITEM_P6)[DAT_009a2be4] != f_0)) {
                  _DAT_009a2bc8 = _DAT_009a2bc8 * (float)(&ITEM_P6)[DAT_009a2be4];
                }
                if ((f_3 < (float)(&ITEM_LEN)[DAT_009a2be4]) &&
                   (f_100 <= (float)(&ITEM_P4)[DAT_009a2be4])) {
                  _DAT_009a2bc8 = _DAT_009a2bc8 * f_0_8;
                }
                if ((float)(&ITEM_P5)[DAT_009a2be4] == f_0_8) {
                  DAT_009a2bd0 = *(int *)(&DAT_020359fc + DAT_009a2be8 * 4);
                  for (local_28 = (((&DAT_02035a00)[DAT_009a2be8] - DAT_009a2bd0) + 2) / 3;
                      0 < local_28; local_28 = local_28 + -1) {
                    DAT_009a2bbc = *(float *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                             DAT_009a2bd0 * VEC_STRIDE);
                    DAT_009a2bb4 = *(float *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                             (DAT_009a2bd0 + 1) * VEC_STRIDE);
                    if ((int)*param_5 < (int)DAT_009a2bbc) {
                      *param_5 = DAT_009a2bbc;
                    }
                    if ((int)DAT_009a2bbc < (int)*param_4) {
                      *param_4 = DAT_009a2bbc;
                      _DAT_009a2bb0 = DAT_009a2be0;
                      _DAT_009a2bac = DAT_009a2be8;
                    }
                    if ((int)*param_2 < (int)DAT_009a2bb4) {
                      *param_2 = DAT_009a2bb4;
                    }
                    if ((((float)(&ITEM_P5)[DAT_009a2be4] == f_0_8) && (DAT_009a2be0 == 4.2039e-45))
                       && (f_4 < (float)(&ITEM_LEN)[DAT_009a2be4])) {
                      in_ST0 = (float10)(int)DAT_009a2bb4;
                      local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                      DAT_009a2bb4 = (float)(int)ROUND(in_ST0 - (float10)_DAT_009a2bc8 *
                                                                (float10)f_400);
                      local_cc = DAT_009a2bb4;
                    }
                    if ((int)DAT_009a2bb4 < (int)*param_3) {
                      *param_3 = DAT_009a2bb4;
                    }
                    DAT_009a2bd0 = DAT_009a2bd0 + 3;
                  }
                  local_24 = 0;
                }
                else {
                  local_2c = 0;
                  DAT_009a2bd0 = *(int *)(&DAT_020359fc + DAT_009a2be8 * 4);
                  for (local_20 = (((&DAT_02035a00)[DAT_009a2be8] - DAT_009a2bd0) + 2) / 3;
                      0 < local_20; local_20 = local_20 + -1) {
                    DAT_009a2bbc = *(float *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                             DAT_009a2bd0 * VEC_STRIDE);
                    DAT_009a2bb4 = *(float *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                             (DAT_009a2bd0 + 1) * VEC_STRIDE);
                    if ((int)*param_5 < (int)DAT_009a2bbc) {
                      *param_5 = DAT_009a2bbc;
                    }
                    if ((int)DAT_009a2bbc < (int)*param_4) {
                      *param_4 = DAT_009a2bbc;
                      _DAT_009a2bb0 = DAT_009a2be0;
                      _DAT_009a2bac = DAT_009a2be8;
                    }
                    if ((int)DAT_009a2bb4 < (int)*param_3) {
                      *param_3 = DAT_009a2bb4;
                    }
                    if (((DAT_009a2be0 == 4.2039e-45) && (f_4 < (float)(&ITEM_LEN)[DAT_009a2be4]))
                       && ((float)(&ITEM_P5)[DAT_009a2be4] == f_0_15 ||
                           (float)(&ITEM_P5)[DAT_009a2be4] == f_0_88)) {
                      in_ST0 = (float10)(int)DAT_009a2bb4;
                      local_d0 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                      DAT_009a2bb4 = (float)(int)ROUND((float10)_DAT_009a2bc8 * (float10)f_420 +
                                                       in_ST0);
                      local_cc = DAT_009a2bb4;
                    }
                    if ((int)*param_2 < (int)DAT_009a2bb4) {
                      *param_2 = DAT_009a2bb4;
                    }
                    DAT_009a2bd0 = DAT_009a2bd0 + 3;
                  }
                  local_1c = 0;
                }
              }
            }
            else {
              local_8c = 0;
            }
          }
          else {
            local_98 = 0;
          }
        }
        else {
          local_9c = 0;
        }
      }
      else {
        local_a4 = 0;
      }
    }
    else {
      if ((DAT_009a2bf4 != 1) || ((float)(&ITEM_P2)[DAT_009a2be4] <= f_200)) goto LAB_0054ee9b;
      local_a0 = 0;
    }
LAB_00550133:
    local_c = 0;
    DAT_009a2be8 = DAT_009a2be8 + 1;
    local_a8 = local_a8 + -1;
    fVar1 = _DAT_009a2b98;
  } while( true );
}


