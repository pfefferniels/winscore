// FUN_004680d8 @ 004680d8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004680d8(int *param_1,int *param_2)

{
  int iVar1;
  
  DAT_00824630 = *param_1;
  for (iVar1 = (*param_2 - DAT_00824630) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(float *)(&DAT_01c5891c + DAT_00824630 * 4) = f_0;
    DAT_00824630 = DAT_00824630 + 1;
  }
  return;
}


