// FUN_00457f60 @ 00457f60 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00457f60(int *param_1)

{
  int iVar1;
  
  DAT_007fecb8 = 1;
  DAT_007fecb4 = 0;
  do {
    _DAT_007fecb0 = 0;
    iVar1 = FUN_00458001(&DAT_007fecb8,&DAT_007fecac,&DAT_007fecb4,&DAT_007fecb0,param_1);
    if (iVar1 == 0) break;
    DAT_007fecb8 = DAT_007fecac + 1;
  } while (DAT_007fecb8 < *param_1);
  if (DAT_007fecb4 != 0) {
    DAT_01c0c260 = DAT_007fecb4;
  }
  return;
}


