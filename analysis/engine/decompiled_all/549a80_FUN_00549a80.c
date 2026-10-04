// FUN_00549a80 @ 00549a80 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00549a80(int *param_1)

{
  int iVar1;
  
  DAT_009a205c = thunk_FUN_0059cfa0();
  *param_1 = (int)DAT_009a205c / 0x100;
  _DAT_009a2058 = DAT_009a205c & 0xff;
  iVar1 = thunk_FUN_00597120(&DAT_020b90a0,&DAT_020b8ea0,DAT_009a2064,DAT_009a2060);
  *param_1 = iVar1;
  _DAT_009a2068 = DAT_009a9488;
  _DAT_009a2054 = DAT_009c48f4;
  return;
}


