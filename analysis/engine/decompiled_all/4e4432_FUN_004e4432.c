// FUN_004e4432 @ 004e4432 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e4432(int *param_1)

{
  int iVar1;
  float10 fVar2;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffffffc;
  DAT_008d08d4 = DAT_0078de16 - 0x40;
  if (DAT_0078de17 == ' ') {
    DAT_01b12c90 = *(int *)(DAT_008d08d4 * 4 + 0x794950);
  }
  else if (DAT_0078de17 == '#') {
    DAT_01b12c90 = *(int *)(DAT_008d08d4 * 4 + 0x794934);
  }
  else {
    DAT_01b12c90 = *(int *)(s_MOPRSTXZ__Q__0079490d + DAT_008d08d4 * 4 + 0xb);
  }
  if ((DAT_01b12c90 != 0) && (*param_1 != 999)) {
    _DAT_008d08d0 = (float)*param_1;
    DAT_008d08cc = 1;
    for (iVar1 = DAT_01e66d04; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&ITEM_LEN)[DAT_01b12c80] = f_6;
      DAT_01b12c80 = DAT_01b12c80 + 1;
      (&ITEM_LEN)[DAT_01b12c80] = f_17;
      DAT_01b12c80 = DAT_01b12c80 + 1;
      (&ITEM_LEN)[DAT_01b12c80] = (float)(&DAT_01e66d04)[DAT_008d08cc];
      DAT_01b12c80 = DAT_01b12c80 + 1;
      (&ITEM_LEN)[DAT_01b12c80] = _DAT_008d08d0 - DAT_0078de0c * f_2_5;
      DAT_01b12c80 = DAT_01b12c80 + 1;
      (&ITEM_LEN)[DAT_01b12c80] = i_0;
      DAT_01b12c80 = DAT_01b12c80 + 1;
      (&ITEM_LEN)[DAT_01b12c80] = (float)DAT_01b12c90;
      DAT_01b12c80 = DAT_01b12c80 + 1;
      (&ITEM_LEN)[DAT_01b12c80] = (float)*(int *)(&DAT_01e67504 + (&DAT_01e66d04)[DAT_008d08cc] * 4)
      ;
      DAT_01b12c80 = DAT_01b12c80 + 1;
      DAT_008d08cc = DAT_008d08cc + 1;
    }
    DAT_008d08c8 = DAT_01b12c90 % 100;
    iVar1 = DAT_008d08c8;
    if (DAT_008d08c8 < 0) {
      iVar1 = -DAT_008d08c8;
    }
    _DAT_008d08c4 = ((float)iVar1 - f_1) * f_2_8 + f_3 + f_1;
    fVar2 = (float10)anint(&stack0xfffffffc,0x4e46a3);
    *(int *)(puVar3 + -0x2c) = (int)ROUND(fVar2);
    **(undefined4 **)(puVar3 + 8) = *(undefined4 *)(puVar3 + -0x2c);
  }
  return;
}


