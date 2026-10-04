// FUN_0043464d @ 0043464d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0043464d(void)

{
  float10 fVar1;
  
  IP9 = 0;
  IP10 = 0;
  IP11 = 0;
  if ((OUTPUT_MODE == 0) && (P13 != f_0)) {
    IP12 = 0xc;
  }
  fVar1 = (float10)staff_level_y(&P46);
  Y_POS = (float)fVar1;
  draw_box();
  return;
}


