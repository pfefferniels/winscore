// FUN_004ac54f @ 004ac54f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004ac54f(undefined4 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar2 = &stack0xfffffffc;
  puVar3 = &DAT_0088d820;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_0088d818 = 1;
LAB_004ac573:
  *(undefined4 *)(puVar2 + -0x40) = 0;
  *(undefined4 *)(puVar2 + -0x50) = 0x80;
  *(undefined4 **)(puVar2 + -0x4c) = &DAT_0088d820;
  *(uint **)(puVar2 + -0x48) = &DAT_0088d81c;
  FUN_005f47c0(puVar2 + -0x40,0xffffffff,0x784ff00,&DAT_00763bf8,puVar2 + -0x50);
  if ((DAT_0088d81c & 1) != 0) {
    *(undefined4 *)(puVar2 + -0x1c) = 0;
LAB_004ac7d3:
    FUN_005f33c9(puVar2,0x4ac7ee);
    return;
  }
  DAT_0088d820._0_1_ = 'B';
  do {
    DAT_0088d820._0_1_ = (char)DAT_0088d820 + '\x01';
    if ('Y' < (char)DAT_0088d820) {
      if (DAT_0088d818 == 1) {
        FUN_005f33c9(puVar2,0x4ac763);
        FUN_005f34d1(puVar2,0x4ac77e);
        DAT_0078b4c0 = 0x14;
        DAT_0088d818 = 2;
        *(undefined4 *)(puVar2 + -0xc) = 0;
        goto LAB_004ac573;
      }
      if (DAT_0088d818 == 2) {
        FUN_005f33c9(puVar2,0x4ac704);
        FUN_005f34d1(puVar2,0x4ac71f);
        DAT_0078b4c0 = 0x22;
        DAT_0088d818 = 3;
        *(undefined4 *)(puVar2 + -8) = 0;
        goto LAB_004ac573;
      }
      if (DAT_0088d818 == 3) break;
      if (DAT_0088d818 == 4) {
        thunk_FUN_0042ac4e(*(undefined4 *)(puVar2 + 8),0x80);
        puVar3 = *(undefined4 **)(puVar2 + 8);
        puVar4 = &DAT_0088d820;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        goto LAB_004ac7d3;
      }
    }
    *(undefined4 *)(puVar2 + -0x40) = 0;
    *(undefined4 *)(puVar2 + -0x50) = 0x80;
    *(undefined4 **)(puVar2 + -0x4c) = &DAT_0088d820;
    *(uint **)(puVar2 + -0x48) = &DAT_0088d81c;
    FUN_005f47c0(puVar2 + -0x40,0xffffffff,0x784ff00,&DAT_00763bf8,puVar2 + -0x50);
    if ((DAT_0088d81c & 1) != 0) {
      *(undefined4 *)(puVar2 + -0x14) = 0;
      goto LAB_004ac7d3;
    }
    *(undefined4 *)(puVar2 + -0x10) = 0;
  } while( true );
  FUN_005f33c9(puVar2,0x4ac6a5);
  FUN_005f34d1(puVar2,0x4ac6c0);
  DAT_0078b4c0 = 0x28;
  DAT_0088d818 = 4;
  *(undefined4 *)(puVar2 + -4) = 0;
  goto LAB_004ac573;
}


