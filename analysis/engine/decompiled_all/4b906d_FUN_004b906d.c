// FUN_004b906d @ 004b906d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b906d(void)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  puVar3 = &DAT_0078b510;
  puVar4 = &DAT_0089f5b8;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  if (DAT_02052740 == 0) {
    DAT_0089f5b4 = VEC_N;
    if (((char)DAT_020b8ea0 == '|') || ((char)DAT_020b8ea0 == '~')) {
      thunk_FUN_0041b011();
    }
    else {
      thunk_FUN_00518448();
      if (((char)DAT_020b8ea0 == 'B') || (P1 == f_0 && P3 == f_0)) goto LAB_004b93ae;
      thunk_FUN_0041aa88();
    }
    thunk_FUN_004a30bb(&DAT_0089f5b0,&DAT_00764974);
    if (DAT_0089f5b0 != -2) {
      if (DAT_0089f5b0 == 0) {
        VEC_N = DAT_0089f5b4;
        thunk_FUN_00549422();
        return;
      }
      goto LAB_004b91cb;
    }
    VEC_N = DAT_0089f5b4;
    draw_items();
  }
  else {
    P4 = (P2 + P1) - f_1;
    P2 = f_0;
    P3 = DAT_01fbb8b8;
LAB_004b91cb:
    DAT_0078b4e0 = DAT_01ade8a0;
    DAT_0078b4e4 = DAT_01ade8a4;
    if (DAT_0089f5ac == 8) {
      if (P2 < f_0) {
        P2 = f_0;
      }
      if ((P3 == f_0) || (DAT_01fbb8b8 < P3)) {
        P3 = DAT_01fbb8b8;
      }
    }
    fVar1 = P2;
    DAT_01ade8a8 = (int)ROUND(P1);
    DAT_01ade8ac = (int)ROUND(P4);
    P1 = P2;
    P2 = P3;
    if (fVar1 < f_0) {
      P1 = f_0;
    }
    if (DAT_01fbb8b8 < P3) {
      P2 = DAT_01fbb8b8;
    }
    thunk_FUN_0054946a(&DAT_00764970,1);
    VEC_N = DAT_0089f5b4;
    DAT_0089f5ac = DAT_0078b4e0;
    FUN_005f33c9(&stack0xfffffffc,0x4b932e);
    FUN_005f34d1(puVar5,0x4b9349);
    thunk_FUN_005725fa();
    DAT_0078b4e0 = DAT_0089f5ac;
    if (DAT_01ade8a4 == 0x54) {
      FUN_004b8b97();
    }
    else {
      FUN_004b80b7(&DAT_01ade8a8,&DAT_01ade8ac,&P1,&P2);
    }
  }
  thunk_FUN_00549422();
  DAT_01fbb8a4 = 0;
  thunk_FUN_00468df8(&DAT_007648f8);
LAB_004b93ae:
  DAT_01fbb8a0 = 0;
  puVar3 = &DAT_0089f5b8;
  puVar4 = &DAT_0078b510;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  DAT_01fbb8a8 = 0;
  return;
}


