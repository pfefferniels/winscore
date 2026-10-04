// FUN_00580738 @ 00580738 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00580738(undefined4 param_1,int *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = &stack0xfffffffc;
  DAT_009a8f68 = (&ITEM_PTR0)[*param_2];
  FUN_005f34d1(&stack0xfffffffc,0x580770);
  DAT_009a8f64 = 0;
  DAT_009a8f60 = DAT_009a8f68 + 0xe;
  iVar2 = (&DAT_02091d20)[**(int **)(puVar1 + 0xc)] - DAT_009a8f60;
  *(int *)(puVar1 + -0x1c) = iVar2;
  while (0 < iVar2) {
    DAT_009a8f64 = DAT_009a8f64 + 1;
    *(undefined4 *)(DAT_009a8f64 * 4 + 0x9a8f9c) = (&ITEM_LEN)[DAT_009a8f60];
    DAT_009a8f60 = DAT_009a8f60 + 1;
    *(int *)(puVar1 + -0x1c) = *(int *)(puVar1 + -0x1c) + -1;
    iVar2 = *(int *)(puVar1 + -0x1c);
  }
  if (**(int **)(puVar1 + 8) == 0) {
    *(undefined4 *)(puVar1 + -0x3c) = 0;
    *(undefined4 *)(puVar1 + -0x50) = 4;
    *(undefined **)(puVar1 + -0x4c) = &DAT_0076aa50;
    *(undefined4 *)(puVar1 + -0x48) = 2;
    *(undefined4 *)(puVar1 + -0x44) = 4;
    FUN_005f6540(puVar1 + -0x3c,5,0x784ff00,&DAT_0076aa40,puVar1 + -0x50);
  }
  **(undefined4 **)(puVar1 + 8) = 0xffffffff;
  FUN_005f33c9(puVar1,0x580864);
  FUN_005f34d1(puVar1,0x58087f);
  if (DAT_009a8fa0 == '_') {
    DAT_009a8f60 = DAT_009a8fa1 - 0x30;
    DAT_0078b6a0 = DAT_009a8f60 * 10 + (uint)DAT_009a8fa2 + -0x30;
    FUN_005f33c9(puVar1,0x5808eb);
    FUN_005f34d1(puVar1,0x580906);
    load_font_metrics();
    FUN_005f33c9(puVar1,0x580934);
    FUN_005f34d1(puVar1,0x58094f);
    thunk_FUN_0056ae1c();
    _DAT_009a8f5c = VIEW_DX + DAT_01a27704;
    _DAT_009a8f58 = DAT_01a27708;
  }
  else {
    *(undefined4 *)(puVar1 + -0x14) = 0;
  }
  _DAT_009a8f54 = f_10_844;
  *(undefined4 *)(puVar1 + -0x3c) = 0;
  *(undefined4 *)(puVar1 + -0x48) = 0x30;
  *(undefined **)(puVar1 + -0x44) = &DAT_009a8f6c;
  FUN_005fc330(puVar1 + -0x3c,5,0x784ff00,&DAT_0076aa2c,puVar1 + -0x48,&DAT_007a0438);
  *(undefined4 *)(puVar1 + -0x3c) = 0;
  *(undefined **)(puVar1 + -0x48) = &DAT_009a8f54;
  FUN_005fc330(puVar1 + -0x3c,5,0x784ff00,&DAT_0076aa28,puVar1 + -0x48,&DAT_007a044c);
  *(undefined4 *)(puVar1 + -0x3c) = 0;
  *(undefined **)(puVar1 + -0x48) = &DAT_009a8f5c;
  FUN_005fc330(puVar1 + -0x3c,5,0x784ff00,&DAT_0076aa24,puVar1 + -0x48,&DAT_007a046c);
  *(undefined **)(puVar1 + -0x48) = &DAT_009a8f58;
  FUN_005fc980(puVar1 + -0x3c,&DAT_0076aa20,puVar1 + -0x48);
  *(undefined4 *)(puVar1 + -0x3c) = 0;
  *(undefined4 *)(puVar1 + -0x48) = 0xa0;
  *(char **)(puVar1 + -0x44) = &DAT_009a8fa0;
  FUN_005fc330(puVar1 + -0x3c,5,0x784ff00,&DAT_0076aa2c,puVar1 + -0x48,&DAT_007a0480);
  return;
}


