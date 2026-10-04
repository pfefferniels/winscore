// barline_brace @ 00412b93 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void barline_brace(void)

{
  DAT_01f95d4c = ((DAT_01f95d3c - DAT_01f95d44) * f_0_0054945) / STEP;
  DAT_01f95d38 = P6;
  if (P6 == f_0) {
    DAT_01f95d38 = (DAT_01f95d4c - f_1) / f_2 + f_1;
  }
  IP1 = 3;
  IP5 = 5;
  Y_POS = DAT_01f95d44 - STEP * f_21;
  IP10 = 0;
  draw_clef(&X_POS,&Y_POS,&DAT_0075f43c,&DAT_01f95d38,&DAT_01f95d4c);
  return;
}


