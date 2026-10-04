// FUN_00545f58 @ 00545f58 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545f58(void)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  float10 fVar6;
  int local_6c;
  int local_64;
  int local_54;
  int local_34;
  
  DAT_0099f848 = DAT_02052740;
  DAT_02052740 = 0;
  if ((P2 == f_0) && (P3 == f_0)) {
    ffree(in_ST0);
    DAT_0099f844 = thunk_FUN_0059d0a0(&DAT_0099f84c);
    ffree(extraout_ST0);
    fVar6 = (float10)thunk_FUN_00468df8(&DAT_00768f54);
    if (DAT_0099f844 == 2) goto LAB_005468fb;
    puVar3 = &DAT_009ae2bc;
    puVar4 = (undefined4 *)&DAT_020b8ea0;
    for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    for (iVar2 = 1; iVar2 < 0x33; iVar2 = iVar2 + 1) {
      *(float *)(&P0 + iVar2 * 4) = f_0;
    }
    ffree(fVar6);
    in_ST0 = thunk_FUN_00518448();
    local_6c = 0x2c;
    DAT_0099f840 = 0x2d;
    do {
      *(undefined4 *)(&P0 + DAT_0099f840 * 4) = *(undefined4 *)(&DAT_020b9358 + DAT_0099f840 * 4);
      DAT_0099f840 = DAT_0099f840 + -1;
      local_6c = local_6c + -1;
    } while (0 < local_6c);
  }
  if ((DAT_0099f844 == 1) || (DAT_020b8ea4 == 'X')) {
    puVar3 = (undefined4 *)&DAT_020b90a0;
    puVar4 = &DAT_009ae2bc;
    for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    ffree(in_ST0);
    in_ST0 = FUN_00546a1b();
    DAT_020b8ea4 = DAT_00768f50;
  }
  ffree(in_ST0);
  fVar6 = (float10)thunk_FUN_0054e546(&DAT_0099f83c,&DAT_0099f838);
  for (iVar2 = 1; fVar1 = P2, iVar2 < 0x259; iVar2 = iVar2 + 1) {
    (&DAT_01fb8cc0)[iVar2] = f_0;
  }
  DAT_0099f834 = 2;
  if (DAT_020b8ea4 == 'X') {
    fVar6 = (float10)P2;
    for (iVar2 = 1; iVar2 < 0x17; iVar2 = iVar2 + 1) {
      *(float *)(iVar2 * 4 + 0x1fb91c4) = fVar1;
    }
    local_64 = 0x2d;
    DAT_0099f830 = 1;
    do {
      if (((&P2)[DAT_0099f830] == f_0) || (_DAT_0099f83c <= (&P2)[DAT_0099f830])) goto LAB_0054633f;
      *(int *)(DAT_0099f830 * 4 + 0x1fb916c) = (int)ROUND((&P2)[DAT_0099f830]);
      DAT_0099f830 = DAT_0099f830 + 1;
      local_64 = local_64 + -1;
    } while (0 < local_64);
  }
  else {
    if (P2 == f_0) {
      P2 = f_999;
    }
    local_54 = 0x2e;
    DAT_0099f830 = 1;
    do {
      if ((_DAT_0099f83c == *(float *)(&P0 + DAT_0099f834 * 4)) ||
         (*(float *)(&P0 + DAT_0099f834 * 4) == f_0)) goto LAB_0054633f;
      *(int *)(DAT_0099f830 * 4 + 0x1fb916c) = (int)ROUND(*(float *)(&P0 + DAT_0099f834 * 4));
      *(float *)(DAT_0099f830 * 4 + 0x1fb91c4) = (&P1)[DAT_0099f834];
      DAT_0099f834 = DAT_0099f834 + 2;
      DAT_0099f830 = DAT_0099f830 + 1;
      local_54 = local_54 + -1;
    } while (0 < local_54);
  }
  ffree(fVar6);
  fVar6 = (float10)thunk_FUN_0054d831(&DAT_00768f08,0x15);
  goto LAB_005468fb;
