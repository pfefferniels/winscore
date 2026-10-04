// FUN_0049846f @ 0049846f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0049846f(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  DAT_0082a6d4 = *param_4;
  DAT_0082a6d0 = 0;
  if ((DAT_0078b4e4 == 0x53) || (DAT_0078b4e4 == 0x58)) {
    DAT_0082a6d0 = 1;
  }
  thunk_FUN_0054c4c6(param_2,&DAT_0082a6ec,&DAT_0082a6d4);
  thunk_FUN_0054c590(param_1,&DAT_01e99980,param_3);
  DAT_0082a6cc = 1;
  DAT_0082a6b4 = DAT_0082a6d4;
  for (iVar2 = DAT_0082a6d4; DAT_0082a6d4 = DAT_0082a6b4, 0 < iVar2; iVar2 = iVar2 + -1) {
    iVar1 = *(int *)(DAT_0082a6cc * 4 + param_2 + -4);
    DAT_0082a6e8 = (int)ROUND(*(float *)(param_1 + 8 + iVar1 * 4) * f_100);
    DAT_0082a6c4 = (int)ROUND(*(float *)(param_1 + -4 + iVar1 * 4));
    if (DAT_0082a6c4 < 3) {
      DAT_0082a6e8 = 0;
    }
    DAT_0082a6e4 = 0;
    if ((1 < DAT_0082a6c4) &&
       (DAT_0082a6e4 = (int)ROUND(*(float *)(param_1 + 4 + iVar1 * 4)), DAT_0082a6d0 != 0)) {
      DAT_0082a6e4 = DAT_0082a6e4 * 1000000;
    }
    *(int *)(&DAT_008304a8 + DAT_0082a6cc * 4) = DAT_0082a6e4 + DAT_0082a6e8;
    DAT_0082a6cc = DAT_0082a6cc + 1;
    DAT_0082a6b4 = DAT_0082a6d4;
  }
  DAT_0082a6c0 = 1;
  DAT_0082a6bc = 1;
  DAT_0082a6b8 = 1;
  while( true ) {
    DAT_0082a6e8 = 99000000;
    DAT_0082a6cc = DAT_0082a6b8;
    for (iVar2 = (DAT_0082a6b4 - DAT_0082a6b8) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
      if (*(int *)(&DAT_008304a8 + DAT_0082a6cc * 4) < DAT_0082a6e8) {
        DAT_0082a6e8 = *(int *)(&DAT_008304a8 + DAT_0082a6cc * 4);
        DAT_0082a6c4 = DAT_0082a6cc;
      }
      DAT_0082a6cc = DAT_0082a6cc + 1;
    }
    if (DAT_0082a6b8 == DAT_0082a6c4) {
      DAT_0082a6b8 = DAT_0082a6b8 + 1;
    }
    else if (DAT_0082a6b4 == DAT_0082a6c4) {
      DAT_0082a6b4 = DAT_0082a6b4 + -1;
    }
    else {
      *(undefined4 *)(&DAT_008304a8 + DAT_0082a6c4 * 4) = 0x5e69ec1;
    }
    DAT_0082a6c8 = (&DAT_0082a6e8)[DAT_0082a6c4];
    DAT_0082a6c4 = (int)ROUND((float)(&DAT_01e9997c)[DAT_0082a6c8] + f_1);
    thunk_FUN_0054c590(&DAT_01e9997c + DAT_0082a6c8,DAT_0082a6bc * 4 + param_1 + -4,&DAT_0082a6c4);
    *(int *)(DAT_0082a6c0 * 4 + param_2 + -4) = DAT_0082a6bc;
    if (DAT_0082a6d4 == DAT_0082a6c0) break;
    DAT_0082a6bc = DAT_0082a6c4 + DAT_0082a6bc;
    DAT_0082a6c0 = DAT_0082a6c0 + 1;
  }
  return;
}


