// input_rhythm_value @ 0051c64f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void input_rhythm_value(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar4;
  unkbyte10 in_ST1;
  float10 extraout_ST1;
  float10 in_ST2;
  
  puVar2 = &stack0xfffffffc;
  ffree(in_ST1);
  ffree(in_ST0);
  fVar4 = (float10)amod(param_3,&f_1000);
  *param_1 = (float)fVar4;
  DAT_01be6c6c = *param_1;
  fVar4 = extraout_ST1;
  if (DAT_01be6c6c <= f_0) {
    *param_5 = f_0;
    *param_2 = f_0;
    *param_4 = f_0;
  }
  else {
    DAT_01be6c60 = (int)ROUND(*param_3 / f_100);
    *param_4 = (float)DAT_01be6c60;
    if (DAT_01be6c60 != 0) {
      in_ST2 = (float10)*param_4 / (float10)f_10;
      ffree(in_ST2);
      puVar2 = &stack0xfffffffc;
      fVar4 = (float10)FUN_006033ff(&stack0xfffffffc,0x51c70a);
      DAT_01be6c6c = (float)fVar4;
      fVar4 = (float10)DAT_01be6c6c * (float10)**(float **)(puVar2 + 8);
      DAT_01be6c6c = (float)(fVar4 / ((float10)DAT_01be6c6c * (float10)f_2 - (float10)f_1));
    }
    **(float **)(puVar2 + 0xc) = f_4 / DAT_01be6c6c;
    fVar1 = **(float **)(puVar2 + 0xc);
    *(undefined2 *)(puVar2 + -0x38) = in_FPUControlWord;
    *(ushort *)(puVar2 + -0x36) = (ushort)*(undefined4 *)(puVar2 + -0x38) | 0xc00;
    *(int *)(puVar2 + -0x34) = (int)ROUND(fVar1 + f_0_001);
    DAT_01be6c60 = *(int *)(puVar2 + -0x34);
    DAT_01be6c68 = 8;
    iVar3 = 10;
    DAT_01be6c64 = 1;
    do {
      if (DAT_01be6c60 < DAT_01be6c68) {
        *(undefined4 *)(puVar2 + -4) = 0;
        break;
      }
      DAT_01be6c68 = DAT_01be6c68 * 2;
      DAT_01be6c64 = DAT_01be6c64 + 1;
      iVar3 = iVar3 + -1;
    } while (0 < iVar3);
    *(int *)(puVar2 + -0x34) = DAT_01be6c64 + -1;
    **(float **)(puVar2 + 0x18) = (float)*(int *)(puVar2 + -0x34);
  }
  ffree(in_ST2);
  ffree(fVar4);
  return;
}


