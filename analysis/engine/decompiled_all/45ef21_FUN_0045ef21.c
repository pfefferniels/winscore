// FUN_0045ef21 @ 0045ef21 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Heritage AFTER dead removal. Example location: r0x01c58948 : 0x0046662a */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_0045ef21(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  undefined2 in_FPUControlWord;
  undefined2 uVar7;
  unkbyte10 in_ST0;
  unkbyte10 Var8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST0;
  float10 fVar11;
  float10 fVar12;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 extraout_ST1_03;
  float10 extraout_ST1_04;
  float10 extraout_ST1_05;
  float10 extraout_ST1_06;
  float10 extraout_ST1_07;
  float10 extraout_ST1_08;
  float10 extraout_ST1_09;
  float10 extraout_ST1_10;
  float10 extraout_ST1_11;
  unkbyte10 extraout_ST1_12;
  unkbyte10 extraout_ST1_13;
  unkbyte10 extraout_ST1_14;
  float10 extraout_ST1_15;
  float10 extraout_ST1_16;
  float10 extraout_ST1_17;
  float10 extraout_ST1_18;
  float10 extraout_ST1_19;
  float10 extraout_ST1_20;
  float10 extraout_ST1_21;
  float10 extraout_ST1_22;
  undefined4 local_5e4;
  undefined4 local_5e0;
  uint *local_5dc;
  undefined4 local_5d0 [371];
  
  puVar3 = &stack0xfffffffc;
  ffree(in_ST0);
  Var8 = FUN_0046808e();
  _DAT_008244dc = 0;
  DAT_01c6da40 = 0;
  DAT_009a9494 = 0;
  if ((short)DAT_009ae2bc == 0x7e7e) {
    _DAT_008244dc = 0xffffffff;
    local_5d0[0] = 0;
    local_5e4 = 3;
    local_5e0 = 0x9ae2be;
    local_5dc = &DAT_020527cc;
    ffree(Var8);
    FUN_005f9240(local_5d0,0x784ff00,&DAT_00761c4c,&local_5e4,&DAT_007909e0);
    if ((0x24 < (int)DAT_020527cc) && ((int)DAT_020527cc < 0x29)) {
      _DAT_008244dc = 1;
    }
  }
  fVar9 = (float10)FUN_005f34d1(&stack0xfffffffc,0x45f000);
  fVar1 = DAT_020b9440;
  if (EDIT_ITEM == 0) {
    _DAT_008244d0 = 0;
  }
  if (((((_DAT_020b8ea0 & 0xffff) == 0x4444) || ((_DAT_020b8ea0 & 0xffff) == 0x5555)) ||
      ((_DAT_020b8ea0 & 0xffff) == 0x4c4c)) || ((_DAT_020b8ea0 & 0xffff) == 0x5252)) {
    *(undefined4 *)(puVar3 + -0x5a8) = 0;
LAB_00467bcb:
    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) != &DAT_00544444) {
      if ((_DAT_020b8ea0 & 0xffffff) != 0x504952) {
        ffree(fVar9);
        fVar9 = (float10)FUN_004681c0(&DAT_008244dc);
      }
LAB_00467f66:
      if (_DAT_020b90a0 >> 8 != 0x303131) {
        *(undefined4 *)(puVar3 + -0x408) = 0;
        goto LAB_00467fb8;
      }
      DAT_01c58944 = f_110;
      *(undefined4 *)(puVar3 + -0x40c) = 0;
      goto LAB_00467f93;
    }
    *(undefined4 *)(puVar3 + -0x410) = 0;
LAB_00467bf0:
    if ((DAT_020b8e50 != 2) || ((_DAT_020b8ea0 & 0xffff) != 0x5743)) {
      ffree(fVar9);
      fVar9 = (float10)thunk_FUN_004359d0();
      *(undefined4 *)(puVar3 + -0x3a8) = 0;
      goto LAB_00467fb8;
    }
    *(undefined4 *)(puVar3 + -0x3ac) = 0;
LAB_00467c1e:
    DAT_008244ac = (&ITEM_PTR0)[EDIT_ITEM];
    fVar1 = (float)(&ITEM_LEN)[DAT_008244ac];
    *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
    *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
    DAT_01cb1068 = *(int *)(puVar3 + -0x5d0);
    ffree(fVar9);
    fVar9 = (float10)thunk_FUN_0042c9b0(&DAT_008244ac,&DAT_01cb1068);
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4e) {
      *(undefined4 *)(puVar3 + -0xd8) = 0;
      if (DAT_01c6da40 == -1) {
        DAT_01c6da40 = 1;
        if (*(float *)(&ITEM_P14 + (&ITEM_PTR0)[DAT_01caf688] * 4) == f_m1) {
          DAT_00824478 = 0x11;
        }
        else {
          DAT_00824478 = 0xe;
        }
        DAT_008244a8 = DAT_00824478 + (&ITEM_PTR0)[DAT_01caf688];
        P48 = DAT_020b9454;
        if (P5 == f_0) {
          P5 = f_1;
        }
        ffree(fVar9);
        thunk_FUN_0042fa58(&ITEM_LEN + DAT_008244a8,4,&IP12);
        P2 = DAT_01caf68c;
        DAT_008244ec = (&DAT_01caea3c)[DAT_01cb1068];
        DAT_00824474 = DAT_01caea44;
        _DAT_00824470 = f_0;
        if ((((DAT_008244ec == 0x4e) || (DAT_008244ec == 0x4c)) || (DAT_008244ec == 0x24)) ||
           ((DAT_008244ec == 0x25 || ((int)DAT_008244ec < 0x46 && 0x41 < (int)DAT_008244ec)))) {
          _DAT_00824470 = *(float *)(&DAT_01cadd3c + DAT_01cb1068 * 4) / f_2;
        }
        if (((DAT_01caea44 == 0x4e) || (DAT_01caea44 == 0x80)) || (DAT_01caea44 == 0x68)) {
          _DAT_00824470 = _DAT_00824470 - DAT_01cadd44 / f_2;
        }
      }
      else {
        *(undefined4 *)(puVar3 + -0x148) = 0;
      }
      DAT_01c58948 = STEP * f_0_064 - P6;
      if (DAT_01c6da40 == 1) {
        DAT_01c58948 = _DAT_00824470 + DAT_01c58948;
        DAT_01c6da40 = 0;
      }
      DAT_01c58928 = P2;
LAB_00467e94:
      fVar9 = (float10)FUN_005f34d1(puVar3,0x467eb1);
LAB_00467eb5:
      *(undefined4 *)(puVar3 + -0x130) = 0;
      goto LAB_00467f93;
    }
    *(undefined4 *)(puVar3 + -0xd4) = 0;
LAB_00467ece:
    _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00761b88);
    *(undefined4 *)(puVar3 + -0x4d0) = 0;
    goto LAB_00467ee8;
  }
  if (DAT_020b8ea0._1_1_ < '\x0e') {
    DAT_020b8ea0 = CONCAT11(0x20,(char)DAT_020b8ea0);
  }
  if (DAT_020b8ea2 < '\x0e') {
    _DAT_020b8ea0 = CONCAT12(DAT_00761c44,DAT_020b8ea0);
  }
  DAT_008244ec = _DAT_020b8ea0 & 0xff;
  DAT_008244f0 = _DAT_020b8ea0 >> 8 & 0xff;
  DAT_020527cc = _DAT_020b8ea0 >> 0x10 & 0xff;
  *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
  *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
  *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
  fVar1 = P2;
  in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
  DAT_020b8e50 = *(int *)(puVar3 + -0x5d0);
  if (EDIT_ITEM == 0) {
    DAT_020b8e50 = 0;
  }
  if (((P2 < f_19) && ((_DAT_020b8ea0 >> 8 & 0xff) != 0x4e)) && ((_DAT_020b8ea0 & 0xff) == 0x42)) {
    *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
    *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
    fVar1 = DAT_01c58924;
    iVar2 = *(int *)(puVar3 + -0x5d0);
    *(undefined2 *)(puVar3 + -0x5d4) = *(undefined2 *)(puVar3 + -0x5d4);
    *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
    *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
    fVar9 = (float10)*(float *)(&DAT_020b943c + *(int *)(puVar3 + -0x5d0) * 4);
    *(float *)(&DAT_01c5891c + iVar2 * 4) = (float)-fVar9;
    *(undefined4 *)(puVar3 + -0x5a4) = 0;
    goto LAB_00467f9e;
  }
  if ((((_DAT_020b8ea0 & 0xffff) == 0x4445) || (DAT_020b8e50 != 9)) || (P2 != f_0)) {
    *(undefined4 *)(puVar3 + -0x5a0) = 0;
    goto LAB_0045fa18;
  }
  if (0x16 < (int)(char)DAT_020b8ea0 - 0x41U) {
    *(undefined4 *)(puVar3 + -0x59c) = 0;
    goto LAB_0045fa18;
  }
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch((char)DAT_020b8ea0) {
  case '\0':
  case '\x01':
  case '\x02':
  case '\x03':
LAB_0045fc4a:
    if (DAT_0205274c == 0) {
      FUN_005f33c9(puVar3,&LAB_0045feb9);
      Var8 = FUN_005f34d1(puVar3,&LAB_0045fed4);
      ffree(Var8);
      fVar9 = (float10)thunk_FUN_005960f0(&DAT_020b8ea0);
      *(undefined4 *)(puVar3 + -0x4c0) = 0;
LAB_00460d1c:
      P1 = f_1;
      P2 = (float)DAT_020b8e50;
      *(undefined4 *)(puVar3 + -0x10) = 0;
      goto LAB_00467fb8;
    }
    *(undefined4 *)(puVar3 + -0x4c4) = 0;
    DAT_01be6d60 = 2;
    DAT_008244b8 = P2;
    P1 = f_1;
    P2 = DAT_020b9440;
    P3 = f_0;
    DAT_008244e4 = _DAT_020b8ea0;
    ffree(fVar9);
    Var8 = thunk_FUN_00449ea8(&DAT_01cb1068);
    ITEM_WORDS = DAT_020b8e44;
    *(int *)(puVar3 + -0x5d0) = EDIT_ITEM + 1;
    DAT_008244b4 = (float)*(int *)(puVar3 + -0x5d0);
    _DAT_020b8ea0 = DAT_008244e4;
    if ((DAT_0078b370 != 1) && ((DAT_008244e4 >> 8 & 0xff) == 0x58)) {
      *(int *)(puVar3 + -0x5d0) = EDIT_ITEM + -1;
      DAT_008244b4 = (float)*(int *)(puVar3 + -0x5d0);
    }
    if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x2a) {
      DAT_008244b4 = DAT_008244b8;
    }
    EDIT_ITEM = 0;
    DAT_0078dc45 = 0;
    if (((_DAT_020b8ea0 >> 8 & 0xff) != 0x20) && (P2 != f_0 || (_DAT_020b8ea0 >> 8 & 0xff) != 0x2a))
    {
      if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x43) {
        *(int *)(puVar3 + -0x5d0) = ITEM_I + 1;
        DAT_008244b4 = (float)*(int *)(puVar3 + -0x5d0);
      }
      ffree(Var8);
      Var8 = thunk_FUN_0047766d();
      ffree(Var8);
      draw_items();
      P2 = DAT_008244b4;
      FUN_005f33c9(puVar3,&LAB_0045fe11);
      fVar9 = (float10)FUN_005f34d1(puVar3,&LAB_0045fe2c);
      _DAT_020b8ea0 = CONCAT12(DAT_00761b7e,DAT_00761b7c);
      DAT_0078b4e4 = 0;
      DAT_0205274c = 0;
      *(undefined4 *)(puVar3 + -0x4b8) = 0;
      goto LAB_00467ee8;
    }
    *(undefined4 *)(puVar3 + -0x4bc) = 0;
    ffree(Var8);
    fVar9 = (float10)draw_items();
    DAT_020527e8 = ITEM_I;
    DAT_0205274c = 0;
    *(undefined4 *)(puVar3 + -0x4b4) = 0;
    goto LAB_0046190d;
  case '\x04':
  case '\x05':
  case '-':
  case '=':
LAB_00461690:
    DAT_01be6d60 = 2;
    ffree(fVar9);
    Var8 = thunk_FUN_00597b60(0xffffffff);
    if (DAT_0205274c != 0) {
      ffree(Var8);
      Var8 = thunk_FUN_00473228(&EDIT_ITEM);
    }
    if (0 < DAT_0205274c) {
      DAT_008244b4 = P2;
      DAT_020527c0 = (&ITEM_PTR0)[EDIT_ITEM];
      ffree(Var8);
      Var8 = thunk_FUN_00476628();
      P2 = DAT_008244b4;
      DAT_0205274c = 0;
      DAT_0078b4f0 = 1;
      ffree(Var8);
      thunk_FUN_00495d4f(&DAT_0078b510,0x80);
    }
    DAT_0078dc45 = 0;
    DAT_020b9440 = f_0;
    FUN_005f33c9(puVar3,0x46175d);
    fVar9 = (float10)FUN_005f34d1(puVar3,0x461778);
    DAT_00790d70 = 0;
    _DAT_008244d0 = 0;
    DAT_008244cc = f_0;
    goto LAB_00461798;
  case '\x06':
  case '\a':
code_r0x0045fefb:
    if ((EDIT_ITEM == 0) && (P2 == f_0)) {
      P2 = (float)(&ITEM_P3)[(&ITEM_PTR0)[DAT_020527e8]];
    }
    ffree(fVar9);
    fVar9 = (float10)thunk_FUN_00597b60(0xffffffff);
    fVar1 = P3;
    DAT_0171b230 = 0;
    DAT_008244cc = P2;
    if (P2 == f_0) {
      DAT_008244cc = DAT_020b9448;
    }
    DAT_020527e4 = P2;
    *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
    *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
    in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
    DAT_01fbb770 = *(int *)(puVar3 + -0x5d0);
    if (DAT_01fbb770 == 0) {
      DAT_01fbb770 = 9999;
    }
    if (EDIT_ITEM == 0) {
      *(undefined4 *)(puVar3 + -0x49c) = 0;
    }
    else {
      if (DAT_0205274c != 0) {
        *(undefined4 *)(puVar3 + -0x498) = 0;
        goto code_r0x00460ca3;
      }
      if (DAT_020527e4 == f_0) {
        DAT_008244ac = (&ITEM_PTR0)[EDIT_ITEM];
        DAT_020527e4 = (float)(&ITEM_P3)[DAT_008244ac];
      }
    }
    goto code_r0x00460d6a;
  case '\b':
  case '\x1a':
  case '\x1e':
  case '2':
  case '?':
    goto LAB_00462bbf;
  case '\t':
  case '\n':
  case ',':
code_r0x00460047:
    fVar1 = P2;
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x58) {
      P5 = P4;
      P4 = P3;
      P3 = P2;
      P2 = _UNK_00761b54;
      if (fVar1 == f_0) {
        P3 = (float)(&ITEM_P1)[(&ITEM_PTR0)[DAT_020527e8]];
      }
    }
    ffree(fVar9);
    fVar9 = (float10)thunk_FUN_00597b60(0xffffffff);
    fVar1 = P2;
    DAT_0171b230 = 0;
    if (P2 == f_0) {
      DAT_008244ac = (&ITEM_PTR0)[DAT_020527e8];
      fVar1 = (float)(&ITEM_P2)[DAT_008244ac];
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
      DAT_01fbb770 = *(int *)(puVar3 + -0x5d0);
      P3 = (float)(&ITEM_P1)[DAT_008244ac];
      *(undefined4 *)(puVar3 + -0x460) = 0;
    }
    else {
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
      DAT_01fbb770 = *(int *)(puVar3 + -0x5d0);
      if (EDIT_ITEM == 0) {
        *(undefined4 *)(puVar3 + -0x45c) = 0;
      }
      else {
        if (DAT_0205274c != 0) {
          *(undefined4 *)(puVar3 + -0x458) = 0;
          goto code_r0x00460ca3;
        }
        if (DAT_01fbb770 == 0) {
          DAT_008244ac = (&ITEM_PTR0)[EDIT_ITEM];
          fVar1 = (float)(&ITEM_P2)[DAT_008244ac];
          *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
          *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
          DAT_01fbb770 = *(int *)(puVar3 + -0x5d0);
          if (P3 == f_0) {
            P3 = (float)(&ITEM_P1)[DAT_008244ac];
          }
        }
      }
    }
    DAT_01fbb760 = 1;
    DAT_008244a0 = DAT_01fbb770 % 1000;
    _DAT_01fbb764 = P3;
    _DAT_01fbb768 = P4;
    _DAT_01fbb76c = P5;
    _DAT_00824494 = P6;
    _DAT_00824490 = P7;
    _DAT_0082448c = P8;
    DAT_0078b370 = 1;
    _DAT_008244d0 = 1;
    DAT_008244f0 = 1;
    DAT_008244a8 = ITEM_I;
    DAT_008244a4 = 1;
    goto LAB_0046093f;
  case '\v':
  case '0':
  case '1':
  case ':':
LAB_004602fc:
    if (DAT_0205274c != 0) {
      FUN_005f33c9(puVar3,&LAB_004604ee);
      Var8 = FUN_005f34d1(puVar3,&LAB_00460509);
      ffree(Var8);
      fVar9 = (float10)thunk_FUN_005960f0(&DAT_020b8ea0);
      *(undefined4 *)(puVar3 + -0x42c) = 0;
      goto LAB_00460d1c;
    }
    *(undefined4 *)(puVar3 + -0x430) = 0;
    if (((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4e) || ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x42)) {
      _DAT_01fbb764 = (float)(&ITEM_P1)[(&ITEM_PTR0)[EDIT_ITEM]];
      fVar1 = (float)(&ITEM_P2)[(&ITEM_PTR0)[EDIT_ITEM]];
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
      DAT_01fbb760 = 1;
      DAT_008244c8 = EDIT_ITEM;
      DAT_01fbb770 = 1;
      DAT_008244a0 = 999;
      DAT_0078b370 = 1;
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x42) {
        DAT_0078b370 = -1;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x428) = 0;
    }
    ffree(fVar9);
    Var8 = thunk_FUN_0045deb2(&EDIT_ITEM);
    ffree(Var8);
    Var8 = thunk_FUN_0054cd13(&DAT_020b9440,&DAT_00761b50);
    DAT_020527e8 = EDIT_ITEM;
    DAT_0078b4f0 = 1;
    ffree(Var8);
    fVar9 = (float10)thunk_FUN_00495d4f(&DAT_0078b510,0x80);
    if (DAT_0078b370 == 1) {
      EDIT_ITEM = EDIT_ITEM + -1;
    }
    DAT_008244c8 = EDIT_ITEM;
    if (ITEM_I == DAT_020527e8) {
      DAT_020527e8 = DAT_020527e8 - 1;
    }
    DAT_0078dc45 = 0;
    DAT_0078b4e0 = 0;
    if (DAT_0078b370 == 1) {
      *(undefined4 *)(puVar3 + -0x424) = 0;
      goto LAB_004606ae;
    }
    *(undefined4 *)(puVar3 + -0x420) = 0;
    goto LAB_004608c9;
  default:
code_r0x00461c81:
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x4f) {
      if ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x42) {
        if ((_DAT_020b8ea0 >> 0x10 & 0xff) != 0x52) goto LAB_00467bcb;
        *(undefined4 *)(puVar3 + -0x414) = 0;
        goto LAB_0046327b;
      }
      *(undefined4 *)(puVar3 + -0x418) = 0;
      goto LAB_0046392a;
    }
    *(undefined4 *)(puVar3 + -0x41c) = 0;
  case '[':
  case '\\':
  case ']':
