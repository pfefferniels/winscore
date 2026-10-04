// FUN_004bf3b8 @ 004bf3b8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bf3b8(void)

{
  undefined1 *puVar1;
  
  DAT_0089f9d0 = 0;
  DAT_0089f9d4 = 0;
  while( true ) {
    _DAT_0089f9cc = thunk_FUN_00597120(&DAT_0089f9e4,&DAT_0089f9e0,DAT_0089f9dc,DAT_0089f9d8);
    if (_DAT_0089f9e4 == 0xd) break;
    if (_DAT_0089f9e4 == 8) {
      if (DAT_0089f9d0 != 0) {
        (&DAT_020b8e9f)[DAT_0089f9d0] = 0x20;
        DAT_0089f9d0 = DAT_0089f9d0 + -1;
      }
    }
    else {
      DAT_0089f9d4 = DAT_0089f9d4 + 1;
      puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_0089f9d0);
      DAT_0089f9d0 = DAT_0089f9d0 + 1;
      *puVar1 = DAT_0089f9e4;
    }
  }
  return;
}


