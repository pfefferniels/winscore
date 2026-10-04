// FUN_004a7440 @ 004a7440 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004a74c6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a7440(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  bool bVar9;
  undefined1 *puVar10;
  
  puVar10 = &stack0xfffffffc;
  NPT = 1;
  DAT_0078b460 = 0xb;
  DAT_020b8ea0._0_1_ = DAT_0078b420._3_1_;
  if ((DAT_0078b420._3_1_ == 'P') || (DAT_0078b420._3_1_ == 'p')) {
    DAT_0078b460 = 0x19;
  }
  if (DAT_0078b431 == '(') {
    DAT_0078b460 = 0x1f;
  }
  FUN_005f46bc(&stack0xfffffffc,0x4a74ea);
  FUN_005f46bc(puVar10,0x4a7506);
  FUN_005f46bc(puVar10,0x4a7522);
  FUN_005f34d1(puVar10,0x4a7538);
  *(undefined4 *)(puVar10 + -0x58) = 0;
  *(undefined4 *)(puVar10 + -0x78) = 0;
  *(undefined4 *)(puVar10 + -0x88) = 0x80;
  *(undefined **)(puVar10 + -0x84) = &DAT_0078b3a0;
  *(uint **)(puVar10 + -0x80) = &DAT_0088cb28;
  FUN_005f47c0(puVar10 + -0x78,0xffffffff,0x784ff00,&DAT_00763bf8,puVar10 + -0x88);
  if ((DAT_0088cb28 & 1) == 0) {
    thunk_FUN_0042ac4e(&DAT_0078b3a0,0x80);
                    /* WARNING: Subroutine does not return */
    FUN_006013a0(&DAT_00763b78,0,0x784ff00,0,0);
  }
  *(undefined4 *)(puVar10 + -0x50) = 0;
  FUN_005f46bc(puVar10,0x4a75df);
  FUN_005f46bc(puVar10,0x4a75fb);
  FUN_005f46bc(puVar10,0x4a7617);
  FUN_005f34d1(puVar10,0x4a762d);
  FUN_005f46bc(puVar10,0x4a7662);
  FUN_005f46bc(puVar10,0x4a767e);
  FUN_005f46bc(puVar10,0x4a769a);
  FUN_005f34d1(puVar10,0x4a76b0);
  DAT_01c5b1e0 = 0;
  DAT_0078ed80 = 0;
  FUN_005f34d1(puVar10,0x4a76e1);
  DAT_00790c10 = 0;
  DAT_01cf8f00 = DAT_00763d0c;
  FUN_005f46bc(puVar10,0x4a7730);
  FUN_005f46bc(puVar10,0x4a774c);
  FUN_005f46bc(puVar10,0x4a7768);
  FUN_005f34d1(puVar10,0x4a777e);
  DAT_0088cb18 = 8;
  *(undefined4 *)(puVar10 + -0x78) = 0;
  FUN_005f7950(puVar10 + -0x78,DAT_0088cb18,0x784ff00,&DAT_00763c88,0);
  *(undefined4 *)(puVar10 + -0x78) = 0;
  *(undefined4 *)(puVar10 + -0x88) = 0x80;
  *(char **)(puVar10 + -0x84) = s_METRINCHBEAMBMTHRESTDASHMIDKPROC_007921c0;
  *(undefined4 *)(puVar10 + -0x80) = 2;
  *(undefined4 *)(puVar10 + -0x7c) = 4;
  uVar3 = FUN_005f6540(puVar10 + -0x78,DAT_0088cb18,0x784ff01,&DAT_00763ce8,puVar10 + -0x88);
  *(undefined4 *)(puVar10 + -0x48) = uVar3;
  if (*(int *)(puVar10 + -0x48) == 0) {
    if (DAT_0088cb18 < 0) {
      *(undefined4 *)(puVar10 + -0x44) = 0;
    }
    else {
      DAT_02052740 = 8;
      FUN_004a830b();
      puVar5 = &DAT_00790b90;
      puVar7 = &DAT_019c68ac;
      for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      do {
        while( true ) {
          if (5000000 < DAT_0078dc84) {
            *(undefined4 *)(puVar10 + -0x40) = 0;
            goto LAB_004a7976;
          }
          thunk_FUN_00571f5d("Type last 4 digits of Serial Number on disk.",0x2d);
          iVar4 = FUN_005f4660(0x20);
          bVar9 = false;
          if (iVar4 == 0) break;
          *(undefined4 *)(puVar10 + -0x3c) = 0;
        }
        iVar4 = 1;
        pbVar6 = (byte *)((int)&DAT_009ae2bc + 3);
        pbVar8 = &DAT_00763cb4;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar2 = *pbVar8;
          bVar1 = *pbVar6;
          bVar9 = bVar1 < bVar2;
          pbVar6 = pbVar6 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar1 == bVar2);
        if (bVar9) {
          DAT_009ae2bc._3_1_ = 0x20;
        }
        iVar4 = 1;
        pbVar6 = (byte *)((int)&DAT_009ae2bc + 2);
        pbVar8 = &DAT_00763cb4;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar2 = *pbVar8;
          bVar1 = *pbVar6;
          bVar9 = bVar1 < bVar2;
          pbVar6 = pbVar6 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar1 == bVar2);
        if (bVar9) {
          DAT_009ae2bc._2_1_ = 0x20;
        }
        iVar4 = 1;
        pbVar6 = (byte *)((int)&DAT_009ae2bc + 1);
        pbVar8 = &DAT_00763cb4;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar2 = *pbVar8;
          bVar1 = *pbVar6;
          bVar9 = bVar1 < bVar2;
          pbVar6 = pbVar6 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar1 == bVar2);
        if (bVar9) {
          DAT_009ae2bc._1_1_ = 0x20;
        }
        *(undefined4 *)(puVar10 + -0x78) = 0;
        *(undefined4 *)(puVar10 + -0x88) = 4;
        *(undefined4 **)(puVar10 + -0x84) = &DAT_009ae2bc;
        *(int **)(puVar10 + -0x80) = &DAT_0078dc84;
        uVar3 = FUN_005f9240(puVar10 + -0x78,0x784ff01,&DAT_00763cac,puVar10 + -0x88,&DAT_00791a00);
        *(undefined4 *)(puVar10 + -0x38) = uVar3;
      } while (*(int *)(puVar10 + -0x38) != 0);
      FUN_004abc64();
