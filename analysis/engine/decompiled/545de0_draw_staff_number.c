// draw_staff_number @ 00545de0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void draw_staff_number(float *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if (f_0 <= X_POS) {
    X_POS = f_m1200;
    if (99 < *param_2) {
      X_POS = f_m1700;
    }
  }
  else {
    X_POS = X_POS - f_1200;
  }
  fVar3 = (float10)staff_level_y(&DAT_00768ef8);
  Y_POS = (float)fVar3;
  DAT_0099f804 = P6;
  P6 = f_1 / *param_1;
  DAT_0099f800 = P5;
  P5 = (float)*param_2;
  IP8 = 0;
  P8 = f_0;
  IP9 = 0;
  DAT_0099f7fc = P26;
  P26 = f_4520;
  IP7 = 0x3f0;
  iVar2 = 0xe;
  for (iVar1 = 1; iVar1 < 0xc; iVar1 = iVar1 + 1) {
    *(float *)(&P0 + iVar2 * 4) = f_0;
    iVar2 = iVar2 + 1;
  }
  iVar2 = 0xe;
  for (iVar1 = 1; iVar1 < 0xc; iVar1 = iVar1 + 1) {
    *(undefined4 *)(&IP0 + iVar2 * 4) = 0;
    iVar2 = iVar2 + 1;
  }
  draw_number(param_2);
  P6 = DAT_0099f804;
  P5 = DAT_0099f800;
  P26 = DAT_0099f7fc;
  DAT_01b11790 = 0;
  return;
}


