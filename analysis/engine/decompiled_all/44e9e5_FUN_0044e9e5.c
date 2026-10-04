// FUN_0044e9e5 @ 0044e9e5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044e9e5(int *param_1)

{
  _DAT_007fe330 = (&PT_X0)[*param_1];
  _DAT_007fe32c = (&PT_Y0)[*param_1];
  _DAT_007fe334 = *(undefined2 *)((int)&DAT_01fbb8dc + *param_1 * 2 + 2);
  DAT_01d953e0 = *param_1;
  FUN_0044ea5b(param_1,&DAT_007fe330,&DAT_007fe32c,&DAT_007fe334);
  FUN_0044ec7c(&DAT_007fe330,&DAT_007fe32c);
  return;
}


