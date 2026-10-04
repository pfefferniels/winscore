// FUN_00524678 @ 00524678 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524678(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 in_ST0;
  unkbyte10 Var4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  LOAD_I = 1;
  for (iVar2 = ITEM_I; 0 < iVar2; iVar2 = iVar2 + -1) {
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    if ((((LOAD_STAFF < (int)ROUND(DAT_01fb8c60)) && (LOAD_CODE == 0xe)) && (f_25 <= LOAD_P3)) &&
       (in_ST0 = (float10)LOAD_STAFF + (float10)(float)(&ITEM_P4)[LOAD_W],
       (float10)(int)ROUND(DAT_01fb8c60) < in_ST0)) goto LAB_00524c41;
    LOAD_I = LOAD_I + 1;
  }
  DAT_0094e6b8 = 1;
  for (iVar2 = DAT_01fb8c80; 0 < iVar2; iVar2 = iVar2 + -1) {
    if ((f_25 < LOAD_P3) && ((float)(&DAT_01f95d44)[DAT_0094e6b8 * 0xf] == f_14)) goto LAB_00524c41;
    DAT_0094e6b8 = DAT_0094e6b8 + 1;
  }
  FUN_005f33c9(&stack0xfffffffc,0x52480a);
  Var4 = FUN_005f34d1(puVar5,0x524825);
  ffree(Var4);
  DAT_0094e6b4 = thunk_FUN_00595cd0(&DAT_020b8ea0);
  in_ST0 = extraout_ST0;
  if (DAT_0094e6b4 == 0) {
    *(undefined4 *)(puVar5 + -0x2c) = 0;
  }
  else if (DAT_0094e6b4 == -2) {
    DAT_020b8ea0._0_1_ = DAT_00767d48;
    DAT_020b90a0 = DAT_00767d48;
    *(undefined4 *)(puVar5 + -0x24) = 0;
  }
  else {
    *(undefined4 *)(puVar5 + -0x28) = 0;
    ffree(extraout_ST0);
    DAT_0094e6b0 = thunk_FUN_0059d310(&DAT_00796d1c);
    iVar2 = DAT_01fb8c80;
    if (DAT_0094e6b0 == 1) {
      _DAT_01a1fe0c = (float)_DAT_00796d24;
      _DAT_01a1fe04 = (float)_DAT_00796d1c;
      _DAT_01a1fe08 = (float)_DAT_00796d20;
      _DAT_0094e6ac = f_0;
      _DAT_0094e6a8 = (_DAT_01a1fe04 * f_4) / _DAT_01a1fe08;
      DAT_0094e6a4 = DAT_01fb8c80;
      DAT_01fb8c60 = DAT_01f95d84;
      *(int *)(puVar5 + -0x1c) = DAT_01fb8c80;
      DAT_0094e6b8 = 1;
      while (0 < iVar2) {
        if (((f_2 < (float)(&DAT_01f95d44)[DAT_0094e6b8 * 0xf]) ||
            (f_60 < *(float *)(&DAT_01f95d5c + DAT_0094e6b8 * 0x3c))) ||
           ((float)(&DAT_01f95d4c)[DAT_0094e6b8 * 0xf] == (float)(&DAT_01f95d88)[DAT_0094e6b8 * 0xf]
           )) {
          *(undefined4 *)(puVar5 + -0x18) = 0;
        }
        else if (_DAT_01a1fe0c == f_0) {
          *(undefined4 *)(puVar5 + -0x14) = 0;
          DAT_0094e6a0 = DAT_0094e6a0 + 1;
          _DAT_0094e6ac = _DAT_0094e6ac + *(float *)(&DAT_01f95d5c + DAT_0094e6b8 * 0x3c);
          if (_DAT_0094e6a8 <= _DAT_0094e6ac) {
            DAT_0094e6a4 = DAT_0094e6a4 + 1;
            (&DAT_01f95d44)[DAT_0094e6a4 * 0xf] = f_14;
            (&DAT_01f95d48)[DAT_0094e6a4 * 0xf] = DAT_01fb8c60;
            DAT_0094e69c = ((float)(&DAT_01f95d88)[DAT_0094e6b8 * 0xf] -
                           (float)(&DAT_01f95d4c)[DAT_0094e6b8 * 0xf]) / f_2 +
                           (float)(&DAT_01f95d4c)[DAT_0094e6b8 * 0xf];
            if (DAT_01fb8c80 == DAT_0094e6b8) {
              DAT_0094e69c = DAT_01fbb8b8;
            }
            (&DAT_01f95d4c)[DAT_0094e6a4 * 0xf] = DAT_0094e69c;
            (&DAT_01f95d50)[DAT_0094e6a4 * 0xf] = (float)_DAT_00796d28;
            iVar2 = DAT_0094e6a4;
            iVar3 = 5;
            for (iVar1 = 1; iVar1 < 0xc; iVar1 = iVar1 + 1) {
              (&DAT_01f95d40)[iVar3 + iVar2 * 0xf] = f_0;
              iVar3 = iVar3 + 1;
            }
            _DAT_0094e6ac = f_0;
          }
          else {
            *(undefined4 *)(puVar5 + -8) = 0;
          }
        }
        else {
          _DAT_01a1fe0c = _DAT_01a1fe0c - f_1;
          if (_DAT_01a1fe0c == f_0) {
            DAT_0094e6a4 = DAT_0094e6a4 + 1;
            (&DAT_01f95d44)[DAT_0094e6a4 * 0xf] = f_14;
            (&DAT_01f95d48)[DAT_0094e6a4 * 0xf] = DAT_01fb8c60;
            (&DAT_01f95d4c)[DAT_0094e6a4 * 0xf] =
                 ((float)(&DAT_01f95d88)[DAT_0094e6b8 * 0xf] -
                 (float)(&DAT_01f95d4c)[DAT_0094e6b8 * 0xf]) / f_2 +
                 (float)(&DAT_01f95d4c)[DAT_0094e6b8 * 0xf];
            (&DAT_01f95d50)[DAT_0094e6a4 * 0xf] = (float)_DAT_00796d28;
            iVar2 = DAT_0094e6a4;
            iVar1 = 5;
            for (iVar3 = 1; iVar3 < 0xc; iVar3 = iVar3 + 1) {
              (&DAT_01f95d40)[iVar1 + iVar2 * 0xf] = f_0;
              iVar1 = iVar1 + 1;
            }
            *(undefined4 *)(puVar5 + -0xc) = 0;
          }
          else {
            *(undefined4 *)(puVar5 + -0x10) = 0;
          }
        }
        *(undefined4 *)(puVar5 + -4) = 0;
        DAT_0094e6b8 = DAT_0094e6b8 + 1;
        *(int *)(puVar5 + -0x1c) = *(int *)(puVar5 + -0x1c) + -1;
        iVar2 = *(int *)(puVar5 + -0x1c);
      }
      ffree(extraout_ST0_00);
      DAT_01fb8c80 = DAT_0094e6a4;
      Var4 = input_store_items();
      ffree(Var4);
      Var4 = draw_items();
      ffree(Var4);
      in_ST0 = (float10)thunk_FUN_00549422();
    }
    else {
      *(undefined4 *)(puVar5 + -0x20) = 0;
      in_ST0 = extraout_ST0_00;
    }
  }
LAB_00524c41:
  ffree(in_ST0);
  return;
}


