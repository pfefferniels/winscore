// add_point @ 0044b820 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void add_point(float *param_1,float *param_2,undefined2 *param_3)

{
  (&PT_X0)[NPT] = (int)ROUND(*param_1);
  (&PT_Y0)[NPT] = (int)ROUND(*param_2);
  *(undefined2 *)((int)&DAT_01fbb8dc + NPT * 2 + 2) = *param_3;
  NPT = NPT + 1;
  return;
}


