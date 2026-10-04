// FUN_004411bd @ 004411bd (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004411bd(int param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = *param_3;
  DAT_007f7d38 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined1 *)((int)&DAT_009a9498 + *param_4 + 3) =
         *(undefined1 *)(param_1 + -1 + DAT_007f7d38);
    *param_4 = *param_4 + 1;
    DAT_007f7d38 = DAT_007f7d38 + 1;
  }
  return;
}


