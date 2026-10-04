// FUN_00534c40 @ 00534c40 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00534c40(int *param_1,float *param_2,int *param_3,int param_4,int param_5,float *param_6)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  float10 in_ST0;
  unkbyte10 extraout_ST0;
  float10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  float10 extraout_ST0_02;
  
  _DAT_0099a7cc = f_0;
  _DAT_0099a7c8 = 0;
  *param_6 = f_0;
  DAT_0099a7c4 = *param_3;
  *param_3 = 0;
  LOAD_I = *param_1 + -1;
  DAT_0099a7c0 = 0;
  DAT_0099a7bc = (int)ROUND(*param_2);
LAB_00534cd1:
  if (LOAD_I < ITEM_I) {
    do {
      LOAD_I = LOAD_I + 1;
      ffree(in_ST0);
      in_ST0 = (float10)load_item_header();
      if (DAT_0099a7c0 == 0) {
        if ((f_200_05 < LOAD_P3) || (LOAD_STAFF < DAT_0099a7bc)) goto LAB_00534cd1;
        in_ST0 = (float10)LOAD_P3;
        if (ABS(in_ST0) <= (float10)f_0_01) {
          if (2 < LOAD_LEN) {
            (&ITEM_P3)[LOAD_W] = f_0;
          }
          LOAD_P3 = f_0;
        }
        if ((((3 < LOAD_CODE) && (LOAD_CODE < 0x11)) && (LOAD_CODE != 0xe)) || (LOAD_P3 < f_0))
        goto LAB_00534cd1;
        if (DAT_0099a7bc != LOAD_STAFF) break;
        if (((LOAD_CODE == 0xe) && (4 < LOAD_LEN)) &&
           ((DAT_0099a7b8 = (int)ROUND((float)(&ITEM_P5)[LOAD_W]), 7 < DAT_0099a7b8 &&
            (DAT_0099a7b8 < 0xb)))) goto LAB_00534cd1;
        if (0x10 < LOAD_CODE) {
          ffree(in_ST0);
          iVar2 = FUN_005358e5(&LOAD_W);
          bVar3 = LOAD_CODE == 0x12;
          ffree(extraout_ST0);
          iVar1 = FUN_00535693(&DAT_0099a7c0);
          in_ST0 = extraout_ST0_00;
          if ((iVar1 != 0 && bVar3 || iVar2 != 0) ||
             ((0xd < LOAD_LEN &&
              ((*(float *)(&ITEM_P14 + LOAD_W * 4) != f_0 ||
               (0xe < LOAD_LEN && *(float *)(&ITEM_P15 + LOAD_W * 4) != f_0)))))) goto LAB_00534cd1;
        }
        DAT_0099a7c0 = LOAD_I;
      }
      else if (DAT_0099a7bc < LOAD_STAFF) {
        *param_1 = LOAD_I;
        goto LAB_0053501f;
      }
      if (ITEM_I <= LOAD_I) {
        LOAD_I = LOAD_I + 1;
        goto LAB_0053501f;
      }
    } while( true );
  }
  goto LAB_00535664;
  while (DAT_0099a7c0 < LOAD_I) {
LAB_0053501f:
    LOAD_I = LOAD_I + -1;
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    if (((0x10 < LOAD_CODE) || (LOAD_CODE < 3)) || (LOAD_CODE == 0xe)) {
      DAT_0099a7b4 = LOAD_I;
      if (ABS(f_200 - LOAD_P3) <= f_0_01) {
        (&ITEM_P3)[LOAD_W] = f_200;
        LOAD_P3 = f_200;
      }
      LOAD_I = DAT_0099a7c0;
      DAT_0099a7c0 = 0;
      _DAT_0099a7b0 = f_m990;
      goto LAB_005350e9;
    }
  }
  goto LAB_00535664;
