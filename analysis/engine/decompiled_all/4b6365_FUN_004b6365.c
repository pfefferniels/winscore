// FUN_004b6365 @ 004b6365 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b6365(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  DAT_01c585c0 = *param_2;
  for (iVar1 = (*param_3 - DAT_01c585c0) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(float *)(param_1 + -4 + DAT_01c585c0 * 4) =
         _DAT_01b11764 + *(float *)(param_1 + -4 + DAT_01c585c0 * 4);
    DAT_01c585c0 = DAT_01c585c0 + 1;
  }
  return;
}


