// FUN_00421651 @ 00421651 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00421651(undefined4 param_1,int *param_2,int *param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  for (iVar2 = 1; iVar2 < 0xc9; iVar2 = iVar2 + 1) {
    (&DAT_007d2568)[iVar2] = 0;
  }
  for (iVar2 = 1; iVar2 < 0xc9; iVar2 = iVar2 + 1) {
    (&DAT_007d2248)[iVar2] = 0;
  }
  DAT_007d2248 = 0;
  DAT_007d223c = 0;
  iVar2 = -ITEM_I / -1;
  _DAT_007d2244 = ITEM_WORDS;
  _DAT_007d2240 = (float)i_0;
  LOAD_I = ITEM_I;
  while( true ) {
    if (iVar2 < 1) {
      *param_2 = 999;
      return;
    }
    load_item_header();
    DAT_007d2248 = DAT_007d2248 + 1;
    (&DAT_007d2248)[DAT_007d2248] = 0;
    iVar1 = DAT_007d223c + 1;
    if (LOAD_CODE < 3) {
      if (_DAT_007d2240 == LOAD_P3) {
        *(undefined4 *)(&DAT_007d2244 + DAT_007d2248 * 4) = 1;
        iVar1 = DAT_007d223c;
      }
      DAT_007d223c = iVar1;
      _DAT_007d2240 = LOAD_P3;
      iVar1 = DAT_007d223c;
    }
    DAT_007d223c = iVar1;
    (&DAT_007d2568)[DAT_007d2248] = LOAD_I;
    if (*param_2 < DAT_007d223c) break;
    LOAD_I = LOAD_I + -1;
    iVar2 = iVar2 + -1;
  }
  DAT_007d2248 = DAT_007d2248 + -1;
  iVar2 = *param_3;
  DAT_007d2238 = 1;
  iVar1 = DAT_007d222c;
  while (DAT_007d222c = iVar1, iVar2 = iVar2 + -1, 0 < iVar2) {
    DAT_007d2234 = DAT_007d2248;
    iVar1 = DAT_007d222c;
    DAT_007d222c = ITEM_WORDS;
    for (iVar3 = -DAT_007d2248 / -1; ITEM_WORDS = DAT_007d222c, 0 < iVar3; iVar3 = iVar3 + -1) {
      DAT_007d2230 = (&ITEM_PTR0)[(&DAT_007d2568)[DAT_007d2234]];
      DAT_007d2228 = (int)ROUND((float)(&ITEM_LEN)[DAT_007d2230] + f_1);
      thunk_FUN_0054c590(&ITEM_LEN + DAT_007d2230,&ITEM_LEN + DAT_007d222c,&DAT_007d2228);
      ITEM_WORDS = DAT_007d2228 + ITEM_WORDS;
      ITEM_I = ITEM_I + 1;
      if ((&DAT_007d2248)[DAT_007d2234] == 0) {
        *param_4 = DAT_0078cae8 + *param_4;
      }
      (&ITEM_P3)[DAT_007d222c] = *param_4;
      DAT_007d2234 = DAT_007d2234 + -1;
      iVar1 = DAT_007d222c;
      DAT_007d222c = ITEM_WORDS;
    }
    DAT_007d2238 = DAT_007d2238 + 1;
  }
  push_words(&DAT_0075f8a0,&DAT_020b8ea0);
  draw_items();
  pop_words(&DAT_0075f8a0,&DAT_020b8ea0);
  thunk_FUN_00549422();
  return;
}