LAB_004a7976:
      DAT_02052740 = DAT_02052748;
      _DAT_020b8e40 = 0;
    }
  }
  *(undefined4 *)(puVar10 + -0x78) = 0;
  FUN_005f7950(puVar10 + -0x78,8,0x784ff00,&DAT_00763c88,0);
  DAT_0088cb18 = 8;
  thunk_FUN_00498826(&DAT_0078b3a0,0x80,&DAT_0088cb18,&DAT_00763c94,&DAT_00763c94);
  if (DAT_0088cb18 < 1) {
    *(undefined4 *)(puVar10 + -0x78) = 0;
    FUN_005f7950(puVar10 + -0x78,8,0x784ff00,&DAT_00763c88,0);
    thunk_FUN_0042ac4e(&DAT_0078b3a0,0x80);
    *(undefined4 *)(puVar10 + -0x28) = 0;
  }
  else {
    *(undefined4 *)(puVar10 + -0x30) = 0;
    do {
      do {
        iVar4 = FUN_005f4660(0x20);
        if (((iVar4 != 0) || (iVar4 = FUN_005f4660(0x20), iVar4 != 0)) ||
           (iVar4 = FUN_005f4660(0x20), iVar4 != 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_006013a0(&DAT_00763b78,0,0x784ff00,0,0);
        }
        *(undefined4 *)(puVar10 + -0x78) = 0;
        *(undefined **)(puVar10 + -0x80) = &DAT_0088cb14;
        iVar4 = FUN_005f8240(puVar10 + -0x78,DAT_0088cb18,0x784ff01,&DAT_00763ca0,puVar10 + -0x80);
        *(int *)(puVar10 + -0x24) = iVar4;
        if (iVar4 == 0) {
          *(undefined **)(puVar10 + -0x80) = &DAT_0088cb10;
          iVar4 = FUN_005f8730(puVar10 + -0x78,&DAT_00763ca0,puVar10 + -0x80);
          *(int *)(puVar10 + -0x24) = iVar4;
          if (iVar4 == 0) {
            *(undefined4 *)(puVar10 + -0x80) = 0xb48;
            *(undefined4 **)(puVar10 + -0x7c) = &DAT_01c58a20;
            uVar3 = FUN_005f8730(puVar10 + -0x78,&DAT_00763c9c,puVar10 + -0x80);
            *(undefined4 *)(puVar10 + -0x24) = uVar3;
          }
        }
      } while (*(int *)(puVar10 + -0x24) != 0);
      *(undefined4 *)(puVar10 + -0x78) = 0;
      *(undefined4 *)(puVar10 + -0x80) = 0x1a4;
      *(undefined4 **)(puVar10 + -0x7c) = &DAT_01c6da60;
      iVar4 = FUN_005f8240(puVar10 + -0x78,DAT_0088cb18,0x784ff01,&DAT_00763c98,puVar10 + -0x80);
      *(int *)(puVar10 + -0x20) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(puVar10 + -0x80) = 0x5c6;
        *(undefined **)(puVar10 + -0x7c) = &DAT_01adfb40;
        uVar3 = FUN_005f8730(puVar10 + -0x78,&DAT_00763c90,puVar10 + -0x80);
        *(undefined4 *)(puVar10 + -0x20) = uVar3;
      }
    } while (*(int *)(puVar10 + -0x20) != 0);
    *(undefined4 *)(puVar10 + -0x78) = 0;
    FUN_005f7950(puVar10 + -0x78,DAT_0088cb18,0x784ff00,&DAT_00763c88,0);
    DAT_0078dc88 = 0;
    _DAT_0078b694 = 0;
    _DAT_0205275c = 0;
    DAT_02052748 = 0;
    DAT_02052744 = 5;
    if (CUR_STAFF == 0) {
      while( true ) {
        while( true ) {
          *(undefined4 *)(puVar10 + -0x14) = 0;
          FUN_00602c70(&DAT_0088cb0c,&DAT_0088cb08,&DAT_0088cb04,&DAT_0088cb00);
          if ((DAT_0088cafc != _DAT_0088cb0c) || (DAT_0088caf8 != _DAT_0088cb08)) break;
          if (DAT_0088caf4 + 4 <= DAT_0088cb04) goto LAB_004a7ca3;
          *(undefined4 *)(puVar10 + -0x10) = 0;
        }
        if (DAT_0088caf4 + -0x38 <= DAT_0088cb04) break;
        *(undefined4 *)(puVar10 + -0xc) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar10 + -0x18) = 0;
    }
LAB_004a7ca3:
    DAT_02052740 = DAT_02052748;
    *(undefined4 *)(puVar10 + -0x78) = 0;
    FUN_005f7950(puVar10 + -0x78,8,0x784ff00,&DAT_00763c88,0);
    *(undefined4 *)(puVar10 + -4) = 0;
    FUN_004acee1(&DAT_019c68ac,0x80,&DAT_0078b4c0);
  }
  return;
}


