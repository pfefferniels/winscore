// FUN_00470fc8 @ 00470fc8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00470fc8(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0078b4f0 < 1) {
    DAT_01c585d4 = DAT_01c585dc;
    DAT_01c585d0 = DAT_01c585cc;
  }
  else {
    DAT_01c585d4 = DAT_01c585cc;
    DAT_01c585d0 = 1;
  }
  DAT_01c585c4 = 0;
  iVar2 = -DAT_0078b4f0;
  iVar1 = ((DAT_01c585d0 - DAT_01c585d4) + iVar2) / iVar2;
  DAT_01c585c8 = DAT_01c585d4;
  do {
    if (iVar1 < 1) {
      return;
    }
    if (DAT_01c585c4 == 0) {
      if (*(char *)(param_1 + -1 + DAT_01c585c8) == ' ') {
        DAT_01c585c4 = DAT_0078b4f0 + DAT_01c585c8;
      }
    }
    else if (*(char *)(param_1 + -1 + DAT_01c585c8) != ' ') {
      return;
    }
    DAT_01c585c8 = iVar2 + DAT_01c585c8;
    iVar1 = iVar1 + -1;
  } while( true );
}


