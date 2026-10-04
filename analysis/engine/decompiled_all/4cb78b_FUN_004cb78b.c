// FUN_004cb78b @ 004cb78b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cb78b(void)

{
  DAT_01add2ec = DAT_01add2e0;
  DAT_01add2e8 = 0;
  do {
    _DAT_01add2f0 = f_0;
    _DAT_01add2f4 = f_0;
    FUN_004cb6bf(&DAT_00764f68);
    if (f_0 <= DAT_01be1818) {
      FUN_004cb74b();
      while (f_0_01 < ABS(_DAT_01add2f0 - _DAT_01add2f4)) {
        if (DAT_01be181c <= DAT_01be1818) {
          do {
            FUN_004cb692(&DAT_01be181c);
            if (ABS(_DAT_01add2f0 - _DAT_01add2f4) < f_0_01) goto LAB_004cbad4;
            if ((_DAT_01add2f4 <= _DAT_01add2f0) &&
               (FUN_004cb74b(), DAT_01be1818 <= DAT_01be181c + f_0_004)) {
              DAT_01be1818 = (_DAT_01add2f0 - _DAT_01add2f4) + DAT_01be181c;
              goto LAB_004cba85;
            }
          } while ((_DAT_01add2f4 - f_0_004 <= _DAT_01add2f0) ||
                  (FUN_004cb6bf(&DAT_00765014), DAT_01be181c + f_0_004 < DAT_01be1818));
          DAT_01add2e8 = DAT_01add2e8 + -1;
          DAT_01be1818 = ((_DAT_01add2f0 - DAT_01be1818) - _DAT_01add2f4) + DAT_01be181c;
        }
        else {
          do {
            FUN_004cb692(&DAT_01be1818);
            if (ABS(_DAT_01add2f0 - _DAT_01add2f4) < f_0_01) goto LAB_004cbad4;
            if ((_DAT_01add2f0 <= _DAT_01add2f4) &&
               (FUN_004cb6bf(&DAT_00765014), DAT_01be181c <= DAT_01be1818 + f_0_004)) {
              DAT_01be181c = (_DAT_01add2f4 - _DAT_01add2f0) + DAT_01be1818;
              goto LAB_004cba85;
            }
          } while ((_DAT_01add2f0 - f_0_004 <= _DAT_01add2f4) ||
                  (FUN_004cb74b(), DAT_01be1818 + f_0_004 < DAT_01be181c));
          DAT_01add2ec = DAT_01add2ec + -1;
          DAT_01be181c = ((_DAT_01add2f4 - DAT_01be181c) - _DAT_01add2f0) + DAT_01be1818;
        }
LAB_004cba85:
        _DAT_01add2f4 = DAT_01be181c;
        _DAT_01add2f0 = DAT_01be1818;
      }
      FUN_004cb692(&DAT_01be1818);
    }
LAB_004cbad4:
    if (DAT_01add2e4 <= DAT_01add2e8) {
      return;
    }
  } while( true );
}


