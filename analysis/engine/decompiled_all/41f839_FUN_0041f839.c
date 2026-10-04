// FUN_0041f839 @ 0041f839 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041f839(void)

{
  char cVar1;
  int iVar2;
  
  if (DAT_007cb2cc != 99) {
    FUN_00420e60(&DAT_020b8ea0,0x200,&DAT_020b90a0,0x200,&DAT_007cc600,&DAT_007cc604);
    if (_DAT_020b90a0 == 0x4f525245) {
      return;
    }
    DAT_007d20a4 = 2;
    for (iVar2 = 1; iVar2 < 0xd; iVar2 = iVar2 + 1) {
      *(undefined1 *)((int)&DAT_01e62c80 + iVar2 + 3) = 0x20;
    }
    if (*(char *)((int)&DAT_020b8ea0 + DAT_007cc604) != '-') {
      if (*(char *)((int)&DAT_020b8ea0 + DAT_007cc604) == '$') {
        thunk_FUN_00527276(&DAT_007cc604);
      }
      else {
        FUN_0041f64f();
      }
      goto LAB_0041f940;
    }
  }
  thunk_FUN_00526f23(&DAT_007cc604);
LAB_0041f940:
  DAT_007d20a0 = 3;
  while( true ) {
    DAT_007d209c = 1;
    while( true ) {
      cVar1 = *(char *)((int)&DAT_007cb2cc + DAT_007d20a0 + 3);
      _DAT_007d20ac = CONCAT31(DAT_007d20ac_1,cVar1);
      if (((cVar1 == ']') || (cVar1 == '/')) || (cVar1 == ':')) break;
      *(char *)((int)&DAT_01e62c80 + DAT_007d209c + 3) = cVar1;
      DAT_007d209c = DAT_007d209c + 1;
      DAT_007d20a0 = DAT_007d20a0 + 1;
    }
    *(char *)((int)&DAT_01e62c80 + DAT_007d209c + 3) = cVar1;
    if ((_DAT_007d20ac & 0xff) == 0x5d) {
      *(undefined1 *)((int)&DAT_01e62c80 + DAT_007d209c + 3) = 0x2f;
    }
    _DAT_020b90a0 = CONCAT31(_DAT_020b90a1,DAT_007d20ac);
    thunk_FUN_004c04fb();
    *(undefined4 *)(DAT_0079485c * 4 + 0x7ccacc) = DAT_007d20a4;
    DAT_007d20a4 = 1;
    if ((_DAT_007d20ac & 0xff) == 0x5d) break;
    DAT_007d20a0 = DAT_007d20a0 + 1;
    for (iVar2 = 1; iVar2 < 0xd; iVar2 = iVar2 + 1) {
      *(undefined1 *)((int)&DAT_01e62c80 + iVar2 + 3) = 0x20;
    }
  }
  DAT_01fb9634 = 0;
  DAT_007d20a4 = 1;
  DAT_007cb2cc = 0;
  return;
}


