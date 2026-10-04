// input_range_dialog @ 0052f991 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void input_range_dialog(int *param_1)

{
  int iVar1;
  
  _DAT_01a1fe04 = f_3;
  _DAT_01a1fe08 = f_4;
  _DAT_01a1fe00 = f_1;
  if (DAT_00796fd4 <= DAT_00796fd0) {
    DAT_00796fd0 = ram0x00768438;
    DAT_00796fd4 = DAT_01fbb8b8;
  }
  IP5 = (int)ROUND(DAT_00796fd0);
  IP6 = (int)ROUND(DAT_00796fd4);
  IP7 = 0;
  _DAT_0099a10c = P2;
  if (_DAT_01fb8c64 != f_0) {
    IP7 = (int)ROUND(_DAT_01fb8c64);
  }
  if (IP7 == 999) {
    IP7 = 0;
  }
  iVar1 = thunk_FUN_00599fd0(&IP1);
  *param_1 = iVar1;
  if (*param_1 == 2) {
    if (DAT_01a1f3b8 != 0) {
      thunk_FUN_0045deb2(&DAT_01a1f3b8);
    }
    _DAT_0099a108 = 0x20202020;
    thunk_FUN_00549422();
  }
  else {
    _DAT_01fb8c64 = (float)IP7;
    if (IP7 == 0) {
      _DAT_01fb8c64 = f_999;
    }
    DAT_00796fd0 = (float)IP5;
    DAT_00796fd4 = (float)IP6;
    P1 = DAT_00796fd0;
    P2 = DAT_00796fd4;
  }
  return;
}


