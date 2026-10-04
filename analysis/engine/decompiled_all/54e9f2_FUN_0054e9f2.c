// FUN_0054e9f2 @ 0054e9f2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054e9f2(void)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  if (DAT_02052744 != DAT_02052740) {
    FUN_005f33c9(&stack0xfffffffc,0x54ea32);
    FUN_005f34d1(puVar1,0x54ea4d);
    DAT_009ae2cc._3_1_ = s_INCHES_0076963c[0];
    DAT_009ae2d0 = s_INCHES_0076963c[1];
    DAT_009ae2d1._0_1_ = s_INCHES_0076963c[2];
    DAT_009ae2d1._1_1_ = s_INCHES_0076963c[3];
    ram0x009ae2d3 = ram0x00769640;
    if (DAT_0078b4e8 != 0) {
      FUN_005f33c9(puVar1,0x54ea8e);
    }
    if (DAT_0078b4e8 == 2) {
      ram0x009ae2cf = i_1313427280;
      ram0x009ae2d3 = i_536892244;
    }
  }
  return;
}


