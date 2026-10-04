// FUN_0041bc5a @ 0041bc5a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041bc5a(void)

{
  float fVar1;
  undefined2 in_FPUControlWord;
  undefined2 uVar2;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x41bc80);
  thunk_FUN_0054e546(&DAT_007d15a8,&DAT_007d15a4);
  fVar1 = P1;
  *(undefined2 *)(puVar3 + -0x28) = in_FPUControlWord;
  *(ushort *)(puVar3 + -0x26) = (ushort)*(undefined4 *)(puVar3 + -0x28) | 0xc00;
  *(int *)(puVar3 + -0x24) = (int)ROUND(fVar1);
  uVar2 = *(undefined2 *)(puVar3 + -0x28);
  DAT_007d15a0 = *(int *)(puVar3 + -0x24);
  if (((DAT_007d15a0 < 200) && (f_200 < _DAT_007d15a8)) && (f_220 < P2)) {
    P1 = P1 + f_200;
    DAT_007d15a0 = DAT_007d15a0 + 200;
  }
  if ((200 < DAT_007d15a0) && (DAT_01a14950 == 0)) {
    DAT_01a14950 = 34000;
    DAT_01a14948 = 64000;
  }
  if ((200 < DAT_007d15a0) && (f_220 < P2)) {
    P2 = P2 - f_227;
    P3 = P3 - f_227;
  }
  thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_0075f6ac,&DAT_0075f6b0,"(1i3)",5,&DAT_007d15a0);
  thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_0075f69c,&DAT_0075f6a0,"(1f7.2)",7,&P2);
  thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_0075f694,&DAT_0075f698,"(1f7.2)",7,&P3);
  fVar1 = P4;
  *(undefined2 *)(puVar3 + -0x28) = uVar2;
  *(ushort *)(puVar3 + -0x26) = (ushort)*(undefined4 *)(puVar3 + -0x28) | 0xc00;
  *(int *)(puVar3 + -0x24) = (int)ROUND(fVar1);
  DAT_007d15a0 = *(int *)(puVar3 + -0x24);
  thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_0075f68c,&DAT_0075f690,"(1i3)",5,&DAT_007d15a0);
  DAT_020b8eb8._0_1_ = 0;
  thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
  return;
}


