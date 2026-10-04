// FUN_004b5db0 @ 004b5db0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b5db0(int *param_1,float *param_2,float *param_3,undefined4 param_4,int param_5)

{
  undefined1 *puVar1;
  int iVar2;
  float10 in_ST0;
  unkbyte10 Var3;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  DAT_0089f480 = 1;
  DAT_0089f488 = *param_1 + -1;
  _DAT_0089f484 = f_0;
  for (iVar2 = DAT_0089f488; 0 < iVar2; iVar2 = iVar2 + -1) {
    _DAT_0089f484 = _DAT_0089f484 + *(float *)(param_5 + -4 + DAT_0089f480 * 4);
    DAT_0089f480 = DAT_0089f480 + 1;
  }
  _DAT_0089f47c = *param_3 - *param_2;
  if (_DAT_0089f47c < _DAT_0089f484) {
    FUN_005f33c9(&stack0xfffffffc,0x4b5e73);
    puVar1 = puVar4;
    Var3 = FUN_005f34d1(puVar4,0x4b5e8e);
    ffree(Var3);
    Var3 = thunk_FUN_0058c248(&DAT_020b90a0,0x200,&DAT_00764758,&DAT_0076475c,"(1f9.3)",7,
                              &DAT_0089f484);
    ffree(Var3);
    in_ST0 = (float10)thunk_FUN_0058c248(&DAT_020b90a0,0x200,&DAT_00764750,&DAT_00764754,"(1f9.3)",7
                                         ,&DAT_0089f47c);
    iVar2 = DAT_0089f488;
    _DAT_0089f47c = (_DAT_0089f484 - _DAT_0089f47c) / (float)DAT_0089f488;
    *(int *)(puVar1 + -0x44) = DAT_0089f488;
    DAT_0089f480 = 1;
    while (0 < iVar2) {
      *(float *)(*(int *)(puVar1 + 0x18) + -4 + DAT_0089f480 * 4) =
           *(float *)(*(int *)(puVar1 + 0x18) + -4 + DAT_0089f480 * 4) - _DAT_0089f47c;
      DAT_0089f480 = DAT_0089f480 + 1;
      *(int *)(puVar1 + -0x44) = *(int *)(puVar1 + -0x44) + -1;
      iVar2 = *(int *)(puVar1 + -0x44);
    }
  }
  *(int *)(puVar1 + -0x40) = DAT_0089f488;
  DAT_0089f480 = 1;
  iVar2 = DAT_0089f488;
  while (0 < iVar2) {
    *(float *)(*(int *)(puVar1 + 0x1c) + -4 + DAT_0089f480 * 4) =
         (*(float *)(*(int *)(puVar1 + 0x14) + DAT_0089f480 * 4) -
         *(float *)(*(int *)(puVar1 + 0x14) + -4 + DAT_0089f480 * 4)) -
         *(float *)(*(int *)(puVar1 + 0x18) + -4 + DAT_0089f480 * 4);
    DAT_0089f480 = DAT_0089f480 + 1;
    *(int *)(puVar1 + -0x40) = *(int *)(puVar1 + -0x40) + -1;
    iVar2 = *(int *)(puVar1 + -0x40);
  }
  *(int *)(puVar1 + -0x3c) = DAT_0089f488;
  DAT_0089f480 = 1;
  _DAT_0089f478 = f_0;
  _DAT_0089f474 = f_0;
  iVar2 = DAT_0089f488;
  while (0 < iVar2) {
    _DAT_01b11764 = *(float *)(*(int *)(puVar1 + 0x1c) + -4 + DAT_0089f480 * 4);
    if (f_0 <= _DAT_01b11764) {
      _DAT_0089f478 = _DAT_01b11764 + _DAT_0089f478;
      *(undefined4 *)(puVar1 + -0x34) = 0;
    }
    else {
      *(undefined4 *)(puVar1 + -0x38) = 0;
      _DAT_0089f474 = _DAT_0089f474 - _DAT_01b11764;
    }
    *(undefined4 *)(puVar1 + -0x30) = 0;
    DAT_0089f480 = DAT_0089f480 + 1;
    *(int *)(puVar1 + -0x3c) = *(int *)(puVar1 + -0x3c) + -1;
    iVar2 = *(int *)(puVar1 + -0x3c);
  }
  if (_DAT_0089f474 == f_0) {
    *(undefined4 *)(puVar1 + -0x2c) = 0;
  }
  else if (_DAT_0089f478 == f_0) {
    *(undefined4 *)(puVar1 + -0x24) = 0;
  }
  else {
    *(undefined4 *)(puVar1 + -0x28) = 0;
    _DAT_0089f470 = _DAT_0089f474 / _DAT_0089f478;
    iVar2 = **(int **)(puVar1 + 8) + -1;
    *(int *)(puVar1 + -0x20) = iVar2;
    DAT_0089f480 = 2;
    DAT_01b11760 = f_m9999;
    while (0 < iVar2) {
      DAT_0089f46c = DAT_0089f480 + -1;
      in_ST0 = (float10)*(float *)(DAT_0089f46c * 4 + *(int *)(puVar1 + 0x1c) + -4);
      _DAT_01b11764 = (float)-in_ST0;
      if (_DAT_01b11764 < f_0) {
        _DAT_01b11764 = _DAT_0089f470 * _DAT_01b11764;
      }
      if (_DAT_01b11764 == f_0) {
        *(undefined4 *)(puVar1 + -0x1c) = 0;
      }
      else if (_DAT_01b11764 <= f_0) {
        ffree(in_ST0);
        Var3 = FUN_004b63cd(DAT_0089f46c * 4 + *(int *)(puVar1 + 0x14) + -4,
                            DAT_0089f480 * 4 + *(int *)(puVar1 + 0x14) + -4);
        ffree(Var3);
        Var3 = FUN_004b6593(DAT_0089f480 * 4 + *(int *)(puVar1 + 0x14) + -4);
        ffree(Var3);
        in_ST0 = (float10)FUN_004b6365(*(undefined4 *)(puVar1 + 0x14),&DAT_0089f480,
                                       *(undefined4 *)(puVar1 + 8));
        *(undefined4 *)(puVar1 + -0x14) = 0;
      }
      else {
        *(undefined4 *)(puVar1 + -0x18) = 0;
        _DAT_0089f484 = *(float *)(*(int *)(puVar1 + 0x14) + -4 + DAT_0089f480 * 4);
        ffree(in_ST0);
        Var3 = FUN_004b6593(&DAT_0089f484);
        ffree(Var3);
        Var3 = FUN_004b6365(*(undefined4 *)(puVar1 + 0x14),&DAT_0089f480,*(undefined4 *)(puVar1 + 8)
                           );
        ffree(Var3);
        in_ST0 = (float10)FUN_004b63cd(DAT_0089f46c * 4 + *(int *)(puVar1 + 0x14) + -4,&DAT_0089f484
                                      );
      }
      *(undefined4 *)(puVar1 + -0x10) = 0;
      DAT_0089f480 = DAT_0089f480 + 1;
      *(int *)(puVar1 + -0x20) = *(int *)(puVar1 + -0x20) + -1;
      iVar2 = *(int *)(puVar1 + -0x20);
    }
    *(int *)(puVar1 + -0xc) = ITEM_I;
    LOAD_I = 1;
    iVar2 = ITEM_I;
    while (0 < iVar2) {
      ffree(in_ST0);
      in_ST0 = (float10)load_item_header();
      if (LOAD_LEN < 3) {
        *(undefined4 *)(puVar1 + -8) = 0;
      }
      else {
        in_ST0 = (float10)LOAD_P3;
        if (ABS(in_ST0) < (float10)f_0_01) {
          (&ITEM_P3)[LOAD_W] = f_0;
        }
        if (ABS(DAT_01fbb8b8 - LOAD_P3) < f_0_01) {
          (&ITEM_P3)[LOAD_W] = DAT_01fbb8b8;
        }
      }
      *(undefined4 *)(puVar1 + -4) = 0;
      LOAD_I = LOAD_I + 1;
      *(int *)(puVar1 + -0xc) = *(int *)(puVar1 + -0xc) + -1;
      iVar2 = *(int *)(puVar1 + -0xc);
    }
  }
  ffree(in_ST0);
  return;
}


