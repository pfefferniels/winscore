// FUN_004a47b0 @ 004a47b0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a47b0(int *param_1,int *param_2)

{
  int iVar1;
  
  DAT_00838eb0 = 1;
  _DAT_00838eb4 = f_0;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_00838eac = (&ITEM_PTR0)[DAT_00838eb0];
    if ((((float)(&ITEM_P1)[DAT_00838eac] == f_8) &&
        ((((DAT_00838ea8 = (float)(&ITEM_P2)[DAT_00838eac], DAT_00838ea8 < f_200 && (*param_1 == 0))
          || (*param_1 == 0)) || (f_200 <= DAT_00838ea8)))) && (_DAT_00838eb4 < DAT_00838ea8)) {
      _DAT_00838eb4 = DAT_00838ea8;
    }
    DAT_00838eb0 = DAT_00838eb0 + 1;
  }
  *param_2 = (int)ROUND(_DAT_00838eb4);
  return;
}


