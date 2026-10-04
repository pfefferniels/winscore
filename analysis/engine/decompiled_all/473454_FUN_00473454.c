// FUN_00473454 @ 00473454 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473454(void)

{
  int iVar1;
  
  iVar1 = (&ITEM_PTR0)[EDIT_ITEM];
  DAT_020b8e50 = (int)ROUND((float)(&ITEM_P1)[iVar1]);
  if (DAT_00824ffc != DAT_020b8e50) {
    DAT_00824ffc = 0;
  }
  if ((((DAT_020b8e50 != 7) ||
       (DAT_00824ff8 = (int)ROUND(*(float *)(&ITEM_P7 + iVar1 * 4)), DAT_00824ff8 == 0)) ||
      ((float)(&ITEM_LEN)[iVar1] < f_7)) &&
     ((*(int *)(&DAT_00790ce0 + DAT_020b8e50 * 4) == 0x71 && (f_5 <= (float)(&ITEM_LEN)[iVar1])))) {
    DAT_00824ff8 = (int)ROUND((float)(&ITEM_P5)[iVar1]);
  }
  DAT_00824ff4 = 0;
  if (DAT_00824ff0 == 0) {
    DAT_0078dc30 = 0;
  }
  DAT_00824ff0 = 0;
  DAT_01fbb700 = 0;
  _DAT_00824fec = 0;
  _DAT_01fbb740 = 0;
  if (0 < DAT_0205274c) {
    DAT_0205274c = 0;
  }
  DAT_00825000 = (&ITEM_PTR0)[EDIT_ITEM];
  DAT_020527c4 = (int)ROUND((float)(&ITEM_LEN)[DAT_00825000]);
  thunk_FUN_0054c419(&DAT_020b9448,&DAT_0076219c);
  if (DAT_020b8e50 == 0x10) {
    DAT_00824fe8 = (int)ROUND((*(float *)(&ITEM_P12 + DAT_00825000 * 4) + f_3) / f_4);
    DAT_020527c8 = 0xd;
    if (P14 == f_m1) {
      DAT_020527c8 = 0x10;
    }
    DAT_00824fe4 = DAT_020527c8 + 1;
    thunk_FUN_0054c473(&DAT_01fb8cf8,0x200);
    thunk_FUN_0054c590(&ITEM_LEN + DAT_00824fe4 + DAT_00825000,&DAT_01fb8cf8,&DAT_00824fe8);
    DAT_020527c4 = DAT_020527c8;
  }
  DAT_020527c8 = DAT_020527c4;
  thunk_FUN_0054c590(&ITEM_P1 + DAT_00825000,&DAT_020b9440,&DAT_020527c8);
  _DAT_0078dc34 = DAT_020527c8;
  DAT_00824fe8 = (int)ROUND(DAT_020b9440);
  if ((10 < DAT_00824fe8) && (DAT_00824fe8 == 0x10)) {
    _DAT_00824fe0 = DAT_020b9470 + DAT_020b9448;
    _DAT_00824fdc = (int)ROUND(DAT_020b946c + f_52);
  }
  if (DAT_0078dc30 < 0x7d1) {
    _DAT_0078dd58 = 0;
  }
  _DAT_02052750 = 0;
  return;
}


