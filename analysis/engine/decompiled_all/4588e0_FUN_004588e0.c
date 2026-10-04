// FUN_004588e0 @ 004588e0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004588e0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  DAT_01c00580 = 32000;
  DAT_01c00584 = 32000;
  _DAT_01c00588 = 32000;
  _DAT_01c0058c = 32000;
  DAT_01c00590 = f_32000;
  DAT_01c00594 = 1;
  if (*param_1 != 0) {
    DAT_01c00594 = DAT_01c23744 + 1;
    *param_2 = *param_2 - DAT_01c23744;
  }
  DAT_01c005b4 = 0;
  (&DAT_01c17e00)[*param_2 * 2] = DAT_01c00590;
  (&DAT_01c17e04)[*param_2 * 2] = DAT_01c00590;
  _DAT_01c00598 = 1;
  fVar4 = (float10)FUN_005ff381(&stack0xfffffffc,0x4589ad);
  *(int *)(puVar5 + -0x38) = (int)ROUND(fVar4);
  DAT_007fecfc = *(int *)(puVar5 + -0x38);
  fVar4 = (float10)FUN_005ff381(puVar5,0x4589da);
  *(int *)(puVar5 + -0x38) = (int)ROUND(fVar4);
  DAT_01c0059c = DAT_01c00594 + 1;
  iVar3 = (**(int **)(puVar5 + 0xc) - DAT_01c0059c) + 2;
  iVar1 = *(int *)(puVar5 + -0x38);
  iVar2 = DAT_007fecfc;
  do {
    DAT_007fecfc = iVar2;
    DAT_007fecf8 = iVar1;
    if (iVar3 < 1) {
      **(int **)(puVar5 + 0xc) = DAT_01c005b4;
      return;
    }
    fVar4 = (float10)FUN_005ff381(puVar5,0x458a2b);
    *(int *)(puVar5 + -0x38) = (int)ROUND(fVar4);
    DAT_01c005a0 = *(int *)(puVar5 + -0x38);
    fVar4 = (float10)FUN_005ff381(puVar5,0x458a58);
    *(int *)(puVar5 + -0x38) = (int)ROUND(fVar4);
    DAT_01c005a4 = *(int *)(puVar5 + -0x38);
    if (10000 < DAT_007fecfc) {
      *(undefined4 *)(puVar5 + -0x10) = 0;
      goto LAB_00458b6c;
    }
    if ((DAT_01c005a0 == DAT_007fecfc) && (DAT_01c00580 == DAT_007fecfc)) {
      *(undefined4 *)(puVar5 + -0xc) = 0;
    }
    else if ((DAT_01c005a4 == DAT_007fecf8) && (DAT_01c00584 == DAT_007fecf8)) {
      *(undefined4 *)(puVar5 + -8) = 0;
    }
    else {
      if ((DAT_01c00580 == DAT_007fecfc) || (DAT_01c00584 == DAT_007fecf8)) {
        *(undefined4 *)(puVar5 + -4) = 0;
LAB_00458b6c:
        DAT_01c005b4 = DAT_01c005b4 + 1;
      }
      else {
        *(int *)(puVar5 + -0x38) = DAT_007fecf8 - _DAT_01c0058c;
        DAT_01c005b0 = (float)*(int *)(puVar5 + -0x38);
        if (DAT_01c005b0 != f_0) {
          *(int *)(puVar5 + -0x38) = DAT_007fecfc - _DAT_01c00588;
          DAT_01c005b0 = (float)*(int *)(puVar5 + -0x38) / DAT_01c005b0;
        }
        if (DAT_01c00590 != DAT_01c005b0) goto LAB_00458b6c;
      }
      (&DAT_01c1e900)[DAT_01c005b4 * 2] = DAT_007fecfc;
      (&DAT_01c1e904)[DAT_01c005b4 * 2] = DAT_007fecf8;
      _DAT_01c00588 = DAT_007fecfc;
      _DAT_01c0058c = DAT_007fecf8;
      DAT_01c00590 = DAT_01c005b0;
    }
    DAT_01c0059c = DAT_01c0059c + 1;
    iVar3 = iVar3 + -1;
    iVar1 = DAT_01c005a4;
    iVar2 = DAT_01c005a0;
    DAT_01c00580 = DAT_007fecfc;
    DAT_01c00584 = DAT_007fecf8;
  } while( true );
}


