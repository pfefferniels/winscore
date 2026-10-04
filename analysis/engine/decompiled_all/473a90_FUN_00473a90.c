// FUN_00473a90 @ 00473a90 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00473ae8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473a90(void)

{
  if (DAT_01fbb8a0 == 3) {
    DAT_01fbb8a0 = 0;
    DAT_0078b4e0 = 0;
    if (P1 == f_0) {
      thunk_FUN_0050d706();
    }
    else {
      if (P2 < f_0) {
        P2 = f_0;
      }
      if ((P3 == f_0) || (DAT_01fbb8b8 < P3)) {
        P3 = DAT_01fbb8b8;
      }
      DAT_01be12e4 = 1;
      thunk_FUN_00586a80();
      if (DAT_01be12e0 < 0) {
        DAT_01fbb700 = 0xffffffff;
        DAT_02052740 = 0xffffffff;
        input_main();
      }
    }
    DAT_01be12e4 = 0;
    _DAT_008251cc = 0;
    DAT_0078b4e0 = 0;
  }
  else if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x4e) {
    thunk_FUN_0055b1f8();
  }
  else if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x49) {
    DAT_0078b4e0 = 0xffffffff;
    DAT_01fbb8a0 = 1;
  }
  else if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x51) {
    FUN_00473d22();
  }
  else if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00504445) {
    DAT_01fbb6f8 = -DAT_01fbb6f8;
  }
  else if ((_DAT_020b8ea0 & 0xff) == 0x45) {
    if ((-1 < DAT_00790d74) || ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x58)) {
      DAT_00790d74 = -DAT_00790d74;
      FUN_00473cdd(&DAT_00790d74);
    }
  }
  else {
    thunk_FUN_0054d7d4(&DAT_020b90a0,0x200);
  }
  return;
}


