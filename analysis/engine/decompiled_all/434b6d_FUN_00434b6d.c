// FUN_00434b6d @ 00434b6d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00434b6d(int *param_1)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var2;
  float10 fVar3;
  float local_3c;
  int local_38;
  int local_14;
  int local_10;
  int local_c;
  
  ffree(in_ST0);
  Var2 = push_words(&DAT_007601e0,&P3);
  ffree(Var2);
  push_words(&DAT_007601e0,&IP3);
  DAT_007f7570 = (int)ROUND(_DAT_01f93e68 - DAT_01f93e60);
  DAT_007f756c = (int)ROUND(_DAT_01f93e7c - DAT_01f93e64);
  if (P10 == f_0) {
    P10 = f_1;
  }
  DAT_01cf8ec4 = (int)ROUND((float)DAT_007f7570 / (P10 * f_175) + f_0_5);
  if (DAT_01cf8ec4 % 2 == 0) {
    DAT_01cf8ec4 = DAT_01cf8ec4 + -1;
  }
  _DAT_007f7568 = (float)(DAT_007f7570 / DAT_01cf8ec4);
  fVar3 = (float10)DAT_007f756c;
  local_3c = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
  DAT_007f7564 = (int)ROUND(fVar3 / ((float10)P10 * (float10)f_175) + (float10)f_0_5);
  if (DAT_007f7564 % 2 == 0) {
    DAT_007f7564 = DAT_007f7564 + -1;
  }
  local_38 = DAT_007f756c / DAT_007f7564;
  _DAT_007f7560 = (float)local_38;
  DAT_01cf8ec0 = 1;
  _DAT_007f755c = DAT_01f93e60;
  for (local_14 = (DAT_01cf8ec4 + 1) / 2; 0 < local_14; local_14 = local_14 + -1) {
    ffree(fVar3);
    Var2 = add_point(&DAT_007f755c,&DAT_01f93e64,&DAT_00760110);
    _DAT_007f755c = _DAT_007f7568 + _DAT_007f755c;
    ffree(Var2);
    fVar3 = (float10)add_point(&DAT_007f755c,&DAT_01f93e64,&DAT_00760108);
    _DAT_007f755c = _DAT_007f7568 + _DAT_007f755c;
    DAT_01cf8ec0 = DAT_01cf8ec0 + 1;
  }
  _DAT_007f7558 = _DAT_007f7560 + DAT_01f93e6c;
  local_10 = (DAT_007f7564 + 1) / 2;
  DAT_01cf8ec0 = 1;
  while (local_10 = local_10 + -1, 0 < local_10) {
    ffree(fVar3);
    Var2 = add_point(&DAT_01f93e68,&DAT_007f7558,&DAT_00760108);
    _DAT_007f7558 = _DAT_007f7560 + _DAT_007f7558;
    ffree(Var2);
    fVar3 = (float10)add_point(&DAT_01f93e68,&DAT_007f7558,&DAT_00760110);
    _DAT_007f7558 = _DAT_007f7560 + _DAT_007f7558;
    DAT_01cf8ec0 = DAT_01cf8ec0 + 1;
  }
  ffree(fVar3);
  Var2 = add_point(&DAT_01f93e68,&DAT_007f7558,&DAT_00760108);
  _DAT_007f755c = _DAT_01f93e68 - _DAT_007f7568;
  iVar1 = (DAT_01cf8ec4 + 1) / 2;
  DAT_01cf8ec0 = 1;
  while (iVar1 = iVar1 + -1, 0 < iVar1) {
    ffree(Var2);
    Var2 = add_point(&DAT_007f755c,&DAT_01f93e74,&DAT_00760108);
    _DAT_007f755c = _DAT_007f755c - _DAT_007f7568;
    ffree(Var2);
    Var2 = add_point(&DAT_007f755c,&DAT_01f93e74,&DAT_00760110);
    _DAT_007f755c = _DAT_007f755c - _DAT_007f7568;
    DAT_01cf8ec0 = DAT_01cf8ec0 + 1;
  }
  ffree(Var2);
  Var2 = add_point(&DAT_007f755c,&DAT_01f93e74,&DAT_00760108);
  _DAT_007f7558 = DAT_01f93e74 - _DAT_007f7560;
  local_c = (DAT_007f7564 + 1) / 2;
  DAT_01cf8ec0 = 1;
  while (local_c = local_c + -1, 0 < local_c) {
    ffree(Var2);
    Var2 = add_point(&DAT_01f93e60,&DAT_007f7558,&DAT_00760108);
    _DAT_007f7558 = _DAT_007f7558 - _DAT_007f7560;
    ffree(Var2);
    Var2 = add_point(&DAT_01f93e60,&DAT_007f7558,&DAT_00760110);
    _DAT_007f7558 = _DAT_007f7558 - _DAT_007f7560;
    DAT_01cf8ec0 = DAT_01cf8ec0 + 1;
  }
  ffree(Var2);
  Var2 = add_point(&DAT_01f93e60,&DAT_007f7558,&DAT_00760108);
  local_3c = _DAT_007f7568 + DAT_01f93e60;
  ffree(Var2);
  Var2 = add_point(&local_3c,&DAT_01f93e64,&DAT_00760108);
  if ((1 < IP8) && (*param_1 != -1)) {
    IP8 = 1;
  }
  ffree(Var2);
  Var2 = thunk_FUN_00549422();
  if (*param_1 == -1) {
    IP5 = 0;
  }
  ffree(Var2);
  return;
}


