// FUN_0046f81d @ 0046f81d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0046f81d(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_18;
  int local_10;
  
  DAT_00824e70 = 0x15;
  if (P2 != f_0) {
    DAT_00824e70 = (int)ROUND((P2 - f_1) / f_10) * 10 + 1;
  }
  if (0x28 < DAT_00824e70) {
    DAT_00824e70 = 0x15;
  }
  DAT_00824e6c = 0x1e;
  for (iVar2 = 1; iVar2 < 0x2e; iVar2 = iVar2 + 1) {
    *(float *)(&DAT_01c25f9c + iVar2 * 4) = f_0;
  }
  DAT_00824e68 = (&ITEM_PTR0)[EDIT_ITEM];
  *param_1 = 0;
  DAT_00824e64 = (int)ROUND((float)(&ITEM_LEN)[DAT_00824e68]);
  DAT_00824e60 = (int)ROUND((float)(&ITEM_P1)[DAT_00824e68]);
  if ((0xe < DAT_00824e60) && (DAT_00824e60 < 0x11)) {
    if (DAT_00824e70 == 0x15) {
      return;
    }
    DAT_00824e6c = 0xd;
    if (*(float *)(&ITEM_P14 + DAT_00824e68 * 4) == f_m1) {
      DAT_00824e6c = 0x10;
    }
  }
  local_18 = 0xb;
  DAT_00824e60 = DAT_00824e70;
  do {
    if (DAT_00824e6c < DAT_00824e60) break;
    *param_1 = *param_1 + 1;
    if (DAT_00824e60 <= DAT_00824e64) {
      *(undefined4 *)(&DAT_01c25f9c + *param_1 * 4) = (&ITEM_LEN)[DAT_00824e60 + DAT_00824e68];
    }
    DAT_00824e60 = DAT_00824e60 + 1;
    local_18 = local_18 + -1;
  } while (0 < local_18);
  thunk_FUN_0054c590(&DAT_020b943c + DAT_00824e70 * 4,&DAT_01c25fc8,&DAT_00761f6c);
  if (DAT_00824e70 == 0x1f) {
    thunk_FUN_0054c590(0x20b94b8,&DAT_01c25fa0,&DAT_00761f6c);
  }
  thunk_FUN_0059a750(&DAT_01c25fa0,DAT_00824e70 + -0xb);
  *param_1 = 1;
  local_10 = 10;
  DAT_00824e60 = 1;
  do {
    if (*(float *)(&DAT_01c25f9c + DAT_00824e60 * 4) != *(float *)(DAT_00824e60 * 4 + 0x1c25fc4)) {
      *(float *)(&P0 + *param_1 * 4) = (float)(DAT_00824e70 + DAT_00824e60 + -1);
      (&P1)[*param_1] = *(float *)(DAT_00824e60 * 4 + 0x1c25fc4);
      *param_1 = *param_1 + 2;
    }
    DAT_00824e60 = DAT_00824e60 + 1;
    local_10 = local_10 + -1;
  } while (0 < local_10);
  puVar1 = &DAT_009ae2bc;
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


