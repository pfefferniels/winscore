// FUN_00557e05 @ 00557e05 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00557e05(void)

{
  int iVar1;
  
  thunk_FUN_0054cd13(&P1,&DAT_00769a7c);
  DAT_01a1ae44 = 4;
  for (iVar1 = (int)ROUND((float)(&ITEM_LEN)[DAT_01a1ae40]) + -3; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined4 *)(&P0 + DAT_01a1ae44 * 4) = (&ITEM_LEN)[DAT_01a1ae44 + DAT_01a1ae40];
    DAT_01a1ae44 = DAT_01a1ae44 + 1;
  }
  IP6 = (int)ROUND(P6);
  note_special_head();
  return;
}


