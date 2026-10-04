// FUN_004b3e1e @ 004b3e1e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b3e1e(void)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 in_FPUControlWord;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  puVar3 = (undefined4 *)&DAT_020b90a0;
  puVar4 = (undefined4 *)&DAT_020b8ea0;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = (undefined4 *)((int)&DAT_01fb8cc4 + 3);
  puVar4 = &DAT_020b90d4;
  for (iVar2 = 0x73; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_005f33c9(&stack0xfffffffc,0x4b3e6b);
  fVar1 = P1;
  *(undefined2 *)(puVar5 + -0x28) = in_FPUControlWord;
  *(ushort *)(puVar5 + -0x26) = (ushort)*(undefined4 *)(puVar5 + -0x28) | 0xc00;
  *(int *)(puVar5 + -0x24) = (int)ROUND(fVar1);
  fVar1 = P4;
  DAT_0089f390 = *(int *)(puVar5 + -0x24);
  *(undefined2 *)(puVar5 + -0x28) = *(undefined2 *)(puVar5 + -0x28);
  *(ushort *)(puVar5 + -0x26) = (ushort)*(undefined4 *)(puVar5 + -0x28) | 0xc00;
  *(int *)(puVar5 + -0x24) = (int)ROUND(fVar1);
  DAT_0089f38c = *(int *)(puVar5 + -0x24);
  *(int *)(puVar5 + -0x28) = DAT_0089f390 + -1;
  thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_007645f4,&DAT_007645f8,"(1i3)",5,puVar5 + -0x28);
  *(int *)(puVar5 + -0x28) = DAT_0089f38c + 1;
  thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_007645f0,&DAT_0076444c,"(1i3)",5,puVar5 + -0x28);
  thunk_FUN_0058c248(&DAT_020b90a0,0x200,&DAT_00764574,&DAT_007645ec,"(1f6.2)",7,&P2);
  thunk_FUN_0058c248(&DAT_020b90a0,0x200,&DAT_007645e4,&DAT_007645e8,"(1f6.2)",7,&P3);
  for (iVar2 = 1; iVar2 < 0x33; iVar2 = iVar2 + 1) {
    *(undefined4 *)(&P0 + iVar2 * 4) = *(undefined4 *)(&DAT_020b943c + iVar2 * 4);
  }
  FUN_004b041d();
  return;
}


