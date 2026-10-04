// FUN_005725fa @ 005725fa (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005725fa(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffffc;
  if (DAT_020527a0 != -2) {
    if (DAT_020527a0 < -2) {
      return;
    }
    _DAT_009a85d4 = 6;
    puVar2 = &DAT_0078b510;
    puVar3 = (undefined4 *)&DAT_007a0b7c;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    DAT_01c58610 = 2;
    FUN_005f33c9(&stack0xfffffffc,0x572674);
    FUN_005f33c9(puVar4,0x572690);
    FUN_005f34d1(puVar4,0x5726ab);
    thunk_FUN_00529628(&DAT_0076a554,&ITEM_WORDS,&ITEM_P1,&DAT_009a85d4,&DAT_009a85d8,0x80);
    puVar2 = (undefined4 *)&DAT_007a0b7c;
    puVar3 = &DAT_0078b510;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005f34d1(puVar4,0x57270c);
    DAT_0078b504 = DAT_0078b4f0;
    DAT_01c58610 = 0;
    DAT_0078b4f0 = 1;
    thunk_FUN_00495d4f(&DAT_0078b510,0x80);
  }
  DAT_020b8e38 = 1;
  DAT_020527a0 = 0xffffffff;
  return;
}


