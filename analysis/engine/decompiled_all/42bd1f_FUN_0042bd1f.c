// FUN_0042bd1f @ 0042bd1f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042bd1f(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 in_ST0;
  
  DAT_007f1348 = DAT_01cafaac;
  if (DAT_01cafaac == 0) {
    DAT_007f1348 = DAT_01cafab0;
  }
  _DAT_007f1344 = (float)(&ITEM_P6)[DAT_007f1348];
  if (_DAT_007f1344 == f_0) {
    _DAT_007f1344 = f_1;
  }
  DAT_007f1340 = (int)ROUND((float)(&ITEM_P2)[DAT_007f1348]);
  _DAT_007f133c = (float)(&STAFF_STEP0)[DAT_007f1340] / f_25;
  _DAT_007f1338 = _DAT_007f133c * _DAT_007f1344;
  DAT_007f1334 = f_0;
  if (DAT_01cafaac != 0) {
    DAT_007f1334 = _DAT_01cafaa0 + (float)(&ITEM_P13)[DAT_007f1348];
  }
  fVar1 = DAT_007f1334;
  _DAT_007f1330 = DAT_007f1334;
  if (f_201 < DAT_01cafaa4) {
    DAT_01cafaa4 = f_201;
  }
  DAT_007f132c = DAT_01cafaa4 - _DAT_0078ded0 * _DAT_007f1338;
  DAT_007f1328 = (float)(&ITEM_P4)[DAT_007f1348];
  if (DAT_020b9458 == f_0) {
    _DAT_01cafaa0 = DAT_007f132c - _DAT_007f133c * f_4;
    DAT_007f1340 = 1;
    fVar2 = f_0;
    for (iVar3 = ITEM_I; 0 < iVar3; iVar3 = iVar3 + -1) {
      DAT_007f1324 = (&ITEM_PTR0)[DAT_007f1340];
      DAT_01cafaa4 = fVar2;
      if (((((float)(&ITEM_P1)[DAT_007f1324] == f_1) &&
           (DAT_020b9444 == (float)(&ITEM_P2)[DAT_007f1324])) &&
          (DAT_007f1334 = (float)(&ITEM_P3)[DAT_007f1324], DAT_007f1334 <= _DAT_01cafaa0)) &&
         (DAT_01cafaa4 = DAT_007f1334, DAT_007f1334 <= fVar2)) {
        DAT_01cafaa4 = fVar2;
      }
      DAT_007f1340 = DAT_007f1340 + 1;
      fVar2 = DAT_01cafaa4;
    }
    DAT_01cafaa4 = _DAT_007f133c * f_4 + fVar2;
    if ((DAT_01cafaa4 < DAT_007f132c) && (_DAT_007f133c * f_2 + fVar1 < DAT_01cafaa4)) {
      DAT_007f132c = DAT_01cafaa4;
    }
  }
  else {
    fVar1 = (DAT_01cafaa4 - DAT_007f1334) - _DAT_007f1338 * _DAT_0078ded0;
    DAT_01cafaa4 = (float)(int)ROUND(fVar1 / (_DAT_007f1338 * f_25)) + f_1;
    if (DAT_020b9474 != f_0) {
      DAT_01cafaa4 = DAT_020b9474;
    }
    if (((DAT_0078b4a0 != 0) && (EDIT_ITEM == 0)) && ((float)DAT_0078b4a0 < DAT_01cafaa4)) {
      DAT_01cafaa4 = (float)DAT_0078b4a0;
    }
    in_ST0 = (float10)fVar1 -
             (float10)_DAT_0078ded8 * (float10)DAT_01cafaa4 * (float10)_DAT_007f1338;
    _DAT_01cafaa0 = (float)(in_ST0 / ((float10)DAT_01cafaa4 + (float10)f_1));
    _DAT_007f1330 = _DAT_01cafaa0 + DAT_007f1334;
    P10 = _DAT_007f1344 * _DAT_0078ded8 * _DAT_0078ded4;
    P12 = (_DAT_01cafaa0 * _DAT_0078ded4) / _DAT_007f133c;
    DAT_007f1328 = _DAT_007f1344 * f_0_8 + DAT_007f1328;
    DAT_007f132c = _DAT_007f133c * f_0_2 + DAT_007f132c;
  }
  P4 = DAT_007f1328;
  P2 = _DAT_007f133c * f_1_5 + _DAT_007f1330;
  fVar1 = _DAT_007f133c * f_0_1 + DAT_007f1334;
  if ((DAT_020b9458 != f_0) && (P2 < fVar1)) {
    P2 = fVar1;
  }
  if (DAT_007f132c - _DAT_007f1330 < f_0_2) {
    DAT_007f132c = _DAT_007f1330 + f_0_02;
  }
  P8 = DAT_007f132c;
  ffree(in_ST0);
  return;
}


