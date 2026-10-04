// FUN_00552d80 @ 00552d80 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00552d80(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined2 in_FPUControlWord;
  undefined2 uVar7;
  float10 fVar8;
  
  puVar3 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x552daa);
  FUN_005f34d1(puVar3,0x552dc5);
  FUN_005f46bc(puVar3,0x552dfa);
  FUN_005f46bc(puVar3,0x552e16);
  FUN_005f34d1(puVar3,0x552e2c);
  if (f_0 <= P2) {
    FUN_005f46bc(puVar3,0x552e74);
    FUN_005f46bc(puVar3,0x552e90);
    FUN_005f34d1(puVar3,0x552ea6);
  }
  OUTPUT_MODE = 1;
  *(undefined2 *)(puVar3 + -0xb4) = in_FPUControlWord;
  *(ushort *)(puVar3 + -0xb2) = (ushort)*(undefined4 *)(puVar3 + -0xb4) | 0xc00;
  *(int *)(puVar3 + -0xb0) = (int)ROUND(P2);
  uVar7 = *(undefined2 *)(puVar3 + -0xb4);
  DAT_009a36b4 = *(int *)(puVar3 + -0xb0);
  puVar4 = &DAT_009a3738;
  puVar5 = &DAT_009a36b8;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(puVar3 + -0xac) = 0;
  *(undefined4 *)(puVar3 + -0xc0) = 0x80;
  *(undefined4 **)(puVar3 + -0xbc) = &DAT_009a36b8;
  *(undefined4 *)(puVar3 + -0xb8) = 2;
  *(undefined4 *)(puVar3 + -0xb4) = 4;
  FUN_005f6540(puVar3 + -0xac,7,0x784ff00,&DAT_00769868,puVar3 + -0xc0);
  if (P2 < f_0) {
    iVar2 = ITEM_I + 1;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    DAT_009a36b0 = iVar2 + 1;
    *(undefined4 *)(puVar3 + -0xac) = 0;
    *(undefined4 *)(puVar3 + -200) = 1;
    *(undefined4 **)(puVar3 + -0xc4) = &DAT_02091d20;
    *(undefined4 *)(puVar3 + -0xc0) = 1;
    *(int *)(puVar3 + -0xbc) = iVar2;
    *(undefined4 *)(puVar3 + -0xb8) = 4;
    FUN_005fc330(puVar3 + -0xac,7,0x784ff00,&DAT_00769844,puVar3 + -200,&DAT_0079eae8);
    *(undefined4 *)(puVar3 + -0xac) = 0;
    FUN_005fc330(puVar3 + -0xac,7,0x784ff00,&DAT_00769840,0,&DAT_0079eafc);
    *(int *)(puVar3 + -0x7c) = ITEM_I;
    DAT_009a36b0 = 1;
    iVar2 = ITEM_I;
    while (0 < iVar2) {
      *(undefined4 *)(puVar3 + -0xac) = 0;
      *(int **)(puVar3 + -0xb8) = &DAT_009a36b0;
      FUN_005fc330(puVar3 + -0xac,7,0x784ff00,&DAT_00769854,puVar3 + -0xb8,&DAT_0079eb0c);
      DAT_009a36ac = (&ITEM_PTR0)[DAT_009a36b0];
      fVar1 = (float)(&ITEM_LEN)[DAT_009a36ac];
      *(undefined2 *)(puVar3 + -0xb4) = uVar7;
      *(ushort *)(puVar3 + -0xb2) = (ushort)*(undefined4 *)(puVar3 + -0xb4) | 0xc00;
      *(int *)(puVar3 + -0xb0) = (int)ROUND(fVar1);
      uVar7 = *(undefined2 *)(puVar3 + -0xb4);
      DAT_009a36a8 = *(int *)(puVar3 + -0xb0);
      if ((float)(&ITEM_P1)[DAT_009a36ac] == f_16) {
        DAT_009a36a8 = 0xd;
      }
      iVar6 = DAT_009a36ac + 1;
      iVar2 = ((DAT_009a36a8 + DAT_009a36ac) - iVar6) + 1;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      DAT_009a36b4 = iVar6 + iVar2;
      *(undefined4 *)(puVar3 + -0xac) = 0;
      *(undefined4 *)(puVar3 + -200) = 1;
      *(undefined4 **)(puVar3 + -0xc4) = &ITEM_LEN + iVar6;
      *(undefined4 *)(puVar3 + -0xc0) = 1;
      *(int *)(puVar3 + -0xbc) = iVar2;
      *(undefined4 *)(puVar3 + -0xb8) = 4;
      FUN_005fc330(puVar3 + -0xac,7,0x784ff00,&DAT_00769838,puVar3 + -200,&DAT_0079eb28);
      if ((float)(&ITEM_P1)[DAT_009a36ac] == f_16) {
        fVar1 = *(float *)(&ITEM_P12 + DAT_009a36ac * 4);
        *(undefined2 *)(puVar3 + -0xb4) = uVar7;
        *(ushort *)(puVar3 + -0xb2) = (ushort)*(undefined4 *)(puVar3 + -0xb4) | 0xc00;
        *(int *)(puVar3 + -0xb0) = (int)ROUND(fVar1);
        uVar7 = *(undefined2 *)(puVar3 + -0xb4);
        DAT_009a36a8 = *(int *)(puVar3 + -0xb0);
        DAT_009a36b4 = DAT_009a36ac * 4 + 0x35;
        *(undefined4 *)(puVar3 + -0xac) = 0;
        FUN_005fc330(puVar3 + -0xac,7,0x784ff00,&DAT_00769834,0,&DAT_0079eb3c);
        DAT_009a36ac = DAT_009a36b4;
        for (iVar2 = DAT_009a36a8; 0 < iVar2; iVar2 = iVar2 + -1) {
          *(undefined4 *)(puVar3 + -0xc0) = 1;
          *(int *)(puVar3 + -0xbc) = DAT_009a36ac + 0x205343f;
          *(undefined4 *)(puVar3 + -0xb8) = 1;
          FUN_005fc980(puVar3 + -0xac,&DAT_00769830,puVar3 + -0xc0);
          DAT_009a36ac = DAT_009a36ac + 1;
        }
        FUN_005fc980(puVar3 + -0xac,&DAT_00769840,0);
      }
      else {
        *(undefined4 *)(puVar3 + -0x70) = 0;
      }
      *(undefined4 *)(puVar3 + -0xac) = 0;
      *(undefined4 *)(puVar3 + -0xb8) = 1;
      *(undefined **)(puVar3 + -0xb4) = &DAT_0076982c;
      FUN_00606890(puVar3 + -0xac,7,0x784ff00,&DAT_00769828,puVar3 + -0xb8);
      DAT_009a36b0 = DAT_009a36b0 + 1;
      *(int *)(puVar3 + -0x7c) = *(int *)(puVar3 + -0x7c) + -1;
      iVar2 = *(int *)(puVar3 + -0x7c);
    }
    *(undefined4 *)(puVar3 + -0xac) = 0;
    FUN_005f7950(puVar3 + -0xac,7,0x784ff00,&DAT_00769848,0);
    *(undefined4 *)(puVar3 + -0x60) = 0;
  }
  else {
    *(undefined4 *)(puVar3 + -0x88) = 0;
    DAT_009a36a4 = 0;
    DAT_009a36a0 = -99999;
    _DAT_009a369c = 99999;
    *(undefined2 *)(puVar3 + -0xb4) = uVar7;
    *(ushort *)(puVar3 + -0xb2) = (ushort)*(undefined4 *)(puVar3 + -0xb4) | 0xc00;
    *(int *)(puVar3 + -0xb0) = (int)ROUND(P2);
    DAT_009a3698 = *(int *)(puVar3 + -0xb0);
    *(undefined2 *)(puVar3 + -0xb4) = *(undefined2 *)(puVar3 + -0xb4);
    *(ushort *)(puVar3 + -0xb2) = (ushort)*(undefined4 *)(puVar3 + -0xb4) | 0xc00;
    *(int *)(puVar3 + -0xb0) = (int)ROUND(P3);
    uVar7 = *(undefined2 *)(puVar3 + -0xb4);
    DAT_009a3694 = *(int *)(puVar3 + -0xb0);
    if (DAT_009a3694 == 0) {
      DAT_009a3694 = ITEM_I;
    }
    if (DAT_009a3698 == 0) {
      DAT_009a3698 = 1;
    }
    NPT = 1;
    iVar2 = (DAT_009a3694 - DAT_009a3698) + 1;
    *(int *)(puVar3 + -0x5c) = iVar2;
    DAT_009a36b0 = DAT_009a3698;
    while (0 < iVar2) {
      DAT_009a36ac = (&ITEM_PTR0)[DAT_009a36b0];
      fVar1 = (float)(&ITEM_LEN)[DAT_009a36ac];
      *(undefined2 *)(puVar3 + -0xb4) = uVar7;
      *(ushort *)(puVar3 + -0xb2) = (ushort)*(undefined4 *)(puVar3 + -0xb4) | 0xc00;
      *(int *)(puVar3 + -0xb0) = (int)ROUND(fVar1);
      uVar7 = *(undefined2 *)(puVar3 + -0xb4);
      DAT_009a3690 = *(int *)(puVar3 + -0xb0);
      for (iVar2 = 1; iVar2 < 0x33; iVar2 = iVar2 + 1) {
        *(float *)(&P0 + iVar2 * 4) = f_0;
      }
      *(int *)(puVar3 + -0x58) = DAT_009a3690;
      DAT_009a36b4 = 1;
      iVar2 = DAT_009a3690;
      while (0 < iVar2) {
        *(undefined4 *)(&P0 + DAT_009a36b4 * 4) = (&ITEM_LEN)[DAT_009a36b4 + DAT_009a36ac];
        DAT_009a36b4 = DAT_009a36b4 + 1;
        *(int *)(puVar3 + -0x58) = *(int *)(puVar3 + -0x58) + -1;
        iVar2 = *(int *)(puVar3 + -0x58);
      }
      draw_item();
      *(undefined4 *)(puVar3 + -0x54) = 0;
      DAT_009a36b0 = DAT_009a36b0 + 1;
      *(int *)(puVar3 + -0x5c) = *(int *)(puVar3 + -0x5c) + -1;
      iVar2 = *(int *)(puVar3 + -0x5c);
    }
    iVar2 = NPT + -1;
    *(int *)(puVar3 + -0x50) = iVar2;
    DAT_009a3684 = 1;
    while (0 < iVar2) {
      DAT_009a36b4 = (&PT_X0)[DAT_009a3684] - DAT_01fd3f80;
      if (DAT_009a36a0 < DAT_009a36b4) {
        DAT_009a36a0 = DAT_009a36b4;
      }
      DAT_009a3684 = DAT_009a3684 + 1;
      *(int *)(puVar3 + -0x50) = *(int *)(puVar3 + -0x50) + -1;
      iVar2 = *(int *)(puVar3 + -0x50);
    }
    if (DAT_009a36a0 < 0x191) {
      *(undefined4 *)(puVar3 + -0x4c) = 0;
      _DAT_009a3680 = f_1;
    }
    else {
      _DAT_009a367c = (float)DAT_009a36a0;
      _DAT_009a3680 = f_400 / _DAT_009a367c;
    }
    iVar2 = NPT + -1;
    *(int *)(puVar3 + -0x48) = iVar2;
    DAT_009a3684 = 1;
    _DAT_009a368c = DAT_01fd3f80;
    _DAT_009a3688 = DAT_02004cc0;
    while (0 < iVar2) {
      iVar2 = (&PT_X0)[DAT_009a3684];
      iVar6 = (&PT_Y0)[DAT_009a3684];
      DAT_009a3678 = (int)*(short *)((int)&DAT_01fbb8dc + DAT_009a3684 * 2 + 2);
      DAT_009a36b0 = iVar6;
      DAT_009a36b4 = iVar2;
      if ((DAT_009a36a4 == 0) || (DAT_009a3678 == 0)) {
        if ((DAT_009a3670 != iVar6) || ((DAT_009a3678 != 0 || (DAT_009a3674 != iVar2)))) {
          if (DAT_009a3684 == 1) {
            DAT_009a36b4 = 0;
            DAT_009a36b0 = 0;
            *(undefined4 *)(puVar3 + -0x38) = 0;
            _DAT_009a369c = iVar6;
            DAT_009a36a0 = iVar2;
          }
          else {
            *(undefined4 *)(puVar3 + -0x3c) = 0;
            *(int *)(puVar3 + -0xb0) = iVar2 - DAT_009a36a0;
            _DAT_009a367c = (float)*(int *)(puVar3 + -0xb0);
            *(int *)(puVar3 + -0xb0) = iVar6 - _DAT_009a369c;
            _DAT_009a366c = (float)*(int *)(puVar3 + -0xb0);
            fVar8 = (float10)FUN_005ff381(puVar3,0x553568);
            *(int *)(puVar3 + -0xb0) = (int)ROUND(fVar8);
            DAT_009a36b4 = *(int *)(puVar3 + -0xb0);
            fVar8 = (float10)FUN_005ff381(puVar3,0x55359a);
            *(int *)(puVar3 + -0xb0) = (int)ROUND(fVar8);
            DAT_009a36b0 = *(int *)(puVar3 + -0xb0);
          }
          goto LAB_005535e4;
        }
        *(undefined4 *)(puVar3 + -0x40) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x44) = 0;
        if (DAT_009a3678 == 1) {
          *(undefined4 *)(puVar3 + -0x2c) = 0;
          DAT_009a36a4 = 0;
          if ((DAT_009a3674 == DAT_009a3668) && (DAT_009a3670 == DAT_009a3664)) {
            *(undefined4 *)(puVar3 + -0x1c) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0xac) = 0;
            *(int **)(puVar3 + -0xb8) = &DAT_009a3668;
            FUN_005fc330(puVar3 + -0xac,7,0x784ff00,&DAT_0076985c,puVar3 + -0xb8,&DAT_0079eb78);
            *(int **)(puVar3 + -0xb8) = &DAT_009a3664;
            FUN_005fc980(puVar3 + -0xac,&DAT_0076985c,puVar3 + -0xb8);
            *(undefined4 *)(puVar3 + -0xb8) = 0;
            FUN_005fc980(puVar3 + -0xac,&DAT_00769858,puVar3 + -0xb8);
            *(undefined4 *)(puVar3 + -0x14) = 0;
          }
        }
        else {
          if ((DAT_009a36a4 == 1) || (DAT_009a3674 == DAT_009a3668 && DAT_009a3670 == DAT_009a3664))
          {
            *(undefined4 *)(puVar3 + -0x28) = 0;
          }
          else {
            DAT_009a36a4 = 1;
            *(undefined4 *)(puVar3 + -0xac) = 0;
            *(int **)(puVar3 + -0xb8) = &DAT_009a3668;
            FUN_005fc330(puVar3 + -0xac,7,0x784ff00,&DAT_0076985c,puVar3 + -0xb8,&DAT_0079eb64);
            *(int **)(puVar3 + -0xb8) = &DAT_009a3664;
            FUN_005fc980(puVar3 + -0xac,&DAT_0076985c,puVar3 + -0xb8);
            *(undefined4 *)(puVar3 + -0xb8) = 0;
            FUN_005fc980(puVar3 + -0xac,&DAT_00769858,puVar3 + -0xb8);
          }
          DAT_009a3668 = DAT_009a36b4;
          DAT_009a3664 = DAT_009a36b0;
          *(undefined4 *)(puVar3 + -0x20) = 0;
        }
LAB_005535e4:
        *(undefined4 *)(puVar3 + -0xac) = 0;
        *(int **)(puVar3 + -0xb8) = &DAT_009a36b4;
        FUN_005fc330(puVar3 + -0xac,7,0x784ff00,&DAT_0076985c,puVar3 + -0xb8,&DAT_0079eb50);
        *(int **)(puVar3 + -0xb8) = &DAT_009a36b0;
        FUN_005fc980(puVar3 + -0xac,&DAT_0076985c,puVar3 + -0xb8);
        *(int **)(puVar3 + -0xb8) = &DAT_009a3678;
        FUN_005fc980(puVar3 + -0xac,&DAT_00769854,puVar3 + -0xb8);
        DAT_009a3674 = DAT_009a36b4;
        DAT_009a3670 = DAT_009a36b0;
        *(undefined4 *)(puVar3 + -0x30) = 0;
      }
      DAT_009a3678 = 0;
      *(undefined4 *)(puVar3 + -0x10) = 0;
      DAT_009a3684 = DAT_009a3684 + 1;
      *(int *)(puVar3 + -0x48) = *(int *)(puVar3 + -0x48) + -1;
      iVar2 = *(int *)(puVar3 + -0x48);
    }
    FUN_005f33c9(puVar3,0x5536ec);
    FUN_005f33c9(puVar3,0x553708);
    FUN_005f34d1(puVar3,0x553723);
    if ((DAT_009a36a4 == 0) || (DAT_009a3674 == DAT_009a3668 && DAT_009a3670 == DAT_009a3664)) {
      *(undefined4 *)(puVar3 + -0xc) = 0;
    }
    else {
      *(undefined4 *)(puVar3 + -0xac) = 0;
      *(int **)(puVar3 + -0xb8) = &DAT_009a3668;
      FUN_005fc330(puVar3 + -0xac,7,0x784ff00,&DAT_0076985c,puVar3 + -0xb8,&DAT_0079eb8c);
      *(int **)(puVar3 + -0xb8) = &DAT_009a3664;
      FUN_005fc980(puVar3 + -0xac,&DAT_0076985c,puVar3 + -0xb8);
      *(undefined4 *)(puVar3 + -0xb8) = 0;
      FUN_005fc980(puVar3 + -0xac,&DAT_00769858,puVar3 + -0xb8);
    }
    *(undefined4 *)(puVar3 + -0xac) = 0;
    FUN_005f7950(puVar3 + -0xac,7,0x784ff00,&DAT_00769848,0);
    draw_items();
  }
  return;
}


