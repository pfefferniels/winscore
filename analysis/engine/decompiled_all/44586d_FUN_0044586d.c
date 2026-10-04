// FUN_0044586d @ 0044586d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044586d(void)

{
  undefined4 *puVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined2 in_FPUControlWord;
  
  puVar5 = &stack0xfffffffc;
  IP18 = ITEM_I;
  DAT_020527a0 = ITEM_WORDS;
  DAT_007fbfa4 = 0x15;
  FUN_005f33c9(&stack0xfffffffc,0x4458ba);
  FUN_005f33c9(puVar5,0x4458d6);
  fVar2 = P2;
  *(undefined2 *)(puVar5 + -0x50) = in_FPUControlWord;
  *(ushort *)(puVar5 + -0x4e) = (ushort)*(undefined4 *)(puVar5 + -0x50) | 0xc00;
  *(int *)(puVar5 + -0x4c) = (int)ROUND(fVar2);
  _DAT_007fbfa0 = *(undefined4 *)(puVar5 + -0x4c);
  thunk_FUN_0058c2c9(&DAT_007924d0,0x12,&DAT_00760844,&DAT_00760844,"(1i1)",5,&DAT_007fbfa0);
  *(undefined4 *)(puVar5 + -0x48) = 0;
  *(undefined4 *)(puVar5 + -0x68) = 0x12;
  *(undefined **)(puVar5 + -100) = &DAT_007924d0;
  *(undefined4 *)(puVar5 + -0x60) = 6;
  *(char **)(puVar5 + -0x5c) = "binary";
  *(undefined4 *)(puVar5 + -0x58) = 3;
  *(undefined **)(puVar5 + -0x54) = &DAT_007609e0;
  *(undefined4 *)(puVar5 + -0x50) = 2;
  uVar3 = FUN_005f6540(puVar5 + -0x48,DAT_007fbfa4,0x784ff01,&DAT_007609cc,puVar5 + -0x68);
  *(undefined4 *)(puVar5 + -0x28) = uVar3;
  if (*(int *)(puVar5 + -0x28) == 0) {
    *(undefined4 *)(puVar5 + -0x48) = 0;
    *(int **)(puVar5 + -0x50) = &DAT_007fbf9c;
    iVar4 = FUN_005f8240(puVar5 + -0x48,DAT_007fbfa4,0x784ff01,&DAT_00760954,puVar5 + -0x50);
    *(int *)(puVar5 + -0x24) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 **)(puVar5 + -0x50) = &DAT_007fbf98;
      iVar4 = FUN_005f8730(puVar5 + -0x48,&DAT_00760954,puVar5 + -0x50);
      *(int *)(puVar5 + -0x24) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 **)(puVar5 + -0x50) = &DAT_01fbb868;
        iVar4 = FUN_005f8730(puVar5 + -0x48,&DAT_00760950,puVar5 + -0x50);
        *(int *)(puVar5 + -0x24) = iVar4;
        if (iVar4 == 0) {
          *(float **)(puVar5 + -0x50) = &DAT_01fbb86c;
          iVar4 = FUN_005f8730(puVar5 + -0x48,&DAT_00760950,puVar5 + -0x50);
          *(int *)(puVar5 + -0x24) = iVar4;
          if (iVar4 == 0) {
            *(undefined4 **)(puVar5 + -0x50) = &DAT_007fbf94;
            iVar4 = FUN_005f8730(puVar5 + -0x48,&DAT_00760954,puVar5 + -0x50);
            *(int *)(puVar5 + -0x24) = iVar4;
            if (iVar4 == 0) {
              *(undefined4 **)(puVar5 + -0x50) = &DAT_01fbb8ac;
              iVar4 = FUN_005f8730(puVar5 + -0x48,&DAT_00760954,puVar5 + -0x50);
              *(int *)(puVar5 + -0x24) = iVar4;
              if (iVar4 == 0) {
                *(undefined4 **)(puVar5 + -0x50) = &DAT_01fbb8b0;
                uVar3 = FUN_005f8730(puVar5 + -0x48,&DAT_0076094c,puVar5 + -0x50);
                *(undefined4 *)(puVar5 + -0x24) = uVar3;
              }
            }
          }
        }
      }
    }
    iVar4 = DAT_007fbf9c;
    if (*(int *)(puVar5 + -0x24) == 0) {
      DAT_020492a4 = DAT_007fbf9c;
      DAT_01fbb860 = DAT_007fbf98;
      DAT_01fbb864 = DAT_007fbf94;
      DAT_02091d20 = 1;
      if (DAT_01fbb86c == f_0) {
        DAT_01fbb86c = DAT_01fbb8b8;
      }
      DAT_01fbb878 = ITEM_I + 1;
      *(int *)(puVar5 + -0x20) = DAT_007fbf9c;
      DAT_007fbf90 = 1;
      while( true ) {
        if (iVar4 < 1) {
          *(undefined4 *)(puVar5 + -0x48) = 0;
          FUN_005f7950(puVar5 + -0x48,DAT_007fbfa4,0x784ff00,&DAT_00760944,0);
          DAT_01fbb87c = ITEM_I;
          DAT_01c58560 = f_0;
          DAT_01fbb874 = 0;
          thunk_FUN_0049b1d8();
          *(undefined4 *)(puVar5 + -0x14) = 0;
          return;
        }
        *(undefined4 *)(puVar5 + -0x48) = 0;
        *(int **)(puVar5 + -0x50) = &DAT_007fbf8c;
        iVar4 = FUN_005f8240(puVar5 + -0x48,DAT_007fbfa4,0x784ff01,&DAT_00760954,puVar5 + -0x50);
        *(int *)(puVar5 + -0x1c) = iVar4;
        if (iVar4 == 0) {
          puVar1 = &ITEM_LEN + ITEM_WORDS;
          iVar4 = DAT_007fbf8c + 1;
          if (iVar4 < 0) {
            iVar4 = 0;
          }
          DAT_007fbfa8 = ITEM_WORDS + iVar4;
          *(undefined4 *)(puVar5 + -0x60) = 1;
          *(undefined4 **)(puVar5 + -0x5c) = puVar1;
          *(undefined4 *)(puVar5 + -0x58) = 1;
          *(int *)(puVar5 + -0x54) = iVar4;
          *(undefined4 *)(puVar5 + -0x50) = 4;
          uVar3 = FUN_005f8730(puVar5 + -0x48,&DAT_00760948,puVar5 + -0x60);
          *(undefined4 *)(puVar5 + -0x1c) = uVar3;
        }
        if (*(int *)(puVar5 + -0x1c) != 0) break;
        ITEM_WORDS = DAT_007fbf8c + ITEM_WORDS + 1;
        ITEM_I = ITEM_I + 1;
        (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
        DAT_007fbf90 = DAT_007fbf90 + 1;
        *(int *)(puVar5 + -0x20) = *(int *)(puVar5 + -0x20) + -1;
        iVar4 = *(int *)(puVar5 + -0x20);
      }
    }
  }
  FUN_005f34d1(puVar5,0x445d24);
  FUN_005f33c9(puVar5,0x445d46);
  FUN_005f33c9(puVar5,0x445d62);
  FUN_005f33c9(puVar5,0x445d84);
  FUN_005f33c9(puVar5,0x445da0);
  FUN_005f33c9(puVar5,0x445dbc);
  FUN_005f33c9(puVar5,0x445dd8);
  FUN_005f34d1(puVar5,0x445df3);
  DAT_0078f85c = 10;
  *(undefined4 *)(puVar5 + -0x10) = 10;
  DAT_007fbf88 = 0;
  do {
    thunk_FUN_0058c2c9(&DAT_007924d0,0x12,&DAT_00760844,&DAT_00760844,"(1i1)",5,&DAT_007fbf88);
    *(undefined4 *)(puVar5 + -0x48) = 0;
    *(undefined4 *)(puVar5 + -0x60) = 0x12;
    *(undefined **)(puVar5 + -0x5c) = &DAT_007924d0;
    *(undefined4 *)(puVar5 + -0x58) = 3;
    *(undefined **)(puVar5 + -0x54) = &DAT_007609e0;
    *(undefined4 *)(puVar5 + -0x50) = 2;
    uVar3 = FUN_005f6540(puVar5 + -0x48,DAT_007fbfa4,0x784ff01,&DAT_0076098c,puVar5 + -0x60);
    *(undefined4 *)(puVar5 + -0xc) = uVar3;
    if (*(int *)(puVar5 + -0xc) == 0) {
      puVar5[-0x49] = (char)DAT_007fbf88 + '0';
      DAT_0078f860 = puVar5[-0x49];
      FUN_005f33c9(puVar5,0x445eee);
      DAT_007fbf90 = FUN_005ff950(puVar5 + -0x268,0x200);
      FUN_005f46bc(puVar5,0x445f4c);
      FUN_005f34d1(puVar5,0x445f62);
    }
    *(undefined4 *)(puVar5 + -8) = 0;
    DAT_007fbf88 = DAT_007fbf88 + 1;
    *(int *)(puVar5 + -0x10) = *(int *)(puVar5 + -0x10) + -1;
  } while (0 < *(int *)(puVar5 + -0x10));
  (&DAT_020b8ea5)[DAT_007fbf90] = 0;
  thunk_FUN_0054d863(&DAT_020b8ea0,0x200);
  ITEM_WORDS = DAT_020527a0;
  DAT_020527a0 = 0;
  ITEM_I = IP18;
  *(undefined4 *)(puVar5 + -0x48) = 0;
  FUN_005f7950(puVar5 + -0x48,DAT_007fbfa4,0x784ff00,&DAT_00760944,0);
  return;
}


