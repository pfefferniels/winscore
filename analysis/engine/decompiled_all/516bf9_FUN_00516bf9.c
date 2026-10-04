// FUN_00516bf9 @ 00516bf9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00516bf9(undefined4 *param_1)

{
  int iVar1;
  float10 in_ST0;
  unkbyte10 Var2;
  
  _DAT_0094c1bc = 0;
  DAT_0094c1b8 = 1;
  for (iVar1 = DAT_01ba2064; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_0094c1b4 = (&DAT_01c4637c)[DAT_0094c1b8];
    DAT_0094c1b0 = (int)ROUND((float)(&DAT_01c6da60)[DAT_0094c1b4]);
    if (((((DAT_0094c1b0 == 0x10) || (DAT_0094c1b0 == 10)) || (DAT_0094c1b0 == 0x12)) ||
        (DAT_0094c1b0 == 1)) ||
       (((DAT_0094c1ac = (int)ROUND(*(float *)(&DAT_01c6da5c + DAT_0094c1b4 * 4)), DAT_0094c1b0 == 5
         && (4 < DAT_0094c1ac)) &&
        ((DAT_0094c1ac = (int)ROUND((float)(&DAT_01c6da7c)[DAT_0094c1b4]), 0 < DAT_0094c1ac &&
         (DAT_0094c1ac < 3)))))) goto LAB_0051781e;
    if (DAT_0094c1b0 == 2) {
      if ((DAT_0094c1ac < 8) ||
         (DAT_0094c1a8 = (float)(&DAT_01c6da7c)[DAT_0094c1b4], iVar1 = DAT_0094c1b8,
         DAT_0094c1a8 <= f_0)) goto LAB_0051781e;
      goto LAB_00516e30;
    }
    DAT_0094c1b8 = DAT_0094c1b8 + 1;
  }
LAB_00516ed9:
  _DAT_0094c198 = 0;
  DAT_0094c1b8 = DAT_01a1fee0;
  for (iVar1 = -DAT_01a1fee0 / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_0094c194 = (&DAT_01a1fee4)[DAT_0094c1b8];
    DAT_0094c1b0 = (int)ROUND((float)(&DAT_01ba2140)[DAT_0094c194]);
    DAT_0094c188 = (float)(int)ROUND(*(float *)(&DAT_01ba213c + DAT_0094c194 * 4));
    if (DAT_0094c1b0 == 0xe) {
      if ((4 < (int)DAT_0094c188) || (DAT_01a1fee0 != DAT_0094c1b8)) goto LAB_0051781e;
      _DAT_0094c198 = 1;
    }
    else if (DAT_0094c1b0 == 2) {
      if (((((int)DAT_0094c188 < 8) ||
           (DAT_0094c1b0 = (int)ROUND((float)(&DAT_01ba2150)[DAT_0094c194]),
           *(float *)(&DAT_01ba215c + DAT_0094c194 * 4) < f_0)) || (-2 < DAT_0094c1b0)) ||
         ((DAT_0094c1b0 == -4 || ((float)(&DAT_01ba2154)[DAT_0094c194] < f_0)))) goto LAB_0051781e;
      DAT_0094c190 = DAT_0094c1b8 + -1;
      iVar1 = -DAT_0094c190 / -1;
      goto joined_r0x0051710a;
    }
    DAT_0094c1b8 = DAT_0094c1b8 + -1;
  }
LAB_005172bb:
  if (f_4 < DAT_0094c1a0) {
    DAT_0094c194 = (&DAT_01a1fee4)[DAT_01a1fee0];
    (&DAT_01ba2150)[DAT_0094c194] = (&DAT_01c6da70)[DAT_0094c1a4];
    DAT_0094c1b0 = (int)ROUND(DAT_0094c1a0);
    DAT_0094c190 = (int)ROUND(*(float *)(&DAT_01ba213c + DAT_0094c194 * 4));
    DAT_01a1fee4 = (DAT_0094c1b0 + DAT_01a1fee4) - DAT_0094c190;
    *(float *)(&DAT_01ba213c + DAT_0094c194 * 4) = DAT_0094c1a0;
  }
  DAT_0094c1ac = DAT_0094c1ac + 1;
  if (DAT_0094c1ac <= DAT_01ba2064) {
    DAT_0094c190 = (&DAT_01c4637c)[DAT_0094c1ac];
    DAT_0094c194 = (int)ROUND((float)(&DAT_01c6da60)[DAT_0094c190]);
    if (0x10 < DAT_0094c194) {
      DAT_0094c194 = (int)ROUND(*(float *)(&DAT_01c6da5c + DAT_0094c190 * 4) + f_1);
      ffree(in_ST0);
      in_ST0 = (float10)thunk_FUN_0054c590(&DAT_01c6da5c + DAT_0094c190 * 4,
                                           &DAT_01ba213c + DAT_01a1fee4 * 4,&DAT_0094c194);
      (&DAT_01ba2148)[DAT_01a1fee4] = (float)(&DAT_01ba2148)[(&DAT_01a1fee4)[DAT_01a1fee0]] + f_1;
      DAT_01a1fee0 = DAT_01a1fee0 + 1;
      DAT_01a1fee4 = DAT_0094c194 + DAT_01a1fee4;
      (&DAT_01a1fee8)[DAT_01a1fee0] = DAT_01a1fee4;
    }
  }
  if (DAT_0094c19c < DAT_01ba2064 + -1) {
    DAT_0094c190 = DAT_0094c19c + 1;
    for (iVar1 = (DAT_01ba2064 - DAT_0094c190) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      if ((int)ROUND((float)(&DAT_01c6da60)[(&DAT_01c4637c)[DAT_0094c190]]) == 0xe) {
        DAT_0094c1b4 = (&DAT_01c46380)[DAT_0094c19c];
        DAT_0094c1b0 = DAT_01ba2068 - DAT_0094c1b4;
        ffree(in_ST0);
        Var2 = thunk_FUN_0054c590(&DAT_01c6da5c + DAT_0094c1b4 * 4,&DAT_01c6da60,&DAT_0094c1b0);
        DAT_0094c1b0 = DAT_0094c1b0 + 1;
        ffree(Var2);
        in_ST0 = (float10)thunk_FUN_0049836a(&DAT_01c6da60,&DAT_01c46380,&DAT_01ba2068,&DAT_01ba2064
                                             ,&DAT_0094c1b0);
        goto LAB_0051781e;
      }
      DAT_0094c190 = DAT_0094c190 + 1;
    }
    DAT_0094c1a0 = (float)(&DAT_01ba2148)[(&DAT_01a1fee4)[DAT_01a1fee0]] + f_0_01;
    DAT_0094c188 = (float)(&DAT_01c6da68)[(&DAT_01c46380)[DAT_0094c19c]];
    if (DAT_0094c188 <= DAT_0094c1a0) {
      DAT_0094c1a0 = (DAT_0094c1a0 - DAT_0094c188) + f_2;
      DAT_0094c190 = DAT_0094c19c + 1;
      for (iVar1 = (DAT_01ba2064 - DAT_0094c190) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&DAT_01c6da68)[(&DAT_01c4637c)[DAT_0094c190]] =
             DAT_0094c1a0 + (float)(&DAT_01c6da68)[(&DAT_01c4637c)[DAT_0094c190]];
        DAT_0094c190 = DAT_0094c190 + 1;
      }
    }
    DAT_0094c1b4 = (&DAT_01c46380)[DAT_0094c19c];
    DAT_0094c1b0 = DAT_01ba2068 - DAT_0094c1b4;
    ffree(in_ST0);
    Var2 = thunk_FUN_0054c590(&DAT_01c6da5c + DAT_0094c1b4 * 4,&DAT_01ba213c + DAT_01a1fee4 * 4,
                              &DAT_0094c1b0);
    DAT_0094c1b0 = DAT_0094c1b0 + DAT_01a1fee4;
    ffree(Var2);
    in_ST0 = (float10)thunk_FUN_0049836a(&DAT_01ba2140,&DAT_01a1fee8,&DAT_01a1fee4,&DAT_01a1fee0,
                                         &DAT_0094c1b0);
  }
  *param_1 = 1;
