// FUN_00575198 @ 00575198 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00575198(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 in_ST0;
  
  DAT_01c585c8 = *(int *)(&DAT_020359fc + LOAD_I * 4);
  DAT_01c585cc = (&DAT_02035a00)[LOAD_I];
  DAT_01caea4c = DAT_01c585cc + -1;
  DAT_01caea48 = DAT_01c585c8;
  if (((LOAD_CODE == 8) && (7 < LOAD_LEN)) && (*(float *)(&ITEM_P8 + LOAD_W * 4) != f_0)) {
    DAT_01caea48 = DAT_01c585c8 + 3;
  }
  if ((&DAT_01caea54)[LOAD_STAFF] == 0) {
    if (DAT_01caf3bc < LOAD_STAFF) {
      DAT_01caf3bc = LOAD_STAFF;
    }
    if (LOAD_STAFF < DAT_01caf3b8) {
      DAT_01caf3b8 = LOAD_STAFF;
    }
    iVar2 = 0;
    for (iVar3 = 1; iVar3 < 0x66; iVar3 = iVar3 + 1) {
      *(undefined4 *)(iVar2 * 4 + param_1) = 0xfff9e580;
      iVar2 = iVar2 + 1;
    }
    iVar2 = 0;
    for (iVar3 = 1; iVar3 < 0x66; iVar3 = iVar3 + 1) {
      *(undefined4 *)(iVar2 * 4 + param_2) = 400000;
      iVar2 = iVar2 + 1;
    }
    (&DAT_01caea54)[LOAD_STAFF] = 1;
  }
  if (DAT_01c585cc != DAT_01c585c8) {
    DAT_01c585d8 = DAT_01caea48;
    for (iVar2 = (DAT_01caea4c - DAT_01caea48) / 3; 0 < iVar2; iVar2 = iVar2 + -1) {
      if (*(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_01c585d8 + 5) * VEC_STRIDE) == 0) {
        DAT_01c585dc = *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_01c585d8 * VEC_STRIDE) -
                       VIEW_DX;
        DAT_01caea40 = *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                               (DAT_01c585d8 + 3) * VEC_STRIDE) - VIEW_DX;
        if (((-1 < DAT_01caea40) || (-1 < DAT_01c585dc)) &&
           ((DAT_01caea40 < 0x7531 || (DAT_01c585dc < 0x7531)))) {
          DAT_01c585dc = (DAT_01caea50 + DAT_01c585dc) / DAT_01caee58;
          DAT_01caea40 = (DAT_01caea50 + DAT_01caea40) / DAT_01caee58;
          DAT_01c585c8 = *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                 (DAT_01c585d8 + 1) * VEC_STRIDE) + 290000;
          DAT_01c585cc = *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) +
                                 (DAT_01c585d8 + 4) * VEC_STRIDE) + 290000;
          if (DAT_01caea40 == DAT_01c585dc) {
            if (DAT_01c585c8 < DAT_01c585cc) {
              ffree(in_ST0);
              in_ST0 = (float10)thunk_FUN_0054c68f(&DAT_01c585c8,&DAT_01c585cc);
            }
LAB_005756c8:
            do {
              if (-1 < DAT_01c585dc) {
                if (*(int *)(param_1 + DAT_01c585dc * 4) < DAT_01c585c8) {
                  *(int *)(DAT_01c585dc * 4 + param_1) = DAT_01c585c8;
                }
                if (DAT_01c585cc < *(int *)(param_2 + DAT_01c585dc * 4)) {
                  *(int *)(DAT_01c585dc * 4 + param_2) = DAT_01c585cc;
                }
                if ((DAT_01c585dc == 100) || (DAT_01caea40 == DAT_01c585dc)) goto LAB_00575764;
              }
              DAT_01c585dc = DAT_01c585dc + 1;
            } while( true );
          }
          if (DAT_01c585cc == DAT_01c585c8) {
            if (DAT_01caea40 < DAT_01c585dc) {
              ffree(in_ST0);
              in_ST0 = (float10)thunk_FUN_0054c68f(&DAT_01c585dc,&DAT_01caea40);
            }
            goto LAB_005756c8;
          }
          DAT_01caea54 = (DAT_01caea40 - DAT_01c585dc) * DAT_01caee58;
          if (DAT_01caea54 < 1) {
            ffree(in_ST0);
            DAT_01c585dc = DAT_01caea40;
            in_ST0 = (float10)thunk_FUN_0054c68f(&DAT_01c585c8,&DAT_01c585cc);
            DAT_01caea54 = -DAT_01caea54;
          }
          iVar1 = DAT_01caee58;
          _DAT_009a8c60 = (float)(DAT_01c585cc - DAT_01c585c8);
          _DAT_009a8c64 = _DAT_009a8c60 / (float)DAT_01caea54;
          _DAT_009a8c5c = 0;
          for (iVar3 = (DAT_01caea54 + DAT_01caee58) / DAT_01caee58; 0 < iVar3; iVar3 = iVar3 + -1)
          {
            if ((-1 < DAT_01c585dc) && (DAT_01c585dc < 0x65)) {
              _DAT_009a8c58 = (float)_DAT_009a8c5c;
              in_ST0 = (float10)_DAT_009a8c64 * (float10)_DAT_009a8c5c;
              DAT_01c585cc = (int)ROUND((float10)DAT_01c585c8 + in_ST0);
              if (*(int *)(param_1 + DAT_01c585dc * 4) < DAT_01c585cc) {
                *(int *)(DAT_01c585dc * 4 + param_1) = DAT_01c585cc;
              }
              if (DAT_01c585cc < *(int *)(param_2 + DAT_01c585dc * 4)) {
                *(int *)(DAT_01c585dc * 4 + param_2) = DAT_01c585cc;
              }
            }
            DAT_01c585dc = DAT_01c585dc + 1;
            _DAT_009a8c5c = iVar1 + _DAT_009a8c5c;
          }
        }
      }
LAB_00575764:
      DAT_01c585d8 = DAT_01c585d8 + 3;
    }
  }
  ffree(in_ST0);
  return;
}


