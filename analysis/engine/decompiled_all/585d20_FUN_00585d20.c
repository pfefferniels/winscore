// FUN_00585d20 @ 00585d20 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00585d20(void)

{
  float fVar1;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var2;
  float10 fVar3;
  float local_5c;
  uint local_58;
  int local_54;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_01be6cd8 = 0;
  DAT_009a9218 = PAPER;
  PAPER = 0;
  ffree(in_ST0);
  Var2 = thunk_FUN_00579770(&DAT_0076acfc,1,&IP1);
  _DAT_009a9214 = (float)IP1;
  _DAT_009a9210 = (float)IP2;
  if (DAT_020b8ea0._1_1_ == 'Z') {
    P2 = f_2;
    DAT_009a920c = EDIT_ITEM;
    ffree(Var2);
    Var2 = thunk_FUN_0058c344();
    P2 = f_0;
    EDIT_ITEM = DAT_009a920c;
    DAT_020b8ea0._1_1_ = 'Z';
  }
  if ((DAT_0205274c == 0) && (DAT_00790c10 != DAT_009c66cc)) {
    DAT_009a9208 = P2;
    DAT_020b8ea0._0_1_ = DAT_0076acf0;
    P2 = (float)DAT_009c66cc / f_64;
    DAT_009a920c = EDIT_ITEM;
    ffree(Var2);
    Var2 = thunk_FUN_0058c344();
    DAT_01e66cb0 = 0;
    P2 = DAT_009a9208;
    DAT_00790c10 = DAT_009c66cc;
    EDIT_ITEM = DAT_009a920c;
  }
  _DAT_009a9204 = 1;
  ffree(Var2);
  Var2 = fit_view(&DAT_009a9204,&DAT_009a9234,&DAT_009a9230,&DAT_009a922c,&DAT_009a9228);
  DAT_009a9234 = DAT_009a9234 + 27000;
  DAT_009a9230 = DAT_009a9230 + 27000;
  IP2 = DAT_009a9234 - DAT_009a9230;
  IP1 = DAT_009a9228 - _DAT_009a922c;
  DAT_009a9224 = (float)IP2;
  DAT_009a9220 = (float)IP1;
  _DAT_009a9200 = (float)DAT_009c66cc / f_64;
  if (_DAT_009a9200 == f_0) {
    _DAT_009a9200 = f_1;
  }
  _DAT_009a91fc = f_3000;
  ffree(Var2);
  Var2 = thunk_FUN_00579770(&DAT_0076ace0,1,&IP1);
  _DAT_009a91f8 = (float)IP1;
  _DAT_009a91f4 = (float)IP2;
  if (DAT_020b9440 == f_0) {
    DAT_009a920c = (&ITEM_PTR0)[EDIT_ITEM];
    DAT_009a91f0 = (float)(&ITEM_P3)[DAT_009a920c] * f_150;
    if (f_200 < (float)(&ITEM_P2)[DAT_009a920c]) {
      DAT_009a91f0 = DAT_009a91f0 + f_34050;
    }
    DAT_009a91ec = (float)(&ITEM_P4)[DAT_009a920c];
    _DAT_009a91e8 = (float)(&ITEM_P1)[DAT_009a920c];
    fVar1 = (float)(&ITEM_P2)[DAT_009a920c];
  }
  else {
    DAT_009a91f0 = DAT_020b9448 * f_150;
    if (f_200 < DAT_020b9444) {
      DAT_009a91f0 = DAT_009a91f0 + f_34050;
    }
    DAT_009a91ec = DAT_020b944c;
    _DAT_009a91e8 = DAT_020b9440;
    fVar1 = DAT_020b9444;
  }
  local_54 = (int)ROUND(fVar1);
  local_58 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_009a91e4 = local_54;
  if ((_DAT_009a91e8 < f_4) || (_DAT_009a91e8 == f_6)) {
    local_5c = DAT_009a91ec;
    ffree(Var2);
    fVar3 = (float10)FUN_005ff874(&local_5c,&DAT_0076acc8);
    DAT_009a91ec = (float)fVar3;
  }
  if (((_DAT_009a91e8 == f_8) || (_DAT_009a91e8 == f_14)) ||
     ((float)(&ITEM_LEN)[DAT_009a920c] < f_4)) {
    DAT_009a91ec = f_3;
  }
  fVar3 = (float10)DAT_009a91ec * (float10)f_7 * (float10)(float)(&STAFF_STEP0)[DAT_009a91e4];
  DAT_009a91ec = (float)((float10)(int)(&STAFF_Y0)[DAT_009a91e4] + fVar3 + (float10)f_27000);
  IP1 = 900000;
  IP2 = -900000;
  ffree(fVar3);
  Var2 = thunk_FUN_00579770(&DAT_0076acb0,1,&IP1);
  ffree(Var2);
  Var2 = thunk_FUN_00579770(&DAT_0076acfc,1,&IP1);
  _DAT_009a91e0 = (float)IP2;
  _DAT_009a91dc = (float)-IP2;
  _DAT_009a91d8 = (float)IP1;
  IP1 = (int)ROUND(_DAT_009a9214);
  local_58 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  IP2 = (int)ROUND(_DAT_009a9210);
  ffree(Var2);
  local_54 = IP2;
  thunk_FUN_00579770(&DAT_0076acb0,1,&IP1);
  _DAT_009a91e8 = DAT_009a9220 - _DAT_009a91f8;
  if (_DAT_009a91e8 < f_0) {
    _DAT_009a91e8 = f_0;
  }
  _DAT_009a91d0 = ((_DAT_009a9214 / _DAT_009a91d8) * _DAT_009a91e8 + _DAT_009a91f8) - f_2600;
  _DAT_009a91cc = _DAT_009a91e8 * (_DAT_009a9214 / _DAT_009a91d8) + f_2400;
  if (DAT_009a91f0 <= _DAT_009a91cc) {
    local_2c = 0;
LAB_0058632f:
    DAT_009a9208 = DAT_009a91f0;
    _DAT_009a91c8 = DAT_009a9220;
    DAT_009a91d4 = DAT_009a91f0 / DAT_009a9220;
    if (f_0_3 <= DAT_009a91d4) {
      if (f_0_7 < DAT_009a91d4) {
        DAT_009a91d4 = f_1;
      }
    }
    else {
      DAT_009a91d4 = f_0;
    }
    DAT_009a9238 = _DAT_009a91d8 * DAT_009a91d4;
    if (_DAT_009a9214 < DAT_009a9238) {
      DAT_009a9238 = DAT_009a9238 + f_1000;
    }
    if (DAT_009a9238 < _DAT_009a9214) {
      DAT_009a9238 = DAT_009a9238 - f_1000;
    }
    IP1 = (int)ROUND(DAT_009a9238);
    _DAT_009a9214 = DAT_009a9238;
  }
  else {
    local_30 = 0;
    if (_DAT_009a91d0 <= DAT_009a91f0) goto LAB_0058632f;
    local_28 = 0;
  }
  DAT_009a91d4 = f_1 - _DAT_009a9210 / _DAT_009a91e0;
  _DAT_009a91e8 = DAT_009a9224 - _DAT_009a91f4;
  if (_DAT_009a91e8 < f_0) {
    _DAT_009a91e8 = f_0;
  }
  fVar3 = (float10)DAT_009a91d4 * (float10)_DAT_009a91e8 + (float10)_DAT_009a91f4;
  _DAT_009a91e8 = (float)((float10)DAT_009a9230 + fVar3);
  _DAT_01a1ac90 = _DAT_009a91e8 - _DAT_009a91fc;
  _DAT_01a1ac94 = (_DAT_009a91e8 - _DAT_009a91f4) + _DAT_009a91fc;
  if (DAT_009a91ec <= _DAT_01a1ac94) {
    local_20 = 0;
  }
  else {
    local_24 = 0;
    if (DAT_009a91ec < _DAT_01a1ac90) {
      local_1c = 0;
      IP1 = (int)ROUND(_DAT_009a9214);
      local_58 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      IP2 = (int)ROUND(_DAT_009a9210);
      ffree(fVar3);
      local_54 = IP2;
      fVar3 = (float10)thunk_FUN_00579770(&DAT_0076acb0,1,&IP1);
      local_14 = 0;
      goto LAB_00586777;
    }
    local_18 = 0;
  }
  DAT_009a9208 = (float)DAT_009a9234 - DAT_009a91ec;
  _DAT_009a91c8 = DAT_009a9224;
  local_58 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  _DAT_009a91c4 = (int)ROUND((DAT_009a9208 / DAT_009a9224) * f_10);
  DAT_009a91d4 = (float)_DAT_009a91c4 / f_10;
  if ((f_0_5 < DAT_009a91d4) && (DAT_009a91d4 < f_1)) {
    DAT_009a91d4 = DAT_009a91d4 + f_0_05;
  }
  if (f_0_1 <= DAT_009a91d4) {
    if (f_0_9 < DAT_009a91d4) {
      DAT_009a91d4 = f_1;
    }
  }
  else {
    DAT_009a91d4 = f_0;
  }
  local_54 = _DAT_009a91c4;
  if ((_DAT_007a04dc != f_1) || (DAT_009a91d4 <= f_0_8)) {
    if ((_DAT_007a04dc != f_0) || (f_0_2 <= DAT_009a91d4)) {
      _DAT_007a04dc = DAT_009a91d4;
      DAT_009a920c = EDIT_ITEM;
      EDIT_ITEM = 0;
      _DAT_0078cad0 = DAT_009a91d4;
      ffree(fVar3);
      Var2 = thunk_FUN_00535d00(&DAT_0076ac7c);
      _DAT_0078cad0 = f_99;
      EDIT_ITEM = DAT_009a920c;
      local_58 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      IP1 = (int)ROUND(_DAT_009a9214);
      ffree(Var2);
      local_54 = IP1;
      fVar3 = (float10)thunk_FUN_00579770(&DAT_0076acb0,1,&IP1);
      local_8 = 0;
    }
    else {
      local_c = 0;
    }
  }
  else {
    local_10 = 0;
  }
LAB_00586777:
  PAPER = DAT_009a9218;
  ffree(fVar3);
  Var2 = thunk_FUN_00579770(&DAT_0076acfc,1,&IP1);
  _DAT_009a91c0 = (float)IP1;
  _DAT_009a91bc = (float)IP2;
  DAT_01be6cd8 = 0xffffffff;
  ffree(Var2);
  return;
}


