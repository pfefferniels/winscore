// FUN_00549825 @ 00549825 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00549825(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  iVar1 = 0x200;
  DAT_009a1e3c = 1;
  do {
    if ((&DAT_020b8e9f)[DAT_009a1e3c] == '\0') goto LAB_00549884;
    DAT_009a1e3c = DAT_009a1e3c + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  DAT_020b90a0 = 0;
LAB_00549884:
  _DAT_009a1e40 = DAT_009a1e3c;
  DAT_009a1e38 = thunk_FUN_00596cc0(&DAT_020b8ea0,&DAT_020b90a0,DAT_009a1e3c,DAT_009a1e3c);
  if (DAT_009a1e38 == -1) {
    FUN_005f33c9(&stack0xfffffffc,0x5498ed);
    FUN_005f34d1(puVar2,0x549908);
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  else {
    FUN_0054943a();
  }
  return;
}


