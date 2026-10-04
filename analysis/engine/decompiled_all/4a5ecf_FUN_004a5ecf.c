// FUN_004a5ecf @ 004a5ecf (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a5ecf(void)

{
  float10 fVar1;
  
  if (DAT_020b9440 == f_16) {
    _DAT_0083918c = DAT_020b9470 + DAT_020b9448;
    _DAT_00839188 = DAT_020b9454;
    if (DAT_020b9454 == f_0) {
      _DAT_00839188 = f_1;
    }
    fVar1 = (float10)amod(&DAT_00839188,&DAT_00763a50);
    _DAT_00839188 = (float)((fVar1 * (float10)STEP) / (float10)f_1_84375);
  }
  _DAT_00839184 = &DAT_00791870;
  if (DAT_020b9440 == f_12) {
    _DAT_00839184 = &DAT_007918a8;
  }
  return;
}


