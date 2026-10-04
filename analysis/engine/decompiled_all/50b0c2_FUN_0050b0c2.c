// FUN_0050b0c2 @ 0050b0c2 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050b0c2(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  float *pfVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined4 *puVar7;
  
  puVar3 = &stack0xfffffffc;
  while (DAT_02052740 < 0) {
    *(undefined4 *)(puVar3 + -0x30) = 0;
    while( true ) {
      thunk_FUN_0042ac4e(&DAT_01cb0e60,0x30);
      puVar5 = &DAT_01c59580;
      puVar7 = (undefined4 *)&DAT_007a0b7c;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      thunk_FUN_0054cd71(&DAT_007a0b7c,0x80,&DAT_007670a4,&DAT_00940bac);
      *(undefined4 *)(puVar3 + -4) = 0;
LAB_0050b4fa:
      FUN_005f33c9(puVar3,0x50b518);
      FUN_005f34d1(puVar3,0x50b533);
      if (IP1 == 0xb) {
        DAT_009ae2c0._1_2_ = DAT_007670b8;
        DAT_009ae2c0._3_1_ = DAT_007670ba;
      }
      DAT_00940bb4 = thunk_FUN_0059c9d0();
      if (DAT_00940bb4 == 2) goto LAB_0050b59d;
      *(undefined4 *)(puVar3 + -0x20) = 0;
      pfVar4 = (float *)&DAT_007a0b7c;
      pfVar6 = &P14;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar6 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar6 = pfVar6 + 1;
      }
LAB_0050b22f:
      iVar2 = FUN_005f4660(0x20);
      if (iVar2 != 0) break;
      _DAT_00940bb0 = 0x80;
      thunk_FUN_0054c83c(&P14,0x80,&DAT_00940bb0);
      thunk_FUN_0054cd71(&P14,0x80,&DAT_007670a4,&DAT_00940bac);
      thunk_FUN_00571b78(&P14,0x80,&DAT_00940bb8,3);
      pfVar4 = &P14;
      pfVar6 = (float *)&DAT_01cb0e60;
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar6 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar6 = pfVar6 + 1;
      }
      pfVar4 = &P14;
      pfVar6 = (float *)&DAT_020b9474;
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar6 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar6 = pfVar6 + 1;
      }
      P13 = f_0;
      IP13 = 0;
      DAT_020b9470 = f_0;
      *(undefined4 *)(puVar3 + -0x50) = 0;
      *(undefined4 *)(puVar3 + -0x60) = 0x30;
      *(char **)(puVar3 + -0x5c) = &DAT_01cb0e60;
      *(uint **)(puVar3 + -0x58) = &DAT_00940bbc;
      FUN_005f47c0(puVar3 + -0x50,0xffffffff,0x784ff00,&DAT_0076706c,puVar3 + -0x60);
      if ((DAT_00940bbc & 1) != 0) {
        *(undefined4 *)(puVar3 + -0x10) = 0;
        return;
      }
      if (DAT_01cb0e60 != '\\') {
        FUN_005f33c9(puVar3,0x50b399);
        FUN_005f33c9(puVar3,0x50b3b5);
        FUN_005f33c9(puVar3,0x50b3d7);
        FUN_005f33c9(puVar3,0x50b3f9);
        FUN_005f34d1(puVar3,0x50b414);
        FUN_005f33c9(puVar3,0x50b436);
        FUN_005f34d1(puVar3,0x50b451);
        *(undefined4 *)(puVar3 + -0x50) = 0;
        *(undefined4 *)(puVar3 + -0x60) = 0x30;
        *(char **)(puVar3 + -0x5c) = &DAT_01cb0e60;
        *(uint **)(puVar3 + -0x58) = &DAT_00940bbc;
        FUN_005f47c0(puVar3 + -0x50,0xffffffff,0x784ff00,&DAT_0076706c,puVar3 + -0x60);
        if ((DAT_00940bbc & 1) != 0) {
          *(undefined4 *)(puVar3 + -8) = 0;
          return;
        }
      }
    }
    *(undefined4 *)(puVar3 + -0x18) = 0;
  }
  DAT_00940bb8 = DAT_007670bc;
  DAT_00940bba = DAT_007670be;
  if (IP1 == 0xb) {
    DAT_00940bb8 = DAT_007670b8;
    DAT_00940bba = DAT_007670ba;
  }
  pfVar4 = &P14;
  pfVar6 = (float *)&DAT_007a0b7c;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar6 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar6 = pfVar6 + 1;
  }
  iVar2 = FUN_005f4660(0x20);
  if (iVar2 != 0) {
    FUN_005f33c9(puVar3,0x50b174);
    FUN_005f34d1(puVar3,0x50b18f);
  }
  if (DAT_02052740 == 0) {
    *(undefined4 *)(puVar3 + -0x2c) = 0;
    goto LAB_0050b4fa;
  }
  *(undefined4 *)(puVar3 + -0x50) = 0;
  *(undefined4 *)(puVar3 + -0x58) = 0x80;
  *(float **)(puVar3 + -0x54) = &P14;
  uVar1 = FUN_005fdbd0(puVar3 + -0x50,DAT_02052740,0x784ff01,&DAT_007670ac,puVar3 + -0x58,
                       &DAT_007957b8);
  *(undefined4 *)(puVar3 + -0x28) = uVar1;
  if (*(int *)(puVar3 + -0x28) == 0) {
    P13 = f_0;
    IP11 = -9999;
    DAT_020b9468 = f_m9999;
    P11 = f_m9999;
    *(undefined4 *)(puVar3 + -0x24) = 0;
    goto LAB_0050b22f;
  }
LAB_0050b59d:
  *(undefined4 *)(puVar3 + -0x1c) = 0;
  DAT_020b9470 = f_0;
  P13 = f_0;
  IP13 = 99;
  return;
}


