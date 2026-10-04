// FUN_0054c318 @ 0054c318 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c318(void)

{
  undefined1 *puVar1;
  
  puVar1 = &stack0xfffffffc;
  if (P2 != f_0) {
    VIEW_DY = (int)ROUND(P2);
    draw_items();
  }
  FUN_005f33c9(&stack0xfffffffc,0x54c381);
  FUN_005f34d1(puVar1,0x54c39c);
  *(undefined4 *)(puVar1 + -0x24) = 0;
  *(undefined4 *)(puVar1 + -0x38) = 7;
  *(undefined4 *)(puVar1 + -0x34) = 0x9ae2c5;
  *(int **)(puVar1 + -0x30) = &VIEW_DY;
  FUN_005f34f0(puVar1 + -0x24,0x784ff00,&DAT_0076915c,puVar1 + -0x38,&DAT_007978d0);
  return;
}


