// FUN_00572420 @ 00572420 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00572420(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffffc;
  if (DAT_020b8ea3 == 'O') {
    if (DAT_020b8e38 < 1) {
      thunk_FUN_0054d831("*** Nothing to UNDO.",0x15);
      DAT_0078b4e4 = 0;
    }
    else {
      FUN_0057275d();
      iVar1 = DAT_020527a0;
      if (DAT_020527a0 < 0) {
        puVar2 = &DAT_0078b510;
        puVar3 = (undefined4 *)&DAT_007a0b7c;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        DAT_01c58610 = 2;
        FUN_005f33c9(&stack0xfffffffc,0x5724ca);
        FUN_005f33c9(puVar4,0x5724e6);
        FUN_005f33c9(puVar4,0x572502);
        FUN_005f34d1(puVar4,0x57251d);
        puVar2 = (undefined4 *)&DAT_020b8ea0;
        puVar3 = (undefined4 *)&DAT_020b90a0;
        for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        DAT_0078b4f0 = 1;
        cmd_get();
        DAT_020527a0 = 0;
        puVar2 = (undefined4 *)&DAT_007a0b7c;
        puVar3 = &DAT_0078b510;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        FUN_005f34d1(puVar4,0x57257c);
        DAT_01c58610 = 0;
        DAT_020b8e38 = -1;
        thunk_FUN_00495d4f(&DAT_0078b510,0x80);
      }
      else {
        ITEM_WORDS = DAT_020527a0;
        DAT_020527a0 = 0;
        DAT_0078b4e4 = 0xffffffff;
        if (iVar1 < 1) {
          ITEM_WORDS = 1;
        }
        draw_items();
      }
    }
  }
  else {
    FUN_0057288b();
  }
  return;
}


