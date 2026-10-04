// FUN_0054c9b4 @ 0054c9b4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c9b4(int param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int local_10;
  
  local_10 = 0x80;
  DAT_009a23a4 = 1;
  do {
    if (*(char *)(DAT_009a23a4 + param_1 + -1) == '\0') goto LAB_0054ca1a;
    DAT_009a23a4 = DAT_009a23a4 + 1;
    local_10 = local_10 + -1;
  } while (0 < local_10);
  DAT_009a23a4 = 0x80;
LAB_0054ca1a:
  iVar2 = 0x80;
  DAT_009a23a0 = 0x80;
  do {
    cVar1 = *(char *)(DAT_009a23a0 + param_1 + -1);
    if ((('z' < cVar1) || (cVar1 < ' ')) || (DAT_009a23a4 < DAT_009a23a0)) {
      *(undefined1 *)(DAT_009a23a0 + param_1 + -1) = 0x20;
    }
    DAT_009a23a0 = DAT_009a23a0 + -1;
    iVar2 = iVar2 + -1;
  } while (0 < iVar2);
  iVar2 = 0x80;
  DAT_009a23a0 = 0x80;
  do {
    DAT_009a23a8 = *(char *)(DAT_009a23a0 + param_1 + -1);
    if ((' ' < DAT_009a23a8) && (DAT_009a23a8 < 'z')) break;
    DAT_009a23a0 = DAT_009a23a0 + -1;
    iVar2 = iVar2 + -1;
  } while (0 < iVar2);
  *param_3 = DAT_009a23a0;
  *(undefined1 *)(*param_3 + param_1 + -1) = 0x5c;
  return;
}


