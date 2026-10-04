// FUN_0042a5f4 @ 0042a5f4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042a5f4(int *param_1,undefined4 param_2,undefined4 param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined2 in_FPUControlWord;
  undefined2 uVar4;
  float10 in_ST0;
  float10 fVar5;
  float10 fVar6;
  unkbyte10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined1 *puVar7;
  
  puVar7 = &stack0xfffffffc;
  DAT_007ec2f4 = *param_1;
  if (DAT_007ec2f4 < 1) {
    DAT_007ec2f4 = -DAT_007ec2f4;
    in_ST0 = (float10)*param_4;
    _DAT_007ec2f0 = (float)-in_ST0;
  }
  else {
    _DAT_007ec2f0 = *param_4 / f_57_295776;
  }
  ffree(in_ST0);
  fVar5 = (float10)FUN_005ff110(&stack0xfffffffc,0x42a666);
  _DAT_007ec2ec = (float)fVar5;
  ffree(extraout_ST1);
  fVar5 = (float10)FUN_005ff0f5(puVar7,0x42a688);
  _DAT_007ec2e8 = (float)fVar5;
  fVar1 = **(float **)(puVar7 + 0xc);
  *(undefined2 *)(puVar7 + -0x34) = in_FPUControlWord;
  *(ushort *)(puVar7 + -0x32) = (ushort)*(undefined4 *)(puVar7 + -0x34) | 0xc00;
  *(int *)(puVar7 + -0x30) = (int)ROUND(fVar1);
  _DAT_007ec2e4 = *(int *)(puVar7 + -0x30);
  fVar1 = **(float **)(puVar7 + 0x10);
  *(undefined2 *)(puVar7 + -0x34) = *(undefined2 *)(puVar7 + -0x34);
  *(ushort *)(puVar7 + -0x32) = (ushort)*(undefined4 *)(puVar7 + -0x34) | 0xc00;
  *(int *)(puVar7 + -0x30) = (int)ROUND(fVar1);
  uVar4 = *(undefined2 *)(puVar7 + -0x34);
  _DAT_007ec2e0 = *(int *)(puVar7 + -0x30);
  fVar5 = extraout_ST1_00;
  if (P1 == f_16) {
    fVar1 = P3 * f_150;
    *(undefined2 *)(puVar7 + -0x34) = uVar4;
    *(ushort *)(puVar7 + -0x32) = (ushort)*(undefined4 *)(puVar7 + -0x34) | 0xc00;
    *(int *)(puVar7 + -0x30) = (int)ROUND(fVar1);
    fVar1 = Y_POS;
    _DAT_007ec2e4 = *(int *)(puVar7 + -0x30);
    *(undefined2 *)(puVar7 + -0x34) = *(undefined2 *)(puVar7 + -0x34);
    *(ushort *)(puVar7 + -0x32) = (ushort)*(undefined4 *)(puVar7 + -0x34) | 0xc00;
    *(int *)(puVar7 + -0x30) = (int)ROUND(fVar1);
    uVar4 = *(undefined2 *)(puVar7 + -0x34);
    _DAT_007ec2e0 = *(int *)(puVar7 + -0x30);
  }
  else {
    *(undefined4 *)(puVar7 + -4) = 0;
  }
  do {
    if (*(short *)((int)&DAT_01fbb8dc + DAT_007ec2f4 * 2 + 2) != 99) {
      *(int *)(puVar7 + -0x30) = (&PT_X0)[DAT_007ec2f4] - _DAT_007ec2e4;
      _DAT_007ec2dc = (float)*(int *)(puVar7 + -0x30);
      *(int *)(puVar7 + -0x30) = (&PT_Y0)[DAT_007ec2f4] - _DAT_007ec2e0;
      _DAT_007ec2d8 = (float)*(int *)(puVar7 + -0x30);
      fVar1 = _DAT_007ec2e8 * _DAT_007ec2dc;
      fVar3 = _DAT_007ec2ec * _DAT_007ec2d8;
      fVar2 = (float)_DAT_007ec2e4;
      *(undefined2 *)(puVar7 + -0x34) = uVar4;
      *(ushort *)(puVar7 + -0x32) = (ushort)*(undefined4 *)(puVar7 + -0x34) | 0xc00;
      *(int *)(puVar7 + -0x30) = (int)ROUND(fVar2 + fVar3 + fVar1);
      uVar4 = *(undefined2 *)(puVar7 + -0x34);
      (&PT_X0)[DAT_007ec2f4] = *(undefined4 *)(puVar7 + -0x30);
      fVar5 = (float10)_DAT_007ec2e8 * (float10)_DAT_007ec2d8 -
              (float10)_DAT_007ec2ec * (float10)_DAT_007ec2dc;
      fVar6 = (float10)_DAT_007ec2e0;
      *(undefined2 *)(puVar7 + -0x34) = uVar4;
      *(ushort *)(puVar7 + -0x32) = (ushort)*(undefined4 *)(puVar7 + -0x34) | 0xc00;
      *(int *)(puVar7 + -0x30) = (int)ROUND(fVar6 + fVar5);
      uVar4 = *(undefined2 *)(puVar7 + -0x34);
      DAT_007ec2d0 = *(undefined4 *)(puVar7 + -0x30);
      (&PT_Y0)[DAT_007ec2f4] = DAT_007ec2d0;
    }
    DAT_007ec2f4 = DAT_007ec2f4 + 1;
  } while (DAT_007ec2f4 < NPT);
  ffree(fVar5);
  return;
}