LAB_0054633f:
  DAT_0099f830 = DAT_0099f830 + -1;
  DAT_0099f840 = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    DAT_0099f834 = (&ITEM_PTR0)[DAT_0099f840];
    if (((float)(&ITEM_P1)[DAT_0099f834] == f_8) &&
       (DAT_0099f844 = (int)ROUND((float)(&ITEM_P2)[DAT_0099f834]), DAT_0099f844 != 0)) {
      (&DAT_01fb8cc0)[DAT_0099f844] = DAT_0099f840;
    }
    DAT_0099f840 = DAT_0099f840 + 1;
  }
  ffree(fVar6);
  fVar6 = (float10)thunk_FUN_005725fa();
  DAT_0099f82c = 0;
  if ((0x100 < DAT_01fb9170) || (DAT_01fb9170 == 0)) {
    DAT_0099f82c = 1;
  }
  if (DAT_0099f830 == 0) {
    DAT_0099f830 = 1;
  }
  DAT_0099f828 = 1;
  for (iVar2 = DAT_0099f830; 0 < iVar2; iVar2 = iVar2 + -1) {
    local_34 = 200;
    DAT_0099f840 = 1;
    do {
      if ((DAT_0099f82c != 0) || (DAT_0099f840 == *(int *)(DAT_0099f828 * 4 + 0x1fb916c))) {
        IP1 = (&STAFF_Y0)[DAT_0099f840];
        fVar6 = (float10)IP1;
        _DAT_0099f824 =
             (int)ROUND((float10)(float)(&STAFF_STEP0)[DAT_0099f840] * (float10)f_77 + fVar6);
        DAT_0099f820 = DAT_0099f840;
        do {
          DAT_0099f820 = DAT_0099f820 + 1;
          if (199 < DAT_0099f820) {
            if (DAT_0099f830 == 1) goto LAB_00546815;
            ffree(fVar6);
            fVar6 = (float10)thunk_FUN_0054d831("No upper staff found.",0x16);
            goto LAB_005468fb;
          }
        } while ((&DAT_01fb8cc0)[DAT_0099f820] == 0);
        DAT_0099f81c = (int)ROUND((float)(&STAFF_STEP0)[DAT_0099f820] * f_21 +
                                  (float)(int)(&STAFF_Y0)[DAT_0099f820]);
        _DAT_0099f818 = DAT_0099f81c - _DAT_0099f824;
        _DAT_0099f814 = *(float *)(DAT_0099f828 * 4 + 0x1fb91c4);
        if (DAT_0099f82c != 0) {
          _DAT_0099f814 = DAT_01fb91c8;
        }
        if (DAT_0078b4e8 == 1) {
          _DAT_0099f814 = _DAT_0099f814 / f_2_54;
        }
        fVar6 = (float10)_DAT_0099f814 * (float10)f_4000;
        _DAT_0099f810 = (int)ROUND(fVar6 - (float10)_DAT_0099f818);
        DAT_0099f834 = DAT_0099f820;
        for (iVar5 = 0xc9 - DAT_0099f820; 0 < iVar5; iVar5 = iVar5 + -1) {
          if ((&DAT_01fb8cc0)[DAT_0099f834] != 0) {
            (&STAFF_Y0)[DAT_0099f834] = (&STAFF_Y0)[DAT_0099f834] + _DAT_0099f810;
            DAT_0099f80c = (&ITEM_PTR0)[(&DAT_01fb8cc0)[DAT_0099f834]];
            if ((float)(&ITEM_LEN)[DAT_0099f80c] < f_4) {
              _DAT_0099f814 = f_0;
              ffree(fVar6);
              thunk_FUN_005239c9(&DAT_01fb8cc0 + DAT_0099f834,&f_4);
            }
            else {
              _DAT_0099f814 = (float)(&ITEM_P4)[DAT_0099f80c];
            }
            fVar6 = (float10)_DAT_0099f810;
            _DAT_0099f808 =
                 (float)(((float10)f_25 / (float10)(float)(&STAFF_STEP0)[DAT_0099f834]) * fVar6);
            (&ITEM_P4)[DAT_0099f80c] = _DAT_0099f808 / f_175 + _DAT_0099f814;
            if (f_999 <= (float)(&ITEM_P4)[DAT_0099f80c]) {
              IP2 = (int)ROUND((float)(&ITEM_P2)[DAT_0099f80c]);
              ffree(fVar6);
              fVar6 = (float10)staff_p4_error(&IP2,&ITEM_P4 + DAT_0099f80c,&DAT_00768f20);
              goto LAB_005468fb;
            }
          }
          DAT_0099f834 = DAT_0099f834 + 1;
        }
      }
      DAT_0099f840 = DAT_0099f840 + 1;
      local_34 = local_34 + -1;
    } while (0 < local_34);
LAB_00546815:
    DAT_0099f828 = DAT_0099f828 + 1;
  }
LAB_005468fb:
  DAT_02052740 = DAT_0099f848;
  ffree(fVar6);
  return;
}


