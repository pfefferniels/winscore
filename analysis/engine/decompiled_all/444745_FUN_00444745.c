// FUN_00444745 @ 00444745 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00444745(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  short *psVar4;
  undefined4 *puVar5;
  short *psVar6;
  undefined4 *puVar7;
  undefined1 uVar8;
  undefined1 *puVar9;
  undefined4 local_74;
  undefined1 *local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_60 [12];
  int local_30;
  int local_2c;
  undefined4 local_28;
  
  puVar3 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  DAT_0078b4f0 = 1;
  if ((0 < ITEM_I) && (iVar1 = thunk_FUN_00579410(&DAT_007608e4), iVar1 == 0)) {
    return;
  }
  ITEM_I = 0;
  ITEM_WORDS = 1;
  DAT_01caf668 = DAT_02052740;
  thunk_FUN_004a7da8();
  DAT_02052740 = DAT_01caf668;
  if (DAT_02052748 == DAT_01caf668) {
    FUN_005f33c9(&stack0xfffffffc,0x4447e7);
    FUN_005f34d1(puVar3,0x444802);
    *(undefined4 *)(puVar3 + -0x38) = 4;
    DAT_01caf66c = 1;
    do {
      *(undefined1 *)(DAT_01caf66c + 0x7a0b7b) =
           *(undefined1 *)((int)&DAT_007f805c + DAT_01caf66c + 3);
      DAT_01caf66c = DAT_01caf66c + 1;
      *(int *)(puVar3 + -0x38) = *(int *)(puVar3 + -0x38) + -1;
    } while (0 < *(int *)(puVar3 + -0x38));
    FUN_005f33c9(puVar3,0x44486f);
    puVar2 = puVar3;
    FUN_005f34d1(puVar3,0x44488a);
    iVar1 = thunk_FUN_0059c2e0();
    if (iVar1 == 2) {
      *(undefined4 *)(puVar2 + -0x34) = 0;
      return;
    }
    puVar5 = &DAT_009ae2bc;
    puVar7 = (undefined4 *)&DAT_020b8ea0;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar5 = &DAT_009ae2bc;
    puVar7 = &DAT_007f8068;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    *(undefined4 *)(puVar2 + -0x30) = 4;
    DAT_01caf66c = 1;
    do {
      *(undefined1 *)((int)&DAT_007f805c + DAT_01caf66c + 3) =
           *(undefined1 *)(DAT_01caf66c + 0x7a0b7b);
      DAT_01caf66c = DAT_01caf66c + 1;
      *(int *)(puVar2 + -0x30) = *(int *)(puVar2 + -0x30) + -1;
    } while (0 < *(int *)(puVar2 + -0x30));
  }
  else {
    local_60[0] = 0;
    local_6c = 0x200;
    local_68 = (undefined4 *)&DAT_020b8ea0;
    local_30 = FUN_005fdbd0(local_60,DAT_01caf668,0x784ff01,&DAT_007608d4,&local_6c,&DAT_0078f808);
    puVar3 = &stack0xfffffffc;
    if (local_30 != 0) goto LAB_004450b4;
    local_60[0] = 0;
    local_74 = 0x80;
    local_70 = &DAT_007a0b7c;
    local_6c = 1;
    local_2c = FUN_005fdbd0(local_60,DAT_02052740,0x784ff01,&DAT_007608d0,&local_74,&DAT_0078f81c);
    puVar3 = &stack0xfffffffc;
    if (local_2c != 0) goto LAB_004450b4;
    local_60[0] = 0;
    local_6c = 0x80;
    local_68 = &DAT_009af4bc;
    local_28 = FUN_005fdbd0(local_60,DAT_02052740,0x784ff01,&DAT_007608d4,&local_6c,&DAT_0078f830);
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f33c9(&stack0xfffffffc,0x444a60);
      puVar2 = puVar9;
      FUN_005f34d1(puVar9,0x444a7b);
    }
  }
  DAT_01caf67c = DAT_007a0b7c - 0x30;
  DAT_007f805c = DAT_007a0b7d - 0x30;
  DAT_007f8058 = DAT_007a0b7e - 0x30;
  if (-1 < DAT_007f805c) {
    DAT_01caf67c = DAT_01caf67c * 10 + DAT_007f805c;
  }
  if (-1 < DAT_007f8058) {
    DAT_01caf67c = DAT_01caf67c * 10 + DAT_007f8058;
  }
  if ((DAT_01caf67c < 2) || ((char)DAT_020b8ea0 == ' ')) {
    *(undefined4 *)(puVar2 + -0x20) = 0;
    puVar3 = puVar2;
  }
  else {
    *(undefined4 *)(puVar2 + -0x1c) = 0x80;
    DAT_01caf668 = 1;
    do {
      if ((&DAT_020b8e9f)[DAT_01caf668] == '\0') {
        (&DAT_020b8e9f)[DAT_01caf668] = 0x20;
      }
      thunk_FUN_0054c768(&DAT_020b8e9f + DAT_01caf668);
      DAT_01caf668 = DAT_01caf668 + 1;
      *(int *)(puVar2 + -0x1c) = *(int *)(puVar2 + -0x1c) + -1;
    } while (0 < *(int *)(puVar2 + -0x1c));
    puVar5 = (undefined4 *)&DAT_020b8ea0;
    puVar7 = &ITEM_P1;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    FUN_005f34d1(puVar2,0x444baf);
    puVar5 = &ITEM_P1;
    puVar7 = &DAT_0078b510;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    thunk_FUN_0054cd71(&DAT_0078b510,0x80,&DAT_007608bc,&DAT_01caf66c);
    thunk_FUN_00571b78(&DAT_0078b510,0x80,0x78b691,3);
    FUN_005f33c9(puVar2,0x444c20);
    _DAT_007f8054 = 1;
    DAT_01caf670 = 0;
    iVar1 = DAT_01caf67c + -1;
    *(int *)(puVar2 + -0x18) = iVar1;
    DAT_01caf66c = 2;
    while (0 < iVar1) {
      thunk_FUN_004f4bb0(&DAT_0078b510,0x80,&DAT_007f8054,&DAT_01caf670);
      FUN_005f33c9(puVar2,0x444c97);
      DAT_01caf66c = DAT_01caf66c + 1;
      *(int *)(puVar2 + -0x18) = *(int *)(puVar2 + -0x18) + -1;
      iVar1 = *(int *)(puVar2 + -0x18);
    }
    DAT_0078b4e0 = 0x43;
    DAT_0078b4e4 = 0x20;
    push_words(&DAT_00760840,&DAT_02052740);
    DAT_02052740 = 5;
    DAT_01caf678 = 1;
    iVar1 = -DAT_01caf67c / -1;
    *(int *)(puVar2 + -0x14) = iVar1;
    _DAT_01caf654 = f_0;
    _DAT_007f8050 = f_0;
    DAT_01caf66c = DAT_01caf67c;
    while (0 < iVar1) {
      DAT_0078b4e4 = 0x4d;
      FUN_005f33c9(puVar2,0x444d69);
      FUN_005f34d1(puVar2,0x444d84);
      FUN_005f33c9(puVar2,0x444dad);
      FUN_005f34d1(puVar2,0x444dc8);
      FUN_005f33c9(puVar2,0x444dea);
      FUN_005f34d1(puVar2,0x444e05);
      FUN_005f33c9(puVar2,0x444e2e);
      FUN_005f34d1(puVar2,0x444e49);
      uVar8 = &stack0x00000000 == (undefined1 *)0x84;
      thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
      DAT_0078dd50 = 0xffffdbe4;
      cmd_get();
      iVar1 = 7;
      psVar4 = &DAT_020b8ea0;
      psVar6 = (short *)"File not found";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        uVar8 = *psVar4 == *psVar6;
        psVar4 = psVar4 + 1;
        psVar6 = psVar6 + 1;
      } while ((bool)uVar8);
      if ((bool)uVar8) {
        pop_words(&DAT_00760840,&DAT_02052740);
        *(undefined4 *)(puVar2 + -0xc) = 0;
        puVar3 = puVar2;
        goto LAB_004450b4;
      }
      *(undefined4 *)(puVar2 + -0x10) = 0;
      thunk_FUN_00448179();
      iVar1 = (ITEM_I - DAT_01caf678) + 1;
      *(int *)(puVar2 + -8) = iVar1;
      DAT_01caf670 = DAT_01caf678;
      while (0 < iVar1) {
        DAT_01caf668 = (&ITEM_PTR0)[DAT_01caf670];
        (&ITEM_P2)[DAT_01caf668] = _DAT_007f8050 + (float)(&ITEM_P2)[DAT_01caf668];
        if (_DAT_01caf654 < (float)(&ITEM_P2)[DAT_01caf668]) {
          _DAT_01caf654 = (float)(&ITEM_P2)[DAT_01caf668];
        }
        DAT_01caf670 = DAT_01caf670 + 1;
        *(int *)(puVar2 + -8) = *(int *)(puVar2 + -8) + -1;
        iVar1 = *(int *)(puVar2 + -8);
      }
      DAT_01caf678 = ITEM_I + 1;
      *(int *)(&DAT_01caf23c + DAT_01caf66c * 4) = ITEM_I;
      DAT_0078b4f0 = 0;
      *(undefined4 *)(puVar2 + -4) = 0;
      DAT_01caf66c = DAT_01caf66c + -1;
      *(int *)(puVar2 + -0x14) = *(int *)(puVar2 + -0x14) + -1;
      iVar1 = *(int *)(puVar2 + -0x14);
    }
    DAT_0078dd50 = 0;
    thunk_FUN_00545752(&DAT_00760890);
    DAT_0078b4e4 = 0x53;
    DAT_02052740 = 0;
    thunk_FUN_004f7808();
    pop_words(&DAT_00760840,&DAT_02052740);
    FUN_005f33c9(puVar2,0x445014);
    FUN_005f33c9(puVar2,0x445030);
    FUN_005f34d1(puVar2,0x44504b);
    puVar5 = (undefined4 *)&DAT_020b8ea0;
    puVar7 = (undefined4 *)&DAT_020b90a0;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    DAT_0078b4e4 = 0;
    thunk_FUN_00496aee();
    DAT_0078b4f0 = 0;
    thunk_FUN_00495d4f(&DAT_0078b510,0x80);
    _DAT_007f804c = f_64;
    redraw(&DAT_00760890);
    thunk_FUN_00549422();
    puVar3 = puVar2;
  }
LAB_004450b4:
  FUN_005f34d1(puVar3,0x4450d1);
  for (iVar1 = 1; iVar1 < 0x81; iVar1 = iVar1 + 1) {
    *(undefined1 *)(iVar1 + 0x7a0b7b) = 0x20;
  }
  FUN_005f34d1(puVar3,0x445117);
  FUN_005f34d1(puVar3,0x445138);
  return;
}


