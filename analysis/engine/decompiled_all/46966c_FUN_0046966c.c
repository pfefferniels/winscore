// FUN_0046966c @ 0046966c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046966c(void)

{
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var1;
  float10 fVar2;
  float local_3c;
  uint local_38;
  int local_34;
  undefined4 local_c;
  undefined4 local_8;
  
  _DAT_00824b38 = (float)DAT_009c66cc / f_64;
  if (_DAT_00824b38 == f_0) {
    _DAT_00824b38 = f_1;
  }
  ffree(in_ST0);
  Var1 = thunk_FUN_00579770(&DAT_00761cd0,1,&IP1);
  _DAT_00824b34 = (float)(IP1 + -2000);
  local_34 = IP2 + -2000;
  _DAT_00824b30 = (float)local_34;
  ffree(Var1);
  Var1 = thunk_FUN_0055036f(&DAT_00824b2c,&DAT_00824b28,&DAT_00824b24,&DAT_00824b20);
  IP2 = (int)ROUND(_DAT_00824b2c - _DAT_00824b28);
  IP1 = (int)ROUND(_DAT_00824b20 - _DAT_00824b24);
  _DAT_00824b44 = (float)IP2;
  _DAT_00824b40 = (float)IP1;
  if ((_DAT_00824b30 < _DAT_00824b44) || (_DAT_00824b34 < _DAT_00824b40)) {
    IP1 = (int)ROUND(_DAT_00824b40);
    local_38 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    IP2 = (int)ROUND(_DAT_00824b44 + f_3000);
    IP3 = 1000;
    IP4 = 1000;
    ffree(Var1);
    local_34 = IP2;
    Var1 = thunk_FUN_00579770(&DAT_00761ccc,1,&IP1);
    IP1 = 0;
    IP2 = 90000;
    ffree(Var1);
    Var1 = thunk_FUN_00579770(&DAT_00761cc8,1,&IP1);
    ffree(Var1);
    Var1 = thunk_FUN_00579770(&DAT_00761cc4,1,&IP1);
    DAT_00824b1c = IP1;
    DAT_00824b18 = IP2;
    IP1 = 90000;
    IP2 = -90000;
    ffree(Var1);
    Var1 = thunk_FUN_00579770(&DAT_00761cc8,1,&IP1);
    ffree(Var1);
    Var1 = thunk_FUN_00579770(&DAT_00761cc4,1,&IP1);
    _DAT_00824b14 = (float)IP2;
    local_34 = -IP2;
    _DAT_00824b10 = (float)local_34;
    _DAT_00824b0c = (float)IP1;
    DAT_00824b08 = (&ITEM_PTR0)[EDIT_ITEM];
    _DAT_00824b04 = (float)(&ITEM_P3)[DAT_00824b08] * f_150;
    if (f_200 < (float)(&ITEM_P2)[DAT_00824b08]) {
      _DAT_00824b04 = _DAT_00824b04 + f_34050;
    }
    DAT_00824b00 = (float)(&ITEM_P4)[DAT_00824b08];
    _DAT_00824afc = (float)(&ITEM_P1)[DAT_00824b08];
    if ((_DAT_00824afc < f_4) || (_DAT_00824afc == f_6)) {
      ffree(Var1);
      local_3c = DAT_00824b00;
      fVar2 = (float10)FUN_005ff874(&local_3c,&f_100);
      DAT_00824b00 = (float)fVar2;
    }
    if (((_DAT_00824afc == f_8) || (_DAT_00824afc == f_14)) ||
       ((float)(&ITEM_LEN)[DAT_00824b08] < f_4)) {
      DAT_00824b00 = f_3;
    }
    DAT_00824af8 = (int)ROUND((float)(&ITEM_P2)[DAT_00824b08]);
    fVar2 = (float10)DAT_00824b00 * (float10)f_7 * (float10)(float)(&STAFF_STEP0)[DAT_00824af8];
    DAT_00824b00 = (float)((float10)(int)(&STAFF_Y0)[DAT_00824af8] + fVar2);
    IP2 = (int)ROUND(((DAT_00824b00 - _DAT_00824b28) / _DAT_00824b44) * _DAT_00824b10 +
                     _DAT_00824b14);
    _DAT_00824af4 = (_DAT_00824b04 - _DAT_00824b24) / _DAT_00824b40;
    local_38 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    local_34 = (int)ROUND((_DAT_00824b0c + f_2400) * _DAT_00824af4 - f_2400);
    _DAT_00824af0 = _DAT_00824b40 - _DAT_00824b34;
    _DAT_00824aec = _DAT_00824af0 / _DAT_00824b0c;
    _DAT_00824b3c = (float)DAT_00824b1c * _DAT_00824aec;
    _DAT_00824ae8 = _DAT_00824b34 + _DAT_00824b3c;
    if ((_DAT_00824ae8 <= _DAT_00824b04) || (_DAT_00824b04 <= _DAT_00824b3c + f_2400)) {
      IP1 = local_34;
      if ((local_34 < DAT_00824b1c) && (_DAT_00824ae8 < _DAT_00824b40)) {
        IP1 = local_34 + -2000;
      }
      if ((f_m2400 < _DAT_00824b3c) && (DAT_00824b1c < IP1)) {
        IP1 = IP1 + 2000;
      }
    }
    else {
      IP1 = DAT_00824b1c;
      local_c = 0;
    }
    _DAT_00824ae4 = _DAT_00824b44 - _DAT_00824b30;
    _DAT_00824ae0 = _DAT_00824ae4 / _DAT_00824b10;
    DAT_00824b00 = DAT_00824b00 - _DAT_00824b28;
    _DAT_00824adc = ((float)DAT_00824b18 - _DAT_00824b14) * _DAT_00824ae0 + f_1000;
    _DAT_00824ad8 = (_DAT_00824b30 + _DAT_00824adc) - f_1000;
    if ((DAT_00824b00 < _DAT_00824adc) || (_DAT_00824ad8 < DAT_00824b00)) {
      if ((DAT_00824b00 < _DAT_00824adc) && (DAT_00824b00 < _DAT_00824b30)) {
        local_38 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        IP2 = (int)ROUND(_DAT_00824b14);
        local_34 = IP2;
      }
      if ((_DAT_00824ad8 < DAT_00824b00) && (_DAT_00824ae4 < DAT_00824b00)) {
        IP2 = 0;
      }
    }
    else {
      IP2 = DAT_00824b18;
      local_8 = 0;
    }
    ffree(fVar2);
    DAT_00824b18 = IP2;
    DAT_00824b1c = IP1;
    Var1 = thunk_FUN_00579770(&DAT_00761cc8,1,&IP1);
  }
  ffree(Var1);
  return;
}


