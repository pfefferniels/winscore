// FUN_004ff19c @ 004ff19c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ff19c(int *param_1)

{
  int iVar1;
  int iVar2;
  int local_c;
  
  DAT_00902080 = 1;
  for (iVar1 = (VEC_N + 2) / 3; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_00902080 + 1) * VEC_STRIDE) =
         *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_00902080 + 1) * VEC_STRIDE) - *param_1
    ;
    DAT_00902080 = DAT_00902080 + 3;
  }
  DAT_00902080 = 1;
  for (iVar1 = DAT_01aea640; 0 < iVar1; iVar1 = iVar1 + -1) {
    _DAT_0090207c = *(int *)(&DAT_01afdec0 + DAT_00902080 * 4);
    local_c = 4;
    DAT_00902078 = 1;
    do {
      *(undefined1 *)(DAT_00902078 + 0x90206f) =
           *(undefined1 *)
            ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) +
            (DAT_00902078 + _DAT_0090207c) * DAT_01fbb83c);
      DAT_00902078 = DAT_00902078 + 1;
      local_c = local_c + -1;
    } while (0 < local_c);
    _DAT_00902070 = _DAT_00902070 - *param_1;
    iVar2 = 4;
    DAT_00902078 = 1;
    do {
      *(undefined1 *)
       ((DAT_01fbb824 - DAT_01fbb83c * DAT_01fbb840) + (DAT_00902078 + _DAT_0090207c) * DAT_01fbb83c
       ) = *(undefined1 *)(DAT_00902078 + 0x90206f);
      DAT_00902078 = DAT_00902078 + 1;
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
    DAT_00902080 = DAT_00902080 + 1;
  }
  thunk_FUN_00549422();
  return;
}


