// FUN_0049daa6 @ 0049daa6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0049daa6(float *param_1,float *param_2)

{
  int iVar1;
  
  *param_2 = f_m999;
  DAT_008389b4 = DAT_01b117ac;
  for (iVar1 = (ITEM_I - DAT_01b117ac) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_01b117b0 = (&ITEM_PTR0)[DAT_008389b4];
    DAT_008389b0 = (int)ROUND((float)(&ITEM_P1)[DAT_01b117b0]);
    if (((DAT_008389b0 == 1) && (ABS((float)(&ITEM_P3)[DAT_01b117b0] - *param_1) <= f_0_1)) &&
       (*param_2 < (float)(&ITEM_P4)[DAT_01b117b0])) {
      *param_2 = (float)(&ITEM_P4)[DAT_01b117b0];
    }
    DAT_008389b4 = DAT_008389b4 + 1;
  }
  return;
}


