// FUN_004a5c0f @ 004a5c0f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a5c0f(void)

{
  int iVar1;
  
  if (DAT_0078b380 != 1) {
    iVar1 = (DAT_01fbb7e8 + 5) / 0x40;
    DAT_01fbb7f8 = iVar1 + 0x3b;
    DAT_01fbb7fc = 0;
    _DAT_01fbb7f4 = 1;
    if (0x1cd < DAT_01fbb7ec) {
      DAT_01fbb7f8 = iVar1 + 0x68;
    }
  }
  return;
}


