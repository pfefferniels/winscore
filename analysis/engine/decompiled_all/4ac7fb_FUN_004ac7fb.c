// FUN_004ac7fb @ 004ac7fb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004ac7fb(undefined4 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 unaff_ESI;
  undefined4 *puVar3;
  undefined4 unaff_EDI;
  undefined4 *puVar4;
  
  puVar2 = &stack0xfffffffc;
  puVar3 = &DAT_0088d8a8;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_0088d8a0 = 1;
LAB_004ac81f:
  *(undefined4 *)(puVar2 + -0x40) = 0;
  *(undefined4 *)(puVar2 + -0x50) = 0x80;
  *(undefined4 **)(puVar2 + -0x4c) = &DAT_0088d8a8;
  *(uint **)(puVar2 + -0x48) = &DAT_0088d8a4;
  FUN_005f47c0(puVar2 + -0x40,0xffffffff,0x784ff00,&DAT_00763bf8,puVar2 + -0x50);
  if ((DAT_0088d8a4 & 1) != 0) {
    *(undefined4 *)(puVar2 + -0x1c) = 0;
LAB_004aca77:
    puVar3 = &DAT_0088d8a8;
    puVar4 = *(undefined4 **)(puVar2 + 8);
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    return;
  }
  DAT_0088d8a8._0_1_ = 'B';
  do {
    DAT_0088d8a8._0_1_ = (char)DAT_0088d8a8 + '\x01';
    if ('Y' < (char)DAT_0088d8a8) {
      if (DAT_0088d8a0 == 1) {
        FUN_005f33c9(puVar2,0x4aca0f);
        FUN_005f34d1(puVar2,0x4aca2a);
        DAT_0078b4c0 = 0xb;
        DAT_0088d8a0 = 2;
        *(undefined4 *)(puVar2 + -0xc) = 0;
        goto LAB_004ac81f;
      }
      if (DAT_0088d8a0 == 2) {
        FUN_005f33c9(puVar2,0x4ac9b0);
        FUN_005f34d1(puVar2,0x4ac9cb);
        DAT_0078b4c0 = 0x19;
        DAT_0088d8a0 = 3;
        *(undefined4 *)(puVar2 + -8) = 0;
        goto LAB_004ac81f;
      }
      if (DAT_0088d8a0 == 3) break;
      if (DAT_0088d8a0 == 4) {
        thunk_FUN_0042ac4e(unaff_EDI,unaff_ESI);
        puVar3 = *(undefined4 **)(puVar2 + 8);
        puVar4 = &DAT_0088d8a8;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        goto LAB_004aca77;
      }
    }
    *(undefined4 *)(puVar2 + -0x40) = 0;
    *(undefined4 *)(puVar2 + -0x50) = 0x80;
    *(undefined4 **)(puVar2 + -0x4c) = &DAT_0088d8a8;
    *(uint **)(puVar2 + -0x48) = &DAT_0088d8a4;
    FUN_005f47c0(puVar2 + -0x40,0xffffffff,0x784ff00,&DAT_00763bf8,puVar2 + -0x50);
    if ((DAT_0088d8a4 & 1) != 0) {
      *(undefined4 *)(puVar2 + -0x14) = 0;
      goto LAB_004aca77;
    }
    *(undefined4 *)(puVar2 + -0x10) = 0;
  } while( true );
  FUN_005f33c9(puVar2,0x4ac951);
  FUN_005f34d1(puVar2,0x4ac96c);
  DAT_0078b4c0 = 0x1f;
  DAT_0088d8a0 = 4;
  *(undefined4 *)(puVar2 + -4) = 0;
  goto LAB_004ac81f;
}


