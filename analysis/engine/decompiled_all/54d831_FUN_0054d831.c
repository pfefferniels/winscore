// FUN_0054d831 @ 0054d831 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054d831(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_009a2490;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  thunk_FUN_005960f0(&DAT_009a2490);
  return;
}


