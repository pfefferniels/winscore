// FUN_004a0729 @ 004a0729 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004a0729(void)

{
  char *pcVar1;
  
  if (9 < DAT_01f93e80) {
    pcVar1 = (char *)((int)&DAT_020b8ea0 + DAT_01cb1068);
    DAT_01cb1068 = DAT_01cb1068 + 1;
    *pcVar1 = (char)(DAT_01f93e80 / 10) + '0';
  }
  pcVar1 = (char *)((int)&DAT_020b8ea0 + DAT_01cb1068);
  DAT_01cb1068 = DAT_01cb1068 + 1;
  *pcVar1 = (char)(DAT_01f93e80 % 10) + '0';
  return;
}


