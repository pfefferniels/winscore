// FUN_0056f689 @ 0056f689 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056f689(undefined4 param_1,int param_2,int param_3,float *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined2 in_FPUControlWord;
  float10 fVar3;
  unkbyte10 Var4;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  
  puVar2 = &stack0xfffffffc;
  _DAT_009a82fc = (STEP * P48) / f_25;
  _DAT_009a82f8 =
       (float)((ABS((float10)*param_4) / (float10)f_30) * (float10)_DAT_009a82fc * (float10)f_175);
  _DAT_009a82f4 = *param_4 / f_57_295776;
  ffree((float10)*param_4);
  fVar3 = (float10)FUN_005ff110(&stack0xfffffffc,0x56f6f9);
  _DAT_009a82f0 = (float)fVar3;
  _DAT_009a82ec = _DAT_009a82fc * f_697_5 * _DAT_009a82f0;
  ffree(extraout_ST1);
  fVar3 = (float10)FUN_005ff0f5(puVar2,0x56f733);
  _DAT_009a82e8 = (float)fVar3;
  ffree(extraout_ST1_00);
  fVar3 = (float10)anint(puVar2,0x56f755);
  *(int *)(puVar2 + -0x2c) = (int)ROUND(fVar3);
  DAT_009a82e4 = *(int *)(puVar2 + -0x2c);
  ffree(extraout_ST1_01);
  fVar3 = (float10)anint(puVar2,0x56f77d);
  *(int *)(puVar2 + -0x2c) = (int)ROUND(fVar3);
  DAT_009a82e0 = *(int *)(puVar2 + -0x2c);
  DAT_009a82dc = 1;
  Var4 = extraout_ST1_02;
  while( true ) {
    if (((int)(&DAT_01caea3c)[DAT_009a82dc] < 1000) &&
       (*(int *)(param_2 + -4 + DAT_009a82dc * 4) != 0)) {
      DAT_009a82d8 = *(int *)(param_2 + -4 + DAT_009a82dc * 4);
      *(int *)(puVar2 + -0x2c) = DAT_009a82d8 - DAT_009a82e4;
      iVar1 = *(int *)(puVar2 + -0x2c);
      _DAT_009a82fc = (float)iVar1;
      *(int *)(puVar2 + -0x2c) = *(int *)(param_3 + -4 + DAT_009a82dc * 4) - DAT_009a82e0;
      _DAT_009a82d4 = (float)*(int *)(puVar2 + -0x2c);
      ffree((float10)_DAT_009a82e8 * (float10)iVar1);
      fVar3 = (float10)anint(puVar2,0x56f835);
      *(int *)(puVar2 + -0x2c) = (int)ROUND(fVar3);
      DAT_009a82d8 = DAT_009a82e4;
      *(undefined2 *)(puVar2 + -0x30) = in_FPUControlWord;
      *(ushort *)(puVar2 + -0x2e) = (ushort)*(undefined4 *)(puVar2 + -0x30) | 0xc00;
      *(int *)(puVar2 + -0x2c) = (int)ROUND((float)DAT_009a82e4 + _DAT_009a82ec);
      in_FPUControlWord = *(undefined2 *)(puVar2 + -0x30);
      *(undefined4 *)(param_2 + -4 + DAT_009a82dc * 4) = *(undefined4 *)(puVar2 + -0x2c);
      ffree((float10)_DAT_009a82e8 * (float10)_DAT_009a82d4);
      fVar3 = (float10)anint(puVar2,0x56f8ba);
      *(int *)(puVar2 + -0x2c) = (int)ROUND(fVar3);
      DAT_009a82d8 = DAT_009a82e0 + *(int *)(puVar2 + -0x2c);
      *(int *)(param_3 + -4 + DAT_009a82dc * 4) = DAT_009a82d8;
      Var4 = extraout_ST1_03;
    }
    else {
      *(undefined4 *)(puVar2 + -8) = 0;
    }
    DAT_009a82dc = DAT_009a82dc + 1;
    if (**(int **)(puVar2 + 8) < DAT_009a82dc) break;
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  ffree(Var4);
  return;
}


