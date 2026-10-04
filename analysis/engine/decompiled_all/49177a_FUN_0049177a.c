// FUN_0049177a @ 0049177a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049177a(int *param_1)

{
  if (*param_1 == 0) {
    DAT_00829d24 = DAT_01a14950;
    DAT_00829d20 = DAT_01a1494c;
    *param_1 = 1;
    DAT_020b90a2 = DAT_00762d90;
    P2 = f_17;
    FUN_00488a8d();
  }
  _DAT_00829d1c = DAT_00829d24 - DAT_01a14950;
  _DAT_00829d18 = DAT_00829d20 - DAT_01a1494c;
  VIEW_DX = (VIEW_DX - DAT_00829d24) + DAT_01a14950;
  DAT_00829d24 = DAT_01a14950;
  VIEW_DY = (DAT_00829d20 + VIEW_DY) - DAT_01a1494c;
  DAT_00829d20 = DAT_01a1494c;
  draw_items();
  FUN_005f34d1(&stack0xfffffffc,0x49186c);
  _DAT_007a0b7c = i_538976288;
  return;
}


