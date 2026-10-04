// FUN_00502d0b @ 00502d0b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00502d0b(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x502d32);
  FUN_005f34d1(puVar2,0x502d4d);
  *(undefined4 *)(puVar2 + -0x30) = 0;
  *(undefined4 *)(puVar2 + -0x40) = 3;
  *(undefined4 *)(puVar2 + -0x3c) = 0x1caea41;
  *(undefined4 **)(puVar2 + -0x38) = &DAT_01ba0d84;
  FUN_005f34f0(puVar2 + -0x30,0x784ff00,&DAT_00766d88,puVar2 + -0x40,&DAT_00795624);
  *(undefined4 *)(puVar2 + -0x30) = 0;
  *(undefined4 *)(puVar2 + -0x40) = 3;
  *(undefined4 **)(puVar2 + -0x3c) = &DAT_01caea68;
  *(undefined4 *)(puVar2 + -0x38) = *(undefined4 *)(puVar2 + 8);
  FUN_005f34f0(puVar2 + -0x30,0x784ff00,&DAT_00766d88,puVar2 + -0x40,&DAT_00795638);
  *(undefined4 *)(puVar2 + -0x30) = 0;
  *(undefined4 *)(puVar2 + -0x40) = 3;
  *(undefined **)(puVar2 + -0x3c) = &DAT_01caea76;
  *(undefined4 **)(puVar2 + -0x38) = &DAT_01ba0d60;
  FUN_005f34f0(puVar2 + -0x30,0x784ff00,&DAT_00766d88,puVar2 + -0x40,&DAT_0079564c);
  *(undefined4 *)(puVar2 + -0x30) = 0;
  *(undefined4 *)(puVar2 + -0x40) = 3;
  *(undefined **)(puVar2 + -0x3c) = &DAT_01caea84;
  *(undefined4 **)(puVar2 + -0x38) = &DAT_01ba0d64;
  FUN_005f34f0(puVar2 + -0x30,0x784ff00,&DAT_00766d88,puVar2 + -0x40,&DAT_00795660);
  FUN_005f33c9(puVar2,0x502e80);
  FUN_005f34d1(puVar2,0x502e9b);
  DAT_0078b4e4 = 0;
  for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
    *(float *)(&P0 + iVar1 * 4) = f_0;
  }
  DAT_02052808 = f_25;
  P2 = f_1;
  P3 = f_10;
  P4 = **(float **)(puVar2 + 0xc) + f_18;
  P6 = f_0_9;
  *DAT_01fbb844 = 0;
  for (iVar1 = 1; iVar1 < 0xfa01; iVar1 = iVar1 + 1) {
    (&ITEM_LEN)[iVar1] = f_0;
  }
  thunk_FUN_005644b8();
  P12 = f_0;
  P13 = f_0;
  _DAT_009029ec = 0;
  return;
}


