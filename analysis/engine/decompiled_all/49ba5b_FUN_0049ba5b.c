// FUN_0049ba5b @ 0049ba5b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049ba5b(int *param_1)

{
  _DAT_00838904 = (float)(&ITEM_LEN)[*param_1 + LOAD_W];
  if ((_DAT_01b117c8 <= _DAT_00838904) && (_DAT_00838904 <= _DAT_01b117cc)) {
    if (DAT_020492a4 < DAT_0204e0c8) {
      DAT_020492a4 = DAT_020492a4 + 1;
    }
    else {
      thunk_FUN_0057237c();
    }
    (&DAT_020492a4)[DAT_020492a4] = -*param_1 - LOAD_W;
    if (DAT_020492a0 == 0) {
      DAT_020492a0 = LOAD_I;
    }
  }
  return;
}


