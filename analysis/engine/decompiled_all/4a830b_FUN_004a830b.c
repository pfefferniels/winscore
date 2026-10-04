// FUN_004a830b @ 004a830b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a830b(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined2 in_FPUControlWord;
  float10 fVar7;
  unkbyte10 extraout_ST0;
  unkbyte10 Var8;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  
  puVar3 = &stack0xfffffffc;
  DAT_01b9d630 = 2000;
  _DAT_01b9d634 = f_0_1;
  _DAT_01b9d638 = f_0_25;
  DAT_0088d248 = DAT_02052740;
  FUN_005f46bc(&stack0xfffffffc,0x4a8377);
  FUN_005f46bc(puVar3,0x4a8393);
  FUN_005f34d1(puVar3,0x4a83a9);
  FUN_005f46bc(puVar3,0x4a83de);
  FUN_005f46bc(puVar3,0x4a83fa);
  fVar7 = (float10)FUN_005f34d1(puVar3,0x4a8410);
LAB_004a8414:
  *(undefined4 *)(puVar3 + -0xb8) = 0;
  *(undefined4 *)(puVar3 + -0xc0) = 0x200;
  *(ushort **)(puVar3 + -0xbc) = &DAT_020b8ea0;
  ffree(fVar7);
  uVar1 = FUN_005fdbd0(puVar3 + -0xb8,DAT_0088d248,0x784ff01,&DAT_00763d88,puVar3 + -0xc0,
                       &DAT_00791a14);
  *(undefined4 *)(puVar3 + -0x98) = uVar1;
  if (*(int *)(puVar3 + -0x98) != 0) {
LAB_004a9494:
    *(undefined4 *)(puVar3 + -4) = 0;
    DAT_0078b4c0 = FUN_004a81c0(&DAT_0088d298,0x80,&DAT_00763d64);
    DAT_0078b4c4 = FUN_004a81c0(&DAT_019c682c,0x80,&DAT_00763d64);
    puVar4 = &DAT_0088d298;
    puVar6 = &DAT_00790b90;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    ffree(extraout_ST0_01);
    return;
  }
  DAT_0088d244 = FUN_004a81c0(&DAT_020b8ea0,1,&DAT_00763d84);
  if ((&DAT_020b8e9f)[DAT_0088d244] == '\0') {
    (&DAT_020b8e9f)[DAT_0088d244] = 0x20;
  }
  ffree(extraout_ST0);
  fVar7 = (float10)thunk_FUN_0054c6b5(&DAT_020b8ea0,1,&DAT_0088d244,&DAT_0078b4e0,&DAT_0078b4e4);
  DAT_0088d264 = _DAT_020b8ea0;
  DAT_0078b4e0 = 0x58;
  if ((((s_METRINCHBEAMBMTHRESTDASHMIDKPROC_007921c0._228_4_ == _DAT_020b8ea0) ||
       (s_METRINCHBEAMBMTHRESTDASHMIDKPROC_007921c0._200_4_ == _DAT_020b8ea0)) ||
      (s_METRINCHBEAMBMTHRESTDASHMIDKPROC_007921c0._196_4_ == _DAT_020b8ea0)) ||
     ((s_METRINCHBEAMBMTHRESTDASHMIDKPROC_007921c0._128_4_ == _DAT_020b8ea0 ||
      (s_METRINCHBEAMBMTHRESTDASHMIDKPROC_007921c0._132_4_ == _DAT_020b8ea0)))) {
    *(undefined4 *)(puVar3 + -0x94) = 0;
  }
  else {
    ffree(fVar7);
    fVar7 = (float10)thunk_FUN_00518b3f(&DAT_0088d244);
  }
  iVar2 = _DAT_020b8ea0;
  *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
  *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
  *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
  in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
  DAT_0078b4e4 = *(int *)(puVar3 + -0xbc);
  *(undefined4 *)(puVar3 + -0x90) = 0x1d;
  DAT_0088d240 = 1;
