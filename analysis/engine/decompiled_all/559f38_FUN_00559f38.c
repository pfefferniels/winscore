// FUN_00559f38 @ 00559f38 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00559f38(float *param_1,float *param_2,int *param_3,int *param_4,float *param_5,
                 float *param_6)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  DAT_01a9f324 = f_0;
  DAT_01a9f300 = 0;
  DAT_01a9f310 = 0;
  DAT_01a9f30c = 0;
  iVar3 = *param_4;
  DAT_01a9f304 = 1;
  DAT_009a3cb8 = f_0;
  for (; 0 < iVar3; iVar3 = iVar3 + -1) {
    DAT_01a9f308 = *(int *)(&DAT_01f9448c + DAT_01a9f304 * 4);
    do {
      DAT_01a9f310 = (int)ROUND((float)(&DAT_01f95d54)[DAT_01a9f308 * 0xf] / f_10);
      if (DAT_01a9f310 != 0) {
        if (DAT_01a9f300 == 0) {
          DAT_01a9f300 = DAT_01a9f310;
        }
        if (DAT_01a9f310 != DAT_01a9f300) {
          DAT_01a9f30c = 1;
        }
        if (*(float *)(&DAT_01f95d70 + DAT_01a9f308 * 0x3c) != f_0) {
          DAT_009a3cb8 = *(float *)(&DAT_01f95d70 + DAT_01a9f308 * 0x3c);
        }
        break;
      }
      DAT_01a9f308 = DAT_01a9f308 + -1;
    } while (DAT_01a9f308 != 0);
    DAT_01a9f304 = DAT_01a9f304 + 1;
  }
  if ((DAT_009a3cb8 != f_0) && (DAT_01a9f30c != 0)) {
    if (DAT_009a3cb8 == f_2) {
      if (DAT_01a9f300 == 2) {
        DAT_009a3cb4 = f_4;
      }
      else {
        DAT_009a3cb4 = f_m7_5;
      }
    }
    else if (DAT_01a9f300 == 2) {
      DAT_009a3cb4 = f_21_5;
    }
    else {
      DAT_009a3cb4 = f_10;
    }
    DAT_009a3cb0 = DAT_009a3cb4;
    *param_3 = DAT_01a9f300 * 10;
    if (DAT_01a9f300 != DAT_01a9f310) {
      _DAT_009a3cac = f_200;
    }
    goto LAB_0055ac00;
  }
  DAT_009a3cb0 = *(float *)(&DAT_01f942fc + *param_4 * 4);
  DAT_009a3cb4 = DAT_01f94300;
  iVar3 = *param_4;
  DAT_01a9f304 = 2;
  DAT_01a9f314 = DAT_01f94300;
  DAT_01a9f318 = DAT_01f94300;
  while (iVar3 = iVar3 + -1, 0 < iVar3) {
    DAT_009a3cb8 = *(float *)(&DAT_01f942fc + DAT_01a9f304 * 4);
    if (DAT_01a9f314 < DAT_009a3cb8) {
      DAT_01a9f314 = DAT_009a3cb8;
    }
    if (DAT_009a3cb8 < DAT_01a9f318) {
      DAT_01a9f318 = DAT_009a3cb8;
    }
    DAT_01a9f304 = DAT_01a9f304 + 1;
  }
  if (*param_3 == 0) {
    DAT_01a9f31c = DAT_01a9f314 - f_7;
    DAT_01a9f320 = f_7 - DAT_01a9f318;
    DAT_01a9f300 = 0x14;
    if (DAT_01a9f320 == DAT_01a9f31c) {
      DAT_01a9f30c = 0;
      DAT_01a9f310 = 0;
      iVar3 = *param_4;
      DAT_01a9f304 = 1;
      for (; 0 < iVar3; iVar3 = iVar3 + -1) {
        if (f_7 < *(float *)(&DAT_01f942fc + DAT_01a9f304 * 4)) {
          DAT_01a9f30c = DAT_01a9f30c + 1;
        }
        if (*(float *)(&DAT_01f942fc + DAT_01a9f304 * 4) < f_7) {
          DAT_01a9f310 = DAT_01a9f310 + 1;
        }
        DAT_01a9f304 = DAT_01a9f304 + 1;
      }
      if (DAT_01a9f30c < DAT_01a9f310) {
        DAT_01a9f300 = 10;
      }
    }
    else if (DAT_01a9f31c < DAT_01a9f320) {
      DAT_01a9f300 = 10;
    }
    *param_3 = DAT_01a9f300;
  }
  else {
    DAT_01a9f300 = *param_3;
  }
  if (DAT_009a3cb0 == DAT_009a3cb4) {
    if (DAT_01a9f300 == 10) {
      if (DAT_009a3cb4 != DAT_01a9f314) goto LAB_0055a7f3;
    }
    else if (DAT_009a3cb4 != DAT_01a9f318) goto LAB_0055a7ab;
    goto LAB_0055a83a;
  }
  if (DAT_01a9f300 == 10) {
    ffree(in_ST0);
    iVar3 = FUN_0055ad81(&DAT_01a9f314,param_4);
    in_ST0 = extraout_ST0_00;
    if (iVar3 < 2) goto LAB_0055a3ca;
LAB_0055a7f3:
    DAT_009a3cb4 = DAT_01a9f314;
    if (DAT_009a3ca8 == 1) {
      DAT_009a3cb4 = DAT_01a9f314 - f_1;
    }
LAB_0055a824:
    DAT_009a3cb0 = DAT_009a3cb4;
  }
  else {
    ffree(in_ST0);
    iVar3 = FUN_0055ad81(&DAT_01a9f318,param_4);
    in_ST0 = extraout_ST0;
    if (1 < iVar3) {
LAB_0055a7ab:
      DAT_009a3cb4 = DAT_01a9f318;
      if (DAT_009a3ca8 == 1) {
        DAT_009a3cb4 = DAT_01a9f318 + f_1;
      }
      goto LAB_0055a824;
    }
LAB_0055a3ca:
    DAT_01a9f324 = *param_6 - *param_5;
    DAT_01a9f328 = (DAT_009a3cb0 - DAT_009a3cb4) / DAT_01a9f324;
    _DAT_01a9f334 = f_m99;
    if (DAT_01a9f300 == 0x14) {
      _DAT_01a9f334 = f_99;
    }
    DAT_01a9f304 = 2;
    for (iVar3 = *param_4 + -2; 0 < iVar3; iVar3 = iVar3 + -1) {
      _DAT_009a3ca4 = (float)(&DAT_01f95d4c)[*(int *)(&DAT_01f9448c + DAT_01a9f304 * 4) * 0xf];
      DAT_01a9f330 = (_DAT_009a3ca4 - *param_5) * DAT_01a9f328 + DAT_009a3cb4;
      DAT_009a3ca0 = *(float *)(&DAT_01f942fc + DAT_01a9f304 * 4) - DAT_01a9f330;
      if (DAT_01a9f300 == 0x14) {
        if ((DAT_009a3ca0 < f_0) && (DAT_009a3ca0 < _DAT_01a9f334)) {
LAB_0055a50f:
          _DAT_01a9f32c = *(float *)(&DAT_01f942fc + DAT_01a9f304 * 4);
          DAT_01a9f308 = DAT_01a9f304;
          _DAT_01a9f334 = DAT_009a3ca0;
        }
      }
      else if ((f_0 < DAT_009a3ca0) && (_DAT_01a9f334 < DAT_009a3ca0)) goto LAB_0055a50f;
      DAT_01a9f304 = DAT_01a9f304 + 1;
    }
    DAT_009a3cb8 = f_1;
    if (1 < DAT_009a3ca8) {
      DAT_009a3cb8 = f_0;
    }
    if (DAT_01a9f300 == 0x14) {
      if ((_DAT_01a9f334 != f_99) &&
         (in_ST0 = (float10)DAT_009a3cb8, (float10)_DAT_01a9f334 < -in_ST0)) {
        DAT_009a3c90 = DAT_009a3cb8 + _DAT_01a9f32c;
        DAT_01a9f314 = DAT_01a9f318;
        _DAT_009a3c9c = DAT_009a3cb0;
        _DAT_009a3c98 = DAT_009a3cb4;
        goto LAB_0055a67f;
      }
    }
    else if ((_DAT_01a9f334 != f_m99) && (DAT_009a3cb8 < _DAT_01a9f334)) {
      DAT_009a3c90 = _DAT_01a9f32c - DAT_009a3cb8;
      _DAT_009a3c9c = DAT_009a3cb4;
      _DAT_009a3c98 = DAT_009a3cb0;
LAB_0055a67f:
      if ((DAT_009a3cb4 != DAT_01a9f314) && (DAT_009a3cb0 != DAT_01a9f314)) {
        if (DAT_01a9f300 == 10) goto LAB_0055a7f3;
        goto LAB_0055a7ab;
      }
      DAT_009a3cb8 = (float)(&DAT_01f95d4c)[*(int *)(&DAT_01f9448c + DAT_01a9f308 * 4) * 0xf];
      if (_DAT_009a3c9c <= _DAT_009a3c98) {
        ffree(in_ST0);
        in_ST0 = (float10)FUN_0055adf4(param_6,&DAT_009a3cb8,param_5,&DAT_009a3cb0,&DAT_009a3c90,
                                       &DAT_009a3cb4);
      }
      else {
        ffree(in_ST0);
        in_ST0 = (float10)FUN_0055adf4(param_5,&DAT_009a3cb8,param_6,&DAT_009a3cb4,&DAT_009a3c90,
                                       &DAT_009a3cb0);
      }
    }
  }
