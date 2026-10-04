// FUN_0042bab0 @ 0042bab0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042bab0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 in_ST0;
  
  if (DAT_020b9440 == f_4) {
    in_ST0 = (float10)f_9999;
    _DAT_01cafaa0 = (float)-in_ST0;
    DAT_01cafaac = 0;
    DAT_01cafab0 = 0;
    DAT_007f1320 = 1;
    DAT_01cafaa4 = f_9999;
    fVar1 = _DAT_01cafaa0;
    for (iVar5 = ITEM_I; _DAT_01cafaa0 = fVar1, 0 < iVar5; iVar5 = iVar5 + -1) {
      DAT_007f131c = (&ITEM_PTR0)[DAT_007f1320];
      fVar2 = DAT_01cafaa4;
      iVar3 = DAT_01cafaac;
      iVar4 = DAT_01cafab0;
      if ((((float)(&ITEM_P1)[DAT_007f131c] == f_16) &&
          (DAT_020b9444 == (float)(&ITEM_P2)[DAT_007f131c])) &&
         (ABS((float)(&ITEM_P4)[DAT_007f131c] - DAT_020b944c) <= f_1_9)) {
        DAT_01cafaa8 = (float)(&ITEM_P3)[DAT_007f131c] + *(float *)(&ITEM_P11 + DAT_007f131c * 4);
        if (DAT_01cafaa8 <= DAT_020b9448) {
          _DAT_01cafaa0 = DAT_01cafaa8;
          iVar3 = DAT_007f131c;
          if (DAT_01cafaa8 < fVar1) {
            _DAT_01cafaa0 = fVar1;
            iVar3 = DAT_01cafaac;
          }
        }
        else {
          fVar2 = DAT_01cafaa8;
          iVar4 = DAT_007f131c;
          if (DAT_01cafaa4 <= DAT_01cafaa8) {
            fVar2 = DAT_01cafaa4;
            iVar4 = DAT_01cafab0;
          }
        }
      }
      DAT_01cafab0 = iVar4;
      DAT_01cafaac = iVar3;
      DAT_01cafaa4 = fVar2;
      DAT_007f1320 = DAT_007f1320 + 1;
      fVar1 = _DAT_01cafaa0;
    }
    if (DAT_01cafab0 + DAT_01cafaac != 0) {
      if (fVar1 < f_0) {
        _DAT_01cafaa0 = f_0;
      }
      ffree(in_ST0);
      in_ST0 = (float10)FUN_0042bd1f();
      P1 = f_3;
      P3 = f_4;
      P5 = f_5;
      P6 = P4;
      P7 = f_6;
      P9 = f_8;
      P11 = f_9;
    }
  }
  ffree(in_ST0);
  return;
}


