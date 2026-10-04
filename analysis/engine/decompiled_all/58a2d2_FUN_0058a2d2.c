// FUN_0058a2d2 @ 0058a2d2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058a2d2(int *param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_2 = *(undefined2 *)(&DAT_007a056f + iVar1 * 3);
  *(undefined *)(param_2 + 1) = (&DAT_007a0571)[iVar1 * 3];
  return;
}


