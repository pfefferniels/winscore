// FUN_004a2c81 @ 004a2c81 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a2c81(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 10;
  DAT_00838b3c = 1;
  while (*(short *)(DAT_00838b3c * 2 + param_2 + -2) != DAT_020b8ea0) {
    DAT_00838b3c = DAT_00838b3c + 1;
    iVar2 = iVar2 + -1;
    if (iVar2 < 1) {
      *param_1 = 0xffffffff;
      return;
    }
  }
  DAT_01fbb8a4 = DAT_00838b3c;
  thunk_FUN_00518448();
  if (DAT_00838b3c - 1U < 10) {
    if (DAT_00838b3c == 5) {
      DAT_01fbb860 = (int)ROUND(P1);
      DAT_01fbb868 = P2;
      DAT_01fbb86c = P3;
      DAT_01c58560 = P5;
      DAT_01fbb864 = (int)ROUND(P4);
      DAT_0078b378 = 1;
      FUN_004a217d();
      DAT_0078b378 = 0;
      return;
    }
    if (DAT_00838b3c == 6) {
      DAT_01fbb860 = (int)ROUND(P1);
      DAT_01fbb868 = f_m10;
      DAT_01fbb86c = f_210;
      DAT_01fbb864 = (int)ROUND((P2 + P1) - f_1);
      DAT_0078b378 = 1;
      DAT_01fbb8a4 = DAT_00838b3c;
      thunk_FUN_004b7ad8();
      DAT_0078b378 = 0;
      return;
    }
    if (DAT_00838b3c == 7) {
      thunk_FUN_0055b1f8();
      return;
    }
  }
  DAT_01fbb860 = (int)ROUND(P1);
  DAT_01fbb868 = P2;
  DAT_01fbb86c = P3;
  DAT_01fbb864 = (int)ROUND(P4);
  if (P3 == f_0) {
    DAT_01fbb86c = DAT_01fbb8b8;
  }
  iVar1 = 5;
  for (iVar2 = 1; iVar2 < 0x13; iVar2 = iVar2 + 1) {
    *(undefined4 *)(iVar2 * 4 + 0x1c5855c) = *(undefined4 *)(&P0 + iVar1 * 4);
    iVar1 = iVar1 + 1;
  }
  DAT_01fbb87c = ITEM_I;
  thunk_FUN_00518448();
  if (DAT_02052740 == 0) {
    return;
  }
  DAT_01fbb890 = (int)ROUND(P1);
  DAT_01fbb880 = P2;
  _DAT_01fbb884 = P3;
  _DAT_01fbb888 = P5;
  if ((DAT_01fbb8a4 == 10) && (DAT_02052760 = (int)ROUND(P4), P2 != f_0)) {
    DAT_02052760 = (int)ROUND(P2);
  }
  if (DAT_01fbb86c == f_0) {
    DAT_01fbb86c = DAT_01fbb8b8;
  }
  if ((P2 == f_0) && (P3 == f_0)) {
    DAT_01fbb880 = DAT_01fbb868;
    _DAT_01fbb884 = DAT_01fbb86c;
  }
  DAT_0078b378 = 1;
  thunk_FUN_00442800(&DAT_007637b4);
  DAT_0078b378 = 0;
  return;
}


