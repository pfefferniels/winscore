// FUN_00475020 @ 00475020 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff28 : 0x00475649 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_00475020(int *param_1)

{
  char cVar1;
  char *extraout_EDX;
  char *extraout_EDX_00;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined1 uVar5;
  bool bVar6;
  undefined4 local_10c [6];
  undefined4 local_f4;
  undefined4 *local_f0;
  undefined4 local_ec;
  char *local_e8;
  undefined4 local_e4;
  char *local_e0;
  int *local_dc;
  int local_94;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_6c;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  
  DAT_0078b4e0 = DAT_01c58604;
  if (DAT_00795464 == 0) {
    DAT_00790d84 = 1;
    DAT_01c58608 = 0;
  }
  else {
    DAT_01c58608 = DAT_01c58608 - DAT_01c58604;
    DAT_00826f40 = (float)DAT_01c58608;
    _DAT_00826f88 =
         (DAT_01be0954 / (float)((&DAT_01be0960)[DAT_01be12c8] * DAT_01c58604) - f_0_78732) /
         f_0_04374;
    DAT_00826f84 = 1;
    for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
      DAT_00826f80 = (&ITEM_PTR0)[DAT_00826f84];
      (&ITEM_P2)[DAT_00826f80] = DAT_00826f40 + (float)(&ITEM_P2)[DAT_00826f80];
      DAT_00826f84 = DAT_00826f84 + 1;
    }
  }
  ITEM_WORDS = ITEM_WORDS + -1;
  DAT_00826f84 = 1;
  if (DAT_00795464 == 0) {
    for (; (float)(&ITEM_P1)[DAT_00826f84] == f_14; DAT_00826f84 = DAT_00826f80 + DAT_00826f84 + 1)
    {
      DAT_00826f80 = (int)ROUND((float)(&ITEM_LEN)[DAT_00826f84]);
      ITEM_WORDS = (ITEM_WORDS - DAT_00826f80) + -1;
    }
  }
  if (DAT_00790d84 != 1) {
    FUN_005f33c9();
    FUN_005f33c9();
    local_f0 = local_10c;
    local_f4 = 0x11;
    local_ec = 6;
    local_e4 = 2;
    local_e0 = (char *)0x4;
    local_e8 = extraout_EDX;
    local_94 = FUN_005f6540();
    if (local_94 != 0) goto FUN_0047603d;
    local_e0 = (char *)DAT_00790d84;
    if (DAT_00790d84 < 0) {
      local_e0 = (char *)0x0;
    }
    DAT_00826f80 = (int)local_e0 + 1;
    local_ec = 1;
    local_e8 = (char *)&DAT_01ba2140;
    local_e4 = 1;
    local_dc = (int *)0x4;
    FUN_005f8240();
    FUN_005f7950();
  }
  thunk_FUN_0054c590();
  if (DAT_00795464 == 0) {
    DAT_00790d84 = ITEM_WORDS + 1;
    local_84 = 0;
  }
  else {
    local_88 = 0;
    DAT_00790d84 = ITEM_WORDS + DAT_00790d84;
    if (*param_1 != 0) {
      FUN_005f33c9();
      FUN_005f33c9();
      local_f0 = local_10c;
      local_f4 = 0x11;
      local_ec = 6;
      local_e4 = 2;
      local_e0 = (char *)0x4;
      local_e8 = extraout_EDX_00;
      local_7c = FUN_005f6540();
      if (local_7c == 0) {
        local_e0 = (char *)DAT_00790d84;
        if (DAT_00790d84 < 0) {
          local_e0 = (char *)0x0;
        }
        DAT_00826f80 = (int)local_e0 + 1;
        local_ec = 1;
        local_e8 = (char *)&DAT_01ba2140;
        local_e4 = 1;
        local_dc = (int *)0x4;
        FUN_005fa4d0();
        FUN_005f7950();
        return;
      }
      goto FUN_0047603d;
    }
    local_80 = 0;
  }
  if (DAT_01c58608 == 0) {
    local_6c = 0;
  }
  else {
    DAT_00826f84 = 1;
    while( true ) {
      DAT_00826f80 = (int)ROUND(*(float *)(&DAT_01ba213c + DAT_00826f84 * 4));
      (&DAT_01ba2144)[DAT_00826f84] = (float)(&DAT_01ba2144)[DAT_00826f84] - DAT_00826f40;
      if ((float)(&DAT_01ba2140)[DAT_00826f84] == f_8) {
        if (DAT_00826f80 < 5) {
          DAT_0078b4e4 = 5 - DAT_00826f80;
          DAT_00826f7c = DAT_0078b4e4 + DAT_00790d84;
          DAT_00790d84 = DAT_00826f7c;
          for (local_64 = ((DAT_00826f84 - DAT_00826f7c) + 5) / -1; 0 < local_64;
              local_64 = local_64 + -1) {
            *(undefined4 *)(&DAT_01ba213c + DAT_00826f7c * 4) =
                 *(undefined4 *)(&DAT_01ba213c + (DAT_00826f7c - DAT_0078b4e4) * 4);
            DAT_00826f7c = DAT_00826f7c + -1;
          }
          if (DAT_00826f80 == 2) {
            (&DAT_01ba2148)[DAT_00826f84] = i_0;
          }
          *(float *)(&DAT_01ba213c + DAT_00826f84 * 4) = f_5;
          DAT_00826f80 = 5;
          (&DAT_01ba2150)[DAT_00826f84] = f_1;
        }
        (&DAT_01ba214c)[DAT_00826f84] = i_0;
      }
      else {
        local_68 = 0;
      }
      DAT_00826f84 = DAT_00826f80 + DAT_00826f84 + 1;
      if (DAT_00790d84 <= DAT_00826f84) break;
      local_60 = 0;
    }
  }
  if (DAT_01c58600 != 2) {
    FUN_00476063();
  }
  thunk_FUN_0049836a();
  uVar5 = &stack0x00000000 == (undefined1 *)0x11c;
  DAT_0078b4e4 = 0x53;
  thunk_FUN_0049846f();
  iVar2 = 1;
  piVar3 = (int *)((int)&DAT_01ba20a0 + 3);
  piVar4 = &DAT_00762294;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    uVar5 = *piVar3 == *piVar4;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  } while ((bool)uVar5);
  if ((bool)uVar5) {
    local_5c = 0;
  }
  else {
    if (1 < DAT_0078b4e0) {
      _DAT_00826f74 = f_2 / (float)(DAT_0078b4e0 + -1);
    }
    DAT_00826f84 = 1;
    _DAT_00826f78 = (float)i_0;
    DAT_0078b4e4 = DAT_0078b4e0;
    for (local_58 = ITEM_I; 0 < local_58; local_58 = local_58 + -1) {
      DAT_00826f80 = (&ITEM_PTR0)[DAT_00826f84];
      bVar6 = f_16 < *(float *)(&DAT_01ba213c + DAT_00826f80 * 4);
      if (f_16 < *(float *)(&DAT_01ba213c + DAT_00826f80 * 4)) {
        iVar2 = 1;
        piVar3 = (int *)((int)&DAT_01ba20a0 + 3);
        piVar4 = &DAT_00762294;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *piVar3 == *piVar4;
          piVar3 = piVar3 + 1;
          piVar4 = piVar4 + 1;
        } while (bVar6);
        if ((!bVar6) && ((float)(&DAT_01ba2140)[DAT_00826f80] == f_2)) {
          *(int *)(&DAT_01ba2180 + DAT_00826f80 * 4) = i_0;
        }
      }
      if ((float)(&DAT_01ba2140)[DAT_00826f80] == f_8) {
        DAT_0078b4e4 = DAT_0078b4e4 + -1;
        _DAT_00826f70 = (float)(&DAT_01ba2144)[DAT_00826f80];
        if (_DAT_00826f70 == f_1) {
          local_50 = 0;
        }
        else {
          DAT_00826f40 = f_1;
          if (f_5 <= *(float *)(&DAT_01ba213c + DAT_00826f80 * 4)) {
            DAT_00826f40 = (float)(&DAT_01ba2150)[DAT_00826f80];
          }
          if (DAT_00826f40 == 0.0) {
            DAT_00826f40 = f_1;
          }
          (&DAT_01ba214c)[DAT_00826f80] =
               ((_DAT_00826f70 - f_1) * _DAT_00826f88) / DAT_00826f40 - _DAT_00826f78;
          if (DAT_0078b4e4 < 1) {
            _DAT_00826f78 = (float)i_0;
            DAT_0078b4e4 = DAT_0078b4e0;
          }
          else {
            local_4c = 0;
          }
        }
        _DAT_00826f78 = _DAT_00826f74 + _DAT_00826f78;
      }
      else {
        local_54 = 0;
      }
      local_48 = 0;
      DAT_00826f84 = DAT_00826f84 + 1;
    }
  }
  DAT_00826f84 = -1;
  bVar6 = DAT_01c5860c == 3;
  if (DAT_01c5860c < 3) {
    DAT_00826f84 = 1;
  }
  iVar2 = 1;
  piVar3 = (int *)((int)&DAT_01ba20a0 + 3);
  piVar4 = &DAT_00762294;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *piVar3 == *piVar4;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (bVar6);
  if (bVar6) {
    local_44 = 0;
  }
  else {
    DAT_00826f6c = 1;
    for (local_40 = ITEM_I; 0 < local_40; local_40 = local_40 + -1) {
      DAT_00826f68 = (&ITEM_PTR0)[DAT_00826f6c];
      if (((*(float *)(&DAT_01ba213c + DAT_00826f68 * 4) < f_5) ||
          ((float)(&DAT_01ba2140)[DAT_00826f68] != f_2)) ||
         (f_m2 < (float)(&DAT_01ba2150)[DAT_00826f68])) {
        local_3c = 0;
      }
      else {
        if (f_16 < *(float *)(&DAT_01ba213c + DAT_00826f68 * 4)) {
          *(int *)(&DAT_01ba2180 + DAT_00826f68 * 4) = i_0;
        }
        if (f_8 < *(float *)(&DAT_01ba213c + DAT_00826f68 * 4)) {
          *(float *)(&DAT_01ba2160 + DAT_00826f68 * 4) = f_m1;
        }
        DAT_00826f64 = (int)ROUND(*(float *)(&DAT_01ba213c + DAT_00826f68 * 4));
        DAT_00826f60 = (int)ROUND((float)(&DAT_01ba2150)[DAT_00826f68]);
        if (DAT_00826f64 < 8) {
          local_38 = 0;
        }
        else {
          DAT_00826f84 = DAT_00826f68 + 8;
          if ((DAT_00826f60 == -2) && (*(float *)(&DAT_01ba213c + DAT_00826f84 * 4) == f_1)) {
            *(undefined4 *)(&DAT_01ba213c + DAT_00826f84 * 4) = DAT_00795450;
          }
          if ((DAT_00795454 == 0) && (DAT_00826f60 < -0xb)) {
            DAT_00826f60 = -2;
            if (f_1 < *(float *)(&DAT_01ba213c + DAT_00826f84 * 4)) {
              DAT_00826f60 = -5;
            }
            (&DAT_01ba2150)[DAT_00826f68] = (float)DAT_00826f60;
          }
          else {
            local_34 = 0;
          }
        }
      }
      local_30 = 0;
      DAT_00826f6c = DAT_00826f6c + 1;
    }
  }
  local_f4 = 0x80;
  local_f0 = &DAT_01ba20a0;
  local_ec = 7;
  local_e8 = "unknown";
  local_e4 = 6;
  local_e0 = "binary";
  local_dc = (int *)0x2;
  local_2c = FUN_005f6540();
  if (local_2c == 0) {
    DAT_00826f84 = 64000;
    DAT_00826f7c = DAT_00790d84;
    DAT_00826f80 = DAT_01c5860c;
    if (DAT_01c5860c < 0) {
      DAT_00826f80 = -DAT_01c5860c;
    }
    if (DAT_00826f80 < 2) {
      local_28 = 0;
    }
    else {
      (&DAT_01ba2140)[DAT_00790d84] = (float)DAT_00826f80;
      (&DAT_01ba2144)[DAT_00826f7c] = (float)DAT_0078b4e8;
      (&DAT_01ba2148)[DAT_00826f7c] = f_4;
      DAT_00826f7c = DAT_00826f7c + 4;
      *(float *)(&DAT_01ba213c + DAT_00826f7c * 4) = f_m9999;
    }
    local_dc = &DAT_00826f7c;
    FUN_005fa4d0();
    local_e0 = (char *)DAT_00826f7c;
    if (DAT_00826f7c < 0) {
      local_e0 = (char *)0x0;
    }
    DAT_00826f84 = (int)local_e0 + 1;
    local_ec = 1;
    local_e8 = (char *)&DAT_01ba2140;
    local_e4 = 1;
    local_dc = (int *)0x4;
    FUN_005fa9f0();
    FUN_005f7950();
    bVar6 = &stack0x00000000 == (undefined1 *)0x11c;
    DAT_00790d84 = 1;
    DAT_00826f84 = DAT_01ba2120;
    iVar2 = 1;
    piVar3 = (int *)((int)&DAT_01ba20a0 + 3);
    piVar4 = &DAT_00762294;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *piVar3 == *piVar4;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (bVar6);
    if (bVar6) {
      DAT_00826f84 = 0xd;
    }
    do {
      cVar1 = (&DAT_01ba209f)[DAT_00826f84] + '\x01';
      _DAT_00826f58 = CONCAT31(DAT_00826f58_1,cVar1);
      if (cVar1 < 'A') {
        if (cVar1 < ':') {
LAB_00476015:
          (&DAT_01ba209f)[DAT_00826f84] = cVar1;
          return;
        }
        DAT_00826f50 = CONCAT31(DAT_00826f50._1_3_,0x30);
      }
      else {
        if (cVar1 < '[') goto LAB_00476015;
        DAT_00826f50 = CONCAT31(DAT_00826f50._1_3_,0x41);
      }
      (&DAT_01ba209f)[DAT_00826f84] = (char)DAT_00826f50;
      DAT_00826f84 = DAT_00826f84 + -1;
      if (DAT_00826f84 < 1) {
        return;
      }
    } while( true );
  }
FUN_0047603d:
                    /* WARNING: Subroutine does not return */
  FUN_006013a0();
}


