// FUN_004b63cd @ 004b63cd (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b63cd(float *param_1,float *param_2)

{
  int iVar1;
  
  DAT_01c585d0 = *param_2 - *param_1;
  if (DAT_01c585d0 != f_0) {
    DAT_01c585cc = (_DAT_01b11764 + DAT_01c585d0) / DAT_01c585d0;
    if (DAT_01c585cc <= f_0_2) {
      DAT_01c585cc = f_1;
    }
    DAT_01c585d0 = *param_1;
    DAT_01c585d4 = *param_2;
    DAT_01c585c0 = 1;
    for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_01c585c4 = (&DAT_020492a4)[DAT_01c585c0];
      if (DAT_01c585c4 < 0) {
        DAT_01c585c4 = -DAT_01c585c4;
      }
      if (((DAT_01c585c4 != 0) &&
          (DAT_01c585c8 = (float)(&ITEM_LEN)[DAT_01c585c4], DAT_01c585d0 <= DAT_01c585c8)) &&
         (DAT_01c585c8 <= DAT_01c585d4)) {
        DAT_0089f48c = (DAT_01c585c8 - DAT_01c585d0) * DAT_01c585cc + *param_1;
        if (DAT_0089f48c < DAT_01b11760) {
          DAT_0089f48c = DAT_01b11760;
        }
        (&ITEM_LEN)[DAT_01c585c4] = DAT_0089f48c;
        (&DAT_020492a4)[DAT_01c585c0] = 0;
      }
      DAT_01c585c0 = DAT_01c585c0 + 1;
    }
    DAT_01b11760 = *param_1 + f_0_2;
  }
  return;
}


