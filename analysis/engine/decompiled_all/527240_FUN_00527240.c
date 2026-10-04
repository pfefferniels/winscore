// FUN_00527240 @ 00527240 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00527240(byte *param_1,undefined4 param_2,int *param_3,int *param_4)

{
  *param_3 = *param_1 - 0x42;
  if (*param_3 < 1) {
    *param_3 = *param_3 + 7;
  }
  *param_3 = *param_4 * 7 + *param_3;
  return;
}


