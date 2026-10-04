// FUN_004a5d09 @ 004a5d09 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a5d09(void)

{
  char *pcVar1;
  int iVar2;
  float10 in_ST0;
  unkbyte10 Var3;
  
  DAT_00839178 = 35000;
  DAT_00839180 = DAT_01be6c44 - DAT_01fbb7ec;
  _DAT_00839174 = (float)(DAT_01be6c4c * DAT_00839180);
  DAT_00839170 = 1;
  DAT_0083916c = 1;
  for (iVar2 = MAX_STAFF; 0 < iVar2; iVar2 = iVar2 + -1) {
    in_ST0 = (float10)(float)(&STAFF_STEP0)[DAT_0083916c] * (float10)f_49;
    _DAT_00839168 = (float)((float10)(int)(&STAFF_Y0)[DAT_0083916c] + in_ST0);
    DAT_0083917c = (int)ROUND(ABS(_DAT_00839174 - _DAT_00839168));
    if (DAT_0083917c < DAT_00839178) {
      DAT_00839170 = DAT_0083916c;
      DAT_00839178 = DAT_0083917c;
    }
    DAT_0083916c = DAT_0083916c + 1;
  }
  DAT_00839164 = 1;
  if (9 < DAT_00839170) {
    DAT_01e62c84 = (char)(DAT_00839170 / 10) + '0';
    DAT_00839164 = 2;
  }
  *(char *)((int)&DAT_01e62c80 + DAT_00839164 + 3) = (char)(DAT_00839170 % 10) + '0';
  pcVar1 = &DAT_01e62c84 + DAT_00839164;
  DAT_00839164 = DAT_00839164 + 1;
  *pcVar1 = s_______09___InchesMetricParallel_P_0078da40[0];
  ffree(in_ST0);
  Var3 = thunk_FUN_004e1b9f(&DAT_00839164);
  ffree(Var3);
  return;
}