LAB_00462a86:
    if ((_DAT_020b8ea0 & 0xff) == 0x54) {
      if (((_DAT_020b8ea0 >> 8 & 0xff) == 0x48) ||
         ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_004d5254)) {
        *(undefined4 *)(puVar3 + -0x398) = 0;
      }
      else if ((DAT_020b8e50 == 5) &&
              ((_DAT_020b8ea0 & 0xffffff) == 0x505254 || (_DAT_020b8ea0 & 0xffffff) == 0x454954)) {
        *(undefined4 *)(puVar3 + -0x394) = 0;
      }
      else {
        if ((DAT_020b8e50 != 6) || ((_DAT_020b8ea0 & 0xffff) != 0x4d54)) {
LAB_004673f4:
          ffree(fVar9);
          fVar9 = (float10)thunk_FUN_0054d7d4(&DAT_020b8ea0,3);
          DAT_0078b4e0 = 9999;
          DAT_009a9494 = 99;
          *(undefined4 *)(puVar3 + -0x38c) = 0;
          goto LAB_00467fb8;
        }
        *(undefined4 *)(puVar3 + -0x390) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x39c) = 0;
    }
    ffree(fVar9);
    fVar9 = (float10)thunk_FUN_0043d0b0();
    if (DAT_0078b4e0 != -99) {
      *(undefined4 *)(puVar3 + -0x388) = 0;
      goto LAB_00467fb8;
    }
    P2 = (float)EDIT_ITEM;
    DAT_0078b4e0 = 2;
    DAT_0205274c = 0;
    if (DAT_01fbb760 == 0) {
      *(undefined4 *)(puVar3 + -900) = 0;
      goto LAB_00462bbf;
    }
    *(undefined4 *)(puVar3 + -0x380) = 0;
    goto LAB_00462db2;
  case '\x18':
  case '\x19':
  case '&':
    goto LAB_00467f66;
  case '\x1b':
  case '/':
code_r0x00460781:
    if (0 < DAT_0205274c) {
      ffree(fVar9);
      Var8 = thunk_FUN_00473228(&EDIT_ITEM);
      DAT_020527c0 = (&ITEM_PTR0)[EDIT_ITEM];
      ffree(Var8);
      Var8 = thunk_FUN_00476628();
      ffree(Var8);
      fVar9 = (float10)thunk_FUN_00495d4f(&DAT_0078b510,0x80);
      DAT_0205274c = 0;
      _DAT_020b8ea0 =
           CONCAT22(_DAT_020b8ea2,CONCAT11((char)(_DAT_020b90a0 >> 8),(char)DAT_020b8ea0));
      DAT_0078b4f0 = 0;
    }
    DAT_0078dc45 = 0;
    if (_DAT_008244d0 == 0) {
      DAT_01fbb760 = 0;
    }
    if (DAT_0078b4e4 == 0x5a) {
      _DAT_01fbb764 = (float)(&ITEM_P1)[(&ITEM_PTR0)[EDIT_ITEM]];
      fVar1 = (float)(&ITEM_P2)[(&ITEM_PTR0)[EDIT_ITEM]];
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
      DAT_01fbb760 = 1;
      DAT_008244c8 = EDIT_ITEM;
      DAT_01fbb770 = 1;
      DAT_008244a0 = 999;
    }
    else {
      *(undefined4 *)(puVar3 + -0x3e4) = 0;
    }
    DAT_0078b370 = -1;
LAB_004608c9:
    if (DAT_01fbb760 != 0) {
      *(undefined4 *)(puVar3 + -0x3e0) = 0;
      DAT_008244f0 = DAT_008244c8 - 1;
      if (0 < (int)DAT_008244f0) {
        DAT_008244a8 = 1;
        DAT_008244a4 = -1;
        if (DAT_01fbb760 != 2) {
          *(undefined4 *)(puVar3 + -0x3cc) = 0;
LAB_0046093f:
          DAT_008244c8 = DAT_008244f0;
          iVar2 = DAT_008244a8;
          *(int *)(puVar3 + -0x454) = DAT_008244a4;
          iVar2 = (int)((iVar2 - DAT_008244f0) + DAT_008244a4) / DAT_008244a4;
          *(int *)(puVar3 + -0x450) = iVar2;
          while (0 < iVar2) {
            DAT_008244ac = (&ITEM_PTR0)[DAT_008244c8];
            fVar1 = (float)(&ITEM_P2)[DAT_008244ac];
            *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
            *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
            DAT_00824498 = *(int *)(puVar3 + -0x5d0);
            if ((DAT_01fbb770 < 0x3e9) || (DAT_00824498 < DAT_008244a0)) {
              if ((DAT_008244a0 == 0) ||
                 ((DAT_00824498 == DAT_008244a0 || (MAX_STAFF < DAT_008244a0)))) goto LAB_00460a34;
              *(undefined4 *)(puVar3 + -0x448) = 0;
            }
            else {
              *(undefined4 *)(puVar3 + -0x44c) = 0;
LAB_00460a34:
              DAT_008244b4 = (float)(&ITEM_P1)[DAT_008244ac];
              if (DAT_008244b4 == f_0) {
                *(undefined4 *)(puVar3 + -0x444) = 0;
              }
              else {
                if ((((((_DAT_0082448c == DAT_008244b4) || (_DAT_00824490 == DAT_008244b4)) ||
                      (_DAT_00824494 == DAT_008244b4)) ||
                     ((_DAT_01fbb76c == DAT_008244b4 || (_DAT_01fbb768 == DAT_008244b4)))) ||
                    (_DAT_01fbb764 == f_0)) || (_DAT_01fbb764 == DAT_008244b4)) goto LAB_0046103e;
                *(undefined4 *)(puVar3 + -0x440) = 0;
              }
            }
            *(undefined4 *)(puVar3 + -0x438) = 0;
            DAT_008244c8 = *(int *)(puVar3 + -0x454) + DAT_008244c8;
            *(int *)(puVar3 + -0x450) = *(int *)(puVar3 + -0x450) + -1;
            iVar2 = *(int *)(puVar3 + -0x450);
          }
          P2 = f_0;
          *(undefined4 *)(puVar3 + -0x434) = 0;
          goto LAB_00461798;
        }
        *(undefined4 *)(puVar3 + -0x3d0) = 0;
        goto LAB_00460e34;
      }
      *(undefined4 *)(puVar3 + -0x3d4) = 0;
      goto LAB_00461798;
    }
    EDIT_ITEM = EDIT_ITEM + -1;
    if (0 < EDIT_ITEM) {
LAB_00461070:
      *(undefined4 *)(puVar3 + -0x3d8) = 0;
      goto LAB_00462d49;
    }
    *(undefined4 *)(puVar3 + -0x3dc) = 0;
    goto LAB_004617c9;
  case '\x1c':
  case '>':
code_r0x00460c8c:
    if (DAT_0205274c != 0) {
      *(undefined4 *)(puVar3 + -0x3bc) = 0;
code_r0x00460ca3:
      FUN_005f33c9(puVar3,&UNK_00460cc1);
      Var8 = FUN_005f34d1(puVar3,&UNK_00460cdc);
      ffree(Var8);
      thunk_FUN_005960f0(&DAT_020b8ea0);
      fVar9 = (float10)FUN_005f34d1(puVar3,&UNK_00460d11);
      *(undefined4 *)(puVar3 + -4) = 0;
      goto LAB_00460d1c;
    }
    DAT_008244cc = DAT_020b9448;
    DAT_020527e4 = DAT_020b9448;
    DAT_01fbb770 = 0;
    *(undefined4 *)(puVar3 + -0x3b8) = 0;
code_r0x00460d6a:
    DAT_008244f0 = 1;
    DAT_008244a8 = ITEM_I;
    DAT_008244a4 = 1;
    DAT_008244a0 = DAT_01fbb770 % 1000;
    DAT_01fbb760 = 2;
    _DAT_01fbb764 = P4;
    _DAT_01fbb768 = P5;
    _DAT_01fbb76c = P6;
    _DAT_008244d0 = 1;
    DAT_0078b370 = 1;
    fVar1 = (float)(&ITEM_P2)[(&ITEM_PTR0)[EDIT_ITEM]];
    *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
    *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
    in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
    DAT_0082449c = *(int *)(puVar3 + -0x5d0);
LAB_00460e34:
    DAT_008244c8 = DAT_008244f0;
    iVar2 = DAT_008244a8;
    *(int *)(puVar3 + -0x494) = DAT_008244a4;
    iVar2 = (int)((iVar2 - DAT_008244f0) + DAT_008244a4) / DAT_008244a4;
    *(int *)(puVar3 + -0x490) = iVar2;
    while (0 < iVar2) {
      DAT_008244ac = (&ITEM_PTR0)[DAT_008244c8];
      fVar1 = (float)(&ITEM_P2)[DAT_008244ac];
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
      DAT_00824498 = *(int *)(puVar3 + -0x5d0);
      if (DAT_0082449c < 0xc9) {
        if (200 < DAT_00824498) {
          *(undefined4 *)(puVar3 + -0x48c) = 0;
          goto LAB_00460ffa;
        }
LAB_00460f13:
        if ((DAT_01fbb770 < 0x3e9) || (DAT_00824498 < DAT_008244a0)) {
          if ((DAT_008244a0 != 0) && ((DAT_00824498 != DAT_008244a0 && (DAT_008244a0 <= MAX_STAFF)))
             ) {
            *(undefined4 *)(puVar3 + -0x480) = 0;
            goto LAB_00460ffa;
          }
        }
        else {
          *(undefined4 *)(puVar3 + -0x484) = 0;
        }
        if (f_5 < ABS(DAT_020527e4 - (float)(&ITEM_P3)[DAT_008244ac])) {
          *(undefined4 *)(puVar3 + -0x47c) = 0;
          goto LAB_00460ffa;
        }
        DAT_008244b4 = (float)(&ITEM_P1)[DAT_008244ac];
        if ((((DAT_008244b4 != _DAT_01fbb76c) && (DAT_008244b4 != _DAT_01fbb768)) &&
            (_DAT_01fbb764 != f_0)) && (DAT_008244b4 != _DAT_01fbb764)) goto LAB_00460ffa;
        *(undefined4 *)(puVar3 + -0x478) = 0;
LAB_0046103e:
        EDIT_ITEM = DAT_008244c8;
        DAT_0078dc45 = 0;
        ffree(fVar9);
        fVar9 = (float10)thunk_FUN_00473cdd(&DAT_00761b84);
        *(undefined4 *)(puVar3 + -0x43c) = 0;
        goto LAB_00461070;
      }
      if (200 < DAT_00824498) goto LAB_00460f13;
      *(undefined4 *)(puVar3 + -0x488) = 0;
LAB_00460ffa:
      *(undefined4 *)(puVar3 + -0x474) = 0;
      DAT_008244c8 = *(int *)(puVar3 + -0x494) + DAT_008244c8;
      *(int *)(puVar3 + -0x490) = *(int *)(puVar3 + -0x490) + -1;
      iVar2 = *(int *)(puVar3 + -0x490);
    }
    *(undefined4 *)(puVar3 + -0x470) = 0;
LAB_00461798:
    if ((P2 != f_0) && ((_DAT_020b8ea0 >> 8 & 0xff) != 0x58)) {
      *(undefined4 *)(puVar3 + -0x4b0) = 0;
      goto LAB_00462bbf;
    }
LAB_004617c9:
    DAT_020527e8 = EDIT_ITEM;
    if (EDIT_ITEM < 1) {
      DAT_020527e8 = 1;
    }
    if (ITEM_I < (int)DAT_020527e8) {
      DAT_020527e8 = ITEM_I;
    }
    EDIT_ITEM = 0;
    DAT_0078dc45 = 0;
    *DAT_01fbb844 = (&DAT_020a55a0)[ITEM_I] + -1;
    VEC_N = (&DAT_02035a00)[ITEM_I];
    *DAT_01fbb7c0 = VEC_N + -1;
    _DAT_008244b0 = (int)DAT_020b8ea0._1_1_;
    ffree(fVar9);
    Var8 = draw_items();
    ffree(Var8);
    Var8 = thunk_FUN_00549422();
    DAT_020b8ea0 = CONCAT11(DAT_008244b0,(char)DAT_020b8ea0);
    DAT_01be6cd8 = 0;
    ITEM_WORDS = (&DAT_02091d20)[ITEM_I];
    ffree(Var8);
    fVar9 = (float10)FUN_00468df8(&DAT_00761aa4);
    if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x58) {
      P2 = f_0;
      FUN_005f33c9(puVar3,0x4618ee);
      fVar9 = (float10)FUN_005f34d1(puVar3,0x461909);
    }
    else {
      *(undefined4 *)(puVar3 + -0x4ac) = 0;
    }
LAB_0046190d:
    if (DAT_00790d74 == 1) {
      *(undefined4 *)(puVar3 + -0x4a8) = 0;
    }
    else if (DAT_00791480 < 0) {
      *(undefined4 *)(puVar3 + -0x4a4) = 0;
    }
    else {
      ffree(fVar9);
      fVar9 = (float10)thunk_FUN_00473cdd(&DAT_00761a9c);
      *(undefined4 *)(puVar3 + -0x4a0) = 0;
    }
    goto LAB_00462dc7;
  case '\x1d':
  case '\x1f':
  case ')':
  case '*':
    goto LAB_00467c1e;
  case ' ':
code_r0x004611cc:
    _DAT_01c58938 = f_20;
    if (_DAT_020b8ea0 >> 0x18 == 0x42) {
      _DAT_01c58938 = f_21;
    }
    if (_DAT_020b8ea0 >> 0x18 == 0x43) {
      _DAT_01c58938 = f_22;
    }
    DAT_01c58934 = DAT_020b9448 + f_40;
    ffree(fVar9);
    Var8 = FUN_004680d8(&DAT_00761ac0,&UNK_00761ac4);
    DAT_020b9458 = _DAT_01c58938;
    ffree(Var8);
    fVar9 = (float10)FUN_00468df8(&DAT_00761abc);
    _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00761c44);
    DAT_01c58930 = f_0;
    if (ram0x020b8ea1 >> 0x10 == 0x41) {
      if (P2 == f_0) {
        *(undefined4 *)(puVar3 + -0x2d4) = 0;
      }
      else {
        fVar1 = P2 - f_10;
        if (0.0 <= fVar1 && fVar1 != 0.0) {
          DAT_01c58930 = f_100;
          if (f_100 <= DAT_020b9450) {
            fVar9 = (float10)f_100;
            DAT_01c58930 = (float)-fVar9;
          }
          *(undefined4 *)(puVar3 + -0x2c8) = 0;
        }
        else if (fVar1 == 0.0) {
          DAT_01c58930 = f_10;
          ffree(fVar9);
          fVar10 = (float10)amod(&DAT_020b9450,&f_100);
          fVar9 = extraout_ST1_00;
          if ((float10)f_10 <= fVar10) {
            fVar9 = (float10)DAT_01c58930;
            DAT_01c58930 = (float)-fVar9;
          }
          *(undefined4 *)(puVar3 + -0x2cc) = 0;
        }
        else {
          DAT_01c58930 = f_1;
          ffree(fVar9);
          fVar10 = (float10)amod(&DAT_020b9450,&f_10);
          fVar9 = extraout_ST1;
          if (fVar10 == (float10)f_1) {
            fVar9 = (float10)DAT_01c58930;
            DAT_01c58930 = (float)-fVar9;
          }
        }
        DAT_01c58930 = DAT_01c58930 + DAT_020b9450;
        *(undefined4 *)(puVar3 + -0x2d0) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x2d8) = 0;
    }
    goto LAB_00467f93;
  case '!':
LAB_0046247f:
    if (_DAT_020b8ea0 == 0x5a534450) {
      DAT_008244b4 = f_0_1;
      if ((char)DAT_020b90a4 == '-') {
        fVar9 = (float10)f_0_1;
        DAT_008244b4 = (float)-fVar9;
      }
      DAT_008244ac = 5;
      if ((DAT_020b9458 == f_20) || (DAT_020b9458 < f_26 && f_22 < DAT_020b9458)) {
        DAT_008244ac = 9;
      }
      if (DAT_020b9440 == f_9) {
        DAT_008244ac = 6;
      }
      if ((char)DAT_020b90a4 == '0') {
        fVar9 = (float10)*(float *)(&DAT_020b943c + DAT_008244ac * 4);
        DAT_008244b4 = (float)-fVar9;
      }
      DAT_008244b8 = *(float *)(&DAT_020b943c + DAT_008244ac * 4);
      if (DAT_008244b8 == f_0) {
        DAT_008244b8 = f_1;
      }
      *(float *)(&DAT_01c5891c + DAT_008244ac * 4) = DAT_008244b4 + DAT_008244b8;
    }
    else {
      if ((_DAT_020b8ea0 & 0xffff) != 0x4450) {
        *(undefined4 *)(puVar3 + -0x33c) = 0;
        uVar7 = DAT_020b8ea0;
        if ((_DAT_020b8ea0 & 0xffff) == 0x5a53) {
          if (DAT_020b8ea2 == '+') {
            _DAT_020b8ea0 = CONCAT12(DAT_00761a4c,DAT_020b8ea0);
          }
          if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x2d) {
            _DAT_020b8ea0 = CONCAT12(DAT_00761a48,DAT_020b8ea0);
          }
          DAT_008244ac = 5;
          if (f_19 < DAT_020b9458) {
            DAT_008244ac = 9;
          }
          if (P2 == f_0) {
            *(float *)(&DAT_01c5891c + DAT_008244ac * 4) = f_0;
            DAT_008244b4 = *(float *)(&DAT_020b943c + DAT_008244ac * 4);
            if (DAT_008244b4 == f_0) {
              DAT_008244b4 = f_1;
            }
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x50) {
              *(float *)(&DAT_01c5891c + DAT_008244ac * 4) = DAT_008244b4 + f_0_1;
            }
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4d) {
              *(float *)(&DAT_01c5891c + DAT_008244ac * 4) = DAT_008244b4 - f_0_1;
            }
            *(undefined4 *)(puVar3 + -0x328) = 0;
          }
          else {
            *(float *)(&DAT_01c5891c + DAT_008244ac * 4) = P2;
            *(undefined4 *)(puVar3 + -0x32c) = 0;
          }
        }
        else if (DAT_020b8ea0._1_1_ == 'S') {
          if (DAT_020b9454 == f_0) {
            *(undefined4 *)(puVar3 + -0x324) = 0;
            goto LAB_00467fb8;
          }
          DAT_01c58940 = f_0;
          DAT_008244b4 = DAT_020b9460;
          if (DAT_020b9460 == f_0) {
            DAT_008244b4 = f_1;
          }
          if (DAT_020b8ea2 == 'P') {
            DAT_01c58940 = DAT_008244b4 + f_0_1;
          }
          if (DAT_020b8ea2 == 'M') {
            DAT_01c58940 = DAT_008244b4 - f_0_1;
          }
          *(undefined4 *)(puVar3 + -800) = 0;
        }
        else if (DAT_020b8ea0._1_1_ == 'Y') {
LAB_0046284d:
          DAT_01c58934 = DAT_020b9448 + f_20;
          *(undefined4 *)(puVar3 + -0x31c) = 0;
        }
        else if (DAT_020b8ea0._1_1_ == 'N') {
LAB_0046288b:
          DAT_01c58934 = f_0;
          *(undefined4 *)(puVar3 + -0x318) = 0;
        }
        else if ((_DAT_020b8ea0 & 0xff) == 0x57) {
          if (DAT_020b8ea0._1_1_ == ' ') {
            *(undefined4 *)(puVar3 + -0x314) = 0;
            goto LAB_0046284d;
          }
          if (DAT_020b9454 == f_0) {
            *(undefined4 *)(puVar3 + -0x310) = 0;
            goto LAB_0046288b;
          }
          DAT_01c58948 = f_0;
          if (DAT_020b8ea0._1_1_ == 'U') {
            DAT_01c58948 = DAT_020b9468 + f_0_2;
          }
          if (DAT_020b8ea0._1_1_ == 'D') {
            DAT_01c58948 = DAT_020b9468 - f_0_2;
          }
          *(undefined4 *)(puVar3 + -0x30c) = 0;
        }
        else {
          if ((_DAT_020b8ea0 & 0xff) != 0x54) {
            if ((_DAT_020b8ea0 & 0xff) == 0x2a) {
              *(undefined4 *)(puVar3 + -0x2f8) = 0;
              goto LAB_00467fb8;
            }
            *(undefined4 *)(puVar3 + -0x2fc) = 0;
            goto LAB_00462a86;
          }
          if ((_DAT_020b8ea0 & 0xffffff) == 0x205254) {
            *(undefined4 *)(puVar3 + -0x308) = 0;
            goto LAB_004673f4;
          }
          if ((_DAT_020b8ea0 & 0xffffff) == 0x495254) {
            DAT_020b9458 = f_0;
            _DAT_01c58938 = f_0;
            DAT_01c58940 = f_0;
            _DAT_020b8ea0 = CONCAT12(DAT_020b8ea5,uVar7);
            DAT_01c5894c = f_0;
            DAT_01c58948 = f_0;
            ffree(fVar9);
            fVar9 = (float10)FUN_00468df8(&DAT_00761abc);
          }
          if (DAT_020b9458 == f_0) {
            DAT_01c5893c = f_0;
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x46) {
              DAT_01c5893c = f_1;
            }
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x53) {
              DAT_01c5893c = f_2;
            }
            if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4e) {
              DAT_01c5893c = f_3;
            }
            *(undefined4 *)(puVar3 + -0x300) = 0;
          }
          else {
            DAT_0078b4e0 = 0;
            DAT_01c58920 = DAT_020b9440;
            DAT_01c58924 = DAT_020b9444;
            *(undefined4 *)(puVar3 + -0x304) = 0;
          }
        }
        goto LAB_00467f93;
      }
      if (DAT_020b9458 == f_20) {
        DAT_008244b4 = f_1;
        if (DAT_020b8ea4 == '-') {
          fVar9 = (float10)f_1;
          DAT_008244b4 = (float)-fVar9;
        }
        if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x52) {
          DAT_008244ac = 6;
          DAT_01c58934 = DAT_020b9454;
          if (DAT_020b9454 <= DAT_020b9448) {
            DAT_01c58934 = DAT_020b9448 + f_10;
          }
        }
        else {
          DAT_008244ac = 8;
          DAT_01c5893c = DAT_020b945c;
          if (DAT_020b945c == f_0) {
            DAT_01c5893c = DAT_020b9448 - f_10;
          }
        }
        *(float *)(&DAT_01c5891c + DAT_008244ac * 4) =
             DAT_008244b4 + *(float *)(&DAT_01c5891c + DAT_008244ac * 4);
        if (_DAT_020b90a0 >> 0x18 == 0x30) {
          if (DAT_008244ac == 8) {
            DAT_01c5893c = f_0;
            DAT_01c58948 = f_0;
          }
          else {
            DAT_01c58934 = DAT_020b9448;
            DAT_01c5894c = f_0;
          }
          *(undefined4 *)(puVar3 + -0x330) = 0;
        }
        else {
          *(undefined4 *)(puVar3 + -0x334) = 0;
        }
      }
      else {
        *(undefined4 *)(puVar3 + -0x338) = 0;
        _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00761c44);
        if ((ram0x020b8ea1 & 0xff00) != 0x4d00) {
          *(undefined4 *)(puVar3 + -0x344) = 0;
          goto LAB_00467fb8;
        }
        DAT_008244b4 = f_1;
        if (ram0x020b8ea1 >> 0x10 == 0x2d) {
          fVar9 = (float10)f_1;
          DAT_008244b4 = (float)-fVar9;
        }
        DAT_01c5893c = DAT_020b945c;
        if (DAT_020b945c <= DAT_020b9448) {
          DAT_01c5893c = DAT_020b9448;
        }
        DAT_01c5893c = DAT_008244b4 + DAT_01c5893c;
        if (DAT_01c5893c < DAT_020b9448) {
          DAT_01c5893c = DAT_020b9448;
        }
        if (ram0x020b8ea1 >> 0x10 == 0x2a) {
          DAT_01c5893c = f_0;
        }
        *(undefined4 *)(puVar3 + -0x340) = 0;
      }
    }
    goto LAB_00463037;
  case '\"':
