// FUN_0052fef6 @ 0052fef6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_0052fef6(void)

{
  undefined4 local_8;
  
  DAT_0099a44c = DAT_01b9d630;
  if (4 < DAT_009c6ae0) {
    DAT_0099a44c = DAT_01b9d630 * 3;
  }
  if (DAT_009c6ae0 % 2 == 0) {
    DAT_0099a44c = -DAT_0099a44c;
  }
  if (((DAT_009c6ae0 == 6) || (DAT_009c6ae0 < 3)) || (DAT_009c6ae0 == 5)) {
    VIEW_DY = DAT_0099a44c + VIEW_DY;
  }
  else {
    VIEW_DX = DAT_0099a44c + VIEW_DX;
  }
  draw_items();
  thunk_FUN_00549422();
  return local_8;
}


