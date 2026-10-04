// FUN_005509e4 @ 005509e4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_005509e4(void)

{
  undefined4 local_18;
  
  thunk_FUN_00579770(&DAT_00769274,1,&IP1);
  if (DAT_009c6ae0 != 1) {
    if (DAT_009c6ae0 == 2) {
      IP2 = IP2 - DAT_01b9d630;
      goto LAB_00550a95;
    }
    if (DAT_009c6ae0 == 3) {
      IP1 = IP1 - DAT_01b9d630;
      goto LAB_00550a95;
    }
    if (DAT_009c6ae0 == 4) {
      IP1 = DAT_01b9d630 + IP1;
      goto LAB_00550a95;
    }
  }
  IP2 = DAT_01b9d630 + IP2;
LAB_00550a95:
  thunk_FUN_00579770(&DAT_00769278,1,&IP1);
  FUN_00549422();
  return local_18;
}


