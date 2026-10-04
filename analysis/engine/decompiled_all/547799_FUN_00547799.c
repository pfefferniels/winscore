// FUN_00547799 @ 00547799 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00547799(int *param_1,float *param_2)

{
  int iVar1;
  
  if (ITEM_I < DAT_01fbb79c) {
    if ((*param_2 == f_16) && (*param_1 = 0xd, param_2[0xd] == f_m1)) {
      *param_1 = 0x10;
    }
    (&ITEM_LEN)[ITEM_WORDS] = (float)*param_1;
    DAT_0099f8ac = ITEM_WORDS + 1;
    thunk_FUN_0054c590(param_2,&ITEM_LEN + DAT_0099f8ac,param_1);
    if (*param_1 < 3) {
      *param_1 = 3;
      (&ITEM_LEN)[ITEM_WORDS] = f_3;
      (&ITEM_P3)[ITEM_WORDS] = f_0;
    }
    DAT_0099f8ac = DAT_0099f8ac + *param_1;
    if (*param_2 == f_16) {
      DAT_0099f8a8 = (int)ROUND((param_2[0xb] + f_3) / f_4);
      thunk_FUN_0054c590(&DAT_01fb8cf8,&ITEM_LEN + DAT_0099f8ac,&DAT_0099f8a8);
      (&ITEM_LEN)[ITEM_WORDS] = (float)(DAT_0099f8a8 + *param_1);
      DAT_0099f8ac = DAT_0099f8a8 + DAT_0099f8ac;
    }
    iVar1 = DAT_0099f8ac;
    ITEM_WORDS = DAT_0099f8ac;
    if (EDIT_ITEM == 0) {
      DAT_020527e8 = ITEM_I + 1;
      ITEM_I = DAT_020527e8;
    }
    DAT_0099f8ac = ITEM_I + 1;
    if (EDIT_ITEM != 0) {
      DAT_0099f8ac = ITEM_I + 2;
    }
    (&ITEM_PTR0)[DAT_0099f8ac] = iVar1;
  }
  else {
    thunk_FUN_004a6228();
  }
  return;
}


