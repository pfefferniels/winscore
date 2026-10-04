// FUN_0049cc74 @ 0049cc74 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049cc74(int *param_1)

{
  int iVar1;
  unkbyte10 in_ST0;
  
  _DAT_00838988 = *(float *)(&DAT_01c6da90 + *param_1 * 4);
  if (_DAT_00838988 != f_0) {
    _DAT_01c4c858 = (float)(&DAT_01c6da68)[*param_1] - f_0_4;
    DAT_00838984 = DAT_01c4c838;
    for (iVar1 = DAT_01c4c83c - DAT_01c4c838; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_00838980 = (&DAT_01c4637c)[DAT_00838984];
      if (((float)(&DAT_01c6da60)[DAT_00838980] == f_14) &&
         (_DAT_01c4c85c = (float)(&DAT_01c6da68)[DAT_00838980] - f_0_4,
         _DAT_01c4c858 < _DAT_01c4c85c)) goto LAB_0049cd82;
      DAT_00838984 = DAT_00838984 + 1;
    }
    _DAT_01c4c85c = f_199_6;
LAB_0049cd82:
    do {
      ffree(in_ST0);
      in_ST0 = FUN_0049ce38(&DAT_00838988);
      if (f_0 <= _DAT_00838988) goto LAB_0049ce0b;
      DAT_00838980 = (int)ROUND(-(float10)_DAT_00838988);
      ffree((float10)_DAT_00838988);
      in_ST0 = thunk_FUN_00518448();
      if (P1 == f_0) break;
      _DAT_00838988 = P1;
    } while( true );
  }
LAB_0049ce2d:
  ffree(in_ST0);
  return;
LAB_0049ce0b:
  (&DAT_01c6da6c)[*param_1] = f_m8;
  goto LAB_0049ce2d;
}


