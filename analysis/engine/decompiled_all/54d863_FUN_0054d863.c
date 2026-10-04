// FUN_0054d863 @ 0054d863 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054d863(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_009a2698;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  iVar1 = 0x3ff;
  DAT_009a2690 = 1;
  do {
    if ((*(char *)(DAT_009a2690 + 0x9a2697) == '|') || ((&DAT_009a2698)[DAT_009a2690] == '|')) {
      *(undefined1 *)(DAT_009a2690 + 0x9a2697) = 0xd;
      (&DAT_009a2698)[DAT_009a2690] = 10;
    }
    DAT_009a2690 = DAT_009a2690 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  thunk_FUN_005960f0(&DAT_009a2698);
  return;
}


