// FUN_00559601 @ 00559601 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


longlong __fastcall FUN_00559601(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 8;
  IP3 = 1;
  do {
    if (IP6 < IP3) {
      *(undefined4 *)(&DAT_01a1adfc + IP3 * 4) = 0;
    }
    else {
      *(undefined4 *)(&DAT_01a1adfc + IP3 * 4) =
           *(undefined4 *)(&DAT_0079ee20 + (DAT_0078cd64 + IP3) * 4);
      param_2 = 0;
    }
    IP3 = IP3 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  if ((DAT_0078cd4c == 1) && (IP6 == 6)) {
    DAT_01a1ae00 = 0x48;
  }
  return (ulonglong)param_2 << 0x20;
}


