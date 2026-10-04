// FUN_0054de6b @ 0054de6b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054de6b(void)

{
  FUN_0054c419(&DAT_0078d820,&DAT_007695f8);
  switch(DAT_020b8e50) {
  default:
    goto LAB_0054e276;
  case 4:
  case 5:
    if (-1 < DAT_0078dc30 + -1) {
      if (DAT_0078dc30 != 1) {
LAB_0054e170:
        if (DAT_020b9450 != f_999) {
          DAT_0078d820 = 6;
          DAT_0078d838 = 5;
          return;
        }
        DAT_0078d820 = 6;
        return;
      }
      goto LAB_0054e276;
    }
    break;
  case 6:
    if (DAT_0078dc30 == 1) {
      if (f_0 < DAT_020b9464) {
        if (DAT_020b9448 == DAT_020b9468) {
          DAT_0078d824 = 0xb;
        }
        if (DAT_020b9448 == DAT_020b946c) {
          DAT_0078d824 = 0xc;
        }
        if (f_0 < DAT_020b9470) {
          if (DAT_020b9448 == DAT_020b9474) {
            DAT_0078d824 = 0xe;
          }
          if (DAT_020b9448 == DAT_020b9478) {
            DAT_0078d824 = 0xf;
          }
        }
      }
      goto LAB_0054e276;
    }
    if (0 < DAT_0078dc30 + -1) {
      if (f_0 < DAT_020b9464) {
        if (DAT_020b9454 == DAT_020b9468) {
          DAT_0078d824 = 0xb;
        }
        if (DAT_020b9454 == DAT_020b946c) {
          DAT_0078d824 = 0xc;
        }
        if (f_0 < DAT_020b9470) {
          if (DAT_020b9454 == DAT_020b9474) {
            DAT_0078d824 = 0xe;
          }
          if (DAT_020b9454 == DAT_020b9478) {
            DAT_0078d824 = 0xf;
          }
        }
      }
      goto LAB_0054e170;
    }
    if ((f_0 < DAT_020b9464) && (f_0 <= DAT_020b9458)) {
      if (f_0 < DAT_020b9468) {
        _DAT_0078d828 = 0xb;
      }
      if (f_0 < DAT_020b946c) {
        _DAT_0078d82c = 0xc;
      }
      if (DAT_020b9470 != f_0) {
        if (f_0 < DAT_020b9474) {
          _DAT_0078d830 = 0xe;
        }
        if (f_0 < DAT_020b9478) {
          _DAT_0078d834 = 0xf;
        }
      }
    }
    break;
  case 7:
    if (DAT_020b9458 != f_1) {
      if (DAT_0078dc30 == 1) {
        DAT_0078d820 = 3;
        DAT_0078d838 = 4;
        return;
      }
      if (0 < DAT_0078dc30 + -1) {
        DAT_0078d820 = 6;
        return;
      }
      if ((DAT_020b945c != f_0) && (f_20 <= DAT_020b9458 && DAT_020b9458 <= f_22)) {
        _DAT_0078d828 = 8;
      }
      DAT_0078d824 = 6;
    }
    goto LAB_0054e276;
  case 8:
    DAT_0078d820 = 3;
    return;
  }
  if (DAT_020b9454 != f_0) {
    DAT_0078d824 = 6;
  }
  if (DAT_020b9450 != f_999) {
    DAT_0078d83c = 5;
  }
LAB_0054e276:
  DAT_0078d820 = 3;
  if (DAT_020b8e50 != 0xe) {
    DAT_0078d838 = 4;
  }
  return;
}


