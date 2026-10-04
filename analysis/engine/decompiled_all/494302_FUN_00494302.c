// FUN_00494302 @ 00494302 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494302(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  
  puVar7 = &stack0xfffffffc;
  puVar8 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  puVar10 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar11 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  if (DAT_01fbb8a0 < 0) {
    DAT_01fbb7e0 = VEC_N;
    if (((char)DAT_020b8ea0 == '|') || ((char)DAT_020b8ea0 == '~')) {
      thunk_FUN_0041b011();
    }
    else {
      thunk_FUN_00518448();
      thunk_FUN_0041aa88();
    }
    thunk_FUN_004a30bb(&DAT_0082a058,&DAT_00762e40);
    if (DAT_0082a058 == 0) {
      DAT_01fbb8a0 = 0xd;
      puVar5 = &DAT_01c4c860;
      puVar6 = (undefined4 *)&DAT_020b8ea0;
      for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      VEC_N = DAT_01fbb7e0;
      thunk_FUN_00549422();
      goto LAB_0049440e;
    }
    if (DAT_0082a058 == -2) goto LAB_0049486b;
    if (P1 <= f_0) {
      thunk_FUN_0050d706();
      return;
    }
    thunk_FUN_005725fa();
    DAT_020527a0 = 0xfffffffe;
  }
  else {
LAB_0049440e:
    if (DAT_020b8ea2 == 'N') {
      DAT_0082a060 = 2;
      FUN_005f33c9(&stack0xfffffffc,0x49444a);
      puVar2 = puVar7;
      FUN_005f34d1(puVar7,0x494465);
    }
    else if (DAT_020b8ea2 == 'D') {
      DAT_0082a060 = 3;
      FUN_005f33c9(&stack0xfffffffc,0x4944a6);
      puVar2 = puVar8;
      FUN_005f34d1(puVar8,0x4944c1);
    }
    else if (DAT_020b8ea2 == 'U') {
      DAT_0082a060 = 4;
      FUN_005f33c9(&stack0xfffffffc,0x494502);
      puVar2 = puVar9;
      FUN_005f34d1(puVar9,0x49451d);
    }
    else if (DAT_020b8ea2 == 'A') {
      DAT_0082a060 = 5;
      FUN_005f33c9(&stack0xfffffffc,0x49455e);
      puVar2 = puVar10;
      FUN_005f34d1(puVar10,0x494579);
    }
    else {
      if (DAT_020b8ea2 == 'V') {
        DAT_0082a060 = 6;
        FUN_005f33c9(&stack0xfffffffc,0x4945be);
        FUN_005f34d1(puVar3,0x4945d9);
        FUN_005f33c9(puVar3,0x4945fb);
        _DAT_0082a05c = 0;
        *(undefined4 *)(puVar3 + -0x34) = 0;
        goto LAB_004946d3;
      }
      DAT_0082a060 = 1;
      FUN_005f33c9(&stack0xfffffffc,0x49463c);
      puVar2 = puVar11;
      FUN_005f34d1(puVar11,0x494657);
    }
    _DAT_0082a05c = 0;
    if (DAT_020b8ea3 == 'X') {
      *(undefined4 *)(puVar2 + -0x30) = 0;
    }
    else {
      if (DAT_02052740 == 0) {
        *(undefined4 *)(puVar2 + -0x2c) = 0;
        FUN_005f33c9(puVar2,0x4946b4);
        puVar3 = puVar2;
        FUN_005f34d1(puVar2,0x4946cf);
LAB_004946d3:
        puVar5 = (undefined4 *)&DAT_020b90a0;
        puVar6 = &DAT_009ae2bc;
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        puVar5 = (undefined4 *)&DAT_020b8ea0;
        puVar6 = &DAT_01c4c860;
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        thunk_FUN_0041b68a();
        thunk_FUN_004a1240(&DAT_00762e60);
        *(undefined4 *)(puVar3 + -0x24) = 0;
        return;
      }
      thunk_FUN_00518448();
      DAT_01fbb8a0 = 0;
      *(undefined4 *)(puVar2 + -0x28) = 0;
    }
  }
  DAT_01fb8c60 = P1;
  DAT_01e67910 = P2;
  DAT_01e67914 = P3;
  _DAT_0082a054 = P4;
  if (P3 == f_0) {
    DAT_01e67914 = f_200;
  }
  DAT_0078b4e4 = 0x58;
  push_words(&DAT_00762e58,&P1);
  thunk_FUN_004f7808();
  pop_words(&DAT_00762e58,&P1);
  while( true ) {
    if (DAT_0082a060 < 5) {
      thunk_FUN_0047c3e8(&DAT_0082a060);
    }
    if (DAT_0082a060 == 5) {
      P5 = P4;
      P4 = P3;
      P3 = P2;
      P2 = P1;
      thunk_FUN_0040cde4(&DAT_00762e20);
    }
    else if (DAT_0082a060 == 6) {
      thunk_FUN_00443b70();
    }
    DAT_01fbb700 = 0;
    if (_DAT_0082a054 <= DAT_01fb8c60) break;
    DAT_01fb8c60 = DAT_01fb8c60 + f_1;
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  *(undefined4 *)(puVar2 + -8) = 0;
  puVar4 = puVar2;
LAB_0049486b:
  draw_items();
  FUN_005f34d1(puVar4,0x49488d);
  thunk_FUN_00549422();
  DAT_01fbb8a0 = 0;
  _DAT_0078b38c = 0;
  thunk_FUN_00468df8(&DAT_00762e50);
  return;
}


