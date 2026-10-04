// FUN_0050f8ec @ 0050f8ec (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0050f8ec(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffffffc;
  DAT_009416ac = 1;
  for (iVar1 = DAT_01ba0d84; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_009416a8 = (&DAT_01a76ac0)[DAT_009416ac] + *(int *)(&DAT_01a77a5c + DAT_009416ac * 4);
    if (9000 < DAT_009416a8) {
      DAT_009416a8 = 9000;
    }
    *(int *)(&DAT_01a76abc + DAT_009416ac * 4) = DAT_009416a8;
    DAT_009416ac = DAT_009416ac + 1;
  }
  FUN_005f33c9(&stack0xfffffffc,0x50f993);
  FUN_005f33c9(puVar3,0x50f9af);
  thunk_FUN_00502575(&DAT_0076747c,puVar3 + -0x60,0x18,&DAT_00767480);
  DAT_009416a8 = DAT_01ba0d84;
  DAT_009416ac = DAT_01c58604;
  if (DAT_0078b4e8 != 0) {
    DAT_009416ac = DAT_01c58604 * 1000;
  }
  *(undefined4 *)(puVar3 + -0x48) = 0;
  *(int **)(puVar3 + -0x50) = &DAT_01c4ef40;
  FUN_00606890(puVar3 + -0x48,9,0x784ff00,&DAT_00767478,puVar3 + -0x50);
  *(int **)(puVar3 + -0x50) = &DAT_009416a8;
  FUN_00606ed0(puVar3 + -0x48,&DAT_00767478,puVar3 + -0x50);
  *(int **)(puVar3 + -0x50) = &MAX_STAFF;
  FUN_00606ed0(puVar3 + -0x48,&DAT_00767478,puVar3 + -0x50);
  *(int **)(puVar3 + -0x50) = &DAT_009416ac;
  FUN_00606ed0(puVar3 + -0x48,&DAT_00767478,puVar3 + -0x50);
  *(undefined4 **)(puVar3 + -0x50) = &DAT_01c5860c;
  FUN_00606ed0(puVar3 + -0x48,&DAT_00767474,puVar3 + -0x50);
  iVar1 = DAT_01c4ef40;
  if (DAT_01c4ef40 < 0) {
    iVar1 = 0;
  }
  DAT_009416ac = iVar1 + 1;
  *(undefined4 *)(puVar3 + -0x48) = 0;
  *(undefined4 *)(puVar3 + -0x60) = 1;
  *(undefined4 **)(puVar3 + -0x5c) = &DAT_01c42500;
  *(undefined4 *)(puVar3 + -0x58) = 1;
  *(int *)(puVar3 + -0x54) = iVar1;
  *(undefined4 *)(puVar3 + -0x50) = 4;
  FUN_005fc330(puVar3 + -0x48,9,0x784ff00,&DAT_00767470,puVar3 + -0x60,&DAT_00795f04);
  *(undefined4 *)(puVar3 + -0x48) = 0;
  FUN_005fc330(puVar3 + -0x48,9,0x784ff00,&DAT_0076746c,0,&DAT_00795f18);
  DAT_009416ac = 1;
  for (iVar1 = DAT_01c4ef40; 0 < iVar1; iVar1 = iVar1 + -1) {
    iVar2 = DAT_009416ac * 0x80;
    *(undefined4 *)(puVar3 + -0x58) = 0x80;
    *(undefined **)(puVar3 + -0x54) = &DAT_01c4eec4 + iVar2;
    *(undefined4 *)(puVar3 + -0x50) = 0x80;
    FUN_005fc980(puVar3 + -0x48,&DAT_00767468,puVar3 + -0x58);
    DAT_009416ac = DAT_009416ac + 1;
  }
  FUN_005fc980(puVar3 + -0x48,&DAT_00767464,0);
  iVar1 = DAT_009416a8;
  if (DAT_009416a8 < 0) {
    iVar1 = 0;
  }
  DAT_009416ac = iVar1 + 1;
  *(undefined4 *)(puVar3 + -0x48) = 0;
  *(undefined4 *)(puVar3 + -0x60) = 1;
  *(undefined4 **)(puVar3 + -0x5c) = &DAT_01a75b20;
  *(undefined4 *)(puVar3 + -0x58) = 1;
  *(int *)(puVar3 + -0x54) = iVar1;
  *(undefined4 *)(puVar3 + -0x50) = 4;
  FUN_005fc330(puVar3 + -0x48,9,0x784ff00,&DAT_00767470,puVar3 + -0x60,&DAT_00795f2c);
  iVar1 = DAT_009416a8;
  if (DAT_009416a8 < 0) {
    iVar1 = 0;
  }
  DAT_009416ac = iVar1 + 1;
  *(undefined4 *)(puVar3 + -0x48) = 0;
  *(undefined4 *)(puVar3 + -0x60) = 1;
  *(undefined4 **)(puVar3 + -0x5c) = &DAT_01ba0d88;
  *(undefined4 *)(puVar3 + -0x58) = 1;
  *(int *)(puVar3 + -0x54) = iVar1;
  *(undefined4 *)(puVar3 + -0x50) = 4;
  FUN_005fc330(puVar3 + -0x48,9,0x784ff00,&DAT_00767460,puVar3 + -0x60,&DAT_00795ef0);
  iVar1 = DAT_009416a8;
  if (DAT_009416a8 < 0) {
    iVar1 = 0;
  }
  DAT_009416ac = iVar1 + 1;
  *(undefined4 *)(puVar3 + -0x48) = 0;
  *(undefined4 *)(puVar3 + -0x60) = 1;
  *(undefined4 **)(puVar3 + -0x5c) = &DAT_01a76ac0;
  *(undefined4 *)(puVar3 + -0x58) = 1;
  *(int *)(puVar3 + -0x54) = iVar1;
  *(undefined4 *)(puVar3 + -0x50) = 4;
  FUN_005fc330(puVar3 + -0x48,9,0x784ff00,&DAT_00767470,puVar3 + -0x60,&DAT_00795f40);
  iVar1 = DAT_01c58604;
  if (DAT_01c58604 < 0) {
    iVar1 = 0;
  }
  DAT_009416ac = iVar1 + 1;
  *(undefined4 *)(puVar3 + -0x48) = 0;
  *(undefined4 *)(puVar3 + -0x60) = 1;
  *(undefined **)(puVar3 + -0x5c) = &DAT_01c41ce4;
  *(undefined4 *)(puVar3 + -0x58) = 1;
  *(int *)(puVar3 + -0x54) = iVar1;
  *(undefined4 *)(puVar3 + -0x50) = 4;
  FUN_005fc330(puVar3 + -0x48,9,0x784ff00,&DAT_00767460,puVar3 + -0x60,&DAT_00795f54);
  iVar1 = DAT_01c58604;
  if (DAT_01c58604 < 0) {
    iVar1 = 0;
  }
  DAT_009416ac = iVar1 + 1;
  *(undefined4 *)(puVar3 + -0x48) = 0;
  *(undefined4 *)(puVar3 + -0x60) = 1;
  *(undefined **)(puVar3 + -0x5c) = &DAT_01c420e8;
  *(undefined4 *)(puVar3 + -0x58) = 1;
  *(int *)(puVar3 + -0x54) = iVar1;
  *(undefined4 *)(puVar3 + -0x50) = 4;
  FUN_005fc330(puVar3 + -0x48,9,0x784ff00,&DAT_00767470,puVar3 + -0x60,&DAT_00795f68);
  *(undefined4 *)(puVar3 + -0x48) = 0;
  FUN_005f7950(puVar3 + -0x48,9,0x784ff00,&DAT_0076745c,0);
  return;
}


