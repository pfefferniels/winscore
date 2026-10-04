// FUN_00458001 @ 00458001 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


undefined4 FUN_00458001(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  DAT_007fecc8 = *param_4;
  DAT_007fecc4 = *param_3;
  *param_4 = 0;
  DAT_007fecc0 = *param_1;
  iVar3 = (*param_5 - DAT_007fecc0) + 1;
  do {
    if (iVar3 < 1) {
      return 0;
    }
    DAT_007fecbc = (int)*(short *)((int)&DAT_01fbb8dc + DAT_007fecc0 * 2 + 2);
    if (DAT_007fecbc < 0) {
      if (DAT_007fecbc == -2) {
        *param_4 = DAT_007fecc0;
      }
      if (*param_4 != 0) {
        iVar2 = *param_4;
        iVar1 = *param_5;
        *param_2 = iVar2;
        for (iVar2 = (iVar1 - iVar2) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
          DAT_007fecbc = (int)*(short *)((int)&DAT_01fbb8dc + *param_2 * 2 + 2);
          if ((DAT_007fecbc != 0) || (DAT_007fecc8 != 0)) {
            *param_3 = *param_3 + 1;
            *(undefined4 *)(&DAT_01c0c258 + *param_3 * 0xc) = (&PT_X0)[*param_2];
            *(undefined4 *)(&DAT_01c0c25c + *param_3 * 0xc) = (&PT_Y0)[*param_2];
            (&DAT_01c0c260)[*param_3 * 3] = 0;
            if (DAT_007fecbc == -3) {
              (&DAT_01c0c26c)[DAT_007fecc4 * 3] = 1;
              return 1;
            }
          }
          *param_2 = *param_2 + 1;
        }
      }
    }
    else if (DAT_007fecbc != 0) {
      *param_4 = DAT_007fecc0;
    }
    DAT_007fecc0 = DAT_007fecc0 + 1;
    iVar3 = iVar3 + -1;
  } while( true );
}


