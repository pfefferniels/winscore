// FUN_00473d22 @ 00473d22 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473d22(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var4;
  float10 fVar5;
  undefined1 *puVar6;
  
  puVar6 = &stack0xfffffffc;
  if ((DAT_020b8ea2 == 'A') || (DAT_020b8ea2 == 'S')) {
    ffree(in_ST0);
    Var4 = thunk_FUN_0054e546(&DAT_00825218,&DAT_00825214);
    DAT_00825210 = (int)ROUND(P2);
    DAT_0082520c = (int)ROUND(P3);
    if (DAT_00825210 == 0) {
      DAT_00825210 = (int)ROUND(_DAT_00825214);
    }
    if (DAT_0082520c == 0) {
      DAT_0082520c = (int)ROUND(_DAT_00825218);
    }
    DAT_00825208 = (uint)(DAT_020b8ea2 == 'A');
    DAT_00825204 = 0;
    do {
      DAT_00825204 = DAT_00825204 + 1;
      DAT_00825200 = (&ITEM_PTR0)[DAT_00825204];
      if (((float)(&ITEM_P1)[DAT_00825200] == f_8) && ((float)(&ITEM_LEN)[DAT_00825200] <= f_3)) {
        ffree(Var4);
        Var4 = thunk_FUN_005239c9(&DAT_00825204,&f_4);
      }
    } while (DAT_00825204 <= ITEM_I);
    FUN_005f33c9(&stack0xfffffffc,0x473f73);
    Var4 = FUN_005f34d1(puVar6,0x473f8e);
    ffree(Var4);
    fVar5 = (float10)thunk_FUN_004f7808();
    if (DAT_00825208 == 1) {
      DAT_020b8ea2 = DAT_007621cc;
    }
    for (iVar2 = 1; iVar3 = ITEM_I, iVar2 < 0x81; iVar2 = iVar2 + 1) {
      *(undefined4 *)(&DAT_00825218 + iVar2 * 4) = 0;
    }
    if (DAT_020b8ea2 == 'A') {
      *(undefined4 *)(puVar6 + -0x58) = 0;
    }
    else {
      *(int *)(puVar6 + -0x54) = ITEM_I;
      LOAD_I = 1;
      while (0 < iVar3) {
        ffree(fVar5);
        fVar5 = (float10)load_item_header();
        if (DAT_008251fc < LOAD_STAFF) {
          DAT_008251fc = LOAD_STAFF;
        }
        if ((LOAD_CODE == 0xe) && (LOAD_STAFF <= DAT_0082520c)) {
          DAT_00825200 = 1;
          if (3 < LOAD_LEN) {
            fVar1 = (float)(&ITEM_P4)[LOAD_W];
            *(undefined2 *)(puVar6 + -0x90) = in_FPUControlWord;
            *(ushort *)(puVar6 + -0x8e) = (ushort)*(undefined4 *)(puVar6 + -0x90) | 0xc00;
            *(int *)(puVar6 + -0x8c) = (int)ROUND(fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar6 + -0x90);
            DAT_00825200 = *(int *)(puVar6 + -0x8c);
          }
          if (*(int *)(&DAT_00825218 + LOAD_STAFF * 4) < DAT_00825200) {
            *(int *)(&DAT_00825218 + LOAD_STAFF * 4) = DAT_00825200;
          }
        }
        else {
          *(undefined4 *)(puVar6 + -0x50) = 0;
        }
        *(undefined4 *)(puVar6 + -0x4c) = 0;
        LOAD_I = LOAD_I + 1;
        *(int *)(puVar6 + -0x54) = *(int *)(puVar6 + -0x54) + -1;
        iVar3 = *(int *)(puVar6 + -0x54);
      }
    }
    DAT_008251f8 = 0;
    for (iVar2 = 1; iVar2 < 0x101; iVar2 = iVar2 + 1) {
      *(float *)(&DAT_00825a18 + iVar2 * 4) = f_0;
    }
    for (iVar2 = 1; iVar3 = ITEM_I, iVar2 < 0x101; iVar2 = iVar2 + 1) {
      *(undefined4 *)(&DAT_00826618 + iVar2 * 4) = 0;
    }
    *(int *)(puVar6 + -0x48) = ITEM_I;
    LOAD_I = 1;
    iVar2 = DAT_00825210;
    while (DAT_00825210 = iVar2, 0 < iVar3) {
      ffree(fVar5);
      fVar5 = (float10)load_item_header();
      if (LOAD_CODE == 8) {
        DAT_008251f8 = LOAD_STAFF;
        *(float *)(&DAT_00825e18 + LOAD_STAFF * 4) = (float)(int)(&STAFF_Y0)[LOAD_STAFF];
        if (DAT_020b8ea2 == 'A') {
          *(undefined4 *)(&DAT_00825218 + DAT_008251f8 * 4) = 1;
        }
        _DAT_008251f4 = f_1;
        if ((4 < LOAD_LEN) && ((float)(&ITEM_P5)[LOAD_W] != f_0)) {
          _DAT_008251f4 = (float)(&ITEM_P5)[LOAD_W];
        }
        *(float *)(&DAT_00825a18 + DAT_008251f8 * 4) = _DAT_008251f4 * f_175;
        *(int *)(&DAT_00826618 + DAT_008251f8 * 4) = LOAD_W + 4;
      }
      else {
        *(undefined4 *)(puVar6 + -0x44) = 0;
      }
      *(undefined4 *)(puVar6 + -0x40) = 0;
      LOAD_I = LOAD_I + 1;
      *(int *)(puVar6 + -0x48) = *(int *)(puVar6 + -0x48) + -1;
      iVar2 = DAT_00825210;
      iVar3 = *(int *)(puVar6 + -0x48);
    }
    if (DAT_020b8ea2 == 'A') {
      *(undefined4 *)(puVar6 + -0x3c) = 0;
    }
    else {
      iVar3 = (DAT_0082520c - iVar2) + 1;
      *(int *)(puVar6 + -0x38) = iVar3;
      DAT_008251f0 = iVar2;
      while (0 < iVar3) {
        if (*(int *)(&DAT_00825218 + DAT_008251f0 * 4) == 0) {
          *(undefined4 *)(puVar6 + -0x34) = 0;
        }
        else {
          DAT_008251ec = *(int *)(&DAT_00825218 + DAT_008251f0 * 4) + DAT_008251f0 + -1;
          DAT_008251f8 = DAT_008251f0 + 1;
          iVar2 = (DAT_008251ec - DAT_008251f8) + 1;
          *(int *)(puVar6 + -0x30) = iVar2;
          while (0 < iVar2) {
            *(undefined4 *)(&DAT_00825218 + DAT_008251f8 * 4) = 0;
            DAT_008251f8 = DAT_008251f8 + 1;
            *(int *)(puVar6 + -0x30) = *(int *)(puVar6 + -0x30) + -1;
            iVar2 = *(int *)(puVar6 + -0x30);
          }
        }
        *(undefined4 *)(puVar6 + -0x2c) = 0;
        DAT_008251f0 = DAT_008251f0 + 1;
        *(int *)(puVar6 + -0x38) = *(int *)(puVar6 + -0x38) + -1;
        iVar3 = *(int *)(puVar6 + -0x38);
      }
    }
    DAT_008251f0 = DAT_00825210;
    DAT_00825200 = 0;
    DAT_00825204 = 0;
    iVar2 = (DAT_0082520c - DAT_00825210) + 1;
    *(int *)(puVar6 + -0x28) = iVar2;
    while (0 < iVar2) {
      if (*(int *)(&DAT_00825218 + DAT_008251f0 * 4) == 0) {
        *(undefined4 *)(puVar6 + -0x24) = 0;
      }
      else {
        DAT_008251e8 = *(int *)(&DAT_00825218 + DAT_008251f0 * 4) + DAT_008251f0 + -1;
        DAT_008251f8 = DAT_008251f0;
        while (DAT_008251f8 = DAT_008251f8 + 1, DAT_008251f8 <= DAT_0082520c) {
          if (*(int *)(&DAT_00825218 + DAT_008251f8 * 4) != 0) goto LAB_00474418;
          *(undefined4 *)(puVar6 + -0x1c) = 0;
        }
        *(undefined4 *)(puVar6 + -0x20) = 0;
LAB_00474418:
        DAT_008251e4 = DAT_008251f8;
        DAT_00825200 = DAT_00825200 + 1;
        *(int *)(DAT_00825200 * 4 + 0x825818) = DAT_008251e8;
        *(int *)(DAT_00825200 * 4 + 0x825418) = DAT_008251e4;
      }
      *(undefined4 *)(puVar6 + -0x18) = 0;
      DAT_008251f0 = DAT_008251f0 + 1;
      *(int *)(puVar6 + -0x28) = *(int *)(puVar6 + -0x28) + -1;
      iVar2 = *(int *)(puVar6 + -0x28);
    }
    iVar2 = DAT_00825200 + -1;
    DAT_00825200 = iVar2;
    *(int *)(puVar6 + -0x14) = iVar2;
    DAT_008251f0 = 1;
    iVar3 = DAT_00825200;
    while (DAT_00825200 = iVar3, 0 < iVar2) {
      DAT_008251e8 = *(int *)(DAT_008251f0 * 4 + 0x825818);
      DAT_008251e4 = *(int *)(DAT_008251f0 * 4 + 0x825418);
      (&DAT_01fb8cc0)[DAT_008251f0] =
           *(float *)(&DAT_00825a18 + DAT_008251e4 * 4) * f_3 +
           (float)(int)(&STAFF_Y0)[DAT_008251e4];
      fVar5 = (float10)(int)(&STAFF_Y0)[DAT_008251e8];
      *(float *)(&P0 + DAT_008251f0 * 4) =
           (float)((float10)*(float *)(&DAT_00825a18 + DAT_008251e8 * 4) * (float10)f_11 + fVar5);
      DAT_008251f0 = DAT_008251f0 + 1;
      *(int *)(puVar6 + -0x14) = *(int *)(puVar6 + -0x14) + -1;
      iVar3 = DAT_00825200;
      iVar2 = *(int *)(puVar6 + -0x14);
    }
    _DAT_008251e0 = f_0;
    *(int *)(puVar6 + -0x10) = iVar3;
    DAT_008251f0 = 1;
    iVar2 = DAT_00825200;
    while (DAT_00825200 = iVar2, 0 < iVar3) {
      *(float *)(&DAT_020b943c + DAT_008251f0 * 4) =
           (float)(&DAT_01fb8cc0)[DAT_008251f0] - *(float *)(&P0 + DAT_008251f0 * 4);
      _DAT_008251e0 = _DAT_008251e0 + *(float *)(&DAT_020b943c + DAT_008251f0 * 4);
      DAT_008251f0 = DAT_008251f0 + 1;
      *(int *)(puVar6 + -0x10) = *(int *)(puVar6 + -0x10) + -1;
      iVar2 = DAT_00825200;
      iVar3 = *(int *)(puVar6 + -0x10);
    }
    _DAT_008251e0 = _DAT_008251e0 / (float)iVar2;
    DAT_008251f8 = 1;
    _DAT_008251dc = f_0;
    *(int *)(puVar6 + -0xc) = iVar2;
    DAT_008251f0 = 1;
    while (0 < iVar2) {
      DAT_008251d8 = _DAT_008251e0 - *(float *)(&DAT_020b943c + DAT_008251f0 * 4);
      DAT_00825204 = *(int *)(DAT_008251f0 * 4 + 0x825418);
      iVar2 = ((&DAT_0082581c)[DAT_008251f0] - DAT_00825204) + 1;
      *(int *)(puVar6 + -8) = iVar2;
      while (0 < iVar2) {
        _DAT_008251d4 = DAT_008251d8 / *(float *)(&DAT_00825a18 + DAT_00825204 * 4);
        (&ITEM_LEN)[*(int *)(&DAT_00826618 + DAT_00825204 * 4)] =
             _DAT_008251d4 + (float)(&ITEM_LEN)[*(int *)(&DAT_00826618 + DAT_00825204 * 4)];
        DAT_00825204 = DAT_00825204 + 1;
        *(int *)(puVar6 + -8) = *(int *)(puVar6 + -8) + -1;
        iVar2 = *(int *)(puVar6 + -8);
      }
      _DAT_008251dc = DAT_008251d8;
      (&DAT_020b9440)[DAT_008251f0] = (float)(&DAT_020b9440)[DAT_008251f0] - DAT_008251d8;
      *(undefined4 *)(puVar6 + -4) = 0;
      DAT_008251f0 = DAT_008251f0 + 1;
      *(int *)(puVar6 + -0xc) = *(int *)(puVar6 + -0xc) + -1;
      iVar2 = *(int *)(puVar6 + -0xc);
    }
    ffree(fVar5);
    Var4 = draw_items();
    ffree(Var4);
    Var4 = draw_items();
  }
  else {
    ffree(in_ST0);
    Var4 = thunk_FUN_0054d831(&DAT_007621e0,0x4b);
  }
  ffree(Var4);
  return;
}


