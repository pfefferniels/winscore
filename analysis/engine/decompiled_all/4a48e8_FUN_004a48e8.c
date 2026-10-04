// FUN_004a48e8 @ 004a48e8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a48e8(int *param_1)

{
  int iVar1;
  int local_c;
  
  DAT_00838ec8 = 1;
  for (iVar1 = (VEC_N + 2) / 3; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_00838ec8 + 1) * VEC_STRIDE) =
         *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_00838ec8 + 1) * VEC_STRIDE) - *param_1
    ;
    DAT_00838ec8 = DAT_00838ec8 + 3;
  }
  DAT_00838ec8 = 1;
  for (; 0 < DAT_01aea640; DAT_01aea640 = DAT_01aea640 + -1) {
    _DAT_00838ec4 = *(int *)(&DAT_01afdec0 + DAT_00838ec8 * 4);
    iVar1 = 4;
    DAT_00838ec0 = 1;
    do {
      *(undefined1 *)(DAT_00838ec0 + 0x838eb7) =
           *(undefined1 *)
            ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
            (DAT_00838ec0 + _DAT_00838ec4) * DAT_01fbb83c);
      DAT_00838ec0 = DAT_00838ec0 + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
    _DAT_00838eb8 = _DAT_00838eb8 - *param_1;
    local_c = 4;
    DAT_00838ec0 = 1;
    do {
      *(undefined1 *)
       ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + (DAT_00838ec0 + _DAT_00838ec4) * DAT_01fbb83c
       ) = *(undefined1 *)(DAT_00838ec0 + 0x838eb7);
      DAT_00838ec0 = DAT_00838ec0 + 1;
      local_c = local_c + -1;
    } while (0 < local_c);
    DAT_00838ec8 = DAT_00838ec8 + 1;
  }
  DAT_01aea640 = 0;
  return;
}


