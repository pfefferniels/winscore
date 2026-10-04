// FUN_004bbc93 @ 004bbc93 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bbc93(float *param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = thunk_FUN_0059b710(&DAT_0089f7d0);
  if (iVar1 == 2) {
    return;
  }
  puVar2 = &DAT_009ae2bc;
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  thunk_FUN_00518448();
  DAT_01be0944 = (int)ROUND(P1 * f_100 + f_0_5);
  DAT_0089f7c4 = DAT_0089f7d0;
  DAT_00795460 = DAT_0089f7d8;
  P3 = (float)_DAT_0089f7d4;
  if (P3 == f_0) {
    P3 = f_10;
  }
  if (DAT_01be0944 == 0) {
    DAT_01be0944 = 200;
  }
  DAT_0089f7c0 = 1;
  *(undefined4 *)(*param_5 * 4 + param_2 + -4) = 30000;
  DAT_0089f7bc = DAT_01be0940;
  *param_6 = 0;
  DAT_0089f7b8 = 1;
  if (DAT_00795460 == 0) {
    DAT_00795460 = 1;
  }
  if (DAT_00795460 % 2 == 0) {
    DAT_0089f7b8 = 2;
  }
  _DAT_0089f7b4 = f_0;
LAB_004bbdf6:
  DAT_0089f7b0 = DAT_01be0944;
  *param_1 = (float)(DAT_0089f7bc / DAT_01ade878) + f_0_5;
  DAT_0089f7ac = (int)ROUND(*param_1 / (_DAT_01ade87c * P3) + f_0_5);
  if (0 < DAT_0089f7c4) {
    DAT_0089f7ac = DAT_0089f7c4;
  }
  if (DAT_0089f7ac < 2) {
    DAT_0089f7b8 = 1;
  }
  DAT_0089f7c4 = DAT_0089f7c4 - DAT_0089f7b8;
  *param_1 = (float)DAT_0089f7ac * P3;
  _DAT_0089f7a8 = (float)(DAT_0089f7b8 * DAT_0089f7bc) / *param_1;
  if (_DAT_0089f7b4 == f_0) {
    _DAT_0089f7b4 = *param_1;
  }
  DAT_0089f7c8 = (int)ROUND(P3 * _DAT_0089f7a8);
  DAT_0089f7a4 = DAT_0089f7c8 / 2;
  do {
    DAT_0089f7cc = 0;
    iVar1 = (*param_5 - DAT_0089f7c0) + 1;
    DAT_0089f794 = DAT_0089f7c0;
    while ((0 < iVar1 &&
           (DAT_0089f7cc = *(int *)(param_3 + -4 + DAT_0089f794 * 4) + DAT_0089f7cc,
           DAT_0089f7cc < DAT_0089f7c8))) {
      DAT_0089f794 = DAT_0089f794 + 1;
      iVar1 = iVar1 + -1;
    }
    DAT_0089f79c = -1;
    DAT_0089f790 = DAT_0089f7cc;
    DAT_0089f78c = DAT_0089f7cc;
    DAT_0089f788 = DAT_0089f7cc;
    DAT_0089f798 = DAT_0089f794;
    DAT_0089f7a0 = DAT_0089f794;
    while( true ) {
      if (DAT_01be0944 <= *(int *)(DAT_0089f7a0 * 4 + param_2 + -4)) {
        *param_6 = *param_6 + 1;
        *(int *)(*param_6 * 4 + param_4 + -4) = DAT_0089f7a0;
        *param_6 = *param_6 + 1;
        *(int *)(*param_6 * 4 + param_4 + -4) = (int)ROUND((float)(DAT_0089f7b8 * 100) + P3);
        DAT_0089f7b8 = 2;
        DAT_0089f7bc = DAT_0089f7bc - DAT_0089f790;
        if (DAT_0089f7bc <= DAT_01ade878) {
          *param_6 = *param_6 + 1;
          *(int *)(*param_6 * 4 + param_4 + -0xc) = *param_5;
          return;
        }
        _DAT_0089f784 = (float)DAT_01be0944 / f_100;
        DAT_01be0944 = DAT_0089f7b0;
        DAT_0089f7c0 = DAT_0089f7a0 + 1;
        goto LAB_004bbdf6;
      }
      if (DAT_0089f790 < DAT_0089f7a4) break;
      DAT_0089f79c = DAT_0089f79c + 1;
      if (DAT_0089f79c == 0) {
        DAT_0089f794 = DAT_0089f794 + 1;
        DAT_0089f788 = *(int *)(param_3 + -4 + DAT_0089f794 * 4) + DAT_0089f788;
        DAT_0089f790 = DAT_0089f788;
        DAT_0089f7a0 = DAT_0089f794;
      }
      else {
        if (DAT_0089f7b8 <= DAT_0089f79c) {
          DAT_0089f79c = -1;
        }
        DAT_0089f798 = DAT_0089f798 + -1;
        DAT_0089f78c = DAT_0089f78c - *(int *)(DAT_0089f798 * 4 + param_3 + -4);
        DAT_0089f790 = DAT_0089f78c;
        DAT_0089f7a0 = DAT_0089f798;
      }
    }
    DAT_01be0944 = DAT_01be0944 + -0x32;
  } while( true );
}


