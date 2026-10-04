// FUN_0050e830 @ 0050e830 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0050f57f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050e830(int *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var4;
  float10 fVar5;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  undefined4 local_d4;
  undefined4 *local_d0;
  undefined4 *local_cc;
  uint local_c8;
  float local_c4;
  undefined4 local_c0 [8];
  int local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
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
  undefined4 local_8;
  
  DAT_0078b4e4 = 0x58;
  ffree(in_ST0);
  Var4 = thunk_FUN_0049846f(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I);
  DAT_020492a0 = 1;
  _DAT_00940eac = f_1;
  ffree(Var4);
  fVar5 = (float10)thunk_FUN_00534c40(&DAT_020492a0,&DAT_00940eac,&DAT_00940ea8,&DAT_01e9cd08,
                                      &DAT_01e9bfc8,&DAT_00940ea4);
  DAT_00940e9c = 0.0;
  DAT_00940e98 = 1;
  DAT_00940ea0 = f_0;
  for (local_a0 = DAT_00940ea8; 0 < local_a0; local_a0 = local_a0 + -1) {
    _DAT_00940e94 = (float)(&DAT_01e9bfc4)[DAT_00940e98];
    if (f_0 <= _DAT_00940e94) {
      DAT_00940ea0 = _DAT_00940e94 + DAT_00940ea0;
      local_98 = 0;
    }
    else {
      local_9c = 0;
      if (DAT_00940ea0 == f_0) {
        local_94 = 0;
      }
      else {
        local_c8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        local_c4 = (float)(int)ROUND(_DAT_00940e94);
        DAT_0078b4e4 = (int)local_c4;
        if ((local_c4 == -NAN) || (local_c4 == -NAN)) {
          DAT_00940e9c = (float)((int)DAT_00940e9c + 1);
          if (local_c4 == -NAN) {
            fVar5 = (float10)DAT_00940ea0;
            DAT_00940ea0 = (float)-fVar5;
          }
          *(float *)(&DAT_00940eb8 + (int)DAT_00940e9c * 4) = DAT_00940ea0;
          DAT_00940ea0 = f_0;
        }
        else {
          local_90 = 0;
        }
      }
    }
    local_8c = 0;
    DAT_00940e98 = DAT_00940e98 + 1;
  }
  pcVar2 = "\r\n         bars,         beats.";
  puVar3 = (undefined4 *)((int)&DAT_020b90b7 + 3);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  local_c0[0] = 0;
  local_d4 = 6;
  local_d0 = &DAT_020b90be;
  local_cc = &DAT_00940e9c;
  ffree(fVar5);
  Var4 = FUN_005f34f0(local_c0,0x784ff00,&DAT_0076742c,&local_d4,&DAT_00795ec8);
  local_c0[0] = 0;
  local_d4 = 7;
  local_d0 = (undefined4 *)&DAT_020b90cb;
  local_cc = (undefined4 *)&DAT_00940ea4;
  ffree(Var4);
  Var4 = FUN_005f34f0(local_c0,0x784ff00,&DAT_00767424,&local_d4,&DAT_00795edc);
  ffree(Var4);
  Var4 = thunk_FUN_0054946a(&DAT_020b90a0,0x200);
  DAT_0078b4e4 = 0;
  ffree(Var4);
  fVar5 = (float10)thunk_FUN_0049846f(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I);
  DAT_00940e90 = 0;
  DAT_00940e8c = f_0;
  DAT_00940e88 = f_0;
  _DAT_00940e84 = f_0;
  _DAT_00940e80 = f_0;
  _DAT_00940eb4 = f_m99;
  _DAT_00940e7c = f_0;
  DAT_00940e78 = 0;
  DAT_00791448 = 0;
  DAT_00940e74 = 0;
  _DAT_00940eb8 = 0;
  DAT_00940e98 = 0;
  _DAT_00940e70 = 0;
