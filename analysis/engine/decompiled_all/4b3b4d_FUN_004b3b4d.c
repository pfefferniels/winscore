// FUN_004b3b4d @ 004b3b4d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b3b4d(float *param_1)

{
  unkbyte10 in_ST0;
  float10 fVar1;
  unkbyte10 extraout_ST1;
  float local_54 [2];
  float local_4c;
  int local_48;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  
  *param_1 = f_0;
  IP3 = 1;
  do {
    _DAT_0089f388 = *(float *)(&P0 + IP1 * 4);
    IP11 = 0;
    if (f_1000000 < _DAT_0089f388) {
      IP11 = (int)ROUND(_DAT_0089f388 - f_1000000);
      _DAT_0089f388 = (float)(&ITEM_LEN)[IP11 + IP8];
      if (IP9 < IP11) {
        _DAT_0089f388 = f_0;
      }
    }
    if (IP3 == 1) {
LAB_004b3c66:
      *param_1 = _DAT_0089f388 + *param_1;
      local_24 = 0;
    }
    else if (IP3 == 2) {
      *param_1 = *param_1 - _DAT_0089f388;
      local_20 = 0;
    }
    else if (IP3 == 3) {
      if (_DAT_0089f388 != f_0) {
        *param_1 = *param_1 / _DAT_0089f388;
      }
      local_1c = 0;
    }
    else {
      if (IP3 != 4) goto LAB_004b3c66;
      *param_1 = _DAT_0089f388 * *param_1;
    }
    for (; (IP3 = *(int *)(&DAT_020b909c + IP1 * 4), IP3 == 0xd || (IP3 == 0xe)); IP1 = IP1 + 1) {
      if (IP3 == 0xd) {
        IP14 = 1;
      }
      if (IP3 == 0xe) {
        IP14 = 0;
      }
    }
    local_18 = 0;
    if (IP3 == 0x13) {
      IP12 = (int)ROUND(*param_1);
      IP1 = IP1 + 1;
      IP13 = (int)ROUND(*(float *)(&P0 + IP1 * 4));
      local_54[0] = *(float *)(&P0 + IP1 * 4);
      local_4c = *param_1;
      ffree((float10)local_54[0]);
      local_48 = IP13;
      fVar1 = (float10)FUN_005ff874(&local_4c,local_54);
      *param_1 = (float)(int)ROUND((fVar1 + (float10)f_0_001) * (float10)f_100) / f_100;
      IP3 = *(int *)(&DAT_020b909c + IP1 * 4);
      in_ST0 = extraout_ST1;
LAB_004b3e13:
      ffree(in_ST0);
      return;
    }
    local_14 = 0;
    if (IP3 < 0xf) goto LAB_004b3e13;
    IP3 = IP3 + -0xe;
    IP1 = IP1 + 1;
    local_8 = 0;
  } while( true );
}