LAB_0046202c:
    if (DAT_020b9440 == f_7) {
      fVar9 = (float10)P2;
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar9);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
      if (*(int *)(puVar3 + -0x5d0) - 1U < 7) {
        *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
        *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar9);
                    /* WARNING: Could not recover jumptable at 0x004620c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&PTR_LAB_007618ec)[*(int *)(puVar3 + -0x5d0) + -1])();
        return;
      }
    }
    DAT_01c58920 = f_7;
    DAT_01c58930 = f_0;
    DAT_01c5893c = f_111;
    DAT_01c58940 = f_1111;
    DAT_01c58934 = f_0;
    _DAT_01c58938 = f_1;
    DAT_01c58948 = f_0;
    DAT_01c5894c = f_0;
    DAT_01c5895c = f_0;
    DAT_01c58964 = f_0;
    if (_DAT_020b8ea0 != 0x50524148) {
      *(undefined4 *)(puVar3 + -0x350) = 0;
      if (DAT_020b8e50 != 7) {
        DAT_020b945c = DAT_01c5893c;
        DAT_020b9460 = DAT_01c58940;
      }
      fVar9 = (float10)P2;
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar9);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
      if (*(int *)(puVar3 + -0x5d0) - 1U < 7) {
        *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
        *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar9);
                    /* WARNING: Could not recover jumptable at 0x0046220c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&PTR_LAB_007618d0)[*(int *)(puVar3 + -0x5d0) + -1])();
        return;
      }
      goto LAB_0046247f;
    }
    ffree(fVar9);
    fVar9 = (float10)FUN_00468df8(&DAT_00761a3c);
    *(undefined4 *)(puVar3 + -0x34c) = 0;
    goto LAB_00467f93;
  case '#':
    goto LAB_00467ee8;
  case '$':
  case 'c':
code_r0x0046394f:
    fVar1 = DAT_020b945c;
    if ((_DAT_020b8ea0 & 0xffff) == 17999) {
      *(undefined4 *)(puVar3 + -0x248) = 0;
      goto LAB_00466fdb;
    }
    if (DAT_020b9450 != f_10) {
      *(undefined4 *)(puVar3 + -0x244) = 0;
code_r0x00463d48:
      fVar1 = P2;
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &UNK_00584254) {
        ffree(fVar9);
        fVar9 = (float10)func_0x00404eda();
        *(undefined4 *)(puVar3 + -0x220) = 0;
        goto LAB_00467f93;
      }
      if (((_DAT_020b8ea0 & 0xff) == 0x54) && ((_DAT_020b8ea0 & 0xffffff) != 0x4b4854)) {
        *(undefined4 *)(puVar3 + -0x21c) = 0;
        goto LAB_004673f4;
      }
      if (DAT_020b9450 != f_2) {
        *(undefined4 *)(puVar3 + -0x218) = 0;
        fVar1 = P2;
        if (f_1 < DAT_020b9450) {
          *(undefined4 *)(puVar3 + -0x1fc) = 0;
          goto LAB_00467fb8;
        }
        if ((DAT_020b9450 < f_0) && ((_DAT_020b8ea0 & 0xffff) == 0x5a53)) {
          *(undefined4 *)(puVar3 + -0x1f8) = 0;
          goto code_r0x0046754a;
        }
        if (_DAT_020b8ea0 == 0x54495547) {
          DAT_01c58930 = DAT_020b9450;
        }
        if (_DAT_020b8ea0 == 0x44495247) {
          DAT_01c58930 = DAT_020b9450 - f_1;
          if (DAT_01c58930 < f_m3) {
            DAT_01c58930 = f_m1;
          }
          _DAT_01c58938 = f_0;
        }
        else if ((_DAT_020b8ea0 & 0xffffff) == 0x524741) {
          DAT_01c58930 = DAT_020b9450;
          if (_UNK_00761a18 < DAT_020b9450) {
            DAT_01c58930 = _UNK_00761a18;
          }
          if (DAT_020b9458 == f_0) {
            _DAT_01c58938 = f_10;
          }
          DAT_01c5894c = _UNK_00761a14;
        }
        else if (_DAT_020b8ea0 == 0x41444843) {
          _DAT_01c58938 = DAT_020b9458;
          ffree(fVar9);
          fVar9 = (float10)FUN_00469059(&DAT_01c58938,&DAT_00761b84,&DAT_008244b4,&DAT_008244c8);
          DAT_008244b4 = DAT_008244b4 + f_1;
          if (f_2 < DAT_008244b4) {
            DAT_008244b4 = f_0;
          }
          _DAT_01c58938 = DAT_008244b4 + _DAT_01c58938;
        }
        else if (_DAT_020b8ea0 == 0x46444843) {
          DAT_01c58940 = DAT_020b9460 + f_1;
          if (f_4 < DAT_01c58940) {
            DAT_01c58940 = f_0;
          }
        }
        else if (_DAT_020b8ea0 == 0x54444843) {
          DAT_01c5893c = DAT_020b945c;
          if (DAT_020b945c == f_0) {
            DAT_01c5893c = f_1;
          }
          DAT_008244b4 = f_1;
          if ((char)DAT_020b90a4 == '-') {
            fVar9 = (float10)f_1;
            DAT_008244b4 = (float)-fVar9;
          }
          DAT_01c5893c = DAT_008244b4 + DAT_01c5893c;
          if (DAT_01c5893c < f_1) {
            DAT_01c5893c = f_20;
          }
          if (f_20 < DAT_01c5893c) {
            DAT_01c5893c = f_1;
          }
        }
        else if ((_DAT_020b8ea0 & 0xffffff) == 0x524843) {
          DAT_008244ac = DAT_020b8ea3 - 0x42;
          if (DAT_008244ac < 1) {
            DAT_008244ac = DAT_020b8ea3 - 0x3b;
          }
          *(int *)(puVar3 + -0x5d0) = DAT_008244ac * 10;
          _DAT_01c58938 = (float)*(int *)(puVar3 + -0x5d0);
        }
        else {
          if ((_DAT_020b8ea0 & 0xffff) == 0x5444) {
            DAT_01c58950 = DAT_020b9470;
            fVar11 = (float10)P2;
            fVar9 = (float10)f_7;
            fVar12 = (float10)P2;
            fVar10 = (float10)f_2;
            *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
            *(int *)(puVar3 + -0x5d0) = (int)ROUND((fVar11 + fVar9) - fVar12 * fVar10);
            DAT_008244ac = *(int *)(puVar3 + -0x5d0);
            ffree(fVar11 + fVar9);
            fVar9 = (float10)FUN_00469059(&DAT_01c58950,&DAT_008244ac,&DAT_008244b4,&DAT_008244c8);
            DAT_008244b4 = DAT_008244b4 + f_1;
            if (_DAT_020b90a0 >> 0x18 == 0x4d) {
              DAT_008244b4 = DAT_008244b4 - f_2;
            }
            if (f_9 < DAT_008244b4) {
              DAT_008244b4 = f_0;
            }
            if (DAT_008244b4 < f_0) {
              DAT_008244b4 = f_9;
            }
            DAT_01c58950 = (float)(int)DAT_008244c8 * DAT_008244b4 + DAT_01c58950;
            goto code_r0x00465376;
          }
          if ((_DAT_020b8ea0 & 0xffffff) == 0x415443) {
            _DAT_01c58938 = DAT_020b9458;
            ffree(fVar9);
            fVar9 = (float10)FUN_00469059(&DAT_01c58938,&UNK_00761a10,&DAT_008244b4,&DAT_008244c8);
            DAT_008244b4 = DAT_008244b4 + f_1;
            if (f_7 < DAT_008244b4) {
              DAT_008244b4 = f_1;
            }
            _DAT_01c58938 = DAT_008244b4 * f_10 + _DAT_01c58938;
          }
          else if ((_DAT_020b8ea0 & 0xffffff) == 0x414441) {
            _DAT_01c58938 = DAT_020b9458;
            ffree(fVar9);
            fVar9 = (float10)FUN_00469059(&DAT_01c58938,&DAT_00761b84,&DAT_008244b4,&DAT_008244c8);
            DAT_008244b4 = DAT_008244b4 + f_1;
            if (f_2 < DAT_008244b4) {
              DAT_008244b4 = f_0;
            }
            _DAT_01c58938 = DAT_008244b4 + _DAT_01c58938;
          }
          else if (_DAT_020b8ea0 == 0x544e4843) {
            DAT_01c5893c = DAT_020b945c + f_1;
            if (f_9 < DAT_01c5893c) {
              DAT_01c5893c = f_0;
            }
          }
          else {
            if ((_DAT_020b8ea0 & 0xffffff) == 0x4e4441) {
              DAT_01c58940 = DAT_020b9460;
              ffree(fVar9);
              fVar9 = (float10)FUN_00469059(&DAT_01c58940,&DAT_00761a0c,&DAT_008244b4,&DAT_008244c8)
              ;
              DAT_01c58940 = DAT_01c58940 + f_1;
              if (_DAT_020b8ea0 >> 0x18 == 0x4d) {
                DAT_01c58940 = DAT_01c58940 - f_2;
              }
              if (_UNK_00761a08 < DAT_01c58940) {
                DAT_01c58940 = f_0;
              }
              if (DAT_01c58940 < f_0) {
                DAT_01c58940 = _UNK_00761a08;
              }
              DAT_01c58940 = DAT_008244b4 * f_100 + DAT_01c58940;
              *(undefined4 *)(puVar3 + -500) = 0;
            }
            else if (_DAT_020b8ea0 == 0x20414d4e) {
              DAT_01c58940 = DAT_020b9460;
              ffree(fVar9);
              fVar9 = (float10)FUN_00469059(&DAT_01c58940,&DAT_00761a0c,&DAT_008244b4,&DAT_008244c8)
              ;
              DAT_008244b4 = DAT_008244b4 + f_1;
              if (f_3 < DAT_008244b4) {
                DAT_008244b4 = f_0;
              }
              DAT_01c58940 = DAT_008244b4 * f_100 + DAT_01c58940;
              *(undefined4 *)(puVar3 + -0x1f0) = 0;
            }
            else if ((_DAT_020b8ea0 & 0xffffff) == 0x5a5354) {
              ffree(fVar9);
              fVar9 = (float10)amod(&DAT_020b947c,&f_10);
              DAT_01c5895c = (float)fVar9;
              fVar1 = DAT_020b947c / f_10;
              *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
              *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
              *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
              DAT_008244ac = *(int *)(puVar3 + -0x5d0);
              if (DAT_01c5895c == f_0) {
                DAT_01c5895c = f_1;
              }
              if (_DAT_020b8ea0 >> 0x18 == 0x4e) {
                DAT_01c5895c = f_0;
              }
              if (_DAT_020b8ea0 >> 0x18 == 0x50) {
                DAT_01c5895c = DAT_01c5895c + f_0_1;
              }
              if (_DAT_020b8ea0 >> 0x18 == 0x4d) {
                DAT_01c5895c = DAT_01c5895c - f_0_1;
              }
              *(int *)(puVar3 + -0x5d0) = DAT_008244ac * 10;
              DAT_01c5895c = (float)*(int *)(puVar3 + -0x5d0) + DAT_01c5895c;
              *(undefined4 *)(puVar3 + -0x1ec) = 0;
              fVar9 = extraout_ST1_09;
            }
            else if ((_DAT_020b8ea0 & 0xffffff) == 0x4d4441) {
              DAT_01c58948 = DAT_020b9468;
              ffree(fVar9);
              Var8 = FUN_00469059(&DAT_01c58948,&UNK_00761a04,&fRam00824488,&DAT_008244c8);
              ffree(Var8);
              FUN_00469059(&DAT_01c58948,&DAT_00761a0c,&DAT_008244b4,&DAT_008244c8);
              if (_DAT_020b8ea0 >> 0x18 == 0x52) {
                fRam00824488 = fRam00824488 + f_1;
                if (f_7 < fRam00824488) {
                  fRam00824488 = f_0;
                }
              }
              else if (_DAT_020b8ea0 >> 0x18 == 0x4e) {
                DAT_01c58948 = DAT_01c58948 + f_1;
                if (_UNK_00761a08 < DAT_01c58948) {
                  DAT_01c58948 = f_0;
                }
              }
              else {
                DAT_008244b4 = DAT_008244b4 + f_1;
                if (f_3 < DAT_008244b4) {
                  DAT_008244b4 = f_0;
                }
              }
              fVar9 = (float10)fRam00824488 * (float10)f_1000;
              DAT_01c58948 = (float)((float10)DAT_008244b4 * (float10)f_100 + fVar9 +
                                    (float10)DAT_01c58948);
              *(undefined4 *)(puVar3 + -0x1e8) = 0;
            }
            else if (_DAT_020b8ea0 == 0x53545246) {
              fVar1 = DAT_020b9474 / f_10;
              *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
              *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
              *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
              DAT_008244ac = *(int *)(puVar3 + -0x5d0);
              ffree(fVar9);
              fVar9 = (float10)amod(&DAT_020b9474,&f_10);
              _DAT_01c58954 = (float)(fVar9 + (float10)f_1);
              if (f_9 < _DAT_01c58954) {
                _DAT_01c58954 = f_0;
              }
              *(int *)(puVar3 + -0x5d0) = DAT_008244ac * 10;
              _DAT_01c58954 = (float)*(int *)(puVar3 + -0x5d0) + _DAT_01c58954;
              *(undefined4 *)(puVar3 + -0x1e4) = 0;
              fVar9 = extraout_ST1_10;
            }
            else if (_DAT_020b8ea0 == 0x53525453) {
              fVar1 = DAT_020b9474 / f_10 + f_1;
              *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
              *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
              *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
              DAT_008244ac = *(int *)(puVar3 + -0x5d0);
              if (DAT_008244ac == 1) {
                DAT_008244ac = 2;
              }
              if (8 < DAT_008244ac) {
                DAT_008244ac = 0;
              }
              *(int *)(puVar3 + -0x5d0) = DAT_008244ac * 10;
              *(float *)(puVar3 + -0x5d0) = (float)*(int *)(puVar3 + -0x5d0);
              ffree(fVar9);
              fVar9 = (float10)amod(&DAT_020b9474,&f_10);
              _DAT_01c58954 = (float)(fVar9 + (float10)*(float *)(puVar3 + -0x5d0));
              _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00761c44);
              *(undefined4 *)(puVar3 + -0x1e0) = 0;
              fVar9 = extraout_ST1_11;
            }
            else {
              if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &UNK_00464843) {
                if (DAT_020b9450 != _UNK_00761a18) {
                  *(undefined4 *)(puVar3 + -0x1dc) = 0;
                  goto LAB_00467fb8;
                }
                DAT_01c58940 = DAT_020b9460;
                if (DAT_020b8ea3 == 0x2b) {
                  DAT_01c58940 = DAT_020b9460 + f_1;
                }
                if (DAT_020b8ea3 == 0x2d) {
                  DAT_01c58940 = DAT_01c58940 - f_1;
                }
                if (DAT_01c58940 < f_0) {
                  DAT_01c58940 = f_4;
                }
                if (f_4 < DAT_01c58940) {
                  DAT_01c58940 = f_0;
                }
                goto code_r0x00465903;
              }
              if ((_DAT_020b8ea0 & 0xffff) == 0x5253) {
                *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
                *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
                *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
                uVar7 = *(undefined2 *)(puVar3 + -0x5d4);
                iRam00824484 = *(int *)(puVar3 + -0x5d0);
                FUN_005f33c9(puVar3,&UNK_00464a97);
                Var8 = FUN_005f34d1(puVar3,&UNK_00464ab2);
                *(undefined4 *)(puVar3 + -0x5cc) = 0;
                *(undefined4 *)(puVar3 + -0x5e0) = 1;
                *(undefined4 *)(puVar3 + -0x5dc) = 0x9ae2c3;
                *(int **)(puVar3 + -0x5d8) = &iRam00824484;
                ffree(Var8);
                Var8 = FUN_005f34f0(puVar3 + -0x5cc,0x784ff00,&DAT_00761c4c,puVar3 + -0x5e0,0x7909f4
                                   );
                iRam00824484 = 7 - iRam00824484;
                DAT_01c58964 = DAT_020b9484;
                if (DAT_020b9484 == f_0) {
                  DAT_01c58964 = _UNK_007619f4;
                }
                ffree(Var8);
                fVar9 = (float10)FUN_00469059(&DAT_01c58964,&iRam00824484,&DAT_008244b4,
                                              &DAT_008244c8);
                fVar1 = DAT_008244b4;
                *(undefined2 *)(puVar3 + -0x5d4) = uVar7;
                *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
                *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
                DAT_008244ac = *(int *)(puVar3 + -0x5d0);
                if ((4 < DAT_008244ac) && (DAT_008244ac < 9)) {
                  DAT_008244ac = 6;
                }
                if (DAT_008244ac == 9) {
                  DAT_008244ac = 5;
                }
                DAT_008244ac = DAT_008244ac + 1;
                if (DAT_008244ac == 7) {
                  DAT_008244ac = 0;
                }
                if (DAT_008244ac == 5) {
                  DAT_008244ac = 9;
                }
                if (DAT_008244ac == 6) {
                  DAT_008244ac = 7;
                }
                *(uint *)(puVar3 + -0x5d0) = DAT_008244c8 * DAT_008244ac;
                DAT_01c58964 = (float)*(int *)(puVar3 + -0x5d0) + DAT_01c58964;
                *(undefined4 *)(puVar3 + -0x1d4) = 0;
              }
              else if ((_DAT_020b8ea0 & 0xffff) == 0x5242) {
                DAT_01c5894c = DAT_020b946c;
                ffree(fVar9);
                fVar9 = (float10)amod(&DAT_01c5894c,&f_1);
                fRam00824480 = (float)fVar9;
                if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4c) {
                  ffree(extraout_ST1_12);
                  FUN_00469059(&DAT_01c5894c,&UNK_00761a04,&DAT_008244b4,&DAT_008244c8);
                  DAT_008244b4 = DAT_008244b4 + f_1;
                  if (f_5 < DAT_008244b4) {
                    DAT_008244b4 = f_1;
                  }
                }
                else if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x52) {
                  ffree(extraout_ST1_12);
                  FUN_00469059(&DAT_01c5894c,&DAT_00761a0c,&DAT_008244b4,&DAT_008244c8);
                  DAT_008244b4 = DAT_008244b4 + f_1;
                  if ((f_6 < DAT_008244b4) || (DAT_008244b4 < f_2)) {
                    DAT_008244b4 = f_2;
                  }
                }
                fVar9 = (float10)fRam00824480 + (float10)DAT_01c5894c;
                DAT_01c5894c = (float)((float10)(int)DAT_008244c8 * (float10)DAT_008244b4 + fVar9);
                *(undefined4 *)(puVar3 + -0x1d0) = 0;
              }
              else {
                if (_DAT_020b8ea0 == 0x52424f4e) {
                  DAT_01c5894c = DAT_020b946c;
                  ffree(fVar9);
                  fVar9 = (float10)amod(&DAT_01c5894c,&f_1);
                  fRam00824480 = (float)fVar9;
                  ffree(extraout_ST1_13);
                  Var8 = FUN_00469059(&DAT_01c5894c,&DAT_00761a0c,&DAT_008244b4,&DAT_008244c8);
                  ffree(Var8);
                  fVar9 = (float10)FUN_00469059(&DAT_01c5894c,&UNK_00761a04,&DAT_008244b4,
                                                &DAT_008244c8);
                  DAT_01c5894c = fRam00824480 + DAT_01c5894c;
                  goto code_r0x00465903;
                }
                if ((_DAT_020b8ea0 & 0xffffff) == 0x4e5246) {
                  fVar1 = DAT_020b946c / f_100;
                  *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
                  *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
                  *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
                  DAT_008244ac = *(int *)(puVar3 + -0x5d0);
                  ffree(fVar9);
                  fVar9 = (float10)amod(&DAT_020b946c,&f_1);
                  DAT_008244b4 = (float)fVar9;
                  ffree(extraout_ST1_14);
                  fVar9 = (float10)amod(&DAT_020b946c,&f_100);
                  DAT_01c5894c = (float)(fVar9 - (float10)DAT_008244b4);
                  if (_DAT_020b8ea0 >> 0x18 == 0x50) {
                    DAT_01c5894c = DAT_01c5894c + f_1;
                  }
                  if (_DAT_020b8ea0 >> 0x18 == 0x4d) {
                    DAT_01c5894c = DAT_01c5894c - f_1;
                  }
                  if (DAT_01c5894c < f_0) {
                    DAT_01c5894c = f_0;
                  }
                  if (_DAT_020b8ea0 >> 0x18 == 0x44) {
                    DAT_008244b4 = DAT_008244b4 + f_0_1;
                  }
                  if (_DAT_020b8ea0 >> 0x18 == 0x55) {
                    DAT_008244b4 = DAT_008244b4 - f_0_1;
                  }
                  if ((_UNK_007619f0 < DAT_008244b4) || (DAT_008244b4 < f_0)) {
                    DAT_008244b4 = f_0;
                  }
                  fVar9 = (float10)DAT_008244b4 + (float10)DAT_01c5894c;
                  *(int *)(puVar3 + -0x5d0) = DAT_008244ac * 100;
                  DAT_01c5894c = (float)((float10)*(int *)(puVar3 + -0x5d0) + fVar9);
                  *(undefined4 *)(puVar3 + -0x1cc) = 0;
                }
                else {
                  if (DAT_020b8ea4 != 'Z' || _DAT_020b8ea0 != 0x54455246) {
                    if ((_DAT_020b8ea0 & 0xffff) == 0x5747) {
                      _DAT_01c58960 = DAT_020b9480;
                      if (DAT_020b9480 == f_0) {
                        _DAT_01c58960 = f_1;
                      }
                      if (DAT_020b8ea2 == 'P') {
                        _DAT_01c58960 = _DAT_01c58960 + f_0_1;
                      }
                      if (DAT_020b8ea2 == 'M') {
                        _DAT_01c58960 = _DAT_01c58960 - f_0_1;
                      }
                      if ((_DAT_01c58960 < f_0) || (DAT_020b8ea2 == 'N')) {
                        _DAT_01c58960 = f_0;
                      }
                    }
                    else if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544e46) {
                      ffree(fVar9);
                      fVar9 = (float10)amod(&DAT_020b947c,&f_10);
                      DAT_01c5895c = (float)((float10)P2 * (float10)f_10 + fVar9);
                    }
                    else {
                      if ((_DAT_020b8ea0 & 0xffffff) == 0x535553) {
                        DAT_01c58944 = DAT_020b9464;
                        if (DAT_020b9464 == f_0) {
                          DAT_01c58944 = f_1000;
                        }
                        else if (DAT_020b8ea3 == 0x20) {
                          DAT_01c58944 = DAT_020b9464 + f_1000;
                          if (f_4000 <= DAT_01c58944) {
                            DAT_01c58944 = DAT_01c58944 - f_4000;
                          }
                        }
                        else if (DAT_020b8ea3 == 0x41) {
                          ffree(fVar9);
                          fVar9 = (float10)FUN_00469059(&DAT_01c58944,&DAT_00761a0c,&DAT_008244b4,
                                                        &DAT_008244c8);
                          DAT_008244b4 = DAT_008244b4 + f_1;
                          if (f_3 < DAT_008244b4) {
                            DAT_008244b4 = f_0;
                          }
                          DAT_01c58944 = DAT_008244b4 * f_100 + DAT_01c58944;
                        }
                        else if (DAT_020b8ea3 == 0x4e) {
                          ffree(fVar9);
                          fVar9 = (float10)amod(&DAT_01c58944,&f_100);
                          DAT_008244b4 = (float)fVar9;
                          fVar1 = DAT_01c58944 / f_100;
                          *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
                          *(ushort *)(puVar3 + -0x5d2) =
                               (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
                          *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
                          DAT_008244ac = *(int *)(puVar3 + -0x5d0);
                          DAT_008244b4 = DAT_008244b4 + f_1;
                          if (_UNK_00761a08 < DAT_008244b4) {
                            DAT_008244b4 = f_0;
                          }
                          *(int *)(puVar3 + -0x5d0) = DAT_008244ac * 100;
                          DAT_01c58944 = (float)*(int *)(puVar3 + -0x5d0) + DAT_008244b4;
                          fVar9 = extraout_ST1_15;
                        }
                        *(undefined4 *)(puVar3 + -0x1c4) = 0;
                        goto code_r0x00465376;
                      }
                      if (_DAT_020b8ea0 == 0x20584f42) {
                        DAT_01c58930 = f_0;
                        DAT_01c5894c = f_0;
                        DAT_01c58944 = f_0;
                        DAT_01c58948 = f_0;
                      }
                      else if (_DAT_020b8ea0 == 0x43524943) {
                        DAT_01c58930 = f_1;
                        DAT_01c5894c = f_0;
                        DAT_01c58944 = f_0;
                        DAT_01c58948 = f_0;
                      }
                      else {
                        if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f52) {
                          *(undefined4 *)(puVar3 + -0x1c0) = 0;
                          goto LAB_00467070;
                        }
                        if (_DAT_020b8ea0 == 0x4c4c4946) {
                          DAT_01c58950 = f_1;
                          if (DAT_020b8ea4 == 'N') {
                            DAT_01c58950 = f_0;
                          }
                        }
                        else if ((_DAT_020b8ea0 & 0xffff) == 0x5842) {
                          if (DAT_020b9454 == f_0) {
                            DAT_01c58934 = f_10;
                          }
                          if (DAT_020b9458 == f_0) {
                            _DAT_01c58938 = f_10;
                          }
                          DAT_008244ac = 7;
                          if (DAT_020b8ea2 == 'H') {
                            DAT_008244ac = 6;
                          }
                          *(undefined4 *)(&DAT_01c5891c + DAT_008244ac * 4) =
                               *(undefined4 *)(&DAT_020b943c + DAT_008244ac * 4);
                          if (*(float *)(&DAT_01c5891c + DAT_008244ac * 4) == f_0) {
                            *(float *)(&DAT_01c5891c + DAT_008244ac * 4) = f_10;
                          }
                          DAT_008244b4 = f_0_4;
                          if (_DAT_020b8ea0 >> 0x18 == 0x4d) {
                            fVar9 = (float10)f_0_4;
                            DAT_008244b4 = (float)-fVar9;
                          }
                          *(float *)(&DAT_01c5891c + DAT_008244ac * 4) =
                               DAT_008244b4 + *(float *)(&DAT_01c5891c + DAT_008244ac * 4);
                        }
                        else if ((_DAT_020b8ea0 & 0xffffff) == 0x445342) {
code_r0x004655f1:
                          DAT_01c58934 = f_10;
                          _DAT_01c58938 = f_0;
                        }
                        else if ((_DAT_020b8ea0 & 0xffff) == 0x5a53) {
                          if (DAT_020b8ea2 == '*') {
                            *(undefined4 *)(puVar3 + -0x1bc) = 0;
                            goto code_r0x004655f1;
                          }
                          DAT_01c58934 = DAT_020b9454;
                          _DAT_01c58938 = DAT_020b9458;
                          if (DAT_020b9454 == f_0) {
                            DAT_01c58934 = f_10;
                          }
                          DAT_008244b4 = f_0_4;
                          if (DAT_020b8ea2 == '-') {
                            fVar9 = (float10)f_0_4;
                            DAT_008244b4 = (float)-fVar9;
                          }
                          DAT_01c58934 = DAT_008244b4 + DAT_01c58934;
                        }
                        else if ((_DAT_020b8ea0 & 0xffff) == 0x5356) {
                          _DAT_01c58938 = DAT_020b9458;
                          if (DAT_020b9458 == f_0) {
                            _DAT_01c58938 = DAT_020b9454;
                          }
                          DAT_008244b4 = f_0_4;
                          if (DAT_020b8ea3 == 0x2d) {
                            fVar9 = (float10)f_0_4;
                            DAT_008244b4 = (float)-fVar9;
                          }
                          _DAT_01c58938 = DAT_008244b4 + _DAT_01c58938;
                        }
                        else if ((_DAT_020b8ea0 & 0xffffff) == 0x4b4854) {
                          DAT_01c5893c = DAT_020b945c + f_1;
                          if (_DAT_020b90a0 >> 0x18 == 0x30) {
                            DAT_01c5893c = f_0;
                          }
                        }
                        else if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &UNK_00435241) {
                          if (DAT_020b9450 == f_0) {
                            *(undefined4 *)(puVar3 + -0x1b8) = 0;
                            goto LAB_00467fb8;
                          }
                          DAT_008244ac = 10;
                          if (DAT_020b8ea3 == 0x42) {
                            DAT_008244ac = 0xb;
                          }
                          DAT_008244b4 = f_5;
                          if (DAT_020b8ea4 == 'M') {
                            fVar9 = (float10)f_5;
                            DAT_008244b4 = (float)-fVar9;
                          }
                          *(float *)(&DAT_01c5891c + DAT_008244ac * 4) =
                               DAT_008244b4 + *(float *)(&DAT_020b943c + DAT_008244ac * 4);
                          if (*(float *)(&DAT_01c5891c + DAT_008244ac * 4) < f_0) {
                            *(undefined4 *)(&DAT_01c5891c + DAT_008244ac * 4) = _UNK_007619e8;
                          }
                        }
                        else if (_DAT_020b8ea0 == 0x48534443) {
                          DAT_01c5894c = DAT_020b946c - f_2;
                        }
                        else if ((_DAT_020b8ea0 & 0xffffff) == 0x574b53) {
                          if (DAT_020b9450 != f_0) {
                            *(undefined4 *)(puVar3 + -0x1b4) = 0;
                            goto LAB_00467fb8;
                          }
                          DAT_008244b4 = f_2;
                          if (DAT_020b8ea3 == 0x4c) {
                            fVar9 = (float10)f_2;
                            DAT_008244b4 = (float)-fVar9;
                          }
                          DAT_01c58944 = DAT_008244b4 + DAT_020b9464;
                          if (DAT_020b8ea3 == 0x2a) {
                            DAT_01c58944 = f_0;
                          }
                        }
                      }
                    }
                    goto code_r0x00465903;
                  }
                  fVar1 = DAT_020b946c / f_100;
                  *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
                  *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
                  *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
                  DAT_008244ac = *(int *)(puVar3 + -0x5d0);
                  *(int *)(puVar3 + -0x5d0) = DAT_008244ac * 100;
                  DAT_01c5894c = (float)*(int *)(puVar3 + -0x5d0);
                  *(undefined4 *)(puVar3 + -0x1c8) = 0;
                }
              }
            }
code_r0x00465376:
            if (DAT_020b9450 < f_m3) {
              DAT_01c58930 = f_m1;
            }
          }
        }
code_r0x00465903:
        *(undefined4 *)(puVar3 + -0x1b0) = 0;
        goto LAB_00467f93;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 0x4250) {
        *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
        *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
        DAT_008244ac = *(int *)(puVar3 + -0x5d0);
        DAT_008244b4 = f_0_1;
        *(undefined4 *)(puVar3 + -0x214) = 0;
code_r0x00465a62:
        *(float *)(&DAT_01c5891c + DAT_008244ac * 4) =
             DAT_008244b4 + *(float *)(&DAT_020b943c + DAT_008244ac * 4);
      }
      else {
        if (_DAT_020b8ea0 == 0x58495350) {
          DAT_008244ac = 6;
          DAT_008244b4 = _UNK_007619e4;
          *(undefined4 *)(puVar3 + -0x210) = 0;
          goto code_r0x00465a62;
        }
        if (_DAT_020b8ea0 == 0x56455350) {
          DAT_008244ac = 7;
          DAT_008244b4 = _UNK_007619e4;
          if (DAT_020b8ea4 == 'Z') {
            DAT_008244b4 = f_0;
          }
          *(undefined4 *)(puVar3 + -0x20c) = 0;
          goto code_r0x00465a62;
        }
        if (_DAT_020b8ea0 == 0x564c4550) {
          DAT_008244ac = 0xb;
          DAT_008244b4 = _UNK_007619e4;
          *(undefined4 *)(puVar3 + -0x208) = 0;
          goto code_r0x00465a62;
        }
        if (_DAT_020b8ea0 == 0x4c575450) {
          DAT_008244ac = 0xc;
          DAT_008244b4 = _UNK_007619e4;
          goto code_r0x00465a62;
        }
        if (_DAT_020b8ea0 == 0x52485450) {
          DAT_01c58950 = f_0;
        }
      }
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f52) {
        *(undefined4 *)(puVar3 + -0x204) = 0;
        goto LAB_00467070;
      }
      *(undefined4 *)(puVar3 + -0x200) = 0;
      goto LAB_00467f93;
    }
    if ((_DAT_020b8ea0 & 0xffff) != 0x5a53) {
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      fVar1 = DAT_020b9460;
      DAT_008244a8 = *(int *)(puVar3 + -0x5d0);
      *(undefined2 *)(puVar3 + -0x5d4) = *(undefined2 *)(puVar3 + -0x5d4);
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
      DAT_008244ac = *(int *)(puVar3 + -0x5d0);
      if ((_DAT_020b8ea0 & 0xffff) == 0x4e4c) {
        _DAT_01c58938 = P2;
        DAT_01c5893c = f_0;
        DAT_01c58940 = f_0;
        *(undefined4 *)(puVar3 + -0x23c) = 0;
      }
      else {
        if ((_DAT_020b8ea0 & 0xffffff) == 0x504f54) {
          DAT_008244f0 = 1;
          if (DAT_008244a8 % 10 == 1) {
            DAT_008244f0 = 0xffffffff;
          }
        }
        else if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f42) {
          fVar1 = DAT_020b9458 - f_1;
          *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
          *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
          DAT_008244f0 = *(uint *)(puVar3 + -0x5d0);
          if ((int)DAT_008244f0 < 1) {
            DAT_008244f0 = 2;
          }
          ffree(fVar9);
          DAT_008244f0 = FUN_005ff9b0(10,DAT_008244f0);
          if ((int)DAT_008244f0 <= DAT_008244a8) {
            DAT_008244f0 = -DAT_008244f0;
          }
          *(undefined4 *)(puVar3 + -0x234) = 0;
          fVar9 = extraout_ST0;
        }
        else {
          if ((_DAT_020b8ea0 & 0xffffff) != 0x44494d) {
            if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &UNK_0046454c) {
              DAT_008244f0 = 100;
              if (99 < DAT_008244ac) {
                DAT_008244f0 = 0xffffff9c;
              }
            }
            else {
              if ((undefined *)(_DAT_020b8ea0 & 0xffffff) != &UNK_00544852) {
                if ((_DAT_020b8ea0 & 0xffffff) == 0x4b4854) {
                  DAT_01c58944 = DAT_020b9464 + f_1;
                  if (_DAT_020b90a0 >> 0x18 == 0x30) {
                    DAT_01c58944 = f_0;
                  }
                  *(undefined4 *)(puVar3 + -0x224) = 0;
                  goto LAB_00467f9e;
                }
                goto code_r0x00463d48;
              }
              DAT_008244f0 = 1;
              if (DAT_008244ac % 10 == 1) {
                DAT_008244f0 = 0xffffffff;
              }
              *(undefined4 *)(puVar3 + -0x228) = 0;
            }
            *(uint *)(puVar3 + -0x5d0) = DAT_008244f0 + DAT_008244ac;
            DAT_01c58940 = (float)*(int *)(puVar3 + -0x5d0);
            *(undefined4 *)(puVar3 + -0x22c) = 0;
            goto LAB_00467f93;
          }
          DAT_008244f0 = 10;
          if ((DAT_020b9458 == f_4) && (_DAT_020b8ea0 >> 0x18 == 0x44)) {
            DAT_008244f0 = 100;
          }
          if ((int)DAT_008244f0 <= DAT_008244a8 % (int)(DAT_008244f0 * 10)) {
            DAT_008244f0 = -DAT_008244f0;
          }
          *(undefined4 *)(puVar3 + -0x230) = 0;
        }
        *(uint *)(puVar3 + -0x5d0) = DAT_008244f0 + DAT_008244a8;
        DAT_01c5893c = (float)*(int *)(puVar3 + -0x5d0);
        *(undefined4 *)(puVar3 + -0x238) = 0;
      }
      goto LAB_00467f93;
    }
    *(undefined4 *)(puVar3 + -0x240) = 0;
code_r0x0046754a:
    DAT_008244b4 = f_0;
    ffree(fVar9);
    fVar9 = (float10)amod(&DAT_020b9454,&f_100);
    DAT_01c58934 = (float)fVar9;
    *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
    *(int *)(puVar3 + -0x5d0) = (int)ROUND(DAT_01c58934 / f_100);
    DAT_008244ac = *(int *)(puVar3 + -0x5d0);
    fVar9 = extraout_ST1_22;
    if (DAT_01c58934 == f_0) {
      DAT_01c58934 = f_1;
    }
LAB_004675d5:
    DAT_01c58934 = DAT_01c58934 - f_0_1;
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x2b) {
      DAT_01c58934 = DAT_01c58934 + f_0_2;
    }
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x2a) {
      DAT_01c58934 = f_0;
    }
    if (DAT_008244b4 != f_0) {
      _DAT_01c58938 = DAT_01c58934 / DAT_008244b4;
    }
    *(int *)(puVar3 + -0x5d0) = DAT_008244ac * 100;
    DAT_01c58934 = (float)*(int *)(puVar3 + -0x5d0) + DAT_01c58934;
    *(undefined4 *)(puVar3 + -0x288) = 0;
    goto LAB_00467f93;
  case '%':
LAB_0045fb24:
    DAT_0205274c = 0;
    DAT_008244c8 = DAT_008244c8 - DAT_0078b370;
    P2 = DAT_008244c4;
    P3 = DAT_008244c0;
    P4 = DAT_008244bc;
    if ((IP1 == 6) && (EDIT_ITEM == _DAT_01c58628)) {
      ffree(fVar9);
      fVar9 = (float10)thunk_FUN_0043f52f(&DAT_00761b84);
    }
    _DAT_01c58628 = 0;
    if ((_DAT_020b90a0 >> 0x10 & 0xff) == 0x58) {
      ffree(fVar9);
      fVar9 = (float10)thunk_FUN_0047766d();
      *(undefined4 *)(puVar3 + -0x4cc) = 0;
      goto LAB_00461690;
    }
    FUN_005f33c9(puVar3,&LAB_0045fbdf);
    FUN_005f34d1(puVar3,&LAB_0045fbfa);
    FUN_005f33c9(puVar3,&LAB_0045fc1c);
    fVar9 = (float10)FUN_005f34d1(puVar3,&LAB_0045fc37);
    *(undefined4 *)(puVar3 + -0x4c8) = 0;
    goto LAB_00462bbf;
  case '\'':
code_r0x004619b8:
    _DAT_01c58938 = f_m1;
    DAT_01c58930 = f_999;
    if (DAT_020b9454 <= DAT_020b9448) {
      DAT_01c58934 = DAT_020b9448 + f_20;
    }
    ffree(fVar9);
    fVar9 = (float10)FUN_004680d8(&DAT_00761ac0,&DAT_00761ad0);
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x2d) {
      DAT_01c58948 = f_1;
    }
    if (DAT_020b9470 != f_0) {
      DAT_01c58950 = DAT_020b9470;
    }
    *(undefined4 *)(puVar3 + -0x37c) = 0;
    goto LAB_00467f9e;
  case '(':
code_r0x00461139:
    ffree(fVar9);
    fVar9 = (float10)FUN_004680d8(&DAT_00761974,&DAT_00761ad0);
    DAT_01c58950 = DAT_020b9470;
    DAT_01c58944 = DAT_020b9464;
    if ((DAT_020b9450 == f_999) || (DAT_020b9454 == f_0)) {
      DAT_01c58930 = DAT_020b944c;
    }
    if (DAT_020b9454 == f_0) {
      DAT_01c58934 = DAT_020b9448 + f_20;
    }
    *(undefined4 *)(puVar3 + -0x378) = 0;
    goto LAB_00467f9e;
  case '+':
code_r0x0046108e:
    fVar1 = DAT_020b9460;
    if (2 < DAT_020b8e50) {
      *(undefined4 *)(puVar3 + -0x3a4) = 0;
      goto LAB_00467fb8;
    }
    if (DAT_020b8e50 == 1) {
      DAT_01c58968 = f_0;
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      DAT_008244ac = *(int *)(puVar3 + -0x5d0);
      *(int *)(puVar3 + -0x5d0) = DAT_008244ac % 10;
      DAT_01c58940 = (float)*(int *)(puVar3 + -0x5d0);
    }
    else {
      DAT_01c58934 = f_0;
    }
    *(undefined4 *)(puVar3 + -0x3a0) = 0;
    goto LAB_00467f9e;
  case '.':
  case '@':
code_r0x00460530:
    if (((_DAT_020b8ea0 >> 8 & 0xff) == 0x20) || ((_DAT_020b8ea0 >> 8 & 0xff) == 0x2a)) {
      *(undefined4 *)(puVar3 + -0x404) = 0;
      goto LAB_00462bbf;
    }
    if (0 < DAT_0205274c) {
      ffree(fVar9);
      Var8 = thunk_FUN_00473228(&EDIT_ITEM);
      DAT_020527c0 = (&ITEM_PTR0)[EDIT_ITEM];
      uRam008244e0 = CONCAT31(uRam008244e0._1_3_,DAT_020b8ea0._1_1_);
      ffree(Var8);
      Var8 = thunk_FUN_00476628();
      ffree(Var8);
      fVar9 = (float10)thunk_FUN_00495d4f(&DAT_0078b510,0x80);
      DAT_0205274c = 0;
      DAT_020b8ea0 = CONCAT11((char)uRam008244e0,(char)DAT_020b8ea0);
      DAT_0078b4f0 = 0;
    }
    DAT_0078dc45 = 0;
    if (_DAT_008244d0 == 0) {
      DAT_01fbb760 = 0;
    }
    if (DAT_0078b4e4 == 0x5a) {
      _DAT_01fbb764 = (float)(&ITEM_P1)[(&ITEM_PTR0)[EDIT_ITEM]];
      fVar1 = (float)(&ITEM_P2)[(&ITEM_PTR0)[EDIT_ITEM]];
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x5d4);
      DAT_01fbb760 = 1;
      DAT_008244c8 = EDIT_ITEM;
      DAT_01fbb770 = 1;
      DAT_008244a0 = 999;
    }
    else {
      *(undefined4 *)(puVar3 + -0x400) = 0;
    }
    DAT_0078b370 = 1;
LAB_004606ae:
    if (DAT_01fbb760 != 0) {
      *(undefined4 *)(puVar3 + -0x3fc) = 0;
      DAT_008244f0 = DAT_008244c8 + 1;
      if (ITEM_I < (int)DAT_008244f0) {
        *(undefined4 *)(puVar3 + -0x3f0) = 0;
        goto LAB_00461798;
      }
      DAT_008244a8 = ITEM_I;
      DAT_008244a4 = 1;
      if (DAT_01fbb760 != 2) {
        *(undefined4 *)(puVar3 + -1000) = 0;
        goto LAB_0046093f;
      }
      *(undefined4 *)(puVar3 + -0x3ec) = 0;
      goto LAB_00460e34;
    }
    EDIT_ITEM = EDIT_ITEM + 1;
    if (EDIT_ITEM <= ITEM_I) {
      DAT_020527e8 = EDIT_ITEM;
      *(undefined4 *)(puVar3 + -0x3f4) = 0;
      goto LAB_00461070;
    }
    *(undefined4 *)(puVar3 + -0x3f8) = 0;
    goto LAB_004617c9;
  case '3':
  case '4':
  case '5':
  case '6':
LAB_00460b94:
    if ((P2 == f_0) && ((_DAT_020b8ea0 & 0xffffff) == 0x424752)) {
      P2 = DAT_020b94a4;
      if ((DAT_020b8e50 == 0x10) && (P14 == f_m1)) {
        P2 = DAT_020b947c;
      }
      ffree(fVar9);
      fVar9 = (float10)FUN_00469127();
      if (COLOR < 0) {
        DAT_01c58920 = DAT_020b9440;
        *(undefined4 *)(puVar3 + -0x3c4) = 0;
        goto LAB_00467f9e;
      }
      *(undefined4 *)(puVar3 + -0x3c8) = 0;
    }
    if (P2 == f_0) {
      _DAT_01c58984 = f_0;
      if ((_DAT_020b8ea0 & 0xffffff) == 0x494857) {
        _DAT_01c58984 = f_1;
      }
    }
    else {
      _DAT_01c58984 = P2;
    }
    *(undefined4 *)(puVar3 + -0x3c0) = 0;
    goto LAB_00467f9e;
  case '7':
    goto LAB_004613dc;
  case '8':
LAB_004614da:
    fVar1 = P2;
    if (P2 != f_0) {
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      DAT_01be6d48 = *(int *)(puVar3 + -0x5d0);
    }
    *(undefined4 *)(&DAT_01c5891c + DAT_01be6d48 * 4) =
         *(undefined4 *)(&DAT_01be6cdc + DAT_01be6d48 * 4);
    *(undefined4 *)(puVar3 + -0x8c) = 0;
    goto LAB_00467f9e;
  case '9':
LAB_00461555:
    if (DAT_020b8e50 == 1) {
      fVar1 = DAT_020b946c + f_1;
      *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
      *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
      DAT_00790a34 = *(int *)(puVar3 + -0x5d0);
      if (2 < DAT_00790a34) {
        DAT_00790a34 = 0;
      }
      DAT_01c5894c = (float)DAT_00790a34;
      *(undefined4 *)(puVar3 + -0x84) = 0;
      goto LAB_00467f9e;
    }
    *(undefined4 *)(puVar3 + -0x88) = 0;
LAB_00467ee8:
    ffree(fVar9);
    fVar9 = (float10)FUN_00468df8(&DAT_00761abc);
    if (EDIT_ITEM != 0) {
      DAT_020527e8 = EDIT_ITEM;
    }
    DAT_0078dc30 = 0;
    *(undefined4 *)(puVar3 + -8) = 0;
    goto LAB_00467fb8;
  case ';':
  case '<':
LAB_004615de:
    _DAT_00824468 = f_0;
    ffree(fVar9);
    fVar9 = (float10)FUN_0045ea40(&DAT_020b9440,&P2,&DAT_00824464,&DAT_00824460,&DAT_00824468,
                                  &DAT_0082445c);
    if (P2 == f_0) {
      *(undefined4 *)(puVar3 + -0x80) = 0;
      goto LAB_00467fb8;
    }
    *(float *)(&DAT_01c5891c + DAT_00824460 * 4) = P2;
    *(undefined4 *)(puVar3 + -0x7c) = 0;
    goto LAB_00467f93;
  case 'A':
    if (DAT_020b8ea0._1_1_ == ' ') {
      *(undefined4 *)(puVar3 + -0x598) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761c3c;
    if (DAT_020b8ea0._1_1_ == 'B') {
      *(undefined4 *)(puVar3 + -0x594) = 0;
      goto LAB_0045fb24;
    }
    if (DAT_020b8ea0._1_1_ == 'T') {
      DAT_01c58930 = _UNK_00761c38;
    }
    if (DAT_020b8ea0._1_1_ == 'C') {
      DAT_01c58930 = f_22;
    }
    if (DAT_020b8ea2 == 'T') {
      DAT_01c58930 = _UNK_00761c30;
    }
    if (DAT_020b8ea3 == 0x53) {
      DAT_01c58930 = f_26;
    }
    if (DAT_020b8ea0._1_1_ == 'R') {
      DAT_01c58930 = _UNK_00761c28;
    }
    if (DAT_020b8ea2 == 'L') {
      DAT_01c58930 = _UNK_00761c24;
    }
    if (_DAT_020b8ea0 != 0x52504441) {
      *(undefined4 *)(puVar3 + -0x58c) = 0;
      break;
    }
    *(undefined4 *)(puVar3 + -0x590) = 0;
code_r0x004671e9:
    if (_DAT_020b8ea0 != 0x52504441) {
      *(undefined4 *)(puVar3 + -0x264) = 0;
      goto LAB_00467fb8;
    }
    if ((DAT_020b9450 <= f_49) || (f_59 <= DAT_020b9450)) {
      if ((DAT_020b9450 <= f_149) || (f_159 <= DAT_020b9450)) {
        if ((DAT_020b9450 <= f_5) || (f_11 <= DAT_020b9450)) {
          if ((DAT_020b9450 <= f_139) || (f_145 <= DAT_020b9450)) {
            if (DAT_020b9450 == f_118) {
              DAT_01c58930 = f_181;
            }
            else if (DAT_020b9450 == f_181) {
              DAT_01c58930 = f_118;
            }
            else {
              DAT_01c58930 = f_91;
            }
          }
          else {
            DAT_01c58930 = DAT_020b9450 - f_134;
            DAT_01c58934 = f_0_25;
          }
        }
        else {
          DAT_01c58930 = DAT_020b9450 + f_134;
          DAT_01c58934 = f_0;
        }
      }
      else {
        DAT_01c58930 = DAT_020b9450 - f_100;
      }
    }
    else {
      DAT_01c58930 = DAT_020b9450 + f_100;
    }
    *(undefined4 *)(puVar3 + -0x260) = 0;
    goto LAB_00467f93;
  case 'B':
  case 'J':
  case 'K':
  case 'N':
  case 'O':
  case 'Q':
  case 'V':
    goto LAB_0045fa18;
  case 'C':
    if (DAT_020b8ea0._1_1_ != 'R') {
      *(undefined4 *)(puVar3 + -0x588) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761c20;
    *(undefined4 *)(puVar3 + -0x584) = 0;
    break;
  case 'D':
    if (((DAT_020b8ea0._1_1_ == 'C') || (DAT_020b8ea2 == 'B')) || (DAT_020b8ea2 == 'M')) {
      if ((_DAT_020b8ea0 & 0xffffff) != 0x424544) {
        DAT_01c58930 = f_111;
        if (DAT_020b8ea0._1_1_ == 'N') {
          DAT_01c58930 = _UNK_00761c18;
        }
        if (DAT_020b8ea0._1_1_ == 'I') {
          DAT_01c58930 = f_64;
        }
        *(undefined4 *)(puVar3 + -0x578) = 0;
        break;
      }
      *(undefined4 *)(puVar3 + -0x57c) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0x580) = 0;
    }
LAB_0045fa18:
    while ((_DAT_020b8ea0 & 0xffff) != 0x4552) {
      *(undefined4 *)(puVar3 + -0x50c) = 0x43;
      DAT_020527cc = 1;
      do {
        if ((*(uint *)(s_ARCRDCDTDSHOLILBLALLLRRORBRASASP_00790a3c + DAT_020527cc * 3 + 0x25) &
            0xffffff) == (_DAT_020b8ea0 & 0xffffff)) {
          switch(DAT_020527cc) {
          case 1:
            goto LAB_00467b25;
          case 2:
          case 0x28:
            goto LAB_0045fb24;
          case 3:
          case 4:
          case 5:
          case 6:
            goto LAB_0045fc4a;
          case 7:
          case 8:
          case 0x30:
          case 0x40:
            goto LAB_00461690;
          case 9:
          case 10:
            goto code_r0x0045fefb;
          case 0xb:
          case 0x1d:
          case 0x21:
          case 0x35:
          case 0x42:
            goto LAB_00462bbf;
          case 0xc:
          case 0xd:
          case 0x2f:
            goto code_r0x00460047;
          case 0xe:
          case 0x33:
          case 0x34:
          case 0x3d:
            goto LAB_004602fc;
          case 0xf:
          case 0x10:
          case 0x11:
          case 0x12:
          case 0x13:
          case 0x14:
          case 0x15:
          case 0x16:
          case 0x17:
          case 0x18:
          case 0x19:
          case 0x1a:
            goto code_r0x00461c81;
          case 0x1b:
          case 0x1c:
          case 0x29:
            goto LAB_00467f66;
          case 0x1e:
          case 0x32:
            goto code_r0x00460781;
          case 0x1f:
          case 0x41:
            goto code_r0x00460c8c;
          case 0x20:
          case 0x22:
          case 0x2c:
          case 0x2d:
            goto LAB_00467c1e;
          case 0x23:
            goto code_r0x004611cc;
          case 0x24:
            goto LAB_0046247f;
          case 0x25:
            goto LAB_0046202c;
          case 0x26:
            goto LAB_00467ee8;
          case 0x27:
            goto code_r0x0046394f;
          case 0x2a:
            goto code_r0x004619b8;
          case 0x2b:
            goto code_r0x00461139;
          case 0x2e:
            goto code_r0x0046108e;
          case 0x31:
          case 0x43:
            goto code_r0x00460530;
          case 0x36:
          case 0x37:
          case 0x38:
          case 0x39:
            goto LAB_00460b94;
          case 0x3a:
            goto LAB_004613dc;
          case 0x3b:
            goto LAB_004614da;
          case 0x3c:
            goto LAB_00461555;
          case 0x3e:
          case 0x3f:
            goto LAB_004615de;
          }
        }
        DAT_020527cc = DAT_020527cc + 1;
        *(int *)(puVar3 + -0x50c) = *(int *)(puVar3 + -0x50c) + -1;
      } while (0 < *(int *)(puVar3 + -0x50c));
      if ((_DAT_020b8ea0 & 0xffff) == 0x4356) {
        ffree(fVar9);
        fVar9 = (float10)thunk_FUN_00577f17();
        *(undefined4 *)(puVar3 + -0x508) = 0;
        goto LAB_00467fb8;
      }
      if (((_DAT_020b8ea0 & 0xffff) != 0x5350) && ((_DAT_020b8ea0 & 0xffff) != 0x4750)) {
        if ((_DAT_020b8ea0 & 0xff) == 0x5a) {
          *(undefined4 *)(puVar3 + -0x500) = 0;
          goto LAB_00461690;
        }
        if (_DAT_020b8ea0 == 0x544c4644) {
          *(float *)(&DAT_01c5891c + DAT_01c589e8 * 4) = f_0;
          *(undefined4 *)(puVar3 + -0x4fc) = 0;
          goto LAB_00467f93;
        }
        if ((_DAT_020b8ea0 & 0xffffff) == 0x2d4344) {
          *(undefined4 *)(puVar3 + -0x4f8) = 0;
          goto code_r0x004619b8;
        }
        if (((((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4f) || (DAT_020b8ea0._1_1_ == 'O')) ||
            ((_DAT_020b8ea0 & 0xffff) == 0x5052)) || (_DAT_020b8ea0 == 0x564e4952)) {
          *(undefined4 *)(puVar3 + -0x4f4) = 0;
        }
        else {
          if (((DAT_020b8ea0._1_1_ == 'P') || (DAT_020b8ea0._1_1_ == 'I')) ||
             (DAT_020b8ea0._1_1_ == 'C')) {
            if ((((_DAT_020b8ea0 & 0xff) == 0x44) || ((_DAT_020b8ea0 & 0xff) == 0x55)) ||
               (((_DAT_020b8ea0 & 0xff) == 0x4c || ((_DAT_020b8ea0 & 0xff) == 0x52)))) {
              *(undefined4 *)(puVar3 + -0x4ec) = 0;
              goto code_r0x00461c81;
            }
          }
          else {
            *(undefined4 *)(puVar3 + -0x4f0) = 0;
          }
          fVar1 = P3;
          if ((_DAT_020b8ea0 & 0xff) == 0x2f) {
            if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x2f) {
              P1 = P2;
              *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
              *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
              *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
              P2 = *(float *)(&DAT_020b943c + *(int *)(puVar3 + -0x5d0) * 4);
              ffree(fVar9);
              fVar9 = (float10)thunk_FUN_0054c590(&P4,&P3,&DAT_00761a98);
              *(undefined4 *)(puVar3 + -0x4e0) = 0;
            }
            else {
              P1 = P2;
              *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
              *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
              *(int *)(puVar3 + -0x5d0) = (int)ROUND(P2);
              P2 = P3 + *(float *)(&DAT_020b943c + *(int *)(puVar3 + -0x5d0) * 4);
              ffree(fVar9);
              fVar9 = (float10)thunk_FUN_0054c590(&P4,&P3,&DAT_00761a98);
              *(undefined4 *)(puVar3 + -0x4e4) = 0;
            }
            goto LAB_00467fb8;
          }
          *(undefined4 *)(puVar3 + -0x4e8) = 0;
        }
        if ((_DAT_020b8ea0 & 0xffff) == 0x5252) {
          ffree(fVar9);
          fVar9 = (float10)thunk_FUN_00488a8d();
          DAT_0078b4e0 = -1;
          *(undefined4 *)(puVar3 + -0x4d8) = 0;
          goto LAB_00467fb8;
        }
        *(undefined4 *)(puVar3 + -0x4dc) = 0;
        switch(DAT_020b8e50) {
        case 1:
        case 2:
        case 3:
          goto code_r0x00467124;
        case 4:
        case 5:
        case 6:
          goto LAB_00462a86;
        case 7:
          goto LAB_00461d2f;
        case 8:
          goto LAB_004630ad;
        case 9:
        case 0xb:
          goto LAB_0046392a;
        case 10:
          goto LAB_0046327b;
        case 0xc:
          goto code_r0x0046394f;
        case 0xd:
          goto LAB_00467fb8;
        case 0xe:
          goto LAB_00465ad6;
        case 0xf:
          goto LAB_00466191;
        case 0x10:
          goto LAB_004663cc;
        case 0x11:
          goto LAB_004668f4;
        case 0x12:
          goto LAB_00466f9f;
        }
LAB_00467b25:
        if (DAT_008244cc == f_0) {
          *(undefined4 *)(puVar3 + -0x4d4) = 0;
          goto LAB_00467b42;
        }
        P1 = f_3;
        P2 = DAT_008244cc;
        P3 = f_0;
        goto LAB_00467ece;
      }
      P2 = f_0;
      _DAT_020b8ea0 = CONCAT12(DAT_00761b88,DAT_020b8ea0);
      *(undefined4 *)(puVar3 + -0x504) = 0;
    }
    *(undefined4 *)(puVar3 + -0x510) = 0;
    goto LAB_00467fb8;
  case 'E':
    DAT_01c58930 = f_79;
    *(undefined4 *)(puVar3 + -0x574) = 0;
    break;
  case 'F':
    if (DAT_020b8ea0._1_1_ == 'L') {
      *(undefined4 *)(puVar3 + -0x570) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761c0c;
    if (DAT_020b8ea0._1_1_ == 'F') {
      DAT_01c58930 = _UNK_00761c08;
    }
    if (DAT_020b8ea2 == 'F') {
      DAT_01c58930 = _UNK_00761c04;
    }
    if (DAT_020b8ea3 == 0x46) {
      DAT_01c58930 = f_59;
    }
    if (DAT_020b8ea0._1_1_ == 'P') {
      DAT_01c58930 = _UNK_00761bfc;
    }
    if (DAT_020b8ea0._1_1_ == 'E') {
      DAT_01c58930 = _UNK_00761bf8;
    }
    *(undefined4 *)(puVar3 + -0x56c) = 0;
    break;
  case 'G':
    if (DAT_020b8ea0._1_1_ == 'R') {
      *(undefined4 *)(puVar3 + -0x568) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761bf4;
    *(undefined4 *)(puVar3 + -0x564) = 0;
    break;
  case 'H':
    DAT_01c58930 = f_36;
    if (DAT_020b8ea0._1_1_ == 'A') {
      DAT_01c58930 = f_30;
    }
    *(undefined4 *)(puVar3 + -0x560) = 0;
    break;
  case 'I':
    if (DAT_020b8ea0._1_1_ != 'N') {
      *(undefined4 *)(puVar3 + -0x55c) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761be8;
    *(undefined4 *)(puVar3 + -0x558) = 0;
    break;
  case 'L':
    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) != &UNK_00474f4c) {
      *(undefined4 *)(puVar3 + -0x554) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761be4;
    *(undefined4 *)(puVar3 + -0x550) = 0;
    break;
  case 'M':
    DAT_01c58930 = _UNK_00761be0;
    if (DAT_020b8ea0._1_1_ == 'F') {
      DAT_01c58930 = _UNK_00761bdc;
    }
    if (DAT_020b8ea0._1_1_ == 'O') {
      DAT_01c58930 = _UNK_00761bd8;
    }
    if (DAT_020b8ea2 == 'R') {
      DAT_01c58930 = _UNK_00761bd4;
    }
    *(undefined4 *)(puVar3 + -0x54c) = 0;
    break;
  case 'P':
    if (DAT_020b8ea0._1_1_ == '*') {
      *(undefined4 *)(puVar3 + -0x548) = 0;
      goto LAB_0045fa18;
    }
    if (DAT_020b8ea0._1_1_ == 'G') {
      *(undefined4 *)(puVar3 + -0x544) = 0;
      goto LAB_004614da;
    }
    if (DAT_020b8ea0._1_1_ != 'S') {
      DAT_01c58930 = _UNK_00761bd0;
      if (DAT_020b8ea0._1_1_ == 'P') {
        DAT_01c58930 = _UNK_00761bcc;
      }
      if (DAT_020b8ea2 == 'P') {
        DAT_01c58930 = _UNK_00761bc8;
      }
      if (DAT_020b8ea3 == 0x50) {
        DAT_01c58930 = _UNK_00761bc4;
      }
      if (DAT_020b8ea0._1_1_ == 'I') {
        DAT_01c58930 = _UNK_00761bc0;
      }
      if (DAT_020b8ea0._1_1_ == 'O') {
        DAT_01c58930 = _UNK_00761bbc;
      }
      if (DAT_020b8ea0._1_1_ == 'L') {
        DAT_01c58930 = _UNK_00761bb8;
      }
      if (DAT_020b8ea0._1_1_ == 'E') {
        DAT_01c58930 = _UNK_00761bb4;
      }
      *(undefined4 *)(puVar3 + -0x53c) = 0;
      break;
    }
    *(undefined4 *)(puVar3 + -0x540) = 0;
LAB_004613dc:
    fVar1 = P2;
    *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
    *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
    DAT_01be6d48 = *(int *)(puVar3 + -0x5d0);
    *(undefined4 *)(&DAT_01be6cdc + DAT_01be6d48 * 4) =
         *(undefined4 *)(&DAT_020b943c + DAT_01be6d48 * 4);
    FUN_005f33c9(puVar3,&LAB_00461453);
    Var8 = FUN_005f34d1(puVar3,&LAB_0046146e);
    *(undefined4 *)(puVar3 + -0x5cc) = 0;
    *(undefined4 *)(puVar3 + -0x5e0) = 2;
    *(undefined4 *)(puVar3 + -0x5dc) = 0x9ae2bd;
    *(int **)(puVar3 + -0x5d8) = &DAT_01be6d48;
    ffree(Var8);
    fVar9 = (float10)FUN_005f34f0(puVar3 + -0x5cc,0x784ff00,&DAT_00761c4c,puVar3 + -0x5e0,
                                  &DAT_00790a08);
    *(undefined4 *)(puVar3 + -0x90) = 0;
    goto LAB_00467fb8;
  case 'R':
    if (((_DAT_020b8ea0 & 0xffffff) != 0x4c4152) &&
       ((undefined *)(_DAT_020b8ea0 & 0xffffff) != &UNK_00544952)) {
      *(undefined4 *)(puVar3 + -0x538) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761bb0;
    if (DAT_020b8ea2 == 'T') {
      DAT_01c58930 = _UNK_00761bac;
    }
    *(undefined4 *)(puVar3 + -0x534) = 0;
    break;
  case 'S':
    if (((DAT_020b8ea0._1_1_ != 'F') && (DAT_020b8ea0._1_1_ != 'T')) && (DAT_020b8ea0._1_1_ != 'U'))
    {
      *(undefined4 *)(puVar3 + -0x530) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761ba8;
    if (DAT_020b8ea0._1_1_ == 'T') {
      DAT_01c58930 = _UNK_00761ba4;
    }
    if (DAT_020b8ea0._1_1_ == 'F') {
      DAT_01c58930 = _UNK_00761ba0;
    }
    if (DAT_020b8ea2 == 'Z') {
      DAT_01c58930 = _UNK_00761b9c;
    }
    *(undefined4 *)(puVar3 + -0x52c) = 0;
    break;
  case 'T':
    if (DAT_020b8ea0._1_1_ != 'E') {
      *(undefined4 *)(puVar3 + -0x528) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761b98;
    if (DAT_020b8ea3 == 0x53) {
      DAT_01c58930 = _UNK_00761b94;
    }
    *(undefined4 *)(puVar3 + -0x524) = 0;
    break;
  case 'U':
    if (DAT_020b8ea2 != 'B') {
      *(undefined4 *)(puVar3 + -0x520) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = _UNK_00761b90;
    *(undefined4 *)(puVar3 + -0x51c) = 0;
    break;
  case 'W':
    if (DAT_020b8ea0._1_1_ == 'H') {
      *(undefined4 *)(puVar3 + -0x518) = 0;
      goto LAB_0045fa18;
    }
    DAT_01c58930 = f_21;
    if (DAT_020b8ea3 == 0x53) {
      DAT_01c58930 = f_25;
    }
    break;
  case 'X':
  case 'Y':
  case 'Z':
code_r0x00467124:
    if ((_DAT_020b8ea0 & 0xff) == 0x54) {
      if ((DAT_020b8e50 == 3) && (DAT_020b8ea0._1_1_ == 'R' || DAT_020b8ea0._1_1_ == 'E')) {
        *(undefined4 *)(puVar3 + -0x3b0) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x3b4) = 0;
    }
    goto LAB_00467bf0;
  case '^':
LAB_00461d2f:
    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) != &DAT_00464f58) {
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00464f4c) {
        _DAT_01c58958 = P2;
        if (DAT_020b8ea4 == 'P') {
          _DAT_01c58958 = DAT_020b9478 + f_0_5;
        }
        if (DAT_020b8ea4 == 'M') {
          _DAT_01c58958 = DAT_020b9478 - f_0_5;
        }
        *(undefined4 *)(puVar3 + -0x370) = 0;
        goto LAB_00467f93;
      }
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) != &DAT_00464f52) {
        if ((_DAT_020b8ea0 & 0xff) != 0x4f) {
          if ((_DAT_020b8ea0 & 0xffffff) == 0x4f4c4c) {
            if (DAT_020b8ea4 == 'P') {
              _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00761c44);
            }
            *(undefined4 *)(puVar3 + -0x35c) = 0;
            goto LAB_00466fdb;
          }
          *(undefined4 *)(puVar3 + -0x360) = 0;
          if ((_DAT_020b8ea0 & 0xff) != 0x52) {
            if ((_DAT_020b8ea0 & 0xff) == 0x48) goto LAB_0046202c;
            *(undefined4 *)(puVar3 + -0x354) = 0;
            goto LAB_0046247f;
          }
          *(undefined4 *)(puVar3 + -0x358) = 0;
          goto LAB_00462a86;
        }
        DAT_01c5894c = f_m1;
        _DAT_01c58938 = f_8;
        if (DAT_020b8ea0._1_1_ == 'M') {
          _DAT_01c58938 = f_15;
        }
        if (DAT_020b8ea0._1_1_ == 'B') {
          fVar9 = (float10)_DAT_01c58938;
          _DAT_01c58938 = (float)-fVar9;
          DAT_01c5894c = f_1;
          DAT_01c58948 = f_0;
        }
        if (_DAT_020b8ea0 == 0x5541564f) {
          _DAT_01c58938 = f_88;
        }
        if (_DAT_020b8ea0 == 0x4441564f) {
          _DAT_01c58938 = f_m88;
          DAT_01c5894c = f_1;
        }
        if (_DAT_020b8ea0 == 0x55414d4f) {
          _DAT_01c58938 = f_155;
        }
        ffree(fVar9);
        fVar9 = (float10)FUN_00468df8(&DAT_00761a7c);
        *(undefined4 *)(puVar3 + -0x364) = 0;
        goto LAB_00467f93;
      }
      if (DAT_020b9458 != f_1) {
        if (DAT_020b8ea4 == 'P') {
          P2 = DAT_020b9484 + f_0_5;
        }
        if (DAT_020b8ea4 == 'M') {
          P2 = DAT_020b9484 - f_0_5;
        }
        DAT_01c5895c = f_1;
        if (P2 == f_0) {
          DAT_01c5895c = f_0;
        }
        DAT_01c58964 = P2;
        *(undefined4 *)(puVar3 + -0x368) = 0;
        goto LAB_00467f93;
      }
      *(undefined4 *)(puVar3 + -0x36c) = 0;
      goto LAB_0046288b;
    }
    _DAT_01c58958 = f_0;
    DAT_01c5895c = f_0;
    _DAT_01c58960 = f_0;
    DAT_01c58964 = f_0;
    *(undefined4 *)(puVar3 + -0x374) = 0;
    goto LAB_00467f93;
  case '_':
LAB_004630ad:
    if ((_DAT_020b8ea0 & 0xffff) == 0x4953) {
      fVar9 = (float10)DAT_020b9458;
      _DAT_01c58938 = (float)-fVar9;
      if (_DAT_01c58938 == f_0) {
        _DAT_01c58938 = f_m1;
      }
      if (DAT_020b9458 == f_m1) {
        _DAT_01c58938 = f_0;
      }
      *(undefined4 *)(puVar3 + -0x2c4) = 0;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x4f4d4e) {
      DAT_01c5894c = f_1;
      if (DAT_020b946c != f_0) {
        DAT_01c5894c = f_0;
      }
      *(undefined4 *)(puVar3 + -0x2c0) = 0;
    }
    else {
      if ((_DAT_020b8ea0 & 0xffffff) == 0x205254) {
        *(undefined4 *)(puVar3 + -700) = 0;
        goto LAB_004673f4;
      }
      if ((_DAT_020b8ea0 & 0xffff) != 0x5a53) {
        *(undefined4 *)(puVar3 + -0x2b8) = 0;
LAB_00467b42:
        ffree(fVar9);
        fVar9 = (float10)thunk_FUN_0054d7d4(&DAT_020b8ea0,5);
        DAT_009a9494 = 99;
        DAT_0078b4e0 = 9999;
        *(undefined4 *)(puVar3 + -0xc) = 0;
        goto LAB_00467fb8;
      }
      DAT_01c58930 = DAT_020b9450;
      if (DAT_020b9450 == f_0) {
        DAT_01c58930 = f_1;
      }
      if (DAT_020b8ea2 == '+') {
        DAT_01c58930 = DAT_01c58930 + f_0_01;
      }
      if (DAT_020b8ea2 == '-') {
        DAT_01c58930 = DAT_01c58930 - f_0_01;
      }
      if (DAT_020b8ea2 == '*') {
        DAT_01c58930 = P2;
        if (P2 == f_0) {
          DAT_01c58930 = f_1;
        }
        *(undefined4 *)(puVar3 + -0x2b0) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x2b4) = 0;
      }
    }
    goto LAB_00467f93;
  case '`':
  case 'b':
LAB_0046392a:
    if ((_DAT_020b8ea0 & 0xffff) != 17999) {
      *(undefined4 *)(puVar3 + -0x2ac) = 0;
      goto LAB_00467070;
    }
LAB_00466fdb:
    _DAT_01c58958 = f_0_5;
    if (((DAT_020b8ea4 == 'M') || ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4c)) ||
       ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4d)) {
      fVar9 = (float10)f_0_5;
      _DAT_01c58958 = (float)-fVar9;
    }
    _DAT_01c58958 = _DAT_01c58958 + DAT_020b9478;
    *(undefined4 *)(puVar3 + -0x2a8) = 0;
    goto LAB_00467f93;
  case 'a':
LAB_0046327b:
    DAT_008244ac = 5;
    if (f_999 < DAT_020b9484) {
      DAT_008244ac = 0x12;
    }
    if ((_DAT_020b8ea0 & 0xffff) == 0x4c50) {
      *(float *)(&DAT_01c5891c + DAT_008244ac * 4) =
           P2 + *(float *)(&DAT_020b943c + DAT_008244ac * 4);
    }
    else if ((_DAT_020b8ea0 & 0xffff) == 0x494d) {
      *(float *)(&DAT_01c5891c + DAT_008244ac * 4) =
           *(float *)(&DAT_020b943c + DAT_008244ac * 4) - P2;
    }
    else if (_DAT_020b8ea0 == 0x58525053) {
      _DAT_01c5896c = f_0;
      _DAT_020b8ea0 = 0x20202020;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x525053) {
      DAT_008244b4 = DAT_020b948c;
      _DAT_020b8ea0 = 0x20202020;
      if (DAT_020b948c == f_0) {
        DAT_008244b4 = f_1;
      }
      _DAT_01c5896c = DAT_008244b4 + f_0_02;
    }
    else if ((_DAT_020b8ea0 & 0xffff) == 0x554e) {
      DAT_01c58930 = P2;
      DAT_01c58964 = f_0;
    }
    else if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00435842) {
      DAT_01c5893c = DAT_020b945c + f_1;
      if (f_2 < DAT_01c5893c) {
        DAT_01c5893c = f_0;
      }
    }
    else if (DAT_020b8ea4 == 'S' && _DAT_020b8ea0 == 0x54504c41) {
      ffree(fVar9);
      fVar9 = (float10)amod(&DAT_020b9454,&f_100);
      DAT_01c58934 = (float)(fVar9 + (float10)f_100);
      fVar9 = extraout_ST1_06;
    }
    else if (DAT_020b8ea4 == 'S' && _DAT_020b8ea0 == 0x54504f4e) {
      ffree(fVar9);
      fVar9 = (float10)amod(&DAT_020b9454,&f_100);
      DAT_01c58934 = (float)(fVar9 + (float10)f_200);
      fVar9 = extraout_ST1_07;
    }
    else if (_DAT_020b8ea0 == 0x4d524f4e) {
      ffree(fVar9);
      fVar9 = (float10)amod(&DAT_020b9454,&f_100);
      DAT_01c58934 = (float)fVar9;
      fVar9 = extraout_ST1_08;
    }
    else if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544e46) {
      _DAT_01c58938 = P2 + f_1000;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x4e4f46) {
      _DAT_01c58938 = f_0;
    }
    else if (_DAT_020b8ea0 == 0x20445342) {
      DAT_01c58948 = f_0;
      DAT_01c5894c = f_0;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x4b4854) {
      DAT_01c58944 = DAT_020b9464 + f_1;
      if (_DAT_020b90a0 >> 0x18 == 0x30) {
        DAT_01c58944 = f_0;
      }
    }
    else {
      if ((_DAT_020b8ea0 & 0xffff) != 0x5842) {
        bVar6 = (undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f52;
        if (!bVar6) {
          iVar2 = 1;
          piVar4 = (int *)((int)&DAT_020b8ea0 + 1);
          piVar5 = &DAT_00761a28;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *piVar4 == *piVar5;
            piVar4 = piVar4 + 1;
            piVar5 = piVar5 + 1;
          } while (bVar6);
          if ((!bVar6) && ((_DAT_020b8ea0 & 0xffff) != 0x5a53)) {
            if ((_DAT_020b8ea0 & 0xffffff) == 0x525055) {
              DAT_01c58930 = f_1001;
              DAT_01c58964 = f_0;
              fVar9 = (float10)FUN_005f34d1(puVar3,0x46384f);
            }
            else if (((_DAT_020b8ea0 & 0xffff) == 0x574c) || ((_DAT_020b8ea0 & 0xffff) == 0x4f4c)) {
              DAT_01c58930 = f_2001;
              DAT_01c58964 = f_0;
            }
            goto LAB_00463891;
          }
        }
        *(undefined4 *)(puVar3 + -0x25c) = 0;
        goto LAB_0046392a;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x20) {
        if ((DAT_020b8ea2 == 'U') || (DAT_020b8ea2 == 'D')) {
          DAT_01c58950 = DAT_020b9470 + f_0_2;
          if (DAT_020b8ea2 == 'D') {
            DAT_01c58950 = DAT_020b9470 - f_0_2;
          }
        }
        else if (DAT_020b8ea2 == 'N') {
          DAT_01c58950 = f_0;
          _DAT_01c58954 = f_0;
        }
        else {
          _DAT_01c58954 = DAT_020b9474 + f_0_2;
          if (DAT_020b8ea2 == 'L') {
            _DAT_01c58954 = DAT_020b9474 - f_0_2;
          }
        }
      }
      else {
        if (DAT_020b9468 == f_0) {
          DAT_01c58948 = f_6;
        }
        if (DAT_020b946c == f_0) {
          DAT_01c5894c = f_6;
        }
        DAT_008244ac = 0xc;
        if (DAT_020b8ea2 == 'H') {
          DAT_008244ac = 0xb;
        }
        *(undefined4 *)(&DAT_01c5891c + DAT_008244ac * 4) =
             *(undefined4 *)(&DAT_020b943c + DAT_008244ac * 4);
        if (*(float *)(&DAT_01c5891c + DAT_008244ac * 4) == f_0) {
          *(float *)(&DAT_01c5891c + DAT_008244ac * 4) = f_4;
        }
        DAT_008244b4 = f_0_2;
        if (_DAT_020b8ea0 >> 0x18 == 0x4d) {
          fVar9 = (float10)f_0_2;
          DAT_008244b4 = (float)-fVar9;
        }
        *(float *)(&DAT_01c5891c + DAT_008244ac * 4) =
             DAT_008244b4 + *(float *)(&DAT_01c5891c + DAT_008244ac * 4);
      }
    }
LAB_00463891:
    if ((_DAT_020b8ea0 & 0xffff) == 17999) {
      *(undefined4 *)(puVar3 + -600) = 0;
      goto LAB_00466fdb;
    }
    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) != &DAT_00464f4e) {
      if (((_DAT_020b8ea0 & 0xff) == 0x54) && ((_DAT_020b8ea0 & 0xffffff) != 0x4b4854)) {
        *(undefined4 *)(puVar3 + -0x250) = 0;
        goto LAB_004673f4;
      }
      *(undefined4 *)(puVar3 + -0x24c) = 0;
      goto LAB_00467f93;
    }
    *(undefined4 *)(puVar3 + -0x254) = 0;
LAB_00467070:
    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00464f4e) {
      _DAT_01c58958 = f_0;
      *(undefined4 *)(puVar3 + -0x2a0) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0x2a4) = 0;
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f52) {
        DAT_008244ac = 9;
        if (DAT_020b8e50 == 10) {
          DAT_008244ac = 0x13;
        }
        *(float *)(&DAT_01c5891c + DAT_008244ac * 4) = f_0;
        if (_DAT_020b8ea0 >> 0x18 == 0x2d) {
          *(float *)(&DAT_01c5891c + DAT_008244ac * 4) =
               *(float *)(&DAT_020b943c + DAT_008244ac * 4) - f_10;
        }
        if (_DAT_020b8ea0 >> 0x18 == 0x2b) {
          *(float *)(&DAT_01c5891c + DAT_008244ac * 4) =
               *(float *)(&DAT_020b943c + DAT_008244ac * 4) + f_10;
        }
        *(undefined4 *)(puVar3 + -0x298) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x29c) = 0;
LAB_004670ba:
        if ((_DAT_020b8ea0 & 0xffff) == 0x5a53) {
          if ((DAT_020b9458 == f_0) || (DAT_020b8e50 == 10)) {
            *(undefined4 *)(puVar3 + -0x290) = 0;
            goto code_r0x0046754a;
          }
          ffree(fVar9);
          fVar9 = (float10)amod(&DAT_020b9454,&f_100);
          DAT_01c58934 = (float)fVar9;
          *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
          *(int *)(puVar3 + -0x5d0) = (int)ROUND(DAT_01c58934 / f_100);
          DAT_008244ac = *(int *)(puVar3 + -0x5d0);
          if (DAT_01c58934 == f_0) {
            DAT_01c58934 = f_1;
          }
          DAT_008244b4 = DAT_01c58934 / DAT_020b9458;
          *(undefined4 *)(puVar3 + -0x28c) = 0;
          fVar9 = extraout_ST1_21;
          goto LAB_004675d5;
        }
        *(undefined4 *)(puVar3 + -0x294) = 0;
        if ((_DAT_020b8ea0 & 0xffffff) == 0x42494c) {
          ffree(fVar9);
          fVar9 = (float10)thunk_FUN_00554a38();
          if (P1 < f_0) {
            *(undefined4 *)(puVar3 + -0x280) = 0;
            goto LAB_00467fb8;
          }
          DAT_01c58920 = f_9;
          DAT_01c58930 = P1;
          *(undefined4 *)(puVar3 + -0x27c) = 0;
        }
        else {
          *(undefined4 *)(puVar3 + -0x284) = 0;
          if ((_DAT_020b8ea0 & 0xffffff) == 0x425055) {
            *(undefined4 *)(puVar3 + -0x278) = 0;
            goto code_r0x00467124;
          }
          if (((_DAT_020b8ea0 & 0xffffff) == 0x205254) || ((_DAT_020b8ea0 & 0xffff) == 0x2054)) {
            *(undefined4 *)(puVar3 + -0x274) = 0;
            goto LAB_004673f4;
          }
          if ((_DAT_020b8ea0 & 0xffff) != 0x7e7e) {
            *(undefined4 *)(puVar3 + -0x270) = 0;
            goto code_r0x004671e9;
          }
          if ((P2 != f_117) && (P2 != f_121)) {
            *(undefined4 *)(puVar3 + -0x26c) = 0;
            goto LAB_00467fb8;
          }
          DAT_01c58930 = DAT_020b9450 + f_1;
          if (P2 == f_121) {
            DAT_01c58930 = DAT_01c58930 - f_2;
          }
          *(undefined4 *)(puVar3 + -0x268) = 0;
        }
      }
    }
    goto LAB_00467f93;
  case 'd':
    goto LAB_00467fb8;
  case 'e':
LAB_00465ad6:
    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00524142) {
      DAT_01c58930 = f_0;
      if (P2 != f_0) {
        DAT_01c5892c = P2;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x44) {
        DAT_01c58930 = f_1;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x48) {
        DAT_01c58930 = f_2;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x4c) {
        DAT_01c58930 = f_3;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x52) {
        DAT_01c58930 = f_4;
      }
      if (DAT_020b8ea4 == 'D') {
        DAT_01c58930 = f_5;
      }
      if (DAT_01c58930 < f_3) {
        DAT_01c5895c = f_0;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x42) {
        DAT_01c5893c = f_0;
        if ((DAT_0082447c == 0x20202020) && (DAT_020b944c < f_2)) {
          DAT_01c5892c = f_2;
        }
        DAT_01c58930 = f_8;
        if (DAT_020b8ea4 == 'K') {
          DAT_01c58930 = f_9;
        }
        *(undefined4 *)(puVar3 + -0x1a8) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x1ac) = 0;
      }
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x485344) {
      if (_DAT_020b8ea0 >> 0x18 == 0x2b) {
        DAT_01c5893c = DAT_020b945c + f_0_2;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x2a) {
        DAT_01c5893c = f_0;
      }
      *(undefined4 *)(puVar3 + -0x1a4) = 0;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x505344) {
      if (_DAT_020b8ea0 >> 0x18 == 0x2b) {
        DAT_01c58940 = DAT_020b9460 + f_0_2;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x2a) {
        DAT_01c58940 = f_0;
      }
      *(undefined4 *)(puVar3 + -0x1a0) = 0;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x535444) {
      _DAT_01c58954 = DAT_020b9474 + f_0_2;
      if (_DAT_020b8ea0 >> 0x18 == 0x2a) {
        _DAT_01c58954 = f_0;
      }
      *(undefined4 *)(puVar3 + -0x19c) = 0;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x4c5444) {
      DAT_01c5895c = DAT_020b947c;
      if (DAT_020b947c == f_0) {
        DAT_01c5895c = f_608;
      }
      if ((f_200 < DAT_01c5895c) && (_DAT_020b8ea0 >> 0x18 == 0x44)) {
        DAT_01c5895c = DAT_01c5895c - f_200;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x55) {
        DAT_01c5895c = DAT_01c5895c + f_200;
      }
      *(undefined4 *)(puVar3 + -0x198) = 0;
    }
    else if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00485444) {
      DAT_01c5895c = DAT_020b947c;
      if (DAT_020b947c == f_0) {
        DAT_01c5895c = f_608;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x44) {
        DAT_01c5895c = DAT_01c5895c - f_2;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x55) {
        DAT_01c5895c = DAT_01c5895c + f_2;
      }
      *(undefined4 *)(puVar3 + -0x194) = 0;
    }
    else if (_DAT_020b8ea0 == 0x53524244) {
      if (DAT_020b8ea4 == '+') {
        DAT_01c58950 = DAT_020b9470 + f_0_2;
      }
      if (DAT_020b8ea4 == '*') {
        DAT_01c58950 = f_0;
      }
      *(undefined4 *)(puVar3 + -400) = 0;
    }
    else if (_DAT_020b8ea0 == 0x57524244) {
      if (DAT_020b8ea4 == '+') {
        _DAT_01c58960 = DAT_020b9480 + f_0_05;
      }
      if (DAT_020b9480 == f_0) {
        _DAT_01c58960 = f_0_75;
      }
      if (DAT_020b8ea4 == '*') {
        _DAT_01c58960 = f_0;
      }
      *(undefined4 *)(puVar3 + -0x18c) = 0;
    }
    else if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f42) {
      DAT_01c58944 = DAT_020b9464;
      if (DAT_020b9464 == f_0) {
        DAT_01c58944 = f_3;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x44) {
        DAT_01c58944 = DAT_01c58944 - f_1;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x55) {
        DAT_01c58944 = DAT_01c58944 + f_1;
      }
      *(undefined4 *)(puVar3 + -0x188) = 0;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x504f54) {
      DAT_01c58948 = DAT_020b9468;
      if (DAT_020b9468 == f_0) {
        DAT_01c58948 = f_11;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x44) {
        DAT_01c58948 = DAT_01c58948 - f_1;
      }
      if (_DAT_020b8ea0 >> 0x18 == 0x55) {
        DAT_01c58948 = DAT_01c58948 + f_1;
      }
      *(undefined4 *)(puVar3 + -0x184) = 0;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x564e49) {
      fVar9 = (float10)DAT_020b944c;
      DAT_01c5892c = (float)-fVar9;
      *(undefined4 *)(puVar3 + -0x180) = 0;
    }
    else {
      if ((_DAT_020b8ea0 & 0xffffff) != 0x444e45) {
        if ((_DAT_020b8ea0 & 0xffff) == 17999) {
          *(undefined4 *)(puVar3 + -0x178) = 0;
          goto LAB_00466fdb;
        }
        if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00464f4e) {
          *(undefined4 *)(puVar3 + -0x174) = 0;
          goto LAB_00467070;
        }
        if ((_DAT_020b8ea0 & 0xff) != 0x54) {
          *(undefined4 *)(puVar3 + -0x16c) = 0;
          goto LAB_00467fb8;
        }
        *(undefined4 *)(puVar3 + -0x170) = 0;
        goto LAB_004673f4;
      }
      DAT_01c58928 = DAT_01fbb8b8;
      *(undefined4 *)(puVar3 + -0x17c) = 0;
    }
    goto LAB_00467f93;
  case 'f':
LAB_00466191:
    if ((_DAT_020b8ea0 & 0xffffff) == 0x2d5a53) {
      DAT_01c58930 = DAT_020b9450 - f_0_1;
      DAT_01c58934 = f_0;
    }
    else if ((_DAT_020b8ea0 & 0xffffff) == 0x2b5a53) {
      DAT_01c58930 = DAT_020b9450 + f_0_1;
      DAT_01c58934 = f_0;
    }
    else if (((_DAT_020b8ea0 & 0xffffff) == 0x2a5a53) || ((_DAT_020b8ea0 & 0xffffff) == 0x445342)) {
      DAT_01c58930 = f_1;
      DAT_01c58934 = f_0;
    }
    else if (_DAT_020b8ea0 == 0x50485842) {
      if (DAT_020b9454 == f_0) {
        DAT_01c58934 = DAT_020b9450;
      }
      DAT_01c58930 = DAT_020b9450 + f_0_1;
    }
    else if (_DAT_020b8ea0 == 0x4d485842) {
      if (DAT_020b9454 == f_0) {
        DAT_01c58934 = DAT_020b9450;
      }
      DAT_01c58930 = DAT_020b9450 - f_0_1;
    }
    else if (_DAT_020b8ea0 == 0x50565842) {
      DAT_01c58934 = DAT_020b9454 + f_0_1;
    }
    else if (_DAT_020b8ea0 == 0x4d565842) {
      DAT_01c58934 = DAT_020b9454 - f_0_1;
    }
    else if (_DAT_020b8ea0 == 0x2b544f52) {
      DAT_01c5894c = DAT_020b946c + f_10;
    }
    else if (_DAT_020b8ea0 == 0x2d544f52) {
      DAT_01c5894c = DAT_020b946c - f_10;
    }
    else if (_DAT_020b8ea0 == 0x2a544f52) {
      DAT_01c5894c = f_0;
    }
    if ((_DAT_020b8ea0 & 0xff) != 0x54) {
      *(undefined4 *)(puVar3 + -0x164) = 0;
      goto LAB_00467f93;
    }
    *(undefined4 *)(puVar3 + -0x168) = 0;
    goto LAB_004673f4;
  case 'g':
LAB_004663cc:
    if ((_DAT_020b8ea0 & 0xffff) == 0x5254) {
      ffree(fVar9);
      fVar9 = (float10)thunk_FUN_0054d7d4(&DAT_007619d0,2);
      DAT_0078b4e0 = 9999;
      DAT_009a9494 = 99;
      *(undefined4 *)(puVar3 + -0x160) = 0;
      goto LAB_00467fb8;
    }
    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) != &DAT_00544e46) {
      if ((_DAT_020b8ea0 & 0xffffff) == 0x4e4f46) {
        DAT_01c5893c = f_0;
        goto LAB_00467eb5;
      }
      if ((_DAT_020b8ea0 & 0xffffff) == 0x534843) {
        DAT_008244b4 = f_0_02;
        DAT_01c58930 = DAT_020b9450;
        if (DAT_020b9450 == f_0) {
          DAT_01c58930 = f_1;
        }
        if (DAT_020b8ea3 == 0x4d) {
          fVar9 = (float10)f_0_02;
          DAT_008244b4 = (float)-fVar9;
        }
        DAT_01c58930 = DAT_008244b4 + DAT_01c58930;
        if (DAT_020b8ea3 == 0x44) {
          DAT_01c58930 = f_0;
        }
        goto LAB_00467eb5;
      }
      if ((_DAT_020b8ea0 & 0xffffff) == 0x535053) {
        DAT_008244b4 = f_0_2;
        if (DAT_020b8ea3 == 0x4d) {
          fVar9 = (float10)f_0_2;
          DAT_008244b4 = (float)-fVar9;
        }
        DAT_01c58944 = DAT_008244b4 + DAT_020b9464;
        if (DAT_020b8ea3 == 0x44) {
          DAT_01c58944 = f_0;
        }
        goto LAB_00467eb5;
      }
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00544f52) {
        *(undefined4 *)(puVar3 + -0x15c) = 0;
        goto LAB_00467070;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 17999) {
        DAT_008244ac = 0xb;
        DAT_01c58948 = f_0_5;
        if (((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4c) || ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x4d)) {
          fVar9 = (float10)f_0_5;
          DAT_01c58948 = (float)-fVar9;
        }
        DAT_01c58948 = DAT_020b9468 + DAT_01c58948;
LAB_00466692:
        _DAT_020b8ea0 = 0x20202020;
        *(undefined4 *)(puVar3 + -0x158) = 0;
        goto LAB_00467f93;
      }
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00464f4e) {
        DAT_01c58948 = f_0;
        *(undefined4 *)(puVar3 + -0x154) = 0;
        goto LAB_00466692;
      }
      if (((_DAT_020b8ea0 & 0xff) == 0x5b) || ((_DAT_020b8ea0 & 0xff) == 0x5d)) {
        _DAT_020b8ea0 = CONCAT22(_DAT_020b8ea2,DAT_007619c8);
        DAT_0078b4e0 = 0x54;
        *(undefined4 *)(puVar3 + -0x150) = 0;
        goto LAB_00467fb8;
      }
      if ((_DAT_020b8ea0 & 0xffff) != 0x5443) {
        if ((_DAT_020b8ea0 & 0xffff) != 0x5a53) {
          if (((((_DAT_020b8ea0 & 0xff) == 0x4c) || ((_DAT_020b8ea0 & 0xff) == 0x43)) ||
              ((_DAT_020b8ea0 & 0xff) == 0x52)) || ((_DAT_020b8ea0 & 0xff) == 0x4a)) {
            *(undefined4 *)(puVar3 + -0x140) = 0;
            goto LAB_00467fb8;
          }
          if ((_DAT_020b8ea0 & 0xffff) != 0x5450) {
            if ((_DAT_020b8ea0 & 0xffff) == 0x5854) {
              DAT_009a9494 = 99;
              *(undefined4 *)(puVar3 + -0x134) = 0;
              goto LAB_00467fb8;
            }
            *(undefined4 *)(puVar3 + -0x138) = 0;
            goto LAB_00467b42;
          }
          if (P2 == f_0) {
            *(undefined4 *)(puVar3 + -0x13c) = 0;
            goto LAB_00467fb8;
          }
          DAT_01c58934 = P2 / ((STEP * f_13_56) / f_25);
          goto LAB_00467eb5;
        }
        *(undefined4 *)(puVar3 + -0x144) = 0;
        goto LAB_004670ba;
      }
      P6 = DAT_020b9470 / f_2;
      if ((DAT_020b8ea2 == 'N') || (DAT_020b8ea2 == 'X')) {
        if (DAT_020b8ea2 == 'X') {
          DAT_01c6da40 = -1;
        }
        DAT_0078b4e4 = 0x4e;
        _DAT_020b8ea0 = CONCAT12(DAT_007619cc,DAT_020b8ea0);
        *(undefined4 *)(puVar3 + -0x14c) = 0;
        goto LAB_00467c1e;
      }
      if (P2 == f_0) {
        P2 = DAT_0078df28;
      }
      DAT_0078df28 = P2;
      DAT_01c58928 = P2 - P6;
      DAT_01c58948 = f_0;
      goto LAB_00467e94;
    }
    DAT_01c5893c = P2 + f_1000;
    goto LAB_00467eb5;
  case 'h':
LAB_004668f4:
    if ((_DAT_020b8ea0 & 0xffff) == 17999) {
      *(undefined4 *)(puVar3 + -300) = 0;
      goto LAB_00466fdb;
    }
    if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00464f4e) {
      *(undefined4 *)(puVar3 + -0x128) = 0;
      goto LAB_00467070;
    }
    if (_DAT_020b8ea0 == 0x4c46534b) {
      ffree(fVar9);
      fVar9 = (float10)amod(&DAT_020b9450,&f_100);
      DAT_01c58930 = (float)fVar9;
      if (DAT_01c58930 < f_0) {
        DAT_01c58930 = DAT_01c58930 - f_1;
      }
      else {
        DAT_01c58930 = f_m1;
      }
      fVar9 = extraout_ST1_16;
      if (DAT_01c58930 < f_m7) {
        DAT_01c58930 = f_m1;
      }
    }
    else if (_DAT_020b8ea0 == 0x4853534b) {
      ffree(fVar9);
      fVar9 = (float10)amod(&DAT_020b9450,&f_100);
      DAT_01c58930 = (float)fVar9;
      if (f_0 < DAT_01c58930) {
        DAT_01c58930 = DAT_01c58930 + f_1;
      }
      else {
        DAT_01c58930 = f_1;
      }
      fVar9 = extraout_ST1_17;
      if (f_7 < DAT_01c58930) {
        DAT_01c58930 = f_1;
      }
    }
    else if (_DAT_020b8ea0 == 0x414e534b) {
      DAT_01c58930 = DAT_020b9450;
      fVar9 = (float10)DAT_020b9450;
      if (ABS(fVar9) < (float10)f_100) {
        DAT_008244b4 = f_100;
        if (DAT_020b9450 < f_0) {
          fVar9 = (float10)f_100;
          DAT_008244b4 = (float)-fVar9;
        }
        DAT_01c58930 = DAT_008244b4 + DAT_020b9450;
      }
      else {
        ffree(fVar9);
        fVar9 = (float10)amod(&DAT_01c58930,&f_100);
        DAT_01c58930 = (float)fVar9;
        fVar9 = extraout_ST1_18;
      }
    }
    else {
      if (_DAT_020b8ea0 == 0x5254534b) {
        DAT_01c58934 = f_0;
        *(undefined4 *)(puVar3 + -0x124) = 0;
      }
      else if (_DAT_020b8ea0 == 0x4142534b) {
        DAT_01c58934 = f_1;
        *(undefined4 *)(puVar3 + -0x120) = 0;
      }
      else if (_DAT_020b8ea0 == 0x4c41534b) {
        DAT_01c58934 = f_2;
        *(undefined4 *)(puVar3 + -0x11c) = 0;
      }
      else {
        if (_DAT_020b8ea0 != 0x4e54534b) {
          if (_DAT_020b8ea0 == 0x5543534b) {
            ffree(fVar9);
            fVar9 = (float10)amod(&DAT_020b9454,&f_100);
            DAT_01c58934 = (float)(fVar9 + (float10)f_100);
            fVar9 = extraout_ST1_19;
          }
          else if (_DAT_020b8ea0 == 0x4f4e534b) {
            ffree(fVar9);
            fVar9 = (float10)amod(&DAT_020b9454,&f_100);
            DAT_01c58934 = (float)fVar9;
            fVar9 = extraout_ST1_20;
          }
          else if (_DAT_020b8ea0 == 0x554a534b) {
            _DAT_01c58954 = f_0;
          }
          else if (_DAT_020b8ea0 == 0x4a4e534b) {
            _DAT_01c58954 = f_1;
          }
          else if ((_DAT_020b8ea0 & 0xffffff) == 0x53534b) {
            _DAT_01c58938 = DAT_020b9458;
            if (DAT_020b9458 == f_0) {
              _DAT_01c58938 = f_1;
            }
            if (DAT_020b8ea3 == 0x4d) {
              _DAT_01c58938 = _DAT_01c58938 - f_0_05;
            }
            if (DAT_020b8ea3 == 0x50) {
              _DAT_01c58938 = _DAT_01c58938 + f_0_05;
            }
            if (DAT_020b8ea3 == 0x5a) {
              _DAT_01c58938 = f_0;
            }
          }
          else if (((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x2a) && ((_DAT_020b8ea0 & 0xffff) == 0x534b))
          {
            fVar1 = P2 + f_7;
            *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
            *(int *)(puVar3 + -0x5d0) = (int)ROUND(fVar1);
            DAT_0082446c = *(int *)(puVar3 + -0x5d0);
            DAT_008244b8 = *(float *)(&DAT_020b943c + DAT_0082446c * 4);
            ffree(fVar9);
            fVar9 = (float10)FUN_00469059(&DAT_008244b8,&DAT_00761a0c,&DAT_008244b4,&DAT_008244c8);
            if (DAT_008244b8 == f_0) {
              DAT_008244b8 = f_7;
            }
            DAT_008244b4 = DAT_008244b4 + f_1;
            if (f_3 < DAT_008244b4) {
              DAT_008244b4 = f_0;
            }
            if (((DAT_008244b4 == f_0) && (DAT_0082446c < 0xd)) &&
               ((&DAT_020b9440)[DAT_0082446c] != f_0)) {
              DAT_008244b4 = f_1;
            }
            *(float *)(&DAT_01c5891c + DAT_0082446c * 4) = DAT_008244b4 * f_100 + DAT_008244b8;
            if (DAT_008244b4 == f_0) {
              *(float *)(&DAT_01c5891c + DAT_0082446c * 4) = f_0;
            }
          }
          else if (_DAT_020b8ea0 == 0x4e44534b) {
            *(float *)(&DAT_01c5891c + DAT_0082446c * 4) =
                 *(float *)(&DAT_020b943c + DAT_0082446c * 4) - f_1;
          }
          else if (_DAT_020b8ea0 == 0x5055534b) {
            *(float *)(&DAT_01c5891c + DAT_0082446c * 4) =
                 *(float *)(&DAT_020b943c + DAT_0082446c * 4) + f_1;
          }
          else {
            if (_DAT_020b8ea0 != 0x525a534b) {
              ffree(fVar9);
              fVar9 = (float10)thunk_FUN_0054d7d4(&DAT_020b8ea0,3);
              DAT_0078b4e0 = 9999;
              DAT_009a9494 = 99;
              *(undefined4 *)(puVar3 + -0x118) = 0;
              goto LAB_00467fb8;
            }
            DAT_01c5893c = f_0;
            DAT_01c58940 = f_0;
            DAT_01c58944 = f_0;
            DAT_01c58948 = f_0;
            DAT_01c5894c = f_0;
            DAT_01c58950 = f_0;
          }
          goto LAB_00466f58;
        }
        DAT_01c58934 = f_3;
      }
      if (f_100 <= DAT_020b9450) {
        DAT_01c58934 = DAT_01c58934 + f_100;
      }
    }
LAB_00466f58:
    *(undefined4 *)(puVar3 + -0x114) = 0;
    goto LAB_00467f93;
  case 'i':
LAB_00466f9f:
    if (_DAT_020b8ea0 == 0x58544f42) {
      DAT_01c58934 = DAT_020b9454 * f_2;
      *(undefined4 *)(puVar3 + -0x10c) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0x110) = 0;
      if ((_DAT_020b8ea0 & 0xffff) == 17999) {
        *(undefined4 *)(puVar3 + -0x108) = 0;
        goto LAB_00466fdb;
      }
      if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_00464f4e) {
        *(undefined4 *)(puVar3 + -0x104) = 0;
        goto LAB_00467070;
      }
      if ((_DAT_020b8ea0 & 0xffff) == 0x5a53) {
        _DAT_01c58938 = DAT_020b9458;
        if (DAT_020b9458 == f_0) {
          _DAT_01c58938 = f_1;
        }
        _DAT_01c58938 = _DAT_01c58938 - f_0_2;
        if (DAT_020b8ea2 == '+') {
          _DAT_01c58938 = _DAT_01c58938 + f_0_4;
        }
        if (DAT_020b8ea2 == '*') {
          _DAT_01c58938 = f_0;
        }
      }
      else if (DAT_020b8ea4 == 'P' && _DAT_020b8ea0 == 0x5352544d) {
        DAT_01c58934 = DAT_020b9454 + f_1;
      }
      else if (_DAT_020b8ea0 == 0x5352544d) {
        DAT_01c58930 = f_0;
        DAT_01c58934 = f_1;
      }
      else if (_DAT_020b8ea0 == 0x504c544d) {
        DAT_01c58930 = DAT_020b9450 + f_1;
        if (DAT_020b945c == f_0) {
          DAT_01c5893c = f_4;
        }
      }
      else if (_DAT_020b8ea0 == 0x4d4c544d) {
        DAT_01c58930 = DAT_020b9450 - f_1;
        if (DAT_01c58930 < f_1) {
          DAT_01c58930 = f_1;
        }
        if (DAT_020b945c == f_0) {
          DAT_01c5893c = f_4;
        }
      }
      else if (_DAT_020b8ea0 == 0x5052544d) {
        DAT_01c5893c = DAT_020b945c + f_1;
      }
      else if (_DAT_020b8ea0 == 0x4d52544d) {
        DAT_01c5893c = DAT_020b945c - f_1;
        if (DAT_01c5893c < f_1) {
          DAT_01c5893c = f_1;
        }
      }
      else if (_DAT_020b8ea0 == 0x504c424d) {
        DAT_01c58934 = DAT_020b9454 * f_2;
      }
      else if (_DAT_020b8ea0 == 0x4d4c424d) {
        DAT_01c58934 = DAT_020b9454 / f_2;
        if (DAT_01c58934 < f_1) {
          DAT_01c58934 = f_1;
        }
      }
      else if (_DAT_020b8ea0 == 0x5052424d) {
        DAT_01c58940 = DAT_020b9460 * f_2;
        if (DAT_01c58940 < f_1) {
          DAT_01c58940 = f_1;
        }
      }
      else if (_DAT_020b8ea0 == 0x4d52424d) {
        DAT_01c58940 = DAT_020b9460 / f_2;
        if (DAT_01c58940 < f_1) {
          DAT_01c58940 = f_0;
        }
      }
      else if (_DAT_020b8ea0 == 0x53414c4d) {
        DAT_01c5895c = DAT_020b947c - f_1;
        if (DAT_01c5895c < f_m3) {
          DAT_01c5895c = f_0;
        }
      }
      else {
        if (_DAT_020b8ea0 != 0x464e4f50) {
          *(undefined4 *)(puVar3 + -0x100) = 0;
          goto LAB_00467b42;
        }
        DAT_01c5894c = f_1;
        if (DAT_020b946c != f_0) {
          DAT_01c5894c = f_0;
        }
      }
      *(undefined4 *)(puVar3 + -0xfc) = 0;
    }
    goto LAB_00467f93;
  case 'j':
  case 'q':
    DAT_01c5893c = DAT_020b945c + f_100;
    if (f_400 <= DAT_01c5893c) {
      DAT_01c5893c = DAT_01c5893c - f_300;
    }
    *(undefined4 *)(puVar3 + -0x2f4) = 0;
    goto LAB_00463037;
  case 'k':
  case 'r':
    DAT_01c5893c = DAT_020b945c + f_10;
    ffree(fVar9);
    fVar9 = (float10)amod(&DAT_01c5893c,&f_100);
    if ((float10)f_40 <= fVar9) {
      DAT_01c5893c = DAT_01c5893c - f_30;
    }
    *(undefined4 *)(puVar3 + -0x2f0) = 0;
    fVar9 = extraout_ST1_01;
    goto LAB_00463037;
  case 'l':
  case 's':
    DAT_01c5893c = DAT_020b945c + f_1;
    ffree(fVar9);
    fVar9 = (float10)amod(&DAT_01c5893c,&f_10);
    if ((float10)f_4 <= fVar9) {
      DAT_01c5893c = DAT_01c5893c - f_3;
    }
    *(undefined4 *)(puVar3 + -0x2ec) = 0;
    fVar9 = extraout_ST1_02;
    goto LAB_00463037;
  case 'm':
  case 't':
    DAT_01c58940 = DAT_020b9460 + f_1000;
    if (f_4000 <= DAT_01c58940) {
      DAT_01c58940 = DAT_01c58940 - f_3000;
    }
    *(undefined4 *)(puVar3 + -0x2e8) = 0;
    goto LAB_00463037;
  case 'n':
  case 'u':
    DAT_01c58940 = DAT_020b9460 + f_100;
    ffree(fVar9);
    fVar9 = (float10)amod(&DAT_01c58940,&f_1000);
    if ((float10)f_400 <= fVar9) {
      DAT_01c58940 = DAT_01c58940 - f_300;
    }
    *(undefined4 *)(puVar3 + -0x2e4) = 0;
    fVar9 = extraout_ST1_03;
    goto LAB_00463037;
  case 'o':
  case 'v':
    DAT_01c58940 = DAT_020b9460 + f_10;
    ffree(fVar9);
    fVar9 = (float10)amod(&DAT_01c58940,&f_100);
    if ((float10)f_40 <= fVar9) {
      DAT_01c58940 = DAT_01c58940 - f_30;
    }
    *(undefined4 *)(puVar3 + -0x2e0) = 0;
    fVar9 = extraout_ST1_04;
    goto LAB_00463037;
  case 'p':
  case 'w':
    DAT_01c58940 = DAT_020b9460 + f_1;
    ffree(fVar9);
    fVar9 = (float10)amod(&DAT_01c58940,&f_10);
    if ((float10)f_4 <= fVar9) {
      DAT_01c58940 = DAT_01c58940 - f_3;
    }
    *(undefined4 *)(puVar3 + -0x2dc) = 0;
    fVar9 = extraout_ST1_05;
LAB_00463037:
    DAT_0205274c = 1;
    ffree(fVar9);
    fVar9 = (float10)FUN_00467fc1();
    *(undefined4 *)(puVar3 + -0x348) = 0;
    goto LAB_00467fb8;
  case 'x':
    if (P2 <= f_0) {
      DAT_00824650 = 1;
      if ((DAT_00824654 == 1) || (DAT_00824654 == 4)) {
        DAT_00824650 = 2;
      }
      *(undefined4 *)(puVar3 + -0x2c) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0x30) = 0;
      if ((DAT_00824654 != 0) && (DAT_00824654 != 3)) {
        *(undefined4 *)(puVar3 + -0x28) = 0;
        DAT_01c58920 = f_999;
        return;
      }
      DAT_00824650 = 3;
      *(undefined4 *)(puVar3 + -0x24) = 0;
    }
    goto LAB_00468dc6;
  case 'y':
    if (P2 <= f_0) {
      if ((DAT_00824654 != 1) && (DAT_00824654 != 4)) {
        *(undefined4 *)(puVar3 + -0x1c) = 0;
        DAT_01c58920 = f_999;
        return;
      }
      DAT_00824650 = 3;
      *(undefined4 *)(puVar3 + -0x18) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0x20) = 0;
      DAT_00824650 = -1;
      if ((DAT_00824654 == 0) || (DAT_00824654 == 3)) {
        DAT_00824650 = 1;
      }
      *(undefined4 *)(puVar3 + -0x14) = 0;
    }
    goto LAB_00468dc6;
  case 'z':
    if (P2 <= f_0) {
      DAT_00824650 = 5;
      if ((DAT_00824654 == 1) || (DAT_00824654 == 4)) {
        DAT_00824650 = 2;
      }
      *(undefined4 *)(puVar3 + -0x38) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0x3c) = 0;
      DAT_00824650 = 4;
      if ((DAT_00824654 == 0) || (DAT_00824654 == 3)) {
        DAT_00824650 = 1;
      }
    }
    if (DAT_0082464c == 3) {
      DAT_00824650 = DAT_00824650 + -3;
    }
    goto LAB_00468dc6;
  case '{':
    if (f_0 < P2) {
      *(undefined4 *)(puVar3 + -0x10) = 0;
      DAT_01c58920 = f_999;
      return;
    }
    DAT_00824650 = -1;
    if ((DAT_00824654 == 1) || (DAT_00824654 == 4)) {
      DAT_00824650 = -3;
    }
    *(undefined4 *)(puVar3 + -0xc) = 0;
    goto LAB_00468dc6;
  case '|':
    if (P2 < f_0) {
      *(undefined4 *)(puVar3 + -8) = 0;
      DAT_01c58920 = f_999;
      return;
    }
    DAT_00824650 = -2;
    if ((DAT_00824654 == 0) || (DAT_00824654 == 3)) {
      DAT_00824650 = -3;
    }
    *(undefined4 *)(puVar3 + -4) = 0;
LAB_00468dc6:
    DAT_01c5892c = P2 + DAT_020b944c;
    DAT_01c58930 = (float)DAT_00824650 + DAT_020b9450;
    *(undefined4 *)(puVar3 + -0x34) = 0;
    return;
  }
  _DAT_020b8ea0 = 0x20202020;
  *(undefined4 *)(puVar3 + -0x514) = 0;
LAB_00467f93:
  DAT_0205274c = 1;
LAB_00467f9e:
  ffree(fVar9);
  fVar9 = (float10)FUN_00467fc1();
  *(undefined4 *)(puVar3 + -0x14) = 0;
LAB_00467fb8:
  ffree(fVar9);
  return;
LAB_00462bbf:
  *(undefined2 *)(puVar3 + -0x5d4) = in_FPUControlWord;
  *(ushort *)(puVar3 + -0x5d2) = (ushort)*(undefined4 *)(puVar3 + -0x5d4) | 0xc00;
  *(int *)(puVar3 + -0x5d0) = (int)ROUND(P2);
  DAT_008244f0 = *(uint *)(puVar3 + -0x5d0);
  ffree(fVar9);
  Var8 = thunk_FUN_00597b60(0xffffffff);
  DAT_0171b230 = 0;
  if (DAT_008244f0 == 0) {
    DAT_008244f0 = DAT_020527e8;
  }
  DAT_0078b370 = 1;
  if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x49) {
    DAT_008244f0 = ITEM_I;
    DAT_0078b370 = -1;
  }
  DAT_020527cc = 1;
  if ((_DAT_020b8ea0 & 0xff) == 0x4e) {
    DAT_020527cc = 0xffffffff;
    _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00761c44);
  }
  ffree(Var8);
  fVar9 = (float10)thunk_FUN_00473cdd(&DAT_020527cc);
  DAT_01fbb760 = 0;
  if (0 < DAT_0205274c) {
    if (EDIT_ITEM == 0) {
      DAT_0205274c = 0;
      *(undefined4 *)(puVar3 + -0x46c) = 0;
    }
    else {
      ffree(fVar9);
      Var8 = thunk_FUN_00473228(&EDIT_ITEM);
      DAT_020527c0 = (&ITEM_PTR0)[EDIT_ITEM];
      ffree(Var8);
      fVar9 = (float10)thunk_FUN_00476628();
      DAT_0205274c = 0;
    }
  }
  if (ITEM_I < (int)DAT_008244f0) {
    DAT_008244f0 = ITEM_I;
  }
  DAT_020527e8 = DAT_008244f0;
  EDIT_ITEM = DAT_008244f0;
  DAT_0078dc45 = 0;
LAB_00462d49:
  if ((DAT_00791480 < 0) || ((_DAT_020b90a0 & 0xff) == 0x43)) {
    *(undefined4 *)(puVar3 + -0x468) = 0;
  }
  else {
    DAT_020b9444 = (float)(&ITEM_P2)[(&ITEM_PTR0)[EDIT_ITEM]];
    DAT_020b9440 = f_0;
    DAT_00790c10 = 0;
    ffree(fVar9);
    fVar9 = (float10)thunk_FUN_00585d20();
  }
LAB_00462db2:
  ffree(fVar9);
  Var8 = thunk_FUN_00549b5b();
  ffree(Var8);
  Var8 = thunk_FUN_00473454();
  ffree(Var8);
  fVar9 = (float10)thunk_FUN_0054de6b();
LAB_00462dc7:
  P1 = f_0;
  DAT_0078b4e0 = -1;
  *(undefined4 *)(puVar3 + -0x464) = 0;
  goto LAB_00467ee8;
}


