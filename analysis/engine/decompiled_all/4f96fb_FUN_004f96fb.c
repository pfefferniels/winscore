// FUN_004f96fb @ 004f96fb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004f96fb(void)

{
  int iVar1;
  int local_8;
  
  DAT_01c4c840 = 0x1900;
  iVar1 = 0x1c20;
  DAT_01c4c828 = 1;
  do {
    *(undefined1 *)((int)&DAT_01c4ef40 + DAT_01c4c828 + 3) = 0x20;
    DAT_01c4c828 = DAT_01c4c828 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  local_8 = 1000;
  DAT_01c4c828 = 1;
  do {
    *(undefined4 *)(&DAT_01a76abc + DAT_01c4c828 * 4) = 0;
    *(undefined4 *)(&DAT_01a77a5c + DAT_01c4c828 * 4) = 0;
    DAT_01c4c828 = DAT_01c4c828 + 1;
    local_8 = local_8 + -1;
  } while (0 < local_8);
  DAT_01c5860c = 0;
  DAT_01ba0d84 = 0;
  DAT_01a75b20 = 0;
  DAT_01ba0d88 = f_0;
  DAT_01ba0d8c = f_0;
  return;
}