LAB_0050ebc0:
  DAT_00940e98 = DAT_00940e98 + 1;
  DAT_00940e6c = (&ITEM_PTR0)[DAT_00940e98];
  local_c8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_00940e9c = (float)(int)ROUND((float)(&ITEM_P1)[DAT_00940e6c]);
  local_c4 = DAT_00940e9c;
  if (((int)DAT_00940e9c < 3) || (DAT_00940e9c == 2.52234e-44)) {
    local_80 = 0;
LAB_0050ec71:
    DAT_00940e74 = 1;
LAB_0050ec7c:
    do {
      ffree(fVar5);
      DAT_00940e9c = local_c4;
      fVar5 = (float10)thunk_FUN_004b6ced(&DAT_00940e6c,&DAT_00940e68);
      if (DAT_00940e9c == 1.4013e-45) {
        DAT_00940e88 = DAT_00795f88;
        if ((DAT_01c58930 == f_2) || (DAT_01c58930 == f_3)) {
          DAT_00940e88 = DAT_00795f84;
        }
        DAT_00940e90 = 1;
        _DAT_00940e70 = 0;
        DAT_00940e8c = f_0;
        _DAT_00940e5c = f_1;
        if ((float10)f_100 <= ABS((float10)DAT_01c58928)) {
          _DAT_00940e5c = f_0_6;
        }
        _DAT_00940e58 = f_0;
        ffree((float10)DAT_01c58928);
        fVar5 = (float10)amod(&DAT_01c5892c,&f_10);
        _DAT_00940e54 = (float)fVar5;
        if (_DAT_00940e54 == f_0) {
          local_44 = 0;
          fVar5 = extraout_ST1;
        }
        else {
          _DAT_00940e58 = f_2_5;
          if (f_4 <= _DAT_00940e54) {
            _DAT_00940e58 = f_4;
          }
          ffree(extraout_ST1);
          fVar5 = (float10)amod(&DAT_00940e54,&f_1);
          DAT_00940e8c = (float)(fVar5 * (float10)f_10 + (float10)_DAT_00940e58);
          fVar5 = extraout_ST1_00;
        }
        if (DAT_01c5893c == f_0) {
          local_40 = 0;
        }
        else {
          if (f_10 <= DAT_01c5893c) {
            local_c8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
            DAT_00940e50 = ((int)ROUND(DAT_01c5893c) % 100) / 10;
            local_c4 = (float)DAT_00940e50 * f_1_5;
            ffree(fVar5);
            fVar5 = (float10)amod(&DAT_01c5893c,&f_1);
            _DAT_00940e94 = (float)(fVar5 * (float10)f_10 + (float10)local_c4);
            local_38 = 0;
            fVar5 = extraout_ST1_01;
          }
          else {
            local_3c = 0;
            if (f_20 <= DAT_01c5892c) {
              local_34 = 0;
              goto LAB_0050f175;
            }
            _DAT_00940e94 = f_1_5;
          }
          DAT_00940e88 = _DAT_00940e94 + DAT_00940e88;
        }
LAB_0050f175:
        if (DAT_00940e68 < 10) {
          local_30 = 0;
        }
        else {
          _DAT_00940e94 = DAT_00940e88;
          DAT_00940ea0 = *(float *)(&ITEM_P10 + DAT_00940e6c * 4);
          if (DAT_00940ea0 == f_20) {
            DAT_00940e8c = DAT_00940e88 + DAT_00940e8c;
          }
          if (DAT_00940ea0 == f_10) {
            DAT_00940e88 = DAT_00940e88 + DAT_00940e88;
          }
          if (DAT_00940ea0 < f_10) {
            if (f_0 < DAT_00940ea0) {
              DAT_00940e88 = DAT_00940ea0 + DAT_00940e88;
            }
            if (DAT_00940ea0 < f_0) {
              DAT_00940e8c = DAT_00940ea0 + DAT_00940e8c;
            }
          }
          else {
            local_2c = 0;
          }
        }
LAB_0050f259:
        DAT_00940e8c = _DAT_00940e5c * DAT_00940e8c;
        DAT_00940e88 = _DAT_00940e5c * DAT_00940e88;
      }
      else {
        if (DAT_00940e9c == 2.8026e-45) {
          _DAT_00940e5c = f_1;
          DAT_00940e8c = f_0;
          ffree(fVar5);
          fVar5 = (float10)thunk_FUN_004b6657(&DAT_00940e68,&DAT_00940e6c,&DAT_00940e8c,
                                              &DAT_00940e88,&DAT_01c58928,&DAT_01c5892c,
                                              &DAT_01c58930,&DAT_00940e5c);
          if ((f_17 <= (float)(&ITEM_LEN)[DAT_00940e6c]) &&
             (*(float *)(&ITEM_P17 + DAT_00940e6c * 4) != f_0)) {
            DAT_01c58934 = *(float *)(&ITEM_P17 + DAT_00940e6c * 4);
          }
          DAT_00940eb0 = (int)ROUND(DAT_01c58934 * f_100 + f_0_5);
          if (DAT_00940e90 == 0) {
            (&DAT_01a76ac0)[DAT_01ba0d84] = DAT_00940eb0;
          }
          DAT_00940e90 = 2;
          local_48 = 0;
          goto LAB_0050f259;
        }
        if (DAT_00940e9c == 1.96182e-44) {
          local_74 = 0;
          if (DAT_00791448 < 1) {
            DAT_00791448 = -1;
            _DAT_00940e70 = 0;
            local_68 = 0;
            goto LAB_0050f591;
          }
          local_6c = 0;
          if (f_7 < DAT_01c5892c) {
            if ((DAT_00940e88 == f_0) && (f_0 <= DAT_01c58928)) {
              local_60 = 0;
              goto LAB_0050f591;
            }
            local_5c = 0;
          }
          else {
            local_64 = 0;
            if (f_0 <= DAT_01c58928) {
              ffree(fVar5);
              fVar5 = (float10)thunk_FUN_004b6818(&DAT_00940e8c,&DAT_00940e88,&DAT_00940e68,
                                                  &DAT_00940eb8);
              DAT_00940e88 = f_0;
              local_54 = 0;
            }
            else {
              local_58 = 0;
            }
          }
        }
        else if (DAT_00940e9c == 2.38221e-44) {
          ffree(fVar5);
          fVar5 = (float10)thunk_FUN_004b6c51(&DAT_00940e8c,&DAT_00940e88,&DAT_01c5892c,
                                              &DAT_01c58934,&DAT_00940eb8);
          local_50 = 0;
        }
        else if (DAT_00940e9c == 2.52234e-44) {
          ffree(fVar5);
          fVar5 = (float10)thunk_FUN_004b6a52(&DAT_00940e68,&DAT_00940e8c,&DAT_00940e88,
                                              &DAT_00940e64,&DAT_00940eb8,&DAT_00940e60);
          local_4c = 0;
        }
        else {
          local_70 = 0;
        }
      }
      iVar1 = DAT_00940e98;
      DAT_00791448 = 1;
      _DAT_00940eb8 = (int)DAT_00940e9c;
      if (_DAT_00940e84 < DAT_00940e8c) {
        _DAT_00940e84 = DAT_00940e8c;
      }
      if (_DAT_00940e80 < DAT_00940e88) {
        _DAT_00940e80 = DAT_00940e88;
      }
      DAT_00940e4c = DAT_00940e98;
      while( true ) {
        if (ITEM_I == DAT_00940e98) {
          local_28 = 0;
          goto LAB_0050f41b;
        }
        DAT_00940e98 = DAT_00940e98 + 1;
        DAT_00940e6c = (&ITEM_PTR0)[DAT_00940e98];
        local_c8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        DAT_00940e48 = (int)ROUND((float)(&ITEM_P1)[DAT_00940e6c]);
        if (((DAT_00940e48 == 0xe) || (DAT_00940e48 < 3)) || (0x10 < DAT_00940e48)) break;
        local_24 = 0;
      }
      if (f_0_01 < ABS((float)(&ITEM_P3)[DAT_00940e6c] - DAT_01c58924)) {
        local_20 = 0;
        DAT_00940e98 = iVar1;
        goto LAB_0050f41b;
      }
      if ((DAT_00940e48 == 0x12) && (DAT_00940e9c == 1.96182e-44)) goto LAB_0050f408;
      local_18 = 0;
      local_c4 = (float)DAT_00940e48;
    } while( true );
  }
  if (DAT_00940e9c == 1.96182e-44) {
    local_7c = 0;
    goto LAB_0050ec7c;
  }
  if ((DAT_00940e9c == 2.38221e-44) && (DAT_00940e74 != 0)) goto LAB_0050ec71;
  local_78 = 0;
  goto LAB_0050f591;
