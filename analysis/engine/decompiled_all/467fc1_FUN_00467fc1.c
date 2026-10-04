// FUN_00467fc1 @ 00467fc1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00467fc1(void)

{
  int iVar1;
  
  DAT_00824628 = 1;
  iVar1 = 0x21;
  DAT_00824624 = 1;
  do {
    if (*(float *)(&DAT_01c5891c + DAT_00824624 * 4) != f_98765) {
      *(float *)(&P0 + DAT_00824628 * 4) = (float)DAT_00824624;
      (&P1)[DAT_00824628] = *(float *)(&DAT_01c5891c + DAT_00824624 * 4);
      DAT_00824628 = DAT_00824628 + 2;
      DAT_01c589e8 = DAT_00824624;
    }
    DAT_00824624 = DAT_00824624 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  *(float *)(&P0 + DAT_00824628 * 4) = f_0;
  return;
}


