// FUN_004c8290 @ 004c8290 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c8290(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 in_ST0;
  float10 fVar4;
  unkbyte10 in_ST1;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  unkbyte10 Var5;
  unkbyte10 extraout_ST1_05;
  unkbyte10 extraout_ST1_06;
  unkbyte10 extraout_ST1_07;
  float local_10c [2];
  float local_104 [11];
  int local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b4;
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
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  
  DAT_01be1800 = (float)(&DAT_01e9bfc4)[*param_3] + f_1001;
  DAT_01be1808 = 1;
  DAT_0089fc90 = *param_1;
  DAT_0089fc8c = *param_2;
  LOAD_I = 1;
  DAT_01be1804 = ITEM_I;
  for (local_d8 = ITEM_I; 0 < local_d8; local_d8 = local_d8 + -1) {
    ffree(in_ST1);
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    if (((LOAD_STAFF <= DAT_0089fc8c) && (LOAD_CODE == 8)) && (DAT_0089fc90 <= LOAD_STAFF)) {
      in_ST0 = (float10)(float)(&ITEM_P2)[LOAD_W];
      (&ITEM_P2)[LOAD_W] = (float)-in_ST0;
    }
    LOAD_I = LOAD_I + 1;
    in_ST1 = extraout_ST1;
  }
  LOAD_I = 0;
LAB_004c837c:
  do {
    LOAD_I = LOAD_I + 1;
    if (ITEM_I < LOAD_I) goto LAB_004c911c;
    ffree(in_ST1);
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    in_ST1 = extraout_ST1_00;
    if ((DAT_0089fc90 <= LOAD_STAFF) && (LOAD_STAFF <= DAT_0089fc8c)) {
      if (LOAD_CODE < 3) {
        local_cc = 0;
        _DAT_0089fc88 = LOAD_P3 - f_2;
      }
      else {
        if (LOAD_CODE != 3) {
          local_c8 = 0;
          goto LAB_004c837c;
        }
        _DAT_0089fc88 = LOAD_P3 + f_2;
        local_c4 = 0;
      }
      DAT_01be1814 = *param_1;
      local_c0 = (*param_2 - DAT_01be1814) + 1;
      iVar1 = DAT_0089fc84;
      DAT_0089fc84 = DAT_01be1808;
      break;
    }
    local_d0 = 0;
  } while( true );
