// FUN_004d3f5f @ 004d3f5f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004d3f5f(void)

{
  DAT_008a02f4 = (int)ROUND(P2);
  if (DAT_01aadd20 != (&DAT_01aadd20)[DAT_008a02f4]) {
    if ((&DAT_01aadd20)[DAT_008a02f4] == 0) {
      thunk_FUN_004cf166();
    }
    else {
      DAT_01aae32c = (float)(&DAT_01aadd20)[DAT_008a02f4];
      thunk_FUN_004cf0d3();
    }
    DAT_01aadd20 = (&DAT_01aadd20)[DAT_008a02f4];
  }
  return;
}


