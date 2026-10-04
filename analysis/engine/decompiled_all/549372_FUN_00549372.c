// FUN_00549372 @ 00549372 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00549372(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_020b90a0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  DAT_020b8ea0._0_1_ = 0;
  do {
    _DAT_009a1808 = thunk_FUN_005966d0(&DAT_020b8ea0,&DAT_020b90a0,DAT_009a180c,0);
    iVar1 = 0x200;
    DAT_009a180c = 1;
    while( true ) {
      if ((&DAT_020b8e9f)[DAT_009a180c] == '\r') {
        return;
      }
      if ((&DAT_020b8e9f)[DAT_009a180c] == '\0') break;
      DAT_009a180c = DAT_009a180c + 1;
      iVar1 = iVar1 + -1;
      if (iVar1 < 1) {
        return;
      }
    }
  } while( true );
}


