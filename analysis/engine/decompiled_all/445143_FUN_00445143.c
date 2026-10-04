// FUN_00445143 @ 00445143 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00445143(void)

{
  float fVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  undefined2 uVar4;
  float10 fVar5;
  undefined1 *puVar6;
  
  puVar6 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if (DAT_020b8ea0._1_1_ == 'X') {
    DAT_007fbe80 = (int)ROUND(P2);
    DAT_007fbe7c = (&ITEM_PTR0)[DAT_020527e8];
    DAT_020492a4 = 1;
    P1 = (float)(&ITEM_P2)[DAT_007fbe7c];
    P2 = (float)(&ITEM_P3)[DAT_007fbe7c];
    P3 = P2;
    P4 = P1;
    fVar5 = (float10)anint(&stack0xfffffffc,0x445259);
    *(int *)(puVar6 + -0x4c) = (int)ROUND(fVar5);
    DAT_01fbb8ac = *(undefined4 *)(puVar6 + -0x4c);
    DAT_01fbb8b0 = DAT_01fbb8ac;
    FUN_005f33c9(puVar6,0x445296);
    puVar2 = puVar6;
    FUN_005f33c9(puVar6,0x4452b2);
    if (DAT_007fbe80 != 0) {
      *(undefined4 *)(puVar2 + -0x48) = 0;
      *(undefined4 *)(puVar2 + -0x58) = 1;
      *(char **)(puVar2 + -0x54) = s_tmp_007924dd;
      *(int **)(puVar2 + -0x50) = &DAT_007fbe80;
      FUN_005f34f0(puVar2 + -0x48,0x784ff00,&DAT_00760974,puVar2 + -0x58,&DAT_0078f844);
    }
    *(undefined4 *)(puVar2 + -0x20) = 0;
  }
  else {
    DAT_01fbb874 = 0x44;
    DAT_01fbb878 = 1;
    DAT_01fbb87c = ITEM_I;
    thunk_FUN_0049b1d8();
    if (DAT_020492a0 == 0) {
      return;
    }
    DAT_0078b4ec = 0;
    DAT_007fbe80 = 0x15;
  }
  *(undefined4 *)(puVar2 + -0x48) = 0;
  *(undefined4 *)(puVar2 + -0x60) = 0x12;
  *(undefined **)(puVar2 + -0x5c) = &DAT_007924d0;
  *(undefined4 *)(puVar2 + -0x58) = 6;
  *(char **)(puVar2 + -0x54) = "binary";
  *(undefined4 *)(puVar2 + -0x50) = 2;
  *(undefined4 *)(puVar2 + -0x4c) = 4;
  FUN_005f6540(puVar2 + -0x48,DAT_007fbe80,0x784ff00,&DAT_00760958,puVar2 + -0x60);
  _DAT_007fbe78 = DAT_020492a4;
  *(undefined2 *)(puVar2 + -0x50) = in_FPUControlWord;
  *(ushort *)(puVar2 + -0x4e) = (ushort)*(undefined4 *)(puVar2 + -0x50) | 0xc00;
  *(int *)(puVar2 + -0x4c) = (int)ROUND(P1);
  _DAT_007fbe74 = *(undefined4 *)(puVar2 + -0x4c);
  *(undefined2 *)(puVar2 + -0x50) = *(undefined2 *)(puVar2 + -0x50);
  *(ushort *)(puVar2 + -0x4e) = (ushort)*(undefined4 *)(puVar2 + -0x50) | 0xc00;
  *(int *)(puVar2 + -0x4c) = (int)ROUND(P4);
  uVar4 = *(undefined2 *)(puVar2 + -0x50);
  _DAT_007fbe70 = *(undefined4 *)(puVar2 + -0x4c);
  *(undefined4 *)(puVar2 + -0x48) = 0;
  *(undefined **)(puVar2 + -0x50) = &DAT_007fbe78;
  FUN_005fa4d0(puVar2 + -0x48,DAT_007fbe80,0x784ff00,&DAT_00760954,puVar2 + -0x50);
  *(undefined **)(puVar2 + -0x50) = &DAT_007fbe74;
  FUN_005fa9f0(puVar2 + -0x48,&DAT_00760954,puVar2 + -0x50);
  *(float **)(puVar2 + -0x50) = &P2;
  FUN_005fa9f0(puVar2 + -0x48,&DAT_00760950,puVar2 + -0x50);
  *(float **)(puVar2 + -0x50) = &P3;
  FUN_005fa9f0(puVar2 + -0x48,&DAT_00760950,puVar2 + -0x50);
  *(undefined **)(puVar2 + -0x50) = &DAT_007fbe70;
  FUN_005fa9f0(puVar2 + -0x48,&DAT_00760954,puVar2 + -0x50);
  *(undefined4 **)(puVar2 + -0x50) = &DAT_01fbb8ac;
  FUN_005fa9f0(puVar2 + -0x48,&DAT_00760954,puVar2 + -0x50);
  *(undefined4 **)(puVar2 + -0x50) = &DAT_01fbb8b0;
  FUN_005fa9f0(puVar2 + -0x48,&DAT_0076094c,puVar2 + -0x50);
  if (DAT_020b8ea0._1_1_ == 'X') {
    fVar1 = (float)(&ITEM_LEN)[DAT_007fbe7c];
    *(undefined2 *)(puVar2 + -0x50) = uVar4;
    *(ushort *)(puVar2 + -0x4e) = (ushort)*(undefined4 *)(puVar2 + -0x50) | 0xc00;
    *(int *)(puVar2 + -0x4c) = (int)ROUND(fVar1);
    DAT_007fbe6c = *(int *)(puVar2 + -0x4c);
    *(undefined4 *)(puVar2 + -0x48) = 0;
    *(int **)(puVar2 + -0x50) = &DAT_007fbe6c;
    FUN_005fa4d0(puVar2 + -0x48,DAT_007fbe80,0x784ff00,&DAT_00760954,puVar2 + -0x50);
    iVar3 = DAT_007fbe6c + 1;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    DAT_007fbe84 = DAT_007fbe7c + iVar3;
    *(undefined4 *)(puVar2 + -0x60) = 1;
    *(undefined4 **)(puVar2 + -0x5c) = &ITEM_LEN + DAT_007fbe7c;
    *(undefined4 *)(puVar2 + -0x58) = 1;
    *(int *)(puVar2 + -0x54) = iVar3;
    *(undefined4 *)(puVar2 + -0x50) = 4;
    FUN_005fa9f0(puVar2 + -0x48,&DAT_00760948,puVar2 + -0x60);
  }
  else {
    *(int *)(puVar2 + -0xc) = DAT_020492a4;
    DAT_007fbe68 = 1;
    iVar3 = DAT_020492a4;
    while (0 < iVar3) {
      DAT_007fbe7c = (&ITEM_PTR0)[(&DAT_020492a4)[DAT_007fbe68]];
      fVar1 = (float)(&ITEM_LEN)[DAT_007fbe7c];
      *(undefined2 *)(puVar2 + -0x50) = uVar4;
      *(ushort *)(puVar2 + -0x4e) = (ushort)*(undefined4 *)(puVar2 + -0x50) | 0xc00;
      *(int *)(puVar2 + -0x4c) = (int)ROUND(fVar1);
      uVar4 = *(undefined2 *)(puVar2 + -0x50);
      DAT_007fbe6c = *(int *)(puVar2 + -0x4c);
      *(undefined4 *)(puVar2 + -0x48) = 0;
      *(int **)(puVar2 + -0x50) = &DAT_007fbe6c;
      FUN_005fa4d0(puVar2 + -0x48,DAT_007fbe80,0x784ff00,&DAT_00760954,puVar2 + -0x50);
      iVar3 = DAT_007fbe6c + 1;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      DAT_007fbe84 = DAT_007fbe7c + iVar3;
      *(undefined4 *)(puVar2 + -0x60) = 1;
      *(undefined4 **)(puVar2 + -0x5c) = &ITEM_LEN + DAT_007fbe7c;
      *(undefined4 *)(puVar2 + -0x58) = 1;
      *(int *)(puVar2 + -0x54) = iVar3;
      *(undefined4 *)(puVar2 + -0x50) = 4;
      FUN_005fa9f0(puVar2 + -0x48,&DAT_00760948,puVar2 + -0x60);
      DAT_007fbe68 = DAT_007fbe68 + 1;
      *(int *)(puVar2 + -0xc) = *(int *)(puVar2 + -0xc) + -1;
      iVar3 = *(int *)(puVar2 + -0xc);
    }
  }
  *(undefined4 *)(puVar2 + -0x48) = 0;
  FUN_005f7950(puVar2 + -0x48,DAT_007fbe80,0x784ff00,&DAT_00760944,0);
  FUN_005f33c9(puVar2,0x445748);
  FUN_005f34d1(puVar2,0x445763);
  thunk_FUN_0058c2c9(&DAT_009ae2bc,0x200,&DAT_0076090c,&DAT_00760910,"(1i3)",5,&DAT_01fbb860);
  thunk_FUN_0058c2c9(&DAT_009ae2bc,0x200,&DAT_00760904,&DAT_00760908,"(1i3)",5,&DAT_01fbb864);
  thunk_FUN_0058c248(&DAT_009ae2bc,0x200,&DAT_007608f4,&DAT_007608f8,"(1f5.1)",7,&P2);
  thunk_FUN_0058c248(&DAT_009ae2bc,0x200,&DAT_007608ec,&DAT_007608f0,"(1f5.1)",7,&P3);
  draw_items();
  DAT_01fbb8a0 = 0;
  thunk_FUN_00468df8(&DAT_007608e8);
  return;
}


