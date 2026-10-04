// FUN_0047766d @ 0047766d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0047766d(void)

{
  int iVar1;
  
  DAT_01f95c98 = (&DAT_02035a00)[ITEM_I];
  DAT_01f95c9c = VEC_N - DAT_01f95c98;
  if (DAT_01f95c9c != 0) {
    DAT_01f95c80 = *(int *)(&DAT_020359fc + ITEM_I * 4);
    for (iVar1 = (VEC_N - DAT_01f95c80) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      if (*(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_01f95c80 * VEC_STRIDE) == 0xff) {
        *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_01f95c80 * VEC_STRIDE) = 0;
      }
      DAT_01f95c80 = DAT_01f95c80 + 1;
    }
  }
  DAT_01f95c90 = (&DAT_020a55a0)[ITEM_I];
  DAT_01f95c94 = (*DAT_01fbb844 - DAT_01f95c90) + 1;
  iVar1 = DAT_01f95c90;
  if (DAT_01f95c94 != 0) {
    do {
      DAT_00828028 = iVar1;
      iVar1 = (*DAT_01fbb844 - DAT_00828028) + 1;
      DAT_01f95c80 = DAT_00828028;
      while( true ) {
        if (iVar1 < 1) {
          return;
        }
        if (*(char *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + DAT_01f95c80 * DAT_01fbb83c) ==
            '\0') break;
        DAT_01f95c80 = DAT_01f95c80 + 1;
        iVar1 = iVar1 + -1;
      }
      *(undefined1 *)
       ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + (DAT_01f95c80 + 9) * DAT_01fbb83c) = 0;
      DAT_00828028 = *(char *)((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
                              (DAT_01f95c80 + 0x1d) * DAT_01fbb83c) * 10 + DAT_01f95c80 + 0x21;
      iVar1 = DAT_00828028;
    } while (DAT_00828028 < *DAT_01fbb844);
  }
  return;
}


