// FUN_0056c055 @ 0056c055 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056c055(float *param_1,float *param_2)

{
  P6 = DAT_020b9470 / f_2;
  P3 = f_11;
  _DAT_009a8098 = 0x4e;
  DAT_01caf6ac = 0x10;
  DAT_01caf6a8 = 0;
  DAT_01caf6b0 = 1;
  P4 = STEP * f_0_064 - P6;
  DAT_01caf6a0 = (int)ROUND(DAT_020b9444);
  _DAT_009a8094 = DAT_020b9448;
  _DAT_009a8090 = 1;
  DAT_01caf6c0 = 0;
  thunk_FUN_0042daf8(&DAT_0076a254,&DAT_009a8094,&DAT_009a808c);
  *param_1 = P4;
  *param_2 = P2;
  return;
}


