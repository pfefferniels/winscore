// FUN_004585b9 @ 004585b9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004585b9(int *param_1)

{
  int iVar1;
  
  DAT_01c00584 = 1;
  _DAT_01c00598 = f_m99999;
  do {
    DAT_01c00584 = DAT_01c00584 + 1;
    _DAT_01c00588 = (float)*(int *)(&DAT_01fd3f78 + DAT_01c00584 * 4);
    _DAT_01c0058c = (float)*(int *)(&DAT_02004cb8 + DAT_01c00584 * 4);
    DAT_01c00590 = (float)(int)(&PT_X0)[DAT_01c00584];
    DAT_01c00594 = (float)(int)(&PT_Y0)[DAT_01c00584];
    DAT_01c005a0 = DAT_01c00594 - _DAT_01c0058c;
    DAT_01c0059c = f_99999;
    if (DAT_01c005a0 != f_0) {
      DAT_01c0059c = (DAT_01c00590 - _DAT_01c00588) / DAT_01c005a0;
    }
    if (DAT_01c0059c == _DAT_01c00598) {
      if (*(short *)((int)&DAT_01fbb8dc + DAT_01c00584 * 2) == 0) {
        *param_1 = *param_1 + -1;
        DAT_01c00580 = DAT_01c00584 + -1;
        DAT_01c00584 = DAT_01c00580;
        for (iVar1 = (*param_1 - DAT_01c00580) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
          (&PT_X0)[DAT_01c00580] = (&DAT_01fd3f80)[DAT_01c00580];
          (&PT_Y0)[DAT_01c00580] = (&DAT_02004cc0)[DAT_01c00580];
          *(undefined2 *)((int)&DAT_01fbb8dc + DAT_01c00580 * 2 + 2) = (&DAT_01fbb8e0)[DAT_01c00580]
          ;
          DAT_01c00580 = DAT_01c00580 + 1;
        }
        goto LAB_0045875f;
      }
    }
    else {
LAB_0045875f:
      _DAT_01c00598 = DAT_01c0059c;
    }
    if (*param_1 <= DAT_01c00584) {
      VEC_N = 0x19;
      iVar1 = *param_1;
      DAT_01c00584 = 1;
      for (; 0 < iVar1; iVar1 = iVar1 + -1) {
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
             (&PT_X0)[DAT_01c00584] + DAT_0078df10;
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
             (&PT_Y0)[DAT_01c00584] - DAT_0078df14;
        DAT_007fecf4 = (undefined *)(int)*(short *)((int)&DAT_01fbb8dc + DAT_01c00584 * 2 + 2);
        if ((int)DAT_007fecf4 < 0) {
          DAT_007fecf4 = (undefined *)0x0;
        }
        if (1 < (int)DAT_007fecf4) {
          DAT_007fecf4 = &DAT_010000ff;
        }
        if (DAT_007fecf4 == (undefined *)0x1) {
          DAT_007fecf4 = &DAT_0100962c;
        }
        *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
             DAT_007fecf4;
        VEC_N = VEC_N + 3;
        DAT_01c00584 = DAT_01c00584 + 1;
      }
      *DAT_01fbb7c0 = VEC_N + -1;
      return;
    }
  } while( true );
}


