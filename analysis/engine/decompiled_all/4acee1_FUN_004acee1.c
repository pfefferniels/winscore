// FUN_004acee1 @ 004acee1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004acee1(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int local_14;
  
  puVar3 = &stack0xfffffffc;
  puVar2 = &DAT_0088e070;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  local_14 = 0x80;
  *param_3 = 0x80;
  do {
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      FUN_005f46bc(&stack0xfffffffc,0x4acfbb);
      FUN_005f34d1(puVar3,0x4acfd1);
      *(undefined4 *)(puVar3 + -8) = 0;
      return;
    }
    *param_3 = *param_3 + -1;
    local_14 = local_14 + -1;
  } while (0 < local_14);
  thunk_FUN_0054d831("Path missing.",0xe);
  return;
}


