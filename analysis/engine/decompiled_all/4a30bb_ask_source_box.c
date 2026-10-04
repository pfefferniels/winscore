// ask_source_box @ 004a30bb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void ask_source_box(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x4a30e1);
  FUN_005f34d1(puVar2,0x4a30fc);
  if (**(int **)(puVar2 + 0xc) != 0) {
    FUN_005f33c9(puVar2,0x4a3126);
    FUN_005f34d1(puVar2,0x4a3141);
  }
  if (DAT_00838b40 != 'D') {
    FUN_004a3172();
  }
  uVar1 = thunk_FUN_00595cd0(&DAT_00838b40);
  **(undefined4 **)(puVar2 + 8) = uVar1;
  return;
}


