// FUN_004a4ae3 @ 004a4ae3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004a4bd8) */
/* WARNING: Removing unreachable block (ram,0x004a528f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a4ae3(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  float *pfVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  float *pfVar9;
  bool bVar10;
  bool bVar11;
  
  puVar3 = &stack0xfffffffc;
  DAT_00838edc = 3;
  if ((DAT_020b8ea0._1_1_ == 'M') && (DAT_020b8ea2 == 'R' || DAT_020b8ea2 == 'L')) {
    DAT_00838edc = 4;
  }
  if ((DAT_009ae2bc & 0xffffff) == 0x527e7e) {
    puVar3 = &stack0xfffffffc;
    FUN_005f34d1(&stack0xfffffffc,0x4a4b83);
    DAT_0078b4e4 = 0x20;
    DAT_00838edc = 1;
    DAT_00838ee0 = 0;
    *(undefined4 *)(puVar3 + -0x34) = 0x80;
    DAT_00838ed8 = 1;
    do {
      FUN_005f46bc(puVar3,0x4a4bfc);
      FUN_005f34d1(puVar3,0x4a4c12);
      if ((&DAT_020b909f)[DAT_00838ed8] == '.') {
        DAT_00838ee0 = DAT_00838ed8;
      }
      DAT_00838ed8 = DAT_00838ed8 + 1;
      *(int *)(puVar3 + -0x34) = *(int *)(puVar3 + -0x34) + -1;
    } while (0 < *(int *)(puVar3 + -0x34));
    bVar10 = false;
    bVar11 = DAT_00838ee0 == 0;
    if (!bVar11) {
      iVar2 = 1;
      pbVar4 = &DAT_020b90a3 + DAT_00838ee0;
      pbVar7 = &DAT_00763964;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar10 = *pbVar4 < *pbVar7;
        bVar11 = *pbVar4 == *pbVar7;
        pbVar4 = pbVar4 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar11);
      if (bVar10 || bVar11) {
        (&DAT_020b90a3)[DAT_00838ee0] = 0;
      }
    }
  }
  else if ((DAT_009ae2bc & 0xffffff) == 0x577e7e) {
    puVar3 = &stack0xfffffffc;
    FUN_005f34d1(&stack0xfffffffc,0x4a4cc3);
    DAT_0078b4e4 = 0x20;
    DAT_00838edc = 1;
    DAT_00838ee0 = 0;
    puVar5 = (undefined4 *)&DAT_007a0b7c;
    puVar8 = (undefined4 *)&DAT_020b90a0;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  do {
    FUN_005f34d1(puVar3,0x4a4d12);
    DAT_00838ee0 = 3;
    if ((DAT_0078b4e4 != 0) && (DAT_0078b4e4 != 0x20)) {
      DAT_00838ee0 = 4;
    }
    FUN_005f34d1(puVar3,0x4a4d5b);
    P1 = 0.0;
    DAT_00838ed8 = 0x81;
    if ((_DAT_020b90a0 & 0xff) == 0x4d) {
      DAT_00838ed8 = 0x82;
    }
    (&DAT_020b909f)[DAT_00838ed8] = 0x20;
    if ((undefined *)(_DAT_020b90a0 & 0xffffff) == &DAT_004d5352) {
      _DAT_020b90a0 = CONCAT12(DAT_00763a0e,DAT_00763a0c);
    }
    thunk_FUN_0054cd71(&DAT_020b90a0,0x200,&DAT_00763960,&DAT_00838ed8);
    iVar2 = (DAT_00838ed8 - DAT_00838edc) + 1;
    *(int *)(puVar3 + -0x30) = iVar2;
    DAT_00838ee0 = DAT_00838edc;
    while (0 < iVar2) {
      if ((&DAT_020b909f)[DAT_00838ee0] != ' ') {
        DAT_00838ed4 = (DAT_00838ed8 - DAT_00838ee0) + 1;
        iVar2 = (DAT_00838ed8 - (DAT_00838ee0 + -1)) + 1;
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        *(int *)(puVar3 + -0x58) = iVar2;
        FUN_005f46bc(puVar3,0x4a4ec1);
        FUN_005f34d1(puVar3,0x4a4ed7);
        if (_DAT_020b90a0 != 0x5453414c) {
          *(undefined4 *)(puVar3 + -0x28) = 0;
          *(undefined4 *)(puVar3 + -8) = 0;
          thunk_FUN_00497193(&P2,0x80,&DAT_0078b690,4);
          if (DAT_0078b690 == 0x20202020) {
            thunk_FUN_00497193(&DAT_0078b510,0x80,&DAT_0078b690,4);
            if ((DAT_0078b690._1_1_ == '\0') || (DAT_0078b690 >> 8 == 0x202020)) {
              FUN_005f46bc(puVar3,0x4a5217);
              FUN_005f46bc(puVar3,0x4a5233);
              FUN_005f34d1(puVar3,0x4a5249);
              DAT_00838ecc = thunk_FUN_00595cd0(&DAT_020b8ea0);
              if (DAT_00838ecc == -1) {
                DAT_0078b690 = 0x53554d2e;
              }
            }
            FUN_005f46bc(puVar3,0x4a52b3);
            FUN_005f34d1(puVar3,0x4a52c9);
          }
          else {
            *(undefined4 *)(puVar3 + -4) = 0;
          }
          pfVar6 = &P2;
          pfVar9 = *(float **)(puVar3 + 8);
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *pfVar9 = *pfVar6;
            pfVar6 = pfVar6 + 1;
            pfVar9 = pfVar9 + 1;
          }
          FUN_004a5309(*(undefined4 *)(puVar3 + 8),0x80);
          return;
        }
        goto LAB_004a5067;
      }
      *(undefined4 *)(puVar3 + -0x2c) = 0;
      *(undefined4 *)(puVar3 + -0x20) = 0;
      DAT_00838ee0 = DAT_00838ee0 + 1;
      *(int *)(puVar3 + -0x30) = *(int *)(puVar3 + -0x30) + -1;
      iVar2 = *(int *)(puVar3 + -0x30);
    }
    DAT_007a0b7c = 0;
    if (DAT_020b8ea0 == 0x4153) {
      puVar5 = &DAT_0078b510;
      puVar8 = (undefined4 *)&DAT_007a0b7c;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar8 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    if ((char)DAT_020b8ea0 == 'G') {
      FUN_005f46bc(puVar3,0x4a4f68);
      FUN_005f46bc(puVar3,0x4a4f84);
      FUN_005f46bc(puVar3,0x4a4fa0);
      FUN_005f34d1(puVar3,0x4a4fb6);
      *(undefined4 *)(puVar3 + -0x54) = 0;
      *(undefined4 *)(puVar3 + -0x70) = 0x80;
      *(undefined **)(puVar3 + -0x6c) = &DAT_00838ee4;
      *(undefined4 *)(puVar3 + -0x68) = 3;
      *(undefined **)(puVar3 + -100) = &DAT_007639f8;
      *(undefined4 *)(puVar3 + -0x60) = 2;
      uVar1 = FUN_005f6540(puVar3 + -0x54,7,0x784ff01,&DAT_007639e8,puVar3 + -0x70);
      *(undefined4 *)(puVar3 + -0x1c) = uVar1;
      if (*(int *)(puVar3 + -0x1c) == 0) {
        *(undefined4 *)(puVar3 + -0x54) = 0;
        *(undefined4 *)(puVar3 + -0x60) = 0x80;
        *(undefined1 **)(puVar3 + -0x5c) = &DAT_007a0b7c;
        uVar1 = FUN_005fdbd0(puVar3 + -0x54,7,0x784ff01,&DAT_007639e4,puVar3 + -0x60,&DAT_00791850);
        *(undefined4 *)(puVar3 + -0x18) = uVar1;
        if (*(int *)(puVar3 + -0x18) == 0) {
          *(undefined4 *)(puVar3 + -0x54) = 0;
          FUN_005f7950(puVar3 + -0x54,7,0x784ff00,&DAT_007639e0,0);
          goto LAB_004a50a4;
        }
      }
LAB_004a5067:
      DAT_007a0b7c = 0;
      *(undefined4 *)(puVar3 + -0x24) = 0;
    }
LAB_004a50a4:
    DAT_00838ed0 = thunk_FUN_0059caa0(DAT_00838ee0);
    if (DAT_00838ed0 == 2) {
      DAT_0078b4e4 = 0;
      draw_items();
      *(undefined4 *)(puVar3 + -0x10) = 0;
      return;
    }
    if (DAT_020b8ea0 == 0x4153) {
      _DAT_020b90a0 = CONCAT12(DAT_007639de,DAT_007639dc);
      FUN_005f33c9(puVar3,0x4a5110);
    }
    else {
      _DAT_020b90a0 = CONCAT22(_DAT_020b90a2,DAT_007639a8);
      FUN_005f33c9(puVar3,0x4a5146);
    }
    *(undefined4 *)(puVar3 + -0xc) = 0;
  } while( true );
}


