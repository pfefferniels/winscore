// cmd_lineup @ 004b7ad8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cmd_lineup(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar2 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  if (_DAT_020b8ea0 == 0x5453414c) {
    FUN_005f33c9(&stack0xfffffffc,0x4b7b18);
    FUN_005f34d1(puVar2,0x4b7b33);
    *(undefined4 *)(puVar2 + -0x70) = 0;
    *(undefined4 *)(puVar2 + -0x88) = 0x80;
    *(undefined **)(puVar2 + -0x84) = &DAT_0089f4fc;
    *(undefined4 *)(puVar2 + -0x80) = 3;
    *(undefined **)(puVar2 + -0x7c) = &DAT_00764918;
    *(undefined4 *)(puVar2 + -0x78) = 2;
    uVar1 = FUN_005f6540(puVar2 + -0x70,7,0x784ff01,&DAT_00764908,puVar2 + -0x88);
    *(undefined4 *)(puVar2 + -0x50) = uVar1;
    if (*(int *)(puVar2 + -0x50) == 0) {
      *(undefined4 *)(puVar2 + -0x70) = 0;
      *(undefined4 *)(puVar2 + -0x78) = 0x7e;
      *(undefined **)(puVar2 + -0x74) = &DAT_020b90a2;
      uVar1 = FUN_005fdbd0(puVar2 + -0x70,7,0x784ff01,&DAT_00764904,puVar2 + -0x78,&DAT_00792500);
      *(undefined4 *)(puVar2 + -0x4c) = uVar1;
      if (*(int *)(puVar2 + -0x4c) == 0) {
        _DAT_020b90a0 = DAT_00764900;
        cmd_get();
        *(undefined4 *)(puVar2 + -0x48) = 0;
        return;
      }
    }
    FUN_005f33c9(puVar2,0x4b7c2e);
    FUN_005f34d1(puVar2,0x4b7c49);
    cmd_get();
    *(undefined4 *)(puVar2 + -0x44) = 0;
    return;
  }
  if (DAT_01fbb8a8 != 1) {
    if (((_DAT_020b8ea0 & 0xff) == 0x4a) || ((_DAT_020b8ea0 & 0xff) == 0x4c)) {
LAB_004b7d05:
      DAT_01ade8a0 = DAT_0078b4e0;
      DAT_01ade8a4 = DAT_0078b4e4;
      if ((_DAT_020b8ea0 & 0xffff) == 0x544a) {
        if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x58) {
          FUN_004b8b97();
          return;
        }
        thunk_FUN_00468df8(&DAT_007648f8);
        FUN_005f33c9(&stack0xfffffffc,0x4b7d87);
        FUN_005f34d1(puVar3,0x4b7da2);
        _DAT_009c6ad4 = f_0;
        DAT_01fbb8a4 = 0x4d;
        *(undefined4 *)(puVar3 + -0x28) = 0;
        return;
      }
      DAT_01fbb8a8 = 1;
      DAT_01fbb8a0 = 8;
      DAT_01fbb8a4 = 8;
      thunk_FUN_0041b68a();
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x41) {
        FUN_004b93f2();
        lineup_answer();
        _DAT_009c6ad4 = f_0;
        thunk_FUN_00597b60(0xffffffff);
        return;
      }
      if (DAT_02052740 == 0) {
        FUN_005f33c9(&stack0xfffffffc,0x4b805b);
        FUN_005f34d1(puVar4,0x4b8076);
        *(undefined4 *)(puVar4 + -0x20) = 0;
        return;
      }
      thunk_FUN_00518448();
    }
    else if ((DAT_01fbb8a4 != 8) && ((DAT_01fbb8a4 != 6 && (DAT_01fbb8a4 != 7)))) {
      if (DAT_0078b4e4 == 0x4d) {
        return;
      }
      if (DAT_0078b4e4 == 0x4b) {
        return;
      }
      if (DAT_0078b4e4 == 0x43) {
        return;
      }
      if (DAT_0078b4e4 == 0x4e) {
        return;
      }
      if (DAT_0078b4e4 == 0x42) {
        return;
      }
      goto LAB_004b7d05;
    }
    DAT_01fbb8a4 = 0;
    _DAT_01fbb8c0 = (int)ROUND(P1);
    if (MAX_STAFF < _DAT_01fbb8c0) {
      DAT_01ade8a8 = 1;
      DAT_01ade8ac = MAX_STAFF;
      DAT_01fbb8c4 = 0;
    }
    else {
      DAT_01ade8ac = (int)ROUND(P2);
      DAT_01ade8a8 = _DAT_01fbb8c0;
      if (_DAT_01fbb8c0 == 0) {
        DAT_01ade8a8 = 1;
      }
      if (DAT_01ade8ac == 0) {
        DAT_01ade8ac = 1;
      }
      DAT_01ade8ac = DAT_01ade8ac + DAT_01ade8a8 + -1;
      if (P4 != f_0) {
        DAT_01ade8ac = (int)ROUND(P4);
      }
      DAT_01fbb8c4 = DAT_01ade8ac;
    }
    if (DAT_01ade8a0 == 0x4a) {
      P1 = P3;
      P2 = P4;
      if (P4 <= P3) {
        P2 = f_200;
      }
      DAT_020b8e28 = 1;
    }
    DAT_0078b4e0 = 0;
    if (DAT_01ade8a4 == 0x54) {
      FUN_004b8b97();
      goto LAB_004b8036;
    }
  }
  DAT_0078b4e0 = DAT_01ade8a0;
  DAT_0078b4e4 = DAT_01ade8a4;
  DAT_01fbb8a8 = 0;
  DAT_01fbb8a0 = 0;
  DAT_01fbb8a4 = 0;
  if (DAT_01ade8a4 != 0x4e) {
    lineup_pass(&DAT_01ade8a8,&DAT_01ade8ac,&P1,&P2);
    DAT_0078b4ec = 1;
  }
LAB_004b8036:
  thunk_FUN_004a5c79();
  return;
}


