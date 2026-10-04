// FUN_00573c5f @ 00573c5f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00573c5f(int *param_1)

{
  int iVar1;
  float10 in_ST0;
  
  if (-1 < *param_1) {
    if (*param_1 != 0) {
      ffree(in_ST0);
      in_ST0 = (float10)draw_items();
      DAT_0078d890 = 0;
      goto LAB_00573ec8;
    }
    if ((DAT_020b8ea2 == 'I') || (DAT_020b8ea2 == 'C')) {
      if (EDIT_ITEM == 0) {
        DAT_0078d890 = 2;
        P1 = f_9;
        P2 = f_1;
        P3 = f_0;
        P6 = f_25 / DAT_02052808;
        P4 = ((f_m24000 - (float)DAT_02052c28) * P6) / f_175;
        P5 = f_1000;
        DAT_01e67948 = NPT;
        ffree(in_ST0);
        in_ST0 = (float10)draw_item();
        NPT = DAT_01e67948;
      }
      goto LAB_00573ec8;
    }
    if (-1 < DAT_0078d890) {
      in_ST0 = (float10)(float)(&STAFF_STEP0)[IP2] * (float10)f_72 - (float10)f_1800;
      _DAT_009a88c4 = (float)((float10)(int)(&STAFF_Y0)[IP2] + in_ST0);
    }
  }
  DAT_01e67944 = (float)DAT_01be6c4c;
  DAT_01e67940 = _DAT_009a88c4 / DAT_01e67944;
  DAT_01e67948 = (int)ROUND((float)DAT_01be6c44 - DAT_01e67940);
  iVar1 = 0xcf;
  DAT_01e6794c = 1;
  do {
    DAT_01fbb790 = (int)(&DAT_01adea20)[DAT_01e6794c] / 10000;
    DAT_01fbb784 = DAT_01e67948 - ((int)(&DAT_01adea20)[DAT_01e6794c] % 10000) / DAT_01be6c4c;
    DAT_01fbb780 = *(int *)(DAT_01e6794c * 4 + 0x1adea1c) / DAT_01be6c48 + DAT_01be6c40;
    DAT_01e6794c = DAT_01e6794c + 2;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  DAT_0078d890 = 1;
LAB_00573ec8:
  ffree(in_ST0);
  return;
}


