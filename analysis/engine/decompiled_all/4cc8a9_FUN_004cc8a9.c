// FUN_004cc8a9 @ 004cc8a9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cc8a9(void)

{
  int iVar1;
  float10 in_ST0;
  
  DAT_0089fd18 = DAT_01be1818 + -1;
  DAT_0089fd14 = *(float *)(&DAT_01e9f4f4 + DAT_01be1818 * 4);
  DAT_0089fd10 = 0;
  DAT_0089fd0c = DAT_01be180c;
  DAT_0089fd08 = 1;
  iVar1 = DAT_0089fd08;
  do {
    if (DAT_01be180c < 1) {
      DAT_01be180c = 0;
      DAT_0089fd08 = iVar1;
LAB_004cccf0:
      ffree(in_ST0);
      return;
    }
    DAT_0089fd04 = *(float *)(&DAT_01e9cf5c + iVar1 * 4);
    if ((f_0 < DAT_0089fd04) || (DAT_0089fd04 == DAT_0089fd14)) {
      DAT_0089fd08 = iVar1 + -1;
      DAT_01be180c = iVar1;
LAB_004cc990:
      _DAT_0089fd00 = f_0;
      _DAT_0089fcfc = f_0;
      DAT_0089fd18 = DAT_0089fd18 + 1;
      DAT_0089fd14 = *(float *)(&DAT_01e9f4f4 + DAT_0089fd18 * 4);
      while (DAT_0089fd0c != DAT_0089fd08) {
        DAT_0089fd08 = DAT_0089fd08 + 1;
        DAT_0089fd04 = *(float *)(&DAT_01e9cf5c + DAT_0089fd08 * 4);
        if (f_0 <= DAT_0089fd04) {
          _DAT_0089fd00 = DAT_0089fd04 + _DAT_0089fd00;
          do {
            if (f_0 < DAT_0089fd14) {
              _DAT_0089fcfc = DAT_0089fd14 + _DAT_0089fcfc;
              DAT_0089fd10 = DAT_0089fd10 + 1;
              *(float *)(&DAT_01e9c21c + DAT_0089fd10 * 4) = DAT_0089fd14;
              (&DAT_01e9cd04)[DAT_0089fd10] = *(undefined4 *)(&DAT_01e9d5b4 + DAT_0089fd18 * 4);
              while( true ) {
                DAT_0089fd04 = _DAT_0089fd00 - _DAT_0089fcfc;
                in_ST0 = (float10)DAT_0089fd04;
                if (ABS(in_ST0) <= (float10)f_0_002) goto LAB_004cc990;
                if (f_0 < DAT_0089fd04) break;
                do {
                  if (DAT_0089fd0c == DAT_0089fd08) goto LAB_004cccd3;
                  DAT_0089fd08 = DAT_0089fd08 + 1;
                  DAT_0089fd04 = *(float *)(&DAT_01e9cf5c + DAT_0089fd08 * 4);
                } while (DAT_0089fd04 < f_0);
                _DAT_0089fd00 = DAT_0089fd04 + _DAT_0089fd00;
              }
            }
            DAT_0089fd18 = DAT_0089fd18 + 1;
            DAT_0089fd14 = *(float *)(&DAT_01e9f4f4 + DAT_0089fd18 * 4);
          } while( true );
        }
        while( true ) {
          if (DAT_0089fd14 == DAT_0089fd04) {
            DAT_0089fd10 = DAT_0089fd10 + 1;
            *(float *)(&DAT_01e9c21c + DAT_0089fd10 * 4) = DAT_0089fd14;
            (&DAT_01e9cd04)[DAT_0089fd10] = *(undefined4 *)(&DAT_01e9d5b4 + DAT_0089fd18 * 4);
            goto LAB_004cc990;
          }
          if ((f_0 < DAT_0089fd14) || (DAT_0089fd14 != f_m15)) break;
          DAT_0089fd18 = DAT_0089fd18 + 1;
          DAT_0089fd14 = *(float *)(&DAT_01e9f4f4 + DAT_0089fd18 * 4);
        }
        DAT_0089fd10 = DAT_0089fd10 + 1;
        *(float *)(&DAT_01e9c21c + DAT_0089fd10 * 4) = DAT_0089fd04;
        DAT_0089fd04 = *(float *)(&DAT_01e9d5b0 + DAT_0089fd18 * 4);
        (&DAT_01e9cd04)[DAT_0089fd10] =
             (*(float *)(&DAT_01e9d5b4 + DAT_0089fd18 * 4) - DAT_0089fd04) / f_2 + DAT_0089fd04;
      }
LAB_004cccd3:
      DAT_01be181c = DAT_0089fd10;
      goto LAB_004cccf0;
    }
    iVar1 = iVar1 + 1;
    DAT_01be180c = DAT_01be180c + -1;
  } while( true );
}


