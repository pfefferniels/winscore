// flush_points @ 0054a497 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void flush_points(void)

{
  int iVar1;
  float10 in_ST0;
  unkbyte10 Var2;
  
  iVar1 = COLOR;
  if ((P1 == f_16) && (P14 == f_m1)) {
    P26 = P16;
  }
  if (P26 != f_0) {
    if (DAT_01b11790 == 1) {
      COLOR = DAT_01b11794;
    }
    else {
      if (P26 == f_1) {
        P26 = f_0_92;
      }
      if (P26 < f_1) {
        in_ST0 = (float10)P26 * (float10)f_10000 + (float10)P26 * (float10)f_100;
        P26 = (float)((float10)P26 * (float10)f_1000000 + in_ST0);
      }
      DAT_009a20a8 = (int)ROUND(P26);
      COLOR._3_1_ = SUB41(iVar1,3);
      COLOR._0_3_ = CONCAT12((char)(int)ROUND((float)(DAT_009a20a8 % 100) * f_2_56),
                             CONCAT11((char)(int)ROUND((float)((DAT_009a20a8 % 10000) / 100) *
                                                       f_2_56),
                                      (char)(int)ROUND((float)(DAT_009a20a8 / 10000) * f_2_56)));
      DAT_01b11790 = 1;
      DAT_01b11794 = COLOR;
    }
  }
  ffree(in_ST0);
  Var2 = emit_points();
  ffree(Var2);
  return;
}


