// FUN_0050f5c8 @ 0050f5c8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050f5c8(int *param_1)

{
  int iVar1;
  
  _DAT_009416a4 = 0;
  DAT_0078b4e4 = 0;
  DAT_009416a0 = 0;
  do {
    while( true ) {
      DAT_009416a0 = DAT_009416a0 + 1;
      if (DAT_01c58600 == 3) {
        DAT_0094169c = DAT_0094169c + 1;
        _DAT_00941698 = *(undefined4 *)(&DAT_01a74e9c + DAT_0094169c * 4);
      }
      ITEM_WORDS = 1;
      thunk_FUN_00497f00(&DAT_01c4eec4 + DAT_009416a0 * 0x80,0x80,&ITEM_P1,&DAT_02091d20,&ITEM_WORDS
                         ,&ITEM_I,&ITEM_WORDS);
      if (ITEM_WORDS < 0) {
        return;
      }
      thunk_FUN_00448ab8(&DAT_01c2cc24,&DAT_01c2cc20);
      if (DAT_01c4c788 < 1) break;
LAB_0050f89b:
      thunk_FUN_00449145();
      if (DAT_01c4ef40 <= DAT_009416a0) {
        return;
      }
    }
    if (DAT_009416a0 == 1) {
      if (DAT_01c4c788 == 0) {
        thunk_FUN_00448e00(param_1);
      }
      if (*param_1 == 1) {
        return;
      }
      if (0 < DAT_01c4c788) goto LAB_0050f89b;
      thunk_FUN_0054c590(&STAFF_Y0,&DAT_01c420e4,&MAX_STAFF);
      thunk_FUN_0054c590(&STAFF_STEP0,&DAT_01c41ce0,&MAX_STAFF);
      _DAT_00941694 = f_0;
      DAT_01c58604 = 0;
    }
    if (0 < DAT_01c4c788) {
      return;
    }
    DAT_00941690 = 1;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_0094168c = (&ITEM_PTR0)[DAT_00941690];
      if ((f_2 < (float)(&ITEM_P1)[DAT_0094168c]) &&
         (_DAT_00941694 < (float)(&ITEM_P2)[DAT_0094168c])) {
        _DAT_00941694 = (float)(&ITEM_P2)[DAT_0094168c];
      }
      DAT_00941690 = DAT_00941690 + 1;
    }
    if (DAT_01c58604 == 0) {
      DAT_01c58604 = (int)ROUND(_DAT_00941694);
    }
    else if ((float)DAT_01c58604 != _DAT_00941694) {
      _DAT_00941694 = (float)DAT_01c58604;
    }
    FUN_0050e830(&DAT_009416a0);
    if (DAT_01c4ef40 <= DAT_009416a0) {
      FUN_0050f8ec();
      return;
    }
  } while( true );
}


