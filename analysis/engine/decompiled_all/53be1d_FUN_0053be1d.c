// FUN_0053be1d @ 0053be1d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053be1d(void)

{
  unkbyte10 in_ST0;
  unkbyte10 Var1;
  int local_34 [2];
  int local_2c;
  int local_28;
  
  DAT_01c585e8 = NPT;
  local_2c = NPT + 1;
  ffree(in_ST0);
  FUN_0053c18d(&DAT_00768a84,&local_2c);
  DAT_0099ca04 = NPT / 2 + NPT;
  _DAT_0099ca00 = (float)NPT;
  _DAT_0099c9fc = f_400;
  if (f_9 < P16) {
    _DAT_0099c9fc = f_600;
  }
  _DAT_0099c9fc = _DAT_0099c9fc / ((f_25 / STEP) * DAT_01c58674);
  DAT_01c585c4 = (int)ROUND((float10)NPT / (float10)f_4 - (float10)_DAT_0099c9fc / (float10)f_2);
  DAT_01c585e8 = DAT_01c585c4 + 1;
  local_2c = NPT - DAT_01c585c4;
  ffree((float10)NPT / (float10)f_4);
  local_28 = DAT_01c585c4;
  Var1 = FUN_0053c18d(&local_2c,&DAT_01c585e8);
  DAT_01c585e8 = DAT_01c585e8 + -1;
  local_2c = DAT_01c585c4 * 2 + 1;
  ffree(Var1);
  Var1 = FUN_0053c18d(&DAT_0099ca04,&local_2c);
  DAT_01c585e8 = DAT_01c585e8 + 1;
  local_2c = (DAT_0099ca04 - DAT_01c585c4) + 1;
  local_34[0] = DAT_01c585c4 * 3 + 1;
  ffree(Var1);
  Var1 = FUN_0053c18d(&local_2c,local_34);
  (&DAT_01fbb8e0)[DAT_01c585c4 * 2] = 2;
  NPT = DAT_01c585c4 * 4;
  ffree(Var1);
  return;
}


