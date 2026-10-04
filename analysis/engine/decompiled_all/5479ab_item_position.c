// item_position @ 005479ab (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void item_position(void)

{
  unkbyte10 in_ST0;
  unkbyte10 Var1;
  float10 fVar2;
  
  STEP = (float)(&STAFF_STEP0)[CUR_STAFF];
  X_POS = P3 * f_150;
  if ((DAT_01f9a6f4 != 1) && ((float)RIGHT_LIMIT + f_12100 < X_POS)) {
    ffree(in_ST0);
    Var1 = thunk_FUN_0054a967();
    ffree(Var1);
    in_ST0 = thunk_FUN_0059d020();
  }
  IP3 = (int)ROUND(X_POS);
  _DAT_0099f8b0 = P4;
  if ((IP1 < 4) || (IP1 == 6)) {
    ffree(in_ST0);
    fVar2 = (float10)amod(&DAT_0099f8b0,&DAT_0076907c);
    _DAT_0099f8b0 = (float)fVar2;
  }
  fVar2 = (float10)_DAT_0099f8b0 * (float10)f_7 * (float10)STEP;
  Y_POS = (float)((float10)(int)(&STAFF_Y0)[CUR_STAFF] + fVar2);
  ffree(fVar2);
  return;
}


