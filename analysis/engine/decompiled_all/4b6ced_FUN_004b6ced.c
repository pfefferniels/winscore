// FUN_004b6ced @ 004b6ced (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b6ced(int *param_1,int *param_2)

{
  int iVar1;
  
  DAT_01c585c4 = 1;
  *param_2 = (int)ROUND((float)(&ITEM_LEN)[*param_1]);
  DAT_01c58920 = (int)ROUND((float)(&ITEM_P2)[*param_1]);
  thunk_FUN_0054c419(&DAT_01c58924,&DAT_00764830);
  DAT_0089f4a0 = *param_2;
  if (0xe < DAT_0089f4a0) {
    DAT_0089f4a0 = 0xe;
  }
  DAT_01c585c0 = 3;
  for (iVar1 = DAT_0089f4a0 + -2; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined4 *)(DAT_01c585c0 * 4 + 0x1c58918) = (&ITEM_LEN)[DAT_01c585c0 + *param_1];
    DAT_01c585c0 = DAT_01c585c0 + 1;
  }
  if ((DAT_01c58930 <= f_m4) && ((float)(&ITEM_P1)[*param_1] == f_1)) {
    DAT_01c5892c = f_0;
    DAT_01c5893c = f_0;
  }
  return;
}


