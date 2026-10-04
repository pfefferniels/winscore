// FUN_0053b514 @ 0053b514 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053b514(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 in_ST0;
  
  _DAT_0099aab8 = f_0;
  DAT_0099aab4 = 0;
  if (f_0 < P14) {
    _DAT_0099aaa8 = f_0;
    in_ST0 = (float10)P15;
    DAT_0099aaa4 = (float)ABS(in_ST0);
    if (P14 == f_0) {
      P14 = DAT_0099aaa4;
      P15 = f_0;
    }
    DAT_0099aaac = NPT / 2;
    _DAT_0099aaa0 = 0;
    _DAT_0099aab8 = DAT_0099aaa4 * f_75;
    _DAT_0099aa9c = (P14 * DAT_01c5866c + DAT_01c58660) - _DAT_0099aab8;
    iVar1 = DAT_0099aaac;
    for (DAT_0099aab0 = 1; (0 < iVar1 && ((float)(int)(&PT_X0)[DAT_0099aab0] <= _DAT_0099aa9c));
        DAT_0099aab0 = DAT_0099aab0 + 1) {
      iVar1 = iVar1 + -1;
    }
    if (P15 <= f_0) {
      (&PT_X0)[DAT_0099aab0] = (int)ROUND(_DAT_0099aa9c);
      _DAT_0099aa98 = (float)DAT_01fd3f80;
      DAT_0099aa90 = DAT_0099aab0 * 2;
      DAT_0099aa8c = 1;
      for (iVar1 = DAT_0099aab0; DAT_0099aa94 = NPT + -1, 0 < iVar1; iVar1 = iVar1 + -1) {
        *(undefined4 *)(&DAT_0099ba58 + DAT_0099aa8c * 4) = (&PT_X0)[DAT_0099aa8c];
        *(undefined4 *)(&DAT_0099ba58 + DAT_0099aa90 * 4) = (&PT_X0)[DAT_0099aa8c];
        *(undefined4 *)(&DAT_0099aab8 + DAT_0099aa8c * 4) = (&PT_Y0)[DAT_0099aa8c];
        *(undefined4 *)(&DAT_0099aab8 + DAT_0099aa90 * 4) = (&PT_Y0)[DAT_0099aa94];
        DAT_0099aa90 = DAT_0099aa90 + -1;
        DAT_0099aa8c = DAT_0099aa8c + 1;
        NPT = DAT_0099aa94;
      }
      if (_DAT_0099aab8 == f_0) {
        NPT = DAT_0099aab0 * 2;
        goto LAB_0053bd80;
      }
    }
  }
  else {
    DAT_0099aab4 = 1;
    DAT_0099aab0 = 1;
    DAT_0099aaac = NPT / 2;
    if (P14 < f_0) {
      in_ST0 = (float10)P14;
      P14 = (float)-in_ST0;
    }
    if (P14 == f_0) {
      P14 = P15;
    }
  }
  _DAT_0099aa88 = P14 * DAT_01c5866c + DAT_01c58660 + _DAT_0099aab8;
  iVar1 = ((DAT_0099aab0 - DAT_0099aaac) + -1) / -1;
  for (DAT_0099aa8c = DAT_0099aaac;
      (0 < iVar1 && (_DAT_0099aa88 <= (float)(int)(&PT_X0)[DAT_0099aa8c]));
      DAT_0099aa8c = DAT_0099aa8c + -1) {
    iVar1 = iVar1 + -1;
  }
  if (DAT_0099aab4 != 1) {
    if (f_0 < P15) {
      DAT_0099aa94 = 1;
      (&PT_X0)[DAT_0099aab0] = (int)ROUND(_DAT_0099aa9c);
      (&PT_X0)[DAT_0099aa8c] = (int)ROUND(_DAT_0099aa88);
      DAT_0099aa80 = DAT_0099aab0;
      for (iVar1 = (DAT_0099aa8c - DAT_0099aab0) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
        *(undefined4 *)(&DAT_0099ba58 + DAT_0099aa94 * 4) = (&PT_X0)[DAT_0099aa80];
        *(undefined4 *)(&DAT_0099aab8 + DAT_0099aa94 * 4) = (&PT_Y0)[DAT_0099aa80];
        DAT_0099aa94 = DAT_0099aa94 + 1;
        DAT_0099aa80 = DAT_0099aa80 + 1;
      }
      DAT_0099aa7c = DAT_0099aaac * 2 - DAT_0099aa8c;
      DAT_0099aa78 = DAT_0099aaac * 2 - DAT_0099aab0;
      (&PT_X0)[DAT_0099aa7c] = (int)ROUND(_DAT_0099aa88);
      (&PT_X0)[DAT_0099aa78] = (int)ROUND(_DAT_0099aa9c);
      DAT_0099aa80 = DAT_0099aa7c;
      for (iVar1 = (DAT_0099aa78 - DAT_0099aa7c) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
        *(undefined4 *)(&DAT_0099ba58 + DAT_0099aa94 * 4) = (&PT_X0)[DAT_0099aa80];
        *(undefined4 *)(&DAT_0099aab8 + DAT_0099aa94 * 4) = (&PT_Y0)[DAT_0099aa80];
        DAT_0099aa94 = DAT_0099aa94 + 1;
        DAT_0099aa80 = DAT_0099aa80 + 1;
      }
      *(undefined4 *)(&DAT_0099ba58 + DAT_0099aa94 * 4) = (&PT_X0)[DAT_0099aab0];
      *(undefined4 *)(&DAT_0099aab8 + DAT_0099aa94 * 4) = (&PT_Y0)[DAT_0099aab0];
      NPT = DAT_0099aa94;
      goto LAB_0053bd80;
    }
    DAT_0099aab0 = DAT_0099aab0 * 2 + 1;
    *(undefined2 *)((int)&DAT_01fbb8dc + DAT_0099aab0 * 2 + 2) = 2;
  }
  (&PT_X0)[DAT_0099aa8c] = (int)ROUND(_DAT_0099aa88);
  DAT_0099aa90 = (DAT_0099aaac - DAT_0099aa8c) * 2 + DAT_0099aab0;
  DAT_0099aa84 = DAT_0099aaac + 1;
  NPT = (DAT_0099aaac - DAT_0099aa8c) * 2 + DAT_0099aab0 + 1;
  *(undefined4 *)(&DAT_0099ba58 + DAT_0099aab0 * 4) = (&PT_X0)[DAT_0099aaac];
  (&PT_X0)[DAT_0099aaac * 2 - DAT_0099aa8c] = (int)ROUND(_DAT_0099aa88);
  *(undefined4 *)(&DAT_0099aab8 + DAT_0099aab0 * 4) = (&PT_Y0)[DAT_0099aaac];
  DAT_0099aa94 = DAT_0099aaac + -1;
  for (iVar1 = ((DAT_0099aa8c - DAT_0099aa94) + -1) / -1; DAT_0099aab0 = DAT_0099aab0 + 1, 0 < iVar1
      ; iVar1 = iVar1 + -1) {
    *(undefined4 *)(&DAT_0099ba58 + DAT_0099aab0 * 4) = (&PT_X0)[DAT_0099aa94];
    *(undefined4 *)(&DAT_0099aab8 + DAT_0099aab0 * 4) = (&PT_Y0)[DAT_0099aa94];
    *(undefined4 *)(&DAT_0099ba58 + DAT_0099aa90 * 4) = (&PT_X0)[DAT_0099aa84];
    *(undefined4 *)(&DAT_0099aab8 + DAT_0099aa90 * 4) = (&PT_Y0)[DAT_0099aa84];
    DAT_0099aa90 = DAT_0099aa90 + -1;
    DAT_0099aa84 = DAT_0099aa84 + 1;
    DAT_0099aa94 = DAT_0099aa94 + -1;
  }
  *(undefined4 *)(&DAT_0099ba58 + NPT * 4) = (&PT_X0)[DAT_0099aaac];
  *(undefined4 *)(&DAT_0099aab8 + NPT * 4) = (&PT_Y0)[DAT_0099aaac];
LAB_0053bd80:
  iVar1 = NPT;
  if (NPT < 0) {
    iVar1 = 0;
  }
  iVar4 = 1;
  iVar2 = 1;
  for (iVar3 = 1; iVar3 <= iVar1; iVar3 = iVar3 + 1) {
    (&PT_X0)[iVar2] = *(undefined4 *)(&DAT_0099ba58 + iVar4 * 4);
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 1;
  }
  iVar1 = NPT;
  if (NPT < 0) {
    iVar1 = 0;
  }
  iVar4 = 1;
  iVar3 = 1;
  for (iVar2 = 1; iVar2 <= iVar1; iVar2 = iVar2 + 1) {
    (&PT_Y0)[iVar3] = *(undefined4 *)(&DAT_0099aab8 + iVar4 * 4);
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 1;
  }
  ffree(in_ST0);
  return;
}