LAB_0050f408:
  local_1c = 0;
  DAT_00940e98 = iVar1;
LAB_0050f41b:
  _DAT_00940e60 = _DAT_00940e84 + _DAT_00940e80;
  _DAT_00940e7c = _DAT_00940e60 + _DAT_00940e7c;
  _DAT_00940e84 = f_0;
  _DAT_00940e80 = f_0;
  if (DAT_00940e9c == 1.96182e-44) {
    local_10 = 0;
    DAT_01ba0d84 = DAT_01ba0d84 + 1;
    if (DAT_00940e90 == 2) {
      *(int *)(&DAT_01a77a5c + DAT_01ba0d84 * 4) = DAT_00940eb0;
    }
    DAT_00940e90 = 0;
    DAT_00940e78 = DAT_00940e78 + 1;
    _DAT_00940e44 = *(float *)(&DAT_00940eb8 + DAT_00940e78 * 4) * f_800;
    _DAT_00940e7c = _DAT_00940e7c * f_100;
    if (_DAT_00940e44 < f_0) {
      fVar5 = (float10)_DAT_00940e7c;
      _DAT_00940e7c = (float)-fVar5;
    }
    *(int *)(&DAT_01a75b1c + DAT_01ba0d84 * 4) = (int)ROUND(_DAT_00940e44 + _DAT_00940e7c);
    (&DAT_01ba0d84)[DAT_01ba0d84] = (int)DAT_01c58924;
    _DAT_00940e7c = f_0;
  }
  else {
    local_14 = 0;
  }
  DAT_00791448 = 1;
LAB_0050f591:
  if (ITEM_I <= DAT_00940e98) {
    *(int *)(&DAT_01c424fc + *param_1 * 4) = DAT_00940e78;
    ffree(fVar5);
    return;
  }
  local_8 = 0;
  goto LAB_0050ebc0;
}


