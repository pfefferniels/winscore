// FUN_0044dc3e @ 0044dc3e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044dc3e(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((0 < *param_1) && (*(short *)((int)&DAT_01fbb8dc + *param_1 * 2 + 2) < 1)) {
    DAT_007fe308 = (&PT_X0)[*param_1] - *(int *)(&DAT_01fd3f78 + *param_1 * 4);
    if (DAT_007fe308 < 0) {
      DAT_007fe308 = -DAT_007fe308;
    }
    _DAT_007fe304 = (&PT_Y0)[*param_1] - *(int *)(&DAT_02004cb8 + *param_1 * 4);
    if (_DAT_007fe304 < 0) {
      _DAT_007fe304 = -_DAT_007fe304;
    }
    DAT_007fe300 = *param_1;
    DAT_007fe2fc = *param_1 + -1;
    if (DAT_007fe308 != _DAT_007fe304) {
      if (DAT_007fe308 - _DAT_007fe304 < 1) {
        (&PT_X0)[DAT_007fe2fc] = (&PT_X0)[DAT_007fe300];
        iVar3 = VEC_STRIDE;
        iVar1 = VEC_BASE;
        iVar5 = FUN_00450b9c(&DAT_007fe2fc);
        iVar4 = VEC_STRIDE;
        iVar2 = VEC_BASE;
        iVar7 = VEC_STRIDE * VEC_LBOUND;
        iVar6 = FUN_00450b9c(&DAT_007fe300);
        *(undefined4 *)(iVar5 * iVar3 + (iVar1 - iVar7)) =
             *(undefined4 *)((iVar2 - VEC_STRIDE * VEC_LBOUND) + iVar6 * iVar4);
      }
      else {
        (&PT_Y0)[DAT_007fe2fc] = (&PT_Y0)[DAT_007fe300];
        iVar3 = VEC_STRIDE;
        iVar1 = VEC_BASE;
        iVar5 = FUN_00450b9c(&DAT_007fe2fc);
        iVar4 = VEC_STRIDE;
        iVar2 = VEC_BASE;
        iVar7 = VEC_STRIDE * VEC_LBOUND;
        iVar6 = FUN_00450b9c(&DAT_007fe300);
        *(undefined4 *)((iVar5 + 1) * iVar3 + (iVar1 - iVar7)) =
             *(undefined4 *)((iVar2 - VEC_STRIDE * VEC_LBOUND) + (iVar6 + 1) * iVar4);
      }
    }
  }
  return;
}


