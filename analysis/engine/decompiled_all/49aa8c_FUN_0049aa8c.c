// FUN_0049aa8c @ 0049aa8c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049aa8c(void)

{
  int iVar1;
  
  DAT_01c4c784 = 0;
  if (1 < DAT_01c4c780) {
    DAT_008388d0 = -1;
    DAT_008388cc = 1;
    _DAT_008388d4 = f_0;
    for (iVar1 = DAT_01ba2064; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_008388c8 = (&DAT_01c4637c)[DAT_008388cc];
      DAT_008388c4 = (int)ROUND((float)(&DAT_01c6da60)[DAT_008388c8]);
      if (DAT_008388d0 < 0) {
        if (DAT_008388c4 < 3) {
          DAT_008388d0 = 0;
        }
      }
      else if (DAT_008388c4 == 0xe) {
        if (f_0_1 <= ABS(_DAT_008388d4 - (float)(&DAT_01c6da68)[DAT_008388c8])) {
          _DAT_008388d4 = (float)(&DAT_01c6da68)[DAT_008388c8];
          DAT_008388d0 = DAT_008388d0 + 1;
          if (DAT_01c4c780 <= DAT_008388d0) break;
        }
        DAT_008388c0 = DAT_008388cc + 1;
      }
      DAT_008388cc = DAT_008388cc + 1;
    }
    DAT_008388d0 = (&DAT_01c4637c)[DAT_008388c0];
    DAT_01ba2068 = (DAT_01ba2068 - DAT_008388d0) + 1;
    thunk_FUN_0054c590(&DAT_01c6da5c + DAT_008388d0 * 4,&DAT_01c6da60,&DAT_01ba2068);
    thunk_FUN_0049836a(&DAT_01c6da60,&DAT_01c46380,&DAT_01ba2068,&DAT_01ba2064,&DAT_01ba2068);
    thunk_FUN_0049846f(&DAT_01c6da60,&DAT_01c46380,&DAT_01ba2068,&DAT_01ba2064);
    *(int *)(&DAT_01c424fc + DAT_01ba207c * 4) =
         (*(int *)(&DAT_01c424fc + DAT_01ba207c * 4) - DAT_01c4c780) + 1;
  }
  return;
}


