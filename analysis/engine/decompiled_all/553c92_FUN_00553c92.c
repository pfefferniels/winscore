// FUN_00553c92 @ 00553c92 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00553d68) */
/* WARNING: Removing unreachable block (ram,0x00553d26) */
/* WARNING: Removing unreachable block (ram,0x00553d41) */
/* WARNING: Removing unreachable block (ram,0x00553d75) */
/* WARNING: Removing unreachable block (ram,0x00553ddc) */
/* WARNING: Removing unreachable block (ram,0x00553de4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00553c92(void)

{
  undefined2 in_FPUControlWord;
  
  DAT_01fbb7f8 = 0;
  DAT_009a3880 = DAT_01fbb7e4;
  _DAT_009a387c = DAT_01fbb7e8;
  _DAT_009a3878 = DAT_01fbb7ec;
  DAT_009a3884 = -((DAT_01fbb7ec - DAT_01be6c44) + 1);
  _DAT_009a3874 = (float)(DAT_01be6c4c * DAT_009a3884);
  _DAT_009a3870 = (float)((DAT_01fbb7e8 - DAT_01be6c40) * DAT_01be6c48);
  DAT_009a386c = 0;
  DAT_009a3868 = 0;
  DAT_009a3864 = DAT_020b8e30 + 999;
  if ((DAT_01fbb7e4 == 2) || (DAT_01fbb7e4 == 6)) {
    if (DAT_01be6c54 <= f_1) {
      _DAT_009a3860 = f_0_8;
    }
    else {
      _DAT_009a3860 = f_0_5;
    }
  }
  else if (DAT_01be6c54 < f_1) {
    _DAT_009a3860 = f_1_25;
  }
  else {
    _DAT_009a3860 = f_2;
  }
  P2 = _DAT_009a3860 * DAT_01be6c54;
  (&PT_X0)[DAT_009a3864] = (int)ROUND(_DAT_009a3870);
  (&PT_Y0)[DAT_009a3864] = (int)ROUND(_DAT_009a3874);
  _DAT_009a3838 = 0x4d;
  if ((DAT_0078b378 == 0) || (DAT_0078b378 == 8)) {
    thunk_FUN_005721e2(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
  }
  return;
}


