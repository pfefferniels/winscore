// FUN_004af456 @ 004af456 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004af456(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 in_ST0;
  float10 fVar4;
  float10 extraout_ST1;
  
  do {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_00524c4a(param_3,param_1);
    *param_2 = DAT_0078dd64;
    if (*param_3 == 0) {
      _DAT_02052754 = -1;
      goto LAB_004af901;
    }
    if (DAT_01fbb710 < 0) {
      if (DAT_01fbb710 != -999) {
        DAT_01fbb710 = -DAT_01fbb710;
LAB_004af593:
        if (DAT_01fb8cc0 < 1) {
          _DAT_02052754 = -2;
          goto LAB_004af901;
        }
        DAT_0089f120 = 0;
        DAT_0089f11c = DAT_01fb8cc0;
        DAT_0089f118 = 0;
        if (DAT_01fbb710 < 100) {
          if (99 < DAT_01fbb70c) {
            DAT_01fbb70c = DAT_01fbb70c + -100;
            goto LAB_004af607;
          }
        }
        else {
          DAT_01fbb710 = DAT_01fbb710 + -100;
LAB_004af607:
          DAT_0089f118 = 1;
        }
        while ((((float)(&DAT_01fb8cc0)[DAT_0089f11c] <= f_0 &&
                ((DAT_0089f114 = (int)ROUND((float)(&DAT_01fb8cc0)[DAT_0089f11c] / f_1000),
                 DAT_0089f114 == -1 || (DAT_0089f114 == -7)))) ||
               (DAT_0089f120 = DAT_0089f120 + 1, DAT_01fbb70c != DAT_0089f120))) {
          DAT_0089f11c = DAT_0089f11c + -1;
          if (DAT_0089f11c < 1) {
            _DAT_02052754 = *param_3 + -2;
            goto LAB_004af901;
          }
        }
        DAT_0089f110 = 1;
        DAT_0089f120 = DAT_01fb8cc0;
        iVar1 = DAT_01fbb710;
        while (iVar1 = iVar1 + -1, 0 < iVar1) {
          DAT_0089f10c = DAT_0089f11c;
          for (iVar2 = (DAT_0089f120 - DAT_0089f11c) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
            DAT_0089f128 = (float)(&DAT_01fb8cc0)[DAT_0089f10c];
            iVar3 = (int)ROUND(DAT_0089f128);
            if (iVar3 < 0) {
              iVar3 = -iVar3;
            }
            DAT_0089f114 = iVar3 / 1000;
            if (((DAT_0089f114 == 1) || (DAT_0089f114 == 7)) && (DAT_0089f118 == 0)) {
              ffree(in_ST0);
              fVar4 = (float10)amod(&DAT_0089f128,&DAT_0076431c);
              DAT_0089f128 = (float)fVar4;
              _DAT_0089f124 = (float)(DAT_0089f114 * 1000);
              in_ST0 = extraout_ST1;
              if (DAT_0089f128 < f_0) {
                in_ST0 = (float10)(DAT_0089f114 * 1000);
                _DAT_0089f124 = (float)-in_ST0;
              }
              DAT_0089f128 = _DAT_0089f124 + DAT_0089f128;
            }
            DAT_01fb8cc0 = DAT_01fb8cc0 + 1;
            (&DAT_01fb8cc0)[DAT_01fb8cc0] = (int)DAT_0089f128;
            DAT_0089f10c = DAT_0089f10c + 1;
          }
          DAT_0089f110 = DAT_0089f110 + 1;
        }
      }
    }
    else {
      DAT_01fb8cc0 = DAT_01fb8cc0 + 1;
      (&DAT_01fb8cc0)[DAT_01fb8cc0] = (int)DAT_01ade8e0;
      if (DAT_01fbb708 != 0) {
        DAT_0089f128 = f_7;
        if (DAT_01fbb708 == 0x2d) {
          in_ST0 = (float10)f_7;
          DAT_0089f128 = (float)-in_ST0;
        }
        DAT_01fb8cc0 = DAT_01fb8cc0 + 1;
        _DAT_0089f124 = DAT_01ade8e0;
        if (f_0 < DAT_01ade8e0) {
          in_ST0 = (float10)DAT_01ade8e0;
          _DAT_0089f124 = (float)-in_ST0;
        }
        (&DAT_01fb8cc0)[DAT_01fb8cc0] = (int)(_DAT_0089f124 - DAT_0089f128);
      }
      if (0 < DAT_01fbb710) goto LAB_004af593;
    }
    *param_3 = *param_3 + 1;
    if (*param_2 < *param_3) {
LAB_004af901:
      ffree(in_ST0);
      return;
    }
  } while( true );
}


