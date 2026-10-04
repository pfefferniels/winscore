// FUN_00455887 @ 00455887 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00455887(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  DAT_007febb4 = 0;
  if (*param_1 < 0) {
    iVar1 = DAT_007febb0 + -1;
    if (*param_1 == -2) {
      iVar1 = DAT_007febb0 + 1;
    }
    DAT_007febb0 = iVar1;
    if ((DAT_007febb0 < 1) || (*param_3 < DAT_007febb0)) {
      *param_1 = 1;
    }
    else {
      VEC_N = 0x19;
      DAT_007febb8 = (&ITEM_PTR0)[DAT_007febb0];
      for (iVar1 = (&DAT_02091d20)[DAT_007febb0] - DAT_007febb8; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_007febb4 = DAT_007febb4 + 1;
        (&PT_X0)[DAT_007febb4] = (&ITEM_LEN)[DAT_007febb8];
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
             (&ITEM_LEN)[DAT_007febb8] + DAT_0078df10;
        (&PT_Y0)[DAT_007febb4] = *(undefined4 *)(&DAT_0205a19c + DAT_007febb8 * 4);
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
             *(int *)(&DAT_0205a19c + DAT_007febb8 * 4) - DAT_0078df14;
        DAT_007feba4 = (undefined *)(int)*(short *)(&DAT_02060efe + DAT_007febb8 * 2);
        *(short *)((int)&DAT_01fbb8dc + DAT_007febb4 * 2 + 2) =
             *(short *)(&DAT_02060efe + DAT_007febb8 * 2);
        if ((int)DAT_007feba4 < 0) {
          DAT_007feba4 = (undefined *)0x0;
        }
        if (DAT_007feba4 == (undefined *)0x1) {
          DAT_007feba4 = &DAT_0100962c;
        }
        if (1 < *(short *)((int)&DAT_01fbb8dc + DAT_007febb4 * 2 + 2)) {
          DAT_007feba4 = &DAT_010000ff;
        }
        *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
             DAT_007feba4;
        VEC_N = VEC_N + 3;
        DAT_007febb8 = DAT_007febb8 + 1;
      }
      *DAT_01fbb7c0 = VEC_N + -1;
      *param_2 = DAT_007febb4;
      *param_1 = *(int *)(&DAT_020a559c + DAT_007febb0 * 4);
    }
  }
  else if (*param_3 < 7000) {
    if (*param_3 < 1) {
      DAT_02091d20 = 1;
    }
    *param_3 = *param_3 + 1;
    DAT_007febac = (&ITEM_PTR0)[*param_3];
    iVar1 = *param_2;
    DAT_007febb8 = 1;
    for (; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&ITEM_LEN)[DAT_007febac] = (&PT_X0)[DAT_007febb8];
      *(undefined4 *)(&DAT_0205a19c + DAT_007febac * 4) = (&PT_Y0)[DAT_007febb8];
      *(undefined2 *)(&DAT_02060efe + DAT_007febac * 2) =
           *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007febb8 * 2 + 2);
      DAT_007febac = DAT_007febac + 1;
      DAT_007febb8 = DAT_007febb8 + 1;
    }
    (&DAT_02091d20)[*param_3] = DAT_007febac;
    *(int *)(&DAT_020a559c + *param_3 * 4) = *param_1;
    DAT_007febb0 = *param_3;
    _DAT_007feba8 = 0;
  }
  return;
}


