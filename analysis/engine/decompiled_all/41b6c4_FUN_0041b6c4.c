// FUN_0041b6c4 @ 0041b6c4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0041b700) */

void FUN_0041b6c4(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = VEC_STRIDE;
  iVar2 = VEC_BASE;
  if (*param_1 == 0) {
    iVar4 = VEC_STRIDE * VEC_LBOUND;
    iVar5 = VEC_N;
    for (iVar3 = 1; iVar3 < 0x11; iVar3 = iVar3 + 1) {
      *(undefined4 *)((iVar2 - iVar4) + iVar1 * iVar5) = 0;
      iVar5 = iVar5 + 1;
    }
  }
  else {
    DAT_01e66ca0 = DAT_01a14950;
    DAT_01e66ca4 = DAT_01a1494c;
    DAT_01e66ca8 = DAT_01a14948;
    DAT_01e66cac = DAT_01a14944;
    DAT_01fbb7f8 = VEC_N;
    DAT_01a14950 = VIEW_DX + DAT_01a14950;
    DAT_01a14948 = VIEW_DX + DAT_01a14948;
    DAT_007d1580 = *(int *)(&DAT_0078e800 + *param_1 * 4) + 0x1000000;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) = DAT_01a14950;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) = DAT_01a1494c;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) = DAT_007d1580;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 3) * VEC_STRIDE) = DAT_01a14950;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 4) * VEC_STRIDE) = DAT_01a14944;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 5) * VEC_STRIDE) = 0;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 6) * VEC_STRIDE) = DAT_01a14948;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 7) * VEC_STRIDE) = DAT_01a14944;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 8) * VEC_STRIDE) = 0;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 9) * VEC_STRIDE) = DAT_01a14948;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 10) * VEC_STRIDE) = DAT_01a1494c
    ;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 0xb) * VEC_STRIDE) = 0;
    *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 0xc) * VEC_STRIDE) = DAT_01a14950;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 0xd) * VEC_STRIDE) =
         DAT_01a1494c;
    *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 0xe) * VEC_STRIDE) = 0;
    iVar2 = VEC_N + 0xe;
    VEC_N = VEC_N + 0xf;
    *DAT_01fbb7c0 = iVar2;
  }
  thunk_FUN_00549422();
  return;
}


