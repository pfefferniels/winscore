// FUN_0052f485 @ 0052f485 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052f485(void)

{
  int iVar1;
  
  P2 = f_1;
  if (0 < ITEM_I) {
    P2 = f_0;
    if ((DAT_020b8ea2 == '-') || (DAT_020b8ea3 == '-')) {
      P2 = f_999;
      DAT_020b8ea2 = DAT_007683f8;
    }
    DAT_0099a0f4 = 1;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_0099a0f0 = (&ITEM_PTR0)[DAT_0099a0f4];
      if ((float)(&ITEM_P1)[DAT_0099a0f0] == f_8) {
        _DAT_0099a0ec = (float)(&ITEM_P2)[DAT_0099a0f0];
        if (DAT_020b8ea2 == '-') {
          if (_DAT_0099a0ec <= P2) {
            P2 = _DAT_0099a0ec - f_1;
          }
        }
        else if (P2 <= _DAT_0099a0ec) {
          P2 = _DAT_0099a0ec + f_1;
        }
      }
      DAT_0099a0f4 = DAT_0099a0f4 + 1;
    }
    if ((P2 < f_1) || (P2 == f_999)) {
      P2 = f_1;
    }
  }
  return;
}