LAB_0055a83a:
  bVar5 = false;
  if (DAT_01a9f300 == 0x14) {
    if (f_14 < DAT_009a3cb4) {
      DAT_009a3cb4 = f_14;
    }
    if (f_14 < DAT_009a3cb0) {
      DAT_009a3cb0 = f_14;
    }
    if (DAT_009a3cb4 < DAT_009a3cb0) {
      bVar5 = true;
    }
  }
  else {
    if (DAT_009a3cb4 < f_0) {
      DAT_009a3cb4 = f_0;
    }
    if (DAT_009a3cb0 < f_0) {
      DAT_009a3cb0 = f_0;
    }
    bVar5 = DAT_009a3cb0 < DAT_009a3cb4;
  }
  DAT_009a3cb8 = ABS(DAT_009a3cb4 - DAT_009a3cb0);
  if ((f_1_5 < DAT_009a3cb8) && (DAT_0078b470 < DAT_009a3cb8 / DAT_01a9f324)) {
    if ((f_3 <= DAT_009a3cb8) && (DAT_009a3cb8 = DAT_009a3cb8 - f_1, DAT_009a3ca8 < 2)) {
      if (DAT_01a9f300 == 0x14) {
        if (bVar5) {
          DAT_009a3cb4 = DAT_009a3cb4 + f_1;
        }
        else {
          DAT_009a3cb0 = DAT_009a3cb0 + f_1;
        }
      }
      else if (bVar5) {
        DAT_009a3cb4 = DAT_009a3cb4 - f_1;
      }
      else {
        DAT_009a3cb0 = DAT_009a3cb0 - f_1;
      }
    }
    fVar2 = DAT_009a3cb4;
    fVar1 = DAT_009a3cb0;
    DAT_01a9f330 = DAT_009a3cb4;
    _DAT_01a9f32c = DAT_009a3cb0;
    for (_DAT_01a9f334 = DAT_0078b470; _DAT_01a9f334 < DAT_009a3cb8 / DAT_01a9f324;
        _DAT_01a9f334 = _DAT_01a9f334 + f_0_01) {
      DAT_009a3c90 = DAT_009a3cb8 - DAT_01a9f324 * _DAT_01a9f334;
      if (DAT_01a9f300 == 0x14) {
        in_ST0 = (float10)DAT_009a3c90;
        DAT_009a3c90 = (float)-in_ST0;
      }
      if (bVar5) {
        DAT_009a3cb0 = DAT_009a3c90 + fVar1;
      }
      else {
        DAT_009a3cb4 = DAT_009a3c90 + fVar2;
      }
      if (f_1 <= ABS(DAT_009a3cb0 - DAT_009a3cb4)) break;
    }
  }
LAB_0055ac00:
  DAT_01a9f304 = (int)ROUND(DAT_009a3cb4 * f_2);
  DAT_009a3c90 = (float)(DAT_01a9f304 / 2);
  DAT_01a9f308 = (int)ROUND(DAT_009a3cb0 * f_2);
  DAT_009a3cb8 = f_0;
  if ((DAT_009a3ca8 % 2 == 0) && (DAT_01a9f308 == DAT_01a9f304)) {
    uVar4 = (uint)DAT_009a3c90 & 1;
    if ((uVar4 != 0) && ((int)DAT_009a3c90 < 0)) {
      uVar4 = uVar4 - 2;
    }
    if (uVar4 != 0) {
      if (DAT_01a9f300 == 0x14) {
        if (0xd < DAT_01a9f304) {
          DAT_009a3cb8 = f_0_5;
        }
      }
      else if (DAT_01a9f304 < 0xf) {
        DAT_009a3cb8 = f_m0_5;
      }
    }
  }
  *param_1 = (float)DAT_01a9f304 / f_2 + DAT_009a3cb8;
  *param_2 = (float)DAT_01a9f308 / f_2 + DAT_009a3cb8;
  ffree(in_ST0);
  return;
}


