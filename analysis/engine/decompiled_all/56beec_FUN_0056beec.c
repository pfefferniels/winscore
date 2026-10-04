// FUN_0056beec @ 0056beec (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056beec(void)

{
  int iVar1;
  int iVar2;
  
  _DAT_009a8088 = STEP * P6;
  _DAT_009a8084 = STEP * P7;
  _DAT_009a8080 = *(float *)(&DAT_01cadd3c + DAT_01cadce0 * 4) - _DAT_009a8088 * f_40;
  _DAT_009a807c = Y_POS - _DAT_009a8084 * f_26;
  DAT_009a8078 = (int)*(short *)(&DAT_01adfb40 + IP5 * 2);
  for (iVar1 = (int)*(short *)(&DAT_01adfb42 + IP5 * 2) - (int)*(short *)(&DAT_01adfb40 + IP5 * 2);
      0 < iVar1; iVar1 = iVar1 + -1) {
    iVar2 = (int)*(short *)(&DAT_01adfbcc + DAT_009a8078 * 2);
    _DAT_009a8070 = iVar2 / 10000;
    _DAT_009a806c = (iVar2 % 10000) / 100;
    DAT_009a8074 = iVar2 % 100;
    _DAT_009a8068 = (float)_DAT_009a806c * _DAT_009a8088 + _DAT_009a8080;
    _DAT_009a8064 = (float)DAT_009a8074 * _DAT_009a8084 + _DAT_009a807c;
    add_point(&DAT_009a8068,&DAT_009a8064,&DAT_009a8070);
    DAT_009a8078 = DAT_009a8078 + 1;
  }
  return;
}


