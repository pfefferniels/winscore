// FUN_00512009 @ 00512009 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00512009(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  puVar5 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if (DAT_0078b4e0 != 0x42) {
    puVar3 = &DAT_0078cb22;
    puVar4 = &DAT_01b9d540;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    thunk_FUN_004d54b8();
    if (DAT_01b9d540 == 0x3154504c) {
      FUN_005f33c9(&stack0xfffffffc,0x5120b8);
      FUN_005f34d1(puVar6,0x5120d3);
      puVar2 = puVar6;
    }
    else {
      FUN_005f33c9(&stack0xfffffffc,0x512066);
      FUN_005f34d1(puVar5,0x512081);
      puVar3 = &DAT_01b9d540;
      puVar4 = (undefined4 *)((int)&DAT_009ae2cc + 1);
      for (iVar1 = 0xc; puVar2 = puVar5, iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    draw_items();
  }
  DAT_00791448 = 1;
  FUN_005f34d1(puVar2,0x512104);
  return;
}


