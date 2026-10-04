// FUN_00566cb2 @ 00566cb2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00566ee9) */
/* WARNING: Removing unreachable block (ram,0x00566fb4) */
/* WARNING: Removing unreachable block (ram,0x00566ea3) */
/* WARNING: Removing unreachable block (ram,0x00567237) */
/* WARNING: Removing unreachable block (ram,0x00567002) */
/* WARNING: Removing unreachable block (ram,0x00566f2f) */
/* WARNING: Removing unreachable block (ram,0x00566f72) */
/* WARNING: Removing unreachable block (ram,0x00567065) */
/* WARNING: Removing unreachable block (ram,0x00567081) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00566cb2(void)

{
  float fVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var11;
  float10 fVar12;
  unkbyte10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  
  puVar6 = &stack0xfffffffc;
  DAT_009a7e58 = 0;
  DAT_009a7e54 = 0;
  ffree(in_ST0);
  Var11 = thunk_FUN_0054c5f8(&DAT_020b8ea0,1,&DAT_01e99980,1,&DAT_0076a068);
  ffree(Var11);
  fVar12 = (float10)thunk_FUN_0054c590(&P1,&DAT_01e60600,&DAT_00769f44);
  _DAT_009a7e50 = P13;
  DAT_009a7e4c = DAT_01c4d10c;
  puVar2 = &stack0xfffffffc;
  if (DAT_01c4d10c == 99) {
LAB_00567866:
    puVar6 = puVar2;
    DAT_009a7e40 = DAT_009a7e40 + 1;
    DAT_009a7e60 = (float)(&DAT_01e60790)[DAT_009a7e40];
LAB_0056797f:
    if (DAT_01c6da40 == 0) {
      *(undefined4 *)(puVar6 + -0xc) = 0;
      DAT_009a7e20 = f_m1_35;
      if (_DAT_009a7e50 < f_8) {
        DAT_009a7e20 = f_6_65 - _DAT_009a7e50;
        if (f_0 < DAT_009a7e20) {
          DAT_009a7e20 = f_0;
        }
      }
      else {
        *(undefined4 *)(puVar6 + -4) = 0;
      }
      DAT_009a7e20 = (STEP * DAT_009a7e20) / f_25;
    }
    else {
      fVar12 = (float10)STEP * (float10)f_0_064;
      DAT_009a7e20 = (float)(fVar12 - (float10)_DAT_009a7e50 / (float10)f_2);
      if (DAT_01c6da40 < 0) {
        DAT_009a7e5c = (&DAT_01caea3c)[DAT_01cb1068];
        DAT_009a7e1c = DAT_01caea44;
        _DAT_009a7e18 = f_0;
        if (((DAT_009a7e5c == 0x4e) || (DAT_009a7e5c == 0x4c)) ||
           ((DAT_009a7e5c == 0x24 ||
            ((DAT_009a7e5c == 0x25 || (DAT_009a7e5c < 0x46 && 0x41 < DAT_009a7e5c)))))) {
          _DAT_009a7e18 = *(float *)(&DAT_01cadd3c + DAT_01cb1068 * 4) / f_2;
        }
        if (((DAT_01caea44 == 0x4e) || (DAT_01caea44 == 0x80)) || (DAT_01caea44 == 0x68)) {
          _DAT_009a7e18 = _DAT_009a7e18 - DAT_01cadd44 / f_2;
        }
        DAT_009a7e20 = _DAT_009a7e18 + DAT_009a7e20;
      }
      *(undefined4 *)(puVar6 + -8) = 0;
    }
    (&ITEM_P3)[DAT_01c4d110] = DAT_009a7e60;
    *(float *)(&ITEM_P11 + DAT_01c4d110 * 4) = DAT_009a7e20;
    ffree(fVar12);
    fVar12 = (float10)thunk_FUN_0054c590(&DAT_01e60600,&P1,&DAT_00769f44);
    P3 = DAT_009a7e60;
LAB_00567b69:
    ffree(fVar12);
    fVar12 = (float10)thunk_FUN_0054c5f8(&DAT_01e99980,1,&DAT_020b8ea0,1,&DAT_0076a068);
    DAT_01c4d10c = DAT_009a7e4c;
    DAT_01b12c70 = 0;
    if (DAT_009a7e58 != 0) {
      DAT_02052740 = DAT_02052744;
    }
LAB_00567bbe:
    ffree(fVar12);
    return;
  }
  DAT_009a7e48 = DAT_01c4d10c;
  if (DAT_01c4d10c == 1) {
    DAT_009a7e44 = 0;
    DAT_009a7e40 = 0;
    puVar6 = &stack0xfffffffc;
  }
LAB_00566d7d:
  if (DAT_009a7e44 == 0) {
    *(undefined4 *)(puVar6 + -0xa4) = 0;
LAB_00566d94:
    do {
      if (DAT_02052744 != DAT_02052740) {
        DAT_009a7e4c = DAT_01c4d104 + 1;
        if (*(char *)((int)&ITEM_LEN + DAT_01c4d104 + 3) == '_') {
          DAT_009a7e4c = DAT_01c4d104 + 3;
        }
        iVar9 = (DAT_01c4d108 - DAT_009a7e4c) + 1;
        if (iVar9 < 0) {
          iVar9 = 0;
        }
        iVar5 = 1;
        iVar3 = DAT_009a7e4c;
        for (iVar7 = 1; iVar7 <= iVar9; iVar7 = iVar7 + 1) {
          (&DAT_020b909f)[iVar5] = *(undefined1 *)((int)&ITEM_LEN + iVar3 + 3);
          iVar3 = iVar3 + 1;
          iVar5 = iVar5 + 1;
        }
        DAT_009a7e38 = 1;
        Var11 = FUN_005f33c9(puVar6,0x566e57);
        ffree(Var11);
        iVar9 = FUN_005ff950(puVar6 + -0x2d8,0x200);
        *(int *)(puVar6 + -0x9c) = iVar9;
        DAT_009a7e34 = 1;
        Var11 = extraout_ST0;
        while (0 < iVar9) {
          iVar9 = FUN_005f4660(0x20);
          if ((((iVar9 == 0) && (iVar9 = FUN_005f4660(0x20), iVar9 == 0)) &&
              (iVar9 = FUN_005f4660(0x20), iVar9 == 0)) &&
             ((iVar9 = FUN_005f4660(0x20), iVar9 == 0 && (iVar9 = FUN_005f4660(0x20), iVar9 == 0))))
          {
            *(undefined4 *)(puVar6 + -0x98) = 0;
          }
          else {
            FUN_005f46bc(puVar6,0x567026);
            FUN_005f34d1(puVar6,0x56703c);
            DAT_009a7e38 = DAT_009a7e38 + 2;
          }
          FUN_005f46bc(puVar6,0x5670a2);
          Var11 = FUN_005f34d1(puVar6,0x5670b8);
          DAT_009a7e38 = DAT_009a7e38 + 1;
          DAT_009a7e34 = DAT_009a7e34 + 1;
          *(int *)(puVar6 + -0x9c) = *(int *)(puVar6 + -0x9c) + -1;
          iVar9 = *(int *)(puVar6 + -0x9c);
        }
        ffree(Var11);
        DAT_009a7e54 = thunk_FUN_0059ab50();
        fVar12 = extraout_ST0_00;
      }
      if ((DAT_009a7e54 == 2) || ((char)DAT_009ae2bc == '0')) {
        IP1 = -999;
        *(undefined4 *)(puVar6 + -0x94) = 0;
        goto LAB_00567bbe;
      }
      puVar8 = &DAT_009ae2bc;
      puVar10 = (undefined4 *)&DAT_020b8ea0;
      for (iVar9 = 0x80; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
LAB_00567136:
      *(undefined4 *)(puVar6 + -0x90) = 0xdc;
      DAT_009a7e40 = 1;
      do {
        if (((&DAT_020b8e9f)[DAT_009a7e40] == ':') || ((&DAT_020b8e9f)[DAT_009a7e40] == '\''))
        goto LAB_005671ae;
        *(undefined4 *)(puVar6 + -0x8c) = 0;
        *(undefined4 *)(puVar6 + -0x80) = 0;
        DAT_009a7e40 = DAT_009a7e40 + 1;
        *(int *)(puVar6 + -0x90) = *(int *)(puVar6 + -0x90) + -1;
      } while (0 < *(int *)(puVar6 + -0x90));
      if (DAT_02052740 == 0) {
        *(undefined4 *)(puVar6 + -0x7c) = 0;
        goto LAB_0056732e;
      }
      *(undefined4 *)(puVar6 + -0xcc) = 0;
      *(undefined4 *)(puVar6 + -0xd8) = 0x200;
      *(char **)(puVar6 + -0xd4) = &DAT_020b90a0;
      ffree(fVar12);
      uVar4 = FUN_005fdbd0(puVar6 + -0xcc,DAT_02052740,0x784ff01,&DAT_0076a04c,puVar6 + -0xd8,
                           &DAT_0079f6a8);
      *(undefined4 *)(puVar6 + -0x78) = uVar4;
      if (*(int *)(puVar6 + -0x78) == 0) {
        if (DAT_020b90a0 == ' ') {
          *(undefined4 *)(puVar6 + -0x74) = 0;
          goto LAB_005675fd;
        }
        puVar8 = (undefined4 *)&DAT_020b90a0;
        puVar10 = (undefined4 *)&DAT_020b8ea0;
        for (iVar9 = 0x80; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        *(undefined4 *)(puVar6 + -0x70) = 0;
        fVar12 = extraout_ST0_01;
LAB_0056732e:
        ffree(fVar12);
        Var11 = thunk_FUN_0054c8e5(&DAT_020b8ea0,0x200,&DAT_009a7e30);
        ffree(Var11);
        fVar12 = (float10)thunk_FUN_00518b3f(&DAT_009a7e30);
        DAT_009a7e4c = DAT_009a7e48 + 1;
        *(undefined4 *)(puVar6 + -0x68) = 0;
        if ((DAT_0078b4e0 == 0x42) || (DAT_0078b4e0 == 0x5e)) {
          DAT_0078dd50 = 1;
          *(undefined4 *)(puVar6 + -100) = 0;
          goto LAB_00567b69;
        }
        DAT_009a7e40 = 1;
        *(undefined4 *)(puVar6 + -0x60) = 0x2d;
        DAT_009a7e34 = 0x2d;
        do {
          if (*(float *)(&P0 + DAT_009a7e34 * 4) != f_0) {
            *(undefined4 *)(puVar6 + -0x5c) = 0;
            break;
          }
          DAT_009a7e34 = DAT_009a7e34 + -1;
          *(int *)(puVar6 + -0x60) = *(int *)(puVar6 + -0x60) + -1;
        } while (0 < *(int *)(puVar6 + -0x60));
        do {
          iVar9 = (DAT_009a7e34 - DAT_009a7e40) + 1;
          *(int *)(puVar6 + -0x58) = iVar9;
          DAT_009a7e38 = DAT_009a7e40;
          while( true ) {
            if (iVar9 < 1) {
              *(undefined4 *)(puVar6 + -0x50) = 0;
              if ((((DAT_0078b4e4 == 0x20) && (DAT_0078b4e0 == 0x20)) &&
                  (DAT_02052744 == DAT_02052740)) &&
                 (s_______09___InchesMetricParallel_P_0078da40[0] == DAT_020b8ea2)) {
                DAT_02052740 = DAT_02052748;
                DAT_009a7e58 = 1;
                *(undefined4 *)(puVar6 + -0x3c) = 0;
                goto LAB_00566d94;
              }
              *(undefined4 *)(puVar6 + -0x40) = 0;
              if (P1 == f_0) {
                P1 = f_1;
              }
              *(undefined4 *)(puVar6 + -0x38) = 0x2d;
              DAT_009a7e34 = 1;
              goto LAB_0056765c;
            }
            if (*(float *)(&P0 + DAT_009a7e38 * 4) == f_77) break;
            DAT_009a7e38 = DAT_009a7e38 + 1;
            *(int *)(puVar6 + -0x58) = *(int *)(puVar6 + -0x58) + -1;
            iVar9 = *(int *)(puVar6 + -0x58);
          }
          *(undefined4 *)(puVar6 + -0x54) = 0;
          fVar1 = (&P1)[DAT_009a7e38];
          *(undefined2 *)(puVar6 + -0xd4) = in_FPUControlWord;
          *(ushort *)(puVar6 + -0xd2) = (ushort)*(undefined4 *)(puVar6 + -0xd4) | 0xc00;
          *(int *)(puVar6 + -0xd0) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar6 + -0xd4);
          DAT_01c4d10c = *(int *)(puVar6 + -0xd0);
          while( true ) {
            *(float *)(&P0 + DAT_009a7e38 * 4) = *(float *)(&DAT_020b9358 + DAT_009a7e38 * 4) + f_1;
            fVar12 = (float10)*(float *)(&P0 + DAT_009a7e38 * 4) + (float10)f_1;
            if ((float10)DAT_01c4d10c <= fVar12) break;
            DAT_009a7e38 = DAT_009a7e38 + 1;
            iVar9 = ((DAT_009a7e38 - DAT_009a7e34) + -1) / -1;
            *(int *)(puVar6 + -0x4c) = iVar9;
            DAT_009a7e2c = DAT_009a7e34;
            while (0 < iVar9) {
              (&P1)[DAT_009a7e2c] = *(float *)(&P0 + DAT_009a7e2c * 4);
              DAT_009a7e2c = DAT_009a7e2c + -1;
              *(int *)(puVar6 + -0x4c) = *(int *)(puVar6 + -0x4c) + -1;
              iVar9 = *(int *)(puVar6 + -0x4c);
            }
            DAT_009a7e34 = DAT_009a7e34 + 1;
            *(undefined4 *)(puVar6 + -0x48) = 0;
          }
          DAT_009a7e40 = DAT_01c4d10c + 1;
          *(undefined4 *)(puVar6 + -0x44) = 0;
        } while( true );
      }
LAB_005675fd:
      DAT_02052740 = 0;
      puVar8 = &DAT_019c5e84;
      puVar10 = &DAT_009ae2bc;
      for (iVar9 = 0x80; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      *(undefined4 *)(puVar6 + -0x6c) = 0;
      fVar12 = extraout_ST0_01;
    } while( true );
  }
  DAT_009a7e44 = DAT_009a7e44 + 1;
  _DAT_009a7e3c = (float)(&DAT_020b9504)[DAT_009a7e44];
  *(undefined4 *)(puVar6 + -0xa0) = 0;
LAB_00567826:
  if (_DAT_009a7e3c != f_99) {
    *(undefined2 *)(puVar6 + -0xd4) = in_FPUControlWord;
    *(ushort *)(puVar6 + -0xd2) = (ushort)*(undefined4 *)(puVar6 + -0xd4) | 0xc00;
    *(int *)(puVar6 + -0xd0) = (int)ROUND(_DAT_009a7e3c);
    DAT_009a7e40 = *(int *)(puVar6 + -0xd0);
    if (DAT_009a7e40 == 0) {
      *(undefined4 *)(puVar6 + -0x18) = 0;
      DAT_009a7e60 = f_0;
    }
    else {
      DAT_009a7e60 = (float)(&DAT_01e60790)[DAT_009a7e40];
      *(undefined4 *)(puVar6 + -0x14) = 0;
    }
    if ((float)DAT_009a7e40 != _DAT_009a7e3c) {
      fVar12 = (float10)(float)(&DAT_01e60794)[DAT_009a7e40] - (float10)DAT_009a7e60;
      DAT_009a7e60 = (float)(((float10)_DAT_009a7e3c - (float10)DAT_009a7e40) * fVar12 +
                            (float10)DAT_009a7e60);
    }
    if (DAT_009a7e28 != f_0) {
      (&ITEM_P4)[DAT_01c4d110] = DAT_009a7e28;
    }
    *(undefined4 *)(puVar6 + -0x10) = 0;
    goto LAB_0056797f;
  }
  *(undefined4 *)(puVar6 + -0x1c) = 0;
  DAT_009a7e4c = 99;
  puVar2 = puVar6;
  if (P1 == f_99) {
    DAT_009a7e40 = 0;
  }
  goto LAB_00567866;
LAB_005671ae:
  iVar9 = (DAT_009a7e40 + -0xdc) / -1;
  *(int *)(puVar6 + -0x88) = iVar9;
  DAT_009a7e48 = 0xdc;
  while (0 < iVar9) {
    (&DAT_020b8ea2)[DAT_009a7e48] = (&DAT_020b8e9f)[DAT_009a7e48];
    DAT_009a7e48 = DAT_009a7e48 + -1;
    *(int *)(puVar6 + -0x88) = *(int *)(puVar6 + -0x88) + -1;
    iVar9 = *(int *)(puVar6 + -0x88);
  }
  FUN_005f46bc(puVar6,0x567259);
  fVar12 = (float10)FUN_005f34d1(puVar6,0x56726f);
  *(undefined4 *)(puVar6 + -0x84) = 0;
  goto LAB_00567136;
LAB_0056765c:
  do {
    if ((*(float *)(&P0 + DAT_009a7e34 * 4) == f_99) || (*(float *)(&P0 + DAT_009a7e34 * 4) == f_0))
    {
      if (DAT_009a7e34 != 1) {
        DAT_009a7e28 = *(float *)(&DAT_020b9358 + DAT_009a7e34 * 4);
        iVar9 = 0x2e - DAT_009a7e34;
        *(int *)(puVar6 + -0x2c) = iVar9;
        DAT_009a7e24 = DAT_009a7e34;
        while (0 < iVar9) {
          DAT_009a7e28 = DAT_009a7e28 + f_1;
          *(float *)(&P0 + DAT_009a7e24 * 4) = DAT_009a7e28;
          DAT_009a7e24 = DAT_009a7e24 + 1;
          *(int *)(puVar6 + -0x2c) = *(int *)(puVar6 + -0x2c) + -1;
          iVar9 = *(int *)(puVar6 + -0x2c);
        }
        *(undefined4 *)(puVar6 + -0x28) = 0;
        goto LAB_00567725;
      }
      *(undefined4 *)(puVar6 + -0x30) = 0;
      break;
    }
    *(undefined4 *)(puVar6 + -0x34) = 0;
LAB_00567725:
    *(undefined4 *)(puVar6 + -0x24) = 0;
    DAT_009a7e34 = DAT_009a7e34 + 1;
    *(int *)(puVar6 + -0x38) = *(int *)(puVar6 + -0x38) + -1;
  } while (0 < *(int *)(puVar6 + -0x38));
  DAT_009a7e28 = P2;
  ffree(fVar12);
  fVar12 = (float10)thunk_FUN_0054c590(&P1,&DAT_020b9508,&DAT_00769f44);
  DAT_009a7e28 = f_0;
  DAT_009a7e44 = 1;
  _DAT_009a7e3c = P1;
  if (P1 != f_0) goto LAB_00567826;
  *(undefined4 *)(puVar6 + -0x20) = 0;
  goto LAB_00566d7d;
}


