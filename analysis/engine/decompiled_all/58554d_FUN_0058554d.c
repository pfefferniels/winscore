// FUN_0058554d @ 0058554d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058554d(int param_1)

{
  int iVar1;
  
  DAT_009a9184 = 1;
  (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
  _DAT_009a9180 = *(float *)(param_1 + 4);
  _DAT_009a917c = *(float *)(param_1 + 8);
  DAT_009a9178 = ITEM_I;
LAB_00585595:
  iVar1 = (DAT_009a9178 - DAT_009a9184) + 1;
  DAT_009a9174 = DAT_009a9184;
  do {
    if (iVar1 < 1) {
      return;
    }
    DAT_009a9170 = (&ITEM_PTR0)[DAT_009a9174];
    if (((_DAT_009a9180 == (float)(&ITEM_P1)[DAT_009a9170]) &&
        (_DAT_009a917c == (float)(&ITEM_P2)[DAT_009a9170])) && (_DAT_009a9180 == f_3)) {
      DAT_009a916c = f_0;
      if (f_5 <= (float)(&ITEM_LEN)[DAT_009a9170]) {
        DAT_009a916c = (float)(&ITEM_P5)[DAT_009a9170];
      }
      if (DAT_009a916c == *(float *)(param_1 + 0x14)) break;
      *(float *)(param_1 + 0x14) = DAT_009a916c;
      DAT_009a9168 = DAT_009a9170 + 4;
      DAT_009a9164 = (int)ROUND((float)(&ITEM_LEN)[DAT_009a9170]);
      if (DAT_009a9164 < 4) {
        thunk_FUN_005239c9(&DAT_009a9174,&f_4);
        (&ITEM_LEN)[DAT_009a9168] = f_100;
      }
      else if ((float)(&ITEM_LEN)[DAT_009a9168] < f_100) {
        (&ITEM_LEN)[DAT_009a9168] = (float)(&ITEM_LEN)[DAT_009a9168] + f_100;
      }
    }
    DAT_009a9174 = DAT_009a9174 + 1;
    iVar1 = iVar1 + -1;
  } while( true );
  FUN_005857c8(&DAT_009a9174);
  DAT_009a9178 = DAT_009a9178 + -1;
  DAT_009a9184 = DAT_009a9174;
  goto LAB_00585595;
}


