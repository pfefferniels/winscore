// FUN_00562cc6 @ 00562cc6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00562cc6(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  DAT_01a1ad64 = *param_2;
  if (DAT_01a1ad64 == 0xc) {
    DAT_01a1ad68 = 7;
  }
  else {
    if (DAT_01a1ad64 != -0xc) {
      DAT_01a1ad6c = (*param_1 + DAT_01a1ad64 * -5) % 0xc;
      if (DAT_01a1ad6c < -6) {
        DAT_01a1ad6c = DAT_01a1ad6c + 0xc;
      }
      if (6 < DAT_01a1ad6c) {
        DAT_01a1ad6c = DAT_01a1ad6c + -0xc;
      }
      iVar1 = DAT_01a1ad6c;
      if (DAT_01a1ad6c < 0) {
        iVar1 = -DAT_01a1ad6c;
      }
      if ((iVar1 == 6) && (DAT_01a1ad6c = 6, *param_1 < 0)) {
        DAT_01a1ad6c = -6;
      }
      FUN_00562f53(param_1,&DAT_01a1ad68);
      FUN_00562f53(&DAT_01a1ad6c,&DAT_01a1ad70);
      DAT_01a1ad70 = DAT_01a1ad68 - DAT_01a1ad70;
      DAT_01a1ad68 = DAT_01a1ad70;
      if (DAT_01a1ad64 < 0) {
        if (DAT_01a1ad70 < 0) {
          DAT_01a1ad68 = -7 - DAT_01a1ad70;
        }
        if (0 < DAT_01a1ad70) {
          DAT_01a1ad68 = -DAT_01a1ad70;
        }
        if ((DAT_01a1ad64 < -10) && (-6 < DAT_01a1ad68)) {
          DAT_01a1ad68 = -DAT_01a1ad70 + -7;
          if (-6 < DAT_01a1ad68) {
            DAT_01a1ad68 = -DAT_01a1ad70 + -0xe;
          }
        }
        if (DAT_01a1ad64 < -0x15) {
          DAT_01a1ad68 = DAT_01a1ad68 + -7;
        }
      }
      else {
        if (0 < DAT_01a1ad70) {
          DAT_01a1ad68 = 7 - DAT_01a1ad70;
        }
        if (DAT_01a1ad70 < 0) {
          DAT_01a1ad68 = -DAT_01a1ad70;
        }
        if ((10 < DAT_01a1ad64) && (DAT_01a1ad68 < 6)) {
          DAT_01a1ad68 = -DAT_01a1ad70 + 7;
          if (DAT_01a1ad68 < 6) {
            DAT_01a1ad68 = -DAT_01a1ad70 + 0xe;
          }
        }
        if (0x15 < DAT_01a1ad64) {
          DAT_01a1ad68 = DAT_01a1ad68 + 7;
        }
      }
      goto LAB_00562f36;
    }
    DAT_01a1ad68 = -7;
  }
  DAT_01a1ad6c = *param_1;
LAB_00562f36:
  *param_4 = DAT_01a1ad68;
  *param_3 = DAT_01a1ad6c;
  return;
}


