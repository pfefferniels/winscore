// note_tails @ 004f06bb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void note_tails(void)

{
  float fVar1;
  int iVar2;
  float10 in_ST0;
  float10 fVar3;
  unkbyte10 Var4;
  unkbyte10 extraout_ST1;
  
  fVar1 = Y_POS;
  DAT_01a9f31c = STEP;
  STEP = DAT_01f95ce0;
  DAT_01a9f30c = Y_POS;
  DAT_01a9f308 = X_POS;
  DAT_01a9f300 = 0x14;
  DAT_01a9f310 = -(DAT_01f95ce0 * f_7);
  DAT_01a9f318 = f_1;
  if (DAT_01f95cec != 2) {
    DAT_01a9f318 = -f_1;
    DAT_01a9f308 = X_POS + DAT_01f95cf0;
    in_ST0 = (float10)DAT_01a9f310;
    DAT_01a9f310 = (float)-in_ST0;
  }
  ffree(in_ST0);
  fVar3 = (float10)amod(&P8,&f_100);
  DAT_01a9f30c = (float)(fVar3 * (float10)DAT_01a9f310 + (float10)fVar1 + (float10)DAT_01a9f310);
  if (1 < DAT_01f95cf4) {
    DAT_01a9f30c = DAT_01a9f30c - DAT_01a9f310 / f_2;
  }
  IP10 = -1;
  DAT_01a9f304 = 1;
  Var4 = extraout_ST1;
  for (iVar2 = DAT_01f95cf4; 0 < iVar2; iVar2 = iVar2 + -1) {
    ffree(Var4);
    Var4 = draw_clef(&DAT_01a9f308,&DAT_01a9f30c,&DAT_01a9f300,&DAT_01f93fc0,&DAT_01a9f318);
    DAT_0078b4e0 = 0x56ce;
    DAT_01a9f30c = DAT_01a9f310 + DAT_01a9f30c + DAT_01a9f310;
    DAT_01a9f304 = DAT_01a9f304 + 1;
  }
  IP10 = 0;
  DAT_0078b4e0 = 0;
  STEP = DAT_01a9f31c;
  ffree(Var4);
  return;
}