LAB_005350e9:
  do {
    ffree(in_ST0);
    in_ST0 = (float10)load_item_header();
    if (LOAD_P3 <= f_200_05) {
      if (LOAD_CODE < 3) {
        if ((6 < LOAD_LEN) && (DAT_0099a7ac = *(float *)(&ITEM_P7 + LOAD_W * 4), f_0 < DAT_0099a7ac)
           ) {
          if (f_64 <= DAT_0099a7ac) {
            DAT_0078b4ec = 0;
            if (DAT_0099a7c4 != 0) goto LAB_005353e0;
            DAT_0099a7ac = f_m64;
          }
          if (f_0_1 < ABS(LOAD_P3 - _DAT_0099a7b0)) {
LAB_0053532c:
            if (0 < *param_3) {
              ffree(in_ST0);
              in_ST0 = (float10)FUN_0053572c(&DAT_0099a7c0,&DAT_020b9440,*param_3 * 4 + param_5 + -4
                                            );
            }
            if ((DAT_0099a7ac == f_99) && (DAT_0099a7c0 != 0)) {
              DAT_0099a7c0 = 0;
            }
            *param_3 = *param_3 + 1;
            *(float *)(param_4 + -4 + *param_3 * 4) = LOAD_P3;
            _DAT_0099a7b0 = LOAD_P3;
          }
          DAT_0099a7c0 = DAT_0099a7c0 + 1;
          *(float *)(&DAT_020b943c + DAT_0099a7c0 * 4) = DAT_0099a7ac;
        }
      }
      else if ((((0x10 < LOAD_CODE) || (LOAD_CODE == 0xe)) || (LOAD_CODE == 3)) &&
              (_DAT_0099a7b0 != LOAD_P3)) {
        bVar3 = LOAD_CODE < 0x11;
        ffree(in_ST0);
        iVar2 = FUN_005358e5(&LOAD_W);
        bVar4 = LOAD_CODE != 0x12;
        ffree(extraout_ST0_01);
        iVar1 = FUN_00535693(&DAT_0099a7c0);
        in_ST0 = extraout_ST0_02;
        if ((iVar1 == 0 || bVar4) && (iVar2 == 0 || bVar3)) {
          if (((LOAD_CODE == 0xe) && (0xb < LOAD_LEN)) && (f_0 < *(float *)(&ITEM_P12 + LOAD_W * 4))
             ) {
            LOAD_CODE = 0x8c;
          }
          if (((LOAD_CODE != 3) || (LOAD_LEN < 5)) || ((float)(&ITEM_P5)[LOAD_W] < f_44)) {
            DAT_0099a7ac = (float)-LOAD_CODE;
            goto LAB_0053532c;
          }
        }
      }
    }
LAB_005353e0:
    LOAD_I = LOAD_I + 1;
  } while (LOAD_I <= DAT_0099a7b4);
  ffree(in_ST0);
  in_ST0 = (float10)FUN_0053572c(&DAT_0099a7c0,&DAT_020b9440,*param_3 * 4 + param_5 + -4);
  iVar2 = *param_3;
  DAT_0099a7a8 = 1;
  for (; 0 < iVar2; iVar2 = iVar2 + -1) {
    DAT_0099a7ac = *(float *)(param_5 + -4 + DAT_0099a7a8 * 4);
    if (f_0 < DAT_0099a7ac) {
      _DAT_0099a7cc = DAT_0099a7ac + _DAT_0099a7cc;
      _DAT_0099a7a4 = (int)ROUND(_DAT_0099a7cc);
      _DAT_0099a7a0 = _DAT_0099a7cc - (float)_DAT_0099a7a4;
      _DAT_0099a79c = f_1 - _DAT_0099a7a0;
      if ((_DAT_0099a7a0 != f_0) && (_DAT_0099a7a0 <= f_0_005 || _DAT_0099a79c <= f_0_005)) {
        if (_DAT_0099a7a0 <= f_0_005) {
          _DAT_0099a7cc = _DAT_0099a7cc - _DAT_0099a7a0;
          DAT_0099a7ac = DAT_0099a7ac - _DAT_0099a7a0;
          *(float *)(param_5 + -4 + DAT_0099a7a8 * 4) =
               *(float *)(param_5 + -4 + DAT_0099a7a8 * 4) - _DAT_0099a7a0;
        }
        else if (_DAT_0099a79c <= f_0_005) {
          _DAT_0099a7cc = _DAT_0099a79c + _DAT_0099a7cc;
          DAT_0099a7ac = _DAT_0099a79c + DAT_0099a7ac;
          *(float *)(param_5 + -4 + DAT_0099a7a8 * 4) =
               _DAT_0099a79c + *(float *)(param_5 + -4 + DAT_0099a7a8 * 4);
        }
      }
    }
    if (f_0 < DAT_0099a7ac) {
      *param_6 = DAT_0099a7ac + *param_6;
    }
    DAT_0099a7a8 = DAT_0099a7a8 + 1;
  }
LAB_00535664:
  if (*param_6 == f_0) {
    *param_3 = 0;
  }
  LOAD_P3 = *param_6;
  ffree(in_ST0);
  return;
}


