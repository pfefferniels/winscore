// FUN_0054037e @ 0054037e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054037e(int *param_1)

{
  int iVar1;
  
  DAT_01fbb8c8 = (&ITEM_PTR0)[*param_1];
  DAT_01fbb8cc = (&DAT_02091d20)[*param_1];
  DAT_01fbb8d0 = *(int *)(&DAT_020359fc + *param_1 * 4);
  DAT_01fbb8d8 = ITEM_WORDS - DAT_01fbb8cc;
  if (DAT_0078b378 == 1) {
    if (DAT_01fbb8d8 == 0) {
      DAT_01fbb8dc = DAT_0078b37c;
    }
    else {
      DAT_01fbb8dc = (int)ROUND((float)(&ITEM_LEN)[DAT_01fbb8c8]);
    }
    DAT_01c26054 = DAT_01fbb8dc;
    if (DAT_020b9440 == f_16) {
      DAT_01c26054 = 0xd;
      _DAT_01c26058 = (int)ROUND(DAT_020b946c + f_1);
      thunk_FUN_0054c590(&ITEM_P14 + DAT_01fbb8c8 * 4,&DAT_01c2605c,&DAT_01c26058);
    }
    thunk_FUN_0054c590(&DAT_020b9440,&DAT_01c25fa0,&DAT_01c26054);
  }
  if (DAT_01fbb8d8 == 0) {
    ITEM_WORDS = DAT_01fbb8c8;
    NPT = DAT_01fbb8d0;
  }
  else {
    thunk_FUN_0054c590(&ITEM_LEN + DAT_01fbb8cc,&ITEM_LEN + DAT_01fbb8c8,&DAT_01fbb8d8);
    if (0 < DAT_01fbb8d0) {
      DAT_01fbb8d0 = DAT_01fbb8d4 - DAT_01fbb8d0;
    }
    DAT_01fbb8c8 = DAT_01fbb8cc - DAT_01fbb8c8;
    DAT_0099d20c = *param_1 + 1;
    for (iVar1 = (ITEM_I - DAT_0099d20c) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_01fbb8cc = DAT_0099d20c + 1;
      (&ITEM_PTR0)[DAT_0099d20c] = (&ITEM_PTR0)[DAT_01fbb8cc] - DAT_01fbb8c8;
      *(int *)(&DAT_020359fc + DAT_0099d20c * 4) =
           *(int *)(&DAT_020359fc + DAT_01fbb8cc * 4) - DAT_01fbb8d0;
      DAT_0099d20c = DAT_0099d20c + 1;
    }
    ITEM_WORDS = ITEM_WORDS - DAT_01fbb8c8;
  }
  ITEM_I = ITEM_I + -1;
  return;
}


