// FUN_004b3534 @ 004b3534 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b3534(undefined4 param_1,int *param_2,undefined4 param_3)

{
  float local_2c [10];
  
  DAT_0089f364 = (&ITEM_PTR0)[*param_2];
  thunk_FUN_0045ea40(&ITEM_P1 + DAT_0089f364,param_3,&DAT_0089f360,&DAT_0089f35c,&ITEM_P1,param_1);
  if ((float)(&ITEM_LEN)[DAT_0089f364] < (float)DAT_0089f35c) {
    local_2c[0] = (float)DAT_0089f35c;
    thunk_FUN_005239c9(param_2,local_2c);
  }
  DAT_0089f358 = (int)ROUND((float)(&ITEM_LEN)[DAT_0089f35c + DAT_0089f364] / f_100);
  if (DAT_0089f358 != 0) {
    DAT_0089f360 = (float)DAT_0089f358 * f_100 + DAT_0089f360;
  }
  (&ITEM_LEN)[DAT_0089f35c + DAT_0089f364] = DAT_0089f360;
  return;
}


