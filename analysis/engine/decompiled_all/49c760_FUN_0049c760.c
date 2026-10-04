// FUN_0049c760 @ 0049c760 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0049c760(void)

{
  int iVar1;
  int iVar2;
  
  thunk_FUN_0049836a(&ITEM_P1,&DAT_02091d20,&ITEM_WORDS,&ITEM_I,&ITEM_WORDS);
  if (1 < DAT_01ba2080) {
    DAT_00838974 = 1;
    DAT_0083897c = ITEM_WORDS;
    DAT_00838978 = ITEM_I;
    for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
      DAT_00838970 = (&ITEM_PTR0)[DAT_00838974];
      DAT_0083896c = (int)ROUND((float)(&ITEM_P1)[DAT_00838970]);
      if ((float)DAT_0083896c == f_18) {
        DAT_00838968 = (int)ROUND((float)(&ITEM_LEN)[DAT_00838970] + f_1);
        DAT_00838964 = 2;
        iVar1 = DAT_01ba2080;
        while (iVar1 = iVar1 + -1, 0 < iVar1) {
          thunk_FUN_0054c590(&ITEM_LEN + DAT_00838970,&ITEM_LEN + DAT_0083897c,&DAT_00838968);
          (&ITEM_P2)[DAT_0083897c] = (float)DAT_00838964;
          DAT_0083897c = DAT_00838968 + DAT_0083897c;
          DAT_00838978 = DAT_00838978 + 1;
          (&DAT_02091d20)[DAT_00838978] = DAT_0083897c;
          DAT_00838964 = DAT_00838964 + 1;
        }
      }
      else if (DAT_0083896c == 8) {
        DAT_00838960 = (&ITEM_P3)[DAT_00838970];
      }
      else if (((DAT_0083896c == 2) && (f_8 <= (float)(&ITEM_LEN)[DAT_00838970])) &&
              (*(float *)(&ITEM_P8 + DAT_00838970 * 4) != f_0)) {
        DAT_00838968 = (int)ROUND((float)(&ITEM_LEN)[DAT_00838970] + f_1);
        DAT_00838964 = 2;
        iVar1 = DAT_01ba2080;
        while (iVar1 = iVar1 + -1, 0 < iVar1) {
          thunk_FUN_0054c590(&ITEM_LEN + DAT_00838970,&ITEM_LEN + DAT_0083897c,&DAT_00838968);
          (&ITEM_P2)[DAT_0083897c] = (float)DAT_00838964;
          (&ITEM_P4)[DAT_0083897c] = f_0;
          DAT_0083897c = DAT_00838968 + DAT_0083897c;
          DAT_00838978 = DAT_00838978 + 1;
          (&DAT_02091d20)[DAT_00838978] = DAT_0083897c;
          DAT_00838964 = DAT_00838964 + 1;
        }
      }
      DAT_00838974 = DAT_00838974 + 1;
    }
    DAT_0083895c = (float)DAT_01ba2080;
    (&ITEM_LEN)[DAT_0083897c] = f_4;
    (&ITEM_P1)[DAT_0083897c] = f_14;
    (&ITEM_P2)[DAT_0083897c] = f_1;
    (&ITEM_P3)[DAT_0083897c] = DAT_00838960;
    (&ITEM_P4)[DAT_0083897c] = DAT_0083895c;
    DAT_00838978 = DAT_00838978 + 1;
    (&ITEM_PTR0)[DAT_00838978] = DAT_0083897c;
    DAT_0083897c = DAT_0083897c + 5;
    (&ITEM_LEN)[DAT_0083897c] = f_5;
    (&ITEM_P1)[DAT_0083897c] = f_14;
    (&ITEM_P2)[DAT_0083897c] = f_1;
    (&ITEM_P3)[DAT_0083897c] = DAT_00838960;
    (&ITEM_P4)[DAT_0083897c] = DAT_0083895c;
    (&ITEM_P5)[DAT_0083897c] = f_8;
    DAT_00838978 = DAT_00838978 + 1;
    (&ITEM_PTR0)[DAT_00838978] = DAT_0083897c;
    DAT_0083897c = DAT_0083897c + 6;
    ITEM_I = DAT_00838978;
    ITEM_WORDS = DAT_0083897c;
  }
  thunk_FUN_00475020(&DAT_007634b4);
  ITEM_WORDS = 1;
  return;
}


