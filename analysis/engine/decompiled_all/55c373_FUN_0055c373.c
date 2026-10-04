// FUN_0055c373 @ 0055c373 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055c373(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var4;
  float10 fVar5;
  float10 extraout_ST1;
  undefined1 *puVar6;
  
  puVar6 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if (*param_1 == 1) {
    FUN_005f33c9(&stack0xfffffffc,0x55c3be);
    puVar3 = puVar6;
    Var4 = FUN_005f33c9(puVar6,0x55c3da);
    *(undefined1 **)(puVar3 + -0x7c) = puVar3 + -0x98;
    *(undefined4 *)(puVar3 + -0x80) = 0x12;
    *(undefined4 *)(puVar3 + -0x78) = 2;
    *(undefined4 *)(puVar3 + -0x74) = 4;
    ffree(Var4);
    in_ST0 = FUN_005f6540(puVar3 + -0x68,9,0x784ff00,&DAT_00769cbc,puVar3 + -0x80);
  }
  if (**(int **)(puVar3 + 8) == 2) {
    *(undefined4 *)(puVar3 + -0x70) = DAT_0078b464;
    *(undefined4 *)(puVar3 + -0x6c) = DAT_0078b468;
    *(undefined4 *)(puVar3 + -0x68) = 0;
    FUN_005f33c9(puVar3,0x55c464);
    Var4 = FUN_005f33c9(puVar3,0x55c480);
    *(undefined1 **)(puVar3 + -0x7c) = puVar3 + -0x98;
    *(undefined4 *)(puVar3 + -0x80) = 0x12;
    *(undefined4 *)(puVar3 + -0x78) = 2;
    *(undefined4 *)(puVar3 + -0x74) = 4;
    ffree(Var4);
    in_ST0 = FUN_005f6540(puVar3 + -0x68,9,0x784ff00,&DAT_00769cbc,puVar3 + -0x80);
  }
  *(undefined4 *)(puVar3 + -0x68) = 0;
  *(undefined4 *)(puVar3 + -0x70) = *(undefined4 *)(puVar3 + 0xc);
  ffree(in_ST0);
  Var4 = FUN_005fc330(puVar3 + -0x68,9,0x784ff00,&DAT_00769cac,puVar3 + -0x70,&DAT_0079ef68);
  *(undefined4 *)(puVar3 + -0x68) = 0;
  *(undefined4 **)(puVar3 + -0x70) = &DAT_01e9ad20;
  ffree(Var4);
  fVar5 = (float10)FUN_005fc330(puVar3 + -0x68,9,0x784ff00,&DAT_00769cac,puVar3 + -0x70,
                                &DAT_0079ef88);
  *(int *)(puVar3 + -0x38) = DAT_01e99980;
  DAT_009a4084 = 1;
  iVar2 = DAT_01e99980;
  while (0 < iVar2) {
    DAT_009a4080 = (&ITEM_PTR0)[*(int *)(*(int *)(puVar3 + 0x10) + -4 + DAT_009a4084 * 4)];
    if ((float)(&ITEM_P1)[DAT_009a4080] == f_1) {
      fVar1 = (float)(&ITEM_P5)[DAT_009a4080];
      *(undefined2 *)(puVar3 + -0x70) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x6e) = (ushort)*(undefined4 *)(puVar3 + -0x70) | 0xc00;
      *(int *)(puVar3 + -0x6c) = (int)ROUND(fVar1 / f_10);
      DAT_009a407c = *(int *)(puVar3 + -0x6c);
      fVar1 = (float)(&ITEM_P4)[DAT_009a4080];
      *(undefined2 *)(puVar3 + -0x70) = *(undefined2 *)(puVar3 + -0x70);
      *(ushort *)(puVar3 + -0x6e) = (ushort)*(undefined4 *)(puVar3 + -0x70) | 0xc00;
      *(int *)(puVar3 + -0x6c) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x70);
      DAT_009a4078 = *(int *)(puVar3 + -0x6c);
      iVar2 = DAT_009a4078;
      if (DAT_009a4078 < 0) {
        iVar2 = -DAT_009a4078;
      }
      DAT_020b8e28 = DAT_009a4078;
      if (99 < iVar2) {
        DAT_020b8e28 = DAT_009a4078 % 100;
      }
      _DAT_009a4074 = f_7;
      if (f_8 <= (float)(&ITEM_LEN)[DAT_009a4080]) {
        ffree(fVar5);
        fVar5 = (float10)amod(&ITEM_P8 + DAT_009a4080 * 4,&f_100);
        _DAT_009a4074 = (float)(fVar5 + (float10)f_7);
        fVar5 = extraout_ST1;
      }
      if (DAT_009a407c == 0) {
        _DAT_009a4074 = f_0;
      }
      if (DAT_009a407c == 2) {
        fVar5 = (float10)_DAT_009a4074;
        _DAT_009a4074 = (float)-fVar5;
      }
      iVar2 = DAT_009a4078;
      if (DAT_009a4078 < 0) {
        iVar2 = -DAT_009a4078;
      }
      if (99 < iVar2) {
        _DAT_009a4074 = _DAT_009a4074 * f_0_6;
      }
      _DAT_009a4074 = (float)DAT_020b8e28 + _DAT_009a4074;
      *(undefined4 *)(puVar3 + -0x68) = 0;
      *(undefined4 *)(puVar3 + -0x70) = 4;
      *(int *)(puVar3 + -0x6c) = DAT_009a4084 * 4 + *(int *)(puVar3 + 0x10) + -4;
      ffree(fVar5);
      Var4 = FUN_005fc330(puVar3 + -0x68,9,0x784ff00,&DAT_00769c98,puVar3 + -0x70,&DAT_0079efc8);
      *(undefined4 *)(puVar3 + -0x70) = 4;
      *(undefined4 **)(puVar3 + -0x6c) = &DAT_01e9dc94 + DAT_009a4084;
      ffree(Var4);
      Var4 = FUN_005fc980(puVar3 + -0x68,&DAT_00769c94,puVar3 + -0x70);
      *(int **)(puVar3 + -0x70) = &DAT_020b8e28;
      ffree(Var4);
      Var4 = FUN_005fc980(puVar3 + -0x68,&DAT_00769c90,puVar3 + -0x70);
      *(int **)(puVar3 + -0x70) = &DAT_009a407c;
      ffree(Var4);
      Var4 = FUN_005fc980(puVar3 + -0x68,&DAT_00769c90,puVar3 + -0x70);
      *(undefined **)(puVar3 + -0x70) = &DAT_009a4074;
      ffree(Var4);
      fVar5 = (float10)FUN_005fc980(puVar3 + -0x68,&DAT_00769c8c,puVar3 + -0x70);
    }
    else {
      *(undefined4 *)(puVar3 + -0x34) = 0;
    }
    *(undefined4 *)(puVar3 + -0x2c) = 0;
    DAT_009a4084 = DAT_009a4084 + 1;
    *(int *)(puVar3 + -0x38) = *(int *)(puVar3 + -0x38) + -1;
    iVar2 = *(int *)(puVar3 + -0x38);
  }
  *(undefined4 *)(puVar3 + -0x68) = 0;
  ffree(fVar5);
  Var4 = FUN_005fc330(puVar3 + -0x68,9,0x784ff00,&DAT_00769c88,0,&DAT_0079f018);
  _DAT_009a4070 = 0;
  *(int *)(puVar3 + -0x24) = ITEM_I;
  LOAD_I = 1;
  iVar2 = ITEM_I;
  while (0 < iVar2) {
    ffree(Var4);
    Var4 = load_item_header();
    if (LOAD_STAFF == **(int **)(puVar3 + 0xc)) {
      if (LOAD_CODE == 3) {
        _DAT_009a4070 = 0;
        if (4 < LOAD_LEN) {
          fVar1 = (float)(&ITEM_P5)[LOAD_W];
          *(undefined2 *)(puVar3 + -0x70) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x6e) = (ushort)*(undefined4 *)(puVar3 + -0x70) | 0xc00;
          *(int *)(puVar3 + -0x6c) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x70);
          _DAT_009a4070 = *(undefined4 *)(puVar3 + -0x6c);
        }
        *(undefined4 *)(puVar3 + -0x1c) = 0;
      }
      else if (LOAD_CODE == 5) {
        if ((LOAD_P3 < DAT_01e67910) || (DAT_01e67914 < LOAD_P3)) {
          *(undefined4 *)(puVar3 + -0x14) = 0;
        }
        else {
          DAT_009a406c = LOAD_W;
          _DAT_009a4068 = *(float *)(&ITEM_P8 + LOAD_W * 4);
          if (((_DAT_009a4068 == f_4) || (_DAT_009a4068 == f_2)) ||
             ((7 < LOAD_LEN && (_DAT_009a4068 == f_1)))) {
            *(undefined4 *)(puVar3 + -0x10) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x68) = 0;
            *(int **)(puVar3 + -0x70) = &LOAD_I;
            ffree(Var4);
            Var4 = FUN_005fc330(puVar3 + -0x68,9,0x784ff00,&DAT_00769c90,puVar3 + -0x70,
                                &DAT_0079f050);
            *(undefined4 *)(puVar3 + -0x70) = 4;
            *(undefined4 **)(puVar3 + -0x6c) = &ITEM_P3 + DAT_009a406c;
            ffree(Var4);
            Var4 = FUN_005fc980(puVar3 + -0x68,&DAT_00769c94,puVar3 + -0x70);
            *(undefined4 *)(puVar3 + -0x70) = 4;
            *(undefined4 **)(puVar3 + -0x6c) = &ITEM_P4 + DAT_009a406c;
            ffree(Var4);
            Var4 = FUN_005fc980(puVar3 + -0x68,&DAT_00769c94,puVar3 + -0x70);
            *(undefined4 *)(puVar3 + -0x70) = 4;
            *(undefined4 **)(puVar3 + -0x6c) = &ITEM_P5 + DAT_009a406c;
            ffree(Var4);
            Var4 = FUN_005fc980(puVar3 + -0x68,&DAT_00769c94,puVar3 + -0x70);
            *(undefined4 *)(puVar3 + -0x70) = 4;
            *(undefined4 **)(puVar3 + -0x6c) = &ITEM_P6 + DAT_009a406c;
            ffree(Var4);
            Var4 = FUN_005fc980(puVar3 + -0x68,&DAT_00769c94,puVar3 + -0x70);
            *(undefined4 *)(puVar3 + -0x70) = 4;
            *(undefined **)(puVar3 + -0x6c) = &ITEM_P7 + DAT_009a406c * 4;
            ffree(Var4);
            Var4 = FUN_005fc980(puVar3 + -0x68,&DAT_00769c94,puVar3 + -0x70);
            *(undefined **)(puVar3 + -0x70) = &DAT_009a4070;
            ffree(Var4);
            Var4 = FUN_005fc980(puVar3 + -0x68,&DAT_00769cac,puVar3 + -0x70);
          }
        }
      }
      else {
        *(undefined4 *)(puVar3 + -0x18) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x20) = 0;
    }
    *(undefined4 *)(puVar3 + -8) = 0;
    LOAD_I = LOAD_I + 1;
    *(int *)(puVar3 + -0x24) = *(int *)(puVar3 + -0x24) + -1;
    iVar2 = *(int *)(puVar3 + -0x24);
  }
  *(undefined4 *)(puVar3 + -0x68) = 0;
  ffree(Var4);
  Var4 = FUN_005f7950(puVar3 + -0x68,9,0x784ff00,&DAT_00769c7c,0);
  if (**(int **)(puVar3 + 8) == 2) {
    ffree(Var4);
    Var4 = FUN_0055cb57();
  }
  ffree(Var4);
  return;
}


