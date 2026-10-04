// FUN_0057275d @ 0057275d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057275d(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffffc;
  DAT_01c58610 = 2;
  DAT_020b8e38 = 0xffffffff;
  puVar2 = &DAT_0078b510;
  puVar3 = (undefined4 *)&DAT_007a0b7c;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_009a86d8 = 6;
  FUN_005f33c9(&stack0xfffffffc,0x5727b8);
  FUN_005f33c9(puVar4,0x5727d4);
  FUN_005f34d1(puVar4,0x5727ef);
  thunk_FUN_00529628(&DAT_0076a554,&ITEM_WORDS,&ITEM_P1,&DAT_009a86d8,&DAT_009a86dc,0x80);
  puVar2 = (undefined4 *)&DAT_007a0b7c;
  puVar3 = &DAT_0078b510;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_005f34d1(puVar4,0x572850);
  DAT_01c58610 = 0;
  DAT_0078b4f0 = DAT_0078b504;
  thunk_FUN_00495d4f(&DAT_0078b510,0x80);
  DAT_020b8e38 = 0xffffffff;
  return;
}


