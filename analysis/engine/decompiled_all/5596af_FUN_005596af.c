// FUN_005596af @ 005596af (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


longlong __fastcall FUN_005596af(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 5;
  IP3 = 1;
  do {
    if (IP3 < 6) {
      *(undefined4 *)(&DAT_01a1adfc + IP3 * 4) = *(undefined4 *)(IP3 * 4 + 0x79ee40);
      param_2 = 0;
    }
    else {
      *(undefined4 *)(&DAT_01a1adfc + IP3 * 4) = 0;
    }
    IP3 = IP3 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return (ulonglong)param_2 << 0x20;
}


