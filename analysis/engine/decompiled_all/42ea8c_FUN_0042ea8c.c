// FUN_0042ea8c @ 0042ea8c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042ea8c(void)

{
  float fVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  
  puVar2 = &stack0xfffffffc;
  _DAT_007f13e8 = f_0;
  if (P2 < f_0) {
    _DAT_007f13e8 = P2;
    thunk_FUN_0054c590(&P3,&P2,&DAT_0075fe5c);
  }
  DAT_007f13e4 = (int)ROUND(P2);
  _DAT_007f13e0 = P3;
  _DAT_007f13dc = P4;
  if (DAT_007f13e4 == 0) {
    DAT_007f13e4 = 1;
  }
  if (P4 == f_0) {
    _DAT_007f13dc = f_200;
  }
  DAT_007f13d8 = (int)ROUND(P5);
  if (DAT_007f13d8 == 0) {
    DAT_007f13d8 = DAT_007f13e4;
  }
  if (P2 == f_0) {
    DAT_007f13d8 = 999;
  }
  DAT_020b9440 = f_16;
  DAT_0078b4e4 = 0x4e;
  DAT_007f13d4 = (uint)(DAT_020b8ea2 == 'X');
  thunk_FUN_005725fa();
  DAT_007f13d0 = 1;
  iVar3 = ITEM_I;
  while (0 < iVar3) {
    LOAD_I = DAT_007f13d0;
    FUN_005f33c9(puVar2,0x42ec3b);
    FUN_005f34d1(puVar2,0x42ec56);
    load_item_header();
    if (LOAD_CODE == 0x10) {
      if ((LOAD_STAFF < DAT_007f13e4) || (DAT_007f13d8 < LOAD_STAFF)) {
        *(undefined4 *)(puVar2 + -0x14) = 0;
      }
      else if ((LOAD_P3 < _DAT_007f13e0) || (_DAT_007f13dc < LOAD_P3)) {
        *(undefined4 *)(puVar2 + -0x10) = 0;
      }
      else if ((_DAT_007f13e8 == f_0) || ((float)(&ITEM_P4)[LOAD_W] <= _DAT_007f13e8)) {
        DAT_020b9448 = LOAD_P3;
        DAT_020b9470 = (&ITEM_P13)[LOAD_W];
        DAT_01caf6a0 = LOAD_STAFF;
        P2 = (float)LOAD_STAFF;
        EDIT_ITEM = DAT_007f13d0;
        DAT_007f13cc = LOAD_W;
        thunk_FUN_0045ef21();
        DAT_020b9448 = P2;
        (&ITEM_P3)[DAT_007f13cc] = P2;
        FUN_005f34d1(puVar2,0x42ed8f);
        if (DAT_007f13d4 == 0) {
          *(undefined4 *)(puVar2 + -8) = 0;
        }
        else {
          iVar3 = (&ITEM_PTR0)[DAT_007f13d0];
          fVar1 = *(float *)(&ITEM_P12 + iVar3 * 4);
          *(undefined2 *)(puVar2 + -0x44) = in_FPUControlWord;
          *(ushort *)(puVar2 + -0x42) = (ushort)*(undefined4 *)(puVar2 + -0x44) | 0xc00;
          *(int *)(puVar2 + -0x40) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar2 + -0x44);
          IP12 = *(int *)(puVar2 + -0x40);
          if (*(float *)(&ITEM_P14 + iVar3 * 4) == f_m1) {
            DAT_007f13c8 = 0x11;
          }
          else {
            DAT_007f13c8 = 0xe;
          }
          P5 = (float)(&ITEM_P5)[iVar3];
          if (P5 == f_0) {
            P5 = f_1;
          }
          P48 = (float)(&ITEM_P6)[iVar3];
          if (P48 == f_0) {
            P48 = f_1;
          }
          DAT_01caf6b0 = DAT_007f13c8 + iVar3;
          thunk_FUN_0042fa58(&ITEM_LEN + DAT_01caf6b0,4,&IP12);
          P2 = DAT_01caf68c;
          DAT_007f13c4 = (&DAT_01caea3c)[DAT_01cb1068];
          DAT_007f13c0 = DAT_01caea44;
          _DAT_007f13bc = f_0;
          if ((((DAT_007f13c4 == 0x4e) || (DAT_007f13c4 == 0x4c)) || (DAT_007f13c4 == 0x24)) ||
             ((DAT_007f13c4 == 0x25 || (DAT_007f13c4 < 0x46 && 0x41 < DAT_007f13c4)))) {
            _DAT_007f13bc = *(float *)(&DAT_01cadd3c + DAT_01cb1068 * 4) / f_2;
          }
          if (((DAT_01caea44 == 0x4e) || (DAT_01caea44 == 0x80)) || (DAT_01caea44 == 0x68)) {
            _DAT_007f13bc = _DAT_007f13bc - DAT_01cadd44 / f_2;
          }
          P4 = _DAT_007f13bc + P4;
        }
        (&ITEM_P3)[DAT_007f13cc] = P2;
        *(float *)(&ITEM_P11 + DAT_007f13cc * 4) = P4;
        DAT_020b9448 = P2;
        DAT_020b9468 = P4;
        (&ITEM_P3)[DAT_007f13cc] = P2;
        *(float *)(&ITEM_P11 + DAT_007f13cc * 4) = P4;
      }
      else {
        *(undefined4 *)(puVar2 + -0xc) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar2 + -0x18) = 0;
    }
    *(undefined4 *)(puVar2 + -4) = 0;
    DAT_007f13d0 = DAT_007f13d0 + 1;
    *(int *)(puVar2 + -0x1c) = *(int *)(puVar2 + -0x1c) + -1;
    iVar3 = *(int *)(puVar2 + -0x1c);
  }
  EDIT_ITEM = 0;
  for (iVar3 = 1; iVar3 < 0x33; iVar3 = iVar3 + 1) {
    *(float *)(&P0 + iVar3 * 4) = f_0;
  }
  draw_items();
  DAT_0205274c = 0;
  return;
}


