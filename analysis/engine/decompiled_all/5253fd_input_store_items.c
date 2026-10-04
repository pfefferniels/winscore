// input_store_items @ 005253fd (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void input_store_items(void)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  unkbyte10 Var3;
  int local_1c;
  
  if (DAT_01fbb700 == 1) {
    DAT_0094e710 = 0;
    DAT_0094e70c = 2;
    iVar1 = DAT_01fb8c80;
    while (iVar1 = iVar1 + -1, 0 < iVar1) {
      if ((float)(&DAT_01f95d4c)[DAT_0094e70c * 0xf] != (float)(&DAT_01f95d10)[DAT_0094e70c * 0xf])
      {
        DAT_0094e710 = DAT_0094e710 + 1;
      }
      DAT_0094e70c = DAT_0094e70c + 1;
    }
    in_ST0 = (float10)DAT_00796fd4 - (float10)DAT_00796fd0;
    _DAT_0094e708 = (float)(in_ST0 / (float10)DAT_0094e710);
    if (DAT_00796fd0 < f_1) {
      DAT_00796fd0 = f_1;
    }
    if (_DAT_0094e708 < f_5) {
      _DAT_0094e708 = f_5;
    }
    DAT_0094e70c = 2;
    DAT_0094e704 = DAT_00796fd0;
    DAT_0094e714 = DAT_00796fd0;
    iVar1 = DAT_01fb8c80;
    while (iVar1 = iVar1 + -1, 0 < iVar1) {
      if ((float)(&DAT_01f95d4c)[DAT_0094e70c * 0xf] != (float)(&DAT_01f95d10)[DAT_0094e70c * 0xf])
      {
        DAT_0094e704 = _DAT_0094e708 + DAT_0094e704;
      }
      (&DAT_0094e710)[DAT_0094e70c] = (int)DAT_0094e704;
      DAT_0094e70c = DAT_0094e70c + 1;
    }
    DAT_0094e70c = 1;
    for (iVar1 = DAT_01fb8c80; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&DAT_01f95d4c)[DAT_0094e70c * 0xf] = (&DAT_0094e710)[DAT_0094e70c];
      DAT_0094e70c = DAT_0094e70c + 1;
    }
  }
  if (DAT_01fbb700 != 2) {
    DAT_0094e700 = 1;
  }
  if (((f_256 < _DAT_01fb8c64) && (DAT_0094e700 != 0)) && (DAT_01fbb700 == 2)) {
    ffree(in_ST0);
    in_ST0 = (float10)input_min_gap(&DAT_01fb8c80);
  }
  if (DAT_01fbb700 == 2) {
    DAT_0094e700 = 0;
  }
  ITEM_COUNT_SAVE = DAT_020b8e58 + 1;
  DAT_0094e70c = 1;
  DAT_0094e6fc = DAT_020b8e54;
  ITEM_I = ITEM_COUNT_SAVE;
  for (iVar1 = DAT_01fb8c80; 0 < iVar1; iVar1 = iVar1 + -1) {
    if (DAT_01fbb700 == 1) {
      DAT_0094e6f8 = 0xc;
    }
    else {
      DAT_0094e6f4 = 0xc;
      if (f_6 <= (float)(&DAT_01f95d44)[DAT_0094e70c * 0xf]) {
        DAT_0094e6f4 = 0xf;
      }
      iVar2 = -DAT_0094e6f4 / -1;
      for (DAT_0094e6f8 = DAT_0094e6f4;
          (0 < iVar2 && ((float)(&DAT_01f95d40)[DAT_0094e6f8 + DAT_0094e70c * 0xf] == f_0));
          DAT_0094e6f8 = DAT_0094e6f8 + -1) {
        iVar2 = iVar2 + -1;
      }
    }
    DAT_0094e6f0 = 1;
    for (iVar2 = DAT_0094e6f8; 0 < iVar2; iVar2 = iVar2 + -1) {
      (&ITEM_LEN)[DAT_0094e6f0 + DAT_0094e6fc] = (&DAT_01f95d40)[DAT_0094e70c * 0xf + DAT_0094e6f0];
      DAT_0094e6f0 = DAT_0094e6f0 + 1;
    }
    if ((DAT_01fbb700 == 1) && ((float)(&DAT_01f95d44)[DAT_0094e70c * 0xf] < f_3)) {
      DAT_0094e6f8 = 0x1a;
      local_1c = 0xd;
      DAT_0094e6ec = 0xd;
      do {
        (&ITEM_LEN)[DAT_0094e6ec + DAT_0094e6fc] = f_0;
        DAT_0094e6ec = DAT_0094e6ec + 1;
        local_1c = local_1c + -1;
      } while (0 < local_1c);
      *(float *)(&ITEM_P26 + DAT_0094e6fc * 4) = f_6800;
    }
    (&ITEM_LEN)[DAT_0094e6fc] = (float)DAT_0094e6f8;
    DAT_0094e6fc = DAT_0094e6f8 + DAT_0094e6fc + 1;
    DAT_0094e70c = DAT_0094e70c + 1;
  }
  ffree(in_ST0);
  ITEM_WORDS = DAT_0094e6fc;
  Var3 = index_items();
  DAT_0094e70c = 1;
  iVar1 = DAT_01fb8c80;
  do {
    if (iVar1 < 1) {
LAB_00525996:
      ITEM_WORDS = DAT_0094e6fc;
      _DAT_0094e6e4 = (int)ROUND(DAT_01fb8c60);
      if (DAT_01be12e0 == 0) {
        ffree(Var3);
        Var3 = draw_items();
      }
      ffree(Var3);
      return;
    }
    if ((float)(&DAT_01f95d44)[DAT_0094e70c * 0xf] == f_6) {
      P2 = DAT_01fb8c60;
      P3 = f_1;
      P4 = DAT_01fbb8b8;
      P5 = DAT_01fb8c60;
      DAT_0094e6e8 = ITEM_WORDS;
      ITEM_WORDS = DAT_0094e6fc;
      ffree(Var3);
      Var3 = thunk_FUN_0040cde4(&DAT_020b8e58);
      DAT_0094e6fc = (&DAT_02091d20)[ITEM_I];
      ITEM_I = ITEM_COUNT_SAVE;
      goto LAB_00525996;
    }
    DAT_0094e70c = DAT_0094e70c + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


