// FUN_00571d69 @ 00571d69 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00571d69(void)

{
  int iVar1;
  float10 fVar2;
  
  IP2 = 500000;
  IP3 = 0;
  iVar1 = 0x100;
  IP9 = 1;
  do {
    fVar2 = (float10)(int)(&STAFF_Y0)[IP9] + (float10)(float)(&STAFF_STEP0)[IP9] * (float10)f_49;
    IP5 = (int)ROUND((float10)DAT_01be6c44 - fVar2 / (float10)DAT_01be6c4c);
    IP4 = IP5 - DAT_01fbb7ec;
    if (IP4 < 0) {
      IP4 = -IP4;
    }
    if (IP4 <= IP2) {
      IP3 = IP9;
      IP2 = IP4;
      IP6 = IP5;
    }
    IP9 = IP9 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  _DAT_009a8478 = (float)((DAT_01fbb7e8 - DAT_01be6c40) * DAT_01be6c48) / f_150;
  if (_DAT_009a8478 < f_0) {
    _DAT_009a8478 = f_m10;
  }
  if (f_200 < _DAT_009a8478) {
    _DAT_009a8478 = f_210;
  }
  P5 = (((float)(IP6 - DAT_01fbb7ec) * (float)(&STAFF_STEP0)[IP3]) / f_25) / f_3 + f_6;
  ffree(fVar2);
  ffree((float10)DAT_01be6c44);
  return;
}


