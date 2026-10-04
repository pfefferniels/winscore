// note_accidental @ 004f2f31 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void note_accidental(void)

{
  undefined2 in_FPUControlWord;
  float10 fVar1;
  uint local_34;
  int local_30;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((5 < DAT_01a9f364) || (IP5 / 100 == 1)) {
    DAT_01a9f364 = DAT_01a9f364 + 0x86;
  }
  fVar1 = (float10)amod(&P5,&f_1);
  _DAT_008d1a14 = (float)fVar1;
  if (_DAT_008d1a14 == f_0) {
    local_c = 0;
  }
  else {
    if (f_0_9 < _DAT_008d1a14) {
      _DAT_008d1a14 = f_0_9 - _DAT_008d1a14;
    }
    _DAT_008d1a14 = _DAT_008d1a14 * f_60 * DAT_01f95ce0;
  }
  if ((P10 == f_10) && (DAT_02091d04 != 0x6e)) {
    _DAT_008d1a14 = _DAT_01c585f0 + _DAT_008d1a14;
  }
  _DAT_008d1a14 = X_POS - _DAT_008d1a14;
  DAT_02091d04 = 0;
  DAT_008d1a10 = STEP;
  STEP = DAT_01f95ce0;
  _DAT_008d1a0c = P29;
  if (P29 == f_0) {
    _DAT_008d1a0c = f_1;
  }
  if (OUTPUT_MODE < 0) {
    local_34 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_02091cfc = (int)ROUND(P28);
    local_30 = DAT_02091cfc;
    if (DAT_02091cfc != 0) {
      thunk_FUN_004d4ed2(&DAT_02091cfc);
    }
  }
  else {
    local_8 = 0;
  }
  local_34 = DAT_01a9f364 + 5;
  draw_clef(&DAT_008d1a14,&Y_POS,&local_34,&DAT_008d1a0c,&DAT_008d1a0c);
  if (DAT_02091cfc != 0) {
    thunk_FUN_004d4f3f();
  }
  DAT_02091cfc = 0;
  STEP = DAT_008d1a10;
  return;
}


