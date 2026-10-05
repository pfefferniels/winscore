// FUN_004a07b1 @ 004a07b1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004a07b1(void)

{
  int iVar1;
  
  iVar1 = IP5;
  if (((IP8 < 0x15) && (0 < IP7)) && (IP7 < 0x49)) {
    DAT_00838a78 = IP5;
    if (IP5 != -5) {
      IP5 = -1;
    }
    if (IP8 < 1) {
      IP8 = 1;
    }
    DAT_00838a74 = IP8;
    if (iVar1 == -5) {
      IP9 = 0;
    }
    if (DAT_01c5b1e0 == 0) {
      load_guitar_dat();
    }
    if ((IP9 < 0) || (4 < IP9)) {
      IP9 = 0;
    }
    DAT_00838a70 = IP9 + 1;
    if (5 < DAT_00838a70) {
      DAT_00838a70 = 1;
    }
    DAT_00838a6c = IP7 % 10;
    if (2 < DAT_00838a6c) {
      DAT_00838a6c = 0;
    }
    if (DAT_00838a6c != 0) {
      DAT_00838a6c = DAT_00838a6c * 2 + -3;
    }
    iVar1 = (IP7 * 2) / 10;
    DAT_00838a68 = iVar1 + -1;
    if (6 < DAT_00838a68) {
      DAT_00838a68 = iVar1 + -2;
    }
    DAT_00838a64 = DAT_00838a6c + DAT_00838a68;
    if (DAT_00838a64 < 1) {
      DAT_00838a64 = 0xc;
    }
    if (0xc < DAT_00838a64) {
      DAT_00838a64 = 1;
    }
    IP7 = -DAT_00838a64;
    IP8 = DAT_00838a74;
    P13 = *(float *)(&DAT_01c5c37c + DAT_00838a70 * 4 + DAT_00838a74 * 0x14 + DAT_00838a64 * 400);
    IP12 = *(int *)(&DAT_01c5d63c + DAT_00838a70 * 4 + DAT_00838a74 * 0x14 + DAT_00838a64 * 400);
    if (P18 == f_0) {
      P18 = (float)*(int *)(&DAT_01c5e8fc +
                           DAT_00838a70 * 4 + DAT_00838a74 * 0x14 + DAT_00838a64 * 400);
    }
    if ((IP12 % 100 != 0) && (IP5 != -5)) {
      IP5 = -2;
    }
    if (DAT_00838a78 == -6) {
      IP7 = 0;
    }
  }
  return;
}


