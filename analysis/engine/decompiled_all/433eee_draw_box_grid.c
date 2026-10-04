// draw_box_grid @ 00433eee (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void draw_box_grid(void)

{
  int iVar1;
  unkbyte10 in_ST0;
  unkbyte10 Var2;
  float10 fVar3;
  
  ffree(in_ST0);
  Var2 = push_words(&DAT_00760144,&P1);
  iVar1 = IP7;
  DAT_007f7518 = IP7;
  IP7 = 0;
  if (iVar1 == 0) {
    DAT_007f7518 = 3;
  }
  IP19 = DAT_007f7518;
  DAT_007f7514 = P6;
  if (P6 == f_0) {
    DAT_007f7514 = f_1;
  }
  P18 = DAT_007f7514;
  IP5 = 1;
  P6 = DAT_007f7514 * f_8;
  P7 = f_0;
  P8 = P10;
  if (OUTPUT_MODE != 0) {
    P8 = P10 + f_1;
  }
  P9 = f_0;
  IP18 = IP9;
  IP9 = 0;
  IP20 = IP8;
  DAT_007f7510 = X_POS;
  DAT_007f750c = Y_POS;
  if (OUTPUT_MODE == 0) {
    IP12 = 8;
  }
  DAT_007f7508 = IP8;
  P46 = P4;
  IP8 = 1;
  ffree(Var2);
  DAT_007f7514 = (STEP * DAT_007f7514) / f_25;
  Var2 = FUN_0043464d();
  P8 = f_0;
  IP20 = DAT_007f7508;
  ffree(Var2);
  fVar3 = (float10)push_words(&DAT_00760144,&P1);
  IP10 = 0;
  P46 = P15 + P3;
  if (DAT_007f7518 != 3) {
    P47 = DAT_007f7514 * f_4_66;
    X_POS = DAT_007f7510 - P47 * f_150;
    P6 = P47 + P46;
    P49 = f_0;
    goto LAB_0043412e;
  }
  P49 = P18 * f_1_35;
  P47 = DAT_007f7514 * f_4_4;
  while( true ) {
    X_POS = DAT_007f7510 - P47 * f_150;
    P6 = P47 + P46;
    ffree(fVar3);
    FUN_004345ee();
    fVar3 = (float10)P49;
    P49 = (float)-fVar3;
LAB_0043412e:
    ffree(fVar3);
    fVar3 = (float10)FUN_004345ee();
    if (DAT_007f7518 != 4) break;
    DAT_007f7518 = 0;
    P21 = DAT_007f7514 * f_4_05;
    P49 = P18 * f_1_95;
    P47 = DAT_007f7514 * f_4_08;
  }
  ffree(fVar3);
  Var2 = pop_words(&DAT_00760144,&P1);
  Y_POS = DAT_007f750c;
  DAT_007f7504 = P4;
  P13 = f_1;
  P6 = P18 * f_1_4;
  if (IP19 == 4) {
    P46 = P4 - P18 * f_2_95;
    P49 = P18 * f_1_98;
    X_POS = DAT_007f7510;
    if (IP20 / 1000 != 0) {
      ffree(Var2);
      Var2 = FUN_0043464d();
    }
    P46 = P49 + P46;
    if ((IP20 % 1000) / 100 != 0) {
      ffree(Var2);
      Var2 = FUN_0043464d();
    }
    P46 = P49 + P46;
    if ((IP20 % 100) / 10 != 0) {
      ffree(Var2);
      Var2 = FUN_0043464d();
    }
    P46 = P49 + P46;
    if (IP20 % 10 != 0) {
      ffree(Var2);
      Var2 = FUN_0043464d();
    }
    if (IP18 == 0) goto LAB_004345d2;
    P46 = DAT_007f7504;
  }
  else {
    if (IP19 == 2) {
      P6 = P18 * f_1_8;
      P19 = P18 * f_2;
      X_POS = DAT_007f7510;
      if (IP20 / 10 != 0) {
        P46 = P4 - P19;
        ffree(Var2);
        Var2 = FUN_0043464d();
      }
      if (IP20 % 10 != 0) {
        P46 = P19 + P4;
        ffree(Var2);
        Var2 = FUN_0043464d();
      }
      goto LAB_004345d2;
    }
    X_POS = DAT_007f7510;
    DAT_007f750c = P18 * f_2_55;
    if (IP20 / 100 != 0) {
      P46 = P4 - DAT_007f750c;
      ffree(Var2);
      Var2 = FUN_0043464d();
    }
    if (IP20 % 10 != 0) {
      P46 = DAT_007f750c + DAT_007f7504;
      ffree(Var2);
      Var2 = FUN_0043464d();
    }
    P46 = DAT_007f7504;
    if (((IP20 % 100) / 10 != 0) || ((IP18 % 100) / 10 != 0)) {
      ffree(Var2);
      Var2 = FUN_0043464d();
    }
  }
  P19 = f_2_875;
  if ((IP19 == 4) || ((IP20 % 100) / 10 == 0 && IP19 == 3)) {
    P19 = f_2_45;
  }
  P19 = DAT_007f7514 * P19 * f_150;
  if (IP18 % 10 != 0) {
    X_POS = P19 + DAT_007f7510;
    ffree(Var2);
    Var2 = FUN_0043464d();
  }
  if (IP18 / 100 != 0) {
    X_POS = DAT_007f7510 - P19;
    ffree(Var2);
    Var2 = FUN_0043464d();
  }
LAB_004345d2:
  ffree(Var2);
  Var2 = pop_words(&DAT_00760144,&P1);
  ffree(Var2);
  return;
}


