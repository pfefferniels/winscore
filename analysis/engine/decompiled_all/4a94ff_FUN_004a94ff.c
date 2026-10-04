// FUN_004a94ff @ 004a94ff (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x004a9947) */
/* WARNING: Removing unreachable block (ram,0x004a98f3) */
/* WARNING: Removing unreachable block (ram,0x004a9d9d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a94ff(void)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 in_FPUControlWord;
  unkbyte10 Var6;
  float10 extraout_ST0;
  float10 fVar7;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  undefined1 *puVar8;
  
  puVar8 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if (DAT_00791f80 == 0) {
    for (iVar1 = 1; iVar1 < 0x21; iVar1 = iVar1 + 1) {
      *(float *)(iVar1 * 4 + 0x88d51c) = f_0;
    }
    for (iVar1 = 1; iVar1 < 0x21; iVar1 = iVar1 + 1) {
      *(undefined4 *)(iVar1 * 4 + 0x88d61c) = 0;
    }
    DAT_0088d520 = DAT_0078b490;
    DAT_0088d524 = DAT_0078b494;
    DAT_0088d528 = DAT_0078b498;
    DAT_0088d52c = DAT_0078b49c;
    _DAT_0088d530 = DAT_0078b470 * f_100;
    _DAT_0088d534 = _DAT_0078ded4 * _DAT_0078ded8;
    DAT_0088d538 = DAT_0078b488;
    DAT_0088d53c = DAT_0078b48c;
    DAT_0088d620 = DAT_0078b478;
    DAT_0088d624 = DAT_0078b4a0;
    DAT_0088d628 = DAT_0078b474;
    DAT_0088d62c = DAT_0078b4a4;
    DAT_0088d630 = DAT_0078b4e8;
    DAT_0088d668 = DAT_0078df00;
    DAT_0088d66c = DAT_01b9d63c;
    DAT_0088d670 = DAT_0078df04;
    DAT_0088d3b4 = DAT_01fbb6f8;
    if ((int)DAT_01fbb6f8 < 0) {
      DAT_0088d3b4 = 0.0;
    }
    DAT_0088d674 = DAT_0088d3b4;
    _DAT_0088d678 = (int)ROUND(_DAT_0078b4b8);
    FUN_005f33c9(&stack0xfffffffc,0x4a96b8);
    puVar2 = puVar8;
    FUN_005f34d1(puVar8,0x4a96d3);
    *(undefined4 *)(puVar2 + -0x94) = 8;
    DAT_0088d3b4 = 1.54143e-44;
    do {
      *(undefined4 *)((int)DAT_0088d3b4 * 4 + 0x88d61c) = 0;
      DAT_0088d3d4 = (int)DAT_0088d3b4 + -10;
      if (DAT_0088d3d4 == PAPER) {
        *(undefined4 *)((int)DAT_0088d3b4 * 4 + 0x88d61c) = 1;
      }
      else {
        *(undefined4 *)(puVar2 + -0x90) = 0;
      }
      *(undefined4 *)(puVar2 + -0x8c) = 0;
      DAT_0088d3b4 = (float)((int)DAT_0088d3b4 + 1);
      *(int *)(puVar2 + -0x94) = *(int *)(puVar2 + -0x94) + -1;
      iVar1 = _DAT_020b8ea0;
    } while (0 < *(int *)(puVar2 + -0x94));
    if (PAPER == 0) {
      _DAT_0088d664 = 1;
    }
    DAT_0088d3b0 = DAT_0078b4a8 / 0xc + -1;
    DAT_020b8ea3 = SUB41(iVar1,3);
    _DAT_020b8ea0 = (uint3)CONCAT11((char)DAT_0088d3b0 + '0',DAT_00763d80);
    puVar4 = (undefined4 *)&DAT_020b8ea0;
    puVar5 = &DAT_009ae2bc;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  else {
    for (iVar1 = 1; iVar1 < 0x21; iVar1 = iVar1 + 1) {
      *(undefined4 *)(iVar1 * 4 + 0x88d51c) = *(undefined4 *)(iVar1 * 4 + 0x88d49c);
    }
    for (iVar1 = 1; iVar1 < 0x21; iVar1 = iVar1 + 1) {
      *(undefined4 *)(iVar1 * 4 + 0x88d61c) = *(undefined4 *)(iVar1 * 4 + 0x88d59c);
    }
    FUN_005f33c9(&stack0xfffffffc,0x4a9848);
    FUN_005f33c9(puVar2,0x4a9864);
    FUN_005f33c9(puVar2,0x4a9880);
    FUN_005f34d1(puVar2,0x4a989b);
    pcVar3 = s___computer_printer_0078dccc;
    puVar4 = &DAT_009af53c;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(puVar2 + -0x98) = 0;
  }
  FUN_005f34d1(puVar2,0x4a98d9);
  FUN_005f46bc(puVar2,0x4a9917);
  FUN_005f34d1(puVar2,0x4a992d);
  FUN_005f46bc(puVar2,0x4a996b);
  Var6 = FUN_005f34d1(puVar2,0x4a9981);
  ffree(Var6);
  DAT_0088d3b0 = thunk_FUN_0059b5a0(&DAT_0088d620,&DAT_0088d520);
  if (DAT_0088d3b0 == 2) {
    DAT_0088d3ac = 0;
    *(undefined4 *)(puVar2 + -0x88) = 0;
    fVar7 = extraout_ST0;
  }
  else {
    fVar7 = extraout_ST0;
    if ((char)DAT_019c692c == '1') {
      FUN_005f33c9(puVar2,0x4a99f0);
      fVar7 = (float10)FUN_005f34d1(puVar2,0x4a9a0b);
    }
    if ((char)DAT_019c692c == '2') {
      FUN_005f33c9(puVar2,0x4a9a3c);
      fVar7 = (float10)FUN_005f34d1(puVar2,0x4a9a57);
    }
    if ((char)DAT_019c692c == '3') {
      pcVar3 = "C:\\PROGRAM FILES (X86)\\WINSCORE\\SCORLIB\\PREF.DAT";
      puVar4 = &DAT_019c692c;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        puVar4 = puVar4 + 1;
      }
    }
    if ((char)DAT_019c68ac == '1') {
      FUN_005f33c9(puVar2,0x4a9aae);
      fVar7 = (float10)FUN_005f34d1(puVar2,0x4a9ac9);
    }
    if ((char)DAT_019c68ac == '2') {
      FUN_005f33c9(puVar2,0x4a9afa);
      fVar7 = (float10)FUN_005f34d1(puVar2,0x4a9b15);
    }
    if ((char)DAT_019c68ac == '3') {
      FUN_005f33c9(puVar2,0x4a9b46);
      fVar7 = (float10)FUN_005f34d1(puVar2,0x4a9b61);
    }
    if ((char)DAT_019c682c == '1') {
      FUN_005f33c9(puVar2,0x4a9b92);
      fVar7 = (float10)FUN_005f34d1(puVar2,0x4a9bad);
    }
    if ((char)DAT_019c682c == '2') {
      FUN_005f33c9(puVar2,0x4a9bde);
      fVar7 = (float10)FUN_005f34d1(puVar2,0x4a9bf9);
    }
    if ((char)DAT_019c682c == '3') {
      FUN_005f33c9(puVar2,0x4a9c2a);
      fVar7 = (float10)FUN_005f34d1(puVar2,0x4a9c45);
    }
    ffree(fVar7);
    Var6 = FUN_004acfe5(&DAT_019c682c,0x80,&DAT_00763d64);
    ffree(Var6);
    FUN_004acfe5(&DAT_019c68ac,0x80,&DAT_00763d64);
    for (iVar1 = 1; iVar1 < 0x21; iVar1 = iVar1 + 1) {
      *(undefined4 *)(iVar1 * 4 + 0x88d49c) = *(undefined4 *)(iVar1 * 4 + 0x88d51c);
    }
    for (iVar1 = 1; iVar1 < 0x21; iVar1 = iVar1 + 1) {
      *(undefined4 *)(iVar1 * 4 + 0x88d59c) = *(undefined4 *)(iVar1 * 4 + 0x88d61c);
    }
    DAT_0088d3b8 = DAT_009ae2bc._1_1_;
    DAT_00791f80 = 1;
    for (iVar1 = 1; iVar1 < 0x65; iVar1 = iVar1 + 1) {
      *(undefined4 *)(&DAT_01cb0ebc + iVar1 * 4) = 0xffffffff;
    }
    Var6 = FUN_005f33c9(puVar2,0x4a9d2f);
    ffree(Var6);
    DAT_0078b4c0 = FUN_005ff950(puVar2 + -0x148,0x80);
    Var6 = FUN_005f33c9(puVar2,0x4a9d6a);
    ffree(Var6);
    DAT_0078b4c4 = FUN_005ff950(puVar2 + -0x148,0x80);
    if ((byte)(&DAT_019c68ab)[DAT_0078b4c0] < 0x21) {
      DAT_0078b4c0 = DAT_0078b4c0 + -1;
    }
    puVar4 = &DAT_009af53c;
    pcVar3 = s___computer_printer_0078dccc;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pcVar3 = *puVar4;
      puVar4 = puVar4 + 1;
      pcVar3 = pcVar3 + 4;
    }
    iVar1 = FUN_00601a30(0x20);
    if (iVar1 != 0) {
      _DAT_019c6828 = DAT_00763db4;
    }
    DAT_0078b390 = DAT_019c6828;
    DAT_0078b490 = DAT_0088d520;
    DAT_0078b494 = DAT_0088d524;
    DAT_0078b498 = DAT_0088d528;
    DAT_0078b49c = DAT_0088d52c;
    DAT_0078b470 = _DAT_0088d530 / f_100;
    _DAT_0078ded8 = _DAT_0088d534 / _DAT_0078ded4;
    DAT_0078b488 = DAT_0088d538;
    DAT_0078b48c = DAT_0088d53c;
    DAT_0078b478 = DAT_0088d620;
    DAT_0078b4a0 = DAT_0088d624;
    DAT_0078b474 = DAT_0088d628;
    DAT_0078b4a4 = DAT_0088d62c;
    DAT_0078b4e8 = DAT_0088d630;
    DAT_0078df00 = DAT_0088d668;
    DAT_01b9d63c = DAT_0088d66c;
    DAT_0078df04 = DAT_0088d670;
    _DAT_0078b4b8 = (float)_DAT_0088d678;
    P1 = DAT_0088d674;
    if (DAT_0088d674 == 0.0) {
      P1 = -NAN;
    }
    DAT_01fbb6f8 = P1;
    DAT_01b9d630 = 2000;
    _DAT_01b9d634 = f_0_1;
    _DAT_01b9d638 = f_0_25;
    if (DAT_0088d66c != 0) {
      DAT_01b9d630 = 0xfffff830;
      _DAT_01b9d634 = -f_0_1;
      _DAT_01b9d638 = -f_0_25;
    }
    *(undefined4 *)(puVar2 + -0x84) = 8;
    P1 = 1.54143e-44;
    do {
      if (*(int *)((int)P1 * 4 + 0x88d61c) != 0) {
        PAPER = (int)P1 + -10;
      }
      P1 = (float)((int)P1 + 1);
      *(int *)(puVar2 + -0x84) = *(int *)(puVar2 + -0x84) + -1;
    } while (0 < *(int *)(puVar2 + -0x84));
    if (PAPER == 8) {
      PAPER = 0;
    }
    _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_009ae2bc._1_1_);
    DAT_0078b4a8 = DAT_009ae2bc._1_1_ * 0xc + -0x234;
    Var6 = FUN_005f33c9(puVar2,0x4aa02f);
    ffree(Var6);
    DAT_0078b4c0 = FUN_005ff950(puVar2 + -0x148,0x80);
    Var6 = FUN_005f33c9(puVar2,0x4aa06a);
    ffree(Var6);
    DAT_0078b4c4 = FUN_005ff950(puVar2 + -0x148,0x80);
    iVar1 = FUN_005f4660(0x20);
    fVar7 = extraout_ST0_00;
    if (iVar1 == 0) {
      FUN_005f34d1(puVar2,0x4aa0cf);
      FUN_005f33c9(puVar2,0x4aa0f1);
      FUN_005f34d1(puVar2,0x4aa10c);
      Var6 = FUN_005f34d1(puVar2,0x4aa12d);
      ffree(Var6);
      fVar7 = (float10)thunk_FUN_00518448();
      *(undefined4 *)(puVar2 + -0x80) = 0x1d;
      P1 = 1.4013e-45;
      do {
        if (*(int *)(s_METRINCHBEAMBMTHRESTDASHMIDKPROC_007921c0 + (int)P1 * 4 + 0x7c) ==
            _DAT_020b8ea0) {
          switch(P1) {
          case 1.4013e-45:
            DAT_0078b4e8 = 1;
            *(undefined4 *)(puVar2 + -0x78) = 0;
            goto LAB_004aac29;
          case 2.8026e-45:
            DAT_0078b4e8 = 0;
            *(undefined4 *)(puVar2 + -0x74) = 0;
            goto LAB_004aac29;
          case 4.2039e-45:
            DAT_0078b470 = P2;
            *(undefined4 *)(puVar2 + -0x70) = 0;
            goto LAB_004aac29;
          case 5.60519e-45:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            DAT_0078b478 = *(undefined4 *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -0x6c) = 0;
            goto LAB_004aac29;
          case 7.00649e-45:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            DAT_0078b474 = *(undefined4 *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -0x68) = 0;
            goto LAB_004aac29;
          case 8.40779e-45:
            _DAT_0078ded8 = P2 / _DAT_0078ded4;
            *(undefined4 *)(puVar2 + -100) = 0;
            goto LAB_004aac29;
          case 9.80909e-45:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND((P4 + f_1) * f_12);
            DAT_0078b4a8 = *(int *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -0x60) = 0;
          case 1.12104e-44:
          case 1.26117e-44:
            goto LAB_004aac29;
          case 1.4013e-44:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            DAT_0078b4a4 = *(undefined4 *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -0x5c) = 0;
            goto LAB_004aac29;
          case 1.54143e-44:
            DAT_0078b488 = P2;
            *(undefined4 *)(puVar2 + -0x58) = 0;
            goto LAB_004aac29;
          case 1.68156e-44:
            DAT_0078b48c = P2;
            *(undefined4 *)(puVar2 + -0x54) = 0;
            goto LAB_004aac29;
          case 1.82169e-44:
            DAT_0078b490 = P2;
            *(undefined4 *)(puVar2 + -0x50) = 0;
            goto LAB_004aac29;
          case 1.96182e-44:
            DAT_0078b494 = P2;
            *(undefined4 *)(puVar2 + -0x4c) = 0;
            goto LAB_004aac29;
          case 2.10195e-44:
            DAT_0078b498 = P2;
            *(undefined4 *)(puVar2 + -0x48) = 0;
            goto LAB_004aac29;
          case 2.24208e-44:
            DAT_0078b49c = P2;
            *(undefined4 *)(puVar2 + -0x44) = 0;
            goto LAB_004aac29;
          case 2.38221e-44:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            DAT_0078b4a0 = *(undefined4 *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -0x40) = 0;
            goto LAB_004aac29;
          case 2.52234e-44:
            Var6 = FUN_005f33c9(puVar2,&LAB_004aa430);
            ffree(Var6);
            DAT_0088d3a8 = FUN_005ff950(puVar2 + -0x2c8,0x200);
            FUN_005f46bc(puVar2,&LAB_004aa484);
            fVar7 = (float10)FUN_005f34d1(puVar2,&LAB_004aa49a);
            if (DAT_020b8ea6 == '\\') {
              *(undefined4 *)(puVar2 + -0x3c) = 0;
            }
            else {
              iVar1 = DAT_0088d3a8 + -6;
              if (iVar1 < 0) {
                iVar1 = 0;
              }
              *(int *)(puVar2 + -0xc0) = iVar1;
              *(undefined4 *)(puVar2 + -0xc4) = 6;
              FUN_005f46bc(puVar2,&LAB_004aa50b);
              FUN_005f46bc(puVar2,&LAB_004aa527);
              FUN_005f46bc(puVar2,&LAB_004aa54a);
              FUN_005f46bc(puVar2,&LAB_004aa566);
              FUN_005f34d1(puVar2,&LAB_004aa57c);
              Var6 = FUN_005f33c9(puVar2,&LAB_004aa59e);
              ffree(Var6);
              DAT_0078b4c0 = FUN_005ff950(puVar2 + -0x148,0x80);
              *(undefined4 *)(puVar2 + -0x38) = 0;
              fVar7 = extraout_ST0_01;
            }
            goto LAB_004aac29;
          case 2.66247e-44:
            Var6 = FUN_005f33c9(puVar2,&LAB_004aa5e5);
            ffree(Var6);
            DAT_0088d3a8 = FUN_005ff950(puVar2 + -0x2c8,0x200);
            FUN_005f46bc(puVar2,&LAB_004aa639);
            fVar7 = (float10)FUN_005f34d1(puVar2,&LAB_004aa64f);
            if (DAT_020b8ea6 == '\\') {
              *(undefined4 *)(puVar2 + -0x34) = 0;
            }
            else {
              iVar1 = DAT_0088d3a8 + -6;
              if (iVar1 < 0) {
                iVar1 = 0;
              }
              *(int *)(puVar2 + -0xc0) = iVar1;
              *(undefined4 *)(puVar2 + -0xc4) = 6;
              FUN_005f46bc(puVar2,&LAB_004aa6c0);
              FUN_005f46bc(puVar2,&LAB_004aa6dc);
              FUN_005f46bc(puVar2,&LAB_004aa6ff);
              FUN_005f46bc(puVar2,&LAB_004aa71b);
              FUN_005f34d1(puVar2,&LAB_004aa731);
              Var6 = FUN_005f33c9(puVar2,&LAB_004aa753);
              ffree(Var6);
              DAT_0078b4c4 = FUN_005ff950(puVar2 + -0x148,0x80);
              *(undefined4 *)(puVar2 + -0x30) = 0;
              fVar7 = extraout_ST0_02;
            }
            goto LAB_004aac29;
          case 2.8026e-44:
            _DAT_0088d3a4 = P2;
            *(undefined4 *)(puVar2 + -0x2c) = 0;
            goto LAB_004aac29;
          case 2.94273e-44:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            PAPER = *(int *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -0x28) = 0;
            goto LAB_004aac29;
          case 3.08286e-44:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            P1 = *(float *)(puVar2 + -0xc0);
            DAT_0088d3d4 = (int)P1 / 1000000;
            DAT_0088d3a0 = ((int)P1 % 1000000) / 10000;
            DAT_0088d39c = ((int)P1 % 10000) / 100;
            DAT_0088d3ac = (int)P1 % 100;
            fVar7 = (float10)((DAT_0088d3a0 / 3) * 100 + (DAT_0088d3d4 / 2) * 1000 +
                              (DAT_0088d39c / 5) * 10 + DAT_0088d3ac / 8);
            *(undefined2 *)(puVar2 + -0xc4) = *(undefined2 *)(puVar2 + -0xc4);
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) =
                 (int)ROUND((float10)_DAT_0088d3a4 * (float10)f_1000000 + fVar7);
            _DAT_0088d398 = *(undefined4 *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -0x24) = 0;
            goto LAB_004aac29;
          case 3.22299e-44:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            DAT_0078df00 = *(undefined4 *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -0x20) = 0;
            goto LAB_004aac29;
          case 3.36312e-44:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            DAT_01b9d63c = *(int *)(puVar2 + -0xc0);
            DAT_01b9d630 = 2000;
            _DAT_01b9d634 = f_0_1;
            _DAT_01b9d638 = f_0_25;
            if (DAT_01b9d63c != 0) {
              DAT_01b9d630 = 0xfffff830;
              _DAT_01b9d634 = -f_0_1;
              fVar7 = (float10)f_0_25;
              _DAT_01b9d638 = (float)-fVar7;
            }
            *(undefined4 *)(puVar2 + -0x1c) = 0;
            goto LAB_004aac29;
          case 3.50325e-44:
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            DAT_0078df04 = *(undefined4 *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -0x18) = 0;
            goto LAB_004aac29;
          case 3.64338e-44:
            FUN_005f34d1(puVar2,&LAB_004aaa8d);
            FUN_005f46bc(puVar2,&LAB_004aaac8);
            FUN_005f46bc(puVar2,&LAB_004aaae4);
            FUN_005f34d1(puVar2,&LAB_004aaafa);
            iVar1 = FUN_005f4660(0x20);
            if (iVar1 == 0) {
              ffree(extraout_ST0_03);
              fVar7 = (float10)FUN_004acfe5(s___computer_printer_0078dccc,0x80,&DAT_00763d64);
              *(undefined4 *)(puVar2 + -0x10) = 0;
            }
            else {
              *(undefined4 *)(puVar2 + -0x14) = 0;
              fVar7 = extraout_ST0_03;
            }
            goto LAB_004aac29;
          case 3.78351e-44:
            FUN_005f33c9(puVar2,&LAB_004aab7b);
            fVar7 = (float10)FUN_005f34d1(puVar2,&LAB_004aab96);
            *(undefined4 *)(puVar2 + -0xc) = 0;
            goto LAB_004aac29;
          case 3.92364e-44:
            if (P2 == f_0) {
              P2 = f_m1;
            }
            *(undefined2 *)(puVar2 + -0xc4) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0xc2) = (ushort)*(undefined4 *)(puVar2 + -0xc4) | 0xc00;
            *(int *)(puVar2 + -0xc0) = (int)ROUND(P2);
            DAT_01fbb6f8 = *(float *)(puVar2 + -0xc0);
            *(undefined4 *)(puVar2 + -8) = 0;
            goto LAB_004aac29;
          case 4.06377e-44:
            _DAT_0078b4b8 = P2;
            *(undefined4 *)(puVar2 + -4) = 0;
            goto LAB_004aac29;
          }
        }
        P1 = (float)((int)P1 + 1);
        *(int *)(puVar2 + -0x80) = *(int *)(puVar2 + -0x80) + -1;
      } while (0 < *(int *)(puVar2 + -0x80));
      *(undefined4 *)(puVar2 + -0x7c) = 0;
    }
  }
LAB_004aac29:
  ffree(fVar7);
  Var6 = thunk_FUN_00468df8(&DAT_00763dac);
  _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00763ca8);
  ffree(Var6);
  Var6 = thunk_FUN_0054e9f2();
  ffree(Var6);
  Var6 = FUN_004acee1(&DAT_019c68ac,0x80,&DAT_0078b4c0);
  ffree(Var6);
  return;
}


