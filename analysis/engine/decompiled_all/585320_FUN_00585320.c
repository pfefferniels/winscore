// FUN_00585320 @ 00585320 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00585320(int *param_1,int *param_2)

{
  int iVar1;
  
  _DAT_009a9150 = *param_1;
  DAT_009a914c = (int)ROUND(*(float *)(&DAT_01c6da5c + *param_1 * 4) + f_1);
  if (0xc < DAT_009a914c) {
    DAT_009a914c = 0xc;
  }
  DAT_009a9148 = (int)ROUND((float)(&DAT_01c6da64)[*param_1]);
  DAT_009a9144 = 1;
  for (iVar1 = DAT_009a914c; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined4 *)(&DAT_01c29bf4 + *param_2 * 0x3000 + DAT_009a9148 * 0x30 + DAT_009a9144 * 4) =
         *(undefined4 *)(&DAT_01c6da5c + *param_1 * 4);
    *param_1 = *param_1 + 1;
    DAT_009a9144 = DAT_009a9144 + 1;
  }
  if (*param_2 == 5) {
    *(float *)(&DAT_01c29bf8 + DAT_009a9148 * 0x30 + *param_2 * 0x3000) = f_5;
  }
  if (DAT_009a914c == 0xc) {
    *(float *)(&DAT_01c29bf8 + *param_2 * 0x3000 + DAT_009a9148 * 0x30) = f_11;
  }
  return;
}


