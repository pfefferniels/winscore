// FUN_00459c07 @ 00459c07 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00459c07(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  float10 fVar3;
  unkbyte10 Var4;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  
  puVar2 = &stack0xfffffffc;
  iVar1 = *param_1;
  DAT_007fedd8 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    (&PT_X0)[DAT_007fedd8] = ((&PT_X0)[DAT_007fedd8] + -8000) / 100;
    (&PT_Y0)[DAT_007fedd8] = ((&PT_Y0)[DAT_007fedd8] + 19000) / 100;
    DAT_007fedd8 = DAT_007fedd8 + 1;
  }
  DAT_007fedd4 = *param_1;
  _DAT_007feddc = 5;
  _DAT_007fede0 = 0x1e;
  ffree(in_ST0);
  DAT_007fedd0 = thunk_FUN_0059ae50(&DAT_007feddc);
  Var4 = extraout_ST0;
  if (DAT_007fedd0 == 2) goto LAB_0045a57a;
  DAT_01c00568 = (float)_DAT_007feddc;
  if (DAT_01c00568 == f_0) {
    DAT_01c00568 = f_5;
  }
  _DAT_007fedcc = (float)_DAT_007fede0 / f_100;
  DAT_007fedc8 = 0;
  DAT_007fedc4 = 0;
  if (_DAT_007fedcc == f_0) {
LAB_00459db2:
    DAT_01bf49e0 = DAT_01fd3f80;
    DAT_01bf49e4 = DAT_02004cc0;
    DAT_007fedc8 = 1;
  }
  else {
    _DAT_007fedcc = (float)DAT_007fedd4 * _DAT_007fedcc;
    ffree(extraout_ST0);
    puVar2 = &stack0xfffffffc;
    fVar3 = (float10)FUN_005ff381(&stack0xfffffffc,0x459d7f);
    *(int *)(puVar2 + -0x9c) = (int)ROUND(fVar3);
    iVar1 = *(int *)(puVar2 + -0x9c);
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    DAT_007fedc0 = iVar1 + 1;
    Var4 = extraout_ST1;
    if (DAT_007fedc0 < 2) {
      *(undefined4 *)(puVar2 + -0x6c) = 0;
      goto LAB_00459db2;
    }
    DAT_007fedbc = DAT_007fedd4 - DAT_007fedc0;
    DAT_007fedc4 = 1;
    _DAT_007fedb8 = f_1 / _DAT_007fedcc;
    *(undefined4 *)(puVar2 + -0x68) = 0;
  }
  DAT_01fbb8e0 = 2;
  DAT_007fedb0 = (float)DAT_01fd3f80;
  DAT_007fedac = (float)DAT_02004cc0;
  DAT_007feda8 = (float)DAT_01fd3f84;
  DAT_007feda4 = (float)DAT_02004cc4;
  _DAT_01c00560 = DAT_007feda8 - DAT_007fedb0;
  _DAT_01c00564 = DAT_007feda4 - DAT_007fedac;
  _DAT_007feda0 = 9999;
  iVar1 = DAT_007fedd4 + -1;
  *(int *)(puVar2 + -100) = iVar1;
  DAT_007fedd8 = 2;
  _DAT_007fedb4 = f_0;
  while (0 < iVar1) {
    ffree(Var4);
    fVar3 = (float10)FUN_0045a738(&DAT_007fedb0,&DAT_007fedac,&DAT_007fed9c,&DAT_007fed98);
    DAT_007fed94 = 0;
    if (DAT_007fedd8 == 2) {
      *(undefined4 *)(puVar2 + -0x60) = 0;
    }
    else if (_DAT_01c00564 == f_0) {
      if (_DAT_007fed90 != f_0) {
        DAT_007fed9c = (DAT_007fed98 - DAT_007fed88) / _DAT_007fed90 + DAT_007fed8c;
      }
      *(undefined4 *)(puVar2 + -0x58) = 0;
    }
    else {
      *(undefined4 *)(puVar2 + -0x5c) = 0;
      if (_DAT_01c00560 == f_0) {
        if (_DAT_007fed90 != f_0) {
          DAT_007fed98 = (DAT_007fed9c - DAT_007fed8c) * _DAT_007fed90 + DAT_007fed88;
        }
        *(undefined4 *)(puVar2 + -0x50) = 0;
      }
      else {
        *(undefined4 *)(puVar2 + -0x54) = 0;
        if (_DAT_007fed90 == f_0) {
          DAT_007fed98 = DAT_007fed88;
          DAT_007fed9c = DAT_007fed88 / DAT_01c0056c + DAT_01c00570;
          *(undefined4 *)(puVar2 + -0x48) = 0;
        }
        else {
          *(undefined4 *)(puVar2 + -0x4c) = 0;
          if (_DAT_007fed90 == f_9999) {
            DAT_007fed9c = DAT_007fed8c;
            DAT_007fed98 = (DAT_007fed8c - DAT_01c00570) * DAT_01c0056c;
            *(undefined4 *)(puVar2 + -0x40) = 0;
          }
          else {
            *(undefined4 *)(puVar2 + -0x44) = 0;
            if (_DAT_007fed90 - DAT_01c0056c == f_0) {
              DAT_007fed94 = -1;
              *(undefined4 *)(puVar2 + -0x38) = 0;
            }
            else {
              *(undefined4 *)(puVar2 + -0x3c) = 0;
              fVar3 = (float10)f_1 / (float10)DAT_01c0056c;
              _DAT_007fed84 = (float)(fVar3 - (float10)f_1 / (float10)_DAT_007fed90);
              DAT_007fed98 = (_DAT_007fed80 - DAT_01c00570) / _DAT_007fed84;
              DAT_007fed9c = DAT_007fed98 / DAT_01c0056c + DAT_01c00570;
            }
          }
        }
      }
    }
    DAT_007fed8c = DAT_007fed9c;
    DAT_007fed88 = DAT_007fed98;
    _DAT_007fed90 = DAT_01c0056c;
    _DAT_007fed80 = DAT_01c00570;
    _DAT_007fed7c = DAT_007fed9c;
    _DAT_007fed78 = DAT_007fed98;
    if (DAT_007fedc4 == 0) {
      *(undefined4 *)(puVar2 + -0x34) = 0;
    }
    else {
      _DAT_007fed74 = DAT_007fed9c - DAT_007fedb0;
      _DAT_007fed70 = DAT_007fed98 - DAT_007fedac;
      _DAT_007fed7c = _DAT_007fed74 * _DAT_007fedb4 + DAT_007fedb0;
      _DAT_007fed78 = _DAT_007fed70 * _DAT_007fedb4 + DAT_007fedac;
      if ((_DAT_007fedb4 == f_1) || (DAT_007fedbc <= DAT_007fedd8)) {
        *(undefined4 *)(puVar2 + -0x30) = 0;
        if (DAT_007fedd8 < DAT_007fedbc) {
          *(undefined4 *)(puVar2 + -0x28) = 0;
        }
        else {
          _DAT_007fedb4 = _DAT_007fedb4 - _DAT_007fedb8;
          if (_DAT_007fedb4 < f_0) {
            _DAT_007fedb4 = f_0;
          }
        }
      }
      else {
        _DAT_007fedb4 = _DAT_007fedb8 + _DAT_007fedb4;
        if (f_1 < _DAT_007fedb4) {
          _DAT_007fedb4 = f_1;
        }
        *(undefined4 *)(puVar2 + -0x2c) = 0;
      }
    }
    ffree(fVar3);
    fVar3 = (float10)FUN_005ff381(puVar2,0x45a239);
    *(int *)(puVar2 + -0x9c) = (int)ROUND(fVar3);
    DAT_007fed6c = *(int *)(puVar2 + -0x9c);
    ffree(extraout_ST1_00);
    fVar3 = (float10)FUN_005ff381(puVar2,0x45a267);
    *(int *)(puVar2 + -0x9c) = (int)ROUND(fVar3);
    DAT_007fed68 = *(int *)(puVar2 + -0x9c);
    DAT_007fedb0 = DAT_007feda8;
    DAT_007fedac = DAT_007feda4;
    if (DAT_007fedd4 == DAT_007fedd8) {
      *(undefined4 *)(puVar2 + -0x24) = 0;
    }
    else {
      _DAT_01c00560 = (float)(&DAT_01fd3f80)[DAT_007fedd8] - DAT_007feda8;
      _DAT_01c00564 = (float)(&DAT_02004cc0)[DAT_007fedd8] - DAT_007feda4;
      DAT_007feda4 = (float)(&DAT_02004cc0)[DAT_007fedd8];
      DAT_007feda8 = (float)(&DAT_01fd3f80)[DAT_007fedd8];
    }
    if ((DAT_007fed6c == _DAT_007feda0) && (DAT_007fed68 == _DAT_007fed64)) {
      *(undefined4 *)(puVar2 + -0x20) = 0;
    }
    else {
      _DAT_007feda0 = DAT_007fed6c;
      _DAT_007fed64 = DAT_007fed68;
      if (DAT_007fed94 < 0) {
        *(undefined4 *)(puVar2 + -0x1c) = 0;
      }
      else {
        DAT_007fedc8 = DAT_007fedc8 + 1;
        *(int *)(DAT_007fedc8 * 0xc + 0x1bf49d4) = DAT_007fed6c;
        *(int *)(DAT_007fedc8 * 0xc + 0x1bf49d8) = DAT_007fed68;
      }
    }
    *(undefined4 *)(puVar2 + -0x18) = 0;
    DAT_007fedd8 = DAT_007fedd8 + 1;
    *(int *)(puVar2 + -100) = *(int *)(puVar2 + -100) + -1;
    Var4 = extraout_ST1_01;
    iVar1 = *(int *)(puVar2 + -100);
  }
  if (DAT_007fedc4 == 0) {
    if (_DAT_01c00564 == f_0) {
      *(undefined4 *)(puVar2 + -0xc) = 0;
      _DAT_007fed7c = DAT_007fedb0;
    }
    else {
      *(undefined4 *)(puVar2 + -0x10) = 0;
      if (_DAT_01c00560 == f_0) {
        *(undefined4 *)(puVar2 + -4) = 0;
        _DAT_007fed78 = DAT_007fedac;
      }
      else {
        *(undefined4 *)(puVar2 + -8) = 0;
        ffree(Var4);
        Var4 = FUN_0045a738(&DAT_007fedb0,&DAT_007fedac,&DAT_007fed7c,&DAT_007fed78);
      }
    }
    DAT_007fedc8 = DAT_007fedc8 + 1;
    iVar1 = DAT_007fedc8 * 0xc;
    ffree(Var4);
    fVar3 = (float10)FUN_005ff381(puVar2,0x45a46f);
    *(int *)(puVar2 + -0x9c) = (int)ROUND(fVar3);
    *(undefined4 *)(iVar1 + 0x1bf49d4) = *(undefined4 *)(puVar2 + -0x9c);
    iVar1 = DAT_007fedc8 * 0xc;
    ffree(extraout_ST1_02);
    fVar3 = (float10)FUN_005ff381(puVar2,0x45a4a4);
    *(int *)(puVar2 + -0x9c) = (int)ROUND(fVar3);
    *(undefined4 *)(iVar1 + 0x1bf49d8) = *(undefined4 *)(puVar2 + -0x9c);
    Var4 = extraout_ST1_03;
  }
  else {
    *(undefined4 *)(puVar2 + -0x14) = 0;
  }
  DAT_007fed94 = **(int **)(puVar2 + 8);
  DAT_007fedd8 = DAT_007fedc8;
  for (iVar1 = -DAT_007fedc8 / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_007fed94 = DAT_007fed94 + 1;
    (&PT_X0)[DAT_007fed94] = *(undefined4 *)(DAT_007fedd8 * 0xc + 0x1bf49d4);
    (&PT_Y0)[DAT_007fed94] = *(undefined4 *)(DAT_007fedd8 * 0xc + 0x1bf49d8);
    *(undefined2 *)((int)&DAT_01fbb8dc + DAT_007fed94 * 2 + 2) = 0;
    DAT_007fedd8 = DAT_007fedd8 + -1;
  }
  **(int **)(puVar2 + 8) = DAT_007fed94;
  ffree(Var4);
  Var4 = FUN_0045a585(*(undefined4 *)(puVar2 + 8));
LAB_0045a57a:
  ffree(Var4);
  return;
}


