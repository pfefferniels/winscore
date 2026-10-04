// FUN_0045e1ee @ 0045e1ee (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045e1ee(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined2 in_FPUControlWord;
  undefined2 uVar7;
  float10 fVar8;
  undefined4 local_54;
  char *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44 [16];
  
  puVar4 = &stack0xfffffffc;
  local_44[0] = 0;
  local_54 = 8;
  local_50 = "vsub.f90";
  local_4c = 2;
  local_48 = 4;
  FUN_005f6540(local_44,5,0x784ff00,&DAT_007616d4,&local_54);
  local_44[0] = 0;
  local_54 = 4;
  local_50 = "date8\x04\r";
  local_4c = 2;
  local_48 = 4;
  FUN_005f6540(local_44,6,0x784ff00,&DAT_007616d4,&local_54);
  DAT_0082432c = 0;
  while( true ) {
    *(undefined4 *)(puVar4 + -0x40) = 0;
    *(undefined4 *)(puVar4 + -0x50) = 0x200;
    *(undefined2 **)(puVar4 + -0x4c) = &DAT_020b8ea0;
    *(undefined4 *)(puVar4 + -0x48) = 1;
    uVar1 = FUN_005fdbd0(puVar4 + -0x40,5,0x784ff01,&DAT_007616cc,puVar4 + -0x50,&DAT_0079099c);
    *(undefined4 *)(puVar4 + -0x18) = uVar1;
    if (*(int *)(puVar4 + -0x18) != 0) break;
    DAT_0082432c = DAT_0082432c + 1;
    thunk_FUN_0054c8e5(&DAT_020b8ea0,1,&DAT_00824328);
    *(undefined1 *)((int)&DAT_020b8ea0 + DAT_00824328) = 0;
    FUN_005f46bc(puVar4,0x45e35e);
    FUN_005f34d1(puVar4,0x45e374);
    if ((char)DAT_020b8ea0 == '\'') {
      FUN_006012d0(&DAT_020b90a1,9);
    }
    else {
      *(undefined4 *)(puVar4 + -0x14) = 0;
    }
    iVar2 = DAT_00824328;
    if (DAT_00824328 < 0) {
      iVar2 = 0;
    }
    puVar5 = puVar4 + -0x70;
    for (uVar3 = iVar2 + 7U & 0xfffffff8; 0x1000 < (int)uVar3; uVar3 = uVar3 - 0x1000) {
      puVar5 = puVar5 + -0x1000;
    }
    iVar6 = (int)puVar5 - uVar3;
    *(int *)(puVar4 + -0x44) = iVar6;
    *(undefined4 *)(puVar4 + -0x48) = 1;
    *(undefined4 *)(puVar4 + -0x4c) = 1;
    while (*(int *)(puVar4 + -0x4c) <= iVar2) {
      *(undefined1 *)(*(int *)(puVar4 + -0x4c) + *(int *)(puVar4 + -0x44) + -1) =
           (&DAT_020b909f)[*(int *)(puVar4 + -0x48)];
      *(int *)(puVar4 + -0x48) = *(int *)(puVar4 + -0x48) + 1;
      *(int *)(puVar4 + -0x4c) = *(int *)(puVar4 + -0x4c) + 1;
    }
    *(undefined4 *)(puVar4 + -0x40) = 0;
    *(int *)(puVar4 + -0x60) = iVar2;
    *(undefined4 *)(puVar4 + -0x5c) = *(undefined4 *)(puVar4 + -0x44);
    *(undefined4 *)(puVar4 + -0x58) = 1;
    *(undefined **)(iVar6 + -4) = &DAT_007909b0;
    *(undefined1 **)(iVar6 + -8) = puVar4 + -0x60;
    *(undefined **)(iVar6 + -0xc) = &DAT_007616cc;
    *(undefined4 *)(iVar6 + -0x10) = 0x784ff00;
    *(undefined4 *)(iVar6 + -0x14) = 6;
    *(undefined1 **)(iVar6 + -0x18) = puVar4 + -0x40;
    *(undefined4 *)(iVar6 + -0x1c) = 0x45e463;
    FUN_005fc330();
    *(undefined4 *)(puVar4 + -0xc) = 0;
  }
  *(undefined4 *)(puVar4 + -0x40) = 0;
  FUN_005f7950(puVar4 + -0x40,5,0x784ff00,&DAT_007616c8,0);
  *(undefined4 *)(puVar4 + -0x40) = 0;
  FUN_005f7950(puVar4 + -0x40,6,0x784ff00,&DAT_007616c8,0);
  fVar8 = (float10)FUN_005f7ed0(&DAT_007616bc,0xc);
  *(undefined2 *)(puVar4 + -0x48) = in_FPUControlWord;
  *(ushort *)(puVar4 + -0x46) = (ushort)*(undefined4 *)(puVar4 + -0x48) | 0xc00;
  *(int *)(puVar4 + -0x44) = (int)ROUND(fVar8);
  uVar7 = *(undefined2 *)(puVar4 + -0x48);
  _DAT_00824324 = *(undefined4 *)(puVar4 + -0x44);
  fVar8 = (float10)FUN_005f7e50(&DAT_007616d0,4,&DAT_007616b0,0xc);
  *(undefined2 *)(puVar4 + -0x48) = uVar7;
  *(ushort *)(puVar4 + -0x46) = (ushort)*(undefined4 *)(puVar4 + -0x48) | 0xc00;
  *(int *)(puVar4 + -0x44) = (int)ROUND(fVar8);
  _DAT_00824324 = *(undefined4 *)(puVar4 + -0x44);
  FUN_006012d0(&DAT_009ae2bc,0x200);
  FUN_005f33c9(puVar4,0x45e56e);
  return;
}


