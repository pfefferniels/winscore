// FUN_0049dbb2 @ 0049dbb2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0049dbb2(float *param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  
  DAT_01b117a0 = *param_2;
  *param_2 = f_999;
  DAT_008389bc = DAT_01b117ac;
  for (iVar2 = (ITEM_I - DAT_01b117ac) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
    iVar1 = (&ITEM_PTR0)[DAT_008389bc];
    DAT_008389b8 = (int)ROUND((float)(&ITEM_P1)[iVar1]);
    if (((DAT_008389b8 == 1) && (ABS((float)(&ITEM_P3)[iVar1] - *param_1) <= f_3)) &&
       ((float)(&ITEM_P4)[iVar1] < *param_2)) {
      *param_2 = (float)(&ITEM_P4)[iVar1];
    }
    DAT_008389bc = DAT_008389bc + 1;
  }
  if (*param_2 == f_999) {
    *param_2 = DAT_01b117a0;
  }
  DAT_01b117b0 = (int)ROUND(*param_2) % 100 + -2;
  *param_2 = (float)DAT_01b117b0;
  if ((DAT_01b117b0 % 2 != 0) && (1 < DAT_01b117b0)) {
    *param_2 = *param_2 + f_0_4;
  }
  return;
}


