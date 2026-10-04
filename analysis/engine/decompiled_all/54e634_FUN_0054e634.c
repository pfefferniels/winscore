// FUN_0054e634 @ 0054e634 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054e634(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  *param_2 = 0;
  DAT_009a2afc = 1;
  iVar2 = ITEM_I;
  do {
    if (iVar2 < 1) {
      return;
    }
    DAT_009a2af8 = (&ITEM_PTR0)[DAT_009a2afc];
    if (((float)(&ITEM_P1)[DAT_009a2af8] == f_14) &&
       (((float)(&ITEM_LEN)[DAT_009a2af8] <= f_4 || ((float)(&ITEM_P5)[DAT_009a2af8] <= f_7)))) {
      DAT_009a2af4 = (float)(&ITEM_P3)[DAT_009a2af8];
      if (*param_2 != 0) {
        iVar1 = *param_2;
        DAT_009a2af0 = 1;
        for (; 0 < iVar1; iVar1 = iVar1 + -1) {
          if (ABS(DAT_009a2af4 - *(float *)(param_1 + -4 + DAT_009a2af0 * 4)) < f_4)
          goto LAB_0054e76c;
          DAT_009a2af0 = DAT_009a2af0 + 1;
        }
      }
      *param_2 = *param_2 + 1;
      *(float *)(param_1 + -4 + *param_2 * 4) = DAT_009a2af4;
    }
LAB_0054e76c:
    DAT_009a2afc = DAT_009a2afc + 1;
    iVar2 = iVar2 + -1;
  } while( true );
}


