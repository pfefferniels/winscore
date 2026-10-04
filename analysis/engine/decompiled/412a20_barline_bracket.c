// barline_bracket @ 00412a20 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void barline_bracket(void)

{
  int iVar1;
  float10 in_ST0;
  unkbyte10 Var2;
  float local_3c [11];
  undefined4 local_10;
  undefined4 local_8;
  
  DAT_01f95d40 = DAT_01f95d3c;
  DAT_01f95d50 = _DAT_02052c08 * f_0_15;
  DAT_01f95d48 = X_POS - _DAT_02052c08 * f_12;
  _DAT_01f95d68 = DAT_01f95d50;
  if (IP8 != 2) goto LAB_00412a7f;
  local_10 = 0;
  do {
    in_ST0 = (float10)_DAT_01f95d68;
    _DAT_01f95d68 = (float)-in_ST0;
    DAT_01f95d40 = DAT_01f95d44;
    IP8 = 1;
    local_8 = 0;
LAB_00412a7f:
    local_3c[0] = -(_DAT_01f95d68 * f_33) + DAT_01f95d40;
    ffree(in_ST0);
    Var2 = add_point(&DAT_01f95d48,local_3c,&DAT_0075f3b8);
    iVar1 = 0xc;
    DAT_01f95d28 = 1;
    do {
      DAT_01f95d38 = DAT_01f95d50 * *(float *)(DAT_01f95d28 * 4 + 0x78b260) + DAT_01f95d48;
      DAT_01f95d4c = _DAT_01f95d68 * *(float *)(DAT_01f95d28 * 4 + 0x78b230) + DAT_01f95d40;
      ffree(Var2);
      Var2 = add_point(&DAT_01f95d38,&DAT_01f95d4c,&DAT_0075f3bc);
      DAT_01f95d28 = DAT_01f95d28 + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
  } while (IP8 != 1);
  ffree(Var2);
  return;
}


