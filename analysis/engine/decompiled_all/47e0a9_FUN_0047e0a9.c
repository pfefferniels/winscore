// FUN_0047e0a9 @ 0047e0a9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0047e0a9(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  float10 in_ST0;
  float10 fVar3;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  
  DAT_01ba0c34 = *param_1;
  iVar1 = *param_2;
  DAT_01ba0c30 = 1;
  while ((0 < iVar1 && ((float)(&DAT_01f95d44)[DAT_01ba0c34 * 0xf] != f_0))) {
    DAT_01ba0c38 = (&ITEM_PTR0)[*(int *)(param_3 + -4 + DAT_01ba0c30 * 4)];
    if ((float)(&ITEM_P3)[DAT_01ba0c38] == (float)(&DAT_01f95d88)[DAT_01ba0c34 * 0xf]) {
      DAT_01ba0c34 = DAT_01ba0c34 + 1;
      (&ITEM_P5)[DAT_01ba0c38] = (&DAT_01f95d54)[DAT_01ba0c34 * 0xf];
      DAT_01ba0c44 = (float)(&DAT_01f95d50)[DAT_01ba0c34 * 0xf];
      DAT_01ba0c3c = (int)ROUND((float)(&ITEM_P1)[DAT_01ba0c38]);
      if (((DAT_01ba0c3c == 1) && (f_8 <= (float)(&ITEM_LEN)[DAT_01ba0c38])) &&
         (in_ST0 = (float10)(float)(&ITEM_P4)[DAT_01ba0c38], (float10)f_100 <= ABS(in_ST0))) {
        ffree(in_ST0);
        fVar3 = (float10)amod(&ITEM_P8 + DAT_01ba0c38 * 4,&f_100);
        DAT_01ba0c40 = (float)fVar3;
        *(float *)(&ITEM_P8 + DAT_01ba0c38 * 4) = DAT_01ba0c40 * f_1_6666 + f_101;
        DAT_01ba0c40 = f_100;
        in_ST0 = extraout_ST1;
        if (DAT_01ba0c44 < f_0) {
          in_ST0 = (float10)f_100;
          DAT_01ba0c40 = (float)-in_ST0;
        }
        DAT_01ba0c44 = DAT_01ba0c40 + DAT_01ba0c44;
      }
      (&ITEM_P4)[DAT_01ba0c38] = DAT_01ba0c44;
      if (DAT_01ba0c3c != 1) {
        DAT_01ba0c40 = *(float *)(&DAT_01f95d5c + DAT_01ba0c34 * 0x3c);
        if (DAT_01ba0c3c == 6) {
          DAT_01ba0c3c = (int)ROUND(DAT_01ba0c40 / f_10);
          iVar2 = DAT_01ba0c3c * 10;
          ffree(in_ST0);
          fVar3 = (float10)amod(&ITEM_P7 + DAT_01ba0c38 * 4,&f_10);
          DAT_01ba0c40 = (float)(fVar3 + (float10)iVar2);
          in_ST0 = extraout_ST1_00;
        }
        else if (DAT_01ba0c3c == 5) {
          iVar2 = 5;
          DAT_01ba0c3c = 4;
          do {
            *(undefined4 *)(&P0 + DAT_01ba0c3c * 4) =
                 (&DAT_01f95d40)[DAT_01ba0c34 * 0xf + DAT_01ba0c3c];
            DAT_01ba0c3c = DAT_01ba0c3c + 1;
            iVar2 = iVar2 + -1;
          } while (0 < iVar2);
          P3 = (float)(&ITEM_P3)[DAT_01ba0c38];
          P6 = (float)(&ITEM_P6)[DAT_01ba0c38];
          ffree(in_ST0);
          in_ST0 = (float10)thunk_FUN_0042c51c();
          DAT_01ba0c40 = P7;
        }
        *(float *)(&ITEM_P7 + DAT_01ba0c38 * 4) = DAT_01ba0c40;
      }
    }
    DAT_01ba0c30 = DAT_01ba0c30 + 1;
    iVar1 = iVar1 + -1;
  }
  ffree(in_ST0);
  return;
}


