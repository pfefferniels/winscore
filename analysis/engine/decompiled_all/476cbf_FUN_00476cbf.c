// FUN_00476cbf @ 00476cbf (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00476cbf(int param_1,int *param_2)

{
  int iVar1;
  
  if (DAT_01f95c8c < 0) {
    DAT_01f95c80 = (ITEM_WORDS - *param_2) + 1;
    thunk_FUN_0054c590(param_1 + -4 + *param_2 * 4,param_1 + -4 + (DAT_01f95c8c + *param_2) * 4,
                       &DAT_01f95c80);
  }
  else {
    DAT_00827080 = DAT_01f95c8c + ITEM_WORDS;
    for (iVar1 = (((DAT_01f95c8c + *param_2) - DAT_00827080) + -1) / -1; 0 < iVar1;
        iVar1 = iVar1 + -1) {
      *(undefined4 *)(param_1 + -4 + DAT_00827080 * 4) =
           *(undefined4 *)(param_1 + -4 + (DAT_00827080 - DAT_01f95c8c) * 4);
      DAT_00827080 = DAT_00827080 + -1;
    }
  }
  return;
}


