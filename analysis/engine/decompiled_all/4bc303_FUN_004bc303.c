// FUN_004bc303 @ 004bc303 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004bc303(int *param_1,undefined4 param_2)

{
  DAT_0089f868 = DAT_01ba0d60;
  DAT_0089f864 = DAT_01ba0d64;
  thunk_FUN_0047a1c9(param_2);
  DAT_0089f860 = DAT_01ba0d64 - DAT_01ba0d60;
  if (*param_1 < DAT_0089f860) {
    DAT_01ba0d60 = DAT_0089f868;
    DAT_01ba0d64 = DAT_0089f864;
  }
  else {
    *param_1 = DAT_0089f860;
  }
  return;
}


