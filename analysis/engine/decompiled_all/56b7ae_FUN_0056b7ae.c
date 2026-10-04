// FUN_0056b7ae @ 0056b7ae (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_0056b7ae(int *param_1)

{
  int iVar1;
  
  iVar1 = 10;
  DAT_01a1c840 = 1;
  do {
    if (DAT_01cadce4 == *(int *)(DAT_01a1c840 * 4 + 0x79f8a8)) {
      DAT_01cadce4 = DAT_01a1c840 + -1;
      *param_1 = i_1329876802;
      *(undefined1 *)(param_1 + 1) = DAT_0076a1d8;
      return 1;
    }
    DAT_01a1c840 = DAT_01a1c840 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return 0;
}


