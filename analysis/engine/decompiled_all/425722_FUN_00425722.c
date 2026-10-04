// FUN_00425722 @ 00425722 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00425722(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  unkbyte10 in_ST0;
  unkbyte10 Var6;
  
  _DAT_007d2f10 = 1;
  _DAT_007d2f0c = 0;
  ffree(in_ST0);
  Var6 = thunk_FUN_004c2458(&DAT_01e62c84,1,&DAT_007d2f08,&DAT_007d2f10);
  if (DAT_007d2f08 != 0) {
    ffree(Var6);
    Var6 = thunk_FUN_004c2458(&DAT_01e62c84,1,&DAT_007d2f04,&DAT_007d2f10);
  }
  DAT_007d2f00 = DAT_00794830 - DAT_007d2f08;
  DAT_007d2efc = DAT_00794830 + -1;
  if (DAT_007d2f00 < 1) {
    ffree(Var6);
    Var6 = thunk_FUN_0054d831(&DAT_0075faa0,0x1d);
    DAT_0079483c = f_99;
  }
  else {
    DAT_007d2ef8 = DAT_00794834 + 1;
    DAT_007d2ef0 = 1;
    DAT_007d2ef4 = DAT_00794830;
    iVar3 = DAT_007d2f04;
    while (iVar3 = iVar3 + -1, 0 < iVar3) {
      DAT_007d2eec = DAT_007d2f00;
      for (iVar4 = (DAT_007d2efc - DAT_007d2f00) + 1; 0 < iVar4; iVar4 = iVar4 + -1) {
        DAT_007d2ef4 = DAT_007d2ef4 + 1;
        DAT_007d2ee8 = *(int *)(&DAT_007cbbac + DAT_007d2eec * 4);
        DAT_007d2f2c = (&ITEM_PTR0)[DAT_007d2ee8];
        _DAT_007d2ee4 = (&ITEM_P3)[DAT_007d2f2c];
        while (DAT_007d2ee0 = (&ITEM_PTR0)[DAT_007d2ef8], f_2 < (float)(&ITEM_P1)[DAT_007d2ee0]) {
          DAT_007d2ef8 = DAT_007d2ef8 + 1;
        }
        *(int *)(&DAT_007cbbac + DAT_00794830 * 4) = DAT_007d2ef8;
        _DAT_007d2edc = (float)(&ITEM_P3)[DAT_007d2ee0];
        DAT_007d2ed8 = (int)ROUND((float)(&ITEM_P1)[DAT_007d2f2c]);
        DAT_007d2ed4 = (int)ROUND((float)(&ITEM_P1)[DAT_007d2ee0]);
        if (DAT_007d2ed4 == DAT_007d2ed8) {
          if (DAT_007d2ed8 == 2) {
            (&ITEM_P5)[DAT_007d2ee0] = (&ITEM_P5)[DAT_007d2f2c];
          }
          (&ITEM_P6)[DAT_007d2ee0] = (&ITEM_P6)[DAT_007d2f2c];
          if (DAT_007d2ed8 == 1) {
            *(undefined4 *)(&ITEM_P9 + DAT_007d2ee0 * 4) =
                 *(undefined4 *)(&ITEM_P9 + DAT_007d2f2c * 4);
          }
        }
        else if (DAT_007d2ed4 == 2) {
          if (f_0 < (float)(&ITEM_P6)[DAT_007d2f2c]) {
            (&ITEM_P5)[DAT_007d2ee0] = -(float)(&ITEM_P6)[DAT_007d2f2c];
          }
          if (*(float *)(&ITEM_P9 + DAT_007d2f2c * 4) != f_0) {
            DAT_007d2ed0 = (int)ROUND(*(float *)(&ITEM_P9 + DAT_007d2f2c * 4));
            (&ITEM_P6)[DAT_007d2ee0] = (float)(DAT_007d2ed0 / 10);
            if ((float)(&ITEM_P6)[DAT_007d2f2c] == f_0) {
              (&ITEM_P5)[DAT_007d2ee0] = (float)(DAT_007d2ed0 % 10);
            }
          }
        }
        else {
          if ((float)(&ITEM_P5)[DAT_007d2f2c] < f_0) {
            (&ITEM_P6)[DAT_007d2ee0] = -(float)(&ITEM_P5)[DAT_007d2f2c];
          }
          if (f_0 < (float)(&ITEM_P5)[DAT_007d2f2c]) {
            *(undefined4 *)(&ITEM_P9 + DAT_007d2ee0 * 4) = (&ITEM_P5)[DAT_007d2f2c];
          }
          if ((float)(&ITEM_P6)[DAT_007d2f2c] != f_0) {
            *(float *)(&ITEM_P9 + DAT_007d2ee0 * 4) =
                 (float)(&ITEM_P6)[DAT_007d2f2c] * f_10 + *(float *)(&ITEM_P9 + DAT_007d2ee0 * 4);
          }
        }
        while( true ) {
          fVar1 = (float)(&ITEM_P1)[DAT_007d2ee0];
          (&ITEM_P1)[DAT_007d2ee0] = (float)-(float10)fVar1;
          ffree((float10)fVar1);
          Var6 = thunk_FUN_004ddb6e(&DAT_007d2ef8);
          DAT_007d2ef8 = DAT_007d2ef8 + 1;
          _DAT_007d2ec8 = DAT_007d2ee0;
          iVar2 = (&ITEM_PTR0)[DAT_007d2ef8];
          if (_DAT_007d2edc != (float)(&ITEM_P3)[iVar2]) break;
          DAT_007d2ee8 = DAT_007d2ee8 + 1;
          DAT_007d2f2c = (&ITEM_PTR0)[DAT_007d2ee8];
          iVar5 = 5;
          DAT_007d2ecc = 5;
          DAT_007d2ee0 = iVar2;
          do {
            if ((float)(&ITEM_P1)[DAT_007d2ee0] != (float)(&ITEM_P1)[DAT_007d2f2c]) {
              ffree(Var6);
              Var6 = thunk_FUN_0054d831("Note/Rest mismatch.",0x13);
            }
            (&ITEM_P1)[DAT_007d2ee0] = (&ITEM_P1)[DAT_007d2f2c];
            (&ITEM_LEN)[DAT_007d2ecc + DAT_007d2ee0] = (&ITEM_LEN)[DAT_007d2ecc + DAT_007d2f2c];
            DAT_007d2ecc = DAT_007d2ecc + 1;
            iVar5 = iVar5 + -1;
          } while (0 < iVar5);
        }
        DAT_00794830 = DAT_00794830 + 1;
        DAT_007d2eec = DAT_007d2eec + 1;
        DAT_007d2ee0 = iVar2;
      }
      DAT_007d2ef0 = DAT_007d2ef0 + 1;
    }
    DAT_00794834 = DAT_007d2ef8 + -1;
    Var6 = FUN_005f34d1(&stack0xfffffffc,0x425d92);
    DAT_00794830 = DAT_00794830 + -1;
  }
  ffree(Var6);
  return;
}


