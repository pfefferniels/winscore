// text_rotate @ 0056f920 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void text_rotate(undefined4 param_1,int param_2,int param_3,float *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined2 in_FPUControlWord;
  undefined2 uVar3;
  unkbyte10 in_ST0;
  float10 fVar4;
  unkbyte10 Var5;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  
  puVar2 = &stack0xfffffffc;
  _DAT_009a8338 = *param_4 / f_57_295776;
  ffree(in_ST0);
  fVar4 = (float10)FUN_005ff110(&stack0xfffffffc,0x56f955);
  _DAT_009a8334 = (float)fVar4;
  ffree(extraout_ST1);
  fVar4 = (float10)FUN_005ff0f5(puVar2,0x56f977);
  _DAT_009a8330 = (float)fVar4;
  DAT_009a8328 = _DAT_009a8334 * f_4_583 * ((STEP * P48) / f_25) * f_150;
  _DAT_009a8338 = (f_270 - **(float **)(puVar2 + 0x14)) / f_57_295776;
  _DAT_009a832c = ((STEP * P48) / f_25) * f_175;
  ffree(extraout_ST1_00);
  fVar4 = (float10)FUN_005ff110(puVar2,0x56fa04);
  _DAT_009a8324 = (float)fVar4;
  _DAT_009a8320 = _DAT_009a832c * f_3_95;
  DAT_009a831c = _DAT_009a8320 * _DAT_009a8324 + _DAT_009a8320;
  ffree(extraout_ST1_01);
  fVar4 = (float10)anint(puVar2,0x56fa50);
  *(int *)(puVar2 + -0x34) = (int)ROUND(fVar4);
  DAT_009a8318 = *(int *)(puVar2 + -0x34);
  ffree(extraout_ST1_02);
  fVar4 = (float10)anint(puVar2,0x56fa78);
  *(int *)(puVar2 + -0x34) = (int)ROUND(fVar4);
  DAT_009a8314 = *(int *)(puVar2 + -0x34);
  DAT_009a8310 = 1;
  Var5 = extraout_ST1_03;
  while( true ) {
    if (((int)(&DAT_01caea3c)[DAT_009a8310] < 1000) &&
       (*(int *)(param_2 + -4 + DAT_009a8310 * 4) != 0)) {
      _DAT_009a830c = DAT_009a8328;
      _DAT_009a8308 = DAT_009a831c;
      if (((int)(&DAT_01caea3c)[DAT_009a8310] < 0x50) || (0x7e < (int)(&DAT_01caea3c)[DAT_009a8310])
         ) {
        *(undefined4 *)(puVar2 + -0xc) = 0;
        DAT_009a8304 = *(int *)(param_2 + -4 + DAT_009a8310 * 4);
        *(int *)(puVar2 + -0x34) = DAT_009a8304 - DAT_009a8318;
        iVar1 = *(int *)(puVar2 + -0x34);
        _DAT_009a8300 = (float)iVar1;
        *(int *)(puVar2 + -0x34) = *(int *)(param_3 + -4 + DAT_009a8310 * 4) - DAT_009a8314;
        _DAT_009a8320 = (float)*(int *)(puVar2 + -0x34);
        ffree((float10)_DAT_009a8330 * (float10)iVar1);
        fVar4 = (float10)anint(puVar2,0x56fb7b);
        *(int *)(puVar2 + -0x34) = (int)ROUND(fVar4);
        DAT_009a8304 = DAT_009a8318 + *(int *)(puVar2 + -0x34);
        *(undefined2 *)(puVar2 + -0x38) = in_FPUControlWord;
        *(ushort *)(puVar2 + -0x36) = (ushort)*(undefined4 *)(puVar2 + -0x38) | 0xc00;
        *(int *)(puVar2 + -0x34) = (int)ROUND((float)DAT_009a8304 + _DAT_009a830c);
        uVar3 = *(undefined2 *)(puVar2 + -0x38);
        *(undefined4 *)(param_2 + -4 + DAT_009a8310 * 4) = *(undefined4 *)(puVar2 + -0x34);
        ffree((float10)_DAT_009a8330 * (float10)_DAT_009a8320);
        fVar4 = (float10)anint(puVar2,0x56fbf4);
        *(int *)(puVar2 + -0x34) = (int)ROUND(fVar4);
        DAT_009a8304 = DAT_009a8314 + *(int *)(puVar2 + -0x34);
        *(undefined2 *)(puVar2 + -0x38) = uVar3;
        *(ushort *)(puVar2 + -0x36) = (ushort)*(undefined4 *)(puVar2 + -0x38) | 0xc00;
        *(int *)(puVar2 + -0x34) = (int)ROUND((float)DAT_009a8304 - _DAT_009a8308);
        in_FPUControlWord = *(undefined2 *)(puVar2 + -0x38);
        *(undefined4 *)(param_3 + -4 + DAT_009a8310 * 4) = *(undefined4 *)(puVar2 + -0x34);
        Var5 = extraout_ST1_04;
      }
      else {
        *(undefined4 *)(puVar2 + -8) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar2 + -0x10) = 0;
    }
    DAT_009a8310 = DAT_009a8310 + 1;
    if (**(int **)(puVar2 + 8) < DAT_009a8310) break;
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  ffree(Var5);
  return;
}


