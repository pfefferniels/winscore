// FUN_0054946a @ 0054946a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054946a(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_009a1818;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  thunk_FUN_005962f0(&DAT_009a1818,&DAT_009a1818,0,0);
  DAT_01be6cd8 = 0;
  return;
}


