// FUN_0056b529 @ 0056b529 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056b529(void)

{
  if (99 < DAT_0078b6a0) {
    DAT_01cadce8 = 0xffffffff;
  }
  X_POS = (float)*(int *)(&DAT_01cafabc + DAT_01cadce0 * 4);
  DAT_01a1c840 = IP1;
  IP1 = 0x10;
  push_words(&DAT_0076a1e0,&P6);
  if (DAT_01cadce4 < 0xa2) {
    if ((OUTPUT_MODE == 2) || (0x4f < DAT_01cadce4 && DAT_01cadce4 < 0x5d)) {
      DAT_01cadce4 = DAT_01cadce4 + 0x820;
    }
    else {
      if (DAT_0078b6a0 != 0x5e) goto LAB_0056b63f;
      DAT_01cadce4 = DAT_01cadce4 + 2000;
    }
  }
  else {
    DAT_01cadce4 = DAT_01cadce4 + 0x7dc;
  }
  P6 = P6 * f_3_5714;
  P7 = P7 * f_3_5714;
LAB_0056b63f:
  _DAT_009a7fc0 = (int)ROUND(P9);
  if (199 < IP2) {
    X_POS = X_POS - f_34050;
  }
  draw_symbol(&X_POS,&Y_POS,&DAT_01cadce4,&P6,&P7,&DAT_01cadce8,&P9,&DAT_009a7fc0);
  if (199 < IP2) {
    X_POS = X_POS + f_34050;
  }
  IP1 = DAT_01a1c840;
  pop_words(&DAT_0076a1e0,&P6);
  return;
}


