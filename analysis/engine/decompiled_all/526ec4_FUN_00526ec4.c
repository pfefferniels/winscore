// FUN_00526ec4 @ 00526ec4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_00526ec4(uint *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  *param_2 = *param_2 + 1;
  while( true ) {
    *param_1 = (uint)(byte)(&DAT_020b8e9f)[*param_2];
    if (*param_3 <= *param_2) {
      uVar1 = 1;
    }
    if (*param_1 != 0x20) break;
    *param_2 = *param_2 + 1;
  }
  return uVar1;
}


