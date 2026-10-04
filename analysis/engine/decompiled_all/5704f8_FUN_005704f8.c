// FUN_005704f8 @ 005704f8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005704f8(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  unkbyte10 in_ST0;
  float10 fVar4;
  unkbyte10 Var5;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  int local_88;
  
  puVar3 = &stack0xfffffffc;
  DAT_01be1800 = P5;
  DAT_01cadce0 = DAT_00791444;
  if (P5 == f_0) {
    P5 = f_1;
  }
  DAT_01be1804 = P6;
  ffree(in_ST0);
  fVar4 = (float10)amod(&P6,&DAT_0076a458);
  P6 = (float)fVar4;
  if (P6 == f_0) {
    P6 = f_1;
  }
  P48 = P6;
  if (IP1 == 0x10) {
    DAT_009a83b4 = (&ITEM_PTR0)[ITEM_I];
    if (*(float *)(&ITEM_P14 + DAT_009a83b4 * 4) == f_m1) {
      DAT_01cadce0 = 0x11;
    }
    else {
      DAT_01cadce0 = 0xe;
    }
    _DAT_01cadcf8 = (&ITEM_PTR0)[ITEM_I] + DAT_01cadce0;
    ffree(extraout_ST1);
    fVar4 = (float10)thunk_FUN_0042fa58(&ITEM_LEN + _DAT_01cadcf8,4,&IP12);
    if (P14 == f_m1) {
      _DAT_01cadcf8 = _DAT_01cadcf8 + -3;
    }
    *(float *)(&DAT_02053438 + _DAT_01cadcf8 * 4) = P13;
    DAT_01cadce8 = DAT_01caea40;
    local_88 = 0x1ff;
    DAT_01cadce0 = 2;
    do {
      iVar2 = (&DAT_01caea3c)[DAT_01cadce0];
      iVar1 = DAT_01cadce8;
      if (((999 < iVar2) && (iVar2 < 0x4b0)) && (iVar1 = iVar2, DAT_01cadce8 == iVar2)) {
        DAT_01cb1068 = DAT_01cb1068 + -1;
        IP10 = DAT_01cadce0;
        for (iVar2 = (DAT_01cb1068 - DAT_01cadce0) + 1; iVar1 = DAT_01cadce8, 0 < iVar2;
            iVar2 = iVar2 + -1) {
          *(undefined4 *)(&DAT_01cadd3c + IP10 * 4) = (&DAT_01cadd40)[IP10];
          (&DAT_01caea3c)[IP10] = (&DAT_01caea40)[IP10];
          IP10 = IP10 + 1;
        }
      }
      DAT_01cadce8 = iVar1;
      if (DAT_01cb1068 <= DAT_01cadce0) break;
      DAT_01cadce0 = DAT_01cadce0 + 1;
      local_88 = local_88 + -1;
    } while (0 < local_88);
  }
  else {
    ffree(extraout_ST1);
    fVar4 = (float10)thunk_FUN_0042fa58(&DAT_020b8ea0,1,&DAT_01cb1068);
  }
  if (P11 != f_0) {
    X_POS = P11 * f_150 + X_POS;
  }
  _DAT_009a83b0 = X_POS;
  _DAT_01cadd20 = f_0;
  if (P5 != f_1) {
    DAT_01cadce8 = -1;
    _DAT_01cadcf8 = 1;
    for (iVar2 = DAT_01cb1068; 0 < iVar2; iVar2 = iVar2 + -1) {
      if (*(float *)(&DAT_01cadd3c + _DAT_01cadcf8 * 4) != f_0) {
        DAT_01cadce8 = DAT_01cadce8 + 1;
      }
      _DAT_01cadcf8 = _DAT_01cadcf8 + 1;
    }
    if (0 < DAT_01cadce8) {
      fVar4 = (float10)P13 - (float10)P13 / (float10)P5;
      _DAT_01cadd20 = (float)(fVar4 / (float10)DAT_01cadce8);
      _DAT_01cadcf8 = 1;
      iVar2 = DAT_01cb1068;
      while (iVar2 = iVar2 + -1, 0 < iVar2) {
        if (*(float *)(&DAT_01cadd3c + _DAT_01cadcf8 * 4) != f_0) {
          *(float *)(&DAT_01cadd3c + _DAT_01cadcf8 * 4) =
               _DAT_01cadd20 + *(float *)(&DAT_01cadd3c + _DAT_01cadcf8 * 4);
        }
        _DAT_01cadcf8 = _DAT_01cadcf8 + 1;
      }
    }
  }
  DAT_01a27710 = 0;
  _DAT_009a83ac = 0;
  DAT_01cadcfc = 0;
  IP10 = 0;
  DAT_01be1808 = P7;
  if (P7 == f_0) {
    P7 = P48;
  }
  DAT_01be180c = P9;
  if (P14 == f_m1) {
    DAT_01be1810 = P17;
    DAT_01be1814 = P18;
  }
  else {
    DAT_01be1810 = P14;
    DAT_01be1814 = P15;
  }
  P6 = P6 * f_0_28;
  P7 = P7 * f_0_28;
  DAT_01cadce8 = 0;
  DAT_01cadcec = IP8;
  if (IP8 < 1000) {
    DAT_01cadcec = 0;
  }
  if (_DAT_01cadd24 != f_0) {
    _DAT_01cadd24 = _DAT_01cadd24 * f_150;
  }
  if (_DAT_01cadd20 != f_0) {
    _DAT_01cadd20 = _DAT_01cadd20 * f_150;
  }
  if (DAT_01cadcec < 0x5a) {
    if ((DAT_01cadcec < 0) && (DAT_0078b6a0 % 100 < 0x5a)) {
      DAT_01cadcec = 0;
    }
    if (DAT_01cadcec != 0) {
      ffree(fVar4);
      fVar4 = (float10)thunk_FUN_004d4ed2(&DAT_01cadcec);
    }
    if (DAT_01caea40 < 1000) {
      if ((_DAT_009a83a8 == P48) && (_DAT_009a83a4 == P7)) goto LAB_00570b79;
      ffree(fVar4);
      fVar4 = (float10)thunk_FUN_0056b845();
    }
  }
  else {
    ffree(fVar4);
    fVar4 = (float10)FUN_00571655(s_BODN0BODB0BODI0BDIB0MUSI0_007a0168,5);
  }
  _DAT_009a83a8 = P48;
  _DAT_009a83a4 = P7;
