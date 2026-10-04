// FUN_00526042 @ 00526042 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00526042(uint *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  *param_1 = -(uint)(DAT_0078d894 < _DAT_01fb8c64);
  if ((*param_1 & 1) == 0) {
    thunk_FUN_0054c473(&DAT_020b8ea0,1);
    FUN_005f33c9(&stack0xfffffffc,0x5260b4);
    puVar1 = puVar2;
    FUN_005f34d1(puVar2,0x5260cf);
    *(undefined4 *)(puVar1 + -0x58) = 0;
    *(undefined4 *)(puVar1 + -0x68) = 3;
    *(undefined1 **)(puVar1 + -100) = &DAT_020b8ea2;
    *(int **)(puVar1 + -0x60) = &DAT_0078d960;
    FUN_005f34f0(puVar1 + -0x58,0x784ff00,&DAT_00767e1c,puVar1 + -0x68,&DAT_00796c50);
    _DAT_01a1f4c4 = _DAT_020b8ea0;
    DAT_01a1f4c8 = _DAT_020b8ea4;
    DAT_01a1f4cc = DAT_020b8ea8;
    DAT_01a1f4d0 = _DAT_020b8eac;
  }
  *(undefined4 *)(puVar1 + -0x30) = 0;
  if (DAT_02052748 != DAT_02052740) {
    *(undefined4 *)(puVar1 + -0x28) = 0;
    goto LAB_0052620f;
  }
  *(undefined4 *)(puVar1 + -0x2c) = 0;
  if ((**(uint **)(puVar1 + 8) & 1) == 0) {
    FUN_005f33c9(puVar1,0x526191);
    FUN_005f34d1(puVar1,0x5261ac);
    *(undefined4 *)(puVar1 + -0x58) = 0;
    *(undefined4 *)(puVar1 + -0x68) = 4;
    *(undefined **)(puVar1 + -100) = &DAT_020b8eaf;
    *(undefined **)(puVar1 + -0x60) = &DAT_01fb8c64;
    FUN_005f34f0(puVar1 + -0x58,0x784ff00,&DAT_00767e00,puVar1 + -0x68,&DAT_00796c64);
    thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
    goto LAB_00526256;
  }
  *(undefined4 *)(puVar1 + -0x24) = 0;
  do {
    if (DAT_0078b378 == 3) {
      P1 = (float)DAT_0078d920;
      P2 = (float)DAT_0078d924;
      *(int *)(puVar1 + -0x5c) = DAT_0078d960 + 1;
      P3 = (float)*(int *)(puVar1 + -0x5c);
      if (DAT_02052748 == DAT_02052740) {
        thunk_FUN_0054c473(&DAT_020b8ea0,1);
        _DAT_0094ea80 = 1;
        thunk_FUN_004a5f84(&DAT_0078d920,&DAT_020b8ea0,1,&DAT_0094ea80);
        thunk_FUN_004a5f84(&DAT_0078d924,&DAT_020b8ea0,1,&DAT_0094ea80);
        DAT_01a1f480 = 1;
        FUN_005253e2();
      }
      *(undefined4 *)(puVar1 + -0x14) = 0;
      goto LAB_005263da;
    }
LAB_0052620f:
    if (DAT_0078b4e4 != 0x50) {
      *(undefined4 *)(puVar1 + -0x10) = 0;
      goto LAB_005263da;
    }
    if (P2 <= f_0) {
      P2 = f_1;
    }
    _DAT_01fb8c64 = P2;
    *(undefined4 *)(puVar1 + -0xc) = 0;
LAB_00526256:
    DAT_0078b4e4 = 0x58;
    DAT_0078b4e0 = 0;
    thunk_FUN_004f7808();
    thunk_FUN_0051c338();
    if (0 < DAT_01fb8c74) {
      *(undefined4 *)(puVar1 + -0x1c) = 0;
      DAT_0078b378 = 3;
      _DAT_0094ea7c = 0;
      return;
    }
    DAT_0078d960 = -1;
    _DAT_01fb8c64 = ram0x00767dfc;
    thunk_FUN_0054d831("*** No rhythms on spacing staff.",0x20);
  } while (-1 < DAT_02052740);
  if (DAT_0078b378 == 3) {
    P1 = (float)DAT_0078d920;
    P2 = (float)DAT_0078d924;
  }
  else {
    P1 = f_0;
    P2 = DAT_01fbb8b8;
  }
  P3 = f_0;
  *(undefined4 *)(puVar1 + -0x18) = 0;
LAB_005263da:
  if (**(int **)(puVar1 + 8) == 0) {
    *(undefined4 *)(puVar1 + -8) = 0;
  }
  else {
    if (P1 < f_0) {
      P1 = f_0;
    }
    DAT_01e67910 = P1;
    DAT_01e67914 = P2;
    if (P2 <= P1) {
      DAT_01e67914 = DAT_01fbb8b8;
    }
    *(undefined4 *)(puVar1 + -4) = 0;
  }
  return;
}


