// FUN_0046808e @ 0046808e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0046808e(void)

{
  int iVar1;
  
  iVar1 = 0x32;
  DAT_0082462c = 1;
  do {
    *(float *)(&DAT_01c5891c + DAT_0082462c * 4) = f_98765;
    DAT_0082462c = DAT_0082462c + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


