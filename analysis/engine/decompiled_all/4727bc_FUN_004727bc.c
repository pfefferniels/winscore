// FUN_004727bc @ 004727bc (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004727bc(int *param_1,int *param_2,int *param_3,int *param_4,int param_5,undefined4 param_6
                 ,int *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  IP8 = (int)ROUND(*(float *)(&ITEM_P8 + *param_1 * 4));
  P10 = *(float *)(&ITEM_P10 + *param_1 * 4);
  P5 = (float)(&ITEM_P5)[*param_1];
  fVar5 = (float10)amod(&ITEM_P6 + *param_1,&DAT_00762118);
  P48 = (float)fVar5;
  if (P48 == f_0) {
    P48 = f_1;
  }
  text_parse(param_5,1,param_3);
  _DAT_00824f94 = *param_7 + (*param_3 + -1) / 4 + 1;
  (&DAT_01e9997c)[*param_2] = (float)_DAT_00824f94;
  *(float *)(&DAT_01e999ac + *param_2 * 4) = (float)*param_3;
  *(float *)(&DAT_01e999b0 + *param_2 * 4) = P13;
  iVar1 = (*param_7 + *param_2) * 4 + 1;
  iVar3 = *param_3;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  iVar2 = 1;
  DAT_00824f90 = iVar1;
  for (iVar4 = 1; iVar4 <= iVar3; iVar4 = iVar4 + 1) {
    *(undefined1 *)((int)&DAT_01e9997c + iVar1 + 3) = *(undefined1 *)(param_5 + -1 + iVar2);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 1;
  }
  *param_4 = *param_2 + _DAT_00824f94 + 1;
  return;
}


