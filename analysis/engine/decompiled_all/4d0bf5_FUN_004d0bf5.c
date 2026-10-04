// FUN_004d0bf5 @ 004d0bf5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004d0fa9) */
/* WARNING: Removing unreachable block (ram,0x004d0f5c) */
/* WARNING: Removing unreachable block (ram,0x004d103c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d0bf5(void)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 in_FPUControlWord;
  float10 fVar6;
  
  puVar2 = &stack0xfffffffc;
  _DAT_0078cbba = 0;
  DAT_01aae304 = -1;
  FUN_005f33c9(&stack0xfffffffc,0x4d0c32);
  FUN_005f34d1(puVar2,0x4d0c4d);
  thunk_FUN_0054aaf8();
  FUN_005f34d1(puVar2,0x4d0c73);
  FUN_005f33c9(puVar2,0x4d0c95);
  FUN_005f34d1(puVar2,0x4d0cb0);
  *(int *)(puVar2 + -0x80) = DAT_01be6cb0 - DAT_01be6ca8;
  _DAT_0089ff64 = (float)*(int *)(puVar2 + -0x80) / f_4000;
  DAT_019c6a00 = f_10_2 / _DAT_0089ff64;
  if (DAT_00793ab8 == 0) {
    *(undefined4 *)(puVar2 + -0x5c) = 0;
    DAT_01c60caa = f_0_5;
    DAT_01c60cae = f_0_75;
    if (DAT_01be6ca8 < -26000) {
      *(int *)(puVar2 + -0x80) = DAT_01be6ca8 + 26000;
      _DAT_0089ff64 = (float)*(int *)(puVar2 + -0x80) / f_4000;
      DAT_01c60cae = DAT_01c60cae - _DAT_0089ff64;
    }
    DAT_0089ffcc = DAT_01c60caa;
    _DAT_0089ffd0 = DAT_01c60cae;
    DAT_008a0038 = 0;
  }
  else {
    FUN_005f34d1(puVar2,0x4d0d8b);
    *(undefined4 *)(puVar2 + -0x58) = 0;
  }
  puVar4 = &DAT_0078cb22;
  puVar5 = &DAT_01a14984;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  _DAT_0089ff60 = f_1;
  if (DAT_0078b4e8 != 0) {
    _DAT_0089ff60 = f_2_56;
  }
  if (DAT_007939e0 == 0) {
    FUN_005f34d1(puVar2,0x4d0dfc);
    for (iVar1 = 1; iVar1 < 0x17; iVar1 = iVar1 + 1) {
      (&DAT_008a0024)[iVar1] = 0.0;
    }
    for (iVar1 = 1; iVar1 < 0x19; iVar1 = iVar1 + 1) {
      *(int *)(iVar1 * 4 + 0x89ffc4) = i_0;
    }
    DAT_0089ffc8 = f_1;
    DAT_008a0048 = 600;
    DAT_008a004c = 4;
    DAT_008a0050 = DAT_0078cbaa;
    _DAT_008a0058 = 1;
    DAT_008a0030 = 0;
    DAT_008a0034 = 1;
    _DAT_008a005c = 1;
    _DAT_008a0060 = 0;
    DAT_008a006c = 0;
    _DAT_008a0074 = 0;
    DAT_008a007c = 1;
    pcVar3 = s___computer_printer_0078dccc;
    puVar4 = &DAT_009af53c;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      puVar4 = puVar4 + 1;
    }
  }
  else {
    *(undefined4 *)(puVar2 + -0x54) = 0;
  }
  if (DAT_008a006c == 0) {
    FUN_005f33c9(puVar2,0x4d0f02);
    FUN_005f34d1(puVar2,0x4d0f1d);
    P1 = 0.0;
    *(undefined4 *)(puVar2 + -0x4c) = 0x80;
    DAT_0089ff38 = 1.79366e-43;
    do {
      if ((P1 == 0.0) && (iVar1 = FUN_005f4660(0x20), iVar1 == 0)) {
        P1 = DAT_0089ff38;
      }
      iVar1 = FUN_005f4660(0x20);
      if (iVar1 != 0) {
        *(undefined4 *)(puVar2 + -0x48) = 0;
        goto LAB_004d100e;
      }
      DAT_0089ff38 = (float)((int)DAT_0089ff38 + -1);
      *(int *)(puVar2 + -0x4c) = *(int *)(puVar2 + -0x4c) + -1;
    } while (0 < *(int *)(puVar2 + -0x4c));
    DAT_0089ff38 = (float)((int)P1 + 1);
LAB_004d100e:
    puVar4 = &DAT_0078b510;
    puVar5 = &DAT_009af4bc;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    FUN_005f46bc(puVar2,0x4d1060);
    FUN_005f34d1(puVar2,0x4d1076);
    pcVar3 = s___computer_printer_0078dccc;
    puVar4 = &DAT_009af53c;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      puVar4 = puVar4 + 1;
    }
  }
  else {
    *(undefined4 *)(puVar2 + -0x50) = 0;
  }
  do {
    _DAT_008a0064 = 1;
    DAT_0089ffcc = _DAT_0089ff60 * DAT_01c60caa;
    _DAT_0089ffd0 = _DAT_0089ff60 * DAT_01c60cae;
    DAT_008a0070 = DAT_0078b4e8;
    _DAT_0089ff60 = (DAT_01c60cae - f_0_75) * f_4000;
    *(int *)(puVar2 + -0x80) = DAT_01be6ca4 + -400;
    DAT_008a0018 = (float)*(int *)(puVar2 + -0x80);
    *(int *)(puVar2 + -0x80) = DAT_01be6ca8 + 0x69aa;
    DAT_008a001c = (float)*(int *)(puVar2 + -0x80) + _DAT_0089ff60;
    *(int *)(puVar2 + -0x80) = DAT_01be6cac + -400;
    DAT_008a0020 = (float)*(int *)(puVar2 + -0x80);
    *(int *)(puVar2 + -0x80) = DAT_01be6cb0 + 0x69aa;
    DAT_008a0024 = (float)*(int *)(puVar2 + -0x80) + _DAT_0089ff60;
    DAT_007939e0 = 1;
    DAT_019c6ad8 = DAT_008a0024;
    DAT_019c6adc = DAT_008a0020;
    DAT_019c6ae0 = DAT_008a001c;
    DAT_019c6ae4 = DAT_008a0018;
    iVar1 = FUN_00601a30(0x20);
    if (iVar1 != 0) {
      pcVar3 = "Letter (default)";
      puVar4 = &DAT_019c6a24;
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        puVar4 = puVar4 + 1;
      }
    }
    iVar1 = FUN_00601a30(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(puVar2,0x4d1205);
      FUN_005f34d1(puVar2,0x4d1220);
    }
    while( true ) {
      DAT_0089ff5c = thunk_FUN_0059b370(&DAT_008a0028,&DAT_0089ffc8,DAT_0089ff58);
      puVar4 = &DAT_009af53c;
      pcVar3 = s___computer_printer_0078dccc;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(undefined4 *)pcVar3 = *puVar4;
        puVar4 = puVar4 + 1;
        pcVar3 = pcVar3 + 4;
      }
      _DAT_008a0064 = 0;
      if (DAT_0089ff5c == 2) {
        DAT_020b8ea0._0_1_ = DAT_00765338;
        **(undefined4 **)(puVar2 + 8) = 0;
        *(undefined4 *)(puVar2 + -0x44) = 0;
        return;
      }
      _DAT_0089ff60 = f_1;
      if (DAT_008a0070 != 0) {
        _DAT_0089ff60 = f_2_56;
      }
      _DAT_01aae2b4 = DAT_01c60caa;
      _DAT_01aae2b8 = DAT_01c60cae;
      DAT_01c60caa = DAT_0089ffcc / _DAT_0089ff60;
      DAT_01c60cae = _DAT_0089ffd0 / _DAT_0089ff60;
      if (DAT_008a0078 == 1) {
        _DAT_01aae2b0 = f_28_346;
        *(undefined4 *)(puVar2 + -0x3c) = 0;
      }
      else if (DAT_008a0078 + -1 < 1) {
        _DAT_01aae2b0 = f_72;
        *(undefined4 *)(puVar2 + -0x40) = 0;
      }
      else {
        _DAT_01aae2b0 = f_1;
      }
      DAT_020b8e8c = DAT_0089ffc8;
      DAT_0078b6b0 = DAT_008a0028;
      FUN_004d31bb(&DAT_01c60caa,&DAT_01c60cae,&DAT_008a0018,&DAT_008a001c,&DAT_008a0020,
                   &DAT_008a0024,&DAT_0078b6b0);
      DAT_00793ab8 = DAT_008a0030;
      DAT_0078b47c = DAT_008a0048;
      _DAT_0078cb00 = DAT_008a004c;
      DAT_0078cba6 = DAT_008a002c;
      if (DAT_008a002c != 0) {
        FUN_005f33c9(puVar2,0x4d13bf);
      }
      DAT_0078cbb2 = DAT_008a0034;
      DAT_0089ff58 = DAT_008a0034;
      if (DAT_008a0034 != 0) break;
      puVar4 = &DAT_009af4bc;
      puVar5 = &DAT_0078cb22;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      _DAT_008a005c = 0;
      _DAT_008a0060 = 1;
      _DAT_008a0074 = 0;
      iVar1 = FUN_004d09d8(&DAT_0078cb22,0x80);
      if (iVar1 == 0) goto LAB_004d14d3;
      *(undefined4 *)(puVar2 + -0x38) = 0;
    }
    if (DAT_008a0034 == 1) {
      FUN_005f33c9(puVar2,0x4d1469);
      FUN_005f34d1(puVar2,0x4d1484);
      _DAT_008a005c = 1;
      _DAT_008a0060 = 0;
      _DAT_008a0074 = 0;
    }
    else {
      puVar4 = &DAT_009af53c;
      puVar5 = &DAT_0078cb22;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      _DAT_008a005c = 0;
      _DAT_008a0060 = 0;
      _DAT_008a0074 = 1;
    }
LAB_004d14d3:
    DAT_0078b6b0 = DAT_008a0028;
    DAT_0078cba2 = DAT_008a0044;
    DAT_020b8e8c = DAT_0089ffc8;
    _DAT_0078b480 = f_4000 / (float)DAT_0078b47c;
    _DAT_007939ec = DAT_0089ffd4;
    _DAT_007939e8 = DAT_0089ffd8;
    fVar6 = (float10)anint(puVar2,0x4d153a);
    *(int *)(puVar2 + -0x80) = (int)ROUND(fVar6);
    DAT_01aae2d0 = *(int *)(puVar2 + -0x80) + 0x318;
    fVar6 = (float10)anint(puVar2,0x4d156c);
    *(int *)(puVar2 + -0x80) = (int)ROUND(fVar6);
    DAT_01aae2d4 = *(int *)(puVar2 + -0x80) + 0xd;
    if (DAT_008a0038 != 0) {
      DAT_020b8ea0._1_1_ = 0x42;
      if (DAT_008a0038 == 2) {
        DAT_020b8ea2 = DAT_0076534c;
      }
      DAT_01aae304 = DAT_008a007c;
      DAT_020b8ea4 = DAT_0076538c;
      if (DAT_008a0054 != 0) {
        DAT_020b8ea4 = DAT_00765348;
      }
    }
    _DAT_0089ff54 = 0;
    DAT_0078b4e0 = 0;
    DAT_0078cbb6 = DAT_007939e4;
    DAT_0078cbaa = DAT_008a0050;
    if (DAT_008a0050 == 6) {
      _DAT_0089ff60 = f_72;
      if (DAT_0078b4e8 != 0) {
        _DAT_0089ff60 = f_28_3466;
      }
      *(undefined2 *)(puVar2 + -0x84) = in_FPUControlWord;
      *(ushort *)(puVar2 + -0x82) = (ushort)*(undefined4 *)(puVar2 + -0x84) | 0xc00;
      *(int *)(puVar2 + -0x80) = (int)ROUND(_DAT_0089ff60 * _DAT_0089fff0);
      _DAT_01aae290 = *(undefined4 *)(puVar2 + -0x80);
      *(undefined2 *)(puVar2 + -0x84) = *(undefined2 *)(puVar2 + -0x84);
      *(ushort *)(puVar2 + -0x82) = (ushort)*(undefined4 *)(puVar2 + -0x84) | 0xc00;
      *(int *)(puVar2 + -0x80) = (int)ROUND(_DAT_0089ff60 * _DAT_0089fff4);
      in_FPUControlWord = *(undefined2 *)(puVar2 + -0x84);
      _DAT_01aae294 = *(undefined4 *)(puVar2 + -0x80);
    }
    DAT_0089ff50 = 2000;
    DAT_0089ff4c = 3000;
    if (0x898 < DAT_0078cafc) {
      DAT_0089ff4c = DAT_0078cafc + 800;
    }
    if (DAT_01aae2d0 == 0) {
      DAT_01aae2d0 = 0x30b;
    }
    else {
      *(undefined4 *)(puVar2 + -0x34) = 0;
    }
    if (DAT_01aae2d4 == 0) {
      DAT_01aae2d4 = 0x1a;
      *(undefined4 *)(puVar2 + -0x2c) = 0;
    }
    else {
      *(undefined4 *)(puVar2 + -0x30) = 0;
    }
    if (DAT_0089ff48 != 0) {
      DAT_0089ff50 = DAT_0089ff44;
      DAT_0089ff4c = DAT_0089ff40;
    }
    _DAT_0078caf8 = DAT_0089ff50;
    DAT_0078cafc = DAT_0089ff4c;
    DAT_0089ff44 = DAT_0089ff50;
    DAT_0089ff40 = DAT_0089ff4c;
    DAT_0089ff70 = DAT_00765340;
    DAT_0089ff72 = DAT_00765342;
    *(undefined4 *)(puVar2 + -0x28) = 0;
    if (DAT_0078cbb2 == 1) {
      *(undefined4 *)(puVar2 + -0x20) = 0;
      goto LAB_004d1939;
    }
    *(undefined4 *)(puVar2 + -0x24) = 0;
    if (DAT_0078cbb2 == 2) {
      *(undefined4 *)(puVar2 + -0x1c) = 0;
      goto LAB_004d1939;
    }
    if (DAT_01aae304 == 0) {
      *(undefined4 *)(puVar2 + -0x18) = 0;
      goto LAB_004d1939;
    }
    if (DAT_0078cbb2 != 0) {
      puVar4 = &DAT_01a14984;
      puVar5 = &DAT_0078cb22;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    thunk_FUN_0054c83c(&DAT_0078cb22,1,&DAT_0076533c);
    if (DAT_0078cb22 == 0x3154504c) {
      FUN_005f34d1(puVar2,0x4d190f);
      **(undefined4 **)(puVar2 + 8) = 1;
      *(undefined4 *)(puVar2 + -0x10) = 0;
      _DAT_01c60cb2 = DAT_020b8e8c;
      return;
    }
    *(undefined4 *)(puVar2 + -0x14) = 0;
    thunk_FUN_00571b78(&DAT_0078cb22,0x80,"EPS",3);
    DAT_0078b4e4 = DAT_0078b4e0;
    thunk_FUN_0049731a(&DAT_0078cb22,0x80,&P1);
    if (P1 != 0.0) {
      if (P1 == -NAN) {
        DAT_020b8ea0._0_1_ = DAT_00765338;
        *(undefined4 *)(puVar2 + -4) = 0;
      }
      else {
        *(undefined4 *)(puVar2 + -8) = 0;
LAB_004d1939:
        _DAT_01c60cb2 = DAT_020b8e8c;
        **(undefined4 **)(puVar2 + 8) = 1;
      }
      return;
    }
    *(undefined4 *)(puVar2 + -0xc) = 0;
  } while( true );
}


