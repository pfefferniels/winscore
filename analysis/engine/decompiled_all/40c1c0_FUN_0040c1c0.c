// FUN_0040c1c0 @ 0040c1c0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040c1c0(int *param_1)

{
  unkbyte10 in_ST0;
  float10 fVar1;
  float10 extraout_ST1;
  
  ffree(in_ST0);
  fVar1 = (float10)amod(&DAT_020b9658,&f_100);
  _DAT_020b9658 = (float)fVar1;
  fVar1 = extraout_ST1;
  if (_DAT_020b9678 != f_0) {
    IP2 = (int)ROUND(_DAT_020b9650);
    IP1 = (int)ROUND(f_3 - _DAT_020b9678 * f_2);
    fVar1 = (float10)(int)((&STAFF_Y0)[IP2] - (&STAFF_Y0)[IP1 + IP2]);
    DAT_020b964c = (float)-(fVar1 / ((float10)(float)(&STAFF_STEP0)[IP2] * (float10)f_7));
    _DAT_020b9658 = DAT_020b964c + _DAT_020b9658;
  }
  _DAT_007abaac = f_1;
  if (0 < IP4) {
    _DAT_007abaac = f_0_6;
  }
  DAT_020b964c = (_DAT_007abaac * f_2_83333 * STEP) / f_25;
  if (*param_1 == 1) {
    _DAT_020b9654 = DAT_020b964c + _DAT_020b9654;
  }
  IP7 = IP7 % 10;
  if (_DAT_020b9620 == f_0) {
    _DAT_020b9620 = f_1;
  }
  if (0 < IP4) {
    _DAT_020b9620 = _DAT_020b9620 * f_0_8;
  }
  IP10 = (int)ROUND(_DAT_020b9604);
  IP13 = (int)ROUND(_DAT_020b9610);
  _DAT_007abaa8 = f_1_5;
  _DAT_007abaa4 = (float)(IP7 + -1) * f_1_5;
  if (_DAT_020b9608 == f_m1) {
    _DAT_020b9608 = DAT_020b95e8;
  }
  if (_DAT_020b960c == f_m1) {
    _DAT_020b960c = DAT_020b95f4;
  }
  if (DAT_020b9614 == f_m1) {
    DAT_020b9614 = DAT_020b95e8;
  }
  if (DAT_020b9618 == f_m1) {
    DAT_020b9618 = DAT_020b95f4;
  }
  if (IP8 == 1) {
    DAT_020b95e8 = DAT_020b964c + DAT_020b95e8;
    DAT_020b95f4 = DAT_020b964c + DAT_020b95f4;
  }
  if (IP10 != 0) {
    if (IP8 == 1) {
      if (_DAT_020b9608 != f_0) {
        _DAT_020b9608 = DAT_020b964c + _DAT_020b9608;
      }
      if (_DAT_020b960c != f_0) {
        _DAT_020b960c = DAT_020b964c + _DAT_020b960c;
      }
    }
    if (IP10 < 0) {
      if ((_DAT_020b9608 != f_0) && (_DAT_020b960c != f_0)) {
        DAT_007abaa0 = -((float)(IP10 / 10) * f_1_5);
      }
    }
    else {
      IP1 = IP10 % 10;
      if (IP1 == 0) {
        IP1 = 1;
      }
      DAT_007abaa0 = (float)((IP10 / 10 + IP1) - IP7) * f_1_5;
    }
  }
  if (IP13 == 0) {
    DAT_020b9634 = DAT_020b9614;
    if (DAT_020b9614 == f_10) {
      DAT_020b9634 = DAT_020b964c;
    }
    if (DAT_020b9634 == f_20) {
      fVar1 = (float10)DAT_020b964c;
      DAT_020b9634 = (float)-fVar1;
    }
    DAT_020b95e8 = DAT_020b9634 + DAT_020b95e8;
    DAT_020b9634 = DAT_020b9618;
    if (DAT_020b9618 == f_10) {
      DAT_020b9634 = DAT_020b964c;
    }
    if (DAT_020b9634 == f_20) {
      fVar1 = (float10)DAT_020b964c;
      DAT_020b9634 = (float)-fVar1;
    }
    DAT_020b95f4 = DAT_020b9634 + DAT_020b95f4;
  }
  else {
    if (IP8 == 1) {
      if (DAT_020b9614 != f_0) {
        DAT_020b9614 = DAT_020b964c + DAT_020b9614;
      }
      if (DAT_020b9618 != f_0) {
        DAT_020b9618 = DAT_020b964c + DAT_020b9618;
      }
    }
    if (IP13 < 0) {
      if ((DAT_020b9614 != f_0) && (DAT_020b9618 != f_0)) {
        DAT_007aba9c = -((float)(IP13 / 10) * f_1_5);
      }
    }
    else {
      IP1 = IP13 % 10;
      if (IP1 == 0) {
        IP1 = 1;
      }
      DAT_007aba9c = (float)((IP13 / 10 + IP1) - IP7) * f_1_5;
    }
  }
  if (_DAT_020b9670 != f_0) {
    if (_DAT_020b9670 == f_10) {
      _DAT_020b9670 = DAT_020b964c;
    }
    if (_DAT_020b9670 == f_20) {
      fVar1 = (float10)DAT_020b964c;
      _DAT_020b9670 = (float)-fVar1;
    }
    _DAT_020b9654 = _DAT_020b9670 + _DAT_020b9654;
  }
  if (8 < IP6) {
    IP9 = (int)ROUND(_DAT_020b9600);
    DAT_007aba98 = IP9 / 100;
    DAT_007aba94 = (IP9 % 100) / 10;
    DAT_007aba90 = IP9 % 10;
    if (IP8 == 1) {
      fVar1 = (float10)DAT_020b964c;
      DAT_020b964c = (float)-fVar1;
    }
    if ((DAT_007aba98 == 1) || (DAT_007aba98 == 3)) {
      DAT_020b95e8 = DAT_020b964c + DAT_020b95e8;
    }
    if ((DAT_007aba98 == 2) || (DAT_007aba98 == 3)) {
      DAT_020b95f4 = DAT_020b964c + DAT_020b95f4;
    }
    if ((DAT_007aba94 == 1) || (DAT_007aba94 == 3)) {
      _DAT_020b9608 = DAT_020b964c + _DAT_020b9608;
    }
    if ((DAT_007aba94 == 2) || (DAT_007aba94 == 3)) {
      _DAT_020b960c = DAT_020b964c + _DAT_020b960c;
    }
    if ((DAT_007aba90 == 1) || (DAT_007aba90 == 3)) {
      DAT_020b9614 = DAT_020b964c + DAT_020b9614;
    }
    if ((DAT_007aba90 == 2) || (DAT_007aba90 == 3)) {
      DAT_020b9618 = DAT_020b964c + DAT_020b9618;
    }
  }
  _DAT_020b9644 = DAT_020b95f4 - DAT_020b95e8;
  ffree(fVar1);
  fVar1 = (float10)amod(&DAT_020b95ec,&f_100);
  _DAT_020b9638 = (float)(fVar1 - (float10)_DAT_020b9658);
  _DAT_020b963c = _DAT_020b95f0 - _DAT_020b9658;
  if (*param_1 != 1) {
    _DAT_020b9638 = -_DAT_020b9638;
    _DAT_020b963c = -_DAT_020b963c;
  }
  _DAT_020b9648 = _DAT_020b9654 - DAT_020b95e8;
  DAT_020b9634 = (float)(((float10)(_DAT_020b9654 - DAT_020b95e8) / (float10)_DAT_020b9644) *
                         ((float10)_DAT_020b963c - (float10)_DAT_020b9638) + (float10)_DAT_020b9638)
  ;
  if (IP8 == *param_1) {
    _DAT_020b9630 = f_0;
    if (((_DAT_020b9654 < _DAT_020b960c + f_0_1) && (IP10 < 0)) &&
       (_DAT_020b9608 - f_0_1 < _DAT_020b9654)) {
      _DAT_020b9630 = DAT_007abaa0;
    }
    if ((((_DAT_020b9630 < DAT_007aba9c) && (_DAT_020b9654 < DAT_020b9618 + f_0_1)) && (IP13 < 0))
       && (DAT_020b9614 - f_0_1 < _DAT_020b9654)) {
      _DAT_020b9630 = DAT_007aba9c;
    }
    DAT_020b9634 = _DAT_020b9630 + DAT_020b9634 / _DAT_007abaac;
  }
  else {
    _DAT_020b9630 = f_0;
    if (((_DAT_020b9654 < _DAT_020b960c + f_0_1) && (0 < IP10)) &&
       (_DAT_020b9608 - f_0_1 < _DAT_020b9654)) {
      _DAT_020b9630 = DAT_007abaa0;
    }
    if (((_DAT_020b9630 < DAT_007aba9c) && (_DAT_020b9654 < DAT_020b9618 + f_0_1)) &&
       ((0 < IP13 && (DAT_020b9614 - f_0_1 < _DAT_020b9654)))) {
      _DAT_020b9630 = DAT_007aba9c;
    }
    DAT_020b9634 = _DAT_020b9630 +
                   ((_DAT_007abaa4 + DAT_020b9634 / _DAT_007abaac) - f_14) + _DAT_020b9620;
  }
  if (((DAT_020b8ea2 == 'F') && (f_0_1 < ABS(DAT_020b95e8 - _DAT_020b9654))) &&
     (f_0_1 < ABS(DAT_020b95f4 - _DAT_020b9654))) {
    _DAT_007aba8c = f_0;
    if (((_DAT_020b960c != f_0) && (IP10 != 0)) &&
       ((_DAT_020b9608 != f_0 &&
        ((_DAT_020b9608 + f_0_1 <= _DAT_020b9654 && (_DAT_020b9654 <= _DAT_020b960c - f_0_1)))))) {
      _DAT_007aba8c = DAT_007abaa0;
    }
    if (((((DAT_020b9618 != f_0) && (IP13 != 0)) && (DAT_020b9614 != f_0)) &&
        ((DAT_020b9614 + f_0_1 <= _DAT_020b9654 && (_DAT_020b9654 <= DAT_020b9618 - f_0_1)))) &&
       (_DAT_007aba8c < DAT_007aba9c)) {
      _DAT_007aba8c = DAT_007aba9c;
    }
    DAT_020b9634 = (DAT_020b9634 - _DAT_007abaa4) - _DAT_007aba8c;
  }
  P2 = DAT_020b9634;
  ffree((float10)_DAT_020b963c - (float10)_DAT_020b9638);
  return;
}


