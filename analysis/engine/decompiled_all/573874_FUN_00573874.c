// FUN_00573874 @ 00573874 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00573874(void)

{
  float10 fVar1;
  
  DAT_009a88c0 = (int)ROUND(DAT_020b9444);
  DAT_009a88a8 = (int)ROUND(DAT_020b944c);
  DAT_009a88bc = (int)ROUND(DAT_020b9440);
  if ((DAT_009a88bc < 4) || (DAT_009a88bc == 6)) {
    DAT_009a88a8 = DAT_009a88a8 % 100;
    if ((DAT_009a88bc == 1) && ((int)ROUND(DAT_020b9454) < -3)) {
      DAT_0078dd74 = (int)ROUND(DAT_020b945c) % 100;
      if (0 < DAT_0078dd74) {
        DAT_009a88a8 = (-DAT_0078dd74 - (int)ROUND(DAT_020b9454) % 10) * 2 + 3;
      }
    }
  }
  DAT_0078dd70 = 0;
  if (DAT_009a88bc == 2) {
    DAT_009a88b4 = (int)ROUND(DAT_020b9450);
    if ((DAT_009a88b4 < -5) || (7 < DAT_009a88b4)) {
      DAT_009a88b4 = -5;
    }
    DAT_0078dd74 = (&DAT_0078dd8c)[DAT_009a88b4];
  }
  else {
    if (DAT_009a88bc == 0xe) {
      DAT_009a88a8 = 3;
      goto LAB_00573b99;
    }
    if (DAT_009a88bc == 6) {
      DAT_009a88b0 = (int)ROUND(ABS(DAT_020b9458));
      if (DAT_009a88b0 < 0x14) {
        DAT_0078dd74 = 6;
        DAT_0078dd70 = 2;
      }
      else {
        DAT_0078dd74 = -7;
      }
    }
    else {
      DAT_0078dd74 = *(int *)(&DAT_0078dda8 + DAT_009a88bc * 4);
      if (DAT_009a88bc == 5) {
        DAT_009a88b0 = (int)ROUND(DAT_020b945c);
        if (DAT_009a88b0 == -1) {
          DAT_0078dd70 = 1;
        }
        else if (DAT_009a88b0 == -2) {
          DAT_0078dd70 = 3;
        }
      }
      else if (DAT_009a88bc == 8) {
        DAT_009a88a8 = 2;
        goto LAB_00573b99;
      }
    }
  }
  DAT_009a88a8 = DAT_0078dd74 + DAT_009a88a8;
LAB_00573b99:
  DAT_009a88b8 = (int)ROUND((float)DAT_01be6c44 -
                            ((float)(int)(&STAFF_Y0)[DAT_009a88c0] +
                            (float)DAT_009a88a8 * f_7 * (float)(&STAFF_STEP0)[DAT_009a88c0]) /
                            (float)DAT_01be6c4c);
  fVar1 = (((float10)DAT_0078dd70 + (float10)DAT_020b9448) * (float10)f_150) / (float10)DAT_01be6c48
  ;
  DAT_009a88a8 = (int)ROUND((float10)DAT_01be6c40 + fVar1);
  ffree(fVar1);
  return;
}


