// barline_stroke @ 00412699 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void barline_stroke(void)

{
  add_point(&DAT_01f95d58,&DAT_01f95d44,&DAT_0075f3c0);
  add_point(&DAT_01f95d58,&DAT_01f95d3c,&DAT_0075f3bc);
  if (OUTPUT_MODE == -1) {
    DAT_01f95d54 = _DAT_0078b480 + DAT_01f95d58;
    add_point(&DAT_01f95d54,&DAT_01f95d44,&DAT_0075f3c0);
    add_point(&DAT_01f95d54,&DAT_01f95d3c,&DAT_0075f3bc);
  }
  return;
}