LAB_0051781e:
  ffree(in_ST0);
  return;
  while (iVar1 = DAT_0094c1ac, (float)(&DAT_01c6da60)[DAT_0094c1a4] == f_3) {
LAB_00516e30:
    DAT_0094c1ac = iVar1 + 1;
    DAT_0094c1a4 = (&DAT_01c4637c)[DAT_0094c1ac];
    _DAT_0094c1bc = DAT_0094c1b4;
    if ((float)(&DAT_01c6da60)[DAT_0094c1a4] == f_14) {
      DAT_0094c1a0 = *(float *)(&DAT_01c6da5c + DAT_0094c1a4 * 4);
      DAT_0094c19c = DAT_0094c1b8;
      goto LAB_00516ed9;
    }
  }
  goto LAB_0051781e;
joined_r0x0051710a:
  if ((iVar1 < 1) || (DAT_0094c190 < 2)) goto LAB_005171bc;
  DAT_0094c1b0 = (int)ROUND((float)(&DAT_01ba2140)[(&DAT_01a1fee4)[DAT_0094c190]]);
  if (DAT_0094c1b0 == 1) goto LAB_0051781e;
  if (DAT_0094c1b0 == 0xe) goto LAB_005171bc;
  DAT_0094c190 = DAT_0094c190 + -1;
  iVar1 = iVar1 + -1;
  goto joined_r0x0051710a;
LAB_005171bc:
  DAT_0094c1a8 = DAT_0094c1a8 + *(float *)(&DAT_01ba215c + DAT_0094c194 * 4);
  *(float *)(&DAT_01ba215c + DAT_0094c194 * 4) = DAT_0094c1a8;
  if (0x10 < (int)DAT_0094c188) {
    *(float *)(&DAT_01ba2180 + DAT_0094c194 * 4) =
         DAT_0094c1a8 * *(float *)(&DAT_01ba2158 + DAT_0094c194 * 4);
  }
  (&DAT_01ba2150)[DAT_0094c194] = f_m5;
  if (DAT_0094c1a8 < f_10) {
    iVar1 = DAT_01c5860c;
    if (DAT_01c5860c < 0) {
      iVar1 = -DAT_01c5860c;
    }
    if (2 < iVar1) {
      in_ST0 = (float10)DAT_0094c1a8;
      (&DAT_01ba2150)[DAT_0094c194] = (float)(-in_ST0 - (float10)f_10);
    }
  }
  if (f_6 < DAT_0094c1a8) {
    DAT_0094c1a8 = f_6;
  }
  *(float *)(&DAT_01ba2158 + DAT_0094c194 * 4) = DAT_0094c1a8;
  goto LAB_005172bb;
}


