// FUN_00501148 @ 00501148 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00501148(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  ITEM_I = 1;
  thunk_FUN_0049836a(&ITEM_P1,&DAT_02091d20,&DAT_00902878,&ITEM_I,&ITEM_WORDS);
  DAT_0078b4e4 = 0;
  thunk_FUN_0049846f(&ITEM_P1,&DAT_02091d20,&DAT_00902878,&ITEM_I);
  DAT_020b8e44 = DAT_00902878 + -1;
  DAT_00902874 = 0;
  DAT_00902870 = 1;
  _DAT_01a72da0 = f_0;
  iVar1 = ITEM_I;
  do {
    if (iVar1 < 1) {
      ITEM_WORDS = DAT_00902878;
      return;
    }
    DAT_0090286c = (&ITEM_PTR0)[DAT_00902870];
    DAT_00902868 = (float)(&ITEM_P3)[DAT_0090286c];
    DAT_00902864 = (int)ROUND((float)(&ITEM_P1)[DAT_0090286c]);
    if ((DAT_00902864 != 10) && (DAT_00902864 != 0x10)) {
      if (DAT_00902864 == 0xe) {
        DAT_00902860 = (int)ROUND((float)(&ITEM_LEN)[DAT_0090286c]);
        if ((DAT_00902860 < 5) || ((float)(&ITEM_P5)[DAT_0090286c] < f_8)) {
          if (DAT_00902874 != 0) {
            if (ABS(DAT_00902868 - DAT_0090285c) <= f_0_5) goto LAB_005015f4;
            _DAT_00902854 = DAT_0090285c + f_0_5;
            DAT_00902850 = 1;
            for (iVar2 = DAT_01ba2064; DAT_00902858 = f_0, 0 < iVar2; iVar2 = iVar2 + -1) {
              DAT_0090286c = (&DAT_01c4637c)[DAT_00902850];
              if (_DAT_00902854 <= (float)(&DAT_01c6da68)[DAT_0090286c]) {
                DAT_00902864 = (int)ROUND((float)(&DAT_01c6da60)[DAT_0090286c]);
                DAT_0090284c = (int)ROUND(*(float *)(&DAT_01c6da5c + DAT_0090286c * 4));
                if (DAT_00902864 == 0xe) break;
                DAT_00902858 = f_m1;
                if (DAT_00902864 == 2) {
                  if ((7 < DAT_0090284c) && ((float)(&DAT_01c6da7c)[DAT_0090286c] < f_0)) break;
                }
                else {
                  if ((DAT_00902864 == 9) && ((float)(&DAT_01c6da70)[DAT_0090286c] == f_31)) break;
                  if ((DAT_00902864 == 1) && (10 < DAT_0090284c)) {
                    DAT_0090284c = (int)ROUND((float)(&DAT_01c6da88)[DAT_0090286c]);
                    iVar3 = DAT_0090284c;
                    if (DAT_0090284c < 0) {
                      iVar3 = -DAT_0090284c;
                    }
                    if (iVar3 == 0xe) break;
                  }
                }
              }
              DAT_00902850 = DAT_00902850 + 1;
            }
            (&ITEM_LEN)[DAT_00902878] = f_9;
            (&ITEM_P1)[DAT_00902878] = f_2;
            (&ITEM_P2)[DAT_00902878] = f_1;
            (&ITEM_P3)[DAT_00902878] = (DAT_00902868 - DAT_0090285c) / f_2 + DAT_0090285c;
            (&ITEM_P4)[DAT_00902878] = f_0;
            (&ITEM_P5)[DAT_00902878] = f_m2;
            (&ITEM_P6)[DAT_00902878] = f_0;
            *(float *)(&ITEM_P7 + DAT_00902878 * 4) = f_3;
            *(float *)(&ITEM_P8 + DAT_00902878 * 4) = DAT_00902858;
            *(float *)(&ITEM_P9 + DAT_00902878 * 4) = f_m1;
            DAT_00902878 = DAT_00902878 + 10;
          }
LAB_00501620:
          DAT_0090285c = DAT_00902868;
          if (DAT_00902874 == 0) {
            _DAT_01a72da0 = DAT_00902868;
          }
          DAT_00902874 = DAT_00902874 + 1;
        }
        else {
LAB_005015f4:
          (&ITEM_P1)[DAT_0090286c] = f_0;
        }
      }
      else if (DAT_00902874 == 0) goto LAB_00501620;
    }
    DAT_00902870 = DAT_00902870 + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


