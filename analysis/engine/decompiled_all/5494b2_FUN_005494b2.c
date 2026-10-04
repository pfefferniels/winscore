// FUN_005494b2 @ 005494b2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_005494b2(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined1 *)((int)&DAT_020b8ea0 + *param_3) = 0;
  puVar2 = &DAT_009a1a20;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  thunk_FUN_005963e0(&DAT_020b8ea0,&DAT_009a1a20,DAT_009a1a1c,DAT_009a1a18);
  DAT_01be6cd8 = 0;
  return;
}


