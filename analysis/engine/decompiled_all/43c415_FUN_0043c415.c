// FUN_0043c415 @ 0043c415 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0043c415(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  unkbyte10 in_ST0;
  float10 fVar2;
  float10 fVar3;
  unkbyte10 Var4;
  unkbyte10 in_ST1;
  unkbyte10 extraout_ST1;
  float local_34 [2];
  float local_2c [10];
  
  local_2c[0] = *param_3 * f_55_3 + *param_2;
  ffree(in_ST1);
  ffree(in_ST0);
  add_point(param_1,local_2c,&DAT_00760498);
  iVar1 = 0xc;
  DAT_007f7788 = 1;
  do {
    fVar2 = (float10)*(float *)(DAT_007f7788 * 4 + 0x78f6d8) * (float10)*param_3 + (float10)*param_1
    ;
    fVar3 = (float10)*(float *)(DAT_007f7788 * 4 + 0x78f6a8) * (float10)*param_3 + (float10)*param_2
    ;
    local_2c[0] = (float)fVar2;
    local_34[0] = (float)fVar3;
    ffree(fVar3);
    ffree(fVar2);
    Var4 = add_point(local_2c,local_34,&DAT_00760494);
    DAT_007f7788 = DAT_007f7788 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  ffree(extraout_ST1);
  ffree(Var4);
  return;
}


