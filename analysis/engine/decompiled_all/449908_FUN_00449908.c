// FUN_00449908 @ 00449908 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00449908(int *param_1)

{
  int iVar1;
  
  _DAT_0078dd6c = *param_1;
  DAT_007fdf0c = (&ITEM_PTR0)[*param_1];
  DAT_007fdf08 = (&DAT_02091d20)[*param_1];
  DAT_007fdf04 = ITEM_WORDS - DAT_007fdf08;
  if ((DAT_0078b378 == 1) && (DAT_01fbb7f8 != 0x42)) {
    if (DAT_007fdf04 == 0) {
      DAT_007fdf00 = DAT_0078b37c;
    }
    else {
      DAT_007fdf00 = (int)ROUND((float)(&ITEM_LEN)[DAT_007fdf0c]);
    }
    _DAT_01c260fc = 0;
    DAT_01c26054 = DAT_007fdf00;
    if (DAT_020b9440 == f_16) {
      DAT_01c26054 = 0xd;
      _DAT_01c26058 = (int)ROUND(DAT_020b946c / f_4 + f_1);
      thunk_FUN_0054c590(&ITEM_P14 + DAT_007fdf0c * 4,&DAT_01c2605c,&DAT_01c26058);
    }
    thunk_FUN_0054c590(&DAT_020b9440,&DAT_01c25fa0,&DAT_01c26054);
  }
  if (DAT_007fdf04 == 0) {
    ITEM_WORDS = DAT_007fdf0c;
  }
  else {
    thunk_FUN_0054c590(&ITEM_LEN + DAT_007fdf08,&ITEM_LEN + DAT_007fdf0c,&DAT_007fdf04);
    DAT_007fdf0c = DAT_007fdf08 - DAT_007fdf0c;
    DAT_007fdefc = *param_1 + 1;
    for (iVar1 = (ITEM_I - DAT_007fdefc) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_007fdf08 = DAT_007fdefc + 1;
      (&ITEM_PTR0)[DAT_007fdefc] = (&ITEM_PTR0)[DAT_007fdf08] - DAT_007fdf0c;
      DAT_007fdefc = DAT_007fdefc + 1;
    }
    ITEM_WORDS = (&ITEM_PTR0)[ITEM_I];
  }
  ITEM_I = ITEM_I + -1;
  DAT_0078b4f0 = 1;
  P2 = f_0;
  return;
}


