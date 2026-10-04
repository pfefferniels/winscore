// FUN_004ddb6e @ 004ddb6e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ddb6e(int *param_1)

{
  int iVar1;
  float10 in_ST0;
  unkbyte10 Var2;
  
  VEC_LAST_PEN = 0;
  VEC_N = *(int *)(&DAT_020359fc + *param_1 * 4);
  ITEM_COUNT_SAVE = ITEM_I;
  ITEM_I = *param_1;
  do {
    DAT_008a0644 = (&ITEM_PTR0)[ITEM_I];
    DAT_008a0640 = (int)ROUND((float)(&ITEM_LEN)[DAT_008a0644]);
    _DAT_008a063c = (float)(&ITEM_P1)[DAT_008a0644];
    _DAT_008a0638 = f_0;
    if (_DAT_008a063c < f_0) {
      _DAT_008a0638 = f_99;
      in_ST0 = (float10)_DAT_008a063c;
      (&ITEM_P1)[DAT_008a0644] = (float)-in_ST0;
    }
    if (((float)(&ITEM_P1)[DAT_008a0644] == f_16) &&
       (f_1 < *(float *)(&ITEM_P12 + DAT_008a0644 * 4))) {
      DAT_008a0640 = 0xc;
    }
    iVar1 = 0x32;
    DAT_008a0634 = 1;
    do {
      if (DAT_008a0640 < DAT_008a0634) {
        *(float *)(&P0 + DAT_008a0634 * 4) = f_0;
      }
      else {
        DAT_008a0644 = DAT_008a0644 + 1;
        *(undefined4 *)(&P0 + DAT_008a0634 * 4) = (&ITEM_LEN)[DAT_008a0644];
      }
      DAT_008a0634 = DAT_008a0634 + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
    NPT = 1;
    ffree(in_ST0);
    Var2 = push_words(&DAT_007659bc,&DAT_020b8ea0);
    ffree(Var2);
    Var2 = draw_item();
    ffree(Var2);
    Var2 = pop_words(&DAT_007659bc,&DAT_020b8ea0);
    OUTPUT_MODE = 1;
    ITEM_I = ITEM_I + 1;
    if (EDIT_ITEM == 0) {
      COLOR = 0xa12d;
    }
    if (_DAT_008a0638 != f_0) {
      P26 = f_0;
      COLOR = 0xff;
    }
    EDIT_ITEM = -1;
    ffree(Var2);
    in_ST0 = (float10)flush_points();
    EDIT_ITEM = 0;
    *(int *)(&DAT_020359fc + ITEM_I * 4) = VEC_N;
  } while (ITEM_I <= ITEM_COUNT_SAVE);
  ITEM_I = ITEM_COUNT_SAVE;
  *DAT_01fbb7c0 = VEC_N + -1;
  ffree(in_ST0);
  Var2 = thunk_FUN_00549422();
  ffree(Var2);
  return;
}


