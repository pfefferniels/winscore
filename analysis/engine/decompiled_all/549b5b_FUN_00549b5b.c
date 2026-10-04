// FUN_00549b5b @ 00549b5b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00549b5b(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  unkbyte10 Var4;
  float10 fVar5;
  uint local_3c;
  int local_38;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_0205274c == 0) {
    DAT_009a20a4 = (&ITEM_PTR0)[EDIT_ITEM];
    local_3c = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    local_38 = (int)ROUND((float)(&ITEM_LEN)[DAT_009a20a4]);
    DAT_009a20a0 = local_38;
    if ((float)(&ITEM_P1)[DAT_009a20a4] == f_0) {
      (&ITEM_P1)[DAT_009a20a4] = f_3;
    }
    if ((float)(&ITEM_P1)[DAT_009a20a4] == f_16) {
      local_3c = DAT_009a20a0 + 1;
      ffree(in_ST0);
      in_ST0 = (float10)FUN_0054c590(&ITEM_LEN + DAT_009a20a4,&ITEM_LEN + (&DAT_02091d20)[ITEM_I],
                                     &local_3c);
      (&ITEM_P1)[(&DAT_02091d20)[ITEM_I] + DAT_009a20a0] = f_0;
      DAT_009a20a0 = 0xd;
      if (*(float *)(&ITEM_P14 + DAT_009a20a4 * 4) == f_m1) {
        DAT_009a20a0 = 0x10;
      }
    }
    iVar1 = 0x33 - DAT_009a20a0;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    iVar3 = DAT_009a20a0;
    for (iVar2 = 1; iVar2 <= iVar1; iVar2 = iVar2 + 1) {
      *(float *)(&DAT_020b943c + iVar3 * 4) = f_0;
      iVar3 = iVar3 + 1;
    }
    ffree(in_ST0);
    Var4 = FUN_0054c590(&ITEM_P1 + DAT_009a20a4,&DAT_020b9440,&DAT_009a20a0);
    ffree(Var4);
    in_ST0 = (float10)FUN_0054c590(&DAT_020b9440,&P1,&DAT_007692b8);
    DAT_009a209c = (&DAT_02035a00)[ITEM_I];
    VEC_N = DAT_009a209c;
    *DAT_01fbb844 = (&DAT_020a55a0)[ITEM_I] + -1;
    DAT_009a2098 = *DAT_01fbb844;
  }
  else {
    VEC_N = DAT_009a209c;
    *DAT_01fbb844 = DAT_009a2098;
  }
  NPT = 1;
  COLOR = 0xff;
  if ((P1 == f_16) && (P14 == f_m1)) {
    P26 = P16;
  }
  if (P26 != f_0) {
    if (P26 <= f_1) {
      if (P26 == f_1) {
        P26 = f_0_92;
      }
      in_ST0 = (float10)P26 * (float10)f_10000 + (float10)P26 * (float10)f_100;
      P26 = (float)((float10)P26 * (float10)f_1000000 + in_ST0);
    }
    DAT_009a2094 = (undefined *)(int)ROUND(P26);
    local_3c = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    local_38 = (int)ROUND((float)((int)DAT_009a2094 % 100) * f_2_56);
    COLOR = (int)CONCAT12((char)local_38,
                          CONCAT11((char)(int)ROUND((float)(((int)DAT_009a2094 % 10000) / 100) *
                                                    f_2_56),
                                   (char)(int)ROUND((float)((int)DAT_009a2094 / 10000) * f_2_56)));
  }
  ffree(in_ST0);
  Var4 = draw_item();
  ffree(Var4);
  fVar5 = (float10)emit_points();
  (&DAT_02035a04)[ITEM_I] = VEC_N;
  *DAT_01fbb7c0 = VEC_N + -1;
  (&DAT_020a55a4)[ITEM_I] = *DAT_01fbb844 + 1;
  if ((P26 != f_0) || (-1 < DAT_01fbb6f8)) {
    DAT_009a20a4 = *DAT_01fbb7c0 + 1;
    DAT_009a2094 = (undefined *)(int)ROUND(DAT_020b9444);
    local_3c = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_009a20a0 = (int)ROUND(DAT_020b9440);
    _DAT_009a2090 = DAT_020b944c;
    if (DAT_020b9440 == f_8) {
      _DAT_009a2090 = f_4;
    }
    if (((0x10 < DAT_009a20a0) || (DAT_009a20a0 == 2)) || (DAT_009a20a0 == 3)) {
      _DAT_009a2090 = _DAT_009a2090 + f_4;
    }
    if ((DAT_009a20a0 < 4) || (DAT_009a20a0 == 6)) {
      ffree(fVar5);
      local_38 = DAT_009a20a0;
      fVar5 = (float10)amod(&DAT_009a2090,&f_100);
      _DAT_009a2090 = (float)fVar5;
    }
    fVar5 = (float10)(int)(&STAFF_Y0)[(int)DAT_009a2094] +
            (float10)_DAT_009a2090 * (float10)f_7 *
            (float10)(float)(&STAFF_STEP0)[(int)DAT_009a2094];
    DAT_009a208c = (int)ROUND(fVar5 - (float10)VIEW_DY);
    local_38 = (int)ROUND(DAT_020b9448 * f_150);
    DAT_009a2088 = local_38;
    if (200 < (int)DAT_009a2094) {
      DAT_009a2088 = local_38 + 0x8502;
    }
    DAT_009a2094 = &DAT_020000ff;
    local_10 = 4;
    DAT_009a20a0 = 1;
    do {
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_009a20a4 * VEC_STRIDE) =
           *(int *)(DAT_009a20a0 * 4 + 0x79d6c8) + DAT_009a2088 + VIEW_DX;
      *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_009a20a4 + 1) * VEC_STRIDE) =
           *(int *)(DAT_009a20a0 * 4 + 0x79d6b8) + DAT_009a208c;
      *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_009a20a4 + 2) * VEC_STRIDE) =
           DAT_009a2094;
      DAT_009a2094 = (undefined *)0xff;
      DAT_009a20a4 = DAT_009a20a4 + 3;
      DAT_009a20a0 = DAT_009a20a0 + 1;
      local_10 = local_10 + -1;
    } while (0 < local_10);
    if (DAT_01fbb760 == 2) {
      DAT_009a2094 = &DAT_010000ff;
      _DAT_009a2084 = DAT_020527e4;
      if ((EDIT_ITEM != 0) && (f_200 < (float)(&ITEM_P2)[(&ITEM_PTR0)[EDIT_ITEM]])) {
        _DAT_009a2084 = DAT_020527e4 + f_227;
      }
      fVar5 = (float10)_DAT_009a2084 * (float10)f_150;
      local_38 = (int)ROUND((float10)VIEW_DX + fVar5);
      DAT_009a208c = DAT_02052c28 - VIEW_DY;
      DAT_009a2088 = local_38;
      while( true ) {
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_009a20a4 * VEC_STRIDE) = DAT_009a2088;
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_009a20a4 + 1) * VEC_STRIDE) =
             DAT_009a208c;
        *(undefined **)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_009a20a4 + 2) * VEC_STRIDE) =
             DAT_009a2094;
        DAT_009a20a4 = DAT_009a20a4 + 3;
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + DAT_009a20a4 * VEC_STRIDE) = DAT_009a2088;
        *(int *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_009a20a4 + 1) * VEC_STRIDE) =
             DAT_009a208c + 300;
        *(undefined4 *)((VEC_BASE - VEC_STRIDE * VEC_LBOUND) + (DAT_009a20a4 + 2) * VEC_STRIDE) =
             0xff;
        DAT_009a208c = DAT_009a208c + 600;
        DAT_009a20a4 = DAT_009a20a4 + 3;
        if (17999 < DAT_009a208c) break;
        local_8 = 0;
      }
    }
    else {
      local_c = 0;
    }
    local_3c = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    *DAT_01fbb7c0 = DAT_009a20a4 + -1;
    if ((DAT_0205274c == 0) && (P1 == f_16)) {
      ffree(fVar5);
      fVar5 = (float10)FUN_00549422();
    }
    DAT_00791474 = *DAT_01fbb7c0;
  }
  ffree(fVar5);
  return;
}


