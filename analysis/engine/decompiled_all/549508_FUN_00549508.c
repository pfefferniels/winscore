// FUN_00549508 @ 00549508 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00549508(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined1 *)((int)&DAT_020b8ea0 + *param_3) = 0;
  puVar2 = &DAT_009a1c20;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  if (*param_3 == 0) {
    DAT_020b8ea0._0_1_ = 0;
  }
  thunk_FUN_00596580(&DAT_020b8ea0,&DAT_009a1c20,*param_4,*param_5);
  DAT_01be6cd8 = 0;
  return;
}


