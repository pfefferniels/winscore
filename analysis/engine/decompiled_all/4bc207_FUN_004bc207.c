// FUN_004bc207 @ 004bc207 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004bc207(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  DAT_0089f85c = 1;
  DAT_0089f858 = 2;
  for (iVar2 = DAT_01ba0d68; 0 < iVar2; iVar2 = iVar2 + -1) {
    *(undefined4 *)(DAT_0089f858 * 4 + param_1 + -4) =
         *(undefined4 *)(param_3 + -4 + DAT_0089f858 * 4);
    DAT_0089f854 = 0;
    DAT_0089f850 = DAT_0089f85c;
    for (iVar1 = *(int *)(param_3 + -4 + DAT_0089f858 * 4) - DAT_0089f85c; 0 < iVar1;
        iVar1 = iVar1 + -1) {
      DAT_0089f854 = DAT_0089f854 + *(int *)(param_2 + -4 + DAT_0089f850 * 4);
      DAT_0089f850 = DAT_0089f850 + 1;
    }
    *(int *)(DAT_0089f858 * 4 + param_4 + -8) = DAT_0089f854;
    DAT_0089f85c = *(int *)(param_3 + -4 + DAT_0089f858 * 4);
    DAT_0089f858 = DAT_0089f858 + 1;
  }
  return;
}