LAB_004a85ea:
  if (*(int *)(s_METRINCHBEAMBMTHRESTDASHMIDKPROC_007921c0 + DAT_0088d240 * 4 + 0x7c) ==
      DAT_0088d264) {
    switch(DAT_0088d240) {
    case 1:
      DAT_0078b4e8 = 1;
      *(undefined4 *)(puVar3 + -0x88) = 0;
      goto LAB_004a8414;
    case 2:
      DAT_0078b4e8 = 0;
      *(undefined4 *)(puVar3 + -0x84) = 0;
      goto LAB_004a8414;
    case 3:
      if (P2 == f_0) {
        P2 = P4;
      }
      if (P2 != f_0) {
        DAT_0078b470 = P2 / f_100;
      }
      *(undefined4 *)(puVar3 + -0x80) = 0;
      goto LAB_004a8414;
    case 4:
      if (DAT_0078b4e4 != 0) {
        DAT_0078b478 = DAT_0078b4e4;
      }
      *(undefined4 *)(puVar3 + -0x7c) = 0;
      goto LAB_004a8414;
    case 5:
      *(undefined4 *)(puVar3 + -0x78) = 0;
      DAT_0078b474 = DAT_0078b4e4;
      goto LAB_004a8414;
    case 6:
      if (P2 != f_0) {
        _DAT_0078ded8 = P2 / _DAT_0078ded4;
      }
      *(undefined4 *)(puVar3 + -0x74) = 0;
      goto LAB_004a8414;
    case 7:
      *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND(P4);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
      DAT_0088d240 = *(int *)(puVar3 + -0xbc);
      if (DAT_0088d240 == 0) {
        *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
        *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
        DAT_0088d240 = *(int *)(puVar3 + -0xbc);
      }
      if (DAT_0088d240 == 0) {
        *(undefined4 *)(puVar3 + -0x70) = 0;
      }
      else {
        DAT_0078b4a8 = DAT_0088d240 * 0xc + 0xc;
        if (P2 != f_0) {
          *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
          *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
          DAT_0078b4a8 = *(int *)(puVar3 + -0xbc);
        }
        iRam0088d23c = DAT_0078b4a8 / 0xc + -1;
        DAT_020b8ea0 = CONCAT11((char)iRam0088d23c + '0',DAT_00763d80);
        IP1._0_2_ = DAT_020b8ea0;
        DAT_020b8ea3 = SUB41(iVar2,3);
        _DAT_020b8ea0 = (uint3)DAT_020b8ea0;
        IP1._2_1_ = 0;
        *(undefined4 *)(puVar3 + -0x6c) = 0;
      }
      goto LAB_004a8414;
    case 8:
      if (DAT_0078b4e4 != 0) {
        DAT_0078dc68 = DAT_0078b4e4;
      }
      *(undefined4 *)(puVar3 + -0x68) = 0;
      goto LAB_004a8414;
    case 9:
      *(undefined4 *)(puVar3 + -100) = 0;
      DAT_0078b484 = DAT_0078b4e4;
      goto LAB_004a8414;
    case 10:
      *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
      DAT_0078b4a4 = *(undefined4 *)(puVar3 + -0xbc);
      *(undefined4 *)(puVar3 + -0x60) = 0;
      goto LAB_004a8414;
    case 0xb:
      DAT_0078b488 = P2;
      *(undefined4 *)(puVar3 + -0x5c) = 0;
      goto LAB_004a8414;
    case 0xc:
      DAT_0078b48c = P2;
      *(undefined4 *)(puVar3 + -0x58) = 0;
      goto LAB_004a8414;
    case 0xd:
      DAT_0078b490 = P2;
      *(undefined4 *)(puVar3 + -0x54) = 0;
      goto LAB_004a8414;
    case 0xe:
      DAT_0078b494 = P2;
      *(undefined4 *)(puVar3 + -0x50) = 0;
      goto LAB_004a8414;
    case 0xf:
      DAT_0078b498 = P2;
      *(undefined4 *)(puVar3 + -0x4c) = 0;
      goto LAB_004a8414;
    case 0x10:
      DAT_0078b49c = P2;
      *(undefined4 *)(puVar3 + -0x48) = 0;
      goto LAB_004a8414;
    case 0x11:
      *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
      DAT_0078b4a0 = *(undefined4 *)(puVar3 + -0xbc);
      *(undefined4 *)(puVar3 + -0x44) = 0;
      goto LAB_004a8414;
    case 0x12:
      FUN_005f34d1(puVar3,&UNK_004a8a17);
      FUN_005f46bc(puVar3,&UNK_004a8a52);
      Var8 = FUN_005f34d1(puVar3,&UNK_004a8a68);
      if ((DAT_020b8ea6 == '\\') || ((char)DAT_020b8ea8 == '\\')) {
        *(undefined4 *)(puVar3 + -0x40) = 0;
      }
      else {
        FUN_005f46bc(puVar3,&UNK_004a8ac7);
        FUN_005f46bc(puVar3,&UNK_004a8ae3);
        FUN_005f34d1(puVar3,&UNK_004a8af9);
        iVar2 = DAT_0088d244 + -6;
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        *(int *)(puVar3 + -0xbc) = iVar2;
        *(undefined4 *)(puVar3 + -0xc0) = 6;
        FUN_005f46bc(puVar3,&UNK_004a8b52);
        FUN_005f46bc(puVar3,&UNK_004a8b75);
        FUN_005f46bc(puVar3,&UNK_004a8b91);
        FUN_005f46bc(puVar3,&UNK_004a8bb7);
        Var8 = FUN_005f34d1(puVar3,&UNK_004a8bcd);
      }
      puVar4 = &DAT_0088d298;
      puVar6 = &DAT_00790b90;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      ffree(Var8);
      FUN_004acee1(&DAT_00790b90,0x80,0x88d238);
      FUN_005f46bc(puVar3,&UNK_004a8c50);
      Var8 = FUN_005f34d1(puVar3,&UNK_004a8c66);
      DAT_0078b4c0 = uRam0088d238;
      ffree(Var8);
      FUN_004ac54f(&DAT_00790b90,0x80);
      FUN_005f46bc(puVar3,&UNK_004a8cba);
      FUN_005f46bc(puVar3,&UNK_004a8cd6);
      fVar7 = (float10)FUN_005f34d1(puVar3,&UNK_004a8cec);
      *(undefined4 *)(puVar3 + -0x3c) = 0;
      goto LAB_004a8414;
    case 0x13:
      FUN_005f34d1(puVar3,&UNK_004a8d19);
      FUN_005f46bc(puVar3,&UNK_004a8d54);
      Var8 = FUN_005f34d1(puVar3,&UNK_004a8d6a);
      if ((DAT_020b8ea6 == '\\') || ((char)DAT_020b8ea8 == '\\')) {
        *(undefined4 *)(puVar3 + -0x38) = 0;
      }
      else {
        iVar2 = DAT_0088d244 + -6;
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        *(int *)(puVar3 + -0xbc) = iVar2;
        *(undefined4 *)(puVar3 + -0xc0) = 6;
        FUN_005f46bc(puVar3,&UNK_004a8dea);
        FUN_005f46bc(puVar3,&UNK_004a8e06);
        FUN_005f46bc(puVar3,&UNK_004a8e29);
        FUN_005f46bc(puVar3,&UNK_004a8e45);
        Var8 = FUN_005f34d1(puVar3,&UNK_004a8e5b);
      }
      puVar4 = &DAT_019c682c;
      puVar6 = &DAT_00790b90;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      ffree(Var8);
      FUN_004acee1(&DAT_00790b90,0x80,0x88d238);
      FUN_005f46bc(puVar3,&UNK_004a8ede);
      Var8 = FUN_005f34d1(puVar3,&UNK_004a8ef4);
      DAT_0078b4c4 = uRam0088d238;
      ffree(Var8);
      FUN_004ac7fb(&DAT_00790b90,0x80);
      FUN_005f46bc(puVar3,&UNK_004a8f48);
      FUN_005f46bc(puVar3,&UNK_004a8f64);
      fVar7 = (float10)FUN_005f34d1(puVar3,&UNK_004a8f7a);
      *(undefined4 *)(puVar3 + -0x34) = 0;
      goto LAB_004a8414;
    case 0x14:
      _DAT_0078dc80 = P2;
      *(undefined4 *)(puVar3 + -0x30) = 0;
      goto LAB_004a8414;
    case 0x15:
      *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
      PAPER = *(int *)(puVar3 + -0xbc);
      *(undefined4 *)(puVar3 + -0x2c) = 0;
      goto LAB_004a8414;
    case 0x16:
      *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
      P1 = *(float *)(puVar3 + -0xbc);
      iRam0088d234 = (int)P1 / 1000000;
      iRam0088d230 = ((int)P1 % 1000000) / 10000;
      iRam0088d22c = ((int)P1 % 10000) / 100;
      iRam0088d228 = (int)P1 % 100;
      fVar7 = (float10)((iRam0088d234 / 2) * 1000 + (iRam0088d230 / 3) * 100 +
                        (iRam0088d22c / 5) * 10 + iRam0088d228 / 8);
      *(undefined2 *)(puVar3 + -0xc0) = *(undefined2 *)(puVar3 + -0xc0);
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND((float10)_DAT_0078dc80 * (float10)f_1000000 + fVar7);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
      DAT_0078dc84 = *(undefined4 *)(puVar3 + -0xbc);
      *(undefined4 *)(puVar3 + -0x28) = 0;
      goto LAB_004a8414;
    case 0x17:
      *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
      DAT_0078df00 = *(undefined4 *)(puVar3 + -0xbc);
      *(undefined4 *)(puVar3 + -0x24) = 0;
      goto LAB_004a8414;
    case 0x18:
      *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
      DAT_01b9d63c = *(int *)(puVar3 + -0xbc);
      if (DAT_01b9d63c != 0) {
        DAT_01b9d630 = -DAT_01b9d630;
        _DAT_01b9d634 = -_DAT_01b9d634;
        fVar7 = (float10)_DAT_01b9d638;
        _DAT_01b9d638 = (float)-fVar7;
      }
      *(undefined4 *)(puVar3 + -0x20) = 0;
      goto LAB_004a8414;
    case 0x19:
      *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
      DAT_0078df04 = *(undefined4 *)(puVar3 + -0xbc);
      *(undefined4 *)(puVar3 + -0x1c) = 0;
      goto LAB_004a8414;
    case 0x1a:
      FUN_005f34d1(puVar3,&UNK_004a9276);
      FUN_005f46bc(puVar3,&UNK_004a92b1);
      FUN_005f46bc(puVar3,&UNK_004a92cd);
      FUN_005f34d1(puVar3,&UNK_004a92e3);
      iVar2 = FUN_005f4660(0x20);
      if (iVar2 != 0) {
        *(undefined4 *)(puVar3 + -0x18) = 0;
        goto LAB_004a9494;
      }
      ffree(extraout_ST0_00);
      fVar7 = (float10)FUN_004acfe5(s___computer_printer_0078dccc,0x80,&DAT_00763d64);
      pcVar5 = s___computer_printer_0078dccc;
      puVar4 = &DAT_009af53c;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        puVar4 = puVar4 + 1;
      }
      *(undefined4 *)(puVar3 + -0x14) = 0;
      goto LAB_004a8414;
    case 0x1b:
      DAT_0078b390 = (&DAT_020b8e9f)[DAT_0088d244];
      if (DAT_0078b390 == ' ') {
        DAT_0078b390 = (&DAT_020b8e9e)[DAT_0088d244];
      }
      if ((DAT_0088d244 < 6) || (DAT_0078b390 == ' ')) {
        DAT_0078b390 = DAT_00763c28;
      }
      FUN_005f33c9(puVar3,&UNK_004a93d1);
      fVar7 = (float10)FUN_005f34d1(puVar3,&UNK_004a93ec);
      *(undefined4 *)(puVar3 + -0x10) = 0;
      goto LAB_004a8414;
    case 0x1c:
      if (P2 == f_0) {
        P2 = f_m1;
      }
      *(undefined2 *)(puVar3 + -0xc0) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0xbe) = (ushort)*(undefined4 *)(puVar3 + -0xc0) | 0xc00;
      *(int *)(puVar3 + -0xbc) = (int)ROUND(P2);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0xc0);
      DAT_01fbb6f8 = *(undefined4 *)(puVar3 + -0xbc);
      *(undefined4 *)(puVar3 + -0xc) = 0;
      goto LAB_004a8414;
    case 0x1d:
      _DAT_0078b4b8 = P2;
      *(undefined4 *)(puVar3 + -8) = 0;
      goto LAB_004a8414;
    }
  }
  DAT_0088d240 = DAT_0088d240 + 1;
  *(int *)(puVar3 + -0x90) = *(int *)(puVar3 + -0x90) + -1;
  if (*(int *)(puVar3 + -0x90) < 1) goto LAB_004a947e;
  goto LAB_004a85ea;
LAB_004a947e:
  *(undefined4 *)(puVar3 + -0x8c) = 0;
  goto LAB_004a8414;
}


