// FUN_00584c27 @ 00584c27 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00584c27(void)

{
  int iVar1;
  int iVar2;
  int local_48;
  int local_8;
  
  DAT_009a9140 = 1;
  for (iVar1 = MAX_STAFF; 0 < iVar1; iVar1 = iVar1 + -1) {
    local_48 = 0xc;
    DAT_009a913c = 1;
    do {
      iVar2 = 6;
      DAT_009a9138 = 1;
      do {
        *(float *)(&DAT_01c29bf4 + DAT_009a9140 * 0x30 + DAT_009a9138 * 0x3000 + DAT_009a913c * 4) =
             f_0;
        DAT_009a9138 = DAT_009a9138 + 1;
        iVar2 = iVar2 + -1;
      } while (0 < iVar2);
      DAT_009a913c = DAT_009a913c + 1;
      local_48 = local_48 + -1;
    } while (0 < local_48);
    *(float *)(&DAT_01c2619c + DAT_009a9140 * 4) = f_0;
    DAT_009a9140 = DAT_009a9140 + 1;
  }
  DAT_01c2cc24 = 0;
  DAT_01c2cc20 = 999;
  DAT_009a9134 = 0;
  DAT_009a9140 = 1;
  iVar1 = DAT_01ba2064;
  do {
    if (iVar1 < 1) {
      _DAT_009a9114 = DAT_01c2cc34;
      if (DAT_01c2cc34 != f_0) {
        DAT_009a9140 = DAT_01c2cc20;
        for (iVar1 = (DAT_01c2cc24 - DAT_01c2cc20) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
          local_8 = 7;
          DAT_009a913c = 1;
          do {
            DAT_009a9128 = *(float *)(DAT_009a9140 * 0x30 + DAT_009a913c * 0x3000 + 0x1c29c04);
            if (DAT_009a9128 != f_0) {
              *(float *)(DAT_009a9140 * 0x30 + DAT_009a913c * 0x3000 + 0x1c29c04) =
                   DAT_009a9128 - _DAT_009a9114;
            }
            DAT_009a913c = DAT_009a913c + 1;
            local_8 = local_8 + -1;
          } while (0 < local_8);
          DAT_009a9140 = DAT_009a9140 + 1;
        }
      }
      return;
    }
    DAT_009a913c = (&DAT_01c4637c)[DAT_009a9140];
    DAT_009a9130 = (int)ROUND((float)(&DAT_01c6da64)[DAT_009a913c]);
    DAT_009a912c = (int)ROUND((float)(&DAT_01c6da60)[DAT_009a913c]);
    if (DAT_009a912c < 3) {
      DAT_009a9134 = 1;
    }
    if (DAT_009a9134 == 0) {
      if (DAT_01c2cc24 < DAT_009a9130) {
        DAT_01c2cc24 = DAT_009a9130;
      }
      if (DAT_009a9130 < DAT_01c2cc20) {
        DAT_01c2cc20 = DAT_009a9130;
      }
      DAT_009a9138 = 0;
      if (DAT_009a912c == 8) {
        DAT_009a9138 = (int)ROUND(*(float *)(&DAT_01c6da5c + DAT_009a913c * 4));
        if (0xb < DAT_009a9138) {
          DAT_009a9138 = 0xb;
        }
        if (DAT_009a9138 < 5) {
          DAT_009a912c = 5 - DAT_009a9138;
          FUN_00584a6f(&DAT_009a9140,&DAT_009a913c,&DAT_009a912c,&f_5,&DAT_01c6da60,&DAT_01c46380,
                       &DAT_01ba2064,&DAT_01ba2068);
          DAT_009a9138 = 5;
        }
        DAT_009a9120 = 1;
        for (iVar2 = DAT_009a9138 + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
          *(undefined4 *)(&DAT_01c2cbf4 + DAT_009a9130 * 0x30 + DAT_009a9120 * 4) =
               *(undefined4 *)(&DAT_01c6da5c + DAT_009a913c * 4);
          DAT_009a913c = DAT_009a913c + 1;
          DAT_009a9120 = DAT_009a9120 + 1;
        }
        _DAT_009a911c = *(float *)(&DAT_01c2cc0c + DAT_009a9130 * 0x30);
        if (_DAT_009a911c == f_0) {
          _DAT_009a911c = f_1;
        }
        DAT_009a9118 = _DAT_01ade87c * _DAT_009a911c;
        DAT_009a9128 = DAT_009a9118 * f_25;
        *(float *)(&DAT_01c41ce0 + DAT_009a9130 * 4) = DAT_009a9128;
        *(float *)(&DAT_01c2cc0c + DAT_009a9130 * 0x30) = DAT_009a9118;
        *(float *)(&DAT_01c2cc08 + DAT_009a9130 * 0x30) = f_0;
        if (*(float *)(&DAT_01c2cc14 + DAT_009a9130 * 0x30) < f_0) {
          *(float *)(&DAT_01c2cc14 + DAT_009a9130 * 0x30) = f_0;
        }
        *(float *)(&DAT_01c2cc18 + DAT_009a9130 * 0x30) = f_0;
      }
      else {
        if (DAT_009a912c == 3) {
          DAT_009a9138 = 5;
        }
        if (DAT_009a912c == 0xe) {
          DAT_009a9124 = (int)ROUND(*(float *)(&DAT_01c6da5c + DAT_009a913c * 4));
          DAT_009a9138 = 2;
          if (4 < DAT_009a9124) {
            DAT_009a9124 = (int)ROUND((float)(&DAT_01c6da70)[DAT_009a913c]);
            if ((DAT_009a9124 < 8) || (9 < DAT_009a9124)) goto LAB_005851f3;
            DAT_009a9138 = DAT_009a9124 + -5;
          }
          FUN_00585320(&DAT_009a913c,&DAT_009a9138);
        }
        else {
          if (DAT_009a912c == 0x11) {
            DAT_009a9138 = 6;
          }
          if (DAT_009a912c == 0x12) {
            DAT_009a9138 = 7;
          }
          if (DAT_009a9138 != 0) {
            FUN_00585320(&DAT_009a913c,&DAT_009a9138);
          }
        }
      }
    }
    else if (DAT_009a912c == 0xe) {
      DAT_009a9128 = f_1;
      if (f_4 <= *(float *)(&DAT_01c6da5c + DAT_009a913c * 4)) {
        DAT_009a9128 = (float)(&DAT_01c6da6c)[DAT_009a913c];
      }
      if (DAT_009a9128 == f_0) {
        DAT_009a9128 = f_1;
      }
      *(float *)(&DAT_01c2619c + DAT_009a9130 * 4) = DAT_009a9128;
    }
LAB_005851f3:
    DAT_009a9140 = DAT_009a9140 + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


