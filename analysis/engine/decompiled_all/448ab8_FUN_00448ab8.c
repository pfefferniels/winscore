// FUN_00448ab8 @ 00448ab8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00448ab8(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  for (iVar1 = 1; iVar1 < 0x101; iVar1 = iVar1 + 1) {
    (&DAT_007fcfa0)[iVar1] = 0;
  }
  DAT_007fcfa0 = 0;
  DAT_01c58604 = 1;
  DAT_007fcf9c = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_007fcf98 = (&ITEM_PTR0)[DAT_007fcf9c];
    if ((float)(&ITEM_P1)[DAT_007fcf98] == f_14) {
      if ((f_3 < (float)(&ITEM_LEN)[DAT_007fcf98]) &&
         ((float)DAT_01c58604 < (float)(&ITEM_P4)[DAT_007fcf98])) {
        DAT_01c58604 = (int)ROUND((float)(&ITEM_P4)[DAT_007fcf98]);
      }
    }
    else if ((float)(&ITEM_P1)[DAT_007fcf98] == f_8) {
      DAT_007fcfa0 = DAT_007fcfa0 + 1;
      (&DAT_007fcfa0)[DAT_007fcfa0] = (int)ROUND((float)(&ITEM_P2)[DAT_007fcf98]);
    }
    DAT_007fcf9c = DAT_007fcf9c + 1;
  }
  DAT_007fcf94 = 1;
  DAT_007fcf90 = f_1;
  do {
    DAT_007fcf9c = 2;
    iVar1 = DAT_007fcfa0;
    while( true ) {
      iVar1 = iVar1 + -1;
      if (iVar1 < 1) {
        *param_2 = 1;
        *param_1 = DAT_007fcfa0;
        do {
          DAT_007fcf8c = 1;
          for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
            DAT_007fcf98 = (&ITEM_PTR0)[DAT_007fcf8c];
            DAT_007fcf88 = (int)ROUND((float)(&ITEM_P2)[DAT_007fcf98]);
            if (DAT_007fcf88 == (&DAT_007fcfa0)[DAT_007fcf94]) {
              (&ITEM_P2)[DAT_007fcf98] = DAT_007fcf90;
            }
            DAT_007fcf8c = DAT_007fcf8c + 1;
          }
          DAT_007fcf90 = DAT_007fcf90 + f_1;
          DAT_007fcf94 = DAT_007fcf94 + 1;
        } while (DAT_007fcf94 <= DAT_007fcfa0);
        return;
      }
      if ((&DAT_007fcfa0)[DAT_007fcf9c] <= (&DAT_007fcf9c)[DAT_007fcf9c]) break;
      DAT_007fcf9c = DAT_007fcf9c + 1;
    }
    thunk_FUN_0054c68f(&DAT_007fcfa0 + DAT_007fcf9c,&DAT_007fcf9c + DAT_007fcf9c);
  } while( true );
}


