// draw_text @ 00569af0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_text(void)

{
  undefined4 *puVar1;
  float fVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar5;
  unkbyte10 Var6;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  undefined1 *puVar7;
  float local_104;
  uint local_100;
  int local_fc;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  int local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
  undefined4 local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  
  puVar7 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if (((IP8 != 0x5e) && (0x59 < IP8)) && (IP8 < 1000)) {
    P8 = f_0;
    IP8 = 0;
  }
  if (P3 < f_m140) {
    if (DAT_01f9a6f4 == 0) {
      ffree(in_ST0);
      in_ST0 = thunk_FUN_0054a967();
    }
    goto LAB_0056ae13;
  }
  DAT_020b945c = (float)IP8;
  local_104 = P8;
  ffree(in_ST0);
  fVar5 = (float10)FUN_005ff874(&local_104,&f_1);
  local_100 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_01cadce0 = (int)ROUND(fVar5 * (float10)f_10);
  Var6 = extraout_ST1;
  local_fc = DAT_01cadce0;
  if (DAT_01cadce0 != 0) {
    ffree(extraout_ST1);
    Var6 = thunk_FUN_005784f1(&DAT_01cadce0);
  }
  if (200 < IP2) {
    X_POS = X_POS + f_34050;
  }
  *(undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068) = 0;
  DAT_009a7fa8 = P14;
  DAT_009a7fa4 = P15;
  DAT_009a7fa0 = P16;
  if (OUTPUT_MODE == -1) {
    ffree(Var6);
    in_ST0 = thunk_FUN_005704f8();
    goto LAB_0056ae13;
  }
  _DAT_01a1c844 = 0;
  DAT_01be1800 = P5;
  DAT_01cadce0 = DAT_00791444;
  if (P5 == f_0) {
    P5 = f_1;
  }
  DAT_01be1804 = P6;
  ffree(Var6);
  fVar5 = (float10)amod(&P6,&DAT_0076a1bc);
  P6 = (float)fVar5;
  if (P6 == f_0) {
    P6 = f_1;
  }
  P48 = P6;
  if (IP1 == 0x10) {
    local_d0 = 0;
    if ((EDIT_ITEM == 0) || ((DAT_0078b4e4 != 0x49 && DAT_0078b4e0 != 0x4a) && DAT_0078b4e0 != 0x54)
       ) {
      local_c8 = 0;
    }
    else {
      if ((DAT_0078b4e4 != 0x49) || (DAT_0078b4e0 == 0x52)) {
        P6 = DAT_01be1804;
        ffree(extraout_ST1_00);
        fVar5 = (float10)thunk_FUN_00470618();
        P6 = P48;
        local_c0 = 0;
        goto LAB_0056a290;
      }
      local_c4 = 0;
    }
    DAT_009a7f9c = ITEM_I;
    if (EDIT_ITEM != 0) {
      DAT_009a7f9c = ITEM_I + 1;
    }
    if (1000 < DAT_0078b4e0) {
      EDIT_ITEM = DAT_0078b4e0 + -1000;
    }
    DAT_009a7f98 = (&ITEM_PTR0)[DAT_009a7f9c];
    if (*(float *)(&ITEM_P14 + DAT_009a7f98 * 4) == f_m1) {
      DAT_01cadce0 = 0x11;
    }
    else {
      DAT_01cadce0 = 0xe;
    }
    DAT_009a7f9c = (&ITEM_PTR0)[DAT_009a7f9c] + DAT_01cadce0;
    ffree(extraout_ST1_00);
    fVar5 = (float10)thunk_FUN_0042fa58(&ITEM_LEN + DAT_009a7f9c,4,&IP12);
    if (P13 == f_0) {
      FUN_005f33c9(&stack0xfffffffc,0x569e9a);
      Var6 = FUN_005f34d1(puVar7,0x569eb5);
      DAT_009a7f94 = EDIT_ITEM;
      if (EDIT_ITEM == 0) {
        DAT_009a7f94 = ITEM_I;
      }
      DAT_009a7f90 = (&ITEM_PTR0)[DAT_009a7f94];
      (&ITEM_P1)[DAT_009a7f90] = f_999;
      *(undefined4 *)(puVar7 + -0xf4) = 0;
      *(undefined4 *)(puVar7 + -0x108) = 4;
      *(undefined1 **)(puVar7 + -0x104) = &DAT_020b8ea5;
      *(int **)(puVar7 + -0x100) = &DAT_009a7f94;
      ffree(Var6);
      Var6 = FUN_005f34f0(puVar7 + -0xf4,0x784ff00,&DAT_0076a164,puVar7 + -0x108,&DAT_0079f700);
      fVar2 = (float)(&ITEM_P2)[DAT_009a7f90];
      *(undefined2 *)(puVar7 + -0xfc) = in_FPUControlWord;
      *(ushort *)(puVar7 + -0xfa) = (ushort)*(undefined4 *)(puVar7 + -0xfc) | 0xc00;
      *(int *)(puVar7 + -0xf8) = (int)ROUND(fVar2);
      DAT_009a7f94 = *(int *)(puVar7 + -0xf8);
      *(undefined4 *)(puVar7 + -0xf4) = 0;
      *(undefined4 *)(puVar7 + -0x108) = 2;
      *(undefined **)(puVar7 + -0x104) = &DAT_020b8ed9;
      *(int **)(puVar7 + -0x100) = &DAT_009a7f94;
      ffree(Var6);
      Var6 = FUN_005f34f0(puVar7 + -0xf4,0x784ff00,&DAT_0076a164,puVar7 + -0x108,&DAT_0079f714);
      puVar1 = &ITEM_P3 + DAT_009a7f90;
      *(undefined4 *)(puVar7 + -0xf4) = 0;
      *(undefined4 *)(puVar7 + -0x108) = 5;
      *(undefined **)(puVar7 + -0x104) = &DAT_020b8ee2;
      *(undefined4 *)(puVar7 + -0x100) = 4;
      *(undefined4 **)(puVar7 + -0xfc) = puVar1;
      ffree(Var6);
      Var6 = FUN_005f34f0(puVar7 + -0xf4,0x784ff00,&DAT_0076a15c,puVar7 + -0x108,&DAT_0079f728);
      ffree(Var6);
      in_ST0 = thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
      *(undefined4 *)(puVar7 + -0xac) = 0;
LAB_0056ae13:
      ffree(in_ST0);
      return;
    }
    if (P14 == f_m1) {
      DAT_009a7f9c = DAT_009a7f9c + -3;
    }
    *(float *)(&DAT_02053434 + DAT_009a7f9c * 4) = (float)IP12;
    *(float *)(&DAT_02053438 + DAT_009a7f9c * 4) = P13;
    DAT_020b9470 = P13;
    DAT_01cadce8 = DAT_01caea40;
    if ((DAT_01caea44 == 0) || (DAT_01caea44 == 100)) {
      _DAT_009a7f8c = 0;
    }
    local_ac = 0x1ff;
    DAT_01cadce0 = 2;
    do {
      iVar4 = (&DAT_01caea3c)[DAT_01cadce0];
      if ((iVar4 < 1000) || (0x4af < iVar4)) {
        local_a8 = 0;
      }
      else if (DAT_01cadce8 == iVar4) {
        local_a4 = 0;
        DAT_01cb1068 = DAT_01cb1068 + -1;
        IP10 = DAT_01cadce0;
        for (local_9c = (DAT_01cb1068 - DAT_01cadce0) + 1; 0 < local_9c; local_9c = local_9c + -1) {
          *(undefined4 *)(&DAT_01cadd3c + IP10 * 4) = (&DAT_01cadd40)[IP10];
          (&DAT_01caea3c)[IP10] = (&DAT_01caea40)[IP10];
          IP10 = IP10 + 1;
        }
      }
      else {
        local_a0 = 0;
        DAT_01cadce8 = iVar4;
      }
      if (DAT_01cb1068 <= DAT_01cadce0) {
        local_98 = 0;
        break;
      }
      DAT_01cadce0 = DAT_01cadce0 + 1;
      local_ac = local_ac + -1;
    } while (0 < local_ac);
  }
  else {
    ffree(extraout_ST1_00);
    fVar5 = (float10)thunk_FUN_0042fa58(&DAT_020b8ea0,1,&DAT_01cb1068);
    local_cc = 0;
  }
LAB_0056a290:
  if (P11 != f_0) {
    X_POS = P11 * f_150 + X_POS;
  }
  _DAT_009a7f88 = X_POS;
  _DAT_01cadd20 = f_0;
  if (P5 == f_1) {
    local_94 = 0;
  }
  else {
    DAT_01cadce8 = -1;
    _DAT_01cadcf8 = 1;
    for (local_90 = DAT_01cb1068; 0 < local_90; local_90 = local_90 + -1) {
      if (*(float *)(&DAT_01cadd3c + _DAT_01cadcf8 * 4) != f_0) {
        DAT_01cadce8 = DAT_01cadce8 + 1;
      }
      _DAT_01cadcf8 = _DAT_01cadcf8 + 1;
    }
    if (DAT_01cadce8 < 1) {
      local_8c = 0;
    }
    else {
      fVar5 = (float10)P13 - (float10)P13 / (float10)P5;
      _DAT_01cadd20 = (float)(fVar5 / (float10)DAT_01cadce8);
      _DAT_01cadcf8 = 1;
      local_88 = DAT_01cb1068;
      while (local_88 = local_88 + -1, 0 < local_88) {
        DAT_009a7f84 = _DAT_01cadd20 + *(float *)(&DAT_01cadd3c + _DAT_01cadcf8 * 4);
        if (DAT_009a7f84 == f_0) {
          DAT_009a7f84 = f_0_1;
        }
        if (*(float *)(&DAT_01cadd3c + _DAT_01cadcf8 * 4) != f_0) {
          *(float *)(&DAT_01cadd3c + _DAT_01cadcf8 * 4) = DAT_009a7f84;
        }
        _DAT_01cadcf8 = _DAT_01cadcf8 + 1;
      }
    }
  }
  DAT_01a27710 = 0;
  _DAT_009a7f80 = 0;
  DAT_01cadcfc = 0;
  IP10 = 0;
  DAT_01be1808 = P7;
  if (P7 == f_0) {
    P7 = P48;
  }
  DAT_01be180c = P9;
  if (P14 == f_m1) {
    DAT_01be1810 = P17;
    DAT_01be1814 = P18;
  }
  else {
    DAT_01be1810 = P14;
    DAT_01be1814 = P15;
  }
  P6 = P6 * f_0_25;
  P7 = P7 * f_0_25;
  DAT_01cadce8 = 0;
  DAT_01cadcec = IP8;
  if (OUTPUT_MODE == 0) {
    local_84 = 0;
  }
  else {
    if (_DAT_01cadd24 != f_0) {
      _DAT_01cadd24 = _DAT_01cadd24 * f_150;
    }
    if (_DAT_01cadd20 != f_0) {
      _DAT_01cadd20 = _DAT_01cadd20 * f_150;
    }
    if (IP8 < 0x5a) {
      local_80 = 0;
      if ((IP8 < 0) && (DAT_0078b6a0 % 100 < 0x5a)) {
        DAT_01cadcec = 0;
      }
      if (DAT_01cadcec != 0) {
        ffree(fVar5);
        fVar5 = (float10)thunk_FUN_004d4ed2(&DAT_01cadcec);
      }
      if ((DAT_01caea40 < 1000) || (1999 < DAT_01caea40)) {
        if (_DAT_009a7f7c == P48) {
          if (_DAT_009a7f78 == P7) {
            local_70 = 0;
            goto LAB_0056a67e;
          }
        }
        else {
          local_74 = 0;
        }
        ffree(fVar5);
        fVar5 = (float10)FUN_0056b845();
      }
      else {
        local_78 = 0;
      }
    }
    else {
      ffree(fVar5);
      fVar5 = (float10)FUN_0056b706(s_BODN0BODB0BODI0BDIB0MUSI0_0079f774,5);
      local_7c = 0;
    }
    _DAT_009a7f7c = P48;
    _DAT_009a7f78 = P7;
  }
LAB_0056a67e:
  _DAT_009a7f74 = NPT;
  DAT_01cadce0 = DAT_0078b6a0 % 100;
  if (DAT_01cadce0 == 0x5e) {
    P14 = (float)s_BODN0BODB0BODI0BDIB0MUSI0_0079f774._20_4_;
    P15 = (float)CONCAT31(P15._1_3_,s_BODN0BODB0BODI0BDIB0MUSI0_0079f774[0x18]);
  }
  if (OUTPUT_MODE == -1) {
    if (DAT_01be180c == f_0) {
      local_68 = 0;
    }
    else {
      ffree(fVar5);
      fVar5 = (float10)thunk_FUN_0056f14d(&DAT_01be180c);
      DAT_0078d850 = 1;
    }
  }
  else {
    local_6c = 0;
  }
  DAT_01a1c848 = 0;
  DAT_01cadce0 = 0;
  DAT_01c6da38 = P6;
  _DAT_009a7f70 = X_POS;
  ffree(fVar5);
  fVar5 = (float10)FUN_005ff381(&stack0xfffffffc,0x56a750);
  *(int *)(puVar3 + -0xf8) = (int)ROUND(fVar5);
  iVar4 = DAT_01cb1068;
  DAT_01a27708 = *(undefined4 *)(puVar3 + -0xf8);
  *(int *)(puVar3 + -0x60) = DAT_01cb1068;
  DAT_009a7f6c = 1;
  in_ST0 = extraout_ST1_01;
  while (0 < iVar4) {
    if (*(float *)(&DAT_01cadd3c + DAT_009a7f6c * 4) == f_0) {
      if (((int)(&DAT_01caea3c)[DAT_009a7f6c] < 10000) ||
         (999999 < (int)(&DAT_01caea3c)[DAT_009a7f6c])) {
        *(undefined4 *)(puVar3 + -0x58) = 0;
      }
      else {
        *(int *)(puVar3 + -0xf8) = (&DAT_01caea3c)[DAT_009a7f6c] + -10000;
        _DAT_009a7f70 = (float)*(int *)(puVar3 + -0xf8) * f_15;
        (&DAT_01caea3c)[DAT_009a7f6c] = 0x5e;
        *(undefined4 *)(puVar3 + -0x54) = 0;
      }
      *(undefined4 *)(&DAT_01cafabc + DAT_009a7f6c * 4) = 0;
      if ((((int)(&DAT_01caea3c)[DAT_009a7f6c] < 0x7f) && ((&DAT_01caea3c)[DAT_009a7f6c] != 0x5e))
         && (0x52 < (int)(&DAT_01caea3c)[DAT_009a7f6c])) {
        *(undefined4 *)(&DAT_01cafabc + DAT_009a7f6c * 4) = 0xffffffff;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x5c) = 0;
      _DAT_009a7f68 = *(float *)(&DAT_01cadd3c + DAT_009a7f6c * 4);
      iVar4 = DAT_009a7f6c * 4;
      ffree(in_ST0);
      fVar5 = (float10)FUN_005ff381(puVar3,0x56a7d6);
      *(int *)(puVar3 + -0xf8) = (int)ROUND(fVar5);
      *(int *)(&DAT_01cafabc + iVar4) = *(int *)(puVar3 + -0xf8) + 20000;
      _DAT_009a7f70 = _DAT_009a7f68 * f_150 + _DAT_009a7f70;
      *(undefined4 *)(puVar3 + -0x50) = 0;
      in_ST0 = extraout_ST1_02;
    }
    *(undefined4 *)(&DAT_01cb02bc + DAT_009a7f6c * 4) = DAT_01a27708;
    DAT_009a7f6c = DAT_009a7f6c + 1;
    *(int *)(puVar3 + -0x60) = *(int *)(puVar3 + -0x60) + -1;
    iVar4 = *(int *)(puVar3 + -0x60);
  }
  *(int *)(puVar3 + -0x4c) = DAT_01cb1068;
  DAT_009a7f6c = 1;
  iVar4 = DAT_01cb1068;
  while (0 < iVar4) {
    if ((0x59 < DAT_01cadcec) && (*(int *)(&DAT_01cafabc + DAT_009a7f6c * 4) == 0)) {
      (&DAT_01caea3c)[DAT_009a7f6c] = DAT_01cadcec;
    }
    *(undefined4 *)(puVar3 + -0x48) = 0;
    DAT_009a7f6c = DAT_009a7f6c + 1;
    *(int *)(puVar3 + -0x4c) = *(int *)(puVar3 + -0x4c) + -1;
    iVar4 = *(int *)(puVar3 + -0x4c);
  }
  if ((DAT_01caea44 == 0) || (DAT_01caea44 == 100)) {
    _DAT_009a7f8c = 0;
  }
  if (P9 == f_0) {
    *(undefined4 *)(puVar3 + -0x44) = 0;
  }
  else {
    *(int *)(puVar3 + -0x40) = DAT_01cb1068;
    DAT_009a7f6c = 1;
    iVar4 = DAT_01cb1068;
    while (0 < iVar4) {
      *(int *)(&DAT_01cafabc + DAT_009a7f6c * 4) =
           *(int *)(&DAT_01cafabc + DAT_009a7f6c * 4) + -20000;
      DAT_009a7f6c = DAT_009a7f6c + 1;
      *(int *)(puVar3 + -0x40) = *(int *)(puVar3 + -0x40) + -1;
      iVar4 = *(int *)(puVar3 + -0x40);
    }
    ffree(in_ST0);
    in_ST0 = thunk_FUN_0056f920(&DAT_01cb1068,&DAT_01cafac0,&DAT_01cb02c0,&P9);
    *(int *)(puVar3 + -0x3c) = DAT_01cb1068;
    DAT_009a7f6c = 1;
    iVar4 = DAT_01cb1068;
    while (0 < iVar4) {
      *(int *)(&DAT_01cafabc + DAT_009a7f6c * 4) =
           *(int *)(&DAT_01cafabc + DAT_009a7f6c * 4) + 20000;
      DAT_009a7f6c = DAT_009a7f6c + 1;
      *(int *)(puVar3 + -0x3c) = *(int *)(puVar3 + -0x3c) + -1;
      iVar4 = *(int *)(puVar3 + -0x3c);
    }
  }
  do {
    DAT_01cadce0 = DAT_01cadce0 + 1;
    DAT_01cadce4 = (&DAT_01caea3c)[DAT_01cadce0];
    if (DAT_01cadce4 < 1000) {
      if (*(int *)(&DAT_01cafabc + DAT_01cadce0 * 4) < 0) {
        *(undefined4 *)(puVar3 + -0x30) = 0;
      }
      else {
        if ((DAT_01cadce4 == 0x5e) || (*(int *)(&DAT_01cafabc + DAT_01cadce0 * 4) == 0)) {
          *(undefined4 *)(puVar3 + -0x2c) = 0;
          goto LAB_0056acb7;
        }
        if (((0xa1 < DAT_01cadce4) || (DAT_01cadce4 < 0x5f)) || (OUTPUT_MODE != 1)) {
          if (DAT_01cadce4 != 0xa7) {
            if (DAT_0078b6a0 < 100) {
              if (((OUTPUT_MODE == 2) || (0x4f < DAT_01cadce4)) || (DAT_0078b6a0 == 0x5e)) {
                if ((P1 != f_10) || (DAT_0078b6a0 == 0x5e)) {
                  *(int *)(&DAT_01cafabc + DAT_01cadce0 * 4) =
                       *(int *)(&DAT_01cafabc + DAT_01cadce0 * 4) + -20000;
                  if (P14 == f_m1) {
                    P26 = P16;
                  }
                  ffree(in_ST0);
                  in_ST0 = FUN_0056b529();
                  *(undefined4 *)(puVar3 + -0x14) = 0;
                  goto LAB_0056acb7;
                }
                *(undefined4 *)(puVar3 + -0x18) = 0;
              }
              else {
                *(undefined4 *)(puVar3 + -0x1c) = 0;
              }
            }
            else {
              *(undefined4 *)(puVar3 + -0x20) = 0;
            }
            goto LAB_0056ac18;
          }
          *(undefined4 *)(puVar3 + -0x24) = 0;
        }
        DAT_01cadce4 = -DAT_01cadce4;
        *(undefined4 *)(puVar3 + -0x28) = 0;
      }
LAB_0056ac18:
      if (*(int *)(&DAT_01cafabc + DAT_01cadce0 * 4) < 1000) {
        *(int *)(&DAT_01cafabc + DAT_01cadce0 * 4) =
             *(int *)(&DAT_01cafabc + DAT_01cadce0 * 4) + 20000;
      }
      ffree(in_ST0);
      in_ST0 = thunk_FUN_00532ec0(&DAT_0076a148);
    }
    else {
      if (999999 < DAT_01cadce4) {
        DAT_01cadce4 = 0x403;
      }
      DAT_0078b6a0 = DAT_01cadce4 % 1000;
      if (DAT_0078b6a0 == 0x5e) {
        *(undefined4 *)(puVar3 + -0x38) = 0;
      }
      else {
        ffree(in_ST0);
        in_ST0 = thunk_FUN_0056caf0(&DAT_009a7f64);
        if ((DAT_01caea44 == 0) || (DAT_01caea44 == 100)) {
          _DAT_009a7f8c = 0;
        }
        *(undefined4 *)(puVar3 + -0x34) = 0;
      }
    }
LAB_0056acb7:
    if (DAT_01cb1068 <= DAT_01cadce0) break;
    *(undefined4 *)(puVar3 + -0x10) = 0;
  } while( true );
  if (IP1 != 0x10) {
    P5 = DAT_01be1800;
  }
  P6 = DAT_01be1804;
  P7 = DAT_01be1808;
  P14 = DAT_009a7fa8;
  P15 = DAT_009a7fa4;
  P16 = DAT_009a7fa0;
  if (DAT_009a7fa8 == f_m1) {
    P17 = DAT_01be1810;
    P18 = DAT_01be1814;
  }
  else {
    P14 = DAT_01be1810;
    P15 = DAT_01be1814;
  }
  if (EDIT_ITEM == 0) {
    (&DAT_020a55a0)[ITEM_I] = *DAT_01fbb844 + 1;
  }
  else {
    (&DAT_020a55a4)[ITEM_I] = *DAT_01fbb844 + 1;
  }
  if (OUTPUT_MODE == 0) {
    *(undefined4 *)(puVar3 + -0xc) = 0;
    if (DAT_01be180c != f_0) {
      ffree(in_ST0);
      in_ST0 = thunk_FUN_0042a5f4(&DAT_009a7f74,&DAT_009a7f88,&Y_POS,&DAT_01be180c);
    }
  }
  else if ((DAT_01cadcec == 0) || (0x59 < DAT_01cadcec)) {
    *(undefined4 *)(puVar3 + -8) = 0;
  }
  else {
    ffree(in_ST0);
    in_ST0 = thunk_FUN_004d4f3f();
    *(undefined4 *)(puVar3 + -4) = 0;
  }
  goto LAB_0056ae13;
}


