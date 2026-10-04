// FUN_00560be2 @ 00560be2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00560be2(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 in_ST0;
  unkbyte10 Var4;
  float10 fVar5;
  float10 extraout_ST1;
  
  DAT_009a7a68 = 1;
  DAT_01e67910 = f_0;
  DAT_01e67914 = f_200;
  for (iVar3 = DAT_01c58604; 0 < iVar3; iVar3 = iVar3 + -1) {
    DAT_01fb8c60 = (float)DAT_009a7a68;
    ffree(in_ST0);
    DAT_01e9ad14 = DAT_01ba0d50;
    DAT_01e9ad1c = DAT_01ba0d54;
    DAT_01e9ad20 = DAT_01ba0d58;
    Var4 = thunk_FUN_004ebd10();
    if (-1 < DAT_01ba0d44) {
      ffree(Var4);
      Var4 = FUN_005611da(&DAT_01ba0d44);
    }
    DAT_01e9ad18 = 0;
    if ((DAT_01e99988 == 0) || (DAT_01e9ad14 == 0)) {
      DAT_01ba0d4c = 0;
    }
    if (DAT_01ba0d4c != 0) {
      ffree(Var4);
      Var4 = thunk_FUN_00562cc6(&DAT_00769e24,&DAT_01e9ad1c,&DAT_009a7a64,&DAT_01e9ad20);
      ffree(Var4);
      Var4 = thunk_FUN_004ec885(&DAT_009a7a64,&DAT_01e9a2ec);
      DAT_01e9ad18 = DAT_009a7a64;
      DAT_01e9ad14 = DAT_009a7a64;
    }
    ffree(Var4);
    in_ST0 = (float10)thunk_FUN_00561b90(&DAT_009a7a60);
    if (DAT_01e9ad1c % 0xc != 0) {
      LOAD_I = 1;
      for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
        ffree(in_ST0);
        in_ST0 = (float10)load_item_header();
        if ((((6 < LOAD_LEN) && (LOAD_CODE == 0xc)) && (LOAD_STAFF == DAT_009a7a68)) &&
           (((float)(&ITEM_P5)[LOAD_W] < f_0 && (*(float *)(&ITEM_P7 + LOAD_W * 4) != f_0)))) {
          DAT_009a7a5c = (int)ROUND(*(float *)(&ITEM_P7 + LOAD_W * 4));
          LOAD_STAFF = *(int *)(&DAT_0079f4e4 + (DAT_009a7a5c / 10) * 4);
          LOAD_LEN = DAT_009a7a5c % 10;
          if (LOAD_LEN == 2) {
            LOAD_LEN = -1;
          }
          LOAD_LEN = ((LOAD_STAFF - LOAD_LEN) + DAT_01e9ad1c) % 0xc;
          if (LOAD_LEN < 1) {
            LOAD_LEN = LOAD_LEN + 0xc;
          }
          *(float *)(&ITEM_P7 + LOAD_W * 4) = (float)*(int *)(&DAT_0079f4b4 + LOAD_LEN * 4);
        }
        LOAD_I = LOAD_I + 1;
      }
    }
    DAT_009a7a58 = (int)ROUND(DAT_01e67910 - f_4);
    DAT_009a7a54 = (int)ROUND(DAT_01e67914 + f_4);
    DAT_009a7a48 = 1;
    _DAT_009a7a50 = DAT_01fb8c60;
    fVar1 = _DAT_009a7a3c;
    _DAT_009a7a3c = (float)DAT_01e9ad20;
    for (iVar2 = ITEM_I; DAT_009a7a4c = _DAT_009a7a3c, 0 < iVar2; iVar2 = iVar2 + -1) {
      DAT_009a7a5c = (&ITEM_PTR0)[DAT_009a7a48];
      if (((_DAT_009a7a50 == (float)(&ITEM_P2)[DAT_009a7a5c]) &&
          (DAT_009a7a44 = (int)ROUND((float)(&ITEM_P1)[DAT_009a7a5c]), 4 < DAT_009a7a44)) &&
         ((DAT_009a7a44 < 7 &&
          ((DAT_009a7a40 = (int)ROUND((float)(&ITEM_P3)[DAT_009a7a5c]), DAT_009a7a40 <= DAT_009a7a54
           && (DAT_009a7a40 = (int)ROUND((float)(&ITEM_P6)[DAT_009a7a5c]),
              DAT_009a7a58 <= DAT_009a7a40)))))) {
        _DAT_009a7a38 = (float)(&ITEM_P4)[DAT_009a7a5c];
        if ((DAT_009a7a44 == 6) && (in_ST0 = (float10)_DAT_009a7a38, (float10)f_100 <= ABS(in_ST0)))
        {
          ffree(in_ST0);
          fVar5 = (float10)amod(&DAT_009a7a38,&f_100);
          _DAT_009a7a3c = (float)fVar5;
          _DAT_009a7a3c = DAT_009a7a4c + _DAT_009a7a3c;
          _DAT_009a7a38 = f_100;
          in_ST0 = extraout_ST1;
          if (_DAT_009a7a3c < f_0) {
            in_ST0 = (float10)f_100;
            _DAT_009a7a38 = (float)-in_ST0;
          }
        }
        (&ITEM_P4)[DAT_009a7a5c] = _DAT_009a7a3c + _DAT_009a7a38;
        (&ITEM_P5)[DAT_009a7a5c] = DAT_009a7a4c + (float)(&ITEM_P5)[DAT_009a7a5c];
        fVar1 = _DAT_009a7a3c;
      }
      _DAT_009a7a3c = fVar1;
      DAT_009a7a48 = DAT_009a7a48 + 1;
      fVar1 = _DAT_009a7a3c;
      _DAT_009a7a3c = DAT_009a7a4c;
    }
    if (DAT_01ba0d48 != 0) {
      ffree(in_ST0);
      _DAT_009a7a3c = fVar1;
      in_ST0 = (float10)thunk_FUN_0047c3e8(&DAT_00769e18);
      fVar1 = _DAT_009a7a3c;
    }
    _DAT_009a7a3c = fVar1;
    DAT_009a7a68 = DAT_009a7a68 + 1;
  }
  ffree(in_ST0);
  return;
}


