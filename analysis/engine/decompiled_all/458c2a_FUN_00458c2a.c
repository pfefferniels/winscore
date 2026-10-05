// FUN_00458c2a @ 00458c2a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00458c2a(undefined4 *param_1,int *param_2)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  float10 in_ST0;
  float10 fVar4;
  float10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  float10 extraout_ST1_01;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  DAT_007fed58 = DAT_01c23740;
  _DAT_007fed54 = (float)*param_2;
  if ((DAT_01c23748 == *(int *)(&DAT_01c23680 + DAT_01c23740 * 200)) &&
     (DAT_01c2374c == *(int *)(&DAT_01c23684 + DAT_01c23740 * 200))) {
    *param_1 = 1;
    DAT_007fed50 = DAT_007fed58;
    for (iVar3 = -DAT_007fed58 / -1; 0 < iVar3; iVar3 = iVar3 + -1) {
      (&DAT_01c23748)[DAT_007fed50 * 0x32] = *(undefined4 *)(&DAT_01c23680 + DAT_007fed50 * 200);
      (&DAT_01c2374c)[DAT_007fed50 * 0x32] = *(undefined4 *)(&DAT_01c23684 + DAT_007fed50 * 200);
      DAT_007fed50 = DAT_007fed50 + -1;
    }
    DAT_01c23748 = *(int *)(&DAT_01c23680 + DAT_007fed58 * 200);
    DAT_01c2374c = *(int *)(&DAT_01c23684 + DAT_007fed58 * 200);
    DAT_007fed58 = DAT_007fed58 + 2;
    *(undefined4 *)(&DAT_01c23680 + DAT_007fed58 * 200) = DAT_01c238d8;
    *(undefined4 *)(&DAT_01c23684 + DAT_007fed58 * 200) = DAT_01c238dc;
  }
  DAT_007fed50 = 1;
  iVar3 = DAT_007fed58 + -1;
  _DAT_01c197c8 = f_1;
  _DAT_01c19890 = f_0_5;
  while (0 < iVar3) {
    DAT_007fed4c = (float)(((&DAT_01c23748)[DAT_007fed50 * 0x32] -
                           *(int *)(&DAT_01c23680 + DAT_007fed50 * 200)) *
                          ((&DAT_01c23748)[DAT_007fed50 * 0x32] -
                          *(int *)(&DAT_01c23680 + DAT_007fed50 * 200)));
    DAT_007fed5c = (&DAT_01c2374c)[DAT_007fed50 * 0x32] -
                   *(int *)(&DAT_01c23684 + DAT_007fed50 * 200);
    *(int *)(puVar5 + -0xa0) = DAT_007fed5c * DAT_007fed5c;
    DAT_007fed48 = (float)*(int *)(puVar5 + -0xa0);
    _DAT_007fed44 = DAT_007fed48 + DAT_007fed4c;
    bVar2 = _DAT_007fed44 < f_0;
    if (bVar2) {
      in_ST0 = (float10)_DAT_007fed44;
      _DAT_007fed44 = (float)-in_ST0;
    }
    DAT_007fed40 = (uint)bVar2;
    iVar3 = DAT_007fed50 * 4;
    ffree(in_ST0);
    fVar4 = (float10)FUN_005ff146(puVar5,0x458ea5);
    *(float *)(&DAT_01c1e83c + iVar3) = (float)fVar4;
    in_ST0 = extraout_ST1;
    if (DAT_007fed40 != 0) {
      in_ST0 = (float10)*(float *)(&DAT_01c1e83c + DAT_007fed50 * 4);
      *(float *)(&DAT_01c1e83c + DAT_007fed50 * 4) = (float)-in_ST0;
    }
    DAT_007fed50 = DAT_007fed50 + 1;
    *(int *)(puVar5 + -0x74) = *(int *)(puVar5 + -0x74) + -1;
    iVar3 = *(int *)(puVar5 + -0x74);
  }
  fVar1 = f_0_1;
  if (DAT_01c1e840 != f_0) {
    *(undefined4 *)(puVar5 + -0x70) = 0;
    fVar1 = DAT_01c1e840;
  }
  DAT_01c1e840 = fVar1;
  DAT_007fed4c = f_3 / (DAT_01c1e840 * f_2);
  *(int *)(puVar5 + -0xa0) = DAT_01c23810 - DAT_01c23748;
  _DAT_01c1be10 = (float)*(int *)(puVar5 + -0xa0) * DAT_007fed4c;
  *(int *)(puVar5 + -0xa0) = DAT_01c23814 - DAT_01c2374c;
  _DAT_01c1be14 = (float)*(int *)(puVar5 + -0xa0) * DAT_007fed4c;
  *(float *)(&DAT_01c196fc + DAT_007fed58 * 4) = f_2;
  *(float *)(&DAT_01c197c4 + DAT_007fed58 * 4) = f_4;
  DAT_007fed3c = DAT_007fed58 + -1;
  if (*(float *)(&DAT_01c1e83c + DAT_007fed3c * 4) == f_0) {
    *(float *)(&DAT_01c1e83c + DAT_007fed3c * 4) = f_0_1;
  }
  else {
    *(undefined4 *)(puVar5 + -0x6c) = 0;
  }
  _DAT_007fed38 = f_6 / *(float *)(&DAT_01c1e83c + DAT_007fed3c * 4);
  *(int *)(puVar5 + -0xa0) =
       *(int *)(&DAT_01c23680 + DAT_007fed58 * 200) - *(int *)(&DAT_01c23680 + DAT_007fed3c * 200);
  *(float *)(&DAT_01c1bd48 + DAT_007fed58 * 200) = (float)*(int *)(puVar5 + -0xa0) * _DAT_007fed38;
  *(int *)(puVar5 + -0xa0) =
       *(int *)(&DAT_01c23684 + DAT_007fed58 * 200) - *(int *)(&DAT_01c23684 + DAT_007fed3c * 200);
  *(float *)(&DAT_01c1bd4c + DAT_007fed58 * 200) = (float)*(int *)(puVar5 + -0xa0) * _DAT_007fed38;
  iVar3 = DAT_007fed3c + -1;
  *(int *)(puVar5 + -0x68) = iVar3;
  DAT_007fed50 = 2;
  while (0 < iVar3) {
    DAT_007fed4c = *(float *)(&DAT_01c1e83c + DAT_007fed50 * 4);
    DAT_007fed48 = *(float *)(DAT_007fed50 * 4 + 0x1c1e838);
    *(float *)(&DAT_01c196fc + DAT_007fed50 * 4) = DAT_007fed4c;
    *(float *)(&DAT_01c197c4 + DAT_007fed50 * 4) = (DAT_007fed48 + DAT_007fed4c) * f_2;
    *(float *)(&DAT_01c1988c + DAT_007fed50 * 4) = DAT_007fed48;
    _DAT_007fed34 = DAT_007fed48 * DAT_007fed48;
    _DAT_007fed30 = DAT_007fed4c * DAT_007fed4c;
    _DAT_007fed2c = DAT_007fed48 * DAT_007fed4c;
    if (_DAT_007fed2c == f_0) {
      _DAT_007fed2c = f_0_1;
    }
    else {
      *(undefined4 *)(puVar5 + -100) = 0;
    }
    _DAT_007fed2c = f_3 / _DAT_007fed2c;
    *(undefined4 *)(puVar5 + -0x60) = 2;
    DAT_007fed28 = 1;
    do {
      *(int *)(puVar5 + -0xa0) =
           (&DAT_01c23744)[DAT_007fed28 + DAT_007fed50 * 0x32] -
           *(int *)(DAT_007fed50 * 200 + DAT_007fed28 * 4 + 0x1c2367c);
      iVar3 = *(int *)(puVar5 + -0xa0);
      *(int *)(puVar5 + -0xa0) =
           *(int *)(DAT_007fed28 * 4 + DAT_007fed50 * 200 + 0x1c2367c) -
           *(int *)(DAT_007fed50 * 200 + DAT_007fed28 * 4 + 0x1c235b4);
      _DAT_007fed24 = (float)*(int *)(puVar5 + -0xa0) * _DAT_007fed30 + (float)iVar3 * _DAT_007fed34
      ;
      *(float *)(DAT_007fed28 * 4 + DAT_007fed50 * 200 + 0x1c1bd44) = _DAT_007fed24 * _DAT_007fed2c;
      DAT_007fed28 = DAT_007fed28 + 1;
      *(int *)(puVar5 + -0x60) = *(int *)(puVar5 + -0x60) + -1;
    } while (0 < *(int *)(puVar5 + -0x60));
    *(undefined4 *)(puVar5 + -0x5c) = 0;
    DAT_007fed50 = DAT_007fed50 + 1;
    *(int *)(puVar5 + -0x68) = *(int *)(puVar5 + -0x68) + -1;
    iVar3 = *(int *)(puVar5 + -0x68);
  }
  iVar3 = DAT_007fed58 + -1;
  *(int *)(puVar5 + -0x58) = iVar3;
  DAT_007fed50 = 2;
  while (0 < iVar3) {
    if (*(float *)(&DAT_01c196fc + DAT_007fed50 * 4) == f_0) {
      *(undefined4 *)(puVar5 + -0x54) = 0;
    }
    else {
      DAT_007fed3c = DAT_007fed50 + -1;
      fVar1 = *(float *)(&DAT_01c196fc + DAT_007fed50 * 4);
      _DAT_007fed30 = f_0_1;
      if (fVar1 != f_0) {
        *(undefined4 *)(puVar5 + -0x50) = 0;
        _DAT_007fed30 = fVar1;
      }
      _DAT_007fed30 = *(float *)(&DAT_01c197c4 + DAT_007fed3c * 4) / _DAT_007fed30;
      *(undefined4 *)(puVar5 + -0x4c) = 3;
      DAT_007fed28 = 1;
      do {
        *(float *)(DAT_007fed28 * 200 + DAT_007fed50 * 4 + 0x1c19634) =
             _DAT_007fed30 * *(float *)(DAT_007fed28 * 200 + DAT_007fed50 * 4 + 0x1c19634) -
             *(float *)(&DAT_01c196fc + DAT_007fed3c * 4 + DAT_007fed28 * 200);
        *(float *)(DAT_007fed28 * 4 + DAT_007fed50 * 200 + 0x1c1bd44) =
             _DAT_007fed30 * *(float *)(DAT_007fed50 * 200 + DAT_007fed28 * 4 + 0x1c1bd44) -
             *(float *)(DAT_007fed28 * 4 + DAT_007fed3c * 200 + 0x1c1bd44);
        DAT_007fed28 = DAT_007fed28 + 1;
        *(int *)(puVar5 + -0x4c) = *(int *)(puVar5 + -0x4c) + -1;
      } while (0 < *(int *)(puVar5 + -0x4c));
      _DAT_007fed38 = *(float *)(&DAT_01c197c4 + DAT_007fed50 * 4);
      if (_DAT_007fed38 == f_0) {
        _DAT_007fed38 = f_0_1;
      }
      else {
        *(undefined4 *)(puVar5 + -0x48) = 0;
      }
      *(undefined4 *)(puVar5 + -0x44) = 3;
      DAT_007fed28 = 1;
      do {
        *(float *)(DAT_007fed28 * 200 + DAT_007fed50 * 4 + 0x1c19634) =
             *(float *)(DAT_007fed50 * 4 + DAT_007fed28 * 200 + 0x1c19634) / _DAT_007fed38;
        *(float *)(DAT_007fed28 * 4 + DAT_007fed50 * 200 + 0x1c1bd44) =
             *(float *)(DAT_007fed50 * 200 + DAT_007fed28 * 4 + 0x1c1bd44) / _DAT_007fed38;
        DAT_007fed28 = DAT_007fed28 + 1;
        *(int *)(puVar5 + -0x44) = *(int *)(puVar5 + -0x44) + -1;
      } while (0 < *(int *)(puVar5 + -0x44));
    }
    *(undefined4 *)(puVar5 + -0x40) = 0;
    DAT_007fed50 = DAT_007fed50 + 1;
    *(int *)(puVar5 + -0x58) = *(int *)(puVar5 + -0x58) + -1;
    iVar3 = *(int *)(puVar5 + -0x58);
  }
  *(undefined4 *)(puVar5 + -0x3c) = 2;
  DAT_007fed28 = 1;
  do {
    *(int *)(puVar5 + -0x38) = DAT_007fed58;
    DAT_007fed50 = 0;
    iVar3 = DAT_007fed58;
    while (0 < iVar3) {
      DAT_007fed3c = DAT_007fed58 - DAT_007fed50;
      fVar1 = *(float *)(&DAT_01c197c4 + DAT_007fed3c * 4);
      _DAT_007fed38 = f_0_1;
      if (fVar1 != f_0) {
        *(undefined4 *)(puVar5 + -0x34) = 0;
        _DAT_007fed38 = fVar1;
      }
      *(float *)(DAT_007fed3c * 0x10 + DAT_007fed28 * 4 + 0x1c1e50c) =
           (*(float *)(DAT_007fed3c * 200 + DAT_007fed28 * 4 + 0x1c1bd44) -
           *(float *)(&DAT_01c1988c + DAT_007fed3c * 4) *
           *(float *)(DAT_007fed28 * 4 + DAT_007fed3c * 0x10 + 0x1c1e51c)) / _DAT_007fed38;
      DAT_007fed50 = DAT_007fed50 + 1;
      *(int *)(puVar5 + -0x38) = *(int *)(puVar5 + -0x38) + -1;
      iVar3 = *(int *)(puVar5 + -0x38);
    }
    *(undefined4 *)(puVar5 + -0x30) = 0;
    DAT_007fed28 = DAT_007fed28 + 1;
    *(int *)(puVar5 + -0x3c) = *(int *)(puVar5 + -0x3c) + -1;
  } while (0 < *(int *)(puVar5 + -0x3c));
  **(undefined4 **)(puVar5 + 0xc) = 0;
  iVar3 = DAT_007fed58 + -1;
  *(int *)(puVar5 + -0x2c) = iVar3;
  DAT_007fed50 = 1;
  do {
    if (iVar3 < 1) {
      DAT_007fed58 = **(int **)(puVar5 + 0x10);
      DAT_007fed0c = (&PT_X0)[DAT_007fed58];
      DAT_007fed08 = (&PT_Y0)[DAT_007fed58];
      iVar3 = **(int **)(puVar5 + 0xc);
      *(int *)(puVar5 + -0xc) = iVar3;
      DAT_007fed28 = 1;
      while (0 < iVar3) {
        DAT_007fed4c = *(float *)(&DAT_01c17df8 + DAT_007fed28 * 8) / _DAT_007fed54;
        ffree(in_ST0);
        fVar4 = (float10)anint(puVar5,0x459ace);
        *(int *)(puVar5 + -0xa0) = (int)ROUND(fVar4);
        DAT_007fed04 = *(int *)(puVar5 + -0xa0);
        *(float *)(&DAT_01c17df8 + DAT_007fed28 * 8) = DAT_007fed4c;
        DAT_007fed4c = *(float *)(DAT_007fed28 * 8 + 0x1c17dfc) / _DAT_007fed54;
        ffree(extraout_ST1_00);
        fVar4 = (float10)anint(puVar5,0x459b28);
        *(int *)(puVar5 + -0xa0) = (int)ROUND(fVar4);
        DAT_007fed00 = *(int *)(puVar5 + -0xa0);
        *(float *)(DAT_007fed28 * 8 + 0x1c17dfc) = DAT_007fed4c;
        if ((DAT_007fed04 == DAT_007fed0c) && (DAT_007fed00 == DAT_007fed08)) {
          *(int *)(puVar5 + -0xa0) = DAT_007fed04 + 20000;
          *(float *)(&DAT_01c17df8 + DAT_007fed28 * 8) = (float)*(int *)(puVar5 + -0xa0);
          DAT_007fed58 = DAT_007fed58 + 1;
          DAT_007fed0c = (&PT_X0)[DAT_007fed58];
          DAT_007fed08 = (&PT_Y0)[DAT_007fed58];
        }
        else {
          *(undefined4 *)(puVar5 + -8) = 0;
        }
        *(undefined4 *)(puVar5 + -4) = 0;
        DAT_007fed28 = DAT_007fed28 + 1;
        *(int *)(puVar5 + -0xc) = *(int *)(puVar5 + -0xc) + -1;
        in_ST0 = extraout_ST1_01;
        iVar3 = *(int *)(puVar5 + -0xc);
      }
      ffree(in_ST0);
      return;
    }
    fVar1 = *(float *)(&DAT_01c1e83c + DAT_007fed50 * 4);
    DAT_007fed20 = DAT_007fed50 + 1;
    DAT_007fed4c = f_0_1;
    if (fVar1 != f_0) {
      *(undefined4 *)(puVar5 + -0x28) = 0;
      DAT_007fed4c = fVar1;
    }
    _DAT_007fed34 = f_3 / (DAT_007fed4c * DAT_007fed4c);
    DAT_007fed48 = f_1 / (DAT_007fed4c * DAT_007fed4c);
    _DAT_007fed30 = -(f_2 / (DAT_007fed4c * DAT_007fed4c * DAT_007fed4c));
    _DAT_007fed2c = f_1 / DAT_007fed4c;
    *(undefined4 *)(puVar5 + -0x24) = 2;
    DAT_007fed28 = 1;
    do {
      (&DAT_01c1e840)[DAT_007fed28 * 0x32] =
           (float)*(int *)(DAT_007fed50 * 200 + DAT_007fed28 * 4 + 0x1c2367c);
      (&DAT_01c1e844)[DAT_007fed28 * 0x32] =
           *(undefined4 *)(DAT_007fed28 * 4 + DAT_007fed50 * 0x10 + 0x1c1e50c);
      *(int *)(puVar5 + -0xa0) =
           *(int *)(DAT_007fed20 * 200 + DAT_007fed28 * 4 + 0x1c2367c) -
           *(int *)(DAT_007fed28 * 4 + DAT_007fed50 * 200 + 0x1c2367c);
      _DAT_007fed38 = (float)*(int *)(puVar5 + -0xa0);
      (&DAT_01c1e848)[DAT_007fed28 * 0x32] =
           _DAT_007fed38 * _DAT_007fed34 -
           (*(float *)(DAT_007fed50 * 0x10 + DAT_007fed28 * 4 + 0x1c1e50c) * f_2 +
           *(float *)(DAT_007fed28 * 4 + DAT_007fed20 * 0x10 + 0x1c1e50c)) * _DAT_007fed2c;
      in_ST0 = (float10)_DAT_007fed38 * (float10)_DAT_007fed30;
      *(float *)(DAT_007fed28 * 200 + 0x1c1e84c) =
           (float)(((float10)*(float *)(DAT_007fed20 * 0x10 + DAT_007fed28 * 4 + 0x1c1e50c) +
                   (float10)*(float *)(DAT_007fed50 * 0x10 + DAT_007fed28 * 4 + 0x1c1e50c)) *
                   (float10)DAT_007fed48 + in_ST0);
      DAT_007fed28 = DAT_007fed28 + 1;
      *(int *)(puVar5 + -0x24) = *(int *)(puVar5 + -0x24) + -1;
    } while (0 < *(int *)(puVar5 + -0x24));
    _DAT_007fed38 = DAT_007fed4c / (float)DAT_01c23744;
    iVar3 = DAT_01c23744 + 1;
    *(int *)(puVar5 + -0x20) = iVar3;
    DAT_007fed18 = 1;
    _DAT_007fed1c = f_0;
    while (0 < iVar3) {
      if (DAT_007fed50 == 1) {
        *(undefined4 *)(puVar5 + -0x1c) = 0;
LAB_0045991a:
        _DAT_007fed14 = _DAT_007fed1c * _DAT_007fed1c;
        _DAT_007fed10 = _DAT_007fed1c * _DAT_007fed1c * _DAT_007fed1c;
        **(int **)(puVar5 + 0xc) = **(int **)(puVar5 + 0xc) + 1;
        *(undefined4 *)(puVar5 + -0x14) = 2;
        DAT_007fed28 = 1;
        do {
          in_ST0 = (float10)_DAT_007fed14 * (float10)(float)(&DAT_01c1e848)[DAT_007fed28 * 0x32] +
                   (float10)_DAT_007fed1c * (float10)(float)(&DAT_01c1e844)[DAT_007fed28 * 0x32] +
                   (float10)(&DAT_01c1e840)[DAT_007fed28 * 0x32];
          *(float *)(**(int **)(puVar5 + 0xc) * 8 + DAT_007fed28 * 4 + 0x1c17df4) =
               (float)((float10)_DAT_007fed10 * (float10)*(float *)(DAT_007fed28 * 200 + 0x1c1e84c)
                      + in_ST0);
          DAT_007fed28 = DAT_007fed28 + 1;
          *(int *)(puVar5 + -0x14) = *(int *)(puVar5 + -0x14) + -1;
        } while (0 < *(int *)(puVar5 + -0x14));
      }
      else {
        if (_DAT_007fed1c != f_0) goto LAB_0045991a;
        *(undefined4 *)(puVar5 + -0x18) = 0;
      }
      _DAT_007fed1c = _DAT_007fed38 + _DAT_007fed1c;
      DAT_007fed18 = DAT_007fed18 + 1;
      *(int *)(puVar5 + -0x20) = *(int *)(puVar5 + -0x20) + -1;
      iVar3 = *(int *)(puVar5 + -0x20);
    }
    *(undefined4 *)(puVar5 + -0x10) = 0;
    DAT_007fed50 = DAT_007fed50 + 1;
    *(int *)(puVar5 + -0x2c) = *(int *)(puVar5 + -0x2c) + -1;
    iVar3 = *(int *)(puVar5 + -0x2c);
  } while( true );
}


