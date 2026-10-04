// FUN_0045bc18 @ 0045bc18 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045bc18(int *param_1)

{
  int iVar1;
  char *pcVar2;
  short *psVar3;
  char *pcVar4;
  short *psVar5;
  bool bVar6;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x48;
  iVar1 = 3;
  pcVar2 = &DAT_007a0b7e;
  pcVar4 = "040";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar6);
  if (bVar6) {
    DAT_0078df14 = DAT_0078df14 + 4000;
  }
  else {
    iVar1 = 3;
    pcVar2 = &DAT_007a0b7e;
    pcVar4 = "038";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar6);
    if (bVar6) {
      DAT_0078df14 = DAT_0078df14 + -4000;
    }
    else {
      iVar1 = 3;
      pcVar2 = &DAT_007a0b7e;
      pcVar4 = "===";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar6 = *pcVar2 == *pcVar4;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar6);
      if (bVar6) {
        DAT_0078df14 = 0;
      }
      else {
        iVar1 = 3;
        pcVar2 = &DAT_007a0b7e;
        pcVar4 = "037";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar6 = *pcVar2 == *pcVar4;
          pcVar2 = pcVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar6);
        if (bVar6) {
          DAT_0078df10 = DAT_0078df10 + -4000;
        }
        else {
          iVar1 = 3;
          pcVar2 = &DAT_007a0b7e;
          pcVar4 = "039";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar6 = *pcVar2 == *pcVar4;
            pcVar2 = pcVar2 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar6);
          if (bVar6) {
            DAT_0078df10 = DAT_0078df10 + 4000;
          }
          else {
            iVar1 = 1;
            psVar3 = (short *)&DAT_007a0b7f;
            psVar5 = &DAT_00761460;
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar6 = *psVar3 == *psVar5;
              psVar3 = psVar3 + 1;
              psVar5 = psVar5 + 1;
            } while (bVar6);
            if (!bVar6) goto LAB_0045beb0;
            DAT_0078df10 = 0;
          }
        }
      }
    }
  }
  thunk_FUN_0044de36();
  if (*param_1 != 0) {
    iVar1 = *param_1;
    DAT_007fefd8 = 1;
    _DAT_007fefdc = f_1;
    for (; 0 < iVar1; iVar1 = iVar1 + -1) {
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + VEC_N * VEC_STRIDE) =
           (&PT_X0)[DAT_007fefd8] + DAT_0078df10;
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 1) * VEC_STRIDE) =
           (&PT_Y0)[DAT_007fefd8] - DAT_0078df14;
      DAT_007fefd4 = (undefined *)(int)*(short *)((int)&DAT_01fbb8dc + DAT_007fefd8 * 2 + 2);
      if ((int)DAT_007fefd4 < 0) {
        DAT_007fefd4 = (undefined *)0x0;
      }
      if (1 < (int)DAT_007fefd4) {
        DAT_007fefd4 = &DAT_010000ff;
      }
      if (DAT_007fefd4 == (undefined *)0x1) {
        DAT_007fefd4 = &DAT_0100962c;
      }
      *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (VEC_N + 2) * VEC_STRIDE) =
           DAT_007fefd4;
      VEC_N = VEC_N + 3;
      DAT_007fefd8 = DAT_007fefd8 + 1;
    }
    *DAT_01fbb7c0 = VEC_N + -1;
  }
LAB_0045beb0:
  FUN_005f34d1(&stack0xfffffffc,0x45becd);
  return;
}


