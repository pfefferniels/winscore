// FUN_0045a738 @ 0045a738 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045a738(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float10 in_ST0;
  float10 fVar1;
  unkbyte10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  _DAT_007fee68 = DAT_01c00568;
  if (_DAT_01c00560 == f_0) {
    if (_DAT_01c00564 < f_0) {
      in_ST0 = (float10)DAT_01c00568;
      _DAT_007fee68 = (float)-in_ST0;
    }
    *param_3 = *param_1 - _DAT_007fee68;
    DAT_01c00570 = *param_3;
    DAT_01c0056c = f_9999;
  }
  else if (_DAT_01c00564 == f_0) {
    if (_DAT_01c00560 < f_0) {
      in_ST0 = (float10)DAT_01c00568;
      _DAT_007fee68 = (float)-in_ST0;
    }
    *param_4 = _DAT_007fee68 + *param_2;
    DAT_01c0056c = f_0;
  }
  else {
    DAT_01c0056c = _DAT_01c00564 / _DAT_01c00560;
    ffree(in_ST0);
    FUN_005ff206(&stack0xfffffffc,0x45a842);
    ffree(extraout_ST1);
    fVar1 = (float10)FUN_005ff110(puVar2,0x45a858);
    _DAT_007fee68 = (float)(fVar1 * (float10)_DAT_007fee68);
    in_ST0 = extraout_ST1_00;
    if (_DAT_01c00560 < f_0) {
      in_ST0 = (float10)_DAT_007fee68;
      _DAT_007fee68 = (float)-in_ST0;
    }
    *param_3 = **(float **)(puVar2 + 8) - _DAT_007fee68;
    **(float **)(puVar2 + 0x14) = _DAT_007fee68 / DAT_01c0056c + **(float **)(puVar2 + 0xc);
    DAT_01c00570 = *param_3 - **(float **)(puVar2 + 0x14) / DAT_01c0056c;
    *(undefined4 *)(puVar2 + -8) = 0;
  }
  ffree(in_ST0);
  return;
}


