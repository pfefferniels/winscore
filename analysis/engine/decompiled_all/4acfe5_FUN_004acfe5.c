// FUN_004acfe5 @ 004acfe5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004ad0a9) */
/* WARNING: Removing unreachable block (ram,0x004ad138) */

void FUN_004acfe5(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  DAT_0088e0f8 = *param_3;
  while (**(char **)(puVar2 + 8) == ' ') {
    FUN_005f46bc(puVar2,0x4ad04b);
    FUN_005f34d1(puVar2,0x4ad061);
    *(undefined4 *)(puVar2 + -0x14) = 0;
  }
  *(undefined4 *)(puVar2 + -0x18) = 0;
  iVar1 = **(int **)(puVar2 + 0x10);
  *(int *)(puVar2 + -0x10) = iVar1;
  DAT_0088e0f4 = 1;
  while( true ) {
    if (iVar1 < 1) {
      iVar1 = DAT_0088e0f8;
      if (DAT_0088e0f8 < 0) {
        iVar1 = 0;
      }
      thunk_FUN_0042ac4e(*(undefined4 *)(puVar2 + 8),iVar1);
                    /* WARNING: Subroutine does not return */
      FUN_006013a0(&DAT_00763b78,0,0x784ff00,0,0);
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) break;
    DAT_0088e0f4 = DAT_0088e0f4 + 1;
    *(int *)(puVar2 + -0x10) = *(int *)(puVar2 + -0x10) + -1;
    iVar1 = *(int *)(puVar2 + -0x10);
  }
  *(undefined4 *)(puVar2 + -0xc) = 0;
  DAT_0088e0f0 = DAT_0088e0f4 + 1;
  iVar1 = (**(int **)(puVar2 + 0x10) - DAT_0088e0f0) + 1;
  *(int *)(puVar2 + -8) = iVar1;
  while (0 < iVar1) {
    FUN_005f46bc(puVar2,0x4ad159);
    FUN_005f34d1(puVar2,0x4ad16f);
    DAT_0088e0f0 = DAT_0088e0f0 + 1;
    *(int *)(puVar2 + -8) = *(int *)(puVar2 + -8) + -1;
    iVar1 = *(int *)(puVar2 + -8);
  }
  return;
}


