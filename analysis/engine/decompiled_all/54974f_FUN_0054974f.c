// FUN_0054974f @ 0054974f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054974f(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)&DAT_020b90a0;
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_009a1e30 = 0;
  if (*param_3 != 0) {
    iVar1 = 0x200;
    DAT_009a1e30 = 1;
    do {
      if ((&DAT_020b909f)[DAT_009a1e30] == '\0') goto LAB_005497e2;
      DAT_009a1e30 = DAT_009a1e30 + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
  }
  DAT_020b8ea0._0_1_ = 0;
LAB_005497e2:
  _DAT_009a1e34 = DAT_009a1e30;
  iVar1 = thunk_FUN_00596cc0(&DAT_020b8ea0,&DAT_020b90a0,DAT_009a1e30,DAT_009a1e30);
  *param_3 = iVar1;
  return;
}


