// FUN_0043d0b0 @ 0043d0b0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043d0b0(void)

{
  int iVar1;
  undefined1 *puVar2;
  float10 in_ST0;
  float10 fVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  int local_1d0;
  int local_10c;
  
  puVar2 = &stack0xfffffffc;
  if (((DAT_020b8e50 != 4) &&
      ((_DAT_020b8ea0 & 0xffff) == 0x4f48 || (_DAT_020b8ea0 & 0xffffff) == 0x56454c)) &&
     (DAT_020b9450 != f_999)) {
    DAT_01c58930 = DAT_020b944c;
    goto LAB_0043f501;
  }
  if (DAT_020b8e50 != 4) {
    if (DAT_020b8e50 == 5) {
      if ((_DAT_020b8ea0 & 0xffffff) == 0x444e45) {
        _DAT_01c58938 = f_5;
        DAT_01c5893c = P2;
        DAT_01c58930 = DAT_020b944c;
        DAT_01c58940 = f_0;
        if (f_2 < P2) {
          DAT_01c5893c = f_1;
          DAT_01c58940 = P2;
        }
LAB_0043e610:
        if ((_DAT_020b8ea0 & 0xff) == 0x58) {
LAB_0043f4d3:
          DAT_01c5895c = f_0;
          _DAT_01c58960 = f_0;
          DAT_01c58964 = f_0;
        }
        else {
          if (((_DAT_020b8ea0 & 0xffffff) != 0x56454c) && ((_DAT_020b8ea0 & 0xffffff) != 0x524f48))
          {
            DAT_0078b4e0 = 0;
            goto LAB_0043f50c;
          }
          DAT_01c58930 = DAT_020b944c;
        }
LAB_0043f501:
        DAT_0205274c = 1;
      }
      else {
        if ((_DAT_020b8ea0 & 0xffffff) == 0x494c46) {
          in_ST0 = (float10)DAT_020b9458;
          _DAT_01c58938 = (float)-in_ST0;
          goto LAB_0043e610;
        }
        if ((_DAT_020b8ea0 & 0xffffff) == 0x554c53) {
LAB_0043dd17:
          DAT_01c5893c = f_m1;
          DAT_01c58944 = f_0;
          DAT_01c58948 = f_0;
          DAT_01c5894c = f_0;
          DAT_01c58940 = f_0;
          if (P2 != f_0) {
            _DAT_01c58938 = f_2;
            DAT_01c5893c = P2;
            if (DAT_020b9458 < f_0) {
              in_ST0 = (float10)f_2;
              _DAT_01c58938 = (float)-in_ST0;
            }
            if (P2 != f_3) {
              DAT_01c5893c = f_3;
              DAT_01c58940 = P2;
            }
          }
          goto LAB_0043e610;
        }
        if ((_DAT_020b8ea0 & 0xffffff) == 0x454954) {
          DAT_01c58940 = f_0;
          DAT_01c5893c = f_m2;
          DAT_01c58944 = f_0;
          DAT_01c58948 = f_0;
          DAT_01c5894c = f_0;
          DAT_01c5895c = f_0;
          goto LAB_0043e610;
        }
        if ((_DAT_020b8ea0 & 0xffffff) == 0x505254) {
          P2 = f_3;
          goto LAB_0043dd17;
        }
        if ((_DAT_020b8ea0 & 0xffffff) == 0x505553) {
          DAT_01c5894c = f_m1;
LAB_0043de51:
          if (DAT_020b946c != f_0) {
            DAT_01c5894c = f_0;
          }
          goto LAB_0043e610;
        }
        if (_DAT_020b8ea0 == 0x4c484c53) {
          DAT_01c5894c = f_1;
          goto LAB_0043de51;
        }
        if (_DAT_020b8ea0 == 0x52484c53) {
          DAT_01c5894c = f_2;
          goto LAB_0043de51;
        }
        if (_DAT_020b8ea0 == 0x54444c53) {
          DAT_01c58948 = f_m1;
          goto LAB_0043e610;
        }
        if (_DAT_020b8ea0 == 0x53444c53) {
          DAT_01c58948 = f_1;
          goto LAB_0043e610;
        }
        if (_DAT_020b8ea0 == 0x52544c53) {
          DAT_01c5893c = f_0;
          DAT_01c58940 = f_0;
          _DAT_01c58954 = f_0;
          DAT_01c5895c = f_3;
          if (DAT_020b947c != f_0) {
            DAT_01c5895c = f_0;
          }
          goto LAB_0043e610;
        }
        if (_DAT_020b8ea0 == 0x4c44494d) {
          DAT_01c58944 = DAT_020b9464 - f_0_02;
          if (DAT_020b9464 == f_0) {
            DAT_01c58944 = f_0_48;
          }
          goto LAB_0043e610;
        }
        if (_DAT_020b8ea0 == 0x5244494d) {
          DAT_01c58944 = DAT_020b9464 + f_0_02;
          if (DAT_020b9464 == f_0) {
            DAT_01c58944 = f_0_52;
          }
          goto LAB_0043e610;
        }
        if ((_DAT_020b8ea0 == 0x2a44494d) || (_DAT_020b8ea0 == 0x2044494d)) {
          DAT_01c58944 = f_0;
          goto LAB_0043e610;
        }
        if (_DAT_020b8ea0 == 0x4d565243) {
          _DAT_01c58938 = DAT_020b9458 - f_0_2;
          goto LAB_0043e610;
        }
        if (_DAT_020b8ea0 == 0x50565243) {
          _DAT_01c58938 = DAT_020b9458 + f_0_2;
          goto LAB_0043e610;
        }
        if ((_DAT_020b8ea0 & 0xffffff) == 0x4d554e) {
          if ((DAT_020b947c != f_0) || (f_2 < DAT_020b945c)) {
            if (_DAT_020b8ea0 >> 0x18 == 0x4c) {
              _DAT_01c58960 = DAT_020b9480 - f_0_1;
            }
            if (_DAT_020b8ea0 >> 0x18 == 0x52) {
              _DAT_01c58960 = DAT_020b9480 + f_0_1;
            }
            if (_DAT_020b8ea0 >> 0x18 == 0x48) {
              _DAT_01c58960 = f_0;
            }
            if (_DAT_020b8ea0 >> 0x18 == 0x55) {
              DAT_01c58964 = DAT_020b9484 + f_0_1;
            }
            if (_DAT_020b8ea0 >> 0x18 == 0x44) {
              DAT_01c58964 = DAT_020b9484 - f_0_1;
            }
            if (_DAT_020b8ea0 >> 0x18 == 0x56) {
              DAT_01c58964 = f_0;
            }
          }
          DAT_01c58920 = f_5;
          DAT_007f77e4 = 9;
          if (DAT_020b945c < f_3) {
            DAT_007f77e4 = 0x10;
          }
          if (_DAT_020b8ea0 >> 0x18 == 0x50) {
            *(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) =
                 *(float *)(&DAT_020b943c + DAT_007f77e4 * 4) + f_1;
          }
          if ((*(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) < f_4) &&
             (*(float *)(&DAT_020b943c + DAT_007f77e4 * 4) == f_0)) {
            *(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) = f_4;
          }
          if (_DAT_020b8ea0 >> 0x18 == 0x4d) {
            *(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) =
                 *(float *)(&DAT_020b943c + DAT_007f77e4 * 4) - f_1;
          }
          if (*(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) < f_0) {
            *(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) = f_0;
          }
          goto LAB_0043e610;
        }
        if ((_DAT_020b8ea0 & 0xffffff) == 0x4b4854) {
          DAT_01c58950 = f_0;
          goto LAB_0043e610;
        }
        if ((_DAT_020b8ea0 & 0xffffff) == 0x4d4854) {
          if (DAT_020b9470 == f_0) {
            DAT_020b9470 = f_1;
          }
          DAT_01c58950 = DAT_020b9470 - f_0_05;
          if (DAT_020b9470 < f_0) {
            DAT_01c58950 = f_0;
          }
          if ((DAT_020b9460 == f_99) && (f_2 <= DAT_020b9470)) {
            DAT_01c58950 = DAT_020b9470 - f_1;
          }
          goto LAB_0043e610;
        }
        if ((_DAT_020b8ea0 & 0xffffff) == 0x504854) {
          if ((DAT_020b9470 == f_0) && (DAT_020b9460 != f_99)) {
            DAT_020b9470 = f_1;
          }
          DAT_01c58950 = DAT_020b9470 + f_0_05;
          if (DAT_020b9460 == f_99) {
            DAT_01c58950 = DAT_020b9470 + f_1;
          }
          goto LAB_0043e610;
        }
        if (_DAT_020b8ea0 == 0x20495254) {
          DAT_01c58940 = f_99;
          DAT_01c5895c = f_0;
          DAT_01c5893c = f_0;
          DAT_01c58950 = f_0;
          DAT_01c58944 = f_0;
          if (DAT_020b9460 == f_99) {
            DAT_01c58940 = f_0;
          }
          goto LAB_0043e610;
        }
        if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544e46) {
          if ((DAT_020b945c <= f_0) && (DAT_020b947c == f_0)) {
            ffree(in_ST0);
            in_ST0 = (float10)thunk_FUN_0054d7d4(&DAT_020b8ea0,5);
            P1 = f_1;
            P2 = (float)DAT_020b8e50;
            P3 = f_0;
            goto LAB_0043f526;
          }
          in_ST0 = (float10)P2;
          _DAT_01c58954 = (float)-in_ST0;
          goto LAB_0043e610;
        }
        if ((((_DAT_020b8ea0 & 0xffff) == 0x5243) || ((_DAT_020b8ea0 & 0xffff) == 0x4e43)) ||
           ((_DAT_020b8ea0 & 0xffff) == 0x5643)) {
          DAT_007f77e4 = (&ITEM_PTR0)[EDIT_ITEM];
          DAT_020527c8 = (int)ROUND((float)(&ITEM_LEN)[DAT_007f77e4]);
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0042c9b0(&DAT_007f77e4,&DAT_020527c8);
          _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_0076061c);
          goto LAB_0043f526;
        }
        if ((undefined *)(_DAT_020b8ea0 >> 8) != &DAT_0046464f) goto LAB_0043e610;
        if ((_DAT_020b8ea0 & 0xff) == 0x52) {
LAB_0043ee44:
          DAT_01c5895c = f_1;
          iVar1 = FUN_005f4660(0x20);
          if ((iVar1 == 0) && (DAT_020b8ea4 != '*')) {
            DAT_01c58964 = DAT_020b9484 + f_0_5;
            in_ST0 = extraout_ST0_00;
            if (DAT_020b8ea4 == 'M') {
              DAT_01c58964 = DAT_020b9484 - f_0_5;
            }
          }
          else {
            DAT_01c58964 = P2;
            in_ST0 = extraout_ST0_00;
            if ((DAT_020b9480 == f_0) && (P2 == f_0)) {
              DAT_01c5895c = f_0;
            }
          }
        }
        else {
          if ((_DAT_020b8ea0 & 0xff) != 0x4c) goto LAB_0043e610;
LAB_0043ed63:
          DAT_01c5895c = f_1;
          iVar1 = FUN_005f4660(0x20);
          if ((iVar1 == 0) && (DAT_020b8ea4 != '*')) {
            _DAT_01c58960 = DAT_020b9480 - f_0_5;
            in_ST0 = extraout_ST0;
            if (DAT_020b8ea4 == 'P') {
              _DAT_01c58960 = DAT_020b9480 + f_0_5;
            }
          }
          else {
            _DAT_01c58960 = P2;
            in_ST0 = extraout_ST0;
            if ((DAT_020b9484 == f_0) && (P2 == f_0)) {
              DAT_01c5895c = f_0;
            }
          }
        }
      }
LAB_0043f50c:
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_00467fc1();
      goto LAB_0043f526;
    }
    if (DAT_020b8e50 == 6) {
      local_10c = 0xf;
      DAT_020527cc = 1;
      do {
        if ((uint)*(ushort *)(DAT_020527cc * 2 + 0x78f78a) == (_DAT_020b8ea0 & 0xffff)) {
          switch(DAT_020527cc) {
          case 1:
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4f) {
              DAT_01c58940 = f_m1;
            }
            else {
              if (DAT_0205274c != 0) {
                DAT_007f77ec = _DAT_020b8ea0;
                DAT_0205274c = 0;
              }
              ffree(in_ST0);
              in_ST0 = (float10)thunk_FUN_0040cde4(&DAT_0076069c);
              *(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) = f_0_5;
              if ((_DAT_020b8ea0 & 0xff) == 0x4c) {
                in_ST0 = (float10)*(float *)(&DAT_01c5891c + DAT_007f77e4 * 4);
                *(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) = (float)-in_ST0;
              }
              *(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) =
                   *(float *)(&DAT_020b943c + DAT_007f77e4 * 4) +
                   *(float *)(&DAT_01c5891c + DAT_007f77e4 * 4);
              if ((_DAT_020b8ea0 & 0xff) == 0x4e) {
                *(float *)(&DAT_01c5891c + DAT_007f77e4 * 4) = f_0;
              }
              _DAT_020b8ea0 = 0x20202020;
            }
            goto LAB_0043f501;
          case 2:
            P2 = f_99;
            if (DAT_020b8ea4 == 'X') {
              P2 = f_98;
            }
            DAT_007f77e0 = ITEM_I;
            ffree(in_ST0);
            in_ST0 = (float10)thunk_FUN_00417738();
            break;
          case 3:
            if ((char)DAT_020b90a4 == '+') {
              _DAT_01c58938 = DAT_020b9458 + f_1;
            }
            else {
              ffree(in_ST0);
              in_ST0 = (float10)thunk_FUN_004680d8(&DAT_00760680,&DAT_00760684);
              DAT_007f77dc = (int)ROUND(DAT_020b9458 / f_10) * 10;
              _DAT_007f77e8 = f_1;
              if (P2 != f_0) {
                _DAT_007f77e8 = P2;
              }
              _DAT_01c58938 = (float)DAT_007f77dc + _DAT_007f77e8;
            }
            goto LAB_0043f501;
          case 4:
            ffree(in_ST0);
            FUN_0043f52f(&DAT_00760678);
            _DAT_01c58628 = EDIT_ITEM;
            P1 = f_8;
            if ((f_9 < P2) && (P2 < f_100)) {
              P2 = P2 * f_10 + f_9;
            }
            fVar3 = (float10)P2;
            P2 = (float)-fVar3;
            DAT_007f77e0 = ITEM_I;
            ffree(fVar3);
            thunk_FUN_00417738();
            puVar2 = &stack0xfffffffc;
            in_ST0 = (float10)FUN_005f34d1(&stack0xfffffffc,&LAB_0043d4d6);
            *(undefined4 *)(puVar2 + -0xd8) = 0;
            break;
          case 5:
            _DAT_007f77e8 = f_100;
            if (DAT_020b944c < f_0) {
              _DAT_007f77e8 = -f_100;
            }
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x58) {
              in_ST0 = (float10)DAT_020b944c;
              if (ABS(in_ST0) < (float10)f_100) goto LAB_0043f40a;
              DAT_01c5892c = DAT_020b944c - _DAT_007f77e8;
            }
            else {
              in_ST0 = (float10)DAT_020b944c;
              if ((float10)f_100 < ABS(in_ST0)) goto LAB_0043f40a;
              DAT_01c5892c = _DAT_007f77e8 + DAT_020b944c;
            }
            in_ST0 = (float10)DAT_020b944c;
            goto LAB_0043f501;
          case 6:
            if (DAT_020b9470 != f_0) goto LAB_0043f526;
            if (DAT_020b8ea4 == 'M') {
              _DAT_01c58954 = f_20;
            }
            else if (DAT_020b8ea4 == 'P') {
              _DAT_01c58954 = f_10;
            }
            else {
              _DAT_01c58954 = P2;
            }
            goto LAB_0043f501;
          case 7:
            if (DAT_020b9470 != f_0) goto LAB_0043f526;
            if (DAT_020b8ea4 == 'M') {
              _DAT_01c58958 = f_20;
            }
            else if (DAT_020b8ea4 == 'P') {
              _DAT_01c58958 = f_10;
            }
            else {
              _DAT_01c58958 = P2;
            }
            goto LAB_0043f501;
          case 8:
            ffree(in_ST0);
            in_ST0 = (float10)thunk_FUN_004680d8(&DAT_00760660,&DAT_00760684);
            if (DAT_020b8ea4 == 'P') {
              DAT_01c5893c = DAT_020b945c + f_1;
            }
            else {
              DAT_01c5893c = P2;
            }
            goto LAB_0043f501;
          case 9:
            DAT_007f77d4 = (int)ROUND(*(float *)(&DAT_020b943c + (int)ROUND(P2) * 4));
            if (DAT_007f77d4 < 0) {
              DAT_007f77d8 = ((int)ROUND(DAT_020b9458) % 10) * 10 - DAT_007f77d4 / 10;
            }
            else {
              DAT_007f77d8 = ((DAT_007f77d4 % 10 + DAT_007f77d4 / 10) -
                             (int)ROUND(DAT_020b9458) % 10) * -0xb;
            }
            if (P2 == f_10) {
              DAT_01c58944 = (float)DAT_007f77d8;
            }
            if (P2 == f_13) {
              DAT_01c58950 = (float)DAT_007f77d8;
            }
            goto LAB_0043f501;
          case 10:
          case 0xf:
            _DAT_01c58938 = f_m10;
            DAT_01c58944 = P2 + f_10;
            ffree(in_ST0);
            in_ST0 = (float10)thunk_FUN_004680d8(&DAT_00760654,&DAT_00760684);
            goto LAB_0043f501;
          case 0xb:
            if (DAT_020b945c == f_0) goto LAB_0043f526;
            _DAT_007f77e8 = f_0_02;
            if (DAT_020b947c == f_0) {
              DAT_020b947c = f_0_5;
            }
            if (_DAT_020b8ea0 >> 0x18 == 0x4d) {
              in_ST0 = (float10)f_0_02;
              _DAT_007f77e8 = (float)-in_ST0;
            }
            DAT_01c5895c = _DAT_007f77e8 + DAT_020b947c;
            if (DAT_020b90a3 == '0') {
              DAT_01c5895c = f_0;
            }
            goto LAB_0043f501;
          case 0xc:
            if (DAT_020b945c == f_0) goto LAB_0043f526;
            _DAT_007f77e8 = f_0_2;
            if (_DAT_020b8ea0 >> 0x18 == 0x4d) {
              in_ST0 = (float10)f_0_2;
              _DAT_007f77e8 = (float)-in_ST0;
            }
            DAT_01c58968 = _DAT_007f77e8 + DAT_020b9488;
            if (DAT_020b90a3 == '0') {
              DAT_01c58968 = f_0;
            }
            goto LAB_0043f501;
          case 0xd:
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x52) goto LAB_0043f501;
            if (P2 == f_11) {
              if (DAT_020b9464 == f_0) goto LAB_0043f526;
              DAT_01c58948 = f_999;
            }
            else {
              if (DAT_020b9470 == f_0) goto LAB_0043f526;
              _DAT_01c58954 = f_999;
            }
            goto LAB_0043f501;
          case 0xe:
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4d) {
              _DAT_01c58960 = DAT_020b9480 - f_0_05;
              if (_DAT_01c58960 <= f_0) {
                _DAT_01c58960 = f_0_95;
              }
            }
            else {
              _DAT_01c58960 = P2;
            }
            goto LAB_0043f501;
          default:
            goto LAB_0043d1ba;
          }
          if (DAT_007f77e0 == ITEM_I) {
            *(undefined4 *)(puVar2 + -0xf4) = 0;
          }
          else {
            ITEM_I = ITEM_I + -1;
            ITEM_WORDS = (&DAT_02091d20)[ITEM_I];
          }
          DAT_0078b4e0 = 0xffffff9d;
          *(undefined4 *)(puVar2 + -0xf0) = 0;
          goto LAB_0043f526;
        }
