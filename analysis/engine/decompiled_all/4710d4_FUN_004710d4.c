// FUN_004710d4 @ 004710d4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004710d4(void)

{
  if (DAT_0078b4e0 != 0x4c) {
    P1 = f_1;
    P2 = f_16;
    P3 = f_0;
    DAT_01c585dc = 0xc;
    DAT_0078b4e0 = 0;
    DAT_0078b4e4 = 0;
    _DAT_01fbb740 = 0;
    DAT_00824f58 = DAT_0078b4f0;
    thunk_FUN_00449ea8(&DAT_01c585dc);
    DAT_0078b4f0 = DAT_00824f58;
  }
  DAT_020527c4 = 0xc;
  DAT_020527c8 = DAT_01c585dc;
  DAT_020527c0 = (&ITEM_PTR0)[EDIT_ITEM];
  thunk_FUN_00476628();
  return;
}


