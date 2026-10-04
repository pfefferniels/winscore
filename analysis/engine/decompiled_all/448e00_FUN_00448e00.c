// FUN_00448e00 @ 00448e00 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00448e00(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  FUN_00448fcc(&ITEM_I,&DAT_02091d20,&ITEM_P1);
  if (DAT_01c4c828 == 0) {
    thunk_FUN_0054c8e5(&DAT_020b90a0,1,&DAT_007fd3a4);
    FUN_005f46bc(&stack0xfffffffc,0x448e8d);
    FUN_005f46bc(puVar2,0x448ea9);
    FUN_005f34d1(puVar2,0x448ebf);
    DAT_007fd3c8 = i_7562585;
    DAT_007fd3cc = i_538976288;
    DAT_007fd3d0 = DAT_00760b58;
    DAT_007fd3b8 = i_536899406;
    DAT_007fd3bc = i_538976288;
    DAT_007fd3c0 = DAT_00760b4c;
    DAT_007fd3a8 = i_1953069125;
    DAT_007fd3ac = i_538976256;
    DAT_007fd3b0 = DAT_00760b40;
    uVar1 = thunk_FUN_00595720(&DAT_020b8ea0,&DAT_007fd3c8,&DAT_007fd3b8,&DAT_007fd3a8,0);
    **(undefined4 **)(puVar2 + 8) = uVar1;
    if (**(int **)(puVar2 + 8) == 0) {
      FUN_005f33c9(puVar2,0x448f7d);
      FUN_005f33c9(puVar2,0x448f99);
      FUN_005f34d1(puVar2,0x448fb4);
      DAT_01c4c788 = 1;
    }
    else {
      *(undefined4 *)(puVar2 + -4) = 0;
    }
  }
  return;
}


