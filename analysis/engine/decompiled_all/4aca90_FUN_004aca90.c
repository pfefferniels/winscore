// FUN_004aca90 @ 004aca90 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004aca90(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_EDX;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar3 = &stack0xfffffffc;
  iVar2 = 1;
  while (iVar2 < 0x1b) {
    FUN_005f34d1(puVar3,0x4acac3);
    iVar2 = extraout_EDX + 1;
  }
  thunk_FUN_00498826(&DAT_0078b420,0x40,&DAT_00764150,&DAT_00763c94,&DAT_00763d50);
  *(undefined4 *)(puVar3 + -0x28) = 0x1a;
  DAT_0088d92c = 1;
  do {
    *(undefined4 *)(puVar3 + -0x48) = 0;
    *(undefined4 *)(puVar3 + -0x50) = 0x40;
    *(int **)(puVar3 + -0x4c) = &DAT_0088d930;
    uVar1 = FUN_005fdbd0(puVar3 + -0x48,8,0x784ff01,&DAT_00763d88,puVar3 + -0x50,&DAT_00791f54);
    *(undefined4 *)(puVar3 + -0x24) = uVar1;
    if (*(int *)(puVar3 + -0x24) != 0) break;
    thunk_FUN_0054c83c(&DAT_0088d930,1,&DAT_0076414c);
    if (DAT_0088d930 == 0x424d5953) {
      *(undefined4 *)(puVar3 + -0x20) = 0;
      FUN_005f33c9(puVar3,0x4acbb6);
      FUN_005f34d1(puVar3,0x4acbd1);
      if (DAT_0078b460 == 0x19) {
        FUN_005f33c9(puVar3,0x4acbfc);
        FUN_005f34d1(puVar3,0x4acc17);
      }
      if (DAT_0078b460 == 0x1f) {
        FUN_005f33c9(puVar3,0x4acc42);
        FUN_005f34d1(puVar3,0x4acc5d);
      }
      *(undefined4 *)(puVar3 + -0x14) = 0;
    }
    else if (DAT_0088d930 == 0x544e4f46) {
      *(undefined4 *)(puVar3 + -0x1c) = 0;
      FUN_005f33c9(puVar3,0x4acca7);
      FUN_005f34d1(puVar3,0x4accc2);
      if (DAT_0078b460 == 0x19) {
        FUN_005f33c9(puVar3,0x4acced);
        FUN_005f34d1(puVar3,0x4acd08);
      }
      if (DAT_0078b460 == 0x1f) {
        FUN_005f33c9(puVar3,0x4acd33);
        FUN_005f34d1(puVar3,0x4acd4e);
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x18) = 0;
    }
    puVar4 = &DAT_0088d930;
    puVar5 = &DAT_0088d930 + DAT_0088d92c * 0x10;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    DAT_0088d92c = DAT_0088d92c + 1;
    *(int *)(puVar3 + -0x28) = *(int *)(puVar3 + -0x28) + -1;
  } while (0 < *(int *)(puVar3 + -0x28));
  *(undefined4 *)(puVar3 + -0x48) = 0;
  FUN_005f7950(puVar3 + -0x48,8,0x784ff00,&DAT_00763c88,0);
  iVar2 = FUN_005f4660(0x20);
  if (iVar2 != 0) {
    DAT_0088d92c = DAT_0088d92c + -1;
  }
  thunk_FUN_00498826(&DAT_0078b420,0x40,&DAT_00764150,&DAT_00763c94,&DAT_00763d50);
  *(int *)(puVar3 + -0xc) = DAT_0088d92c;
  DAT_0088d928 = 1;
  iVar2 = DAT_0088d92c;
  while (0 < iVar2) {
    *(undefined4 *)(puVar3 + -0x48) = 0;
    *(undefined4 *)(puVar3 + -0x58) = 0x40;
    *(int **)(puVar3 + -0x54) = &DAT_0088d930 + DAT_0088d928 * 0x10;
    *(undefined4 *)(puVar3 + -0x50) = 0x40;
    FUN_005fc330(puVar3 + -0x48,8,0x784ff00,&DAT_00763c8c,puVar3 + -0x58,&DAT_00791f68);
    DAT_0088d928 = DAT_0088d928 + 1;
    *(int *)(puVar3 + -0xc) = *(int *)(puVar3 + -0xc) + -1;
    iVar2 = *(int *)(puVar3 + -0xc);
  }
  *(undefined4 *)(puVar3 + -0x48) = 0;
  FUN_005f7950(puVar3 + -0x48,8,0x784ff00,&DAT_00763c88,0);
  return;
}


