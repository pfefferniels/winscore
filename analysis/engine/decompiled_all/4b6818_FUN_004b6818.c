// FUN_004b6818 @ 004b6818 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b6818(float *param_1,float *param_2,int *param_3,int *param_4)

{
  *param_2 = f_2_5;
  DAT_01c585d0 = f_1;
  if (((*param_3 < 5) || (DAT_01c585c0 = (int)ROUND(DAT_01c5892c), DAT_01c585c0 < 1)) ||
     (6 < DAT_01c585c0)) goto LAB_004b69b8;
  DAT_01c58940 = f_0;
  switch(DAT_01c585c0) {
  case 0:
    goto LAB_004b69b8;
  default:
    DAT_01c585d0 = _DAT_01c58938 * f_2_2;
    break;
  case 2:
    DAT_01c585d0 = _DAT_01c58938 * f_3_3;
    break;
  case 3:
    DAT_01c585d0 = _DAT_01c58938 * f_5_4 + DAT_01c58950;
    break;
  case 4:
    DAT_01c585d0 = _DAT_01c58938 * f_2;
    goto LAB_004b6926;
  case 5:
    DAT_01c585d0 = _DAT_01c58938 * f_5_4 + DAT_01c5894c + DAT_01c58950;
LAB_004b6926:
    *param_2 = _DAT_01c58938 * f_6 + DAT_01c5894c + DAT_01c58950;
    goto LAB_004b69b8;
  case 6:
    DAT_01c585d0 = _DAT_01c58938 * f_4_3 + DAT_01c58950;
    *param_2 = _DAT_01c58938 * f_7 + DAT_01c5894c + DAT_01c58950;
    goto LAB_004b69b8;
  }
  DAT_01c585d0 = DAT_01c5894c + DAT_01c585d0;
LAB_004b69b8:
  if ((*param_4 == 3) || (*param_4 == 0x11)) {
    DAT_01c585d0 = DAT_01c585d0 - f_1;
  }
  *param_1 = DAT_01c585d0;
  if (DAT_01c58934 != f_0) {
    DAT_01c585d0 = DAT_01c58934;
    *param_1 = *param_1 - DAT_01c58934;
    *param_2 = DAT_01c585d0 + *param_2;
    if (DAT_01c585d0 == f_m12345_67) {
      thunk_FUN_0054d831(&DAT_007647ec,3);
    }
  }
  return;
}


