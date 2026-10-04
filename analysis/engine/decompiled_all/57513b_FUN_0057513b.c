// FUN_0057513b @ 0057513b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_0057513b(void)

{
  undefined4 local_10;
  
  LOAD_I = LOAD_I + 1;
  load_item_header();
  if ((LOAD_STAFF < DAT_01c585e0) || (DAT_01c585e4 < LOAD_STAFF)) {
    local_10 = 1;
  }
  else {
    local_10 = 0;
  }
  return local_10;
}


