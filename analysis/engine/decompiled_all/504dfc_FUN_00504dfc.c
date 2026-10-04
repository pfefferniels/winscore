// FUN_00504dfc @ 00504dfc (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00504dfc(int *param_1,int *param_2,int *param_3,short *param_4)

{
  int iVar1;
  
  LOAD_I = *param_2;
  _DAT_00909e9c = *param_1;
  DAT_00909e98 = 32000;
  DAT_00909e94 = 1;
  iVar1 = DAT_01b34584;
  do {
    if (iVar1 < 1) {
      *param_1 = DAT_00909e8c;
      return;
    }
    LOAD_CODE = (int)*(char *)((int)&DAT_01b34588 + DAT_00909e94 + 3);
    if ((LOAD_CODE == 1) || (LOAD_CODE == 0xe)) {
      DAT_00909e90 = *(int *)(&DAT_01b36c98 + DAT_00909e94 * 4);
      if (*param_4 == 0) {
        if (DAT_00909e90 < *param_3) {
          DAT_00909e90 = *(int *)(&DAT_01b36c98 + DAT_00909e94 * 4) - _DAT_00909e9c;
          if (DAT_00909e90 < 0) {
            DAT_00909e90 = -DAT_00909e90;
          }
          if (DAT_00909e90 <= DAT_00909e98) goto LAB_00504f41;
        }
      }
      else if (LOAD_I < DAT_00909e90) {
        DAT_00909e90 = *(int *)(&DAT_01b36c98 + DAT_00909e94 * 4) - _DAT_00909e9c;
        if (DAT_00909e90 < 0) {
          DAT_00909e90 = -DAT_00909e90;
        }
        if (DAT_00909e90 < DAT_00909e98) {
LAB_00504f41:
          DAT_00909e98 = DAT_00909e90;
          DAT_00909e8c = *(int *)(&DAT_01b36c98 + DAT_00909e94 * 4);
          if ((LOAD_CODE != 1) && (*param_4 != 0)) {
            LOAD_I = DAT_00909e90;
            DAT_00909e98 = 32000;
          }
        }
      }
    }
    DAT_00909e94 = DAT_00909e94 + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


