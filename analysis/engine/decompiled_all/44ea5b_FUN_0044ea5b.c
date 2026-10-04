// FUN_0044ea5b @ 0044ea5b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044ea5b(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x44ea82);
  FUN_005f34d1(puVar4,0x44ea9d);
  if (DAT_01fbb8a0 == 0x3eb) {
    ram0x020b90a6 = i_2002874948;
  }
  *(undefined4 *)(puVar4 + -0x34) = 0;
  *(undefined4 *)(puVar4 + -0x48) = 4;
  *(undefined **)(puVar4 + -0x44) = &DAT_020b90b0;
  *(undefined **)(puVar4 + -0x40) = &DAT_01c25e58;
  FUN_005f34f0(puVar4 + -0x34,0x784ff00,&DAT_00760eec,puVar4 + -0x48,&DAT_0078fa08);
  DAT_020b90bb = 0xd;
  DAT_020b90bc = 10;
  puVar2 = &DAT_00760f28;
  puVar3 = (undefined4 *)&DAT_020b90bd;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(puVar4 + -0x34) = 0;
  *(undefined4 *)(puVar4 + -0x48) = 4;
  *(undefined4 *)(puVar4 + -0x44) = 0x20b90bf;
  *(undefined4 *)(puVar4 + -0x40) = *(undefined4 *)(puVar4 + 8);
  FUN_005f34f0(puVar4 + -0x34,0x784ff00,&DAT_00760eec,puVar4 + -0x48,&DAT_0078fa1c);
  iVar1 = **(int **)(puVar4 + 0xc);
  *(undefined4 *)(puVar4 + -0x34) = 0;
  *(undefined4 *)(puVar4 + -0x48) = 6;
  *(undefined **)(puVar4 + -0x44) = &DAT_020b90c9;
  *(int *)(puVar4 + -0x40) = (iVar1 + -8000) / 100;
  FUN_005f34f0(puVar4 + -0x34,0x784ff00,&DAT_00760f20,puVar4 + -0x48,&DAT_0078fa30);
  iVar1 = **(int **)(puVar4 + 0x10);
  *(undefined4 *)(puVar4 + -0x34) = 0;
  *(undefined4 *)(puVar4 + -0x48) = 6;
  *(undefined4 **)(puVar4 + -0x44) = &DAT_020b90d4;
  *(int *)(puVar4 + -0x40) = (iVar1 + 32000) / 100;
  FUN_005f34f0(puVar4 + -0x34,0x784ff00,&DAT_00760f20,puVar4 + -0x48,&DAT_0078fa44);
  *(undefined4 *)(puVar4 + -0x34) = 0;
  *(undefined4 *)(puVar4 + -0x48) = 5;
  *(undefined **)(puVar4 + -0x44) = &DAT_020b90dc;
  *(undefined4 *)(puVar4 + -0x40) = *(undefined4 *)(puVar4 + 0x14);
  FUN_005f34f0(puVar4 + -0x34,0x784ff00,&DAT_00760f18,puVar4 + -0x48,&DAT_0078fa58);
  puVar2 = (undefined4 *)&DAT_020b90a0;
  puVar3 = &DAT_009ae2bc;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  thunk_FUN_0054946a(&DAT_020b90a0,0x200);
  return;
}


