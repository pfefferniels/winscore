// FUN_004a6baa @ 004a6baa (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a6baa(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  thunk_FUN_004aec88();
  if (DAT_00791448 == 0) {
    OUTPUT_MODE = 1;
    DAT_020527a0 = 0;
    DAT_0079144c = 0x20202020;
    DAT_00791450 = 0x20202020;
    DAT_00839274 = (uint)DAT_007a0b7c;
    if (DAT_00839274 < 0x21) {
      puVar2 = &stack0xfffffffc;
      FUN_005f34d1(&stack0xfffffffc,0x4a6c2b);
    }
    *DAT_01fbb844 = 0;
    DAT_01fbb700 = 0;
    DAT_0078b690 = 0x53554d2e;
    DAT_00791444 = 0xffffffff;
    _DAT_0083926c = 0;
    DAT_009a9494 = 0;
    DAT_009a9490 = 0;
    DAT_01be6d60 = 2;
    _DAT_01be6d64 = f_100;
    DAT_01be6d6c = 0;
    DAT_0078b370 = 1;
    _DAT_01a14bac = 0;
    DAT_01be6d68 = 1;
    _DAT_00839268 = 0xffffffff;
    VEC_N = 1;
    _DAT_01fbb820 = 0;
    DAT_01be6d80 = 0;
    DAT_01fbb8a8 = 0;
    DAT_01fbb8a0 = 0;
    DAT_0078de20 = 0;
    DAT_020527e8 = 1;
    DAT_01fb9630 = 0;
    DAT_00791448 = 1;
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(puVar2,0x4a6d4d);
      FUN_005f34d1(puVar2,0x4a6d68);
    }
    DAT_0078b4f0 = 0;
    COLOR = 0;
    _DAT_009c6ad4 = f_0;
    VIEW_DX = 0x960;
    thunk_FUN_00490cce(&DAT_00763c40,&DAT_00763c44);
    FUN_004a6db2();
  }
  return;
}


