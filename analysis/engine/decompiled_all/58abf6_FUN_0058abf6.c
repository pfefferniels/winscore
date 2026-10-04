// FUN_0058abf6 @ 0058abf6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058abf6(void)

{
  int iVar1;
  undefined1 *puVar2;
  float10 in_ST0;
  float10 fVar3;
  float10 extraout_ST1;
  
  puVar2 = &stack0xfffffffc;
  DAT_009a932c = 1;
  iVar1 = DAT_01a9f30c;
  do {
    if (iVar1 < 1) {
      DAT_009a932c = DAT_01a9f30c + 1;
      DAT_01a9f310 = (float)(&DAT_01a18340)[DAT_01a9f30c];
      DAT_01f95c94 = P3;
LAB_0058ad17:
      DAT_01f95c94 = DAT_01f95c94 - DAT_01a9f310;
      if (DAT_01f95c94 == f_0) {
        DAT_01a9f310 = f_0;
      }
      else {
        in_ST0 = ((float10)LOAD_P3 - (float10)DAT_01a9f310) / (float10)DAT_01f95c94;
        DAT_01a9f310 = (float)(((float10)DAT_009a932c + in_ST0) - (float10)f_1);
        if (LOAD_CODE == 6) {
          ffree(in_ST0);
          puVar2 = &stack0xfffffffc;
          fVar3 = (float10)FUN_005ff381(&stack0xfffffffc,0x58ad89);
          *(int *)(puVar2 + -0x3c) = (int)ROUND(fVar3);
          DAT_01a9f310 = (float)*(int *)(puVar2 + -0x3c);
          in_ST0 = extraout_ST1;
        }
        *(undefined4 *)(puVar2 + -4) = 0;
      }
LAB_0058adb8:
      ffree(in_ST0);
      return;
    }
    DAT_01f95c94 = LOAD_P3 - (float)(&DAT_01a18340)[DAT_009a932c];
    in_ST0 = (float10)DAT_01f95c94;
    if (ABS(in_ST0) < (float10)f_0_1) {
      DAT_01a9f310 = (float)DAT_009a932c;
      goto LAB_0058adb8;
    }
    if (DAT_01f95c94 < f_0) {
      DAT_01a9f310 = P2;
      if (1 < DAT_009a932c) {
        DAT_01a9f310 = *(float *)(DAT_009a932c * 4 + 0x1a1833c);
      }
      DAT_01f95c94 = (float)(&DAT_01a18340)[DAT_009a932c];
      goto LAB_0058ad17;
    }
    DAT_009a932c = DAT_009a932c + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


