// FUN_004c4f72 @ 004c4f72 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c4f72(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar4;
  float10 extraout_ST1;
  uint local_54;
  int local_50;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  DAT_0089fbb4 = DAT_00794834;
  DAT_00794830 = DAT_00794830 + -1;
  DAT_0089fbac = 0;
  DAT_0089fbb0 = DAT_00794830;
  for (iVar1 = 1; iVar1 < 0x12d; iVar1 = iVar1 + 1) {
    *(float *)(&DAT_01add2fc + iVar1 * 4) = f_0;
  }
  for (iVar1 = 1; iVar1 < 0x12d; iVar1 = iVar1 + 1) {
    *(float *)(&DAT_01addc5c + iVar1 * 4) = f_0;
  }
  for (iVar1 = 1; iVar1 < 0x12d; iVar1 = iVar1 + 1) {
    *(float *)(&DAT_01add7ac + iVar1 * 4) = f_0;
  }
  local_2c = *param_1;
  DAT_0089fba8 = 1;
  _DAT_0089fbb8 = f_m99;
  do {
    if (local_2c < 1) {
      DAT_0089fbac = (DAT_00794830 - *param_1) + 1;
      local_1c = *param_1;
      DAT_0089fba0 = 1;
      for (; 0 < local_1c; local_1c = local_1c + -1) {
        _DAT_0089fb9c = *(float *)(&DAT_01add2fc + DAT_0089fbac * 4);
        DAT_0089fb98 = *(float *)(&DAT_01add7ac + DAT_0089fbac * 4);
        _DAT_0089fb94 = *(float *)(&DAT_01addc5c + DAT_0089fbac * 4);
        DAT_0089fbac = DAT_0089fbac + 1;
        DAT_0089fbb4 = DAT_0089fbb4 + 1;
        DAT_0089fba4 = (&ITEM_PTR0)[DAT_0089fbb4];
        if ((float)(&ITEM_P1)[DAT_0089fba4] == f_1) {
          _DAT_0089fbb8 = (float)(&ITEM_P3)[DAT_0089fba4];
          while( true ) {
            in_ST0 = (float10)(float)(&ITEM_P1)[DAT_0089fba4];
            DAT_0089fb90 = DAT_0089fbb4;
            (&ITEM_P1)[DAT_0089fba4] = (float)-in_ST0;
            *(float *)(&ITEM_P9 + DAT_0089fba4 * 4) = _DAT_0089fb94 + _DAT_0089fb9c;
            (&ITEM_P6)[DAT_0089fba4] = DAT_0089fb98;
            DAT_0089fb90 = DAT_0089fb90 + 1;
            DAT_0089fba4 = (&ITEM_PTR0)[DAT_0089fb90];
            if (_DAT_0089fbb8 != (float)(&ITEM_P3)[DAT_0089fba4]) break;
            local_18 = 0;
            DAT_0089fbb4 = DAT_0089fb90;
          }
          _DAT_0089fbb8 = (float)(&ITEM_P3)[DAT_0089fba4];
          DAT_00794830 = DAT_00794830 + 1;
          if (_DAT_0089fb8c != f_0) {
            _DAT_0089fb88 = f_100;
            if ((float)(&ITEM_P4)[DAT_0089fba4] < f_0) {
              in_ST0 = (float10)f_100;
              _DAT_0089fb88 = (float)-in_ST0;
            }
            (&ITEM_P4)[DAT_0089fba4] = _DAT_0089fb88 + (float)(&ITEM_P4)[DAT_0089fba4];
            if (DAT_0089fb84 == 0) {
              if (f_20 <= (float)(&ITEM_P5)[DAT_0089fba4]) {
                (&ITEM_P5)[DAT_0089fba4] = (float)(&ITEM_P5)[DAT_0089fba4] - f_10;
              }
              *(float *)(&ITEM_P8 + DAT_0089fba4 * 4) = f_101;
            }
            else {
              local_10 = 0;
            }
          }
        }
        else if ((float)(&ITEM_P5)[DAT_0089fba4] == f_0) {
          (&ITEM_P5)[DAT_0089fba4] = _DAT_0089fb9c - DAT_0089fb98;
          (&ITEM_P6)[DAT_0089fba4] = _DAT_0089fb94 / f_10;
        }
        else {
          local_c = 0;
        }
        DAT_0089fb80 = DAT_0089fbb4;
        puVar2 = (undefined4 *)&DAT_020b8ea0;
        puVar3 = (undefined4 *)&DAT_020b90a0;
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_004ddb6e(&DAT_0089fb80);
        DAT_00794834 = DAT_0089fb80;
        puVar2 = (undefined4 *)&DAT_020b90a0;
        puVar3 = (undefined4 *)&DAT_020b8ea0;
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        DAT_0089fba0 = DAT_0089fba0 + 1;
      }
      *param_1 = 0;
      ffree(in_ST0);
      return;
    }
    DAT_0089fba4 = (&ITEM_PTR0)[DAT_0089fbb0];
    while( true ) {
      DAT_0089fbac = DAT_0089fbac + 1;
      DAT_0089fbb0 = DAT_0089fbb0 + 1;
      if (f_2 < (float)(&ITEM_P1)[DAT_0089fba4]) break;
      *(undefined4 *)(&DAT_01add7ac + DAT_0089fbac * 4) = (&ITEM_P6)[DAT_0089fba4];
      iVar1 = DAT_0089fbac * 4;
      local_54 = *(uint *)(&ITEM_P9 + DAT_0089fba4 * 4);
      ffree(in_ST0);
      fVar4 = (float10)FUN_005ff874(&local_54,&f_10);
      *(float *)(&DAT_01add2fc + iVar1) = (float)fVar4;
      local_54 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      local_50 = (int)ROUND(*(float *)(&ITEM_P9 + DAT_0089fba4 * 4)) / 10;
      *(float *)(&DAT_01addc5c + DAT_0089fbac * 4) = (float)local_50;
      _DAT_0089fbb8 = (float)(&ITEM_P3)[DAT_0089fba4];
      DAT_0089fba4 = (&ITEM_PTR0)[DAT_0089fbb0];
      in_ST0 = extraout_ST1;
      if (_DAT_0089fbb8 != (float)(&ITEM_P3)[DAT_0089fba4]) goto LAB_004c517b;
      local_24 = 0;
    }
    local_28 = 0;
LAB_004c517b:
    local_20 = 0;
    DAT_0089fba8 = DAT_0089fba8 + 1;
    local_2c = local_2c + -1;
  } while( true );
}


