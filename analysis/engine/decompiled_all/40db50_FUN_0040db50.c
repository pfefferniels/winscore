// FUN_0040db50 @ 0040db50 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0040dc97) */
/* WARNING: Removing unreachable block (ram,0x0040dd19) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040db50(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined2 in_FPUControlWord;
  float10 fVar10;
  
  puVar6 = &stack0xfffffffc;
  if (DAT_007abb0c != 0) {
    return;
  }
  DAT_0078b4f0 = 1;
  FUN_005f33c9(&stack0xfffffffc,0x40db9d);
  FUN_005f34d1(puVar6,0x40dbb8);
  *(undefined4 *)(puVar6 + -0x11c) = 0;
  *(undefined4 *)(puVar6 + -0x130) = 4;
  *(undefined4 *)(puVar6 + -300) = 0x7a0b81;
  *(int **)(puVar6 + -0x128) = &ITEM_I;
  FUN_005f34f0(puVar6 + -0x11c,0x784ff00,&DAT_0075f1c0,puVar6 + -0x130,&DAT_0078af78);
  *(undefined4 *)(puVar6 + -0x11c) = 0;
  *(undefined4 *)(puVar6 + -0x130) = 4;
  *(undefined **)(puVar6 + -300) = &DAT_007a0b8d;
  *(int **)(puVar6 + -0x128) = &IP5;
  FUN_005f34f0(puVar6 + -0x11c,0x784ff00,&DAT_0075f1c0,puVar6 + -0x130,&DAT_0078af8c);
  *(undefined4 *)(puVar6 + -0xf0) = 0x18;
  DAT_007abb08 = 0x18;
  do {
    iVar2 = FUN_005f4660(0x20);
    if (iVar2 == 0) {
      FUN_005f46bc(puVar6,0x40dd3b);
      FUN_005f34d1(puVar6,0x40dd51);
      *(undefined4 *)(puVar6 + -0xe8) = 0;
      break;
    }
    *(undefined4 *)(puVar6 + -0xec) = 0;
    *(undefined4 *)(puVar6 + -0xe4) = 0;
    DAT_007abb08 = DAT_007abb08 + -1;
    *(int *)(puVar6 + -0xf0) = *(int *)(puVar6 + -0xf0) + -1;
  } while (0 < *(int *)(puVar6 + -0xf0));
  do {
    FUN_005f33c9(puVar6,0x40dd7d);
    FUN_005f34d1(puVar6,0x40dd98);
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    *(undefined4 *)(puVar6 + -0x130) = 4;
    *(undefined4 *)(puVar6 + -300) = 0x9ae2c1;
    *(int **)(puVar6 + -0x128) = &ITEM_I;
    FUN_005f34f0(puVar6 + -0x11c,0x784ff00,&DAT_0075f1c0,puVar6 + -0x130,&DAT_0078afa0);
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    *(undefined4 *)(puVar6 + -0x130) = 3;
    *(undefined4 *)(puVar6 + -300) = 0x9ae2cb;
    *(int **)(puVar6 + -0x128) = &IP5;
    FUN_005f34f0(puVar6 + -0x11c,0x784ff00,&DAT_0075f1c0,puVar6 + -0x130,&DAT_0078afb4);
    DAT_009ae2d1 = P14;
    _DAT_009ae2d5 = P15;
    DAT_009ae2d8._1_2_ = P16._0_2_;
    while( true ) {
      DAT_007abb04 = thunk_FUN_0059b810(&DAT_007bbe38);
      DAT_007abb0c = DAT_007bbe40;
      if ((DAT_007bbe40 != 0) || (DAT_007abb04 == 3)) {
        *(undefined4 *)(puVar6 + -0xd8) = 0;
        return;
      }
      if (DAT_007abb04 == 2) {
        DAT_007abb00 = (&ITEM_PTR0)[ITEM_I];
        (&ITEM_P1)[DAT_007abb00] = f_19;
        *(undefined4 *)(puVar6 + -0xd0) = 0;
        return;
      }
      *(undefined4 *)(puVar6 + -0xd4) = 0;
      DAT_007abb00 = DAT_007bbe38;
      if ((DAT_007bbe38 < 0x2706) && (4999 < DAT_007bbe38)) break;
      *(undefined4 *)(puVar6 + -0xcc) = 0;
    }
    _DAT_007abafc = *(float *)(&ITEM_P14 + (&ITEM_PTR0)[ITEM_I] * 4);
    _DAT_007abaf8 = *(float *)(&ITEM_P15 + (&ITEM_PTR0)[ITEM_I] * 4);
    _DAT_007abaf4 = (float)(&ITEM_P5)[(&ITEM_PTR0)[ITEM_I]];
    _DAT_007abaf0 = DAT_007bbe38;
    puVar7 = &DAT_0075f180;
    puVar9 = &DAT_007abb64;
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    *(undefined4 *)(puVar6 + -0x130) = 4;
    *(undefined4 *)(puVar6 + -300) = 0x7abb66;
    *(int **)(puVar6 + -0x128) = &DAT_007abb00;
    FUN_005f34f0(puVar6 + -0x11c,0x784ff00,&DAT_0075f1c0,puVar6 + -0x130,&DAT_0078afc8);
    DAT_007abb68._0_2_ = CONCAT11(0x30,(undefined1)DAT_007abb68);
    DAT_007abbbc = DAT_007abb64;
    DAT_007abbc0 = DAT_007abb68;
    DAT_007abbc4 = DAT_007abb6c;
    FUN_005f46bc(puVar6,0x40e010);
    FUN_005f46bc(puVar6,0x40e02c);
    FUN_005f46bc(puVar6,0x40e048);
    FUN_005f46bc(puVar6,0x40e064);
    FUN_005f34d1(puVar6,0x40e07a);
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    *(undefined4 *)(puVar6 + -0x130) = 0x80;
    *(undefined **)(puVar6 + -300) = &DAT_0078b3a0;
    *(char **)(puVar6 + -0x128) = &DAT_007abae0;
    FUN_005f47c0(puVar6 + -0x11c,0xffffffff,0x784ff00,&DAT_0075f164,puVar6 + -0x130);
    if (DAT_007abae0 == '\0') {
      *(undefined4 *)(puVar6 + -0xc0) = 0;
      goto LAB_0040e490;
    }
    FUN_005f33c9(puVar6,0x40e103);
    FUN_005f34d1(puVar6,0x40e11e);
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    *(undefined4 *)(puVar6 + -0x130) = 4;
    *(undefined **)(puVar6 + -300) = &DAT_007abb74;
    *(int **)(puVar6 + -0x128) = &DAT_007abb00;
    FUN_005f34f0(puVar6 + -0x11c,0x784ff00,&DAT_0075f1c0,puVar6 + -0x130,&DAT_0078afdc);
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    *(undefined4 *)(puVar6 + -0x130) = 4;
    *(undefined4 **)(puVar6 + -300) = &DAT_009ae2c4;
    *(int **)(puVar6 + -0x128) = &DAT_007abb00;
    FUN_005f34f0(puVar6 + -0x11c,0x784ff00,&DAT_0075f1c0,puVar6 + -0x130,&DAT_0078aff0);
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    *(undefined4 *)(puVar6 + -0x130) = 4;
    *(undefined4 *)(puVar6 + -300) = 0x9ae2ce;
    *(int **)(puVar6 + -0x128) = &DAT_007abb00;
    FUN_005f34f0(puVar6 + -0x11c,0x784ff00,&DAT_0075f1c0,puVar6 + -0x130,&DAT_0078b004);
    DAT_009ae2d1 = (float)CONCAT31(DAT_009ae2d1._1_3_,0x30);
    DAT_007bbe38 = 1;
    DAT_007bbe3c = 0;
    DAT_007abb04 = thunk_FUN_0059b8b0(&DAT_007bbe38);
    if (DAT_007abb04 != -1) break;
    *(undefined4 *)(puVar6 + -0xb0) = 0;
    DAT_007abb04 = -1;
  } while( true );
  if (DAT_007bbe3c == 1) {
    *(undefined4 *)(puVar6 + -0xac) = 0;
LAB_0040ee02:
    *(int *)(puVar6 + -0x1c) = ITEM_COUNT_SAVE;
    DAT_007abb08 = 1;
    iVar2 = ITEM_COUNT_SAVE;
    while (0 < iVar2) {
      DAT_007abb04 = (&ITEM_PTR0)[DAT_007abb08];
      if ((float)(&ITEM_P1)[DAT_007abb04] == f_11) {
        if (_DAT_007abaf4 == (float)(&ITEM_P5)[DAT_007abb04]) {
          if ((_DAT_007abafc == *(float *)(&ITEM_P14 + DAT_007abb04 * 4)) &&
             (_DAT_007abaf8 == *(float *)(&ITEM_P15 + DAT_007abb04 * 4))) {
            (&ITEM_P1)[DAT_007abb04] = f_9;
            iVar8 = DAT_007abb04 + 0xe;
            fVar1 = (float)(&ITEM_LEN)[DAT_007abb04];
            *(undefined2 *)(puVar6 + -0x124) = in_FPUControlWord;
            *(ushort *)(puVar6 + -0x122) = (ushort)*(undefined4 *)(puVar6 + -0x124) | 0xc00;
            *(int *)(puVar6 + -0x120) = (int)ROUND((float)DAT_007abb04 + fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar6 + -0x124);
            iVar2 = (*(int *)(puVar6 + -0x120) - iVar8) + 1;
            if (iVar2 < 0) {
              iVar2 = 0;
            }
            for (iVar4 = 1; iVar4 <= iVar2; iVar4 = iVar4 + 1) {
              (&ITEM_LEN)[iVar8] = f_0;
              iVar8 = iVar8 + 1;
            }
            (&ITEM_P5)[DAT_007abb04] = (float)_DAT_007abaf0;
          }
          else {
            *(undefined4 *)(puVar6 + -0x10) = 0;
          }
        }
        else {
          *(undefined4 *)(puVar6 + -0x14) = 0;
        }
      }
      else {
        *(undefined4 *)(puVar6 + -0x18) = 0;
      }
      *(undefined4 *)(puVar6 + -0xc) = 0;
      DAT_007abb08 = DAT_007abb08 + 1;
      *(int *)(puVar6 + -0x1c) = *(int *)(puVar6 + -0x1c) + -1;
      iVar2 = *(int *)(puVar6 + -0x1c);
    }
    *(undefined4 *)(puVar6 + -8) = 0;
  }
  else {
    FUN_005f46bc(puVar6,0x40e2cf);
    FUN_005f46bc(puVar6,0x40e2eb);
    FUN_005f46bc(puVar6,0x40e307);
    FUN_005f34d1(puVar6,0x40e31d);
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    *(undefined4 *)(puVar6 + -0x140) = 0x80;
    *(undefined4 **)(puVar6 + -0x13c) = &DAT_007abbc8;
    *(undefined4 *)(puVar6 + -0x138) = 3;
    *(undefined **)(puVar6 + -0x134) = &DAT_0075f130;
    *(undefined4 *)(puVar6 + -0x130) = 6;
    *(char **)(puVar6 + -300) = "binary";
    *(undefined4 *)(puVar6 + -0x128) = 2;
    uVar3 = FUN_005f6540(puVar6 + -0x11c,9,0x784ff01,&DAT_0075f114,puVar6 + -0x140);
    *(undefined4 *)(puVar6 + -0xa8) = uVar3;
    if (*(int *)(puVar6 + -0xa8) == 0) {
      *(undefined4 *)(puVar6 + -0x11c) = 0;
      *(undefined4 *)(puVar6 + -0x128) = 6;
      *(char **)(puVar6 + -0x124) = "DELETE";
      FUN_005f7950(puVar6 + -0x11c,9,0x784ff00,&DAT_0075f104,puVar6 + -0x128);
    }
    fVar10 = (float10)FUN_005f7e50(&DAT_0078b3a0,0x80,&DAT_007abbc8,0x80);
    *(undefined2 *)(puVar6 + -0x124) = in_FPUControlWord;
    *(ushort *)(puVar6 + -0x122) = (ushort)*(undefined4 *)(puVar6 + -0x124) | 0xc00;
    *(int *)(puVar6 + -0x120) = (int)ROUND(fVar10);
    in_FPUControlWord = *(undefined2 *)(puVar6 + -0x124);
    _DAT_007abaec = *(int *)(puVar6 + -0x120);
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    FUN_005f7950(puVar6 + -0x11c,9,0x784ff00,&DAT_0075f100,0);
    *(undefined4 *)(puVar6 + -0x9c) = 0;
LAB_0040e490:
    FUN_005f46bc(puVar6,0x40e4c1);
    FUN_005f46bc(puVar6,0x40e4dd);
    FUN_005f46bc(puVar6,0x40e4f9);
    FUN_005f46bc(puVar6,0x40e515);
    FUN_005f34d1(puVar6,0x40e52b);
    *(undefined4 *)(puVar6 + -0x11c) = 0;
    *(undefined4 *)(puVar6 + -0x140) = 0x80;
    *(undefined **)(puVar6 + -0x13c) = &DAT_0078b3a0;
    *(undefined4 *)(puVar6 + -0x138) = 3;
    *(undefined **)(puVar6 + -0x134) = &DAT_0075f130;
    *(undefined4 *)(puVar6 + -0x130) = 6;
    *(char **)(puVar6 + -300) = "binary";
    *(undefined4 *)(puVar6 + -0x128) = 2;
    uVar3 = FUN_005f6540(puVar6 + -0x11c,5,0x784ff01,&DAT_0075f114,puVar6 + -0x140);
    *(undefined4 *)(puVar6 + -0x60) = uVar3;
    if (*(int *)(puVar6 + -0x60) == 0) {
      *(undefined4 *)(puVar6 + -0x11c) = 0;
      *(undefined **)(puVar6 + -0x128) = &DAT_007abb10;
      FUN_005f8240(puVar6 + -0x11c,5,0x784ff00,&DAT_0075f0fc,puVar6 + -0x128);
      *(undefined4 *)(puVar6 + -0x128) = 0x16;
      *(undefined **)(puVar6 + -0x124) = &DAT_007abb18;
      FUN_005f8730(puVar6 + -0x11c,&DAT_0075f0f8,puVar6 + -0x128);
      *(undefined4 *)(puVar6 + -0x130) = 0x32;
      *(undefined **)(puVar6 + -300) = &DAT_007abb30;
      *(undefined4 *)(puVar6 + -0x128) = 5;
      FUN_005f8730(puVar6 + -0x11c,&DAT_0075f0f4,puVar6 + -0x130);
      _DAT_007abaec = DAT_007abb2c + -1;
      *(undefined4 *)(puVar6 + -0x58) = 20000;
      DAT_007abb08 = 1;
      do {
        uVar5 = DAT_007abb08 + 0x40U & 0x3f;
        if ((uVar5 != 0) && ((int)(DAT_007abb08 + 0x40U) < 0)) {
          uVar5 = uVar5 - 0x40;
        }
        if (uVar5 == 1) {
          *(undefined4 *)(puVar6 + -0x11c) = 0;
          *(undefined **)(puVar6 + -0x128) = &DAT_007abb10;
          uVar3 = FUN_005f8240(puVar6 + -0x11c,5,0x784ff02,&DAT_0075f0f0,puVar6 + -0x128);
          *(undefined4 *)(puVar6 + -0x54) = uVar3;
          if (*(int *)(puVar6 + -0x54) == -1) break;
        }
        *(undefined4 *)(puVar6 + -0x11c) = 0;
        *(undefined4 *)(puVar6 + -0x128) = 2;
        *(int *)(puVar6 + -0x124) = DAT_007abb08 * 2 + 0x7b5806;
        uVar3 = FUN_005f8240(puVar6 + -0x11c,5,0x784ff02,&DAT_0075f0ec,puVar6 + -0x128);
        *(undefined4 *)(puVar6 + -0x50) = uVar3;
        if (*(int *)(puVar6 + -0x50) == -1) break;
        DAT_007abb08 = DAT_007abb08 + 1;
        *(int *)(puVar6 + -0x58) = *(int *)(puVar6 + -0x58) + -1;
      } while (0 < *(int *)(puVar6 + -0x58));
      *(undefined4 *)(puVar6 + -0x11c) = 0;
      FUN_005f7950(puVar6 + -0x11c,5,0x784ff00,&DAT_0075f100,0);
      *(undefined4 *)(puVar6 + -0x11c) = 0;
      *(undefined4 *)(puVar6 + -0x130) = 4;
      *(undefined4 *)(puVar6 + -300) = 0x7abbbe;
      *(int **)(puVar6 + -0x128) = &DAT_007abb00;
      FUN_005f9240(puVar6 + -0x11c,0x784ff00,&DAT_0075f1c0,puVar6 + -0x130,&DAT_0078b018);
      *(undefined4 *)(puVar6 + -0x44) = 10;
      DAT_007abae8 = 2;
      do {
        *(short *)(DAT_007abae8 * 2 + 0x7abba2) = *(short *)(DAT_007abae8 * 2 + 0x7abb16) / 3 + 1;
        DAT_007abae8 = DAT_007abae8 + 1;
        *(int *)(puVar6 + -0x44) = *(int *)(puVar6 + -0x44) + -1;
      } while (0 < *(int *)(puVar6 + -0x44));
      _DAT_007abba4 = 0;
      *(undefined4 *)(puVar6 + -0x40) = 10;
      DAT_007abae8 = 1;
      do {
        *(int *)(DAT_007abae8 * 4 + 0x7abb78) = DAT_007abae8 + DAT_007abb00 + -1;
        FUN_005f33c9(puVar6,0x40e8d6);
        FUN_005f34d1(puVar6,0x40e8f1);
        DAT_007abae8 = DAT_007abae8 + 1;
        *(int *)(puVar6 + -0x40) = *(int *)(puVar6 + -0x40) + -1;
      } while (0 < *(int *)(puVar6 + -0x40));
      DAT_007abb04 = 0;
      iVar2 = (DAT_007abb2c + 1) / 3;
      *(int *)(puVar6 + -0x3c) = iVar2;
      DAT_007abae8 = 1;
      while (0 < iVar2) {
        DAT_007abb04 = DAT_007abb04 + 1;
        *(int *)(puVar6 + -0x120) = (int)*(short *)(DAT_007abae8 * 2 + 0x7b5806);
        *(float *)(&DAT_007abbc4 + DAT_007abb04 * 2) = (float)*(int *)(puVar6 + -0x120);
        *(int *)(puVar6 + -0x120) = (int)(short)(&DAT_007b5808)[DAT_007abae8];
        *(float *)(DAT_007abb04 * 4 + 0x7bbeb4) = (float)*(int *)(puVar6 + -0x120);
        *(undefined2 *)(DAT_007abb04 * 2 + 0x7c5af6) = (&DAT_007b580a)[DAT_007abae8];
        DAT_007abae8 = DAT_007abae8 + 3;
        *(int *)(puVar6 + -0x3c) = *(int *)(puVar6 + -0x3c) + -1;
        iVar2 = *(int *)(puVar6 + -0x3c);
      }
      FUN_005f46bc(puVar6,0x40ea1a);
      FUN_005f46bc(puVar6,0x40ea36);
      FUN_005f46bc(puVar6,0x40ea52);
      FUN_005f46bc(puVar6,0x40ea6e);
      FUN_005f34d1(puVar6,0x40ea84);
      *(undefined4 *)(puVar6 + -0x11c) = 0;
      *(undefined4 *)(puVar6 + -0x140) = 0x80;
      *(undefined **)(puVar6 + -0x13c) = &DAT_0078b3a0;
      *(undefined4 *)(puVar6 + -0x138) = 7;
      *(char **)(puVar6 + -0x134) = "unknown";
      *(undefined4 *)(puVar6 + -0x130) = 6;
      *(char **)(puVar6 + -300) = "binary";
      *(undefined4 *)(puVar6 + -0x128) = 2;
      uVar3 = FUN_005f6540(puVar6 + -0x11c,8,0x784ff01,&DAT_0075f114,puVar6 + -0x140);
      *(undefined4 *)(puVar6 + -0x38) = uVar3;
      if (*(int *)(puVar6 + -0x38) == 0) {
        *(undefined4 *)(puVar6 + -0x11c) = 0;
        *(undefined4 *)(puVar6 + -0x128) = 0x16;
        *(undefined **)(puVar6 + -0x124) = &DAT_007abba4;
        uVar3 = FUN_005fa4d0(puVar6 + -0x11c,8,0x784ff01,&DAT_0075f0ec,puVar6 + -0x128);
        *(undefined4 *)(puVar6 + -0x34) = uVar3;
        if (*(int *)(puVar6 + -0x34) == 0) {
          *(undefined4 *)(puVar6 + -0x11c) = 0;
          *(undefined4 *)(puVar6 + -0x130) = 0xf0;
          *(undefined **)(puVar6 + -300) = &DAT_007ca918;
          *(undefined4 *)(puVar6 + -0x128) = 0x18;
          uVar3 = FUN_005fa4d0(puVar6 + -0x11c,8,0x784ff01,&DAT_0075f0f4,puVar6 + -0x130);
          *(undefined4 *)(puVar6 + -0x30) = uVar3;
          if (*(int *)(puVar6 + -0x30) == 0) {
            DAT_007abb08 = DAT_007abbb8 + -1;
            iVar2 = DAT_007abb08;
            if (DAT_007abb08 < 0) {
              iVar2 = 0;
            }
            DAT_007abb04 = iVar2 + 1;
            *(undefined4 *)(puVar6 + -0x11c) = 0;
            *(undefined4 *)(puVar6 + -0x138) = 1;
            *(undefined4 **)(puVar6 + -0x134) = &DAT_007abbc8;
            *(undefined4 *)(puVar6 + -0x130) = 1;
            *(int *)(puVar6 + -300) = iVar2;
            *(undefined4 *)(puVar6 + -0x128) = 4;
            uVar3 = FUN_005fa4d0(puVar6 + -0x11c,8,0x784ff01,&DAT_0075f0e0,puVar6 + -0x138);
            *(undefined4 *)(puVar6 + -0x2c) = uVar3;
            if (*(int *)(puVar6 + -0x2c) == 0) {
              iVar2 = DAT_007abb08;
              if (DAT_007abb08 < 0) {
                iVar2 = 0;
              }
              DAT_007abb04 = iVar2 + 1;
              *(undefined4 *)(puVar6 + -0x11c) = 0;
              *(undefined4 *)(puVar6 + -0x138) = 1;
              *(undefined4 **)(puVar6 + -0x134) = &DAT_007bbeb8;
              *(undefined4 *)(puVar6 + -0x130) = 1;
              *(int *)(puVar6 + -300) = iVar2;
              *(undefined4 *)(puVar6 + -0x128) = 4;
              uVar3 = FUN_005fa4d0(puVar6 + -0x11c,8,0x784ff01,&DAT_0075f0e0,puVar6 + -0x138);
              *(undefined4 *)(puVar6 + -0x28) = uVar3;
              if (*(int *)(puVar6 + -0x28) == 0) {
                iVar2 = DAT_007abb08;
                if (DAT_007abb08 < 0) {
                  iVar2 = 0;
                }
                DAT_007abb04 = iVar2 + 1;
                *(undefined4 *)(puVar6 + -0x11c) = 0;
                *(undefined4 *)(puVar6 + -0x138) = 1;
                *(undefined2 **)(puVar6 + -0x134) = &DAT_007c5af8;
                *(undefined4 *)(puVar6 + -0x130) = 1;
                *(int *)(puVar6 + -300) = iVar2;
                *(undefined4 *)(puVar6 + -0x128) = 2;
                uVar3 = FUN_005fa4d0(puVar6 + -0x11c,8,0x784ff01,&DAT_0075f0dc,puVar6 + -0x138);
                *(undefined4 *)(puVar6 + -0x24) = uVar3;
                if (*(int *)(puVar6 + -0x24) == 0) {
                  *(undefined4 *)(puVar6 + -0x11c) = 0;
                  FUN_005f7950(puVar6 + -0x11c,8,0x784ff00,&DAT_0075f100,0);
                  goto LAB_0040ee02;
                }
              }
            }
          }
        }
      }
    }
    thunk_FUN_0054d831(&DAT_0075f0b4,0x1a);
  }
  *(undefined4 *)(puVar6 + -4) = 0;
  return;
}


