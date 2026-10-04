// FUN_00445fff @ 00445fff (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00445fff(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  if ((DAT_01fbb8a0 == 0x1f) || (DAT_01fbb8a0 != 0x20)) {
    FUN_005f33c9(&stack0xfffffffc,0x44653c);
    FUN_005f34d1(puVar5,0x446557);
    thunk_FUN_0041b68a();
    DAT_01fbb8a0 = 0x20;
    puVar2 = &DAT_009ae2bc;
    puVar3 = (undefined4 *)&DAT_020b90a0;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(puVar5 + -0x38) = 0;
    return;
  }
  if (DAT_020b8ea2 == 'X') {
    for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
      *(undefined4 *)(&DAT_020b943c + iVar1 * 4) = *(undefined4 *)(&P0 + iVar1 * 4);
    }
    puVar2 = (undefined4 *)&DAT_020b8ea0;
    puVar3 = (undefined4 *)&DAT_020b90a0;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  puVar2 = &DAT_009ae2bc;
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (((char)DAT_020b8ea0 == '|') || ((char)DAT_020b8ea0 == '~')) {
    DAT_01fbb7e0 = VEC_N;
    thunk_FUN_0041b011();
    thunk_FUN_004a30bb(&DAT_007fc0cc,&DAT_00760840);
    if (DAT_007fc0cc == -2) {
      ITEM_I = IP18;
      ITEM_WORDS = IP19;
      goto LAB_004464ce;
    }
    if (DAT_007fc0cc == 0) {
      VEC_N = DAT_01fbb7e0;
      puVar2 = (undefined4 *)&DAT_020b90a0;
      puVar3 = &DAT_009ae2bc;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      thunk_FUN_00549422();
      return;
    }
  }
  else {
    thunk_FUN_00518448();
  }
  if (DAT_020b90a2 == 'X') {
    DAT_01fbb8a0 = 0;
    thunk_FUN_004b3e1e();
    FUN_005f34d1(&stack0xfffffffc,0x446179);
    *(undefined4 *)(puVar4 + -0x2c) = 0;
    return;
  }
  DAT_01fbb890 = (int)ROUND(P1);
  DAT_007fc0c8 = P2;
  _DAT_007fc0c4 = P3;
  _DAT_007fc0c0 = ITEM_I;
  _DAT_007fc0bc = f_0;
  if (MAX_STAFF < DAT_01fbb890) {
    DAT_01fbb890 = DAT_01fbb860;
  }
  if ((P2 == f_0) && (P3 == f_0)) {
    DAT_007fc0c8 = DAT_01fbb868;
    _DAT_007fc0c4 = DAT_01fbb86c;
  }
  if ((_DAT_007fc0c4 == f_0) && (DAT_007fc0c8 != f_0)) {
    _DAT_007fc0bc = DAT_007fc0c8;
LAB_004463c8:
    DAT_007fc0b8 = 2;
    if (DAT_01fbb890 == DAT_01fbb860) {
      DAT_007fc0b8 = 0;
    }
  }
  else {
    if (_DAT_007fc0c4 == f_0) {
      _DAT_007fc0c4 = DAT_01fbb86c;
    }
    if ((DAT_007fc0c8 == DAT_01fbb868) && (_DAT_007fc0c4 == DAT_01fbb86c)) {
      DAT_007fc0b8 = 1;
    }
    else {
      _DAT_007fc0b4 = DAT_01fbb86c - DAT_01fbb868;
      DAT_007fc0b0 = _DAT_007fc0c4 - DAT_007fc0c8;
      if (_DAT_007fc0b4 == f_0) {
        _DAT_007fc0b4 = DAT_007fc0b0;
      }
      if (ABS(_DAT_007fc0b4 - DAT_007fc0b0) <= f_0_001) {
        _DAT_007fc0bc = DAT_007fc0c8 - DAT_01fbb868;
        goto LAB_004463c8;
      }
      _DAT_007fc0bc = DAT_007fc0b0 / _DAT_007fc0b4;
      DAT_007fc0b8 = 0xffffffff;
      if (DAT_01fbb890 != DAT_01fbb860) {
        DAT_007fc0b8 = 3;
      }
    }
  }
  DAT_01fbb874 = DAT_007fc0b8;
  DAT_01fbb87c = ITEM_I;
  P1 = (float)(DAT_01fbb890 - DAT_01fbb860);
  thunk_FUN_004e7eea();
  if (_DAT_007fc0bc != f_0) {
    thunk_FUN_0049bb13(&DAT_007fc0b8,&DAT_01fbb868,&DAT_007fc0c8,&DAT_007fc0bc);
  }
  DAT_01fbb8a0 = 0;
  if (DAT_020492a0 < 1) {
    DAT_01fbb8a0 = 0;
    return;
  }
  DAT_0078b4f0 = 1;
  thunk_FUN_00495d4f(&DAT_0078b510,0x80);
  draw_items();
  DAT_020527e8 = ITEM_I;
  DAT_0078b4ec = 0;
  DAT_0078b4f0 = 1;
  DAT_0078b4e0 = 0;
  thunk_FUN_00597b60(0xffffffff);
LAB_004464ce:
  DAT_01fbb8a4 = 0;
  DAT_01fbb8a0 = 0;
  if (DAT_007fc0cc == -2) {
    draw_items();
  }
  if (DAT_007fc0ac == 0) {
    thunk_FUN_00597b60(0xffffffff);
    DAT_007fc0ac = -1;
  }
  return;
}