LAB_00570b79:
  _DAT_009a83a0 = NPT;
  DAT_01cadce0 = DAT_0078b6a0 % 100;
  if ((0x59 < DAT_01cadce0) && (DAT_01cadce0 < 0x5f)) {
    P14 = *(float *)(&DAT_0079ffa6 + DAT_01cadce0 * 5);
    P15 = (float)CONCAT31(P15._1_3_,(&DAT_0079ffaa)[DAT_01cadce0 * 5]);
  }
  if (DAT_01be180c != f_0) {
    ffree(fVar4);
    fVar4 = (float10)thunk_FUN_0056f14d(&DAT_01be180c);
    DAT_0078d850 = 1;
  }
  DAT_01a1c848 = 0;
  _DAT_01a1c844 = 0;
  DAT_01cadce0 = 0;
  DAT_01c6da38 = P6;
  _DAT_009a839c = X_POS;
  ffree(fVar4);
  fVar4 = (float10)FUN_005ff381(&stack0xfffffffc,0x570c4a);
  *(int *)(puVar3 + -0xb4) = (int)ROUND(fVar4);
  iVar2 = DAT_01cb1068;
  DAT_01a27708 = *(undefined4 *)(puVar3 + -0xb4);
  *(int *)(puVar3 + -0x44) = DAT_01cb1068;
  DAT_009a8398 = 1;
  Var5 = extraout_ST1_00;
  while (0 < iVar2) {
    if (*(float *)(&DAT_01cadd3c + DAT_009a8398 * 4) == f_0) {
      if (((int)(&DAT_01caea3c)[DAT_009a8398] < 10000) ||
         (999999 < (int)(&DAT_01caea3c)[DAT_009a8398])) {
        *(undefined4 *)(puVar3 + -0x3c) = 0;
      }
      else {
        *(int *)(puVar3 + -0xb4) = (&DAT_01caea3c)[DAT_009a8398] + -10000;
        _DAT_009a839c = (float)*(int *)(puVar3 + -0xb4) * f_15;
        *(undefined4 *)(puVar3 + -0x38) = 0;
      }
      *(undefined4 *)(&DAT_01cafabc + DAT_009a8398 * 4) = 0;
      if ((((int)(&DAT_01caea3c)[DAT_009a8398] < 0x7f) && ((&DAT_01caea3c)[DAT_009a8398] != 0x5e))
         && (0x52 < (int)(&DAT_01caea3c)[DAT_009a8398])) {
        *(undefined4 *)(&DAT_01cafabc + DAT_009a8398 * 4) = 0xffffffff;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x40) = 0;
      _DAT_009a8394 = *(float *)(&DAT_01cadd3c + DAT_009a8398 * 4);
      iVar2 = DAT_009a8398 * 4;
      ffree(Var5);
      fVar4 = (float10)FUN_005ff381(puVar3,0x570cd4);
      *(int *)(puVar3 + -0xb4) = (int)ROUND(fVar4);
      *(undefined4 *)(&DAT_01cafabc + iVar2) = *(undefined4 *)(puVar3 + -0xb4);
      if (*(int *)(&DAT_01cafabc + DAT_009a8398 * 4) == 0) {
        *(undefined4 *)(&DAT_01cafabc + DAT_009a8398 * 4) = 0xd431;
      }
      _DAT_009a839c = _DAT_009a8394 * f_150 + _DAT_009a839c;
      *(undefined4 *)(puVar3 + -0x34) = 0;
      Var5 = extraout_ST1_01;
    }
    *(undefined4 *)(&DAT_01cb02bc + DAT_009a8398 * 4) = DAT_01a27708;
    DAT_009a8398 = DAT_009a8398 + 1;
    *(int *)(puVar3 + -0x44) = *(int *)(puVar3 + -0x44) + -1;
    iVar2 = *(int *)(puVar3 + -0x44);
  }
  *(int *)(puVar3 + -0x30) = DAT_01cb1068;
  DAT_009a8398 = 1;
  iVar2 = DAT_01cb1068;
  while (0 < iVar2) {
    if ((DAT_01cadcec != 0) && (*(int *)(&DAT_01cafabc + DAT_009a8398 * 4) == 0)) {
      (&DAT_01caea3c)[DAT_009a8398] = DAT_01cadcec;
    }
    if (*(int *)(&DAT_01cafabc + DAT_009a8398 * 4) == 0xd431) {
      *(undefined4 *)(&DAT_01cafabc + DAT_009a8398 * 4) = 0;
    }
    *(undefined4 *)(puVar3 + -0x2c) = 0;
    DAT_009a8398 = DAT_009a8398 + 1;
    *(int *)(puVar3 + -0x30) = *(int *)(puVar3 + -0x30) + -1;
    iVar2 = *(int *)(puVar3 + -0x30);
  }
  do {
    DAT_01cadce0 = DAT_01cadce0 + 1;
    DAT_01cadce4 = (&DAT_01caea3c)[DAT_01cadce0];
    if (999999 < DAT_01cadce4) {
      DAT_01cadce4 = 0x403;
    }
    if (DAT_01cadcec == 0) {
      *(undefined4 *)(puVar3 + -0x28) = 0;
    }
    else if (9999 < DAT_01cadce4) {
      *(undefined4 *)(puVar3 + -0x24) = 0;
    }
    DAT_01a1c840 = DAT_0078b6a0 % 100;
    if (DAT_01a1c840 == 99) {
      *(undefined4 *)(puVar3 + -0x20) = 0;
      *(undefined4 *)(puVar3 + -0x14) = 0;
      *(undefined4 *)(puVar3 + -0x10) = 0;
LAB_00570f63:
      ffree(Var5);
      Var5 = FUN_00571059(s_BODN0BODB0BODI0BDIB0MUSI0_007a0168,5);
      *(undefined4 *)(puVar3 + -0x18) = 0;
    }
    else {
      if (DAT_01a1c840 < 0x5a) goto LAB_00570f63;
      *(undefined4 *)(puVar3 + -0x1c) = 0;
      ffree(Var5);
      Var5 = FUN_005713d0(s_BODN0BODB0BODI0BDIB0MUSI0_007a0168,5);
    }
    if (DAT_01cb1068 <= DAT_01cadce0) {
      if (IP1 != 0x10) {
        P5 = DAT_01be1800;
      }
      P6 = DAT_01be1804;
      P7 = DAT_01be1808;
      if (P14 == f_m1) {
        P17 = DAT_01be1810;
        P18 = DAT_01be1814;
      }
      else {
        P14 = DAT_01be1810;
        P15 = DAT_01be1814;
      }
      if ((DAT_01cadcec == 0) || (0x59 < DAT_01cadcec)) {
        *(undefined4 *)(puVar3 + -8) = 0;
      }
      else {
        ffree(Var5);
        Var5 = thunk_FUN_004d4f3f();
        *(undefined4 *)(puVar3 + -4) = 0;
      }
      if (P14 == f_m1) {
        DAT_00791444 = -1;
      }
      ffree(Var5);
      return;
    }
    *(undefined4 *)(puVar3 + -0xc) = 0;
  } while( true );
}