LAB_0043d1ba:
        DAT_020527cc = DAT_020527cc + 1;
        local_10c = local_10c + -1;
      } while (0 < local_10c);
      if (((_DAT_020b8ea0 & 0xffff) != 0x4f58) || (DAT_020b9470 != f_0)) goto LAB_0043f526;
      _DAT_01c58954 = f_0;
      _DAT_01c58958 = f_0;
      goto LAB_0043f501;
    }
  }
  local_1d0 = 0x17;
  DAT_020527cc = 1;
  do {
    if ((uint)*(ushort *)(s_ADAUBESPCULOROBNPBTRNLNUFLTHTM_0078f78c + DAT_020527cc * 2 + 0x1e) ==
        (_DAT_020b8ea0 & 0xffff)) {
      switch(DAT_020527cc) {
      case 1:
        if (DAT_020b9458 != f_100) {
          DAT_01c58934 = f_0;
          _DAT_01c58938 = f_m1;
          DAT_01c58930 = DAT_020b944c + f_10;
          DAT_01c5894c = f_0;
          if ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x50) {
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x55) {
              DAT_01c5894c = f_1;
            }
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x44) {
              DAT_01c5894c = f_m1;
            }
          }
          goto LAB_0043f50c;
        }
        goto LAB_0043f526;
      case 2:
        if (DAT_020b9458 == f_100) goto LAB_0043f526;
        _DAT_01c58938 = f_0;
        break;
      case 3:
        if (DAT_020b9458 == f_100) goto LAB_0043f526;
        _DAT_01c58938 = f_m1;
        break;
      case 4:
      case 0x15:
        if (DAT_020b9458 != f_100) {
          _DAT_01c58938 = f_m4;
          if (DAT_020b9450 == f_999) {
            DAT_01c58930 = DAT_020b944c;
          }
          if (DAT_020b9454 <= DAT_020b9448) {
            DAT_01c58934 = DAT_020b9448 + f_20;
            DAT_01c58950 = f_m90;
          }
          goto LAB_0043f50c;
        }
        goto LAB_0043f526;
      case 5:
      case 0x16:
        if (DAT_020b9458 != f_100) {
          if (_DAT_020b8ea0 >> 0x18 == 0x20) {
            _DAT_01c58938 = f_1;
            if (DAT_020b9450 == f_999) {
              DAT_01c58930 = DAT_020b944c;
            }
            goto LAB_0043e944;
          }
          if (_DAT_020b8ea0 >> 0x18 == 0x4c) {
            if (DAT_020b8ea4 == '*') {
              DAT_01c5893c = f_0;
            }
            _DAT_007f77e8 = DAT_020b945c;
            if (DAT_020b945c == f_0) {
              _DAT_007f77e8 = f_2;
            }
            if (DAT_020b8ea4 == '-') {
              DAT_01c5893c = _DAT_007f77e8 - f_0_1;
            }
            if (DAT_020b8ea4 == '+') {
              DAT_01c5893c = _DAT_007f77e8 + f_0_1;
            }
          }
          else if (_DAT_020b8ea0 >> 0x18 == 0x53) {
            if (DAT_020b8ea4 == '*') {
              DAT_01c58940 = f_0;
            }
            _DAT_007f77e8 = DAT_020b9460;
            if (DAT_020b9460 == f_0) {
              _DAT_007f77e8 = f_2;
            }
            if (DAT_020b8ea4 == '-') {
              DAT_01c58940 = _DAT_007f77e8 - f_0_1;
            }
            if (DAT_020b8ea4 == '+') {
              DAT_01c58940 = _DAT_007f77e8 + f_0_1;
            }
            if (DAT_01c58940 <= f_0) {
              DAT_01c58940 = f_0;
            }
          }
          goto LAB_0043f50c;
        }
        goto LAB_0043f526;
      case 6:
        DAT_01c58950 = f_0;
        if (DAT_020b9450 != f_999) {
          DAT_01c58930 = DAT_020b944c;
        }
        if (DAT_020b9454 <= DAT_020b9448) {
          DAT_01c58934 = DAT_020b9448 + f_20;
        }
        goto LAB_0043f50c;
      case 7:
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_004680d8(&DAT_00760610,&DAT_00760684);
        DAT_01c58950 = DAT_020b9470;
        DAT_01c58944 = DAT_020b9464;
        if ((DAT_020b9450 == f_999) || (DAT_020b9454 == f_0)) {
          DAT_01c58930 = DAT_020b944c;
        }
        if (DAT_020b9454 == f_0) {
          DAT_01c58934 = DAT_020b9448 + f_20;
        }
        goto LAB_0043f50c;
      case 8:
        if ((DAT_020b9450 == f_999) || (DAT_020b9458 < f_0)) goto LAB_0043f40a;
        DAT_01c58948 = f_2;
        if ((DAT_020b9468 != f_0) && (_DAT_020b8ea0 >> 0x18 == 0x20)) {
          DAT_01c58948 = f_0;
        }
        if (_DAT_020b8ea0 >> 0x18 == 0x2d) {
          DAT_01c58948 = DAT_020b9468 - f_0_5;
        }
        if (_DAT_020b8ea0 >> 0x18 == 0x2b) {
          DAT_01c58948 = DAT_020b9468 + f_0_5;
        }
        if (_DAT_020b8ea0 >> 0x18 == 0x44) {
          DAT_01c58948 = f_m2;
        }
        goto LAB_0043f50c;
      case 9:
        if ((DAT_020b9450 == f_999) || (DAT_020b9458 < f_0)) goto LAB_0043f40a;
        DAT_01c58948 = f_102;
        if (f_100 < DAT_020b9468) {
          DAT_01c58948 = f_0;
        }
        goto LAB_0043f50c;
      case 10:
        goto LAB_0043ed63;
      case 0xb:
        goto LAB_0043ee44;
      case 0xc:
        if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x46) goto LAB_0043ee44;
        if (DAT_020b9458 == f_100) {
          _DAT_01c5896c = f_0;
          if (_DAT_020b8ea0 >> 0x18 == 0x2d) {
            _DAT_01c5896c = DAT_020b948c - f_10;
          }
          if (_DAT_020b8ea0 >> 0x18 == 0x2b) {
            _DAT_01c5896c = DAT_020b948c + f_10;
          }
        }
        else {
          DAT_01c58950 = f_0;
          if (_DAT_020b8ea0 >> 0x18 == 0x2d) {
            DAT_01c58950 = DAT_020b9470 - f_10;
          }
          if (_DAT_020b8ea0 >> 0x18 == 0x2b) {
            DAT_01c58950 = DAT_020b9470 + f_10;
          }
          if (P2 != f_0) {
            DAT_01c58950 = P2 + DAT_020b9470;
          }
        }
        goto LAB_0043f50c;
      case 0xd:
        if ((DAT_020b9450 == f_999) ||
           ((DAT_020b9458 != f_m88 && DAT_020b9458 < f_0) && DAT_020b9458 != f_m8))
        goto LAB_0043f40a;
        DAT_01c5894c = f_2;
        if ((DAT_020b946c != f_0) && (_DAT_020b8ea0 >> 0x18 == 0x20)) {
          DAT_01c5894c = f_0;
        }
        if (_DAT_020b8ea0 >> 0x18 == 0x2d) {
          DAT_01c5894c = DAT_020b946c - f_0_5;
        }
        if (_DAT_020b8ea0 >> 0x18 == 0x2b) {
          DAT_01c5894c = DAT_020b946c + f_0_5;
        }
        if (_DAT_020b8ea0 >> 0x18 == 0x44) {
          DAT_01c5894c = f_m2;
        }
        goto LAB_0043f50c;
      case 0xe:
        DAT_01c5894c = f_102;
        if (f_100 < DAT_020b946c) {
          DAT_01c5894c = f_0;
        }
        goto LAB_0043f50c;
      case 0xf:
        _DAT_01c58938 = f_m3;
        DAT_01c58948 = f_0;
        if (_DAT_020b8ea0 >> 0x18 == 0x58) {
          DAT_01c58948 = f_0_8;
          DAT_01c5893c = f_2;
        }
        goto LAB_0043f50c;
      case 0x10:
        DAT_020b8ea0 = CONCAT11(0x20,(undefined1)DAT_020b8ea0);
        if (DAT_020b9458 != f_100) {
          if (DAT_020b9450 != f_999) goto LAB_0043f40a;
          _DAT_007f77e8 = f_0_4;
          _DAT_01c58938 = DAT_020b9458;
          if (DAT_020b9458 == f_m1) {
            _DAT_01c58938 = f_m2_3;
          }
          if (DAT_020b9458 == f_0) {
            _DAT_01c58938 = f_2_3;
          }
          if (DAT_020b9458 < f_0) {
            in_ST0 = (float10)f_0_4;
            _DAT_007f77e8 = (float)-in_ST0;
          }
          if (_DAT_020b8ea2 >> 8 == 0x2d) {
            _DAT_01c58938 = _DAT_01c58938 - _DAT_007f77e8;
          }
          if (_DAT_020b8ea2 >> 8 == 0x2b) {
            _DAT_01c58938 = _DAT_007f77e8 + _DAT_01c58938;
          }
          if ((_DAT_020b8ea2 >> 8 == 0x2a) && (_DAT_01c58938 = f_0, DAT_020b9458 < f_0)) {
            _DAT_01c58938 = f_m1;
          }
          goto LAB_0043f50c;
        }
        goto LAB_0043f526;
      case 0x11:
        DAT_01c58944 = DAT_020b9464 + f_1;
        if (DAT_020b90a3 == '0') {
          DAT_01c58944 = f_0;
        }
        goto LAB_0043f50c;
      case 0x12:
        _DAT_01c58938 = f_m2;
        DAT_01c58944 = f_0;
        DAT_01c58948 = f_0;
        goto LAB_0043f50c;
      case 0x13:
        if ((DAT_020b9450 == f_999) || (DAT_020b9454 <= DAT_020b9448)) goto LAB_0043f40a;
        if (DAT_020b9458 == f_m4) {
          DAT_01c58950 = f_m90;
        }
        else {
          DAT_01c58950 = f_0;
          DAT_01c58934 = DAT_020b9448;
          DAT_01c58930 = DAT_020b944c + f_10;
        }
        goto LAB_0043f50c;
      case 0x14:
        if (DAT_020b9458 != f_100) {
          if (DAT_020b9454 <= DAT_020b9448) {
            DAT_01c58934 = DAT_020b9448 + f_20;
          }
          DAT_01c5894c = f_0;
          _DAT_01c58938 = f_m1;
          if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x41) {
            DAT_01c5894c = f_1;
          }
          if (DAT_020b9450 == f_999) {
            DAT_01c58930 = DAT_020b944c;
          }
          goto LAB_0043f50c;
        }
        goto LAB_0043f526;
      case 0x17:
        goto LAB_0043f4d3;
      default:
        goto LAB_0043e6c5;
      }
      DAT_01c58930 = f_999;
      if (DAT_020b9454 <= DAT_020b9448) {
        DAT_01c58934 = DAT_020b9448 + f_20;
      }
LAB_0043e944:
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_004680d8(&DAT_00760680,&DAT_00760684);
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x2d) {
        DAT_01c58948 = f_1;
      }
      if (DAT_020b9470 != f_0) {
        DAT_01c58950 = DAT_020b9470;
      }
      goto LAB_0043f50c;
    }
LAB_0043e6c5:
    DAT_020527cc = DAT_020527cc + 1;
    local_1d0 = local_1d0 + -1;
  } while (0 < local_1d0);
LAB_0043f526:
  ffree(in_ST0);
  return;
LAB_0043f40a:
  P1 = f_1;
  P2 = (float)DAT_020b8e50;
  goto LAB_0043f526;
}