joined_r0x004c844f:
  DAT_01be1808 = DAT_0089fc84;
  if (local_c0 < 1) {
    DAT_01be180c = 0;
    DAT_0089fc50 = 0;
    LOAD_I = 1;
    DAT_0089fc64 = f_0;
    for (local_58 = ITEM_I; DAT_0089fc84 = iVar1, 0 < local_58; local_58 = local_58 + -1) {
      ffree(in_ST1);
      ffree(in_ST0);
      in_ST0 = (float10)load_item_header();
      if (((DAT_01fbb8b8 + f_0_05 < LOAD_P3) || (LOAD_STAFF < DAT_0089fc90)) ||
         (DAT_0089fc8c < LOAD_STAFF)) {
        local_54 = 0;
      }
      else if (LOAD_CODE == 3) {
        if (_DAT_0089fc88 <= LOAD_P3) {
          DAT_01be180c = DAT_01be180c + 1;
          *(float *)(DAT_01be180c * 4 + 0x1e9d8d4) = LOAD_P3;
          *(int *)(DAT_01be180c * 4 + 0x1e9e234) = LOAD_I;
          *(int *)(DAT_01be180c * 4 + 0x1e9dbf4) = LOAD_STAFF;
          local_48 = 0;
        }
        else {
          local_4c = 0;
        }
      }
      else {
        local_50 = 0;
        if (LOAD_CODE == 0xe) {
          if (_DAT_0089fc88 <= LOAD_P3) {
            DAT_0089fc50 = DAT_0089fc50 + 1;
            *(float *)(&DAT_01e9d5b4 + DAT_0089fc50 * 4) = LOAD_P3;
            if (DAT_0089fc64 < LOAD_P3) {
              DAT_0089fc64 = LOAD_P3;
            }
          }
          else {
            local_40 = 0;
          }
        }
        else {
          local_44 = 0;
        }
      }
      if (LOAD_STAFF < 0) {
        in_ST0 = (float10)(float)(&ITEM_P2)[LOAD_W];
        (&ITEM_P2)[LOAD_W] = (float)-in_ST0;
      }
      LOAD_I = LOAD_I + 1;
      in_ST1 = extraout_ST1_07;
      iVar1 = DAT_0089fc84;
    }
    DAT_01be1814 = 1;
    for (iVar1 = DAT_01be180c; 0 < iVar1; iVar1 = iVar1 + -1) {
      _DAT_0089fc80 = *(float *)(DAT_01be1814 * 4 + 0x1e9d8d4);
      DAT_01be1810 = *(int *)(DAT_01be1814 * 4 + 0x1e9e234);
      DAT_0089fc4c = *(int *)(DAT_01be1814 * 4 + 0x1e9dbf4);
      _DAT_0089fc7c = (float)(&STAFF_STEP0)[DAT_0089fc4c] * f_0_3 + f_1;
      DAT_01be181c = DAT_01be1810;
      do {
        iVar2 = DAT_01be181c + 1;
        iVar3 = (&ITEM_PTR0)[iVar2];
        DAT_01be181c = DAT_01be1810;
        DAT_0089fc60 = DAT_0089fc64;
        if ((ITEM_I < iVar2) || (DAT_0089fc4c != (int)ROUND((float)(&ITEM_P2)[iVar3])))
        goto LAB_004c8fdf;
        if ((float)(&ITEM_P1)[iVar3] == f_14) {
          DAT_0089fc60 = (float)(&ITEM_P3)[iVar3];
          goto LAB_004c8fdf;
        }
        DAT_01be181c = iVar2;
      } while (f_2 < (float)(&ITEM_P1)[iVar3]);
      DAT_0089fc74 = (float)(&ITEM_P3)[iVar3];
      DAT_01be181c = 1;
      for (iVar3 = DAT_0089fc50; 0 < iVar3; iVar3 = iVar3 + -1) {
        DAT_0089fc60 = *(float *)(&DAT_01e9d5b4 + DAT_01be181c * 4);
        if (_DAT_0089fc80 <= DAT_0089fc60) {
          DAT_01be181c = DAT_01be1810;
          if (DAT_0089fc60 <= DAT_0089fc74) goto LAB_004c8fdf;
          break;
        }
        DAT_01be181c = DAT_01be181c + 1;
      }
      DAT_01be181c = DAT_01be1810;
      DAT_0089fc60 = DAT_0089fc74;
LAB_004c8fdf:
      do {
        DAT_01be181c = DAT_01be181c + -1;
        DAT_01be1818 = (&ITEM_PTR0)[DAT_01be181c];
        DAT_0089fc58 = (float)(&ITEM_P3)[DAT_01be1818];
        if (_DAT_0089fc7c < DAT_0089fc60 - DAT_0089fc58) {
          DAT_01be1824 = (DAT_0089fc60 - _DAT_0089fc7c) + f_1;
          goto LAB_004c90d7;
        }
        LOAD_I = (int)ROUND((float)(&ITEM_P1)[DAT_01be1818]);
      } while ((2 < LOAD_I) && (LOAD_I < 0x11));
      DAT_01be1824 = (DAT_0089fc60 - DAT_0089fc58) / f_2 + DAT_0089fc58;
LAB_004c90d7:
      (&ITEM_P3)[(&ITEM_PTR0)[DAT_01be1810]] = DAT_01be1824;
      DAT_01be1814 = DAT_01be1814 + 1;
    }
LAB_004c911c:
    ffree(in_ST1);
    ffree(in_ST0);
    return;
  }
  DAT_01be1818 = *(int *)(&DAT_01e9d1b4 + DAT_01be1814 * 4);
  DAT_01be181c = *(int *)(&DAT_01e9d1b8 + DAT_01be1814 * 4);
  if (DAT_01be181c == DAT_01be1818) {
    local_bc = 0;
  }
  else {
    DAT_01be181c = DAT_01be181c + -1;
    DAT_01be180c = *param_3;
    ffree(in_ST1);
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_004cc8a9();
    in_ST1 = extraout_ST1_01;
    if (DAT_01be180c == 0) goto LAB_004c911c;
    DAT_01be1818 = 1;
    _DAT_0089fc80 = (float)(&DAT_01e9bfc4)[DAT_01be180c];
    _DAT_0089fc7c = *(float *)(&DAT_01e9cf5c + DAT_01be180c * 4);
    DAT_0089fc78 = _DAT_0089fc80 + f_800;
    DAT_0089fc74 = DAT_01e9c220;
    DAT_0089fc70 = DAT_01e9cd08;
    _DAT_01be1820 = (uint)(f_0 < _DAT_0089fc7c);
    _DAT_0089fc6c = (uint)(f_0 < DAT_01e9c220);
    DAT_01be1810 = 0;
    Var5 = extraout_ST1_01;
    while( true ) {
      if (DAT_01be1810 == 0) {
        if (*param_3 < DAT_01be180c) {
          local_b0 = 0;
          goto LAB_004c8a41;
        }
        ffree(Var5);
        ffree(in_ST0);
        in_ST0 = (float10)FUN_004c9129(&DAT_0089fc68,&DAT_0089fc64,&DAT_01be180c);
        Var5 = extraout_ST1_02;
      }
      else {
        local_b4 = 0;
      }
      if (DAT_01be181c <= DAT_01be1818) break;
      DAT_01be1818 = DAT_01be1818 + 1;
      DAT_0089fc60 = *(float *)(&DAT_01e9c21c + DAT_01be1818 * 4);
      DAT_0089fc5c = (float)(&DAT_01e9cd04)[DAT_01be1818];
      if (DAT_0089fc74 == _DAT_0089fc7c) {
        local_a8 = 0;
LAB_004c8794:
        DAT_01be1810 = 0;
        DAT_0089fc58 = DAT_0089fc64;
        DAT_01be1824 = DAT_0089fc68;
        if (DAT_0089fc68 == DAT_0089fc60) {
          local_78 = 0;
        }
        else if ((DAT_0089fc60 == f_m14) || (DAT_0089fc60 == f_m140)) {
          DAT_0089fc58 = (DAT_0089fc64 - _DAT_0089fc80) / f_2 + _DAT_0089fc80;
          DAT_01be1824 = DAT_0089fc60;
          DAT_01be180c = DAT_01be180c + -1;
          local_70 = 0;
        }
        else {
          local_74 = 0;
          if ((DAT_0089fc68 == f_m14) || (DAT_0089fc68 == f_m140)) {
            DAT_0089fc5c = (DAT_0089fc5c - DAT_0089fc70) / f_2 + DAT_0089fc70;
            DAT_0089fc60 = DAT_0089fc68;
            DAT_01be1818 = DAT_01be1818 + -1;
            local_68 = 0;
          }
          else {
            local_6c = 0;
          }
        }
      }
      else {
        DAT_01be1824 = _DAT_0089fc7c - DAT_0089fc74;
        in_ST0 = (float10)DAT_01be1824;
        if (ABS(in_ST0) <= (float10)f_0_005) {
          local_a4 = 0;
          goto LAB_004c8794;
        }
        if (DAT_01be1824 < f_0) {
          local_a0 = 0;
          while( true ) {
            while (DAT_0089fc68 <= f_0) {
              ffree(Var5);
              ffree(in_ST0);
              in_ST0 = (float10)FUN_004c9129(&DAT_0089fc68,&DAT_0089fc64,&DAT_01be180c);
              local_90 = 0;
              Var5 = extraout_ST1_04;
            }
            local_94 = 0;
            _DAT_0089fc7c = DAT_0089fc68 + _DAT_0089fc7c;
            DAT_01be1824 = _DAT_0089fc7c - DAT_0089fc74;
            ffree(Var5);
            ffree(in_ST0);
            FUN_004c9129(&DAT_0089fc68,&DAT_0089fc64,&DAT_01be180c);
            in_ST0 = (float10)DAT_01be1824;
            Var5 = extraout_ST1_03;
            if (ABS(in_ST0) <= (float10)f_0_005) {
              local_8c = 0;
              goto LAB_004c8794;
            }
            if (DAT_0089fc68 <= f_0) {
              *param_1 = -1;
              in_ST1 = extraout_ST1_03;
              goto LAB_004c911c;
            }
            local_88 = 0;
            if (f_0 <= DAT_01be1824) break;
            local_80 = 0;
          }
          local_7c = 0;
        }
        DAT_01be1810 = 1;
        DAT_0089fc58 = ((DAT_0089fc64 - _DAT_0089fc80) * DAT_0089fc74) / _DAT_0089fc7c +
                       _DAT_0089fc80;
      }
      if (DAT_0089fc70 < DAT_0089fc5c) {
        DAT_0089fc54 = -DAT_01be1804;
        DAT_01fbb860 = DAT_01be1814;
        DAT_01fbb864 = DAT_01be1814;
        DAT_01fbb868 = DAT_0089fc70;
        DAT_01fbb86c = DAT_0089fc5c;
        DAT_01fbb870 = f_0;
        DAT_01fbb874 = 0;
        DAT_01fbb878 = DAT_01be1808;
        ffree(Var5);
        ffree(in_ST0);
        DAT_01fbb87c = DAT_0089fc54;
        thunk_FUN_0049b1d8();
        fVar4 = ((float10)DAT_0089fc58 - (float10)_DAT_0089fc80) /
                ((float10)DAT_0089fc5c - (float10)DAT_0089fc70);
        local_104[0] = (float)((float10)_DAT_0089fc80 + (float10)f_1000);
        local_10c[0] = (float)fVar4;
        ffree(fVar4);
        ffree((float10)_DAT_0089fc80 + (float10)f_1000);
        in_ST0 = (float10)thunk_FUN_0049bb13(&DAT_00764eb8,&DAT_0089fc70,local_104,local_10c);
        _DAT_0089fc80 = DAT_0089fc58;
        _DAT_0089fc7c = DAT_01be1824;
        DAT_0089fc74 = DAT_0089fc60;
        DAT_0089fc70 = DAT_0089fc5c;
        local_98 = 0;
        Var5 = extraout_ST1_05;
      }
      else {
        local_9c = 0;
      }
    }
    local_ac = 0;
LAB_004c8a41:
    if ((DAT_01be181c + -1 <= DAT_01be1818) && (*param_3 <= DAT_01be180c)) {
      local_60 = 0;
    }
    DAT_01be1808 = DAT_01fbb87c + -1;
    DAT_01fbb860 = DAT_01be1814;
    DAT_01fbb864 = DAT_01be1814;
    DAT_01fbb868 = DAT_0089fc78;
    DAT_01fbb86c = DAT_01be1800;
    DAT_01fbb870 = f_0;
    DAT_01fbb874 = 0;
    DAT_01fbb878 = DAT_0089fc84;
    DAT_01fbb87c = ITEM_I;
    ffree(Var5);
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0049b1d8();
    DAT_01be181c = 1;
    for (iVar3 = DAT_020492a4; in_ST1 = extraout_ST1_06, iVar1 = DAT_0089fc84, 0 < iVar3;
        iVar3 = iVar3 + -1) {
      DAT_01be1818 = (&DAT_020492a4)[DAT_01be181c];
      if (DAT_01be1818 < 0) {
        DAT_01be1818 = -DAT_01be1818;
      }
      DAT_01be1824 = (float)(&ITEM_LEN)[DAT_01be1818];
      if (DAT_0089fc78 <= DAT_01be1824) {
        (&ITEM_LEN)[DAT_01be1818] = DAT_01be1824 - f_1000;
      }
      DAT_01be181c = DAT_01be181c + 1;
    }
  }
  DAT_0089fc84 = iVar1;
  local_5c = 0;
  DAT_01be1814 = DAT_01be1814 + 1;
  local_c0 = local_c0 + -1;
  iVar1 = DAT_0089fc84;
  DAT_0089fc84 = DAT_01be1808;
  goto joined_r0x004c844f;
}


