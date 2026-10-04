// FUN_00476da3 @ 00476da3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00476da3(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  uint local_64;
  int local_60;
  undefined4 local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_64 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_020527c8 = (int)ROUND((float)(&ITEM_LEN)[(&DAT_02091d20)[ITEM_I]] + f_1);
  ITEM_WORDS = (&DAT_02091d20)[ITEM_I];
  local_60 = DAT_020527c8;
  thunk_FUN_0054c590(&ITEM_LEN + ITEM_WORDS,&DAT_01e9f740,&DAT_020527c8);
  if (DAT_020527c8 < 4) {
    DAT_020527c8 = 4;
  }
  DAT_01f95c8c = (DAT_020527c8 - DAT_020527c4) + -1;
  if (DAT_01f95c8c != 0) {
    if (DAT_01f95c8c < 1) {
      DAT_01f95c80 = (&DAT_02091d20)[EDIT_ITEM];
      local_64 = (ITEM_WORDS - DAT_01f95c80) + 1;
      thunk_FUN_0054c590(&ITEM_LEN + DAT_01f95c80,&ITEM_LEN + DAT_01f95c8c + DAT_01f95c80,&local_64)
      ;
      local_3c = 0;
    }
    else {
      DAT_01f95c80 = (&DAT_02091d20)[ITEM_I];
      for (local_38 = (((&DAT_02091d20)[EDIT_ITEM] - DAT_01f95c80) + -1) / -1; 0 < local_38;
          local_38 = local_38 + -1) {
        (&ITEM_LEN)[DAT_01f95c8c + DAT_01f95c80] = (&ITEM_LEN)[DAT_01f95c80];
        DAT_01f95c80 = DAT_01f95c80 + -1;
      }
    }
    DAT_01f95c80 = EDIT_ITEM + 1;
    for (local_34 = (ITEM_I - DAT_01f95c80) + 2; 0 < local_34; local_34 = local_34 + -1) {
      (&ITEM_PTR0)[DAT_01f95c80] = (&ITEM_PTR0)[DAT_01f95c80] + DAT_01f95c8c;
      DAT_01f95c80 = DAT_01f95c80 + 1;
    }
  }
  thunk_FUN_0054c590(&DAT_01e9f740,&ITEM_LEN + (&ITEM_PTR0)[EDIT_ITEM],&DAT_020527c8);
  ITEM_WORDS = (&DAT_02091d20)[ITEM_I];
  FUN_0047766d();
  if (DAT_01f95c9c == 0) {
    local_30 = 0;
  }
  else {
    thunk_FUN_0054c4c6((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_01f95c98 * VEC_STRIDE,
                       &DAT_01e99980,&DAT_01f95c9c);
    DAT_01f95c84 = (&DAT_02035a04)[ITEM_I] - (&DAT_02035a00)[ITEM_I];
    DAT_01f95c88 = DAT_01f95c84 -
                   ((&DAT_02035a00)[EDIT_ITEM] - *(int *)(&DAT_020359fc + EDIT_ITEM * 4));
    if (DAT_01f95c88 != 0) {
      if (DAT_01f95c88 < 1) {
        DAT_01f95c80 = (&DAT_02035a00)[EDIT_ITEM];
        local_64 = (&DAT_02035a00)[ITEM_I] - DAT_01f95c80;
        thunk_FUN_0054c590((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_01f95c80 * VEC_STRIDE,
                           (VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                           (DAT_01f95c88 + DAT_01f95c80) * VEC_STRIDE,&local_64);
        local_2c = 0;
      }
      else {
        DAT_01f95c80 = (&DAT_02035a00)[ITEM_I];
        for (local_28 = (((&DAT_02035a00)[EDIT_ITEM] - DAT_01f95c80) + -1) / -1; 0 < local_28;
            local_28 = local_28 + -1) {
          *(undefined4 *)
           ((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_01f95c88 + DAT_01f95c80) * VEC_STRIDE) =
               *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_01f95c80 * VEC_STRIDE);
          DAT_01f95c80 = DAT_01f95c80 + -1;
        }
      }
      DAT_01f95c80 = EDIT_ITEM + 1;
      for (local_24 = (ITEM_I - DAT_01f95c80) + 2; 0 < local_24; local_24 = local_24 + -1) {
        *(int *)(&DAT_020359fc + DAT_01f95c80 * 4) =
             *(int *)(&DAT_020359fc + DAT_01f95c80 * 4) + DAT_01f95c88;
        DAT_01f95c80 = DAT_01f95c80 + 1;
      }
    }
    thunk_FUN_0054c4c6(&DAT_01e99980,
                       (VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                       *(int *)(&DAT_020359fc + EDIT_ITEM * 4) * VEC_STRIDE,&DAT_01f95c9c);
    VEC_N = (&DAT_02035a00)[ITEM_I];
    *DAT_01fbb7c0 = VEC_N + -1;
  }
  DAT_01f95c94 = (&DAT_020a55a4)[ITEM_I] - (&DAT_020a55a0)[ITEM_I];
  DAT_00827084 = DAT_01f95c90;
  while( true ) {
    iVar1 = (*DAT_01fbb844 - DAT_00827084) + 1;
    DAT_01f95c80 = DAT_00827084;
    while( true ) {
      if (iVar1 < 1) goto LAB_004773c9;
      if (*(char *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_01f95c80 * DAT_01fbb83c) ==
          '\0') break;
      local_20 = 0;
      local_14 = 0;
      DAT_01f95c80 = DAT_01f95c80 + 1;
      iVar1 = iVar1 + -1;
    }
    *(undefined1 *)
     ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + (DAT_01f95c80 + 9) * DAT_01fbb83c) = 0;
    DAT_00827084 = *(char *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
                            (DAT_01f95c80 + 0x1d) * DAT_01fbb83c) * 10 + DAT_01f95c80 + 0x21;
    if (*DAT_01fbb844 <= DAT_00827084) break;
    local_1c = 0;
  }
  local_18 = 0;
LAB_004773c9:
  thunk_FUN_0054c52c(DAT_01f95c90 * DAT_01fbb83c + (DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840),
                     &DAT_00827088,&DAT_01f95c94);
  DAT_01f95c88 = DAT_01f95c94 -
                 ((&DAT_020a55a0)[EDIT_ITEM] - *(int *)(&DAT_020a559c + EDIT_ITEM * 4));
  if (DAT_01f95c88 != 0) {
    if (DAT_01f95c88 < 1) {
      DAT_01f95c80 = (&DAT_020a55a0)[EDIT_ITEM];
      local_64 = *DAT_01fbb844 - DAT_01f95c80;
      thunk_FUN_0054c52c(DAT_01f95c80 * DAT_01fbb83c + (DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840),
                         (DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
                         (DAT_01f95c88 + DAT_01f95c80) * DAT_01fbb83c,&local_64);
      local_10 = 0;
    }
    else {
      DAT_01f95c80 = (&DAT_020a55a4)[ITEM_I];
      for (local_c = (((&DAT_020a55a0)[EDIT_ITEM] - DAT_01f95c80) + -1) / -1; 0 < local_c;
          local_c = local_c + -1) {
        *(undefined1 *)
         ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
         (DAT_01f95c88 + DAT_01f95c80) * DAT_01fbb83c) =
             *(undefined1 *)
              ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_01f95c80 * DAT_01fbb83c);
        DAT_01f95c80 = DAT_01f95c80 + -1;
      }
    }
    DAT_01f95c80 = EDIT_ITEM + 1;
    for (local_8 = (ITEM_I - DAT_01f95c80) + 3; 0 < local_8; local_8 = local_8 + -1) {
      *(int *)(&DAT_020a559c + DAT_01f95c80 * 4) =
           *(int *)(&DAT_020a559c + DAT_01f95c80 * 4) + DAT_01f95c88;
      DAT_01f95c80 = DAT_01f95c80 + 1;
    }
  }
  thunk_FUN_0054c52c(&DAT_00827088,
                     (DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
                     *(int *)(&DAT_020a559c + EDIT_ITEM * 4) * DAT_01fbb83c,&DAT_01f95c94);
  *DAT_01fbb844 = (&DAT_020a55a0)[ITEM_I] + -1;
  DAT_0205274c = 0;
  DAT_01f95c80 = EDIT_ITEM;
  EDIT_ITEM = 0;
  draw_items();
  EDIT_ITEM = DAT_01f95c80;
  return;
}


