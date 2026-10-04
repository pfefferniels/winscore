// FUN_0045deb2 @ 0045deb2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045deb2(int *param_1)

{
  int iVar1;
  
  _DAT_01c26198 = *param_1;
  DAT_00824320 = (&ITEM_PTR0)[*param_1];
  DAT_0082431c = *param_1 + 1;
  DAT_00824318 = (&ITEM_PTR0)[DAT_0082431c] - DAT_00824320;
  DAT_01c26194 = DAT_00824318;
  thunk_FUN_0054c590(&ITEM_LEN + DAT_00824320,&DAT_01c25fa0,&DAT_01c26194);
  DAT_00824320 = ITEM_WORDS - (&ITEM_PTR0)[DAT_0082431c];
  thunk_FUN_0054c590(&ITEM_LEN + (&ITEM_PTR0)[DAT_0082431c],&ITEM_LEN + (&ITEM_PTR0)[*param_1],
                     &DAT_00824320);
  _DAT_00824314 =
       *(int *)(&DAT_020359fc + DAT_0082431c * 4) - *(int *)(&DAT_020359fc + *param_1 * 4);
  _DAT_00824310 = VEC_N - *(int *)(&DAT_020359fc + DAT_0082431c * 4);
  thunk_FUN_0054c4c6((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                     *(int *)(&DAT_020359fc + DAT_0082431c * 4) * VEC_STRIDE,
                     *(int *)(&DAT_020359fc + *param_1 * 4) * VEC_STRIDE +
                     (VEC_BASE - VEC_STRIDE * VEC_LBOUND),&DAT_00824310);
  _DAT_0082430c =
       *(int *)(&DAT_020a559c + DAT_0082431c * 4) - *(int *)(&DAT_020a559c + *param_1 * 4);
  _DAT_00824308 = (&DAT_020a55a0)[ITEM_I] - *(int *)(&DAT_020a559c + DAT_0082431c * 4);
  thunk_FUN_0054c4c6(*(int *)(&DAT_020a559c + DAT_0082431c * 4) * DAT_01fbb83c +
                     (DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840),
                     *(int *)(&DAT_020a559c + *param_1 * 4) * DAT_01fbb83c +
                     (DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840),&DAT_00824308);
  DAT_00824304 = *param_1 + 1;
  for (iVar1 = (ITEM_I - DAT_00824304) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(int *)(&DAT_020a559c + DAT_00824304 * 4) = (&DAT_020a55a0)[DAT_00824304] - _DAT_0082430c;
    *(int *)(&DAT_020359fc + DAT_00824304 * 4) = (&DAT_02035a00)[DAT_00824304] - _DAT_00824314;
    (&ITEM_PTR0)[DAT_00824304] = (&DAT_02091d20)[DAT_00824304] - DAT_00824318;
    DAT_00824304 = DAT_00824304 + 1;
  }
  ITEM_I = ITEM_I + -1;
  *DAT_01fbb844 = (&DAT_020a55a0)[ITEM_I] + -1;
  ITEM_WORDS = (&DAT_02091d20)[ITEM_I];
  VEC_N = (&DAT_02035a00)[ITEM_I];
  *DAT_01fbb7c0 = VEC_N + -1;
  DAT_0078b4f0 = 1;
  return;
}


