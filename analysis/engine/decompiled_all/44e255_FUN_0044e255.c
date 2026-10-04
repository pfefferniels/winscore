// FUN_0044e255 @ 0044e255 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044e255(int *param_1,int *param_2)

{
  int iVar1;
  int local_44 [2];
  undefined4 local_3c;
  undefined4 local_18;
  undefined4 local_c;
  
  if ((DAT_007fe314 == 0) || (DAT_020b8ea0._1_1_ != 'x')) {
    local_18 = 0;
    if ((*param_2 == 0) && (1 < *param_1)) {
      local_44[0] = *param_1 + -1;
      DAT_007fe310 = FUN_00450b9c(local_44);
      FUN_0044ec7c(&PT_X0 + *param_1,&PT_Y0 + *param_1);
    }
    else {
      if (*param_2 == 3) {
        DAT_007fe310 = *param_1;
        local_3c = 0xffffffff;
        for (iVar1 = -DAT_007fe310 / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
          if (*(short *)((int)&DAT_01fbb8dc + DAT_007fe310 * 2 + 2) != 0) {
            local_c = 0;
            break;
          }
          DAT_007fe310 = DAT_007fe310 + -1;
        }
        DAT_01a14950 = (&PT_X0)[DAT_007fe310];
        DAT_01a1494c = (&PT_Y0)[DAT_007fe310] + _DAT_01cf8f40;
        *param_1 = *param_1 + 1;
        (&PT_X0)[*param_1] = DAT_01a14950;
        (&PT_Y0)[*param_1] = DAT_01a1494c;
        *(undefined2 *)((int)&DAT_01fbb8dc + *param_1 * 2 + 2) = (undefined2)IP1;
        IP1 = 0;
        *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) = DAT_01a14950;
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) = DAT_01a1494c;
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) = IP2;
        FUN_0044ec7c(&DAT_01a14950,&DAT_01a1494c);
        IP2 = 0;
        *param_1 = *param_1 + 1;
        iVar1 = VEC_N + 2;
        VEC_N = VEC_N + 3;
        *DAT_01fbb7c0 = iVar1;
      }
      if (*param_1 == 0) {
        IP2 = (int)&DAT_0100962c;
        IP1._0_2_ = 1;
        DAT_01fbb8a0 = 0x3eb;
      }
      *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) = DAT_01a14950;
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) = DAT_01a1494c;
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) = IP2;
      *param_1 = *param_1 + 1;
      (&PT_X0)[*param_1] = DAT_01a14950;
      (&PT_Y0)[*param_1] = DAT_01a1494c;
      *(undefined2 *)((int)&DAT_01fbb8dc + *param_1 * 2 + 2) = (undefined2)IP1;
      IP1 = 0;
      IP3 = 0;
      IP2 = 0;
      iVar1 = VEC_N + 2;
      VEC_N = VEC_N + 3;
      *DAT_01fbb7c0 = iVar1;
      FUN_0044e9e5(param_1);
      if (DAT_020b8ea0._1_1_ == 'v') {
        DAT_007fe314 = 1;
        *param_1 = *param_1 + -1;
        VEC_N = VEC_N + -3;
      }
    }
  }
  else {
    DAT_007fe314 = 0;
    *param_1 = *param_1 + 1;
    VEC_N = VEC_N + 3;
  }
  return;
}


