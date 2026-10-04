// FUN_004346b3 @ 004346b3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004346b3(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 in_FPUControlWord;
  float10 fVar5;
  unkbyte10 Var6;
  float10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  
  puVar4 = &stack0xfffffffc;
  DAT_007f7554 = (int)ROUND(DAT_020b9444);
  DAT_007f7550 = (int)ROUND(DAT_020b9448);
  if (200 < DAT_007f7554) {
    DAT_007f7550 = (int)ROUND((float)DAT_007f7550 + f_227);
  }
  DAT_007f7550 = DAT_007f7550 * 0x96;
  _DAT_007f754c = (float)(&STAFF_STEP0)[LOAD_STAFF] * f_7;
  fVar5 = (float10)_DAT_007f754c * (float10)DAT_020b944c;
  _DAT_007f7548 = (int)ROUND((float10)(int)(&STAFF_Y0)[DAT_007f7554] + fVar5);
  DAT_007f7544 = 99999;
  DAT_007f7540 = 0;
  LOAD_I = 1;
  for (iVar3 = ITEM_I; 0 < iVar3; iVar3 = iVar3 + -1) {
    ffree(fVar5);
    fVar5 = (float10)load_item_header();
    if (LOAD_CODE == 0x10) {
      _DAT_007f753c = (float)(&ITEM_P4)[LOAD_W];
      if (200 < LOAD_STAFF) {
        LOAD_P3 = LOAD_P3 + f_227;
      }
      LOAD_P3 = LOAD_P3 + *(float *)(&ITEM_P11 + LOAD_W * 4);
      fVar2 = (float)(&STAFF_STEP0)[LOAD_STAFF];
      iVar1 = (&STAFF_Y0)[LOAD_STAFF];
      *(undefined2 *)(puVar4 + -0x3c) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0x3a) = (ushort)*(undefined4 *)(puVar4 + -0x3c) | 0xc00;
      *(int *)(puVar4 + -0x38) = (int)ROUND((float)iVar1 + _DAT_007f753c * f_7 * fVar2);
      DAT_007f7538 = *(int *)(puVar4 + -0x38);
      DAT_007f7534 = DAT_007f7538 - _DAT_007f7548;
      fVar5 = (float10)LOAD_P3 * (float10)f_150;
      *(undefined2 *)(puVar4 + -0x3c) = *(undefined2 *)(puVar4 + -0x3c);
      *(ushort *)(puVar4 + -0x3a) = (ushort)*(undefined4 *)(puVar4 + -0x3c) | 0xc00;
      *(int *)(puVar4 + -0x38) = (int)ROUND(fVar5 - (float10)DAT_007f7550);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0x3c);
      DAT_007f7530 = *(int *)(puVar4 + -0x38);
      *(int *)(puVar4 + -0x38) = DAT_007f7530 * DAT_007f7530 + DAT_007f7534 * DAT_007f7534;
      _DAT_007f752c = (float)*(int *)(puVar4 + -0x38);
      if (f_0 <= _DAT_007f752c) {
        ffree(fVar5);
        fVar5 = (float10)FUN_005ff146(puVar4,0x434938);
        _DAT_007f752c = (float)fVar5;
        *(undefined2 *)(puVar4 + -0x3c) = in_FPUControlWord;
        *(ushort *)(puVar4 + -0x3a) = (ushort)*(undefined4 *)(puVar4 + -0x3c) | 0xc00;
        *(int *)(puVar4 + -0x38) = (int)ROUND(_DAT_007f752c);
        in_FPUControlWord = *(undefined2 *)(puVar4 + -0x3c);
        DAT_007f7528 = *(int *)(puVar4 + -0x38);
        fVar5 = extraout_ST1;
        if (DAT_007f7528 <= DAT_007f7544) {
          DAT_007f7540 = LOAD_I;
          DAT_007f7544 = DAT_007f7528;
        }
      }
      else {
        *(undefined4 *)(puVar4 + -0x10) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar4 + -0x14) = 0;
    }
    *(undefined4 *)(puVar4 + -0xc) = 0;
    LOAD_I = LOAD_I + 1;
  }
  if (DAT_007f7540 == 0) {
    ffree(fVar5);
    Var6 = thunk_FUN_0054d831(&DAT_007601ac,0x17);
    DAT_0078b4e0 = 9999;
    *(undefined4 *)(puVar4 + -4) = 0;
  }
  else {
    *(undefined4 *)(puVar4 + -8) = 0;
    DAT_007f7524 = (&ITEM_PTR0)[DAT_007f7540];
    DAT_01c58924 = (&ITEM_P2)[DAT_007f7524];
    DAT_01c58928 = (float)(&ITEM_P13)[DAT_007f7524] / f_2 + (float)(&ITEM_P3)[DAT_007f7524] +
                   *(float *)(&ITEM_P11 + DAT_007f7524 * 4);
    *(undefined4 *)(puVar4 + -0x40) = (&ITEM_P6)[DAT_007f7524];
    ffree(fVar5);
    fVar5 = (float10)FUN_005ff874(puVar4 + -0x40,&DAT_007601d0);
    _DAT_007f7520 = (float)fVar5;
    if (_DAT_007f7520 == f_0) {
      _DAT_007f7520 = f_1;
    }
    if (*(float *)(&ITEM_P7 + DAT_007f7524 * 4) != f_0) {
      _DAT_007f7520 = *(float *)(&ITEM_P7 + DAT_007f7524 * 4);
    }
    DAT_01c5892c = _DAT_007f7520 * f_1_51 + (float)(&ITEM_P4)[DAT_007f7524];
    fVar2 = (float)(&ITEM_P2)[DAT_007f7524];
    *(undefined2 *)(puVar4 + -0x3c) = in_FPUControlWord;
    *(ushort *)(puVar4 + -0x3a) = (ushort)*(undefined4 *)(puVar4 + -0x3c) | 0xc00;
    *(int *)(puVar4 + -0x38) = (int)ROUND(fVar2);
    _DAT_007f751c = (float)(&STAFF_STEP0)[*(int *)(puVar4 + -0x38)] / f_25;
    DAT_01c58934 = (((float)(&ITEM_P13)[DAT_007f7524] + f_2) * f_0_8571) / _DAT_007f751c;
    _DAT_01c58938 = _DAT_007f7520 * f_3_1 + f_2;
    Var6 = extraout_ST1_00;
  }
  ffree(Var6);
  return;
}


