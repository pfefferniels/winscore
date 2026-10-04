// FUN_0045a8d7 @ 0045a8d7 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045a8d7(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  undefined1 *puVar6;
  
  puVar6 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  DAT_01c58a20 = 1;
  DAT_01c58a24 = 1;
  _DAT_007feeb8 = 1;
  DAT_007feeb4 = thunk_FUN_0059af40(&DAT_007feebc);
  if (DAT_007feeb4 != 2) {
    puVar3 = &DAT_009ae2bc;
    puVar4 = (undefined4 *)&DAT_020b8ea0;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    thunk_FUN_00518448();
    DAT_007feeb0 = (int)ROUND(P1);
    DAT_007feeac = (int)ROUND(P2);
    _DAT_007feeb8 = 1;
    FUN_005f33c9(&stack0xfffffffc,0x45a9c3);
    FUN_005f34d1(puVar6,0x45a9de);
    thunk_FUN_00518448();
    if (((char)DAT_020b8ea0 == '\0') || ((char)DAT_020b8ea0 == ' ')) {
      P1 = (float)_DAT_01bf49c0;
      P2 = (float)_DAT_01bf49c4;
    }
    _DAT_007feea8 = P1;
    _DAT_007feea4 = P2;
    FUN_005f33c9(puVar6,0x45aa54);
    puVar2 = puVar6;
    FUN_005f34d1(puVar6,0x45aa6f);
    thunk_FUN_00518448();
    DAT_007feea0 = P1;
    if (P1 == f_0) {
      DAT_007feea0 = f_50;
    }
    _DAT_007fee9c = P2;
    if (P2 == f_0) {
      _DAT_007fee9c = DAT_007feea0;
    }
    DAT_007feea0 = DAT_007feea0 / f_100;
    _DAT_007fee9c = _DAT_007fee9c / f_100;
    DAT_007fee98 = DAT_01a14bb4;
    if (DAT_01a14bb4 == 0) {
      DAT_007fee98 = 5;
    }
    DAT_007fee94 = **(int **)(puVar2 + 8);
    if (DAT_007feeb0 < 0) {
      DAT_007feeb0 = DAT_007feeb0 + 0x168;
    }
    if (DAT_007feeac < DAT_007feeb0) {
      DAT_007feeac = DAT_007feeac + 0x168;
    }
    if (DAT_007feeb0 == 0) {
      DAT_007feeb0 = 1;
    }
    if ((DAT_007feeac == 0) || (DAT_007feeac == 0x168)) {
      DAT_007feeac = 0x169;
    }
    DAT_007fee90 = DAT_007feeb0 * 2 + -1;
    DAT_007fee8c = DAT_007feeac * 2 + -1;
    DAT_007fee98 = DAT_007fee98 * 2;
    _DAT_007fee88 = _DAT_007feea8 - DAT_007feea0 * *(float *)(&DAT_0078fb74 + DAT_007fee90 * 4);
    _DAT_007fee84 = _DAT_007feea4 - _DAT_007fee9c * (float)(&DAT_0078fb78)[DAT_007fee90];
    _DAT_007feeb8 = 1;
    DAT_007fee80 = -9999;
    DAT_007fee7c = -9999;
    while( true ) {
      _DAT_007fee78 = DAT_007feea0 * *(float *)(&DAT_0078fb74 + DAT_007fee90 * 4) + _DAT_007fee88;
      _DAT_007fee74 = _DAT_007fee9c * (float)(&DAT_0078fb78)[DAT_007fee90] + _DAT_007fee84;
      **(int **)(puVar2 + 8) = **(int **)(puVar2 + 8) + 1;
      fVar5 = (float10)anint(puVar2,0x45ac8f);
      *(int *)(puVar2 + -0x34) = (int)ROUND(fVar5);
      DAT_007fee70 = *(int *)(puVar2 + -0x34);
      fVar5 = (float10)anint(puVar2,0x45acb5);
      *(int *)(puVar2 + -0x34) = (int)ROUND(fVar5);
      DAT_007fee6c = *(int *)(puVar2 + -0x34);
      if ((DAT_007fee80 == DAT_007fee70) && (DAT_007fee7c == DAT_007fee6c)) {
        **(int **)(puVar2 + 8) = **(int **)(puVar2 + 8) + -1;
      }
      (&PT_X0)[**(int **)(puVar2 + 8)] = DAT_007fee70;
      (&PT_Y0)[**(int **)(puVar2 + 8)] = DAT_007fee6c;
      DAT_007fee80 = DAT_007fee70;
      DAT_007fee7c = DAT_007fee6c;
      *(undefined2 *)((int)&DAT_01fbb8dc + **(int **)(puVar2 + 8) * 2 + 2) = DAT_007feeb8;
      if (DAT_007fee94 + 1 == **(int **)(puVar2 + 8)) {
        _DAT_007feeb8 = 0;
      }
      DAT_007fee90 = DAT_007fee98 + DAT_007fee90;
      if (DAT_007fee8c < DAT_007fee90) break;
      if (DAT_007fee90 < 0x2d2) {
        *(undefined4 *)(puVar2 + -8) = 0;
      }
      else {
        DAT_007fee90 = 1;
        DAT_007fee8c = DAT_007fee8c + -0x2d2;
        *(undefined4 *)(puVar2 + -4) = 0;
      }
    }
    *(undefined4 *)(puVar2 + -0xc) = 0;
    FUN_0045a585(*(undefined4 *)(puVar2 + 8));
    FUN_004585b9(*(undefined4 *)(puVar2 + 8));
  }
  DAT_01c58a20 = 0;
  DAT_01c58a24 = 0;
  _DAT_01beac0c = **(undefined4 **)(puVar2 + 8);
  return;
}


