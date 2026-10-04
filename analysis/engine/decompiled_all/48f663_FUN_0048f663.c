// FUN_0048f663 @ 0048f663 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f663(void)

{
  undefined1 *puVar1;
  int iVar2;
  float10 fVar3;
  
  puVar1 = &stack0xfffffffc;
  DAT_01be6d74 = (&DAT_02035a00)[ITEM_I];
  DAT_01be6d70 = (&DAT_020a55a0)[ITEM_I] + -1;
  _DAT_00829858 = (float)(&STAFF_STEP0)[(int)ROUND(DAT_020b9444)] * f_7;
  P4 = DAT_020b944c;
  if ((DAT_009bb1cc == 0) && (DAT_00829854 = 1, (short)DAT_009ae2bc == 0x737e)) {
    DAT_00829854 = 2;
  }
  if (DAT_00829854 != 1) {
    DAT_00829850 = DAT_01a14950;
    DAT_0082984c = DAT_01a1494c;
    if (DAT_00829854 == 2) {
      if (DAT_009bb1cc == 0) {
        _DAT_00829844 = DAT_01a1494c;
        _DAT_00829848 = DAT_01a14950;
        DAT_009bb1cc = 1;
        return;
      }
      if (DAT_009bb1cc == 1) {
        _DAT_00829848 = DAT_01a14950 - _DAT_00829848;
        if (_DAT_00829848 < 0) {
          _DAT_00829848 = -_DAT_00829848;
        }
        _DAT_00829844 = DAT_01a1494c - _DAT_00829844;
        if (_DAT_00829844 < 0) {
          _DAT_00829844 = -_DAT_00829844;
        }
        if (_DAT_00829848 < _DAT_00829844) {
          DAT_00829854 = 3;
        }
        _DAT_00829848 = DAT_01a14950;
        _DAT_00829844 = DAT_01a1494c;
        DAT_009bb1cc = 2;
        goto LAB_0048f854;
      }
    }
    if (DAT_00829854 == 2) {
      iVar2 = DAT_01a14950 - _DAT_00829848;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
    }
    else {
      iVar2 = DAT_01a1494c - _DAT_00829844;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
    }
    if (iVar2 < 0x32) {
      return;
    }
    _DAT_00829848 = DAT_01a14950;
    _DAT_00829844 = DAT_01a1494c;
  }
LAB_0048f854:
  _DAT_00829840 = VIEW_DX;
  _DAT_0082983c = (&STAFF_Y0)[(int)ROUND(DAT_020b9444)] - VIEW_DY;
  _DAT_00829838 = f_2;
  if (((0x10 < DAT_020b8e50) || (DAT_020b8e50 == 2)) || (DAT_020b8e50 == 3)) {
    _DAT_00829838 = f_m2;
  }
  DAT_00829834 = (float)(DAT_01a14950 - VIEW_DX) / f_150;
  DAT_00829830 = (float)(DAT_01a1494c - _DAT_0082983c) / _DAT_00829858 + _DAT_00829838;
  if (200 < IP2) {
    DAT_00829834 = DAT_00829834 - f_226_66;
  }
  _DAT_0082982c = DAT_00829834 - DAT_020b9448;
  _DAT_00829828 = DAT_00829830 - DAT_020b944c;
  P3 = DAT_020b9448;
  P6 = DAT_020b9454;
  if ((DAT_020b8e50 == 6) && (DAT_0078dc30 == 2)) {
    _DAT_0082982c = DAT_00829834 - DAT_020b9454;
  }
  if (DAT_00829854 != 1) {
    if ((DAT_00829854 != 2) && (DAT_00829854 == 3)) {
      _DAT_0082982c = f_0;
      goto LAB_0048fab3;
    }
    _DAT_00829828 = f_0;
  }
  iVar2 = 6;
  DAT_00829824 = 1;
  do {
    DAT_00829820 = *(int *)(DAT_00829824 * 4 + 0x78d81c);
    if (DAT_00829820 != 0) {
      if (DAT_00829820 == 3) {
        DAT_020b9448 = DAT_00829834;
      }
      else if (DAT_0078dc30 == 1) {
        *(float *)(&DAT_020b943c + DAT_00829820 * 4) = DAT_00829834;
      }
      else if (DAT_0078dc30 + -1 < 1) {
        *(float *)(&DAT_020b943c + DAT_00829820 * 4) =
             _DAT_0082982c + *(float *)(&DAT_020b943c + DAT_00829820 * 4);
      }
      else {
        *(float *)(&DAT_020b943c + DAT_00829820 * 4) = DAT_00829834;
      }
    }
    DAT_00829824 = DAT_00829824 + 1;
    iVar2 = iVar2 + -1;
  } while (0 < iVar2);
LAB_0048fab3:
  if (_DAT_00829828 != f_0) {
    iVar2 = 2;
    DAT_00829824 = 1;
    puVar1 = &stack0xfffffffc;
    do {
      DAT_00829820 = *(int *)(&DAT_0078d834 + DAT_00829824 * 4);
      if (DAT_00829820 == 0) {
        *(undefined4 *)(puVar1 + -0xc) = 0;
      }
      else if (DAT_00829820 == 5) {
        DAT_020b9450 = _DAT_00829828 + DAT_020b9450;
        if (DAT_0078dc30 == 2) {
          DAT_020b9450 = DAT_00829830;
        }
      }
      else {
        if ((DAT_020b8e50 < 4) || (0x10 < DAT_020b8e50)) {
          fVar3 = (float10)FUN_005ff381(puVar1,0x48fb5e);
          *(int *)(puVar1 + -0x60) = (int)ROUND(fVar3);
          DAT_00829830 = (float)*(int *)(puVar1 + -0x60);
        }
        DAT_020b944c = DAT_00829830;
      }
      *(undefined4 *)(puVar1 + -8) = 0;
      DAT_00829824 = DAT_00829824 + 1;
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
  }
  if (((DAT_0078dc30 == 0) && (DAT_020b8e50 == 4)) && (DAT_020b9458 == f_100)) {
    DAT_020b945c = _DAT_0082982c + DAT_020b945c;
    DAT_020b9460 = _DAT_00829828 + DAT_020b9460;
    DAT_020b9464 = _DAT_0082982c + DAT_020b9464;
    DAT_020b9468 = _DAT_00829828 + DAT_020b9468;
    DAT_020b946c = _DAT_0082982c + DAT_020b946c;
    DAT_020b9470 = _DAT_00829828 + DAT_020b9470;
    DAT_020b9474 = _DAT_0082982c + DAT_020b9474;
    DAT_020b9478 = _DAT_00829828 + DAT_020b9478;
    DAT_020b947c = _DAT_0082982c + DAT_020b947c;
    DAT_020b9480 = _DAT_00829828 + DAT_020b9480;
  }
  else {
    *(undefined4 *)(puVar1 + -4) = 0;
  }
  VEC_N = DAT_01be6d74;
  *DAT_01fbb844 = DAT_01be6d70;
  NPT = 1;
  thunk_FUN_0054c590(&DAT_020b9440,&P1,&DAT_00762d14);
  draw_item();
  P1 = f_99;
  if (COLOR == 0) {
    COLOR = 0xff;
  }
  flush_points();
  *DAT_01fbb7c0 = VEC_N + -1;
  FUN_0048ecfb();
  DAT_0205274c = 1;
  DAT_01c58934 = P6;
  DAT_01c58930 = P5;
  DAT_01c5892c = P4;
  DAT_01c58928 = P3;
  return;
}


