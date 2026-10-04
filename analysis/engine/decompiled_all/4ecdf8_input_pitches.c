// input_pitches @ 004ecdf8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void input_pitches(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  uint local_124;
  int local_120;
  undefined4 local_fc;
  int local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  int local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_0078cd30 = 0;
  DAT_01f95c80 = f_0;
  DAT_01f95c84 = 0;
  DAT_01fb8c88 = 0;
  DAT_01f95c88 = DAT_01fb8cc0;
  DAT_01f95c8c = (int)ROUND(DAT_01fb8c60);
  if (DAT_01be12e0 == 0) {
    DAT_01f95c90 = *(int *)(&DAT_01e67504 + DAT_01f95c8c * 4);
  }
  else {
    DAT_01f95c90 = 0;
  }
  DAT_01f95c94 = DAT_01f95c90;
  if ((int)ROUND(DAT_01fb8cc4 / f_1000) == 4) {
    local_fc = 0;
  }
  else if (DAT_01e67910 == f_0) {
    DAT_01e67910 = f_1_5;
  }
  DAT_008d1768 = DAT_01fb8cc0 + 1;
  DAT_008d1764 = 1;
  for (local_f8 = DAT_01fb8cc0; 0 < local_f8; local_f8 = local_f8 + -1) {
    if ((int)ROUND((float)(&DAT_01fb8cc0)[DAT_008d1764]) < 0) {
      iVar4 = (int)ROUND((float)(&DAT_01fb8cc0)[DAT_008d1764]) / 1000;
      if ((iVar4 == -1) || (iVar4 == -7)) {
        DAT_008d1768 = DAT_008d1768 + -1;
      }
    }
    else {
      local_f4 = 0;
    }
    local_f0 = 0;
    DAT_008d1764 = DAT_008d1764 + 1;
  }
  _DAT_008d1760 = (DAT_01e67914 - DAT_01e67910) / (float)DAT_008d1768;
  _DAT_01fb8c70 = f_0;
  DAT_01fb8c68 = 0;
  _DAT_008d175c = 0;
  DAT_008d1758 = 0;
  DAT_008d1768 = 1;
  DAT_008d1764 = 1;
  do {
    DAT_008d1754 = -1;
    local_124 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_0078cd34 = (int)ROUND((float)(&DAT_01fb8cc0)[DAT_008d1764]);
    iVar4 = DAT_0078cd34;
    if (DAT_0078cd34 < 0) {
      iVar4 = -DAT_0078cd34;
    }
    DAT_008d1750 = iVar4 / 1000;
    if (DAT_008d1750 == 7) {
      DAT_008d1750 = 1;
    }
    else {
      local_ec = 0;
    }
    local_120 = DAT_0078cd34;
    if (DAT_008d1750 < 2) {
      if ((DAT_0078cd34 < 0) || (DAT_01f95c88 == DAT_008d1764)) {
        local_e4 = 0;
      }
      else {
        DAT_008d174c = DAT_008d1764 + 1;
        local_124 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        local_120 = (int)ROUND((float)(&DAT_01fb8cc0)[DAT_008d174c]);
        DAT_008d1748 = local_120 / 1000;
        DAT_008d1744 = DAT_008d1748;
        if (DAT_008d1748 < 0) {
          DAT_008d1744 = -DAT_008d1748;
        }
        if (DAT_008d1744 == 7) {
          DAT_008d1744 = 1;
        }
        if ((DAT_008d1748 < 1) && (DAT_008d1744 == 1)) {
          while (DAT_008d174c = DAT_008d174c + 1, DAT_008d174c <= DAT_01fb8cc0) {
            DAT_008d1748 = (int)ROUND((float)(&DAT_01fb8cc0)[DAT_008d174c] / f_1000);
            local_120 = DAT_008d1748;
            if ((DAT_008d1748 != -7) && (DAT_008d1748 != -1)) goto LAB_004ed280;
            local_d8 = 0;
          }
          local_dc = 0;
LAB_004ed280:
          local_124 = DAT_008d174c - DAT_008d1764;
          ffree(in_ST0);
          thunk_FUN_0054c590(&DAT_01fb8cc0 + DAT_008d1764,&DAT_01f9a0ac + DAT_008d1764 * 4,
                             &local_124);
          DAT_008d1748 = 99;
          DAT_008d1744 = -99;
          DAT_008d1740 = 0;
          _DAT_008d173c = *(int *)(&DAT_00794ce4 + DAT_01f95c90 * 4);
          iVar4 = DAT_008d1748;
          iVar2 = DAT_008d1744;
          DAT_008d1738 = DAT_008d1764;
          iVar3 = _DAT_008d172c;
          iVar1 = DAT_008d1730;
          for (local_d4 = DAT_008d174c - DAT_008d1764; 0 < local_d4; local_d4 = local_d4 + -1) {
            iVar5 = (int)ROUND((float)(&DAT_01fb8cc0)[DAT_008d1738]);
            if (iVar5 < 0) {
              iVar5 = -iVar5;
            }
            iVar5 = iVar5 % 100 - _DAT_008d173c;
            DAT_008d1740 = DAT_008d1740 + 1;
            DAT_008d1730 = DAT_008d1740;
            DAT_008d1744 = iVar5;
            if (iVar5 < iVar2) {
              local_d0 = 0;
              DAT_008d1730 = iVar1;
              DAT_008d1744 = iVar2;
            }
            _DAT_008d172c = DAT_008d1740;
            DAT_008d1748 = iVar5;
            if (iVar4 < iVar5) {
              local_cc = 0;
              _DAT_008d172c = iVar3;
              DAT_008d1748 = iVar4;
            }
            *(int *)(&DAT_01f9a3cc + DAT_008d1740 * 4) = iVar5;
            DAT_008d1738 = DAT_008d1738 + 1;
            iVar4 = DAT_008d1748;
            iVar2 = DAT_008d1744;
            iVar3 = _DAT_008d172c;
            iVar1 = DAT_008d1730;
          }
          if (DAT_008d1758 == 0) {
            local_c8 = 0;
            if (DAT_008d1740 == 2) {
              local_c0 = 0;
            }
            DAT_008d1734 = 0xe - (iVar4 + iVar2);
            local_bc = 0;
          }
          else {
            DAT_008d1734 = 0xb - DAT_008d1758;
            local_c4 = 0;
          }
          DAT_008d1728 = -99;
          if (0 < DAT_008d1734) {
            DAT_008d1728 = 99;
          }
          DAT_008d1738 = 1;
          _DAT_008d172c = iVar3;
          DAT_008d1730 = iVar1;
          DAT_008d1744 = iVar2;
          DAT_008d1748 = iVar4;
          for (local_b4 = DAT_008d1740; 0 < local_b4; local_b4 = local_b4 + -1) {
            DAT_008d1734 = 1;
            DAT_008d1724 = DAT_008d1728;
            for (iVar4 = DAT_008d1740; 0 < iVar4; iVar4 = iVar4 + -1) {
              DAT_008d1720 = *(int *)(&DAT_01f9a3cc + DAT_008d1734 * 4);
              iVar2 = DAT_008d1720;
              iVar3 = DAT_008d1734;
              if (DAT_008d1728 < 0) {
                local_b0 = 0;
                if (DAT_008d1720 <= DAT_008d1724) {
                  local_a4 = 0;
                  iVar2 = DAT_008d1724;
                  iVar3 = DAT_008d1730;
                }
              }
              else if (DAT_008d1720 < DAT_008d1724) {
                local_a8 = 0;
              }
              else {
                local_ac = 0;
                iVar2 = DAT_008d1724;
                iVar3 = DAT_008d1730;
              }
              DAT_008d1730 = iVar3;
              DAT_008d1724 = iVar2;
              local_a0 = 0;
              DAT_008d1734 = DAT_008d1734 + 1;
            }
            *(int *)(DAT_008d1738 * 4 + 0x1f9a55c) = DAT_008d1730 + -1;
            *(int *)(&DAT_01f9a3cc + DAT_008d1730 * 4) = DAT_008d1728;
            DAT_008d1738 = DAT_008d1738 + 1;
          }
          DAT_008d1734 = 0;
          DAT_008d1738 = DAT_008d1764;
          for (iVar4 = DAT_008d174c - DAT_008d1764; 0 < iVar4; iVar4 = iVar4 + -1) {
            DAT_008d1734 = DAT_008d1734 + 1;
            (&DAT_01fb8cc0)[DAT_008d1738] =
                 (int)-ABS(*(float *)(&DAT_01f9a0ac +
                                     (*(int *)(DAT_008d1734 * 4 + 0x1f9a55c) + DAT_008d1764) * 4));
            DAT_008d1738 = DAT_008d1738 + 1;
          }
          in_ST0 = (float10)(float)(&DAT_01fb8cc0)[DAT_008d1764];
          (&DAT_01fb8cc0)[DAT_008d1764] = (int)(float)-in_ST0;
          local_124 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
          DAT_0078cd34 = (int)ROUND((float)(&DAT_01fb8cc0)[DAT_008d1764]);
          local_120 = DAT_0078cd34;
        }
        else {
          local_e0 = 0;
        }
      }
    }
    else {
      local_e8 = 0;
    }
    DAT_008d171c = f_0;
    DAT_008d1718 = f_0;
    DAT_008d1714 = f_0;
    DAT_008d1710 = f_0;
    DAT_008d170c = f_0;
    (&DAT_01f95d48)[DAT_008d1768 * 0xf] = DAT_01fb8c60;
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0054cd13(&DAT_01f95d5c + DAT_008d1768 * 0x3c,&DAT_00766420);
    if ((DAT_0078cd34 < 0) && (DAT_008d1750 != 2)) {
      local_9c = 0;
    }
    else if (DAT_008d1750 < 3) {
      DAT_01fb8c88 = DAT_01fb8c88 + 1;
    }
    switch(DAT_008d1750) {
    case 1:
      *(float *)(&DAT_01f95d70 + DAT_008d1768 * 0x3c) = DAT_01f95c80;
      if (DAT_0078cd34 < 1) {
        DAT_0078cd34 = -DAT_0078cd34;
        DAT_008d170c = f_m1;
        DAT_008d1754 = 0;
      }
      else {
        uStack_48 = 0;
      }
      DAT_008d1738 = DAT_0078cd34 % 1000;
      DAT_008d1718 = (float)(DAT_008d1738 / 100);
      iVar4 = DAT_008d1738 % 100 + -1;
      DAT_008d1708 = iVar4 / 7;
      DAT_008d1740 = iVar4 % 7 + 1;
      DAT_008d1704 = DAT_01f95c90 * 0xc;
      if (1 < DAT_01f95c90) {
        DAT_008d1704 = DAT_01f95c90 * 2 + 2;
      }
      DAT_008d171c = (float)(DAT_008d1708 * 7 + DAT_008d1704 + DAT_008d1740 + -0x1c);
      if (DAT_008d1754 == 0) {
        uStack_44 = 0;
        iRam008d16fc = (int)ROUND((float)(&DAT_01f95d54)[(DAT_008d1768 + -1) * 0xf]) % 100;
        if (9 < iRam008d16fc) {
          iRam008d16f8 = DAT_008d1768 + -1;
        }
        fRam008d1700 = f_0;
        DAT_008d1708 = DAT_008d1768 - iRam008d16f8;
        DAT_008d1738 = (int)ROUND(DAT_008d171c);
        DAT_008d1704 = (int)ROUND((float)(&DAT_01f95d50)[iRam008d16f8 * 0xf]) % 100;
        if (DAT_008d1738 < DAT_008d1704) {
          DAT_008d1708 = -DAT_008d1708;
        }
        if ((DAT_008d1704 == DAT_008d1738) && (DAT_008d1708 = 1, 0x13 < iRam008d16fc)) {
          DAT_008d1708 = -1;
        }
        *(float *)(&DAT_01f95d5c + iRam008d16f8 * 0x3c) = (float)DAT_008d1708;
        DAT_008d1738 = DAT_008d1704 - DAT_008d1738;
        if (DAT_008d1738 < 0) {
          DAT_008d1738 = -DAT_008d1738;
        }
        if ((float)(&DAT_01f95d60)[iRam008d16f8 * 0xf] < (float)DAT_008d1738) {
          (&DAT_01f95d60)[iRam008d16f8 * 0xf] = (float)DAT_008d1738;
        }
      }
      else {
        DAT_01fb8c68 = DAT_01fb8c68 + 1;
        *(int *)(&DAT_01f9929c + DAT_01fb8c68 * 4) = DAT_008d1758;
        *(int *)(&DAT_01f995bc + DAT_01fb8c68 * 4) = DAT_008d1768;
        if (DAT_008d1758 == 0) {
          uStack_40 = 0;
          fRam008d1700 = _DAT_00766404;
          if (_UNK_00766400 <= DAT_008d171c) {
            fRam008d1700 = f_20;
          }
        }
        else {
          fRam008d1700 = _DAT_01fb8c70;
          uStack_3c = 0;
        }
        if (fRam008d1700 < f_20) {
          if (DAT_008d171c < f_0) {
            in_ST0 = (float10)DAT_008d171c;
            DAT_008d1710 = (float)-in_ST0;
          }
          uStack_34 = 0;
        }
        else {
          uStack_38 = 0;
          if (_UNK_0076641c < DAT_008d171c) {
            DAT_008d1710 = DAT_008d171c - _UNK_0076641c;
          }
          uStack_30 = 0;
        }
      }
      _DAT_008d16f4 = f_0;
      if (7000 < DAT_0078cd34) {
        _DAT_008d16f4 = f_100;
      }
      DAT_008d1718 = fRam008d1700 + DAT_008d1718 + _DAT_008d16f4;
      break;
    case 2:
    case 9:
      iVar4 = DAT_0078cd34;
      if (DAT_0078cd34 < 0) {
        iVar4 = -DAT_0078cd34;
      }
      DAT_0078cd38 = iVar4 + -2000;
      if (DAT_0078cd34 < 0) {
        uStack_68 = 0;
        DAT_008d1710 = (float)DAT_0078cd38;
DAT_004eda69:
        DAT_008d1718 = _UNK_0076640c;
code_r0x004eda75:
        DAT_008d170c = f_m1;
        if (DAT_0078cd38 < 8) {
          uStack_50 = 0;
        }
        else {
          if (DAT_0078cd38 == 8) {
            DAT_0078cd38 = 4;
          }
          uStack_4c = 0;
DAT_004edab1:
          DAT_008d171c = _UNK_00766408;
          if (DAT_0078cd38 == 4) {
            in_ST0 = (float10)_UNK_00766408;
            DAT_008d171c = (float)-in_ST0;
          }
          uStack_5c = 0;
        }
      }
      else {
        switch(iVar4) {
        case 0x7d1:
          DAT_008d1714 = f_m1;
          uStack_58 = 0;
          break;
        case 0x7d2:
        case 0x7d8:
        case 0x7d9:
          goto DAT_004eda69;
        case 0x7d3:
          DAT_008d1718 = _UNK_00766410;
          uStack_54 = 0;
          goto code_r0x004eda75;
        case 0x7d4:
        case 0x7d5:
          goto DAT_004edab1;
        case 0x7d6:
          DAT_008d1710 = f_m1;
          uStack_60 = 0;
          break;
        case 0x7d7:
          break;
        default:
          uStack_64 = 0;
        }
      }
      break;
    case 3:
      iVar4 = DAT_0078cd34;
      if (DAT_0078cd34 < 0) {
        iVar4 = -DAT_0078cd34;
      }
      DAT_01f95c90 = iVar4 + -3000;
      if (-1 < DAT_0078cd34) {
        DAT_008d1718 = (float)DAT_01f95c90;
        if (DAT_01f95c90 == 4) {
          DAT_01f95c90 = 0;
        }
        if (DAT_008d1768 == 1) {
          uStack_8c = 0;
        }
        else if ((DAT_01f95c94 < 0) ||
                (*(float *)(DAT_008d1768 * 0x3c + 0x1f95d08) != _UNK_0076641c)) {
          DAT_008d171c = DAT_008d171c + f_100;
        }
        DAT_01f95c94 = -1;
        uStack_88 = 0;
        break;
      }
      uStack_90 = 0;
      goto LAB_004ee1c7;
    case 4:
      DAT_008d171c = (float)(DAT_0078cd34 % 100);
      DAT_008d1708 = (DAT_0078cd34 + -4000) / 100;
      DAT_008d1718 = (float)DAT_008d1708;
      DAT_008d1750 = 0xe;
      if (DAT_008d1708 == 9) {
        in_ST0 = (float10)(DAT_0078cd34 % 100);
        DAT_008d171c = (float)-in_ST0;
        DAT_008d1718 = f_0;
        uStack_74 = 0;
      }
      else {
        uStack_78 = 0;
      }
      break;
    case 5:
      DAT_008d1758 = DAT_0078cd34 + -5000;
      _DAT_008d175c = DAT_008d1758;
      goto code_r0x004ed917;
    case 6:
      DAT_01f95c80 = (float)(DAT_0078cd34 + -6000);
      uStack_80 = 0;
      goto LAB_004ee1c7;
    case 7:
    case 8:
      DAT_0078cd30 = DAT_0078cd34 + -8000;
      if (DAT_0078cd30 == 0) {
        DAT_008d1758 = _DAT_008d175c;
      }
      else if (DAT_008d1758 == 0) {
        DAT_008d1758 = 10;
      }
      uStack_7c = 0;
code_r0x004ed917:
      _DAT_01fb8c70 = (float)DAT_008d1758;
      uStack_84 = 0;
      goto LAB_004ee1c7;
    default:
      if (DAT_008d1750 == 0x11) {
        local_98 = 0;
        iVar4 = DAT_0078cd34;
        if (DAT_0078cd34 < 0) {
          iVar4 = -DAT_0078cd34;
        }
        DAT_008d1718 = (float)(iVar4 + -17000);
        if (DAT_008d1718 == f_0) {
          local_70 = 0;
          goto LAB_004ee1c7;
        }
        if (DAT_0078cd34 < 0) {
          in_ST0 = (float10)(iVar4 + -17000);
          DAT_008d1718 = (float)-in_ST0;
        }
        DAT_008d1714 = (float)DAT_01f95c90;
        local_6c = 0;
      }
      else {
        DAT_008d1718 = (float)((DAT_0078cd34 + -20000) / 100);
        DAT_008d1714 = (float)(DAT_0078cd34 % 100);
        DAT_008d1750 = 0x12;
        local_94 = 0;
      }
    }
    if ((DAT_008d1750 < 3) && (DAT_0078cd30 != 0)) {
      _DAT_008d16f4 = f_100;
      if (DAT_008d171c < f_0) {
        in_ST0 = (float10)f_100;
        _DAT_008d16f4 = (float)-in_ST0;
      }
      DAT_008d171c = _DAT_008d16f4 + DAT_008d171c;
    }
    else {
      local_2c = 0;
    }
    if (DAT_008d1750 == 9) {
      DAT_01fb8c88 = DAT_01fb8c88 + 1;
      DAT_008d1750 = 2;
      DAT_008d1710 = f_m1;
      DAT_008d171c = f_m6;
      if (DAT_0078cd34 == 0x2329) {
        in_ST0 = (float10)f_m6;
        DAT_008d171c = (float)-in_ST0;
      }
    }
    else {
      local_28 = 0;
    }
    (&DAT_01f95d44)[DAT_008d1768 * 0xf] = (float)DAT_008d1750;
    if (DAT_008d1718 < f_0) {
      DAT_008d171c = f_0;
    }
    (&DAT_01f95d50)[DAT_008d1768 * 0xf] = DAT_008d171c;
    (&DAT_01f95d54)[DAT_008d1768 * 0xf] = DAT_008d1718;
    (&DAT_01f95d58)[DAT_008d1768 * 0xf] = DAT_008d1714;
    (&DAT_01f95d60)[DAT_008d1768 * 0xf] = DAT_008d1710;
    *(float *)(&DAT_01f95d7c + DAT_008d1768 * 0x3c) = DAT_008d170c;
    if (DAT_008d1754 < 0) {
      DAT_01f95c84 = DAT_01f95c84 + 1;
    }
    (&DAT_01f95d4c)[DAT_008d1768 * 0xf] = (float)DAT_01f95c84 * _DAT_008d1760 + DAT_01e67910;
    DAT_008d1768 = DAT_008d1768 + 1;
LAB_004ee1c7:
    DAT_008d1764 = DAT_008d1764 + 1;
    if (DAT_01f95c88 < DAT_008d1764) {
      (&DAT_01f95d44)[DAT_008d1768 * 0xf] = f_0;
      DAT_01fb8c80 = DAT_008d1768 + -1;
      DAT_008d1738 = 1;
      for (local_20 = DAT_01fb8c68; 0 < local_20; local_20 = local_20 + -1) {
        DAT_008d1768 = *(int *)(&DAT_01f995bc + DAT_008d1738 * 4);
        DAT_008d16f0 = *(float *)(&DAT_01f95d5c + DAT_008d1768 * 0x3c);
        if (DAT_008d16f0 == f_0) {
          local_1c = 0;
        }
        else {
          DAT_008d1704 = (int)ROUND((float)(&DAT_01f95d54)[DAT_008d1768 * 0xf]);
          DAT_008d1708 = 0;
          if (DAT_008d1704 < 100) {
            local_18 = 0;
          }
          else {
            DAT_008d1708 = 100;
            DAT_008d1704 = DAT_008d1704 + -100;
          }
          _DAT_008d16ec = DAT_008d16f0;
          if (DAT_008d1704 < 10) {
            local_14 = 0;
          }
          else {
            if (DAT_008d16f0 <= f_0) {
              in_ST0 = (float10)DAT_008d16f0;
              _DAT_008d16ec = (float)-in_ST0;
              if (DAT_008d1704 < 0x14) {
                DAT_008d1704 = DAT_008d1704 + 10;
              }
              local_c = 0;
            }
            else {
              local_10 = 0;
              if (0x13 < DAT_008d1704) {
                DAT_008d1704 = DAT_008d1704 + -10;
              }
            }
            (&DAT_01f95d54)[DAT_008d1768 * 0xf] = (float)(DAT_008d1708 + DAT_008d1704);
          }
          local_124 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
          local_120 = (int)ROUND((float)DAT_008d1768 + _DAT_008d16ec);
          DAT_008d1708 = local_120;
          *(float *)(&DAT_01f95d5c + DAT_008d1768 * 0x3c) = f_0;
          ffree(in_ST0);
          in_ST0 = (float10)FUN_004ee442(&DAT_008d16f0,&DAT_008d1708);
        }
        local_8 = 0;
        DAT_008d1738 = DAT_008d1738 + 1;
      }
      ffree(in_ST0);
      return;
    }
    local_24 = 0;
  } while( true );
}


