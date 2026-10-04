// FUN_004d4ed2 @ 004d4ed2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004d4ed2(int *param_1)

{
  DAT_008a0350 = (DAT_0078b47c * *param_1) / 600;
  (&PT_X0)[NPT] = 999;
  (&PT_Y0)[NPT] = DAT_008a0350;
  *(undefined2 *)((int)&DAT_01fbb8dc + NPT * 2 + 2) = 99;
  NPT = NPT + 1;
  return;
}


